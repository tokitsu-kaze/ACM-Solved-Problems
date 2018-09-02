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
char s[100010];
int main()
{
	int t,n,m;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n>>m;
			cin>>s;
			if(s[m-2]=='b'&&s[m]=='b'||(s[m-2]=='a'&&s[m]=='a')||(m==1&&s[m]=='a')||(m==n&&s[m-1]=='a')) puts("defensive");
			else puts("offensive");
		}
	}
    return 0;  
}