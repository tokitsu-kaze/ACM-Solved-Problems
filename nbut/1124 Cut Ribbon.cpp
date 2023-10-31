#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=100000+10; //MAX为数组大小
ll dp[4010];
int main()
{
	int n,a,b,c,ans,i,res;
	while(~scanf("%d%d%d%d",&n,&a,&b,&c))
	{
		if(a>b) swap(a,b);
		if(b>c) swap(b,c);
		if(a>b) swap(a,b);
		res=0;
		ans=n/a;
		n%=a;
		if(n==0)
		{
			printf("%d\n",ans);
			continue;
		}
		while(n&&ans)
		{
			n+=a;
			ans--;
			if(n%b==0) res=max(res,ans+n/b);
			for(i=0;i<=n;i+=c)
			{
				if(i!=0&&n%i==0)
				{
					res=max(res,ans+n/i);
					break;
				}
				if((n-i)%b==0)
				{
					res=max(res,ans+(i/c+(n-i)/b));
					break;
				}
			}
		}
		printf("%d\n",res);
	}
	return 0;
}