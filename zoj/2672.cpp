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
int main()
{
	int n,i,j,k,a[3022],tot,tmp,x,p,cnt,flag=0;
	ll f[3020];
	while(n=io.read())
	{
		hash_map<int,int> mp;
		vector<int> pos[3020],ans,now;
		tot=0;
		cnt=0;
		for(i=1;i<=n;i++)
		{
			a[i]=io.read(); 
			if(a[i]==0) cnt++;
			if(!mp.count(a[i])) mp[a[i]]=++tot;
			pos[mp[a[i]]].pb(i);
		}
		if(flag) puts("");
		flag=1;
		for(i=1;i<=tot;i++) pos[i].pb(INF);
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]==a[j]&&a[j]==0) continue;
				f[1]=a[i];
				f[2]=a[j];
				now.clear();
				now.pb(a[i]);
				now.pb(a[j]);
				p=j;
				for(k=3;;k++)
				{
					f[k]=f[k-1]+f[k-2];
					if(!mp.count(f[k])) break;
					else
					{
						x=mp[f[k]];
						tmp=*upper_bound(all(pos[x]),p);
						if(tmp==INF) break;
						now.pb(f[k]);
						p=tmp;
					}
				}
				if(sz(now)>sz(ans)) swap(now,ans);
			}
		}
		if(n==1) printf("%d\n%d\n",1,a[1]);
		else if(sz(ans)<cnt)
		{
			printf("%d\n",cnt);
			for(i=0;i<cnt;i++) printf("0%c"," \n"[i==sz(ans)-1]);
		}
		else
		{
			printf("%d\n",sz(ans));
			for(i=0;i<sz(ans);i++) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
		}
	}
	return 0;
}
