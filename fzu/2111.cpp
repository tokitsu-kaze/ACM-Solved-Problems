#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[10001];
		scanf("%s",s);
		int len=strlen(s);
		int i=0;
		int n;
		scanf("%d",&n);
		for(int j=1;j<=n;)
		{
			int min='9';
			int point;
			if(i==0&&j==1)
			{
			    point=i;
				for(int k=0;k<len;k++)
				{
					if(s[k]<=min&&s[k]!='0')
					{
						min=s[k];
						point=k;
					}
				}
				if(min==s[0])
				{
					i++;
					continue;
				}
				swap(s[i],s[point]);
				i++;
				j++;
			}
			else
			{
			    point=i;
				for(int k=i;k<len;k++)
				{
					if(s[k]<=min)
					{
						min=s[k];
						point=k;
					}
				}
				if(min==s[i])
				{
					i++;
					continue;
				}
				swap(s[i],s[point]);
				i++;
				j++;
			}
		}
		printf("%s\n",s);
	}
}
/*
100
9012 0
9012 1
9012 2
97200759210 1
97200759210 2
97200759210 3
97200759210 4
97200759210 5
9802946 1
9802946 2
9802946 3
9802946 4
9802946 5
9802946 6
*/