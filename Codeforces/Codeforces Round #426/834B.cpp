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
const int MAX=1e6+10;
const ll mod=1e9+7;
int main()
{
	int n,k,i,cnt[333],flag[333],now,ans;
	char a[MAX];
	while(~scanf("%d%d",&n,&k))
	{
		scanf("%s",a);
		mem(cnt,0);
		for(i=0;i<n;i++)
		{
			cnt[a[i]]++;
		}
		ans=now=0;
		mem(flag,0);
		for(i=0;i<n;i++)
		{
			if(!flag[a[i]])
			{
				now++;
				flag[a[i]]=1;
			}
			cnt[a[i]]--;
			ans=max(ans,now);
			if(cnt[a[i]]==0) now--;
		}
		if(ans>k) puts("YES");
		else puts("NO");
	}
	return 0;
}