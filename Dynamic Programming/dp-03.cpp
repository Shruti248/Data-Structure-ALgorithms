// Matrix chain Multiplication

// Identification
// Given : String or Array
        // Take some i & j
        // Take k between k
        // SO larger problem (i to j) --> divided in various subproblems(i to k & k+1 to j)
        // SO smaller problems will be solved by taking k everytime between i to j
        // All the partition of different k will result in some temp ans;
        // We apply some function in the temp ans to get the final ans

// Main format code : All the questions based on MCM will have this format

// NOTE : Base condition of recursion : (Smallest valid Input or think of first invalid Input )

// Recursive Code
// int solve( int arr[] , int i , int j){

//     // Base condition
//     // i == j : 1 element in array
//     // i > j : Invalid input (No element in array)
//     if(i > j){
//         return 0;
//     }

//     // Breaking into k from i to j
//     for(int k = i ; k<j ; k++){
//         // Calculate temp ans
//         int tempAns = solve(arr , i , k) + solve(arr , k+1 , j);

//         int ans = func(tempAns) // applying some func in tempAns (like max , min etc ) )which depends on question
//     }

//     return ans;

// }

// Change teh format as per the questions
