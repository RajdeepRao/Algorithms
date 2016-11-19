#include<iostream>
#include<fstream>
#include<string>
#include <ctime>
using namespace std;

void insertion_sort(int arr[], int length);
void print_array(int array[],int size);

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
    File.close();
    int start_s=clock();
    insertion_sort(arr1,n);
    int stop_s=clock();
    cout<<"RandomList: " ;
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    n=0;
    File.open("sorted_list.txt");
    while(File >> arr2[n])
    {
        n++;
    }
    File.close();
    start_s=clock();
    insertion_sort(arr2,n);
    stop_s=clock();
    cout<<"Sortedist: " ;
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    n=0;
    File.open("reverse_list.txt");
    while(File >> arr3[n])
    {
        n++;
    }
    File.close();
    start_s=clock();
    insertion_sort(arr3,n);
    stop_s=clock();
    cout<<"ReverseList: " ;
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    cout << "done\n";
    return 0;
}

void insertion_sort(int arr[], int length)
{
 int i, j ,tmp;
 for (i = 1; i < length; i++)
 {
   j = i;
   while (j > 0 && arr[j - 1] > arr[j])
   {
     tmp = arr[j];
     arr[j] = arr[j - 1];
     arr[j - 1] = tmp;
     j--;
   }
 }
 print_array(arr,length);
}

void print_array(int array[], int size)
{


  std::ofstream myfile;
  int j;
  myfile.open ("Insertion.txt", ios::out | ios::app);
  for (j=0; j<size;j++)
    myfile <<" "<< array[j];
  myfile << endl;
  myfile.close();
}
