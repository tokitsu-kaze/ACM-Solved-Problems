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
int sum;
struct Trie
{
	int cnt[20*MAX];
	void Insert(int x,int pos,int v)
	{
		if(pos<0)
		{
			cnt[x]=1;
			return;
		}
		Insert((x<<1)|((v>>pos)&1),pos-1,v);
		cnt[x]=cnt[x<<1]+cnt[x<<1|1];
	}
	int query(int x,int pos,int v)
	{
		if(pos<0) return v;
		int temp=(sum>>pos)&1;
		temp|=x<<1;
		if(cnt[temp]<(1<<pos)) return query(temp,pos-1,v);
		return query(temp^1,pos-1,v|(1<<pos));
	}
}Trie;
int main()
{
	int n,m,x,i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			Trie.Insert(1,19,x);
		}
		sum=0;
		while(m--)
		{
			scanf("%d",&x);
			sum^=x;
			printf("%d\n",Trie.query(1,19,0));
		}
	}
	return 0;
}