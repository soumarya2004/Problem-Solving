class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<pair<int,int>> litter;
        int sr = -1, sc = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }
        int k = litter.size();
        int fullMask = (1 << k) - 1;
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(n, vector<int>(1 << k, -1))
        );
        queue<tuple<int,int,int,int>> q;
        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy});
        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();
                if (mask == fullMask){
                    return moves;
                }
                int dr[] = {1, -1, 0, 0};
                int dc[] = {0, 0, 1, -1};
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n){
                        continue;
                    }
                    if (classroom[nr][nc] == 'X'){
                        continue;
                    }
                    if (e == 0){
                        continue;
                    }
                    int ne = e - 1;
                    int nmask = mask;
                    if (classroom[nr][nc] == 'L') {
                        int idx = id[nr][nc];
                        nmask |= (1 << idx);
                    }

                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    if (best[nr][nc][nmask] >= ne){
                        continue;
                    }
                    best[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne});
                }
            }
            moves++;
        }
        return -1;
    }
};