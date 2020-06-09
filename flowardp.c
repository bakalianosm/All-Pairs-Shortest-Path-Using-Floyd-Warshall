#include <stdio.h>
#include <stdlib.h>



int pfordyn ( int i , int j , int k ){
    int p1,p2,p3;
    p1=i;
    p2=j;
    p3=k;
    if(p1<0 && (p2<0 || p3<0))//if p1 is "infinity" and p2 or p3 are "infinity"the minimum is "infinity".
        return -1; //distance is infinity,return it!
    else if(p1<0) //If p1<0 and p2&p3 are>0,
        return p2+p3; //return the sum of p2+p3 as minimum distance.
    else if(p2<0 || p3<0)//if one of p2 and p3 is infiny , and p1 isnt infinity ,
       return p1;  //return p1
    else if(p1 > p2+p3)//if p1,p2,p3 aren't infinity and p1>p2+p3
        return p2+p3; //Minimum is the sum of p2+p3 , return it!
    else // if p1<p2+p3
        return p1;//Minimum is the p1,return it
}



void  solve (int n , int **array){
    int **q,i,j,b,k;
    q=malloc (n*sizeof(int *)); //Allocate memory for 2D array.
    for (i=0 ; i<n ; i++)
        q[i]=malloc(n* sizeof(int ));
    
    for (i=0 ; i<n ; i++){ //Set every q array's element ,
        for (j=0 ; j< n ; j++ )
            q[i][j]=-1;// as infinity
    }
    for (i=0 ; i<n ;i++){
        for (j=0 ; j<n ; j++){
            b=array[i][j]; // b is to copy every element from array to q
            q[i][j]=b;
        }
    }
    for (k=0 ; k<n-1 ; k++){
        for (i=0 ; i<n ; i++){
            for (j=0 ; j<n ; j++){
                q[i][j]=pfordyn ( q[i][j], q[i][k], q[k][j] ) ; //calling function to fill q array with the distances.
            }
        }
    }
    for (i=0 ; i< n ; i++){
        for (j=0 ; j< i ;j++){
            printf ("From node %d to node %d : " , i ,j );
            if (q[i][j]>0)   //Ιf length is equal to -1 there is no path to go from node i to j
                printf("Length of shortest path is : %d \n " , q[i][j]);
            else
                printf ("There is no path\n");
        }
        printf("\n");
    }
}





