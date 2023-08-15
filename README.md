# cos
cos is a toy operating system in C Language  with reference to https://operating-system-in-1000-lines.vercel.app

# Features
- [x] Virtual Memory(paging)
- [x] Multitasking
  - [ ] round robin scheduler
- [x] Exception
- [x] File System
- [x] System Call
- [x] Disk IO
- [x] Memory Allocator
  - [x] bit map allocator
    - if a process exits, the memory it used will be freed.
- [x] shell command
  - [x] ls
  - [x] ps
  - [x] init(init new process)

# How To Use

```
$ ./run.sh
...
...

created process pid=1
pid=1 use 19 pages
hello world
created process pid=2
pid=2 use 37 pages
current page use 56/128 (pages)
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