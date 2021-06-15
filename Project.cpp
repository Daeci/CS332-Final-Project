#include <iostream>
#include <chrono>
#include "Project.h"

void merge(std::vector<int> *array, int left, int middle, int right) {
    int i = left, index = left, j = middle + 1;
    std::vector<int> temp(array->size());

    while (i <= middle && j <= right) {
        if (array->at(i) < array->at(j)) {
            temp[index] = array->at(i);
            index++;
            i++;
        }
        else {
            temp[index] = array->at(j);
            index++;
            j++;
        }
    }

    while (i <= middle) {
        temp[index] = array->at(i);
        index++;
        i++;
    }

    while (j <= right) {
        temp[index] = array->at(j);
        index++;
        j++;
    }

    for (i = left; i < index; i++) {
        array->at(i) = temp[i];
    }
}

void mergeSort(std::vector<int> *array, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

void display(std::vector<int> array) {
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Array before sorting: ";
    display(nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(&nums, 0, nums.size() - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "Array after sorting: ";
    display(nums);
    std::cout << "Time taken to sort: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " microseconds" << std::endl;
}