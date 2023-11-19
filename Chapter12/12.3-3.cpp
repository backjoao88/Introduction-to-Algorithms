/**
 * 12.3-3
 * You can sort a given set of n numbers by first building a binary search tree contain-
 * ing these numbers (using TREE-INSERT repeatedly to insert the numbers one by one)
 * and then printing the numbers by an inorder tree walk. What are the worst-
 * case and best-case running times for this sorting algorithm?
 *
 * R:
 *
 * * The worst case of the sorting algorithm would be the case where the elements that are being inserted are already sorted. So it would take
 * O(n) * O(k) or O(n²), where k is the degree of the tree which in this case is equal to N.
 *
 * * The best case would be when the elements being inserted are in a random order. So the height of the tree would be less than the number
 * of elements, represented by lg(n). In this case it would take O(n) * (O(lgn)) or O(n*lgn)
 *
 *
 */