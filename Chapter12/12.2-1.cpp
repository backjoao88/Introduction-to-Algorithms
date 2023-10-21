/**
 *
 * 12.2-1
 * You are searching for the number 363 in a binary search tree containing numbers
 * between 1 and 1000. Which of the following sequences cannot be the sequence of
 * nodes examined?
 *
 * a. 2, 252, 401, 398, 330, 344, 397, 363.
 * b. 924, 220, 911, 244, 898, 258, 362, 363.
 * c. 925, 202, 911, 240, 912, 245, 363.
 * d. 2, 399, 387, 219, 266, 382, 381, 278, 363.
 * e. 935, 278, 347, 621, 299, 392, 358, 363.
 *
 * R: It's the letter E. The sequence of comparisons "347, 621, 299" doesn't make sense because in a binary search the number being
 * compare must be in the range of the last two numbers compared, if not, the tree is broken. It's as well the letter C, because the comparison
 * "911" limits the search, and then a comparison of "912" is made.
 */