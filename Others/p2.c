#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	int i,j,r,c;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			{
				r=i;
				c=j;
			}
		}
		
	}
	int sum[(2*n)+2];
	int sum0=0,sum2=0,sum1=0;
	
	for(i=0;i<n;i++)
	{	
		sum[i]=0;
		for(j=0;j<n;j++)
		{
			sum[i]+=a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{	
		sum[i+3]=0;
		for(j=0;j<n;j++)
		{
			sum[i+3]+=a[j][i];
		}
	}
	sum[(2*n)]=0;
	for(i=0;i<n;i++)
	{
		sum[(2*n)]+=a[i][i];
	}
	sum[(2*n)+1]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i+j==n-1)
			{ sum[(2*n)+1]+=a[i][j]; }
		}
	}
	for(i=0;i<(2*n)+2;i++)
	{
		printf("%d,",sum[i]);
	}
	
	for(i=0;i<(2*n)+2;i++)
	{
		for(j=0;j<(2*n)+2;j++)
		{	
			if(i!=r && i!=n+c && j!=r && j!=n+c)
			{
			if(sum[i]!=sum[j])
			{
				printf("-1\n");
				return 0;
			}
			}
		}
	}
		
	
	
	
	if(r>=1)
	{
		for(j=0;j<n;j++)
		{
			sum0+=a[r-1][j];
		}
	}
	else if(r==0)
	{
		for(j=0;j<n;j++)
		{
			sum0+=a[r+1][j];
		}
	}
	for(i=0;i<n;i++)
	{
		sum1+=a[r][i];
		sum2+=a[i][c];
	}
	

	if ((sum0>sum1) && (sum0-sum1)==(sum0-sum2))
		{ a[r][c]=sum0-sum1; }
	else
		{ a[r][c]=-1; }
	printf("%d\n",a[r][c]);
	
	return 0;
}
	

