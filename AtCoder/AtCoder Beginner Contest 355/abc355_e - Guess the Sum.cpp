#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=(1<<18)+10;
vector<int> mp[MAX];
int vis[MAX],pre[MAX];
void init(int n)
{
	int i,j;
	for(i=0;i<=(1<<n);i++) mp[i].clear();
	for(i=0;i<=n;i++)
	{
		for(j=0;j+(1<<i)<=(1<<n);j+=(1<<i))
		{
			mp[j].push_back(j+(1<<i));
			mp[j+(1<<i)].push_back(j);
		}
	}
}
void bfs(int s,int t,int n)
{
	memset(vis,0,sizeof vis);
	memset(pre,0x3f,sizeof pre);
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==t) return;
		for(auto &to:mp[x])
		{
			if(!vis[to])
			{
				q.push(to);
				pre[to]=x;
				vis[to]=1;
			}
		}
	}
}
int main()
{
	int n,l,r,ans,x,sgn;
	cin>>n>>l>>r;
	init(n);
	r++;
	bfs(l,r,n);
	vector<int> res;
	while(r!=l)
	{
		assert(pre[r]!=INF);
		res.push_back(r);
		r=pre[r];
	}
	reverse(res.begin(),res.end());
	ans=0;
	for(auto &it:res)
	{
		if(it-l<0) sgn=-1;
		else sgn=1;
		x=__lg(abs(it-l));
		cout<<"? "<<x<<" "<<min(l,it)/(1<<x)<<endl;
		cin>>x;
		ans=(ans+sgn*x+100)%100;
		l=it;
	}
	cout<<"! "<<ans<<endl;
	return 0;
}


