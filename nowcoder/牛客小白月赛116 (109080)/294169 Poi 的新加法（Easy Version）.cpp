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
fun go()
{
	var T=readint()
	require(T>=1 && T<=1e6)
	var sumn=0
	var res=mutableListOf<Long>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var q=tmp_line[1]
		require(n>=1 && n<=1e6)
		sumn+=n
		require(sumn>=1 && sumn<=1e6)
		require(q==1)
		var a=readline_ll()
		require(a.size==n)
		tmp_line=readline_int()
		require(tmp_line.size==2)
		var l=tmp_line[0]
		var r=tmp_line[1]
		require(l==1 && r==n)
		var ans=a[0]
		for(i in 1..n-1)
		{
			ans=(ans+a[i])-(ans xor a[i])
		}
		res.add(ans)
	}
	println(res.joinToString("\n"))
}
