#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Trie
{
	#define type int
	static const int LOG=30;
	static const int K=LOG+2;
	static const type inf=INF;
	int rt,root[MAX],tot,ch[MAX*K][2],mx[MAX*K];
	Trie &operator[](const int _rt){this->rt=_rt;return *this;}
	int newnode()
	{
		tot++;
		memset(ch[tot],0,sizeof ch[tot]);
		mx[tot]=-inf;
		return tot;
	}
	void init(int n=1)
	{
		ch[0][0]=ch[0][1]=0;
		mx[0]=-inf;
		tot=1;
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
	}
	void insert(type x,int pos)
	{
		int id,t,i;
		if(!root[rt]) root[rt]=newnode();
		id=root[rt];
		for(i=LOG;~i;i--)
		{
			mx[id]=max(mx[id],pos);
			t=(x>>i)&1;
			if(!ch[id][t]) ch[id][t]=newnode();
			id=ch[id][t];
		}
		mx[id]=max(mx[id],pos);
	}
	int ask(type x,type limt)
	{
		int id,i;
		type res,t;
		if(!root[rt]) return -inf;
		id=root[rt];
		res=-inf;
		for(i=LOG;~i;i--)
		{
			t=(x>>i)&1;
			if(!((limt>>i)&1))
			{
				res=max(res,mx[ch[id][!t]]);
				id=ch[id][t];
			}
			else id=ch[id][!t];
		}
		res=max(res,mx[id]);
		return res;
	}
	#undef type
}tr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T,n,k,i,x,now,ans,l,r,res;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		tr.init();
		tr.insert(0,1);
		ans=INF;
		now=0;
		for(i=1;i<=n;i++)
		{
			cin>>x;
			now^=x;
			tr.insert(now,i+1);
			res=tr.ask(now,k);
			if(res>0 && res<=i)
			{
				if(i-res+1<ans)
				{
					ans=i-res+1;
					l=res;
					r=i;
				}
			}
		}
		if(ans==INF) cout<<"-1"<<"\n";
		else cout<<l<<" "<<r<<"\n";
	}
	return 0;
}

