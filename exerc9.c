// Teste_De_Socket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "TpComTcpipSvr.h"

					//declara a classe na head



int main(int argc, char* argv[])


{
	printf("Alo Mundo!\n");

	TpComTcpipSvr servidorDeSocket;			//instancia a classe

	servidorDeSocket.DefinePortaTcp(7777);	//define a porta de comunicação

	BOOL resultado = servidorDeSocket.AbrePortaTcpSvr();	//tenta abrir a portadefinida e joga o resultado na variavel

	if (resultado == FALSE) {
		return 0;							//se não abrir retorna 0
	}

	resultado = servidorDeSocket.AbrePortaTcpCli();	 //tenta abrir a porta definida no cliente

	if (resultado == FALSE) {
		return 0;							//se não abrir retorna 0
	}

	std::cout << "Conectado!!!!" << std::endl;		//se abrir escreve mensagem na tela

	const DWORD tamanhoBuffer = 1024;		//define o tamanho max do dado a ser recebido 
	BYTE bufferDeDados[tamanhoBuffer];		//define um string para receber dados do cliente
	resultado = servidorDeSocket.RdDadoPortaTcp(bufferDeDados, tamanhoBuffer);	//tenta receber o dado do cliente e joga o resultado na variavel

	if (resultado == FALSE) {
		return 0;
	}
	else {
		std::cout << "dado recebido ok!!! \n";	//se receber escreve mensagem na tela  
	}


	char chTag, chValTag;
	int x;

	

	//std::cout << (char*) bufferDeDados << std::endl;	//escreve na tela a string recebida.
	

	/*	if (bufferDeDados[0] == '$')
		{
			x=1;
			while (bufferDeDados[x] != '#')
			{
				chTag[x] = bufferDeDados[x];
			    x++;
			}
	       while (bufferDeDados[x] != '!')
		   {
			   chValTag[x] = bufferDeDados[x];
			   x++;
		   }

		}

		printf("%s",chTag);
		printf("%s",chValTag);*/
				printf("%s",bufferDeDados[0]);
			
	return 0;
}