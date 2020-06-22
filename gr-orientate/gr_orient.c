#include <stdio.h>
int c[20],v[20],ns,comp,n,a[20][20],b[20][20],d[20];
int x,y,e,r,m;int prim;int ultim;
int citire(){
	printf("nr de varfuri: ");scanf("%d",&n);
	printf("nr de muchii: ");scanf("%d",&m);

	for(int k=1;k<=m;k++){
		printf("Muchia cu nr. de ordine %d: ",k);
		scanf("%d%d",&x,&y);
		a[x][y]=1;b[x][y]=b[y][x]=1;
	}
}
int afisare(int a[20][20],int n){
	printf("Matricea de adiacenta este: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%-4d",a[i][j]);
		printf("\n");
	}
}
int gradul(int d[20]){
	int s1;//GRADUL EXTERN
	for(int i=1;i<=n;i++){
		s1=0;
		for(int j=1;j<=n;j++)
			s1+=a[i][j];
		d[i]=s1;
	}
	printf("Gradul extern:\n");
	for(int i=1;i<=n;i++)
		printf("d+(%d)=%d\n",i,d[i]);
	//GRADUL INTERN
	for(int i=1;i<=n;i++){
		s1=0;
		for(int j=1;j<=n;j++)
			s1+=a[j][i];
		d[i]=s1;
	}
	printf("Gradul intern:\n");
	for(int i=1;i<=n;i++)
		printf("d-(%d)=%d\n",i,d[i]);
}
int succ_pred(int d[20]){
	//GRADUL SUCCESOR
	printf("Gradul succesor:\n");
	for(int i=1;i<=n;i++){
		printf("G+(%d)=",i);
		for(int j=1;j<=n;j++){
			if(a[i][j]==1)printf("{%d}",j);
		}
		printf("\n");
	}
	//GRADUL PREDECESOR
	printf("Gradul predecesor:\n");
	for(int i=1;i<=n;i++){
		printf("G-(%d)=",i);
		for(int j=1;j<=n;j++)
			if(a[j][i]==1)printf("{%d}",j);
		printf("\n");
	}
}
int turneu(){
	int c=0,d=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(b[i][j]!=1)d++;
	d-=n;
	if(d==0)printf("Acesta este graf turneu\n");
	else printf("Acesta nu este graf turneu\n");
}
int main(){
	citire();
	afisare(a,n);
	gradul(d);
	succ_pred(d);
	turneu();
	return 0;
}