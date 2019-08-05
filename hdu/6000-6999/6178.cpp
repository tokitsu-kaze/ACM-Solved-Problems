////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-09-04 00:10:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 6178
////Problem Title: 
////Run result: Accept
////Run time:733MS
////Run memory:8868KB
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
const int MAX=1e5+10;
const ll mod=10007;
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
vector<int> mp[MAX];
int degree[MAX],n;
bool flag[MAX];
int bfs()
{
	int i,t,res=0;
	queue<int> q;
	for(i=1;i<=n;i++)
	{
		if(degree[i]==1) q.push(i);
	}
	mem(flag,0);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(i=0;i<sz(mp[t]);i++)
		{
			if(!flag[mp[t][i]])
			{
				if(!flag[t])
				{
					flag[t]=flag[mp[t][i]]=1;
					res++;
				}
				q.push(mp[t][i]);
			}
		}
	}
	return res;
}
int main()
{
	int t,k,i,j,res;
	scanf("%d",&t);
	while(t--)
	{
		n=io.read();
		k=io.read();
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			degree[i]=0;
		}
		for(i=2;i<=n;i++)
		{
			j=io.read();
			mp[i].pb(j);
			mp[j].pb(i);
			degree[i]++;
			degree[j]++;
		}
		res=bfs();
	//	cout<<res<<endl;
		if(res*2>=k) printf("%d\n",(k+1)/2);
		else printf("%d\n",res+k-res*2);
	}
	return 0;
}