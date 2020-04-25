#include <stdio.h>
#include <string.h>

int main()
{
	int x=0,y=0,z=0,res=0,cont=0;
	char palavra[81],palavrainversa[81],palavra1[81];
	
	fgets(palavra,81,stdin);
	
	y=strlen(palavra)-2;
	cont=y;
	
	for(x=0;palavra[x] != '\0';x++,y--)
	{
		if((palavra[x]>64) && (palavra[x]<91))
		{
			palavra [x] +=32;
		}
		palavrainversa[y]=palavra[x];
	}
			
//    printf("%s",palavra1);
//    printf("2 X%sX",palavrainversa);
	
	for(x=0;x<cont;x++)
	{
		if(palavra[x] != palavrainversa[x])
		{
	//		printf("entrou\n");
	//		printf("1- %c\n",palavra[x]);
	//		printf("2- %c\n",palavrainversa[x]);
			res=1;
		}
	}
	if(palavra[x] != palavrainversa[x])
		{
//	printf("1b- b%cb\n",palavra[x]);
//	printf("2b- b%cb\n",palavrainversa[x]);
	res=1;
	}
	if(res==0)
	{
		printf("sao palindromos");
	}else
	{
		printf("nao sao palindromos");
	}

	
	return 0;
}
