import java.util.*
import kotlin.math.*

fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readdb()=readLine()!!.toDouble()
fun readstring()=readLine()!!
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
fun readline_db()=(readLine()!!.split(" ").map{it.toDouble()}).toDoubleArray()
fun main(args: Array<String>){go()}
inline fun <T:Number> lower_bound_pos(
a:MutableList<T>,L:Int,R:Int,target:T):Int{
	var l=L
	var r=R
	var mid:Int
	while(l<r){
		mid=(l+r) shr 1
		if(a[mid].toLong()>=target.toLong()) r=mid
		else l=mid+1
	}
	return l
}
data class pair(var fi:Int,var se:Int)
/*using: xxx.sortWith(cmp)*/
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
const val INF=0x3f3f3f3f
const val LLINF=0x3f3f3f3f3f3f3f3fL
const val MAX=2e5.toInt()+10
/*------------------------------------------------------------*/
fun go()
{
	var tmp_line=readline_int()
	var n=tmp_line[0]
	var k=tmp_line[1]
	require(n>=1 && n<=2e5)
	require(k>=1 && k<=n)
	var s=readstring()
	var l=INF
	var r=INF
	for(i in 0..n-1)
	{
		require(s[i]=='I'||s[i]=='('||s[i]==')')
		if(s[i]=='I')
		{
			l=i-1
			r=i+1
		}
	}
	require(l!=INF)
	while(k-->0)
	{
		var op=readstring()
		require(op=="backspace"||op=="delete")
		if(op[0]=='b')
		{
			if(l<0) continue
			if(r<n&&s[l]=='('&&s[r]==')') r++
			l--
		}
		else r++
	}
	var ans=""
	if(l>=0) ans+=s.substring(0,l+1)
	ans+="I"
	if(r<n) ans+=s.substring(r,n)
	println(ans)
}

