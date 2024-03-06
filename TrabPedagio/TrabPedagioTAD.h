#define MAXFILA 10

struct TpCarro{
	char placa[7], cor[15], fabricante[30], categoria, prioridade;
	int eixos, atendimento;
};

struct TpFila{
	TpCarro Fila[MAXFILA];
	int inicio, fim;
	char situacao;
};

void Inicializar(TpFila &F){
	F.inicio = 0;
	F.fim = -1;
}

char Cheia(TpFila F){
	return F.fim-F.inicio+1 == MAXFILA;
}

char Vazia(TpFila F){
	return F.fim-F.inicio+1 == 0;
}

TpCarro Retirar(TpFila &F){
	return F.Fila[F.inicio++%MAXFILA];
}

void Inserir(TpFila &F, TpCarro C){
	F.Fila[++F.fim%MAXFILA];
}

TpCarro ElemFrente(TpFila F){
	return F.Fila[F.inicio];
}

void Exibir(TpFila F, int n){
	while(!Vazia(F)){
		printf("[%d]-", n);
		if(ElemFrente(F).categoria == 'P'){
			printf(" @ ");
		}
		else
			if(ElemFrente(F).categoria == 'C'){
				printf(" @@ ");
			}
			else
				if(ElemFrente(F).categoria == 'M'){
					printf(" - ");
				}
		printf("\n");
	}
}
