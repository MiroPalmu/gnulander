# Importing rest of documented modules #5

```
=> ~/data/scratch/repos/gnulib/gnulib-tool --add-import sys_un-h
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
    bool
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
    dirent-h
    dirfd
    double-slash-root
    dup
    dup2
    environ
    errno-h
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
    gnulib-i18n
    hash
    hash-pjw
    hash-triple-simple
    ialloc
    idx
    include_next
    intprops
    inttypes-h-incomplete
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
  pipe-filter-gi
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
    realloc-posix
    reallocarray
    rewinddir
    safe-read
    safe-write
    same-inode
    save-cwd
    sched-h
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
    spawn-h
    spawn-pipe
    ssize_t
    stat
    stat-time
    std-gnu11
    stdckdint-h
    stddef-h
    stdint-h
    stdio-h
    stdlib-h
    stpcpy
    strchrnul
    strdup-posix
    strerror
    strerror-override
    string-h
    sys_select-h
    sys_socket-h
    sys_stat-h
    sys_time-h
    sys_types-h
    sys_uio-h
  sys_un-h
    sys_wait-h
    thread-optim
    threadlib
    time-h
    unistd-h
    unistd-safer
    vararrays
    verify
    wait-process
    waitpid
    wchar-h
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
  lib/pipe-filter-gi.c
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
  lib/stdlib.c
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
  lib/sys_un.in.h
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
  m4/build-to-host.m4
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
  m4/gnulib-i18n.m4
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
  m4/sys_un_h.m4
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
Removing file m4/eealloc.m4 (backup in m4/eealloc.m4~)
Copying file lib/stdlib.c
Copying file lib/sys_un.in.h
Copying file m4/build-to-host.m4
Copying file m4/gnulib-i18n.m4
Copying file m4/sys_un_h.m4
Updating file lib/_Noreturn.h (backup in lib/_Noreturn.h~)
Updating file lib/access.c (backup in lib/access.c~)
Updating file lib/alloca.in.h (backup in lib/alloca.in.h~)
Updating file lib/arg-nonnull.h (backup in lib/arg-nonnull.h~)
Updating file lib/assert.in.h (backup in lib/assert.in.h~)
Updating file lib/assure.h (backup in lib/assure.h~)
Updating file lib/at-func.c (backup in lib/at-func.c~)
Updating file lib/attribute.h (backup in lib/attribute.h~)
Updating file lib/basename-lgpl.c (backup in lib/basename-lgpl.c~)
Updating file lib/basename-lgpl.h (backup in lib/basename-lgpl.h~)
Updating file lib/binary-io.c (backup in lib/binary-io.c~)
Updating file lib/binary-io.h (backup in lib/binary-io.h~)
Updating file lib/bitrotate.c (backup in lib/bitrotate.c~)
Updating file lib/bitrotate.h (backup in lib/bitrotate.h~)
Updating file lib/c++defs.h (backup in lib/c++defs.h~)
Updating file lib/calloc.c (backup in lib/calloc.c~)
Updating file lib/canonicalize.c (backup in lib/canonicalize.c~)
Updating file lib/canonicalize.h (backup in lib/canonicalize.h~)
Updating file lib/cdefs.h (backup in lib/cdefs.h~)
Updating file lib/chdir-long.c (backup in lib/chdir-long.c~)
Updating file lib/chdir-long.h (backup in lib/chdir-long.h~)
Updating file lib/cloexec.c (backup in lib/cloexec.c~)
Updating file lib/cloexec.h (backup in lib/cloexec.h~)
Updating file lib/close.c (backup in lib/close.c~)
Updating file lib/closedir.c (backup in lib/closedir.c~)
Updating file lib/concat-filename.c (backup in lib/concat-filename.c~)
Updating file lib/concat-filename.h (backup in lib/concat-filename.h~)
Updating file lib/connect.c (backup in lib/connect.c~)
Updating file lib/dirent-private.h (backup in lib/dirent-private.h~)
Updating file lib/dirent.in.h (backup in lib/dirent.in.h~)
Updating file lib/dirfd.c (backup in lib/dirfd.c~)
Updating file lib/dup-safer-flag.c (backup in lib/dup-safer-flag.c~)
Updating file lib/dup-safer.c (backup in lib/dup-safer.c~)
Updating file lib/dup.c (backup in lib/dup.c~)
Updating file lib/dup2.c (backup in lib/dup2.c~)
Updating file lib/errno.in.h (backup in lib/errno.in.h~)
Updating file lib/error.c (backup in lib/error.c~)
Updating file lib/error.in.h (backup in lib/error.in.h~)
Updating file lib/exitfail.c (backup in lib/exitfail.c~)
Updating file lib/exitfail.h (backup in lib/exitfail.h~)
Updating file lib/fatal-signal.c (backup in lib/fatal-signal.c~)
Updating file lib/fatal-signal.h (backup in lib/fatal-signal.h~)
Updating file lib/fchdir.c (backup in lib/fchdir.c~)
Updating file lib/fcntl.c (backup in lib/fcntl.c~)
Updating file lib/fcntl.in.h (backup in lib/fcntl.in.h~)
Updating file lib/fd-hook.c (backup in lib/fd-hook.c~)
Updating file lib/fd-hook.h (backup in lib/fd-hook.h~)
Updating file lib/fd-safer-flag.c (backup in lib/fd-safer-flag.c~)
Updating file lib/fd-safer.c (backup in lib/fd-safer.c~)
Updating file lib/fdopendir.c (backup in lib/fdopendir.c~)
Updating file lib/file-set.c (backup in lib/file-set.c~)
Updating file lib/file-set.h (backup in lib/file-set.h~)
Updating file lib/filename.h (backup in lib/filename.h~)
Updating file lib/filenamecat-lgpl.c (backup in lib/filenamecat-lgpl.c~)
Updating file lib/filenamecat.h (backup in lib/filenamecat.h~)
Updating file lib/findprog-in.c (backup in lib/findprog-in.c~)
Updating file lib/findprog.h (backup in lib/findprog.h~)
Updating file lib/free.c (backup in lib/free.c~)
Updating file lib/fstat.c (backup in lib/fstat.c~)
Updating file lib/fstatat.c (backup in lib/fstatat.c~)
Updating file lib/ftruncate.c (backup in lib/ftruncate.c~)
Updating file lib/full-read.c (backup in lib/full-read.c~)
Updating file lib/full-read.h (backup in lib/full-read.h~)
Updating file lib/full-write.c (backup in lib/full-write.c~)
Updating file lib/full-write.h (backup in lib/full-write.h~)
Updating file lib/getcwd-lgpl.c (backup in lib/getcwd-lgpl.c~)
Updating file lib/getcwd.c (backup in lib/getcwd.c~)
Updating file lib/getdtablesize.c (backup in lib/getdtablesize.c~)
Updating file lib/getprogname.c (backup in lib/getprogname.c~)
Updating file lib/getprogname.h (backup in lib/getprogname.h~)
Updating file lib/gettext.h (backup in lib/gettext.h~)
Updating file lib/glthread/lock.c (backup in lib/glthread/lock.c~)
Updating file lib/glthread/lock.h (backup in lib/glthread/lock.h~)
Updating file lib/glthread/once.c (backup in lib/glthread/once.c~)
Updating file lib/glthread/once.h (backup in lib/glthread/once.h~)
Updating file lib/glthread/threadlib.c (backup in lib/glthread/threadlib.c~)
Updating file lib/hash-pjw.c (backup in lib/hash-pjw.c~)
Updating file lib/hash-pjw.h (backup in lib/hash-pjw.h~)
Updating file lib/hash-triple-simple.c (backup in lib/hash-triple-simple.c~)
Updating file lib/hash-triple.h (backup in lib/hash-triple.h~)
Updating file lib/hash.c (backup in lib/hash.c~)
Updating file lib/hash.h (backup in lib/hash.h~)
Updating file lib/ialloc.c (backup in lib/ialloc.c~)
Updating file lib/ialloc.h (backup in lib/ialloc.h~)
Updating file lib/idx.h (backup in lib/idx.h~)
Updating file lib/intprops-internal.h (backup in lib/intprops-internal.h~)
Updating file lib/intprops.h (backup in lib/intprops.h~)
Updating file lib/inttypes.in.h (backup in lib/inttypes.in.h~)
Updating file lib/libc-config.h (backup in lib/libc-config.h~)
Updating file lib/limits.in.h (backup in lib/limits.in.h~)
Updating file lib/lstat.c (backup in lib/lstat.c~)
Updating file lib/malloc.c (backup in lib/malloc.c~)
Updating file lib/malloc/scratch_buffer.h (backup in lib/malloc/scratch_buffer.h~)
Updating file lib/malloc/scratch_buffer_grow.c (backup in lib/malloc/scratch_buffer_grow.c~)
Updating file lib/malloc/scratch_buffer_grow_preserve.c (backup in lib/malloc/scratch_buffer_grow_preserve.c~)
Updating file lib/malloc/scratch_buffer_set_array_size.c (backup in lib/malloc/scratch_buffer_set_array_size.c~)
Updating file lib/malloca.c (backup in lib/malloca.c~)
Updating file lib/malloca.h (backup in lib/malloca.h~)
Updating file lib/memchr.c (backup in lib/memchr.c~)
Updating file lib/memchr.valgrind (backup in lib/memchr.valgrind~)
Updating file lib/mempcpy.c (backup in lib/mempcpy.c~)
Updating file lib/memrchr.c (backup in lib/memrchr.c~)
Updating file lib/minmax.h (backup in lib/minmax.h~)
Updating file lib/mkfifo.c (backup in lib/mkfifo.c~)
Updating file lib/msvc-inval.c (backup in lib/msvc-inval.c~)
Updating file lib/msvc-inval.h (backup in lib/msvc-inval.h~)
Updating file lib/msvc-nothrow.c (backup in lib/msvc-nothrow.c~)
Updating file lib/msvc-nothrow.h (backup in lib/msvc-nothrow.h~)
Updating file lib/open.c (backup in lib/open.c~)
Updating file lib/openat-die.c (backup in lib/openat-die.c~)
Updating file lib/openat-priv.h (backup in lib/openat-priv.h~)
Updating file lib/openat-proc.c (backup in lib/openat-proc.c~)
Updating file lib/openat.c (backup in lib/openat.c~)
Updating file lib/openat.h (backup in lib/openat.h~)
Updating file lib/opendir.c (backup in lib/opendir.c~)
Updating file lib/os2-spawn.c (backup in lib/os2-spawn.c~)
Updating file lib/os2-spawn.h (backup in lib/os2-spawn.h~)
Updating file lib/passfd.c (backup in lib/passfd.c~)
Updating file lib/passfd.h (backup in lib/passfd.h~)
Updating file lib/pathmax.h (backup in lib/pathmax.h~)
Updating file lib/pipe-filter-aux.c (backup in lib/pipe-filter-aux.c~)
Updating file lib/pipe-filter-aux.h (backup in lib/pipe-filter-aux.h~)
Updating file lib/pipe-filter-gi.c (backup in lib/pipe-filter-gi.c~)
Updating file lib/pipe-filter-ii.c (backup in lib/pipe-filter-ii.c~)
Updating file lib/pipe-filter.h (backup in lib/pipe-filter.h~)
Updating file lib/pipe-safer.c (backup in lib/pipe-safer.c~)
Updating file lib/pipe.c (backup in lib/pipe.c~)
Updating file lib/pipe2-safer.c (backup in lib/pipe2-safer.c~)
Updating file lib/pipe2.c (backup in lib/pipe2.c~)
Updating file lib/pthread-once.c (backup in lib/pthread-once.c~)
Updating file lib/pthread.in.h (backup in lib/pthread.in.h~)
Updating file lib/raise.c (backup in lib/raise.c~)
Updating file lib/rawmemchr.c (backup in lib/rawmemchr.c~)
Updating file lib/rawmemchr.valgrind (backup in lib/rawmemchr.valgrind~)
Updating file lib/read.c (backup in lib/read.c~)
Updating file lib/readdir.c (backup in lib/readdir.c~)
Updating file lib/readlink.c (backup in lib/readlink.c~)
Updating file lib/realloc.c (backup in lib/realloc.c~)
Updating file lib/reallocarray.c (backup in lib/reallocarray.c~)
Updating file lib/rewinddir.c (backup in lib/rewinddir.c~)
Updating file lib/safe-read.c (backup in lib/safe-read.c~)
Updating file lib/safe-read.h (backup in lib/safe-read.h~)
Updating file lib/safe-write.c (backup in lib/safe-write.c~)
Updating file lib/safe-write.h (backup in lib/safe-write.h~)
Updating file lib/same-inode.h (backup in lib/same-inode.h~)
Updating file lib/save-cwd.c (backup in lib/save-cwd.c~)
Updating file lib/save-cwd.h (backup in lib/save-cwd.h~)
Updating file lib/sched.in.h (backup in lib/sched.in.h~)
Updating file lib/scratch_buffer.h (backup in lib/scratch_buffer.h~)
Updating file lib/sig-handler.c (backup in lib/sig-handler.c~)
Updating file lib/sig-handler.h (backup in lib/sig-handler.h~)
Updating file lib/sigaction.c (backup in lib/sigaction.c~)
Updating file lib/signal.in.h (backup in lib/signal.in.h~)
Updating file lib/sigprocmask.c (backup in lib/sigprocmask.c~)
Updating file lib/socket.c (backup in lib/socket.c~)
Updating file lib/sockets.c (backup in lib/sockets.c~)
Updating file lib/sockets.h (backup in lib/sockets.h~)
Updating file lib/spawn-pipe.c (backup in lib/spawn-pipe.c~)
Updating file lib/spawn-pipe.h (backup in lib/spawn-pipe.h~)
Updating file lib/spawn.c (backup in lib/spawn.c~)
Updating file lib/spawn.in.h (backup in lib/spawn.in.h~)
Updating file lib/spawn_faction_addchdir.c (backup in lib/spawn_faction_addchdir.c~)
Updating file lib/spawn_faction_addclose.c (backup in lib/spawn_faction_addclose.c~)
Updating file lib/spawn_faction_adddup2.c (backup in lib/spawn_faction_adddup2.c~)
Updating file lib/spawn_faction_addopen.c (backup in lib/spawn_faction_addopen.c~)
Updating file lib/spawn_faction_destroy.c (backup in lib/spawn_faction_destroy.c~)
Updating file lib/spawn_faction_init.c (backup in lib/spawn_faction_init.c~)
Updating file lib/spawn_int.h (backup in lib/spawn_int.h~)
Updating file lib/spawnattr_destroy.c (backup in lib/spawnattr_destroy.c~)
Updating file lib/spawnattr_init.c (backup in lib/spawnattr_init.c~)
Updating file lib/spawnattr_setflags.c (backup in lib/spawnattr_setflags.c~)
Updating file lib/spawnattr_setpgroup.c (backup in lib/spawnattr_setpgroup.c~)
Updating file lib/spawnattr_setsigmask.c (backup in lib/spawnattr_setsigmask.c~)
Updating file lib/spawni.c (backup in lib/spawni.c~)
Updating file lib/spawnp.c (backup in lib/spawnp.c~)
Updating file lib/stat-time.c (backup in lib/stat-time.c~)
Updating file lib/stat-time.h (backup in lib/stat-time.h~)
Updating file lib/stat-w32.c (backup in lib/stat-w32.c~)
Updating file lib/stat-w32.h (backup in lib/stat-w32.h~)
Updating file lib/stat.c (backup in lib/stat.c~)
Updating file lib/stdckdint.in.h (backup in lib/stdckdint.in.h~)
Updating file lib/stddef.in.h (backup in lib/stddef.in.h~)
Updating file lib/stdint.in.h (backup in lib/stdint.in.h~)
Updating file lib/stdio-read.c (backup in lib/stdio-read.c~)
Updating file lib/stdio-write.c (backup in lib/stdio-write.c~)
Updating file lib/stdio.in.h (backup in lib/stdio.in.h~)
Updating file lib/stdlib.in.h (backup in lib/stdlib.in.h~)
Updating file lib/stpcpy.c (backup in lib/stpcpy.c~)
Updating file lib/strchrnul.c (backup in lib/strchrnul.c~)
Updating file lib/strchrnul.valgrind (backup in lib/strchrnul.valgrind~)
Updating file lib/strdup.c (backup in lib/strdup.c~)
Updating file lib/strerror-override.c (backup in lib/strerror-override.c~)
Updating file lib/strerror-override.h (backup in lib/strerror-override.h~)
Updating file lib/strerror.c (backup in lib/strerror.c~)
Updating file lib/string.in.h (backup in lib/string.in.h~)
Updating file lib/sys-limits.h (backup in lib/sys-limits.h~)
Updating file lib/sys_select.in.h (backup in lib/sys_select.in.h~)
Updating file lib/sys_socket.c (backup in lib/sys_socket.c~)
Updating file lib/sys_socket.in.h (backup in lib/sys_socket.in.h~)
Updating file lib/sys_stat.in.h (backup in lib/sys_stat.in.h~)
Updating file lib/sys_time.in.h (backup in lib/sys_time.in.h~)
Updating file lib/sys_types.in.h (backup in lib/sys_types.in.h~)
Updating file lib/sys_uio.in.h (backup in lib/sys_uio.in.h~)
Updating file lib/sys_wait.in.h (backup in lib/sys_wait.in.h~)
Updating file lib/thread-optim.h (backup in lib/thread-optim.h~)
Updating file lib/time.in.h (backup in lib/time.in.h~)
Updating file lib/unistd--.h (backup in lib/unistd--.h~)
Updating file lib/unistd-safer.h (backup in lib/unistd-safer.h~)
Updating file lib/unistd.c (backup in lib/unistd.c~)
Updating file lib/unistd.in.h (backup in lib/unistd.in.h~)
Updating file lib/verify.h (backup in lib/verify.h~)
Updating file lib/w32sock.h (backup in lib/w32sock.h~)
Updating file lib/wait-process.c (backup in lib/wait-process.c~)
Updating file lib/wait-process.h (backup in lib/wait-process.h~)
Updating file lib/waitpid.c (backup in lib/waitpid.c~)
Updating file lib/warn-on-use.h (backup in lib/warn-on-use.h~)
Updating file lib/wchar.in.h (backup in lib/wchar.in.h~)
Updating file lib/windows-initguard.h (backup in lib/windows-initguard.h~)
Updating file lib/windows-mutex.c (backup in lib/windows-mutex.c~)
Updating file lib/windows-mutex.h (backup in lib/windows-mutex.h~)
Updating file lib/windows-once.c (backup in lib/windows-once.c~)
Updating file lib/windows-once.h (backup in lib/windows-once.h~)
Updating file lib/windows-path.c (backup in lib/windows-path.c~)
Updating file lib/windows-path.h (backup in lib/windows-path.h~)
Updating file lib/windows-recmutex.c (backup in lib/windows-recmutex.c~)
Updating file lib/windows-recmutex.h (backup in lib/windows-recmutex.h~)
Updating file lib/windows-rwlock.c (backup in lib/windows-rwlock.c~)
Updating file lib/windows-rwlock.h (backup in lib/windows-rwlock.h~)
Updating file lib/windows-spawn.c (backup in lib/windows-spawn.c~)
Updating file lib/windows-spawn.h (backup in lib/windows-spawn.h~)
Updating file lib/write.c (backup in lib/write.c~)
Updating file lib/xalloc-die.c (backup in lib/xalloc-die.c~)
Updating file lib/xalloc-oversized.h (backup in lib/xalloc-oversized.h~)
Updating file lib/xalloc.h (backup in lib/xalloc.h~)
Updating file lib/xmalloc.c (backup in lib/xmalloc.c~)
Updating file m4/00gnulib.m4 (backup in m4/00gnulib.m4~)
Updating file m4/__inline.m4 (backup in m4/__inline.m4~)
Updating file m4/absolute-header.m4 (backup in m4/absolute-header.m4~)
Updating file m4/access.m4 (backup in m4/access.m4~)
Updating file m4/alloca.m4 (backup in m4/alloca.m4~)
Updating file m4/assert_h.m4 (backup in m4/assert_h.m4~)
Updating file m4/builtin-expect.m4 (backup in m4/builtin-expect.m4~)
Updating file m4/c-bool.m4 (backup in m4/c-bool.m4~)
Updating file m4/calloc.m4 (backup in m4/calloc.m4~)
Updating file m4/canonicalize.m4 (backup in m4/canonicalize.m4~)
Updating file m4/chdir-long.m4 (backup in m4/chdir-long.m4~)
Updating file m4/close.m4 (backup in m4/close.m4~)
Updating file m4/closedir.m4 (backup in m4/closedir.m4~)
Updating file m4/codeset.m4 (backup in m4/codeset.m4~)
Updating file m4/d-ino.m4 (backup in m4/d-ino.m4~)
Updating file m4/dirent_h.m4 (backup in m4/dirent_h.m4~)
Updating file m4/dirfd.m4 (backup in m4/dirfd.m4~)
Updating file m4/double-slash-root.m4 (backup in m4/double-slash-root.m4~)
Updating file m4/dup.m4 (backup in m4/dup.m4~)
Updating file m4/dup2.m4 (backup in m4/dup2.m4~)
Updating file m4/eaccess.m4 (backup in m4/eaccess.m4~)
Updating file m4/environ.m4 (backup in m4/environ.m4~)
Updating file m4/errno_h.m4 (backup in m4/errno_h.m4~)
Updating file m4/error.m4 (backup in m4/error.m4~)
Updating file m4/error_h.m4 (backup in m4/error_h.m4~)
Updating file m4/extensions-aix.m4 (backup in m4/extensions-aix.m4~)
Updating file m4/extensions.m4 (backup in m4/extensions.m4~)
Updating file m4/extern-inline.m4 (backup in m4/extern-inline.m4~)
Updating file m4/fatal-signal.m4 (backup in m4/fatal-signal.m4~)
Updating file m4/fchdir.m4 (backup in m4/fchdir.m4~)
Updating file m4/fcntl-o.m4 (backup in m4/fcntl-o.m4~)
Updating file m4/fcntl.m4 (backup in m4/fcntl.m4~)
Updating file m4/fcntl_h.m4 (backup in m4/fcntl_h.m4~)
Updating file m4/fdopendir.m4 (backup in m4/fdopendir.m4~)
Updating file m4/filenamecat.m4 (backup in m4/filenamecat.m4~)
Updating file m4/findprog-in.m4 (backup in m4/findprog-in.m4~)
Updating file m4/free.m4 (backup in m4/free.m4~)
Updating file m4/fstat.m4 (backup in m4/fstat.m4~)
Updating file m4/fstatat.m4 (backup in m4/fstatat.m4~)
Updating file m4/ftruncate.m4 (backup in m4/ftruncate.m4~)
Updating file m4/getcwd-abort-bug.m4 (backup in m4/getcwd-abort-bug.m4~)
Updating file m4/getcwd-path-max.m4 (backup in m4/getcwd-path-max.m4~)
Updating file m4/getcwd.m4 (backup in m4/getcwd.m4~)
Updating file m4/getdtablesize.m4 (backup in m4/getdtablesize.m4~)
Updating file m4/getprogname.m4 (backup in m4/getprogname.m4~)
Updating file m4/gnulib-common.m4 (backup in m4/gnulib-common.m4~)
Updating file m4/gnulib-tool.m4 (backup in m4/gnulib-tool.m4~)
Updating file m4/include_next.m4 (backup in m4/include_next.m4~)
Updating file m4/inttypes.m4 (backup in m4/inttypes.m4~)
Updating file m4/largefile.m4 (backup in m4/largefile.m4~)
Updating file m4/limits-h.m4 (backup in m4/limits-h.m4~)
Updating file m4/locale-en.m4 (backup in m4/locale-en.m4~)
Updating file m4/lock.m4 (backup in m4/lock.m4~)
Updating file m4/lstat.m4 (backup in m4/lstat.m4~)
Updating file m4/malloc.m4 (backup in m4/malloc.m4~)
Updating file m4/malloca.m4 (backup in m4/malloca.m4~)
Updating file m4/memchr.m4 (backup in m4/memchr.m4~)
Updating file m4/mempcpy.m4 (backup in m4/mempcpy.m4~)
Updating file m4/memrchr.m4 (backup in m4/memrchr.m4~)
Updating file m4/minmax.m4 (backup in m4/minmax.m4~)
Updating file m4/mkfifo.m4 (backup in m4/mkfifo.m4~)
Updating file m4/mmap-anon.m4 (backup in m4/mmap-anon.m4~)
Updating file m4/mode_t.m4 (backup in m4/mode_t.m4~)
Updating file m4/msvc-inval.m4 (backup in m4/msvc-inval.m4~)
Updating file m4/msvc-nothrow.m4 (backup in m4/msvc-nothrow.m4~)
Updating file m4/multiarch.m4 (backup in m4/multiarch.m4~)
Updating file m4/musl.m4 (backup in m4/musl.m4~)
Updating file m4/nocrash.m4 (backup in m4/nocrash.m4~)
Updating file m4/off64_t.m4 (backup in m4/off64_t.m4~)
Updating file m4/off_t.m4 (backup in m4/off_t.m4~)
Updating file m4/once.m4 (backup in m4/once.m4~)
Updating file m4/open-cloexec.m4 (backup in m4/open-cloexec.m4~)
Updating file m4/open-slash.m4 (backup in m4/open-slash.m4~)
Updating file m4/open.m4 (backup in m4/open.m4~)
Updating file m4/openat.m4 (backup in m4/openat.m4~)
Updating file m4/opendir.m4 (backup in m4/opendir.m4~)
Updating file m4/passfd.m4 (backup in m4/passfd.m4~)
Updating file m4/pathmax.m4 (backup in m4/pathmax.m4~)
Updating file m4/pid_t.m4 (backup in m4/pid_t.m4~)
Updating file m4/pipe.m4 (backup in m4/pipe.m4~)
Updating file m4/pipe2.m4 (backup in m4/pipe2.m4~)
Updating file m4/posix_spawn.m4 (backup in m4/posix_spawn.m4~)
Updating file m4/posix_spawn_faction_addchdir.m4 (backup in m4/posix_spawn_faction_addchdir.m4~)
Updating file m4/pthread-once.m4 (backup in m4/pthread-once.m4~)
Updating file m4/pthread-spin.m4 (backup in m4/pthread-spin.m4~)
Updating file m4/pthread_h.m4 (backup in m4/pthread_h.m4~)
Updating file m4/pthread_rwlock_rdlock.m4 (backup in m4/pthread_rwlock_rdlock.m4~)
Updating file m4/raise.m4 (backup in m4/raise.m4~)
Updating file m4/rawmemchr.m4 (backup in m4/rawmemchr.m4~)
Updating file m4/read.m4 (backup in m4/read.m4~)
Updating file m4/readdir.m4 (backup in m4/readdir.m4~)
Updating file m4/readlink.m4 (backup in m4/readlink.m4~)
Updating file m4/realloc.m4 (backup in m4/realloc.m4~)
Updating file m4/reallocarray.m4 (backup in m4/reallocarray.m4~)
Updating file m4/rewinddir.m4 (backup in m4/rewinddir.m4~)
Updating file m4/safe-read.m4 (backup in m4/safe-read.m4~)
Updating file m4/safe-write.m4 (backup in m4/safe-write.m4~)
Updating file m4/save-cwd.m4 (backup in m4/save-cwd.m4~)
Updating file m4/sched_h.m4 (backup in m4/sched_h.m4~)
Updating file m4/sh-filename.m4 (backup in m4/sh-filename.m4~)
Updating file m4/sig_atomic_t.m4 (backup in m4/sig_atomic_t.m4~)
Updating file m4/sigaction.m4 (backup in m4/sigaction.m4~)
Updating file m4/signal_h.m4 (backup in m4/signal_h.m4~)
Updating file m4/signalblocking.m4 (backup in m4/signalblocking.m4~)
Updating file m4/socketlib.m4 (backup in m4/socketlib.m4~)
Updating file m4/sockets.m4 (backup in m4/sockets.m4~)
Updating file m4/socklen.m4 (backup in m4/socklen.m4~)
Updating file m4/sockpfaf.m4 (backup in m4/sockpfaf.m4~)
Updating file m4/spawn-pipe.m4 (backup in m4/spawn-pipe.m4~)
Updating file m4/spawn_h.m4 (backup in m4/spawn_h.m4~)
Updating file m4/ssize_t.m4 (backup in m4/ssize_t.m4~)
Updating file m4/stat-time.m4 (backup in m4/stat-time.m4~)
Updating file m4/stat.m4 (backup in m4/stat.m4~)
Updating file m4/std-gnu11.m4 (backup in m4/std-gnu11.m4~)
Updating file m4/stdalign.m4 (backup in m4/stdalign.m4~)
Updating file m4/stddef_h.m4 (backup in m4/stddef_h.m4~)
Updating file m4/stdint.m4 (backup in m4/stdint.m4~)
Updating file m4/stdio_h.m4 (backup in m4/stdio_h.m4~)
Updating file m4/stdlib_h.m4 (backup in m4/stdlib_h.m4~)
Updating file m4/stpcpy.m4 (backup in m4/stpcpy.m4~)
Updating file m4/strchrnul.m4 (backup in m4/strchrnul.m4~)
Updating file m4/strdup.m4 (backup in m4/strdup.m4~)
Updating file m4/strerror.m4 (backup in m4/strerror.m4~)
Updating file m4/string_h.m4 (backup in m4/string_h.m4~)
Updating file m4/sys_cdefs_h.m4 (backup in m4/sys_cdefs_h.m4~)
Updating file m4/sys_select_h.m4 (backup in m4/sys_select_h.m4~)
Updating file m4/sys_socket_h.m4 (backup in m4/sys_socket_h.m4~)
Updating file m4/sys_stat_h.m4 (backup in m4/sys_stat_h.m4~)
Updating file m4/sys_time_h.m4 (backup in m4/sys_time_h.m4~)
Updating file m4/sys_types_h.m4 (backup in m4/sys_types_h.m4~)
Updating file m4/sys_uio_h.m4 (backup in m4/sys_uio_h.m4~)
Updating file m4/sys_wait_h.m4 (backup in m4/sys_wait_h.m4~)
Updating file m4/threadlib.m4 (backup in m4/threadlib.m4~)
Updating file m4/time_h.m4 (backup in m4/time_h.m4~)
Updating file m4/unistd-safer.m4 (backup in m4/unistd-safer.m4~)
Updating file m4/unistd_h.m4 (backup in m4/unistd_h.m4~)
Updating file m4/vararrays.m4 (backup in m4/vararrays.m4~)
Updating file m4/wait-process.m4 (backup in m4/wait-process.m4~)
Updating file m4/waitpid.m4 (backup in m4/waitpid.m4~)
Updating file m4/warn-on-use.m4 (backup in m4/warn-on-use.m4~)
Updating file m4/wchar_h.m4 (backup in m4/wchar_h.m4~)
Updating file m4/wint_t.m4 (backup in m4/wint_t.m4~)
Updating file m4/write.m4 (backup in m4/write.m4~)
Updating file m4/xalloc.m4 (backup in m4/xalloc.m4~)
Updating file m4/zzgnulib.m4 (backup in m4/zzgnulib.m4~)
Updating m4/gnulib-cache.m4 (backup in m4/gnulib-cache.m4~)
Updating m4/gnulib-comp.m4 (backup in m4/gnulib-comp.m4~)
Updating lib/Makefile.am (backup in lib/Makefile.am~)
Finished.

You may need to add #include directives for the following .h files.
  #include <fcntl.h>
  #include <sys/socket.h>
  #include <sys/stat.h>
  #include <sys/un.h>
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
