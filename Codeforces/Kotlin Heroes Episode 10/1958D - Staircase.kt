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
		var n=readint()
		var a=readline_ll()
		var nex=IntArray(n+5){n+1}
		var lst=n+1
		for(i in n downTo 1)
		{
			if(a[i-1]==0L) lst=i
			nex[i]=lst
		}
		var ans=0L
		var pos=1
		while(pos<=n)
		{
			if(a[pos-1]==0L)
			{
				pos++
				continue
			}
			var tmp=nex[pos]-pos
			var res=0L
			for(i in pos..nex[pos]-1) res+=a[i-1]
			if(tmp%2==0) ans+=res*2
			else
			{
				var i=pos
				var mx=0L
				while(i<=nex[pos]-1)
				{
					mx=max(mx,a[i-1])
					i+=2
				}
				ans+=res*2-mx
			}
			pos=nex[pos]
		}
		println("${ans}")
	}
}
