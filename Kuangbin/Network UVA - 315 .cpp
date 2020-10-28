题意：
无向图求割点个数

题解：
割点模板题

/*
 * @Author : Nightmare
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ls 2 * rt
#define rs 2 * rt + 1
#define gcd(a,b) __gcd(a,b)
#define eps 1e-8
#define lowbit(x) (x&(-x))
#define N 105
#define M 1000005
#define mod 1000000007
#define inf 0x3f3f3f3f
int n, cnt, low[N], dfn[N], fa[N], vis[N], check[N];
vector<int> edge[N];
void dfs(int u){
    low[u] = dfn[u] = ++ cnt; vis[u] = 1; int son = 0;
    for(auto &v : edge[u]){
        if(!vis[v]){
            fa[v] = u; son ++; dfs(v);
            if(low[v] >= dfn[u] && u != 1 && !check[u]) check[u] = 1;
            else if(son > 1 && u == 1 && !check[u]) check[u] = 1;
            low[u] = min(low[u], low[v]);
        }else if(fa[u] != v){
            low[u] = min(low[u], dfn[v]);
        }
    }
}
inline void solve(){
    for(int i = 1 ; i <= n ; i ++) low[i] = dfn[i] = fa[i] = vis[i] = check[i] = 0;
    for(int i = 0 ; i <= n ; i ++) edge[i].clear();
    int u, v;
    while(~scanf("%d", &u) && u){
        while(getchar() != '\n'){
            scanf("%d", &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }
    int ans = 0; cnt = 0;
    dfs(1);
    for(int i = 1 ; i <= n ; i ++) if(check[i]) ans ++;
    printf("%d\n", ans);
}
signed main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\in.txt", "r", stdin);
#endif
    while(~scanf("%d", &n) && n) solve();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}