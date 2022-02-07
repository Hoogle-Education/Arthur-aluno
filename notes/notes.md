# Aula 01 

## Stucts

 - essencialmente é um estilo prático e comodo de programar.

**alguns exemplos:**
```
 Aluno
  | - nome
  | - idade
  | - RA
  | - média
  |
  | - calculaMedia( )

 Bicicleta-elétrica
  | - marca
  | - velocidadeMaxima
  | - estadoDoMotor
  | 
  | - ligarMotor( ) 
```

**sintaxe:**
```c
  typedef struct Aluno{
    char nome[];
    int idade;
    int RA;
    int media = 0;
  };
```

### Por que

evitar paralelismo de vetores.

## C keywords

### Palavra `define` 

```c
  #define MAXN 10000
```

```c
  #define MAXBUFFER 400
```

## Manipulação de arquivo

### fopen( )

sintaxe:

```c
  FILE* csvFile;

  csvFile = fopen("file_path", " ");
```

### fclose( )

sintaxe:
```c
  fclose(csvFile);
```

## Pausa para Ponteiros

Fazer referência a variável e não a cópia.

- `&` -> trabalha com o endereço da variável

- `*` -> aponta para o enderço da variável.

## Retornando a manipulação de arquivos

### feof( )

Retorna `true` ou `false` para a pergunta: "é o fim do arquivo".

```C
  while(true){

    if(feof(csvFile)){
      puts("eh o fim do arquivo");
      break;
    } 
    
  }
```

## fgets( )

sintaxe:
```c
  fgets(row, MAXCHAR, csvFile);
```

### strcpy()

strcpy(write_file, source_file);