#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int x[30],y[30],c[30],h[20][20],t,p,r,i,j;
int parent[50],n,m;
int u,v,a,b,min=0,mincost=0,ne=1;
int introducere(){
for(i=1;i<=m;i++)
for(j=1;j<=m;j++){
       h[i][j]=999;
       h[i][i]=0;
        }
for(i=1;i<=n;i++){
    printf("x[%d]=",i);scanf("%d",&x[i]);
    printf("y[%d]=",i);scanf("%d",&y[i]);
    printf("c[%d]=",i);scanf("%d",&c[i]);
    h[x[i]][y[i]]=c[i];
   }
}

int afisare(int b){
printf("  |");
for(i=1;i<=b;i++)
    printf("%d ",x[i]);
    printf("|\n");
printf("A=|");
for(i=1;i<=b;i++)
    printf("%d ",y[i]);
     printf("|\n");
printf("  |");
for(i=1;i<=b;i++)
    printf("%d ",c[i]);
      printf("|\n");
}

int afis_pond(){
for(i=1;i<=m;i++){
    for(j=1;j<=m;j++)
        printf("%6d",h[i][j]);
    printf("\n");
}
}

int sortarea(int s){
    t=0;
for(i=1;i<=s;i++)
for(j=s;j>i;j--){
    if(c[j]<c[j-1]){
        t=c[j];r=x[j];p=y[j];
        c[j]=c[j-1];x[j]=x[j-1];y[j]=y[j-1];
        c[j-1]=t;x[j-1]=r;y[j-1]=p;
    }
  }

}
int find(int f){
    while(parent[f])
	f=parent[f];
	return f;
	 }

int uni(int h,int w)
{	if(h!=w)
	{	parent[w]=h;
		return 1; }
	return 0;
}

void kruskal(){

while((ne) < m)
	{	for(i=1,min=999;i<=m;i++)
		{	for(j=1;j <= m;j++)
			{	if(h[i][j] < min)
				{	min=h[i][j];  a=u=i;  b=v=j;
				}
            }
        }
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{	printf("\n%d muchia [%d,%d] =%d\n",ne,a,b,min);ne++;
		 printf("mincost=%d+%d=%d\n",mincost,min,mincost+min);
			mincost +=min; printf("mincost=%d\n",mincost);}
		h[a][b]=h[b][a]=999;
	  }
       printf("\n\t APCM= %d",mincost);
    }



int main()
{

printf("Introduceti numarul de muchii: ");
scanf("%d",&n);
printf("Numarul de noduri: ");scanf("%d",&m);
printf("Introducem p/u muchii(x-extr. intiala, y-extr. finala,c-costul)\n");
  introducere(n);
  printf("Matricea ponderilor\n");
  afis_pond(n);
  afisare(n);
  sortarea(n);
  printf("***Matricea reorganizata***\n");
  afisare(n);
  kruskal();

}
