#include <stdio.h>
#include <stdlib.h>

#define N 4

//clear buffer
void clear_buffer();

int print_re(int *v, int n);

int main(){

    int v[N] = {10,-2,-1,10};

    int n = print_re(v,N);

    return 0;
}

int print_re(int *v, int n){

  if(n == 0)
	    return;
	
    print_re(v, n-1);

    printf (" %d ", v[n-1]);
 
}