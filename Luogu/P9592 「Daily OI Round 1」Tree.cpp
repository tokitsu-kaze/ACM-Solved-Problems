#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
int res[MAX],id[MAX],cnt[MAX];
ll v[MAX];
int main()
{
	int t,n,k,i,j,pos,now;
	ll s,d,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld%d",&n,&d,&k);
		if(k>=n)
		{
			puts("NO");
			continue;
		}
		s=0;
		now=1;
		v[1]=0;
		for(i=2;i<=n;i+=k)
		{
			for(j=i;j<=min(n,i+k-1);j++)
			{
				v[j]=now;
				s+=now;
			}
			if(s+1ll*now*(n-min(n,i+k-1))>=d) continue;
			if(i+k-1+k-1>n) continue;
			now++;
		}
		if(s<d)
		{
			puts("NO");
			continue;
		}
		for(i=n;i>=2;i--)
		{
			tmp=min(s-d,v[i]-1);
			v[i]-=tmp;
			s-=tmp;
		}
		for(i=0;i<=n;i++) id[i]=cnt[i]=0;
		id[0]=1;
		for(i=2;i<=n;i++)
		{
			cnt[v[i]]++;
			res[i]=id[v[i]-1];
			if(!id[v[i]]) id[v[i]]=i;
		}
		for(i=1;i<=n;i++)
		{
			if(cnt[i]>0&&cnt[i]<k) s=-1;
		}
		if(s==d)
		{
			puts("YES");
			for(i=2;i<=n;i++)
			{
				printf("%d%c",res[i]," \n"[i==n]);
			}
		}
		else puts("NO");
	}
	return 0;
}
/*
100
10 10 5
*/
