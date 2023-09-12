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
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int i,cnt0,cnt1,n;
	char a[111];
	while(~scanf("%d%s",&n,a))
	{
		cnt0=cnt1=0;
		for(i=0;i<n;i++)
		{
			if(a[i]=='1')
			{
				while(cnt0>1)
				{
					printf("0");
					cnt0--;
				}
				cnt0=0;
				cnt1++;
			}
			else
			{
				if(cnt1) printf("%d",cnt1);
				cnt1=0;
				cnt0++;
			}
		}
		if(cnt1) printf("%d",cnt1);
		else
		{
			while(cnt0>0)
			{
				printf("0");
				cnt0--;
			}
		}
		puts("");
	}
	return 0;
}