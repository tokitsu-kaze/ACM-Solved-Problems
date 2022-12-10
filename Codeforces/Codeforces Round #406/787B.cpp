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
const int MAX=1e4+10;
const ll mod=1e9+7;
int a[MAX];
int main()
{
	int n,m,k,i,flag;
	while(~scanf("%d%d",&n,&m))
	{
		flag=0;
		while(m--)
		{
			scanf("%d",&k);
			map<int,int> mp;
			for(i=0;i<k;i++)
			{
				scanf("%d",&a[i]);
				mp[a[i]]=1;
			}
			if(flag) continue;
			for(i=0;i<k;i++)
			{
				if(mp[-a[i]]) flag=1;
			}
			if(flag) flag=0;
			else flag=1;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}