#include <iostream>
#include <vector>
using namespace std;
// 5a
class Task
{
public:
 Task(float cost)
 {
 this->cost = cost;
 }
 ~Task() = default;
 float value()
 {
 return this->cost;
 }
private:
 float cost;
 string name;
};
// 5a
class TaskPool
{
public:
 TaskPool() = default;
 TaskPool(vector<Task *> tasks)
 {
 //copy the data passed as parameters
 for (size_t i = 0; i < tasks.size(); i++)
 {
 this->data.push_back(tasks[i]);
 }
 }
 ~TaskPool()
 {
 while (!this->data.empty())
 {
 auto task = this->data.back();
 delete task;
 this->data.pop_back();
 }
 }
 // 5a
 void reheapUp(int position)
 {
 if (position > 0)
 {
 int parent = int((position - 1) / 2);
 if (data[position]->value() > data[parent]->value())
 {
 this->swap(position, parent);
 this->reheapUp(parent);
 }
 }
 }
 // 5a
 void add(Task *task)
 {
 this->data.push_back(task);
 this->reheapUp(this->data.size() - 1);
 }
 void buildHeap(vector<float> costs)
 {
 //(1) copy the data passed as parameters
 for (size_t i = 0; i < costs.size(); i++)
 {
 this->data.push_back(new Task(costs[i]));
 }
 //(2) Build heap
 int walker = 1;
 while (walker < this->data.size())
 {
 this->reheapUp(walker);
 walker += 1;
 }
 }
 void display()
 {
 cout << "Max heap:" << endl;
 cout << "Item: ";
 for (size_t i = 0; i < this->data.size(); i++)
 {
 cout << this->data[i]->value() << " ";
 }
 cout << endl;
 }
 // 5b
 void reheapDown(int position)
 {
 int leftChild = position * 2 + 1;
 int rightChild = position * 2 + 2;
 int lastPosition = data.size() - 1;
 // cout << leftChild << " " << rightChild << " " << lastPosition << endl;
 if (leftChild <= lastPosition)
 {
 int largeChild = 0;
 if (rightChild <= lastPosition &&
 data[rightChild]->value() > data[leftChild]->value())
 {
 largeChild = rightChild;
 }
 else
 {
 largeChild = leftChild;
 }
 if (data[largeChild]->value() > data[position]->value())
 {
 this->swap(largeChild, position);
 this->reheapDown(largeChild);
 }
 }
 }
 // 5b
 Task *next_task()
 {
 Task *res = nullptr;
 if (!data.empty())
 {
 // get root
 res = data[0];
 // move the last node to root then reheap down
 data[0] = data.back();
 data.pop_back();
 this->reheapDown(0);
 }
 return res;
 }
private:
 void swap(int a, int b)
 {
 Task *temp = data[a];
 data[a] = data[b];
 data[b] = temp;
 }
 vector<Task *> data;
};
int main()
{
 TaskPool heap;
 vector<float> data{8, 19, 23, 32, 45, 56, 78};
 heap.buildHeap(data);
 heap.display();
 Task *next = heap.next_task();
 while (next)
 {
 heap.display();
 cout << next->value() << endl;
 delete next;
 next = heap.next_task();
 }
 return 0;
}
