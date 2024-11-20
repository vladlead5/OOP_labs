#include "../include/block_memory_resourse.h"
#include <new>
#include <cstddef>
#include <stdexcept>
#include <iostream>

BlockMemoryResource::BlockMemoryResource(size_t block_size, size_t block_count)
    : block_size_(block_size), block_count_(block_count)
{
    memory_pool_ = ::operator new(block_size_ * block_count_);
    for (size_t i = 0; i < block_count_; ++i)
    {
        void *block = static_cast<char *>(memory_pool_) + i * block_size_;
        free_blocks_.push_back(block);
    }
}

BlockMemoryResource::~BlockMemoryResource()
{
    ::operator delete(memory_pool_);
}

void *BlockMemoryResource::do_allocate(size_t bytes, size_t alignment)
{
    if (bytes > block_size_)
    {
        std::cerr << "Allocation size exceeds block size!" << std::endl;
        throw std::bad_alloc();
    }

    if (free_blocks_.empty())
    {
        std::cerr << "No free blocks available!" << std::endl;
        throw std::bad_alloc();
    }

    void *block = free_blocks_.front();
    free_blocks_.pop_front();
    return block;
}

void BlockMemoryResource::do_deallocate(void *p, size_t bytes, size_t alignment)
{
    if (p != nullptr)
    {
        free_blocks_.push_back(p);
    }
}

bool BlockMemoryResource::do_is_equal(const std::pmr::memory_resource &other) const noexcept
{
    return this == &other;
}