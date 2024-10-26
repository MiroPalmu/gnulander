Gnulander wants to use some modules from gnulib,
however gnulib assumes that projects that use it are build with gnu build system.

This subdirectory is for setting mock gnu build system for building libgnu.a,
in such way that meson can build it with custom target.

Every generated file in source tree should be tracked with git, as it is assumed that,
this directory is setup once and rarely updated and we do not want to meson to gnereate *any*
files to source tree. Only to build tree.

Every usage of `gnulib-tool` should be logged to gnulib-tool-log.
