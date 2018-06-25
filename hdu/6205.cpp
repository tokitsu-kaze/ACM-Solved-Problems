////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-10 19:22:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6205
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:9488KB
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
const double eps=1e-6;
const int MAX=2e6+10;
const ll mod=998244353;
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
int v[MAX],a[MAX];
int main()
{
	int n,i,j,ans,temp,pos,s;
	while(n=io.read())
	{
		for(i=1;i<=n;i++)
		{
			v[i]=io.read();
		}
		for(i=1;i<=n;i++)
		{
			temp=io.read();
			v[i]-=temp;
		}
		for(i=n+1;i<=2*n-1;i++)
		{
			v[i]=v[i-n];
		}
		s=0;
		ans=0;
		j=1;
		for(i=1;i<=n;i++)
		{
			while(s>=0&&j<=i+n-1)
			{
				s+=v[j];
				j++;
			}
			if(j-i>ans)
			{
				ans=j-i;
				pos=i-1;
			}
			if(ans==n) break;
			s-=v[i];
		}
		printf("%d\n",pos);
	}
	return 0;
}