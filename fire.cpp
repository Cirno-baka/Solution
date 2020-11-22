#include <iostream>
#include <cstdio>
#include <algorithm>
using std::sort;

int n, num[1009], depth[1009], f[1009], ans; 
bool build[1009], bro[1009], cover[1009];

int cmp(const int &cirno, const int &daiyousei)
{
    return depth[cirno]>depth[daiyousei];
}

bool covered(int index)
{
    return (build[index]||build[f[index]]||build[f[f[index]]]||bro[f[index]]||cover[index]);
}

int main()
{
    scanf("%d", &n);
    num[1]=1;
    for(register int i=2; i<=n; ++i)
    {
        int node;
        scanf("%d", &node);
        f[i]=node;
        depth[i]=depth[node]+1;
        num[i]=i;
    }
    sort(num+1, num+n+1, cmp);
    for(register int i=1; i<=n; ++i)
    {
        if(!covered(num[i]))
        {
            if(depth[num[i]]>=2)
            {
                build[f[f[num[i]]]]=1;
                bro[f[f[f[num[i]]]]]=1;
                cover[f[f[f[num[i]]]]]=1;
                cover[f[f[f[f[num[i]]]]]]=1;
                ++ans;
            }
            else
            {
                ++ans;
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}