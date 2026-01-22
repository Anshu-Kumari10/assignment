#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main() {
    int arr[30];
    int status;
    pid_t p1, p2;
    int final_sum_p1 = 0, final_sum_p2 = 0; 
    srand(time(NULL));
    printf("Array initialized by Parent \n");
    
    
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 50 + 1;
    }

    p1 = fork(); 

        if (p1 == 0) {
        int sum = 0;
            for (int v = 0; v < 15; v++) {
            if (arr[v] % 2 == 0) {
                sum += arr[v];
            }
        }
        exit(sum); 
    }

    waitpid(p1, &status, 0); 
    final_sum_p1 = WEXITSTATUS(status); 

    p2 = fork(); 

    if (p2 == 0) {
        int sum = 0;
        for (int b = 15; b < 30; b++) {
            if (arr[b] % 2 == 0) {
                sum += arr[b];
            }
        }
        exit(sum); 
    }

    waitpid(p2, &status, 0); 
    final_sum_p2 = WEXITSTATUS(status);  
    printf("\nTotal Even Sum of left side and right side are: %d and %d\n",
           final_sum_p1, final_sum_p2); 

    return 0;
}