#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int i,j,flag=0;
	char a[n][6];
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%c",&a[i][j]);
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		if(a[i][1]==a[i][2] && a[i][1]=='O')
		{
			printf("Yes\n");
			flag=1;
			a[i][1]=a[i][2]='+';
			break;
		}
		else if(a[i][4]==a[i][5] && a[i][4]=='O')
		{
			printf("Yes\n");
			flag=1;
			a[i][4]=a[i][5]='+';
			break;
		}
	
	}
	if (flag==0)
	{
		printf("No");
	}
	else
	{
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%c",a[i][j]);
		}
	}
	}
	printf("\n");
	return 0;
}

