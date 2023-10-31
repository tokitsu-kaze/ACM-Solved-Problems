#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=4e4+10;
const ll mod=1e9+7;
struct node
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}p[1011];
bool check(int x)
{
	if(x<0||x>40000) return 0;
	else return 1;
}
int main()
{
    int n,i,j,ans,t;
    scanf("%d",&t);
	while(t--)
	{
		while(~scanf("%d",&n)&&n)
	    {
			map<int,bool> mp[MAX];
	        for(i=0;i<n;i++)
	        {
	            p[i].input();
	            p[i].x+=20000;
	            p[i].y+=20000;
	            mp[p[i].x][p[i].y]=1;
	        }
	        ans=0;
	        for(i=0;i<n;i++)
	        {
	            for(j=i+1;j<n;j++)
	            {
	                int a,b,c,d,e,f,g,h;
	                a=p[i].x;
	                b=p[i].y;
	                c=p[j].x;
	                d=p[j].y;
	                e=a+b+c-d;
	                f=-a+b+c+d;
	                g=a-b+c+d;
	                h=a+b-c+d;
	                if(abs(e%2)+abs(f%2)+abs(g%2)+abs(h%2)==0&&(check(e/2)+check(f/2)+check(g/2)+check(h/2)==4))
	                {
	                    if(mp[e/2][f/2]&&mp[g/2][h/2]) ans++;
	                }
	            }
	        }
	        printf("%d\n",ans/2);
	    }
	    if(t) puts("");
	}
    return 0;
}
