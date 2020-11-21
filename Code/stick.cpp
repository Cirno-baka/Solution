#include <cstdio>
#include <cstdlib>

int n, s[69], tot, sum, cnt[59];
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
        s[tot]=cutLength;
        sum+=cutLength;
        ++cnt[cutLength];
    }
    return;
}

inline int min(const int &Cirno, const int &Daiyousei)
{
    return (Cirno<Daiyousei) ? Cirno : Daiyousei;
}

void dfs(int num, int rest, int length, int pre)
{
    if(num==sum/length+1)
    {
        printf("%d", length);
        exit(0);
    }
    for(register int j=min(rest, pre); j>=1; --j)
    {
        if(cnt[j]>0)
        {
            if(j==rest)
            {
                --cnt[j];
                dfs(num+1, length, length, 0x7fffffff);
                ++cnt[j];
            }
            else
            {
                if(j<rest)
                {
                    --cnt[j];
                    dfs(num, rest-j, length, j);
                    ++cnt[j];
                    if(rest==0||rest==j)
                    {
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    scan();
    for(register int i=s[1]; i<=sum/2; ++i)
    {
        if(sum%i!=0)
        {
            continue;
        }
        dfs(1, i, i, 0x7fffffff);
    }
    printf("%d", sum);
    return 0;
}