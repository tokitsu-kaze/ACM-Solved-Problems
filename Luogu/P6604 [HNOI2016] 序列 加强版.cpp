#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const int MAX=1e5+10;
namespace gen{
	typedef unsigned long long ull;
	ull s,a,b,c,lastans=0;
	ull rand(){
		return s^=(a+b*lastans)%c;
	}
};
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmn[LOG][N];
	int pmin(const int &a,const int &b){return v[a]<v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmn[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmn[j][i]=pmin(pmn[j-1][i],pmn[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[t][l],pmn[t][r-bin[t]+1]);
	}
	type ask_min(int l,int r){return v[ask_pmin(l,r)];}
	#undef type
}rmq;
int a[MAX],st[MAX],top,R[MAX],L[MAX];
ll suf[MAX],sufsum[MAX],pre[MAX],presum[MAX];
int main()
{
	int T,n,q,type,i,l,r,p;
	ull res;
	scanf("%d%d%d",&n,&q,&type);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	rmq.work(n,a);
	top=0;
	for(i=1;i<=n;i++) L[i]=0;
	for(i=n;i;i--)
	{
		while(top && a[st[top-1]]>a[i])
		{
			L[st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	top=0;
	for(i=1;i<=n;i++) R[i]=n+1;
	for(i=1;i<=n;i++)
	{
		while(top && a[st[top-1]]>a[i])
		{
			R[st[top-1]]=i;
			top--;
		}
		st[top++]=i;
	}
	pre[0]=presum[0]=0;
	for(i=1;i<=n;i++)
	{
		pre[i]=1LL*a[i]*(i-L[i])+pre[L[i]];
		presum[i]=presum[i-1]+pre[i];
	}
	suf[n+1]=sufsum[n+1]=0;
	for(i=n;i;i--)
	{
		suf[i]=1LL*a[i]*(R[i]-i)+suf[R[i]];
		sufsum[i]=sufsum[i+1]+suf[i];
	}
	res=0;
	gen::lastans=0;
	if(type==1) scanf("%llu%llu%llu%llu",&gen::s,&gen::a,&gen::b,&gen::c);
	for(i=1;i<=q;i++)
	{
		if(type==0) scanf("%d%d",&l,&r);
		else
		{
			l=gen::rand()%n+1;
			r=gen::rand()%n+1;
			if(l>r) swap(l,r);
		}
		p=rmq.ask_pmin(l,r);
		gen::lastans=1LL*a[p]*(r-p+1)*(p-l+1)
					+sufsum[l]-sufsum[p]-suf[p]*(p-l)
					+presum[r]-presum[p]-pre[p]*(r-p);
		res^=gen::lastans;
	}
	printf("%llu\n",res);
	return 0;
}
