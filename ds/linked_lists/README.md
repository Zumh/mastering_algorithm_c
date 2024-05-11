## Q AND A

1. Arrays are better than linked lists when:

    1. **Fast Random Access:** You need to quickly access elements using their position (index). Arrays store elements contiguously in memory, allowing for constant time (O(1)) access with the index.
    2. **Limited Insertions/Deletions:** Insertions and deletions are less frequent than random access. Frequent changes can be slow in arrays as they require shifting elements in memory.

    In short, use arrays for fast retrieval by position and when you know the size beforehand. 

2. Operations of linked lists for inserting, removing, and accessing elements compare with similar ones for arrays:

* **Inserting and removing elements:**
    * Linked lists: Fast (usually O(1)), but requires finding the element first (can be slow in worst case).
    * Arrays: Slow (O(n)) because other elements might need to be shifted to make space.
* **Accessing elements:**
    * Linked lists: Slow (O(n)) in the worst case, as you need to traverse the list to find the element.
    * Arrays: Fast (O(1)) if you know the element's index (position) in the array.

**Choosing between them:**

* Use arrays when you need fast access by index and the size is fixed upfront.
* Use linked lists when you need frequent insertions/removals or the size is unknown. But be aware of the potential overhead in finding elements.

**The passage emphasizes considering the specific application when choosing between arrays and linked lists.**

3. 