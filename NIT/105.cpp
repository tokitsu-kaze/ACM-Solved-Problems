#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	int len;
	char s[101];
	while(gets(s))
	{
		len=strlen(s);
		sort(s,s+len);
		cout<<s<<endl;
	}
	return 0;
}