// Teste_Socket_Cliente.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"				
#include <iostream>
#include "TpComTcpipCli.h"		//declara a classe na head

int main(int argc, char* argv[])
{
	printf("Olá Servidor!\n");
	

	TpComTcpipCli socketCliente;						//instancia a classe

	socketCliente.DefinePortaTcp("Servidor001", 7777);	//define o IP e a porta do servidor

	BOOL resultado = socketCliente.AbrePortaTcp();		//tenta abrir a porta definida e joga o resultado na variavel

	if (!resultado)
		return 0;										//se (resultado == 0) retorna 0 

	std::cout << "Cliente conectado!!!!" << std::endl;	//se (resultado == 1) escreve mensagem na tela

	BYTE mensagemEnviada[1024] = "Teste de Mensagem"; //define uma string de 1024 pos e anexa a mensagem
	
	resultado = socketCliente.WrDadoPortaTcp(mensagemEnviada, 1024); //tenta escrever a string na porta definida 
	                                                                 //e joga o resultado na variavel

	if (!resultado) 
		return 0;

	std::cout << "Mensagem enviada para o servidor!!!!" << std::endl; //se (resultado==1) escreve mensagem na tela

	return 0;
}
