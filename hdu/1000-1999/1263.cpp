////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: tokitsukaze
////Nickname: tokitsukaze
////Run ID: 
////Submit time: 2017-02-27 19:37:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1263
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1664KB
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
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,i,v;
    string fruit,place;
    while(cin>>t)
    {
		while(t--)
		{
			cin>>n;
			map<string,int> mf;
			map<string,map<string,int> > mp;
			map<string,int> ::iterator itf;
			map<string,map<string,int> > ::iterator itp;
			while(n--)
			{
				getchar();
				cin>>fruit>>place>>v;
				mp[place][fruit]+=v;
			}
			for(itp=mp.begin();itp!=mp.end();itp++)
			{
				cout<<itp->first<<endl;
				mf=itp->second;
				for(itf=mf.begin();itf!=mf.end();itf++)
				{
					printf("   |----%s(%d)\n",itf->first.c_str(),itf->second);
				}
			}
			if(t) puts("");
		}
	}
    return 0;
}