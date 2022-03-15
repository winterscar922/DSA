const int N = 501;
ll dist[N][N];
 
void pleaseAC() {
    ll n, m, q;
    cin >> n >> m >> q;
    vector<pii>g[n + 1];
    FOR(i, 0, n + 1) {
        FOR(j, 0, n + 1) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            dist[i][j] = INF;
        }
    }
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
 
    }
    FOR(k, 1, n + 1) {
        FOR(i, 1, n + 1) {
            FOR(j, 1, n + 1) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
 
    while (q--) {
        ll a, b;
        cin >> a >> b;
        (dist[a][b] == INF) ? cout << "-1\n" : cout << dist[a][b] << nline;
    }
 
}
