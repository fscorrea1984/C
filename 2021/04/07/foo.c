#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int A[5];
int B[5];
int C[5];

unsigned int todo = 5; // how many rows left to do
pthread_mutex_t todo_mutex = PTHREAD_MUTEX_INITIALIZER; // synchronize access to variable 'todo'

void calculate_row(int *num) {

  int x = *num; // row to compute
  
  while(1) {
    for(int col = 0; col < 5; col++) {
      C[x][col] = 0;
      for(int y = 0; y < 5; y++) {
	C[x][col] += A[x][y] * B[y][col]; // C[x][col]
      }
    }

    pthread_mutex_lock(&todo_mutex);
    if(todo > 0) {
      x = 5 - todo;
      todo--;
      pthread_mutex_unlock(&todo_mutex);
    } else break;
  
}

int main(int argc, char **argv) {
  
  /* input */
  
  FILE *fd1; // input A.txt
  FILE *fd2; // input B.txt
  FILE *fd3; // output C.txt

  fd1 = fopen("A.txt","r");
  fd2 = fopen("B.txt","r");

  if((fd1 < 0) || (fd2 < 0)) {
    perror("Error opening file");
    exit(1);
  }

  for(int row; row < 5; row++) {
    char *str1,str2,str3,str4,str5;
    fscanf(fd1,"%s %s %s %s %s\n",str1,str2,str3,str4,str5);
    A[row][0] = atoi(*str1);
    A[row][1] = atoi(*str2);
    A[row][2] = atoi(*str3);
    A[row][3] = atoi(*str4);
    A[row][4] = atoi(*str5);
    fscanf(fd2,"%s %s %s %s %s\n",str1,str2,str3,str4,str5);
    B[row][0] = atoi(*str1);
    B[row][1] = atoi(*str2);
    B[row][2] = atoi(*str3);
    B[row][3] = atoi(*str4);
    B[row][4] = atoi(*str5);
  }

  /* input A and B are ready */

  close(fd2);
  close(fd1);

  if(argc != 2) {
    perror("Usage: %s numberofthreads",argv[0]);
    exit(1);
  }
  
  /* thread vector */
  int n_threads = atoi(argv[1]);
  pthread_t thr[n_threads];


  fd3 = fopen("C.txt","w+");

  if(fd3 < 0) {
    perror("Error opening file");
    exit(1);
  }

  for(int t = 0; t < n_threads; t++) {
    int k = 5 - todo;
    pthread_create(&thr[t],NULL,(void *) calculate_row,(void *) &k);
  }

  for(int t = 0; t < n_threads; t++)
    pthread_join(thr[t],NULL);

  for(int r = 0; r < 5; r++)
    for(int c = 0; c < 5; c++){
      fprintf(fd3,"%i",C[r][c]);
      (c == 4)? fputc('\n',fd3) : fputc(' ',fd3);
    }
  
  close(fd3);
  
  return 0;

}
