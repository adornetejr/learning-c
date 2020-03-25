/*********************** Funcao principal ******************/
int main() {

	// Limpar a tela
	system("clear");

	printf("\n Inicializando servidor %s...",SERVERNAME);

	Host server;
	if (setServer(&server, PORTA) > 0)
        	saidaErro(" Nao foi possivel criar o socket do servidor.");

	printf("\n [Inicializado com sucesso]\n\n");
	printf("\n ***********************************************************");
	printf("\n Eu sou o servidor http em C. Estou escutando a porta [%d]", PORTA);
	printf("\n ***********************************************************\n\n");

	Host client[MAX_THREAD];

	//Iniciando o vetor de clientes com o valor 0
	int i;
	for (i=0; i<MAX_THREAD;i++)
		client[i].socket = 0;

	int threadCOD = 0;
	pthread_t thread[MAX_THREAD];
	
	while(1) {
		//Se o socket do client[threadCOD] estiver com o valor de inicio 0 (o que significa que nao esta sendo usado)
		if (client[threadCOD].socket == 0){
			//Se a funcao de sokcet accept for false entao retorna erro
			if (initAccept(&server,&client[threadCOD]) == false)
				saidaErro("Nao foi possivel efetuar acao de accept().\n");

			printf("\n[THREAD_COD] %d \n", threadCOD);
			turnThread_on(server, client[threadCOD], thread[threadCOD]);
		}

		//Implementando um vetor circular, se client sock nao estiver zerado (valor == 0))
		if (client[threadCOD].socket != 0)
			if (threadCOD > MAX_THREAD )  //Se o indice de vetor threadCOD for maior que a capacidade maxima de threads MAX_THREAD
				threadCOD = 0; // reinicia o indice threadCOD do vetor client com 0
			else threadCOD++; //se nao incrementa o indice do vetor client "threadCOD" +1


	}//fim do loop
}