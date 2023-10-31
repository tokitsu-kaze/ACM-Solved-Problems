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
const int MAX=(int)1e5+10;
int a[MAX],b[MAX],n;
int LIS()
{
	int i;
	mem(b,0x3f);
	for(i=0;i<n;i++)
	{
		*upper_bound(b,b+n,a[i])=a[i];
	}
	return lower_bound(b,b+n,INF)-b;
}
int main()
{
	int i;
	while(~scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++) scanf("%d",&a[i]),a[i]*=-1;
		printf("%d\n",LIS());
	}
	return 0;
}