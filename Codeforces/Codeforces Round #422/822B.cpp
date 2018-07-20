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
const int MAX=100000+10;
const ll mod=1e9+7;
int res[1010][1010];
int main()
{
	int n,m,i,j,minn,cnt,pos;
	char a[1111],b[1111];
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%s%s",a,b);
		minn=INF;
		pos=-1;
		for(i=0;i<m-n+1;i++)
		{
			cnt=0;
			for(j=0;j<n;j++)
			{
				if(b[i+j]==a[j]);
				else
				{
					res[i][cnt++]=j+1;
				}
			}
			if(cnt<minn)
			{
				minn=cnt;
				pos=i;
			}
		}
		printf("%d\n",minn);
		if(minn)
		{
			for(i=0;i<minn;i++)
			{
				if(!i) printf("%d",res[pos][i]);
				else printf(" %d",res[pos][i]);
			}
			puts("");
		}
	}
	return 0;
}