#include<stdio.h>
#include<stdlib.h>
// nome da fun��o
int pegavalor(void);

//programa
main()
{ 
      int resultado;
      //ao inv�s de fazer o calculo no programa voc� insere somente a fun��o  
       economizando linhas de c�digo e ficando bem mais f�cil

      resultado=pegavalor();
      printf("o resultado � %i",resultado);
      system("pause");
}
//a fun��o criada que vai fazer o c�lculo da pot�ncia
int pegavalor(void)
{int base,pot,res=1,var;
 printf("digite a base ");
 scanf("%i",&base);
 printf("digite a potencia ");
 scanf("%i",&pot);
 for(var=1;var<=pot;var++)
 {res=res*base;}
 return res;
}