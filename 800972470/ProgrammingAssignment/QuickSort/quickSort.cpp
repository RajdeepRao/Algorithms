#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int partitionIndex = partition(arr, low, high);


		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

void printArray(int arr[], int size)
{
  std::ofstream myfile;
  int j;
  myfile.open ("QuickSort.txt", ios::out | ios::app);
  for (j=0; j<size;j++)
    myfile <<" "<< arr[j];
  myfile << endl;
  myfile.close();
}

int main()
{
  int n = 0;
  int num;
  int arr1[1000];
  int arr2[1000];
  int arr3[1000];

  ifstream File;
  File.open("random_list.txt");

  while(File >> arr1[n])
  {
      n++;
  }
  int arr_size1 = sizeof(arr1)/sizeof(arr1[0]);
  File.close();
  int start_s=clock();
  quickSort(arr1, 0, arr_size1-1);
  int stop_s=clock();
  cout<<"RandomList: " ;
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  n=0;
  File.open("sorted_list.txt");
  while(File >> arr2[n])
  {
      n++;
  }
  int arr_size2 = sizeof(arr2)/sizeof(arr2[0]);
  File.close();
  start_s=clock();
  quickSort(arr2, 0, arr_size2-1);
  stop_s=clock();
  cout<<"Sortedist: " ;
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  n=0;
  File.open("reverse_list.txt");
  while(File >> arr3[n])
  {
      n++;
  }
  int arr_size3 = sizeof(arr3)/sizeof(arr3[0]);
  File.close();
  start_s=clock();
  quickSort(arr3, 0, arr_size3-1);
  stop_s=clock();
  cout<<"ReverseList: " ;
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  cout << "done\n";


  printArray(arr1, arr_size1);
  printArray(arr2, arr_size2);
  printArray(arr3, arr_size3);

  return 0;

}
