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
	int i,sum;
	char c[1001];
	while(cin>>c)
	{
		sum=0;
		for(i=0;i<strlen(c);i++)
		{
			sum+=c[i]-'0';
		}
		cout<<sum%9<<endl;
	}
}