#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
int main()
{
	int a[10],i,sum;
	while(cin>>a[0])
	{
		sum=0;
		for(i=1;i<6;i++)
		{
			cin>>a[i];
			if(i%2) sum+=a[i-1]*a[i];
		}
		sort(a,a+6);
		if(a[5]*a[5]==sum) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}