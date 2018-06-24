////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2018-01-28 15:52:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4474
////Problem Title: 
////Run result: Accept
////Run time:4321MS
////Run memory:3120KB
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
const double eps=1e-8;
const int MAX=1e4+10;
const ll mod=1e9+7;
int flag[MAX];
vector<int> res;
void bfs(int n)
{
	int i;
	pair<string,int> t,nex;
	queue<pair<string,int> > q;
	mem(flag,0);
	for(i=0;i<sz(res);i++)
	{
		if(res[i]==0) continue;	
		string ss="";
		ss+=res[i]+'0';
		t=MP(ss,res[i]%n);
		q.push(t);
		flag[t.se]=1;
		if(t.se==0)
		{
			cout<<t.fi<<"\n";
			return;
		}
	}
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		if(t.se==0)
		{
			cout<<t.fi<<"\n";
			return ;
		}
		for(i=0;i<sz(res);i++)
		{
			nex=t;
			nex.fi+=res[i]+'0';
			nex.se=nex.se*10+res[i];
			nex.se%=n;
			if(!flag[nex.se])
			{
				q.push(nex);
				flag[nex.se]=1;
			}
		}
	}
	puts("-1");
}
int main()
{
	int n,m,cas=1,i,j,tag[11];
	char s[111];
	while(~scanf("%d%d",&n,&m))
	{
		mem(tag,0);
		while(m--)
		{
			scanf("%s",s);
			tag[s[0]-'0']=1;
		}
		res.clear();
		for(i=0;i<10;i++)
		{
			if(!tag[i]) res.pb(i);
		}
		printf("Case %d: ",cas++);
		if(sz(res)==0) puts("-1");
		else bfs(n);
	}
	return 0;
}