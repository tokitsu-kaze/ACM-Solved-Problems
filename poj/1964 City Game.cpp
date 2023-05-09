#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int mp[1010][1010],up[1010][1010],l[1010],r[1010];
int st[1010],top;
void go()
{
	int t,n,m,i,j,ans;
	char s[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%s",s);
				if(s[0]=='R') mp[i][j]=0;
				else mp[i][j]=1;
			}
		}
		mem(up[0],0);
		for(j=1;j<=m;j++)
		{
			for(i=1;i<=n;i++)
			{
				if(mp[i][j]) up[i][j]=up[i-1][j]+1;
				else up[i][j]=0;
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			top=0;
			up[i][m+1]=-1;
			for(j=1;j<=m+1;j++)
			{
				while(top&&up[i][st[top-1]]>up[i][j])
				{
					r[st[top-1]]=j-1;
					top--;
				}
				st[top++]=j;
			}
			top=0;
			up[i][0]=-1;
			for(j=m;~j;j--)
			{
				while(top&&up[i][st[top-1]]>up[i][j])
				{
					l[st[top-1]]=j+1;
					top--;
				}
				st[top++]=j;
			}
			for(j=1;j<=m;j++) ans=max(ans,up[i][j]*(r[j]-l[j]+1));
		}
		printf("%d\n",ans*3);
	}
}
