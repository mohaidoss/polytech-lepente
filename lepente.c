#define N 19
#include <stdio.h>
#include <stdlib.h>

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

int limite(int nb){
  return ((19  < nb) || (-1 > nb));
}

pt emplacement(char mat[N][N]){
  /*D: mat: matrice de caractere*/
  pt coord;
  int plein = 1;
  /*VL: coord: structure donnant les coordonnees, plein: booleen indiquant si la case est pleine*/
  
  while (plein && (coord.x!=-1 && coord.y!=-1)){
    /*test si sort de la matrice*/
    printf("Entrer les coordonnees (pour abandonner entrer 0,0)\n");
    scanf("%d,%d",&(coord.x),&(coord.y));
    printf("(%d, %d)",coord.x,coord.y);
    coord.x = coord.x - 1;
    coord.y = coord.y - 1;
    while (limite(coord.x) || limite(coord.y)){
      printf("\nSaisie invalide\n");
      printf("Entrer les coordonnees (pour abandonner entrer 0,0)\n");
      scanf("%d,%d",&(coord.x),&(coord.y));
      coord.x = coord.x - 1;
      coord.y = coord.y - 1;
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
      printf("\n------------------------------------------------\n");
      printf("\nVous avez ABANDONNE la partie, le JOUEUR o A GAGNE\n");
      printf("\n------------------------------------------------\n");
    }
    else {
      printf("\n------------------------------------------------\n");
      printf("\nVous avez ABANDONNE la partie, le JOUEUR x A GAGNE\n");
      printf("\n------------------------------------------------\n");
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

void alignement(char mat[N][N],pt coord, int *statut) {
  int i,compteur;
  i=-4;
  compteur=1;
  /*Verification Horizontale*/ 
  while ((i<=4) && (compteur < 5)){
    if ( i!=0 && !(limite((coord.y) + i))){
      if (mat[coord.x][coord.y]==mat[coord.x][(coord.y)+i]){ 
	compteur = compteur + 1;      }
      else {
	compteur = 1;
      }
       if (compteur >= 5){
	*statut = 0;
	}
    }
    i++;
  }
  i=-4;
  /*Verification Verticale*/
  while ((i<=4) && (compteur < 5)){
    if(i!=0 && !(limite((coord.x) + i))){
	if (mat[coord.x][coord.y]==mat[(coord.x)+i][coord.y]){
	  compteur = compteur + 1;
	}
	else {
	  compteur = 1;
	}
		if (compteur >= 5){
	*statut = 0;
	}
      }
    i++;
  }
  i=-4;
  /*Verification Diagonale / */
  while ((i<=4) && (compteur < 5)){
    if (i!=0 && !(limite((coord.y) - i)) && (!(limite((coord.x)+i)))) {
      if (mat[coord.x][coord.y]==mat[(coord.x)+i][(coord.y)-i]){
	compteur = compteur + 1;
      }
      else {
	compteur = 1;
      }
       if (compteur >= 5){
	*statut = 0;
	}
    }
    i++;
  }
  i=-4;
  /*  Verification Diagonale \ */
  while ((i<=4) && (compteur < 5)){
    if (i!=0 && !(limite((coord.y) + i)) && (!(limite((coord.x)-i)))){
      if (mat[coord.x][coord.y]==mat[(coord.x)-i][(coord.y)-i]){
	compteur = compteur + 1;
      }
      else {
	compteur = 1;
      }
         if (compteur >= 5){
	*statut = 0;
	}
    }
    i++;
  }
  if (compteur >= 5){
    *statut = 0;
  }  
}



void prise(char mat[N][N], pt coord, int *statut, int *compteur){
  /*D/R: mat: matrice de caractères      statut: entier donnant le statut de la partie
  compteur: entier comptant le nombre de prises*/
  /*D: coord: structure de type pt donnant les coordonnées du pion joué*/

  /*test vertical bas*/
  if ((!limite(coord.x+3)) && (mat[coord.x][coord.y])==(mat[coord.x+3][coord.y])){
	if ((mat[coord.x+1][coord.y]==mat[coord.x+2][coord.y]) && (mat[coord.x+1][coord.y] !='.')){
	  if (mat[coord.x+1][coord.y]!=mat[coord.x][coord.y]){
	    mat[coord.x+1][coord.y]= '.';
	    mat[coord.x+2][coord.y]= '.';
	    (*compteur)++;
	  }
	}
  }

  /*test vertical haut*/
  if ((!limite(coord.x-3)) && (mat[coord.x][coord.y])==(mat[coord.x-3][coord.y])){
    if ((mat[coord.x-1][coord.y]==mat[coord.x-2][coord.y]) && (mat[coord.x-1][coord.y] !='.')){
	  if (mat[coord.x-1][coord.y]!=mat[coord.x][coord.y]){
	    mat[coord.x-1][coord.y]= '.';
	    mat[coord.x-2][coord.y]= '.';
	    (*compteur)++;
	  }
	}
  }
  /*test horizontal droite*/
  if ((!limite(coord.y+3)) && (mat[coord.x][coord.y])==(mat[coord.x][coord.y+3])){
    if ((mat[coord.x][coord.y+1]==mat[coord.x][coord.y+2]) && (mat[coord.x][coord.y+1] !='.')){
	  if (mat[coord.x][coord.y+1]!=mat[coord.x][coord.y]){
	    mat[coord.x][coord.y+1]= '.';
	    mat[coord.x][coord.y+2]= '.';
	    (*compteur)++;
	  }
	}
  }
  /*test horizontal gauche*/
  if ((!limite(coord.y-3)) && (mat[coord.x][coord.y])==(mat[coord.x][coord.y-3])){
    if ((mat[coord.x][coord.y-1]==mat[coord.x][coord.y-2]) && (mat[coord.x][coord.y-1] !='.')){
	  if (mat[coord.x][coord.y-1]!=mat[coord.x][coord.y]){
	    mat[coord.x][coord.y-1]= '.';
	    mat[coord.x][coord.y-2]= '.';
	    (*compteur)++;
	  }
	}
  }
  /*test diagonale /" */
  if ((!limite(coord.y+3)) && (!limite(coord.x-3)) && (mat[coord.x][coord.y])==(mat[coord.x-3][coord.y+3])){
    if ((mat[coord.x-1][coord.y+1]==mat[coord.x-2][coord.y+2]) && (mat[coord.x-1][coord.y+1] !='.')){
	  if (mat[coord.x-1][coord.y+1]!=mat[coord.x][coord.y]){
	    mat[coord.x-1][coord.y+1]= '.';
	    mat[coord.x-2][coord.y+2]= '.';
	    (*compteur)++;
	  }
	}
  }
  /*test diagonale ,/ */
  if ((!limite(coord.y-3)) && (!limite(coord.x+3)) && (mat[coord.x][coord.y])==(mat[coord.x+3][coord.y-3])){
    if ((mat[coord.x+1][coord.y-1]==mat[coord.x+2][coord.y-2]) && (mat[coord.x+1][coord.y-1] !='.')){
	  if (mat[coord.x+1][coord.y-1]!=mat[coord.x][coord.y]){
	    mat[coord.x+1][coord.y-1]= '.';
	    mat[coord.x+2][coord.y-2]= '.';
	    (*compteur)++;
	  }
	}
  }
  /*test diagonal \,*/
  if ((!limite(coord.y+3)) && (!limite(coord.x+3)) && (mat[coord.x][coord.y])==(mat[coord.x+3][coord.y+3])){
    if ((mat[coord.x+1][coord.y+1]==mat[coord.x+2][coord.y+2]) && (mat[coord.x+1][coord.y+1] !='.')){
	  if (mat[coord.x+1][coord.y+1]!=mat[coord.x][coord.y]){
	    mat[coord.x+1][coord.y+1]= '.';
	    mat[coord.x+2][coord.y+2]= '.';
	    (*compteur)++;
	  }
	}
  }
  /*test diagonal "\ */
  if ((!limite(coord.y-3)) && (!limite(coord.x-3)) && (mat[coord.x][coord.y])==(mat[coord.x-3][coord.y-3])){
    if ((mat[coord.x-1][coord.y-1]==mat[coord.x-2][coord.y-2]) && (mat[coord.x-1][coord.y-1] !='.')){
	  if (mat[coord.x-1][coord.y-1]!=mat[coord.x][coord.y]){
	    mat[coord.x-1][coord.y-1]= '.';
	    mat[coord.x-2][coord.y-2]= '.';
	    (*compteur)++;
	  }
	}
  }
  if (*compteur >= 5){
	  *statut = 0;
  }
}

  


  

int main(){

  char tableau[N][N];
  pt coord;
  int nbt;
  int compteurpair=0;
  int compteurimpair=0;
  int statut = 1;
  printf("\n/////////////////////////////////");
  printf("\nJeu du pente \nChoisissez une action :\n \t1.Lancer le jeux\n \t2.Lire les instructions\n");
  printf("/////////////////////////////////\n");
  scanf("%d",&statut);
   switch (statut){
	case 1:
		matrice_init(tableau);
  		nbt = 0;

  		while (statut){
  		  nbt++;
  		  system("clear");

  		  printf("\n///////////////");
  		  printf("\n/ O a fait %d prise /",compteurpair);
  		  printf("\n/ X a fait %d prise /",compteurimpair);
  		  printf("\n///////////////\n");

  		  matrice_affichage(tableau);
  		  coord = emplacement(tableau);
  		  modifCase(tableau,nbt,coord,&statut);

  		  if (nbt%2){
  		  	prise(tableau,coord,&statut,&compteurpair);
  		  }
  		  else prise(tableau,coord,&statut,&compteurimpair);

  		  if (statut){
  		  	alignement(tableau,coord,&statut);
  		  }

  		}
  		matrice_affichage(tableau);

  		if((statut==0) && (nbt%2==0) && (coord.x!= -1)){
  		  printf("BRAVO ! Le joueur x a gagné\n");
  		}
  		else if((statut==0) && (nbt%2!=0)&& (coord.x!= -1)){
  		  printf("BRAVO ! Le joueur o a gagné\n");
  		}
  		return 1;
	case 2:
		printf("\nChaque joueur, O et X, pose l’un après l’autre son symbole sur la grille. O commence toujours la partie.\nIl existe deux façons de gagner la partie :\n\taligner cinq pions de sa couleur\n\tcapturer cinq paires de pions à l’adversaire.\n");
    		return main();
	default :
		printf("\nFin du programme\n");
		return 1;
   }
}
