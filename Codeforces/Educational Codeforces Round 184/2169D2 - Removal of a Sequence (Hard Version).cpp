#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
ll x,y,k;
ll cal()
{
	ll i,nex,tmp,n;
	n=k;
	for(i=0;i<x;)
	{
		if(y-1==0) return -1;
		tmp=(n-1)/(y-1);
		if(tmp==0) break;
		nex=min(x-i,((tmp+1)*(y-1)+1-n+tmp-1)/tmp);
		i+=nex;
		n+=tmp*nex;
//		cout<<n<<" "<<tmp<<" "<<nex<<endl;
		if(n>1e12) return -1;
	}
	return n;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&x,&y,&k);
		printf("%lld\n",cal());
	}
	return 0;
}
