#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int MAX=2e5+10;
int main()
{
	int n,l,r,i,a[105];
	scanf("%d%d%d",&n,&l,&r);
	for(i=1;i<=n;i++) a[i]=i;
	reverse(a+l,a+r+1);
	for(i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	return 0;
}
