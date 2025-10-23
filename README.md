# cpp_strong_array

**Method-chained array implementation**

Designed to allow *chained transformations* and *expressive syntax* similar to array languages (APL, NumPy, etc.).

---

### Example

```cpp
#include "strong.hpp"
using strong::array;

int main() {
    array::iota(10).show();
    // [ 1 2 3 4 5 6 7 8 9 10 ]

    std::cout << array::iota(1'000'000).times(2).plus(5).sum() << "\n";
    // 1.00001e+12

    std::cout << array::iota(5).times(5).show().pick(3) << "\n";
    // [ 5 10 15 20 25 ]
    // 15

    return 0;
}
```
