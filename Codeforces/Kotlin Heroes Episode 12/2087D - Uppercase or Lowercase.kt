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
fun ask(x:Int):String
{
	println("? ${x}")
	System.out.flush()
	var s=readstring()
	return s
}
fun go()
{
	var tmp_line=readline_string()
	var n=tmp_line[0].toInt()
	var tar=tmp_line[1]
	var tmp=ask(1)
	if(tmp==tar)
	{
		println("! 1")
		System.out.flush()
		return
	}
	var ra=0
	if(tar[0]>='A' && tar[0]<='Z') ra=1
	var rb=0
	if(tmp[0]>='A' && tmp[0]<='Z') rb=1
	var l=2
	var r=n
	if(ra==rb)
	{
		while(l<r)
		{
			var mid=(l+r) shr 1
			var res=ask(mid+1)
			var rc=0
			if(res[0]>='A' && res[0]<='Z') rc=1
			if(rc!=ra || res>tar) r=mid
			else l=mid+1
		}
	}
	else
	{
		while(l<r)
		{
			var mid=(l+r) shr 1
			var res=ask(mid+1)
			var rc=0
			if(res[0]>='A' && res[0]<='Z') rc=1
			if(rc!=ra || res<=tar) l=mid+1
			else r=mid
		}
	}
	println("! ${l}")
	System.out.flush()
}

