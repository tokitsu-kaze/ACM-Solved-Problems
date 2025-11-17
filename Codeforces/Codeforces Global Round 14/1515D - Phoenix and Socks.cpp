#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int l[MAX],r[MAX],a[MAX];
int main()
{
	int T,n,L,R,i,tmp,cntl,cntr,ans;
	memset(l,0,sizeof l);
	memset(r,0,sizeof r);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&L,&R);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i<=L) l[a[i]]++;
			else r[a[i]]++;
		}
		cntl=cntr=0;
		ans=0;
		for(i=1;i<=n;i++)
		{
			tmp=min(l[i],r[i]);
			l[i]-=tmp;
			r[i]-=tmp;
			cntl+=l[i];
			cntr+=r[i];
		}
		tmp=min(cntl,cntr);
		ans+=tmp;
		cntl-=tmp;
		cntr-=tmp;
		for(i=1;i<=n;i++)
		{
			tmp=min(cntl,l[i])/2;
			ans+=tmp;
			cntl-=tmp*2;
			
			tmp=min(cntr,r[i])/2;
			ans+=tmp;
			cntr-=tmp*2;
		}
		ans+=cntl+cntr;
		printf("%d\n",ans);
		for(i=1;i<=n;i++) l[a[i]]=r[a[i]]=0;
	}
	return 0;
}

