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
const int MAX=100+10;
const int EDGE=100000+10;//�ߵ�����
typedef long long ll;
int main()
{
	int cnt=0,len,i,ans=0,flag;
	char a[111];
	while(gets(a))
	{
		if(a[0]=='+') cnt++;
		else if(a[0]=='-') cnt--;
		else
		{
			len=flag=0;
			for(i=0;i<strlen(a);i++)
			{
				if(flag) len++;
				if(a[i]==':') flag=1;
			}
			ans+=cnt*len;
		}
	}
	printf("%d\n",ans);
	return 0;
}