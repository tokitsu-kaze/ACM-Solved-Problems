import java.util.*
fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()
data class pair(var fi:Int,var se:Int,var id:Int)
val cmp: Comparator<pair> = Comparator{ a,b->
    if (a.fi==b.fi) a.se.compareTo(b.se)
    else a.fi.compareTo(b.fi)
}
fun main(args: Array<String>)
{
    var t=readint()
    while(t-->0)
    {
        var tmp=readline_int()
        var n=tmp[0]
        var m=tmp[1]
        var res:MutableList<pair> =mutableListOf()
        for(i in 0 until n)
        {
            tmp=readline_int()
            var a=tmp[0]
            var b=tmp[1]
            res.add(pair(a,b,i))
        }
        res.sortBy({it.fi})
        var ans=Array(n){0}
        fun ck(x:Int):Int
        {
            var s= PriorityQueue<pair>(compareBy({it.fi}))
            var now=0
            var i=0
            var cnt=0
            while(i<n)
            {
                if(now<res[i].fi)
                {
                    now=res[i].fi
                    cnt=0
                }
                var j=i
                while(j<n&&res[j].fi==res[i].fi)
                {
                    s.add(pair(res[j].se+x,0,res[j].id))
                    j++
                }
                i=j
                while(s.size>0)
                {
                    var tp=s.first()
                    if(tp.fi<now) return 0
                    else
                    {
                        if(i>=n||now<res[i].fi)
                        {
                            cnt++
                            s.remove(tp)
                            ans[tp.id]=now
                            if(cnt==m)
                            {
                                cnt=0
                                now++
                            }
                        }
                        else break
                    }
                }
            }
            return 1
        }
        var l=0
        var r=n
        while(l<r)
        {
            var mid=(l+r)/2
            if(ck(mid)==1) r=mid
            else l=mid+1
        }
        ck(l)
        println("${l}")
        println(ans.joinToString(" "))
    }
}