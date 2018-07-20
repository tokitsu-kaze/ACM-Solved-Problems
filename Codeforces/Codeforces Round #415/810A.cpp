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
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int n,k,a[111],ans,s,i;
	while(~scanf("%d%d",&n,&k))
	{
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s+=a[i];
		}
		ans=0;
		while(s*1.0/(ans+n)<k-0.5)
		{
			s+=k;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}