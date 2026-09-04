#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const int MAX=1e5+10;
const int B=350;
int n,a[MAX],cnt[MAX],nex[MAX],res1[MAX],res2[MAX];
void solve1()
{
	int c,x,i,p;
	for(c=1;c<=n;c++)
	{
		if(cnt[c]<=B) continue;
		nex[n+1]=n+1;
		for(i=n;i;i--)
		{
			nex[i]=nex[i+1];
			if(a[i]==c) nex[i]=i;
		}
		for(x=1;x<=n;x++)
		{
			p=nex[1];
			while(p<=n)
			{
				res1[x]++;
				if(p+x+1>n) break;
				p=nex[p+x+1];
			}
		}
	}
}
vector<int> pos[MAX];
int cal(int c,int x)
{
	int pre,cnt;
	pre=-1;
	cnt=0;
	for(auto &p:pos[c])
	{
		if(pre==-1) pre=p;
		else
		{
			if(p-pre>x)
			{
				cnt++;
				pre=p;
			}
		}
	}
	return cnt+1;
}
void solve2()
{
	int i,c,l,r,mid,pre,nowx;
	for(c=1;c<=n;c++)
	{
		if(cnt[c]>B) continue;
		if(cnt[c]==0) continue;
		pre=n;
		while(pre>0)
		{
			nowx=cal(c,pre);
			l=1;
			r=pre;
			while(l<r)
			{
				mid=(l+r)>>1;
				if(cal(c,mid)<=nowx) r=mid;
				else l=mid+1;
			}
			res2[pre]+=nowx;
			res2[l-1]-=nowx;
			pre=l-1;
		}
	}
	for(i=n-1;i;i--) res2[i]+=res2[i+1];
}
int main()
{
	int i;
	scanf("%d",&n);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[i]=res1[i]=res2[i]=0;
		pos[i].clear();
	}
	for(i=1;i<=n;i++)
	{
		cnt[a[i]]++;
		pos[a[i]].push_back(i);
	}
	solve1();
	solve2();
	for(i=1;i<=n;i++) printf("%d\n",res1[i]+res2[i]);
	return 0;
}
/*
枚举 x。
超过根号头奶牛的标号最多只有根号个。

数量超过根号的，不超过根号种标号。
考虑枚举每种标号的奶牛，调和级数暴力跳，但这里如何找到下一个比 pos+x 大的？如果二分不就是要两个log了？
对于每种标号分开处理，每次预处理一下，每个 i 下一个有标号的位置是啥。
这部分复杂度是 O(B n ln n)

数量不超过根号的，最多被分为根号组。
考虑反过来枚举分组，用差分对一个范围内的 x 计算贡献。
分成 1 组：x=[len,n]
分成 2 组：x=[l2,len-1]
分成 3 组：x=[l3,l2-1]
每次去二分分界点 li，对于每种标号都暴力遍历一下。
这里要注意姿势，有些分组是不存在的。
这样每种标号和每头奶牛都只会被遍历一次。
这部分复杂度也是 O(B n log n)。

所以总复杂度是根号带log的。感觉应该有*2400。
*/

