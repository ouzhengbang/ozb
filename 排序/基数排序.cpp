#include <iostream>
#include <math.h>

using namespace std;

bool coutingSort(int array[], size_t arrLen) {
    if (arrLen < 2) {
        return true;
    }

                                              //求最大值和最小值
    int max = array[0];
    int min = array[0];

    for (size_t i = 1; i < arrLen; ++i)
    {
        if (min > array[i]) {
            min = array[i];
        }
        else if (max < array[i]) {
            max = array[i];
        }
    }

                                                            // 创建桶
    int *countingBuckets = new int[max - min + 1]();

                                                             // 计数数组中值的数量
    for (size_t j = 0; j < arrLen; ++j)
    {
        ++countingBuckets[array[j] - min];
    }

                                                          // 累积桶数以查找数组中值的最后有序位置
    for (size_t k = 1; k < (max - min + 1); ++k)
    {
        countingBuckets[k] += countingBuckets[k-1];
    }

                                                         //以相反的顺序遍历数组
    int *tempArray = new int[arrLen]();
    for (int l = arrLen - 1; l >= 0; --l)
    {
        tempArray[--countingBuckets[array[l] - min]] = array[l];
    }

    for (size_t m = 0; m < arrLen; ++m)
    {
        array[m] = tempArray[m];
    }

    delete [] countingBuckets;             //删除桶
    delete [] tempArray;                     //删除数组

    
    return true;
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {             //输出数组
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);
    coutingSort(array0, arrayLen);
    printArray(array0, arrayLen);

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    coutingSort(array1, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    coutingSort(array2, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 3, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    coutingSort(array3, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 9, 12, 12};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    coutingSort(array4, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 3, 3, 9, 5};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    coutingSort(array5, arrayLen);
    printArray(array5, arrayLen);


     cout << "=========================================" << endl;

    int array6[] = {9, 3, 3, 9, 5,5, 10, 12, 12, 14, 16, 16};
    arrayLen = sizeof(array6)/sizeof(int);

    printArray(array6, arrayLen);
    coutingSort(array6, arrayLen);
    printArray(array6, arrayLen);


}
