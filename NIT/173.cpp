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
const int MAX=1e4+10;
const ll mod=1e6;
int main()
{
	int i,len,flag;
	char a[1111],b[1111];
	map<char,int> m;
	m['A']=1;
	m['H']=1;
	m['I']=1;
	m['M']=1;
//	m['m']=1;
	m['O']=1;
	m['o']=1;
	m['T']=1;
	m['U']=1;
	m['V']=1;
	m['v']=1;
	m['W']=1;
	m['w']=1;
	m['X']=1;
	m['x']=1;
	m['Y']=1;
	while(~scanf("%s",a))
	{
		len=strlen(a);
		strcpy(b,a);
		flag=0;
		for(i=0;i<len;i++)
		{
			if(!m[a[i]]&&a[i]!='p'&&a[i]!='q'&&a[i]!='b'&&a[i]!='d')
			{
				flag=1;
				break;
			}
			if(a[i]=='p') a[i]='q';
			else if(a[i]=='q') a[i]='p';
			if(a[i]=='b') a[i]='d';
			else if(a[i]=='d') a[i]='b';
		}
	//	cout<<b<<endl;
		reverse(a,a+len);
		if(strcmp(a,b)) flag=1;
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}
/*
pppqqq
dqAoApb
*/