ll grundy[100010];
ll *st = new ll[1000000];

ll constructSTUtil(ll ss, ll se, ll si)
{
    if (ss == se)
    {
        st[si] = grundy[ss];
        return grundy[ss];
    }

    ll mid = ss + (se-ss)/2 ;
    st[si] =  constructSTUtil(ss, mid, si*2+1)^constructSTUtil(mid+1, se, si*2+2);
    return st[si];
}


ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    ll mid = ss + (se-ss)/2;;
    return getSumUtil(ss, mid, qs, qe, 2*si+1)^getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

void updateValueUtil(ll ss, ll se, ll i, ll upd, ll si)
{
    if (i < ss || i > se)
        return;

    st[si] = st[si]^upd;
    if (se != ss)
    {
        ll mid = ss + (se-ss)/2 ;
        updateValueUtil(ss, mid, i, upd, 2*si + 1);
        updateValueUtil(mid+1, se, i, upd, 2*si + 2);
    }
}

void updateValue(ll n, ll i, ll new_val)
{
    ll old = grundy[i];
    grundy[i] = new_val;
    updateValueUtil(0, n-1, i, old^new_val, 0);
}


int main()
{
    constructSTUtil(0, n-1, 0);
    getSumUtil(0,n-1,qs-1,qe-1,0)
    updateValue(n,pos-1,newGrundy);
}

////////////////////////////////////////////////////////////////


Alternate Implementation : 
void update(ll i,ll v,ll si,ll ss,ll se,ll l)
{
    if(ss==se)
        { st[si]=v; return;}
    if(ss > i || i>se || se <ss) return;
    ll mid=(ss+se)/2;

    if(i>mid)
        update(i,v,2*si+2,mid+1,se,l+1);
    else
        update(i,v,2*si+1,ss,mid,l+1);
    if((n-l)&1)
        st[si]=st[2*si+1] | st[2*si+2];
    else
        st[si]=st[2*si+1]^st[2*si+2];
}