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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int id;
	double g,a,b,cmp,s;
	void input()
	{
		scanf("%lf%lf%lf",&g,&a,&b);
		if(b==0) cmp=10000;
		else cmp=a/b;
		s=0;
	}
	friend bool operator <(node a,node b)
	{
		return a.cmp>b.cmp;
	}
}a[MAX];
double ans[MAX];
int main()
{
	int i,n;
	double ans1,ans2,A,B;
	freopen("burrito.in","r",stdin);
	freopen("burrito.out","w",stdout);
	while(~scanf("%d%lf%lf",&n,&A,&B))
	{
		for(i=0;i<n;i++)
		{
			a[i].input();
			a[i].id=i;
			ans[i]=0;
		}
		ans1=ans2=0;
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			if(ans2+a[i].g*a[i].b<=B) a[i].s=a[i].g;
			else a[i].s=(B-ans2)/a[i].b;
			ans1+=a[i].s*a[i].a;
			ans2+=a[i].s*a[i].b;
			ans[a[i].id]=a[i].s;
		}
		if(ans1<A)
		{
			puts("-1 -1");
			continue;
		}
		printf("%.6lf %.6lf\n",ans1,ans2);
		for(i=0;i<n;i++)
		{
			if(i==n-1) printf("%.6lf\n",ans[i]);
			else printf("%.6lf ",ans[i]);
		}
	}
	return 0;
}