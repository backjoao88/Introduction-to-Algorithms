/****
 * Suppose that we hash a string of
 * characters into
 * slots by treating it as a radix-128 number and then using the division method. We can easily represent the number
 * as a 32-bit computer word, but the string of
 * characters, treated as a radix-128 number, takes many words.
 * How can we apply the division method to compute the hash value of the character string without using more than a constant number of words of storage outside the string itself?
 *
 * R: Using a function that convert each character into a integer value. Then using another routine to sum all these integers and by the end use the mod function.
 *
 */