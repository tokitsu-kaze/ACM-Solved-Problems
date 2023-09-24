#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
bool check(char x)
{
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return 0;
	return 1;
}
int main()
{
	int len,i,cnt;
	char a[3333];
	while(~scanf("%s",a))
	{
		len=strlen(a);
		set<char> s;
		cnt=0;
		for(i=0;i<len;i++)
		{
			if(check(a[i]))
			{
				s.insert(a[i]);
				if(sz(s)>1&&cnt>=2)
				{
					putchar(' ');
					s.clear();
					s.insert(a[i]);
					cnt=0;
				}
				cnt++;
			}
			else
			{
				s.clear();
				cnt=0;
			}
			putchar(a[i]);
		}
		puts("");
	}
	return 0;
}