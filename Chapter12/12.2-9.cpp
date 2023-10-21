/***
 *
 * 12.2-9
 * Let T be a binary search tree whose keys are distinct, let x be a leaf node, and let y
 * be its parent. Show that y: key is either the smallest key in T larger than x: key or
 * the largest key in T smaller than x: key.
 *
 * R: Parent Key is gonna be smallest than the x.key whose is in it's right subtree (SUCCESSOR). Parent Key is the smallest key in T which is big than it's first right
 * child key.
 *    Parent Key is gonna be bigger than the x.key whose is in it's left subtree (PREDECESSOR). Parent Key is the bigger key in T which is big
 * than it's first left child key.
 *
 */