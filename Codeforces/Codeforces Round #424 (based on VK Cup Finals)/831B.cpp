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
const int MAX=1e5+10;
const ll mod=1e6;
int main()
{
	int i;
	char a[1111],b[1111],temp[1111];
	while(~scanf("%s%s%s",a,b,temp))
	{
		map<char,int> mp;
		for(i=0;i<strlen(a);i++)
		{
			mp[a[i]]=i+1;
			mp[a[i]-'a'+'A']=i+1;
		}
		for(i=0;i<strlen(temp);i++)
		{
			if(!mp[temp[i]]) putchar(temp[i]);
			else
			{
				if(temp[i]>='A'&&temp[i]<='Z') printf("%c",b[mp[temp[i]]-1]-'a'+'A');
				else putchar(b[mp[temp[i]]-1]);
			}
		}
		puts("");
	}
	return 0;
}