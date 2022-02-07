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

int main(){
	
	TLista input = criaLista();
	FILE* file = "./Dicionarios/dic-pt-al.txt";

	fopen( file, "r" );

	

	return 0;
}

