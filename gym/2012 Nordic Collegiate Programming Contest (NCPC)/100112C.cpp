#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=6e5+10;
const ll mod=1e9+7;
struct Treap  
{  
	int ch[2],v,fix,sz,w;
	Treap(){}
	Treap(int x)
	{
		v=x;
		fix=rand();
		sz=w=1;
		ch[0]=ch[1]=0;
	} 
}t[MAX];  
int tot,root,tmp;  
void maintain(int k)  
{  
	t[k].sz=t[t[k].ch[0]].sz+t[t[k].ch[1]].sz+t[k].w ;  
}  
void Rorate(int &x,int k)
{
	int y=t[x].ch[k^1];
	t[x].ch[k^1]=t[y].ch[k];
	t[y].ch[k]=x;
	maintain(x);
	maintain(y);
	x=y;
}
void Insert(int &x,int v)
{
	if(!x) t[x=++tot]=Treap(v);
	else
	{
		if(t[x].sz++,t[x].v==v)t[x].w++;
		else if(Insert(t[x].ch[tmp=v>t[x].v],v),t[t[x].ch[tmp]].fix>t[x].fix) Rorate(x,tmp^1);
    }
}
void Delete(int &x,int v)
{
	if(!x)return;
	if(t[x].v==v)
	{
		if(t[x].w>1) t[x].w--,t[x].sz--;
		else
		{
			if(!(t[x].ch[0]&&t[x].ch[1])) x=t[x].ch[0]|t[x].ch[1];
			else
			{
				Rorate(x,tmp=t[t[x].ch[0]].fix>t[t[x].ch[1]].fix);
				t[x].sz--;
				Delete(t[x].ch[tmp],v);
			}
		}
	}
	else
	{
		t[x].sz--;
		Delete(t[x].ch[v>t[x].v],v);
	}
}
int Kth(int x,int k)
{
	if(x==0) return 0;  
	if(t[t[x].ch[0]].sz>=k) return Kth(t[x].ch[0],k);
	else if(t[t[x].ch[0]].sz+t[x].w>=k) return t[x].v;
	else return Kth(t[x].ch[1],k-t[t[x].ch[0]].sz-t[x].w);
}   
int main()
{
	int cnt;
	char a[111];
	while(~scanf("%s",a))
	{
		if(a[0]=='#')
		{
			cnt=t[root].sz;
			int ans=Kth(root,cnt/2+1);
			printf("%d\n",ans);
			Delete(root,ans);
		}
		else Insert(root,atoi(a));
	}
	return 0;
}