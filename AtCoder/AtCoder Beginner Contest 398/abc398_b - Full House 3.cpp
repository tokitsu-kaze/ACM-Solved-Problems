#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=3e5+10;
int main()
{
	int n,i,j,x,cnt[22],ok;
	n=7;
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	ok=0;
	for(i=1;i<=13;i++)
	{
		for(j=1;j<=13;j++)
		{
			if(i==j) continue;
			if(cnt[i]>=3 && cnt[j]>=2) ok=1;
		}
	}
	if(ok) puts("Yes");
	else puts("No");
	return 0;
}
