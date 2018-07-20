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
const int MAX=2e5+10;
const ll mod=1e9+7;
struct node
{
	int id,v;
}a[MAX],b[MAX],c[MAX],d[MAX];
bool cmp1(node a,node b)
{
	return a.v<b.v;
}
bool cmp2(node a,node b)
{
	return a.v>b.v;
}
int ans[MAX];
bool flag[MAX];
int main()
{
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].v);
			a[i].id=i;
			c[i]=a[i];
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i].v);
			b[i].id=i;
			d[i]=b[i];
		}
		sort(c,c+n,cmp1);
		sort(d,d+n,cmp2);
		mem(flag,0);
		j=0;
		for(i=0;i<n;i++)
		{
			while(c[j].v<d[i].v||flag[j])
			{
				j++;
				if(j==n) j=0;
			}
			ans[d[i].id]=c[j].v;
			flag[j]=1;
		}
		for(i=0;i<n;i++)
		{
			if(i==n-1) printf("%d\n",ans[i]);
			else printf("%d ",ans[i]);
		}
	}
	return 0;
}