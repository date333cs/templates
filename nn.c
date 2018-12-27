#include <stdio.h>
#include <stdlib.h>

#define RAND_SEED 20181227

typedef struct {
  int n1;  /* number of input units */
  int n2;  /* number of units in the second layer */
  double *x; /* input units */
  double *u; /* output of the second layer units */
  double z;  /* output unit */
  double **s; /* s[j][k]: connection weights */
  double *w; /* w[j]: connection weights to the ouput unit */
} NN;



/*** Allocate 1d array of doubles ***/

double *alloc_1d_dbl(int n){

  double *new;

  new = (double *) malloc ((unsigned) (n * sizeof (double)));
  if (new == NULL) {
	  printf("ALLOC_1D_DBL: Couldn't allocate array of doubles\n");
	  return (NULL);
  }
  return (new);
}


/*** Allocate 2d array of doubles ***/

double **alloc_2d_dbl(int m, int n){
	
	int i;
	double **new;
	
	new = (double **) malloc ((unsigned) (m * sizeof (double *)));
	if (new == NULL) {
		printf("ALLOC_2D_DBL: Couldn't allocate array of dbl ptrs\n");
		return (NULL);
	}
	
	for (i = 0; i < m; i++) {
		new[i] = alloc_1d_dbl(n);
	}
	
	return (new);
}



NN* nn_new(int n1, int n2) {

    NN* this;
    int j, k;

	this = (NN*) malloc (sizeof(NN));
	if (this == NULL) return NULL;
	
	this->n1 = n1;
	this->n2 = n2;
	
	this->x = alloc_1d_dbl(n1);
	for(k=0; k<n1; k++) {
		this->x[k] = 0.0;
	}
	
	this->u = alloc_1d_dbl(n2);
	for(j=0; j<n2; j++) {
		this->u[j] = 0.0;
	}
	
	this->s = alloc_2d_dbl(n2,n1);
	for(j=0; j<n2; j++) {
		for(k=0; k<n1; k++) {
			this->s[j][k] = 0.0;
		}
	}
	
	
   this->w = alloc_1d_dbl(n2);
   for(j=0; j<n2; j++) {
	   this->w[j] = 0.0;
   }
   
   return this;
   
}







void nn_free(NN* this) {
	
    int i;
    int n2 = this->n2;
    n2++;
    
    free((char *) this->x);
    free((char *) this->u);
	
    for (i=0; i<n2; i++) {
        free((char *) this->s[i]);
    }
    free((char *) this->w);
	
}



void  nn_test(){

	NN* NN1;

	NN1 = nn_new(100, 20);

	nn_free(NN1);
		
}



int main (int argc, char *argv[] ){

  int i;
  int seed = RAND_SEED;
  
  for (i=1; i<argc; i++) {
	  switch (*(argv[i]+1)) {
	  case 'r':
		  seed = atoi(argv[++i]);
		  break;
	  default:
		  fprintf(stderr, "Usage : %s\n",argv[0]);
		  fprintf(stderr, "\t-r : random seed(%d)\n",seed);
		  exit(0);
		  break;
	  }
  }
  srand48(seed);
  
  nn_test();
  
  return 0;
}
