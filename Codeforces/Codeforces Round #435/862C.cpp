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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,x,ans,i,temp;
	while(~scanf("%d%d",&n,&x))
	{
		if(n==2&&x==0)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		if(n<=2)
		{
			if(n==1) printf("%d\n",x);
			else if(n==2) printf("%d %d\n",0,x);
			continue;
		}
		ans=0;
		for(i=1;i<=n-3;i++)
		{
			printf("%d ",i);
			ans^=i;
		}
		temp=1<<17;
		if(ans==x) printf("%d %d %d\n",temp,temp*2,temp*2+temp);
		else printf("%d %d %d\n",0,temp,temp^ans^x);
	}
	return 0;
}