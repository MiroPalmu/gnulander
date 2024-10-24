Gnulander wants to use some modules from gnulib,
however gnulib assumes that projects that use it are build with gnu build system.

This subdirectory is for setting mock gnu build system for building libgnu.a,
in such way that meson can build it with custom target.

Every generated file in source tree should be tracked with git, as it is assumed that,
this directory is setup once and rarely updated and we do not want to meson to gnereate *any*
files to source tree. Only to build tree.

# Initial import process

At commit 4f3f6b3 build(gnulib): add subdir and configure.ac (hash potentially going to change),
following command was executed in gnulander/gnulib:

```bash
$ /path/to/gnulib/gnulib-tool --aux-dir=build-aux --import full-read full-write

Module list with included dependencies (indented):
    absolute-header
    extensions
    extern-inline
  full-read
  full-write
    gen-header
    include_next
    msvc-inval
    msvc-nothrow
    raise
    read
    safe-read
    safe-write
    signal-h
    snippet/arg-nonnull
    snippet/c++defs
    snippet/warn-on-use
    ssize_t
    stddef
    sys_types
    unistd
    write
File list:
  lib/arg-nonnull.h
  lib/c++defs.h
  lib/full-read.c
  lib/full-read.h
  lib/full-write.c
  lib/full-write.h
  lib/msvc-inval.c
  lib/msvc-inval.h
  lib/msvc-nothrow.c
  lib/msvc-nothrow.h
  lib/raise.c
  lib/read.c
  lib/safe-read.c
  lib/safe-read.h
  lib/safe-write.c
  lib/safe-write.h
  lib/signal.in.h
  lib/stddef.in.h
  lib/sys-limits.h
  lib/sys_types.in.h
  lib/unistd.c
  lib/unistd.in.h
  lib/warn-on-use.h
  lib/write.c
  m4/00gnulib.m4
  m4/absolute-header.m4
  m4/extensions.m4
  m4/extern-inline.m4
  m4/gnulib-common.m4
  m4/include_next.m4
  m4/msvc-inval.m4
  m4/msvc-nothrow.m4
  m4/off_t.m4
  m4/pid_t.m4
  m4/raise.m4
  m4/read.m4
  m4/safe-read.m4
  m4/safe-write.m4
  m4/signal_h.m4
  m4/ssize_t.m4
  m4/stddef_h.m4
  m4/sys_types_h.m4
  m4/unistd_h.m4
  m4/warn-on-use.m4
  m4/wchar_t.m4
  m4/write.m4
  m4/zzgnulib.m4
Creating directory ./lib
Creating directory ./m4
Creating directory ./build-aux
Copying file lib/arg-nonnull.h
Copying file lib/c++defs.h
Copying file lib/full-read.c
Copying file lib/full-read.h
Copying file lib/full-write.c
Copying file lib/full-write.h
Copying file lib/msvc-inval.c
Copying file lib/msvc-inval.h
Copying file lib/msvc-nothrow.c
Copying file lib/msvc-nothrow.h
Copying file lib/raise.c
Copying file lib/read.c
Copying file lib/safe-read.c
Copying file lib/safe-read.h
Copying file lib/safe-write.c
Copying file lib/safe-write.h
Copying file lib/signal.in.h
Copying file lib/stddef.in.h
Copying file lib/sys-limits.h
Copying file lib/sys_types.in.h
Copying file lib/unistd.c
Copying file lib/unistd.in.h
Copying file lib/warn-on-use.h
Copying file lib/write.c
Copying file m4/00gnulib.m4
Copying file m4/absolute-header.m4
Copying file m4/extensions.m4
Copying file m4/extern-inline.m4
Copying file m4/gnulib-common.m4
Copying file m4/gnulib-tool.m4
Copying file m4/include_next.m4
Copying file m4/msvc-inval.m4
Copying file m4/msvc-nothrow.m4
Copying file m4/off_t.m4
Copying file m4/pid_t.m4
Copying file m4/raise.m4
Copying file m4/read.m4
Copying file m4/safe-read.m4
Copying file m4/safe-write.m4
Copying file m4/signal_h.m4
Copying file m4/ssize_t.m4
Copying file m4/stddef_h.m4
Copying file m4/sys_types_h.m4
Copying file m4/unistd_h.m4
Copying file m4/warn-on-use.m4
Copying file m4/wchar_t.m4
Copying file m4/write.m4
Copying file m4/zzgnulib.m4
Creating m4/gnulib-cache.m4
Creating m4/gnulib-comp.m4
Creating lib/Makefile.am
Finished.

You may need to add #include directives for the following .h files.
  #include "full-read.h"
  #include "full-write.h"

Don't forget to
  - add "lib/Makefile" to AC_CONFIG_FILES in ./configure.ac,
  - mention "lib" in SUBDIRS in Makefile.am,
  - mention "-I m4" in ACLOCAL_AMFLAGS in Makefile.am
    or add an AC_CONFIG_MACRO_DIRS([m4]) invocation in ./configure.ac,
  - mention "m4/gnulib-cache.m4" in EXTRA_DIST in Makefile.am,
  - invoke gl_EARLY in ./configure.ac, right after AC_PROG_CC,
  - invoke gl_INIT in ./configure.ac.
```

# Importing rest of documented modules #1

