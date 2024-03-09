#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main() {
  int fd = open( "sample.txt",O_RDWR ) ;
  char buffer[256] = {'\0'} ;
  lseek(fd,14,SEEK_SET ) ;
  ssize_t reads = read( fd,buffer,sizeof(buffer) ) ;
  buffer[reads-1] = '\0' ; 
  printf("%s\n",buffer ) ;
  lseek(fd,14,SEEK_SET) ;
  char buffer2[] = "NTHU student." ;
  write(fd,buffer2,strlen(buffer2) ) ;
  lseek(fd,0,SEEK_SET) ;
  reads = read( fd , buffer, sizeof(buffer) ) ;
  printf("%s",buffer) ;
  close(fd) ;

} 



