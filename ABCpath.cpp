// Problem link:https://www.spoj.com/problems/ABCPATH/

// Problem: You will be given a 2-dimensional grid of letters.Find the length of the longest path of consecutive letters, starting at 'A'. Paths can step from one letter in the grid to any adjacent letter (horizontally, vertically, or diagonally).

// idea:

// Brute: perform dfs from the cells containg the alphabet 'A'.keep taking max path found.

ll global_max = 0;
void dfs(ll i, ll j, ll n, ll m, ll &cnt, vector<vector<char>>&arr, ll ii, ll jj, vector<vector<bool>>&vis) {
    if (i < 0 || j < 0)return;
    if (i > n || j > m)return;
    if ((arr[i][j] == arr[ii][jj] + 1) && !vis[i][j]) {
        if (vis[ii][jj]) {
            cnt = arr[ii][jj] - 'A' + 1;
        }
        cnt++;
        vis[ii][jj] = 1;

        //all corners of a cell
        dfs(i, j - 1, n, m, cnt, arr, i, j, vis);
        dfs(i, j + 1, n, m, cnt, arr, i, j, vis);
        dfs(i - 1, j, n, m, cnt, arr, i, j, vis);
        dfs(i + 1, j, n, m, cnt, arr, i, j, vis);
        dfs(i + 1, j + 1, n, m, cnt, arr, i, j, vis);
        dfs(i - 1, j - 1, n, m, cnt, arr, i, j, vis);
        dfs(i - 1, j + 1, n, m, cnt, arr, i, j, vis);
        dfs(i + 1, j - 1, n, m, cnt, arr, i, j, vis);

        global_max = max(global_max, cnt);

    }
}


void solve() {
    ll tc = 1;
    while (1) {
        ll n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)return;
        vector<vector<char>>arr(n + 1, vector<char>(m + 1));

        ll  local_max = 0;
        FOR(i, 1, n + 1) {
            FOR(j, 1, m + 1) {
                cin >> arr[i][j];
                if (arr[i][j] == 'A')local_max = 1;
            }
        }
        arr[0][0] = 'A' - 1;
        FOR(i, 1, n + 1) {
            FOR(j, 1, m + 1) {
                if (arr[i][j] == 'A') {
                    ll cnt = 0;
                    vector<vector<bool>>vis(n + 1, vector<bool>(m + 1));
                    FOR(i, 0, n + 1) {
                        FOR(j, 0, m + 1)vis[i][j] = 0;
                    }
                    dfs(i, j, n, m, cnt, arr, 0, 0, vis);
                    local_max = max(local_max, global_max);
                    global_max = 0;
                }
            }
        }
        cout << "Case " << tc++ << ": " << min(local_max, 26LL) << nline;
    }

}


