#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char dias[5][10] = {"segunda", "terça", "quarta", "quinta", "sexta"};

typedef struct{
    char matricula[9];
    char nomeCompleto[72];
    char cpf[11];
    float np1;
    float np2;
    float mediaFinal;
    char codTurma[6];
}ALUNOS;

typedef struct{
    char componenteCurricular[72];
    char codigo[6];
    char fase[30];
    char horarios[5][13];
    ALUNOS coleguinhas[30];
    int cotAlunos;
}TURMAS;

//gerar codigo da turma

void gerarcodigo(TURMAS *a){
    for(int i = 0; i < 3; i++) a->codigo[i] = a->componenteCurricular[i];
    srand(time(NULL));
    for(int i = 0; i < 3; i++) a->codigo[i + 3] = (rand() % 10) + 48;
 
}

void acadastroTurma(TURMAS *a, int indice){
	printf("Digite o componente corricular: ");
	scanf("%s", a[indice].componenteCurricular);
	printf("Digite a fase correspondente: ");
	scanf("%s", a[indice].fase);	
    for(int i = 0; i < 5; i++){
    printf("Dia: %s:", dias[i]);
    scanf("%s", a[indice].horarios[i]);
}   gerarcodigo(a);
    printf("O código da turma é: %s, por favor anote\n", a->codigo);
    a[indice].cotAlunos = 0;
}

void cadastroAluno(TURMAS *B, int indice){
	int sm, i, r, num;
    char dig10, dig11;
	printf("Digite o nome completo do aluno: ");
	scanf("%s", B[indice].coleguinhas[B[indice].cotAlunos].nomeCompleto);
	printf("Digite a matricula: ");
	scanf("%s", B[indice].coleguinhas[B[indice].cotAlunos].matricula);
	  printf("Digite o CPF do aluno: ");
  scanf("%s", B[indice].coleguinhas[B[indice].cotAlunos].cpf);
sm = 0; for (i=0; i<9; i++) { num =   B[indice].coleguinhas[B[indice].cotAlunos].cpf[i] - 48; sm = sm + (num * (10 - i));}
  r = 11 - (sm % 11); if ((r == 10) || (r == 11)) dig10 = '0'; else dig10 = r + 48; sm = 0;
  for (i=0; i<10; i++) { num =  B[indice].coleguinhas[B[indice].cotAlunos].cpf[i] - 48; sm = sm + (num * (11 - i)); }
  r = 11 - (sm % 11); if ((r == 10) || (r == 11)) dig11 = '0'; else dig11 = r + 48;
if ((dig10 ==  B[indice].coleguinhas[B[indice].cotAlunos].cpf[9]) && (dig11 ==  B[indice].coleguinhas[B[indice].cotAlunos].cpf[10]));
    else{
    printf("\nO CPF informado eh inválido.");
 }   
    printf("Digite a turma ao qual o aluno pertence: ");
	scanf("%s", B[indice].codigo);
	B[indice].cotAlunos++;
} 
void notasaluno(TURMAS *B, int indice){
	int op;
	printf("Digite o numero do aluno: ");
	scanf("%d", &op);
	printf("Digite a NP1: ");
	scanf("%f", &B[indice].coleguinhas[op].np1);
	printf("Digite a NP2: ");
	scanf("%f", &B[indice].coleguinhas[op].np2);
	B[indice].coleguinhas[op].mediaFinal= B[indice].coleguinhas[op].np1+B[indice].coleguinhas[op].np2/2;
}	

void calcularmedia(TURMAS *B, int indice ){
for(int i=0; i<B[indice].cotAlunos; i++){
printf("NOME DO ALUNO: %s\nMEDIA FINAL: %.2f\n", B[indice].coleguinhas[i].nomeCompleto, B[indice].coleguinhas[i].mediaFinal);
}
}	
	
