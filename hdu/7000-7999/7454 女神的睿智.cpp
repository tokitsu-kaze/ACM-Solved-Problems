#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e7+10;
const int mod=998244353;
int main()
{
	int t,i,cnt[4],id[256];
	char s[11];
	memset(id,0,sizeof id);
	id['R']=0;
	id['G']=1;
	id['B']=2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		memset(cnt,0,sizeof cnt);
		for(i=0;i<8;i++) cnt[id[s[i]]]++;
		string res,tmp;
		for(i=0;i<8;i+=2) res+=s[i];
		tmp=res;
		res="";
		for(i=0;i<4;i+=2) res+=tmp[i];
		if(res[0]==res[1])
		{
			printf("%c\n",res[0]);
			continue;
		}
		if(cnt[id[res[0]]]>cnt[id[res[1]]]) printf("%c\n",res[0]);
		else if(cnt[id[res[0]]]<cnt[id[res[1]]]) printf("%c\n",res[1]);
		else puts("N");
	}
	return 0;
}
