#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
vector<int> a[MAX];
int c[MAX];
int main()
{
	int n,i,j,l;
	ll k;
	scanf("%d%lld",&n,&k);
	k--;
	for(i=0;i<n;i++)
	{
		scanf("%d",&l);
		a[i]=vector<int>(l);
		for(auto &it:a[i]) scanf("%d",&it);
	}
	for(i=0;i<n;i++) scanf("%d",&c[i]);
	for(i=0;i<n;i++)
	{
		l=a[i].size();
		if(k>=1LL*c[i]*l)
		{
			k-=1LL*c[i]*l;
			continue;
		}
		k%=l;
		printf("%d\n",a[i][k]);
		break;
	}
	return 0;
}
