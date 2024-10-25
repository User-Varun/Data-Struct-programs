#include <iostream>
using namespace std;

int main() {
   int arr[1000];
   int n;
   
  cout<<"enter no. of elements you wish to enter: ";
  cin>> n;
   
  for(int i = 0; i < n; i++){
      cout<<"Enter the element at index "<<i<<": ";
      cin>>arr[i];
  }
  

    cout<<endl;
    cout<<"before: ";
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    
  }
  cout<<endl;
  
//  decreasing the n by 1 , effectively deleting the last element from the array
   n = n - 1;
  
    cout<<"Performing deletion at end..."<<endl;
    cout<<"after: ";
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    
  }
  cout<<endl;

    return 0;
}