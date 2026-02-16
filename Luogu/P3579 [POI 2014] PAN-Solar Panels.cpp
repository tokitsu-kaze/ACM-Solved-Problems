#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,a,b,c,d,i,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ans=1;
		for(i=1;i<=min(b,d);i++)
		{
			i=min(b/(b/i),d/(d/i));
			if(b/i*i>=a && d/i*i>=c) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
枚举答案 i，判断是否在范围内。
发现答案能形成一段在同一个范围内的区间，
每次答案取区间右端点。
然后发现写法是整除分块。 
*/
