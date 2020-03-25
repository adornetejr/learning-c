********************************/

/*  Jackpot Console Game        */

/*  By Felipe Andrade           */

/*  araujoandrade.flp@gmail.com */

/********************************/

#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <time.h>

#include <windows.h> 



#define  BLACK   0

#define  DARK_BLUE   1

#define  DARK_GREEN   2

#define  DARK_CYAN   3

#define  DARK_RED   4

#define  DARK_MAGENTA   5

#define  DARK_YELLOW   6

#define  DARK_WHITE   7

#define  GRAY   8

#define  BLUE   9

#define  GREEN   10

#define  CYAN   11

#define  RED   12

#define  MAGENTA   13

#define  YELLOW   14

#define  WHITE   15



struct Recordes{

       

       char nome1[20];

       int Recorde_Facil;

       char nome2[20];

       int Recorde_Medio;

       char nome3[20];

       int Recorde_Dificil;

       

};



void Menu(HANDLE hConsole){

	 

     SetConsoleTextAttribute(hConsole, RED); //Cor de exibição dos caraceteres

	 printf("\n\t\t    -___-___-___-___-___-___-___-___-___-");

	 printf("\n\n\t\t    -___-");

	 

     SetConsoleTextAttribute(hConsole, GREEN);

	 printf("      JACKPOT CONSOLE");

	 

     SetConsoleTextAttribute(hConsole, RED);

	 printf("\t    -___-");

	 printf("\n\n\t\t    -___-___-___-___-___-___-___-___-___-");

	 

	 SetConsoleTextAttribute(hConsole, YELLOW);

	 printf("\n\n\n\t\t\t");

	 printf("      1 - Novo Jogo");

	 printf("\n\n\t\t\t");

	 printf("      2 - Instrucoes");

	 printf("\n\n\t\t\t");

	 printf("      3 - Recordes");

	 printf("\n\n\t\t\t");

	 printf("      4 - Sair");

	 

	 SetConsoleTextAttribute(hConsole, CYAN);

     printf("\n\n\n\n     Digite a opcao desejada: ");

	 

}



void Menu_Novo_Jogo(HANDLE hConsole){

     

     SetConsoleTextAttribute(hConsole, RED);

     printf("\n\t\t    -___-___-___-___-___-___-___-___-___-");

     printf("\n\n\t\t    -___-");

         

     SetConsoleTextAttribute(hConsole, GREEN);

     printf("    Grau de dificuldade"); 

         

     SetConsoleTextAttribute(hConsole, RED);

     printf("    -___-");

     printf("\n\n\t\t    -___-___-___-___-___-___-___-___-___-");

         

     SetConsoleTextAttribute(hConsole, YELLOW);

     printf("\n\n\n\t");

     printf("      1 - Facil");

    	 

     SetConsoleTextAttribute(hConsole, BLUE);

     printf("   (numeros de 1 a  20, 10 chances)");

    	 

     SetConsoleTextAttribute(hConsole, YELLOW);

     printf("\n\n\t");

     printf("      2 - Medio");

    	 

     SetConsoleTextAttribute(hConsole, BLUE);

     printf("   (numeros de 1 a  50,  7 chances)");

    	 

     SetConsoleTextAttribute(hConsole, YELLOW);

     printf("\n\n\t");

 	 printf("      3 - Dificil");

    	 

     SetConsoleTextAttribute(hConsole, BLUE);

     printf(" (numeros de 1 a 100,  5 chances)");

     

}



