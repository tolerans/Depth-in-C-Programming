#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**Initial global variables
 **writing .data memmory segment*/
int global_variables_1 = 10;
int global_variables_2 = 20;
typedef unsigned long int UI;

int main(){
	
/**Local variables and args
 **writing a .stack 
 **memmory segment */
  int local_variables_1 = 30;
  int local_variables_2 = 40;
  int local_variables_3 = 50;
/** New memmory allocation .heap 
 ** memmory segment */
  char *buffer1;
  buffer1 = (char *) malloc(200);
  char *buffer2;
  buffer2 = (char *) malloc(200);
  

  printf("Page size: %d\n", getpagesize());
  printf("Data segment : start= 0x%lx, size= 8156345 Byte\n", (UI) &global_variables_1);
  printf("Heap segment : start= 0x%lx, size= 8156345 Byte\n", (UI) buffer1);
  printf("Stack segment : start= 0x%lx, size= 8156345 Byte\n", (UI) &local_variables_1);
  
  /* Finally, print the addressses as 
     recorded in the directory "/proc". */
  printf("\n Control Address Value \n");
  sprintf(buffer1, "cat /proc/%d/maps | grep stack", getpid());
  sprintf(buffer2, "cat /proc/%d/maps | grep heap", getpid());
  system(buffer1);
  system(buffer2);
  return 0;
}

