import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
/*
#include<bits/stdc++.h>
using namespace std;
string s;
int ok;
void dfs(int x,int n,string now)
{
	if(ok) return;
	if(x==n)
	{
		int i;
		string a,b;
		int res=n/__gcd(n,(int)s.size())*s.size();
		while(a.size()<res) a+=s;
		while(b.size()<res) b+=now;
		int cnt=0;
		for(i=0;i<res;i++) cnt+=(a[i]==b[i]);
		if(cnt*2>=res)
		{
			cout<<now<<endl;
			ok=1;
		}
		return;
	}
	for(int i=0;i<26;i++) dfs(x+1,n,now+char(i+'a'));
}
int main()
{
	int t,n,i,j;
	cin>>t;
	while(t--)
	{
		
		cin>>s;
		n=s.size();
		ok=0;
		for(i=1;i<=2*n;i++) dfs(0,i,"");
	}
	return 0;
}
*/
fun go()
{
	var t=readint()
	require(t>=1 && t<=2e5)
	var sumt=0
	while(t-->0)
	{
		var s=readstring()
		var n=s.length
		for(it in s) require(it>='a' && it<='z')
		s=" "+s
		sumt+=n
		require(n>=1 && n<=2e5)
		require(sumt>=1 && sumt<=2e5)
		var res=mutableListOf<Int>()
		var sq=sqrt(n.toDouble()).toInt()+1
		for(i in 1..sq)
		{
			if(n%i==0)
			{
				res.add(i)
				if(n/i!=i) res.add(n/i)
			}
		}
		res.sort()
		for(len in res)
		{
			var suf=IntArray(len+2){0}
			for(i in len downTo 1)
			{
				var cnt=IntArray(26){0}
				var j=i
				while(j<=n)
				{
					cnt[s[j]-'a']++
					j+=len
				}
				for(j in 0..25) suf[i]=max(suf[i],cnt[j])
				suf[i]+=suf[i+1]
			}
			if(suf[1]*2<n) continue
			var now=0
			var ans=""
			for(i in 1..len)
			{
				var cnt=IntArray(26){0}
				var j=i
				while(j<=n)
				{
					cnt[s[j]-'a']++
					j+=len
				}
				for(j in 0..25)
				{
					if((now+cnt[j]+suf[i+1])*2>=n)
					{
						now+=cnt[j]
						ans+=('a'+j)
						break
					}
				}
			}
			println(ans)
			break
		}
	}
}

