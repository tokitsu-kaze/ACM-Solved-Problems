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
	var T=readint()
	require(T>=1 && T<=1000)
	while(T-->0){
		var a=readstring()
		var b=readstring()
		require(a.length>=1 && a.length<=4)
		require(b.length>=1 && b.length<=4)
		for(i in 0..a.length-1){
			for(j in i+1..a.length-1){
				require(a[i]!=a[j])
			}
		}
		for(i in 0..b.length-1){
			for(j in i+1..b.length-1){
				require(b[i]!=b[j])
			}
		}
		var ok=1
		for(i in 0..a.length-1){
			var f=0
			for(j in 0..b.length-1){
				if(a[i]==b[j]) f=1
			}
			if(f==0) ok=0
		}
		if(ok==1) println("10")
		else println("0")
	}
}

