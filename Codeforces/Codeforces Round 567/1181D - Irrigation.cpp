#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
struct Treap
{
	#define type int
	static const type inf=INF;
	struct node
	{
		int ch[2],fix,sz,cnt;
		type v,sum;
		node(){sum=0;}
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
		t[id].sum=t[t[id].ch[0]].sum+t[t[id].ch[1]].sum+t[id].v*t[id].cnt;
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
		if(t[id].v==v)
		{
			t[id].cnt+=cnt;
			t[id].sum+=t[id].v*cnt;
		}
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
				t[id].sum-=t[id].v*cnt;
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
	type find_by_order(int k)//k small
	{
		int id=root[rt];
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				id=t[id].ch[1];
			}
		}
		return 0;
	}
	type kth_sum(int k)//k small
	{
		type res=0;
		int id=root[rt];
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].cnt>=k)
			{
				res+=t[t[id].ch[0]].sum;
				k-=t[t[id].ch[0]].sz;
				res+=t[id].v*k;
				return res;
			}
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].cnt;
				res+=t[t[id].ch[0]].sum+t[id].v*t[id].cnt;
				id=t[id].ch[1];
			}
		}
		return 0;
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
	type find_pre(type key)
	{
		type res=-inf;
		int id=root[rt];
		while(id)
		{
			if(t[id].v<key)
			{
				res=t[id].v;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_nex(type key)
	{
		type res=inf;
		int id=root[rt];
		while(id)
		{
			if(t[id].v>key)
			{
				res=t[id].v;
				id=t[id].ch[0];
			}
			else id=t[id].ch[1];
		}
		return res;
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
/*
1 treap
tr.init();
tr.insert(x);
tr.erase(x);
tr.count(x);
tr.order_of_key(x); // rank
tr.find_by_order(k); // kth
tr.kth_sum(k); // sum{1..kth}
tr.find_pre(x);
tr.find_nex(x);
tr.upper_bound_count(x); //the count <=key
tr.lower_bound_count(x); //the count <key

n treap
tr.init(n);
tr[i].insert(x);
*/
int ans[MAX],cnt[MAX],v[MAX],rk[MAX],a[MAX];
int main()
{
	int n,m,q,i,j,sum,id;
	ll x,now;
	scanf("%d%d%d",&n,&m,&q);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(i=1;i<=m;i++) v[i]=cnt[i];
	sort(v+1,v+1+m);
	vector<pair<ll,int>> pre;
	sum=0;
	for(i=1;i<=m;i++)
	{
		sum+=v[i];
		pre.push_back({1LL*v[i]*i-sum,i});
	}
	for(i=1;i<=m;i++) rk[i]=i;
	sort(rk+1,rk+1+m,[&](int a,int b){
		if(cnt[a]==cnt[b]) return a<b;
		return cnt[a]<cnt[b];
	});
	vector<pair<ll,int>> qst;
	for(i=1;i<=q;i++)
	{
		scanf("%lld",&x);
		if(x<=n) ans[i]=a[x];
		else qst.push_back({x-n,i});
	}
	sort(qst.begin(),qst.end());
	j=0;
	tr.init();
	for(auto &it:qst)
	{
		x=it.first;
		id=it.second;
		while(j<pre.size() && x>pre[j].first)
		{
			j++;
			tr.insert(rk[j]);
		}
		now=(x-pre[j-1].first)%pre[j-1].second;
		if(now==0) now=pre[j-1].second;
		ans[id]=tr.find_by_order(now);
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