```bash
=> ~/data/scratch/repos/gnulib/gnulib-tool --add-import full-read full-write pipe2-safer mkfifo socket connect open close
Module list with included dependencies (indented):
    absolute-header
    alignasof
    alloca-opt
    assert-h
    binary-io
    c99
    cloexec
  close
  connect
    dup2
    errno
    extensions
    extern-inline
    fcntl
    fcntl-h
    fd-hook
    fd-safer-flag
    filename
    fstat
  full-read
  full-write
    gen-header
    getdtablesize
    idx
    include_next
    largefile
    limits-h
    malloca
  mkfifo
    msvc-inval
    msvc-nothrow
    multiarch
  open
    pathmax
    pipe-posix
    pipe2
  pipe2-safer
    raise
    read
    safe-read
    safe-write
    signal-h
    snippet/arg-nonnull
    snippet/c++defs
    snippet/warn-on-use
  socket
    socketlib
    sockets
    socklen
    ssize_t
    stat
    stat-time
    std-gnu11
    stdbool
    stdckdint
    stddef
    stdint
    sys_socket
    sys_stat
    sys_types
    sys_uio
    time-h
    unistd
    unistd-safer
    write
    xalloc-oversized
File list:
  lib/alloca.in.h
  lib/arg-nonnull.h
  lib/assert.in.h
  lib/binary-io.c
  lib/binary-io.h
  lib/c++defs.h
  lib/cloexec.c
  lib/cloexec.h
  lib/close.c
  lib/connect.c
  lib/dup-safer-flag.c
  lib/dup-safer.c
  lib/dup2.c
  lib/errno.in.h
  lib/fcntl.c
  lib/fcntl.in.h
  lib/fd-hook.c
  lib/fd-hook.h
  lib/fd-safer-flag.c
  lib/fd-safer.c
  lib/filename.h
  lib/fstat.c
  lib/full-read.c
  lib/full-read.h
  lib/full-write.c
  lib/full-write.h
  lib/getdtablesize.c
  lib/idx.h
  lib/intprops-internal.h
  lib/limits.in.h
  lib/malloca.c
  lib/malloca.h
  lib/mkfifo.c
  lib/msvc-inval.c
  lib/msvc-inval.h
  lib/msvc-nothrow.c
  lib/msvc-nothrow.h
  lib/open.c
  lib/pathmax.h
  lib/pipe-safer.c
  lib/pipe.c
  lib/pipe2-safer.c
  lib/pipe2.c
  lib/raise.c
  lib/read.c
  lib/safe-read.c
  lib/safe-read.h
  lib/safe-write.c
  lib/safe-write.h
  lib/signal.in.h
  lib/socket.c
  lib/sockets.c
  lib/sockets.h
  lib/stat-time.c
  lib/stat-time.h
  lib/stat-w32.c
  lib/stat-w32.h
  lib/stat.c
  lib/stdckdint.in.h
  lib/stddef.in.h
  lib/stdint.in.h
  lib/sys-limits.h
  lib/sys_socket.c
  lib/sys_socket.in.h
  lib/sys_stat.in.h
  lib/sys_types.in.h
  lib/sys_uio.in.h
  lib/time.in.h
  lib/unistd--.h
  lib/unistd-safer.h
  lib/unistd.c
  lib/unistd.in.h
  lib/verify.h
  lib/w32sock.h
  lib/warn-on-use.h
  lib/write.c
  lib/xalloc-oversized.h
  m4/00gnulib.m4
  m4/absolute-header.m4
  m4/alloca.m4
  m4/assert_h.m4
  m4/c-bool.m4
  m4/close.m4
  m4/dup2.m4
  m4/eealloc.m4
  m4/errno_h.m4
  m4/extensions.m4
  m4/extern-inline.m4
  m4/fcntl-o.m4
  m4/fcntl.m4
  m4/fcntl_h.m4
  m4/fstat.m4
  m4/getdtablesize.m4
  m4/gnulib-common.m4
  m4/include_next.m4
  m4/largefile.m4
  m4/limits-h.m4
  m4/malloca.m4
  m4/mkfifo.m4
  m4/mode_t.m4
  m4/msvc-inval.m4
  m4/msvc-nothrow.m4
  m4/multiarch.m4
  m4/off_t.m4
  m4/open-cloexec.m4
  m4/open-slash.m4
  m4/open.m4
  m4/pathmax.m4
  m4/pid_t.m4
  m4/pipe.m4
  m4/pipe2.m4
  m4/raise.m4
  m4/read.m4
  m4/safe-read.m4
  m4/safe-write.m4
  m4/signal_h.m4
  m4/socketlib.m4
  m4/sockets.m4
  m4/socklen.m4
  m4/sockpfaf.m4
  m4/ssize_t.m4
  m4/stat-time.m4
  m4/stat.m4
  m4/std-gnu11.m4
  m4/stdalign.m4
  m4/stddef_h.m4
  m4/stdint.m4
  m4/sys_socket_h.m4
  m4/sys_stat_h.m4
  m4/sys_types_h.m4
  m4/sys_uio_h.m4
  m4/time_h.m4
  m4/unistd-safer.m4
  m4/unistd_h.m4
  m4/warn-on-use.m4
  m4/wchar_t.m4
  m4/wint_t.m4
  m4/write.m4
  m4/zzgnulib.m4
Copying file lib/alloca.in.h
Copying file lib/connect.c
Copying file lib/errno.in.h
Copying file lib/filename.h
Copying file lib/fstat.c
Copying file lib/idx.h
Copying file lib/intprops-internal.h
Copying file lib/limits.in.h
Copying file lib/malloca.c
Copying file lib/malloca.h
Copying file lib/mkfifo.c
Copying file lib/open.c
Copying file lib/pathmax.h
Copying file lib/socket.c
Copying file lib/sockets.c
Copying file lib/sockets.h
Copying file lib/stat-time.c
Copying file lib/stat-time.h
Copying file lib/stat-w32.c
Copying file lib/stat-w32.h
Copying file lib/stat.c
Copying file lib/stdckdint.in.h
Copying file lib/stdint.in.h
Copying file lib/sys_socket.c
Copying file lib/sys_socket.in.h
Copying file lib/sys_stat.in.h
Copying file lib/sys_uio.in.h
Copying file lib/time.in.h
Copying file lib/w32sock.h
Copying file lib/xalloc-oversized.h
Copying file m4/alloca.m4
Copying file m4/eealloc.m4
Copying file m4/errno_h.m4
Copying file m4/fstat.m4
Copying file m4/largefile.m4
Copying file m4/limits-h.m4
Copying file m4/malloca.m4
Copying file m4/mkfifo.m4
Copying file m4/mode_t.m4
Copying file m4/multiarch.m4
Copying file m4/open-cloexec.m4
Copying file m4/open-slash.m4
Copying file m4/open.m4
Copying file m4/pathmax.m4
Copying file m4/socketlib.m4
Copying file m4/sockets.m4
Copying file m4/socklen.m4
Copying file m4/sockpfaf.m4
Copying file m4/stat-time.m4
Copying file m4/stat.m4
Copying file m4/stdalign.m4
Copying file m4/stdint.m4
Copying file m4/sys_socket_h.m4
Copying file m4/sys_stat_h.m4
Copying file m4/sys_uio_h.m4
Copying file m4/time_h.m4
Copying file m4/wint_t.m4
Updating m4/gnulib-cache.m4 (backup in m4/gnulib-cache.m4~)
Updating m4/gnulib-comp.m4 (backup in m4/gnulib-comp.m4~)
Updating lib/Makefile.am (backup in lib/Makefile.am~)
Finished.

You may need to add #include directives for the following .h files.
  #include <fcntl.h>
  #include <sys/socket.h>
  #include <sys/stat.h>
  #include <unistd.h>
  #include "full-read.h"
  #include "full-write.h"
  #include "unistd-safer.h"

You may need to use the following Makefile variables when linking.
Use them in <program>_LDADD when linking a program, or
in <library>_a_LDFLAGS or <library>_la_LDFLAGS when linking a library.
  $(LIBSOCKET)

Don't forget to
  - add "lib/Makefile" to AC_CONFIG_FILES in ./configure.ac,
  - mention "lib" in SUBDIRS in Makefile.am,
  - mention "-I m4" in ACLOCAL_AMFLAGS in Makefile.am
    or add an AC_CONFIG_MACRO_DIRS([m4]) invocation in ./configure.ac,
  - mention "m4/gnulib-cache.m4" in EXTRA_DIST in Makefile.am,
  - invoke gl_EARLY in ./configure.ac, right after AC_PROG_CC,
```

