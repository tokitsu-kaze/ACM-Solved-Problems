#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1e6+10;
struct KMP
{
	int nex[MAX],len;
	char t[MAX];
	void get_next(char *s)
	{
		int i,j;
		len=strlen(s+1);
		for(i=1;i<=len;i++) t[i]=s[i];
		t[len+1]='\0';
		nex[0]=nex[1]=0;
		j=0;
		for(i=2;i<=len;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			nex[i]=j;
		}
	}
	
	// s[1..n], return all pos t in s 
	vector<int> match(char *s)
	{
		int n,i,j;
		vector<int> res;
		n=strlen(s+1);
		for(i=1,j=0;i<=n;i++)
		{
			while(j&&t[j+1]!=s[i]) j=nex[j];
			if(t[j+1]==s[i]) j++;
			if(j==len)
			{
				res.push_back(i-len+1);
				j=nex[j];
			}
		}
		return res;
	}
}kmp;// kmp.get_next(s); s[1..len]
char s[MAX];
int main()
{
	int i,q,x,y,d;
	scanf("%s",s+1);
	kmp.get_next(s);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		x=kmp.nex[x];
		y=kmp.nex[y];
		while(x!=y)
		{
			if(x<y) swap(x,y);
			// 所有长度大于等于 |s|/2 的 border 是 1 个等差数列
			// 这个等差数列内的所有border一起判断
			if(kmp.nex[x]*2>=x)
			{
				d=x-kmp.nex[x];// 公差 
				if(x%d==y%d) x=y;// x 和 y 在同一个等差数列中
				else x=x-x/2/d*d;// 找到等差数列首项
			}
			else x=kmp.nex[x];
		}
		printf("%d\n",x);
	}
	return 0;
}

