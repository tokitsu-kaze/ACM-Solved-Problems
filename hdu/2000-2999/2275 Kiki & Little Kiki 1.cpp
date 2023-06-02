////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-06-04 15:46:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2275
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:5000KB
//////////////////System Comment End//////////////////
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
const ll mod=200907;
int main()
{
	int n,x;
	char op[11];
	while(~scanf("%d",&n))
	{
		multiset<int> s;
		multiset<int> ::iterator it1,it2;
		while(n--)
		{
			getchar();
			scanf("%s %d",op,&x);
			if(op[1]=='u') s.insert(x);
			else if(op[1]=='o')
			{
				if(x<*s.begin()) puts("No Element!");
				else
				{
					it1=s.find(x); 
					if(it1!=s.end())
					{
						printf("%d\n",*it1);
						s.erase(it1);
					}
					else
					{
						s.insert(x);
						it1=it2=s.find(x);
						it2--;
						printf("%d\n",*it2);
						s.erase(it1);
						s.erase(it2);
					}
				}
			}
		}
		puts("");
	}
	return 0;
}