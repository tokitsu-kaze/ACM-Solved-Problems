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
    var m=tmp_line[1]
    require(n>=1 && n<=1e5)
    require(m>=1 && m<=1e5)
    var a=readline_ll()
    require(a.size==n)
    var ans=0L
    var mx=0L
    for(it in a){
        ans+=it
        mx=max(mx,it)
        require(it>=1 && it<=1e9)
    }
    ans=max((ans+m-1)/m,mx)
    var id1=IntArray(2*n+5)
    var id2=IntArray(2*n+5)
    var l=LongArray(2*n+5)
    var r=LongArray(2*n+5)
    var tot=0
    var pos=0
    for(i in 0..m-1){
        var now=ans
        while(pos<n && now>0L){
            id1[tot]=pos+1
            id2[tot]=i+1
            if(a[pos]<=now){
                l[tot]=ans-now
                r[tot]=l[tot]+a[pos]
                tot++
                now-=a[pos]
                pos++
            }
            else{
                l[tot]=ans-now
                r[tot]=ans
                tot++
                a[pos]-=now
                now=0L
            }
        }
    }
    var rs=mutableListOf<String>()
    rs.add("${tot}")
    for(i in 0..tot-1){
        rs.add("${id1[i]} ${id2[i]} ${l[i]} ${r[i]}")
    }
    println(rs.joinToString("\n"))
}
