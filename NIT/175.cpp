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
const int MAX=100000;
const ll mod=1e9+7;
int hashing[2*MAX+10];
int main()
{
	int n,k,cnt,i,j,a,ans,sum,bgin,ed;
	while(~scanf("%d%d",&n,&k))
	{
		ans=0;
		mem(hashing,0);
		bgin=INF;
		ed=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			hashing[a+MAX]++;
			ans=max(ans,hashing[a+MAX]);
			bgin=min(bgin,a+MAX);
			ed=max(ed,a+MAX);
	//		cout<<a+MAX<<endl;
		}
		if(n==1)
		{
			puts("1");
			continue;
		}
	//	cout<<ans<<endl;
		sum=0;
		for(j=bgin;j<=bgin+k;j++)
		{
			sum+=hashing[j];
		}
		ans=max(ans,sum);
		for(i=bgin;i<=ed&&j<=ed;i++)
		{
	//		cout<<i<<endl;
			
			for(;j<=i+k&&j<=ed;j++)
			{
				sum+=hashing[j];
			}
			ans=max(ans,sum);
			sum-=hashing[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
1 1
10000

2 1
-10000 100000

2 2
10 1

2 1
1 2

3 2
1 2 5

3 2
1 2 3

5 2
-1 1 1 1 10

5 100000
1 5 10 111 -1

5 1
0 0 0 2 2
*/