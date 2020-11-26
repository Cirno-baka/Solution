#include <iostream>
#include <cstdio>
#include <stack>
typedef long long ll;
using std::stack;

ll n, m, bit, tree[2000009], ls[2000009], rs[2000009], tag[2000009];

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
        ls[i]=i-bit;
        rs[i]=i-bit;
    }
    for(register int i=bit-1; i>=1; --i)
    {
        tree[i]=tree[(i<<2)]+tree[(i<<2|1)];
        ls[i]=ls[(i<<2)];
        rs[i]=rs[(i<<2|1)];
    }
    return;
}

inline void pushDown(ll xx)
{
    if(tag[xx]>0&&xx>bit)
    {
        tag[(xx<<1)]+=tag[xx];
        tag[(xx<<1|1)]+=tag[xx];
        tree[(xx<<1)]+=(rs[(xx<<1)]-ls[(xx<<1)])*tag[xx];
        tree[(xx<<1|1)]+=(rs[(xx<<1|1)]-ls[(xx<<1|1)])*tag[xx];
        tag[xx]=0;
    }
    return;
}

inline void tagUpdate(ll nod)
{
    stack <ll> s;
    while(nod>0)
    {
        s.push(nod);
        nod>>=1;
    }
    while(s.size>0)
    {
        pushDown(s.top);
        s.pop();
    }
    return;
}

inline void rangeUpdate(ll pl, ll pr, ll as)
{
    int 
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
        ll o, x, y, k;
        o=read();
        if(o==1)
        {
            x=read();
            y=read();
            k=read();
            rangeUpdate(x, y, k);
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