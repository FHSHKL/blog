#include<bits/stdc++.h>

using namespace std;

bool debug=1;

int n,m;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const char* tow[]={"ri","dw","le","up"};

bool a[5000][5000][4];
int fa[5000*5000];

struct poi
{
    int x,y;
    bool to[4];
    int tint()
    {
        return x*n+y;
    }
    bool out()
    {
        if(x>n||y>m||x<1||y<1)
        {
            return 1;
        }
        return 0;
    }
};

int gf(const int &x)
{
    return (fa[x]==x)?(x):(fa[x]=gf(fa[x]));
}

int randd()
{
    int x=rand()*rand()%n+1;
    int y=rand()*rand()%m+1;
    int t=rand()%4;
    poi now;
    now.x=x;
    now.y=y;
    poi to;
    to.x=x+dx[t];
    to.y=y+dy[t];
    if(to.out())return 0;
    if(now.out())return 0;
    int le=gf(now.tint());
    int ri=gf(to.tint());
    if(le==ri)return 0;
    fa[le]=fa[ri];
    a[x][y][t]=1;
    if(debug)
    {
        printf("%d %d %d %s\n",x,y,t,tow[t]);
    }
    return 1;
}

signed main(int args,char *argc[])
{
    if(!args)
    {
        debug=0;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=(n+1)*(m+1);i++)
    {
        fa[i]=i;
    }
    int ans=n*m-1;
    if(debug)printf("ans:%d\n",ans);
    while(ans)
    {
        ans-=randd();
    }
    for(int i=1;i<=n*2-1;i++)
    {
        if(i&1)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[(i+1)/2][j][0]||a[(i+1)/2][j+1][2])
                {
                    printf("C-");
                }
                else
                {
                    printf("C ");
                }
            }
        }
        else
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i/2][j][1]||a[(i+3)/2][j][3])
                {
                    printf("| ");
                }
                else
                {
                    printf("  ");
                }
            }
        }
        putchar('\n');
    }
}
