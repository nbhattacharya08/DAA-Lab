#include<stdio.h>
#define MAX 10
int status[MAX];
int find(int x)
{
	while(status[x])
	 x=status[x];
	return x;
}
int uni(int x, int y)//1  2
{
	if(x!=y)
	{
		status[y]=x; 
		return 1;
	}
	return 0;
}
int main()
{
	int a[MAX][MAX];

	int n,i,j,p=1,r,c,src,dest,min;
	printf("Enter the no. of node : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\n Enter value for %c : ",i+65);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			 a[i][j]=9999;
		}
	}
	while(p<=n)
	{
		min=9999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]<min)
				{
					r=i;
					c=j;
					src=i;
					dest=j;
				 	min=a[i][j];
				 }
			}
		}
		r=find(r);//1
		c=find(c);//2
		if(uni(r,c))
		{
			printf("\n %c  to %c",src+65,dest+65);
		}
		a[src][dest]=999;
		a[dest][src]=999;
		p++;
	}
}
