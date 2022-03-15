void solve() {
    ll n, m;
    cin >> n >> m;
    vll dist(n + 1, INF);
    vector<pii>g[n + 1];
    vll vis(n + 1, 0);
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({v, w});
    }
    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > q;
    q.push({0, 1});
    while (!q.empty()) {
        auto fro = q.top();
        ll node = fro.ss;
        q.pop();
 
        if (vis[node])continue;
        ll dis = fro.ff;
        vis[node] = 1;
        for (auto child : g[node]) {
            if (dis + child.ss < dist[child.ff]) {
                dist[child.ff] = dis + child.ss;
                q.push({dist[child.ff], child.ff});
            }
        }
    }
 
    FOR(i, 1, n + 1) {
        cout << dist[i] << " ";
    }
    cout << nline;
}
