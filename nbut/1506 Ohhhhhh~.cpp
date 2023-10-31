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
	int n;
	while(~scanf("%d",&n))
	{
		putchar('O');
		while(n--) putchar('h');
		puts("~");
	}
	return 0;
}