#pragma once

#include <memory_resource>
#include <list>

class BlockMemoryResource : public std::pmr::memory_resource
{
public:
    BlockMemoryResource(size_t block_size, size_t block_count);
    ~BlockMemoryResource();

protected:
    void *do_allocate(size_t bytes, size_t alignment) override;
    void do_deallocate(void *p, size_t bytes, size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource &other) const noexcept override;

private:
    size_t block_size_;
    size_t block_count_;
    void *memory_pool_;
    std::list<void *> free_blocks_;
};