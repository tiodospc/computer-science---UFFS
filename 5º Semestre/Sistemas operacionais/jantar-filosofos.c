#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


//Numero de filosofos
#define N 5
#define RIGHT(i) (i + 4) % N
#define LEFT(i) (i + 1) % N

typedef enum {
    THIKING, 
    HUNGRY,
    EATING
} estado_filosofo;

estado_filosofo estados[N];
pthread_mutex_t garfos[N];

void thinking(int i){
    estados[i] = THIKING;
    printf("Filosofo %d está pensando...\n", i);
}

void getForkRight(int i){
    pthread_mutex_lock(&garfos[RIGHT(i)]);
    estados[i] = HUNGRY;
}
void getForkLeft(int i){
    pthread_mutex_lock(&garfos[LEFT(i)]);
}

void eat(int i){
    estados[i] = EATING;
	printf("Filósofo %d está comendo\n",i);
}


void returnForkRight(int i){
    pthread_mutex_unlock(&garfos[RIGHT(i)]);
}

void returnForkLeft(int i){
    pthread_mutex_unlock(&garfos[LEFT(i)]);
	estados[i] = THIKING;	
}

//filosofos ações
void *filosofo(void *num){
    int i = atoi(num);
    thinking(i);
    getForkLeft(i);
    printf("Filósofo %d está com fome\n", i);
    getForkRight(i);
    eat(i);
    returnForkRight(i);
    returnForkLeft(i);
    printf("Filósofo %d terminou de comer\n", i);
    pthread_exit(NULL);
}

void *outroFilosofo(void *num){
    int i = atoi(num);
    thinking(i);
    getForkLeft(i);
    printf("Filósofo %d está com fome\n", i);
    getForkRight(i);
    eat(i);
    returnForkRight(i);
    returnForkLeft(i);
    printf("Filósofo %d terminou de comer\n", i);
    pthread_exit(NULL);
};

int main(void){	
    pthread_t filosofos[N];
          
    for(int i = 0; i < N; i++){
        pthread_mutex_init(&garfos[i], NULL);
    }

    for (int i = 0; i < N; i++){
        if(i == (N -1)){
			pthread_create(&filosofos[i], NULL, outroFilosofo, (void *) &i);
        } else {
            pthread_create(&filosofos[i], NULL, filosofo, (void *) &i);
        }
    }
    
    for(int i = 0; i < N; i++){
        pthread_join(filosofos[i], NULL);
    }

    pthread_exit(NULL);
    return 0;
}
