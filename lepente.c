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
    /*D: mat: matrice de caractere*/

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
  /*D: mat: matrice de caractere*/
  pt coord;
  int plein = 1;
  /*VL: coord: structure donnant les coordonnees, plein: booleen indiquant si la case est pleine*/
  
  while (plein && (coord.x!=-1 && coord.y!=-1)){
    /*test si sort de la matrice*/
    printf("Entrer les coordonnees (pour abandonner entrer 0,0)");
    printf("\nSaisissez la ligne de la case ou ajouter le pion\n");
    scanf("%d",&(coord.x));
    printf("\nSaisissez la colonne de la case ou ajouter le pion\n");
    scanf("%d",&(coord.y));
    coord.x = coord.x - 1;
    coord.y = coord.y - 1;
    while ((19  < coord.x) || (-1 > coord.x)){
      printf("\nSaisie invalide\n");
      printf("\nSaisissez la ligne de la case ou ajouter le pion\n");
      scanf("%d",&(coord.x));
    }

    while ((19  < coord.y) || (-1 > coord.y)){
      printf("\nSaisie invalide\n");
      printf("\nSaisissez la colonne de la case ou ajouter le pion\n");
      scanf("%d",&(coord.y));
    }

    if ((coord.x != -1) && (coord.y!=-1)){
      plein = (mat[coord.x][coord.y]!='.');
      if (plein) {
	printf("\nLa case est pleine, resaisissez les coordonnées\n");
      }
    }
  }
  return coord;
}
 



void modifCase(char mat[N][N],int tour,pt coord,int *statut){
  /*D/R: mat: matrice de caractere, statut: entier, indique si la partie en cours continue*/
  /*D: tour: entier indiquant le nombre de tours ,  coord: structure donnant les coordonnees d'un point*/

  if ((coord.x == -1) && (coord.y==-1)){
    if (tour%2==0){
      printf("\nVous avez abandonne la partie, le joueur o a gagne\n");
    }
    else {
      printf("\nVous avez abandonne la partie, le joueur x a gagne\n");
    }
    *statut=0;
  }
  else{
    if (tour%2==0){
      mat[coord.x][coord.y]='x';
    }
    else {
      mat[coord.x][coord.y]='o';
    }
  }
}



int main(){

  char tableau[N][N];
  pt coord;
  int nbt;
  int statut = 1;

  matrice_init(tableau);
  nbt = 0;

  while ( statut && nbt<5){
    nbt++;
    matrice_affichage(tableau);
    coord = emplacement(tableau);
    modifCase(tableau,nbt,coord,&statut);
  }
  matrice_affichage(tableau);
  return 1;
}
