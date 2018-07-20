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
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int main()
{
	int i,j,t,mp[333],len,flag,lenb,pos;
	char a[33],b[MAX],s[MAX];
	while(~scanf("%s%s",a,b))
	{
		lenb=strlen(b);
		mem(mp,0);
		for(i=0;i<strlen(a);i++)
		{
			mp[a[i]]=1;
		}
		pos=-1;
		for(i=0;i<lenb;i++)
		{
			if(b[i]=='*')
			{
				pos=i;
				break;
			}
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%s",s);
			len=strlen(s);
			if((len<lenb-1)||(len==lenb-1&&pos==-1)||(len>lenb&&pos==-1))
			{
				puts("NO");
				continue;
			}
			flag=0;
			if(pos==-1) pos=len;
			for(i=0;i<pos;i++)
			{
				if(b[i]>='a'&&b[i]<='z')
				{
					if(b[i]!=s[i])
					{
						flag=1;
						break;
					}
				}
				else if(b[i]=='?')
				{
					if(mp[s[i]]);
					else
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)
			{
				puts("NO");
				continue;
			}
			for(i=lenb-1,j=len-1;i>pos;i--,j--)
			{
				if(b[i]>='a'&&b[i]<='z')
				{
					if(b[i]!=s[j])
					{
						flag=1;
						break;
					}
				}
				else if(b[i]=='?')
				{
					if(mp[s[j]]);
					else
					{
						flag=1;
						break;
					}
				}
			}
			if(flag)
			{
				puts("NO");
				continue;
			}
			for(i=pos;i<=j;i++)
			{
				if(mp[s[i]])
				{
					flag=1;
					break;
				}
	//			cout<<s[i]<<endl;
			}
			if(flag) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
/*
abc
ab*aba
6
absdsdsdaba
abaaba
absabaa
abssaba
abbba
*/