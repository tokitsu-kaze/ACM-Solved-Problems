////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-12 16:20:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6197
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2832KB
//////////////////System Comment End//////////////////
#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
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
int a[MAX],c[MAX],d[MAX];
int main()
{
	int t,i,n,k,pos1,pos2;
	t=io.read();
	while(t--)
	{
		n=io.read();
		k=io.read();
		for(i=0;i<n;i++)
		{
			a[i]=io.read();
			c[i]=d[i]=INF;
		}
		for(i=0;i<n;i++)
		{
			*lower_bound(c,c+n,a[i])=a[i];
			*lower_bound(d,d+n,-a[i])=-a[i];
		}
		if(n-(lower_bound(c,c+n,INF)-c)<=k||n-(lower_bound(d,d+n,INF)-d)<=k) puts("A is a magic array.");
		else puts("A is not a magic array.");
	}
	return 0;
}