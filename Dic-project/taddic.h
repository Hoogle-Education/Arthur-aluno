/*
 *
 *
 *  taddic.h
 *
 */

#ifndef TADDIC_V2_H_
#define TADDIC_V2_H_

#include "stdlib.h"
#include "tadlista.h"

#define TAMDIC 1000
#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

typedef unsigned char tipochave[256];

typedef struct tentrada{
    tipochave key;
    tdado value;
} *tentrada_dic;

// Vers�o 1.0: naive
// typedef TLista TDicionario[TAMDIC];

// vers�o 2.0 better -----------
typedef struct {
    int tam_vet_dic;
    TLista *vetdic;
}tcabecDic;

typedef tcabecDic *TDicionario;
//-----------------------------

TDicionario criaDicTam(int tamvet);
TDicionario criaDic();
TDicionario adicionaDic(TDicionario dic, tipochave chave, tdado d);
TDicionario alteraDic(TDicionario dic, tipochave chave, tdado d);
tdado obtemDic(TDicionario dic, tipochave chave);
tdado removeDic(TDicionario dic, tipochave chave);
int lenDic (TDicionario dic);
BOOLEAN inDic(TDicionario dic, tipochave chave);
TLista keys(TDicionario dic);
TLista values(TDicionario dic);
TDicionario clonaDic(TDicionario dic);
TDicionario concatenaDic(TDicionario dicA,
TDicionario dicB);

#endif
