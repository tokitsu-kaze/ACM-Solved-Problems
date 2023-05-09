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
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
int main()
{
	int i,j;
	char a[1010],b[1010];
	while(gets(a))
	{
		j=0;
		mem(b,0);
		for(i=0;i<strlen(a);i++)
		{
			if(a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u')
			{
				b[j++]='w';
				b[j++]='e';
				i+=2;
			}
			else b[j++]=a[i];
		}
		cout<<b<<endl;
	}
	return 0;
} 