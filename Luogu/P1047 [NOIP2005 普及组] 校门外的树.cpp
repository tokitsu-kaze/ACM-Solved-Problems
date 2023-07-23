#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e5+10;
int bit[MAX];
int main()
{
	int n,m,i,l,r,ans;
	scanf("%d%d",&n,&m);
	n++;
	for(i=0;i<=n;i++) bit[i]=0;
	while(m--)
	{
		scanf("%d%d",&l,&r);
		l++;
		r++;
		bit[l]++;
		bit[r+1]--;
	}
	ans=0;
	for(i=1;i<=n;i++)
	{
		bit[i]+=bit[i-1];
		if(!bit[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
