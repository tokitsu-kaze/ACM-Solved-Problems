#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=5e5+10;
struct node{int l,r;};
int main()
{
	int n,i,l,r;
	ll ans;
	scanf("%d",&n);
	vector<node> res;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&l,&r);
		res.push_back({l,r});
	}
	sort(res.begin(),res.end(),[](node x,node y){
		return x.l<y.l;
	});
	ans=0;
	priority_queue<int> q;
	for(auto &it:res)
	{
		while(!q.empty()&&-q.top()<it.l) q.pop();
		ans+=q.size();
		q.push(-it.r);
	}
	printf("%lld\n",ans);
	return 0;
}
