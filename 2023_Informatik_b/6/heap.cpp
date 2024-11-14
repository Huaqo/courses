// g++ ./w6/heap.cpp -o ./bin/heap && ./bin/heap

#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    // Hilfsfunktionen zum Vertauschen von Elementen und zur Berechnung von Eltern- und Kindknotenindizes
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getLeftChildIndex(int index) {
        return (2 * index) + 1;
    }

    int getRightChildIndex(int index) {
        return (2 * index) + 2;
    }

    // Hilfsfunktion zum Wiederherstellen der Heap-Eigenschaft nach oben
    void heapifyUp(int index) {
        if (index == 0)
            return;

        int parentIndex = getParentIndex(index);
        if (heap[parentIndex] < heap[index]) {
            swap(heap[parentIndex], heap[index]);
            heapifyUp(parentIndex);
        }
    }

    // Hilfsfunktion zum Wiederherstellen der Heap-Eigenschaft nach unten
    void heapifyDown(int index) {
        int largest = index;
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);

        if (leftChildIndex < heap.size() && heap[leftChildIndex] > heap[largest])
            largest = leftChildIndex;

        if (rightChildIndex < heap.size() && heap[rightChildIndex] > heap[largest])
            largest = rightChildIndex;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Einfügen eines Elements in den Heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Entfernen des Maximums aus dem Heap
    int removeMax() {
        if (heap.empty())
            throw std::out_of_range("Heap is empty!");

        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    // Zugriff auf das Maximum im Heap
    int getMax() {
        return heap[0];
    }

    // Prüfen, ob der Heap leer ist
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    MaxHeap heap;

    // Beispielverwendung des Heaps
    heap.insert(10);
    heap.insert(7);
    heap.insert(15);
    heap.insert(30);
    heap.insert(20);

    std::cout << "Max: " << heap.getMax() << std::endl;

    heap.removeMax();

    std::cout << "Max after removal: " << heap.getMax() << std::endl;

    return 0;
}