#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;

int n, m, dp[309][309];

struct Node
{
    int num, wei;
};

vector<Node> t[309];

void dfs(int at)
{
    for(register int i=0; i<t[at].size(); ++i)
    {
        dfs(t[at][i].num);
        for(register int j=m+1; j>=1; --j)
        {
            for(register int k=0; k<j; ++k)
            {
                dp[at][j]=((dp[at][j]<dp[at][j-k]+dp[t[at][i].num][k]) ? (dp[at][j-k]+dp[t[at][i].num][k]) : (dp[at][j]));
            }
        }
    }
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= n; ++i)
    {
        int k, s;
        scanf("%d%d", &k, &s);
        Node temp;
        temp.num = i;
        temp.wei = s;
        t[k].push_back(temp);
        dp[i][1]=temp.wei;
    }
    dfs(0);
    printf("%d", dp[0][m+1]);
    return 0;
}