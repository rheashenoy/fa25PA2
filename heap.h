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
        return min; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        int i = pos;
        if (weightArr[i] < weightArr[(i-1)/2]) {
            int tmp = weightArr[i];
            weightArr[i] = weightArr[(i-1)/2];
            weightArr[(i-1)/2] = tmp;
            upheap(i, weightArr);
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif