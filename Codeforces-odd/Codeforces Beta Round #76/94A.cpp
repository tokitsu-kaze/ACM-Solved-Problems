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
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const ll mod=1e9+7;
const int MAX=1e5+10;
int main()
{
	int i,j,ans;
	map<string,int> m;
	char a[1111],b[111];
	while(~scanf("%s",a))
	{
		m.clear();
		for(i=0;i<10;i++)
		{
			scanf("%s",b);
			m[b]=i;
		}
		ans=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<10;j++)
			{
				b[j]=a[i*10+j];
			}
			b[10]='\0';
			ans=ans*10+m[b];
		}
		printf("%08d\n",ans);
	}
	return 0;
}