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
const int MAX=4000000;
const ll mod=1e6;
int mp[2000*2000*4+100];
int main()
{
	int k,n,i,j,a[2222],b[2222],sum[2222],ans,res[2222],cnt;
	while(~scanf("%d%d",&k,&n))
	{
		ans=0;
		cnt=0;
		mem(sum,0);
		map<int,int> tag;
		for(i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
			if(i) sum[i]=sum[i-1]+a[i];
			else sum[i]=a[i];
			if(!tag[sum[i]])
			{
				tag[sum[i]]=1;
				res[cnt++]=sum[i];
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
			for(j=0;j<cnt;j++)
			{
				mp[b[i]-res[j]+MAX]++;
				int temp=mp[b[i]-res[j]+MAX];
	//			cout<<sum[j]<<" "<<b[i]-res[j]<<endl;
				if(temp==n) ans++;
	//			cout<<ans<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
5 2
-5 5 0 20 5
10 35
2 2
-2000 -2000
3998000 4000
*/