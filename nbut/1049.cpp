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
	int n,i,flag=0;
	double a,b;
    while(cin>>n)
    {
		if(n<=0) break;
		if(flag) puts("");
		for(i=1;i<=n;i++)
		{
			cin>>a>>b;
			if((int)(a*100000)==(int)(b*100000)) printf("CASE# %d : YES\n",i);
			else printf("CASE# %d : NO\n",i);
		}
		flag=1;
    }
    return 0;
}