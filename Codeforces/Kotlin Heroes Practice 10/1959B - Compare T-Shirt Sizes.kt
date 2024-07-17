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
		var tmp_line=readstring().split(" ")
		var a=tmp_line[0].reversed()
		var b=tmp_line[1].reversed()
		if(a[0]<b[0]) println(">");
		else if(a[0]>b[0]) println("<")
		else
		{
			if(a[0]=='S')
			{
				if(a.length<b.length) println(">")
				else if(a.length>b.length) println("<")
				else println("=")
			}
			else if(a[0]=='L')
			{
				if(a.length>b.length) println(">")
				else if(a.length<b.length) println("<")
				else println("=")
			}
			else println("=")
		}
	}
}
