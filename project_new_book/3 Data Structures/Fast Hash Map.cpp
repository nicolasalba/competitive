#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    long long operator()(const ll &x) const {
        return x ^ RANDOM;
    };
};
// There is no mp.count(x), so use mp.find(x) != mp.end()
gp_hash_table<ll,ll,chash> mp;
