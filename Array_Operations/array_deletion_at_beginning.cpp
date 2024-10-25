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
  
 
  int index = 0; // array index
  
    cout<<endl;
    cout<<"before: ";
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    
  }
  cout<<endl;
  
  for(int i = index;  i <= n-1; i++ ){
      arr[i] = arr[i+1];
  }
  n--;
  
    cout<<"Performing deletion at beginning..."<<endl;
    cout<<"after: ";
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    
  }
  cout<<endl;

    return 0;
}