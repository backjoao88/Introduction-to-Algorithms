/**
 *
 * 12.2-4
 * Professor Kilmer claims to have discovered a remarkable property of binary search
 * trees. Suppose that the search for key k in a binary search tree ends up at a leaf.
 * Consider three sets: A, the keys to the left of the search path; B , the keys on
 * the search path; and C , the keys to the right of the search path. Professor Kilmer
 * claims that any three keys a belonging A, b belonging B , and c belonging C must satisfy a <= b <= c . Give
 * a smallest possible counterexample to the professor’s claim.
 *
 * R: Lets suppose the tree below, searching for the leaf 65.
 *
 * The search path is B = {19,55,60,70,65}
 * The values in the left side of the search path are A = {1, 50, 58} and the right is C = {}
 *
 * This claim of Kilmer is wrong because there are values in A that are bigger than values in B.
 *
 *                                        19
 *                                1                55
 *
 *                                          50            60
 *
 *                                                 58           70
 *
 *                                                          65
 *
 */
