#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct Strongly_Connected_Components
{
	int scc_cnt,tot;
	int low[MAX],dfn[MAX],col[MAX],sz[MAX];
	int st[MAX],top,flag[MAX];
	vector<int> *mp;
	void dfs(int x)
	{
		int tmp;
		st[top++]=x;
		flag[x]=1;
		low[x]=dfn[x]=++tot;
		for(auto &to:mp[x])
		{
			if(!dfn[to])
			{
				dfs(to);
				low[x]=min(low[x],low[to]);
			}
			else if(flag[to]) low[x]=min(low[x],dfn[to]);
		}
		if(low[x]==dfn[x])
		{
			scc_cnt++;
			do
			{
				tmp=st[--top];
				flag[tmp]=0;
				col[tmp]=scc_cnt;
				sz[scc_cnt]++;
			}while(tmp!=x);
		}
	}
	void work(int n,vector<int> *_mp)
	{
		int i;
		mp=_mp;
		for(i=1;i<=n;i++) col[i]=sz[i]=flag[i]=dfn[i]=0;
		scc_cnt=top=tot=0;
		for(i=1;i<=n;i++)
		{
			if(col[i]) continue;
			dfs(i);
		}
	}
}scc;
/*
scc.work(n,mp);
*/
struct Tow_SAT
{
	static const int N=MAX;
	int n;
	vector<int> mp[N];
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=2*n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].push_back(b);}
	void pop_edge(int a,int b){mp[a].pop_back();}
	bool work(int *res)
	{
		int i;
		scc.work(2*n,mp);
		for(i=1;i<=n;i++)
		{
			if(scc.col[i]==scc.col[i+n]) return 0; // no solution
			if(scc.col[i]<scc.col[i+n]) res[i]=1;
			else res[i]=0;
		}
		return 1;
	}
}sat;
/*
MAX > 2*n
sat.init(n);
sat.work(int *res);

sat.add_edge(a,b); -> if a is true, b must true
special:
a must false -> if a is true, a must false
a must true  -> if a is false, a must true
*/
mt19937 rd(2333);
char s[MAX],ans[MAX],tmp[MAX][2],ta[MAX],tb[MAX];
int a[MAX],b[MAX],tag[MAX];
int n,m;
int res[MAX];
vector<int> idm;
void cal(int p)
{
	if(s[p]=='a')
	{
		tmp[p][0]='b';
		tmp[p][1]='c';
	}
	else if(s[p]=='b')
	{
		tmp[p][0]='a';
		tmp[p][1]='c';
	}
	else
	{
		tmp[p][0]='a';
		tmp[p][1]='b';
	}
}
void pre_work()
{
	int i,fa,fb;
	sat.init(n);
	idm.clear();
	for(i=1;i<=m;i++)
	{
		if(tag[a[i]] || tag[b[i]])
		{
			idm.push_back(i);
			continue;
		}
		if(s[a[i]]==ta[i]) continue;
		if(s[b[i]]==tb[i])
		{
			if(tmp[a[i]][1]==ta[i]) sat.add_edge(a[i],a[i]+n);
			else sat.add_edge(a[i]+n,a[i]);
		}
		else
		{
			fa=(tmp[a[i]][0]==ta[i]);
			fb=(tmp[b[i]][0]==tb[i]);
			sat.add_edge(a[i]+fa*n,b[i]+fb*n);
			fa=(tmp[a[i]][1]==ta[i]);
			fb=(tmp[b[i]][1]==tb[i]);
			sat.add_edge(b[i]+fb*n,a[i]+fa*n);
		}
	}
}
int ck()
{
	int i,fa,fb;
	for(auto &it:idm)
	{
		i=it;
		if(s[a[i]]==ta[i]) continue;
		if(s[b[i]]==tb[i])
		{
			if(tmp[a[i]][1]==ta[i]) sat.add_edge(a[i],a[i]+n);
			else sat.add_edge(a[i]+n,a[i]);
		}
		else
		{
			fa=(tmp[a[i]][0]==ta[i]);
			fb=(tmp[b[i]][0]==tb[i]);
			sat.add_edge(a[i]+fa*n,b[i]+fb*n);
			fa=(tmp[a[i]][1]==ta[i]);
			fb=(tmp[b[i]][1]==tb[i]);
			sat.add_edge(b[i]+fb*n,a[i]+fa*n);
		}
	}
	if(sat.work(res))
	{
		for(i=1;i<=n;i++) ans[i]=tmp[i][res[i]]-'a'+'A';
		ans[n+1]='\0';
		puts(ans+1);
		return 1;
	}
	for(auto &it:idm)
	{
		i=it;
		if(s[a[i]]==ta[i]) continue;
		if(s[b[i]]==tb[i])
		{
			if(tmp[a[i]][1]==ta[i]) sat.pop_edge(a[i],a[i]+n);
			else sat.pop_edge(a[i]+n,a[i]);
		}
		else
		{
			fa=(tmp[a[i]][0]==ta[i]);
			fb=(tmp[b[i]][0]==tb[i]);
			sat.pop_edge(a[i]+fa*n,b[i]+fb*n);
			fa=(tmp[a[i]][1]==ta[i]);
			fb=(tmp[b[i]][1]==tb[i]);
			sat.pop_edge(b[i]+fb*n,a[i]+fa*n);
		}
	}
	return 0;
}
int main()
{
	double time_st=clock();
	int d,i,j,k,ok,tot;
	char ch[2];
	scanf("%d%d",&n,&d);
	scanf("%s",s+1);
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%s",&a[i],ch);
		ta[i]=ch[0]-'A'+'a';
		scanf("%d%s",&b[i],ch);
		tb[i]=ch[0]-'A'+'a';
	}
	vector<int> pos;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='x')
		{
			pos.push_back(i);
			tag[i]=1;
		}
		else
		{
			cal(i);
			tag[i]=0;
		}
	}
	pre_work();
	vector<int> S;
	for(i=0;i<(1<<d);i++) S.push_back(i);
	shuffle(S.begin(),S.end(),rd);
	ok=0;
	for(auto &it:S)
	{
		for(i=0;i<d;i++)
		{
			s[pos[i]]='a'+((it>>i)&1);
			cal(pos[i]);
		}
		double time_ed=clock();
		if ((time_ed-time_st)/CLOCKS_PER_SEC>1.98) break;
		if(ck())
		{
			ok=1;
			break;
		}
	}
	if(!ok) puts("-1");
	return 0;
}
