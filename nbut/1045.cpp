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
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int t,n,m,i,j;
	char a[22];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			scanf("%d %d %s",&n,&m,a);
			printf("%d ",n);
			for(i=0;i<strlen(a);i++)
			{
				for(j=0;j<m;j++)
				{
					printf("%c",a[i]);
				}
			}
			puts("");
		}
	}
	return 0;
}