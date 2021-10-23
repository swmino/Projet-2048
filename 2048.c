#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define MAXCARAC 1000
int score=0;
void deplace_d(int plateau[4][4]);
void deplace_g(int plateau[4][4]);
void deplace_h(int plateau[4][4]);
void deplace_b(int plateau[4][4]);


void affiche_ligne(int plateau[4][4]){
  int hauteur ;
  int largeur ;
  printf("SCORE : %d",score);

  printf("\n___________________________\n");
  printf("\n");

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){


    for( largeur=0 ; largeur<4 ;largeur++ ){                    




      switch( plateau[largeur][hauteur] ) {

        case 0 :

          printf("|     |" ) ;
          if(largeur==3){

            printf("\n___________________________\n");
      
          }

        break ;

        case 2 :                                                              

          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0B);  
          printf("|  2  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("\n__________________________\n");
      
          }

        break ;

        case 4 :

          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);  
          printf("|  4  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break ;

        case 8 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("|  8  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break ;

        case 16 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("| 16  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break ;

        case 32 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("| 32  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

        case 64 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
          printf("| 64  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

        case 128 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
          printf("| 128 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

        case 256 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
          printf("| 256 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

        case 512 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
          printf("| 512 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

        case 1024 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
          printf("|1024 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

        case 2048 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
          printf("|2048 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

            printf("      %d ",hauteur+1);

            printf("\n");
            printf("_____________________");
            printf("\n");

          }
      
        break;

      }
  
    }

  }
  
}

void spawn(int plateau[4][4]){

    srand(time(NULL));
    
    int nbgens;
    int nbgene;

    int gener;

    nbgens=rand()%3+1;
    nbgene=rand()%3+1;


    int alea;
    alea=rand()%2+1;
    int val;
    
    if(alea==0){

      val=4;
    }

    else{

      val=2;

    }

    plateau[nbgens][nbgene]=val;
  
}



void deplace_g(int plateau [4][4]){


  int i,j;

  for (j=0;j<4;j++)
  {
    for(i=0;i<4;i++){

       
        
      if (plateau[i][j]!=0){


        int z=i;

        for(z=i;z>-1;z--){

          if(plateau[z-1][j]==0){
            plateau[z-1][j]=plateau[z][j];
            plateau[z][j]=0;
            

          }

          if(plateau[z-1][j]!=0){
            if(plateau[z-1][j]==plateau[z][j]){
              plateau[z-1][j]=2*plateau[z][j];
              plateau[z][j]=0;
              score=score+plateau[z-1][j];
            }

            else{
              plateau[z][j]=plateau[z][j];
            }

          }
        }
      }
    }
  }

  spawn(plateau);
  affiche_ligne(plateau);

}

void deplace_d(int plateau[4][4]){

  int i,j;
 

  for (j=0;j<4;j++){

    for(i=0;i<4;i++){
      
      if (plateau[i][j]!=0)
      {
        int z=i;

        for(z=i;z<3;z++){

          if(plateau[z+1][j]==0){

            plateau[z+1][j]=plateau[z][j];
            plateau[z][j]=0;

          }

          if(plateau[z+1][j]!=0){
            if(plateau[z+1][j]==plateau[z][j]){
              plateau[z+1][j]=2*plateau[z][j];
              plateau[z][j]=0;
              score=score+plateau[z+1][j];

            }

            else{
              break;
            }

          }
        }
      }
    }
  }

  spawn(plateau);
  affiche_ligne(plateau);

}

void deplace_h(int plateau[4][4]){

    int i,j;

  for (j=0;j<4;j++){

    for(i=0;i<4;i++){
      
      if (plateau[i][j]!=0)
      {
        
        int z=j;

        for(z=j;z>=0;z--){

          if(plateau[i][z-1]==0){
            plateau[i][z-1]=plateau[i][z];
            plateau[i][z]=0;

          }

          if(plateau[i][z-1]!=0){
            if(plateau[i][z-1]==plateau[i][z]){
              plateau[i][z-1]=2*plateau[i][z];
              plateau[i][z]=0;
              score=score+plateau[i][z-1];

            }

            else{
              break;
            }

          }
        }
      }  
    }
  }

  spawn(plateau);
  affiche_ligne(plateau);

}









void emtasser_bas(int plateau[4][4]){
  int i, j, pos, z;
   for(i=0;i<4;i++){

        j = 3;
        int pos =3;
        /// emtasser
        while ((j>0) && (pos>1)){

          
          if(plateau[i][j] ==0){
                for (z=j; z>0; z--){
                  plateau[i][z]=plateau[i][z-1];
                }
                pos--;
          }
          else{
            j--; 
          }

          }

   }
}

void deplace_b(int plateau[4][4]){

  int i,j;

  for (i=0; i<4; i++){
      j=3;
  
 
    do {
        emtasser_bas(plateau);
         if (plateau[i][j]!=0){
            if (plateau[i][j]==plateau[i][j-1]){
                  plateau[i][j]= 2*plateau[i][j];
                  plateau[i][j-1]=0;
            }
           
         }
         j--;
         }while(j>0);
        
}

       /* if((plateau[i][j]!=0) && (plateau[i][j]== plateau[i][j-1])) 
            plateau[i][j] = 2*plateau[i][j];
            plateau[i][j-1] =0;

            
            for (z=j-1; z>0; z--){
              plateau[i][z] = plateau[i][z-1];
              plateau[i][z-1]= 0;

            }

        }


    }  */
       

  spawn(plateau);
  affiche_ligne(plateau);

}















void sauvegardepartie(int plateau[4][4]){

  FILE* ecriture; 
  char* nomfichier= "test.txt";

  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      ecriture= fopen(nomfichier,"a");
      fprintf(ecriture,"%d\n",plateau[i][j]);
      fclose(ecriture);
    }
  }
}

int chargerpartie(int plateau[4][4]) {

  FILE* lecture;
  char* nomfichier= "test.txt";
  char ligne[MAXCARAC];
  lecture=fopen(nomfichier,"r");
  int i=0;
  int j=0;


     while(fgets(ligne,MAXCARAC,lecture)!= NULL){     // boucle pour lire toute les lignes d'un code

      plateau[i][j] = atoi(ligne);

      if(j==3){

        j=0;
        i=i+1; 
      
      }

      else{

        j=j+1; 
      
      }

     
    } 
    
  fclose(lecture);
  return plateau[i][j]; 
}

  


char SaisieDirection(int plateau[4][4]){

  char key;
  key=getchar();
  switch (key)
  {
    case 'z':
      deplace_h(plateau);

      break;
    case 's':
      deplace_b(plateau);

      break;
    case 'q':
      deplace_g(plateau);

      break;
    case 'd':
      deplace_d(plateau);
      
      break;
  } 
}

void fin(int plateau[4][4]){

  int hauteur;
  int largeur;

  for(largeur=0;largeur<4;largeur++){
    for(hauteur=0;hauteur<4;hauteur++){

      if(plateau[largeur][hauteur]==2048){

        printf("Gagner !");

        exit(0);

      }

    }

  }

}



int main(void){

  int plateau[4][4];

  int largeur;
  int hauteur;

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){
    for( largeur=0 ; largeur<4 ;largeur++ ){
      plateau[largeur][hauteur]=0;
    }
  }


  int plateau2[4][4];

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){
    for( largeur=0 ; largeur<4 ;largeur++ ){
      plateau2[largeur][hauteur]=0;
    }
  }

  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);                   // Texte rouge (C) sur fond noir (0)
  printf ("                              -2048-\n");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);                   // Texte blanc (F) sur fond noir (0)

  printf("\n\n");

  printf("Saississez le nombre de joueur\n\n");
  printf("Tapez 1 ou 2;\n\n");

  int nb_j,rep;

  scanf("%d", &nb_j);

  srand(time(NULL));

  if(nb_j==1){

    printf("\nVoulez vous charger une partie precedemment sauvegarder ? Tapez 1 pour charger sinon un autre chiffre pour continuer \n");
    scanf("%d",&rep);

    if(rep==1){

      chargerpartie(plateau);
      affiche_ligne(plateau);

      int tour;

      for(tour=0;tour<10000;tour++){

        SaisieDirection(plateau);
        fin(plateau);

        for(largeur=0;largeur<4;largeur++){
          for(hauteur=0;hauteur<4;hauteur++){
            if(plateau[largeur][hauteur]!=0){
              if((plateau[largeur][hauteur]!=plateau[largeur-1][hauteur]) && (plateau[largeur][hauteur]!=plateau[largeur+1][hauteur]) && (plateau[largeur][hauteur]!=plateau[largeur][hauteur-1]) && (plateau[largeur][hauteur]!=plateau[largeur][hauteur+1])){
                int pos=0;
                pos=pos+1;
                if(pos==64){
                  printf("Perdu !\n");
                  exit(0);
                }
              }
            }
          }
        }

      } 

    }
  
  
    if(rep!=1){
      int nbgen=rand()%3+1;
      int nbgen2=rand()%3+1;

      int nbgen3=rand()%3+1;
      int nbgen4=rand()%3+1;

      plateau[nbgen][nbgen2]=2;
      plateau[nbgen3][nbgen4]=2;
    
      affiche_ligne(plateau);
  
      int tour;

      for(tour=0;tour<10000;tour++){

        SaisieDirection(plateau);
        fin(plateau);

        int hauteur;
        int largeur;

        for(largeur=0;largeur<4;largeur++){
          for(hauteur=0;hauteur<4;hauteur++){
            if(plateau[largeur][hauteur]!=0){
              if((plateau[largeur][hauteur]!=plateau[largeur-1][hauteur]) && (plateau[largeur][hauteur]!=plateau[largeur+1][hauteur]) && (plateau[largeur][hauteur]!=plateau[largeur][hauteur-1]) && (plateau[largeur][hauteur]!=plateau[largeur][hauteur+1])){
                int pos=0;
                pos=pos+1;
                if(pos==64){
                  printf("Perdu !\n");
                  exit(0);
                }
              }
            }
          }
        }

      }
    }

  } 

  if(nb_j==2){

    int nbgen=rand()%3+1;     // 2 pour joeur 1
    int nbgen2=rand()%3+1;

    int nbgen3=rand()%3+1;    // 2 pour joueur 1
    int nbgen4=rand()%3+1;

    int nbgen5=rand()%3+1;    // 2 pour joueur 2    
    int nbgen6=rand()%3+1;

    int nbgen7=rand()%3+1;    // 2 pour joueur 2
    int nbgen8=rand()%3+1;

    plateau[nbgen][nbgen2]=2;
    plateau[nbgen3][nbgen4]=2;

    plateau2[nbgen5][nbgen6]=2;
    plateau2[nbgen7][nbgen8]=2;

    printf("Plateau Joueur 1");
    affiche_ligne(plateau);

    printf("Plateau Joueur 2");
    affiche_ligne(plateau2);

    int cp=1;
    int tour;

    for(tour=0;tour<10000;tour++){

      cp=(cp+1)%2;

      if(cp==0){

        printf("Joueur 1, joue");

        SaisieDirection(plateau);
        fin(plateau);

        for(largeur=0;largeur<4;largeur++){
        for(hauteur=0;hauteur<4;hauteur++){
          if(plateau[largeur][hauteur]!=0){
            if((plateau[largeur][hauteur]!=plateau[largeur-1][hauteur]) && (plateau[largeur][hauteur]!=plateau[largeur+1][hauteur]) && (plateau[largeur][hauteur]!=plateau[largeur][hauteur-1]) && (plateau[largeur][hauteur]!=plateau[largeur][hauteur+1])){
              int pos=0;
              pos=pos+1;
              if(pos==64){
                printf("Perdu !\n");
                exit(0);
              }
            }
          }
        }
      }


      if(cp==1){
        
        printf("Joueur 2, joue");

        SaisieDirection(plateau2);
        fin(plateau2);

        for(largeur=0;largeur<4;largeur++){
          for(hauteur=0;hauteur<4;hauteur++){
            if(plateau2[largeur][hauteur]!=0){
              if((plateau2[largeur][hauteur]!=plateau2[largeur-1][hauteur]) && (plateau2[largeur][hauteur]!=plateau2[largeur+1][hauteur]) && (plateau2[largeur][hauteur]!=plateau2[largeur][hauteur-1]) && (plateau2[largeur][hauteur]!=plateau2[largeur][hauteur+1])){
                int pos=0;
                pos=pos+1;
                if(pos==64){
                  printf("Perdu !\n");
                  exit(0);
                }
              }
            }
          }
        }
      }
    }
  }
}
}