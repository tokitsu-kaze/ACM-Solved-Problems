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
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int n,k,flag,i;
	char a[111],cnt[333];
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s",a);
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			cnt[a[i]]++;
		}
		flag=0;
		for(i=0;i<333;i++)
		{
			if(cnt[i]>k)
			{
				flag=1;
				break;
			}
		}
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}