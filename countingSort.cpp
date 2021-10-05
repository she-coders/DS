/*
    Contributed by: Mohammad Haziq Khan
    GitHub: haaaziq
*/

#include<iostream>
using namespace std;

// Function to do Counting Sort
void countingSort(int arr[], int n, int digitPlace){
    int sortedData[n];
    int count[10] = {0};    //array for storing count of int from 0-9 in current pass
    
    for(int i=0; i<n; i++){
        //incrementing the count of int, and storing it at its own index.
        count[(arr[i]/digitPlace)%10]++;
    }

    // cout << "Counts :" << endl;
    // for(int i=0; i<10; i++){
    //     cout << i << ": " << count[i] << endl;
    // }

    // now count will contain index posn of digit for sorted array
    for(int i=1; i<10; i++){ //first(0) will be same
        count[i] = count[i] + count[i-1];    
    }

    // cout << "Final Indices: " <<endl;
    // for(int i=0; i<10; i++){
    //     cout << i << ": " << count[i] << endl;
    // }

    //Creating Sorted Array.... starting iteration from the rightmost element of numbers
    for(int i=n-1; i>=0;i--){
        sortedData[--count[arr[i]]] = arr[i];
    }

    cout << "SORTED DATA: ";
    for(int i=0; i<n; i++){
        cout << sortedData[i] << " ";
    }

}

int main(){
    cout << "\nCOUNTING SORT:" << endl;
    cout << "===============" << endl;

    int size;
    cout << "Enter size of data: ";
    cin >> size;

    int numbers[size];

    cout << "Numbers: ";
    for(int i=0; i<size; i++){
        cin >> numbers[i];
    }
    cout << "\n";
    
    countingSort(numbers, size, 1);
}