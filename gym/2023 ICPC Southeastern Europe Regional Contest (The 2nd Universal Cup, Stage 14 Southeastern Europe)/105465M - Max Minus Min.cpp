#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
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
}st;
int a[MAX];
int work(int n,int f)
{
	int i,mna,mxa,mnb,mxb,ans,x,d,mxp,mnp;
	vector<pair<int,int>> res;
	for(i=1;i<=n;i++) res.push_back({a[i],i});
	sort(res.begin(),res.end());
	if(res[0].first==res.back().first) return 0;
	if(f) reverse(res.begin(),res.end());
	map<int,int> l,r;
	mnp=res[0].second;
	mxp=res[0].second;
	for(i=1;i<n;i++)
	{
		if(res[i].first!=res[i-1].first)
		{
			l[res[i].first]=mnp;
			r[res[i].first]=mxp;
		}
		mnp=min(mnp,res[i].second);
		mxp=max(mxp,res[i].second);
	}
	ans=2e9;
	for(auto &it:l)
	{
		x=it.first;
		mna=st.ask_min(l[x],r[x]);
		mxa=st.ask_max(l[x],r[x]);
		mnb=INF;
		mxb=-INF;
		if(l[x]>1)
		{
			mnb=min(mnb,st.ask_min(1,l[x]-1));
			mxb=max(mxb,st.ask_max(1,l[x]-1));
		}
		if(r[x]<n)
		{
			mnb=min(mnb,st.ask_min(r[x]+1,n));
			mxb=max(mxb,st.ask_max(r[x]+1,n));
		}
		d=mnb-mna;
		mna+=d;
		mxa+=d;
		ans=min(ans,max(mxa,mxb)-min(mna,mnb));
	}
	return ans;
}
int main()
{
	int T,n,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		st.work(n,a);
		ans=INF;
		ans=min(ans,work(n,0));
		ans=min(ans,work(n,1));
		printf("%d\n",ans);
	}
	return 0;
}
