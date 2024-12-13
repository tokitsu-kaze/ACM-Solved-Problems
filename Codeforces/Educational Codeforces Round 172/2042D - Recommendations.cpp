#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node{int l,r,id;}a[MAX];
int l[MAX],r[MAX];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i].l,&a[i].r);
			a[i].id=i;
			l[i]=INF;
			r[i]=0;
		}
		sort(a+1,a+1+n,[&](node x,node y){
			return x.l<y.l;
		});
		multiset<int> s;
		for(i=1,j=1;i<=n;i++)
		{
			while(j<=n && a[j].l==a[i].l) s.insert(a[j++].r);
			s.erase(s.find(a[i].r));
			auto it=s.lower_bound(a[i].r);
			if(it!=s.end()) r[a[i].id]=*it;
			s.insert(a[i].r);
		}
		
		sort(a+1,a+1+n,[&](node x,node y){
			return x.r>y.r;
		});
		s.clear();
		for(i=1,j=1;i<=n;i++)
		{
			while(j<=n && a[j].r==a[i].r) s.insert(a[j++].l);
			s.erase(s.find(a[i].l));
			auto it=s.upper_bound(a[i].l);
			if(it!=s.begin()) l[a[i].id]=*(--it);
			s.insert(a[i].l);
		}
		
		sort(a+1,a+1+n,[&](node x,node y){
			return x.id<y.id;
		});
		for(i=1;i<=n;i++)
		{
//			printf("%d %d\n",l[i],r[i]);
			printf("%d\n",max(0,r[i]-l[i]+1-(a[i].r-a[i].l+1)));
		}
	}
	return 0;
}
