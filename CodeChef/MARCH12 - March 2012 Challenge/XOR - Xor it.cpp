#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
struct Trie
{
	#define type int
	static const int LOG=31;
	static const int K=LOG+2;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[MAX*K][2],cnt[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		cnt[tot]=0;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=cnt[0]=0;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			cnt[id]++;
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		cnt[id]++;
	}
	type ask_min(int now,type x)
	{
		int id,i;
		type res,t;
		if(!root[rt]) return inf;
		id=root[rt];
		res=0;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!ch[id][t] || cnt[ch[id][t]]<now)
			{
				now-=cnt[ch[id][t]];
				t^=1;
			}
			res|=(t<<i);
			id=ch[id][t];
		}
		return res^x;
	}
	#undef type
}tr;
struct node
{
	int v,x,now;
	friend bool operator<(node a,node b)
	{
		return a.v>b.v;
	}
};
int a[MAX];
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	priority_queue<node> q;
	tr.init();
	for(i=1;i<=n;i++) tr.insert(a[i]);
	for(i=1;i<=n;i++) q.push({tr.ask_min(2,a[i]),a[i],2});
	vector<int> res;
	for(i=1;i<=2*k;i++)
	{
		node t=q.top();
		q.pop();
		if(i&1) res.push_back(t.v);
		if(t.now+1<=n) q.push({tr.ask_min(t.now+1,t.x),t.x,t.now+1});
	}
	for(i=0;i<k;i++) printf("%d%c",res[i]," \n"[i+1==k]);
	return 0;
}
/*
4 5
7 5 3 2
*/
