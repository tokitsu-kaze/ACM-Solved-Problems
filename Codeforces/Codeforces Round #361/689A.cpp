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
const ll mod=1e6;
int main()
{
	int n,i,j,flag[11],xx,yy,tag;
	char a[111];
	map<int,pair<int,int> >mp;
	for(i=1;i<=9;i++)
	{
		mp[i]=MP((i-1)/3,i%3==0?3:i%3);
//		cout<<mp[i].fi<<" "<<mp[i].se<<endl;
	}
	mp[0]=MP(3,2);
	while(~scanf("%d%s",&n,a))
	{
		xx=yy=0;
		tag=0;
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			flag[a[i]-'0']++;
			if(a[i]=='0') tag=1;
			for(j=0;j<n;j++)
			{
				xx=max(abs(mp[a[i]-'0'].fi-mp[a[j]-'0'].fi),xx);
				yy=max(abs(mp[a[i]-'0'].se-mp[a[j]-'0'].se),yy);
			}
		}
	//	cout<<xx<<" "<<yy<<endl;
		if(flag[8]&&!flag[7]&&!flag[9]&&!flag[0]) puts("NO");
		else if((!tag&&xx==2&&yy==2)||(tag&&(xx>2||yy>2))) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
5
69870
4
1358
*/