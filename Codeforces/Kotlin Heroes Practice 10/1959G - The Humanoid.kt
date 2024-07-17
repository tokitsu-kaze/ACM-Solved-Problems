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
var a=IntArray(1)
fun cal(n:Int,hh:Long,x:Int,y:Int,z:Int):Int
{
	var h=hh
	var tmp=IntArray(3)
	tmp[0]=x
	tmp[1]=y
	tmp[2]=z
	var i=0
	var j=0
	var res=0
	while(i<n)
	{
		if(a[i]<h)
		{
			res++
			h+=a[i]/2
		}
		else
		{
			if(j==tmp.size) return res
			h=h*tmp[j]
			j++
			i--
		}
		i++
	}
	return res
}
fun go()
{
	var t=readint()
	while(t-->0)
	{
		var tmp_line=readline_int()
		var n=tmp_line[0]
		var h=tmp_line[1].toLong()
		a=readline_int().sorted().toIntArray()
		var ans=0
		ans=max(ans,cal(n,h,2,2,3))
		ans=max(ans,cal(n,h,2,3,2))
		ans=max(ans,cal(n,h,3,2,2))
		println("${ans}")
	}
}
