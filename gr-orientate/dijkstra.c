#include<stdio.h>
int n,m,l,x,y,a[20][20];
int e1,p,u,coada[20],viz[20];
int r,poz,d[20],s[20],t[20],q[20];
int citire(){
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
int afisare(int a[20][20],int n){
	printf("Matricea de adiacenta este: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%7d",a[i][j]);
		printf("\n");
	}
}
int parcurgere_latime(){
	for(int i=1;i<=n;i++)viz[i]=0;
	viz[r]=1;coada[1]=r;p=1;u=1;
	while(p<=u){
		e1=coada[p];
		for(int j=1;j<=n;j++)
			if((a[e1][j]!=0)&&(a[e1][j]!=800)&&(viz[j]==0)){
				u+=1;coada[u]=j;viz[j]=1;}p+=1;
	}
}
int tabel_initial(){
	printf("r= ");scanf("%d",&r);
	printf("D=");
	for(int i=r;i<=r;i++)
		for(int j=1;j<=n;j++){
			d[j]=a[i][j];printf("%4d",d[j]);}
	printf("\nS=");
	for(int i=1;i<=n;i++){
		s[i]=0;s[r]=1;printf("%4d",s[i]);}
	printf("\nT=");
	for(int i=1;i<=n;i++){
		if(d[i]!=0&&d[i]!=800)t[i]=r;else t[i]=0;
		printf("%4d",t[i]);}printf("\n");
}
int secventa(){
	printf("\n");
	printf("poz= ");scanf("%d",&poz);
	printf("j= ");
	for(int i=1;i<=n;i++)
		if(i!=1&&coada[i]!=poz){q[i]=coada[i];printf("%d ",q[i]);}
	printf("\n");
	for(int i=1;i<=n;i++)
		if(i!=1&&coada[i]!=poz){printf("%d->%d->%d\n",r,poz,q[i]);}
	for(int i=1;i<=n;i++)
		if(i!=coada[1]&&coada[i]!=poz)
			if(d[i]>d[poz]+a[poz][i]){
				printf("%d>%d+%d=%d>%d\n",d[i],d[poz],a[poz][i],d[i],d[poz]+a[poz][i]);
				d[i]=d[poz]+a[poz][i];t[i]=poz;
			}else if(d[i]<d[poz]+a[poz][i])
				printf("%d<%d+%d\n",d[i],d[poz],a[poz][i]);
	s[poz]=1;
	printf("D=");for(int i=1;i<=n;i++)printf("%4d",d[i]);
	printf("\nS=");for(int i=1;i<=n;i++)printf("%4d",s[i]);
	printf("\nT=");for(int i=1;i<=n;i++){printf("%4d",t[i]);}
	printf("\n");
}
int main(){
	citire();
	afisare(a,n);
	tabel_initial();
	parcurgere_latime();
	for(int j=1;j<=n-1;j++)
	secventa();
}
///by andrian gavrilovici