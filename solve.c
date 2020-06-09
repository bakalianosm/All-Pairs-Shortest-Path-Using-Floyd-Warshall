#include <stdio.h>
#include <stdlib.h>
#include "p.h" //We need "p" function's header file.

//The solve function.
void  solve (int n , int **array){
    int i,j,length,k;
    
    for (i=1 ; i<n ; i++){
        for (j=0 ; j<i ; j++){
            length =p(i,j,n-1,array); //Here i call the recursive p function.
            printf("From node %d to node %d: ", i, j);
            if(length<0)                            //if length is less than 0 (equal to -1) there is no path to go from node i to j
                printf("There is no path\n");
            else
                printf("Length of shortest path is %d\n", length);
        }
        printf("\n");
    }
}







