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
	int t,a,b,i,j,c,d,cnt;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>a>>b;
			cnt=0;
			for(i=a;i<=b;i++)
			{
				c=i%1000;
				d=i%100;
				for(j=1;j<=12;j++)
				{
					if(j*j==c||j*j==d) cnt++;
				}
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}