#include <stdio.h>
#include <string.h>


int mod(int p,int q)
{
	if(p>=0)
	{
		return p%q;
	}
	return q-abs(p);

}
int out(int p,int q)
{
	if(mod(p,q)<=(mod(-p,q)))
	{
		return mod(p,q);
	}
	else
		return mod(-p,q);
}
int main()
{
	char a[101];
	scanf("%s",a);
	int i,ans=out((a[0]-97),26);
	int n=strlen(a);
	for(i=1;i<n;i++)
	{	
		ans+=out((a[i]-a[i-1]),26);
	}
	printf("%d\n",ans );
}