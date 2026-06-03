import java.util.*
import kotlin.math.*
import kotlin.random.Random

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_char()=readLine()!!.toCharArray()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_ull()=(readLine()!!.split(" ").map{it.toULong()}).toULongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Long)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
class KMP()
{
	lateinit var nex:IntArray
	lateinit var t:CharArray
	var len=0
	lateinit var dep:IntArray
	fun get_next(s:String,n:Int)
	{
		len=n
		t=CharArray(n+2)
		nex=IntArray(n+2)
		for(i in 1..len) t[i]=s[i-1]
		t[len+1]='\u0000'
		nex[0]=0
		nex[1]=0
		var j=0
		for(i in 2..len)
		{
			while(j>0 && t[j+1]!=s[i-1]) j=nex[j]
			if(t[j+1]==s[i-1]) j++
			nex[i]=j
		}
		dep=IntArray(n+2){0}
		for(i in 1..len) dep[i]=dep[nex[i]]+1
	}
	fun match(tj:Int,s:String,n:Int):pair
	{
		var res=0L
		var j=tj
		for(i in 0..n-1)
		{
			while(j>0 && t[j+1]!=s[i]) j=nex[j]
			if(t[j+1]==s[i]) j++
			res+=dep[j]
			if(j==len) j=nex[j]
		}
		return pair(j,res)
	}
}
/*
kmp.get_next(t,len); // t[1..len]
kmp.match(s,n); // s[0..n-1]
*/
fun go()
{
	var T=readint()
	require(1<=T && T<=100)
	var suma=0
	var sumb=0
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var s=readstring()
		var len=s.length
		require(1<=len && len<=100)
		var kmp=KMP()
		kmp.get_next(s,len)
		var dp=LongArray(len+2){-LLINF}
		var cnt=LongArray(len+2){0}
		dp[0]=0
		cnt[0]=1
		for(i in 1..n)
		{
			var ss=readline_string()
			require(ss.size==2)
			var lena=ss[0].length
			var lenb=ss[1].length
			require(1<=lena && lena<=2e5)
			require(1<=lenb && lenb<=2e5)
			suma+=lena
			sumb+=lenb
			require(suma<=2e5)
			require(sumb<=2e5)
			var ndp=LongArray(len+2){-LLINF}
			var ncnt=LongArray(len+2){0}
			for(j in 0..len-1)
			{
				if(dp[j]==-LLINF) continue
				for(k in 0..1)
				{
					var res=kmp.match(j,ss[k],ss[k].length)
					if(ndp[res.fi]==dp[j]+res.se) ncnt[res.fi]=(ncnt[res.fi]+cnt[j])%mod
					else if(ndp[res.fi]<dp[j]+res.se)
					{
						ndp[res.fi]=dp[j]+res.se
						ncnt[res.fi]=cnt[j]
					}
				}
			}
			for(j in 0..len-1)
			{
				dp[j]=ndp[j]
				cnt[j]=ncnt[j]
			}
		}
		var ans=0L
		var anscnt=0L
		for(j in 0..len-1)
		{
			if(dp[j]>ans)
			{
				ans=dp[j]
				anscnt=cnt[j]
			}
			else if(dp[j]==ans) anscnt=(anscnt+cnt[j])%mod
		}
		println("${ans} ${anscnt}")
	}
}
/*
dp[i][0/1][j] 表示考虑了前 i 组串，第 i 组串选了 a/b，当前匹配到自动机的 j 节点的最大值和方案数。
出现次数就是当前节点的深度，不用建树，预处理沿着nex转移一下即可。
*/
