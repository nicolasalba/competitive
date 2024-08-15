#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

struct multiordered_set {
    tree<ll,
        null_type,
        less_equal<ll>, // this is the trick
        rb_tree_tag,
        tree_order_statistics_node_update> oset;

    //this function inserts one more occurrence of (x) into the set.
    void insert(ll x) {
        oset.insert(x);
    }

    //this function checks weather the value (x) exists in the set or not.
    bool exists(ll x) {
        auto it = oset.upper_bound(x);
        if (it == oset.end()) {
            return false;
        }
        return *it == x;
    }

    //this function erases one occurrence of the value (x).
    void erase(ll x) {
        if (exists(x)) {
            oset.erase(oset.upper_bound(x));
        }
    }

    //this function returns the value at the index (idx)..(0 indexing).
    ll find_by_order(ll pos) {
        return *(oset.find_by_order(pos));
    }

    //this function returns the first index of the value (x)..(0 indexing).
    int first_index(ll x) {
        if (!exists(x)) {
            return -1;
        }
        return (oset.order_of_key(x));
    }

    //this function returns the last index of the value (x)..(0 indexing).
    int last_index(ll x) {
        if (!exists(x)) {
            return -1;
        }
        if (find_by_order(size() -1) == x) {
            return size() - 1;
        }
        return first_index(*oset.lower_bound(x)) -1;
    }

    //this function returns the number of occurrences of the value (x).
    int count(ll x) {
        if (!exists(x)) {
            return -1;
        }
        return last_index(x) - first_index(x) + 1;
    }
    
    // Count the numbers between [l, r]
    int count(ll l, ll r) {
        auto left = oset.upper_bound(l);
        if (left == oset.end() || *left>r) {
            return 0;
        }
        auto right = oset.upper_bound(r);
        if (right != oset.end()) {
            right = oset.find_by_order(oset.order_of_key(*right));
        }
        if (right == oset.end() || *right >r) {
            if (right == oset.begin()) return 0;
            right--;
        }
        return last_index(*right)-first_index(*left)+1;
    }

    //this function clears all the elements from the set.
    void clear() {
        oset.clear();
    }

    //this function returns the size of the set.
    ll size() {
        return (ll)oset.size();
    }
};
