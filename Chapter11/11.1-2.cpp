/**
 *
 * 11.1-2
 * A bit vector is simply an array of bits (0s and 1s). A bit vector of length
 * takes much less space than an array of
 * pointers. Describe how to use a bit vector to represent a dynamic set of distinct elements with no satellite data. Dictionary operations should run in
 * time.
 *
 * R: To represent a set of integers with a array of bit instead of an array of pointers, we can use a char[] vector, where if we have a '0' in a specified position
 * means that the key in that index doesn't exist. The opposite, if we have a '1' in the specifiec position, means that the key exists.
 * To insert, we just pass the key (there's no satelite data) by parameter and set 1 to the position specified.
 * To delete, we just pass the key and set 0 to the position specified.
 *
 */