#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int t,n,m,a[10001],i,j,count;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			mem(a,0);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a,a+n,cmp);
			count=0;
		//	cout<<a[0]<<endl;
			for(i=0;i<n;i++)
			{
				if(a[i]==m) count++;
				else if(a[i]+a[n-1]<=m)
				{
					count++;
					n--;
				}
				else count++;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}