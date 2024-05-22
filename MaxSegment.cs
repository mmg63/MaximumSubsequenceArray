
/*
Finding the maximum contiguous subarray sum using a more sophisticated algorithm that runs in 
O(n) time.
*/
using System;

public class MaximumSubsequence
{
    public static void Main()
    {
        Random rand = new Random();
        const int numberOfSequences = 10;
        const int sequenceLength = 15;

        for (int seq = 0; seq < numberOfSequences; seq++)
        {
            int[] sequence = new int[sequenceLength];
            int[] startIndex = new int[sequenceLength];
            int[] segmentSum = new int[sequenceLength];

            // Generate a random sequence
            for (int i = 0; i < sequenceLength; i++)
            {
                sequence[i] = rand.Next(-100, 101); // Random integers between -100 and 100
            }

            // First scan to compute initial startIndex and segmentSum
            for (int i = 0; i < sequenceLength; i++)
            {
                if (sequence[i] < 0)
                {
                    startIndex[i] = sequenceLength;
                    segmentSum[i] = 0;
                }
                else
                {
                    startIndex[i] = i;
                    segmentSum[i] = sequence[i];
                }
            }

            // Second scan to update startIndex and segmentSum
            for (int i = 1; i < sequenceLength; i++)
            {
                if (segmentSum[i - 1] + sequence[i] > segmentSum[i])
                {
                    segmentSum[i] = segmentSum[i - 1] + sequence[i];
                    startIndex[i] = startIndex[i - 1];
                }
            }

            // Find the maximum segment
            int maxSegmentSum = segmentSum[0];
            int maxStartIndex = startIndex[0];
            int maxEndIndex = 0;

            for (int i = 1; i < sequenceLength; i++)
            {
                if (segmentSum[i] > maxSegmentSum)
                {
                    maxSegmentSum = segmentSum[i];
                    maxStartIndex = startIndex[i];
                    maxEndIndex = i;
                }
            }

            // Output the results
            Console.WriteLine($"Sequence {seq + 1}:");
            Console.WriteLine("Sequence: " + string.Join(", ", sequence));
            Console.WriteLine($"Maximum Segment Sum: {maxSegmentSum}");
            Console.WriteLine($"Start Index: {maxStartIndex}");
            Console.WriteLine($"End Index: {maxEndIndex}");
            Console.WriteLine();
        }
    }
}
