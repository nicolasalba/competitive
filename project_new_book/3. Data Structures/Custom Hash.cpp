// Avoid hashing hacks and improve performance of hash structures
// e.g. unordered_map<ll,ll,custom_hash> 

// use a fixed ll FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
struct custom_hash {
    size_t operator()(uint64_t x) const {
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

// pair
struct chash {
  size_t operator()(const pair<ll,ll>&x)const{
    return ...;
  }
};