void encerradiario(TURMAS *B, int indice){
	for(int i=0; i<B[indice].cotAlunos; i++){
	if (B[indice].coleguinhas[i].mediaFinal >= 6.00)
	printf("ALUNO APROVADO: %s MEDIA: %.2f\n", B[indice].coleguinhas[i].nomeCompleto, B[indice].coleguinhas[i].mediaFinal);
    else
    printf("ALUNO REPROVADO: %s MEDIA: %.2f\n", B[indice].coleguinhas[i].nomeCompleto, B[indice].coleguinhas[i].mediaFinal);
	 
	}	
}	
//função de exibição
//OP = CODIGO DO ALUNO
void listaralunos(TURMAS *B, int indice){
	for(int i = 0; i<B[indice].cotAlunos; i++){
	printf("TODOS OS ALUNOS DA TURMA:\n%s\n", B[indice].coleguinhas[i].nomeCompleto);
}	
}	
void exibirdados(TURMAS *B, int quantidade){
    for(int i=0;i<quantidade; i++){
    printf("CODIGO: %s\n", B[i].codigo);  
    printf("COMPONENTE CURRICULAR: %s\n", B[i].componenteCurricular);
    printf("HORARIOS: %s\n", dias[10]);
    } 
}

void exibirnotasp(TURMAS *B, int indice){
	for(int i= 0; i< B[indice].cotAlunos; i++){
	printf("ALUNO: %s\nNP1: %.2f\nNP2: %.2f\n",B[indice].coleguinhas[i].nomeCompleto, B[indice].coleguinhas[i].np1, B[indice].coleguinhas[i].np2);
	}
}

void notasfinais(TURMAS *B, int indice){
	for(int i = 0; i<B[indice].cotAlunos; i++){
		printf("ALUNO: %s\n MEDIA FINAL: %.2f\n",B[indice].coleguinhas[i].nomeCompleto, B[indice].coleguinhas[i].mediaFinal);
		}
}	
void semlixo(TURMAS *T, int x){
for(int i=0; i<x; i++){
printf("\tTURMA: %d CODIGO: %s\n", i, T[i].codigo);  

printf("\tCOMPONENTE CURRICULAR: %s\n", T[i].componenteCurricular);}

}




int main(){
int	 x=0 ,sw, indice;

TURMAS T[2];


do{
printf("\t______________________________________________________\n");
printf("\t|_____BEM VINDO AO MOODLE DIGITE A OPÇÃO DESEJADA_____|\n");
printf("\t|                                                     |\n");
printf("\t|        1 - cadastrar turmas                         |\n");
printf("\t|        2 - cadastrar alunos                         |\n");
printf("\t|        3 - inserir notas                            |\n");
printf("\t|        4 - exibir medias                            |\n");                
printf("\t|        5 - lista de alunos                          |\n");
printf("\t|        6 - exibir notas parcias                     |\n");
printf("\t|        7 - exibir notas finais                      |\n");
printf("\t|        8 - exibir dados                             |\n");
printf("\t|        9 - encerrar diario                          |\n");
printf("\t|       12 - parar programa                           |\n");
printf("\t|_____________________________________________________|\n");
scanf("%d", &sw);
switch(sw){



case 1:
acadastroTurma(T, x);
x++;
break;


case 2:
printf("Qual turma desaja cadastrar o aluno?\n");
semlixo(T, x);
scanf("%d", &indice);
cadastroAluno(T, indice);
break;

case 3:
printf("Qual turma deseja inserir notas\n");
semlixo(T, x);
scanf("%d", &indice);
notasaluno(T, indice);
break;

case 4:
printf("Qual turma deseja exibir as medias ?\n");
semlixo(T, x);
scanf("%d", &indice);
calcularmedia(T, indice);
break;

case 5:
printf("Qual turma deseja exibir lista de alunos ?");
semlixo(T, x);
scanf("%d", &indice);
listaralunos(T, indice);
break;

case 6:
printf("Qual turma deseja exibir notas parciais \n ?");
semlixo(T, x);
scanf("%d", &indice);
exibirnotasp(T, indice);
break;

case 7:
printf("Qual turma deseja exibir notas finais ?\n");
semlixo(T, x);
scanf("%d", &indice);
notasfinais(T, indice);
break;

case 8:
printf("Qual turma deseja exibir os dados ?\n");
semlixo(T, x);
scanf("%d", &indice);
exibirdados(T , indice);
break;


case 9:
printf("De qual turma deseja encerrar o diario\n");
semlixo(T, x);
scanf("%d", &indice);
encerradiario(T, indice);
break;


case 10:
break;
}
	
} while(sw != 12);	
	
	
	
	
	
	
	
	return 0;
	}





