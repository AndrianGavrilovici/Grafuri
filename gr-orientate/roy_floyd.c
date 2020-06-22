#include<stdio.h>
int n,m,a[20][20],q,w;
int citire(){
	int l,x,y;
	printf("nr de varfuri: ");scanf("%d",&n);
	printf("nr de muchii: ");scanf("%d",&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){a[i][j]=800;a[i][i]=0;}
	for(int k=1;k<=m;k++){
		printf("Muchia cu nr. de ordine %d: ",k);
		scanf("%d%d%d",&x,&y,&l);
		a[x][y]=l;
	}
}
int afisare(int n,int a[20][20]){
	printf("Matricea de adiacenta este: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%7d",a[i][j]);
		printf("\n");
	}
}
int drum_minim(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(a[i][k]!=800&&a[k][j]!=800){
					if(i!=j&&i!=k&&j!=i&&j!=k&&k!=i&&k!=j){
						printf("%d->%d->%d\n",i,k,j);
						printf("A%d(%d,%d)=min(A%d(%d,%d),A%d(%d,%d)+A%d(%d,%d))=min(%d,%d+%d)\n",k,i,j,k-1,i,j,k-1,i,k,k-1,k,j,a[i][j],a[i][k],a[k][j]);
					}

					if(a[i][j]>a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
						for(int i=1;i<=n;i++){
							for(int j=1;j<=n;j++)
								printf("%-4d",a[i][j]);
							printf("\n");
						}
					}
				}
			}
}
int descompun(int i,int j){
	int ok=0;
	int k=1;
	while(k<=n&&!ok){
		if(i!=k&&j!=k)
			if(a[i][j]==a[i][k]+a[k][j]){
				descompun(i,k);
				descompun(k,j);
				ok=1;
			}
			k++;
		}
	
		if(!ok)printf(" %d ",j);
}
int scriu_drum(int nod_init,int nod_final){
	if(a[nod_init][nod_final]<800){
		printf("\nlantul de la %d la %d are lungimea %d",nod_init,nod_final,a[nod_init][nod_final]);
		printf("\n un drum optim este: %d ",nod_init);
		descompun(nod_init,nod_final); 
	} else printf("nu exista lant de la %d la %d ",nod_init,nod_final);
}
int main(){
	citire();
	afisare(n,a);
	drum_minim();
	for(int q=1;q<=n;q++)
		for(int w=1;w<=n;w++)
	scriu_drum(q,w);
	printf("\n");
}
//By Andrian Gavrilovici