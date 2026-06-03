#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
char s[MAX];
int sum[MAX];
int main()
{
	int n,q,i,l,r;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	sum[0]=sum[1]=0;
	for(i=2;i<=n;i++) sum[i]=sum[i-1]+(s[i]!=s[i-1]);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",(1+sum[r]-sum[l]+(s[r]!=s[l]))/2);
	}
	return 0;
}
