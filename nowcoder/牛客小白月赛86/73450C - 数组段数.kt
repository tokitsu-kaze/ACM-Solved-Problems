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
	require(n>=1 && n<=2e5)
	var q=tmp_line[1]
	require(q>=1 && q<=2e5)
	var a=readline_int()
	require(a.size==n)
	var bit=IntArray(n+5)
	require(a[0]>=1 && a[0]<=1e6)
	bit[0]=0
	for(i in 1..n-1){
		require(a[i]>=1 && a[i]<=1e6)
		if(a[i]!=a[i-1]) bit[i]=1
		else bit[i]=0
		bit[i]+=bit[i-1]
	}
	bit[n]=bit[n-1]+1
	var res=mutableListOf<Int>()
	while(q-->0){
		tmp_line=readline_int()
		var l=tmp_line[0]
		require(l>=1 && l<=n)
		var r=tmp_line[1]
		require(r>=l && r<=n)
		var ans=bit[r]-bit[l-1]
		if(r<n&&a[r-1]==a[r]) ans++
		res.add(ans)
	}
	println(res.joinToString("\n"))
}

