#include <iostream>
using namespace std;

int main() {
   int arr[1000];
   int n;
   int position;
   
  cout<<"enter no. of elements you wish to enter: ";
  cin>> n;
   
  for(int i = 0; i < n; i++){
      cout<<"Enter the element at index "<<i<<": ";
      cin>>arr[i];
  }
  
  
  cout<<"Enter the position of element you wish to delete: ";
  cin >> position;
  
  int index = position-1; // used formula for converting position to index
  
  if(index < 0 || index > n-1){
      cout<<"invalid position.."<<endl;
      cout<<"Exited from program.";
      return 0;
  }
  
    cout<<endl;
    cout<<"before: ";
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    
  }
  
  for(int i = index;  i <= n-1; i++ ){
      arr[i] = arr[i+1];
  }
  n--;
  
    cout<<endl;
    cout<<"after: ";
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    
  }
  cout<<endl;

    return 0;
}