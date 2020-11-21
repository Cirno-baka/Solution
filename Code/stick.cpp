#include <cstdio>
#include <cstdlib>

int n, tot, sum, cnt[59], maxn, minn=99;
bool use[69];

inline int read()
{
    char ch=getchar();
    int figure=0;
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        figure=((figure<<3)+(figure<<1))+ch-'0';
        ch=getchar();
    }
    return figure;
}

void scan()
{
    n=read();
    for(register int i=1; i<=n; ++i)
    {
        int cutLength;
        cutLength=read();
        if(cutLength>50)
        {
            continue;
        }
        ++tot;
        sum+=cutLength;
        ++cnt[cutLength];
        minn=(minn>cutLength) ? cutLength : minn;
        maxn=(maxn<cutLength) ? cutLength : maxn;
    }
    return;
}

void dfs(int num, int rest, int length, int pre)
{
    if(num==sum/length+1)
    {
        printf("%d", length);
        exit(0);
    }
    if(rest==0)
    {
        dfs(num+1, length, length, maxn);
    }
    for(register int j=pre; j>=minn; --j)
    {
        if(cnt[j]>0&&j<=rest)
        {
            --cnt[j];
            dfs(num, rest-j, length, j);
            ++cnt[j];
            if(rest==length||j==rest)
            {
                return;
            }
        }
    }
    return;
}

int main()
{
    scan();
    for(register int i=maxn; i<=(sum>>1); ++i)
    {
        if(sum%i!=0)
        {
            continue;
        }
        dfs(1, i, i, maxn);
    }
    printf("%d", sum);
    return 0;
}