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
const int MAX=1e3+10;
const ll mod=1e9+6;
int main()
{
	ll a,b,c,d,e,f,x,y,z;
	while(~scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f))
	{
		x=a*1000/d;
		y=b*1000/e;
		z=c/f;
	//	cout<<x<<" "<<y<<" "<<z<<endl;
		printf("%lld\n",min(x,min(y,z)));
	}
	return 0;
}