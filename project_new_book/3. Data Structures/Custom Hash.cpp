struct custom_hash {
  size_t operator()(uint64_t x)const{x ^= FIXED_RANDOM;
    return x ^ (x >> 16);}};
struct chash {
  size_t operator()(const pair<ll,ll>&x)const{
    return ...; }};

