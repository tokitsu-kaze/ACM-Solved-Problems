#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmx[LOG][N],pmn[LOG][N];
	int pmax(const int &a,const int &b){return v[a]>v[b]?a:b;}
	int pmin(const int &a,const int &b){return v[a]<v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmx[0][i]=pmn[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmx[j][i]=pmax(pmx[j-1][i],pmx[j-1][i+bin[j-1]]);
				pmn[j][i]=pmin(pmn[j-1][i],pmn[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmax(int l,int r)
	{
		int t=lg[r-l+1];
		return pmax(pmx[t][l],pmx[t][r-bin[t]+1]);
	}
	int ask_pmin(int l,int r)
	{
		int t=lg[r-l+1];
		return pmin(pmn[t][l],pmn[t][r-bin[t]+1]);
	}
	type ask_max(int l,int r){return v[ask_pmax(l,r)];}
	type ask_min(int l,int r){return v[ask_pmin(l,r)];}
	#undef type
}sta,stb,stmna,stmxa;
int a[MAX],b[MAX],tmna[MAX],tmxa[MAX];
int main()
{
	int n,m,q,i,l1,r1,l2,r2,mna,mxa,mnb,mxb;
	ll ans,ra,rb;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]);
	for(i=1;i<=n;i++)
	{
		tmna[i]=INF;
		tmxa[i]=-INF;
		if(a[i]>=0) tmna[i]=a[i];
		else tmxa[i]=a[i];
	}
	sta.work(n,a);
	stb.work(m,b);
	stmna.work(n,tmna);
	stmxa.work(n,tmxa);
	while(q--)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		mna=sta.ask_min(l1,r1);
		mxa=sta.ask_max(l1,r1);
		mnb=stb.ask_min(l2,r2);
		mxb=stb.ask_max(l2,r2);
		if(mna>=0 && mnb>=0) ans=1LL*mxa*mnb;
		else if(mxa<=0 && mxb<=0) ans=1LL*mna*mxb;
		else if(mna>=0) ans=1LL*mna*mnb;
		else if(mxa<=0) ans=1LL*mxa*mxb;
		else if(mnb>=0) ans=1LL*mxa*mnb;
		else if(mxb<=0) ans=1LL*mna*mxb;
		else
		{
			ra=stmna.ask_min(l1,r1);
			if(ra!=INF) ra=ra*mnb;
			else ra=-LLINF;
			rb=stmxa.ask_max(l1,r1);
			if(rb!=-INF) rb=rb*mxb;
			else rb=-LLINF;
			ans=max(ra,rb);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
min([l1,r1])>=0, min([l2,r2])>=0 -> max([l1,r1]),min([l2,r2])
max([l1,r1])<=0, max([l2,r2])<=0 -> min([l1,r1]),max([l2,r2])
min([l1,r1])>=0 -> min([l1,r1]),min([l2,r2])
min([l2,r2])>=0 -> max([l1,r1]),min([l2,r2])
max([l1,r1])<=0 -> max([l1,r1]),max([l2,r2])
max([l2,r2])<=0 -> min([l1,r1]),max([l2,r2])
max{min([l1,r1]>0),min([l2,r2]);max([l1,r1]<0),max([l2,r2])}
*/
