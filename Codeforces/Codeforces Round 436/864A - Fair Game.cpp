#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,i,a[111],x,flag;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		flag=0;
		for(i=1;i<=100;i++)
		{
			if(a[i]==n/2) flag++;
		}
		if(flag==2)
		{
			puts("YES");
			for(i=1;i<=100;i++)
			{
				if(a[i]==n/2) printf("%d ",i);
			}
		}
		else puts("NO");
	}
	return 0;
}