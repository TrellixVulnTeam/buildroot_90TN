/* EINA - EFL data type library
 * Copyright (C) 2008 Cedric Bail
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library;
 * if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EINA_CONFIG_H_
#define EINA_CONFIG_H_

#ifdef HAVE_EXOTIC
# include <Exotic.h>
#endif

#ifdef EINA_MAGIC_DEBUG
# undef EINA_MAGIC_DEBUG
#endif
#define EINA_MAGIC_DEBUG

#ifndef EINA_DEFAULT_MEMPOOL
# undef EINA_DEFAULT_MEMPOOL
#endif


#ifdef EINA_SAFETY_CHECKS
# undef EINA_SAFETY_CHECKS
#endif
#define EINA_SAFETY_CHECKS

#ifndef EINA_HAVE_THREADS
#define EINA_HAVE_THREADS
#endif

#ifdef EINA_HAVE_PTHREAD_AFFINITY
# undef EINA_HAVE_PTHREAD_AFFINITY
#endif
#define EINA_HAVE_PTHREAD_AFFINITY

#ifdef EINA_HAVE_PTHREAD_BARRIER
# undef EINA_HAVE_PTHREAD_BARRIER
#endif
#define EINA_HAVE_PTHREAD_BARRIER

#ifdef EINA_HAVE_PTHREAD_SETNAME
# undef EINA_HAVE_PTHREAD_SETNAME
#endif
#define EINA_HAVE_PTHREAD_SETNAME

#ifdef EINA_HAVE_DEBUG_THREADS
# undef EINA_HAVE_DEBUG_THREADS
#endif


#ifdef EINA_SIZEOF_WCHAR_T
# undef EINA_SIZEOF_WCHAR_T
#endif
#define EINA_SIZEOF_WCHAR_T 4

#ifdef EINA_SIZEOF_UINTPTR_T
# undef EINA_SIZEOF_UINTPTR_T
#endif
#define EINA_SIZEOF_UINTPTR_T 4

#ifdef EINA_CONFIGURE_HAVE_DIRENT_H
# undef EINA_CONFIGURE_HAVE_DIRENT_H
#endif


#ifdef EINA_CONFIGURE_ENABLE_LOG
# undef EINA_CONFIGURE_ENABLE_LOG
#endif
#define EINA_ENABLE_LOG

#ifdef EINA_HAVE_ALLOCA_H
# undef EINA_HAVE_ALLOCA_H
#endif
#define EINA_HAVE_ALLOCA_H

#ifdef EINA_HAVE_BSWAP16
# undef EINA_HAVE_BSWAP16
#endif
#define EINA_HAVE_BSWAP16

#ifdef EINA_HAVE_BSWAP32
# undef EINA_HAVE_BSWAP32
#endif
#define EINA_HAVE_BSWAP32

#ifdef EINA_HAVE_BSWAP64
# undef EINA_HAVE_BSWAP64
#endif
#define EINA_HAVE_BSWAP64

#ifdef EINA_HAVE_BYTESWAP_H
# undef EINA_HAVE_BYTESWAP_H
#endif
#define EINA_HAVE_BYTESWAP_H

#ifdef EINA_HAVE_POSIX_SPINLOCK
# undef EINA_HAVE_POSIX_SPINLOCK
#endif
#define EINA_HAVE_POSIX_SPINLOCK

#ifndef EINA_HAVE_OSX_SPINLOCK
# undef EINA_HAVE_OSX_SPINLOCK
#endif


#ifndef EINA_HAVE_OSX_SEMAPHORE
# undef EINA_HAVE_OSX_SEMAPHORE
#endif


#include <limits.h>

#ifndef __WORDSIZE
# if defined(__OPENBSD__) && (INTPTR_MAX == INT32_MAX)
#  define __WORDSIZE 32
# else
#  define __WORDSIZE 64
# endif
#endif

/* Do not turn the following #define as meaning EFL64. We are only 
   interested to know if sizeof (void*) == 64bits or not. Those means
   something else.

   defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__amd64)
 */
#if defined(_WIN64) || defined(__LP64__) || defined(_LP64) || defined(__ppc64__)
# define EFL64
#endif

#endif /* EINA_CONFIG_H_ */
