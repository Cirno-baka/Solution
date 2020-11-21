#include <iostream>
#include <cstdio>

int n;

struct Carpet
{
    int a, b, g, k;
}m[10009];

int main()
{
    scanf("%d", &n);
    for(register int i=1; i<=n; ++i)
    {
        int ax, bx, gx, kx;
        scanf("%d%d%d%d", &ax, &bx, &gx, &kx);
        m[i].a=ax;
        m[i].b=bx;
        m[i].g=gx;
        m[i].k=kx;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    for(register int i=n; i>=1; --i)
    {
        if(x>=m[i].a&&x<=m[i].a+m[i].g-1&&y>=m[i].b&&y<=m[i].b+m[i].k-1)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}