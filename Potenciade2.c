
#include <stdio.h>
#include <string.h>
#include <math.h>

//int Quadrado(int a,int b){
//	b = a*a*a;
//	return b;
//}

int main(){
	int j=0,i=0;
	int vetA[10],vetB[10];
	printf("Insira 10 numeros e o programa retorna o quadrado dos mesmos\n");
	for(j=0;j<10;j++){
		scanf("%d",&vetA[j]);
	}
	for(i=0;i<10;i++){
		vetB[i]=pow(vetA[i],2);
		printf("%d\n",vetB[i]);
	}
return 0;
}

