#include <ext/pb_ds/assoc_container.hpp>

template <typename T, class Compare = std::less<>>
using OSet = __gnu_pbds::tree<T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;
