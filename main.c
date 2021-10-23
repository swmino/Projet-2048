#include <stdio.h>                                                                  // Inclusion des librairies nécessaire à l'execution
#include <stdlib.h>                                                                 // du programme
#include <windows.h>
#include <time.h>

int score=0;                                                                        // Initialisation du score (variable globale)

#define MAXCARAC 1000                                                               // Maximum de caractère d'une ligne récupérée (Fct chargerpartie)

void deplace_d(int plateau[4][4]);
void deplace_g(int plateau[4][4]);
void deplace_h(int plateau[4][4]);
void deplace_b(int plateau[4][4]);


void affiche_ligne(int plateau[4][4]){
  
  int hauteur ;
  int largeur ;
  printf("SCORE : %d", score);                                                      // Affiche le score du joueur !

  printf("\n___________________________\n");
  printf("\n");

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){


    for( largeur=0 ; largeur<4 ;largeur++ ){                    




      switch( plateau[largeur][hauteur] ) {                                         // Affiche la valeur d'une case donnée, en fonction de celle-ci

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

            printf("\n___________________________\n");
      
          }

        break ;

        case 4 :

          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);  
          printf("|  4  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break ;

        case 8 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("|  8  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

 

            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break ;

        case 16 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("| 16  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break ;

        case 32 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
          printf("| 32  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 64 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
          printf("| 64  |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 128 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
          printf("| 128 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 256 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x05);
          printf("| 256 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 512 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
          printf("| 512 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){



            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 1024 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
          printf("|1024 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

    

            printf("\n");
            printf("___________________________");
            printf("\n");

          }
      
        break;

        case 2048 :
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
          printf("|2048 |" ) ;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F); 

          if(largeur==3){

           

            printf("\n");
            printf("___________________________");
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
    do {                                                        // Cherche une case libre, afin d'y ajouter la valeur '2' ou '4'
      nbgens=rand()%3;
      nbgene=rand()%3;
    }while(plateau[nbgens][nbgene]!=0);
    


    int alea;
	  alea=rand()%2+1;                                            // En fonction de la valeur d'alea :
    int val;                                                    // On aura soit '2' ou '4' dans la case libre crée ci-dessus
	  
    if(alea==1){

		  val=4;
    }

    else{

		  val=2;

    }

    plateau[nbgens][nbgene]=val;
  
}



void entasser_d(int plateau[4][4])
{
	int i,j,z;
	for(j=0;j<4;j++)
	{
		z=3;
		for (i=3;i>=0;i--)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)	
			{
				plateau[z][j]=plateau[i][j];
				if(z>i)
					{plateau[i][j]=0;}
				z--;
			}
	}

}

void deplace_d(int plateau[4][4])
{
	int i,j;
	for(i=3;i>0;i--)
		for(j=0;j<4;j++)
			if(plateau[i][j]==plateau[i-1][j])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i-1][j];        // Fusion des cases égales
				score=score+2*plateau[i-1][j];                      // Augmentation du score
				plateau[i-1][j]=0;
			}
}


void entasser_h(int plateau[4][4])
{
	int i,j,z;
	for (i=0;i<4;i++)
	{
		z=0;
		for(j=0;j<4;j++)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)
			{
				plateau[i][z]=plateau[i][j];
				if(z<j)
					{plateau[i][j]=0;}
				z++;
			}
		}

}

void deplace_h(int plateau[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			if(plateau[i][j]==plateau[i][j+1])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i][j+1];        // Fusion des cases égales
				score=score+2*plateau[i][j+1];                      // Augmentation du score
				plateau[i][j+1]=0;
			}

}


void entasser_b(int plateau[4][4])
{
	int i,j,z;
	for (i=0;i<4;i++)
	{	
		z=3;
		for(j=3;j>=0;j--)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)
			{
				plateau[i][z]=plateau[i][j];
			  if(z>j)
					{plateau[i][j]=0;}		
				z--;
			}
	}			

}

void deplace_b(int plateau[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=3;j>0;j--)
			if(plateau[i][j]==plateau[i][j-1])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i][j-1];        // Fusion des cases égales
				score=score+2*plateau[i][j-1];                      // Augmentation du score
				plateau[i][j-1]=0;
			}
}


