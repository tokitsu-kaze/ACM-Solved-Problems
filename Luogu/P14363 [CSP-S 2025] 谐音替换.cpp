#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e6+10;
namespace HASH
{
	#define type int
	int m,k;
	vector<type> sd,p;
	vector<vector<type>> tmp;
	void set(vector<type> _sd,vector<type> _p)
	{
		sd=_sd;
		p=_p;
		assert(sd.size()==p.size());
		k=sd.size();
	}
	void init(int _m)
	{
		int i,j;
		m=_m;
		tmp.resize(k);
		for(j=0;j<k;j++)
		{
			tmp[j].resize(m+1);
			tmp[j][0]=1;
			for(i=1;i<=m;i++) tmp[j][i]=1ll*tmp[j][i-1]*sd[j]%p[j];
		}
	}
	struct hash_table
	{
		vector<vector<type>> ha;
		void work(char *s,int n)
		{
			int i,j;
			assert(n<=m);
			ha.resize(k);
			for(j=0;j<k;j++)
			{
				ha[j].resize(n+1);
				ha[j][0]=0;
				for(i=1;i<=n;i++) ha[j][i]=(1ll*ha[j][i-1]*sd[j]+s[i])%p[j];
			}
		}
		pair<type,type> get(int l,int r)
		{
			if(l>r) return {-1,-1};
			vector<type> res(k);
			for(int j=0;j<k;j++)
			{
				res[j]=(ha[j][r]-1ll*ha[j][l-1]*tmp[j][r-l+1])%p[j];
				if(res[j]<0) res[j]+=p[j];
			}
			return {res[0],res[1]};
		}
	};
	#undef type
}
HASH::hash_table ha,haa,hab;
/*
HASH::set({131,233},{402653189,805306457});
HASH::init(m);
ha.work(s,n);   // n<=m
*/
struct AC_Automaton
{
	static const int K=26;
	int nex[MAX][K],fail[MAX],cnt[MAX],lst[MAX],nowlen[MAX];
	int root,tot,pos[MAX];
	int getid(char c){return c-'a';}//may need change
	map<pair<int,int>,int> mp[MAX];
	int newnode()
	{
		memset(nex[tot],0,sizeof nex[tot]);
		fail[tot]=0;
		cnt[tot]=0;
		mp[tot].clear();
		return tot++;
	}
	void init()
	{
		tot=0;
		root=newnode();
	}
	void insert(char *s,int n,pair<int,int> ha) // s[0..n-1]
	{
		int now,i,t;
		now=root;
		for(i=1;i<=n;i++)
		{
			t=getid(s[i]);
			if(!nex[now][t]) nex[now][t]=newnode();
			now=nex[now][t];
		}
		cnt[now]++;
		mp[now][ha]++;
		nowlen[now]=n;
	}
	void work()
	{
		int i,now;
		queue<int> q;
		for(i=0;i<K;i++)
		{
			if(nex[root][i]) q.push(nex[root][i]);
		}
		while(!q.empty())
		{
			now=q.front();
			q.pop();
			
			//suffix link
			if(cnt[fail[now]]) lst[now]=fail[now];
			else lst[now]=lst[fail[now]];
			
			for(i=0;i<K;i++)
			{
				if(nex[now][i])
				{
					fail[nex[now][i]]=nex[fail[now]][i];
					q.push(nex[now][i]);
				}
				else nex[now][i]=nex[fail[now]][i];
			}
		}
	}
	void query(char *s,int n,char *tar)
	{
		int now,i,t,tmp;
		ll ans;
		haa.work(s,n);
		hab.work(tar,n);
		now=root;
		ans=0;
		vector<pair<int,int>> del;
		for(i=1;i<=n;i++)
		{
			t=getid(s[i]);
			now=nex[now][t];
			if(haa.get(i+1,n)!=hab.get(i+1,n)) continue;
			tmp=now;
			while(tmp!=root)
			{
				if(haa.get(1,i-nowlen[tmp])==hab.get(1,i-nowlen[tmp]))
				{
					ans+=mp[tmp][hab.get(i-nowlen[tmp]+1,i)];
				}
				tmp=lst[tmp];
			}
		}
		printf("%lld\n",ans);
	}
}ac;
/*
i is the suffix for each node in the subtree(i) of the fail tree

ac.init();
ac.insert(s,len,id); s[1..len], id:1..n
ac.work();
ac.query(s,len); s[1..len]
ac.build_fail_tree(mp);
*/
pair<int,int> get_all_hash(char *s,int len)
{
	ha.work(s,len);
	return ha.get(1,len);
}
char s1[MAX],s2[MAX],t1[MAX],t2[MAX];
int main()
{
	HASH::set({131,233},{402653189,805306457});
	HASH::init(MAX-10);
	int n,q,i,j,l1,l2,len;
	scanf("%d%d",&n,&q);
	ac.init();
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",s1+1,s2+1);
		len=strlen(s1+1);
		ac.insert(s1,len,get_all_hash(s2,len));
	}
	ac.work();
	while(q--)
	{
		scanf("%s%s",t1+1,t2+1);
		l1=strlen(t1+1);
		l2=strlen(t2+1);
		if(l1!=l2)
		{
			puts("0");
			continue;
		}
		ac.query(t1,l1,t2);
	}
}
