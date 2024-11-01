#include<stdio.h>
#include<stdlib.h>
void selectionsort(int a[],int n);
void selectionsort(int a[],int n)
{
	int i,j,temp,pos;
	for (i=0;i<n-1;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[pos])
			pos=j;
		}
		if(i!=pos)
		{
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
}
int main()
{
	int i,n,*a;
	printf("enter size");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("enter ele");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	selectionsort(a,n);
	printf("sorted");
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	 free(a);
}

