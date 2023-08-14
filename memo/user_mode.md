create_process()で, ユーザモードプロセスを作成する.

各アプリケーションのページテーブルを作成する際, 実行イメージをページ単位でコピーしてからユーザーモードのページにマッピングすることで, プロセス間のメモリ空間を分離することができる.

user_entry()から実行イメージの開始番地にジャンプする際, ユーザーモードに切り替える.
```
CPU#0
 V      =   0
 pc       01000010
```

```
shell.c

*((volatile int *)0x80200000) = 0x1234; // this causes a page fault
```
すると...
```
idle_proc->id=1
PANIC: kernel.c:303: unexpected trap scause=0000000f, stval=80200000, sepc=0100001a, sp=80238d00
```