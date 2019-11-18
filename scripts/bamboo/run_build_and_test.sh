#!/bin/bash
##############################################################################
# Copyright (c) 2016-19, Lawrence Livermore National Security, LLC and Umpire
# project contributors. See the COPYRIGHT file for details.
#
# SPDX-License-Identifier: (MIT)
##############################################################################

function trycmd
{
  echo $1
  $1

  if [ $? -ne 0 ]; then
    echo "Error: Command Failed"
    exit -1
  fi
}

echo "Configuring..."
trycmd "cmake -DENABLE_DEVELOPER_DEFAULTS=On \
    -C ${UMPIRE_SOURCE_DIR}/.gitlab/radiuss-ci/gitlab/conf/host-configs/${SYS_TYPE}/${UMPIRE_COMPILER}.cmake \
    -C ${UMPIRE_SOURCE_DIR}/host-configs/${SYS_TYPE}/${UMPIRE_COMPILER}.cmake \
    -DCMAKE_BUILD_TYPE=${UMPIRE_BUILD_TYPE} ${BUILD_OPTIONS} ${UMPIRE_SOURCE_DIR}"

echo "Building..."
trycmd "make VERBOSE=1 -j"

echo "Testing..."
trycmd "ctest --output-on-failure -T Test"
