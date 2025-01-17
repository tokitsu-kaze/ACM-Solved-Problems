#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
struct ST_table
{
	#define type int
	static const int N=MAX;
	static const int LOG=21;
	type v[N];
	int lg[N],bin[LOG],pmx[LOG][N];
	int pmax(const int &a,const int &b){return v[a]>v[b]?a:b;}
	void work(int n,type *a)
	{
		int i,j;
		for(i=bin[0]=1;1<<(i-1)<=n;i++) bin[i]=(bin[i-1]<<1);
		for(i=2,lg[1]=0;i<=n;i++) lg[i]=lg[i>>1]+1;
		for(i=1;i<=n;i++)
		{
			v[i]=a[i];
			pmx[0][i]=i;
		}
		for(j=1;1<<(j-1)<=n;j++)
		{
			for(i=1;i+bin[j]-1<=n;i++)
			{
				pmx[j][i]=pmax(pmx[j-1][i],pmx[j-1][i+bin[j-1]]);
			}
		}
	}
	int ask_pmax(int l,int r)
	{
		int t=lg[r-l+1];
		return pmax(pmx[t][l],pmx[t][r-bin[t]+1]);
	}
	type ask_max(int l,int r){return v[ask_pmax(l,r)];}
	#undef type
}rmq;
int a[MAX],n,mx[MAX];
bool ck(int x,int l,int r)
{
	if(l+x-1+max(x,rmq.ask_max(l,l+x-1))>r) return 0;
	return 1;
}
int work(int L,int R)
{
	int l,r,mid;
	l=0;
	r=(R-L+1)/2;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ck(mid+1,L,R)) l=mid+1;
		else r=mid;
	}
	return l;
}
int main()
{
	int q,l,r,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	a[n+1]=2e9;
	for(i=1;i<=n;i++) mx[i]=lower_bound(a+1,a+1+n,a[i]*2)-a-i;
	rmq.work(n,mx);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",work(l,r));
	}
	return 0;
}

