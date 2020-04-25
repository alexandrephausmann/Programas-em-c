#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
	int j=0,i=0,menor=0,maior=0,num=0;
	int vetA[20],vetB[20];
	
	printf(" Buscador para achar o numero maior e o menor \n");
	printf(" ******************************************** \n");
	printf("Insira a quantidade de numeros que voce quer verificar(O maximo e 20) \n");
	
	scanf("%d",&num);
	
	if(num<0)
	{
		printf("Valor inválido");
		return 0;
	}
	
	for(j=0;j<num;j++){
		scanf("%d",&vetA[j]);
	}
	menor=99999;
	for(j=0;j<num;j++)
	{
		if (vetA[j]<menor)
		{
			menor=vetA[j];
		}
	}
	
	for(j=0;j<num;j++)
	{
		if (vetA[j]>maior)
		{
			maior=vetA[j];
		}
	}
	printf("menor valor eh %d\n",menor);
	printf("maior valor eh %d\n",maior);
return 0;
}
