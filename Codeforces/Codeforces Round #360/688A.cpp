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
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int n,d,i,j,flag,now,ans;
	char a[1111];
	while(~scanf("%d%d",&n,&d))
	{
		now=ans=0;
		for(i=0;i<d;i++)
		{
			flag=0;
			scanf("%s",a);
			for(j=0;j<n;j++)
			{
				if(a[j]=='0') flag=1;
			}
			if(flag) now++;
			else now=0;
			ans=max(ans,now);
		}
		printf("%d\n",ans);
	}
	return 0;
}