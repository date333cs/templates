#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[] ){

  int i;
  long int seed = 123456;
  
  for (i=1; i<argc; i++) {
    switch (*(argv[i]+1)) {
    case 'r':
      seed = atoi(argv[++i]);
      break;
    default:
      fprintf(stderr, "Usage : %s\n",argv[0]);
      fprintf(stderr, "\t-r : random-seed(%ld)\n",seed) ;
      exit(0);
      break;
    }
  }
    
  srand48(seed);



  

  return 0;
  
}
