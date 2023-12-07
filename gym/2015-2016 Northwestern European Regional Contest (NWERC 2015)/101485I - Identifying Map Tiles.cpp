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
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	ll i,len,x,y,temp;
	char a[55];
	while(~scanf("%s",a))
	{
		len=strlen(a);
		temp=1;
		if(a[0]=='0') x=y=0;
		else if(a[0]=='1') x=1,y=0;
		else if(a[0]=='2') x=0,y=1;
		else x=1,y=1;
		for(i=1;i<len;i++)
		{
			x<<=1;
			y<<=1;
			if(a[i]=='1') x++;
			else if(a[i]=='2')y++;
			else if(a[i]=='3') x++,y++;
		}
		printf("%lld %lld %lld\n",len,x,y);
	}
	return 0;
}