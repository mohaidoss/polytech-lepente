#define N 19
#include <stdio.h>

typedef struct {
  int x;
  int y;
} pt;



void matrice_init(char mat[N][N]){
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

pt emplacement(char mat[N][N]){
  pt coord;
  int plein = 1;
  
  while (plein){
    
    printf("\nSaisissez la ligne de la case ou ajouter le pion\n");
    scanf("%d",&(coord.x));
    printf("\nSaisissez la colonne de la case ou ajouter le pion\n");
    scanf("%d",&(coord.y));
    coord.x = coord.x - 1;
    coord.y = coord.y - 1;
    while ((19  < coord.x) || (0 > coord.x)){
      printf("\nSaisie invalide\n");
      printf("\nSaisissez la ligne de la case ou ajouter le pion\n");
      scanf("%d",&(coord.x));
    }

    while ((19  < coord.y) || (0 > coord.y)){
      printf("\nSaisie invalide\n");
      printf("\nSaisissez la colonne de la case ou ajouter le pion\n");
      scanf("%d",&(coord.y));
    }
    plein = (mat[coord.x][coord.y]!='.');
    if (plein) {
      printf("\nLa case est pleine, resaisissez les coordonnées\n");
    }
  }
  return coord;
}
 
void modifCase(char mat[N][N],int Tour,pt coord){
  if (Tour%2==0){
    mat[coord.x][coord.y]='x';
  }
  else {
    mat[coord.x][coord.y]='o';
  }
}



int main(){
  char tableau[N][N];
  pt coord;
  int i,nbt;
  matrice_init(tableau);
  nbt = 0;
  for (i=0;i<2;i++){
    nbt++;
    matrice_affichage(tableau);
    coord = emplacement(tableau);
    modifCase(tableau,nbt,coord);
  }
  matrice_affichage(tableau);
  return 1;
}
