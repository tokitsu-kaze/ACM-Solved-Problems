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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,ans,now;
	char a[333];
	while(~scanf("%d",&n))
	{
		getchar();
		gets(a);
		ans=0;
		now=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>='A'&&a[i]<='Z')
			{
				now++;
			}
			if(a[i]==' ')
			{
				ans=max(ans,now);
				now=0;
			}
		}
		ans=max(ans,now);
		printf("%d\n",ans);
	}
	return 0;
}