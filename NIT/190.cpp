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
const double eps=1e-5;
const int MAX=1e5+10;
const ll mod=1e6;
ll a[MAX];
ll sum[MAX];
int main()
{
	ll t,n,i,k,c,d,temp;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		mem(a,0);
		mem(sum,0);
		temp=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			temp+=a[i];
			sum[i]=temp;
		}
		scanf("%lld",&k);
		while(k--)
		{
			scanf("%lld%lld",&c,&d);
			printf("%lld\n",sum[d]-sum[c]+a[c]);
		}
	}
	return 0;
}