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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e7.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var T=readint()
	require(1<=T && T<=1e4)
	var res=mutableListOf<String>()
	var sumn=0L
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var k=tmp_line[1]
		require(1<=n && n<=1e5)
		require(0<=k && k<=n)
		sumn+=n
		require(sumn<=2e5)
		var s=readstring()
		require(s.length==n)
		for(it in s)
		{
			require(('A'<=it && it<='Z') ||
					('a'<=it && it<='z') ||
					it=='_')
		}
		var tmp=mutableListOf<String>()
		tmp.add("awdec")
		tmp.add("Fantasy_Blue")
		var dp=Array(n+1){IntArray(4){INF}}
		dp[0][0]=0
		for(i in 1..n)
		{
			for(j in 0..3) dp[i][j]=dp[i-1][j]
			for(id in 0..1)
			{
				if(i-tmp[id].length<0) continue
				var k=i-tmp[id].length
				var cnt=0
				for(j in 0..tmp[id].length-1)
				{
					if(s[k+j]!=tmp[id][j]) cnt++
				}
				for(j in 0..3)
				{
					var nex=j or (1 shl id)
					dp[i][nex]=min(dp[i][nex],dp[k][j]+cnt)
				}
			}
		}
		if(dp[n][3]<=k) res.add("Yes")
		else res.add("No")
	}
	println(res.joinToString("\n"))
}
