////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-02-07 19:02:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5880
////Problem Title: 
////Run result: Accept
////Run time:592MS
////Run memory:46520KB
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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int flag[MAX];
struct AC_Automaton
{
	int next[MAX][26],fail[MAX],cnt[MAX];
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
	void insert(char *s)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';
			int t=s[i]-'a';
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		cnt[now]=max(cnt[now],len);
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<26;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			for(i=0;i<26;i++)
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
	void query(char *s)
	{
		int len,now,i,res;
		len=strlen(s+1);
		now=root;
		for(i=1;i<=len;i++)
		{
			int t;
			if(!((s[i]>='a'&&s[i]<='z')||s[i]>='A'&&s[i]<='Z')) continue;
			if(s[i]>='A'&&s[i]<='Z') t=s[i]-'A';
			else t=s[i]-'a';
			now=next[now][t];
			int temp=now;
			res=0;
			while(temp)
			{
				res=max(res,cnt[temp]);
				temp=fail[temp];
				
			}
    		if(res)
    		{
    		    flag[i-res+1]++;
    			flag[i+1]--;
    		}
		}
	}
}ac;
char s[MAX];
int main()
{
	int t,n,i,len;
	scanf("%d",&t);
	while(t--)
	{
		ac.init();
		scanf("%d",&n);
		while(n--)
		{
			scanf("%s ",s);
			ac.insert(s);
		}
		ac.setfail();
		mem(flag,0);
		gets(s+1);
		ac.query(s);
		len=strlen(s+1);
		for(i=1;i<=len;i++)
		{
			flag[i]+=flag[i-1];
			if(flag[i]) s[i]='*';
		}
		puts(s+1);
	}
	return 0;
}