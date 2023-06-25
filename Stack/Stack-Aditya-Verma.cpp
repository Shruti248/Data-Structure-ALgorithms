// O(n2) brute force --> add some DS to make it optimize

// Identification
// Array is GIVEN

// If array --> DS : Stack or Heap (Heap for Sorting)

// brute firce : O(n2) --> i = 0 to n & j = 0 to n

// inner for loop is dependent --> i = 0 to n & (j = 0 to i j++) (j = i to 0 j--) (j = i to n j++) (j = n to i j--) ---> STACK USED in this type of questions

// Therefire ---> if j loop is dependent on i --> USE STACK for otpimized
