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
data class pair(var fi:Long,var se:Long)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
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
	var t=readint()
	while(t-->0)
	{
		var fstl=readstring()
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var m=tmp_line[1]
		var a=readline_int()
		var s=TreeSet<Int>()
		for(i in 0..n-1)
		{
			if(s.size==0||a[i]<a[s.last()]) s.add(i)
		}
		var res=mutableListOf<Int>()
		for(i in 0..m-1)
		{
			tmp_line=readline_int()
			var k=tmp_line[0]
			var d=tmp_line[1]
			k--
			a[k]-=d
			var it=s.floor(k)
			if(it!=null)
			{
				if(it==k||a[it]>a[k]) s.add(k)
			}
			else s.add(k)
			while(true)
			{
				it=s.ceiling(k+1)
				if(it!=null && a[it]>=a[k]) s.remove(it)
				else break
			}
			res.add(s.size)
		}
		println(res.joinToString(" "))
	}
}
