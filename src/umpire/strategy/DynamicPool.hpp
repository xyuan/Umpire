//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2018-2019, Lawrence Livermore National Security, LLC.
// Produced at the Lawrence Livermore National Laboratory
//
// Created by David Beckingsale, david@llnl.gov
// LLNL-CODE-747640
//
// All rights reserved.
//
// This file is part of Umpire.
//
// For details, see https://github.com/LLNL/Umpire
// Please also see the LICENSE file for MIT license.
//////////////////////////////////////////////////////////////////////////////
#ifndef UMPIRE_DynamicPool_HPP
#define UMPIRE_DynamicPool_HPP

#include <memory>
#include <vector>
#include <functional>

#include "umpire/strategy/AllocationStrategy.hpp"
#include "umpire/strategy/DynamicPoolHeuristic.hpp"
#include "umpire/util/MemoryMap.hpp"

#include "umpire/Allocator.hpp"

#include <map>

namespace umpire {
namespace strategy {

/*!
 * \brief Simple dynamic pool for allocations
 *
 * This AllocationStrategy uses Simpool to provide pooling for allocations of
 * any size. The behavior of the pool can be controlled by two parameters: the
 * initial allocation size, and the minimum allocation size.
 *
 * The initial size controls how large the first piece of memory allocated is,
 * and the minimum size controls the lower bound on all future chunk
 * allocations.
 */
class DynamicPool :
  public AllocationStrategy
{
  public:
    /*!
     * \brief Callback Heuristic to trigger coalesce of free blocks in pool.
     *
     * The registered heuristic callback function will be called immediately
     * after a deallocation() has completed from the pool.
     */
    using Coalesce_Heuristic = std::function<bool( const strategy::DynamicPool& )>;

    /*!
     * \brief Construct a new DynamicPool.
     *
     * \param name Name of this instance of the DynamicPool.
     * \param id Id of this instance of the DynamicPool.
     * \param min_initial_alloc_size The minimum size of the first allocation
     *                               the pool will make.
     * \param min_alloc_size The minimum size of all future allocations.
     * \param coalesce_heuristic Heuristic callback function.
     */
    DynamicPool(
        const std::string& name,
        int id,
        Allocator allocator,
        const std::size_t initial_alloc_size = (512 * 1024 * 1024),
        const std::size_t min_alloc_size = (1 * 1024 *1024),
        const short align_bytes = 8,
        Coalesce_Heuristic coalesce_heuristic = heuristic_percent_releasable(100)) noexcept;

    ~DynamicPool();

    void* allocate(std::size_t bytes) override;

    void deallocate(void* ptr) override;

    void release() override;

    std::size_t getCurrentSize() const noexcept override;
    std::size_t getActualSize() const noexcept override;
    std::size_t getHighWatermark() const noexcept override;

    std::size_t getFreeBlocks() const;
    std::size_t getInUseBlocks() const;

    Platform getPlatform() noexcept override;

    /*!
     * \brief Get the number of bytes that may be released back to resource
     *
     * A memory pool has a set of blocks that have no allocations
     * against them.  If the size of the set is greater than one, then
     * the pool will have a number of bytes that may be released back to
     * the resource or coalesced into a larger block.
     *
     * \return The total number of bytes that are releasable
     */
    std::size_t getReleasableSize() const noexcept;

    /*!
     * \brief Get the number of memory blocks that the pools has
     *
     * \return The total number of blocks that are allocated by the pool
     */
    std::size_t getBlocksInPool() const noexcept;

    void coalesce() noexcept;

  private:
  using Pointer = void*;
  using AddressMap = util::MemoryMap<std::size_t>;
  using SizeMap = std::multimap<std::size_t, Pointer>;

  strategy::AllocationStrategy* m_allocator;
  const std::size_t m_min_alloc_bytes;
  const short m_align_bytes;
  AddressMap m_used_map;
  SizeMap m_free_map;
  std::size_t m_curr_bytes;
  std::size_t m_actual_bytes;
  std::size_t m_highwatermark;
};

} // end of namespace strategy
} // end namespace umpire

#endif // UMPIRE_DynamicPool_HPP
