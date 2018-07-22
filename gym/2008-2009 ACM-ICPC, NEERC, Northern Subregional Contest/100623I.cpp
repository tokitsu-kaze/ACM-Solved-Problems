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
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	freopen("important.in","r",stdin);
	freopen("important.out","w",stdout);
	int n,i;
	char a[11][1010];
	while(~scanf("%d",&n))
	{
		getchar();
		for(i=0;i<n;i++)
		{
			gets(a[i]);
		}
		puts("Yes");
		for(i=0;i<n;i++)
		{
			printf("%c|",a[i][0]);
		}
		printf("~%c\n",a[0][0]);
	}
	return 0;
}