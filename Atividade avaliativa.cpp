#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//alterar para 30
char cidades[30][40] = { 
"Astorga",
"Abadiania",
"Abaete",
"Abaetetuba",
"Abaiara", 
"Abaira", 
"Abare",
"Blumenau",
"Babaculandia",
"Bacabal",
"Bacabeira",
"Bacuri",
"Bacurituba", 
"Baependi",
"Curitiba ",
"Cianorte",
"Caibate",
"Caicara",
"Camaqua",
"Cacequi",
"Cachoeira do Sul",
"Cachoeirinha",
"Sinop",
"Santos",
"Sabino",
"Sagres",
"Sales",
"Sales Oliveira",
"Salesopolis",
"Salmourão"  
};

typedef struct tipoElemento
{
	char nomeCidade[50];
	struct tipoElemento *proximo;
}TElemento;

typedef struct tipoLista
{
	TElemento *inicio;
	TElemento *fim;
}TLista;

TLista tabelaHashing[15];

void inicializar()
{
	int i;
	for(i = 0; i < 15; i++)
	{
		tabelaHashing[i].inicio = NULL;
		tabelaHashing[i].fim = NULL;
	}
}

int hash(int soma)
{
	return soma % 15;
}

void executar()
{
	int infoNumero, i, x;
	printf("Informe quantidade de letras que sera utilizada para o calculo do Hashing: ");
	scanf("%d", &infoNumero);
	
	for(x = 0; x < 30; x++)// passando pelas cidades cadastradas. 30 = quantidade de cidades
	{
		int soma = 0;
		
		for(i = 0; i < infoNumero && cidades[x][1] != '\0'; i++)
		{
			soma = soma + cidades[x][i]; // armazenando o valor asc do nome da cidade
		}
		
		int indice = hash(soma);
		
		TElemento *novaCidade;
		novaCidade = new TElemento;
		strcpy (novaCidade->nomeCidade, cidades[x]);
		novaCidade->proximo = NULL;
		
		if (tabelaHashing[indice].inicio == NULL)
		{
			tabelaHashing[indice].inicio = novaCidade;
			tabelaHashing[indice].fim = novaCidade;
		}
		else
		{
			tabelaHashing[indice].fim->proximo = novaCidade;
			tabelaHashing[indice].fim = novaCidade;
		}	
	}
	
}
void apresentar ()
{
	int i;
	
	for (i = 0; i < 15; i++) //para percorrer a tabela hashing
	{
		TElemento *aux;
		aux = tabelaHashing[i].inicio;
		if (aux != NULL)
		{
			printf("\n Indice: %d - ", i);
			while (aux != NULL) //para percorrer as listas encadeadas
			{
				printf("%s | ", aux->nomeCidade);
				aux = aux->proximo;
			}
		}
		else
		{
			printf("\n Indice: %d - / ", i);
		}
	}
}
int main()
{
	TLista *nome;
	int opcao;
	inicializar();
	
	do{
	
		printf("\n----------MENU----------");
		printf("\n 1- Executar Hash");
		printf("\n 2- Apresentar tabela Hashing");
		printf("\n 0- Sair");
		printf("\n Informe uma opcao: ");
		scanf("%d", &opcao);
	
		switch(opcao)
		{
			case 1:
				executar();
				break;
			case 2:
				apresentar();
				break;
		}
	
	}while(opcao != 0);
	
}

