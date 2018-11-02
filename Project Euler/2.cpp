#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll f[1010],ans,i;
	f[0]=f[1]=1;
	ans=0;
	for(i=2;;i++)
	{
		f[i]=f[i-1]+f[i-2];
		if(f[i]>4000000) break;
		if(f[i]%2==0) ans+=f[i];
	}
	printf("%lld\n",ans);
	return 0;
}
/*

4613732

*/