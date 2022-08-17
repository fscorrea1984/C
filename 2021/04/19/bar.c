#define GNU_SOURCE

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define BUF_SIZE 1024

int main(int argc,char **argv) {

  int tot,j,fp;
  ssize_t nread;
  char buf[BUF_SIZE];
  char cwd[PATH_MAX];

  /*Changeourcurrentworkingdirectorytothatofthe
    crashingprocess*/

  snprintf(cwd,PATH_MAX,"/proc/%s/cwd",argv[1]);
  chdir(cwd);

  /*Writeoutputtofile"core.info"inthatdirectory*/

  fp = open("core.info",O_CREAT,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

  if(fp == NULL)
    exit(EXIT_FAILURE);

  /*Displaycommand-lineargumentsgiventocore_pattern
    pipeprogram*/

  fprintf(fp,"argc = %d\n",argc);

  for(j = 0 ; j < argc ; j++)
    fprintf(fp,"argc[%d]= <%s>\n",j,argv[j]);

  /*Countbytesinstandardinput(thecoredump)*/

  tot = 0;

  while((nread = read(STDIN_FILENO,buf,BUF_SIZE)) > 0)
    tot += (unsigned int) nread;
  
  fprintf(fp,"Total bytes in core dump:%d\n",tot);

  close(fp);
  
  exit(EXIT_SUCCESS);
  
}
