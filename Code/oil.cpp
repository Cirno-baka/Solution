#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define M_PI		3.14159265358979323846
using std::abs;
using std::sort;

int n, rumia, daiyousei, cirno, letty, ans;
double s;

struct Kagiyama
{
    int x,y;
    double r;
}hina[9];

inline double min(const double &remilia, const double &flandre)
{
    return (remilia<flandre) ? (remilia) : (flandre);
}

int getFrontier(int xn, int yn)
{
    return (int)min((int)min(abs(rumia-xn), abs(cirno-xn)), (int)min(abs(daiyousei-yn), abs(letty-yn)));
}

int cmp(const Kagiyama satori, const Kagiyama koishi)
{
    return satori.r>koishi.r;
}

double getDistance(Kagiyama shion, Kagiyama jyoon)
{
    return (double)sqrt((double)((shion.x-jyoon.x)*(shion.x-jyoon.x)+(shion.y-jyoon.y)*(shion.y-jyoon.y)));
}

double getSquare(const double &R)
{
    return R*R*(M_PI);
}

int main()
{
    scanf("%d%d%d%d%d", &n, &rumia, &daiyousei, &cirno, &letty);
    s=(double)(abs(rumia-cirno)*abs(daiyousei-letty));
    for(register int i=1; i<=n; ++i)
    {
        scanf("%d%d", &hina[i].x, &hina[i].y);
        hina[i].r=getFrontier(hina[i].x, hina[i].y);
    }
    sort(hina+1, hina+n+1, cmp);
    for(register int i=1; i<=n; ++i)
    {
        for(register int j=i-1; j>=1; --j)
        {
            if(hina[j].r>0)
            hina[i].r=min(hina[i].r, getDistance(hina[i], hina[j])-hina[j].r);
        }
    }
    for(register int i=1; i<=n; ++i)
    {
        if(hina[i].r>0)
        s-=getSquare(hina[i].r);
    }
    ans=(int)round(s);
    printf("%d", ans);
    return 0;
}