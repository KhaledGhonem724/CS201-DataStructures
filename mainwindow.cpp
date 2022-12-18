#include "mainHeader.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include <QListWidgetItem>
#include <iostream>
#include <string>
#include <QString>
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
            s=s+ to_string(arr[i]) + " ";
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
        if(isempty()){
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
        if(isempty()){
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
        return "pushed "+to_string(val)+" done ! \n";
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
        return "top= "+to_string(top->data)+"\n";
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
            s=s+to_string( i->data)+" ";
            i = i->next;
        }
        s = s + to_string(i->data)+ " ]\n";
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
            return "enqueued "+to_string(val)+" done !\n";
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
        return "front = "+to_string(front->data)+" \n";
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
           s=s+to_string( i->data) + " ";
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
           s=s+to_string( i->data) + " ";
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
        if ( i->data == value)
        {
            temp = i;
            i=i->next;
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
        if (IsEmpty() )
        {
            return "<Empt>\n";
        }
        string s = "";
        node* temp = new node;
        temp = head;
        while (temp != tail) {
            s=s+to_string(temp->data) + " -> ";
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
        if ( i->data == value)
        {
            temp = i;
            i=i->next;
            tail->next=i;
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
        s = s +"\n";
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
        if ( i->data == value)
        {
            temp = i;
            i=i->next;
            i->pre=NULL;
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
        if ( i->data == value)
        {
            temp = i;
            i=i->next;
            i->pre=tail;
            tail->next=i;
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
        s = s  + "\n";
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
Array arr=Array(10);
Stack stc=Stack();
Queue sq=Queue();
DoubleQueue dq=DoubleQueue();
CircularQueue cq=CircularQueue();
LinkedList sll=LinkedList();
CircularLinkedList cll=CircularLinkedList();
DoubleLinkedList dll=DoubleLinkedList();
DoubleCircularLinkedList dcll=DoubleCircularLinkedList();
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap start_pic1(":/material_pics/pics/baymax2.png");
    ui->label_start_batmax->setPixmap(start_pic1.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap start_pic2(":/material_pics/pics/welcome.png");
    ui->label_start_welcome->setPixmap(start_pic2.scaled(300,75,Qt::KeepAspectRatio));
    QPixmap pix(":/material_pics/pics/robot1 .png");
    ui->lable_about->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));
    QPixmap array_pic(":/material_pics/pics/array .png");
    ui->array_label->setPixmap(array_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap stack_pic(":/material_pics/pics/stack .png");
    ui->stack_label_1->setPixmap(stack_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap linkedlist_pic(":/material_pics/pics/linked list .png");
    ui->Simple_Linked_List_label1->setPixmap(linkedlist_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap circularlinkedlist_pic(":/material_pics/pics/circular linked list.png");
    ui->Circulary_Linked_List_label1->setPixmap(circularlinkedlist_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap doublylinkedlist_pic(":/material_pics/pics/doubly linked list .png");
    ui->Doubly_Linked_List_label1->setPixmap(doublylinkedlist_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap doublyCurcularlinkedlist_pic(":/material_pics/pics/doubly circular linked list .png");
    ui->Doubly_Circular_Linked_List_label1->setPixmap(doublyCurcularlinkedlist_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap simpleQueue_pic(":/material_pics/pics/queue .png");
    ui->simple_queue_label1->setPixmap(simpleQueue_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap circularQueue_pic(":/material_pics/pics/Circular queue .png");
    ui->Circular_queue_label1->setPixmap(circularQueue_pic.scaled(200,200,Qt::KeepAspectRatio));
    QPixmap doubleEndedQueue_pic(":/material_pics/pics/double ended queue .png");
    ui->double_ended_queue_label1->setPixmap(doubleEndedQueue_pic.scaled(200,200,Qt::KeepAspectRatio));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_show_report_clicked()
{
    QString link="https://drive.google.com/drive/folders/1p-TBffjyjPfeAc9OQriX17-S3lJUv-km?usp=sharing";
    QDesktopServices::openUrl(QUrl(link));
}
void MainWindow::on_show_sourceCode_on_github_clicked()
{
    QString link="https://github.com/KhaledGhonem724/CS201_Final_project";
    QDesktopServices::openUrl(QUrl(link));
}
void MainWindow::on_show_sourceCode_on_drive_clicked()
{
    QString link="https://drive.google.com/drive/folders/1TdKdd3BTSvJwgz570812KSOD8ZVzneZi?usp=sharing";
    QDesktopServices::openUrl(QUrl(link));
}
//////Array////
void MainWindow::on_array_insert_button_clicked(){
    int n=stoi(ui->array_input->displayText().toStdString());
    QString s=QString::fromStdString(arr.insert(n));
    ui->Array_output->setText(s);
}
void MainWindow::on_array_deleteByIndex_button_clicked(){
    int n=stoi(ui->array_input->displayText().toStdString());
    QString s=QString::fromStdString(arr.DeletionByIndex(n));
    ui->Array_output->setText(s);
}
void MainWindow::on_array_deleteByValue_button_clicked(){
    int n=stoi(ui->array_input->displayText().toStdString());
    QString s=QString::fromStdString(arr.DeletionByValue(n));
    ui->Array_output->setText(s);
}
void MainWindow::on_array_Enlarge_button_clicked(){
    int n=stoi(ui->array_input->displayText().toStdString());
    QString s=QString::fromStdString(arr.Enlarge(n));
    ui->Array_output->setText(s);
}
void MainWindow::on_array_sort_button_clicked(){
    QString s=QString::fromStdString(arr.Sort());
    ui->Array_output->setText(s);
}
void MainWindow::on_array_display_button_clicked(){
    QString s=QString::fromStdString(arr.Display());
    ui->Array_output->setText(s);
}
//////Simple linked list////
void MainWindow::on_SLL_insertFirst_button_clicked(){
    int n=stoi(ui->SLL_input->displayText().toStdString());
    QString s=QString::fromStdString(sll.insert_first(n));
    ui->SLL_output->setText(s);
}
void MainWindow::on_SLL_insertLast_button_clicked(){
    int n=stoi(ui->SLL_input->displayText().toStdString());
    QString s=QString::fromStdString(sll.insert_last(n));
    ui->SLL_output->setText(s);
}
void MainWindow::on_SLL_deleteByValue_button_clicked(){
    int n=stoi(ui->SLL_input->displayText().toStdString());
    QString s=QString::fromStdString(sll.deleteByValue(n));
    ui->SLL_output->setText(s);
}
void MainWindow::on_SLL_display_button_clicked(){
    QString s=QString::fromStdString(sll.display());
    ui->SLL_output->setText(s);
}
void MainWindow::on_SLL_deleteFirst_button_clicked(){
    QString s=QString::fromStdString(sll.delete_first());
    ui->SLL_output->setText(s);
}
void MainWindow::on_SLL_deleteLast_button_clicked(){
    QString s=QString::fromStdString(sll.delete_last());
    ui->SLL_output->setText(s);
}
//////Circular linked list////
void MainWindow::on_CLL_insertFirst_button_clicked()
{
    int n=stoi(ui->CLL_input->displayText().toStdString());
    QString s=QString::fromStdString(cll.insert_first(n));
    ui->CLL_output->setText(s);
}
void MainWindow::on_CLL_insertLast_button_clicked()
{
    int n=stoi(ui->CLL_input->displayText().toStdString());
    QString s=QString::fromStdString(cll.insert_last(n));
    ui->CLL_output->setText(s);
}
void MainWindow::on_CLL_deleteByValue_button_clicked()
{
    int n=stoi(ui->CLL_input->displayText().toStdString());
    QString s=QString::fromStdString(cll.deleteByValue(n));
    ui->CLL_output->setText(s);
}
void MainWindow::on_CLL_display_button_clicked()
{
    QString s=QString::fromStdString(cll.display());
    ui->CLL_output->setText(s);
}
void MainWindow::on_CLL_circular_display_button_clicked()
{
    int n=stoi(ui->CLL_input->displayText().toStdString());
    QString s=QString::fromStdString(cll.circular_display(n));
    ui->CLL_output->setText(s);
}
//////Double linked list////
void MainWindow::on_DLL_insertFirst_button_clicked()
{
    int n=stoi(ui->DLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dll.insert_first(n));
    ui->DLL_output->setText(s);
}
void MainWindow::on_DLL_insertLast_button_clicked()
{
    int n=stoi(ui->DLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dll.insert_last(n));
    ui->DLL_output->setText(s);
}
void MainWindow::on_DLL_deleteByValue_button_clicked()
{
    int n=stoi(ui->DLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dll.deleteByValue(n));
    ui->DLL_output->setText(s);
}
void MainWindow::on_DLL_display_button_clicked()
{
    QString s=QString::fromStdString(dll.display());
    ui->DLL_output->setText(s);
}
void MainWindow::on_DLL_reverse_display_button_clicked()
{
    QString s=QString::fromStdString(dll.reverse_display());
    ui->DLL_output->setText(s);
}
//////Double Circular linked list////
void MainWindow::on_DCLL_insertFirst_button_clicked()
{
    int n=stoi(ui->DCLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dcll.insert_first(n));
    ui->DCLL_output->setText(s);
}
void MainWindow::on_DCLL_insertLast_button_clicked()
{
    int n=stoi(ui->DCLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dcll.insert_last(n));
    ui->DCLL_output->setText(s);
}
void MainWindow::on_DCLL_deleteByValue_button_clicked()
{
    int n=stoi(ui->DCLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dcll.deleteByValue(n));
    ui->DCLL_output->setText(s);
}
void MainWindow::on_DCLL_display_button_clicked(){
    QString s=QString::fromStdString(dcll.display());
    ui->DCLL_output->setText(s);
}
void MainWindow::on_DCLL_circular_display_button_clicked(){
    int n=stoi(ui->DCLL_input->displayText().toStdString());
    QString s=QString::fromStdString(dcll.circular_display(n));
    ui->DCLL_output->setText(s);
}
void MainWindow::on_DCLL_reverse_display_button_clicked(){
    QString s=QString::fromStdString(dcll.reverse_display());
    ui->DCLL_output->setText(s);
}

//////stack////
void MainWindow::on_stack_Push_button_clicked()
{
    int n=stoi(ui->stack_input->displayText().toStdString());
    QString s=QString::fromStdString(stc.Push(n));
    ui->Stack_output->setText(s);
}
void MainWindow::on_stack_Pop_button_clicked()
{
    QString s=QString::fromStdString(stc.Pop());
    ui->Stack_output->setText(s);
}
void MainWindow::on_stack_Peek_button_clicked()
{
    QString s=QString::fromStdString(stc.Peek());
    ui->Stack_output->setText(s);
}
void MainWindow::on_stack_Display_button_clicked()
{
    QString s=QString::fromStdString(stc.Display());
    ui->Stack_output->setText(s);
}
//////Simple Queue////
void MainWindow::on_SQ_enqueue_buttom_clicked(){
    int n=stoi(ui->SQ_input->displayText().toStdString());
    QString s=QString::fromStdString(sq.enqueue(n));
    ui->SQ_output->setText(s);
}
void MainWindow::on_SQ_dequeue_buttom_clicked(){
    QString s=QString::fromStdString(sq.dequeue());
    ui->SQ_output->setText(s);
}
void MainWindow::on_SQ_getfront_buttom_clicked(){
    QString s=QString::fromStdString(sq.getfront());
    ui->SQ_output->setText(s);
}
void MainWindow::on_SQ_display_buttom_clicked(){
    QString s=QString::fromStdString(sq.display());
    ui->SQ_output->setText(s);
}
//////Circular Queue////
void MainWindow::on_CQ_enqueue_buttom_clicked(){
    int n=stoi(ui->CQ_input->displayText().toStdString());
    QString s=QString::fromStdString(cq.enqueue(n));
    ui->CQ_output->setText(s);
}
void MainWindow::on_CQ_dequeue_buttom_clicked(){
    QString s=QString::fromStdString(cq.dequeue());
    ui->CQ_output->setText(s);
}
void MainWindow::on_CQ_getfront_buttom_clicked(){
    QString s=QString::fromStdString(cq.getfront());
    ui->CQ_output->setText(s);
}
void MainWindow::on_CQ_display_buttom_clicked(){
    QString s=QString::fromStdString(cq.display());
    ui->CQ_output->setText(s);
}
void MainWindow::on_CQ_circular_display_buttom_clicked(){
    int n=stoi(ui->CQ_input->displayText().toStdString());
    QString s=QString::fromStdString(cq.circural_display(n));
    ui->CQ_output->setText(s);
}
//////double Queue////
void MainWindow::on_DQ_enqueue_back_buttom_clicked(){
    int n=stoi(ui->DQ_input->displayText().toStdString());
    QString s=QString::fromStdString(dq.enqueue_back(n));
    ui->DQ_output->setText(s);
}
void MainWindow::on_DQ_enqueue_front_buttom_clicked(){
    int n=stoi(ui->DQ_input->displayText().toStdString());
    QString s=QString::fromStdString(dq.enqueue_front(n));
    ui->DQ_output->setText(s);
}
void MainWindow::on_DQ_dequeue_front_button_clicked(){
    QString s=QString::fromStdString(dq.dequeue_front());
    ui->DQ_output->setText(s);
}
void MainWindow::on_DQ_dequeue_back_button_clicked(){
    QString s=QString::fromStdString(dq.dequeue_back());
    ui->DQ_output->setText(s);
}
void MainWindow::on_DQ_getfront_buttom_clicked(){
    QString s=QString::fromStdString(dq.getFront());
    ui->DQ_output->setText(s);
}
void MainWindow::on_DQ_getrear_buttom_clicked(){
    QString s=QString::fromStdString(dq.getRear());
    ui->DQ_output->setText(s);
}
void MainWindow::on_DQ_display_buttom_clicked(){
    QString s=QString::fromStdString(dq.display());
    ui->DQ_output->setText(s);
}
