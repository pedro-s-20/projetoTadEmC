#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
//Aluno: Pedro Sousa
//Atividade de Algoritmos e Estrutura de Dados II
//curso de Engenharia da Computa��o - UEMG

//Definindo a estrutura para agrupar as vari�veis
typedef struct pontoPlanoCartesiano{
	//criando vari�veis
	float x;
	float y;
}pontoPlanoCartesiano;

//Inicializando por par�metro
pontoPlanoCartesiano inicializandoPPam(float x, float y){
	//criando um ponto (do tipo da estrutura j� definida anteriormente) para maniupala��o
	pontoPlanoCartesiano pontoFuncao;
	//recebendo as coordenadas passadas por par�metro
	pontoFuncao.x = x;
	pontoFuncao.y = y;
	//retornando o ponto inicializado
	return pontoFuncao;
}

//Fun��o para inicializar um ponto dentro dela e retornar o ponto
pontoPlanoCartesiano inicializandoPFuncao(){
	//criando um ponto para manipula��o
	pontoPlanoCartesiano pontoFuncao;
	//pedindo as coordenadas
	printf("\nDigite a coordenada X do plano: ");
	scanf("%f", &pontoFuncao.x);
	fflush(stdin);
	printf("Digite a coordenada Y do plano: ");
	scanf("%f", &pontoFuncao.y);
	fflush(stdin);
	//retornando o ponto criado
	return pontoFuncao;
}

// Verifica o quadrante do ponto passado por par�metro
int verificaQuadrante(pontoPlanoCartesiano pontoParam){
	
	pontoPlanoCartesiano ponto = pontoParam;
	//vari�veis para verificar o sinal, sendo: 0 para ponto 0, 1 para negativo e 2 para positivo
	int sinalX = 0, sinalY = 0;
	//verificando o sinal das coordenadas do ponto passado por par�metro
	if(ponto.x > 0){
		sinalX = 2;
	}else if(ponto.x < 0){
		sinalX = 1;
	}
	if(ponto.y > 0){
		sinalY = 2;
	}else if(ponto.y < 0){
		sinalY = 1;
	}
	
	//verificando em qual quadrante est� o ponto, de acordo com a verifica��o de sinal feita anteriormente
	if(sinalX == 2 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) � do 1� quadrante!\n\n", ponto.x, ponto.y);
		return 1;
	}else if(sinalX == 1 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) � do 2� quadrante!\n\n", ponto.x, ponto.y);
		return 2;
	}else if(sinalX == 1 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) � do 3� quadrante!\n\n", ponto.x, ponto.y);
		return 3;
	}else if(sinalX == 2 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) � do 4� quadrante!\n\n", ponto.x, ponto.y);
		return 4;
	}else if(sinalX == 0 && sinalY == 0){
		printf("\n O ponto(%.2f,%.2f) � a origem do quadrante!\n\n", ponto.x, ponto.y);
	}else{
		if(sinalX == 0){
			if(sinalY == 2){
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 1 e 2!\n\n", ponto.x, ponto.y);
				return 5;
			}else{
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 3 e 4!\n\n", ponto.x, ponto.y);
				return 6;
			}
		}
		if(sinalY == 0){
			if(sinalX == 2){
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 1 e 4!\n\n", ponto.x, ponto.y);
				return 7;
			}else{
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 2 e 3!\n\n", ponto.x, ponto.y);
				return 8;
			}
		}
	}
}

