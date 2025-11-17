#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int l[MAX],r[MAX],cnt[MAX];
char s[MAX];
int main()
{
	int T,n,k,q,x,y,i,j,pos,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(i=1;i<=k;i++) scanf("%d",&l[i]);
		for(i=1;i<=k;i++) scanf("%d",&r[i]);
		for(i=1;i<=n;i++) cnt[i]=0;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&x);
			pos=upper_bound(l+1,l+1+k,x)-l-1;
			y=l[pos]+r[pos]-x;
			if(x>y) swap(x,y);
			cnt[x]++;
			cnt[y+1]--;
		}
		cnt[0]=0;
		for(i=1;i<=n;i++) cnt[i]+=cnt[i-1];
		for(i=1;i<=k;i++)
		{
			mid=(l[i]+r[i])>>1;
			for(j=l[i];j<=mid;j++)
			{
				if(cnt[j]&1) swap(s[j],s[l[i]+r[i]-j]);
			}
		}
		s[n+1]='\0';
		puts(s+1);
	}
	return 0;
}
