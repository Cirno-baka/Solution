#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using std::vector;

int n, m, v[3009], dp[3009][3009];

struct Node
{
    int num, wei;
};

vector<Node> t[3009];

int read()
{
    char ch = getchar();
    int figure = 0;
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        figure = (figure << 3) + (figure << 1) + ch - '0';
        ch = getchar();
    }
    return figure;
}

int dfs(int at)
{
    if (at > n - m)
    {
        dp[at][1] = v[at];
        return 1;
    }
    int totElement = 0;
    for (register int i = 0; i < t[at].size(); ++i)
    {
        int sonElement = dfs(t[at][i].num);
        totElement += sonElement;
        for (register int j = totElement; j > 0; --j)
        {
            for (register int k = 1; k <= sonElement; ++k)
            {
                if (j - k >= 0)
                {
                    dp[at][j] = ((dp[at][j] < dp[at][j - k] + dp[t[at][i].num][k] - t[at][i].wei) ? (dp[at][j - k] + dp[t[at][i].num][k] - t[at][i].wei) : (dp[at][j]));
                }
            }
        }
    }
    return totElement;
}

int main()
{
    n = read();
    m = read();
    memset(dp, 0x80, sizeof(dp));
    for (register int i = 1; i <= n - m; ++i)
    {
        int k;
        k = read();
        for (register int j = 1; j <= k; ++j)
        {
            Node temp;
            temp.num = read();
            temp.wei = read();
            t[i].push_back(temp);
        }
        dp[i][0] = 0;
    }
    for (register int i = 1; i <= m; ++i)
    {
        v[i + n - m] = read();
        dp[i + n - m][0] = 0;
    }
    dfs(1);
    for (register int i = m; i >= 1; --i)
    {
        if (dp[1][i] >= 0)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}