/*
Alexandre Paschoal Hausmann - 256601
Isabela Archanjo Batarce - 236862
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Matriz {
int li;
int co;
int **m;
}Matriz;

/*Questão 1) Faça o construtor do registro. Tal construtor recebe como paramêtros o m e o n. O
construtor deve criar o registro e alocar a matriz dinamicamente. Após alocar, todos os campos da
matriz devem ser iniciados com valor igual a zero.
*/
Matriz* criaMatriz(int li, int co){

	int i=0,k=0;
//	printf("teste 1\n");
	Matriz *matriz;
	matriz = (Matriz *) malloc (sizeof(Matriz *));
	matriz->li = li;
	matriz->co = co;
	printf("Matriz\n");
  /* aloca as linhas da matriz */
  	matriz->m = (int**) malloc (li *sizeof(int*));


	for(i=0;i<matriz->li;i++)
	{
		matriz->m[i]= (int*) malloc (co *sizeof(int));

		for( k=0;k<co;k++)
		{
//			printf("teste 2\n");
			matriz->m[i][k] = 0;
		}
	}
//		printf("Matriz com %d colunas e %d linhas\n",matriz->co,matriz->li);
		return matriz;
}

/*Quest˜ao 2 Quest˜ao 2) Crie o destrutor do registro. O Destrutor deve desalocar tudo que foi alocado dinamicamente.*/
void freeMatriz(Matriz *ma){
    free(ma);
}
/*Quest˜ao 3) Crie uma fun¸c˜ao que imprime o registro.*/
void imprime(Matriz * m){
	int i=0,k=0;
    for(i=0;i<m->li;i++){
        for(k=0;k<m->co;k++){
            printf("%d ",m->m[i][k]);
        }
         printf("\n");
    }
}

/*Quest˜ao 4) Fa¸ca uma fun¸c˜ao que multiplica duas matrizes. Vocˆe deve verificar se as dimens˜oes das
matrizes s˜ao compat´iveis.*/

Matriz * multiplica(Matriz *a, Matriz *b){
	int i=0,k=0,j=0,aux=0;
//	printf("teste 1\n");
	Matriz *matriz;
	matriz = (Matriz *) malloc (sizeof(Matriz *));
	matriz->li = a->li;
	matriz->co = b->co;
//	printf("Matriz\n");
  /* aloca as linhas da matriz */
  	matriz->m = (int**) malloc (a->li *sizeof(int*));

	for(j=0;j<matriz->co;j++)
	{		
	    matriz->m[j]= (int*) malloc (b->co *sizeof(int));
		for(i=0;i<matriz->li;i++)
		{			
			aux=0;
			for( k=0;k<matriz->co;k++)
			{
				aux += a->m[j][k]*b->m[k][i];
			//	printf("teste 2\n");
			//	printf("aux eh: %d\n",aux);		
			}
//			printf("aux eh: %d\n",aux);	
			matriz->m[j][i] =aux;	
		}
	}
	
//		printf("Matriz com %d colunas e %d linhas\n",matriz->co,matriz->li);
		return matriz;
	
}

/*QuestËœao 5) FaÂ¸ca uma funÂ¸cËœao que cria uma matriz preenchida de 1s.*/

Matriz * criaMatrizUns(int linha, int coluna){
	int i=0,k=0;
//	printf("teste 1\n");
	Matriz *matriz;
	matriz = (Matriz *) malloc (sizeof(Matriz *));
	matriz->li = linha;
	matriz->co = coluna;
//	printf("Matriz\n");
  /* aloca as linhas da matriz */
  	matriz->m = (int**) malloc (linha *sizeof(int*));


	for(i=0;i<matriz->li;i++)
	{
		matriz->m[i]= (int*) malloc (coluna *sizeof(int));

		for( k=0;k<coluna;k++)
		{
//			printf("teste 2\n");
			matriz->m[i][k] = 1;
		}
	}
//		printf("Matriz com %d colunas e %d linhas\n",matriz->co,matriz->li);
		return matriz;

}
/*Quest˜ao 6) Fa¸ca uma fun¸c˜ao que escreve o registro em um arquivo.*/

void persiste(Matriz *m, char * fname){
	int i=0,k=0;
    FILE * f = fopen(fname, "w");
    for(i=0;i<m->li;i++){
        for(k=0;k<m->co;k++){
            fprintf(f,"%d ",m->m[i][k]);
        }
        fprintf(f,"\n");
    }
    fclose(f);
}


/*Quest˜ao 7) Fa¸ca uma fun¸c˜ao que lˆe um registro
de um arquivo.*/
Matriz * carrega(char *fname){
    char buffer[10000];
    FILE * f = fopen(fname, "rb");
    fread(&buffer, sizeof(char), 10000,f);
    printf("%s\n",buffer);
    fclose(f);

}
int main(){
    Matriz *m = criaMatriz(4,2);
    m->m[0][0]=7;
    m->m[1][0]=m->m[2][0]=m->m[3][0]=5;
    printf("--m--\n");
    imprime(m);
    Matriz *a = criaMatrizUns(3,3);
    Matriz *b = criaMatrizUns(3,3);
    a->m[0][1]=7;
	a->m[0][2]=5;
    printf("--a--\n");
    imprime(a);
    printf("--b--\n");
    imprime(b);
    printf("--a*a--\n");
    imprime(multiplica(a,a));
    persiste(a,"a.txt");
    printf("--a.txt--\n");
    imprime(carrega("a.txt"));
    freeMatriz(m);
	freeMatriz(a);
	freeMatriz(b);
    return 0;
}
