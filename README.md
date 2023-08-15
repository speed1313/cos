# cos
cos is a toy operating system in C Language  with reference to https://operating-system-in-1000-lines.vercel.app

# Features
- [x] Virtual Memory(paging)
  - Sv32 Two-Level Address Translation
- [x] Multitasking
  - for now, it is not preemptive multitasking
  - [ ] round robin scheduler?
- [x] Exception Handling
  - system call, page fault and so on
- [x] File System
  - [ ] more rich one
- [x] System Call
- [x] Disk IO
- [x] Memory Allocator
  - [x] bit map allocator
    - if a process exits, the memory it used will be freed.
- [x] shell command
  - [x] ls
  - [x] ps
  - [ ] init(init new process)
- [ ] TCP/IP protocol stack
- [ ] interrupt processing
- [ ] multi processor support
- [ ] inter process communication
- [ ] timer processing
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