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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int t,n,i,x,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> res;
		if(n&1) res.pb(0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			res.pb(x);
		}
		sort(all(res));
		ans=0;
		for(i=0;i<sz(res);i+=2)
		{
			ans^=(res[i+1]-res[i]-1);
		}
		ans?puts("Georgia will win"):puts("Bob will win");
	}
	return 0;
}