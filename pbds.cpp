#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Functions:
//
// s.order_of_key(x)
// Number of elements strictly less than x
//
// s.find_by_order(k)
// Iterator to kth element (0 indexed)