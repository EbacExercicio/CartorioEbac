#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação e espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários do sistema. Os parênteses denominam uma função.
{
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se à string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever.
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" é para atualizar a informação e não criar um novo arquivo.
	fprintf(file,","); // Salvar informação no arquivo. "," serve pra separar.
	fclose(file); // Fechar o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); //armazenar valor dentro da string, na variável nome.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" é para atualizar a informação e não criar um novo arquivo.
	fprintf(file,nome); //salva o nome no arquivo.
	fclose(file); // Fechar arquivo.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" é para atualizar a informação e não criar um novo arquivo.
	fprintf(file,","); // Salvar informação no arquivo. "," serve pra separar.
	fclose(file); // Fechar o arquivo.
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome); // Salvar valor dentro da string, na variável sobrenome.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" é para atualizar a informação e não criar um novo arquivo.
	fprintf(file,sobrenome); // Salva o sobrenome no arquivo.
	fclose(file); // Fechar o arquivo.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" é para atualizar a informação e não criar um novo arquivo.
	fprintf(file,","); // Salvar informação no arquivo. "," serve pra separar.
	fclose(file); // Fechar o arquivo.
	
	printf("Digite o cargo a ser cadastrado: "); //coletar informação do usuário.
	scanf("%s",cargo); // salvar dentro na string, na variável cargo.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" é para atualizar a informação e não criar um novo arquivo.
	fprintf(file,cargo); // salva o cargo no arquivo.
	fclose(file); // Fecha o arquivo.
	
	system("pause"); // Faz a mensagem aparecer para o usuário até que ele não a deseje mais.
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // arquivo para consultar. Número é o tamanho.
	char conteudo[200]; //Conteúdo do arquivo. Número é o tamanho.
	
	printf("Digite cpf a ser consultado: "); // Coletar informação do ususário.
	scanf("%s",cpf); // Salvando na string, na variável "cpf"
	
	FILE *file; // Consultar arquivo.
	file = fopen(cpf,"r"); // Abrir arquivo. "r" serve para ler.
	
	if(file == NULL) //Validação para caso nulo.
	{
		printf("Não foi possível abrir o arquivo, arquivo não localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Laço de repetição até acabarem as letras. "fgets" quer dizer "indo buscar."
	{
		printf("\nEssas são as informações do usuário: "); //Comunicação com o ususário.
		printf("%s", conteudo); //Salvar conteúdo que está dentro da string.
		printf("\n\n"); // Pular linhas.
	}
	
	system("pause"); // Faz a mensagem aparecer para o usuário até que ele não a deseje mais.
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digitar o CPF do ususário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usuário não se encontra no sistema!.\n");
		system("pause"); // Faz a mensagem aparecer para o usuário até que ele não a deseje mais.
	}
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1; // Variável a ser repetida
	
	for(laco=1;laco=1;) // Função de repetição
	{
	
	    system("cls"); // Responsável por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cartório da EBAC###\n\n"); //Início do Menu
	    printf("Escolha a Opção Desejada do Menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: ");//Fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do ususário
	
	    system("cls"); // Responsável por limpar a tela
	    
	    
	    switch(opcao) //Início da seleção do Menu
	    {
	    	case 1:
	    	registro(); //chamada de funções
		    break; // "breaks" encerram uma função enviando de volta para o início.
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default: //Quando o usuário digita algo fora do padrão ou não mapeada.
		    printf("Esta opção não está disponível!\n");
		    system("pause");
		    break; //Fim da Seleção
		    	
		}
	    
	
    }
}


