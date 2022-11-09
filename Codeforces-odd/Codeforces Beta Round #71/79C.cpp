#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/****************************************  head  ****************************************/
vector<PII > res;
struct AC_Automaton
{
	int next[MAX][64],l[MAX],fail[MAX],last[MAX],p[333];
	int root,tot;
	int newnode()
	{
		int i;
		mem(next[tot],0);
		l[tot]=0;
		return tot++;
	}
	int getid(char c)
	{
		return p[c];
	}
	void init()
	{
		int i;
		tot=0;
		mem(p,0);
		for(i='a';i<='z';i++) p[i]=tot++;
		for(i='A';i<='Z';i++) p[i]=tot++;
		for(i='0';i<='9';i++) p[i]=tot++;
		p['_']=tot++;
		tot=0;
		root=newnode();
	}
	void insert(const char *s)
	{
		int len,now,i;
		len=strlen(s);
		now=root;
		for(i=0;i<len;i++)
		{
			int t=getid(s[i]);
			if(!next[now][t]) next[now][t]=newnode();
			now=next[now][t];
		}
		l[now]=len;
	}
	void setfail()
	{
		int i,now;
		queue<int>q;
		for(i=0;i<63;i++)
		{
			if(next[root][i]) q.push(next[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			if(l[fail[now]]) last[now]=fail[now];
			else last[now]=last[fail[now]];
			for(i=0;i<63;i++)
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
		int len,now,i;
		len=strlen(s+1);
		now=root;
		for(i=1;i<=len;i++)
		{
			int t=getid(s[i]);
			now=next[now][t];
			int tmp=now;
			while(tmp)
			{
				if(l[tmp]) res.pb(MP(i-l[tmp]+1,i));
				tmp=last[tmp];
			}
		}
	}
}ac;
char s[MAX];
int main()
{
	int n,i,j,ans,pos,pre,len;
	while(~scanf("%s",s+1))
	{
		scanf("%d",&n);
		ac.init();
		string t[11];
		for(i=0;i<n;i++) cin>>t[i];
		int f[12]={0};
		for(i=0;i<n;i++)
		{
			if(f[i]) continue;
			for(j=0;j<n;j++)
			{
				if(i==j) continue;
				if(t[j].find(t[i])!=-1) f[j]=1;
			}
		}
		for(i=0;i<n;i++)
		{
			if(!f[i]) ac.insert(t[i].c_str());
		}
		ac.setfail();
		res.clear();
		ac.query(s);
		sort(all(res));
		ans=0;
		pos=pre=1;
		set<PII > tmp;
		for(auto it:res)
		{
			if(it.se-pre>ans)
			{
				pos=pre;
				ans=it.se-pre;
				tmp.insert(MP(ans,pos));
			}
			if(it.fi>=pos&&it.se<=pos+ans-1)
			{
				tmp.erase(MP(ans,pos));
				ans=pos+ans-it.fi-2;
				pos=it.fi+1;
			}
			pre=it.fi+1;
		}
		len=strlen(s+1);
		if(pre<=len&&len-pre+1>ans)
		{
			pos=pre;
			ans=len-pre+1;
		}
		if(sz(tmp))
		{
			auto it=tmp.end();
			it--;
			if((*it).fi>ans)
			{
				ans=(*it).fi;
				pos=(*it).se;
			}
		}
		printf("%d %d\n",ans,pos-1);
	}
	return 0;
} 