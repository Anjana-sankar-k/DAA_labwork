#include <iostream>
using namespace std;

void heapify(int arr[], int size, int index){
            int largest = index;
            int left = 2*index +1;
            int right = 2*index +2;
            
            if(left < size && arr[left] > arr[largest]){
                largest = left;
            }
            
            if(right <size && arr[right] > arr[largest]){
                largest = right;
            }
            if(largest != index){
                int temp = arr[largest];
                arr[largest] = arr[index];
                arr[index] = temp;
                 
                 heapify(arr, size, largest);
            }
            
            }
         
void heapsort(int arr[], int size){
          for(int i = size / 2-1; i >=0; i--){
          heapify(arr, size, i);
          }
          
          for(int i = size - 1; i >0; i--){
          int temp = arr[0];
          arr[0] = arr[i];
          arr[i] = temp;
          heapify(arr, i, 0);
}
}

int main(){
	int n;
	cout<<"Enter the size of the array: "<<endl;
	cin>>n;
	int arr[n];

	cout<<"Enter the elements of the array: "<<endl;
	for(int i = 0; i < n; i++){
	     cin>>arr[i];
	}

	cout<<"given array: "<<endl;
	for(int i = 0; i < n; i++){
	cout<<arr[i]<<" ";
	}
	cout<<endl;

	heapsort(arr, n);

	cout<<"sorted array: "<<endl;
	for(int i = 0;i < n;i++){
	   cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}                     
        
