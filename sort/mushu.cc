#include <iostream>
#include "sort.h"
using namespace std;

int main() {

    int array[] = {73, 62};

    oddevensort(array, 2);

    for (int i = 0; i < 2; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}