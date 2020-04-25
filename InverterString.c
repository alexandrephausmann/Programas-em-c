#include <stdio.h>

int main ()
{
	char nome[80];
	int i=0,cont=0;
	
	fgets
	(nome, 80, stdin);

for(i=0;nome[i] != '\0';i++)
	{
		cont++;
	}
	cont--;
	
	
for(;cont>=0;cont--)
	{
	printf("%c", nome[cont]);
	}
	return 0;
}
