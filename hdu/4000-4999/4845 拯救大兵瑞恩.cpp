////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-04-10 15:45:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4845
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:5660KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
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
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
struct node
{
	int id,v,k;
	node(){}
	node(int a,int b,int c) :id(a),v(b),k(c){}
};
vector<int> mp[233];
int dir[4][2]={0,1,1,0,0,-1,-1,0},n,m;
int gate[233][233];
int flag[233][(1<<12)+10],key[233];
int bfs(int x)
{
	int to,i,tmp;
	node t;
	queue<node> q;
	q.push(node(x,0,key[x]));
	mem(flag,0);
	flag[x][key[x]]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.id==n*m) return t.v;
		for(i=0;i<sz(mp[t.id]);i++)
		{
			to=mp[t.id][i];
			tmp=gate[t.id][to];
			if(tmp)
			{
				if(tmp&1) continue;
				if((tmp&t.k)!=tmp) continue;
			}
			if(flag[to][t.k|key[to]]) continue;
			q.push(node(to,t.v+1,t.k|key[to]));
			flag[to][t.k|key[to]]=1;
		}
	}
	return -1;
}

int check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return 0;
	return 1;
}
int getid(int x,int y)
{
	return m*(x-1)+y;
}
int main()
{
	int i,j,k,x,y,xx,yy,p,a,b,c,d,e;
	while(~scanf("%d%d%d",&n,&m,&p))
	{
		for(i=1;i<=n*m;i++) mp[i].clear();
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				xx=getid(i,j);
				for(k=0;k<4;k++)
				{
					x=i+dir[k][0];
					y=j+dir[k][1];
					if(!check(x,y)) continue;
					yy=getid(x,y);
					mp[xx].pb(yy);
				}
			}
		}
		mem(gate,0);
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
			x=getid(a,b);
			y=getid(c,d);
			gate[x][y]|=1<<e;
			gate[y][x]|=1<<e;
		}
		mem(key,0);
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d%d%d",&a,&b,&c);
			key[getid(a,b)]|=1<<c;
		}
		printf("%d\n",bfs(1));
	}
	return 0;
}