#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-12;
const int MAX=1000000+10;
const int EDGE=100000+10;//±ßµÄÌõÊý
typedef long long ll;
int main()
{
	int len,i,k,l;
	char a[1111],tk[1111],tl[1111];
	while(~scanf("%s",a))
	{
		mem(tk,0);
		mem(tl,0);
		k=l=0;
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			if(a[i]=='Z'||a[i]=='O'||a[i]=='J'||a[i]=='7') tk[k++]=a[i];
			else tl[l++]=a[i];
		}
		for(i=0;i<k;i++)
		{
			if(tk[i]=='Z') putchar(tk[i]);
		}
		for(i=0;i<k;i++)
		{
			if(tk[i]=='O') putchar(tk[i]);
		}
		for(i=0;i<k;i++)
		{
			if(tk[i]=='J') putchar(tk[i]);
		}
		for(i=0;i<k;i++)
		{
			if(tk[i]=='7') putchar(tk[i]);
		}
		tl[l]='\0';
		puts(tl);
	}
	return 0;
}