#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+11;
int main()
{
	int a,b,tmp,ans;
	scanf("%d%d",&a,&b);
	tmp=min(a,b);
	ans=tmp*5;
	a-=tmp;
	b-=tmp;
	ans+=a*1;
	ans+=b*2;
	printf("%d\n",ans);
	return 0;
}
