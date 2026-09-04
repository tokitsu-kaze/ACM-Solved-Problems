#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x,ans;
	string a,b,c;
	scanf("%d",&n);
	a="";
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x--;
		a+=to_string(x);
	}
	b="";
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x--;
		b+=to_string(x);
	}
	c="";
	for(i=0;i<n;i++) c+=to_string(i);
	ans=0;
	do
	{
		if(a<c && c<b) ans++;
	}
	while(next_permutation(c.begin(),c.end()));
	printf("%d\n",ans);
	return 0;
}
