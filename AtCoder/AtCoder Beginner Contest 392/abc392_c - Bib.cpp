#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int MAX=3e5+10;
int p[MAX],q[MAX],idq[MAX];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++) scanf("%d",&q[i]);
	for(i=1;i<=n;i++) idq[q[i]]=i;
	for(i=1;i<=n;i++) printf("%d%c",q[p[idq[i]]]," \n"[i==n]);
	return 0;
}
