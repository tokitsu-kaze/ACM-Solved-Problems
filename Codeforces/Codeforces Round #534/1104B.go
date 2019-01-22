package main

import "fmt"
import "os"
import "bufio"
import "strconv"

func min(a,b int)int {
    var res int
    if a<b {
        res=a
    } else {
        res=b;
    }
    return res;
}

func solve(){
    var s string
    var n,i,flag,top int
    flag=0
    var st [100010] int
    top=0
    s=readString()
    n=len(s)
    for i=0;i<n;i++{
        if top==0{
            st[top]=(int)(s[i]-'a')
            top=top+1
        }else if st[top-1]!=(int)(s[i]-'a') {
            st[top]=(int)(s[i]-'a')
            top=top+1
        }else{
            top=top-1
            flag=flag^1
        }
    }
    if flag==0{
        fmt.Println("No")
    }else{
        fmt.Println("Yes")
    }

}


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