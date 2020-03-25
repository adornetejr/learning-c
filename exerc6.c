//Programador: Panco

#include"stdio.h"
#include"conio.h"

main(){
       int valor, soma = 0, media;
       int i = 0;
       FILE *arq;
       if((arq = fopen("Arquivo.DAT", "rb")) == NULL)
       printf("\nProblema com o arquivo!\n");
       else{
            fread(&valor, sizeof(int), 1, arq);
            printf("\n\nValores reais positivos\n\n");
            while(!feof(arq)){
                              soma = soma + valor;
                              printf(" '%d' ", valor);
                              fread(&valor, sizeof(int), 1, arq);
                              i++;
            }//fim while
            media =soma /i;
            fclose(arq);
            printf("\n\nMedia dos valores reais: %d", media);                  
            }//fim else
            getche();
            }//fim main