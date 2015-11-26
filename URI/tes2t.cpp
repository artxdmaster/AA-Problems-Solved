//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 200001
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
//const int inf=0x7fffffff;   //нчоч╢С
const int inf=0x3f3f3f3f;
/*

inline void P(int x)
{
    Num=0;if(!x){putchar(‘0‘);puts("");return;}
    while(x>0)CH[++Num]=x%10,x/=10;
    while(Num)putchar(CH[Num--]+48);
    puts("");
}
*/
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void P(int x)
{
    Num=0;if(!x){putchar('0');puts("");return;}
    while(x>0)CH[++Num]=x%10,x/=10;
    while(Num)putchar(CH[Num--]+48);
    puts("");
}
//**************************************************************************************


int a[2010];
ll dp[2010][30];
ll cal(ll x)
{
    if(x%10>=5)
        x+=10;
    x-=x%10;
    return x;
}
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n-1;i++)
    {
        for(int j=0;j<=d;j++)
        {
            if(j==0)
                dp[i][j]+=dp[i-1][j]+a[i];
            else
                dp[i][j]=min(dp[i-1][j]+a[i],cal(dp[i-1][j-1]+a[i]));
        }
    }
    ll ans=inf;
    for(int j=0;j<=d;j++)
        ans=min(cal(dp[n-1][j]+a[n]),ans);
    cout<<ans<<endl;
}
