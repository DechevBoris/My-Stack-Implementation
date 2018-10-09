#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node<T>(const T& _data, Node<T>* ptr = nullptr)
    {
        data  = _data;
        next = ptr;
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* first;
    size_t size;

    void copy(const Stack<T>& other);
    void erase();
public:
    Stack();
    Stack(const Stack<T>& other);
    Stack& operator=(const Stack<T>& other);
    ~Stack();
    void push(const T& element);
    void pop();
    void empty();
    const T& top()const;
    bool isEmpty()const;
    size_t getSize()const;
};

template <typename T>
void Stack<T>::copy(const Stack<T>& other)
{
    if(!other.first)
    {
        this->first = nullptr;
        this->size = 0;
        return;
    }
    this->first = new Node<T>(other.first->data, other.first->next);
    Node<T>* tmp1 =  this->first;
    Node<T>* tmp2 = other.first->next;
    while(tmp2)
    {
        tmp1->next = new Node<T>(tmp2->data, tmp2->next);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    this->size = other.size;
}

template <typename T>
void Stack<T>::erase()
{
    while(this->first)
    {
        this->pop();
    }
}

template <typename T>
Stack<T>::Stack()
{
    this->first = nullptr;
    this->size = 0;

}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
    this->copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack()
{
    this->erase();
}

template <typename T>
void Stack<T>::push(const T& element)
{
    Node<T>* newEl = new Node<T>(element, this->first);
    if(newEl)
    {
        this->first = newEl;
        this->size++;
    }
}

template <typename T>
void Stack<T>::pop()
{
    if(!this->isEmpty())
    {
        Node<T>* remove = this->first;
        this->first = this->first->next;
        delete remove;
        this->size--;
    }
}

template <typename T>
void Stack<T>::empty()
{
    this->erase();
}

template <typename T>
const T& Stack<T>::top()const
{
    if(this->first)
        return this->first->data;
    return NULL;
}

template <typename T>
bool Stack<T>::isEmpty()const
{
    return this->first == nullptr;
}

template <typename T>
size_t Stack<T>::getSize()const
{
    return this->size;
}
