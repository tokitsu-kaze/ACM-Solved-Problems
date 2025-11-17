#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=2e5+10;
int main()
{
	int n,i,x;
	string s[105],y;
	cin>>n;
	for(i=1;i<=n;i++) cin>>s[i];
	cin>>x>>y;
	if(s[x]==y) puts("Yes");
	else puts("No");
	return 0;
}
