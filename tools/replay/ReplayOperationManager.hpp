//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-19, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
//////////////////////////////////////////////////////////////////////////////
#ifndef REPLAY_ReplayOperationManager_HPP
#define REPLAY_ReplayOperationManager_HPP

#include <iostream>
#include <cstdint>
#include <vector>

#include "ReplayFile.hpp"
#include "umpire/Allocator.hpp"
#include "umpire/strategy/AllocationAdvisor.hpp"
#include "umpire/strategy/SizeLimiter.hpp"
#include "umpire/strategy/MixedPool.hpp"
#include "umpire/strategy/MonotonicAllocationStrategy.hpp"
#include "umpire/strategy/SlotPool.hpp"
#include "umpire/strategy/ThreadSafeAllocator.hpp"
#include "umpire/util/AllocationRecord.hpp"
#include "umpire/ResourceManager.hpp"

class ReplayOperationManager {
public:
  ReplayOperationManager( ReplayFile::Header* Operations );
  ~ReplayOperationManager();

  void runOperations(bool gather_statistics);
  void printInfo();

private:
  std::map<std::string, std::vector< std::pair<size_t, std::size_t>>> m_stat_series;
  ReplayFile::Header* m_ops_table;

  void makeAllocator(ReplayFile::Operation* op);
  void makeAllocate(ReplayFile::Operation* op);
  void makeDeallocate(ReplayFile::Operation* op);
  void makeCoalesce(ReplayFile::Operation* op);
  void makeRelease(ReplayFile::Operation* op);
  void dumpStats();
};

#endif // REPLAY_ReplayOperationManager_HPP
