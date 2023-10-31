#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
char s[MAX];
int main()
{
	int t,k,i,j,x,pos,n;
	t=1;
//	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		scanf("%d",&k);
		queue<int> q[11];
		i=1;
		j=1;
		string res;
		while(i<=n-k)
		{
			//[i,i+k]
		//	printf("%d %d %d\n",i,j,k);
			while(j<=i+k)
			{
				q[s[j]-'0'].push(j);
				j++;
			}
			x=0; 
			//枚举我们要选哪个数 
			for(;x<=9;x++)
			{
				if(q[x].size())
				{
					res+=('0'+x);
					pos=q[x].front();
					k-=pos-i;
					break;
				}
			}
			for(x=i;x<=pos;x++)
			{
				q[s[x]-'0'].pop();
			}
			i=pos+1;
		}
		reverse(res.begin(),res.end());
		while(res.size()>1&&res.back()=='0') res.pop_back();
		reverse(res.begin(),res.end());
		cout<<res<<"\n";
	}
	return 0;
}
// CF1765N
