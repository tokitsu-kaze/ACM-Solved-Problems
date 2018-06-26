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
	int t,n,m,i,a[110],sum;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			mem(a,0);
			sum=0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
				a[i]=100-a[i];
			}
			sort(a,a+n);
			for(i=0;i<n;i++)
			{
				sum+=a[i];
				if(sum>m) break;
			}
			cout<<i<<endl;
		}
	}
    return 0;
}