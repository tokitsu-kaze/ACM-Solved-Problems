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
using namespace std;
typedef long long ll;
int main()
{
	int a[31],i,t,n;
	a[1]=1;
	a[2]=2;
	for(i=3;i<30;i++)
	{
		a[i]=a[i-1]+a[i-2]*2+1;
	}
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			cout<<a[n]<<endl;
		}
	}
	return 0;
}