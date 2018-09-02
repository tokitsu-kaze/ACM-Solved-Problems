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
const int MAX=4e5+10;
const ll mod=1e6;
ll a[MAX];
int main()
{
	ll n,k,i,j,res,ans;
	while(~scanf("%lld%lld",&n,&k))
	{
		res=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(j=1;j<=k;j++)
		{
			res+=a[j];
		}
		ans=res;
		for(i=1;i<=n;i++,j++)
		{
			if(j==n+1) j=1;
			res+=a[j];
			res-=a[i];
//			cout<<i<<" "<<j<<endl;
			ans=max(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}