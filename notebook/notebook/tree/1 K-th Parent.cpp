1. K-th Parent.cpp

class TreeAncestor {
    int LOG = 20;
    int up[50000][20];
public:
    TreeAncestor(int n, vector<int>& parent) {
        memset(up, -1, 50000 * LOG * 4);
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                if (up[i][k-1] != -1)
                    up[i][k] = up[up[i][k-1]][k-1];
            }   
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < LOG; i++) {
            if (k & 1<<i) {
                node = up[node][i];
            }
            if (node == -1) return -1;
        }
        return node;
    }
};