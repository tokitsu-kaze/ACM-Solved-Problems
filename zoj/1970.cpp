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
const double eps=1e-9;
const int MAX=100000+10;
const ll mod=10000;
char a[MAX],b[MAX];
int main()
{
	int lena,lenb,i,j;
	while(~scanf("%s %s",a,b))
	{
		lena=strlen(a);
		lenb=strlen(b);
		for(i=0,j=0;i<lenb;i++)
		{
			if(a[j]==b[i]&&j<lena) j++;
		}
		if(j==lena) puts("Yes");
		else puts("No");
	}
	return 0;
}