void Novo_Jogo(HANDLE hConsole){

     

     int df, numero_sorteado, palpite, pontuacao = 0, tentativas = 0, chances, discrepancia = 0;

     char jogador[10];

     

     FILE *Novo_Recorde; //ponteiro para o arquivo

     struct Recordes Novo; //variável do tipo struct Recordes

	 

	 do{ 

        Menu_Novo_Jogo(hConsole);

        

   	    SetConsoleTextAttribute(hConsole, CYAN);

   	    printf("\n\n\n\n\tDigite sua escolha : ");

	    scanf("%d", &df);

	    

	    if(df < 1 || df > 3){

           SetConsoleTextAttribute(hConsole, DARK_WHITE);

	       printf("\n\t\tOpcao Invalida! Tente denovo!");

	       getch();

        }

	    system("cls");

           

     }while(df < 1 || df > 3);

	 

	 system("cls");

	 

	 SetConsoleTextAttribute(hConsole, CYAN);

	 printf("\n\nDigite ");

	 

	 SetConsoleTextAttribute(hConsole, GREEN);

	 printf ("APENAS ");

	 

	 SetConsoleTextAttribute(hConsole, CYAN);

	 printf("o seu primeiro nome: ");

	 

	 SetConsoleTextAttribute(hConsole, WHITE);

     scanf("%s", jogador);

     

     system("cls");

     

	 srand(time(NULL));

	 

	 if(df == 1){

        numero_sorteado = rand() % 20 + 1; //sorteia um número no intervalo de 1 a 20

        chances = 10;

     }

     else if(df == 2){

        numero_sorteado = rand() % 50 + 1; //sorteia um número no intervalo de 1 a 50

        chances = 7;

     }

     else if(df == 3){

        numero_sorteado = rand() % 100 + 1; //sorteia um número no intervalo de 1 a 100

        chances = 5;

     }

     

     SetConsoleTextAttribute(hConsole, RED);

     printf("\n-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___\n");

         

     SetConsoleTextAttribute(hConsole, GREEN);

     printf("\t\t\t   Jogador : %s", jogador);

     

     switch(df){

          

          case 1: printf("\n\n\t\t  O Numero sorteado esta entre 1 e 20"); 

                  break;

          

          case 2: printf("\n\n\t\t  O Numero sorteado esta entre 1 e 50"); 

                  break;

          

          case 3: printf("\n\n\t\t  O Numero sorteado esta entre 1 e 100"); 

                  break;

                  

     }

     SetConsoleTextAttribute(hConsole, RED);

     printf("\n\n-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___-___");

	 

     

	 do{

        SetConsoleTextAttribute(hConsole, CYAN);

        printf("\n\nQual o numero sorteado? ");

        

        scanf("%d", &palpite);

        

        if(palpite > numero_sorteado){

           SetConsoleTextAttribute(hConsole, CYAN);

           printf("O numero sorteado eh menor do que "); 

           

           SetConsoleTextAttribute(hConsole, RED+WHITE*16);

           printf(" %d ", palpite);

           

           discrepancia += (palpite - numero_sorteado);

           tentativas ++;

           

           SetConsoleTextAttribute(hConsole, DARK_CYAN);

           printf("\t\t Voce tem mais %d chances", chances - tentativas);

        }

        else if(palpite < numero_sorteado){

           SetConsoleTextAttribute(hConsole, CYAN);

           printf("O numero sorteado eh maior do que ");

           

           SetConsoleTextAttribute(hConsole, RED+WHITE*16);

           printf(" %d ", palpite);

           

           discrepancia += (numero_sorteado - palpite);

           tentativas ++;

           

           SetConsoleTextAttribute(hConsole, DARK_CYAN);

           printf("\t\t Voce tem mais %d chances", chances - tentativas);

        }

     

     }while((palpite != numero_sorteado) && (tentativas != chances)); 

     

     pontuacao = ((10000*df) - (discrepancia*10))/(tentativas+1);

     

     if(palpite == numero_sorteado){ //Verifica se o jogador acertou o número

        SetConsoleTextAttribute(hConsole, GREEN);

        printf("\n\n\t  PARABENS!! Voce advinhou o numero em %d tentativas", tentativas+1);

        

        SetConsoleTextAttribute(hConsole, YELLOW);

        printf("\n\n\t\t\tSUA PONTUACAO : ");

        

        SetConsoleTextAttribute(hConsole, WHITE);

        printf("%d", pontuacao);

        

        if((Novo_Recorde = fopen("Recordes", "r+")) == NULL){ //Tenta abrir um arquivo para ler e atualizar os recordes (modo "r+")

        Novo_Recorde = fopen("Recordes", "w"); //Se não houver, abre um novo arquivo para gravação (modo "w")

        

        strcpy(Novo.nome1, "*****"); //Inicializa com asteriscos o nome

        Novo.Recorde_Facil = 0; //inicializa com zero o recorde

        

        strcpy(Novo.nome2, "*****");

        Novo.Recorde_Medio = 0;

        

        strcpy(Novo.nome3, "*****");

        Novo.Recorde_Dificil = 0;

        

        fseek(Novo_Recorde, 0, SEEK_SET); //posiciona no início do arquivo

        

        fwrite(&Novo, sizeof(struct Recordes), 1, Novo_Recorde); //grava os valores iniciais

        

        fclose(Novo_Recorde); //fecha o arquivo

     }

     else{ //Caso já exista o arquivo

        

        fseek(Novo_Recorde, 0, SEEK_SET); //posiciona no início

        fread(&Novo, sizeof(struct Recordes), 1, Novo_Recorde); //lê o arquivo

        

        //se houver novo recorde, faz a atualização

        switch(df){

             

             case 1:

                  if(pontuacao > Novo.Recorde_Facil){

                     strcpy(Novo.nome1, jogador);

                     Novo.Recorde_Facil = pontuacao;

                  }

                  break; 

             

             case 2:

                  if(pontuacao > Novo.Recorde_Medio){

                     strcpy(Novo.nome2, jogador);

                     Novo.Recorde_Medio = pontuacao;

                  }

                  break;

             

             case 3:

                  if(pontuacao > Novo.Recorde_Dificil){

                     strcpy(Novo.nome3, jogador);

                     Novo.Recorde_Dificil = pontuacao;

                  }

                  break;

        }

        

        fseek(Novo_Recorde, 0, SEEK_SET); //Posiciona no início do arquivo

        fwrite(&Novo, sizeof(struct Recordes), 1, Novo_Recorde); //faz a gravação do novo recorde

        

        fclose(Novo_Recorde); //fecha o arquivo

        

     }

     }

     else if(tentativas == chances){

        SetConsoleTextAttribute(hConsole, RED);

        printf("\n\n\t\tVOCE PERDEU! Tente outra vez!");

     }

}



