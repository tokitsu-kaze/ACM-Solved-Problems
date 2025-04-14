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
var n=0
var m=0
var k=0
var h=IntArray(1)
var x=IntArray(1)
fun ck(cnt:Int):Boolean
{
	var res=mutableListOf<pair>()
	for(i in 0..n-1)
	{
		if(1L*cnt*m<1L*h[i]) continue
		var tmp=m-(h[i]+cnt-1)/cnt
		var l=x[i]-tmp
		var r=x[i]+tmp
		res.add(pair(l,1))
		res.add(pair(r+1,-1))
	}
	if(res.size==0) return false
	res.sortWith(pair_cmp)
	var now=0
	for(it in res)
	{
		now+=it.se
		if(now>=k) return true
	}
	return false
}
fun go()
{
	var T=readint()
	while(T-->0)
	{
		var tmp_line=readline_int()
		n=tmp_line[0]
		m=tmp_line[1]
		k=tmp_line[2]
		h=readline_int()
		x=readline_int()
		var l=0
		var r=(1e9+1e5+10).toInt()
		while(l<r)
		{
			var mid=(l+r) shr 1
			if(ck(mid)) r=mid
			else l=mid+1
		}
		if(!ck(l)) println("-1")
		else println("${l}")
	}
}

