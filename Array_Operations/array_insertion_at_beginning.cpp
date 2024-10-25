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
   
   cout<<"Enter the element to be inserted at beginning: ";
   cin >> element;
  
  int index = 0; // stored 0 coz array index start with 0;
   
   cout<<endl;
   cout<<"before ";
   for(int i = 0; i< n; i++){
       cout<<arr[i]<<" ";
   }
       
  for(int i = n-1; i >= index; i--){
           arr[i + 1] = arr[i];
       }
       arr[0] = element;
       n++;

    cout<<endl;
   cout<<"after ";
   for(int i = 0; i< n; i++){
       cout<<arr[i]<<" ";
   }

    return 0;
}