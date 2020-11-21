#include <iostream>
#include <cstdio>
#include <cstring>

int n, m, nu[10009];
bool use[10009];

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

void cantor()
{
	int sum;
    for(register int i=1; i<=n; ++i)
    {
    	sum=0;
    	for(register int j=1; j<=n; ++j)
    	{
    		if(!use[j])
    		{
    			++sum;
			}
			if(j==nu[i])
			{
                use[j]=1;
				nu[i]=sum-1;
				break;
			}
		}
	}
	return;
}

void plus()
{
	nu[n]+=m;
	for(register int i=n; i>=1; --i)
	{
		nu[i-1]+=nu[i]/(n-i+1);
		nu[i]%=(n-i+1);
	}
	return;
}

void decantor()
{
    int su;
    for(register int i=1; i<=n; ++i)
    {
    	su=0;
        for(register int j=1; j<=n; ++j)
        {
            if(!use[j])
            {
                ++su;
            }
            if(su==nu[i]+1)
            {
                use[j]=1;
                printf("%d ", j);
                break;
            }
        }
	}
}

int main()
{
    n=read();
    m=read();
    for(register int i=1; i<=n; ++i)
    {
        nu[i]=read();
    }
    cantor();
    memset(use, 0, sizeof(use));
    plus();
    decantor();
    return 0;
}