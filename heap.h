//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <stdexcept>
using namespace std;
struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    //adds value to last, then calls upheap to ensure minheap structure.
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

    //removes root and replaces it with last element, then calls downheap to ensure minheap structure
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

    //Bubbles up if child is less than root, ensures minheap
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
    //Bubbles down if root is greater than children, ensures minheap.
    void downheap(int pos, int weightArr[]) {
         while (true) {
             int lc = (2*pos) + 1;
             int rc = lc+1;
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
             //continue from child's position
             pos = smallest;
         }
    }
};
#endif