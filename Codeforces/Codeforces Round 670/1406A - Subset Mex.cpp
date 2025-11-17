#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i,cnta[105],cntb[105],x,mexa,mexb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(cnta,0,sizeof cnta);
		memset(cntb,0,sizeof cntb);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(cnta[x]) cntb[x]++;
			else cnta[x]++;
		}
		mexa=mexb=0;
		while(cnta[mexa]) mexa++;
		while(cntb[mexb]) mexb++;
		printf("%d\n",mexa+mexb);
	}
	return 0;
}
