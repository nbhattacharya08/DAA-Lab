#include<stdio.h>
#define MAX 20
int top;
void push(int[], int );
int pop(int[]);
void main()
{
	int a[MAX][MAX];
	int stack[MAX];
	int state[MAX];
	int n,i,j,p=1,k;
	printf("Enter no. of nodes ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter data  ( %c to %c ): ",i+65,j+65);
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	 state[i]=1;
	 
	push(stack,0);// first node
	state[0]=2;
	while(p<=n)//until all node process
	{
	
		k=pop(stack);
		state[k]=3;//for execute
		printf("\t %c",k+65);
		
		for(i=0;i<n;i++)// store the neighbour in stack
		{
			if(a[k][i]==1 && state[i]==1)
			{
				push(stack,i);
				state[i]=2;
			}
		}
		p++;
		
	}
	
}
void push(int s[], int num)
{
	s[++top]=num;
}
int pop(int s[])
{
	return(s[top--]);
}