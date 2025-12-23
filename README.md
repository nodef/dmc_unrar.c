dmc_unrar
=========

dmc_unrar is a dependency-free, single-file FLOSS library for unpacking
and decompressing [RAR](https://en.wikipedia.org/wiki/RAR_(file_format))
archives - by [Sven Hesse](https://github.com/DrMcCoy). dmc_unrar is
licensed under the terms of the
[GNU General Public License version 2](https://www.gnu.org/licenses/gpl-2.0.html) (or later).

Please see `dmc_unrar.h` for details.

<br>

Installation
------------

Run:

```sh
$ npm i dmc_unrar.c
```

And then include `dmc_unrar.h` as follows:

```c
// main.c
#include "node_modules/dmc_unrar.c/dmc_unrar.h"

int main() { /* ... */ }
```

And then compile with `clang` or `gcc` as usual.

```bash
$ clang main.c  # or, use gcc
$ gcc   main.c
```

You may also use a simpler approach:

```c
// main.c
#include <dmc_unrar.h>

int main() { /* ... */ }
```

If you add the path `node_modules/dmc_unrar.c` to your compiler's include paths.

```bash
$ clang -I./node_modules/dmc_unrar.c main.c  # or, use gcc
$ gcc   -I./node_modules/dmc_unrar.c main.c
```

<br>
<br>


[![SRC](https://img.shields.io/badge/src-repo-green?logo=Org)](https://github.com/DrMcCoy/dmc_unrar)
[![ORG](https://img.shields.io/badge/org-nodef-green?logo=Org)](https://nodef.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/nodef/dmc_unrar.c)
