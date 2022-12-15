const val MAXN = 200005
const val INF : Long = (9e18).toLong()

class DS (val N: Int) {
    private val p = IntArray(N)
    private val r = IntArray(N)
    init {
        for (i in p.indices) {p[i] = i; r[i] = 0;}
    }
    
    public fun find (x: Int) : Int {
        if (p[x] == x) return x;
        p[x] = find(p[x]);
        return p[x];
    }
    
    public fun join (a: Int, b: Int) : Boolean {
        var (x,y) = arrayOf(find(a),find(b));
        if (x == y) return false;
        if (r[x] > r[y]) y = x.also {x = y}
        p[x] = y; if (r[x] == r[y]) r[y]++;
        return true;
    }
}

data class Edge(var u: Int, var v: Int, var w: Long)

var edges = ArrayList<Edge>()
var MST = DS(MAXN)

fun main() {
    val (n,m) = readLine()!!.split(" ").map {it.toInt();}
    val arr = readLine()!!.split(" ").map {it.toLong();}
    for (i in 0..m-1) {
        val (u,v,w) = readLine()!!.split(" ").map {it.toLong();}
        edges.add(Edge(u.toInt()-1,v.toInt()-1,w));
    }
    
    var mini : Long = INF; var ind = -1;
    for (i in 0..n-1) if (arr[i] < mini) {mini = arr[i]; ind = i;}
    for (i in 0..n-1) if (i != ind) edges.add(Edge(ind,i,arr[i]+arr[ind]));
        
    edges.sortBy{it.w};
        
    var r : Long = 0;
    for (i in edges) if (MST.join(i.u,i.v)) r += i.w;
    
    print("$r");
}
