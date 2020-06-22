#include<stdio.h>
int main(){
	int b[55],no,c,p,temp;
	printf("Introduceti nodurile:\n");
	char key;
	no=0;
	while(key!='\n'){
		scanf("%d",&b[no]);
		scanf("%c", &key);
		no++;
	}
	for(int i=1;i<no;i++){
		c=i;
		do{
			p=(c-1)/2;
			if(b[p]<b[c]){
				temp=b[p];
				b[p]=b[c];
				b[c]=temp;
			}
			c=p;
		}while(c!=0);
	}
	for(int j=no-1;j>=0;j--){
		temp=b[0];
		b[0]=b[j];
		b[j]=temp;
		p=0;
		do{
			c=2*p+1;
			if(b[p]<b[c]&&c<j){
				temp=b[p];
				b[p]=b[c];
				b[c]=temp;
			}
			p=c;
		}while(c<j);
	}
	printf("Elementele sortate sunt:\n");
	for(int i=0;i<no;i++)
		printf("%d ",b[i]);

	return 0;
}