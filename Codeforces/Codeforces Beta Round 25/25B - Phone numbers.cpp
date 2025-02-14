#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=1000+10;
int main()
{
	int n,i;
	char s[111];
	scanf("%d",&n);
	scanf("%s",s+1);
	if(n<=3) return 0*puts(s+1);
	string ans;
	i=1;
	ans+=s[i++];
	ans+=s[i++];
	if(n&1) ans+=s[i++];
	for(;i<=n;i+=2)
	{
		ans+="-";
		ans+=s[i];
		ans+=s[i+1];
	}
	cout<<ans<<"\n";
	return 0;
}
