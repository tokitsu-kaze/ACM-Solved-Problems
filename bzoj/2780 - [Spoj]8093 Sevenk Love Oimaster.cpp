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
#include <bitset>
#include <limits>
#include <assert.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
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
struct Suffix_Automaton
{
	static const int N=MAX<<1;
	static const int K=26;// char size: [0,25]
	int tot,last,nex[N][K],fa[N],len[N],cnt[N],maxlen;
	int vis[N];
	int newnode()
	{
		tot++;
		fa[tot]=len[tot]=cnt[tot]=0;
		vis[tot]=0;
		mem(nex[tot],0);
		return tot;
	}
	void init()
	{
		fa[0]=len[0]=cnt[0]=0;
		mem(nex[0],0);
		tot=0;
		maxlen=0;
		last=newnode();
	}
	void add(int x)
	{
		int p,q,np,nq;
		p=last;
		np=last=newnode();
		len[np]=len[p]+1;
		maxlen=max(maxlen,len[np]);
		while(p&&!nex[p][x])
		{
			nex[p][x]=np;
			p=fa[p];
		}
		if(p==0) fa[np]=1;
		else
		{
			q=nex[p][x];
			if(len[q]==len[p]+1) fa[np]=q;
			else
			{
				nq=newnode();
				memcpy(nex[nq],nex[q],sizeof(nex[q]));
				len[nq]=len[p]+1;
				maxlen=max(maxlen,len[nq]);
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				while(p&&nex[p][x]==q)
				{
					nex[p][x]=nq;
					p=fa[p];
				}
			}
		}
	}
}sam;// sam.init();
string s[MAX];
char ss[MAX];
void go()
{
	int n,q,i,j,len,now,tmp;
	ll ans;
	scanf("%d%d",&n,&q);
	sam.init();
	for(j=1;j<=n;j++)
	{
		cin>>s[j];
		len=sz(s[j]);
		sam.last=1;
		for(i=0;i<len;i++) sam.add(s[j][i]-'a');
	}
	for(j=1;j<=n;j++)
	{
		now=1;
		len=sz(s[j]);
		for(i=0;i<len;i++)
		{
			now=sam.nex[now][s[j][i]-'a'];
			tmp=now;
			while(sam.vis[tmp]!=j&&tmp)
			{
				sam.cnt[tmp]++;
				sam.vis[tmp]=j;
				tmp=sam.fa[tmp];
			}
		}
	}
	while(q--)
	{
		ans=0;
		scanf("%s",ss+1);
		len=strlen(ss+1);
		now=1;
		for(i=1;i<=len;i++)
		{
			now=sam.nex[now][ss[i]-'a'];
		}
		printf("%d\n",sam.cnt[now]);
	}
}
