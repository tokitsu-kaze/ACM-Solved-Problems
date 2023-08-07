////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-10-03 15:13:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4786
////Problem Title: 
////Run result: Accept
////Run time:733MS
////Run memory:4424KB
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
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int pre[MAX],ans;
struct node
{
	int x,y,v;
	node(){}
	node(int a,int b,int c):x(a),y(b),v(c){}
	friend bool operator<(node a,node b)
	{
		return a.v<b.v;
	}
}a[MAX],b[MAX];
void init(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		pre[i]=i;
	}
}
int find(int x)
{
	if(pre[x]!=x) pre[x]=find(pre[x]);
	return pre[x];
}
void merge(node s)
{
	int rx,ry;
	rx=find(s.x);
	ry=find(s.y);
	if(rx!=ry)
	{
		pre[rx]=ry;
		ans+=s.v;
	}
}
void kruskal(int n,int m,node *s)
{
	int i;
	init(n);
	sort(s,s+m);
	for(i=0;i<m;i++)
	{
		merge(s[i]);
	}
}
int main()
{
	int n,m,t,cas=1,i,x,y,c,l,r,f[44],cnt;
	mem(f,0);
	f[0]=1;
	f[1]=2;
	for(cnt=2;;cnt++)
	{
		f[cnt]=f[cnt-1]+f[cnt-2];
		if(f[cnt]>100000) break;
//		cout<<f[cnt]<<endl;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&x,&y,&c);
			a[i]=node(x,y,c);
			b[i]=node(x,y,c^1);
		}
		printf("Case #%d: ",cas++);
		if(m<n-1)
		{
			puts("No");
			continue;
		}
		ans=0;
		kruskal(n,m,a);
		int flag=0;
		for(i=1;i<=n;i++)
		{
			if(pre[i]==i) flag++;
		} 
		if(flag>1)
		{
			puts("No");
			continue;
		}
		l=ans;
		ans=0;
		kruskal(n,m,b);
		r=n-1-ans;
	//	cout<<l<<" "<<r<<endl;
		if(*lower_bound(f,f+cnt,l)<=r) puts("Yes");
		else puts("No");
	}
	return 0;
}
