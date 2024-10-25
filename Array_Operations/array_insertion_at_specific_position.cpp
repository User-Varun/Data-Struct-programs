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
   
   int element;
   int position;
   
   cout<<"Enter the element to be inserted: ";
   cin >> element;
   
   cout<<"Enter the Postion:  ";
   cin >> position;
   
   int index = position-1;
   
   if(index < 0 || index > n-1){
       cout<<"invalid Postion";
       return 0;
   }
   
   cout<<"before ";
   for(int i = 0; i< n; i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
       
  for(int i = n-1; i >= index; i--){
           arr[i + 1] = arr[i];
       }
       arr[index] = element;
       n++;

    cout<<endl;
   cout<<"after ";
   for(int i = 0; i< n; i++){
       cout<<arr[i]<<" ";
   }

    return 0;
}