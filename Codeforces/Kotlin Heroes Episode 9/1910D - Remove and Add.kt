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
		var a=readline_int()
		var ok=1
		var f=0
		for(i in 1..n-1)
		{
			if(a[i]<a[i-1])
			{
				if(f==0)
				{
					if(i-2>=0)
					{
						if(a[i]<a[i-2]) a[i]=a[i-1]
						else if(a[i]==a[i-2]) a[i]++
					}
					f=1
				}
				else
				{
					ok=0
					break
				}
			}
			else if(a[i]==a[i-1]) a[i]++
		}
		if(ok==1) println("YES")
		else println("NO")
	}
}
