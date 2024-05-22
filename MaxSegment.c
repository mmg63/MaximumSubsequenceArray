/*
Finding the maximum contiguous subarray sum using a more sophisticated algorithm that runs in 
O(n) time.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SEQUENCES 10
#define SEQUENCE_LENGTH 15

void findMaxSegment(int sequence[], int length, int *maxSum, int *startIdx, int *endIdx) {
    int startIndex[length];
    int segmentSum[length];

    // Initial scan
    for (int i = 0; i < length; i++) {
        if (sequence[i] < 0) {
            startIndex[i] = i + 1;
            segmentSum[i] = 0;
        } else {
            startIndex[i] = i;
            segmentSum[i] = sequence[i];
        }
    }

    // Second scan to update startIndex and segmentSum
    for (int i = 1; i < length; i++) {
        if (segmentSum[i - 1] + sequence[i] > segmentSum[i]) {
            segmentSum[i] = segmentSum[i - 1] + sequence[i];
            startIndex[i] = startIndex[i - 1];
        }
    }

    // Find the maximum segment sum and indices
    *maxSum = segmentSum[0];
    *startIdx = startIndex[0];
    *endIdx = 0;

    for (int i = 1; i < length; i++) {
        if (segmentSum[i] > *maxSum) {
            *maxSum = segmentSum[i];
            *startIdx = startIndex[i];
            *endIdx = i;
        }
    }
}

void generateRandomSequence(int sequence[], int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = (rand() % 201) - 100;  // Random integers between -100 and 100
    }
}

int main() {
    srand(time(0));

    int sequence[SEQUENCE_LENGTH];
    int maxSum, startIdx, endIdx;

    for (int seq = 0; seq < NUM_SEQUENCES; seq++) {
        generateRandomSequence(sequence, SEQUENCE_LENGTH);
        
        printf("Sequence %d: ", seq + 1);
        for (int i = 0; i < SEQUENCE_LENGTH; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");

        findMaxSegment(sequence, SEQUENCE_LENGTH, &maxSum, &startIdx, &endIdx);
        
        printf("Max Segment Sum: %d, Start Index: %d, End Index: %d\n\n", maxSum, startIdx, endIdx);
    }

    return 0;
}
