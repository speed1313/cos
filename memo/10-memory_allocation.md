リンカスクリプトにheap領域を定義して, 動的にメモリを確保する領域を用意しておく.
static変数でnext_paddrを管理.

[] For now, allocated memory can't be free.

```
alloc_pages test: paddr0=80221000
alloc_pages test: paddr1=80223000
PANIC: kernel.c:141: booted!
```