void entasser_g(int plateau[4][4])
{
	int i,j,z;
	for (j=0;j<4;j++)
	{
		z=0;
		for(i=0;i<4;i++)                                      // Entasse le plateau dans la direction donnée
			if (plateau[i][j]!=0)	
			{
				plateau[z][j]=plateau[i][j];
				if(z<i)
					{plateau[i][j]=0;}
				z++;
			}
	}

}

void deplace_g(int plateau[4][4])
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(plateau[i][j]==plateau[i+1][j])
			{	
				plateau[i][j]=plateau[i][j]+plateau[i+1][j];        // Fusion des cases égales
				score=score+2*plateau[i+1][j];                      // Augmentation du score
				plateau[i+1][j]=0;
			}

}




void sauvegardepartie(int plateau[4][4]){

  FILE* ecriture;                               
  char* nomfichier= "sauvegarde.txt";

  for (int i = 0; i < 4; ++i)                   // On sauvegarde les cases du plateau dans un fichier externe
  {
    for (int j = 0; j < 4; ++j)
    {
      ecriture= fopen(nomfichier,"a");
      fprintf(ecriture,"%d\n",plateau[i][j]);
      fclose(ecriture);
    }
  }
}

int chargerpartie(int plateau[4][4]){

  FILE* lecture;
  char* nomfichier= "sauvegardegc.txt";
  char ligne[MAXCARAC];
  lecture=fopen(nomfichier,"r");
  int i=0;
  int j=0;


     while(fgets(ligne,MAXCARAC,lecture)!= NULL){     // Boucle qui récupère les cases sauvegarder dans la partie précédente

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
  printf("choisir la direction \n");
	key=getchar();                        // getchar(), récupère une touche, correspondant à une action
  key=getchar();                        //
	switch (key)                          //Dans chaque cas, on lance les procédures correspondant au caractère donné.
	{
		case 'z':                           // Déplacement haut

      entasser_h(plateau);
			deplace_h(plateau);
      
      break;

		case 's':                           // Déplacement bas

      entasser_b(plateau);
			deplace_b(plateau);

      break;

		case 'q':                           // Déplacement gauche
			
      entasser_g(plateau);
			deplace_g(plateau);
      
      break;

		case 'd':                           // Déplacement droite

      entasser_d(plateau);
			deplace_d(plateau);


      break;
    
    case 'c':                           // Sauvegarde

      sauvegardepartie(plateau);

      break;
	}	
}

void fin(int plateau[4][4]){

  int hauteur;
  int largeur;

  for(largeur=0;largeur<4;largeur++){
    for(hauteur=0;hauteur<4;hauteur++){

      if(plateau[largeur][hauteur]==2048){    // Vérifie la condition que '2048' soit présent sur le plateau 

        affiche_ligne(plateau);

        printf("Gagner !");                   // Si condition est vérifié, partie gagné :)

        exit(0);

      }

    }

  }

}


void fin_2(int plateau[4][4]){
  
  int i,j;

  int ct;

  int a,b;

  int cpt=0;

 
          for(i=0;i<4;i++){
            for(j=0;j<4;j++){

              a=i;
              b=j;

             if(ct=16){ // Condition : Si toutes les cases sont bloqués, alors le jeu est perdu
               printf("Perdu!\n"); // Si toutes les cases bloqués, jeu perdu :(
               exit(0);
             } 

             if(i==0 && j==0){                                                            // On vérifie si une case est bloquée : En fonction de sa position

              if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b+1]) ){ // sur le plateau. Ici, il s'agit de la première case en haut à gauche
                ct++;                                                                     // Si la case est bloqué, on la compte comme étant bloqué via le compteur
              }                                                                           // ct

             } 


            if (i==3 && j==0)  {                                                           // Même processus

              if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b+1]) ){
                
                ct++;
              }}
              
               
               
            }                   

              if(i==3 && j==3){
                if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b-1]) ){
                  ct++;
                }
              }

            if(i==0 && j==3){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b-1]) ){
                  ct++;
                }
              }
              
            if( (i==3 && j==1) || (i==3 && j==2) ){
                if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a][b+1]) ){
                  ct++;
                }
              }

              if( (i==2 && j==3) || (i==3 && j==3) ){
                if( (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a+1][b]) ){
                  ct++;
                }
              }  


              if( (i==1 && j==0) || (i==2 && j==0) ){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b+1]) && (plateau[a][b]!=plateau[a-1][b]) ){
                  ct++;
                }
              }

              if( (i==1 && j==3) || (i==2 && j==3) ){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a-1][b]) ){
                  ct++;
                }
              }

              if( (i==1 && j==2) || (i==2 && j==2) || (i==2 && j==1) || (i==1 && j==1) ){
                if( (plateau[a][b]!=plateau[a+1][b]) && (plateau[a][b]!=plateau[a][b-1]) && (plateau[a][b]!=plateau[a-1][b]) && (plateau[a][b]!=plateau[a][b+1]) ){
                  ct++;
                }
              }


            }
          

}


