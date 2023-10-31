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
	int n;
	char c[11];
	while(cin>>n)
	{
		while(n--)
		{
			cin>>c;
			if(strlen(c)>3) puts("3");
			else
			{
				if((c[0]=='o')+(c[1]=='n')+(c[2]=='e')>=2) puts("1");
				else puts("2");
			}
		}
	}
    return 0;
}