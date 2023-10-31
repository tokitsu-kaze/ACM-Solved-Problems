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
using namespace std;
int main()
{
	int n,a[10010],i;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<a[n-1]<<endl;
	}
}