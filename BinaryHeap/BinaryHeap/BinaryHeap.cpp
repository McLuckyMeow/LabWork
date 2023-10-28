#include <iostream>
#include <vector>

class MaxHeap {
    std::vector<int> heap;  // Вектор для хранения элементов кучи

public:
    MaxHeap() {}

    // Добавление элемента в кучу
    void insert(int value);

    // Извлечение максимального элемента
    int extractMax();

    // Вывод элементов кучи в виде массива
    void display();

private:
    // Поддержание свойства кучи после добавления элемента
    void heapifyUp(int index);

    // Поддержание свойства кучи после извлечения максимального элемента
    void heapifyDown(int index);
};

void MaxHeap::insert(int value) {
    heap.push_back(value);
    int currentIndex = heap.size() - 1;
    heapifyUp(currentIndex);
}

int MaxHeap::extractMax() {
    if (heap.empty()) {
        std::cerr << "Куча пуста. Извлечение не возможно." << std::endl;
        return -1;
    }

    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

    return maxValue;
}

void MaxHeap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parentIndex]) {
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void MaxHeap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::display() {
    for (int value : heap) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {

    setlocale(LC_ALL, "Russian");

    MaxHeap maxHeap;

    for (int i = 0; i < 16; i++) {
        std::cout << "Введите элемент " << i + 1 << ": ";
        int value;
        std::cin >> value;
        maxHeap.insert(value);
    }

    std::cout << "Куча: ";
    maxHeap.display();

    int maxElement = maxHeap.extractMax();
    std::cout << "Извлеченный максимальный элемент: " << maxElement << std::endl;

    std::cout << "Обновленная куча: ";
    maxHeap.display();

    return 0;
}
