#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int T,n,m,i,g,lcm;
	string a,b,ra,rb;
	scanf("%d",&T);
	while(T--)
	{
		cin>>a>>b;
		n=a.size();
		m=b.size();
		g=__gcd(n,m);
		lcm=n*m/g;
		ra="";
		rb="";
		for(i=1;i<=lcm/n;i++) ra+=a;
		for(i=1;i<=lcm/m;i++) rb+=b;
		if(ra==rb) cout<<ra<<"\n";
		else puts("-1");
	}
	return 0;
}
