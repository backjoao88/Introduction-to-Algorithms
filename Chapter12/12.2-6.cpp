/**
 *
 * 12.2-6
 * Consider a binary search tree T whose keys are distinct. Show that if the right
 * subtree of a node x in T is empty and x has a successor y , then y is the lowest
 * ancestor of x whose left child is also an ancestor of x . (Recall that every node is
 * its own ancestor.)
 *
 * R: That's what happen in the successor algoritm. If the right child of a node is empty, then we have to find
 * the slowest ancestor of x whereas this ancestor came from the LEFT SIDE. Because this will be the largest number right after.
 * This can be done by at each step veryfing if the next ancestor has a right child equals to the actual node.
 *
 */