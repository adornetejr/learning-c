/*
  Author: Bruno Vicente Alves de Lima
  Date: 31/12/08 12:51
  Description: Calculadora
*/
#include<stdio.h>
main()
{
    float num1,num2,total,n;
    char opcao;
    do
    {
        system("color 0b");
        printf("\t\t>>>>CALCULADORA<<<<\n\nAutor: Bruno Vicente");
        printf("\nBacharelando em Ciencia da Computacao");
        printf("\n\n\tMENU DE OPCOES");
        printf("\n\nDigite + para adicao");
        printf("\nDigite - para subtracao");
        printf("\nDigite x para multiplicacao");
        printf("\nDigite / para divisao");
        printf("\nDigite p para potenciacao");
        printf("\nDigite r para radiciacao");
        printf("\nDigite c para porcentagem");
        printf("\nDigite s para sair");
        printf("\n\n>>> ");
        scanf("%c", &opcao);
        switch(opcao)
        {
        case '+':
            do
            {
                system("cls");
                printf("OPERACAO: SOMA");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite a primeira parcela: ");
                scanf("%f", &num1);
                if (num1!=-0)
                {
                    printf("\n\nDigite a segunda parcela: ");
                    scanf("%f", &num2);
                    total = num1+num2;
                    system("cls");
                    printf("RESULTADO");
                    printf("\n\n%.2f + %.2f = %.2f", num1, num2, total);
                    getch();
                }
                else
                {
                    system("cls");
                    printf("Sair da SOMA?");
                    getch();
                }
            }
            while(num1!=-0); //fim do
            break;
        case '-':
            do
            {
                system("cls");
                printf("OPERACAO: SUBTRAÇÃO");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite a primeira parcela: ");
                scanf("%f", &num1);
                if(num1!=-0)
                {
                    printf("\n\nDigite a segunda parcela: ");
                    scanf("%f", &num2);
                    total = num1-num2;
                    system("cls");
                    printf("RESULTADO");
                    printf("\n\n%.2f - %.2f = %.2f", num1, num2, total);
                    getch();
                }
                else
                {
                    system("cls");
                    printf("Sair da SUBTRACAO?");
                    getch();
                }
            }
            while(num1!=-0); //fim do
            break;
        case 'x':
        case 'X':
            do
            {
                system("cls");
                printf("OPERACAO: MULTIPLICACAO");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite o primeiro numero: ");
                scanf("%f", &num1);
                if(num1!=-0)
                {
                    printf("\n\nDigite o segundo numero: ");
                    scanf("%f", &num2);
                    total = num1*num2;
                    system("cls");
                    printf("RESULTADO");
                    printf("\n\n%.2f x %.2f = %.2f", num1, num2, total);
                    getch();
                }//fim if
                else
                {
                    system("cls");
                    printf("Sair da MULTIPLICACAO?");
                    getch();
                }
            }
            while(num1!=-0); //fim do
            break;
        case '/':
            do
            {
                system("cls");
                printf("OPERACAO: DIVISAO");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite o primeiro numero: ");
                scanf("%f", &num1);
                if(num1!=-0)
                {
                    printf("\n\nDigite o segundo numero: ");
                    scanf("%f", &num2);
                    if(num2!=0)
                    {
                        total = num1/num2;
                        system("cls");
                        printf("RESULTADO");
                        printf("\n\n%.2f : %.2f = %.2f", num1, num2, total);
                        getch();
                    }
                    else
                    {
                        system("cls");
                        printf("RESULTADO");
                        printf("\n\nNao existe divisao por zero!");
                        getch();
                    }
                }//fim if
                else
                {
                    system("cls");
                    printf("Sair da DIVISAO?");
                    getch();
                }
            }
            while(num1!=-0);
            break;
        case 'p':
        case 'P':
            do
            {
                system("cls");
                printf("OPERACAO: POTENCIACAO");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite o numero: ");
                scanf("%f", &num1);
                if(num1!=-0)
                {
                    printf("\n\nDigite o indice: ");
                    scanf("%f", &n);
                    total = pow(num1,n);
                    system("cls");
                    printf("RESULTADO:");
                    printf("\n\n%.2f elevado a %.f vale %.2f", num1,n,total);
                    getch();
                }//fim if
                else
                {
                    system("cls");
                    printf("Sair da POTENCIACAO?");
                    getch();
                }//fim else
            }
            while(num1!=-0);
            break;
        case 'r':
        case 'R':
            do
            {
                system("cls");
                printf("OPERACAO: RADICIACAO");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite um numero: ");
                scanf("%f", &num1);
                if(num1!=-0)
                {
                    if(num1>=0)
                    {
                        printf("\n\nDigite o indice: ");
                        scanf("%f", &n);
                        total = pow(num1,1/n);
                        if(n<0)
                        {
                            system("cls");
                            printf("\aERRO:");
                            printf("\n\nNao existe raiz com indice negativo!");
                            getch();
                        }
                        else
                        {
                            system("cls");
                            printf("RESULTADO");
                            printf("\n\nA raiz %.2f de %.2f vale %.2f.",n,num1,total);
                            getch();
                        }
                    }//fim if menor
                    else
                    {
                        system("cls");
                        printf("\aERRO:");
                        printf("\n\nNao existe raiz de numero negativo.");
                        getch();
                    }//fim else menor
                }//fim if
                else
                {
                    system("cls");
                    printf("Sair da RADICIACAO?");
                    getch();
                }//fim else
            }
            while(num1!=-0);
            break;
        case 'c':
        case 'C':
            do
            {
                system("cls");
                printf("OPERACAO: POTENCIACAO");
                printf("\n\nOBS.:Digite -0 para sair");
                printf("\n\nDigite um numero: ");
                scanf("%f", &num1);
                if(num1!=-0)
                {
                    printf("\n\nDigite a porcentagem: ");
                    scanf("%f", &n);
                    if(n>=0)
                    {
                        total = (num1*n)/100;
                        system("cls");
                        printf("RESULTADO:");
                        printf("\n\n%.2f por cento de %.2f vale %.2f", n,num1,total);
                        getch();
                    }//fim if
                    else
                    {
                        system("cls");
                        printf("\aERRO:");
                        printf("\n\nNao existe porcentagem negativa!");
                        getch();
                    }//fim else
                }//fim if
                else
                {
                    system("cls");
                    printf("Sair da PORCENTAGEM?");
                    getch();
                }//fim else
            }
            while(num1!=-0);
            break;
        case 's':
        case 'S':
            system("cls");
            printf("Pressione ENTER para sair da calculadora!");
            getch();
            break;
        default:
            system("cls");
            printf("\aERRO:");
            printf("\n\nOpcao Invalida!");
            getch();
        }//fim switch
        fflush(stdin);
        system("cls");
    }
    while(opcao!='s'&&opcao!='S'); //fim do maior
}//fim main
