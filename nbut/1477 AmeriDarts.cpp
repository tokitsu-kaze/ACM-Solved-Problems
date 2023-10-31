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
const ll mod=1e9+7;
int main()
{
	int n,m,i,j,a[1010],b[1010],ans;
	while(~scanf("%d%d",&n,&m))
	{
		ans=INF;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=0;i<m;i++) scanf("%d",&b[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				ans=min(ans,abs(a[i]-b[j]));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}