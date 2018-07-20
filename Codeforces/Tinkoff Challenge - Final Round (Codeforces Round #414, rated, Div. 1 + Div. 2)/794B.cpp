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
const int MAX=5e4+10;
const ll mod=1e9+7;
int main()
{
	int n,h,i;
	double ans[1010],s;
	while(~scanf("%d%d",&n,&h))
	{
		for(i=1;i<n;i++)
		{
			ans[i]=sqrt((i*1.0/n)*h*h);
			if(i==1) printf("%.10lf",ans[i]);
			else printf(" %.10lf",ans[i]);
		}
		puts("");
	}
	return 0;
}