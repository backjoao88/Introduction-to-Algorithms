/**
 *
 * 11.1-3
 * Suggest how to implement a direct-address table in which the keys of stored elements do not need to be distinct and the elements can have satellite data. All
 * three dictionary operations (INSERT, DELETE, and SEARCH) should run in O(1) time. (Don’t forget that DELETE takes as an argument a pointer to an object to be
 * deleted, not a key.)
 *
 * R: If the key is not unique, then we can implement a simple hash with the chaining collision method which uses doubly linked list as values.
 *
 */
