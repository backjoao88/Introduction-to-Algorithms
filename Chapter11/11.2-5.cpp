/***
 *
 * 11.2-5 Suppose that we are storing a set of n keys into a hash table of size m.
 * Show that if the keys are drawn from a universe U with |U| > nm, then U has a subset of size n consisting of
 * keys that all hash to the same slot, so that the worst-case searching time for hashing with chaining is ѳ(n).
 *
 * R: Use the N mod TOTAL function to generate the keys to fit into the hashtable, searching will be O(n) in worst case. This
 * function hash the table into uniform slices until reaches the max value of N
 *
 */