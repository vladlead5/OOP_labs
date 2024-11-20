#include "./src/singly_linked_list.cpp"
#include "./src/block_memory_resourse.cpp"
#include <iostream>
#include <string>

struct Person
{
    std::string name;
    int age;

    Person(const std::string &n, int a) : name(n), age(a) {}
};

int main()
{
    {
        BlockMemoryResource memory_resource(SinglyLinkedList<Person>::node_size(), 4);

        SinglyLinkedList<Person> list(&memory_resource);

        list.push_front(Person("Pavel", 30));
        list.push_front(Person("Peter", 25));
        list.push_front(Person("Artem", 35));
        list.push_front(Person("Nikolai", 28));

        std::cout << "List of Persons:" << std::endl;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            std::cout << "Name: " << it->name << ", Age: " << it->age << std::endl;
        }
    }

    {
        BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 4);

        SinglyLinkedList<int> list(&memory_resource);

        list.push_front(10);
        list.push_front(20);
        list.push_front(30);
        list.push_front(40);

        std::cout << "List of Integers:" << std::endl;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }

    return 0;
}