void Recordes(HANDLE hConsole){

     

     FILE *Novo_Recorde;

     struct Recordes Novo;

     

     SetConsoleTextAttribute(hConsole, RED);

     printf("\n\t\t    -___-___-___-___-___-___-___-___-___-");

     printf("\n\n\t\t    -___-___-");

         

     SetConsoleTextAttribute(hConsole, GREEN);

     printf("     RECORDES"); 

         

     SetConsoleTextAttribute(hConsole, RED);

     printf("      -___-___-");

     printf("\n\n\t\t    -___-___-___-___-___-___-___-___-___-");

     

     if((Novo_Recorde = fopen("Recordes", "r")) == NULL){ //Tenta abrir o arquivo "Recordes" para ler os recordes (modo "r")

        Novo_Recorde = fopen("Recordes", "w"); //Se não existir, abre novo arquivo para gravação

        

        strcpy(Novo.nome1, "*****");

        Novo.Recorde_Facil = 0;

        

        strcpy(Novo.nome2, "*****");

        Novo.Recorde_Medio = 0;

        

        strcpy(Novo.nome3, "*****");

        Novo.Recorde_Dificil = 0;

        

        fseek(Novo_Recorde, 0, SEEK_SET);

        

        fwrite(&Novo, sizeof(struct Recordes), 1, Novo_Recorde);

        

        fclose(Novo_Recorde);

     }

     else{

        fseek(Novo_Recorde, 0, SEEK_SET);

        

        fread(&Novo, sizeof(struct Recordes), 1, Novo_Recorde);

        

        SetConsoleTextAttribute(hConsole, CYAN);

        printf("\n\n\n\n\n\t\t   Nivel 1 (Facil) : ");

        

        SetConsoleTextAttribute(hConsole, WHITE);

        printf("  %s", Novo.nome1);

        

        SetConsoleTextAttribute(hConsole, YELLOW);

        printf("\t  %d", Novo.Recorde_Facil);

        

        SetConsoleTextAttribute(hConsole, CYAN);

        printf("\n\n\n\t\t   Nivel 2 (Medio) : ");

        

        SetConsoleTextAttribute(hConsole, WHITE);

        printf("  %s", Novo.nome2);

        

        SetConsoleTextAttribute(hConsole, YELLOW);

        printf("\t  %d", Novo.Recorde_Medio);

        

        SetConsoleTextAttribute(hConsole, CYAN);

        printf("\n\n\n\t\t   Nivel 3 (Dificil) : ");

        

        SetConsoleTextAttribute(hConsole, WHITE);

        printf("%s", Novo.nome3);

        

        SetConsoleTextAttribute(hConsole, YELLOW);

        printf("\t  %d", Novo.Recorde_Dificil);

        

        fclose(Novo_Recorde);

     }

     

}



void Instrucoes(HANDLE hConsole){

     

     SetConsoleTextAttribute(hConsole, RED);

     printf("\n\t\t    -___-___-___-___-___-___-___-___-___-");

     printf("\n\n\t\t    -___-___-");

         

     SetConsoleTextAttribute(hConsole, GREEN);

     printf("     Instrucoes"); 

         

     SetConsoleTextAttribute(hConsole, RED);

     printf("    -___-___-");

     printf("\n\n\t\t    -___-___-___-___-___-___-___-___-___-");

     

     SetConsoleTextAttribute(hConsole, CYAN);

     printf("\n\n\n\n   O jogo consiste em advinhar qual o numero sorteado em um dado"

            " intervalo. Para \nisso, o usuario tera um determinado numero de tentativas."

            " O intervalo e o numero \nde tentativas variam de acordo com o grau de difi"

            "culdade escolhido.");

}



int main()

{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int opc;

    

    do{ 

       Menu(hConsole);

       scanf("%d", &opc);

       SetConsoleTextAttribute(hConsole, WHITE);

       if(opc < 1 || opc > 4){

          printf("\n\t\t\tOpcao Invalida!! Tente denovo!");

          getch();

       }

       else if(opc == 1){

          system("cls");

          Novo_Jogo(hConsole);

          getch();

          

       }

       else if(opc == 2){

          system("cls");

          Instrucoes(hConsole);

          getch();

       }

       else if(opc == 3){

          system("cls");

          Recordes(hConsole);

          getch();

          

       }

       system("cls");

        

    }while(opc != 4);

	

}