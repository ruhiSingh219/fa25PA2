//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdexcept>
using namespace std;
//ADD OVERALL COMMENTS**************
struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        //throw error if push onto full
        if (size >= 64) {
            throw runtime_error("Overflow");
        }
        //add to end
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // throw error if pop from empty.
        if (size == 0) {
            throw runtime_error("Underflow");
        }
        int minInx = data[0];
        //move last to root
        data[0] = data[size-1];
        size--;
        if (size > 0) {
            downheap(0, weightArr);
        }
        //return popped val
        return minInx;
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            //parent index
            int parent = (pos-1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                int tmp = data[pos];
                data[pos] = data[parent];
                data[parent] = tmp;
                pos = parent;
            } else {
                //break if parent weight is less than child's
                break;
            }
        }
    }
    void downheap(int pos, int weightArr[]) {
         while (true) {
             int lc = data[(2*pos) + 1];
             int rc = data[(2*pos) + 2];
             //break if no children
             if (lc >= size) {
                 break;
             }

             int smallest = lc;
             if (rc < size && weightArr[data[rc]] < weightArr[data[lc]]) {
                 smallest = rc;
             }
             //break if parent is already less than smallest child
             if (weightArr[data[pos]] <= weightArr[data[smallest]]) {
                 break;
             }
             int t = data[pos];
             data[pos] = data[smallest];
             data[smallest] = t;
             //continue from child's postion
             pos = smallest;
         }
    }
};
#endif