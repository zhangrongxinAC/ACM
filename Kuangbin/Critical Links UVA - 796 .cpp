/*
题意：
无向图割边数量并输出

题解：
无向图割边模板题
*/

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
#define N 100005
#define M 1000005
#define mod 1000000007
#define inf 0x3f3f3f3f
int n, cnt, top, scc, low[N], dfn[N], instack[N], st[N];
vector<int> edge[N];
vector<pair<int,int>> ans;
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt; instack[u] = 1; st[++top] = u;
    for(auto &v : edge[u]) {
        if(v == fa) continue;
        if(!dfn[v]){
            tarjan(v, u), low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]) ans.push_back({u, v}); // 满足割边条件
        }
        else if(instack[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        ++scc; int v;
        do{
            v = st[top--]; instack[v] = 0;
        }while (u != v);
    }
}
inline void solve(){
    cnt = top = scc = 0; ans.clear();
    for(int i = 1 ; i <= n ; i ++) edge[i].clear();
    for(int i = 1 ; i <= n ; i ++) low[i] = dfn[i] = instack[i] = 0;
    for(int i = 0 ; i < n ; i ++){
        int u, v, k; scanf("%d (%d)", &u, &k);
        for(int p = 0 ; p < k ; p ++) scanf("%d", &v), edge[u + 1].push_back(v + 1);
    }
    for(int i = 1 ; i <= n ; i ++) if(!dfn[i]) tarjan(i, i);
    for(auto &pq : ans) if(pq.first > pq.second) swap(pq.first, pq.second);
    sort(ans.begin(), ans.end());
    cout << ans.size() << " critical links" << '\n';
    for(auto &pq : ans) cout << pq.first - 1 << " - " << pq.second - 1 << '\n';
    cout << '\n';
}
signed main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\in.txt", "r", stdin);
#endif
    while(~scanf("%d", &n)) solve();
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}