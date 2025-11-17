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
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e5.toInt()+10
const val mod=998244353//1e9.toInt()+7
/*------------------------------------------------------------*/
fun go()
{
	var n=readint()
	require(n>=1 && n<=2e5)
	var a=readline_int().sorted()
	require(a.size==n)
	var b=readline_int()
	require(b.size==n)
	for(i in 0..n-1)
	{
		if(i>0) require(a[i]!=a[i-1])
		require(a[i]>=0 && a[i]<=2e9)
		require(b[i]>=0 && b[i]<=2e9)
	}
	var mp:MutableMap<Int,Int> = mutableMapOf()
	for(i in 0..n-1) mp[b[i]]=(mp[b[i]]?:0)+1
	var ok=1
	var ans=0
	for((v,cnt) in mp)
	{
		if(cnt==1) ok=0
		ans+=(cnt+1)/2
	}
	if(ok==0) println("-1")
	else println("${ans}")
}

