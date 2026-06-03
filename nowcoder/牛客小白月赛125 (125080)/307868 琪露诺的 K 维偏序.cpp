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
	var tmp_line=readline_int()
	require(tmp_line.size==2)
	var n=tmp_line[0]
	var q=tmp_line[1]
	require(1<=n && n<=1e5)
	require(1<=q && q<=1e5)
	var a=readline_int()
	require(a.size==n)
	for(i in 1..n-1)
	{
		require(1<=a[i] && a[i]<=1e9)
		require(a[i-1]<=a[i])
	}
	while(q-->0)
	{
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var k=tmp_line[0]
		var x=tmp_line[1]
		require(1<=k && k<=n)
		require(1<=x && x<=1e9)
		if(a[k-1]<x) println("Yes")
		else println("No")
	}
}

