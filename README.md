NDKTest
=======

A small android project to test NDK with C++11 support


------------------------

Note : If using Android studio and gradle 0.7.2+, just create a symlink named `jniLibs` in `app/src/main/` to `app/libs/` and android studio will pack that library in the apk.

```sh
cd app/src/main
ln -s ../../libs/ jniLibs
```
