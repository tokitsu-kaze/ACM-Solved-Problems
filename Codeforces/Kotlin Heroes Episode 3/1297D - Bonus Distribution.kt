fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
data class pair(var fi:Int,var se:Int)
fun main(args: Array<String>)
{
    var t=readint()
    while(t-->0)
    {
        var tmp=readline_int()
        var n=tmp[0]
        var k=tmp[1]
        var a=readline_int()
        var ans=Array(n){0}
        var res:MutableList<pair> =mutableListOf()
        for(i in 0 until n)  res.add(pair(a[i],i))
        res.sortBy({it.fi})
        for(i in n-2 downTo 0)
        {
            var dt=res[i+1].fi-res[i].fi-1
            dt=minOf(dt,k)
            ans[res[i].se]+=dt
            res[i].fi+=dt
            k-=dt
        }
        var tp=(k+n-1)/n
        res[n-1].fi+=tp
        ans[res[n-1].se]+=tp
        k-=tp
        for(i in n-2 downTo 0)
        {
            var dt=res[i+1].fi-res[i].fi-1
            dt=minOf(dt,k)
            ans[res[i].se]+=dt
            res[i].fi+=dt
            k-=dt
        }
        for(i in 0 until n) print("${ans[i]} ")
        println()
    }
}