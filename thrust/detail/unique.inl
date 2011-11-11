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


/*! \file unique.inl
 *  \brief Inline file for unique.h.
 */

#include <thrust/detail/config.h>
#include <thrust/unique.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/system/detail/generic/select_system.h>
#include <thrust/system/detail/generic/unique.h>
#include <thrust/system/detail/generic/unique_by_key.h>
#include <thrust/system/detail/internal/entry/select_system.h>
#include <thrust/system/detail/internal/entry/unique.h>
#include <thrust/system/detail/internal/entry/unique_by_key.h>

namespace thrust
{
    
template<typename ForwardIterator>
  ForwardIterator unique(ForwardIterator first,
                         ForwardIterator last)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique;

  typedef typename thrust::iterator_space<ForwardIterator>::type space;

  return unique(select_system(space()), first, last);
} // end unique()


template<typename ForwardIterator,
         typename BinaryPredicate>
  ForwardIterator unique(ForwardIterator first,
                         ForwardIterator last,
                         BinaryPredicate binary_pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique;

  typedef typename thrust::iterator_space<ForwardIterator>::type space;

  return unique(select_system(space()), first, last, binary_pred);
} // end unique()


template<typename InputIterator,
         typename OutputIterator>
  OutputIterator unique_copy(InputIterator first,
                             InputIterator last,
                             OutputIterator output)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique_copy;

  typedef typename thrust::iterator_space<InputIterator>::type  space1;
  typedef typename thrust::iterator_space<OutputIterator>::type space2;

  return unique_copy(select_system(space1(),space2()), first, last, output);
} // end unique_copy()


template<typename InputIterator,
         typename OutputIterator,
         typename BinaryPredicate>
  OutputIterator unique_copy(InputIterator first,
                             InputIterator last,
                             OutputIterator output,
                             BinaryPredicate binary_pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique_copy;

  typedef typename thrust::iterator_space<InputIterator>::type  space1;
  typedef typename thrust::iterator_space<OutputIterator>::type space2;

  return unique_copy(select_system(space1(),space2()), first, last, output, binary_pred);
} // end unique_copy()


template<typename ForwardIterator1,
         typename ForwardIterator2>
  thrust::pair<ForwardIterator1,ForwardIterator2>
    unique_by_key(ForwardIterator1 keys_first, 
                  ForwardIterator1 keys_last,
                  ForwardIterator2 values_first)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique_by_key;

  typedef typename thrust::iterator_space<ForwardIterator1>::type space1;
  typedef typename thrust::iterator_space<ForwardIterator2>::type space2;

  return unique_by_key(select_system(space1(),space2()), keys_first, keys_last, values_first);
} // end unique_by_key()


template<typename ForwardIterator1,
         typename ForwardIterator2,
         typename BinaryPredicate>
  thrust::pair<ForwardIterator1,ForwardIterator2>
    unique_by_key(ForwardIterator1 keys_first, 
                  ForwardIterator1 keys_last,
                  ForwardIterator2 values_first,
                  BinaryPredicate binary_pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique_by_key;

  typedef typename thrust::iterator_space<ForwardIterator1>::type space1;
  typedef typename thrust::iterator_space<ForwardIterator2>::type space2;

  return unique_by_key(select_system(space1(),space2()), keys_first, keys_last, values_first, binary_pred);
} // end unique_by_key()


template<typename InputIterator1,
         typename InputIterator2,
         typename OutputIterator1,
         typename OutputIterator2>
  thrust::pair<OutputIterator1,OutputIterator2>
    unique_by_key_copy(InputIterator1 keys_first, 
                       InputIterator1 keys_last,
                       InputIterator2 values_first,
                       OutputIterator1 keys_output,
                       OutputIterator2 values_output)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique_by_key_copy;

  typedef typename thrust::iterator_space<InputIterator1>::type  space1;
  typedef typename thrust::iterator_space<InputIterator2>::type  space2;
  typedef typename thrust::iterator_space<OutputIterator1>::type space3;
  typedef typename thrust::iterator_space<OutputIterator2>::type space4;

  return unique_by_key_copy(select_system(space1(),space2(),space3(),space4()), keys_first, keys_last, values_first, keys_output, values_output);
} // end unique_by_key_copy()


template<typename InputIterator1,
         typename InputIterator2,
         typename OutputIterator1,
         typename OutputIterator2,
         typename BinaryPredicate>
  thrust::pair<OutputIterator1,OutputIterator2>
    unique_by_key_copy(InputIterator1 keys_first, 
                       InputIterator1 keys_last,
                       InputIterator2 values_first,
                       OutputIterator1 keys_output,
                       OutputIterator2 values_output,
                       BinaryPredicate binary_pred)
{
  using thrust::system::detail::generic::select_system;
  using thrust::system::detail::generic::unique_by_key_copy;

  typedef typename thrust::iterator_space<InputIterator1>::type  space1;
  typedef typename thrust::iterator_space<InputIterator2>::type  space2;
  typedef typename thrust::iterator_space<OutputIterator1>::type space3;
  typedef typename thrust::iterator_space<OutputIterator2>::type space4;

  return unique_by_key_copy(select_system(space1(),space2(),space3(),space4()), keys_first, keys_last, values_first, keys_output, values_output, binary_pred);
} // end unique_by_key_copy()


} // end namespace thrust

