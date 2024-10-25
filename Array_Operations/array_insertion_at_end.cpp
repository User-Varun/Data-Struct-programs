#include <iostream>
using namespace std;

int main() {
   int arr[1000];
   int n;
   int element; 
   
  cout<<"enter no. of elements you wish to enter: ";
  cin>> n;
   
  for(int i = 0; i < n; i++){
      cout<<"Enter the element at index "<<i<<": ";
      cin>>arr[i];
  }
   
   cout<<"Enter the element to be inserted at End: ";
   cin >> element;
  
  int index = n; // stored n coz array's last element is n-1. we want to insert at the next postion, that is: n;
   
   cout<<endl;
   cout<<"before ";
   for(int i = 0; i< n; i++){
       cout<<arr[i]<<" ";
   }
      
    //   put the element in array at the index(i.e last)
    // increase n by  1
       arr[index] = element;
       n++;


//   output before and after result
    cout<<endl;
   cout<<"after ";
   for(int i = 0; i< n; i++){
       cout<<arr[i]<<" ";
   }

    return 0;
}