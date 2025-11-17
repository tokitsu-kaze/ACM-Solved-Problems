#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct node{int a,b;}v[MAX];
int sufmx[MAX];
int main()
{
	int T,n,i,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&v[i].a,&v[i].b);
	sort(v+1,v+1+n,[](node x,node y){
		return x.a<y.a;
	});
	sufmx[n+1]=0;
	for(i=n;i;i--) sufmx[i]=max(sufmx[i+1],v[i].b);
	ans=2e9;
	set<int> s;
	for(i=1;i<=n;i++)
	{
		auto it=s.upper_bound(v[i].a);
		if(it!=s.begin()) ans=min(ans,abs(v[i].a-max(sufmx[i+1],*--it)));
		it=s.lower_bound(v[i].a);
		if(it!=s.end()) ans=min(ans,abs(v[i].a-max(sufmx[i+1],*it)));
		if(i+1<=n) ans=min(ans,abs(v[i].a-sufmx[i+1]));
		s.insert(v[i].b);
	}
	printf("%d\n",ans);
	return 0;
}
