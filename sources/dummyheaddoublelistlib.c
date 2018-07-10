#include <stdio.h>
#include <stdlib.h>
#include "dummyheaddoublelistlib.h"
#include "inputReader.h"

int listaVuotaDummy(dummyList dum){

  int ret = 0;

  if(dum == NULL){
    printf("ERRORE in listaVuotaDummy: puntatore NULL\n");
    ret = 1;
  }else if(dum->next == dum){
    ret = 1;
  }

  return ret;
}

dummyList nuovaListaDummy(void){

  dummyList tmp = (dummyList)malloc(sizeof(dummyNode));

  if(tmp != NULL){
    tmp->info = -100;
    tmp->next = tmp;
    tmp->prev = tmp;
  }else{
    printf("ERRORE in nuovaListaDummy: impossibile allocare memoria per nuova lista\n");
  }
  return tmp;
}

dummyList precedenteDummy(dummyList nodo){
  dummyList ret = NULL;
  if(nodo != NULL){
    ret = nodo->prev;
  }
  return ret;
}

dummyList successivoDummy(dummyList nodo){
  dummyList ret = NULL;
  if(nodo != NULL){
    ret = nodo->next;
  }
  return ret;
}

int valoreDummy(dummyList nodo){
  int ret = 0;
  if(nodo !=NULL){
    ret = nodo->info;
  }
  return ret;
}

int aggiungiInCodaDummy(dummyList dum, int k){

  int ret = 1;

  if(dum != NULL){

    dummyList tmp = (dummyList)malloc(sizeof(dummyNode));
    if(tmp != NULL){

      tmp->info = k;
      tmp->next = dum;
      tmp->prev = dum->prev;
      dum->prev->next = tmp;
      dum->prev = tmp;
    }else{
      printf("ERRORE in aggiungiInCodaDummy: Impossibile allocare memoria per nuovo nodo\n");
      ret = 0;
    }
  }else{
    printf("ERRORE in aggiungiInCodaDummy: il puntatore passato non contiene una lista\n");
    ret = 0;
  }

  return ret;
}

int aggiungiInTestaDummy(dummyList dum, int k){

  int ret = 1;

  if(dum != NULL){

    dummyList tmp = (dummyList)malloc(sizeof(dummyNode));
    if(tmp != NULL){

      tmp->info = k;
      tmp->next = dum->next;
      tmp->prev = dum;
      dum->next->prev = tmp;
      dum->next = tmp;
    }
    else{
      printf("ERRORE in aggiungiInTestaDummy: impossibile allocare memoria per nuovo nodo\n");
      ret = 0;
    }
  }else{
    printf("ERRORE in aggiungiInTestaDummy: il puntatore passato non contiene una lista\n");
    ret = 0;
  }
  return ret;
}

void stampaListaDummyHelper(dummyList curr, dummyList dum){

  if(curr!=dum){
    printf("%d -> ", curr->info);
    stampaListaDummyHelper(curr->next, dum);
  }
  return;
}

void stampaListaDummy(dummyList dum){

  if(!listaVuotaDummy(dum)){
    stampaListaDummyHelper(dum->next, dum);
  }
  printf("//\n");

  return;
}

void svuotaListaDummy(dummyList dum){

  dummyList curr = NULL;
  dummyList prev = NULL;

  if(!listaVuotaDummy(dum)){

    curr = dum->next;

    while(curr != dum){
      prev = curr;
      curr = curr->next;
      free(prev);
    }
  }

  return;
}

dummyList deallocaListaDummy(dummyList dum){

  if(!listaVuotaDummy(dum)){
    svuotaListaDummy(dum);
    free(dum);
  }

  return NULL;
}

int ricercaInListaDummy(dummyList dum, int k){

  int ret = 0;

  if(!listaVuotaDummy(dum)){

    dummyList curr = dum->next;

    while(ret == 0 && curr!=dum){

      if(curr->info == k){
        ret = 1;
      }
      curr = curr->next;
    }
  }

  return ret;
}
