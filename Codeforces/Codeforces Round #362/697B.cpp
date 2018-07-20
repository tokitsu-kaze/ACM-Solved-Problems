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
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1000000+10;
const ll mod=1e6;
int main()
{
	int i,j,len,cnt,flag,flag2;
	char a[100011],ans[100011];
	while(~scanf("%s",&a))
	{
		len=strlen(a);
		cnt=0;
		flag=0;
		flag2=0;
		for(i=0;i<len;i++)
		{
			if(flag)
			{
				cnt=cnt*10+a[i]-'0';
			}
			if(a[i]=='e') flag=1;
		}
		flag=0;
		for(i=0,j=0;i<len;i++)
		{
			if(a[i]=='e') break;
			if(flag)
			{
				if(a[i]!='0') flag2=1;
				if(cnt==0) ans[j++]='.';
				cnt--;
			}
			if(a[i]=='.') flag=1;
			else ans[j++]=a[i];
		}
		while(cnt>0)
		{
			ans[j++]='0';
			cnt--;
		}
		ans[j]='\0';
		i=0;
		for(i=0;i<j;i++)
		{
			if(ans[i]!='0') break;
		}
		if(ans[i]=='.') i--;
		if(!flag2)
		{
			for(;i<j;i++)
			{
				if(ans[i]=='.') break;
				putchar(ans[i]);
			}
			puts("");
		}
		else puts(ans+i);
	}
	return 0;
}