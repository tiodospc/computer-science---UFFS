#include <stdio.h>

void verificacontrato(int idade){
	
	scanf("%d", &idade);
	if(idade < 18)
	printf("Pode ser contratado");
	else 
	printf("Ainda e aprendiz");
	}
	
	  double aumentasalario(double salario, int porcentual){
      double aumenta;
	  aumenta= salario+salario*(porcentual/100);
      printf("aumento: %.2lf", aumenta);
	  return aumenta; 
		}
		
    
    void fixacompleta(char nome[30], int idade, int tempo, double salario){
		printf("\tnome: %s\n", nome);
		printf("\tidade: %d\n", idade);
		printf("\ttempo de empresa: %d\n", tempo);
		printf("\tsalario: %.2lf\n", salario);}


      double bonificasalario(int tempo, double salario){
      int salariobon;
      if (tempo >= 5);
      salariobon= salario+100;
      printf("bonificação: %d", salariobon);
      	  return salariobon;
  }
int main(){
	char nome[30];
	int idade, tempo, porcentual;
	double salario;
	int op;
	
	printf("Digite sua idade\n");
	scanf("%d", &idade);
	printf("Digite seu nome:\n");
	scanf("%s", nome);
	printf("Digite seu salario\n");
	scanf("%lf", &salario);
    printf("Digite seu tempo de impresa\n");
	scanf("%d", &tempo);
	printf("Digite porcentual de aumento do seu salario\n");
	scanf("%d", &porcentual);
	
	
system("clear");
	
	do{
	printf("\n\tBem vindo ao menu do funcionario Digite a opção desejada:\n");
	printf("1- Ver fixa completa\n");
	printf("2- para ver aumento do salario\n");
	printf("3- para sua bonificação\n");
	printf("4- verificar contrato\n");
	printf("5- limpar tela\n");
	printf("6- parar execução\n");
	scanf("%d", &op);
	switch(op){
		
		case 1: 
		fixacompleta(nome, idade, tempo, salario);
		break;
		
		
		case 2:
		aumentasalario(salario, porcentual);
		break;
	
		case 3:
		bonificasalario(tempo, salario);
		break;

        case 4: verificacontrato(idade);
        break;
        
        case 5:
        system("clear");
        break;
        

		
		
		
} 
}while(op != 6);


   
	return 0;
	}

