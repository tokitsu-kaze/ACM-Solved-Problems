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
const int MAX=1e3+10;
const ll mod=1e9+7;
struct node
{
	int l,r,len;
}a[MAX];
int main()
{
	int i,n,m,l,r,t,ans,pos;
//	freopen("knockout.in","r",stdin);
//	freopen("knockout.out","w",stdout);
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].l,&a[i].r);
			a[i].len=a[i].r-a[i].l;
		}
		while(m--)
		{
			scanf("%d%d%d",&l,&r,&t);
			ans=0;
			for(i=0;i<n;i++)
			{
				if((t/a[i].len)%2) pos=a[i].r-t%a[i].len;
				else pos=a[i].l+t%a[i].len;
	//			cout<<pos<<endl;
				if(pos>=l&&pos<=r) ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}// gym 100553K
