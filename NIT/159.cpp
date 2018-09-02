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
	int n,t,i;
	while(~scanf("%d",&n))
	{
		if(n<15) puts("So sad!");
		else
		{
			t=1;
			if(n%15==0) printf("%d %d %d %d %d\n",n/15,n/15*2,n/15*3,n/15*4,n/15*5);
			else
			{
				for(i=n/15;i>=1;i--)
				{
					if(n%i==0)
					{
						t=i;
						break;
					}
				}
				printf("%d %d %d %d %d\n",t,t*2,t*3,t*4,n-t*10);
			}
		}
	}
	return 0;
}