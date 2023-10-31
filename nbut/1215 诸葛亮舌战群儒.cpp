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
	int a,b,n,count;
    while(cin>>a>>n)
    {
		count=0;
		while(n--)
		{
			scanf("%d",&b);
			if(b<a) count++;
		}
		cout<<count<<endl;
    }
    return 0;
}