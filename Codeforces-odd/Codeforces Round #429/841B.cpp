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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,i,cnt1,cnt2;
	while(~scanf("%d",&n))
	{
		cnt1=cnt2=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]%2) cnt1++;
			else cnt2++;
		}
		if(cnt1) puts("First");
		else puts("Second");
	}
	return 0;
}