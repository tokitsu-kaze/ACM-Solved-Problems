#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,m,k,i,x,cnt,ok,seg;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		seg=n/k;
		cnt=n%k;
		ok=1;
		for(i=1;i<=m;i++)
		{
			scanf("%d",&x);
			if(x>seg+1) ok=0;
			else if(x==seg+1) cnt--;
		}
		if(cnt<0) ok=0;
		if(ok) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
2
9 1 1
9
45570 7 7
6510 6510 6510 6510 6510 6510 6510
*/
