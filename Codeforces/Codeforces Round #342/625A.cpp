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
int main()
{
	ll a,b,c,n,ans;
	while(~scanf("%lld%lld%lld%lld",&n,&a,&b,&c))
	{
		ll temp=b-c;
		ans=0;
		if(a>=temp&&n>=b)
		{
			ans=(n-b)/temp;
			n-=ans*temp;
			ans++;
			n-=temp;
			ans+=n/a;
	//		cout<<n<<endl;
		}
		else ans=n/a;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
12 1 6 5
1 2 6 5
*/