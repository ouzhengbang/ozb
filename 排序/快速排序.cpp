#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int partition(int array[], size_t arrStart, size_t pivot, size_t arrEnd) {
   int arrayLen = arrEnd - arrStart;

   if ( arrayLen < 1 || pivot < arrStart || pivot >= arrEnd) {
       cout << "Please check your implementation." << endl;
       return -1;
   }
   int pivotValue = array[pivot];
   array[pivot] = array[arrEnd - 1];
   int pivotPos = arrStart;
   int temp;

   for (int i = arrStart; i < arrEnd - 1; ++i)
   {
       if (array[i] < pivotValue) {
          temp = array[pivotPos];
          array[pivotPos] = array[i];
          array[i] = temp;
          ++pivotPos;
       }
   }
   array[arrEnd - 1] = array[pivotPos];
   array[pivotPos] = pivotValue;

   return pivotPos;
}
bool quickSort(int array[], size_t arrStart, size_t arrEnd) {   // 开始默认基准为 arrStart
    int arrLen = arrEnd - arrStart;
    if (arrLen < 0) {
        cout << "Please check your input." << endl;          //如果数组长度小于0为false
        return false;
    }

    if (arrLen == 0 || arrLen == 1) {
        return true;
    } 

    srand(array[array[arrStart] + arrLen + array[arrEnd - 1]]);    

    int pivot = arrStart + floor(((arrLen - 1) + (size_t)rand()) % (arrLen - 1));  

    int pivotPos = partition(array, arrStart, pivot, arrEnd);  

    quickSort(array, arrStart, pivotPos);
    quickSort(array, pivotPos+1, arrEnd);

    return true;
}

void printArray(int array[], int arrLen) {
    for (int i = 0; i < arrLen; ++i) {
        cout << array[i] << " ";                 //输出数组
    }
    cout << endl;
}

int main(){
    int array0[] = {};
    int arrayLen = sizeof(array0)/sizeof(int);

    printArray(array0, arrayLen);
    quickSort(array0, 0, arrayLen);
    printArray(array0, arrayLen);

    cout << "=========================================" << endl;

    int array1[] = {1};
    arrayLen = sizeof(array1)/sizeof(int);

    printArray(array1, arrayLen);
    quickSort(array1, 0, arrayLen);
    printArray(array1, arrayLen);

    cout << "=========================================" << endl;

    int array2[] = {2, 1};
    arrayLen = sizeof(array2)/sizeof(int);

    printArray(array2, arrayLen);
    quickSort(array2, 0, arrayLen);
    printArray(array2, arrayLen);

    cout << "=========================================" << endl;

    int array3[] = {1, 5, 3};
    arrayLen = sizeof(array3)/sizeof(int);

    printArray(array3, arrayLen);
    quickSort(array3, 0, arrayLen);
    printArray(array3, arrayLen);


    cout << "=========================================" << endl;

    int array4[] = {9, 12, 8, 7};
    arrayLen = sizeof(array4)/sizeof(int);

    printArray(array4, arrayLen);
    quickSort(array4, 0, arrayLen);
    printArray(array4, arrayLen);

    cout << "=========================================" << endl;

    int array5[] = {9, 12, 8, 7, 3};
    arrayLen = sizeof(array5)/sizeof(int);

    printArray(array5, arrayLen);
    quickSort(array5, 0, arrayLen);
    printArray(array5, arrayLen);


}
//////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

void display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getStandard(int array[], int i, int j) {
    // 基准数据
    int key = array[i];
    while (i < j) {
                              // 因为默认基准是从左边开始，所以从右边开始比较
                              // 当队尾的元素大于等于基准数据 时,就一直向前挪动 j 指针
        while (i < j && array[j] >= key) {
            j--;
        }
        // 当找到比 array[i] 小的时，就把后面的值 array[j] 赋给它
        if (i < j) {
            array[i] = array[j];
        }
        // 当队首元素小于等于基准数据 时,就一直向后挪动 i 指针
        while (i < j && array[i] <= key) {
            i++;
        }
        // 当找到比 array[j] 大的时，就把前面的值 array[i] 赋给它
        if (i < j) {
            array[j] = array[i];
        }
    }
    // 跳出循环时 i 和 j 相等,此时的 i 或 j 就是 key 的正确索引位置
    // 把基准数据赋给正确位置
    array[i] = key;
    return i;
}

void QuickSort(int array[], int low, int high) {
    // 开始默认基准为 low
    if (low < high) {
        // 分段位置下标
        int standard = getStandard(array, low, high);
        // 递归调用排序
        // 左边排序
        QuickSort(array, low, standard - 1);
        // 右边排序
        QuickSort(array, standard + 1, high);
    }
}

// 合并到一起快速排序
// void QuickSort(int array[], int low, int high) {
//     if (low < high) {
//         int i   = low;
//         int j   = high;
//         int key = array[i];
//         while (i < j) {
//             while (i < j && array[j] >= key) {
//                 j--;
//             }
//             if (i < j) {
//                 array[i] = array[j];
//             }
//             while (i < j && array[i] <= key) {
//                 i++;
//             }
//             if (i < j) {
//                 array[j] = array[i];
//             }
//         }
//         array[i] = key;
//         QuickSort(array, low, i - 1);
//         QuickSort(array, i + 1, high);
//     }
// }

int main() {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49, 10};
    int size    = sizeof(array) / sizeof(int);

    // 打印数据
    printf("%d \n", size);
    QuickSort(array, 0, size - 1);
    display(array, size);

    // int size      = 20;
    // int array[20] = {0};                 // 数组初始化
    // for (int i = 0; i < 10; i++) {       // 数组个数
    //     for (int j = 0; j < size; j++) { // 数组大小
    //         array[j] = rand() % 1000;    // 随机生成数大小 0~999
    //     }
    //     printf("原来的数组：");
    //     display(array, size);
    //     QuickSort(array, 0, size - 1);
    //     printf("排序后数组：");
    //     display(array, size);
    //     printf("\n");
    // }

    return 0;
}
