/*
题意：
有一张无向图，在其中添边。问每次添边之后，还剩多少桥。

题解：
首先就是缩成一个只有桥的图，此时就会缩成一颗树，这时减少的桥就是询问的两点到他们的lca的距离
由于询问只有1000，所以LCA写暴力就可以实现。
*/

```cpp
/*
 * @Author : Nightmare
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <time.h>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ls 2 * rt
#define rs 2 * rt + 1
#define gcd(a,b) __gcd(a,b)
#define eps 1e-8
#define lowbit(x) (x&(-x))
#define N 100005
#define M 1000005
#define mod 1000000007
#define inf 0x3f3f3f3f
int n, m, cnt, ans, cas, low[N], dfn[N], dep[N], bridge[N], fa[N];
vector<int> edge[N];
inline void add(int a, int b){ edge[a].push_back(b); edge[b].push_back(a); }
void dfs(int u){
    dfn[u] = low[u] = ++cnt; dep[u] = dep[fa[u]] + 1;
    for(int i = 0 ; i < edge[u].size() ; i ++){
        int v = edge[u][i];
        if(!dfn[v]){
            fa[v] = u; dfs(v);
            if(low[v] > dfn[u]) ans ++, bridge[v] = 1;
            low[u] = min(low[u], low[v]);
        }else if(fa[u] != v){
            low[u] = min(low[u], dfn[v]);
        }
    }
}
void update(int a, int b){
    while(dep[a] < dep[b]){
        if(bridge[b]) bridge[b] = 0, ans --;
        b = fa[b];
    }
    while(dep[a] > dep[b]){
        if(bridge[a]) bridge[a] = 0, ans --;
        a = fa[a];
    }
    while(a != b){
        if(bridge[a]) bridge[a] = 0, ans --;
        if(bridge[b]) bridge[b] = 0, ans --;
        a = fa[a]; b = fa[b];
    }
}
inline void solve(){
    for(int i = 1 ; i <= n ; i ++) low[i] = dfn[i] = dep[i] = fa[i] = bridge[i] = 0;
    for(int i = 1 ; i <= n ; i ++) edge[i].clear();
    for(int i = 1, a, b; i <= m ; i ++) scanf("%d %d", &a, &b), add(a, b);
    dfs(1);
    printf("Case %d:\n", ++cas);
    int Q; scanf("%d", &Q);
    while(Q--){
        int a, b; scanf("%d %d", &a, &b); update(a, b);
        printf("%d\n", ans);
    }
}
signed main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\in.txt", "r", stdin);
#endif
    while(~scanf("%d %d", &n, &m) && (n + m)) solve();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
```