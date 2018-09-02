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
const double eps=1e-4;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	ll t,n,x,k;
	freopen("in.txt","w",stdout);
	srand((unsigned)time(0));
	t=100;
	printf("%lld\n",t);
	while(t--)
	{
		n=(llrand()%(ll)1e5)+1;
		k=rand()%8+2;
		printf("%lld %lld\n",n,k);
		while(n--)
		{
			x=(llrand()%(ll)1e9)+1;
			printf("%lld\n",x);
		}
	}
	return 0;
}
*/
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
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,cnt[11],i,x,t,k;
	ll ans;
	t=io.read();
	while(t--)
	{
		n=io.read();
		k=io.read();
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			x=io.read();
			cnt[x%k]++;
		}
		ans=(ll)cnt[0]*(cnt[0]-1)/2;
		for(i=1;i<=k/2;i++)
		{
			if(k%2==0&&i==k/2) break;
			ans+=(ll)cnt[i]*cnt[k-i];
		}
		if(k%2==0) ans+=(ll)cnt[k/2]*(cnt[k/2]-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}