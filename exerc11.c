Connect.cpp: 
#include "vcl\condefs.h" 
#include "stdio.h" 
#include "stdlib.h" 
#include "string.h"
#include "Metodos.h" 
#pragma hdrstop 
//---------------------------------------------------------------------------------------------------------- 
//USERES("Connect.res");
USEUNIT("Metodos.cpp");
//----------------------------------------------------------------------------------------------------------
//Programa exemplo
int main(int argc, char **argv) 
{ 
      TParalela  Lpt;     //Instancia objeto 
      cout << "Envio de Arquivo através da Porta Paralela" << endl; 
      cout << "------------------------------------------" << endl; 
      if(argc < 3) 
      { 
            cout << "Ajuda:" << endl; 
            cout << "Use: CONNECT E Nome_do_Arquivo\n"; //Quem envia 
            cout << "Ou" << endl; 
            cout << "Use: CONNECT R Nome_do_Arquivo\n"; //Quem recebe 
       } 
       Lpt.Envia(LPT1,BIT4); //Seta Busy == 0
       if(argv[1][0] == 'R' || argv[1][0] == 'r') 
       { 
            cout << "Estação pronta para Receber arquivo!" << endl;             
            Lpt.RecebeArquivo(argv[2]); 
       }else{ 
            cout << "Estação pronta para Enviar arquivo!" << endl; 
            Lpt.EnviaArquivo(argv[2]); 
       } 
       return( 0 ); 
} 