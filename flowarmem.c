#include <stdio.h>
#include <stdlib.h>



int  p ( int i , int j , int k , int ***array ){
    int p1,p2,p3; ////I use 3 p variables to hold each result.
    
    if   (k>=0){
        if (array[i][j][k]==-1){
            p1 = p(i,j,k-1,array);
            p2 = p(i,k,k-1,array);
            p3 = p(k,j,k-1,array);
            
            if(p1<0 && (p2<0 || p3<0))//if p1 is "infinity" and p2 or p3 are "infinity"the minimum is "infinity".
                
                array[i][j][k] = -1; //Distance is infinity , store on array[i][j][k] the infinity.
            else if(p1<0) //If p1<0 and p2&p3 are>0,
                array[i][j][k] = p2+p3; //store at array[i][j][k]the sum of p2+p3 as minimum distance
            else if(p2<0 || p3<0) //if one of p2 and p3 is infiny , and p1 isnt infinity
                array[i][j][k]=p1; //store p1
            else if(p1 > p2+p3) //if p1,p2,p3 aren't infinity and p1>p2+p3
                array[i][j][k]=p2+p3; //Minimum is the sum of p2+p3 , store it!
            else // if p1<p2+p3
                array[i][j][k] = p1; //Minimum is the p1,store it !
        }
        else return array[i][j][k]; //If array[i][j][k] isn't infinity return it!
    }
    else //if k<0
        return array[i][j][0];
    return array[i][j][k];
}




void solve (int n, int** array){
    int i, j , k , cost  ;
    int ***tab;
    tab= malloc(n*sizeof(int**)); // Allocate memmory for 3D tab array
    for (i = 0; i < n ; i++) {
        tab[i] = malloc(n*sizeof(int*));
        for (j = 0; j < n; j++) {
            tab[i][j] = malloc(n*sizeof(int));
        }
    }
    
    for (i=0 ; i < n ; i++){
        for (j=0 ; j < n ; j++)
            tab[i][j][0]= array[i][j]; //Each tab[i][j][0] variable is the distances that the program reads from scanf.
    }
    for (k=1 ; k<n ; k++){
        for (i=0 ; i<n ; i++){
            for (j=0 ; j<n ; j++)
                tab[i][j][k]=-1; //set every other arrays element as infinity
            
        }
    }
    for (i=1 ; i < n ; i++){
        for (j=0 ; j < i ; j++){
            if (tab[i][j][n-1]==-1){ //if element tab[i][j][n-1] is infinity
                cost=p(i,j,n-1 ,tab); //get cost from p function
                tab[i][j][n-1]=cost; //and store it
                printf("From node %d to node %d: " ,  i , j ) ;
                if (cost<0)  //Ιf cost  is equal to -1 there is no path to go from node i to j
                    printf("There is no path\n") ;
                else
                    printf("Length of shortest path is %d\n" , cost) ;
            }
            else { //if tab [i][j][n-1] element isn't infinity ,cost is the tab[i][j][n-1] element
                printf("From node %d to node %d: " ,  i , j ) ;
                if (tab[i][j][n-1] < 0 )//Ιf element  is equal to -1 there is no path to go from node i to j
                    printf("There is no path\n") ;
                else
                    printf("Length of shortest path is %d\n" , tab[i][j][n-1]) ;
                
                
            }
        }
        printf ("\n") ;
    }
}
