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
	int n,k,i,ans,a[111],flag,s;
	while(~scanf("%d%d",&n,&k))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		s=ans=0;
		flag=0;
		for(i=1;i<=n;i++)
		{
			s+=a[i];
			if(s>8)
			{
				s-=8;
				ans+=8;
			}
			else
			{
				ans+=s;
				s=0;
			}
			if(ans>=k)
			{
				flag=1;
				printf("%d\n",i);
				break;
			}
		}
		if(!flag) puts("-1");
	}
	return 0;
}