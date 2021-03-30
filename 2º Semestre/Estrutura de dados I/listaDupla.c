#include <stdio.h>
#include <stdlib.h>



typedef struct produto{
	int codigo;
	char nome[20];
	float preco;
	
}tpProduto;  


typedef struct _nodo{
	tpProduto info;
	struct _nodo *next;
	struct _nodo *prev;
	
}tpNodo;


typedef struct _lista{			
		int nItens;
		tpNodo *frist;
		tpNodo *last;

}tplista;

tplista *insere(tplista *u){
	
		tpNodo *N = (tpNodo *)malloc(sizeof(tpNodo));
			printf("Codigo: ");
			scanf("%d", &(N->info.codigo));
			printf("Nome: ");
			scanf("%s", (N->info.nome));
			printf("Preço: ");
			scanf("%f", &(N->info.preco));
		if(u->nItens == 0){
			u->frist = N;
			u->last=N;
			u->nItens++;
		}else{
			
		u->frist->prev = N; //cria um novo nodo que recebe N//
		N->next = u->frist;  //vai para a esquerda com o nodo//
		N->prev = NULL; //o prev atual recebe null
		N = u->frist;  //Atualiza o Nodo  atual recebe frist//
}
return u; 
}	
tplista*  excluir(tplista *u, int codigo,tpNodo *v){
	tpNodo *aux;
	if(u->nItens == 0){
			printf("A lista esta vazia\n");
			return NULL;
}

for(v = u->frist  ; v != NULL  ; v = v->next)
	if(v->info.codigo == codigo){
		if(v == u->frist){ //caso for o primeiro
			aux = u->frist;
			u->frist = u->frist->next;
			aux->prev = NULL;
			(u->nItens)--;
			}
	else if(v == u->last){//caso for o ultimo
			aux = u->last;
			u->last = u->last->prev;
			u->last->next = NULL;
			(u->nItens)--;
		}else{
		v->next->prev = v->prev;
		v->prev->next = v->next;
		(u->nItens)--;		
		
		}
	printf("Produto excluido\n");	

	}
	free(u);
return u;
}
	
void printar(tplista *lista){
	tpNodo* v;
	
	for(v = lista->frist  ; v != NULL  ; v = v->next){
		printf("CODIGO: %d\n", lista->frist->info.codigo);
		printf("Nome: %s\n", lista->frist->info.nome);
		printf("Preço: %.2f\n", lista->frist->info.preco);
		printf("\n                              \n");
		}
	
	}	

	
int main(){

int codigo;	
int op;
tpNodo *v;

tplista *lista = (tplista *)malloc(sizeof(lista));
lista->frist = NULL;
lista->last = NULL;
lista->nItens = 0;
	
do{	
	

		printf("(1) Para inserir um produto na lista\n");
		printf("(2) Para excluir um elemento da listaz\n");
		printf("(3) Para listar todos os campos dos elementos da lista\n");
		printf("(0) Para finalizar o programa\n");
		scanf("%d", &op);
	
	
switch(op){
	
	case 1:
	
	lista = insere(lista);
	break; 
		
	case 2:
	printf("Digite o código do produto que deseja remover: ");
	scanf("%d", &codigo);
	lista = excluir(lista, codigo, v);
	
	break;
	
	case 3: 
	printar(lista);
	
	
	break;
	
	}
}while(op != 0);



return 0; }

