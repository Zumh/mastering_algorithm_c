## Open address-hash
An open-addressed hash table is a type of hash table in which all elements are stored in the array itself, and collisions are resolved using a strategy called open addressing. In contrast to separate chaining, where each array index points to a linked list of elements that hash to the same index, open addressing deals with collisions by finding another position within the array.

Here’s an overview of how open-addressed hash tables work and some common techniques used to handle collisions:

### Open Addressing Methods

1. **Linear Probing:**
   - When a collision occurs, linear probing checks the next position in the array.
   - If that position is also occupied, it checks the following position, and so on, wrapping around to the beginning of the array if necessary.
   - The probing sequence can be defined as: \( h(k, i) = (h(k) + i) \% m \), where \( h(k) \) is the initial hash function, \( i \) is the probe sequence, and \( m \) is the size of the hash table.

2. **Quadratic Probing:**
   - This method uses a quadratic function to calculate the interval between probes.
   - The probing sequence can be defined as: \( h(k, i) = (h(k) + c1 \cdot i + c2 \cdot i^2) \% m \), where \( c1 \) and \( c2 \) are constants.
   - This approach reduces clustering compared to linear probing.

3. **Double Hashing:**
   - Double hashing uses a second hash function to determine the step size for probing.
   - The probing sequence can be defined as: \( h(k, i) = (h1(k) + i \cdot h2(k)) \% m \), where \( h1(k) \) and \( h2(k) \) are two different hash functions.
   - This method is considered one of the best open addressing methods because it reduces clustering and the probe sequence depends on the key.

### Characteristics

- **Load Factor:** The performance of open-addressed hash tables depends heavily on the load factor \( \alpha \) (i.e., the ratio of the number of elements to the table size). Higher load factors can lead to increased probing times.
- **Table Size:** To reduce the likelihood of collisions and clustering, the table size \( m \) is often chosen to be a prime number.
- **Deletion:** Deleting elements from an open-addressed hash table can be challenging because simply removing an element can disrupt the probing sequence. Special markers (such as "deleted" flags) are often used to indicate removed elements without breaking the probe sequence.

### Advantages and Disadvantages

**Advantages:**
- Open addressing tends to use less memory than separate chaining because it does not require additional pointers or storage for linked lists.
- It can be faster for lookups and insertions when the load factor is low due to better cache performance.

**Disadvantages:**
- Performance degrades significantly as the load factor increases, leading to longer probe sequences and more collisions.
- Deletion is more complex compared to separate chaining.

### Example Usage

Suppose you have a hash table with a size of 10 and you want to insert the values 5, 15, 25 using linear probing:
1. Hash(5) -> 5
2. Hash(15) -> 5 (collision, probe to next slot) -> 6
3. Hash(25) -> 5 (collision, probe to next slot) -> 6 (collision, probe to next slot) -> 7

After these insertions, the hash table would look something like this:
```
Index:   0 1 2 3 4 5 6 7 8 9
Values:  - - - - - 5 15 25 - -
```

In summary, open-addressed hash tables use probing strategies to resolve collisions within the array itself, and while they can be efficient with low load factors, their performance can degrade with higher load factors.