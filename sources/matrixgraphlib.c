#include <stdio.h>
#include <stdlib.h>
#include "matrixgraphlib.h"
#include "inputReader.h"

int grafoVuotoMatrix(grafomat *g){
  return (g == NULL);
}

int nuovoGrafoMatrix(int vertici, grafomat **g, int pesato){   //Funzione che costruisce un grafo con matrice di adiacenza.

  grafomat *nuovo;
  int ret = 0;
  int i;

  if(vertici > 0){//Se il numero di vertici nel grafo è maggiore di zero, tenta di allocare la memoria per il grafo.
    nuovo = (grafomat*)malloc(sizeof(grafomat));

    if(nuovo != NULL){//Se la memoria per il grafo è stata allocata con successo
      nuovo->n_vertici = vertici;
      nuovo->adiacenti = (int*)malloc( (vertici * vertici) * sizeof(int));//alloca memoria per la matrice di adiacenza.

      if(nuovo->adiacenti != NULL) {//se la matrice e' stata allocata con successo
        for(i = 0; i < vertici*vertici; i++){//ne azzera il contenuto
          nuovo->adiacenti[i] = 0;
        }

        if(pesato != 0){

          nuovo->pesi = (int*)calloc( (vertici * vertici), sizeof(int));

          if(nuovo->pesi != NULL){
            nuovo->pesato = 1;
            *g = nuovo;
            ret = 1;
          }else{
            printf("ERRORE in nuovoGrafoMatrix: impossibile allocare memoria per matrice dei pesi\n");
            free(nuovo->adiacenti);
            free(nuovo);
          }

        }else{//se il grafo non era pesato finisce qui
          *g = nuovo;//il puntatore parametro viene fatto puntare al grafo allocato
          ret = 1;//aggiorna il valore che segnala l'esito della funzione
          nuovo->pesato = 0;
          nuovo->pesi = NULL;
        }
      }else{
        printf("ERRORE in nuovoGrafoMatrix: impossibile allocare memoria per matrice di adiacenza\n");
        free(nuovo);
      }
    }else{
      printf("ERRORE in nuovoGrafoMatrix: impossibile allocare memoria per grafo\n");
    }
  }else{
    printf("ERRORE in nuovoGrafoMatrix: impossibile creare grafo di 0 vertici\n");
  }

  return ret;     //Ritorna 1 se la costruzione del grafo è andata a buon fine, 0 altrimenti.
}

void menuGrafoMatrix(grafomat *g){

  int scelta = -1, esci = 0;
  int part, arr, peso = 0;

  if(!grafoVuotoMatrix(g)){

    while(esci == 0){

      do{
        printf("Seleziona operazione\n1 = aggiungiArco\n2 = rimuoviArco\n3 = esci\n");
        getPositive(&scelta);
      }while(scelta < 1 || scelta > 3);

      if(scelta == 1 || scelta == 2){
        do{
          printf("Inserire il vertice di partenza (max %d):", (g->n_vertici)-1);
        }while(!getPositive(&part));

        do{
          printf("Inserire il vertice di arrivo (max %d): ", (g->n_vertici)-1);
        }while(!getPositive(&arr));

        if(g->pesato == 1 && scelta == 1){  //se l'operazione è di aggiunta e il grafo è pesato, allora viene preso da tastiera il peso.
          do{
            printf("Inserire il peso dell'arco.\n");
          }while(!getPositive(&peso));
        }
      }

      printf("\n");

      switch(scelta){
        case 1:
          aggiungiArcoPesatoMatrix(g, part, arr, peso);
          break;
        case 2:
          rimuoviArcoMatrix(g, part, arr);
          break;
        case 3:
          esci = 1;
          break;
      }

    }
  }

  return;
}

int isPesatoMatrix(grafomat *g){

  int ret = 0;

  if(!grafoVuotoMatrix(g)){
    ret = g->pesato;
  }else{
    printf("ERRORE in isPesatoMatrix: Il grafo e' vuoto\n");
  }

  return ret;
}

int numeroVerticiMatrix(grafomat *g){

  int ret;

  if(!grafoVuotoMatrix(g)){
    ret = g->n_vertici;
  }else{
    ret = 0;
  }

  return ret;
}

void stampaGrafoMatrix(grafomat *g){
  int i, j;

  if(!grafoVuotoMatrix(g)){
    for(i = 0; i < numeroVerticiMatrix(g); i++){
      for(j = 0; j < numeroVerticiMatrix(g) ; j++){
        if(g->adiacenti[(i * numeroVerticiMatrix(g)) + j]){
          printf("%d -", i);
          if(g->pesato == 1){
            printf("-%d-", g->pesi[(i * numeroVerticiMatrix(g)) + j]);
          }
          printf("> %d\t", j);
        }
      }
      printf("\n");
    }
  }else{
    printf("ERRORE in stampaGrafoMatrix: grafo vuoto\n");
  }
  return;
}

