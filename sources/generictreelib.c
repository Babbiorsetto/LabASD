#include <stdio.h>
#include <stdlib.h>
#include "generictreelib.h"
#include "inputReader.h"

galbero nuovoGnodo(int key){

  galbero ret = (galbero)malloc(sizeof(gnodo));

  if(ret != NULL){
    ret->info = key;
    ret->figlio = NULL;
    ret->fratello = NULL;
  }else{
    printf("ERRORE in nuovoGnodo: impossibile allocare memoria\n");
  }

  return ret;
}


int setFratello(galbero sinistro, galbero destro){

 int ret = 1;

  if(sinistro != NULL){
    sinistro->fratello = destro;
  }else{
    ret = 0;
    printf("ERRORE in setFratello: sinistro NULL\n");
  }

  return ret;
}


int setFiglio(galbero padre, galbero figlio){

  int ret = 1;

  if(padre != NULL){
    padre->figlio = figlio;
  }else{
    ret = 0;
    printf("ERRORE in setFiglio: padre NULL\n");
  }

  return ret;
}

galbero getFiglio(galbero padre){

  galbero ret = NULL;

  if(padre != NULL){
    ret = padre->figlio;
  }else{
    printf("ERRORE in getFiglio: padre NULL\n");
  }

  return ret;
}

galbero getFratello(galbero sinistro){

  galbero ret = NULL;

  if(sinistro != NULL){
    ret = sinistro->fratello;
  }else{
    printf("ERRORE in getFratello: sinisto NULL\n");
  }

  return ret;
}
