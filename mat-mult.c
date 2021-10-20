#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
	/* We declare variables of start and finish time, duration,
	   And three arrays by using 2-dimensional arrays.
	*/
	clock_t start, finish;
	double duration;
	int **matrix_array1;
	int **matrix_array2;
	int **matrix_array_result;

	// Check that we have the right number of arguments.
	if(argc != 4){
		printf("ERROR: incorrect number of arguments, please read the usage below.\n");
		printf("Usage: %s <N> <M> <seed>\n", argv[0]);
		return -1;
	}else{
		// All arguments should be converted to integers.
		int M = atoi(argv[1]);
		int N = atoi(argv[2]);
		// We fetch the seed number from the argv[3], which is the user's fourth input.
		int seed = atoi(argv[3]);
		srand((unsigned) seed);

		// Here we check each matrix dimension number entered.
		if(M == 0 || N == 0){
			printf("ERROR: invalid arguments. Please read the usage below.\n");
			printf("Usage: %s <N> <M> <seed>\n", argv[0]);
			return -1;
		}

		// We use malloc to dynamically allocate memories for these arrays.
		// And we need to check if each array returns null.
		matrix_array1 = malloc(M * sizeof(int *));
		if(matrix_array1 == NULL) return -1;
		matrix_array2 = malloc(N * sizeof(int *));
		if(matrix_array2 == NULL) return -1;
		matrix_array_result = malloc(M * sizeof(int *));
		if(matrix_array_result == NULL) return -1;

		// Hence we allocate memory to each of the numbers in each of matrices.
		// Including the resulted matrix.
		for(int i = 0; i<M; i++){
			matrix_array1[i] = malloc(N * sizeof(int));
			if (matrix_array1[i] == NULL) return -1;
		}

		for(int i = 0; i<N; i++){
			matrix_array2[i] = malloc(M * sizeof(int));
			if (matrix_array2[i] == NULL) return -1;
		}

		for(int i = 0; i<M; i++){
			matrix_array_result[i] = malloc(M * sizeof(int));
			if (matrix_array_result[i] == NULL) return -1;
		}

		// We print the formatted result to the console while we assign values.
		printf("MATRIX 1:\n");
		for(int i = 0; i<M; i++){
			for(int j = 0; j<N; j++){
				matrix_array1[i][j] = rand()%100;
				if(j == N-1){
					printf("%d",matrix_array1[i][j]);
				}else{
					printf("%d ",matrix_array1[i][j]);
				}
			}
			printf("\n");
		}

		printf("MATRIX 2:\n");
		for(int i = 0; i<N; i++){
			for(int j = 0; j<M; j++){
				matrix_array2[i][j] = rand()%100;
				if(j == M-1){
					printf("%d",matrix_array2[i][j]);
				}else{
					printf("%d ",matrix_array2[i][j]);
				}
			}
			printf("\n");
		}

		// We first initialise the values in result matrix to 0.
		for(int i = 0; i<M; i++){
			for(int j = 0; j<M; j++){
				matrix_array_result[i][j] = 0;
			}
		}

		printf("RESULT:\n");
		// Start the clock when the result part executes.
		start = clock();
	    // Iterate over rows of mat1.
	    for(int i = 0; i < M; i++){
	        // Iterate over columns of mat2.
	        for(int j = 0; j < M; j++){
	            // Iterate over rows of mat2.
	            for(int k = 0; k < N; k++){
	            	// Logic of matrix multiplication.
	                matrix_array_result[i][j] = matrix_array_result[i][j] + (matrix_array1[i][k] * matrix_array2[k][j]);
	            }
                if(j == M-1){
            		printf("%d\n",matrix_array_result[i][j]);
                }else{
                	printf("%d ",matrix_array_result[i][j]);
                }
	        }
	    }
	    // Close the clock to finish the timing requirements.
		finish = clock();
	}
	
	// Time conversion.
	duration = (double) (finish - start) / CLOCKS_PER_SEC;

	// We need to free every matrix's memory after use.
	free(matrix_array1);
	free(matrix_array2);
	free(matrix_array_result);

	// Finally display the execution time. 
	printf("EXECUTION TIME: %f\n", duration);

	// And return the code 0 for exit normally.
	return 0;
}