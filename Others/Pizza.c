#include <stdio.h>
#include <string.h>

void find(int a[],int n)
{
	int check=0;
	static int i=0;
	while(a[i]!=0 && i<n)
	{
		check+=a[i];
		if(i==n-1 && check%2==0)
		{
			printf("YES\n");
			return ;
		}
		i++;
	}
	 						
	if(check%2==1)
	{
		printf("No\n");
		return ;
	}
	else
	{	
		i+=1;
		find(a,n);
	}
	
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	find(a,n);
	
}