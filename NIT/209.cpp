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
const int MAX=1e5+10;
const ll mod=1e6;
ll n,i,a[MAX],b[MAX],flag[MAX],cnt;
int main()
{
	
	while(~scanf("%lld",&n))
	{
		map<ll,ll> mp;
		mem(flag,0);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			b[i]=a[i];
			mp[a[i]]=i;
		}
		sort(b+1,b+1+n);
		cnt=0;
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				int pos=i;
				while(!flag[pos])
				{
					flag[pos]=1;
					pos=mp[b[pos]];
					if(!flag[pos]) cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
/*
3
3 1 2
2
2 1
*/