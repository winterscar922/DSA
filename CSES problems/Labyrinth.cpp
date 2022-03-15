vll dx = {1, -1, 0, 0};
vll dy = {0, 0, -1, 1};
vector<char>dir = {'D', 'U', 'L', 'R'};
bool is_valid(ll i, ll j, ll n, ll m, vector<vector<bool>> &vis) {
    if (i < 0 || j < 0 || i >= n || j >= m)return 0;
    if (vis[i][j])return 0;
    return 1;
}
bool found = 0;
void bfs(ll i, ll j , vector<vb>&vis, vector<vector<char>>&arr, ll n, ll m, vector<char> &v, vector<vector<char>>&gg) {
    queue<pair<ll, ll>> q;
    ll orix = i;
    ll oriy = j;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty()) {
        ll ii = q.front().ff;
        ll jj = q.front().ss;
        q.pop();
        FOR(i, 0, 4) {
            if (is_valid(ii + dx[i], jj + dy[i], n, m, vis) && arr[ii + dx[i]][jj + dy[i]] != '#') {
                ll newx = ii + dx[i];
                ll newy = jj + dy[i];
 
                q.push({newx, newy});
                gg[newx][newy] = dir[i];
 
                if (arr[newx][newy] == 'B') {
                    found = 1;
                    while (1) {
                        if (gg[newx][newy] == 'R')newy--, v.pb('R');
                        else if (gg[newx][newy] == 'L')newy++, v.pb('L');
                        else if (gg[newx][newy] == 'U')newx++, v.pb('U');
                        else if (gg[newx][newy] == 'D')newx--, v.pb('D');
                        if (newx == orix && newy == oriy)return;
                    }
                }
                vis[newx][newy] = 1;
            }
 
        }
    }
}
 
 
void solve() {
    ll n, m, cnt = 0;
    cin >> n >> m;
    vector<vector<char>>arr(n, vector<char>(m));
    vector<vector<bool>>vis(n, vector<bool>(m, 0));
    vector<vector<char>>gg(n, vector<char>(m));
    vector<char> v;
    // debug(gg)
    ll a, aa;
    ll b, bb;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> arr[i][j];
        }
    }
 
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if (arr[i][j] == 'A') {
                bfs(i, j, vis, arr, n, m, v, gg);
            }
        }
    }
    debug(v)
    reverse(all(v));
    if (found) {
        cout << "YES" << nline;
        cout << v.size() << nline;
        for (auto c : v)cout << c;
        cout << nline;
    } else {
        cout << "NO" << nline;
    }
}
 
