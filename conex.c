//graful conex
#include <stdio.h>
int c[20],v[20],ns,comp,n,a[20][20];
int x,y,m;int prim;int ultim;//FILE *f;
//citirea grafului din fisier si constr.matricei de adiacenta
/*int citire()
{
	FILE *f=fopen("graf.in","w+");
	n=fscanf(f);
	while(x=fscanf(f),y=fscanf(f)){
		a[x][y]=a[y][x]=1;
	}
	fclose(f);
}*/
int citire(){
	printf("nr de varfuri: ");scanf("%d",&n);
	printf("nr de muchii: ");scanf("%d",&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=0;
	for(int k=1;k<=m;k++){
		printf("Muchia cu nr. de ordine %d: ",k);
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
}
//afisarea pe ecran a matricei de adiacenta
int afisare(int a[20][20],int n)
{
	printf("Matricea de adiacenta este: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%-4d",a[i][j]);
		printf("\n");
	}
}
//returneaza primul nod nevizitat
int exista_nod_nevizitat(int v[20],int n)
{
	for(int i=1;i<=n;i++)
		if(v[i]==0)return i;//primul nod nevizitat
	return 0;//nu mai exista noduri nevizitate
}
/*parcurgerea in latime a unei componente conexe, plecand din nodul de start ns*/
int parcurgere_latime(int a[20][20],int n,int ns)
{
	comp++;v[ns]=1;
	printf("Componenta conexa :%d este formata din nodurile\n",comp);
	printf("%-4d",ns);	
	prim=ultim=1;c[ultim]=ns;
	while(prim<=ultim){
		for(int i=1;i<=n;i++)
			if(a[c[prim]][i]==1)
				if(v[i]==0){
					ultim++;
					c[ultim]=i;
					printf("%-4d",i);
					v[i]=1;
				}
				prim++;
	}
	printf("\n");
}
int main()
{
	citire();
	afisare(a,n);
	parcurgere_latime(a,n,1);
	if(exista_nod_nevizitat(v,n)!=0)
		printf("Graful Nu este conex!\n");
	else printf("Graful este conex!\n");
	return 0;
}
