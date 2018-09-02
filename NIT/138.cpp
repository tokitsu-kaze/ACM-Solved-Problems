#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
using namespace std;
int main()
{
	int t,x,y,a[]={1000,2,6,4,5,2,10,10,10,21,25,100,214,216,1};
	while(cin>>t)
	{
		sort(a,a+15);
		while(t--)
		{
			cin>>x>>y;
			if((x+y)%2==0)  cout<<a[(x+y)/2-1]<<endl;
			else cout<<(int)(a[(x+y-1)/2-1]+a[(x+y-1)/2])/2<<endl;
		}
	}
    return 0;
}