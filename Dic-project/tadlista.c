/*
 * tadlista.c
 *
 *  Created on: 25 de nov. de 2021
 *      Author: ernani
 */
#include <stdlib.h>
#include "tadlista.h"

TLista criaLista() {
	TLista c = (tcabec *)malloc(sizeof(tcabec));

	c->tamanho = 0;
	c->primeiro = NULL;
	c->ultimo = NULL;

	return c;
}

TLista appendLista(TLista lst, tdado dado) {
	// criar novo nó
	pnoh novono = (tipoNo *)malloc(sizeof(tipoNo));

	// associar dado a nó
	novono->dado = dado;
	novono->anterior = lst->ultimo; // <== ALTERAÇÃO P/ ENCADEAMENTO DUPLO
	novono->proximo = NULL;

	// processa lista vazia.
	if(lst->tamanho == 0){
		lst->primeiro = novono;
		lst->ultimo = novono;
	} // processa lista não vazia.
	else {
		// inserir novo nó na ultima posição da lista
		lst->ultimo->proximo = novono;

		// atualizar cabeçalho
		lst->ultimo = novono;
	}

	lst->tamanho++;

	return lst;
}

int lenLista(TLista lst) {
	return lst->tamanho;
}

tdado primLista(TLista lst) {
	return lst->primeiro->dado;
}

tdado ultLista(TLista lst) {
	return lst->ultimo->dado;
}

TLista insertLista(TLista lst,int i, tdado dado) {
  int tam = lenLista(lst);

  if((i < 0) || (i > tam)) return NULL;

  if(lenLista(lst) == 0)
    appendLista(lst,dado);
  else
    if(i==tam)
      appendLista(lst,dado);
    else {
        if(i == 0) {
          pnoh novono = (tipoNo *)malloc(sizeof(tipoNo));
          novono->dado = dado;

          novono->proximo = lst->primeiro;
          novono->anterior = NULL;
          lst->primeiro = novono;
        }
        else {
          pnoh novono = (tipoNo *)malloc(sizeof(tipoNo));
          novono->dado = dado;

          pnoh aux = lst->primeiro;
          int pos = 0;

          while(pos != (i - 1)){
            aux = aux->proximo;
            pos++;
          }
          novono->proximo = aux->proximo;
          aux->proximo->anterior = novono;
          novono->anterior = aux;
          aux->proximo = novono;
        }

        lst->tamanho++;
    }

  return lst;
}

tdado infoLista(TLista lst,int i) {
  int tam = lenLista(lst);

  if((tam == 0) || (i < 0) || (i > tam))
    return NULL;

  if(i == 0) return lst->primeiro->dado;

  else if(i == tam - 1) return lst->ultimo->dado;


  else{
    pnoh aux = lst->ultimo;
    int pos = tam;

    while(pos-1 != i){
      aux = aux->anterior;
      pos--;
    }

    return aux->dado;
  }

}

tdado removeLista(TLista lst,int i) {
  int tam = lenLista(lst);

  if((i < 0) || (i > tam) || (tam == 0)) return NULL;

  if(tam == 1) { // remover o primeiro/ultimo de uma lista de 1 só elemento.
     pnoh aux = lst->primeiro;
     lst->primeiro = NULL;
     lst->ultimo = NULL;
     aux->anterior = NULL;
     lst->tamanho--;

     // salva o dado e libera memória do nó.
     tdado d =aux->dado;
     free(aux);

     return d;
  }
  else { // remover o primeiro de uma lista com mais de 1 elemento.
	 if(i == 0){
	   pnoh aux = lst->primeiro;
	   lst->primeiro = aux->proximo;

     aux->proximo->anterior = NULL;

	   lst->tamanho--;

	   // salva o dado e libera memória do nó.
	   tdado d =aux->dado;
	   free(aux);

	   return d;
	 }
	 else {
	   if(i == tam - 1) { // remover o ultimo de uma lista com mais de 1 elemento.
		 pnoh aux = lst->ultimo;

		 // caminha até o penúltimo
		 pnoh penultimo = lst->primeiro;
		 int pos = 0;

		 while(pos != i-1){
			 penultimo = penultimo->proximo;
			 pos++;
		 }

		 penultimo->proximo = NULL;
		 lst->ultimo = penultimo;

		 lst->tamanho--;

		 // salva o dado e libera memória do nó.
	     tdado d =aux->dado;
	     free(aux);

	     return d;
	   }     // remover o i-ésimo (entre primeiro e último)
	   else {// de uma lista com mais de 1 elemento.
		 // caminha até o nó anterior ao que será removido.
		 pnoh anterior = lst->primeiro;
		 int pos = 0;

		 while(pos != i-1){
			 anterior = anterior->proximo;
			 pos++;
		 }

		 // remove o nó da lista.
		 pnoh aux = anterior->proximo;
     pnoh apos = anterior->proximo;
		 apos = aux->proximo;
     apos->anterior = anterior;
		 lst->tamanho--;

		 // salva o dado e libera memória do nó.
		 tdado d = aux->dado;
		 free(aux);

		 return d;
	   } // fim else linha 172
	 } // fim else linha 148
  } // fim else linha 136
} // fim removeLista

int indexLista(TLista lst, tdado dado){
  int tam = lenLista(lst);
  int i;
  tdado dadolst;

  if(tam == 0) return -1;

  i = 0;
  dadolst = infoLista(lst,i);
  while((i < tam) && (dado != dadolst)){
	  i++;
  	  dadolst = infoLista(lst,i);
  }

  if(i < tam) return i;
  else return -1;
} // fim indexLista

TLista clearLista(TLista lst){
  int tam = lenLista(lst);

  if(tam == 0) return lst;

  while(lenLista(lst) > 0)
	  removeLista(lst,0);

  return lst;
} // fim clearLista

TLista clonaLista(TLista lst){
  TLista clone = criaLista();
  int tam = lenLista(lst);

  if(tam == 0) return clone;

  for(int i=0;i < tam; i++)
	 appendLista(clone,infoLista(lst,i));

  return clone;
} // fim cloneLista
