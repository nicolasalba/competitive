// Use: unordered_set<pair<ll,ll>, HASH> exists;

struct HASH{
  size_t operator()(const pair<ll,ll>&x)const{
    return hash<ll>()(((ll)x.first)^(((ll)x.second)<<32));
  }
};

