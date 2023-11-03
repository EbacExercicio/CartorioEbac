#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o e espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios do sistema. Os par�nteses denominam uma fun��o.
{
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se � string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever.
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" � para atualizar a informa��o e n�o criar um novo arquivo.
	fprintf(file,","); // Salvar informa��o no arquivo. "," serve pra separar.
	fclose(file); // Fechar o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); //armazenar valor dentro da string, na vari�vel nome.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" � para atualizar a informa��o e n�o criar um novo arquivo.
	fprintf(file,nome); //salva o nome no arquivo.
	fclose(file); // Fechar arquivo.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" � para atualizar a informa��o e n�o criar um novo arquivo.
	fprintf(file,","); // Salvar informa��o no arquivo. "," serve pra separar.
	fclose(file); // Fechar o arquivo.
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",sobrenome); // Salvar valor dentro da string, na vari�vel sobrenome.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" � para atualizar a informa��o e n�o criar um novo arquivo.
	fprintf(file,sobrenome); // Salva o sobrenome no arquivo.
	fclose(file); // Fechar o arquivo.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" � para atualizar a informa��o e n�o criar um novo arquivo.
	fprintf(file,","); // Salvar informa��o no arquivo. "," serve pra separar.
	fclose(file); // Fechar o arquivo.
	
	printf("Digite o cargo a ser cadastrado: "); //coletar informa��o do usu�rio.
	scanf("%s",cargo); // salvar dentro na string, na vari�vel cargo.
	
	file = fopen(arquivo, "a"); //Abrir um arquivo. "a" � para atualizar a informa��o e n�o criar um novo arquivo.
	fprintf(file,cargo); // salva o cargo no arquivo.
	fclose(file); // Fecha o arquivo.
	
	system("pause"); // Faz a mensagem aparecer para o usu�rio at� que ele n�o a deseje mais.
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // arquivo para consultar. N�mero � o tamanho.
	char conteudo[200]; //Conte�do do arquivo. N�mero � o tamanho.
	
	printf("Digite cpf a ser consultado: "); // Coletar informa��o do usus�rio.
	scanf("%s",cpf); // Salvando na string, na vari�vel "cpf"
	
	FILE *file; // Consultar arquivo.
	file = fopen(cpf,"r"); // Abrir arquivo. "r" serve para ler.
	
	if(file == NULL) //Valida��o para caso nulo.
	{
		printf("N�o foi poss�vel abrir o arquivo, arquivo n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //La�o de repeti��o at� acabarem as letras. "fgets" quer dizer "indo buscar."
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Comunica��o com o usus�rio.
		printf("%s", conteudo); //Salvar conte�do que est� dentro da string.
		printf("\n\n"); // Pular linhas.
	}
	
	system("pause"); // Faz a mensagem aparecer para o usu�rio at� que ele n�o a deseje mais.
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digitar o CPF do usus�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema!.\n");
		system("pause"); // Faz a mensagem aparecer para o usu�rio at� que ele n�o a deseje mais.
	}
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1; // Vari�vel a ser repetida
	
	for(laco=1;laco=1;) // Fun��o de repeti��o
	{
	
	    system("cls"); // Respons�vel por limpar a tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("###Cart�rio da EBAC###\n\n"); //In�cio do Menu
	    printf("Escolha a Op��o Desejada do Menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: ");//Fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usus�rio
	
	    system("cls"); // Respons�vel por limpar a tela
	    
	    
	    switch(opcao) //In�cio da sele��o do Menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
		    break; // "breaks" encerram uma fun��o enviando de volta para o in�cio.
		    
		    case 2:
		    consulta();
		    break;
		    
		    case 3:
		    deletar();
		    break;
		    
		    default: //Quando o usu�rio digita algo fora do padr�o ou n�o mapeada.
		    printf("Esta op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break; //Fim da Sele��o
		    	
		}
	    
	
    }
}


