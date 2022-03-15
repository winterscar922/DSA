void dfs(ll i, ll j , vector<vb>&vis, vector<vector<char>>&arr, ll n, ll m) {
    if (i < 0 || j < 0 )return;
    if (i >= n || j >= m)return;
    if (vis[i][j])return;
    if (arr[i][j] == '#')return;
    vis[i][j] = 1;
    dfs(i, j - 1, vis, arr, n, m);
    dfs(i, j + 1, vis, arr, n, m);
    dfs(i - 1, j, vis, arr, n, m);
    dfs(i + 1, j, vis, arr, n, m);
}
 
 
void solve() {
    ll n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>>arr(n, vector<char>(m));
    vector<vector<bool>>vis(n, vector<bool>(m));
    FOR(i, 0, n) {
        FOR(j, 0, m)vis[i][j] = 0;
    }
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> arr[i][j];
        }
    }
    debug(arr)
 
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (arr[i][j] == '.' && !vis[i][j]) {
                dfs(i, j, vis, arr, n, m);
                debug(vis)
                cnt++;
            }
        }
    }
    cout << cnt << nline;
 
}
