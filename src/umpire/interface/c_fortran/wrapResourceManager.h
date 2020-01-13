//////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
//////////////////////////////////////////////////////////////////////////////
// wrapResourceManager.h
// This is generated code, do not edit
// Copyright (c) 2016-19, Lawrence Livermore National Security, LLC and Umpire
// project contributors. See the COPYRIGHT file for details.
//
// SPDX-License-Identifier: (MIT)
/**
 * \file wrapResourceManager.h
 * \brief Shroud generated wrapper for ResourceManager class
 */
// For C users and C++ implementation

#ifndef WRAPRESOURCEMANAGER_H
#define WRAPRESOURCEMANAGER_H

#include "typesUmpire.h"
#ifdef __cplusplus
#include <cstddef>
#else
#include <stdbool.h>
#include <stddef.h>
#endif

// splicer begin class.ResourceManager.CXX_declarations
// splicer end class.ResourceManager.CXX_declarations

#ifdef __cplusplus
extern "C" {
#endif

// splicer begin class.ResourceManager.C_declarations
// splicer end class.ResourceManager.C_declarations

umpire_resourcemanager * umpire_resourcemanager_get_instance(
    umpire_resourcemanager * SHC_rv);

umpire_allocator * umpire_resourcemanager_get_allocator_by_name(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_get_allocator_by_name_bufferify(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_get_allocator_by_id(
    umpire_resourcemanager * self, const int id,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_pool(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, size_t initial_size, size_t block,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_pool(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, size_t initial_size, size_t block,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_list_pool(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, size_t initial_size, size_t block,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_list_pool(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, size_t initial_size, size_t block,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_advisor(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, const char * advice_op, int device_id,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_advisor(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, const char * advice_op, int Ladvice_op,
    int device_id, umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_named(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_named(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_thread_safe(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_thread_safe(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_fixed_pool(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, size_t object_size,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_fixed_pool(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, size_t object_size,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_prefetcher(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator, int device_id,
    umpire_allocator * SHC_rv);

umpire_allocator * umpire_resourcemanager_make_allocator_bufferify_prefetcher(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator, int device_id,
    umpire_allocator * SHC_rv);

void umpire_resourcemanager_register_allocator(
    umpire_resourcemanager * self, const char * name,
    umpire_allocator allocator);

void umpire_resourcemanager_register_allocator_bufferify(
    umpire_resourcemanager * self, const char * name, int Lname,
    umpire_allocator allocator);

umpire_allocator * umpire_resourcemanager_get_allocator_for_ptr(
    umpire_resourcemanager * self, void * ptr,
    umpire_allocator * SHC_rv);

bool umpire_resourcemanager_is_allocator(umpire_resourcemanager * self,
    const char * name);

bool umpire_resourcemanager_is_allocator_bufferify(
    umpire_resourcemanager * self, const char * name, int Lname);

bool umpire_resourcemanager_has_allocator(umpire_resourcemanager * self,
    void * ptr);

void umpire_resourcemanager_copy_all(umpire_resourcemanager * self,
    void * src_ptr, void * dst_ptr);

void umpire_resourcemanager_copy_with_size(
    umpire_resourcemanager * self, void * src_ptr, void * dst_ptr,
    size_t size);

void umpire_resourcemanager_memset_all(umpire_resourcemanager * self,
    void * ptr, int val);

void umpire_resourcemanager_memset_with_size(
    umpire_resourcemanager * self, void * ptr, int val, size_t length);

void * umpire_resourcemanager_reallocate_default(
    umpire_resourcemanager * self, void * src_ptr, size_t size);

void * umpire_resourcemanager_reallocate_with_allocator(
    umpire_resourcemanager * self, void * src_ptr, size_t size,
    umpire_allocator allocator);

void * umpire_resourcemanager_move(umpire_resourcemanager * self,
    void * src_ptr, umpire_allocator allocator);

void umpire_resourcemanager_deallocate(umpire_resourcemanager * self,
    void * ptr);

size_t umpire_resourcemanager_get_size(umpire_resourcemanager * self,
    void * ptr);

#ifdef __cplusplus
}
#endif

#endif  // WRAPRESOURCEMANAGER_H
