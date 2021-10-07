// BinaryHeap.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

struct HeapNode {
    int id{-1};
    int priority{-1};
};

class BinaryHeap {
    vector<HeapNode> heap{0};

public:
    BinaryHeap() {
        heap.resize(1);
    }

    void swapNode(int x, int y) {
        auto temp = heap[x];
        heap[x] = heap[y];
        heap[y] = temp;
    }

    void minHeapify(int root) {
        //find smallest among the node and its children
        int left = root * 2;
        int right = root * 2 + 1;
        int smallest = root;
        if (left < heap.size() && heap[left].priority < heap[root].priority) {
            smallest = left;
        }

        if (right < heap.size() && heap[right].priority < heap[right].priority) {
            smallest = right;
        }
        if (smallest != root) {
            swapNode(smallest, root);
            minHeapify(smallest);
        }
    }

    int findNode(int id) {
        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    void update(int id, int priority) {
        int index = findNode(id);
        if (index < 0) {
            cout << "can't find id" << endl;
            return;
        }
        if (priority > heap[index].priority) {
            cout << "new key is greater or equal to the node." << endl;
            return;
        }

        heap[index].priority = priority;
        int parent = getParent(index);
        while (index > 0 && heap[parent].priority > heap[index].priority) {
            swapNode(index, parent);
            index = parent;
            parent = getParent(index);
        }
    }

    int getParent(int index) {
        if (index <= 0) {
            return 0;
        }
        return index / 2;
    }

    void insert(HeapNode task) {
        heap.push_back(task);
        update(task.id, task.priority);
    }

    pair<int, int> getHeightest() {
        if (heap.size() < 1) {
            return make_pair(-1, -1);
        }
        return make_pair(heap[1].id, heap[1].priority);
    }
};

int main()
{
    BinaryHeap heap;
    vector<HeapNode> input{ {1, 10}, {2, 15}, {3, 12}, {4, 5}, {5, 8}, {6, 2}, {7, 11} };

    for(auto& task: input)
        heap.insert(task);
    auto minTask = heap.getHeightest();
    cout << minTask.first << ", p: " << minTask.second << endl;
    heap.update(3, 1);
    minTask = heap.getHeightest();
    cout << minTask.first << ", p: " << minTask.second << endl;
    std::cout << "Hello World!\n";
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
