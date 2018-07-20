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
const int MAX=100000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int a[MAX];
int main()
{
	int n,i,j,cnt1,cnt2,s1,s2;
	while(~scanf("%d",&n))
	{
		mem(a,0);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		s1=s2=cnt1=cnt2=0;
		i=0;
		j=n-1;
		while(i<=j)
		{
			s1+=a[i++];
			cnt1++;
			while(s1>s2&&i<=j)
			{
				s2+=a[j--];
				cnt2++;
			}
			if(s1==s2&&i==j)
			{
				cnt1++;
				break;
			}
		}
		printf("%d %d\n",cnt1,cnt2);
	}
	return 0;
}