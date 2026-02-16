#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int T,n,i;
	char ss[105];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		assert(n%2==0);
		scanf("%s",ss);
		string s=string(ss);
		string tmp=s;
		reverse(tmp.begin(),tmp.end());
		tmp+=s;
		puts(min(tmp,s).c_str());
	}
	return 0;
}
