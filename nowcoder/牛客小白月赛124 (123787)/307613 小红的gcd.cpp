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
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun readline_string()=(readLine()!!.split(" "))
fun main(args: Array<String>){go()}
data class pair(var fi:Int,var se:Int)
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
	require(1<=T && T<=200)
	var sum2n=0
	while(T-->0)
	{
		var n=readint()
		require(1<=n && n<=1000)
		require((2*n-1)%3==0)
		sum2n+=n*n
		require(sum2n<=1e6)
		var mp=Array(n+2){CharArray(n+2)}
		for(i in 0..n-1)
		{
			mp[i]=readline_char()
			require(mp[i].size==n)
			for(it in mp[i]) require(it=='g' || it=='c' || it=='d')
		}
		if(mp[0][0]==mp[n-1][n-1])
		{
			println("0")
			continue
		}
		var dp=Array(n+2){IntArray(n+2){0}}
		var k=(2*n-1)/3
		dp[1][1]=1
		for(i in 1..n)
		{
			for(j in 1..n)
			{
				if(i==1 && j==1) continue
				var stp=i+j-1
				var ok=false
				if(stp<=k)
				{
					if(mp[i-1][j-1]==mp[0][0]) ok=true
				}
				else if(stp<=2*k)
				{
					if(mp[i-1][j-1]!=mp[n-1][n-1] &&
					   mp[i-1][j-1]!=mp[0][0]) ok=true
				}
				else
				{
					if(mp[i-1][j-1]==mp[n-1][n-1]) ok=true
				}
				if(ok) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod
			}
		}
		println("${dp[n][n]}")
	}
}

