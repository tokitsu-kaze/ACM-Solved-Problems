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
	int i,j,k,w[111],ans,n,flag,res;
	while(~scanf("%d",&n))
	{
		n*=2;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
		}
		sort(w+1,w+n+1);
		ans=INF;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				flag=-1;
				res=0;
				for(k=1;k<=n;k++)
				{
					while(k==i||k==j) k++;
					if(k>n) break;
					res+=w[k]*flag;
					flag*=-1;
				}
				ans=min(ans,res);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}