# Importing rest of documented modules #2

```bash
=>  ~/data/scratch/repos/gnulib/gnulib-tool --add-import ftruncate passfd
Module list with included dependencies (indented):
    absolute-header
    alignasof
    alloca-opt
    assert-h
    binary-io
    c99
    cloexec
  close
  connect
    dup2
    errno
    extensions
    extern-inline
    fcntl
    fcntl-h
    fd-hook
    fd-safer-flag
    filename
    fstat
  ftruncate
  full-read
  full-write
    gen-header
    getdtablesize
    idx
    include_next
    largefile
    limits-h
    malloca
  mkfifo
    msvc-inval
    msvc-nothrow
    multiarch
  open
  passfd
    pathmax
    pipe-posix
    pipe2
  pipe2-safer
    raise
    read
    safe-read
    safe-write
    signal-h
    snippet/arg-nonnull
    snippet/c++defs
    snippet/warn-on-use
  socket
    socketlib
    sockets
    socklen
    ssize_t
    stat
    stat-time
    std-gnu11
    stdbool
    stdckdint
    stddef
    stdint
    sys_socket
    sys_stat
    sys_types
    sys_uio
    time-h
    unistd
    unistd-safer
    write
    xalloc-oversized
File list:
  lib/alloca.in.h
  lib/arg-nonnull.h
  lib/assert.in.h
  lib/binary-io.c
  lib/binary-io.h
  lib/c++defs.h
  lib/cloexec.c
  lib/cloexec.h
  lib/close.c
  lib/connect.c
  lib/dup-safer-flag.c
  lib/dup-safer.c
  lib/dup2.c
  lib/errno.in.h
  lib/fcntl.c
  lib/fcntl.in.h
  lib/fd-hook.c
  lib/fd-hook.h
  lib/fd-safer-flag.c
  lib/fd-safer.c
  lib/filename.h
  lib/fstat.c
  lib/ftruncate.c
  lib/full-read.c
  lib/full-read.h
  lib/full-write.c
  lib/full-write.h
  lib/getdtablesize.c
  lib/idx.h
  lib/intprops-internal.h
  lib/limits.in.h
  lib/malloca.c
  lib/malloca.h
  lib/mkfifo.c
  lib/msvc-inval.c
  lib/msvc-inval.h
  lib/msvc-nothrow.c
  lib/msvc-nothrow.h
  lib/open.c
  lib/passfd.c
  lib/passfd.h
  lib/pathmax.h
  lib/pipe-safer.c
  lib/pipe.c
  lib/pipe2-safer.c
  lib/pipe2.c
  lib/raise.c
  lib/read.c
  lib/safe-read.c
  lib/safe-read.h
  lib/safe-write.c
  lib/safe-write.h
  lib/signal.in.h
  lib/socket.c
  lib/sockets.c
  lib/sockets.h
  lib/stat-time.c
  lib/stat-time.h
  lib/stat-w32.c
  lib/stat-w32.h
  lib/stat.c
  lib/stdckdint.in.h
  lib/stddef.in.h
  lib/stdint.in.h
  lib/sys-limits.h
  lib/sys_socket.c
  lib/sys_socket.in.h
  lib/sys_stat.in.h
  lib/sys_types.in.h
  lib/sys_uio.in.h
  lib/time.in.h
  lib/unistd--.h
  lib/unistd-safer.h
  lib/unistd.c
  lib/unistd.in.h
  lib/verify.h
  lib/w32sock.h
  lib/warn-on-use.h
  lib/write.c
  lib/xalloc-oversized.h
  m4/00gnulib.m4
  m4/absolute-header.m4
  m4/alloca.m4
  m4/assert_h.m4
  m4/c-bool.m4
  m4/close.m4
  m4/dup2.m4
  m4/eealloc.m4
  m4/errno_h.m4
  m4/extensions.m4
  m4/extern-inline.m4
  m4/fcntl-o.m4
  m4/fcntl.m4
  m4/fcntl_h.m4
  m4/fstat.m4
  m4/ftruncate.m4
  m4/getdtablesize.m4
  m4/gnulib-common.m4
  m4/include_next.m4
  m4/largefile.m4
  m4/limits-h.m4
  m4/malloca.m4
  m4/mkfifo.m4
  m4/mode_t.m4
  m4/msvc-inval.m4
  m4/msvc-nothrow.m4
  m4/multiarch.m4
  m4/off64_t.m4
  m4/off_t.m4
  m4/open-cloexec.m4
  m4/open-slash.m4
  m4/open.m4
  m4/passfd.m4
  m4/pathmax.m4
  m4/pid_t.m4
  m4/pipe.m4
  m4/pipe2.m4
  m4/raise.m4
  m4/read.m4
  m4/safe-read.m4
  m4/safe-write.m4
  m4/signal_h.m4
  m4/socketlib.m4
  m4/sockets.m4
  m4/socklen.m4
  m4/sockpfaf.m4
  m4/ssize_t.m4
  m4/stat-time.m4
  m4/stat.m4
  m4/std-gnu11.m4
  m4/stdalign.m4
  m4/stddef_h.m4
  m4/stdint.m4
  m4/sys_socket_h.m4
  m4/sys_stat_h.m4
  m4/sys_types_h.m4
  m4/sys_uio_h.m4
  m4/time_h.m4
  m4/unistd-safer.m4
  m4/unistd_h.m4
  m4/warn-on-use.m4
  m4/wint_t.m4
  m4/write.m4
  m4/zzgnulib.m4
Removing file m4/wchar_t.m4 (backup in m4/wchar_t.m4~)
Copying file lib/ftruncate.c
Copying file lib/passfd.c
Copying file lib/passfd.h
Copying file m4/ftruncate.m4
Copying file m4/off64_t.m4
Copying file m4/passfd.m4
Updating file lib/fcntl.in.h (backup in lib/fcntl.in.h~)
Updating file lib/intprops-internal.h (backup in lib/intprops-internal.h~)
Updating file lib/stddef.in.h (backup in lib/stddef.in.h~)
Updating file lib/stdint.in.h (backup in lib/stdint.in.h~)
Updating file lib/sys_types.in.h (backup in lib/sys_types.in.h~)
Updating file lib/time.in.h (backup in lib/time.in.h~)
Updating file lib/unistd.in.h (backup in lib/unistd.in.h~)
Updating file lib/verify.h (backup in lib/verify.h~)
Updating file m4/extensions.m4 (backup in m4/extensions.m4~)
Updating file m4/gnulib-common.m4 (backup in m4/gnulib-common.m4~)
Updating file m4/largefile.m4 (backup in m4/largefile.m4~)
Updating file m4/stdalign.m4 (backup in m4/stdalign.m4~)
Updating file m4/stddef_h.m4 (backup in m4/stddef_h.m4~)
Updating file m4/sys_types_h.m4 (backup in m4/sys_types_h.m4~)
Updating file m4/time_h.m4 (backup in m4/time_h.m4~)
Updating file m4/unistd_h.m4 (backup in m4/unistd_h.m4~)
Updating m4/gnulib-cache.m4 (backup in m4/gnulib-cache.m4~)
Updating m4/gnulib-comp.m4 (backup in m4/gnulib-comp.m4~)
Updating lib/Makefile.am (backup in lib/Makefile.am~)
Finished.

You may need to add #include directives for the following .h files.
  #include <fcntl.h>
  #include <sys/socket.h>
  #include <sys/stat.h>
  #include <unistd.h>
  #include "full-read.h"
  #include "full-write.h"
  #include "passfd.h"
  #include "unistd-safer.h"

You may need to use the following Makefile variables when linking.
Use them in <program>_LDADD when linking a program, or
in <library>_a_LDFLAGS or <library>_la_LDFLAGS when linking a library.
  $(LIBSOCKET)

Don't forget to
  - add "lib/Makefile" to AC_CONFIG_FILES in ./configure.ac,
  - mention "lib" in SUBDIRS in Makefile.am,
  - mention "-I m4" in ACLOCAL_AMFLAGS in Makefile.am
    or add an AC_CONFIG_MACRO_DIRS([m4]) invocation in ./configure.ac,
  - mention "m4/gnulib-cache.m4" in EXTRA_DIST in Makefile.am,
  - invoke gl_EARLY in ./configure.ac, right after AC_PROG_CC,
  - invoke gl_INIT in ./configure.ac.
```

