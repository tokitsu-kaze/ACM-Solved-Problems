#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
struct node{int x,y;}a[MAX];
int main()
{
	int n,i,t,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&t,&x);
		a[i]={t+x,t-x};
	}
	sort(a+1,a+1+n,[](node a,node b){
		if(a.x==b.x) return a.y<b.y;
		return a.x<b.x;
	});
	multiset<int> s;
	for(i=1;i<=n;i++)
	{
		auto it=s.upper_bound(a[i].y);
		if(it!=s.begin()) s.erase(--it);
		s.insert(a[i].y);
	}
	printf("%d\n",(int)s.size());
	return 0;
}
