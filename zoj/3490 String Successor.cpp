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
	int t,n,pos,i,flag,flag1,j,post,flag2;
	char a[1111],ans[1111];
	while(~scanf("%d",&t))
	{
		while(t--)
		{
			getchar();
			flag=0;
			mem(ans,0);
			mem(a,0);
			scanf("%s %d",a,&n);
		/*	for(i=0;i<strlen(a);i++)
			{
				if((a[i]>='0'&&a[i]<='9')||(a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
				{
					flag=1;
					break;
				}
			}*/
			for(j=1;j<=n;j++)
			{
				pos=strlen(a)-1;
				flag1=0;
				flag2=0;
				post=pos;
				while(pos>=0&&!((a[pos]>='0'&&a[pos]<='9')||(a[pos]>='a'&&a[pos]<='z')||(a[pos]>='A'&&a[pos]<='Z')))
				{
					pos--;
				}
				while(pos>=0&&(a[pos]=='9'||a[pos]=='z'||a[pos]=='Z'))
				{
					while(pos>=0&&a[pos]=='9')
					{
						a[pos]='0';
						pos--;
						flag1=1;
						post=pos;
						while(pos>=0&&!((a[pos]>='0'&&a[pos]<='9')||(a[pos]>='a'&&a[pos]<='z')||(a[pos]>='A'&&a[pos]<='Z')))
						{
							pos--;
						}
					}
					while(pos>=0&&a[pos]=='z')
					{
						a[pos]='a';
						pos--;
						flag1=1;
						post=pos;
						while(pos>=0&&!((a[pos]>='0'&&a[pos]<='9')||(a[pos]>='a'&&a[pos]<='z')||(a[pos]>='A'&&a[pos]<='Z')))
						{
							pos--;
						}
					}
					while(pos>=0&&a[pos]=='Z')
					{
						a[pos]='A';
						pos--;
						flag1=1;
						post=pos;
						while(pos>=0&&!((a[pos]>='0'&&a[pos]<='9')||(a[pos]>='a'&&a[pos]<='z')||(a[pos]>='A'&&a[pos]<='Z')))
						{
							pos--;
						}
					}
				}
	//			cout<<pos<<endl;
				flag=0;
				if(pos<0)
				{
					pos=post;
					flag=1;
				}
				if(flag1&&flag&&pos>=0)
				{
					pos++;
					a[strlen(a)+1]='\0';
					for(i=strlen(a);i>pos;i--)
					{
						a[i]=a[i-1];
					}
					a[pos]=a[pos+1];
					flag2=1;
				}
	//			cout<<pos<<endl;
				if(pos<0)
				{
					pos=0;
					ans[0]=a[post+1];
					strcat(ans,a);
					mem(a,0);
					strcpy(a,ans);
					mem(ans,0);
					flag2=1;
					a[strlen(a)]='\0';
				}
				if(flag2&&a[pos]!='0');
				else a[pos]++;
				puts(a);
			}
			puts("");
		}
	}
	return 0;
}
/*
7
(Z9z9) 1000
:-( 1000
1:-(1 1000
:1-(1 1000
1:1-(1 1000
cirno=8 2000
X 3000
*/