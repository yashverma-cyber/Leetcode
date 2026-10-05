## 2. charCount[c] lookup/creation:
In C++, when you access a map key using [] syntax that does not exist yet, std::unordered_map automatically creates that key and initializes its value to 0 (the default value for int).

For example, on the first time seeing 'a', charCount['a'] becomes 0.


## 1. What does charCount.find(c) return?
If character c IS present in the map:
find(c) returns an iterator pointing directly to the key-value pair {c, count} stored in the map.

If character c IS NOT present in the map:
find(c) returns a special marker iterator called charCount.end().

