#include "taddic.h"

#include <stdlib.h>
#include <string.h>

#define TAM_DEFAULT_VET_DIC 1024

int funcao_hash(tipochave k, TDicionario dic) {
    int soma = 0;
    int pos_vet;

    for(int i=0; i < strlen((char *)k); i++)
        soma = soma + (int)k[i];

    pos_vet = soma % dic->tam_vet_dic;

    return pos_vet;
} //funcao_hash

/*
 * Aloca e retorna o endere�o de uma vari�vel din�mica do tipo TDicionario.
 */
TDicionario criaDic(){
    TDicionario template = criaDicTam(TAM_DEFAULT_VET_DIC);
    return template;
} // fim criaDic

TDicionario criaDicTam(int tamvet){
    TDicionario template = (tcabecDic *)malloc(sizeof(tcabecDic));
    template->vetdic = (TLista)malloc(sizeof(TLista) * tamvet);
    template->tam_vet_dic = tamvet;

    for(int i=0; i < tamvet; i++)
        template->vetdic[i] = NULL;

    return template;
}// fim criaDicTam

int lenDic (TDicionario dic){
    int somaTotal = 0;

    for(int i=0; i < dic->tam_vet_dic;i++)
        if(dic->vetdic[i] != NULL)
            somaTotal= somaTotal + lenLista(dic->vetdic[i]);

    return somaTotal;
}; //fim de lenDic

TLista keys(TDicionario dic){
    TLista lstkeys = criaLista();
    tentrada_dic entrada_dic; /* dado da lista � igual a ENTRADA do DICIONARIO */

    for(int i=0; i < dic->tam_vet_dic; i++)
        if(dic->vetdic[i] != NULL){
            for(int j=0; j < lenLista(dic->vetdic[i]); j++){
                entrada_dic = infoLista(dic->vetdic[i],j);
                appendLista(lstkeys, entrada_dic->key);
            }
        }
    return lstkeys;
} // fim keys

TLista values(TDicionario dic){
    TLista lstvalues = criaLista();
    tentrada_dic entrada_dic; /* dado da lista � igual a ENTRADA do DICIONARIO */

    for(int i=0; i < dic->tam_vet_dic; i++)
        if(dic->vetdic[i] != NULL){
            for(int j=0; j < lenLista(dic->vetdic[i]); j++){
                entrada_dic = infoLista(dic->vetdic[i],j);
                appendLista(lstvalues, entrada_dic->value);
            }
        }
    return lstvalues;
} // fim values


TDicionario adicionaDic(TDicionario dic, tipochave chave, tdado dado){
    int indice_vet = funcao_hash(chave,dic);
    tentrada_dic entrada = malloc(sizeof(struct tentrada));

    if(dic->vetdic[indice_vet] == NULL)
        dic->vetdic[indice_vet] = criaLista();

    strcpy(entrada->key,chave);
    entrada->value = dado;

    appendLista(dic->vetdic[indice_vet],entrada);

    return dic;
} //fimadicionaDic

BOOLEAN inDic(TDicionario dic, tipochave chave){
    int indice_vet = funcao_hash(chave,dic);
    TLista lst = dic->vetdic[indice_vet];
    tentrada_dic entrada;

    for(int i=0; i < lenLista(lst); i++){
        entrada= infoLista(lst,i);
        if(strcmp((char *)entrada->key,(char *)chave) == 0)
            return TRUE;
    }
    return FALSE;
} // fim inDic

tentrada_dic private_busca_entrada(TLista lst, tipochave chave){
    tentrada_dic entrada;

    for(int i=0; i < lenLista(lst); i++){
    entrada = infoLista(lst,i);
    if(strcmp((char *)entrada->key,(char *)chave) == 0)
        return entrada;
    }
    return NULL;
} //fim private_busca_entrada

int private_busca_indice_entrada(TLista lst, tipochave chave){ // if(strcmp((char *)entrada->key,(char *)chave) == 0)

    tentrada_dic entrada;

    for(int i=0; i < lenLista(lst); i++){
    	entrada = infoLista(lst,i);
    	if(strcmp((char *)entrada->key,(char *)chave) == 0)
    		return i;
    }
    return -1;
} //fim private_busca_entrada


TDicionario alteraDic(TDicionario dic, tipochave chave, tdado novo_dado) {
    if(inDic(dic,chave) == FALSE)
        return dic;
    else {
        int indice_vet = funcao_hash(chave, dic);
        TLista lst = dic->vetdic[indice_vet];
        tentrada_dic entrada = private_busca_entrada(lst,chave);
        entrada->value = novo_dado;
    }
    return dic;
} // fim alteraDic

tdado obtemDic(TDicionario dic, tipochave chave){
    int indice_vet= funcao_hash(chave,dic);
    TLista lst = dic->vetdic[indice_vet];
    if(lst == NULL)
        return NULL;
    tentrada_dic entrada = private_busca_entrada(lst,chave);

    return entrada->value;
 } //fim de obtemDic

tdado removeDic(TDicionario dic, tipochave chave){
    if(inDic(dic,chave) == FALSE)
        return dic;
    else {
        tdado salvo;
        tentrada_dic entrada;
        int indice_vet = funcao_hash(chave, dic);
        TLista lst = dic->vetdic[indice_vet];
        int pos = private_busca_indice_entrada(lst, chave);
        entrada = infoLista(lst,pos);
        salvo = entrada->value;
        removeLista(lst, pos);

        return salvo;
    }
} //fim removeDic

// TDicionario clonaDic(TDicionario dic){
//     return dic;
// } // fim clonaDic

TDicionario clonaDic(TDicionario dic){

  int tam = dic->tam_vet_dic;

  TDicionario template = criaDicTam(tam);

  tentrada_dic entrada_dic; /* dado da lista é igual a ENTRADA do DICIONARIO */

    for(int i=0; i < dic->tam_vet_dic; i++){
        if(dic->vetdic[i] != NULL){
            for(int j=0; j < lenLista(dic->vetdic[i]); j++){
                entrada_dic = infoLista(dic->vetdic[i],j);
                adicionaDic(template, entrada_dic->key, entrada_dic->value);
            }
        }
    }

  return template;
} // fim clonaDic

// A
// B
// A+B

TDicionario concatenaDic(TDicionario dicA, TDicionario dicB){

    TDicionario aux = clonaDic(dicA);
    tdado ultimoAux = ultLista( *(aux->vetdic) );
    tdado primeiroB = primLista( *(dicB->vetdic) );

    ultimoAux = primeiroB;

    return aux;
}

