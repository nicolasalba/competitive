// Same as set, but you can get the order of an element or the
// element in given sorted position in O(log n)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define oset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//find_by_order(k) order_of_key(k)
