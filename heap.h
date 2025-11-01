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
        // Replace root with last element
        int tmp = weightArr[data[size-1]];
        size--;
        weightArr[0] = tmp;
        downheap(data[0], weightArr);
        return 0;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int parent = (pos - 1) / 2;
        int tmp = data[pos];
        while (weightArr[data[pos]] < weightArr[parent]) {
            weightArr[data[pos]] = weightArr[data[parent]];
            weightArr[data[parent]] = weightArr[tmp];
            pos = pos/2;
        }
    }
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int lc = data[(2*pos) + 1];
        int rc = data[(2*pos) + 2];
        int tmp = data[pos];
        while (weightArr[data[pos]] > weightArr[lc] || weightArr[data[pos]] > weightArr[rc]) {
            if (weightArr[lc] < weightArr[rc]) {
                weightArr[pos] = weightArr[lc];
                weightArr[lc] = weightArr[tmp];
            } else {
                weightArr[pos] = weightArr[rc];
                weightArr[rc] = weightArr[tmp];
            }
            pos = pos*2;
        }
    }
};
#endif