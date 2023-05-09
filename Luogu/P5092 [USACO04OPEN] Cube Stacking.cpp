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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int pre[MAX],cnt[MAX],s[MAX];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
		cnt[i]=0;
		s[i]=1;
	}
}
int find(int x)
{
	if(pre[x]==x) return pre[x];
	int t=pre[x];
	pre[x]=find(pre[x]);
	cnt[x]+=cnt[t];
	return pre[x];
}
void merge(int a,int b)
{
	int ra,rb;
	ra=find(a);
	rb=find(b);
	if(ra!=rb)
	{
		pre[ra]=rb;
		cnt[ra]=s[rb];
		s[rb]+=s[ra];
	}
}
int main()
{
	int n,x,y;
	char op[11];
	while(~scanf("%d",&n))
	{
		init(30000);
		while(n--)
		{
			scanf("%s%d",op,&x);
			if(op[0]=='M')
			{
				scanf("%d",&y);
				merge(x,y);
			}
			else printf("%d\n",cnt[find(x),x]);
		}
	}
	return 0;
}
