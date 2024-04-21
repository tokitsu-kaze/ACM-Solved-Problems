#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e3+10;
void ask(vector<int> &res,int &x,int &d)
{
	cout<<"? "<<res.size();
	for(auto &it:res) cout<<" "<<it;
	cout<<endl;
	cin>>x>>d;
}
vector<int> mp[MAX],tmp[MAX];
int mx,h[MAX];
void dfs(int x,int fa)
{
	h[x]=h[fa]+1;
	mx=max(mx,h[x]);
	tmp[h[x]].push_back(x);
	for(auto &to:mp[x])
	{
		if(to==fa) continue;
		dfs(to,x);
	}
}
int main()
{
	int t,n,i,a,b,x,d,l,r,mid,nx,nd;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<=n;i++)
		{
			mp[i].clear();
			tmp[i].clear();
		}
		for(i=1;i<n;i++)
		{
			cin>>a>>b;
			mp[a].push_back(b);
			mp[b].push_back(a);
		}
		vector<int> res;
		for(i=1;i<=n;i++) res.push_back(i);
		ask(res,x,d);
		mx=0;
		h[0]=-1;
		dfs(x,0);
		l=0;
		r=mx;
		while(l<r)
		{
			mid=(l+r)>>1;
			ask(tmp[mid+1],nx,nd);
			if(nd<=d) l=mid+1;
			else r=mid;
		}
		ask(tmp[l],nx,nd);
		for(i=0;i<=n;i++) tmp[i].clear();
		h[0]=-1;
		dfs(nx,0);
		ask(tmp[d],x,nd);
		cout<<"! "<<x<<" "<<nx<<endl;
		string fk;
		cin>>fk;
	}
	return 0;
}
