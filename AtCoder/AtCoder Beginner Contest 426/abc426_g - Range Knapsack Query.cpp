#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
const int W=500;
struct node
{
	int l,r,c,id;
}qst[MAX],tmp1[MAX],tmp2[MAX];
int w[MAX],v[MAX];
ll dp[MAX][505],ans[MAX];
void dfs(int l,int r,int ql,int qr)
{
	if(ql>qr) return;
	int i,j,cnt1,cnt2;
	if(l==r)
	{
		for(i=ql;i<=qr;i++)
		{
			if(qst[i].c>=w[l]) ans[qst[i].id]=v[l];
		}
		return;
	}
	int mid=(l+r)>>1;
	memset(dp[mid],0,sizeof(dp[mid]));
	for(i=w[mid];i<=W;i++) dp[mid][i]=v[mid];
	for(i=mid-1;i>=l;i--)
	{
		for(j=0;j<=W;j++) dp[i][j]=dp[i+1][j];
		for(j=W;j>=w[i];j--) dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
	}
	memset(dp[mid+1],0,sizeof(dp[mid+1]));
	for(i=w[mid+1];i<=W;i++) dp[mid+1][i]=v[mid+1];
	for(i=mid+2;i<=r;i++)
	{
		for(j=0;j<=W;j++) dp[i][j]=dp[i-1][j];
		for(j=W;j>=w[i];j--) dp[i][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
	}
	cnt1=0;
	cnt2=0;
	for(i=ql;i<=qr;i++)
	{
		if(qst[i].l<=mid && qst[i].r<=mid) tmp1[++cnt1]=qst[i];
		else if(qst[i].l>mid && qst[i].r>=mid) tmp2[++cnt2]=qst[i];
		else
		{
			for(j=0;j<=min(qst[i].c,W);j++)
			{
				ans[qst[i].id]=max(ans[qst[i].id],
						dp[qst[i].l][j]+dp[qst[i].r][qst[i].c-j]);
			}
		}
	}
	for(i=1;i<=cnt1;i++) qst[ql+i-1]=tmp1[i];
	for(i=1;i<=cnt2;i++) qst[ql+cnt1+i-1]=tmp2[i];
	dfs(l,mid,ql,ql+cnt1-1);
	dfs(mid+1,r,ql+cnt1,ql+cnt1+cnt2-1);
}
int main()
{
	int n,q,l,r,c,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&w[i],&v[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d%d%d",&l,&r,&c);
		qst[i]={l,r,c,i};
	}
	dfs(1,n,1,q);
	for(i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
