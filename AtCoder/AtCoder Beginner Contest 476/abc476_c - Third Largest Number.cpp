#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=5e5+10;
int a[MAX];
int main()
{
	int n,i,j,k,x,mx[3];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(mx,-0x3f,sizeof mx);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<3;j++)
		{
			if(a[i]>mx[j])
			{
				for(k=2;k>=j+1;k--) swap(mx[k],mx[k-1]);
				mx[j]=a[i];
				break;
			}
		}
		if(i>=3) printf("%d\n",mx[2]);
	}
	return 0;
}
