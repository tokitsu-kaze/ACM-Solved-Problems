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
	long long n,count;
	while(cin>>n)
	{
		count=n/10*7;
		n%=10;
		if(n>=3) count+=n/3*2;
		n%=3;
		if(n==2) count++;
		cout<<count<<endl;
	}
}