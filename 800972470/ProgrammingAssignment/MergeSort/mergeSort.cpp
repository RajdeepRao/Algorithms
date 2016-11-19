#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int Left[n1], Right[n2];

	for (i = 0; i < n1; i++)
		Left[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		Right[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l+(r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{

  std::ofstream myfile;
  int j;
  myfile.open ("Merge.txt", ios::out | ios::app);
  for (j=0; j<size;j++)
    myfile <<" "<< A[j];
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
  mergeSort(arr1, 0, arr_size1 - 1);
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
  mergeSort(arr2, 0, arr_size2 - 1);
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
  mergeSort(arr3, 0, arr_size3 - 1);
  stop_s=clock();
  cout<<"ReverseList: " ;
  cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

  cout << "done\n";


  printArray(arr1, arr_size1);
  printArray(arr2, arr_size2);
  printArray(arr3, arr_size3);


  return 0;
}