int numeroArchiMatrix(grafomat *g){

  int ret = 0;
  int i;

  if(!grafoVuotoMatrix(g)){
    for(i = 0; i < g->n_vertici * g->n_vertici; i++){//scorre tutta la matrice di adiacenza

      if(g->adiacenti[i] == 1){
        ret = ret + 1;
      }

    }
  }
  return ret;
}

int modificaArcoMatrix(grafomat *g, int partenza, int arrivo, int op, int peso){

  int ret = 0;

  if(!grafoVuotoMatrix(g)){
    if(g->pesato == 1 || peso == 0){//controlla se si sta cercando di inserire arco pesato in grafo non pesato
      if(partenza < g->n_vertici && arrivo < g->n_vertici){//esistono i vertici di partenza e arrivo

        g->adiacenti[(g->n_vertici * partenza) + arrivo] = op;//aggiunge o elimina l'arco a seconda di op

        if(g->pesato == 1){//se il grafo e' pesato
          g->pesi[(g->n_vertici * partenza) + arrivo] = peso;//aggiunge il peso alla matrice dei pesi o lo imposta a zero nel caso di un'eliminazione
        }
        ret = 1;

      }else{
        printf("ERRORE: Vertice di partenza o arrivo non presenti\n");//TODO questo controllo si puo' rimuovere perché viene effettuato in altri posti (aggiungi, rimuovi)
      }
    }else{
      printf("ERRORE: Impossibile inserire arco pesato in grafo non pesato\n");
    }
  }else{
    printf("ERRORE: grafo vuoto\n");
  }
  return ret;
}

int aggiungiArcoMatrix(grafomat *g, int partenza, int arrivo){

  int ret = 1;

  if(partenza < g->n_vertici && arrivo < g->n_vertici){
    if(g->adiacenti[(partenza * g->n_vertici) + arrivo] == 0){
      if(!modificaArcoMatrix(g, partenza, arrivo, 1, 0)){
        printf("Impossibile aggiungere arco.\n");
        ret = 0;
      }
    }else{
      printf("L'arco %d -> %d e' gia' presente nel grafo\n", partenza, arrivo);
    }
  }else{
    printf("Il vertice di partenza o arrivo non esiste\n");
  }

  return ret;//Ritorna 1 se l'arco è stato aggiunto o è già presente, 0 altrimenti.
}

int aggiungiArcoPesatoMatrix(grafomat *g, int partenza, int arrivo, int peso){

  int ret = 1;

  if(partenza < g->n_vertici && arrivo < g->n_vertici){
    if(g->adiacenti[(partenza * g->n_vertici) + arrivo] == 0){//evita di chiamare modificaArcoMatrix per non modificare il peso dell'arco e mantenere il comportamento della libreria con liste
      if(!modificaArcoMatrix(g, partenza, arrivo, 1, peso)){
        printf("Impossibile aggiungere arco\n");
        ret = 0;
      }
    }else{
      printf("L'arco %d -> %d e' gia' presente nel grafo\n", partenza, arrivo);
    }
  }else{
    printf("Il vertice di partenza o arrivo non esiste\n");
  }

  return ret;
}

int rimuoviArcoMatrix(grafomat *g, int partenza, int arrivo){

    int ret = 1;

    if(partenza < g->n_vertici && arrivo < g->n_vertici){
      if(g->adiacenti[(partenza * g->n_vertici) + arrivo] == 1){
        if(!modificaArcoMatrix(g, partenza, arrivo, 0, 0)){
          printf("Impossibile rimuovere arco.\n");
          ret = 0;
        }
      }else{
        printf("L'arco non e' presente nel grafo\n");
      }
    }else{
      printf("Il vertice di partenza o arrivo non esiste\n");
    }

    return ret;//Ritorna 1 se l'arco è stato rimosso o è non era presente, 0 altrimenti.
}

int indiceMatrix(grafomat *g, int i, int j){//restituisce l'indice della locazione nella matrice di adiacenza con riga i e colonna j
  return (i * g->n_vertici) + j;
}

int esisteArcoMatrix(grafomat *g, int partenza, int arrivo){//restituisce 1 se l'arco dal vertice partenza al vertice arrivo esiste, 0 altrimenti
  int ret = 0;

  if(!grafoVuotoMatrix(g)){
    if(partenza <= g->n_vertici && arrivo <= g->n_vertici){

      ret = g->adiacenti[indiceMatrix(g, partenza, arrivo)];

    }else{
      printf("ERRORE in esisteArco: vertice di partenza o arrivo fuori dal range\n");
    }
  }else{
    printf("ERRORE in esisteArco: grafo vuoto\n");
  }

  return ret;
}

int pesoArcoMatrix(grafomat *g, int partenza, int arrivo){

  int ret = 0;

  if(!grafoVuotoMatrix(g)){
    if(esisteArcoMatrix(g, partenza, arrivo)){

      if(g->pesato == 1){//implicitamente se il grafo non e' pesato ritorna 0
        ret = g->pesi[(partenza * g->n_vertici) + arrivo];
      }

    }else{
      printf("ERRORE in pesoArcoMatrix: l'arco non esiste\n");
    }
  }else{
    printf("ERRORE in pesoArcoMatrix: grafo vuoto\n");
  }

  return ret;
}

