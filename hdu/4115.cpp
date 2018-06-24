////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-18 20:52:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4115
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:31700KB
//////////////////System Comment End//////////////////
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=6e5+10;
const ll mod=1e9+7;
int n,scc,top,tot;
vector<int> mp[MAX];
int low[MAX],dfn[MAX],belong[MAX];
int stk[MAX],flag[MAX];
int pos[MAX],degree[MAX],ans[MAX],outflag[MAX],cnt;
vector<int> dag[MAX];
void init(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		mp[i].clear();
		dag[i].clear();
		low[i]=0;
		dfn[i]=0;
		stk[i]=0;
		flag[i]=0;
		degree[i]=0;
		outflag[i]=0;
	}
	scc=top=tot=0;
}
void tarjan(int x)
{
	int to,i,temp;
	stk[top++]=x;
	flag[x]=1;
	low[x]=dfn[x]=++tot;
	for(i=0;i<mp[x].size();i++)
	{
		to=mp[x][i];
		if(!dfn[to])
		{
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}
		else if(flag[to]) low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		scc++;
		do
		{
			temp=stk[--top];
			flag[temp]=0;
			belong[temp]=scc;
		}while(temp!=x);
	}
}
void add(int x,int y)
{
	mp[x].pb(y);
}
void topsort(int n)
{
	int i,t;
	queue<int> q;
	cnt=0;
	for(i=1;i<=scc;i++)
	{
		if(degree[i]==0) q.push(i);
		outflag[i]=0;
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(outflag[t]==0)
		{
			outflag[t]=1;
			outflag[pos[t]]=2;
		}
		for(i=0;i<sz(dag[t]);i++)
		{
			int to=dag[t][i];
			degree[to]--;
			if(degree[to]==0) q.push(to);
		}
	}
}
void builddag(int n)
{
	int i,j,to;
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<sz(mp[i]);j++)
		{
			to=mp[i][j];
			if(belong[i]!=belong[to])
			{
				degree[belong[i]]++;
				dag[belong[to]].pb(belong[i]);
			}
		}
	}
}
void twosat(int n)
{
	int i;
	for(i=0;i<2*n;i++)
	{
		if(!dfn[i]) tarjan(i);
	}
	for(i=0;i<n;i++)
	{
		if(belong[2*i]==belong[2*i+1])
		{
			puts("no"); 
			return;
		}
	}
	puts("yes");
}
int v[MAX];
int main()
{
	int t,n,m,i,a,b,c,cas=1,t1,t2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(3*n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			if(v[i]==1)
			{
				add(6*(i-1)+1,6*(i-1)+2);
				add(6*(i-1)+3,6*(i-1)+0);
			}
			else if(v[i]==2)
			{
				add(6*(i-1)+3,6*(i-1)+4);
				add(6*(i-1)+5,6*(i-1)+2);
			}
			else if(v[i]==3)
			{
				add(6*(i-1)+5,6*(i-1)+0);
				add(6*(i-1)+1,6*(i-1)+4);
			}
			add(6*(i-1)+0,6*(i-1)+3);
			add(6*(i-1)+0,6*(i-1)+5);
			add(6*(i-1)+2,6*(i-1)+1);
			add(6*(i-1)+2,6*(i-1)+5);
			add(6*(i-1)+4,6*(i-1)+1);
			add(6*(i-1)+4,6*(i-1)+3);
		}
		// 0 1->1
		// 2 3->2
		// 4 5->3
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(c)
			{
				add(6*(a-1)+0,6*(b-1)+1);
				add(6*(b-1)+0,6*(a-1)+1);
				add(6*(a-1)+2,6*(b-1)+3);
				add(6*(b-1)+2,6*(a-1)+3);
				add(6*(a-1)+4,6*(b-1)+5);
				add(6*(b-1)+4,6*(a-1)+5);
			}
			else
			{
				add(6*(a-1)+0,6*(b-1)+0);
				add(6*(b-1)+0,6*(a-1)+0);
				add(6*(a-1)+2,6*(b-1)+2);
				add(6*(b-1)+2,6*(a-1)+2);
				add(6*(a-1)+4,6*(b-1)+4);
				add(6*(b-1)+4,6*(a-1)+4);
			}
		}
		printf("Case #%d: ",cas++);
		twosat(3*n);
	}
	return 0;
}