#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>
#define TAM 50

typedef struct _produto{
	int cod;
	char nome[TAM];
	float preco;
}tp_produto;

typedef struct _pilha{
	tp_produto *info;
	int topo;
}tp_pilha;

tp_pilha* inicia_pilha_vazia(tp_pilha *p_pilha){
	
	p_pilha = (tp_pilha *)malloc(sizeof(tp_pilha));
	p_pilha->topo = -1;
	return p_pilha;
}

void aloca_espaco_produtos(tp_pilha *p_pilha, int n){
	
	tp_produto *p_produto;
	tp_pilha *p_new;
	p_pilha->info = (tp_produto *)malloc(sizeof(tp_produto)*n);
}

void push(tp_pilha *p_pilha, int n){

	//cheia
	if(p_pilha->topo == n-1){
		printf("pilha cheia.\n");
	}else{
		p_pilha->topo++;
		printf("produtos:\n");
		printf("Nome:");
		fgets((p_pilha->info + p_pilha->topo)->nome,TAM,stdin);
		printf("Codigo:");
		scanf("%d", &(p_pilha->info + p_pilha->topo)->cod);
		printf("Preço:");
		scanf("%f", &(p_pilha->info + p_pilha->topo)->preco);
	}
}

void pop(tp_pilha *p_pilha, int n){
	//vazia
	if(p_pilha->topo == -1){
		printf("pilha vazia\n");
	}else{
		//cheia ou não vazia
		p_pilha->topo--;
	}
}

void telinha(tp_pilha *p_pilha, int n){
int i;
	for(i = 0; i <= p_pilha->topo; i++){
		printf("\nProduto:\n");
		printf("\nNome: %s\n", (p_pilha->info + i)->nome);
		printf("Código: %d\n", (p_pilha->info + i)->cod);
		printf("Preço: %.2f R$\n", (p_pilha->info + i)->preco);
	}
}

void free_all(tp_pilha *p_pilha){
	free(p_pilha->info);
	free(p_pilha);
}


int main(){

	
	tp_pilha *p_pilha;
	int qtd_produtos, op;
	
	p_pilha = inicia_pilha_vazia(p_pilha);

	printf("\nDigite quantos produtos:\n");
	scanf("%d", &qtd_produtos);
	getchar();



	aloca_espaco_produtos(p_pilha, qtd_produtos);
    
    
do{
    printf("\nMENU:");
	printf("\n1 - PUSH");
	printf("\n2 - POP");
	printf("\n3 - tela");
	printf("\n0 - EXIT\n");
	scanf("%d", &op);

switch(op){

case 1: 

	push(p_pilha, qtd_produtos);
    break;
    
case 2: 
    
    pop(p_pilha, qtd_produtos);
    break;
    
    
case 3:
        telinha(p_pilha, qtd_produtos);
        break;
}
}while(op != 0);
   
    
    

    
    


return 0; 
}




