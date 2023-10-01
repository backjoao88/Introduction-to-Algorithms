/***
 * 11.2-1
 * You use a hash function h to hash n distinct keys into an array T of length m.
 * Assuming independent uniform hashing, what is the expected number of collisions? More precisely, what is the expected cardinality of ˚
 * {(k1,k2)} Where k1 <> k2 and h(k1) = h(k2) ?
 *
 * R: The number of collisions would be the sum of (n-i)/m, where i goes from 0 to N (total number of keys). Given that the probability of
 * one collision to happen is 1/m.
 *
 */