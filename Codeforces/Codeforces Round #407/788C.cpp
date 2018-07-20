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
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int now,v;
	node(){}
	node(int a,int b):now(a),v(b){}
};
vector<int> v;
bool flag[5111];
int bfs()
{
	int i;
	node t;
	queue<node> q;
	q.push(node(0,0));
	mem(flag,0);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<sz(v);i++)
		{
	//		cout<<t.now<<" "<<v[i]<<endl;
			if(t.now+v[i]<-1000||t.now+v[i]>1000) continue;
			if(t.now+v[i]==0) return t.v+1;
			if(flag[t.now+v[i]+1000]) continue;
			q.push(node(t.now+v[i],t.v+1));
			flag[t.now+v[i]+1000]=1;
		}
	}
	return -1;
}
int main()
{
	int n,k,x;
	while(~scanf("%d%d",&n,&k))
	{
		v.clear();
		while(k--)
		{
			scanf("%d",&x);
			if(!flag[x]) v.pb(n-x);
			flag[x]=1;
		}
		printf("%d\n",bfs());
	}
	return 0;
}