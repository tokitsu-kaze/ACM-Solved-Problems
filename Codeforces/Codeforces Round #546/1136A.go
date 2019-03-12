package main

import(
    "fmt"
    "os"
    "bufio"
    "strconv"
//    "sort"
)

const INF int =0x3f3f3f3f
const LLINF int64 = 0x3f3f3f3f3f3f3f3f
const MAX int =200000+10

func solve(){
    var l,r [111] int
    var x,i,n int
    n=readInt()
    for i=0;i<n;i++{
        l[i]=readInt()
        r[i]=readInt()
    }
    x=readInt()
    for i=0;i<n;i++{
        if l[i]<=x&&r[i]>=x{
            fmt.Println(n-i)
            break
        }
    }
    
}

/***************************FastIO begin**********************************/
var scanner *bufio.Scanner

func main() {
    scanner = bufio.NewScanner(os.Stdin)
    const MaxTokenLength = 1024 * 1024
    scanner.Buffer(make([]byte, 0, MaxTokenLength), MaxTokenLength)
    scanner.Split(bufio.ScanWords)
    solve()
}
func readString() string {
    scanner.Scan()
    return scanner.Text()
}

func readInt() int {
    val, _ := strconv.Atoi(readString())
    return val
}

func readInt64() int64 {
    v, _ := strconv.ParseInt(readString(), 10, 64)
    return v
}
/***************************FastIO end**********************************/

/***************************sort begin**********************************/
type IntSlice []int

func (s IntSlice) Len() int { return len(s) }
func (s IntSlice) Swap(i,j int){ s[i],s[j]=s[j],s[i] }
func (s IntSlice) Less(i,j int) bool { return s[i]<s[j] }

//sort.Sort(sort.IntSlice(a[0:n]))
//sort.Sort(sort.Reverse(sort.IntSlice(a[0:n])))


/***************************sort end**********************************/

/*************************************************************/
func min(a,b int64)int64 {
    if a<b {
        return a
    } else {
        return b
    }
}

func max(a,b int64)int64 {
    if a>b {
        return a
    } else {
        return b
    }
}

func abs(x int64)int64 {
    if x>0 {
        return x
    } else {
        return -x
    }
}