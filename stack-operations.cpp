#include<stdio.h>
#include<stdlib.h>
int max, top=-1;
int *a;
void push(int ele)
{
	if (top==max-1)
	{
		max=2*max;
		printf("Stack size is full, resized to %d\n", max);
        a = realloc(a, max * sizeof(int));
        
        if (a == NULL) {
            printf("Memory allocation failed\n");
            exit(1);

	}
	a[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("empty");
		return -999;
	}
	else
	{
		return(a[top--]);
	}
}
void display()
{
	if(top==-1)
	{
		printf("empty");
	}
	else
	{
		printf("stack ele are");
		for(int i=top;i>=0;i--)
		printf("%d",a[i]);
	}
}
int main()
{
	int choice,ele;
	printf("enter max");
	scanf("%d",&max);
	a=(int*)malloc(max*sizeof(int));
	while(1)
	{
		printf("enter choice");
		printf("1 for push 2:pop 3:display 4:exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter ele to push");
			        scanf("%d",&ele);
			        push(ele);
		        	break;
		    case 2:ele=pop();
		          if(ele!=-999)
		          {
		          	printf("the del is %d",ele);
				  }
			     break;
			case 3:display();
			       break;
			case 4:free(a);
			       exit(0);
		    default:printf("invalid"); 
		}
	}
}
