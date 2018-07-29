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
using namespace std;
int main()
{
	int i,len,pos,x,y;
	char s[205]; 
	int dir[4][2]={10,0,0,10,-10,0,0,-10};
	while(~scanf("%s",s))
	{
		len=strlen(s);
		x=300;
		y=420; 
		pos=0;
		puts("300 420 moveto");
		for(i=0;i<len;i++)
		{
			x+=dir[pos][0];
			y+=dir[pos][1];
			printf("%d %d lineto\n",x,y);
			if(s[i]=='A') pos--;
			else pos++;
			pos=(pos+4)%4;
		}
		x+=dir[pos][0];
		y+=dir[pos][1];
		printf("%d %d lineto\n",x,y);
		puts("stroke");
		puts("showpage");
	}
	return 0;
}