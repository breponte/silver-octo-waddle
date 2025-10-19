# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-src"
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-build"
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix"
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix/tmp"
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp"
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix/src"
  "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/breponte/silver-octo-waddle/build/_deps/sdl-subbuild/sdl-populate-prefix/src/sdl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
