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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int op,l,r;
	void input()
	{
		scanf("%d%d%d",&op,&l,&r);
	}
}a[MAX];
int x[MAX];
int main()
{
	int n,q,m,i,p;
	while(~scanf("%d%d%d",&n,&q,&m))
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		for(i=1;i<=q;i++)
		{
			a[i].input();
		}
		while(m--)
		{
			scanf("%d",&p);
			for(i=q;i>=1;i--)
			{
				if(a[i].op==1&&p>=a[i].l&&p<=a[i].r)
				{
					p--;
					if(p<a[i].l) p=a[i].r;
				}
				else if(a[i].op==2&&p>=a[i].l&&p<=a[i].r)
				{
					if(p<=(a[i].r-a[i].l+1)/2) p=a[i].r-(p-a[i].l);
					else p=a[i].l+(a[i].r-p);
				}
			}
			if(m) printf("%d ",x[p]);
			else printf("%d\n",x[p]);
		}
	}
	return 0;
}