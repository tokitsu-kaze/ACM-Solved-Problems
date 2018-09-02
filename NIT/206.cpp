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
int main()
{
	ll t,a,b,c,d;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b) swap(a,b);
		if(__gcd(a,b)!=1)
		{
			puts("NO");
			continue;
		}
		if(a==1||b==1)
		{
			puts("1");
			continue;
		}
		c=a;
		d=b;
		while(abs(c-d)!=1)
		{
			if(c<d) c+=a;
			else d+=b;
		}
		puts("YES");
		printf("%lld\n",c+d);
	}
	return 0;
}
/*
1000
4 47
5 7
3 1000000000
*/