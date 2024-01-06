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
    var tmp=readline_ll()
    var n=tmp[0].toInt()
    var m=tmp[1]
    require(n>=2 && n<=1e5)
    require(m>=1 && m<=1e9)
    var a=readline_ll()
    require(a.size==n)
    require(a[0]==0L)
    require(a[n-1]==0L)
    var res=mutableListOf<Long>()
    var now=0L
    var ret=0L
    for(it in a){
        require(it>=0 && it<=1e9)
        if(it==0L)
        {
            if(now>0) res.add(now)
            now=0
        }
        now+=it
        ret+=it
    }
    now=m
    var ans=(n-1).toLong()
    for(it in res){
        if(ret<m)
        {
            ans+=m-now
            break
        }
        ret-=it
        if(now-it>0) now-=it
        else{
            ans+=m-now
            now=m
            now-=it
            if(now<=0){
                ans=-1L
                break
            }
        }
    }
    if(ans==-1L) println("NO")
    else println("${ans}")
     
}
