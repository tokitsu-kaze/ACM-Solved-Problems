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
fun gcd(a:Int,b:Int):Int
{
	if(b==0) return a
	return gcd(b,a%b)
}
fun go()
{
	var T=readint()
	require(1<=T && T<=1e3)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(9<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var s=readstring()
		require(s.length==n)
		for(it in s) require('0'<=it && it<='9')
		var cnt=IntArray(9){0}
		var sum=Array(9){IntArray(9){0}}
		var g=gcd(n,9)
		for(i in 0..n-1)
		{
			cnt[i%g]++
			sum[i%g][s[i].toInt()%9]++
		}
		var dp=Array(g){IntArray(9){INF}}
		for(j in 0..8) dp[0][j]=cnt[0]-sum[0][j]
		for(i in 1..g-1)
		{
			for(j in 0..8)
			{
				for(k in 0..8)
				{
					var now=(j+k)%9
					dp[i][now]=min(dp[i][now],dp[i-1][j]+cnt[i]-sum[i][k])
				}
			}
		}
		var ans=INF
		for(j in 0..8)
		{
			if(j*(9/g)%9==0) ans=min(ans,dp[g-1][j])
		}
		println("${ans}")
	}
}

