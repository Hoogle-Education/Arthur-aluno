/*
 * tadlista.h
 *
 *  Created on: 25 de nov. de 2021
 *      Author: ernani
 */

#ifndef TADLISTA_H_
#define TADLISTA_H_

#define MAXCHAR 100

typedef void *tdado;

typedef struct tno {
	tdado dado;
	struct tno *anterior; // <== ALTERA��O P/ ENCADEAMENTO DUPLO
	struct tno *proximo;
} tipoNo;

typedef tipoNo *pnoh;

typedef struct {
	int tamanho;
	pnoh primeiro;
	pnoh ultimo;
} tcabec;

typedef tcabec *TLista;

TLista criaLista();

TLista appendLista(TLista lst, tdado dado);
TLista insertLista(TLista lst,int i, tdado dado);
tdado removeLista(TLista lst,int i);

tdado infoLista(TLista lst,int i);
int lenLista(TLista lst);

tdado primLista(TLista lst);
tdado ultLista(TLista lst);

int indexLista(TLista lst, tdado dado);
TLista clearLista(TLista lst);
TLista clonaLista(TLista lst);

#endif /* TADLISTA_H_ */
