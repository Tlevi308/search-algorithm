//name:TAMIR

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <math.h>
#define M 1000
//----------------------------------------------------------------------------------------//
//sorted array whit 'n' number sorted and rest array is '0'(zeros)
//the program geting V->array, its size->m, num->x
//---------------------------------------------------------------------------------------//
//the function returm index num->x in the array->V 
//or 0 if num->x not found

//O(n)
int search1(int array[], int size, int search_num, int* count);
//O(log(m))
int search2(int array[], int size, int search_num, int* count);
//O(log(n))
int search3(int array[], int size, int search_num, int* count);
//bubble sort
void bubbleSort(int array[], int size_n);
//print arr
void printArr(int array[]);
//avg
int avg(int* p);

void main() {

	int arr[M] = { 0 };
	int avg_size_n = 0;

	//count the number of tests
	int* count1 = 0;
	int* count2 = 0;
	int* count3 = 0;

	//the index that has 'search_num' in
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;

	srand(time(NULL));
	int size_n = rand() % (300 - 200 + 1) + 200;
	int num_to_search = rand() % size_n;

	//test for one arr
	for (int j = 0; j < size_n; j++)
	{
		arr[j] = rand() % (1000 - 1 + 1) + 1;
	}
	bubbleSort(arr, size_n);
	printArr(arr);

	printf("\n");
	printf("\n");
	printf("The size of array is : %d\n", M);
	printf("The size of 'n' is : %d\n", size_n);
	printf("The num to saerch is : %d\n", num_to_search);
	printf("The number zero means the %d is not in array", num_to_search);
	printf("\n");
	printf("\n");
	printf("Test for this array");
	printf("\n");
	index1 = search1(arr, M, num_to_search, &count1);
	index2 = search2(arr, M, num_to_search, &count2);
	index3 = search3(arr, M, num_to_search, &count3);
	printf("The index thet the number %d is on search1 is : %d\n", num_to_search, index1);
	printf("The index thet the number %d is on search2 is : %d\n", num_to_search, index2);
	printf("The index thet the number %d is on search3 is : %d\n", num_to_search, index3);
	printf("The number of tests for search1 is : %d\n", count1);
	printf("The number of tests for search2 is : %d\n", count2);
	printf("The number of tests for search3 is : %d\n", count3);

	
	//count the sum number of tests in function
	int *sum_count1 = 0;
	int *sum_count2 = 0;
	int *sum_count3 = 0;

	//avgerge the sum number of tests in function
	int avg_count1 = 0;
	int avg_count2 = 0;
	int avg_count3 = 0;
	
	for (int i = 0; i < M; i++)//1000 times
	{
		
		for (int j = 0; j < size_n; j++)
		{
			arr[j] = rand() % (1000 - 1 + 1) + 1;
		}
		bubbleSort(arr, size_n);

		search1(arr, M, num_to_search, &sum_count1);
		search2(arr, M, num_to_search, &sum_count2);
		search3(arr, M, num_to_search, &sum_count3);
	}


	printf("\n");
	printf("Test for 1000 diffrent arrays");
	printf("\n");
	avg_count1 = avg(&sum_count1);
	avg_count2 = avg(&sum_count2);
	avg_count3 = avg(&sum_count3);

	printf("Average tests for search1 is : %d\n", avg_count1);
	printf("Average tests for search2 is : %d\n", avg_count2);
	printf("Average tests for search3 is : %d\n", avg_count3);


}

//O(n)
int search1(int array[], int size, int search_num, int* count) {

	int i = 0;
	for (i = 0; i < size && (array[i] != 0); i++ && (*count)++)
	{
		if (array[i] == search_num)
			return i;
	}
	return 0;
}

//O(log(m))
int search2(int array[], int size, int search_num, int* count) {

	int zero = 0;
	int low = 0;
	int high = size - 1;
	while (low <= high)
	{
		int div = ((low + high) / 2);

		if (array[div] == search_num)
		{
			return div;
		}
		else if ((array[div] == zero) || (array[div] > search_num))
		{
			high = div - 1;
		}
		else if (array[div] < search_num)
		{
			low = div + 1;
		}
		(*count)++;
	}
	return 0;

}

//O(log(n))
int search3(int array[], int size, int search_num, int* count) {

	int place = 1;
	int zero = 0;
	if (array[0] == search_num)
		return 0;
	//O(log(place))->search 'n' place
	while ((place < size)//for not bigger then array 
		&& (array[place] < search_num)
		&& (array[place] != zero))//to be near size_n
	{
		place = place * 2;
		(*count)++;
	}


	if (place > size)
		place = size;

	int high = place - 1;//the limit is 2^(place)
	int low = place / 2;//the lower is 2^(place-1)

	//O(log(n))
	while (low <= high)
	{
		int div = ((low + high) / 2);

		if (array[div] == search_num)
		{
			return div;
		}
		else if ((array[div] == zero) || (array[div] > search_num))
		{
			high = div - 1;
		}
		else if (array[div] < search_num)
		{
			low = div + 1;
		}
		(*count)++;
	}
	return 0;

}

//O((n^2))
void bubbleSort(int array[], int size_n) {

	int i, j;
	for (i = size_n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tamp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tamp;
			}
		}
	}
}

//print arr
void printArr(int array[]) {

	int j = 0;
	for (int j = 0; j < M; j++)
	{
		printf("%d", array[j]);
		printf(" ");
	}
}

//to calculate averge 
int avg(int* p) {
	
	int sum = (*p) / M;
}
