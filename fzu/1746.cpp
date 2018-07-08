#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <list> 
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
int main()
{
	int i;
	char a[25][25];
	while(cin>>a[0])
	{
		for(i=1;i<24;i++)
		{
			cin>>a[i];
		}
		if(a[0][5]=='#') puts("Black King");
		else puts("Red General");
	}
	return 0;
}