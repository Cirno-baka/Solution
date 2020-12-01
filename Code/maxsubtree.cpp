#include <iostream>
#include <cstdio>
#include <vector>
using std::vector;

int n, b[16009], dp[16009], ans;
vector<int> t[16009];

int read()
{
    char ch = getchar();
    int flag = 1, figure = 0;
    while ((ch < '0' || ch > '9') && ch != '-')
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        flag = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        figure = (figure << 3) + (figure << 1) + ch - '0';
        ch = getchar();
    }
    return flag * figure;
}

void dfs(int pre, int at)
{
    dp[at]=b[at];
    for(register int i=0; i<t[at].size(); ++i)
    {
        if(t[at][i]==pre)
        {
            continue;
        }
        dfs(at, t[at][i]);
        if(dp[t[at][i]]>0)
        {
            dp[at]+=dp[t[at][i]];
        }
    }
    return;
}

int main()
{
    n = read();
    for (register int i = 1; i <= n; ++i)
    {
        b[i] = read();
    }
    for (register int i = 1; i < n; ++i)
    {
        int f1, f2;
        f1=read();
        f2=read();
        t[f1].push_back(f2);
        t[f2].push_back(f1);
    }
    dfs(0, 1);
    for(register int i=1; i<=n; ++i)
    {
        ans=((ans<dp[i]) ? (dp[i]) : (ans));
    }
    printf("%d", ans);
    return 0;
}