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
        // TODO: insert index at end of heap, restore order using upheap()
        if (size == 0) {
            data[0] = 1;
        } else {
            data[size] = idx;
            if (weightArr[data[size]] < weightArr[0]) {
                upheap(data[size-1], weightArr);
            }
        }
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        pos = size-1;
        int posd = data[pos];
        int parent = (pos-1) / 2;
        while (pos > 0 && data[pos] < data[parent]) {
            data[pos] = data[parent];
            data[parent] = posd;
        }
    }
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};
#endif