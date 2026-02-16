#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int main()
{
	int T,n,h,a,b,c,tmp,pre,ok,l,r;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&h);
		l=r=h;
		pre=0;
		ok=1;
		while(n--)
		{
			scanf("%d%d%d",&a,&b,&c);
			tmp=a-pre;
			l-=tmp;
			r+=tmp;
			l=max(l,0);
			if(l>c||r<b||l>r) ok=0;
			l=max(l,b);
			r=min(r,c);
			pre=a;
		}
		puts(ok?"Yes":"No");
	}
	return 0;
}
