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
	int n,a,sum;
	while(cin>>n)
	{
		sum=0;
		while(n--)
		{
			cin>>a;
			sum^=a;
		}
		if(sum) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
    return 0;
}