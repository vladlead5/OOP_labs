#include "../include/singly_linked_list.h"

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::pmr::memory_resource *resource)
    : head(nullptr), allocator(resource) {}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    clear();
}

template <typename T>
void SinglyLinkedList<T>::push_front(const T &value)
{
    Node *new_node = allocator.allocate(1);
    allocator.construct(new_node, value, head);
    head = new_node;
}

template <typename T>
void SinglyLinkedList<T>::pop_front()
{
    if (head)
    {
        Node *old_head = head;
        head = head->next;
        allocator.destroy(old_head);
        allocator.deallocate(old_head, 1);
    }
}

template <typename T>
void SinglyLinkedList<T>::clear()
{
    while (head)
    {
        pop_front();
    }
}

template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::begin()
{
    return Iterator(head);
}

template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::end()
{
    return Iterator(nullptr);
}

template <typename T>
T &SinglyLinkedList<T>::Iterator::operator*() const
{
    return current->value;
}

template <typename T>
T *SinglyLinkedList<T>::Iterator::operator->() const
{
    return &(current->value);
}

template <typename T>
typename SinglyLinkedList<T>::Iterator &SinglyLinkedList<T>::Iterator::operator++()
{
    current = current->next;
    return *this;
}

template <typename T>
typename SinglyLinkedList<T>::Iterator SinglyLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
bool SinglyLinkedList<T>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

template <typename T>
bool SinglyLinkedList<T>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}