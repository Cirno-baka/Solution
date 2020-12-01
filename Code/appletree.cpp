#include <iostream>
#include <cstdio>
#include <vector>
using std::vector;

int n, q, dp[109][109];

struct Node
{
    int num, wei;
};

vector <Node> t[109];

int max(int x, int y)
{
    return ((x>y) ? (x) : (y));
}

void dfs(int pre, int at)
{
    int l=0, r=0, wl, wr;
    for(register int i=0; i<t[at].size(); ++i)
    {
        if(t[at][i].num==pre)
        {
            continue;
        }
        if(l==0)
        {
            l=t[at][i].num;
            wl=i;
        }
        else
        {
            r=t[at][i].num;
            wr=i;
        }
    }
    if(l==0)
    {
        return;
    }
    dfs(at, l);
    dfs(at, r);
    for(register int i=1; i<=q; ++i)
    {
        for(register int j=0; j<=i; ++j)
        {
            if(j==0)
            {
                dp[at][i]=max(dp[at][i], dp[r][i-1]+t[at][wr].wei);
                continue;
            }
            if(j==i)
            {
                dp[at][i]=max(dp[at][i], dp[l][i-1]+t[at][wl].wei);
                continue;
            }
            dp[at][i]=max(dp[at][i], dp[l][j-1]+t[at][wl].wei+dp[r][i-j-1]+t[at][wr].wei);
        }
    }
    return;
}

int main()
{
    scanf("%d%d", &n, &q);
    for(register int i=1; i<n; ++i)
    {
        int u,v,w;
        scanf("%d%d%d", &u, &v, &w);
        Node n1, n2;
        n1.num=v;
        n1.wei=w;
        n2.num=u;
        n2.wei=w;
        t[u].push_back(n1);
        t[v].push_back(n2);
    }
    dfs(0, 1);
    printf("%d", dp[1][q]);
    return 0;
}