#include <stdio.h>
#include <conio2.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include "TrabPedagioTAD.h"

int Inicio(TpFila C[]){
	
	int intervalo, qtde, i;
	
	printf("Quais cabines deseja iniciar de imediato?\n");
	scanf("%d", &qtde);
	for(i = 0; i<5; i++){
		Inicializar(C[i]);
	}
	for(i = 0; i<qtde; i++){
		C[i].situacao = 'H';
	}
	printf("Qual sera o intervalo entre a chegada dos carros?\n");
	scanf("%d", &intervalo);
	
	return intervalo;
}

int Minimo(TpFila F[]){
	int i, menorQtde = 999, menor;
	for(i=0; i<4 ; i++){
		if((F[i].situacao == 'H' && F[i].fim - F[i].inicio + 1)<menorQtde){
			menor = i;
			menorQtde = F[i].fim - F[i].inicio + 1;
		}
			
	}
	return menor;
}

TpCarro Leitura(FILE *Ptr){
	TpCarro Carro;
	fscanf(Ptr, "%[^;];%[^;];%[^;];%c;%c;%d;%d\n", &Carro.placa, &Carro.cor, &Carro.fabricante, &Carro.categoria, &Carro.prioridade, &Carro.eixos, &Carro.atendimento);
	return Carro;
}

void Saida(TpFila F[], int timer){
	 
	 int i;
	 
	 for(i = 0; i<5; i++){
	 	if(!Vazia(F[i]) && F[i].Fila[F[i].inicio].atendimento == 0){
	 		Retirar(F[i]);
	 	}
	 }
	 for(i = 0; i<5; i++){
	 	if(!Vazia(F[i])){
	 		F[i].Fila[F[i].inicio].atendimento--;
	 	}
	 }
}

int main(void){
	
	TpFila Cabines[5];
	TpCarro Carro;
	char op;
	int timer = 0, intervalo, maxAtendimento, i;
	
	FILE *Ptr = fopen("Carros.txt", "r");
	
	intervalo = Inicio(Cabines);
	
	do{
		do{
			if(timer%intervalo == 0){
				Carro = Leitura(Ptr);
				if(Carro.prioridade == 'R'){
					Inserir(Cabines[4], Carro);
				}
				else
					Inserir(Cabines[Minimo(Cabines)], Carro);
			}
			timer++;
			Saida(Cabines, timer);
			for(i = 0; i<5; i++){
				if(!Vazia(Cabines[i])){
					Exibir(Cabines[i], i);
				}
				Sleep(500);
			}
		}while(!kbhit());
		
		op = toupper(getch());
		
		switch(op){
			case 'A':
				if(Cabines[0].situacao == 'H'){
					clrscr();
					printf("Esta cabine já está habilitada!\n");
					getch();
				}
				else{
					Inicializar(Cabines[0]);
					Cabines[0].situacao = 'H';
					clrscr();
					printf("\nCabine 1 HABILITADA\n");
				}
				break;
			case 'B':
				if(Cabines[1].situacao == 'H'){
					clrscr();
					printf("Esta cabine já está habilitada!\n");
					getch();
				}
				else{
					Inicializar(Cabines[1]);
					Cabines[1].situacao = 'H';
					clrscr();
					printf("\nCabine 2 HABILITADA\n");
				}
				break;
			case 'C':
				if(Cabines[2].situacao == 'H'){
					clrscr();
					printf("Esta cabine já está habilitada!\n");
					getch();
				}
				else{
					Inicializar(Cabines[2]);
					Cabines[2].situacao = 'H';
					clrscr();
					printf("\nCabine 3 HABILITADA\n");	
				}
				break;
			case 'D':
				if(Cabines[3].situacao == 'H'){
					clrscr();
					printf("Esta cabine já está habilitada!\n");
					getch();
				}
				else{
					Inicializar(Cabines[3]);
					Cabines[3].situacao = 'H';
					clrscr();
					printf("\nCabine 4 HABILITADA\n");
				}
				break;
			case 'E':
				if(Cabines[4].situacao == 'H'){
					clrscr();
					printf("Esta cabine já está habilitada!\n");
					getch();
				}
				else{
					Inicializar(Cabines[4]);
					Cabines[4].situacao = 'H';
					clrscr();
					printf("\nCabine 5 HABILITADA\n");
				}
				break;
			case '1':
				if(Cabines[0].situacao != 'H'){
					printf("Esta cabine já está desabilitada\n");
				}
				else{
					if(!Vazia(Cabines[0]))
						printf("Ainda há carros ná fila, favor esperar esvaziar\n");
					Cabines[0].situacao == 'D';
				}
				break;
			case '2':
				if(Cabines[1].situacao != 'H'){
					printf("Esta cabine já está desabilitada\n");
				}
				else{
					if(!Vazia(Cabines[0]))
						printf("Ainda há carros ná fila, favor esperar esvaziar\n");
					Cabines[1].situacao == 'D';
				}
				break;
			case '3':
				if(Cabines[2].situacao != 'H'){
					printf("Esta cabine já está desabilitada\n");
				}
				else{
					if(!Vazia(Cabines[0]))
						printf("Ainda há carros ná fila, favor esperar esvaziar\n");
					Cabines[2].situacao == 'D';
				}
				break;
			case '4':
				if(Cabines[3].situacao != 'H'){
					printf("Esta cabine já está desabilitada\n");
				}
				else{
					if(!Vazia(Cabines[0]))
						printf("Ainda há carros ná fila, favor esperar esvaziar\n");
					Cabines[3].situacao == 'D';
				}
				break;
		}
		printf("Habilitar cabine: Cabine 1 - [A] // Cabine 2 - [B] // Cabine 3 - [C] // Cabine 4 - [D] // Cabine 5 - [E] // Sair - [ESC]\n");
		printf("Desabilitar Cabine: Cabine 1 - [1] // Cabine 2 - [2] // Cabine 3 - [3] // Cabine 4 - [4] // Cabine 5 - [5] // Sair - [ESC]");
	}while(op!=27);
	fclose(Ptr);
}
