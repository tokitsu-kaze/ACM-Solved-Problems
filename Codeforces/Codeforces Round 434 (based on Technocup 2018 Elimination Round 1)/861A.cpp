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
	ll n,k,cnt2,cnt5,temp,ans;
	while(~scanf("%lld%lld",&n,&k))
	{
		temp=n;
		cnt2=cnt5=0;
		while(temp%2==0)
		{
			temp/=2;
			cnt2++;
		}
		while(temp%5==0)
		{
			temp/=5;
			cnt5++;
		}
		while(cnt2>0&&cnt5>0)
		{
			k--;
			cnt2--;
			cnt5--;
		}
		ans=1;
		while(k>0&&(cnt2>0||cnt5>0))
		{
			if(cnt2)
			{
				cnt2--;
				ans*=5;
			}
			else if(cnt5)
			{
				cnt5--;
				ans*=2;
			}
			k--;
		}
		printf("%lld",ans*n);
		while(k>0)
		{
			printf("0");
			k--;
		}
		puts("");
	}
	return 0;
}