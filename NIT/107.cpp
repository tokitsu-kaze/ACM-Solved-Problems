#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct abc
{
	char c[3];
}c[4];
int main()
{
	int flag,i,j;
	char a[3];
	while(~scanf("%s",c[0].c))
	{
		flag=0;
		for(i=1;i<=2;i++)
		{
			scanf("%s",c[i].c);
		}
		for(i=0;i<=2;i++)
		{
			if(strcmp(c[i].c,"AB")==0)
			{
				for(j=0;j<=2;j++)
				{
					if(strcmp(c[j].c,"BC")==0)
					{
						if(strcmp(c[3-i-j].c,"AB")==0||strcmp(c[3-i-j].c,"BC")==0||strcmp(c[3-i-j].c,"AC")==0)
						{
							flag=1;
							break;
						}
					}
				}
			}
			else if(strcmp(c[i].c,"AC")==0)
			{
				for(j=0;j<=2;j++)
				{
					if(strcmp(c[j].c,"CB")==0)
					{
						if(strcmp(c[3-i-j].c,"AC")==0||strcmp(c[3-i-j].c,"CB")==0||strcmp(c[3-i-j].c,"AB")==0)
						{
							flag=2;
							break;
						}
					}
				}
			}
			else if(strcmp(c[i].c,"BA")==0)
			{
				for(j=0;j<=2;j++)
				{
					if(strcmp(c[j].c,"AC")==0)
					{
						if(strcmp(c[3-i-j].c,"BA")==0||strcmp(c[3-i-j].c,"AC")==0||strcmp(c[3-i-j].c,"BC")==0)
						{
							flag=3;
							break;
						}
					}
				}
			}
			else if(strcmp(c[i].c,"BC")==0)
			{
				for(j=0;j<=2;j++)
				{
					if(strcmp(c[j].c,"CA")==0)
					{
						if(strcmp(c[3-i-j].c,"BC")==0||strcmp(c[3-i-j].c,"CA")==0||strcmp(c[3-i-j].c,"BA")==0)
						{
							flag=4;
							break;
						}
					}
				}
			}
			else if(strcmp(c[i].c,"CA")==0)
			{
				for(j=0;j<=2;j++)
				{
					if(strcmp(c[j].c,"AB")==0)
					{
						if(strcmp(c[3-i-j].c,"CA")==0||strcmp(c[3-i-j].c,"AB")==0||strcmp(c[3-i-j].c,"CB")==0)
						{
							flag=5;
							break;
						}
					}
				}
			}
			else if(strcmp(c[i].c,"CB")==0)
			{
				for(j=0;j<=2;j++)
				{
					if(strcmp(c[j].c,"BA")==0)
					{
						if(strcmp(c[3-i-j].c,"CB")==0||strcmp(c[3-i-j].c,"BA")==0||strcmp(c[3-i-j].c,"CA")==0)
						{
							flag=6;
							break;
						}
					}
				}
			}
			if(flag) break;
		}
		if(flag==0) puts("The input is not true!");
		else if(flag==1) puts("C<B<A");
		else if(flag==2) puts("B<C<A");
		else if(flag==3) puts("C<A<B");
		else if(flag==4) puts("A<C<B");
		else if(flag==5) puts("B<A<C");
		else if(flag==6) puts("A<B<C");
	}
	return 0;
}