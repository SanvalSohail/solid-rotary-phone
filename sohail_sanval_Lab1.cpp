#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <iostream>

void Merge(int a[], int low, int high, int mid);
void mergeSort(int a[], int low, int high);
void timeEnd(clock_t time,int size,bool selectOrmerge);
void selectionSort(int array[], int size);
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

int main()
{
  srand(time(NULL));
  int arraySelect1[2000],arrayMerge1[20000];
  int arraySelect2[5000],arrayMerge2[50000];
  int arraySelect3[6000],arrayMerge3[60000];
  int arraySelect4[7000],arrayMerge4[70000];
  int arraySelect5[8000],arrayMerge5[80000];
  int arraySelect6[10000],arrayMerge6[100000];
  int n1 = array_size(arraySelect1);
  int n2 = array_size(arraySelect2);
  int n3 = array_size(arraySelect3);
  int n4 = array_size(arraySelect4);
  int n5 = array_size(arraySelect5);
  int n6 = array_size(arraySelect6);
  int n7 = array_size(arrayMerge1);
  int n8 = array_size(arrayMerge2);
  int n9 = array_size(arrayMerge3);
  int n10 = array_size(arrayMerge4);
  int n11 = array_size(arrayMerge5);
  int n12 = array_size(arrayMerge6);
  //----------------------------------Populate Arrays----------------------------------------------//
    for (int i = 0; i < n12; i++)
  {
    arrayMerge6[i] = rand() % (4*n12) + 1;
  }
    for (int i = 0; i < n11; i++)
  {
    arrayMerge5[i] = rand() % (4*n11) + 1;
  }
    for (int i = 0; i < n10; i++)
  {
    arrayMerge4[i] = rand() % (4*n10) + 1;
  }
    for (int i = 0; i < n9; i++)
  {
    arrayMerge3[i] = rand() % (4*n9) + 1;
  }
    for (int i = 0; i < n8; i++)
  {
    arrayMerge2[i] = rand() % (4*n8) + 1;
  }
  for (int i = 0; i < n7; i++)
  {
    arrayMerge1[i] = rand() % (4*n7) + 1;
  }
  for(int i = 0; i < n6;i++)
  {
    arraySelect6[i] = rand() % (4*n6) + 1;
  }  
    for(int i = 0; i < n5;i++)
  {
    arraySelect5[i] = rand() % (4*n5) + 1;
  }  
  for(int i = 0; i < n4;i++)
  {
    arraySelect4[i] = rand() % (4*n4) + 1;
  }  
  for(int i = 0; i < n3;i++)
  {
    arraySelect3[i] = rand() % (4*n3) + 1;
  }  
  for(int i = 0; i < n2;i++)
  {
    arraySelect2[i] = rand() % (4*n2) + 1;
  }  
  for(int i = 0; i < n1;i++)
  {
    arraySelect1[i] = rand() % (4*n1) + 1;
  }  
  //----------------------------------Populate Arrays----------------------------------------------//

  //----------------------------------Selection Sort Times----------------------------------------//
    clock_t time = clock();
    selectionSort(arraySelect6,n6);
    timeEnd(time,n6,true);

    clock_t time2 = clock();
    selectionSort(arraySelect5,n5);
    timeEnd(time2,n5,true);

    clock_t time3 = clock();
    selectionSort(arraySelect3,n4);
    timeEnd(time3,n3,true);

    clock_t time4 = clock();
    selectionSort(arraySelect4,n3);
    timeEnd(time4,n3,true);

    clock_t time5 = clock();
    selectionSort(arraySelect2,n2);
    timeEnd(time5,n2,true);

    clock_t time6 = clock();
    selectionSort(arraySelect1,n1);
    timeEnd(time6,n1,true);
  //----------------------------------Selection Sort Times----------------------------------------//

  //----------------------------------Merge Sort Times--------------------------------------------//
    clock_t time7 = clock();
    mergeSort(arrayMerge6,0,n12-1);
    timeEnd(time7,n12,false);

        clock_t time8 = clock();
    mergeSort(arrayMerge5,0,n11-1);
    timeEnd(time8,n11,false);

        clock_t time9 = clock();
    mergeSort(arrayMerge4,0,n10-1);
    timeEnd(time9,n10,false);

        clock_t time10 = clock();
    mergeSort(arrayMerge3,0,n9-1);
    timeEnd(time10,n9,false);

        clock_t time11 = clock();
    mergeSort(arrayMerge2,0,n8-1);
    timeEnd(time11,n8,false);

        clock_t time12 = clock();
    mergeSort(arrayMerge1,0,n7-1);
    timeEnd(time12,n7,false);

  //----------------------------------Merge Sort Times--------------------------------------------//
  //----------Merge Test-------------//
    /*mergeSort(arrayMerge1,0,n1-1);
    for(int i = 0; i < n1; i++)
    {
      std::cout<<arrayMerge1[i] << " ";
    }*/
  //----------Merge Test-------------//
  
}
//--------------------WORKS----------------------------------
void selectionSort(int array[], int size)
{
  int temp;
  for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if(array[i]>array[j])
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}

}
//--------------------WORKS----------------------------------

//--------------------WORKS----------------------------------
void Merge(int a[], int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
// A function to split array into two parts.
void mergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		mergeSort(a, low, mid);
		mergeSort(a, mid+1, high);
 
		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
//--------------------WORKS----------------------------------

void timeEnd(clock_t time,int size,bool selectOrmerge)
{
  time = clock() - time;
  int ms = double(time) / CLOCKS_PER_SEC * 1000;
  if (selectOrmerge)
  std::cout << "Elapsed Time: " << ms << "ms" << " for selection sort of size: " << size << "\n";
  if (!selectOrmerge)
  std::cout << "Elapsed Time: " << ms << "ms" << " for merge sort of size: " << size << "\n";
}


  
