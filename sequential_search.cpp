#include <iostream> 

using namespace std;
int main()
{
    int arr[10];
    int no_of_elements, key;
    bool found = false;
    cout << "Enter the number of element: ";
    cin >> no_of_elements;
    for (int i = 0; i < no_of_elements; i++) {
        cout << "arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Enter the value to search: ";
    cin >> key;
    for (int i = 0; i < no_of_elements; i++) {
        if (key == arr[i]) {
            found = true;
            cout << "The value is found at index arr[" << i << "]";
        }
    }
    if (!found) {
        cout << "Key not found!";
    }
    return 0;
}