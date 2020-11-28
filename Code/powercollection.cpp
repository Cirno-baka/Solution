#include <iostream>
#include <cstdio>
#include <algorithm>
using std::sort;

int n, m, k, t, dp[4009], ans;

struct Power
{
    int x, y, v;
}p[4009];

int cmp(const Power &p1, const Power &p2)
{
    return (p1.x!=p2.x) ? (p1.x<p2.x) : (p1.y<p2.y);
}

int abs(int num)
{
    return (num>0) ? (num) : (0-num);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &t);
    for(register int i=1; i<=k; ++i)
    {
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].v);
    }
    sort(p+1, p+k+1, cmp);
    for(register int i=1; i<=k; ++i)
    {
        dp[i]=p[i].v;
        for(register int j=1; j<i; ++j)
        {
            if(abs(p[i].y-p[j].y)<=(t*(p[i].x-p[j].x)))
            {
                dp[i]=((dp[i]>dp[j]+p[i].v) ? (dp[i]) : (dp[j]+p[i].v));
            }
        }
        ans=((ans<dp[i]) ? (dp[i]) : (ans));
    }
    printf("%d", ans);
    return 0;
}