# Importing resto of the modules #3

```
Module list with included dependencies (indented):
    absolute-header
    access
    alignasof
    alloca-opt
    assert-h
    assure
    at-internal
    attribute
    basename-lgpl
    binary-io
    bitrotate
    builtin-expect
    c99
    calloc-gnu
    calloc-posix
    canonicalize
    chdir
    chdir-long
    cloexec
  close
    closedir
    concat-filename
  connect
    d-ino
    dirent
    dirfd
    double-slash-root
    dup
    dup2
    environ
    errno
    error
    error-h
    exitfail
    extensions
    extensions-aix
    extern-inline
    fatal-signal
    fchdir
    fcntl
    fcntl-h
    fd-hook
    fd-safer-flag
    fdopendir
    file-set
    filename
    filenamecat-lgpl
    findprog-in
    free-posix
    fstat
    fstatat
  ftruncate
  full-read
  full-write
    gen-header
    getcwd
    getcwd-lgpl
    getdtablesize
    getprogname
    gettext-h
    glibc-internal/scratch_buffer
    hash
    hash-pjw
    hash-triple-simple
    ialloc
    idx
    include_next
    intprops
    inttypes-incomplete
    largefile
    libc-config
    limits-h
    lock
    lstat
    malloc-gnu
    malloc-posix
    malloca
    memchr
    mempcpy
    memrchr
    minmax
  mkfifo
    msvc-inval
    msvc-nothrow
    multiarch
    nocrash
    once
  open
    openat
    openat-die
    openat-h
    opendir
  passfd
    pathmax
  pipe-filter-ii
    pipe-posix
    pipe2
  pipe2-safer
    posix_spawn
    posix_spawn-internal
    posix_spawn_file_actions_addchdir
    posix_spawn_file_actions_addclose
    posix_spawn_file_actions_adddup2
    posix_spawn_file_actions_addopen
    posix_spawn_file_actions_destroy
    posix_spawn_file_actions_init
    posix_spawnattr_destroy
    posix_spawnattr_init
    posix_spawnattr_setflags
    posix_spawnattr_setpgroup
    posix_spawnattr_setsigmask
    posix_spawnp
    pthread-h
    pthread-once
    raise
    rawmemchr
    read
    readdir
    readlink
    realloc-gnu
    realloc-posix
    reallocarray
    rewinddir
    safe-read
    safe-write
    same-inode
    save-cwd
    sched
    sh-filename
    sigaction
    signal-h
    sigprocmask
    snippet/_Noreturn
    snippet/arg-nonnull
    snippet/c++defs
    snippet/warn-on-use
  socket
    socketlib
    sockets
    socklen
    spawn
    spawn-pipe
    ssize_t
    stat
    stat-time
    std-gnu11
    stdbool
    stdckdint
    stddef
    stdint
    stdio
    stdlib
    stpcpy
    strchrnul
    strdup-posix
    strerror
    strerror-override
    string
    sys_select
    sys_socket
    sys_stat
    sys_time
    sys_types
    sys_uio
    sys_wait
    thread-optim
    threadlib
    time-h
    unistd
    unistd-safer
    vararrays
    verify
    wait-process
    waitpid
    wchar
    windows-mutex
    windows-once
    windows-recmutex
    windows-rwlock
    windows-spawn
    write
    xalloc
    xalloc-die
    xalloc-oversized
File list:
  lib/_Noreturn.h
  lib/access.c
  lib/alloca.in.h
  lib/arg-nonnull.h
  lib/assert.in.h
  lib/assure.h
  lib/at-func.c
  lib/attribute.h
  lib/basename-lgpl.c
  lib/basename-lgpl.h
  lib/binary-io.c
  lib/binary-io.h
  lib/bitrotate.c
  lib/bitrotate.h
  lib/c++defs.h
  lib/calloc.c
  lib/canonicalize.c
  lib/canonicalize.h
  lib/cdefs.h
  lib/chdir-long.c
  lib/chdir-long.h
  lib/cloexec.c
  lib/cloexec.h
  lib/close.c
  lib/closedir.c
  lib/concat-filename.c
  lib/concat-filename.h
  lib/connect.c
  lib/dirent-private.h
  lib/dirent.in.h
  lib/dirfd.c
  lib/dup-safer-flag.c
  lib/dup-safer.c
  lib/dup.c
  lib/dup2.c
  lib/errno.in.h
  lib/error.c
  lib/error.in.h
  lib/exitfail.c
  lib/exitfail.h
  lib/fatal-signal.c
  lib/fatal-signal.h
  lib/fchdir.c
  lib/fcntl.c
  lib/fcntl.in.h
  lib/fd-hook.c
  lib/fd-hook.h
  lib/fd-safer-flag.c
  lib/fd-safer.c
  lib/fdopendir.c
  lib/file-set.c
  lib/file-set.h
  lib/filename.h
  lib/filenamecat-lgpl.c
  lib/filenamecat.h
  lib/findprog-in.c
  lib/findprog.h
  lib/free.c
  lib/fstat.c
  lib/fstatat.c
  lib/ftruncate.c
  lib/full-read.c
  lib/full-read.h
  lib/full-write.c
  lib/full-write.h
  lib/getcwd-lgpl.c
  lib/getcwd.c
  lib/getdtablesize.c
  lib/getprogname.c
  lib/getprogname.h
  lib/gettext.h
  lib/glthread/lock.c
  lib/glthread/lock.h
  lib/glthread/once.c
  lib/glthread/once.h
  lib/glthread/threadlib.c
  lib/hash-pjw.c
  lib/hash-pjw.h
  lib/hash-triple-simple.c
  lib/hash-triple.h
  lib/hash.c
  lib/hash.h
  lib/ialloc.c
  lib/ialloc.h
  lib/idx.h
  lib/intprops-internal.h
  lib/intprops.h
  lib/inttypes.in.h
  lib/libc-config.h
  lib/limits.in.h
  lib/lstat.c
  lib/malloc.c
  lib/malloc/scratch_buffer.h
  lib/malloc/scratch_buffer_grow.c
  lib/malloc/scratch_buffer_grow_preserve.c
  lib/malloc/scratch_buffer_set_array_size.c
  lib/malloca.c
  lib/malloca.h
  lib/memchr.c
  lib/memchr.valgrind
  lib/mempcpy.c
  lib/memrchr.c
  lib/minmax.h
  lib/mkfifo.c
  lib/msvc-inval.c
  lib/msvc-inval.h
  lib/msvc-nothrow.c
  lib/msvc-nothrow.h
  lib/open.c
  lib/openat-die.c
  lib/openat-priv.h
  lib/openat-proc.c
  lib/openat.c
  lib/openat.h
  lib/opendir.c
  lib/os2-spawn.c
  lib/os2-spawn.h
  lib/passfd.c
  lib/passfd.h
  lib/pathmax.h
  lib/pipe-filter-aux.c
  lib/pipe-filter-aux.h
  lib/pipe-filter-ii.c
  lib/pipe-filter.h
  lib/pipe-safer.c
  lib/pipe.c
  lib/pipe2-safer.c
  lib/pipe2.c
  lib/pthread-once.c
  lib/pthread.in.h
  lib/raise.c
  lib/rawmemchr.c
  lib/rawmemchr.valgrind
  lib/read.c
  lib/readdir.c
  lib/readlink.c
  lib/realloc.c
  lib/reallocarray.c
  lib/rewinddir.c
  lib/safe-read.c
  lib/safe-read.h
  lib/safe-write.c
  lib/safe-write.h
  lib/same-inode.c
  lib/same-inode.h
  lib/save-cwd.c
  lib/save-cwd.h
  lib/sched.in.h
  lib/scratch_buffer.h
  lib/sig-handler.c
  lib/sig-handler.h
  lib/sigaction.c
  lib/signal.in.h
  lib/sigprocmask.c
  lib/socket.c
  lib/sockets.c
  lib/sockets.h
  lib/spawn-pipe.c
  lib/spawn-pipe.h
  lib/spawn.c
  lib/spawn.in.h
  lib/spawn_faction_addchdir.c
  lib/spawn_faction_addclose.c
  lib/spawn_faction_adddup2.c
  lib/spawn_faction_addopen.c
  lib/spawn_faction_destroy.c
  lib/spawn_faction_init.c
  lib/spawn_int.h
  lib/spawnattr_destroy.c
  lib/spawnattr_init.c
  lib/spawnattr_setflags.c
  lib/spawnattr_setpgroup.c
  lib/spawnattr_setsigmask.c
  lib/spawni.c
  lib/spawnp.c
  lib/stat-time.c
  lib/stat-time.h
  lib/stat-w32.c
  lib/stat-w32.h
  lib/stat.c
  lib/stdckdint.in.h
  lib/stddef.in.h
  lib/stdint.in.h
  lib/stdio-read.c
  lib/stdio-write.c
  lib/stdio.in.h
  lib/stdlib.in.h
  lib/stpcpy.c
  lib/strchrnul.c
  lib/strchrnul.valgrind
  lib/strdup.c
  lib/strerror-override.c
  lib/strerror-override.h
  lib/strerror.c
  lib/string.in.h
  lib/sys-limits.h
  lib/sys_select.in.h
  lib/sys_socket.c
  lib/sys_socket.in.h
  lib/sys_stat.in.h
  lib/sys_time.in.h
  lib/sys_types.in.h
  lib/sys_uio.in.h
  lib/sys_wait.in.h
  lib/thread-optim.h
  lib/time.in.h
  lib/unistd--.h
  lib/unistd-safer.h
  lib/unistd.c
  lib/unistd.in.h
  lib/verify.h
  lib/w32sock.h
  lib/wait-process.c
  lib/wait-process.h
  lib/waitpid.c
  lib/warn-on-use.h
  lib/wchar.in.h
  lib/windows-initguard.h
  lib/windows-mutex.c
  lib/windows-mutex.h
  lib/windows-once.c
  lib/windows-once.h
  lib/windows-path.c
  lib/windows-path.h
  lib/windows-recmutex.c
  lib/windows-recmutex.h
  lib/windows-rwlock.c
  lib/windows-rwlock.h
  lib/windows-spawn.c
  lib/windows-spawn.h
  lib/write.c
  lib/xalloc-die.c
  lib/xalloc-oversized.h
  lib/xalloc.h
  lib/xmalloc.c
  m4/00gnulib.m4
  m4/__inline.m4
  m4/absolute-header.m4
  m4/access.m4
  m4/alloca.m4
  m4/assert_h.m4
  m4/builtin-expect.m4
  m4/c-bool.m4
  m4/calloc.m4
  m4/canonicalize.m4
  m4/chdir-long.m4
  m4/close.m4
  m4/closedir.m4
  m4/codeset.m4
  m4/d-ino.m4
  m4/dirent_h.m4
  m4/dirfd.m4
  m4/double-slash-root.m4
  m4/dup.m4
  m4/dup2.m4
  m4/eaccess.m4
  m4/eealloc.m4
  m4/environ.m4
  m4/errno_h.m4
  m4/error.m4
  m4/error_h.m4
  m4/extensions-aix.m4
  m4/extensions.m4
  m4/extern-inline.m4
  m4/fatal-signal.m4
  m4/fchdir.m4
  m4/fcntl-o.m4
  m4/fcntl.m4
  m4/fcntl_h.m4
  m4/fdopendir.m4
  m4/filenamecat.m4
  m4/findprog-in.m4
  m4/free.m4
  m4/fstat.m4
  m4/fstatat.m4
  m4/ftruncate.m4
  m4/getcwd-abort-bug.m4
  m4/getcwd-path-max.m4
  m4/getcwd.m4
  m4/getdtablesize.m4
  m4/getprogname.m4
  m4/gnulib-common.m4
  m4/include_next.m4
  m4/inttypes.m4
  m4/largefile.m4
  m4/limits-h.m4
  m4/locale-en.m4
  m4/lock.m4
  m4/lstat.m4
  m4/malloc.m4
  m4/malloca.m4
  m4/memchr.m4
  m4/mempcpy.m4
  m4/memrchr.m4
  m4/minmax.m4
  m4/mkfifo.m4
  m4/mmap-anon.m4
  m4/mode_t.m4
  m4/msvc-inval.m4
  m4/msvc-nothrow.m4
  m4/multiarch.m4
  m4/musl.m4
  m4/nocrash.m4
  m4/off64_t.m4
  m4/off_t.m4
  m4/once.m4
  m4/open-cloexec.m4
  m4/open-slash.m4
  m4/open.m4
  m4/openat.m4
  m4/opendir.m4
  m4/passfd.m4
  m4/pathmax.m4
  m4/pid_t.m4
  m4/pipe.m4
  m4/pipe2.m4
  m4/posix_spawn.m4
  m4/posix_spawn_faction_addchdir.m4
  m4/pthread-once.m4
  m4/pthread-spin.m4
  m4/pthread_h.m4
  m4/pthread_rwlock_rdlock.m4
  m4/raise.m4
  m4/rawmemchr.m4
  m4/read.m4
  m4/readdir.m4
  m4/readlink.m4
  m4/realloc.m4
  m4/reallocarray.m4
  m4/rewinddir.m4
  m4/safe-read.m4
  m4/safe-write.m4
  m4/save-cwd.m4
  m4/sched_h.m4
  m4/sh-filename.m4
  m4/sig_atomic_t.m4
  m4/sigaction.m4
  m4/signal_h.m4
  m4/signalblocking.m4
  m4/socketlib.m4
  m4/sockets.m4
  m4/socklen.m4
  m4/sockpfaf.m4
  m4/spawn-pipe.m4
  m4/spawn_h.m4
  m4/ssize_t.m4
  m4/stat-time.m4
  m4/stat.m4
  m4/std-gnu11.m4
  m4/stdalign.m4
  m4/stddef_h.m4
  m4/stdint.m4
  m4/stdio_h.m4
  m4/stdlib_h.m4
  m4/stpcpy.m4
  m4/strchrnul.m4
  m4/strdup.m4
  m4/strerror.m4
  m4/string_h.m4
  m4/sys_cdefs_h.m4
  m4/sys_select_h.m4
  m4/sys_socket_h.m4
  m4/sys_stat_h.m4
  m4/sys_time_h.m4
  m4/sys_types_h.m4
  m4/sys_uio_h.m4
  m4/sys_wait_h.m4
  m4/threadlib.m4
  m4/time_h.m4
  m4/unistd-safer.m4
  m4/unistd_h.m4
  m4/vararrays.m4
  m4/wait-process.m4
  m4/waitpid.m4
  m4/warn-on-use.m4
  m4/wchar_h.m4
  m4/wint_t.m4
  m4/write.m4
  m4/xalloc.m4
  m4/zzgnulib.m4
Creating directory ./lib/glthread
Creating directory ./lib/malloc
Copying file lib/_Noreturn.h
Copying file lib/access.c
Copying file lib/assure.h
Copying file lib/at-func.c
Copying file lib/attribute.h
Copying file lib/basename-lgpl.c
Copying file lib/basename-lgpl.h
Copying file lib/bitrotate.c
Copying file lib/bitrotate.h
Copying file lib/calloc.c
Copying file lib/canonicalize.c
Copying file lib/canonicalize.h
Copying file lib/cdefs.h
Copying file lib/chdir-long.c
Copying file lib/chdir-long.h
Copying file lib/closedir.c
Copying file lib/concat-filename.c
Copying file lib/concat-filename.h
Copying file lib/dirent-private.h
Copying file lib/dirent.in.h
Copying file lib/dirfd.c
Copying file lib/dup.c
Copying file lib/error.c
Copying file lib/error.in.h
Copying file lib/exitfail.c
Copying file lib/exitfail.h
Copying file lib/fatal-signal.c
Copying file lib/fatal-signal.h
Copying file lib/fchdir.c
Copying file lib/fdopendir.c
Copying file lib/file-set.c
Copying file lib/file-set.h
Copying file lib/filenamecat-lgpl.c
Copying file lib/filenamecat.h
Copying file lib/findprog-in.c
Copying file lib/findprog.h
Copying file lib/free.c
Copying file lib/fstatat.c
Copying file lib/getcwd-lgpl.c
Copying file lib/getcwd.c
Copying file lib/getprogname.c
Copying file lib/getprogname.h
Copying file lib/gettext.h
Copying file lib/glthread/lock.c
Copying file lib/glthread/lock.h
Copying file lib/glthread/once.c
Copying file lib/glthread/once.h
Copying file lib/glthread/threadlib.c
Copying file lib/hash-pjw.c
Copying file lib/hash-pjw.h
Copying file lib/hash-triple-simple.c
Copying file lib/hash-triple.h
Copying file lib/hash.c
Copying file lib/hash.h
Copying file lib/ialloc.c
Copying file lib/ialloc.h
Copying file lib/intprops.h
Copying file lib/inttypes.in.h
Copying file lib/libc-config.h
Copying file lib/lstat.c
Copying file lib/malloc.c
Copying file lib/malloc/scratch_buffer.h
Copying file lib/malloc/scratch_buffer_grow.c
Copying file lib/malloc/scratch_buffer_grow_preserve.c
Copying file lib/malloc/scratch_buffer_set_array_size.c
Copying file lib/memchr.c
Copying file lib/memchr.valgrind
Copying file lib/mempcpy.c
Copying file lib/memrchr.c
Copying file lib/minmax.h
Copying file lib/openat-die.c
Copying file lib/openat-priv.h
Copying file lib/openat-proc.c
Copying file lib/openat.c
Copying file lib/openat.h
Copying file lib/opendir.c
Copying file lib/os2-spawn.c
Copying file lib/os2-spawn.h
Copying file lib/pipe-filter-aux.c
Copying file lib/pipe-filter-aux.h
Copying file lib/pipe-filter-ii.c
Copying file lib/pipe-filter.h
Copying file lib/pthread-once.c
Copying file lib/pthread.in.h
Copying file lib/rawmemchr.c
Copying file lib/rawmemchr.valgrind
Copying file lib/readdir.c
Copying file lib/readlink.c
Copying file lib/realloc.c
Copying file lib/reallocarray.c
Copying file lib/rewinddir.c
Copying file lib/same-inode.c
Copying file lib/same-inode.h
Copying file lib/save-cwd.c
Copying file lib/save-cwd.h
Copying file lib/sched.in.h
Copying file lib/scratch_buffer.h
Copying file lib/sig-handler.c
Copying file lib/sig-handler.h
Copying file lib/sigaction.c
Copying file lib/sigprocmask.c
Copying file lib/spawn-pipe.c
Copying file lib/spawn-pipe.h
Copying file lib/spawn.c
Copying file lib/spawn.in.h
Copying file lib/spawn_faction_addchdir.c
Copying file lib/spawn_faction_addclose.c
Copying file lib/spawn_faction_adddup2.c
Copying file lib/spawn_faction_addopen.c
Copying file lib/spawn_faction_destroy.c
Copying file lib/spawn_faction_init.c
Copying file lib/spawn_int.h
Copying file lib/spawnattr_destroy.c
Copying file lib/spawnattr_init.c
Copying file lib/spawnattr_setflags.c
Copying file lib/spawnattr_setpgroup.c
Copying file lib/spawnattr_setsigmask.c
Copying file lib/spawni.c
Copying file lib/spawnp.c
Copying file lib/stdio-read.c
Copying file lib/stdio-write.c
Copying file lib/stdio.in.h
Copying file lib/stdlib.in.h
Copying file lib/stpcpy.c
Copying file lib/strchrnul.c
Copying file lib/strchrnul.valgrind
Copying file lib/strdup.c
Copying file lib/strerror-override.c
Copying file lib/strerror-override.h
Copying file lib/strerror.c
Copying file lib/string.in.h
Copying file lib/sys_select.in.h
Copying file lib/sys_time.in.h
Copying file lib/sys_wait.in.h
Copying file lib/thread-optim.h
Copying file lib/wait-process.c
Copying file lib/wait-process.h
Copying file lib/waitpid.c
Copying file lib/wchar.in.h
Copying file lib/windows-initguard.h
Copying file lib/windows-mutex.c
Copying file lib/windows-mutex.h
Copying file lib/windows-once.c
Copying file lib/windows-once.h
Copying file lib/windows-path.c
Copying file lib/windows-path.h
Copying file lib/windows-recmutex.c
Copying file lib/windows-recmutex.h
Copying file lib/windows-rwlock.c
Copying file lib/windows-rwlock.h
Copying file lib/windows-spawn.c
Copying file lib/windows-spawn.h
Copying file lib/xalloc-die.c
Copying file lib/xalloc.h
Copying file lib/xmalloc.c
Copying file m4/__inline.m4
Copying file m4/access.m4
Copying file m4/builtin-expect.m4
Copying file m4/calloc.m4
Copying file m4/canonicalize.m4
Copying file m4/chdir-long.m4
Copying file m4/closedir.m4
Copying file m4/codeset.m4
Copying file m4/d-ino.m4
Copying file m4/dirent_h.m4
Copying file m4/dirfd.m4
Copying file m4/double-slash-root.m4
Copying file m4/dup.m4
Copying file m4/eaccess.m4
Copying file m4/environ.m4
Copying file m4/error.m4
Copying file m4/error_h.m4
Copying file m4/extensions-aix.m4
Copying file m4/fatal-signal.m4
Copying file m4/fchdir.m4
Copying file m4/fdopendir.m4
Copying file m4/filenamecat.m4
Copying file m4/findprog-in.m4
Copying file m4/free.m4
Copying file m4/fstatat.m4
Copying file m4/getcwd-abort-bug.m4
Copying file m4/getcwd-path-max.m4
Copying file m4/getcwd.m4
Copying file m4/getprogname.m4
Copying file m4/inttypes.m4
Copying file m4/locale-en.m4
Copying file m4/lock.m4
Copying file m4/lstat.m4
Copying file m4/malloc.m4
Copying file m4/memchr.m4
Copying file m4/mempcpy.m4
Copying file m4/memrchr.m4
Copying file m4/minmax.m4
Copying file m4/mmap-anon.m4
Copying file m4/musl.m4
Copying file m4/nocrash.m4
Copying file m4/once.m4
Copying file m4/openat.m4
Copying file m4/opendir.m4
Copying file m4/posix_spawn.m4
Copying file m4/posix_spawn_faction_addchdir.m4
Copying file m4/pthread-once.m4
Copying file m4/pthread-spin.m4
Copying file m4/pthread_h.m4
Copying file m4/pthread_rwlock_rdlock.m4
Copying file m4/rawmemchr.m4
Copying file m4/readdir.m4
Copying file m4/readlink.m4
Copying file m4/realloc.m4
Copying file m4/reallocarray.m4
Copying file m4/rewinddir.m4
Copying file m4/save-cwd.m4
Copying file m4/sched_h.m4
Copying file m4/sh-filename.m4
Copying file m4/sig_atomic_t.m4
Copying file m4/sigaction.m4
Copying file m4/signalblocking.m4
Copying file m4/spawn-pipe.m4
Copying file m4/spawn_h.m4
Copying file m4/stdio_h.m4
Copying file m4/stdlib_h.m4
Copying file m4/stpcpy.m4
Copying file m4/strchrnul.m4
Copying file m4/strdup.m4
Copying file m4/strerror.m4
Copying file m4/string_h.m4
Copying file m4/sys_cdefs_h.m4
Copying file m4/sys_select_h.m4
Copying file m4/sys_time_h.m4
Copying file m4/sys_wait_h.m4
Copying file m4/threadlib.m4
Copying file m4/vararrays.m4
Copying file m4/wait-process.m4
Copying file m4/waitpid.m4
Copying file m4/wchar_h.m4
Copying file m4/xalloc.m4
Updating file lib/c++defs.h (backup in lib/c++defs.h~)
Updating file lib/errno.in.h (backup in lib/errno.in.h~)
Updating file lib/fcntl.in.h (backup in lib/fcntl.in.h~)
Updating file lib/full-read.h (backup in lib/full-read.h~)
Updating file lib/full-write.c (backup in lib/full-write.c~)
Updating file lib/full-write.h (backup in lib/full-write.h~)
Updating file lib/intprops-internal.h (backup in lib/intprops-internal.h~)
Updating file lib/safe-read.c (backup in lib/safe-read.c~)
Updating file lib/safe-read.h (backup in lib/safe-read.h~)
Updating file lib/safe-write.h (backup in lib/safe-write.h~)
Updating file lib/signal.in.h (backup in lib/signal.in.h~)
Updating file lib/stddef.in.h (backup in lib/stddef.in.h~)
Updating file lib/sys_socket.in.h (backup in lib/sys_socket.in.h~)
Updating file lib/sys_stat.in.h (backup in lib/sys_stat.in.h~)
Updating file lib/time.in.h (backup in lib/time.in.h~)
Updating file lib/unistd.in.h (backup in lib/unistd.in.h~)
Updating file lib/verify.h (backup in lib/verify.h~)
Updating file lib/warn-on-use.h (backup in lib/warn-on-use.h~)
Updating file lib/xalloc-oversized.h (backup in lib/xalloc-oversized.h~)
Updating file m4/00gnulib.m4 (backup in m4/00gnulib.m4~)
Updating file m4/absolute-header.m4 (backup in m4/absolute-header.m4~)
Updating file m4/alloca.m4 (backup in m4/alloca.m4~)
Updating file m4/assert_h.m4 (backup in m4/assert_h.m4~)
Updating file m4/c-bool.m4 (backup in m4/c-bool.m4~)
Updating file m4/close.m4 (backup in m4/close.m4~)
Updating file m4/dup2.m4 (backup in m4/dup2.m4~)
Updating file m4/eealloc.m4 (backup in m4/eealloc.m4~)
Updating file m4/errno_h.m4 (backup in m4/errno_h.m4~)
Updating file m4/extensions.m4 (backup in m4/extensions.m4~)
Updating file m4/extern-inline.m4 (backup in m4/extern-inline.m4~)
Updating file m4/fcntl-o.m4 (backup in m4/fcntl-o.m4~)
Updating file m4/fcntl.m4 (backup in m4/fcntl.m4~)
Updating file m4/fcntl_h.m4 (backup in m4/fcntl_h.m4~)
Updating file m4/fstat.m4 (backup in m4/fstat.m4~)
Updating file m4/ftruncate.m4 (backup in m4/ftruncate.m4~)
Updating file m4/getdtablesize.m4 (backup in m4/getdtablesize.m4~)
Updating file m4/gnulib-common.m4 (backup in m4/gnulib-common.m4~)
Updating file m4/gnulib-tool.m4 (backup in m4/gnulib-tool.m4~)
Updating file m4/include_next.m4 (backup in m4/include_next.m4~)
Updating file m4/largefile.m4 (backup in m4/largefile.m4~)
Updating file m4/limits-h.m4 (backup in m4/limits-h.m4~)
Updating file m4/malloca.m4 (backup in m4/malloca.m4~)
Updating file m4/mkfifo.m4 (backup in m4/mkfifo.m4~)
Updating file m4/mode_t.m4 (backup in m4/mode_t.m4~)
Updating file m4/msvc-inval.m4 (backup in m4/msvc-inval.m4~)
Updating file m4/msvc-nothrow.m4 (backup in m4/msvc-nothrow.m4~)
Updating file m4/multiarch.m4 (backup in m4/multiarch.m4~)
Updating file m4/off64_t.m4 (backup in m4/off64_t.m4~)
Updating file m4/off_t.m4 (backup in m4/off_t.m4~)
Updating file m4/open-cloexec.m4 (backup in m4/open-cloexec.m4~)
Updating file m4/open-slash.m4 (backup in m4/open-slash.m4~)
Updating file m4/open.m4 (backup in m4/open.m4~)
Updating file m4/passfd.m4 (backup in m4/passfd.m4~)
Updating file m4/pathmax.m4 (backup in m4/pathmax.m4~)
Updating file m4/pid_t.m4 (backup in m4/pid_t.m4~)
Updating file m4/pipe.m4 (backup in m4/pipe.m4~)
Updating file m4/pipe2.m4 (backup in m4/pipe2.m4~)
Updating file m4/raise.m4 (backup in m4/raise.m4~)
Updating file m4/read.m4 (backup in m4/read.m4~)
Updating file m4/safe-read.m4 (backup in m4/safe-read.m4~)
Updating file m4/safe-write.m4 (backup in m4/safe-write.m4~)
Updating file m4/signal_h.m4 (backup in m4/signal_h.m4~)
Updating file m4/socketlib.m4 (backup in m4/socketlib.m4~)
Updating file m4/sockets.m4 (backup in m4/sockets.m4~)
Updating file m4/socklen.m4 (backup in m4/socklen.m4~)
Updating file m4/sockpfaf.m4 (backup in m4/sockpfaf.m4~)
Updating file m4/ssize_t.m4 (backup in m4/ssize_t.m4~)
Updating file m4/stat-time.m4 (backup in m4/stat-time.m4~)
Updating file m4/stat.m4 (backup in m4/stat.m4~)
Updating file m4/std-gnu11.m4 (backup in m4/std-gnu11.m4~)
Updating file m4/stdalign.m4 (backup in m4/stdalign.m4~)
Updating file m4/stddef_h.m4 (backup in m4/stddef_h.m4~)
Updating file m4/stdint.m4 (backup in m4/stdint.m4~)
Updating file m4/sys_socket_h.m4 (backup in m4/sys_socket_h.m4~)
Updating file m4/sys_stat_h.m4 (backup in m4/sys_stat_h.m4~)
Updating file m4/sys_types_h.m4 (backup in m4/sys_types_h.m4~)
Updating file m4/sys_uio_h.m4 (backup in m4/sys_uio_h.m4~)
Updating file m4/time_h.m4 (backup in m4/time_h.m4~)
Updating file m4/unistd-safer.m4 (backup in m4/unistd-safer.m4~)
Updating file m4/unistd_h.m4 (backup in m4/unistd_h.m4~)
Updating file m4/warn-on-use.m4 (backup in m4/warn-on-use.m4~)
Updating file m4/wint_t.m4 (backup in m4/wint_t.m4~)
Updating file m4/write.m4 (backup in m4/write.m4~)
Updating file m4/zzgnulib.m4 (backup in m4/zzgnulib.m4~)
Updating m4/gnulib-cache.m4 (backup in m4/gnulib-cache.m4~)
Updating m4/gnulib-comp.m4 (backup in m4/gnulib-comp.m4~)
Updating lib/Makefile.am (backup in lib/Makefile.am~)
Finished.

You may need to add #include directives for the following .h files.
  #include <fcntl.h>
  #include <sys/socket.h>
  #include <sys/stat.h>
  #include <unistd.h>
  #include "full-read.h"
  #include "full-write.h"
  #include "passfd.h"
  #include "pipe-filter.h"
  #include "unistd-safer.h"

You may need to use the following Makefile variables when linking.
Use them in <program>_LDADD when linking a program, or
in <library>_a_LDFLAGS or <library>_la_LDFLAGS when linking a library.
  $(LIBPMULTITHREAD)
  $(LIBPTHREAD)
  $(LIBSOCKET)
  $(LIBTHREAD)
  $(LTLIBINTL) when linking with libtool, $(LIBINTL) otherwise
  $(POSIX_SPAWN_LIB)

Don't forget to
  - add "lib/Makefile" to AC_CONFIG_FILES in ./configure.ac,
  - mention "lib" in SUBDIRS in Makefile.am,
  - mention "-I m4" in ACLOCAL_AMFLAGS in Makefile.am
    or add an AC_CONFIG_MACRO_DIRS([m4]) invocation in ./configure.ac,
  - mention "m4/gnulib-cache.m4" in EXTRA_DIST in Makefile.am,
  - invoke gl_EARLY in ./configure.ac, right after AC_PROG_CC,
  - invoke gl_INIT in ./configure.ac.
```
