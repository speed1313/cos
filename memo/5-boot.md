pc = 8020004c

80200024 <kernel_main>:
80200024: 37 05 20 80   lui     a0, 524800
80200028: 13 05 05 05   addi    a0, a0, 80
8020002c: b7 05 20 80   lui     a1, 524800
80200030: 93 85 05 05   addi    a1, a1, 80
80200034: 33 86 a5 40   sub     a2, a1, a0
80200038: 11 ca         beqz    a2, 0x8020004c <.LBB1_3>
8020003a: b3 05 b5 40   sub     a1, a0, a1

8020004c <.LBB1_3>:
8020004c: 01 a0         j       0x8020004c <.LBB1_3>

kernel_mainから無限ループのルーチンに入っているため, 正しくbootできている.