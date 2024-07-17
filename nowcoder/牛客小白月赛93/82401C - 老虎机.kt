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
fun qpow(aa:Long,bb:Int):Long
{
	var res=1L
	var a=aa
	var b=bb
	while(b>0)
	{
		if((b and 1)==1) res=res*a%mod
		a=a*a%mod
		b=b shr 1
	}
	return res
}
fun inv(x:Long):Long{return qpow(x,mod-2)}
fun go()
{
	var t=readint()
	require(t>=1 && t<=1e4)
	while(t-->0)
	{
		var tmp_line=readline_int()
		require(tmp_line.size==4)
		var m=tmp_line[0]
		var a=tmp_line[1]
		var b=tmp_line[2]
		var c=tmp_line[3]
		require(m>=1 && m<=1e6)
		require(a>=1 && a<=1e6)
		require(b>=1 && b<=1e6)
		require(c>=1 && c<=1e6)
		var fz=0L
		fz=(fz+1L*m*(m-1)*(m-2)%mod*a)%mod
		fz=(fz+1L*m*(m-1)*3*b)%mod
		fz=(fz+1L*m*c)%mod
		var fm=1L*m*m*m%mod
		println("${fz*inv(fm)%mod}")
	}
}

