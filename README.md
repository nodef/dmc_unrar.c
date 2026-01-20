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
#include <dmc_unrar.h>

int main() { /* ... */ }
```

Finally, compile while adding the path `node_modules/dmc_unrar.c` to your compiler's include paths.

```bash
$ clang -I./node_modules/dmc_unrar.c main.c  # or, use gcc
$ gcc   -I./node_modules/dmc_unrar.c main.c
```

You may also use a simpler approach with the [cpoach](https://www.npmjs.com/package/cpoach.sh) tool, which automatically adds the necessary include paths of all the installed dependencies for your project.

```bash
$ cpoach clang main.c  # or, use gcc
$ cpoach gcc   main.c
```

<br>
<br>


[![](https://raw.githubusercontent.com/qb40/designs/gh-pages/0/image/11.png)](https://wolfram77.github.io)<br>
[![SRC](https://img.shields.io/badge/src-repo-green?logo=Org)](https://github.com/DrMcCoy/dmc_unrar)
[![ORG](https://img.shields.io/badge/org-nodef-green?logo=Org)](https://nodef.github.io)
![](https://ga-beacon.deno.dev/G-RC63DPBH3P:SH3Eq-NoQ9mwgYeHWxu7cw/github.com/nodef/dmc_unrar.c)
