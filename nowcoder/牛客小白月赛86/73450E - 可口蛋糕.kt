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
	require(n>=1 && n<=1e6)
	var w=tmp_line[1].toLong()
	require(w>=1 && w<=1e9)
	var a=readline_ll()
	require(a.size==n)
	var b=readline_ll()
	require(b.size==n)
	var i=0
	var sum=0L
	var bit=LongArray(n+5)
	var mn=LLINF
	var ans=-LLINF
	var suma=0L
	for(j in 0..n-1){
		require(a[j]>=1 && a[j]<=1e9)
		require(b[j]>=-1e9 && b[j]<=1e9)
		sum+=a[j]
		suma+=a[j]
		if(j>0) bit[j]=bit[j-1]+b[j]
		else bit[j]=b[j]
		while(i<=j&&sum>=w){
			sum-=a[i]
			if(i==0) mn=0
			else mn=min(mn,bit[i-1])
			i++
		}
		ans=max(ans,bit[j]-mn)
	}
	require(w<=suma)
	println("${ans}")
}

