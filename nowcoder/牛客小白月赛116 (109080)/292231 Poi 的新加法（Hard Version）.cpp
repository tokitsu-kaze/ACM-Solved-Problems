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
	var sumq=0
	var res=mutableListOf<Long>()
	while(T-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==2)
		var n=tmp_line[0]
		var q=tmp_line[1]
		sumn+=n
		sumq+=q
		require(n>=1 && n<=1e6)
		require(sumn>=1 && sumn<=1e6)
		require(q>=1 && q<=1e6)
		require(sumq>=1 && sumq<=1e6)
		var a=readline_ll()
		require(a.size==n)
		while(q-->0)
		{
			tmp_line=readline_int()
			require(tmp_line.size==2)
			var l=tmp_line[0]
			var r=tmp_line[1]
			require(l>=1 && l<=n)
			require(r>=l && r<=n)
			if(r-l>66)
			{
				res.add(0)
				continue
			}
			var ans=a[l-1]
			for(i in l..r-1) ans=(ans and a[i]) shl 1
			res.add(ans)
		}
	}
	println(res.joinToString("\n"))
}
