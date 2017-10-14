// Program to calculate nCr

// (a/b) mod m = a*y mod m where y is the multiplicative modulo inverse of b in mod m i.e. yb % m = 1
// a^(p-1) mod p = 1
// a * a^(p-2) mod p = 1
// So , multiplicative modulo inverse of a is a^(p-2)
// So, if we know multiplicative modulo inverse of N, we can find multiplicative modulo inverse of N-1 and so on
// Since N! * y mod p = 1
// (N-1)! * (N)*y mod p = 1
// So, multiplicative modulo inverse of i = multiplicative modulo inverse of (i+1) * (i+1) 

#define ll long long


const ll N = 4e5 + 5;
const ll mod = 1e9 + 7;
ll ifact[N];
ll fact[N];
void pre()
{
    fact[0] = 1;
    for(ll i = 1 ; i < N ; ++i)
    {
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    ifact[N - 1] = 977041169;   // multiplicative modulo inverse of (N-1)!
    for(ll i = N - 2 ; i >= 0 ; --i)
    {
        ifact[i] = (1LL * ifact[i + 1] * (i + 1LL)) % mod;
    }
}

ll ncr(ll n , ll r)
{
    if(r >= 0 && r <= n)
    {
        ll res = fact[n];
        res = (1LL * res * ifact[r]) % mod;
        res = (1LL * res * ifact[n - r]) % mod;
        return res;
    }
    else
    {
        return 0;
    }
}
