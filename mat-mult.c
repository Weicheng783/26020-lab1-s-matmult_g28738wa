#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int gettimeofday();
// int timersub();
int isdigit();
int main(int argc, char **argv){
	clock_t start, finish;
	double duration;
	int **matrix_array1;
	int **matrix_array2;
	int **matrix_array_result;
	// struct timeval start, stop, elapsed;
	// gettimeofday(&start, NULL);

	// Check that we have the right number of arguments
	if(argc != 4){
		printf("ERROR: incorrect number of arguments, please read the usage below.\n");
		printf("Usage: %s <N> <M> <seed>\n", argv[0]);
		return -1;
	}
	//HAS PROBLEM...
	// else if(atoi(argv[1]) == 0 || isdigit(atoi(argv[2])) == 0 || isdigit(atoi(argv[3])) == 0){
	// 	printf("ERROR: invalid arguments.\n");
	// 	printf("Usage: %s <N> <M> <seed>\n", argv[0]);
	// 	return -1;
	// }
	else{
		// All arguments should be converted to integers
		int M = atoi(argv[1]);
		// printf("%d\n", M);
		int N = atoi(argv[2]);
		int seed = atoi(argv[3]);
		srand((unsigned) seed); //time( NULL )

		
		matrix_array1 = malloc(M * sizeof(int *));
		if(matrix_array1 == NULL) return -1;
		matrix_array2 = malloc(N * sizeof(int *));
		if(matrix_array2 == NULL) return -1;
		matrix_array_result = malloc(M * sizeof(int *));
		if(matrix_array_result == NULL) return -1;

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


		printf("RESULT:\n");
		start = clock();
	    // Iterate over rows of mat1
	    // printf("%d\n", sizeof(matrix_array1)/sizeof(matrix_array1[0])/sizeof(matrix_array1[0][0]));
	    // printf("%d\n", sizeof(matrix_array1[0]));
	    for(int i = 0; i < M; i++){
	        // Iterate over columns of mat2:
	        for(int j = 0; j < M; j++){
	            // Iterate over rows of mat2:
	            for(int k = 0; k < N; k++){
	                matrix_array_result[i][j] = matrix_array_result[i][j] + matrix_array1[i][k] * matrix_array2[k][j];
	            }
                if(j == M-1){
            		printf("%d\n",matrix_array_result[i][j]);
                }else{
                	printf("%d ",matrix_array_result[i][j]);
                }
	        }
	    }
		// printf("%d\n", rand()%100);
		// mat1 = [[random.randrange(100) for i in range(M)] for j in range(N)];
		// for(int i=0; i<1000000; i++){
		// 	if(rand()%100 == 100){
		// 		printf("ERROR! MEET 100!\n");
		// 		exit(-1);
		// 	}
		// }
		// printf("Done LOOP.\n");
		finish = clock();
	}
	// gettimeofday(&stop,NULL);
	// timersub(&stop, &start, &elapsed);
	
	duration = (double) (finish - start) / CLOCKS_PER_SEC;
	// printf("EXECUTION TIME: %lu.%06lu\n", elapsed.tv_sec, elapsed.tv_usec); //%f
	free(matrix_array1);
	free(matrix_array2);
	free(matrix_array_result);
	printf("EXECUTION TIME: %f\n", duration);
	return 0;
}