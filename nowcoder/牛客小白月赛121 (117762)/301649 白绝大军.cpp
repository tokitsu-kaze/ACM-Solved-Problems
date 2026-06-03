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
data class pair(var fi:Long,var se:Int)
/*using: xxx.sortWith(pair_cmp)*/
val pair_cmp: Comparator<pair> = Comparator{ a,b->
	if (a.fi==b.fi) a.se.compareTo(b.se)
	else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=1e6.toInt()+10
const val mod=998244353
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_ll()
	require(tmp_line.size==2)
	var n=tmp_line[0].toInt()
	var t=tmp_line[1]
	require(1<=n && n<=2e5)
	require(0L<=t && t<=1e18)
	var a=readline_ll()
	require(a.size==n)
	var b=readline_int()
	require(b.size==n)
	var sumb=0
	var res=mutableListOf<Long>()
	var sum=0L
	for(i in 0..n-1)
	{
		require(0<=a[i] && a[i]<=1e9)
		require(0<=b[i] && b[i]<=2e5)
		sumb+=b[i]
		require(sumb<=2e5)
		while(b[i]-->0) res.add(a[i])
		sum+=a[i]
	}
	res.sort()
	res.reverse()
	var cnt=0
	for(it in res)
	{
		if(sum>=t) break
		sum+=it
		cnt++
	}
	if(sum>=t) println("${cnt}")
	else println("-1")
}

