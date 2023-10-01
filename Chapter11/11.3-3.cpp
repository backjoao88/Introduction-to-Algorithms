/****
 *
 * 11.3-3
 * Consider a version of the division method in which h(k) = k mod m, where
 * m = 2^p - 1 (a prime number) and k is a character string interpreted in radix 2p. Show that if string x
 * can be converted to string y by permuting its characters, then x and y hash to the
 * same value. Give an example of an application in which this property would be
 * undesirable in a hash function.
 *
 * R: That'd be undesirable for a orthographic corrector for example. If a orthographic corrector uses a hash table to store it's words and map them with a hash function that
 * hash the permutations of x to the same slot, it could be showing me words such as "PATO" and "TOPA" in the same suggestion.
 *
 *
 */

#include <stdio.h>
#include <math.h>

int hashFn(const char *key, int p)
{
    int hash = 0;
    char curr = key[0];
    int idx = 0;
    int base = pow(2, p);
    int m = pow(2, p) - 1;
    printf("m is %d\n", m);
    while (curr != '\0')
    {
        curr = key[idx];
        hash += (base + curr);
        idx++;
    }
    return hash % m;
};

int main(void)
{
    const char *firstWord = "PATO";
    const char *secondWord = "TOPA";

    // radix-128
    int firstWordIndex = hashFn(firstWord, 8);
    int secondWordIndex = hashFn(secondWord, 8);

    printf("Hash value of the first word: %d\n", firstWordIndex);
    printf("Hash value of the second word: %d\n", secondWordIndex);
}