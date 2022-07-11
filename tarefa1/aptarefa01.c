// ----------------------------
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 200
// ----------------------------

typedef struct TregCovidES {
  char dataDiagnostico[14];
  char classificacao[13];
  char municipio[30];
  char bairro[30];
  char sexo[1];
  char racaCor[12];
} tregCovidES ;
// ----------------------------
// global variables

typedef struct Classificacao{
  double nBrancos;
  double nAmarelos;
  double nPretos;
  double nIndigenas;
  double nPardos;
  double nIgnorados;
  double nTotal;
} classificacao ;

// ----------------------------

classificacao confirmados = {
  .nBrancos = 0.0,
  .nAmarelos = 0.0,
  .nPretos = 0.0,
  .nIndigenas = 0.0,
  .nPardos = 0.0,
  .nIgnorados = 0.0,
  .nTotal = 0.0
};

classificacao suspeitos = {
  .nBrancos = 0.0,
  .nAmarelos = 0.0,
  .nPretos = 0.0,
  .nIndigenas = 0.0,
  .nPardos = 0.0,
  .nIgnorados = 0.0,
  .nTotal = 0.0
};

classificacao descartados = {
  .nBrancos = 0.0,
  .nAmarelos = 0.0,
  .nPretos = 0.0,
  .nIndigenas = 0.0,
  .nPardos = 0.0,
  .nIgnorados = 0.0,
  .nTotal = 0.0
};

// ----------------------------
// filtrar as pessoas 

void filterPerson( tregCovidES pessoa ){

  if( strcmp(pessoa.classificacao , "Confirmados") == 0 ){
    confirmados.nTotal += 1.0;

    if( strcmp(pessoa.racaCor, "Branca\n") == 0 )
      confirmados.nBrancos += 1.0;
    else if( strcmp(pessoa.racaCor, "Amarela\n") == 0 )
      confirmados.nAmarelos += 1.0;
    else if( strcmp(pessoa.racaCor, "Preta\n") == 0 )
      confirmados.nPretos += 1.0;
    else if( strcmp(pessoa.racaCor, "Indigena\n") == 0 )
      confirmados.nIndigenas += 1.0;
    else if( strcmp(pessoa.racaCor, "Parda\n") == 0 )
      confirmados.nPardos += 1.0;
    else if( strcmp(pessoa.racaCor, "Ignorado\n") == 0 )
      confirmados.nIgnorados += 1.0;

  } else if( strcmp(pessoa.classificacao , "Descartados") == 0 ){        
    descartados.nTotal += 1.0;

    if( strcmp(pessoa.racaCor, "Branca\n") == 0 )
      descartados.nBrancos += 1.0;
    else if( strcmp(pessoa.racaCor, "Amarela\n") == 0 )
      descartados.nAmarelos += 1.0;
    else if( strcmp(pessoa.racaCor, "Preta\n") == 0 )
      descartados.nPretos += 1.0;
    else if( strcmp(pessoa.racaCor, "Indigena\n") == 0 )
      descartados.nIndigenas += 1.0;
    else if( strcmp(pessoa.racaCor, "Parda\n") == 0 )
      descartados.nPardos += 1.0;
    else if( strcmp(pessoa.racaCor, "Ignorado\n") == 0 )
      descartados.nIgnorados += 1.0;

  }else if( strcmp(pessoa.classificacao , "Suspeito") == 0 ){      
    suspeitos.nTotal += 1.0;

    if( strcmp(pessoa.racaCor, "Branca\n") == 0 )
      suspeitos.nBrancos += 1.0;
    else if( strcmp(pessoa.racaCor, "Amarela\n") == 0 )
      suspeitos.nAmarelos += 1.0;
    else if( strcmp(pessoa.racaCor, "Preta\n") == 0 )
      suspeitos.nPretos += 1.0;
    else if( strcmp(pessoa.racaCor, "Indigena\n") == 0 )
      suspeitos.nIndigenas += 1.0;
    else if( strcmp(pessoa.racaCor, "Parda\n") == 0 )
      suspeitos.nPardos += 1.0;
    else if( strcmp(pessoa.racaCor, "Ignorado\n") == 0 )
      suspeitos.nIgnorados += 1.0;
  }else{
    puts("nao entrou em nenhum");
  }

}

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

    // catch the first data
    splitedData = strtok(buffer, ";");
    strcpy(bancoCSV[line].dataDiagnostico, splitedData);

    int dataID = 1;

    while( splitedData != NULL ){

      if(dataID == 1){
        dataID++;
        continue;
      }
      
      splitedData = strtok(NULL, ";");

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

  puts("Classificacao: Confirmados");
  printf("Amarela: %.2lf %%\n", 100*(confirmados.nAmarelos/confirmados.nTotal));
  printf("Branca: %.2lf %%\n", 100*(confirmados.nBrancos/confirmados.nTotal));
  printf("Indigena: %.2lf %%\n", 100*(confirmados.nIndigenas/confirmados.nTotal));
  printf("Parda: %.2lf %%\n", 100*(confirmados.nPardos/confirmados.nTotal));
  printf("Preta: %.2lf %%\n", 100*(confirmados.nPretos/confirmados.nTotal));
  printf("Ignorados: %.2lf %%\n", 100*(confirmados.nIgnorados/confirmados.nTotal));
  puts("");
  
  puts("Classificacao: Descartados");
  printf("Amarela: %.2lf %%\n", 100*(descartados.nAmarelos/descartados.nTotal));
  printf("Branca: %.2lf %%\n", 100*(descartados.nBrancos/descartados.nTotal));
  printf("Indigena: %.2lf %%\n", 100*(descartados.nIndigenas/descartados.nTotal));
  printf("Parda: %.2lf %%\n", 100*(descartados.nPardos/descartados.nTotal));
  printf("Preta: %.2lf %%\n", 100*(descartados.nPretos/descartados.nTotal));
  printf("Ignorados: %.2lf %%\n", 100*(descartados.nIgnorados/descartados.nTotal));
  puts("");
  
  puts("Classificacao: Suspeitos");
  printf("Amarela: %.2lf %%\n", 100*(suspeitos.nAmarelos/suspeitos.nTotal));
  printf("Branca: %.2lf %%\n", 100*(suspeitos.nBrancos/suspeitos.nTotal));
  printf("Indigena: %.2lf %%\n", 100*(suspeitos.nIndigenas/suspeitos.nTotal));
  printf("Parda: %.2lf %%\n", 100*(suspeitos.nPardos/suspeitos.nTotal));
  printf("Preta: %.2lf %%\n", 100*(suspeitos.nPretos/suspeitos.nTotal));
  printf("Ignorados: %.2lf %%\n", 100*(suspeitos.nIgnorados/suspeitos.nTotal));
  puts("");

  return 0;
}
// ----------------------------