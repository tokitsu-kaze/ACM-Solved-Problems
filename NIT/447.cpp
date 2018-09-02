#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAX=1e5+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	freopen("in.txt","w",stdout);
	int n,q,t=9,maxx=(int)1e5+1,flag,pos,x,i;
	string s[2]={"MODIFY","QUERY"};
	puts("10");
	n=(int)1e5;
	q=(int)1e5;
	printf("%d %d\n",n,q);
	for(i=0;i<n;i++)
	{
		x=(llrand()%maxx);
		printf("%d ",x);
	}
	puts("");
	while(q--)
	{
		flag=1;
		x=(llrand()%maxx);
		cout<<s[flag]<<" "<<x;
		puts("");
	}
	while(t--)
	{
		n=(llrand()%maxx);
		q=(llrand()%maxx);
		printf("%d %d\n",n,q);
		for(i=0;i<n;i++)
		{
			x=(llrand()%maxx);
			printf("%d ",x);
		}
		puts("");
		while(q--)
		{
			flag=rand()%2;
			cout<<s[flag]<<" ";
			if(!flag)
			{
				pos=(llrand()%n)+1;
				printf("%d ",pos);
			}
			x=(llrand()%maxx);
			printf("%d\n",x);
		}
	}
	return 0;
}
*/
/*
int a[MAX];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i,x,y,n,q,now;
	char op[12];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		now=0;
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='M')
			{
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
			else
			{
				scanf("%d",&x);
				int ans=0;
				for(i=1;i<=n;i++)
				{
					a[i]=a[i]^x;
					ans=max(ans,a[i]);
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
*/
struct Trie
{
	int cnt[18*MAX],val[18*MAX];
	void Insert(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]++;
			val[x]=v;
			return;
		}
		Insert((x<<1)|((v>>pos)&1),pos-1,v);
		cnt[x]=cnt[x<<1]+cnt[x<<1|1];
	}
	void Delete(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]--;
			return;
		}
		Delete((x<<1)|((v>>pos)&1),pos-1,v);
		cnt[x]=cnt[x<<1]+cnt[x<<1|1];
	}
	void clear(int x,int pos)
	{
		cnt[x]=0;
		if(pos<0) return;
		clear(x<<1,pos-1);
		clear(x<<1|1,pos-1);
	}
	int query(int x,int pos,int v)
	{
		if(pos<0) return val[x];
		int temp=(v>>pos)&1;
		temp|=x<<1;
		if(cnt[temp^1]) return query(temp^1,pos-1,v);
		return query(temp,pos-1,v);
	}
}Trie;
int a[MAX];
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,i,x,y,n,q,now;
	char op[12];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			Trie.Insert(1,17,a[i]);
		}
		now=0;
		while(q--)
		{
			scanf("%s",op);
			if(op[0]=='M')
			{
				scanf("%d%d",&x,&y);
				Trie.Delete(1,17,a[x]);
				a[x]=now^y;
				Trie.Insert(1,17,a[x]);
			}
			else
			{
				scanf("%d",&x);
				now^=x;
				printf("%d\n",now^Trie.query(1,17,now));
			}
		}
		Trie.clear(1,17);
	}
	return 0;
}