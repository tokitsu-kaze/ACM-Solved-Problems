#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=3e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i;
	char a[21];
	while(~scanf("%d",&n))
	{
		mem(a,0);
		for(i=0;i<n*2;i++)
		{
			a[i]='9';
		}
		a[n-1]='8';
		puts(a);
		swap(a[n-1],a[2*n-1]);
		puts(a);
	}
	return 0;
}