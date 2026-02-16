#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
char s[MAX];
int main()
{
	int n,a,b,i,l,r,cnta,cntb;
	ll ans;
	scanf("%d%d%d",&n,&a,&b);
	scanf("%s",s+1);
	ans=0;
	cnta=cntb=0;
	for(i=1,l=r=0;i<=n;i++)
	{
		while(l+1<=n && cnta<a)
		{
			l++;
			if(s[l]=='a') cnta++;
		}
		while(r+1<=l)
		{
			r++;
			if(s[r]=='b') cntb++;
		}
		while(r+1<=n && cntb<b)
		{
			if(s[r+1]=='b' && cntb+1==b) break;
			r++;
			if(s[r]=='b') cntb++;
		}
//		printf("%d %d %d %d\n",l,r,cnta,cntb);
		if(cnta>=a && cntb<b) ans+=max(0,r-l+1);
		if(s[i]=='a') cnta--;
		else cntb--;
	}
	printf("%lld\n",ans);
	return 0;
}
