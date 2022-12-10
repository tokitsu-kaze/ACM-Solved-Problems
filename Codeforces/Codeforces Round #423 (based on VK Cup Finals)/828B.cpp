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
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=2e5+10;
const ll mod=1e6;
int main()
{
	int n,m,i,j,px1,py1,px2,py2,a,b,c,cnt;
	char mp[111][111];
	while(~scanf("%d%d",&n,&m))
	{
		px1=n;
		py1=m;
		px2=py2=0;
		cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",mp[i]);
			for(j=0;j<m;j++)
			{
				if(mp[i][j]=='B')
				{
					px1=min(px1,i);
					py1=min(py1,j);
					px2=max(px2,i);
					py2=max(py2,j);
					cnt++;
				}
			}
		}
		if(cnt==0)
		{
			puts("1");
			continue;
		}
	//	cout<<px1<<" "<<py1<<endl;
	//	cout<<px2<<" "<<py2<<endl;
		a=px2-px1+1;
		b=py2-py1+1;
	//	cout<<a<<" "<<b<<endl;
		c=max(a,b);
		if(c<=n&&c<=m) printf("%d\n",c*c-cnt);
		else puts("-1");
	}
	return 0;
}
/*
5 4
BWWW
WWWB
WWWB
WWBB
WWBW
*/