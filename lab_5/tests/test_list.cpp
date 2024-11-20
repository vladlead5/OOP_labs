#include <gtest/gtest.h>
#include "../src/block_memory_resourse.cpp"
#include "../src/singly_linked_list.cpp"
#include <string>
#include <stdexcept>
#include <memory>

TEST(SinglyLinkedListTest, PushFront)
{
    BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 5);
    SinglyLinkedList<int> list(&memory_resource);

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    auto it = list.begin();
    EXPECT_EQ(*it, 30);
    ++it;
    EXPECT_EQ(*it, 20);
    ++it;
    EXPECT_EQ(*it, 10);
}

TEST(SinglyLinkedListTest, PopFront)
{
    BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 5);
    SinglyLinkedList<int> list(&memory_resource);

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.pop_front();
    auto it = list.begin();
    EXPECT_EQ(*it, 20);
}

TEST(SinglyLinkedListTest, Clear)
{
    BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 5);
    SinglyLinkedList<int> list(&memory_resource);

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.clear();
    EXPECT_EQ(list.begin(), list.end());
}

TEST(SinglyLinkedListTest, PushFrontPerson)
{
    struct Person
    {
        std::string name;
        int age;

        Person(const std::string &n, int a) : name(n), age(a) {}
    };

    BlockMemoryResource memory_resource(SinglyLinkedList<Person>::node_size(), 5);
    SinglyLinkedList<Person> list(&memory_resource);

    list.push_front(Person("John", 30));
    list.push_front(Person("Alice", 25));
    list.push_front(Person("Bob", 35));

    auto it = list.begin();
    EXPECT_EQ(it->name, "Bob");
    EXPECT_EQ(it->age, 35);
    ++it;
    EXPECT_EQ(it->name, "Alice");
    ++it;
    EXPECT_EQ(it->name, "John");
}

TEST(SinglyLinkedListTest, PushFrontLargeNumber)
{
    BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 100);
    SinglyLinkedList<int> list(&memory_resource);

    for (int i = 0; i < 100; ++i)
    {
        list.push_front(i);
    }

    int expected = 99;
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        EXPECT_EQ(*it, expected);
        --expected;
    }
}

TEST(SinglyLinkedListTest, MixedOperations)
{
    BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 5);
    SinglyLinkedList<int> list(&memory_resource);

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.pop_front();
    list.push_front(40);
    list.push_front(50);
    list.clear();

    EXPECT_EQ(list.begin(), list.end());
}

TEST(SinglyLinkedListTest, PushFrontDifferentTypes)
{
    struct Person
    {
        std::string name;
        int age;

        Person(const std::string &n, int a) : name(n), age(a) {}
    };
    BlockMemoryResource memory_resource(SinglyLinkedList<Person>::node_size(), 5);
    SinglyLinkedList<Person> list(&memory_resource);

    list.push_front(Person("Alice", 25));
    list.push_front(Person("Bob", 30));

    auto it = list.begin();
    EXPECT_EQ(it->name, "Bob");
    EXPECT_EQ(it->age, 30);
    ++it;
    EXPECT_EQ(it->name, "Alice");
    EXPECT_EQ(it->age, 25);
}

TEST(SinglyLinkedListTest, PopAndClearWithMultipleItems)
{
    BlockMemoryResource memory_resource(SinglyLinkedList<int>::node_size(), 5);
    SinglyLinkedList<int> list(&memory_resource);

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.pop_front();
    list.pop_front();
    list.clear();

    EXPECT_EQ(list.begin(), list.end());
}