#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int n;
ll k,a[MAX],b[MAX];
int ck(int x)
{
	int i,cnt;
	
	for(i=1;i<=n;i++)
	{
		b[i]=a[i];
		cnt=0;
		while(b[i]%x!=0)
		{
			b[i]+=k;
			cnt++;
			if(cnt>k) return 0;
			if(cnt>5*x) break;
		}
		if(b[i]%x) return 0;
	}
	for(i=1;i<=n;i++) printf("%lld%c",b[i]," \n"[i==n]);
	return 1;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&k);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(i=2;i<=31;i++)
		{
			if(ck(i)) break;
		}
	}
	return 0;
}
