#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int a[MAX];
int main()
{
	int n,d,i,l;
	ll ans;
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	set<int> s;
	l=1;
	s.insert(-INF);
	s.insert(INF);
	ans=0;
	for(i=1;i<=n;i++)
	{
		while(l<i && (abs(a[i]-*s.lower_bound(a[i]))<d || abs(a[i]-*--s.lower_bound(a[i]))<d))
		{
			s.erase(a[l]);
			l++;
		}
		ans+=i-l;
		s.insert(a[i]);
//		printf("%d %d\n",l,i);
	}
	ans+=n;
	printf("%lld\n",ans);
	return 0;
}
