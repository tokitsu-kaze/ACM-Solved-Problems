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
	char a[51];
	while(gets(a))
	{
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]>='A'&&a[i]<='Z') a[i]+=32;
		}
		cout<<a<<endl;
	}
	return 0;
}