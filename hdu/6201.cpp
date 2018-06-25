////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-12 00:14:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6201
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:12208KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct FastIO  
{  
	static const int S=200;  
	int wpos;  
	char wbuf[S];  
	FastIO():wpos(0){}  
	inline int xchar()  
	{  
		static char buf[S];  
		static int len=0,pos=0;  
		if(pos==len) pos=0,len=fread(buf,1,S,stdin);  
		if(pos==len) exit(0);  
		return buf[pos++];  
	}  
	inline int read()  
	{  
		int s=1,c=xchar(),x=0;  
		while(c<=32) c=xchar();  
		if(c=='-') s=-1,c=xchar();  
		for(;'0'<=c&&c<='9';c=xchar()) x=x*10+c-'0';  
		return x*s;  
	}  
	~FastIO()  
	{  
		if(wpos) fwrite(wbuf,1,wpos,stdout),wpos=0;  
	}  
}io;
struct node
{
	int id,v;
	node(){}
	node(int a,int b)
	{
		id=a;
		v=b;
	}
};
vector<node> mp[MAX];
int v[MAX],outmax[MAX],inmin[MAX],ans;
void dfs(int x,int pre)
{
	int i;
	outmax[x]=inmin[x]=v[x];
	for(i=0;i<sz(mp[x]);i++)
	{
		if(mp[x][i].id!=pre)
		{
			dfs(mp[x][i].id,x);
			outmax[x]=max(outmax[x],outmax[mp[x][i].id]-mp[x][i].v);
			inmin[x]=min(inmin[x],inmin[mp[x][i].id]+mp[x][i].v);
		}
	}
	ans=max(ans,outmax[x]-inmin[x]);
}
int main()
{
	int t,n,i,a,b,c;
	t=io.read();
	while(t--)
	{
		n=io.read();
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			outmax[i]=0;
			inmin[i]=INF;
			v[i]=io.read();
		}
		for(i=1;i<=n-1;i++)
		{
			a=io.read();
			b=io.read();
			c=io.read();
			mp[a].pb(node(b,c));
			mp[b].pb(node(a,c));
		}
		ans=0;
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}