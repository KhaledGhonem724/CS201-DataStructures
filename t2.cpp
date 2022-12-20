#include <string>
#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
struct dnode {
    int data;
    dnode* next;
    dnode* pre;
};
class Array {
    int size;
    int length;
    int* arr;
public:
    Array(int a) {
        if (a <= 0) {
            exit(1);
        }
        else {
            size = a;
            length = 0;
            arr = new int[size];
        }
    }
    bool isempty() {
        return length == 0;
    }
    bool isfull() {
        return length >= size;
    }
    string getlength() {
        return to_string(length);
    }
    string getsize() {
        return to_string(size);
    }
    string Enlarge(int added_size) {
        int* temp = new int[size + added_size];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        arr = temp;
        size = size + added_size;
        return "enlarged ! ";
    }
    string Sort() {
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }
        return "sorted ! ";
    }
    string Display() {
        string s = "[ ";
        for (int i = 0; i < length; i++) {
            s = s + to_string(arr[i]) + " ";
        }
        s = s + "]";
        return s;
    }
    string insert(int newitem) {
        if (isfull())
        {
            return "Array is Full\n";
        }
        else {
            arr[length] = newitem;
            length++;
            return "inserted \n";
        }
    }
    string DeletionByIndex(int index) {
        if (isempty()) {
            return "already empty \n";
        }
        if (index >= 0) {
            for (int i = index; i < length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            length--;
            return "deleted \n";
        }
        else {
            return "out of range\n";
        }
    }
    string DeletionByValue(int val) {
        if (isempty()) {
            return "already empty \n";
        }
        for (int i = 0; i < length; i++) {
            if (arr[i] == val)
            {
                for (int j = i; j < length - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                length--;
                return "deleted \n";
            }
        }
        return "not found\n";

    }
};
class Stack {
private:
    node* top;
public:
    Stack() {
        top = NULL;
    }
    string Push(int val) {
        node* temp = new node();
        temp->data = val;
        top == NULL ? temp->next = NULL : temp->next = top;
        top = temp;
        return "pushed " + to_string(val) + " done ! \n";
    }
    string Pop() {
        if (IsEmpyt()) {
            return "Stack empty before Pop\n";
        }
        node* temp = top;
        top = top->next;
        free(temp);
        return "Pop done !\n";

    }
    string Peek() {
        if (IsEmpyt()) {
            return "Stack empty before Peek\n";
            exit(1);
        }
        return "top= " + to_string(top->data) + "\n";
    }
    bool IsEmpyt() {
        return top == NULL;
    }
    string Display() {
        if (IsEmpyt())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = top;
        while (i->next != NULL) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n";
        return s;
    }
};
class Queue {
private:
    node* front;
    node* rear;
public:
    Queue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    string enqueue(int val) {
        node* temp = new node();
        temp->data = val;
        temp->next = NULL;
        if (IsEmpty()) {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        rear->next = temp;
        rear = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string dequeue() {
        if (IsEmpty())
        {
            return "Queue empty before dequeue\n";
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        node* temp = front;
        front = front->next;
        free(temp);
        return "dequeue done !\n";
    }
    string getfront() {
        if (IsEmpty()) {
            return "Queue empty before getfront\n";
        }
        return "front = " + to_string(front->data) + " \n";
    }
    bool IsEmpty() {
        return front == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = front;
        while (i->next != NULL) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n ";
        return s;
    }
};
class DoubleQueue {
private:
    dnode* front;
    dnode* rear;
public:
    DoubleQueue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    string enqueue_back(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (isEmpty())
        {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        temp->pre = rear;
        rear->next = temp;
        rear = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string enqueue_front(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (isEmpty())
        {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        temp->next = front;
        front->pre = temp;
        front = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string dequeue_front() {
        if (isEmpty())
        {
            return "doubleQueue empty before dequeue\n";
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        dnode* temp = front;
        front = front->next;
        front->pre = NULL;
        free(temp);
        return "dequeue done !\n";
    }
    string dequeue_back() {
        if (isEmpty())
        {
            return "doubleQueue empty before dequeue\n";
        }
        if (front->next == NULL)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        dnode* temp = rear;
        rear = rear->pre;
        rear->next = NULL;
        free(temp);
        return "dequeue done !\n";

    }
    string getFront() {
        if (isEmpty()) {
            return "doubleQueue empty before getfront\n";
        }
        return "front = " + to_string(front->data) + " \n";
    }
    string getRear() {
        if (isEmpty()) {
            return "doubleQueue empty before getRear\n";
        }
        return "rear = " + to_string(rear->data) + " \n";
    }
    bool isEmpty() {
        return front == NULL;
    }
    string display() {
        if (isEmpty()) {
            return "[ ]\n";
        }
        dnode* i = front;
        string s = "[ ";
        while (i->next != NULL) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n ";
        return s;
    }
};
class CircularQueue {
private:
    node* front;
    node* rear;
public:
    CircularQueue() {
        front = NULL;// like head
        rear = NULL;// like tail
    }
    string enqueue(int val) {
        node* temp = new node();
        temp->data = val;
        temp->next = front;
        if (IsEmpty()) {
            front = rear = temp;
            return "enqueued " + to_string(val) + " done !\n";
        }
        rear->next = temp;
        rear = temp;
        return "enqueued " + to_string(val) + " done !\n";

    }
    string dequeue() {
        if (IsEmpty())
        {
            return "circularQueue empty before dequeue\n";
        }
        if (front->next == front)
        {
            front = rear = NULL;
            return "dequeue done !\n";
        }
        node* temp = front;
        rear->next = front->next;
        front = front->next;
        free(temp);
        return "dequeue done !\n";

    }
    string getfront() {
        if (IsEmpty()) {
            return "circularQueue empty before getfront\n";
        }
        return "front = " + to_string(front->data) + " \n";
    }
    bool IsEmpty() {
        return front == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = front;
        while (i->next != front) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + to_string(i->data) + " ]\n";
        return s;
    }
    string circural_display(int elements) {
        if (IsEmpty())
        {
            return "[ ]\n";
        }
        string s = "[ ";
        node* i = front;
        while (elements--) {
            s = s + to_string(i->data) + " ";
            i = i->next;
        }
        s = s + " ]\n";
        return s;
    }
};
class LinkedList {
private:
    node* head, * tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    string insert_first(int value)
    {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty())
        {
            temp->next = NULL;
            head = tail = temp;
            return "insert done !\n";
        }
        temp->next = head;
        head = temp;
        return "insert done !\n";

    }
    string insert_last(int value) {
        node* temp = new node;
        temp->data = value;
        temp->next = NULL;
        if (IsEmpty())
        {
            head = temp;
            tail = temp;
            return "insert done !\n";
        }
        tail->next = temp;
        tail = temp;
        return "insert done !\n";
    }
    string delete_first() {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        node* temp = new node;
        temp = head;
        head = head->next;
        delete temp;
        return "deletion done !\n";

    }
    string delete_last() {
        if (IsEmpty())
        {
            return "already empty !";
        }
        node* current = new node;
        node* prev = new node;
        current = head;
        while (current != tail)
        {
            prev = current;
            current = current->next;
        }
        tail = prev;
        prev->next = NULL;
        free(current);
        return "deletion done !\n";

    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        node* temp = new node;
        node* i = new node;
        i = head;
        if (i->next == NULL && i->data == value)
        {
            temp = head;
            tail = head = NULL;
            free(temp);
            return "deletion done !\n";
        }
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        if (i->next->data == value)
        {
            temp = i->next;
            i->next = NULL;
            free(temp);
            tail = i;
            return "deletion done !\n";
        }
        return "value not found ! \n";
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    bool IsEmpty() {
        return head == NULL;
    }
};
class CircularLinkedList {
private:
    node* head, * tail;
public:
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }
    string insert_last(int value) {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty()) {
            temp->next = temp;
            tail = head = temp;
            return "insert done !\n";

        }
        else {
            temp->next = head;
            tail->next = temp;
            tail = temp;
            return "insert done !\n";
        }
    }
    string insert_first(int value) {
        node* temp = new node;
        temp->data = value;
        if (IsEmpty()) {
            temp->next = temp;
            tail = head = temp;
            return "insert done !\n";

        }
        else {
            temp->next = head;
            tail->next = temp;
            head = temp;
            return "insert done !\n";

        }
    }
    bool IsEmpty() {
        return head == NULL;
    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        node* temp = new node;
        node* i = new node;
        i = head;
        if (head->next == head && head->data == value)
        {
            temp = head;
            free(temp);
            head = tail = NULL;
            return "deletion done !\n";
        }
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            tail->next = i;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        if (i->next->data == value)
        {
            temp = i->next;
            i->next = NULL;
            free(temp);
            tail = i;
            return "deletion done !\n";
        }
        return "value not found ! \n";
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    string circular_display(int elements) {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (elements--) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + "\n";
        return s;
    }
};
class DoubleLinkedList {
private:
    dnode* head;
    dnode* tail;
public:
    DoubleLinkedList() {
        head = NULL;// like head
        tail = NULL;// like tail
    }
    string insert_last(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return "insert done !\n";
        }
        temp->pre = tail;
        tail->next = temp;
        tail = temp;
        return "insert done !\n";
    }
    string insert_first(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            head = tail = temp;
            return "insert done !\n";
        }
        temp->next = head;
        head->pre = temp;
        head = temp;
        return "insert done !\n";
    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        dnode* temp = new dnode;
        if (head->next == NULL && head->data == value)
        {
            temp = head;
            head = tail = NULL;
            free(temp);
            return "deletion done !\n";
        }
        if (tail->data == value)
        {
            temp = tail;
            tail = tail->pre;
            tail->next = NULL;
            free(temp);
            return "deletion done !\n";
        }
        dnode* i = new dnode;
        i = head;
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            i->pre = NULL;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                temp->next->pre = i;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        return "value not found ! \n";
    }
    bool IsEmpty() {
        return head == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    string reverse_display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = tail;
        while (temp != head) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->pre;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
};
class DoubleCircularLinkedList {
private:
    dnode* head;
    dnode* tail;
public:
    DoubleCircularLinkedList() {
        head = NULL;// like head
        tail = NULL;// like tail
    }
    string insert_last(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            temp->next = temp;
            temp->pre = temp;
            head = tail = temp;
            return "insert done !\n";
        }
        temp->pre = tail;
        tail->next = temp;
        temp->next = head;
        head->pre = temp;
        tail = temp;
        return "insert done !\n";
    }
    string insert_first(int val) {
        dnode* temp = new dnode();
        temp->data = val;
        temp->next = NULL;
        temp->pre = NULL;
        if (IsEmpty())
        {
            temp->next = temp;
            temp->pre = temp;
            head = tail = temp;
            return "insert done !\n";
        }
        temp->pre = tail;
        tail->next = temp;
        temp->next = head;
        head->pre = temp;
        head = temp;
        return "insert done !\n";
    }
    string deleteByValue(int value) {
        if (IsEmpty())
        {
            return "already empty !\n";
        }
        dnode* temp = new dnode;
        if (head->next == head && head->data == value)
        {
            temp = head;
            free(temp);
            head = tail = NULL;
            return "deletion done !\n";
        }
        if (tail->data == value)
        {
            temp = tail;
            tail = tail->pre;
            tail->next = head;
            free(temp);
            return "deletion done !\n";
        }
        dnode* i = new dnode;
        i = head;
        if (i->data == value)
        {
            temp = i;
            i = i->next;
            i->pre = tail;
            tail->next = i;
            head = i;
            free(temp);
            return "deletion done !\n";
        }
        while (i->next != tail)
        {
            if (i->next->data == value)
            {
                temp = i->next;
                temp->next->pre = i;
                i->next = temp->next;
                free(temp);
                return "deletion done !\n";
            }
            i = i->next;
        }
        return "value not found ! \n";

    }
    bool IsEmpty() {
        return head == NULL;
    }
    string display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = head;
        while (temp != tail) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
    string circular_display(int elements) {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = head;
        while (elements--) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->next;
        }
        s = s + "\n";
        return s;
    }
    string reverse_display() {
        if (IsEmpty())
        {
            return "<Empt>\n";
        }
        string s = "";
        dnode* temp = new dnode;
        temp = tail;
        while (temp != head) {
            s = s + to_string(temp->data) + " -> ";
            temp = temp->pre;
        }
        s = s + to_string(temp->data) + "\n";
        return s;
    }
};
int main()
{
}