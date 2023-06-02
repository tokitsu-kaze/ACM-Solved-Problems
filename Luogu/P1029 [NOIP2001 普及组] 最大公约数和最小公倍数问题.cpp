#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int a,b,i,ans,p,q;
	scanf("%d%d",&a,&b);
	ans=0;
	for(i=1;i<=b;i++)
	{
		if(b%i) continue;
		p=i;
		q=a*(b/i);
		if(__gcd(p,q)==a && p/__gcd(p,q)*q==b) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
