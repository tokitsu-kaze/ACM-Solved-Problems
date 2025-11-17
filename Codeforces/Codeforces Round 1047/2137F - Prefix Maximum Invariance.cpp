#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX],tmp[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	type get(int x)
	{
		type res=0;
		for(;x<=n;x+=lowbit(x)) res=max(res,bit[x]);
		return res;
	}
	void upd(int x,type v)
	{
		for(;x;x-=lowbit(x)) bit[x]=max(bit[x],v);
	}
	type ask_sufmax(int x)
	{
		return get(x);
	}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	#undef type
}tr;
int a[MAX],b[MAX];
int main()
{
	int T,n,i,mxpos,premx;
	ll ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		tr.init(2*n);
		ans=0;
		premx=-1;
		for(i=1;i<=n;i++)
		{
			if(a[i]==b[i]) ans+=1LL*i*(n-i+1);
			else
			{
				mxpos=tr.ask_sufmax(max(a[i],b[i]));
				if(a[i]<=premx) ans+=1LL*mxpos*(n-i+1);
			}
			premx=max(premx,a[i]);
			tr.upd(a[i],i);
//			cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
