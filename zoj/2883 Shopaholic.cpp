#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define MAX 100000000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,i,a[20001],sum;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			mem(a,0);
			sum=0;
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a,a+n);
			for(i=n-3;i>=0;i-=3)
			{
				sum+=a[i];
			}
			cout<<sum<<endl;
		}
    }
    return 0;
} 