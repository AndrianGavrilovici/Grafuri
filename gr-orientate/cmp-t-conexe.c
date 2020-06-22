#include<stdio.h>
typedef int mat[20][20];
typedef int sir[20];
mat a,d;
sir s,p,luate;
sir comp[50],ncomp;
int ok,n1,n,m,nc,ns,np,q,w;
int succesori(int i,sir s,int ns){
	ns=0;
	for(int j=1;j<=n;j++)
		if(d[i][j]==1){ns+=1;s[ns]=j;}
}
int predecesori(int i,sir p,int np){
	np=0;
	for(int j=1;j<=n;j++)
		if(d[j][i]==1){np+=1;p[np]=j;}
}
int intersectie(sir s,int ns,sir p,int np,sir x,int nx){
	int ok;
	nx=0;
	for(int i=1;i<=ns;i++){
		ok=0;
		for(int j=1;j<=np;j++)
			if(s[i]==p[j])ok=1;
		if(ok==1){nx++;x[nx]=s[i];}
	}
}
int main(){int a,b,c;
	printf("dati nr de noduri: ");
	scanf("%d",&n);
	printf("dati nr de muchii: ");
	scanf("%d",&m);
	for (int i = 1; i <= m; ++i){
		printf("Muchia cu nr. de ordine %d: ", i);
		scanf("%d%d",&q,&w);
		d[q][w] = 1; 
	}
	printf("Matricea de adiacenta este: \n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%-4d",d[i][j]);
		printf("\n");
	}
		nc=0;
		n1=0;
		for(int i=1;i<=n;i++){
			ok=0;
			for(int j=1;j<=n1;j++)
				if(luate[j]==i)ok=1;
				if(ok==0){
					nc++;
					succesori(i,s,ns);
					predecesori(i,p,np);
					intersectie(s,ns,p,np,comp[nc],ncomp[nc]);
					printf("%d\n",ncomp[nc]);
					for(int j=1;j<=ncomp[nc];j++){
						n1++;
						luate[n1]=comp[nc][j];}
				}
		}
	for(int i=1;i<=nc;i++){
		printf("component tare conexa cu nr:%d\n",i);
		for(int j=1;j<=ncomp[i];j++)
			printf("%d ",comp[i][j]);
		printf("\n");
	}
}