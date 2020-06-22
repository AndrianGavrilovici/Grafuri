#include <stdio.h>
int c[20],v[20],ns,comp,n,a[20][20],d[20];
int x,y,m;int prim;int ultim;
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
int afisare(int a[20][20],int n)
{
	printf("Matricea de adiacenta este: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%-4d",a[i][j]);
		printf("\n");
	}
}
int exista_nod_nevizitat(int v[20],int n)
{
	for(int i=1;i<=n;i++)
		if(v[i]==0)return i;//primul nod nevizitat
	return 0;//nu mai exista noduri nevizitate
}
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
int conex()
{
	citire();
	afisare(a,n);
	parcurgere_latime(a,n,1);
	if(exista_nod_nevizitat(v,n)!=0)
		printf("Graful Nu este conex!\n");
	else printf("Graful este conex!\n");
}

int grad(int d[20])
{
	int s1,b=0,c=0;
	for(int i=1;i<=n;i++){
		s1=0;
		for(int j=1;j<=n;j++)
			s1+=a[i][j];
		d[i]=s1;
	}
	for(int i=1;i<=n;i++){
		printf("d(%d)=%d\n",i,d[i]);
		if(d[i]==0)b+=1;
		if(d[i]==1)c+=1;
	}
	printf("Noduri terminale = %d\n", c);
	printf("Noduri izolate = %d\n",b);
	b=0;
	if(n>=3)
		for(int i=1;i<=n;i++)
			if(d[i]<n/2)b++;
	if(b==0)printf("Graful este hamiltonian\n");
	else printf("Graful nu este hamiltonian\n");
	c=0;
	for(int i=1;i<=n;i++)
		if(d[i]%2!=0)c++;
	if(c==0)printf("Graful este eolerian\n");
	else printf("Graful nu este eolerian\n");
}
int main()
{
	conex();
	grad(d);
	return 0;
}