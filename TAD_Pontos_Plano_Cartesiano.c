#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
//Aluno: Pedro Sousa
//Atividade de Algoritmos e Estrutura de Dados II
//curso de Engenharia da Computação - UEMG

//Definindo a estrutura para agrupar as variáveis
typedef struct pontoPlanoCartesiano{
	//criando variáveis
	float x;
	float y;
}pontoPlanoCartesiano;

//Inicializando por parâmetro
pontoPlanoCartesiano inicializandoPPam(float x, float y){
	//criando um ponto (do tipo da estrutura já definida anteriormente) para maniupalação
	pontoPlanoCartesiano pontoFuncao;
	//recebendo as coordenadas passadas por parâmetro
	pontoFuncao.x = x;
	pontoFuncao.y = y;
	//retornando o ponto inicializado
	return pontoFuncao;
}

//Função para inicializar um ponto dentro dela e retornar o ponto
pontoPlanoCartesiano inicializandoPFuncao(){
	//criando um ponto para manipulação
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

// Verifica o quadrante do ponto passado por parâmetro
int verificaQuadrante(pontoPlanoCartesiano pontoParam){
	
	pontoPlanoCartesiano ponto = pontoParam;
	//variáveis para verificar o sinal, sendo: 0 para ponto 0, 1 para negativo e 2 para positivo
	int sinalX = 0, sinalY = 0;
	//verificando o sinal das coordenadas do ponto passado por parâmetro
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
	
	//verificando em qual quadrante está o ponto, de acordo com a verificação de sinal feita anteriormente
	if(sinalX == 2 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) é do 1° quadrante!\n\n", ponto.x, ponto.y);
		return 1;
	}else if(sinalX == 1 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) é do 2° quadrante!\n\n", ponto.x, ponto.y);
		return 2;
	}else if(sinalX == 1 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) é do 3° quadrante!\n\n", ponto.x, ponto.y);
		return 3;
	}else if(sinalX == 2 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) é do 4° quadrante!\n\n", ponto.x, ponto.y);
		return 4;
	}else if(sinalX == 0 && sinalY == 0){
		printf("\n O ponto(%.2f,%.2f) é a origem do quadrante!\n\n", ponto.x, ponto.y);
	}else{
		if(sinalX == 0){
			if(sinalY == 2){
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 1 e 2!\n\n", ponto.x, ponto.y);
				return 5;
			}else{
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 3 e 4!\n\n", ponto.x, ponto.y);
				return 6;
			}
		}
		if(sinalY == 0){
			if(sinalX == 2){
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 1 e 4!\n\n", ponto.x, ponto.y);
				return 7;
			}else{
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 2 e 3!\n\n", ponto.x, ponto.y);
				return 8;
			}
		}
	}
}

