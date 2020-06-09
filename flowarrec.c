#include <stdio.h>
#include <stdlib.h>



int p ( int i , int j , int k , int **array){ // p fuction on iphw3.
    int p1,p2,p3; //I use 3 p variables to hold each result.
    if   (k>=0){
        p1 = p(i,j,k-1,array);
        p2 = p(i,k,k-1,array);
        p3 = p(k,j,k-1,array);
        
        if(p1<0 && (p2<0 || p3<0)) //if p1 is "infinity" and p2 or p3 are "infinity"the minimum is "infinity".
            return -1; //Infinity distance.
        else if(p1<0) //If p1<0 and p2&p3 are>0,
            return p2+p3; //return the sum of p2+p3 as minimum distance
        else if(p2<0 || p3<0) //if one of p2 and p3 is infiny , and p1 isnt infinity , return p1
            return p1;
        else if(p1 > p2+p3) //if p1,p2,p3 aren't infinity and p1>p2+p3
            return p2+p3; //Minimum is the sum of p2+p3 , return it!
        else // if p1<p2+p3
            return p1; //Minimum is the p1,return it
    }
    else //if k is <0
        return array[i][j]; // minimum distance is the  array[i][j] ,return it.
    
}

void  solve (int n , int **array){
    int i,j,length,k;
    
    for (i=1 ; i<n ; i++){ //Because we want from node "1"
        for (j=0 ; j<i ; j++){
            length =p(i,j,n-1,array); //store p function's result on length variable.
            printf("From node %d to node %d: ", i, j);
            if(length<0)                            //Ιf length is equal to -1 there is no path to go from node i to j
                printf("There is no path\n");
            else
                printf("Length of shortest path is %d\n", length);
        }
        printf("\n");
    }
}

