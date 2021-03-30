//busca biraria 

#include <stdio.h>
#include <stdlib.h>

int busca(int vetor[], int ini, int fim, int pesq){ 
	//função recusiva 
    int meio=(ini+fim)/2;
    if (ini > fim) {
        printf("NAO ENCONTREI\n");
        return -1; 
    }
    if(vetor[meio]== pesq){ //se o elemento estiver no meio do vetor
        return meio;
    }else if(vetor[meio]<pesq){
		//vai para direta 
        return busca(vetor, meio + 1,fim, pesq);
    }else{
		//vai para esquerda 
        return busca(vetor, ini, meio - 1, pesq);
    }
}

void selecao(int vetor[]){ 

    int Menor, aux, i, j;

    for(i=0; i<10 - 1; i++){
        Menor=i;
        for(j=i+1 ;j<10; j++){
            if(vetor[Menor] > vetor[j])
                Menor=j;
        }
        if(i!=Menor){
            aux=vetor[i];
            vetor[i]=vetor[Menor];
            vetor[Menor]=aux;
        }
    }
}

int main(){
    int x, vetor_ts[10], i,fun; 

    printf("Digite 10 elementos para preencher o vetor?\n");
    for(i=0;i<10;i++){
        printf("elemento %d \n", i+1);
        scanf("%d", &vetor_ts[i]);
    }

    selecao(vetor_ts);

    printf("Vetor ordenado: ");
    for(i=0;i<10;i++){
        printf(" %d - ",vetor_ts[i]);
    }
    printf("\n");
    printf("Digite o elemento que deseja buscar: \n");
    scanf("%d", &x);
    fun = busca(vetor_ts,0,9,x);
    printf("Esse elemento encontra-se na posição - %d do vetor", fun);
    return 0;
}
