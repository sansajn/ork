# About

Fork of [Ork](https://gitlab.inria.fr/neyret/ork) library with SCons build support.

# Build

Following lines describes how to build *Ork* under *Ubuntu 22.04 LTS*.

- download *glew* library from [glew](https://glew.sourceforge.net/) page where 1.5.6 version can be downloaded [here](https://sourceforge.net/projects/glew/files/glew/1.5.6/)

- unpack with
```bash
tar -xaf glew-1.5.6.tgz	
```
command.

- install *glew* dependencies with
```bash
sudo apt install libxmu-dev
```
command

- build with
```bash
cd glew-1.5.6
make -j8
```
command

- install with to `/usr` directory with
```bash
sudo make install
```
command. Where *glew* library in installed to `/usr` directory.


- create linker configuration for `/usr/lib64` where *glew* was installed. Go to configuration directory with

```bash
cd /etc/ld.so.conf.d
```

and create `usr_lib64.conf` with following

```console
$ cat usr_lib64.conf 
# linker configuration for /usr/lib64
/usr/lib64
```

content

- update linker cache with

```bash
sudo ldconfig
```

Be aware that (`/usr/lib64/pkgconfig`) pkg-config install directory is not searched by `pkg-config` command. As a result `pkg-config` is not aware of locally installed *glew* library e.g.

```console
$ pkg-config --modversion glew
2.2.0
```

can return 2.2.0 (verson of *glew* library installed by package manager) instead of 1.5.6 version installed manually.

This can be solved by setting `PKG_CONFIG_PATH` environment variable from build script with

```python
env.AppendENVPath('PKG_CONFIG_PATH', '/usr/lib64/pkgconfig')
```

line (see `SConstruct` file).

## Issues

1. undefined reference to `glEnable`

```
/bin/ld: libork.a(FrameBuffer.o): undefined reference to symbol 'glEnable'
/bin/ld: /lib/x86_64-linux-gnu/libGL.so.1: error adding symbols: DSO missing from command line
```

There are missing `-lGL -lX11 -lGLU` dependencies for *glew* library in a pkg-config configuration.


# Run

After succesfull building examples can be found in `examples` directory.

```console
$ cd examples
$ ./examples minimal
```
> TODO: still not working..., see issue 2

other examples are *render*, *resource*, *scenegraph*, *scenegraphresource* and *tessellation*.

Run

```bash
./examples render .
```

commnad for *render* example or

```bash
./examples resource .
```

command for *resource* or

```bash
./examples tessellation
```

command for a tessellation sample (GLSL 4.0).


> TODO: how to run tests to find errors?

> TODO: not working examples *scenegraph*, `scenegraphresource . cubesScene`


## Issues

1. Unable to loading shared library `libGLEW.so.1.5`
```console
$ ./examples
./examples: error while loading shared libraries: libGLEW.so.1.5: c/etc/ld.so.conf.dannot open shared object file: No such file or directory
```

The root cause is that the library in not in a linker cache. 

```console
$ ldconfig -p|grep -i glew
        libGLEW.so.2.2 (libc6,x86-64) => /lib/x86_64-linux-gnu/libGLEW.so.2.2
        libGLEW.so (libc6,x86-64) => /lib/x86_64-linux-gnu/libGLEW.so
```

There is missig linker configuration for `/usr/lib64` in `/etc/ld.so.conf.d` directory.

2. *OpenGL error 1282* complain for exampes

```console
$ ./examples minimal
ERROR [RENDER] OpenGL error 1282, returned string 'invalid operation'
invalid operation
examples: ork/render/Program.cpp:660: void ork::Program::initUniforms(): Assertion `FrameBuffer::getError() == 0' failed.
Aborted (core dumped)
```

# Install

To install *Ork* library run

```bash
sudo scons install
```

command and to update linker database, run

```bash
sudo ldconfig
```

> TODO: is linker searching in `/usr/local/lib` by default?

command.

The library is installed to `/usr/local/lib` directory.
