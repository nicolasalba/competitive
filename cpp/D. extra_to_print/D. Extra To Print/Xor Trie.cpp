
// Find given an array of inserted nums into the trie
// It could find the max (someNum ^ someInsertedNum)
// Take into account the maximum position of the bit
const int start = 30;
struct Node {
    Node *left = nullptr;
    Node *right = nullptr;
    
    void insert(ll num, ll bit=start) {
        if (bit == -1) return;
        Node *&next = (num >> bit) & 1 ? right : left;
        if (next == nullptr) next = new Node();
        next->insert(num, bit-1);
    }

    ll max(ll num, ll bit=start) {
        if (bit == -1) return 0;
        Node *&next = (num >> bit) & 1 ? left : right;
        Node *&other = (next == left) ? right : left;
        if (next != nullptr) return (1 << bit) + next->max(num, bit-1);
        return other->max(num, bit-1);
    }
};