int main(void){

  int plateau[4][4];

  int largeur;
  int hauteur;

  for( hauteur=0 ; hauteur<4 ; hauteur++ ){                                         // Initialisation du plateau
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

  int nb_j,rep,cpt;

  cpt=0;

  scanf("%d", &nb_j);                                     // Sélection du nombre de joueur

  srand(time(NULL));

  if(nb_j==1){                                                // Si 1 joueur :

    printf("\nVoulez-vous charger une partie precedemment sauvegarder ? Si oui tapez 1, sinon un autre chiffre pour commencer une nouvelle partie \n");
    scanf("%d",&rep);

    if(rep==1){                                     // Charge la partie précedente.

    chargerpartie(plateau);
    affiche_ligne(plateau);

    int tour;
    int pos=0;

    for(tour=0;tour<10000;tour++){


    for(largeur=0;largeur<4;largeur++){
      for(hauteur=0;hauteur<4;hauteur++){
        if(plateau[largeur][hauteur]!=0){
          cpt++;
        }
      }
    }
              
    if(cpt==16){                             
      
      fin_2(plateau);

      SaisieDirection(plateau);

      fin(plateau);

      for(largeur=0;largeur<4;largeur++){
                  for(hauteur=0;hauteur<4;hauteur++){
                    if(plateau[largeur][hauteur]!=0){
                      cpt++;
                    }  
                      if(cpt!=16){
                        spawn(plateau);
                        affiche_ligne(plateau);
                      }

                      else{
                        affiche_ligne(plateau);
                      }
                
              }
            }
      }

      else{
        SaisieDirection(plateau);
        fin(plateau);
        spawn(plateau);
        affiche_ligne(plateau);
      
      }
      
      
  
  }


}

    
  
  
    if(rep!=1){                         // Crée une nouvelle partie
      int nbgen=rand()%3;
      int nbgen2=rand()%3;

      int nbgen3=rand()%3;
      int nbgen4=rand()%3;

      plateau[nbgen][nbgen2]=2;
      plateau[nbgen3][nbgen4]=2;
    
      affiche_ligne(plateau);
  
      int tour;
      int pos=0;

      for(tour=0;tour<10000;tour++){

        for(largeur=0;largeur<4;largeur++){                   // Compte le nombre de cases remplies 
      for(hauteur=0;hauteur<4;hauteur++){
        if(plateau[largeur][hauteur]!=0){
          cpt++;
        }
      }
    }
              
    if(cpt==16){                                              // Si plateau est plein :
      
      fin_2(plateau);                                         // Vérifie s'il reste des déplacements possibles !

      SaisieDirection(plateau);                               // Demande la saisie d'une direction, ou si le joueur veut sauvegarder sa partie

      fin(plateau);                                           // Vérifie si la partie est gagnée ! (ou non)

      for(largeur=0;largeur<4;largeur++){
          for(hauteur=0;hauteur<4;hauteur++){
              if(plateau[largeur][hauteur]!=0){
                cpt++;
              }                                                         //(Plateau est plein :)
                      
              if(cpt!=16){                                                      // Si le plateau a été libéré :
                spawn(plateau);                                                 // Apparition d'une valeur aléatoire !
                affiche_ligne(plateau);                                         // Affiche le plateau de jeu 
              }

              else{                                                             // Si le plateau n'est pas encore libéré
                affiche_ligne(plateau);                                         // Affiche ce plateau, en vue de s'améliorer au tour suivant !
              }
        }
      }
    }

    else{                                             // Si le plateau n'est pas plein, alors déroulement classique et;
        SaisieDirection(plateau);
        fin(plateau);
        spawn(plateau);                               // Apparition d'une valeur aléatoire
        affiche_ligne(plateau);                        
      
      }

        

      }
    }

  } 

  if(nb_j==2){                                                  // Si 2 joueur :

    int nbgen=rand()%3;     
    int nbgen2=rand()%3;

    int nbgen3=rand()%3;    
    int nbgen4=rand()%3;

    int nbgen5=rand()%3;        
    int nbgen6=rand()%3;

    int nbgen7=rand()%3;    
    int nbgen8=rand()%3;

    plateau[nbgen][nbgen2]=2;
    plateau[nbgen3][nbgen4]=2;

    plateau2[nbgen5][nbgen6]=2;
    plateau2[nbgen7][nbgen8]=2;

    printf("Plateau Joueur 1  ");
    affiche_ligne(plateau);

    printf("Plateau Joueur 2  ");
    affiche_ligne(plateau2);

    int cp;
    int tour;
    int pos=0;

    cp=0;

    for(tour=0;tour<10000;tour++){
        printf("%d \n",tour);
      

      if(cp==0){                                                 // Joueur 1 qui joue ici,

        printf("\nJoueur 1, joue  \n");

        for(largeur=0;largeur<4;largeur++){                     // Compte le nombre de cases remplies
          for(hauteur=0;hauteur<4;hauteur++){
            if(plateau[largeur][hauteur]!=0){
              cpt++;
            }
          }
        }
              
        if(cpt==16){                                             // Si plateau est plein : ( Voir explication pour le module 1 joueur )
      
          fin_2(plateau);

           SaisieDirection(plateau);

         fin(plateau);

          for(largeur=0;largeur<4;largeur++){
                  for(hauteur=0;hauteur<4;hauteur++){
                    if(plateau[largeur][hauteur]!=0){
                      cpt++;
                    }  
                      if(cpt!=16){
                        spawn(plateau);
                        printf("Plateau Joueur 1:\n");
                        affiche_ligne(plateau);
                      }

                      else{
                        printf("Plateau Joueur 1:\n");
                        affiche_ligne(plateau);
                      }
                
              }
            }
      }

      else{                                                 // Si le plateau n'est pas plein, alors déroulement classique et;
        SaisieDirection(plateau);
        fin(plateau);
        spawn(plateau);
        printf("Plateau Joueur 1:\n");
        affiche_ligne(plateau);
      
      }
        
      }

      else{                                                 // Joueur 2 qui joue ici
    

        printf("\nJoueur 2, joue   \n");

       for(largeur=0;largeur<4;largeur++){                  // Compte le nombre de cases remplies
      for(hauteur=0;hauteur<4;hauteur++){
        if(plateau2[largeur][hauteur]!=0){
          cpt++;
        }
      }
    }
              
    if(cpt==16){                                            // Si plateau est plein : ( Voir explication pour le module 1 joueur )
      
      fin_2(plateau2);

      SaisieDirection(plateau2);

      fin(plateau2);

      for(largeur=0;largeur<4;largeur++){
                  for(hauteur=0;hauteur<4;hauteur++){
                    if(plateau2[largeur][hauteur]!=0){
                      cpt++;
                    }  
                      if(cpt!=16){
                        spawn(plateau2);
                        printf("Plateau Joueur 2:\n");
                        affiche_ligne(plateau2);
                      }

                      else{
                        printf("Plateau Joueur 2:\n");
                        affiche_ligne(plateau2);
                      }
                
              }
            }
      }

      else{                                                   // Si le plateau n'est pas plein, alors déroulement classique ;
        SaisieDirection(plateau2);
        fin(plateau2);
        printf("Plateau Joueur 2:\n");
        spawn(plateau2);
        affiche_ligne(plateau2);
      
      }

        
      }
      cp=(cp+1)%2;                                            // Alterne entre les joueurs
    }
  }
}

