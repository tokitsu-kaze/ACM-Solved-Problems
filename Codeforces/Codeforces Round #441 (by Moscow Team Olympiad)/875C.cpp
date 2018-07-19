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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-3;
const int MAX=2e5+10;
const ll mod=1e9+7;
int scc,top,tot;
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
vector<int> out;
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
			puts("No"); 
			return;
		}
		pos[belong[2*i]]=belong[2*i+1];
		pos[belong[2*i+1]]=belong[2*i];
	}
	builddag(n);
	topsort(n);
	cnt=0;
	for(i=0;i<2*n;i++)
	{
		if(outflag[belong[i]]==1) ans[cnt++]=i+1;
	}
	out.clear();
	for(i=0;i<cnt;i++)
	{
		if(ans[i]%2) out.pb((ans[i]+1)/2);
	}
	puts("Yes");
	printf("%d\n",(int)sz(out));
	if((int)sz(out))
	{
		printf("%d",out[0]);
		for(i=1;i<sz(out);i++)
		{
			printf(" %d",out[i]);
		}
		puts("");
	}
}
vector<int> v[MAX];
int main()
{
	int m,n,i,j,k,x,a;
	while(~scanf("%d%d",&m,&n))
	{
		init(n);
		for(i=0;i<m;i++)
		{
			v[i].clear();
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&x);
			for(j=0;j<x;j++)
			{
				scanf("%d",&a);
				a--;
				v[i].pb(a);
			}
		}
		for(i=1;i<m;i++)
		{
			int p=-1;
			for(j=0,k=0;j<sz(v[i-1])&&k<sz(v[i]);j++,k++)
			{
				if(v[i-1][j]!=v[i][k])
				{
					p=j;
					break;
				}
			}
			if(p==-1)
			{
				if((int)sz(v[i-1])>(int)sz(v[i]))
				{
					puts("No");
					return 0;
				}
			}
			else
			{
				if(v[i-1][p]>v[i][p])
				{
					add(v[i-1][p]*2+1,v[i-1][p]*2);
					add(v[i][p]*2,v[i][p]*2+1);
				}
				else
				{
					add(v[i-1][p]*2+1,v[i][p]*2+1);
					add(v[i][p]*2,v[i-1][p]*2);
				}
			}
		}
		twosat(n);
	}
	return 0;
}