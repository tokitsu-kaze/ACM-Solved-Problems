#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
struct Fenwick_Tree
{
	#define type int
	type bit[MAX];
	int n;
	void init(int _n)
	{
		n=_n;
		for(int i=0;i<=n;i++) bit[i]=0;
	}
	int lowbit(int x){return x&(-x);}
	void clear(int x)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=0;
	}
	void upd(int x,type v)
	{
		for(;x<=n;x+=lowbit(x)) bit[x]=max(bit[x],v);
	}
	type ask_premax(int x)
	{
		type res=0;
		for(;x;x-=lowbit(x)) res=max(res,bit[x]);
		return res;
	}
	#undef type
}tr;
vector<int> res[MAX];
int id[MAX];
int main()
{
	int n,k,i,j,ans,pre,a,dp,len;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		res[i].clear();
		pre=0;
		id[i]=i;
		while(k--)
		{
			scanf("%d",&a);
			if(a>pre) res[i].push_back(a);
			pre=max(pre,a);
		}
	}
	sort(id,id+n,[&](int x,int y){
		return res[x].back()<res[y].back();
	});
	ans=0;
	pre=0;
	tr.init(MAX-10);
	for(i=0;i<n;i++)
	{
		dp=len=res[id[i]].size();
		for(j=0;j<res[id[i]].size();j++)
		{
			dp=max(dp,len-j+tr.ask_premax(res[id[i]][j]-1));
		}
		tr.upd(res[id[i]].back(),dp);
		ans=max(ans,dp);
//		cout<<id[i]<<" "<<dp<<endl;
	}
	printf("%d\n",ans);
	return 0;
}

