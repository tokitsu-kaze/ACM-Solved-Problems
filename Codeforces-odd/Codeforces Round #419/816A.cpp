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
#include <ctime>
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=3e5+10;
const ll mod=10000;
int main()
{
	int i,a,b,temp;
	char t1[111],t2[111];
	while(~scanf("%d:%d",&a,&b))
	{
		temp=a*100+b;
		for(i=0;;i++)
		{
			sprintf(t1,"%04d",temp);
			t1[4]='\0';
	//		cout<<t1<<endl;
			strcpy(t2,t1);
	//		cout<<t2<<endl;
			reverse(t1,t1+4);
			if(strcmp(t1,t2)==0) break;
			temp++;
			if(temp%100==60) temp=temp+100-60;
			if(temp==2400) temp=0;
		}
		printf("%d\n",i);
	}
	return 0;
}