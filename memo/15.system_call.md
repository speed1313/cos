ユーザモードからカーネルの機能を呼び出す

putcharをユーザモード, カーネルモード双方で実装することで, 同じように使える.
ただし, ユーザモードではシステムコールを呼び出す必要がある.

```
> hello
Hello World from shell!
> run
Unknown command: run
> exit
process 2 exited
PANIC: kernel.c:386: switched to idle process
```

[] EXITEDされたプロセスが持つページテーブルや割り当てられたメモリ領域などの資源を開放する

