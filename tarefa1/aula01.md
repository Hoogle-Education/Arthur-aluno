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

## Manipulação de arquivo
