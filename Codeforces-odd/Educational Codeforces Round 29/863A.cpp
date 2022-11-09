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
	int x;
	char a[22],b[22];
	while(~scanf("%d",&x))
	{
		while(x%10==0) x/=10;
		sprintf(a,"%d",x);
		strcpy(b,a);
		reverse(b,b+strlen(b));
		if(strcmp(a,b)==0) puts("YES");
		else puts("NO");
	}
	return 0;
}