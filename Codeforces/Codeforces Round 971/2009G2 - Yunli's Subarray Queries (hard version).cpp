#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=4e5+10;
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
int cnt[MAX],a[MAX],ans[MAX],st[MAX],top,nex[MAX];
ll suf[MAX];
int main()
{
	int T,n,k,q,i,l,r,p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&k,&q);
		for(i=0;i<=2*n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=a[i]-i+n;
		}
		multiset<int> s;
		for(i=1;i<=k-1;i++)
		{
			ans[i]=0;
			if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
			cnt[a[i]]++;
			s.insert(cnt[a[i]]);
		}
		for(i=k;i<=n;i++)
		{
			if(cnt[a[i]]) s.erase(s.find(cnt[a[i]]));
			cnt[a[i]]++;
			s.insert(cnt[a[i]]);
			ans[i]=k-*s.rbegin();
			s.erase(s.find(cnt[a[i-k+1]]));
			cnt[a[i-k+1]]--;
			if(cnt[a[i-k+1]]) s.insert(cnt[a[i-k+1]]);
		}
		rmq.work(n,ans);
		top=0;
		for(i=1;i<=n;i++) nex[i]=n+1;
		for(i=1;i<=n;i++)
		{
			while(top && ans[st[top-1]]>ans[i])
			{
				nex[st[top-1]]=i;
				top--;
			}
			st[top++]=i;
		}
/*		for(i=1;i<=n;i++) printf("%d ",ans[i]);
		puts("");
		for(i=1;i<=n;i++) printf("%d ",nex[i]);
		puts("");*/
		suf[n+1]=0;
		for(i=n;i;i--) suf[i]=1LL*ans[i]*(nex[i]-i)+suf[nex[i]];
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&l,&r);
			l=l+k-1;
			p=rmq.ask_pmin(l,r);
			printf("%lld\n",1LL*ans[p]*(r-p+1)+suf[l]-suf[p]);
		}
	}
	return 0;
}

