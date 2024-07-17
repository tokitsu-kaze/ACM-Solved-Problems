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
		var n=tmp_line[0].toInt()
		var op=tmp_line[1]
		var s=readstring()
		s=s+s
		var mp:MutableMap<Char,Int> = mutableMapOf()
		mp['g']=0
		mp['r']=0
		mp['y']=0
		var lst=INF
		for(i in s.length-1 downTo 0)
		{
			if(s[i]=='g') lst=i
			else
			{
				if(lst==INF) continue
				mp[s[i]]=max(mp[s[i]]?:0,lst-i)
			}
		}
		println("${mp[op[0]]?:0}")
	}
}
