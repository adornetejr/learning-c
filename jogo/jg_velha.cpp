#include<stdio.h>
#include<stdlib.h>
/*
   PROGRAMA........: JOGO DA VELHA V. 2.0
   CRIADO EM.......: 11/11/2007 
   ATUALIZADO EM...: 30/07/2008
   AUTOR...........: THIAGO C. SERRILHO
   E-MAIL..........: webserrilho@gmail.com / webserrilho@hotmail.com
   DESCRIÇÃO.......: TRADICIONAL JOGO DA VELHA ONDE O OBJETIVO DO JOGO É FAZER
                     UMA SEQUENCIA DE "X" OU DE "O". O JOGADOR DEVE INFORMAR O
                     NUMERO DA LINHA E DA COLUNA ONDE DESEJA FAZER A JOGADA.
*/
main()
{
   char matriz[4][4], valor, jog1[60], jog2[60], resp;
   int linha=0, coluna=0, i=0, j=0, empate=0, venceu=0,cont=1, jogada=0, verifica[4][4];
   do
   {
      jogada=1;
      empate=0;
      venceu=0;
      fflush(stdin);  
      printf("           JOGO DA VELHA V. 2.0\n");
      printf("           ==== == ===== == ===\n\n\n\n");
      printf("INFORME O NOME DO JOGADOR 1: "); gets(jog1); 
      printf("INFORME O NOME DO JOGADOR 2: "); gets(jog2);
      printf("===============================================================\n");
      printf("JOGADOR 1: %s = \"X\"\n", jog1);
      printf("JOGADOR 2: %s = \"O\"\n", jog2);
      printf("===============================================================\n");
      printf("PRESSIONE \"ENTER\" PARA CONTINUAR..."); getchar();
      system("cls");
      for(i = 0; i <= 3; i++)
      {
         for(j = 0; j <= 3; j++)
         {
            matriz[i][j]  =' '; //esvazia os vetores.
            verifica[i][j]=' '; //esvazia os vetores.
         }
      }
      
      do
      {
         if(jogada <= 10) system("cls");  
         printf("\n");
         for(i = 1; i <= 3; i++)
         {
            for(j = 1; j <= 3; j++)
            {
               //controla o preenchimento dos valores.
               if(matriz[i][j] == 'X' || matriz[i][j] == 'O')
               printf(" %2c  ",matriz[i][j]); //mostra os valores colocados.
               else
               printf("     "); //deixa em branco espaços ainda não informados.
               if(j <= 2)
               printf("%c", -77); //desenha as colunas.
            }
            printf("\n");
            if(i <= 2) //controla a exibição da última linha do desenho.
            for(cont = 1; cont <= 15; cont++)
            {
               printf("%c", -60); //desenha as linhas.
               if(cont == 5 || cont == 10) 
               printf("%c", -59); //coloca o caractere '+' na junção das linhas e colunas.
            }
            printf("\n");
         }
         
         if(venceu==1)
         {
            printf("===============================================================\n\n");
            if (jogada%2 == 0)printf("RESULTADO: >>> \"X\" VENCEU <<<\n");
            else printf("RESULTADO: >>> \"O\" VENCEU <<<\n");
            goto FIM; //termina o jogo
         }
         if(empate == 1)
         {
            printf("===============================================================\n\n");
            printf("RESULTADO: >>> O JOGO EMPATOU <<<\n");
            goto FIM; //termina o jogo
         }
         
         if(jogada % 2 != 0) //Impar = jogador 1, Par = jogador 2.
         {
            printf("VEZ DO JOGADOR 1: %s = \"X\"\n", jog1);
            valor= 'X';
         }
         else
         {
            printf("VEZ DO JOGADOR 2: %s = \"O\"\n", jog2);
            valor= 'O';
         }
         printf("===============================================================\n\n");
         VOLTA:;
         do
         {
            printf("INFORME O NUMERO DA LINHA.: "); scanf("%d",&linha);
            if(linha > 3) printf("O numero da linha nao pode ser maior que 3.\n");
            if(linha < 1) printf("O numero da linha nao pode ser menor que 1.\n");
         }while(linha > 3 || linha < 1);
         do
         {
            printf("INFORME O NUMERO DA COLUNA: "); scanf("%d",&coluna);
            if(coluna > 3) printf("O numero da coluna nao pode ser maior que 3.\n");
            if(coluna < 1) printf("O numero da coluna nao pode ser menor que 1.\n");
         }while(coluna > 3 || coluna < 1);
         
         if(verifica[linha][coluna]==1) //verifica se a jogada já foi feita
         {
            printf(">>> Esta jogada ja foi feita!! <<<\n");
            goto VOLTA;
         }
         else
         {
            matriz[linha][coluna]=valor; // coloca o valor no jogo "X" ou "O".
            verifica[linha][coluna]=1;   // coloca valor 1 em jogadas já feitas
         }
         //VERIFICA LINHAS.
         if(matriz[1][1]=='X' && matriz[1][2]=='X' && matriz[1][3]=='X') venceu=1;
         if(matriz[2][1]=='X' && matriz[2][2]=='X' && matriz[2][3]=='X') venceu=1;
         if(matriz[3][1]=='X' && matriz[3][2]=='X' && matriz[3][3]=='X') venceu=1;
         if(matriz[1][1]=='O' && matriz[1][2]=='O' && matriz[1][3]=='O') venceu=1;
         if(matriz[2][1]=='O' && matriz[2][2]=='O' && matriz[2][3]=='O') venceu=1;
         if(matriz[3][1]=='O' && matriz[3][2]=='O' && matriz[3][3]=='O') venceu=1;			
         //VERIFICA COLUNAS.
         if(matriz[1][1]=='X' && matriz[2][1]=='X' && matriz[3][1]=='X') venceu=1;
         if(matriz[1][2]=='X' && matriz[2][2]=='X' && matriz[3][2]=='X') venceu=1;
         if(matriz[1][3]=='X' && matriz[2][3]=='X' && matriz[3][3]=='X') venceu=1;
         if(matriz[1][1]=='O' && matriz[2][1]=='O' && matriz[3][1]=='O') venceu=1;
         if(matriz[1][2]=='O' && matriz[2][2]=='O' && matriz[3][2]=='O') venceu=1;
         if(matriz[1][3]=='O' && matriz[2][3]=='O' && matriz[3][3]=='O') venceu=1;
         //VERIFICA DIAGONAIS.
         if(matriz[1][1]=='X' && matriz[2][2]=='X' && matriz[3][3]=='X') venceu=1;
         if(matriz[1][3]=='X' && matriz[2][2]=='X' && matriz[3][1]=='X') venceu=1;
         if(matriz[1][1]=='O' && matriz[2][2]=='O' && matriz[3][3]=='O') venceu=1;
         if(matriz[1][3]=='O' && matriz[2][2]=='O' && matriz[3][1]=='O') venceu=1;
         
         jogada++; //incrementa as jogadas
         if(jogada > 9) empate=1; //jogo empatou
      }while(jogada >1 );
      FIM:;
      printf("\n===============================================================\n");
      printf("DESEJA JOGAR NOVAMENTE (S/N): ");
      scanf("%s",&resp);
      system("cls"); //Limpa a tela para recomeçar o jogo.
   }while(resp=='s' || resp=='S');	
}
