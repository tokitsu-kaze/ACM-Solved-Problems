#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
int main()
{
	int n,i,ans;
	string a,b;
	cin>>n>>a>>b;
	ans=0;
	for(i=0;i<n;i++) ans+=(a[i]!=b[i]);
	printf("%d\n",ans);
	return 0;
}
