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
	int n,max,m;
	char s[16],c[16];
	map<string ,int> a;
	while(cin>>m)
	{
		while(m--)
		{
			cin>>n;
			max=0;
			a.clear();
			while(n--)
			{
				cin>>s;
				a[s]++;
				if(a[s]>max)
				{
					max=a[s];
					strcpy(c,s);
				}
			}
			cout<<c<<endl;
		}
	}
}