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
const int MAX=1e6+10;
const ll mod=1e6;
void getnext(char *b,int *next,int len)
{
	int i,j;
	i=0;
	mem(next,0);
	j=next[0]=-1;
	while(i<len)
	{
		if(j==-1||b[i]==b[j])
		{
			i++;
			j++;
			next[i]=j;
		}
		else j=next[j];
	}
}
int next1[MAX];
int main()
{
	int len,i,cas=1;
	char a[MAX];
	while(~scanf("%d",&len)&&len)
	{
		scanf("%s",a);
		getnext(a,next1,len);
		printf("Test case #%d\n",cas++);
		for(i=1;i<=len;i++)
		{
//			cout<<i<<" "<<next1[i]<<endl;
			if(i%(i-next1[i])==0)
			{
				if(i/(i-next1[i])>1) printf("%d %d\n",i,i/(i-next1[i]));
			}
		}
		puts("");
	}
	return 0;
}