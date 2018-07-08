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
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
bool flag[MAX];
int prime[MAX],mo[MAX],cnt;
void mobius(int n)
{
	int i,j;
	cnt=0;
	mo[1]=1;
	for(i=2;i<=n;i++)
	{
		if(!flag[i])
		{
			prime[cnt++]=i;
			mo[i]=-1;
        }
		for(j=0;j<cnt&&i*prime[j]<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				mo[i*prime[j]]=0;
				break;
			}
			else mo[i*prime[j]]=-mo[i];
		}
	}
}
int main()
{
	int t,i,n,m;
	ll ans;
	mobius(MAX);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ans=0;
		for(i=1;i<=min(n,m);i++)
		{
			ans+=(ll)mo[i]*(n/i)*(m/i);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}