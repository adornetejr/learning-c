/*
Algoritmo que l� o nome dos alunos e suas respectivas cinco notas.
Inicialmente o algoritmo deve perguntar quantos alunos existem na turma e deve tamb�m escrever:
 - Nome dos alunos que foram aprovados em todas as mat�rias
 - dos aprovados nas mat�rias 1 e 4
 - A porcentagem dos aprovados na mat�ria 3

 Por: luiz@luizdiniz.net
*/

#include <string.h>
#include <iostream>

using namespace std;


int main ()
{
    system ("color 1F");
    //Declara��o de Vari�veis
    int Qtde, i, Media;
    double x=0;
    int Mat1[100], Mat2[100], Mat3[100], Mat4[100], Mat5[100];
    char Nome[100][100];

    //Usu�rio informa a quantidade de alunos na turma
    cout << "Digite a quantidade de alunos na turma: ";
    cin >> Qtde;

    cout << "\n\nDigite a m�dia adotada na escola. Ex: 60: ";
    cin >> Media;

    //Entra na repeti��o para o usu�rio entrar a nota de todos os alunos
    for(i=1;i<Qtde+1;i++)
    {
        system ("cls");

        cout << "\n\nDigite o nome do aluno " << i << ":";
        cin >> Nome[i];

        cout << "\n\nDigite a nota do aluno na mat�ria 1:";
        cin >> Mat1[i];

        cout << "\n\nDigite a nota do aluno na mat�ria 2:";
        cin >> Mat2[i];

        cout << "\n\nDigite a nota do aluno na mat�ria 3:";
        cin >> Mat3[i];

        cout << "\n\nDigite a nota do aluno na mat�ria 4:";
        cin >> Mat4[i];

        cout << "\n\nDigite a nota do aluno na mat�ria 5:";
        cin >> Mat5[i];
    }

    system ("cls");

    cout << "Obrigado! Voc� j� informou todas as notas\n\n";
    system ("pause");

    //Escrever alunos com m�dia em todas as mat�rias:
    system ("cls");
    cout << "Alunos com nota maior ou igual a " << Media << " em todas as mat�rias:\n\n";

    for(i=1;i<Qtde+1;i++)
    {
        if(Mat1[i]>=Media && Mat2[i]>=Media && Mat3[i]>=Media && Mat4[i]>=Media && Mat5[i]>=Media)
        {
            cout << "O aluno: " << Nome[i] << " foi aprovado em todas as mat�rias.\n\n";
        }
    }

    system ("pause");

    //Escrever alunos aprovados nas mat�rias 1 e 4:
    system ("cls");
    cout << "Alunos com nota maior ou igual a " << Media << " em todas as mat�rias:\n\n";

    for(i=1;i<Qtde+1;i++)
    {
        if(Mat1[i]>=Media && Mat4[i]>=Media)
        {
            cout << "O aluno: " << Nome[i] << " foi aprovado nas mat�rias 1 e 4.\n\n";
        }
    }

    system ("pause");

    //Escrever a porcentagem de aprovados na mat�ria 3:
    system ("cls");
    cout << "Alunos com nota maior ou igual a " << Media << " na mat�ria 3 em porcentagem:\n\n";

    for(i=1;i<Qtde+1;i++)
    {
        if(Mat3[i]>=Media)
        {
            x++;
        }
    }

    x=x/Qtde;
    x=x*100;

    cout<< "A porcentagem de alunos aprovados na mat�ria 3 e de: " << x << " .\n\n\n";

    cout<< "Obrigado!!!";

system ("pause");
}