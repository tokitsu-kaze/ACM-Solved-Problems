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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,(b),sizeof(a))
#define PI acos(-1.0)
#define MAX 200000+10
using namespace std;
typedef long long ll;
int main()
{ 
	ll t,n,m,i,a,sum,max;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			sum=max=0;
			for(i=0;i<n;i++)
			{
				scanf("%lld",&a);
				sum+=a;
				if(a>max) max=a;
			}
			if(m>=n) cout<<max<<endl;
			else
			{
				if(sum%m) sum=sum/m+1;
				else sum/=m;
				if(sum>max) cout<<sum<<endl;
				else cout<<max<<endl;
			}
		}
	}
    return 0;
}