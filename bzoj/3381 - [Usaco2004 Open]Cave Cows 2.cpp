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
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
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
const int MAX=25000+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
int v[MAX],minn[MAX][22];
void RMQ(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		minn[i][0]=v[i];
		for(j=1;1<<(j-1)<=n;j++)
		{
			minn[i][j]=INF;
		}
	}
	for(j=1;1<<(j-1)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			int t=1<<(j-1);
			minn[i][j]=min(minn[i][j-1],minn[i+t][j-1]);
		}
	}
}
int query(int l,int r)
{
	int j=(int)(log10(r-l+1)/log10(2))+1;
	int i=r-(1<<(j-1))+1;
	return min(minn[l][j-1],minn[i][j-1]);
}
void go()
{
	int n,q,i,l,r;
	while(~scanf("%d%d",&n,&q))
	{
		for(i=1;i<=n;i++) scanf("%d",&v[i]);
		RMQ(n);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			printf("%d\n",query(l,r));
		}
	}
}