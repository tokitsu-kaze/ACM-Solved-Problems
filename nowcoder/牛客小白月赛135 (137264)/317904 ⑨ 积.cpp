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
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var sumn=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=2e5)
		sumn+=n
		require(sumn<=2e5)
		var a=readline_int()
		require(a.size==n)
		for(it in a) require(0<=it && it<=1e9)
		var dp=Array(n+1){IntArray(9){INF}}
		dp[0][1]=0
		for(i in 1..n)
		{
			for(j in 0..8)
			{
				for(k in 0..8)
				{
					var now=j*(a[i-1]%9+k)%9
					dp[i][now]=min(dp[i][now],dp[i-1][j]+k);
				}
			}
		}
		println("${dp[n][0]}")
	}
}

