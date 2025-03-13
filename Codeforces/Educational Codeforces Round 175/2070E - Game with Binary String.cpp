#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
const int mod=998244353;
struct Treap
{
	#define type int
	static const type inf=INF;
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
tr.find_pre(x);
tr.find_nex(x);
tr.upper_bound_count(x); //the count <=key
tr.lower_bound_count(x); //the count <key

n treap
tr.init(n);
tr[i].insert(x);
*/
char s[MAX];
int sum0[MAX],sum1[MAX];
int main()
{
	int n,i;
	ll ans;
	scanf("%d",&n);
	scanf("%s",s+1);
	tr.init();
	map<int,int> mp;
	sum0[0]=sum1[0]=0;
	ans=0;
	for(i=1;i<=n;i++)
	{
		sum0[i]=sum0[i-1];
		sum1[i]=sum1[i-1];
		if(s[i]=='0') sum0[i]++;
		else sum1[i]++;
		ans+=tr.upper_bound_count(sum0[i]-sum1[i]*3);
		tr.insert(sum0[i-1]-sum1[i-1]*3+2);
		if(mp.count(sum0[i]-sum1[i]*3)) ans+=mp[sum0[i]-sum1[i]*3];
		mp[sum0[i-1]-sum1[i-1]*3-1]++;
//		printf("%d %lld\n",i,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
[l,r] cnt0{l..r}>=cnt1{l..r}*3+2
sum0[r]-sum0[l-1]>=sum1[r]*3-sum1[l-1]*3+2
sum0[r]-sum1[r]*3>=sum0[l-1]-sum1[l-1]*3+2

[l,r] cnt0{l..r}=cnt1{l..r}*3-1
sum0[r]-sum0[l-1]=sum1[r]*3-sum1[l-1]*3-1
sum0[r]-sum1[r]*3=sum0[l-1]-sum1[l-1]*3-1


3
101

3
100

00011

0000011

000011

00
001
000001

1100000000
cnt1*3-1
cnt1*3+2
*/
