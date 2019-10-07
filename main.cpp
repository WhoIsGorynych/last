#include <stdio.h>
#include "matrix_help.h"
#include <iostream>
#include <stdlib.h>
#include "function_v1.h"

int main(int argc, char** argv){
    
  int N = -1;
  double **matrix_old;
  double **matrix_new;


  if(argc == 1){
    printf("Hello!\n");
    printf("1 - matrix from file ('in.txt')\n");
    printf("2 - matrix from function\n");
    printf("Input mode: ");

    int input_mode;
    scanf("%d", &input_mode);


    if(input_mode == 1){
      FILE* file = fopen("in.txt", "r");
      matrix_old = matrix_read(file, N);
    }
    else if(input_mode == 2){
      printf("not ready yet");
      return -1;
    }
  }
  else if(argc == 2){
      N = atoi(argv[1]);
      matrix_old = identity_matrix(N);

  }
  else if(argc == 3){
      N = atoi(argv[1]);
      FILE* file = fopen(argv[2], "r");
      
      matrix_old = matrix_read_woN(file, N);
  }
  else{
      printf("END!");
      return -1;
  }


  matrix_print(matrix_old, N);
    
  matrix_new = identity_matrix(N);

  Function(matrix_old, matrix_new, N);

  printf("Answer: \n");
  matrix_print(matrix_new, N);

    
  delete[] matrix_old;
  delete[] matrix_new;

}