//fun��o para verificar se um ponto passado por par�metro est� em um determinado quadrante tamb�m passado por par�metro
int verificaSeEstaNoQuadrante(pontoPlanoCartesiano ponto, int quadranteParam){
	
	int quadrante = quadranteParam;
	//0 para ponto 0, 1 para negativo e 2 para positivo
	int sinalX = 0, sinalY = 0;

	//1 para quadrante 1, 2 para quadrante 2, 3 para quadrante 3 e 4 para quadrante 4
	int quadranteAnalisado = 0;
	
	//1 para quadrante 1, 2 para quadrante 2, 3 para quadrante 3 e 4 para quadrante 4
	int quadranteAnalisado1 = 0;
	
	//1 para quadrante 1, 2 para quadrante 2, 3 para quadrante 3 e 4 para quadrante 4
	int quadranteAnalisado2 = 0;
	
	//verificando o sinal das coordenadas do ponto passado por par�metro
	if(ponto.x > 0){
		sinalX = 2;
	}else if(ponto.x < 0){
		sinalX = 1;
	}
	if(ponto.y > 0){
		sinalY = 2;
	}else if(ponto.y < 0){
		sinalY = 1;
	}
	
	//verificando se est� no quadrante escolhido
	/*OBS.: resolvi j� mostrar o resultado por aqui mesmo e n�o somente retornar o valor, 
	pois na parte do main ficaria muita coisa, ou eu teria que criar uma fun��o s� para mostrar os resultados, 
	o que acredito que nessa situ��o n�o seria necess�rio*/
	if(sinalX == 2 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) � do 1� quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 1;
		if(quadranteAnalisado == quadrante){
			printf("\n Est� no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n N�o est� no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 1 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) � do 2� quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 2;
		if(quadranteAnalisado == quadrante){
			printf("\n Est� no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n N�o est� no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 1 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) � do 3� quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 3;
		if(quadranteAnalisado == quadrante){
			printf("\n Est� no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n N�o est� no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 2 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) � do 4� quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 4;
		if(quadranteAnalisado == quadrante){
			printf("\n Est� no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n N�o est� no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 0 && sinalY == 0){
		printf("\n O ponto(%.2f,%.2f) � a origem do quadrante!\n\n", ponto.x, ponto.y);
	}else{
		if(sinalX == 0){
			if(sinalY == 2){
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 1 e 2!\n\n", ponto.x, ponto.y);
				printf("\n Est� no quadrante que escolheu para verificar, o %f� quadrante.\n\n", quadrante);
			}else{
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 3 e 4!\n\n", ponto.x, ponto.y);
				printf("\n Est� no quadrante que escolheu para verificar, o %f� quadrante.\n\n", quadrante);
			}
		}
		if(sinalY == 0){
			if(sinalX == 2){
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 1 e 2!\n\n", ponto.x, ponto.y);
				printf("\n Est� no quadrante que escolheu para verificar, o %f� quadrante.\n\n", quadrante);
			}else{
				printf("\n O ponto(%.2f,%.2f) est� nos quadrantes 3 e 4!", ponto.x, ponto.y);
				printf("\n Est� no quadrante que escolheu para verificar, o %f� quadrante.\n\n", quadrante);
			}
		}
	}
}

//fun��o para alterar valor de um ponto
pontoPlanoCartesiano alterarValorPonto(pontoPlanoCartesiano pontoParam){
	
	//criando um ponto para receber o ponto passado por par�metro, e ocorrer as altera��es
	pontoPlanoCartesiano novoPonto = pontoParam; 
	
	//pedindo os valores de coordenada para alter��o
	printf("\nDigite a coordenada que deseja alterar para X: \n");
	scanf("%f", &novoPonto.x);
	printf("\nDigite a coordenada que deseja alterar para Y: \n");
	scanf("%f", &novoPonto.y);
	//printando o novo ponto na tela do usu�rio 
	printf("\nO novo ponto � (%.2f,%.2f). \n\n", novoPonto.x, novoPonto.y);
	//retornando o ponto alterado
	return novoPonto;
	
}

//fun��o para calcular a dist�ncia entre dois pontos (passados por par�metro)
float distanciaPontos(pontoPlanoCartesiano a, pontoPlanoCartesiano b){
	float distancia;
	distancia = ((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y));
	distancia = sqrtf((pow((b.x - a.x),2)) + (pow((b.y - a.y),2)));
	//retornando a dist�ncia
	return distancia;
};

//fun��o para ver a maior coordenada de um ponto passado por par�metro
float maiorCoordPonto(pontoPlanoCartesiano pontoParam){
	//verificando se o valor de x � maior que o de y
	if (pontoParam.x > pontoParam.y){
		//se sim, retorna o valor de x
		return pontoParam.x;
	}else{
		//se n�o, retorna o valor de y
		return pontoParam.y;
	}
	
}

//fun��o para o menu inicial para que ele posso ser resumido e chamado a qualquer momento
int menuInicial(){
	int opcMenuInicial = 0;
	//mostrando as op��es para o usu�rio enquanto ele n�o digitar uma op��o v�lida
	do{
		printf("(1) Inicializar o ponto passando par�metros\n");
		printf("(2) Inicializa��o o ponto fazendo a leitura dentro da fun��o\n");
		printf("(3) Analisar qual o quadrante um ponto se encontra\n");
		printf("(4) Verificar se um determinado ponto est� em um determinado quadrante\n");
		printf("(5) Alterar os valores de um determinado ponto\n");
		printf("(6) Retornar qual a dist�ncia entre dois pontos\n");
		printf("(7) Retornar o maior valor de coordenada de um ponto\n");
		printf("(8) Sair\n\n");
		scanf("%i", &opcMenuInicial);	
		fflush(stdin);
		system("cls");
		
	}while(opcMenuInicial < 1 && opcMenuInicial > 8);
	//retornando a op��o escolhida
	return opcMenuInicial;
}

int main(){
	//definindo a linguagem para pt-br para que os caracteres sejam lidos corretamente
	setlocale(LC_ALL, "Portuguese");
	//definindo a cor do prompt s� por mudar mesmo, rs
	system("color 70");
	//criando o ponto padr�o para ser utilizado durante as chamadas das fun��es
	pontoPlanoCartesiano ponto;
	//setando as coordenadas do ponto para zero
	ponto.x = 0;
	ponto.y = 0;
	//vari�veis para verificar op�� escolhida pelo usu�rio no menu
	int opcMenuInicial = 0, quadranteAVerificar = 0; 
	//vari�veis para serem utilizadas junto com as fun��es
	float maiorValorCoord = 0;
	float pontoXUsu = 0, pontoYUsu = 0;
	char respostaConfirmacao = 'n';
	//pontos criados para c�lculo de dist�ncia
	pontoPlanoCartesiano num1; 
	pontoPlanoCartesiano num2;
	
	printf("\n	Bem vindo ao analisador de pontos. Como deseja prosseguir? (digite a op��o)\n\n");
	//repetindo o menu at� que o usu�rio queira sair (na op��o 8)
	do{
		opcMenuInicial = 0;
		//chamando a fun��o do menu
		opcMenuInicial = menuInicial();
		//verificando as op��es do menu
		switch(opcMenuInicial){
			case 1:
				//pedindo as coordenadas do ponto ao usu�rio
				printf("Digite a coordenada X: \n");
				scanf("%f", &pontoXUsu);
				fflush(stdin);
				printf("Digite a coordenada Y: \n");
				scanf("%f", &pontoYUsu);
				fflush(stdin);
				//inicializando a vari�vel, passando as coordenadas escolhidas
				ponto = inicializandoPPam(pontoXUsu, pontoYUsu);
				//printando o ponto escolhido na tela do usu�rio
				printf("\nO ponto escolhido foi: (%.2f;%.2f)\n\n", ponto.x, ponto.y);	
				opcMenuInicial = 0;
				break;
				
			case 2:
				//utilizando a fun��o de inicializar por par�metro
				ponto = inicializandoPFuncao();
				//printando o ponto escolhido na tela do usu�rio
				printf("\nO pontos escolhido foi: (%.2f;%.2f)\n\n", ponto.x, ponto.y);
				opcMenuInicial = 0;
				break;
				
			case 3:
				//inicializando um novo ponto, utilizando a fun��o de inicializar por par�metro
				ponto = inicializandoPFuncao();
				//verificando qual quadrante est� o ponto escolhido
				verificaQuadrante(ponto);
				opcMenuInicial = 0;
				break;
				
			case 4:
				//inicializando um novo ponto
				ponto = inicializandoPFuncao();
				//pedindo o quadrante que o usu�rio deseja verificar
				do{
					printf("Digite o quadrante que deseja verificar (1, 2, 3 ou 4): \n");
					scanf("%i", &quadranteAVerificar);
				}while(quadranteAVerificar < 1 || quadranteAVerificar > 4);
				/*utilizando a fun��o de verificar se est� no quadrante, 
				passando o ponto e o quadrante escolhido pelo usu�rio*/
				verificaSeEstaNoQuadrante(ponto, quadranteAVerificar);
				opcMenuInicial = 0;
				break;
			
			case 5:
				//inicializando um ponto
				ponto = inicializandoPFuncao();
				//chamando a fun��o de alterar valor das coordendas do ponto
				ponto = alterarValorPonto(ponto);
				opcMenuInicial = 0;
				break;
				
			case 6:
				//pedindo as coordenadas dos dois ponto ao usu�rio
				printf("Digite o x do ponto 1: ");
				scanf("%f", &num1.x);
				fflush(stdin);
				printf("Digite o y do ponto 1: ");
				scanf("%f", &num1.y);
				fflush(stdin);
				
				printf("\nDigite o x do ponto 2: ");
				scanf("%f", &num2.x);
				fflush(stdin);
				printf("Digite o y do ponto 2: ");
				scanf("%f", &num2.y);
				fflush(stdin);
				
				//printando os pontos escolhidos pelo usu�rio
				printf("\nAs coordenadas do ponto 1, no plano cartesiano s�o: (%.1f,%.1f)", num1.x, num1.y);
				printf("\nAs coordenadas do ponto 2, no plano cartesiano s�o: (%.1f,%.1f)", num2.x, num2.y);
				
				//calculando a dist�ncia entre os dois pontos escolhidos, utilizando a fun��o e passando os pontos por par�metro
				printf("\nA dist�ncia entre os dois pontos �: %.2f", distanciaPontos(num1, num2));
				printf("\n\n");
				opcMenuInicial = 0;
				break;
			
			case 7:
				//inicializando um ponto	
				ponto = inicializandoPFuncao();
				//utilizando a fun��o de verificar o maior valor de coordenada do ponto
				maiorValorCoord = maiorCoordPonto(ponto);
				printf("\n Do ponto: (%.2f;%.2f), o maior valor de coordenada � o: %.2f \n\n", ponto.x, ponto.y, maiorValorCoord);	
				opcMenuInicial = 0;
				break;
				
			case 8:
				//verificando com o usu�rio se ele realmente deseja sair do programa
				printf("Deseja realmente fazer isso? (s/n): \n");
				scanf("%s", &respostaConfirmacao);
				fflush(stdin);
				if(respostaConfirmacao == 's' || respostaConfirmacao == 'S'){
					system("exit");
				}else {
					opcMenuInicial = 0;
					break;
				}
		};
	}while(opcMenuInicial != 8);
	
	//retornando o inteiro pedido pela fun��o main do tipo int
	return 0;
}
