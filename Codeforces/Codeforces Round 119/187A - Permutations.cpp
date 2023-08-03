#include<bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=2e5+10;
int a[MAX],b[MAX];
int main()
{
	int n,i,ans;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			if(b[i]==a[ans]) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}