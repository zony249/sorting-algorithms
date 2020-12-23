#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>


using namespace std;


///////////////
//           //
// Utilities //
//           //
///////////////

// swaps two values
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Prints the vector
void print_vec(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}

	cout << endl;
}

// Scrambles the vector
void scramble(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int rand_index = i+rand()%(vec.size() - i);
		swap(vec[i], vec[rand_index]);
	}
}




////////////////////////
//                    //
// Sorting Algorithms //
//                    //
////////////////////////


// Bubblesort compares every pair of values and swaps them if they are
// not in order. Every major iteration causes the largest value to 
// "bubble" to the end of the list.
// Algorithmic Complexity: O(n^2)
vector<int> bubblesort(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 1; j < vec.size()-i; j++)
		{
			if (vec[j] < vec[j-1])
			{
				swap(vec[j], vec[j-1]);
			}
		}
	}

	return vec;
}

// Selection sort keeps track of a sorted portion of the vector
// as well as an unsorted portion. Sorted is left of index i, and 
// unsorted is right of index i. 
// Selection sort loops through the unsorted portion and
// finds the smallest value's index, and swaps the value into the end of 
// the sorted list.
// Algorithmic Complexity: O(n^2)
vector<int> selectionsort(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		int smallest = i;
		for (int j = i; j < vec.size(); j++)
		{
			if (vec[j] < vec[smallest])
			{
				smallest = j;
			}
		}

		swap(vec[i], vec[smallest]);
	}
	return vec;
}


// Insertion sort keeps track of a sorted portion and an unsorted portion
// of the vector. Everything on the left of index i is sorted, and on the
// right is unsorted.
// Values in the unsorted section are moved into place in the sorted section.
// Algorithmic Complexity: O(n^2)
vector<int> insertionsort(vector<int> vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		int val = vec[i];
		for (int j = i-1; j >= 0; j -= 1)
		{
			if (val < vec[j]) {swap(vec[j], vec[j+1]);}
			else {break;}
		}
	}
	return vec;

}


// Partition function that is used by quicksort.
void partition(vector<int>& vec, int low, int high)
{
	int pivot = vec[high];
	if (low < high)
	{
		int j = low;
		for (int i = low; i < high; i++)
		{
			if (vec[i] < pivot)
			{
				swap(vec[i], vec[j]);
				j++;
			}

		}

		swap(vec[high], vec[j]);
	
		partition(vec, low, j-1);
		partition(vec, j+1, high);
	}
}

// Quicksort performs a rough sort by choosing a pivot value,
// then moving all values less than the pivot to the left, and 
// all values greater than the pivot to the right. Partition then
// recurses and does the same on the left and right portions until 
// the vector is sorted.
// Algorithmic complexity:
// 	Rough sort: O(n)
// 	Depth of Recursion: O(log n)
// 	Total: O(n log n)
vector<int> quicksort(vector<int> vec)
{	
	int low = 0;
	int high = vec.size() - 1;
	partition(vec, low, high);
	return vec;
}


int main()
{
	vector<int> vec1 = {3, 4, 7, 6, 8, 9, 2, 1, 0, 5};
	vector<int> vec2 = {1, 2, 4, 4, 4, 3, 5, 7, 5, 5, 4, 4, 7, 7, 4, 5, 3, 9, 0};
	
	//creates an unsorted vector vec3
	vector<int> vec3 = {};
	for (int i = 0; i < 100000; i++)
	{
		vec3.push_back(i);
	}
	scramble(vec3);
	
	// print_vec(vec3);
	

	// Clock Start. Run your algorithm in between 
	// the start and end sections to time your algorithm
	std::chrono::steady_clock::time_point begin_time = chrono::steady_clock::now();
	

	vector<int> sorted = quicksort(vec2);
	
	
	// Clock End.
	std::chrono::steady_clock::time_point end_time = chrono::steady_clock::now();

	print_vec(sorted);

	cout << "Time taken: " << chrono::duration_cast<chrono::nanoseconds> (end_time - begin_time).count() << " ns" << endl;

	return 0;
}
