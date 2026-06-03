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
const val mod=1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(1<=n && n<=2e5)
	var a=readline_int()
	require(a.size==n)
	for(it in a) require(0<=it && it<=1e9)
	var dp=LongArray(n+1){0}
	var lst=Array(2){IntArray(31){0}}
	var nowand=(1 shl 30)-1
	var nowor=0
	for(i in 1..n)
	{
		for(j in 0..30) lst[(a[i-1] shr j) and 1][j]=i
		var res=mutableListOf<pair>()
		for(j in 0..30)
		{
			if(lst[((a[i-1] shr j) and 1) xor 1][j]==0) continue
			res.add(pair(-lst[((a[i-1] shr j) and 1) xor 1][j],j))
		}
		res.sortWith(pair_cmp)
		var now=0
		for(it in res)
		{
			now=now or (1 shl it.se)
			dp[i]=max(dp[i],dp[-it.fi-1]+now)
		}
//		println("${i} ${dp[i]}")
	}
	println("${dp[n]}")
}

