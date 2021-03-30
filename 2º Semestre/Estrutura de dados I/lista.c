#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 100


typedef struct produto{
int codigo;
char nome[TAM];
float preco;
}tp_produto;		



typedef struct nodo{
tp_produto produto;
struct nodo *prox;
}tp_nodo;



tp_nodo *inserir(tp_nodo *u){ //insere elementos na lista e a variavel U aponta para o tp nodo//

	tp_nodo *N = (tp_nodo *)malloc(sizeof(tp_nodo));
	printf("Digite as informaçoes a seguir\n");
	printf("Codigo: ");
	scanf("%d", &(N->produto.codigo));		
	printf("Nome: ");
	scanf("%s", (N->produto.nome));
	printf("Preço: ");
	scanf("%f", &(N->produto.preco));
	N->prox = u;
	return N;
}

void display(tp_nodo *u){ //for que per-corre a lista e printa na tela os produtoos 
	tp_nodo *v;
	for(v=u; v != NULL ; v = v->prox){
		printf("CODIGO: %d\n", v->produto.codigo);
		printf("Nome: %s\n", v->produto.nome);
		printf("Preço: %.2f\n", v->produto.preco);
		printf("\n                              \n");
		}
	
	} 
	
tp_nodo*  excluir(tp_nodo *u, int codigo){
tp_nodo* atual = u; //variavel que recebe a lista	
	if(atual == NULL){//verificar se a lista ta vazia se estiver vai parar 
			printf("A lista esta vazia\n");
		return NULL;
	}
	if(atual->produto.codigo == codigo){ //se a variavel atual for igual codigo do produto
		u = atual->prox;
		free(atual); 
	}
	while(atual->prox != NULL){ //se tem produtos com o mesmo codigo
		if(atual->prox->produto.codigo == codigo){//
		tp_nodo* TenhoQueRemover = atual->prox;	
		atual->prox = atual->prox->prox;
		free(TenhoQueRemover);
		}
		atual = atual->prox;
	}
			
	return u;
	
}


int main(){
int codigo;
int op;
	
	tp_nodo *u = NULL;
	
do{	
	
		printf("\n                                   \n");
		printf("(1) Para inserir um produto na lista\n");
		printf("(2) Para excluir um elemento da listaz\n");
		printf("(3) Para listar todos os campos dos elementos da lista\n");
		printf("(0) Para finalizar o programa\n");
		scanf("%d", &op);
		system("clear");
	
switch(op){
	
	case 1:
		u = inserir(u);
		break;
		
		
	case 2:
	printf("Digite o código do produto que deseja remover: ");
	scanf("%d", &codigo);
	u = excluir(u, codigo);
	break;
	
	case 3:
	display(u);
	break;
	
	}
}while(op != 0);

	
	return 0; 
	}
