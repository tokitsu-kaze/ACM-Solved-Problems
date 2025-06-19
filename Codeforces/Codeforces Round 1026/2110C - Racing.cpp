#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a[MAX],l[MAX],r[MAX],mxl[MAX],mnr[MAX],tag[MAX];
int main()
{
	int T,n,i,now,sum,ok;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		sum=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==-1)
			{
				a[i]=0;
				tag[i]=1;
			}
			else tag[i]=0;
			sum+=a[i];
			mxl[i]=l[i]-sum;
			mnr[i]=r[i]-sum;
		}
		mxl[n+1]=0;
		mnr[n+1]=INF;
		for(i=n;i;i--)
		{
			mxl[i]=max(mxl[i],mxl[i+1]);
			mnr[i]=min(mnr[i],mnr[i+1]);
		}
		now=0;
		sum=0;
		ok=1;
		for(i=1;i<=n;i++)
		{
			if(tag[i] && mxl[i]-now>0 && mnr[i]-now>0)
			{
				a[i]=1;
				now++;
			}
			sum+=a[i];
			if(sum<l[i]||sum>r[i]) ok=0;
		}
		if(ok)
		{
			for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
		}
		else puts("-1");
	}
	return 0;
}

