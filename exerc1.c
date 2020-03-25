//Programador: Panco

#include"stdio.h"
#include"stdlib.h"
#include"conio.h"

const int flag = -999;

main(){

int num;
FILE *arq;

if((arq = fopen("Arquivo.DAT", "wb")) == NULL)
printf("\nArquivo com problemas!\n");
else{
printf("\n\n\t'Digite -999 para parar as insercoes'\n\n");
printf("Entre com os valores: ");
scanf("%d", &num);
while(num != flag){
fwrite (&num, sizeof(int), 1, arq);//Gravando variavel no arquivo
printf("Entre com os valores: ");
scanf("%d", &num);
}//fim while
fclose(arq);
}//fim else
getche();
}//fim main


