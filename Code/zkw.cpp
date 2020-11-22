#include <iostream>
#include <cstdio>
typedef long long ll;

ll n, m, bit, tree[2000009];

inline ll read()
{
    ll input=0, f=1;
    char ch=getchar();
    while((ch<'0'||ch>'9')&&(ch!='-'))
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        f=-f;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        input=((input<<3)+(input<<1))+ch-'0';
        ch=getchar();
    }
    return input*f;
}

inline void maintain(const ll &node)
{
    tree[node]=tree[node<<1]+tree[node<<1|1];
    return;
}

inline void build()
{
    bit=1;
    while(bit<n)
    {
        bit<<=1;
    }
    for(register int i=bit+1; i<=bit+n; ++i)
    {
        tree[i]=read();
    }
    for(register int i=bit-1; i>=1; --i)
    {
        maintain(i);
    }
    return;
}

inline void singlePointMod(ll pos, ll as)
{
    pos+=bit;
    tree[pos]=as;
    for((pos>>=1); pos>=1; (pos>>=1))
    {
        maintain(pos);
    }
    return;
}

inline void rangeSumQuery(ll l, ll r)
{
    ll ans=0;
    for(l=l+bit-1, r=r+bit+1; (l^r^1); (l>>=1), (r>>=1))
    {
        if(~l&1)
        {
            ans+=tree[l^1];
        }
        if(r&1)
        {
            ans+=tree[r^1];
        }
    }
    printf("%lld\n", ans);
    return;
}

int main()
{
    n=read();
    m=read();
    build();
    for(register ll i=1; i<=m; ++i)
    {
        ll o, x, y;
        o=read();
        if(o==1)
        {
            x=read();
            y=read();
            singlePointMod(x, tree[x+bit]+y);
        }
        else
        {
            x=read();
            y=read();
            rangeSumQuery(x, y);
        }
    }
    return 0;
}