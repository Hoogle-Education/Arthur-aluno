# Estruturas dinâmicas

## Alocação dinâmica

```
int -> 2 or 4 bytes
long -> 4 bytes
long long -> 8 bytes
```

### 1. `malloc()` -> Memory Allocation

&10210xf -> func() 

A função não é descartada após seu uso, apenas ocupa um valor de memória que não está sendo mencionado. Para isto, usaremos a malloc que aloca espaços na memória em bytes e anotaremos seu endereço.

sintaxe:
```c
  int *ptr;
  ptr = (int *) malloc(sizeOfArray * sizeof(int));
```

ou
```c
  int *ptr = (int *) malloc(sizeOfArray * sizeof(int));
```

### 2. `calloc()` -> Continguos Allocation

igual a malloc.
vantagem: começa zerado;

sintaxe:
```c
  char *ptr = (char*) calloc(sizeOfArray, sizeof(char) );
```

### 3. `realloc()` -> Realocate Allocation

sintaxe reflexiva:
```
  ptr = (int*)realloc(ptr, newSizeOfArray);
```

sintaxe:
```
  int *list = (int *)realloc(ptr, newSizeOfArray);
```


198 = 1\*10^2 + 9\*10^1 + 8\*10^0

# Listas encadeadas

 