//função para verificar se um ponto passado por parâmetro está em um determinado quadrante também passado por parâmetro
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
	
	//verificando o sinal das coordenadas do ponto passado por parâmetro
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
	
	//verificando se está no quadrante escolhido
	/*OBS.: resolvi já mostrar o resultado por aqui mesmo e não somente retornar o valor, 
	pois na parte do main ficaria muita coisa, ou eu teria que criar uma função só para mostrar os resultados, 
	o que acredito que nessa situção não seria necessário*/
	if(sinalX == 2 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) é do 1° quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 1;
		if(quadranteAnalisado == quadrante){
			printf("\n Está no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n Não está no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 1 && sinalY == 2){
		printf("\n O ponto(%.2f,%.2f) é do 2° quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 2;
		if(quadranteAnalisado == quadrante){
			printf("\n Está no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n Não está no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 1 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) é do 3° quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 3;
		if(quadranteAnalisado == quadrante){
			printf("\n Está no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n Não está no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 2 && sinalY == 1){
		printf("\n O ponto(%.2f,%.2f) é do 4° quadrante!\n\n", ponto.x, ponto.y);
		quadranteAnalisado = 4;
		if(quadranteAnalisado == quadrante){
			printf("\n Está no quadrante que escolheu para verificar.\n\n");
			return 1;
		}else{
			printf("\n Não está no quadrante que escolheu para verificar.\n\n");
			return 0;
		}
	}else if(sinalX == 0 && sinalY == 0){
		printf("\n O ponto(%.2f,%.2f) é a origem do quadrante!\n\n", ponto.x, ponto.y);
	}else{
		if(sinalX == 0){
			if(sinalY == 2){
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 1 e 2!\n\n", ponto.x, ponto.y);
				printf("\n Está no quadrante que escolheu para verificar, o %f° quadrante.\n\n", quadrante);
			}else{
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 3 e 4!\n\n", ponto.x, ponto.y);
				printf("\n Está no quadrante que escolheu para verificar, o %f° quadrante.\n\n", quadrante);
			}
		}
		if(sinalY == 0){
			if(sinalX == 2){
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 1 e 2!\n\n", ponto.x, ponto.y);
				printf("\n Está no quadrante que escolheu para verificar, o %f° quadrante.\n\n", quadrante);
			}else{
				printf("\n O ponto(%.2f,%.2f) está nos quadrantes 3 e 4!", ponto.x, ponto.y);
				printf("\n Está no quadrante que escolheu para verificar, o %f° quadrante.\n\n", quadrante);
			}
		}
	}
}

//função para alterar valor de um ponto
pontoPlanoCartesiano alterarValorPonto(pontoPlanoCartesiano pontoParam){
	
	//criando um ponto para receber o ponto passado por parâmetro, e ocorrer as alterações
	pontoPlanoCartesiano novoPonto = pontoParam; 
	
	//pedindo os valores de coordenada para alterção
	printf("\nDigite a coordenada que deseja alterar para X: \n");
	scanf("%f", &novoPonto.x);
	printf("\nDigite a coordenada que deseja alterar para Y: \n");
	scanf("%f", &novoPonto.y);
	//printando o novo ponto na tela do usuário 
	printf("\nO novo ponto é (%.2f,%.2f). \n\n", novoPonto.x, novoPonto.y);
	//retornando o ponto alterado
	return novoPonto;
	
}

//função para calcular a distância entre dois pontos (passados por parâmetro)
float distanciaPontos(pontoPlanoCartesiano a, pontoPlanoCartesiano b){
	float distancia;
	distancia = ((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y));
	distancia = sqrtf((pow((b.x - a.x),2)) + (pow((b.y - a.y),2)));
	//retornando a distância
	return distancia;
};

//função para ver a maior coordenada de um ponto passado por parâmetro
float maiorCoordPonto(pontoPlanoCartesiano pontoParam){
	//verificando se o valor de x é maior que o de y
	if (pontoParam.x > pontoParam.y){
		//se sim, retorna o valor de x
		return pontoParam.x;
	}else{
		//se não, retorna o valor de y
		return pontoParam.y;
	}
	
}

//função para o menu inicial para que ele posso ser resumido e chamado a qualquer momento
int menuInicial(){
	int opcMenuInicial = 0;
	//mostrando as opções para o usuário enquanto ele não digitar uma opção válida
	do{
		printf("(1) Inicializar o ponto passando parâmetros\n");
		printf("(2) Inicialização o ponto fazendo a leitura dentro da função\n");
		printf("(3) Analisar qual o quadrante um ponto se encontra\n");
		printf("(4) Verificar se um determinado ponto está em um determinado quadrante\n");
		printf("(5) Alterar os valores de um determinado ponto\n");
		printf("(6) Retornar qual a distância entre dois pontos\n");
		printf("(7) Retornar o maior valor de coordenada de um ponto\n");
		printf("(8) Sair\n\n");
		scanf("%i", &opcMenuInicial);	
		fflush(stdin);
		system("cls");
		
	}while(opcMenuInicial < 1 && opcMenuInicial > 8);
	//retornando a opção escolhida
	return opcMenuInicial;
}

int main(){
	//definindo a linguagem para pt-br para que os caracteres sejam lidos corretamente
	setlocale(LC_ALL, "Portuguese");
	//definindo a cor do prompt só por mudar mesmo, rs
	system("color 70");
	//criando o ponto padrão para ser utilizado durante as chamadas das funções
	pontoPlanoCartesiano ponto;
	//setando as coordenadas do ponto para zero
	ponto.x = 0;
	ponto.y = 0;
	//variáveis para verificar opçõ escolhida pelo usuário no menu
	int opcMenuInicial = 0, quadranteAVerificar = 0; 
	//variáveis para serem utilizadas junto com as funções
	float maiorValorCoord = 0;
	float pontoXUsu = 0, pontoYUsu = 0;
	char respostaConfirmacao = 'n';
	//pontos criados para cálculo de distância
	pontoPlanoCartesiano num1; 
	pontoPlanoCartesiano num2;
	
	printf("\n	Bem vindo ao analisador de pontos. Como deseja prosseguir? (digite a opção)\n\n");
	//repetindo o menu até que o usuário queira sair (na opção 8)
	do{
		opcMenuInicial = 0;
		//chamando a função do menu
		opcMenuInicial = menuInicial();
		//verificando as opções do menu
		switch(opcMenuInicial){
			case 1:
				//pedindo as coordenadas do ponto ao usuário
				printf("Digite a coordenada X: \n");
				scanf("%f", &pontoXUsu);
				fflush(stdin);
				printf("Digite a coordenada Y: \n");
				scanf("%f", &pontoYUsu);
				fflush(stdin);
				//inicializando a variável, passando as coordenadas escolhidas
				ponto = inicializandoPPam(pontoXUsu, pontoYUsu);
				//printando o ponto escolhido na tela do usuário
				printf("\nO ponto escolhido foi: (%.2f;%.2f)\n\n", ponto.x, ponto.y);	
				opcMenuInicial = 0;
				break;
				
			case 2:
				//utilizando a função de inicializar por parâmetro
				ponto = inicializandoPFuncao();
				//printando o ponto escolhido na tela do usuário
				printf("\nO pontos escolhido foi: (%.2f;%.2f)\n\n", ponto.x, ponto.y);
				opcMenuInicial = 0;
				break;
				
			case 3:
				//inicializando um novo ponto, utilizando a função de inicializar por parâmetro
				ponto = inicializandoPFuncao();
				//verificando qual quadrante está o ponto escolhido
				verificaQuadrante(ponto);
				opcMenuInicial = 0;
				break;
				
			case 4:
				//inicializando um novo ponto
				ponto = inicializandoPFuncao();
				//pedindo o quadrante que o usuário deseja verificar
				do{
					printf("Digite o quadrante que deseja verificar (1, 2, 3 ou 4): \n");
					scanf("%i", &quadranteAVerificar);
				}while(quadranteAVerificar < 1 || quadranteAVerificar > 4);
				/*utilizando a função de verificar se está no quadrante, 
				passando o ponto e o quadrante escolhido pelo usuário*/
				verificaSeEstaNoQuadrante(ponto, quadranteAVerificar);
				opcMenuInicial = 0;
				break;
			
			case 5:
				//inicializando um ponto
				ponto = inicializandoPFuncao();
				//chamando a função de alterar valor das coordendas do ponto
				ponto = alterarValorPonto(ponto);
				opcMenuInicial = 0;
				break;
				
			case 6:
				//pedindo as coordenadas dos dois ponto ao usuário
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
				
				//printando os pontos escolhidos pelo usuário
				printf("\nAs coordenadas do ponto 1, no plano cartesiano são: (%.1f,%.1f)", num1.x, num1.y);
				printf("\nAs coordenadas do ponto 2, no plano cartesiano são: (%.1f,%.1f)", num2.x, num2.y);
				
				//calculando a distância entre os dois pontos escolhidos, utilizando a função e passando os pontos por parâmetro
				printf("\nA distância entre os dois pontos é: %.2f", distanciaPontos(num1, num2));
				printf("\n\n");
				opcMenuInicial = 0;
				break;
			
			case 7:
				//inicializando um ponto	
				ponto = inicializandoPFuncao();
				//utilizando a função de verificar o maior valor de coordenada do ponto
				maiorValorCoord = maiorCoordPonto(ponto);
				printf("\n Do ponto: (%.2f;%.2f), o maior valor de coordenada é o: %.2f \n\n", ponto.x, ponto.y, maiorValorCoord);	
				opcMenuInicial = 0;
				break;
				
			case 8:
				//verificando com o usuário se ele realmente deseja sair do programa
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
	
	//retornando o inteiro pedido pela função main do tipo int
	return 0;
}
