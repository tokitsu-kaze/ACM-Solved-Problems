#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int a,b,c;
int ck(int x)
{
	if(x>min(a,c)) return 0;
	ll sum=0;
	sum+=a-x;
	sum+=c-x;
	sum+=b;
	return sum>=x;
}
int main()
{
	int T,l,r,mid;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		l=0;
		r=1e9;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(ck(mid+1)) l=mid+1;
			else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
