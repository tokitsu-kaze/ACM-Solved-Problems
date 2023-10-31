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
int lowestpos(int n)
{
	int count=0;
	while(n)
	{
		n>>=1;
		count+=n;
	}
	return count+1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<lowestpos(n)<<endl;
	}
}