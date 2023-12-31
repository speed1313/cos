# cos
cos is a toy operating system in C Language  with reference to https://operating-system-in-1000-lines.vercel.app

# Features
- [x] Virtual Memory(paging)
  - Sv32 Two-Level Address Translation
- [x] Multitasking
  - for now, it is not preemptive multitasking
  - [ ] round robin scheduler?
  - [ ] priority scheduler(longer sleep time, higher priority)
- [x] Exception Handling
  - system call, page fault and so on
- [x] File System
  - [ ] more rich one
- [x] System Call
  - [ ] fork()(Let's see xv6)
  - [ ] Exec()(only predefined binary)
- [x] Disk IO
- [x] Memory Allocator
  - [x] bit map allocator
    - if a process exits, the memory it used will be freed.
- [x] shell command
  - [x] ls
  - [x] ps
  - [x] init(init new process)
  - [x] bitmap(show heap memory usage)
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

created process pid=1, page_table=80277000
pid=1 use 19 pages
hello world
created process pid=2, page_table=8028a000
pid=2 use 37 pages
> ps
pid=-1 runnable
pid=2 runnable
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
> init
created process pid=3, page_table=802af000
pid=3 use 37 pages
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
used_page_count 59
> ps
pid=-1 runnable
pid=2 unused
pid=3 runnable
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
> init
created process pid=2, page_table=8028a000
pid=2 use 37 pages
> ps
pid=-1 runnable
pid=2 runnable
pid=3 runnable
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
pid=0 unused
> init
created process pid=4, page_table=802d4000
pid=4 use 37 pages
> bitmap
0xfffffffffffffffffffffffffffffffff80000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 current page use 133/512 (pages)
> ls
hello.txt
meow.txt
> hello
Hello World from shell!
> readfile
hello

> writefile
virtio: tried to read/write sector=6, but capacity is 6
virtio: tried to read/write sector=7, but capacity is 6
wrote 4096 bytes to disk
```
You can find that each process has its own page table.

# Reference
## Operating System in 1000 lines
- https://operating-system-in-1000-lines.vercel.app
## xv6 related
- https://www.sugawara-lab.jp/lecture.html
- https://github.com/mit-pdos/xv6-riscv
- https://pdos.csail.mit.edu/6.828/2023/