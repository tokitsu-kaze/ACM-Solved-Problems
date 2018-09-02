#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	long long n,sum;
	while(cin>>n)
	{
		sum=((1+n)%2142160)*(n%2142160)/2%214216;
		cout<<sum<<endl;
	}
	return 0;
}