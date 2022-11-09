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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	char s[7];
	int i,a[7],now,ans;
	while(~scanf("%s",s))
	{
		ans=INF;
		for(a[0]=0;a[0]<10;a[0]++)
		{
			for(a[1]=0;a[1]<10;a[1]++)
			{
				for(a[2]=0;a[2]<10;a[2]++)
				{
					for(a[3]=0;a[3]<10;a[3]++)
					{
						for(a[4]=0;a[4]<10;a[4]++)
						{
							for(a[5]=0;a[5]<10;a[5]++)
							{
								if(a[0]+a[1]+a[2]!=a[3]+a[4]+a[5]) continue;
								now=0;
								for(i=0;i<6;i++)
								{
									now+=s[i]!=a[i]+'0';
								}
								ans=min(ans,now);
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}