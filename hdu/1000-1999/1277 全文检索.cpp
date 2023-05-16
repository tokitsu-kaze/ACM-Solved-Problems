////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-12 19:58:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1277
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:18908KB
//////////////////System Comment End//////////////////
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
const double eps=1e-4;
const int MAX=6e5+10;
const ll mod=1e9+7;
string s[60010];
int n,flag[MAX];
char a[MAX];
struct AC_Automaton
{
	int next[MAX][11],fail[MAX],cnt[MAX];
	int root,tot;
	int newnode()
	{
		int i;
		mem(next[tot],0);
		fail[tot]=0;
		cnt[tot]=0;
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s,int id)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=s[i]-'0';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]=id;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<10;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(i=0;i<10;i++)
			{
				if(next[now][i])
				{
					fail[next[now][i]]=next[fail[now]][i];
					q.push(next[now][i]);
				}
				else next[now][i]=next[fail[now]][i];
			}
		}
	}
	void query()
	{
		int len,now,i,j;
		now=root;
		vector<int> res;
		for(i=0;i<n;i++)
		{
			len=s[i].length();
			for(j=0;j<len;j++)
			{
				int t=s[i][j]-'0';
				now=next[now][t];
				int temp=now;
				while(temp)
				{
					if(cnt[temp])
					{
						if(!flag[cnt[temp]])
						{
							flag[cnt[temp]]=1;
							res.pb(cnt[temp]);
						}
					}
					temp=fail[temp];
				}
			}
		}
		if(sz(res))
		{
			printf("Found key:");
			for(i=0;i<sz(res);i++) printf(" [Key No. %d]",res[i]);
			puts("");
		}
		else puts("No key can be found !");
	}
}ac;
int main()
{
	int i,m;
	while(~scanf("%d%d",&n,&m))
	{
		ac.init();
		for(i=0;i<n;i++) cin>>s[i];
		for(i=1;i<=m;i++)
		{
			scanf("%s",a);
			scanf("%s",a);
			scanf("%s",a);
			scanf("%s",a);
			ac.insert(a,i);
			flag[i]=0;
		}
		ac.setfail();
		ac.query();
	}
	return 0;
}