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
const int MAX=1e6+10;
const ll mod=1e9+6;
int prime[MAX],res[MAX],k;
void init()
{
	int i,j;
	mem(prime,0);
	mem(res,0);
	k=0;
	for(i=2;i<=MAX;i++)
	{
		if(!prime[i])
		{
			res[k++]=i;
			for(j=i+i;j<MAX&&i<=sqrt(MAX);j+=i)
			{
				prime[j]=i;
			}
		}
	}
}
int main()
{
	int i,n,s;
	init();
//	for(i=0;i<k;i++) cout<<res[i]<<endl;
//	cout<<k<<endl;
	while(~scanf("%d",&n))
	{
		s=0;
		if(!prime[n])
		{
			puts("1");
			continue;
		}
		for(i=k-1;i>=0;i--)
		{
			if(res[i]<=n&&(n%res[i]>1||n%res[i]==0))
			{
				if(!prime[n-res[i]])
				{
					s=2;
					break;
				}
			}
		}
		if(s==0) s=3;
		printf("%d\n",s);
	}
	return 0;
}