#include<stdio.h>
#define MAX 10
#define INF 99999
int main()
{
	int a[MAX][MAX],status[MAX];
	int n,i,j,p=1,min,s,d,sum=0;
	printf("Enter the order ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter value for Vertex %c : ",i+65);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			 a[i][j]=INF;
			 
		}
	}
	printf("\n matrix form \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		 printf("%d\t",a[i][j]);
		 
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	 status[i]=0; // 0 = not process  1 =process
	
	
	status[0]=1;// first node always process
	
	while(p<n)//n=no. of nodes p=total no. of process p
	{
		min=INF;
		s=-1,d=-1;
		for(i=0;i<n;i++)
		{
			if(status[i]==1)
			{
				for(j=0;j<n;j++)
				{
					if(status[j]==0 && a[i][j]<min)
					{
						min=a[i][j];
						s=i;
						d=j;
					}
				
				}//end of inner for
			}// end of if
		}// end of outer for

	   printf("\n %c ---- %c  = %d",s+65,d+65,min);
	   sum=sum+min;
	   status[d]=1;
	 p++;//every time atleaast one node process
	}
	printf("\n\n Value %d",sum);
}