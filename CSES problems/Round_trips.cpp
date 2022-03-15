void dfs(ll node, vll &vis, vll g[], ll par, vll &glo, vll &parent) {
    vis[node] = 1;
    for (auto child : g[node]) {
        glo.pb(child);
        if (!vis[child]) {
            parent[child] = node;
            dfs(child, vis, g, node, glo, parent);
        }
        else if (par != child) {
            vll tmp;
            tmp.pb(node);
            ll beg = node;
            ll end = child;
            while (beg != end) {
                beg = parent[beg];
                tmp.pb(beg);
            }
            reverse(all(tmp));
            tmp.pb(beg);
            cout << tmp.size() << nline;
            for (auto c : tmp)cout << c << " ";
            debug(tmp)
            cout << nline;
            exit(0);
        }
    }
}
 
 
void solve() {
    ll n, m;
    cin >> n >> m;
    vll g[n + 1];
    vll parent(n + 1);
    vll vis(n + 1, 0);
    while (m--) {
        ll u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR(i, 1, n + 1) {
        vll glo;
        glo.pb(i);
        if (!vis[i]) {
            dfs(i, vis, g, -1, glo, parent);
            debug(parent)
        }
 
    }
 
 
    cout << "IMPOSSIBLE" << nline;
 
}
