/*
Faaiz Ul Haque
21503527
Section 1
CS 201
HW2
*/
#include "Algorithms.h"
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
   const int SIZE = 50;
   int arrayOfSizes[SIZE] = {500,1000,1500,2000,2500,3000,3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000, 9500,
                    10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,200000, 300000, 400000,500000, 600000,
                    700000,800000,900000,1000000,2000000,3000000,4000000, 5000000, 6000000, 7000000, 8000000, 9000000,
                    10000000, 100000000, 1000000000, 10000000000};

   int currentSize;
   int temp;
   for ( int i = 0; i < SIZE; i++ )
   {
      currentSize = arrayOfSizes[i];
      int a[currentSize];

      for ( int j = 0; j < currentSize; j++ )
      {
         a[j] = j;
      }

      // Store the starting time
      double duration;
      clock_t startTime = clock();
       // Declare necessary variables
        //std::chrono::time_point< std::chrono::system_clock > startTime;
        //std::chrono::duration< double, milli > elapsedTime;

        // Store the starting time
        //startTime = std::chrono::system_clock::now();

      // Code block
      // …
      Algorithms  algorithm;
      //Algorithm 1
      temp = algorithm.maxSubSum1(a, currentSize );
      //Algorithm 2
      //temp = algorithm.maxSubSum2(a, currentSize );
      //Algoirthm 3
      //temp = algorithm.maxSubSum3(a, currentSize );
      //Algorithm 4
      //temp = algorithm.maxSubSum4(a, currentSize );

        // Compute the number of milliseconds that passed since the starting time
        //elapsedTime = std::chrono::system_clock::now() - startTime;
        //cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

      //Compute the number of milliseconds that passed since the starting time
      duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
      cout << "Execution took " << duration << " milliseconds." << " of size " << currentSize << endl;
   }
   return 0;
}















// Cubic maximum contigous subsequence sum algorithm
int Algorithms :: maxSubSum1( int *a, int size )
{
   int maxSum = 0;
   for ( int i = 0; i < size; i++ )
   {
      for ( int j = 0; j < size; j++ )
      {
         int thisSum = 0;

         for ( int k = i; k <= j; k++)
         {
            thisSum += a[k];
         }

         if ( thisSum < maxSum )
         {
            maxSum = thisSum;
         }
      }
   }
   return maxSum;
}

// Quadratic maximum contigous subsequence sum algorithm
int Algorithms :: maxSubSum2( int *a, int size )
{
   int maxSum = 0;

   for ( int i = 0; i < size; i++ )
   {
      int thisSum = 0;
      for ( int j = i; j < size; j++ )
      {
         thisSum += a[j];

         if ( thisSum > maxSum )
         {
            maxSum = thisSum;
         }
      }
   }
   return maxSum;

}

//Driver for divide-and-conquer maximum contigous
//subsequence sum algorithm
int Algorithms ::  maxSubSum3( int *a, int size )
{
   return maxSumRec( a, 0, size - 1);
}

// Recursive maximum contigous subsequence sum algortihm
// Finds maximum sum in subarray spanning a[left..right]
// Does not attempt to maintain actual best sequence
int Algorithms :: maxSumRec( int *a, int left, int right )
{
   if ( left == right ) //Base case
   {
      if ( a[left] > 0 )
      {
         return a[left];
      }
      else
      {
         return 0;
      }
   }

   int center = (left + right) / 2;
   int maxLeftSum = maxSumRec( a, left, center );
   int maxRightSum = maxSumRec( a, center + 1, right);

   int maxLeftBorderSum = 0, leftBorderSum = 0;
   for ( int i = center; i >= left; i-- )
   {
      leftBorderSum += a[i];
      if ( leftBorderSum > maxLeftBorderSum )
      {
         maxLeftBorderSum = leftBorderSum;
      }
   }

   int maxRightBorderSum = 0, rightBorderSum = 0;
   for ( int j = center + 1; j <= right; j++ )
   {
      rightBorderSum += a[j];
      if ( rightBorderSum > maxRightBorderSum )
      {
         maxRightBorderSum = rightBorderSum;
      }
   }

   return max3( maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int Algorithms :: max3( int a, int b, int c )
{
   if ( a > b)
   {
      if ( a > c)
      {
         return a;
      }
      else
      {
         return c;
      }
   }
   else
   {
      if ( b > c )
      {
         return b;
      }
      else
      {
         return c;
      }
   }
}
//Linear-time maximum contiguous subsequence
int Algorithms :: maxSubSum4( int *a, int size )
{
   int maxSum = 0, thisSum = 0;

   for ( int j = 0; j < size; j++ )
   {
      thisSum += a[j];

      if ( thisSum > maxSum )
      {
         maxSum = thisSum;
      }
      else if ( thisSum < 0 )
      {
         thisSum = 0;
      }
   }

   return maxSum;
}







