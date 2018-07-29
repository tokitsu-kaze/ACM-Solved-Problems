#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int main()
{
	int len,i,a,b,c,d;
	char s[1001];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		a=b=c=-1;
		d=INT_MAX;
		for(i=0;i<len;i++)
		{
			if(s[i]=='a')
			{
				a=i;
				if(b!=-1&&c!=-1)
				d=min(d,a-min(b,c)+1);
			}
			else if(s[i]=='b')
			{
				b=i;
				if(a!=-1&&c!=-1)
				d=min(d,b-min(a,c)+1);
			}
			else if(s[i]=='c')
			{
				c=i;
				if(a!=-1&&b!=-1)
				d=min(d,c-min(a,b)+1);
			}
		}
		printf("%d\n",d);
	}
	return 0;
}