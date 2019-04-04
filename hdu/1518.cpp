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
int ok,a[33],flag[33],s,n;
void dfs(int cnt,int now,int x)
{
	if(ok) return;
	if(now==s&&cnt==3)
	{
		ok=1;
		return;
	}
	if(now==0)
	{
		dfs(cnt+1,s,x);
		return;
	}
	for(int i=x;i<n;i++)
	{
		if(flag[i]) continue;
		if(now-a[i]<0) continue;
		flag[i]=1;
		if(now-a[i]==0) dfs(cnt+1,s,1);
		else dfs(cnt,now-a[i],i+1);
		flag[i]=0;
		if(ok) return;
		while(i+1<n&&a[i]==a[i+1]) i++;
	}
}
void go()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		reverse(a,a+n);
		s=0;
		for(i=0;i<n;i++) s+=a[i];
		if(s%4)
		{
			puts("no");
			continue;
		}
		s/=4;
		if(a[0]>s)
		{
			puts("no");
			continue;
		}
		ok=0;
		mem(flag,0);
		flag[0]=1;
		dfs(0,s-a[0],1);
		if(ok) puts("yes");
		else puts("no");
	}
}
