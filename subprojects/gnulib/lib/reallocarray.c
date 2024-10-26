/* reallocarray function that is glibc compatible.

   Copyright (C) 2017-2024 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* written by Darshit Shah */

#include <config.h>

#include <stdckdint.h>
#include <stdlib.h>
#include <errno.h>

void *
reallocarray (void *ptr, size_t nmemb, size_t size)
{
  size_t nbytes;
  if (ckd_mul (&nbytes, nmemb, size))
    {
      errno = ENOMEM;
      return NULL;
    }

  /* Avoid calling realloc (ptr, 0), since that is undefined behaviour in
     ISO C 23 and since the GNU libc behaviour may possibly change.  */
  if (nbytes == 0)
    {
      void *new_ptr = malloc (1);
      if (new_ptr == NULL)
        /* errno is set here.  */
        return NULL;
      free (ptr);
      return new_ptr;
    }

  /* Call realloc, setting errno to ENOMEM on failure.  */
  return realloc (ptr, nbytes);
}