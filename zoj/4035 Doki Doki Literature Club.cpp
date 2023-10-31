#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
typedef long long ll;
struct node
{
	string s;
	ll v;
	int id;
	friend bool operator<(node a,node b)
	{
		if(a.v==b.v) return a.s>b.s;
		return a.v<b.v;
	}
	void input(int i)
	{
		id=i;
		cin>>s;
		scanf("%lld",&v);
	}
}a[111];
int main()
{
	int t,n,i,m;
	ll ans;
	node tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		priority_queue<node> q;
		for(i=1;i<=n;i++)
		{
			a[i].input(i);
			q.push(a[i]);
		}
		vector<string> res;
		ans=0;
		for(;m;m--)
		{
			tmp=q.top();
			q.pop();
			ans+=tmp.v*m;
			res.push_back(tmp.s);
		}
		printf("%lld",ans);
		for(i=0;i<res.size();i++)
		{
			cout<<" "<<res[i];
		}
		puts("");
	}
	return 0;
}