int esisteVerticeMatrix(grafomat *g, int v){//restituisce 1 se il vertice è presente nel grafo, 0 altrimenti

  int ret = 0;

  if(!grafoVuotoMatrix(g)){
    ret = (v < g->n_vertici);
  }else{
    printf("ERRORE in esisteVerticeMatrix: Il grafo e' vuoto\n");
  }

  return ret;
}

int aggiungiVerticeMatrix(grafomat *g){

  int ret = 0;
  int i, j;
  int *matrice = NULL;
  int *pesi = NULL;
  int vertici;

  if(!grafoVuotoMatrix(g)){

    vertici = g->n_vertici + 1;
    matrice = (int *)calloc(vertici*vertici, sizeof(int));
    if(g->pesato == 1){//alloca nuova matrice di pesi solo se il grafo e' pesato
      pesi = (int*)calloc(vertici*vertici, sizeof(int));
    }

    if(matrice != NULL && (g->pesato == 0 || pesi != NULL)){//se la memoria e' stata allocata per entrambi o per adiacenti in grafo non pesato

      i = j = 0;
      while(j < g->n_vertici * g->n_vertici){

        if(j != 0 && (j % g->n_vertici) == 0){//se j arriva su un multiplo di n_vertici
          i++;//aumenta i prima di copiare per essere nella posizione giusta
        }

        matrice[i] = g->adiacenti[j];
        if(g->pesato == 1){
          pesi[i] = g->pesi[j];
        }
        j++;
        i++;
      }

      free(g->adiacenti);
      g->adiacenti = matrice;
      if(g->pesato == 1){
        free(g->pesi);
        g->pesi = pesi;
      }
      g->n_vertici = vertici;
      ret = 1;
    }else{
      printf("ERRORE in aggiungiVerticeMatrix: impossibile allocare nuova matrice di adiacenza o nuova matrice dei pesi\n");
    }
  }else{
    printf("ERRORE in aggiungiVerticeMatrix: grafo vuoto.\n");
  }
  return ret;
}

int rimuoviVerticeMatrix(grafomat *g, int vertice){

  int i = 0, j = 0, ret = 0;
  int *matrice = NULL;
  int *pesi;
  int vertici;

  if(!grafoVuotoMatrix(g)){

    vertici = g->n_vertici - 1;
    matrice = (int *)malloc(vertici * vertici * sizeof(int));
    pesi = (int*)malloc(vertici * vertici * sizeof(int));

    if(matrice != NULL){
      while(j < vertici * vertici){

        if(i % g->n_vertici == vertice){ //tutti gli archi che vanno nel vertice da eliminare
          i++;
        }else if(i == vertice * g->n_vertici){ //primo arco del vertice da eliminare
          i += g->n_vertici;
        }else{
          matrice[j] = g->adiacenti[i];
          if(g->pesato == 1){
            pesi[j] = g->pesi[i];
          }
          j++;
          i++;
        }
      }

      free(g->adiacenti);
      g->adiacenti = matrice;
      if(g->pesato == 1){
        free(g->pesi);
        g->pesi = pesi;
      }
      g->n_vertici = vertici;
      ret = 1;
    }else{
      printf("ERRORE in rimuoviVerticeMatrix: impossibile allocare memoria per nuova matrice di adiacenza.\n");}
  }else{
    printf("ERRORE in rimuoviVerticeMatrix: grafo vuoto.\n");
  }

  return ret;
}

void randomizzaGrafoMatrix(grafomat *g){

  int j, z;

  if(!grafoVuotoMatrix(g)){

    for(j = 0; j < numeroVerticiMatrix(g); j++){
      for(z = 0; z < numeroVerticiMatrix(g); z++){
        if(rand() % 2 == 1){
          aggiungiArcoMatrix(g, j, z);
        }
      }
    }
  }else{
    printf("ERRORE in randomizzaGrafoMatrix: Il grafo e' vuoto.\n");
  }
  return;
}

void randomizzaGrafoPesatoMatrix(grafomat *g, int massimo){

  int i, j;

  if(!grafoVuotoMatrix(g)){
    if(g->pesato == 1){
      if(massimo > 0){
        for(i = 0; i < g->n_vertici; i++){
          for(j = 0; j < g->n_vertici; j++){
            if(rand() % 2 == 1){
              aggiungiArcoPesatoMatrix(g, i, j, rand() % (massimo+1));
            }
          }
        }
      }else{
        printf("ERRORE in randomizzaGrafoPesatoMatrix: massimo negativo\n");
      }
    }else{
      printf("ERRORE in randomizzaGrafoPesatoMatrix: il grafo non e' pesato\n");
    }
  }else{
    printf("ERRORE in randomizzaGrafoPesatoMatrix: Il grafo e' vuoto\n");
  }

  return;
}
