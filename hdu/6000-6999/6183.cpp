////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-14 15:54:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6183
////Problem Title: 
////Run result: Accept
////Run time:4336MS
////Run memory:8224KB
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
int root[55],tot,ls[MAX],rs[MAX],v[MAX],flag;
inline void init()
{
	mem(root,0);
	tot=1;
}
inline void Insert(int l,int r,int &id,int pos,int val)
{
	if(!id)
	{
		id=tot;
		ls[id]=rs[id]=0;
		v[id]=val;
		tot++;
	}
	v[id]=min(v[id],val);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(pos<=mid) Insert(l,mid,ls[id],pos,val);
	else Insert(mid+1,r,rs[id],pos,val);
}
inline void query(int l,int r,int id,int x,int y,int val)
{
	if(flag||!id) return;
	if(l>=x&&r<=y)
	{
		if(v[id]<=val) flag=1;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid) query(l,mid,ls[id],x,y,val);
	if(y>mid) query(mid+1,r,rs[id],x,y,val);
}
int main()
{
	int op,x,y,c,i,ans;
	while(1)
	{
		op=io.read();
		if(op==3) break;
		if(op==0) init();
		else if(op==1)
		{
			x=io.read();
			y=io.read();
			c=io.read();
			Insert(1,1e6,root[c],y,x);
		}
		else if(op==2)
		{
			c=io.read();
			x=io.read();
			y=io.read();
			ans=0;
			for(i=0;i<=50;i++)
			{
				flag=0;
				query(1,1e6,root[i],x,y,c);
				ans+=flag;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}