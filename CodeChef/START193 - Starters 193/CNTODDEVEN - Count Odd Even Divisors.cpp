#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=4e5+10;
int main()
{
	int T,n,i,cnt[2];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(i=1;i<=n;i++)
		{
			if(n%i==0) cnt[i&1]++;
		}
		printf("%d %d\n",cnt[1],cnt[0]);
	}
	return 0;
}
