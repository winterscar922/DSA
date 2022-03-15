
void dfs(ll node, vll g[], vll &vis, bool col, vll &colr) {
    vis[node] = 1;
    colr[node] = col;
    for (auto child : g[node]) {
        if (!vis[child]) {
            dfs(child, g, vis, !col, colr);
        }
        else {
            if (colr[node] == colr[child]) {
                cout << "IMPOSSIBLE" << nline;
                exit(0);
            }
        }
    }
}
 
 
void pleaseAC() {
    ll n, m;
    cin >> n >> m;
    vll g[n + 1];
    vll vis(n + 1, 0);
    vll colr(n + 1);
    FOR(i, 0, m) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll cnt = 0;
    FOR(i, 1, n + 1) {
        if (!vis[i]) {
            dfs(i, g, vis, 0, colr);
            cnt++;
        }
    }
 
    FOR(i, 1, n + 1) {
        if (colr[i] == 0) {
            cout << 2 << " ";
        }
        else
            cout << 1 << " ";
    }
}
