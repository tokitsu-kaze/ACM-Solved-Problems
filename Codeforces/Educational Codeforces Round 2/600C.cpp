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
const int MAX=2e5+10;
const ll mod=1e9+7;
char s[MAX],ans[MAX];
int bit[333];
int main()
{
	int i,len,cnt,l,r,tag,top;
	char t,temp[111];
	while(~scanf("%s",s))
	{
		len=strlen(s);
		mem(bit,0);
		sort(s,s+len);
		for(i=0;i<len;i++)
		{
			bit[s[i]]++;
		}
		cnt=0;
		for(i='a';i<='z';i++)
		{
			if(bit[i]%2)
			{
				cnt++;
			}
		}
		priority_queue<char> q;
		mem(temp,'.');
		tag=cnt/2;
		top=0;
		for(i='a';i<='z';i++)
		{
			if(bit[i]%2)
			{
				if(temp[top]=='.'&&top<tag) temp[top++]=(char)i;
				else q.push((char)i);
			}
		}
		l=0;
		r=len-1;
		if(len%2)
		{
			int flag=0;
			while(sz(q)>1)
			{
				t=q.top();
				q.pop();
				bit[t]--;
				bit[temp[flag]]++;
				if(tag)
				{
					flag++;
					flag%=tag;
				}
			}
		}
		else
		{
			int flag=0;
			while(!q.empty())
			{
				t=q.top();
				q.pop();
				bit[t]--;
				bit[temp[flag]]++;
				if(tag)
				{
					flag++;
					flag%=tag;
				}
			}
		}
		for(i='a';i<='z';i++)
		{
			if(bit[i]%2)
			{
				bit[i]--;
				ans[len/2]=(char)i;
			}
			while(bit[i])
			{
				ans[l++]=ans[r--]=(char)i;
				bit[i]-=2;
			}
		}
		ans[len]='\0';
		puts(ans);
	}
	return 0;
}
/*
aaabcde
aaabcdef
*/