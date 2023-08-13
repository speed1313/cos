例外ハンドラの開始アドレスを特別なレジスタstvecに登録し, CPUに例外発生時に実行してもらう.
例外発生時のspの値などを, 一時退避用としてsscratchレジスタを使う.

a0にスタックポイントを設定することで, handle_trapの第一引数として渡すことができる.

stvecレジスタの下位2ビットはモードを表すフラグに使用されるため, 関数の先頭アドレスを4バイト境界にアラインする必要がある.


[] medelegでモード確認がopenSBIで定義されているとあるが、どのタイミングか。デフォルト？

```
#define READ_CSR(reg)                                                          \
    ({                                                                         \
        unsigned long __tmp;                                                   \
        __asm__ __volatile__("csrr %0, " #reg : "=r"(__tmp));                          \
        __tmp;                                                                 \
    })
```
__tmp;を最後に差し込むことで
```
unsigned long value = READ_CSR(mstatus);
```
上記のように, レジスタ値を関数の戻り値のように使用できる.


PANIC: kernel.c:115: unexpected trap scause=00000002, stval=00000000, sepc=8020011c, sp=80220350
8020011c: 00 00         unimp