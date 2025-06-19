#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
struct Treap
{
	#define type pair<int,int>
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v;
		node(){}
		node(type x,int _sz)
		{
			v=x;
			fix=rand();
			sz=cnt=_sz;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];
	int tot,root[MAX],rt;
	void init(int n=1)
	{
		for(int i=0;i<=n;i++) root[i]=0;
		rt=1;
		srand(time(0));
		tot=0;
		t[0].sz=t[0].cnt=0;
		memset(t[0].ch,0,sizeof t[0].ch);
	}
	void pushup(int id)  
	{  
		t[id].sz=t[t[id].ch[0]].sz+t[t[id].ch[1]].sz+t[id].cnt;
	}
	void rotate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		pushup(id);
		pushup(y);
		id=y;
	}
	void _insert(int &id,type v,int cnt)
	{
		if(!id)
		{
			id=++tot;
			t[id]=node(v,cnt);
			return;
		}
		if(t[id].v==v) t[id].cnt+=cnt;
		else
		{
			int tmp=(v>t[id].v);
			_insert(t[id].ch[tmp],v,cnt);
			if(t[t[id].ch[tmp]].fix>t[id].fix) rotate(id,tmp^1);
		}
		pushup(id);
	}
	void _erase(int &id,type v,int cnt)
	{
		if(!id) return;
		if(t[id].v==v)
		{
			cnt=min(t[id].cnt,cnt);
			if(t[id].cnt>cnt)
			{
				t[id].cnt-=cnt;
				pushup(id);
				return;
			}
			if(!(t[id].ch[0]&&t[id].ch[1]))
			{
				id=t[id].ch[0]+t[id].ch[1];
				return;
			}
			else
			{
				int tmp=(t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
				rotate(id,tmp);
				_erase(t[id].ch[tmp],v,cnt);
				pushup(id);
			}
		}
		else
		{
			_erase(t[id].ch[v>t[id].v],v,cnt);
			pushup(id);
		}
	}
	int _find(type key,int f)
	{
		int id=root[rt],res=0;
		while(id)
		{
			if(t[id].v<=key)
			{
				res+=t[t[id].ch[0]].sz+t[id].cnt;
				if(f&&key==t[id].v) res-=t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	int count(type key)
	{
		int id=root[rt];
		while(id)
		{
			if(t[id].v<key)
			{
				if(key==t[id].v) return t[id].cnt;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return 0;
	}
	Treap &operator[](const int _rt){this->rt=_rt;return *this;}
	void insert(type v,int sz=1){_insert(root[rt],v,sz);}
	void erase(type v,int sz=1){_erase(root[rt],v,sz);}
	int upper_bound_count(type key){return _find(key,0);}//the count <=key
	int lower_bound_count(type key){return _find(key,1);}//the count <key
	int order_of_key(type key){return lower_bound_count(key)+1;}
	int size(){return t[root[rt]].sz;}
	#undef type
}tr;
typedef unsigned int ui ;
ui randNum( ui& seed , ui last , const ui m){ 
    seed = seed * 17 + last ; return seed % m + 1; 
}
int cnt[MAX],sum[MAX];
int main()
{
	int T,m,n,i,ans,x,y;
	ui seed;
	ans=7;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%u",&m,&n,&seed);
		tr.init();
		for(i=1;i<=m;i++)
		{
			tr.insert({0,0});
			cnt[i]=sum[i]=0;
		}
		while(n--)
		{
			x=randNum(seed,ans,m);
			y=randNum(seed,ans,m);
			tr.erase({-cnt[x],sum[x]});
			cnt[x]++;
			sum[x]+=y;
			tr.insert({-cnt[x],sum[x]});
			ans=tr.lower_bound_count({-cnt[x],sum[x]});
			printf("%d\n",ans);
		}
	}
	return 0;
}
