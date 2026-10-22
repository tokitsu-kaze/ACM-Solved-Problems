#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=6e5+10;
int main()
{
	int T,n,x,i,cnta,cntb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnta=cntb=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>0) cnta++;
			else cntb++;
		}
		for(i=1;i<=n;i++)
		{
			if(i<=cnta) printf("%d",i);
			else printf("%d",cnta*2-i);
			printf("%c"," \n"[i==n]);
		}
		for(i=1;i<=n;i++)
		{
			if(i<=cntb*2) printf("%d",i%2);
			else printf("%d",i-cntb*2);
			printf("%c"," \n"[i==n]);
		}
	}
	return 0;
}
