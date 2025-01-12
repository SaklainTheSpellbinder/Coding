#include<stdio.h>
#include<stdlib.h>
int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	int ** p=(int**)malloc(m*sizeof(int*));
	for(int i=0; i<m; i++) {
		*(p+i)=(int *)malloc(n*sizeof(int));
	}
	int sum=0;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d",*(p+i)+j);
			sum+=*(*(p+i)+j);
		}
	}
	printf("\nRow-wise elements: ");

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf("%d ",*(*(p+i)+j));
		}
		//printf("\n");
	}
	printf("\n");

    printf("Sum= %d",sum);
	for(int i=0; i<m; i++) {
		free(*(p+i));
	}
	free(p);
}