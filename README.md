# LabASD
Raccolta di soluzioni ad esercizi di laboratorio che nel tempo si trasformerà in libreria di funzioni di base per manipolare strutture dati.

## Utilizzo
#### 1. con un IDE
  * Il file .h della libreria che si intende utilizzare deve essere incluso nel file main del progetto con l'istruzione #include "esempio.h" e si può spostare nella stessa directory di questo.
  * Il file .c della stessa libreria deve essere incluso nel progetto attraverso le modalità previste dall'IDE. Non è importante la sua posizione purché questa non cambi dopo l'inclusione.
#### 2. da linea di comando
  * Il file .h deve essere incluso in ognuno dei source files che utilizzano funzioni al suo interno. La posizione del file deve essere o una di quelle di deafult (all'interno della directory include del compilatore o nella directory corrente quando si lancia il comando di compilazione) oppure si può specificare. Con compilatore GNU la flag ```-I <directory>``` specifica le directory dove cercare i file header. ```<directory>``` deve essere unò o più path assoluti o relativi verso directory all'interno del file system.
  * Il file .c deve essere mandato in compilazione insieme a ogni altro source file necessario utilizzando il suo path assoluto o relativo rispetto alla directory da dove viene lanciato il comando di compilazione.

## Aprire una issue
#### per una nuova feature
Se ritieni che una feature debba essere inclusa nella libreria utilizza il tag feature e descrivi al meglio cosa dovrebbe essere aggiunto. Se la feature da aggiungere è una funzione all'interno di un file esistente, il nome della issue deve iniziare con il nome del file da modificare racchiuso fra parentesi quadre.
#### per un bug
Prima di aprire una issue per segnalare un bug, assicurati che il comportamento non sia conforme a quanto presente nell'header file in cui la funzione è descritta. Se hai testato un file della libreria e hai incontrato un bug, apri una issue utilizzando il tag bug. Descrivi al meglio la natura del problema, includi input di esempio che causano il bug ad ogni esecuzione e metti a confronto il comportamento errato con il comportamento "intended".

## Proporre modifiche
Prima di Proporre modifiche, apri una issue che descriva le aggiunte che intendi apportare per verificare che queste non siano già in corso d'opera.

Se hai scelto di contribuire, segui questi passi
1. Forka la repository
1. Fai le modifiche sul tuo fork seguendo le [regole di formattazione](#formattazione)
1. Crea una pull request verso il branch "esame" della repository originale

## Formattazione
Un buon esempio da seguire sono i file graphlib.c e graphlib.h, in particolare:
* Le parentesi graffe di apertura di un blocco vanno sulla stessa riga della corrispondente istruzione if, for, while etc...
* Eventuali struct utilizzate vanno definite nel file .c e dichiarate nel file .h per mascherare i campi all'interno.
* I nomi dei paramentri devono essere significativi e devono essere riportati nel file .h.
* Le variabili locali dovrebbero essere dichiarate una per riga ed essere commentate qualora il loro scopo non sia ovvio.
* I commenti alle funzioni nei file .h devono essere nel formato:
  1. Descrizione dei parametri.
  1. Eventuali condizioni per i parametri.
  1. Azioni collaterali eseguite dalla funzione.
  1. Significato del valore ritornato dalla funzione.
