libxlsxwriter++
===============

C++ bindings for jmcnamara's excellent [libxlsxwriter](https://github.com/jmcnamara/libxlsxwriter) library.

[![Build Status](https://travis-ci.org/Alexhuszagh/libxlsxwriterpp.svg?branch=master)](https://travis-ci.org/Alexhuszagh/libxlsxwriterpp)
[![Build Status](https://tea-ci.org/api/badges/Alexhuszagh/libxlsxwriterpp/status.svg)](https://tea-ci.org/Alexhuszagh/libxlsxwriterpp)
[![Build status](https://ci.appveyor.com/api/projects/status/xc6xv5fdqf2nlgor?svg=true)](https://ci.appveyor.com/project/Alexhuszagh/libxlsxwriterpp)
[![Coverity Scan Build Status](https://scan.coverity.com/projects/12993/badge.svg)](https://scan.coverity.com/projects/alexhuszagh-libxlsxwriterpp)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/29a95557c6a0442486daee87ce4eb089)](https://www.codacy.com/app/Alexhuszagh/libxlsxwriterpp?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Alexhuszagh/libxlsxwriterpp&amp;utm_campaign=Badge_Grade)
[![GitHub License](https://img.shields.io/badge/License-BSD%202--Clause-orange.svg)](https://github.com/Alexhuszagh/libxlsxwriterpp/blob/master/LICENSE.md)

**Table of Contents**

- [Building](#building)
- [License](#license)

## Building

Simply clone, configure with CMake, and build.

```bash
git clone https://github.com/Alexhuszagh/libxlsxwriterpp.git
cd libxlsxwriterpp
git submodule update --init --recursive
cd build
cmake .. -DBUILD_TESTS=ON
make -j 5                       # "msbuild libxlsxwriter++.sln" for MSVC
```

## License

FreeBSD, see [license](LICENSE.md).
