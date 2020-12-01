#include <iostream>
#include <cstdio>
#include <vector>
using std::vector;

int n, r[6009], dp[6009][2], root, ans;
bool son[6009];
vector<int> t[6009];

void dfs(int x)
{
    for (register int i = 0; i < t[x].size(); ++i)
    {
        dfs(t[x][i]);
        dp[x][0] += ((dp[t[x][i]][0] < dp[t[x][i]][1] + r[t[x][i]]) ? (dp[t[x][i]][1] + r[t[x][i]]) : (dp[t[x][i]][0]));
        dp[x][1] += dp[t[x][i]][0];
    }
    return;
}

int main()
{
    scanf("%d", &n);
    for (register int i = 1; i <= n; ++i)
    {
        scanf("%d", &r[i]);
    }
    for (register int i = 1; i < n; ++i)
    {
        int l, k;
        scanf("%d%d", &l, &k);
        t[k].push_back(l);
        son[l] = 1;
        if (!son[k])
        {
            root = k;
        }
    }
    dfs(root);
    ans = ((dp[root][0] < dp[root][1] + r[root]) ? (dp[root][1] + r[root]) : (dp[root][0]));
    printf("%d", ans);
    return 0;
}