#include <stdio.h>
#include <stdlib.h>

int n;

void Merge(int a[], int left, int mid, int right){
	
	int *b=(int *)malloc(sizeof(int)*n);
	int i=left, j=mid+1, k=left;

	for(i=left; i<=right; i++)
		printf("%d ",a[i]);
	printf("\n");

	i=left;

	while(i<=mid&&j<=right){
		if(a[i]>=a[j]){
			b[k++]=a[j++];
		}
		else b[k++]=a[i++];
	}
	
	if(i>mid){
		while(j<=right){
			b[k++]=a[j++];
		}
	}
	else if(j>right){
		while(i<=mid) {
			b[k++]=a[i++];
		}
	}
	for(i=left; i<=right; i++)
		printf("%d ",b[i]);
	printf("\n");

	free(b);
}

void Division(int a[], int left, int right){
	int mid;
	
	if(left<right){
		mid=(left+right)/2;
		Division(a, left, mid);
		Division(a, mid+1, right);
		Merge(a,left,mid,right);
	}
}

int main(void){
	int a[]={37,13,12,16,3,22,25,18};
	int i;
	n=sizeof(a)/sizeof(int);
	Division(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}



