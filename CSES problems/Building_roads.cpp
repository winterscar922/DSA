
void dfs(ll node, vll &vis, vll g[]) {
    vis[node] = 1;
    for (auto child : g[node]) {
        if (!vis[child]) {
            dfs(child, vis, g);
        }
    }
}
 
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vll g[n + 1];
    vll v;
    vll vis(n + 1, 0);
    FOR(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll cnt = 0;
    FOR(i, 1, n + 1) {
        if (!vis[i]) {
            v.pb(i);
            dfs(i, vis, g);
            cnt++;
        }
    }
    cout << cnt - 1 << nline;
    FOR(i, 0, cnt - 1) {
        cout << v[i] << " " << v[i + 1] << nline;
    }
}
