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
	long long a,b,sum;
	while(cin>>a>>b)
	{
		
		sum=1L<<b;
		cout<<a*sum<<endl;
	}
    return 0;
}