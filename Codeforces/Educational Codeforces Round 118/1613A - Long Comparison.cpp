#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		scanf("%d%d",&c,&d);
		while(b>0 && to_string(a).size()<to_string(c).size())
		{
			a*=10;
			b--;
		}
		while(d>0 && to_string(c).size()<to_string(a).size())
		{
			c*=10;
			d--;
		}
		if(a==c && b==d) puts("=");
		else if(b!=d)
		{
			if(b<d) puts("<");
			else puts(">");
		}
		else
		{
			if(to_string(a).size()!=to_string(c).size())
			{
				if(to_string(a).size()<to_string(c).size()) puts("<");
				else puts(">");
			}
			else
			{
				if(a<c) puts("<");
				else puts(">");
			}
		}
	}
	return 0;
}
