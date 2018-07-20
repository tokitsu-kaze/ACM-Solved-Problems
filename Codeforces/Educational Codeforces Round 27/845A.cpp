#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=5e4+10;
const ll mod=1e9+7;
int main()
{
	int n,i,a[211],x,tag;
	while(~scanf("%d",&n))
	{
		n*=2;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		if(a[n/2]==a[n/2-1]) puts("NO");
		else puts("YES");
	}
	return 0;
}
/*
1
3 3
2
1 3 2 4
*/