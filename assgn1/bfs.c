#include<stdio.h>
#define MAX 20
int top;

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
	 
	insert(stack,0);// first node
	state[0]=2;
	while(p<=n)//until all node process
	{
	
		k=del(stack);
		state[k]=3;//for execute
		printf("\t %c",k+65);
		
		for(i=0;i<n;i++)// store the neighbour in stack
		{
			if(a[k][i]==1 && state[i]==1)
			{
				insert(stack,i);
				state[i]=2;
			}
		}
		p++;
		
	}
	
}
int front,rear;
void insert(int [],int);
int del(int[]);
void insert(int s[], int num)
{
	if(rear==-1)
	{
		rear=0;
		front=0;
		s[rear]=num;
	}
	else
	 s[++rear]=num;
}
int del(int s[])
{
	int t=s[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
		
	}
	else
	 front++;
	 
	 return t;
}