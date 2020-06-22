//parcurgere in adancime DEPTH FIRST
#include <stdio.h>
int a[20][20],viz[20];
int n,p1,m,x,y;
void parc_adancime(int k)
{
	viz[k]=1;
	for(int j=1;j<=n;j++)
		if((a[k][j]==1)&&(viz[j]==0)){
			printf("%-5d",j);
			parc_adancime(j);
		}

}
int main()
{
	printf("Introdu nr de noduri: ");
	scanf("%d",&m);
	printf("Introdu nr de muchii: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("Muchia cu nr. de ordine %d: ",i);
		scanf("%d%d",&x,&y);
		a[x][y]=1;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++)
			viz[i]=0;
		printf("dati nodul de plecare:%d\n",k);
		printf("%-5d",k );
		parc_adancime(k);
		printf("\n");
	}
	return 0;
}