#include<stdio.h>
#include<stdlib.h>
int* aranjare_nod_max(int n,int *d);
int* aranjare_nod_min(int n,int *d);
int *allocation(int l){
    int *m;
    m=(int*)calloc(l,sizeof(int));
    return m;
}
void release(int* m){
    free(m);
}
char input_key(){
	char key;
	do{			
		printf("Rs: ");scanf("%s",&key);
		if(key!='y'&&key!='n')printf("Nu ati introdus corect!\n");
	}while(key!='y'&&key!='n');
	return key;
}
int* introducere(int n,int *a){
	for(int i=1;i<=n;i++){
		printf("Valoarea nodului %d= ",i);
		scanf("%d",&a[i]);
	}
	return a;
}
void Max_Heap(int n,int *d){
	int c=0;char key;
	printf("H={  ");
	for(int i=1;i<=n;i++)printf("%-4d",d[i]);
	printf("}\n");
	for(int i=1;i<=(n/2);i++){
		if(d[i]>=d[i*2])c++;
		if(n%2==0&&i==n/2){}else
		if(d[i]>=d[i*2+1])c++;
	}
	if(c==n||c==n-1)printf("Este Max-Heap\n");
	else {
		printf("Nu este Max-Heap\n");
		printf("Doriti sa-l faceti Max-Heap? y/n\n");
		key=input_key();
		if(key=='y'){d=aranjare_nod_max(n,d);Max_Heap(n,d);}
		else return;
	}
}
void Min_Heap(int n,int *d){
	int c=0;char key;
	printf("H={  ");
	for(int i=1;i<=n;i++)printf("%-4d",d[i]);
	printf("}\n");
	for(int i=1;i<=(n/2);i++){
		if(d[i]<=d[i*2])c++;
		if(n%2==0&&i==n/2){}else
		if(d[i]<=d[i*2+1])c++;
	}
	if(c==n||c==n-1)printf("Este Min-Heap\n");
	else {
		printf("Nu este Min-Heap\n");
		printf("Doriti sa-l faceti Min-Heap? y/n\n");
		key=input_key();
		if(key=='y'){d=aranjare_nod_min(n,d);Min_Heap(n,d);}
		else return;
	}
}
int inserare_nod(int n,int *d){
	int insert; char key;
	printf("Doriti sa adaugati noduri? y/n\n");
	key=input_key();
	if(key=='n'){printf("Ati ales sa nu adaugati noduri.\n");exit(1);}
	printf("Cate noduri doriti sa adaugati?\n");
	printf("Rs: ");scanf("%d",&insert);
	return insert;
}
int* adaugare_nod(int n,int insert,int *a){
	int subtitute[n+1];
	for(int i=1;i<=n-insert;i++)subtitute[i]=a[i];
	for(int i=(n-insert)+1;i<=n;i++){
		printf("Valoarea nodului adaugat %d= ",i);
		scanf("%d",&subtitute[i]);
	}
		a=0;
		release(a);
		a=allocation(n);
	for(int i=1;i<=n;i++)a[i]=subtitute[i];
	return a;
}
int* aranjare_nod_max(int n,int *d){
	int t;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n/2;j++){
		if(d[j]<d[j*2]){
			t=d[j];
			d[j]=d[j*2];
			d[j*2]=t;
		}
		if(n%2==0&&j==n/2){}else
		if(d[j]<d[j*2+1]){
			t=d[j];
			d[j]=d[j*2+1];
			d[j*2+1]=t;
		}
	}
	return d;
}
int* aranjare_nod_min(int n,int *d){
	int t;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n/2;j++){
		if(d[j]<d[j*2]){
			t=d[j];
			d[j]=d[j*2];
			d[j*2]=t;
		}
		if(n%2==0&&j==n/2){}else
		if(d[j]<d[j*2+1]){
			t=d[j];
			d[j]=d[j*2+1];
			d[j*2+1]=t;
		}
	}
	return d;
}
int main(){
	int n,insert,*a;char key;
		printf("Max-Heap sau Min-Heap? y=Max-Heap, n=Min-Heap\n");
		key=input_key();
	printf("Numarul de noduri:\n");
	printf("n= ");scanf("%d",&n);
	a=allocation(n+1);
	a=introducere(n,a);
	if(key=='y')Max_Heap(n,a);
	else Min_Heap(n,a);
	insert=inserare_nod(n,a);
	n+=insert;
	a=adaugare_nod(n,insert,a);
	printf("H={  ");
	for(int i=1;i<=n;i++)printf("%-4d",a[i]);
	printf("}\n");
	if(key=='y'){a=aranjare_nod_max(n,a);printf("Max-Heap-ul aranjat dupa inserare.\n");}
	else {a=aranjare_nod_min(n,a);printf("Min-Heap-ul aranjat dupa inserare.\n");}
	if(key=='y')Max_Heap(n,a);
	else Min_Heap(n,a);
	release(a);
	return 0;
}
