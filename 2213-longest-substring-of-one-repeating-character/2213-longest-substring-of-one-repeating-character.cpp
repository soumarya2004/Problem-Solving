class Solution {
public:
    struct Node {
        int leftChar;
        int rightChar;
        int prefix;
        int suffix;
        int best;
        int len;
    };
    vector<Node> tree;
    Node merge(Node a, Node b) {
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;
        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.best = max(a.best, b.best);
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
            if (a.prefix == a.len){
                res.prefix = a.len + b.prefix;
            }
            if (b.suffix == b.len){
                res.suffix = b.len + a.suffix;
            }
        }
        return res;
    }
    void build(int node, int left, int right, string &s) {
        if (left == right) {
            tree[node] = {
                s[left],
                s[left],
                1,
                1,
                1,
                1
            };
            return;
        }
        int mid = (left + right) / 2;
        build(node * 2, left, mid, s);
        build(node * 2 + 1, mid + 1, right, s);
        tree[node] = merge(tree[node * 2],
                            tree[node * 2 + 1]);
    }
    void update(int node, int left, int right,
                int index, char c) {
        if (left == right) {
            tree[node] = {
                c,
                c,
                1,
                1,
                1,
                1
            };
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid){
            update(node * 2, left, mid, index, c);
        }
        else{
            update(node * 2 + 1, mid + 1, right, index, c);
        }
        tree[node] = merge(tree[node * 2],
                            tree[node * 2 + 1]);
    }
    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
        vector<int> ans;
        for (int i = 0; i < queryCharacters.size(); i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];
            update(1, 0, n - 1, index, c);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};