/*
 *  Copyright 2008-2011 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


/*! \file logical.inl
 *  \brief Inline file for logical.h.
 */

#include <thrust/detail/config.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/system/detail/generic/select_system.h>
#include <thrust/system/detail/generic/logical.h>
#include <thrust/system/detail/internal/entry/select_system.h>
#include <thrust/system/detail/internal/entry/logical.h>

namespace thrust
{

template <class InputIterator, class Predicate>
bool all_of(InputIterator first, InputIterator last, Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::all_of;

  typedef typename thrust::iterator_space<InputIterator>::type space;

  return all_of(select_system(space()), first, last, pred);
}

template <class InputIterator, class Predicate>
bool any_of(InputIterator first, InputIterator last, Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::any_of;

  typedef typename thrust::iterator_space<InputIterator>::type space;

  return any_of(select_system(space()), first, last, pred);
}

template <class InputIterator, class Predicate>
bool none_of(InputIterator first, InputIterator last, Predicate pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::none_of;

  typedef typename thrust::iterator_space<InputIterator>::type space;

  return none_of(select_system(space()), first, last, pred);
}

} // end namespace thrust

