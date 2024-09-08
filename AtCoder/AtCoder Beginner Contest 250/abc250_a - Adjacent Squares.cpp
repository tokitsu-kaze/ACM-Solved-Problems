#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int n,m,x,y,ans;
	cin>>n>>m>>x>>y;
	ans=4;
	if(x==1) ans--;
	if(x==n) ans--;
	if(y==1) ans--;
	if(y==m) ans--;
	printf("%d\n",ans);
	return 0;
}
