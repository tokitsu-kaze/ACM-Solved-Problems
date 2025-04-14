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
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun gcd(a:Int,b:Int):Int
{
	if(b==0) return a
	return gcd(b,a%b)
}
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e3)
	var aa=readline_int()
	require(aa.size==n)
	for(it in aa) require(it>=1 && it<=1e9)
	var a=IntArray(n+2)
	for(i in 1..n) a[i]=aa[i-1]
	var pre=IntArray(n+2){0}
	var nex=IntArray(n+2){n+1}
	for(i in 1..n)
	{
		for(j in i-1 downTo 1)
		{
			if(gcd(a[i],a[j])>1)
			{
				pre[i]=j
				break
			}
		}
		for(j in i+1..n)
		{
			if(gcd(a[i],a[j])>1)
			{
				nex[i]=j
				break
			}
		}
	}
	var dp=IntArray(n+2){-INF}
	dp[0]=0
	for(i in 1..n)
	{
		var l=pre[i]
		for(j in i-1 downTo 1)
		{
			if(nex[j]>i) l=min(l,pre[j])
			if(j<=l) dp[i]=max(dp[i],dp[j-1]+1)
		}
	}
//	for(i in 1..n) println("${i} ${dp[i]}")
	if(dp[n]<0) println("-1")
	else println("${dp[n]}")
}

