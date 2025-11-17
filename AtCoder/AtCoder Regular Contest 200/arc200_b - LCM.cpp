#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,a,b,c,tmp,i;
	ll x,y;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c>a+b || c<max(a,b))
		{
			puts("No");
			continue;
		}
		string sa,sb;
		while(sa.size()<a) sa+="9";
		sb+="1";
		while(sb.size()<b) sb+="0";
		tmp=(a+b)-c;
		for(i=a-1;i;i--)
		{
			if(tmp==0) break;
			sa[i]='0';
			tmp--;
		}
		x=stol(sa);
		y=stol(sb);
		if(to_string(x/__gcd(x,y)*y).size()==c-1) y*=2;
		puts("Yes");
		cout<<x<<" "<<y<<"\n";
		assert(to_string(x/__gcd(x,y)*y).size()==c);
	}
	return 0;
}
