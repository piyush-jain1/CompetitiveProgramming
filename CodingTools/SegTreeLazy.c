// Segment Tree with Lazy Implementation

#include <iostream>
#include <math.h>
#include <stdlib.h>
#define MAX 100005
using namespace std;

/*si -> index of current node in segment tree
    s and e -> Starting and ending indexes of elements for
                 which current nodes stores sum.
    us and ue -> starting and ending indexes of update query
    diff -> which we need to add in the range us to ue */
int constructTreeUtil(int a[],int s, int e, int * st, int si)
{
	if(s==e)
	{
		st[si] = a[s];
		return a[s];
	}

	int mid = s + (e-s)/2;
	st[si] = constructTreeUtil(a,s,mid,st,2*si + 1) + constructTreeUtil(a,mid+1,e,st,2*si + 2);

	return st[si];
}

int * constructTree(int a[], int n)
{
	int h = (int)(ceil(log2(n)));

	int max_size = 2*(int)pow(2,h) - 1;

	int *st = new int[max_size];

	constructTreeUtil(a, 0, n-1, st, 0);

	return st;

}

void updateRangeUtil(int si, int s, int e, int us, int ue, int *tree, int * lazy)
{
	if(lazy[si]!=0)
	{
		if(lazy[si]%2 == 1)
		{
			tree[si] += (e-s+1)-tree[si];
		}


		if(e!=s)
		{
			lazy[si*2 + 1] += lazy[si];
			lazy[si*2 + 2] += lazy[si];

		}

		lazy[si] = 0;
	}

	if(s>e || s>ue || e<us)
		return;

	if(s>=us && e<=ue)
	{
		tree[si] = (e-s+1)-tree[si];


		if(s!=e)
		{
			lazy[si*2 + 1] += 1;
			lazy[si*2 + 2] += 1;

		}

		return ;
	}

	int mid = (s+e)/2;
	updateRangeUtil(si*2 +1, s, mid, us, ue, tree, lazy);
	updateRangeUtil(si*2 +2, mid+1, e, us, ue, tree, lazy);

	tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}

void updateRange(int n, int us, int ue, int * tree, int * lazy)
{
	updateRangeUtil(0,0,n-1,us,ue,tree,lazy);
}

int getValUtil(int * tree, int * lazy, int s, int e, int qs, int qe, int si)
{
	if(lazy[si] != 0)
	{
		if((lazy[si])%2 == 1)
		{
			tree[si] += (e-s+1)-tree[si];
		}

		if(s!=e)
		{
			lazy[si*2 + 1] += lazy[si];
			lazy[si*2 + 2] += lazy[si];
		}

		lazy[si] = 0;
	}

    if(s>e || s>qe || e<qs)
    {
        return 0;
    }

	if(s>=qs && e<=qe)
	{
		return tree[si];
	}

	int mid = (s+e)/2;
	return getValUtil(tree, lazy, s, mid, qs, qe, 2*si + 1) + getValUtil(tree, lazy, mid+1, e, qs, qe, 2*si + 2);

}

int getVal(int * tree, int * lazy, int n, int qs, int qe)
{
	return getValUtil(tree, lazy, 0, n-1, qs, qe, 0);
}

int main()
{
	int n,q,i;
	cin>>n>>q;
	int a[100005]={0};
	int max_size = 2*n - 1;
	int *st = (int *)malloc(max_size * sizeof(int));
	int *lazy = (int *)malloc(max_size * sizeof(int));
	for(i=0;i<max_size;i++)
	{
		st[i]=0;
		lazy[i]=0;
	}
	st = constructTree(a,n);
    int qt,qs,qe;
    while(q--)
    {
        cin>>qt>>qs>>qe;
        if(qt==0)
        {
            updateRange(n,qs,qe,st,lazy);
        }
        else if(qt==1)
        {
            cout<<getVal(st,lazy,n,qs,qe)<<endl;
        }
    }


	return 0;



}
