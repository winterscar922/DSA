bool found = 0;
void bfs(ll node, ll n, vll g[], vll &vis) {
    queue<ll>q;
    q.push(1);
    vis[1] = 1;
    vll par(n + 1);
    par[1] = -1;
    vll dist(n + 1, 0);
    while (!q.empty()) {
        ll fro = q.front();
        q.pop();
        for (auto child : g[fro]) {
            if (!vis[child]) {
                dist[child] = dist[fro] + 1;
                par[child] = fro;
                if (child == n) {
                    found = 1;
                    ll beg = n;
                    ll end = par[1];
                    vll path;
                    while (beg != end) {
                        path.pb(beg);
                        beg = par[beg];
                    }
                    cout << dist[n] + 1 << nline;
                    reverse(all(path));
                    for (auto child : path)cout << child << " ";
 
                    return;
                }
                vis[child] = 1;
                q.push(child);
            }
        }
    }
    cout << "IMPOSSIBLE" << nline;
 
}
 
 
void pleaseAC() {
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
    bfs(1, n, g, vis);
 
 
}
