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
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=2e6+10;
const ll mod=1e9+7;
int main()
{
	int n,i;
	char a[111];
	while(~scanf("%d",&n))
	{
		map<string,int> mp;
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			if(mp[a]) puts("YES");
			else puts("NO");
			mp[a]++;
		}
	}
	return 0;
}