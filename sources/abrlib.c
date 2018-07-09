#include <stdio.h>
#include <stdlib.h>
#include "abrlib.h"

int alberoVuoto(albero radice){

  return (radice == NULL);
}

void inizializzaABR(albero *radice){

  int scelta = -1;
  int x;
  int i = 0;

  do{
    printf("Quanti elementi inserire nell'ABR?: ");
    scanf("%d", &scelta);
  }while(scelta < 0);

  while(i < scelta){
    printf("inserire elemento %d: ", i+1);
    scanf("%d", &x);

    if(!inserisciInABR(radice, x)){
      printf("Elemento già presente.\n");
    }else{
      i++;
    }
  }
  printf("\n");

  return;
}

int valoreRadice(albero radice, int *val){
  int ret = 0;

  if(!alberoVuoto(radice)){
    *val = radice->info;
    ret = 1;
  }
  return ret;
}

albero figlioSx(albero radice){

  albero ret = NULL;

  if(!alberoVuoto(radice)){
    ret = radice->sx;
  }

  return ret;
}

albero figlioDx(albero radice){

  albero ret = NULL;

  if(!alberoVuoto(radice)){
    ret = radice->dx;
  }

  return ret;
}

albero costruisciAlbero(int e, albero s, albero d){

  albero temp;

  temp = (albero)malloc(sizeof(nodo));

  if(temp != NULL){
    temp->info = e;
    temp->dx = d;
    temp->sx = s;
  }

  return temp;
}

albero deallocaNodo(albero radice){
  if(!alberoVuoto(radice)){
    free(radice);
  }
  return NULL;
}

void visitaPreOrder(albero radice){

  int temp;

  if(valoreRadice(radice, &temp)){
    printf("%d ", temp);
    visitaPreOrder(figlioSx(radice));
    visitaPreOrder(figlioDx(radice));
  }
  return;
}

void visitaInOrder(albero radice){

  int temp;

  if(valoreRadice(radice, &temp)){
    visitaInOrder(figlioSx(radice));
    printf("%d ", temp);
    visitaInOrder(figlioDx(radice));
  }
  return;
}

void visitaPostOrder(albero radice){

  int temp;

  if(valoreRadice(radice, &temp)){
    visitaPostOrder(figlioSx(radice));
    visitaPostOrder(figlioDx(radice));
    printf("%d ", temp);
  }
  return;
}

int ricercaInABR(albero radice, int key){

  int ret = 0;
  int temp;

  if(valoreRadice(radice, &temp)){
    if(temp == key){
      ret = 1;
    }else if(temp > key){
      ret = ricercaInABR(figlioSx(radice), key);
    }else{
      ret = ricercaInABR(figlioDx(radice), key);
    }
  }

  return ret;
}

int inserisciInABR(albero *radice, int e){

  int temp;
  int ret;
  albero x;

  if(!valoreRadice(*radice, &temp)){
    x = costruisciAlbero(e, NULL, NULL);
    if(x != NULL){
      *radice = x;
      ret = 1;
    }else{
      printf("ERRORE in inserisciInABR: impossibile allocare memoria\n");
      ret = 0;
    }
  }else if(e < temp){
    ret = inserisciInABR(&((*radice)->sx), e);
  }else if(e > temp){
    ret = inserisciInABR(&((*radice)->dx), e);
  }else{
    ret = 0;//l'elemento era gia' presente
  }

  return ret;
}

int minimoABR(albero radice){

  int temp, ret = -1;//ritorna -1 se la radice era nulla

  if(valoreRadice(radice, &temp)){

    if(figlioSx(radice) == NULL){
      ret = temp;
    }else{
      ret = minimoABR(figlioSx(radice));
    }
  }

  return ret;
}

void eliminaInABR(albero *radice, int e){

  int temp, minimo;
  albero swap;

  if(valoreRadice(*radice, &temp)){
    if(e < temp){
      eliminaInABR(&((*radice)->sx), e);
    }else if(e > temp){
      eliminaInABR(&((*radice)->dx), e);
    }else{//e == temp
      if(figlioSx(*radice) == NULL && figlioDx(*radice) == NULL){
        *radice = deallocaNodo(*radice);
      }else if(figlioSx(*radice) == NULL){
        swap = *radice;
        *radice = figlioDx(*radice);
        swap = deallocaNodo(swap);
      }else if(figlioDx(*radice) == NULL){
        swap = *radice;
        *radice = figlioSx(*radice);
        swap = deallocaNodo(swap);
      }else{
        minimo = minimoABR(figlioDx(*radice));
        (*radice)->info = minimo;
        eliminaInABR(&((*radice)->dx), minimo);
      }
    }
  }

  return;
}

void randomizzaABR(albero *radice, int numeroElementi, int valoreMax){

  int i = 0;

  if(alberoVuoto(*radice)){
    if(numeroElementi <= valoreMax){
      while(i < numeroElementi){
        if(inserisciInABR(radice, ( rand() % valoreMax ) + 1) ){
          i++;
        }
      }
    }else{
      printf("ERRORE in randomizzaABR: numeroElementi non puo' essere maggiore di valoreMax\n");
    }
  }else{
    printf("ERRORE in randomizzaABR: l'albero di partenza deve essere vuoto\n");
  }

  return;
}
