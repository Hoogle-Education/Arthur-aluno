/*
 * main.c
 *
 *  Created on: 6 de fev. de 2022
 *      Author: Matheus
 */

#include "tadlista.h"
#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 100

void inline menu(){
	puts("a");
}

int main(){
	
	// creating dic
	TDicionario dicPortAlem = criaDic();
	TDicionario dicPortFran = criaDic();
	TDicionario dicAlemFran = criaDic();
 
	// creating TLista of port words
	TLista portKeys;

	// creating file
	FILE* txtFile;
	char buffer[MAXCHAR];

	// ------------------------------------------

	// open pt-al
	txtFile = fopen( "./Dicionarios/dic-pt-al.txt" , "r" );

	while( !feof(txtFile) ){
		fgets(buffer, MAXCHAR, txtFile);

		char *value, *key;
		key = strtok(buffer, ",");
		value = strtok(NULL, ",");	

		if( value != NULL) dicPortAlem = adicionaDic(dicPortAlem, key, value);

	}

	// ------------------------------------------
	// open pt-fran

	txtFile = fopen( "./Dicionarios/dic-pt-fr.txt" , "r" );

	while ( !feof(txtFile) ){
	 	fgets(buffer, MAXCHAR, txtFile);

		char *value, *key;
		key = strtok(buffer, ",");
		value = strtok(NULL, ",");	

		if( value != NULL) dicPortFran = adicionaDic(dicPortFran, key, value);

	}

	fclose(txtFile);
	txtFile = fopen("./Dicionarios/dic-al-fr.txt", "a");
	portKeys = keys(dicPortAlem);

	printf("lendic: %d\n", lenDic(dicPortAlem) );

	for(int i=0; i < lenDic(dicPortAlem); i++){
		
		tdado key = infoLista(portKeys, i);
		tdado valueAlem =  obtemDic(dicPortAlem, key);
		tdado valueFranc = obtemDic(dicPortFran, key);

		printf("%s : %s\n", valueAlem, valueFranc );		

		dicAlemFran = adicionaDic(dicAlemFran, valueAlem, valueFranc);

		printf("%s : %s\n", "femme", obtemDic(dicAlemFran, "femme") );
	}

	fclose(txtFile);
	return 0;
}

