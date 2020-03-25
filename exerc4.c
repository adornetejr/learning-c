#include<stdio.h>
#include<stdlib.h>
// nome da função
int pegavalor(void);

//programa
main()
{ 
      int resultado;
      //ao invés de fazer o calculo no programa você insere somente a função  
       economizando linhas de código e ficando bem mais fácil

      resultado=pegavalor();
      printf("o resultado é %i",resultado);
      system("pause");
}
//a função criada que vai fazer o cálculo da potência
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