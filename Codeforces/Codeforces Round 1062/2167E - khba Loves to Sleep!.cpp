#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct node
{
	int pos,dir,tar;
	friend bool operator <(node a,node b)
	{
		return abs(a.tar-a.pos)<abs(b.tar-b.pos);
	}
};
int a[MAX];
int main()
{
	int T,n,k,x,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		priority_queue<node> q;
		map<int,int> mp,inq;
		for(i=2;i<=n;i++)
		{
			q.push({(a[i]+a[i-1])/2,-1,a[i-1]});
			q.push({(a[i]+a[i-1]+1)/2,1,a[i]});
		}
		q.push({0,1,a[1]});
		q.push({x,-1,a[n]});
		vector<int> res;
		while(res.size()<k)
		{
			node t=q.top();
			q.pop();
			if(!mp.count(t.pos))
			{
				res.push_back(t.pos);
				mp[t.pos]=1;
			}
			if(t.pos==t.tar) continue;
			t.pos+=t.dir;
			q.push(t);
		}
		for(i=0;i<k;i++) printf("%d%c",res[i]," \n"[i+1==k]);
	}
	return 0;
}
