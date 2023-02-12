// C++ program to print largest contiguous array sum
#include<iostream>
#include<climits>
using namespace std;
//int divideAndConquer(int *array, int size);

int divideAndConquer(int *array, int size)
{
	int max = INT_MIN;
	int newMax = 0;
	int j = 0;
	int i = 0;
	int front = 0;
	int back = 0;

	for (i = 0; i < size; i++)
	{
		newMax += array[i];
		if(max < newMax)
		{
			front = j;
			back = i;
			max = newMax;
		}	
		if(newMax < 0)
		{
			newMax = 0;
			j = i+1;
		}
	}
	return max;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int arraySize;
	int *a;
	
	cin >> arraySize;
  	a = new int[arraySize];

	for(int i=0; i < arraySize; i++)
	{
    	cin >> a[i];
	}

	int max_sum = divideAndConquer(a, arraySize);
	cout << max_sum;
	return 0;
}
