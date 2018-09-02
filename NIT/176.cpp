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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
ll pre[55],flag;
void init()
{
	mem(pre,0);
	for(ll i=1;i<=21;i++)
	{
		pre[i]=(2<<(i-1));
//		cout<<pre[i]<<endl;
	}
}
void dfs(ll a,ll b,ll cnt)
{
	ll i;
	if(a<0||b<0) return;
	if(a==0&&b==0&&cnt==0)
	{
		flag=1;
		return;
	}
	if(cnt==0) return;
	dfs(a-cnt,b-pre[cnt],cnt-1);
	if(flag) return;
	dfs(a-pre[cnt],b-cnt,cnt-1);
	if(flag) return;
}
int main()
{
	ll t,a,b,n,i;
	init();
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		flag=0;
		dfs(a,b,n);
		if(flag) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*int a[MAX],b[MAX];
int main()
{
	int n,m,cnt,i;
	while(~scanf("%d%d",&n,&m))
	{
		mem(a,0);
		mem(b,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if(n==1)
		{
			puts("1");
			continue;
		}
		sort(a,a+n);
		for(i=0;i<n-1;i++)
		{
			b[i]=a[i+1]-a[i];
		}
		sort(b,b+n-1);
		cnt=0;
		for(i=0;i<n-1;i++)
		{
			m-=b[i];
			if(m<0) break;
			cnt++;
		}
		printf("%d\n",cnt+1);
	}
	return 0;
}*/
/*
1 1
10000
2 1
-10000 100000

2 2
10 1

2 1
1 2
3 2
1 2 5
3 2
1 2 3

5 2
5 4 3 2 1

*/