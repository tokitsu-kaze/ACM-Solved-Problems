#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e4+10;
int main()
{
	int n,m,i,k,a[105],b[105],fz,fm;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(k=1;k<=m;k++)
	{
		fz=fm=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==k)
			{
				fz+=b[i];
				fm++;
			}
		}
		printf("%.10f\n",1.0*fz/fm);
	}
	return 0;
}
