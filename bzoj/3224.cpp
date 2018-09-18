#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define len(x) (int) x.length()
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct treap
{
	#define type ll
	struct Treap  
	{
		int ch[2],fix,sz,w;
		type v;
		Treap(){}
		Treap(type x)
		{
			v=x;
			fix=rand();
			sz=w=1;
			ch[0]=ch[1]=0;
		} 
	}t[MAX];  
	int tot,root,tmp;
	void init()
	{
		srand(unsigned(new char));
		root=tot=0;
		t[0].sz=t[0].w=0;
		mem(t[0].ch,0);
	}
	inline void maintain(int k)  
	{  
		t[k].sz=t[t[k].ch[0]].sz+t[t[k].ch[1]].sz+t[k].w ;  
	}  
	inline void rorate(int &id,int k)
	{
		int y=t[id].ch[k^1];
		t[id].ch[k^1]=t[y].ch[k];
		t[y].ch[k]=id;
		maintain(id);
		maintain(y);
		id=y;
	}
	void insert(int &id,type v)
	{
		if(!id) t[id=++tot]=Treap(v);
		else
		{
			if(t[id].sz++,t[id].v==v)t[id].w++;
			else if(insert(t[id].ch[tmp=v>t[id].v],v),t[t[id].ch[tmp]].fix>t[id].fix) rorate(id,tmp^1);
	    }
	}
	void erase(int &id,type v)
	{
		if(!id)return;
		if(t[id].v==v)
		{
			if(t[id].w>1) t[id].w--,t[id].sz--;
			else
			{
				if(!(t[id].ch[0]&&t[id].ch[1])) id=t[id].ch[0]|t[id].ch[1];
				else
				{
					rorate(id,tmp=t[t[id].ch[0]].fix>t[t[id].ch[1]].fix);
					t[id].sz--;
					erase(t[id].ch[tmp],v);
				}
			}
		}
		else
		{
			t[id].sz--;
			erase(t[id].ch[v>t[id].v],v);
		}
	}
	type kth(int k)//k small
	{
		int id=root;
		if(id==0) return 0;
		while(id)
		{
			if(t[t[id].ch[0]].sz>=k) id=t[id].ch[0];
			else if(t[t[id].ch[0]].sz+t[id].w>=k) return t[id].v;
			else
			{
				k-=t[t[id].ch[0]].sz+t[id].w;
				id=t[id].ch[1];
			}
		}
	}
	int find(type key,int f)
	{
		int id=root,res=0;
		while(id)
		{
			if(t[id].v<=key)
			{
				res+=t[t[id].ch[0]].sz+t[id].w;
				if(f&&key==t[id].v) res-=t[id].w;
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_pre(type key)
	{
		type res=-LLINF;
		int id=root;
		while(id)
		{
			if(t[id].v<key)
			{
				res=max(res,t[id].v);
				id=t[id].ch[1];
			}
			else id=t[id].ch[0];
		}
		return res;
	}
	type find_suc(type key)
	{
		type res=LLINF;
		int id=root;
		while(id)
		{
			if(t[id].v>key)
			{
				res=min(res,t[id].v);
				id=t[id].ch[0];
			}
			else id=t[id].ch[1];
		}
		return res;
	}
	void insert(type v){insert(root,v);}
	void erase(type v){erase(root,v);}
	int upper_bound_count(type key){return find(key,0);}//the count >=key
	int lower_bound_count(type key){return find(key,1);}//the count >key
	int rank(type key){return lower_bound_count(key)+1;}
	#undef type
}t;
void go()
{
	int n,op;
	ll x;
	while(~scanf("%d",&n))
	{
		t.init();
		while(n--)
		{
			scanf("%d%lld",&op,&x);
			if(op==1) t.insert(x);
			else if(op==2) t.erase(x);
			else if(op==3) printf("%d\n",t.rank(x));
			else if(op==4) printf("%lld\n",t.kth(x));
			else if(op==5) printf("%lld\n",t.find_pre(x));
			else if(op==6) printf("%lld\n",t.find_suc(x));
		}
	}
}