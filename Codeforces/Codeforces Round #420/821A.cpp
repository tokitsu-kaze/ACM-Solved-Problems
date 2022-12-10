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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=100000+10;
const ll mod=10000;
int main()
{
	int n,mp[55][55],i,j,ii,jj;
	while(~scanf("%d",&n))
	{
		mem(mp,0);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&mp[i][j]);
			}
		}
		map<int,int> m[55][55];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				for(ii=0;ii<n;ii++)
				{
					for(jj=0;jj<n;jj++)
					{
						if(j==ii||i==jj) continue;
						m[i][j][mp[i][ii]+mp[jj][j]]=1;
		//				cout<<i<<" "<<j<<" "<<mp[i][ii]+mp[jj][j]<<endl;
					}
				}
			}
		}
		int flag=0;
		for(i=0;i<n&&!flag;i++)
		{
			for(j=0;j<n&&!flag;j++)
			{
				if(mp[i][j]!=1)
				{
					if(m[i][j][mp[i][j]]);
					else flag=1;
				}
			}
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
} 