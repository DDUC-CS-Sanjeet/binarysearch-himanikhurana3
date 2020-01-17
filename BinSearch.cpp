#include<iostream>
#include<algorithm>
void sort_array(int arr[],int n);
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
    int mid = 0;
	if(startIndex<=lastIndex)
	{
		mid=(startIndex+lastIndex)/2;
		if(array[mid]==element)
	        return true;
		else if(array[mid]>element)
		    return binarySearchReacursive(array, startIndex, mid-1, element);
		else
		    return binarySearchReacursive(array, mid+1, lastIndex, element);
    }
    return false;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
  int mid = 0;
  while(startIndex<=lastIndex)
  {
    mid = (startIndex+lastIndex)/2;
    if(array[mid] == element)
    {  
        return true;
    } 
    else if(array[mid] < element)
        startIndex = mid+1;
    else if(array[mid] > element)
        lastIndex = mid-1;
  }
  return false;
}

int main()
{
  int size = 0, element = 0;
  bool ans_it= false , ans_rec = false;
  try
  {
      cout<<"Enter the size of Array: ";
      cin>>size;
      if(size<1)
          throw "Invalid !!!";
  }
  catch(const char *str)
  {
    cout<<str;
  }
  int ch=0;
  int *A = new int[size];
  cout<<"\nEnter the elements of the Array \n";
  for(int i=0; i<size; i++)
      cin>>A[i];
  sort(A,A+size);
   cout<<"\nEnter the element to be searched: ";
  cin>>element;
  cout<<"\n \t\t choose ";
  cout<<"\n 1.By Iteration \n 2.By Recursion \n ";
  cin>>ch;
  switch(ch)
  {
  	case 1: ans_it = binarySearchIterative(A, 0, size-1, element); break;
  	case 2: ans_rec = binarySearchReacursive(A, 0, size-1, element); break;
  	default: cout<<" \n wrong choice";
  }
  if(ch==1)
    {
	  if(ans_it == true)
      cout<<element<<" is found in the given Array by Iterative"<<endl;
  else
      cout<<element<<" is not found in the given Array by Iterative"<<endl;
 }
  if(ch==2)

  {
  
  if(ans_rec)
      cout<<element<<" is found in the given Array by Recursion"<<endl;
  else
      cout<<element<<" is not found in the given Array by Recursive"<<endl;
  }
  delete[] A;
  return 0;
}
