#include <stdio.h>

#define MAXA 100000

void foo(int *x){
  (*x)++;
  printf("foo: %d\n", *x);
}

int main( ){

  int a;
  int *pointer = &a;
  scanf(" %d", &a);

  foo(pointer);

  printf("main: %d\n", a);

  return 0;
}