#include <stdio.h>
#include <string.h>

int main()
{
	unsigned long int n,m,k,i;
	scanf("%lu %lu %lu",&n,&m,&k);
	unsigned long int c[n],l[m],r[m];
	for(i=0;i<n;i++)
	{
		scanf("%lu",&c[i]);
	}

	for(i=0;i<m;i++)
	{
		scanf("%lu %lu",&l[i],&r[i]);
	}

	long int count=0;
	for(i=0;i<m;i++)
	{
		if(c[l[i]-1]!=c[r[i]-1])
		{
			count++;
		}
	}
	printf("%ld\n",count );
}