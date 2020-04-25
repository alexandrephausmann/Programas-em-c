#include <stdio.h>
#define N 20

int main ()
{ 		int matriz [N][N];
		int nlin=0,ncol=0,l=0,c=0;
		
		printf("Transformar matriz transposta \n");
		printf("Insira a quantidade de linhas \n");
		scanf("%d",&nlin);
		printf("Insira a quantidade de colunas \n");
		scanf("%d",&ncol);
		
			for(l=0;l<nlin;l++)
			{
				for(c=0;c<ncol;c++)
				{
					scanf("%d",&matriz[l][c]);
				}
			}
			
					for(c=0;c<ncol;c++)
					{
						for(l=0;l<nlin;l++)
						{
							printf("%d ",matriz[l][c]);
						}
							printf("\n");
					}
return 0;

}
