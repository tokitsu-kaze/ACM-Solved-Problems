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
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_ll()
		var n=tmp_line[0].toInt()
		var k=tmp_line[1]
		var a=readline_ll()
		var mx=0L
		var mn=LLINF
		for(it in a)
		{
			mx=max(mx,it)
			mn=min(mn,it)
		}
		var need=0L
		for(it in a) need+=max(0L,mx-it)
		if(need>k)
		{
			println("${-1}")
			continue
		}
		k-=need
		mx+=k/n
		var ans=0L
		for(it in a)
		{
			if(it==mn) ans+=max(0L,mx-mn-1)
			else ans+=mx-it
		}
		ans-=max(0L,mx-mn-1)
		println("${ans}")
	}
}

