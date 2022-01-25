// ----------------------------
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 200
// ----------------------------

typedef struct TregCovidES {
  char dataDiagnostico[14];
  char classificacao[23];
  char municipio[30];
  char bairro[30];
  char sexo[1];
  char racaCor[12];
} tregCovidES ;
// ----------------------------
// global variables

typedef struct Classificacao{
  int nBrancos;
  int nAmarelos;
  int nPretos;
  int nIndigenas;
  int nPardos;
  int nIgnorados;
} classificacao ;

// ----------------------------

classificacao confirmados, descartados, suspeitos;

confirmados = {
  .nBrancos = 0,
  .nAmarelos = 0,
  .nPretos = 0,
  .nIndigenas = 0,
  .nPardos = 0,
  .nIgnorados = 0
};

descartados = {
  .nBrancos = 0,
  .nAmarelos = 0,
  .nPretos = 0,
  .nIndigenas = 0,
  .nPardos = 0,
  .nIgnorados = 0
};

suspeitos = {
  .nBrancos = 0,
  .nAmarelos = 0,
  .nPretos = 0,
  .nIndigenas = 0,
  .nPardos = 0,
  .nIgnorados = 0
};

// ----------------------------

// filtrar as pessoas 

// ----------------------------

int main(){

  tregCovidES bancoCSV[30000];

  FILE *csvFile;
  char *splitedData;
  char buffer[MAXCHAR];
  int line = 1;

  csvFile = fopen("microdados-stat-covid-19-tarefa01.csv", "r");

  while( !feof(csvFile) ){

    fgets(buffer, MAXCHAR, csvFile);
    
    printf("row %d: %s", line, buffer);

    // catch the first data
    splitedData = strtok(buffer, ";");
    strcpy(bancoCSV[line].dataDiagnostico, splitedData);

    int dataID = 1;

    while( splitedData != NULL ){

      if(dataID == 1){
        dataID++;
        continue;
      }
      
      splitedData = strtok(buffer, ";");

      switch (dataID){
        case 2:
          strcpy(bancoCSV[line].classificacao, splitedData);
          break;
        case 3:
          strcpy(bancoCSV[line].municipio, splitedData);        
          break;
        case 4:
          strcpy(bancoCSV[line].bairro, splitedData);
          break;
        case 5:
          strcpy(bancoCSV[line].sexo, splitedData);
          break;
        case 6:
          strcpy(bancoCSV[line].racaCor, splitedData);
          break;
      }
      dataID++;
    }

    filterPerson(bancoCSV[line]);

    line++;    
  }
  fclose(csvFile);

  // daq

  return 0;
}

// ----------------------------