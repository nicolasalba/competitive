/* Disjoint Set Union 
This uses union by rank, it is longer to code but faster
than normal Disjoint Set Union. The time complexity per operation
is faster than O(log n)

It finds if 2 nodes in a graph are connected or not (have same 'find(x)' value),
and the size of the connected component, the graph starts with no edges, 
then you can add edges with 'group(nodeA, nodeB)' method.
*/

struct union_find {
    vi link, score, size;
    int n;
    void init(int nn) {
        link.resize(nn);
        score.resize(nn);
        size.resize(nn);
        this->n = nn;
        for (int i = 0; i < n; i++) {
            link[i] = i;
            score[i] = 0;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (link[x] == x) return x;
        return (link[x] = find(link[x]));
    }
    void group(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (score[pa] >= score[pb]) {
                link[pb] = pa;
                size[pa] += size[pb];
                if (score[pa] == score[pb]) score[pa]++;
            } else {
                link[pa] = pb;
                size[pb] += size[pa];
            }
        }
    }
};
