//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx;
        size++;
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        int min = data[0];
        data[0] = data[size - 1];
        downheap(0, weightArr);
        return min;
    }

    void upheap(int pos, int weightArr[]) {
        int i = pos;
        while (i > 0) {
            int j = data[pos];
            int parent = (i -1) / 2;
            if (weightArr[j] > weightArr[data[parent]]) break;
            else {
                int tmp = data[i];
                data[i] = data[parent];
                data[parent] = tmp;
            }
            i = parent;
        }

    }

    void downheap(int pos, int weightArr[]) {
        int i = pos;
        while (i <= size) {
            int j = data[pos];
            int leftChild = (2 * i) + 1;
            int rightChild = (2 * i) + 2;
            if (weightArr[j] < weightArr[data[leftChild]] && weightArr[j] < weightArr[data[rightChild]]) break;
            else if (weightArr[j] > weightArr[data[leftChild]]) {
                int tmp = data[i];
                data[i] = data[leftChild];
                data[leftChild] = tmp;
                i = leftChild;
            }
            else {
                int tmp = data[i];
                data[i] = data[rightChild];
                data[rightChild] = tmp;
                i = rightChild;
            }
        }

    }
};

#endif