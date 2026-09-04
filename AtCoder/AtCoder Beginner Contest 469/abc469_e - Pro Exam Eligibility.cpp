#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e6+10;
int cnt[MAX];
double res[MAX],mn[MAX];
char s[MAX];
int n,k;
int ck(double ans)
{
	int i,j;
	res[0]=0;
	mn[0]=0;
	for(i=1,j=0;i<=n;i++)
	{
		res[i]=cnt[i]-ans*i;
		mn[i]=min(mn[i-1],res[i]);
		while(j<i && cnt[i]-cnt[j]>=k) j++;
		if(cnt[i]-cnt[j-1]>=k && res[i]>=mn[j-1]) return 1;
	}
	return 0;
}
/*
max{(cnt[r]-cnt[l-1])/(r-l+1)}>=ans
(cnt[r]-cnt[l-1])-(ans*r-ans*(l-1))>=0
cnt[r]-cnt[l-1]-ans*r+ans*(l-1)>=0
cnt[r]-ans*r>=cnt[l-1]-ans*(l-1)
*/
int main()
{
	int i;
	double l,r,mid;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	cnt[0]=0;
	for(i=1;i<=n;i++) cnt[i]=cnt[i-1]+(s[i]=='o');
	l=0;
	r=1;
	for(i=0;i<40;i++)
	{
		mid=(l+r)/2;
		if(ck(mid)) l=mid;
		else r=mid;
	}
	printf("%.10f\n",l);
	return 0;
}
