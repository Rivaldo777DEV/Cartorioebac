#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//bibliotec responsavel por cuidar das string

int registro()// função responsavel por cadastrar os usuários no sistema
{
	//iniçio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	

	printf("Digite o cpf a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a string
	

	strcpy(arquivo, cpf);//responsavel por copiar os valores das string
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo "w"significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
    
    
	file = fopen(arquivo, "a");// abrir e atualizar os arquivos
	fprintf(file,",");
	fclose(file);//fechar arquivo


	printf("Digite o nome a ser cadastrado: ");//F
	scanf("%s",nome);//%s refere-se a string
	
	file = fopen(arquivo, "a");//F
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//F
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);//%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");// pausar
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, nâo localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);//%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
	    setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	    printf("###Cartório da EBAC###\n\n"); // Inicio do menu
    	printf("Escolha a opção desejada do menu:\n\n"); 
    	printf("\t1 - Registrar nomes\n"); 
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("opção:"); // fim do menu
	    scanf("%d", &opcao); // armazenando a escolha do úsuario
	
    	system("cls");// responsavel por limpar a tela
    	
    	switch(opcao)//inicio da seleção
    	{
    		case 1:
    		registro();//chamada de funçoes
    		break;
    		
    		case 2:
    		consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
		
		
    		default:
    		printf("essa opção está indisponivel!\n");
    		system("pause");
    		break;
		}
   }
}



