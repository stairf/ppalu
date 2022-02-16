PPALU
=====

A 64-bit arithmetic logic unit ([wiki](https://en.wikipedia.org/wiki/Arithmetic_logic_unit)) entirely written in the C preprocessor.

Features
--------

 - *bit* and or xor not eq
 - *byte* fromhex tohex or and xor not/inv getbit iszero eq neq
 - *i{08,16,32,64}* ZERO ONE UMAX SMAX SMIN
 - *i{08,16,32,64}* fromhex tohex getbyte cast-up
   (zero-extend/sign-extend) cast-down inv or and xor neg add inc sub iszero
   ispos isneg isnonzero isposorzero isnegorzero iseq isneq isa isae isb isbe isge isgt isle islt
   rshift (sign-extend/zero-extend) lshift rrot lrot

