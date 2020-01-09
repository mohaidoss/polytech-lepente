#define N 19
#include <stdio.h>

void matrice_lecture(char mat[N][N]){
  /*D/R: mat: matrice de caractère*/
  /*VL: i,j : entiers*/
  int i,j;
  
  for(i=0; i<N; i++){

    for(j=0; j<N; j++){

      mat[i][j]='.';

    }
  }
}

void matrice_affichage (char mat[N][N]){
    /*D: mat: matrice d'entiers*/

    int i,j;
    /*VL: i,j : entiers*/

    /* Affichage des indices de colonnes */
    printf("     ");
    for (j=0; j<N; j++) printf("%2d  ",j+1);
    printf("\n");

    /* Affichage de la matrice */
    for (i=0; i<N; i++) {
        printf("%2d   ",i+1);
        for (j=0; j<N; j++) printf("%c   ", mat[i][j]);
        printf("\n");
    }

    printf("\n");
}


int main(){
  char tableau[N][N];
  matrice_lecture(tableau);
  matrice_affichage(tableau);
  return 1;
}
