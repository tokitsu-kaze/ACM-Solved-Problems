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
const int MAX=1e6+10;
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
	int t,i,j,n,a[1011],ans,l,r;
	t=io.read();
	while(t--)
	{
		n=io.read();
		for(i=0;i<n;i++)
		{
			a[i]=io.read();
		}
		a[n++]=INF;
		ans=0;
		sort(a,a+n);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				l=lower_bound(a,a+n,-(a[i]+a[j]))-a;
				int temp=a[l];
				if(temp+a[i]+a[j]!=0) continue;
				r=upper_bound(a,a+n,-(a[i]+a[j]))-a-1;
				ans+=r-l+1;
				if(i>=l&&i<=r) ans--;
				if(j>=l&&j<=r) ans--;
			}
		}
		printf("%d\n",ans/3);
	}
	return 0;
}