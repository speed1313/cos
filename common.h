#pragma once


typedef int bool;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef uint32_t size_t;
typedef uint32_t paddr_t; // physical address
typedef uint32_t vaddr_t; // virtual address

#define true 1
#define false 0
#define NULL ((void *)0)
#define PAGE_SIZE 4096
// align_up and is_aligned is used for memory alignment
#define align_up(value, align) __builtin_align_up(value, align) // Round up value to a multiple of ALIGN
#define is_aligned(value, align) __builtin_is_aligned(value, align) // check if the value is a multiple of ALIGN
#define offsetof(type, member) __builtin_offsetof(type, member) // get the offset of a member in a struct

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg
#define SYS_PUTCHAR 1
#define SYS_GETCHAR 2
#define SYS_EXIT 3
#define SYS_READFILE 4
#define SYS_WRITEFILE 5
#define SYS_LISTFILE 6
#define SYS_PS 7

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
char *strcpy(char *dst, const char *src);
int strcmp(const char *s1, const char *s2);
void printf(const char *fmt, ...);