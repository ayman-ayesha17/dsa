#include<stdio.h>
int main()
{
	int n,i,a[10],big;
	printf("enter size");
	scanf("%d",&n);
	printf("enter the ele");
	for(i=0;i<n;i++)
	 scanf("%d",&a[i]);
	big=a[0];
	for(i=0;i<n;i++)
	{
		if (a[i]>big);
		 big=a[i];
	}
	printf("the big is %d",big);
}
