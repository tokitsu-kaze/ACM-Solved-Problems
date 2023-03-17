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
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define eps 1e-12
#define MAX 100000+10
#define EDGE 20000+10//±ßµÄÌõÊý 
using namespace std;
typedef long long ll;
int main()
{
	int n,i,flag,cnt,flag2,temp,flag3,t,cnth;
	char a[111],ans[111];
	while(gets(a))
	{
		mem(ans,0);
		flag=flag2=cnt=cnth=0;
		for(i=strlen(a)-1;i>=0;i--)
		{
			if(flag)
			{
				ans[i]=a[i];
				if(a[i]!='-')
				{
					cnt++;
				}
				else flag2=1;
			}
			if(a[i]=='.')
			{
				flag=1;
				if(i+2!=strlen(a))
				{
					ans[i+2]=a[i+2];
					if(!cnth) cnth=2;
				}
				if(i+1!=strlen(a))
				{
					ans[i+1]=a[i+1];
					if(!cnth) cnth=1;
				}
				ans[i]=a[i];
				cnt=0;
			}
		}
		if(!flag)
		{
			cnt=strlen(a);
			if(a[0]=='-')
			{
				flag2=1;
				cnt--;
			}
			strcpy(ans,a);
		}
		flag3=0;
		temp=cnt%3;
		if(temp==0) temp=3;
		t=0;
		if(flag2) cout<<"(";
		cout<<"$";
		for(i=0;i<strlen(ans);i++)
		{
			if(ans[i]=='-')
			{
				continue;
			}
			else t++;
			cout<<ans[i];
			if(flag3&&ans[i]!='.') temp++;
			if(flag3&&temp==3&&ans[i]!='.'&&ans[i+1]!='.'&&ans[i+1]!='\0')
			{
				cout<<",";
				temp=0;
			}
			if(!flag3&&t==temp&&temp!=cnt)
			{
				cout<<",";
				flag3=1;
				temp=0;
			}
		}
		if(cnth==0) cout<<".00"; 
		else if(cnth==1) cout<<"0";
		if(flag2) cout<<")";
		puts("");
	}
	return 0;
}