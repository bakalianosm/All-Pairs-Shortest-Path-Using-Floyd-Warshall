#include <stdio.h>
#include <stdlib.h>
#include "solve.h" //We need solve fucntion's header file.

//Contains main function

int main (void) {
    int **graph; //Let's make graph array.
    int i,j, n,k;
    scanf("%d" ,&n ); //Get num of nodes.
    printf("%d\n" , n); //Print num of nodes.
    graph=malloc(n*sizeof(int *)); //Allocate memory.
    for (i=0 ; i<n ; i++)
        graph[i]=malloc(n* sizeof(int )); //Allocate memory.
    
    for (i=0 ; i<n ; i++){
        for (j=0 ; j < n ; j++){
            if (i==j) //If number of node is the same,
                graph[i][j]=0; //distance is 0.
        }
    }
    for (i=1 ; i<n ; i++){
        for (j=0 ; j<i ; j++){
            scanf("%d" , &graph[i][j]); //Get the distances between node [i] and [j]
            graph[j][i]=graph[i][j]; //That's to complete the whole n*n array , not the half.
        }
    }

    for (i=0 ; i<n ; i++){
	for (j=0 ; j< i ; j++){
		printf("%d \t " , graph[i][j] );
		}
	printf("\n");
    }

    solve ( n , graph ); //Call solve function to print length of shortest paths.
}
