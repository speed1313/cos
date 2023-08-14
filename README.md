# cos
cos is a toy operating system in C Language  with reference to https://operating-system-in-1000-lines.vercel.app

# Features
- [x] Virtual Memory(paging)
- [x] Multitasking
- [x] Exception
- [x] File System
- [x] System Call
- [x] Disk IO
- [x] Memory Allocator
- [x] shell command
  - [x] ls
  - [x] ps

# How To Use

```
$ ./run.sh
...
...


> ls
hello.txt
meow.txt
> ps
pid=-1 runnable
pid=2 runnable
pid=3 runnable
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
> exit
process 2 exited
> ps
pid=-1 runnable
pid=2 exited
pid=3 runnable
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
> hlel
Unknown command: hlel
> hello
Hello World from shell!
> readfile
hello

> writefile
virtio: tried to read/write sector=6, but capacity is 6
virtio: tried to read/write sector=7, but capacity is 6
wrote 4096 bytes to disk
> exit
process 3 exited
PANIC: kernel.c:699: switched to idle process
```


# Reference
- https://operating-system-in-1000-lines.vercel.app