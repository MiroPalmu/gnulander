This is a library to interface with GNU system using bleeding edge C++.
It wraps low-level functionality into C++ abstractions
in order to increase expressibility and reuse of code,
which require a high attention to detail.

# Requirements

Gnulander uses C++26 features which have lacking compiler support.
Currently it is tested to work with GCC 15.0.0 20241129 (experimental).

# Usage

Gnulander is provided as Meson dependency: `gnulander_dep`.

Example Meson wrap to acquire gnulander:

```
[wrap-git]
url = https://github.com/MiroPalmu/gnulander.git
revision = v0.2.1
depth = 1
```

# Author

Miro Palmu, email@miropalmu.cc
