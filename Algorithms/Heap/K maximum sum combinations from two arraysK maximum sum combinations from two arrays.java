// Question

Input :  A[] : {3, 2} 
         B[] : {1, 4}
         K : 2 [Number of maximum sum
               combinations to be printed]
Output : 7    // (A : 3) + (B : 4)
         6    // (A : 2) + (B : 4)
Input :  A[] : {4, 2, 5, 1}
         B[] : {8, 0, 3, 5}
         K : 3
Output : 13   // (A : 5) + (B : 8)
         12   // (A : 4) + (B :  8)
         10   // (A : 2) + (B : 8)

// Solution

// Java program to find K
// maximum combinations
// from two arrays,
import java.io.*;
import java.util.*;

class Jay {

	// function to display first K
	// maximum sum combinations
	static void KMaxCombinations(int A[], int B[], 
								int N, int K)
	{
		// max heap.
		PriorityQueue<Integer> pq
			= new PriorityQueue<Integer>(
				Collections.reverseOrder());

		// Insert all the possible
		// combinations in max heap.
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				pq.add(A[i] + B[j]);

		// Pop first N elements
		// from max heap and
		// display them.
		int count = 0;

		while (count < K) {
			System.out.println(pq.peek());
			pq.remove();
			count++;
		}
	}

	// Driver Code
	public static void main(String[] args)
	{
		int A[] = { 4, 2, 5, 1 };
		int B[] = { 8, 0, 5, 3 };
		int N = A.length;
		int K = 3;

		// Function Call
		KMaxCombinations(A, B, N, K);
	}
}
