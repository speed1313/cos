プロセスというのは結局のところ
プロセスID, プロセスの状態, コンテキストスイッチ時のスタックポインタ, カーネルスタック(cpu registers, caller's address, etc)を持った構造体のことで, カーネルがspやpc, レジスタを書き換えることでプロセスを切り替えている.
スタックやレジスタが変わる関数呼び出しと同じようなもの.
カーネルはPCB構造体においてstackフィールドを持ち, そこにプロセスのレジスタ等を保持する. 

```
switch_context(uint32_t *prev_sp, uint32_t *next_sp){

}
```
において, 第一引数のアドレスがa0に, 第二引数のアドレスがa1に入る.
a0, a1を用いてspの保存, 復元を行うことでプロセスの切り替えを実現している.

レジスタの保存は, スタックにpushすることで行い, 復元はpopすることで行う.
各プロセスがスタックとspを持っているので, それを切り替えることでプロセスの切り替えができる.

プロセスキューはPCBの配列として大域変数が定義されている.

# scheduling
current_proc = idle_proc
で初期化することで, ブート処理の実行コンテキストがアイドルプロセスのそれとして保存・復元されるようになる.
ブート時のスタックがアイドルプロセスのスタックとして使われるため, process構造体に割り当ててあるstackフィールドは使われない.


# 例外ハンドラの修正
プロセスごとに構造体のフィールドとしてスタックを持つようになった.
既存の例外ハンドラはidle_procのスタックを使っていたので, それを修正する必要がある.
まずyield時に, sscratchに次に実行するプロセスのスタックの底を保存する.


[x] この実装だと, カーネルスタックの底周辺が上書きされてしまわない?
    - アプリケーションのスタックはuser.ldで別で用意されているため, アプリケーションのスタックは上書きされない.
    - カーネルスタックは毎回底からから再利用するため, 上書きされるが, 例外処理からカーネルモードに復帰しない, または復帰してもカーネルパニックするので問題ない.
    - Ref. https://github.com/nuta/operating-system-in-1000-lines/issues/12
[] sscratchにカーネルスタックの底を保持しておく理由がわからない
