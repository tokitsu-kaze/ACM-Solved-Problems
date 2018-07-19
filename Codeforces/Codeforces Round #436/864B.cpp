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
	int len,i,ans;
	char a[222];
	while(~scanf("%d",&len))
	{
		scanf("%s",a);
		set<char> s;
		ans=0;
		for(i=0;i<len;i++)
		{
			if(a[i]>='A'&&a[i]<='Z')
			{
				ans=max(ans,(int)sz(s));
				s.clear();
			}
			else s.insert(a[i]);
		}
		ans=max(ans,(int)sz(s));
		printf("%d\n",ans);
	}
	return 0;
}