#pragma once

#include <memory_resource>
#include <iterator>

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T value;
        Node *next;

        Node(const T &value, Node *next = nullptr) : value(value), next(next) {}
    };

    Node *head;
    std::pmr::polymorphic_allocator<Node> allocator;

public:
    class Iterator
    {
        Node *current;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        Iterator(Node *node) : current(node) {}

        T &operator*() const;
        T *operator->() const;
        Iterator &operator++();
        Iterator operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
    };

    SinglyLinkedList(std::pmr::memory_resource *resource = std::pmr::get_default_resource());
    ~SinglyLinkedList();

    void push_front(const T &value);
    void pop_front();
    void clear();

    Iterator begin();
    Iterator end();
    static size_t node_size()
    {
        return sizeof(Node);
    }
};