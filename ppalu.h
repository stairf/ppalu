/*
 *  Copyright (c) 2021, Stefan Reif
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// include guard
#ifndef __PPALU__
#define __PPALU__ 1

// single-bit operations
#define bit$or(...) bit$or$1(__VA_ARGS__)
#define bit$or$1(...) bit$or$2(__VA_ARGS__)
#define bit$or$2(b1, b2) bit$or$with$##b1##b2
#define bit$or$with$00 0
#define bit$or$with$01 1
#define bit$or$with$10 1
#define bit$or$with$11 1
#define bit$and(...) bit$and$1(__VA_ARGS__)
#define bit$and$1(...) bit$and$2(__VA_ARGS__)
#define bit$and$2(b1, b2) bit$and$with$##b1##b2
#define bit$and$with$00 0
#define bit$and$with$01 0
#define bit$and$with$10 0
#define bit$and$with$11 1
#define bit$xor(...) bit$xor$1(__VA_ARGS__)
#define bit$xor$1(...) bit$xor$2(__VA_ARGS__)
#define bit$xor$2(b1, b2) bit$xor$with$##b1##b2
#define bit$xor$with$00 0
#define bit$xor$with$01 1
#define bit$xor$with$10 1
#define bit$xor$with$11 0
#define bit$not(...) bit$not$1(__VA_ARGS__)
#define bit$not$1(...) bit$not$2(__VA_ARGS__)
#define bit$not$2(b1) bit$not$with$##b1
#define bit$not$with$0 1
#define bit$not$with$1 0
#define bit$eq(...) bit$eq$1(__VA_ARGS__)
#define bit$eq$1(...) bit$eq$2(__VA_ARGS__)
#define bit$eq$2(b1, b2) bit$eq$with$##b1##b2
#define bit$eq$with$00 1
#define bit$eq$with$01 0
#define bit$eq$with$10 0
#define bit$eq$with$11 1
#define bit$all1(...) bit$all1$1(__VA_ARGS__)
#define bit$all1$1(...) bit$all1$2(__VA_ARGS__)
#define bit$all1$2(b0) b0
#define bit$all2(...) bit$all2$1(__VA_ARGS__)
#define bit$all2$1(...) bit$all2$2(__VA_ARGS__)
#define bit$all2$2(...) bit$all2$3(__VA_ARGS__)
#define bit$all2$3(b1,b0) bit$all2$##b1##b0
#define bit$all2$00 0
#define bit$all2$01 0
#define bit$all2$10 0
#define bit$all2$11 1
#define bit$all3(...) bit$all3$1(__VA_ARGS__)
#define bit$all3$1(...) bit$all3$2(__VA_ARGS__)
#define bit$all3$2(b,...) bit$all3$with##b(__VA_ARGS__)
#define bit$all3$with0(...) 0
#define bit$all3$with1(...) bit$all2$2(__VA_ARGS__)
#define bit$all4(...) bit$all4$1(__VA_ARGS__)
#define bit$all4$1(...) bit$all4$2(__VA_ARGS__)
#define bit$all4$2(b,...) bit$all4$with##b(__VA_ARGS__)
#define bit$all4$with0(...) 0
#define bit$all4$with1(...) bit$all3$2(__VA_ARGS__)
#define bit$all5(...) bit$all5$1(__VA_ARGS__)
#define bit$all5$1(...) bit$all5$2(__VA_ARGS__)
#define bit$all5$2(b,...) bit$all5$with##b(__VA_ARGS__)
#define bit$all5$with0(...) 0
#define bit$all5$with1(...) bit$all4$2(__VA_ARGS__)
#define bit$all6(...) bit$all6$1(__VA_ARGS__)
#define bit$all6$1(...) bit$all6$2(__VA_ARGS__)
#define bit$all6$2(b,...) bit$all6$with##b(__VA_ARGS__)
#define bit$all6$with0(...) 0
#define bit$all6$with1(...) bit$all5$2(__VA_ARGS__)
#define bit$all7(...) bit$all7$1(__VA_ARGS__)
#define bit$all7$1(...) bit$all7$2(__VA_ARGS__)
#define bit$all7$2(b,...) bit$all7$with##b(__VA_ARGS__)
#define bit$all7$with0(...) 0
#define bit$all7$with1(...) bit$all6$2(__VA_ARGS__)
#define bit$all8(...) bit$all8$1(__VA_ARGS__)
#define bit$all8$1(...) bit$all8$2(__VA_ARGS__)
#define bit$all8$2(b,...) bit$all8$with##b(__VA_ARGS__)
#define bit$all8$with0(...) 0
#define bit$all8$with1(...) bit$all7$2(__VA_ARGS__)
#define bit$any1(...) bit$any1$1(__VA_ARGS__)
#define bit$any1$1(...) bit$any1$2(__VA_ARGS__)
#define bit$any1$2(b0) b0
#define bit$any2(...) bit$any2$1(__VA_ARGS__)
#define bit$any2$1(...) bit$any2$2(__VA_ARGS__)
#define bit$any2$2(b1,b0) bit$any2$##b1##b0
#define bit$any2$00 0
#define bit$any2$01 1
#define bit$any2$10 1
#define bit$any2$11 1
#define bit$any3(...) bit$any3$1(__VA_ARGS__)
#define bit$any3$1(...) bit$any3$2(__VA_ARGS__)
#define bit$any3$2(b,...) bit$any3$with##b(__VA_ARGS__)
#define bit$any3$with0(...) bit$any2$2(__VA_ARGS__)
#define bit$any3$with1(...) 1
#define bit$any4(...) bit$any4$1(__VA_ARGS__)
#define bit$any4$1(...) bit$any4$2(__VA_ARGS__)
#define bit$any4$2(b,...) bit$any4$with##b(__VA_ARGS__)
#define bit$any4$with0(...) bit$any3$2(__VA_ARGS__)
#define bit$any4$with1(...) 1
#define bit$any5(...) bit$any5$1(__VA_ARGS__)
#define bit$any5$1(...) bit$any5$2(__VA_ARGS__)
#define bit$any5$2(b,...) bit$any5$with##b(__VA_ARGS__)
#define bit$any5$with0(...) bit$any4$2(__VA_ARGS__)
#define bit$any5$with1(...) 1
#define bit$any6(...) bit$any6$1(__VA_ARGS__)
#define bit$any6$1(...) bit$any6$2(__VA_ARGS__)
#define bit$any6$2(b,...) bit$any6$with##b(__VA_ARGS__)
#define bit$any6$with0(...) bit$any5$2(__VA_ARGS__)
#define bit$any6$with1(...) 1
#define bit$any7(...) bit$any7$1(__VA_ARGS__)
#define bit$any7$1(...) bit$any7$2(__VA_ARGS__)
#define bit$any7$2(b,...) bit$any7$with##b(__VA_ARGS__)
#define bit$any7$with0(...) bit$any6$2(__VA_ARGS__)
#define bit$any7$with1(...) 1
#define bit$any8(...) bit$any8$1(__VA_ARGS__)
#define bit$any8$1(...) bit$any8$2(__VA_ARGS__)
#define bit$any8$2(b,...) bit$any8$with##b(__VA_ARGS__)
#define bit$any8$with0(...) bit$any7$2(__VA_ARGS__)
#define bit$any8$with1(...) 1

// convert to/from internal byte representation
#define byte$tohex(p, ...) byte$tohex$1(p, __VA_ARGS__)
#define byte$tohex$1(p, ...) byte$tohex$2(p, __VA_ARGS__)
#define byte$tohex$2(p, ...) byte$tohex$3(p, __VA_ARGS__)
#define byte$tohex$3(p, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) byte$tohex$##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(p)
#define byte$as$ff(b) b
#define byte$as$0xff(b) 0x##b
#define byte$as$0xffu(b) 0x##b##u
#define byte$join$glue(...)  byte$join$glue$1(__VA_ARGS__)
#define byte$join$glue$1(...)  byte$join$glue$2(__VA_ARGS__)
#define byte$join$glue$2(a,b) a##b
#define byte$join$comma(a,b) a,b
#define byte$tohex$00000000(p) p(00)
#define byte$tohex$00000001(p) p(01)
#define byte$tohex$00000010(p) p(02)
#define byte$tohex$00000011(p) p(03)
#define byte$tohex$00000100(p) p(04)
#define byte$tohex$00000101(p) p(05)
#define byte$tohex$00000110(p) p(06)
#define byte$tohex$00000111(p) p(07)
#define byte$tohex$00001000(p) p(08)
#define byte$tohex$00001001(p) p(09)
#define byte$tohex$00001010(p) p(0a)
#define byte$tohex$00001011(p) p(0b)
#define byte$tohex$00001100(p) p(0c)
#define byte$tohex$00001101(p) p(0d)
#define byte$tohex$00001110(p) p(0e)
#define byte$tohex$00001111(p) p(0f)
#define byte$tohex$00010000(p) p(10)
#define byte$tohex$00010001(p) p(11)
#define byte$tohex$00010010(p) p(12)
#define byte$tohex$00010011(p) p(13)
#define byte$tohex$00010100(p) p(14)
#define byte$tohex$00010101(p) p(15)
#define byte$tohex$00010110(p) p(16)
#define byte$tohex$00010111(p) p(17)
#define byte$tohex$00011000(p) p(18)
#define byte$tohex$00011001(p) p(19)
#define byte$tohex$00011010(p) p(1a)
#define byte$tohex$00011011(p) p(1b)
#define byte$tohex$00011100(p) p(1c)
#define byte$tohex$00011101(p) p(1d)
#define byte$tohex$00011110(p) p(1e)
#define byte$tohex$00011111(p) p(1f)
#define byte$tohex$00100000(p) p(20)
#define byte$tohex$00100001(p) p(21)
#define byte$tohex$00100010(p) p(22)
#define byte$tohex$00100011(p) p(23)
#define byte$tohex$00100100(p) p(24)
#define byte$tohex$00100101(p) p(25)
#define byte$tohex$00100110(p) p(26)
#define byte$tohex$00100111(p) p(27)
#define byte$tohex$00101000(p) p(28)
#define byte$tohex$00101001(p) p(29)
#define byte$tohex$00101010(p) p(2a)
#define byte$tohex$00101011(p) p(2b)
#define byte$tohex$00101100(p) p(2c)
#define byte$tohex$00101101(p) p(2d)
#define byte$tohex$00101110(p) p(2e)
#define byte$tohex$00101111(p) p(2f)
#define byte$tohex$00110000(p) p(30)
#define byte$tohex$00110001(p) p(31)
#define byte$tohex$00110010(p) p(32)
#define byte$tohex$00110011(p) p(33)
#define byte$tohex$00110100(p) p(34)
#define byte$tohex$00110101(p) p(35)
#define byte$tohex$00110110(p) p(36)
#define byte$tohex$00110111(p) p(37)
#define byte$tohex$00111000(p) p(38)
#define byte$tohex$00111001(p) p(39)
#define byte$tohex$00111010(p) p(3a)
#define byte$tohex$00111011(p) p(3b)
#define byte$tohex$00111100(p) p(3c)
#define byte$tohex$00111101(p) p(3d)
#define byte$tohex$00111110(p) p(3e)
#define byte$tohex$00111111(p) p(3f)
#define byte$tohex$01000000(p) p(40)
#define byte$tohex$01000001(p) p(41)
#define byte$tohex$01000010(p) p(42)
#define byte$tohex$01000011(p) p(43)
#define byte$tohex$01000100(p) p(44)
#define byte$tohex$01000101(p) p(45)
#define byte$tohex$01000110(p) p(46)
#define byte$tohex$01000111(p) p(47)
#define byte$tohex$01001000(p) p(48)
#define byte$tohex$01001001(p) p(49)
#define byte$tohex$01001010(p) p(4a)
#define byte$tohex$01001011(p) p(4b)
#define byte$tohex$01001100(p) p(4c)
#define byte$tohex$01001101(p) p(4d)
#define byte$tohex$01001110(p) p(4e)
#define byte$tohex$01001111(p) p(4f)
#define byte$tohex$01010000(p) p(50)
#define byte$tohex$01010001(p) p(51)
#define byte$tohex$01010010(p) p(52)
#define byte$tohex$01010011(p) p(53)
#define byte$tohex$01010100(p) p(54)
#define byte$tohex$01010101(p) p(55)
#define byte$tohex$01010110(p) p(56)
#define byte$tohex$01010111(p) p(57)
#define byte$tohex$01011000(p) p(58)
#define byte$tohex$01011001(p) p(59)
#define byte$tohex$01011010(p) p(5a)
#define byte$tohex$01011011(p) p(5b)
#define byte$tohex$01011100(p) p(5c)
#define byte$tohex$01011101(p) p(5d)
#define byte$tohex$01011110(p) p(5e)
#define byte$tohex$01011111(p) p(5f)
#define byte$tohex$01100000(p) p(60)
#define byte$tohex$01100001(p) p(61)
#define byte$tohex$01100010(p) p(62)
#define byte$tohex$01100011(p) p(63)
#define byte$tohex$01100100(p) p(64)
#define byte$tohex$01100101(p) p(65)
#define byte$tohex$01100110(p) p(66)
#define byte$tohex$01100111(p) p(67)
#define byte$tohex$01101000(p) p(68)
#define byte$tohex$01101001(p) p(69)
#define byte$tohex$01101010(p) p(6a)
#define byte$tohex$01101011(p) p(6b)
#define byte$tohex$01101100(p) p(6c)
#define byte$tohex$01101101(p) p(6d)
#define byte$tohex$01101110(p) p(6e)
#define byte$tohex$01101111(p) p(6f)
#define byte$tohex$01110000(p) p(70)
#define byte$tohex$01110001(p) p(71)
#define byte$tohex$01110010(p) p(72)
#define byte$tohex$01110011(p) p(73)
#define byte$tohex$01110100(p) p(74)
#define byte$tohex$01110101(p) p(75)
#define byte$tohex$01110110(p) p(76)
#define byte$tohex$01110111(p) p(77)
#define byte$tohex$01111000(p) p(78)
#define byte$tohex$01111001(p) p(79)
#define byte$tohex$01111010(p) p(7a)
#define byte$tohex$01111011(p) p(7b)
#define byte$tohex$01111100(p) p(7c)
#define byte$tohex$01111101(p) p(7d)
#define byte$tohex$01111110(p) p(7e)
#define byte$tohex$01111111(p) p(7f)
#define byte$tohex$10000000(p) p(80)
#define byte$tohex$10000001(p) p(81)
#define byte$tohex$10000010(p) p(82)
#define byte$tohex$10000011(p) p(83)
#define byte$tohex$10000100(p) p(84)
#define byte$tohex$10000101(p) p(85)
#define byte$tohex$10000110(p) p(86)
#define byte$tohex$10000111(p) p(87)
#define byte$tohex$10001000(p) p(88)
#define byte$tohex$10001001(p) p(89)
#define byte$tohex$10001010(p) p(8a)
#define byte$tohex$10001011(p) p(8b)
#define byte$tohex$10001100(p) p(8c)
#define byte$tohex$10001101(p) p(8d)
#define byte$tohex$10001110(p) p(8e)
#define byte$tohex$10001111(p) p(8f)
#define byte$tohex$10010000(p) p(90)
#define byte$tohex$10010001(p) p(91)
#define byte$tohex$10010010(p) p(92)
#define byte$tohex$10010011(p) p(93)
#define byte$tohex$10010100(p) p(94)
#define byte$tohex$10010101(p) p(95)
#define byte$tohex$10010110(p) p(96)
#define byte$tohex$10010111(p) p(97)
#define byte$tohex$10011000(p) p(98)
#define byte$tohex$10011001(p) p(99)
#define byte$tohex$10011010(p) p(9a)
#define byte$tohex$10011011(p) p(9b)
#define byte$tohex$10011100(p) p(9c)
#define byte$tohex$10011101(p) p(9d)
#define byte$tohex$10011110(p) p(9e)
#define byte$tohex$10011111(p) p(9f)
#define byte$tohex$10100000(p) p(a0)
#define byte$tohex$10100001(p) p(a1)
#define byte$tohex$10100010(p) p(a2)
#define byte$tohex$10100011(p) p(a3)
#define byte$tohex$10100100(p) p(a4)
#define byte$tohex$10100101(p) p(a5)
#define byte$tohex$10100110(p) p(a6)
#define byte$tohex$10100111(p) p(a7)
#define byte$tohex$10101000(p) p(a8)
#define byte$tohex$10101001(p) p(a9)
#define byte$tohex$10101010(p) p(aa)
#define byte$tohex$10101011(p) p(ab)
#define byte$tohex$10101100(p) p(ac)
#define byte$tohex$10101101(p) p(ad)
#define byte$tohex$10101110(p) p(ae)
#define byte$tohex$10101111(p) p(af)
#define byte$tohex$10110000(p) p(b0)
#define byte$tohex$10110001(p) p(b1)
#define byte$tohex$10110010(p) p(b2)
#define byte$tohex$10110011(p) p(b3)
#define byte$tohex$10110100(p) p(b4)
#define byte$tohex$10110101(p) p(b5)
#define byte$tohex$10110110(p) p(b6)
#define byte$tohex$10110111(p) p(b7)
#define byte$tohex$10111000(p) p(b8)
#define byte$tohex$10111001(p) p(b9)
#define byte$tohex$10111010(p) p(ba)
#define byte$tohex$10111011(p) p(bb)
#define byte$tohex$10111100(p) p(bc)
#define byte$tohex$10111101(p) p(bd)
#define byte$tohex$10111110(p) p(be)
#define byte$tohex$10111111(p) p(bf)
#define byte$tohex$11000000(p) p(c0)
#define byte$tohex$11000001(p) p(c1)
#define byte$tohex$11000010(p) p(c2)
#define byte$tohex$11000011(p) p(c3)
#define byte$tohex$11000100(p) p(c4)
#define byte$tohex$11000101(p) p(c5)
#define byte$tohex$11000110(p) p(c6)
#define byte$tohex$11000111(p) p(c7)
#define byte$tohex$11001000(p) p(c8)
#define byte$tohex$11001001(p) p(c9)
#define byte$tohex$11001010(p) p(ca)
#define byte$tohex$11001011(p) p(cb)
#define byte$tohex$11001100(p) p(cc)
#define byte$tohex$11001101(p) p(cd)
#define byte$tohex$11001110(p) p(ce)
#define byte$tohex$11001111(p) p(cf)
#define byte$tohex$11010000(p) p(d0)
#define byte$tohex$11010001(p) p(d1)
#define byte$tohex$11010010(p) p(d2)
#define byte$tohex$11010011(p) p(d3)
#define byte$tohex$11010100(p) p(d4)
#define byte$tohex$11010101(p) p(d5)
#define byte$tohex$11010110(p) p(d6)
#define byte$tohex$11010111(p) p(d7)
#define byte$tohex$11011000(p) p(d8)
#define byte$tohex$11011001(p) p(d9)
#define byte$tohex$11011010(p) p(da)
#define byte$tohex$11011011(p) p(db)
#define byte$tohex$11011100(p) p(dc)
#define byte$tohex$11011101(p) p(dd)
#define byte$tohex$11011110(p) p(de)
#define byte$tohex$11011111(p) p(df)
#define byte$tohex$11100000(p) p(e0)
#define byte$tohex$11100001(p) p(e1)
#define byte$tohex$11100010(p) p(e2)
#define byte$tohex$11100011(p) p(e3)
#define byte$tohex$11100100(p) p(e4)
#define byte$tohex$11100101(p) p(e5)
#define byte$tohex$11100110(p) p(e6)
#define byte$tohex$11100111(p) p(e7)
#define byte$tohex$11101000(p) p(e8)
#define byte$tohex$11101001(p) p(e9)
#define byte$tohex$11101010(p) p(ea)
#define byte$tohex$11101011(p) p(eb)
#define byte$tohex$11101100(p) p(ec)
#define byte$tohex$11101101(p) p(ed)
#define byte$tohex$11101110(p) p(ee)
#define byte$tohex$11101111(p) p(ef)
#define byte$tohex$11110000(p) p(f0)
#define byte$tohex$11110001(p) p(f1)
#define byte$tohex$11110010(p) p(f2)
#define byte$tohex$11110011(p) p(f3)
#define byte$tohex$11110100(p) p(f4)
#define byte$tohex$11110101(p) p(f5)
#define byte$tohex$11110110(p) p(f6)
#define byte$tohex$11110111(p) p(f7)
#define byte$tohex$11111000(p) p(f8)
#define byte$tohex$11111001(p) p(f9)
#define byte$tohex$11111010(p) p(fa)
#define byte$tohex$11111011(p) p(fb)
#define byte$tohex$11111100(p) p(fc)
#define byte$tohex$11111101(p) p(fd)
#define byte$tohex$11111110(p) p(fe)
#define byte$tohex$11111111(p) p(ff)
#define byte$fromhex(...) byte$fromhex$1(__VA_ARGS__)
#define byte$fromhex$1(...) byte$fromhex$2(__VA_ARGS__)
#define byte$fromhex$2(...) byte$fromhex$3(__VA_ARGS__)
#define byte$fromhex$3(hex) byte$fromhex$value$##hex
#define byte$fromhex$value$0 0,0,0,0,0,0,0,0
#define byte$fromhex$value$1 0,0,0,0,0,0,0,1
#define byte$fromhex$value$2 0,0,0,0,0,0,1,0
#define byte$fromhex$value$3 0,0,0,0,0,0,1,1
#define byte$fromhex$value$4 0,0,0,0,0,1,0,0
#define byte$fromhex$value$5 0,0,0,0,0,1,0,1
#define byte$fromhex$value$6 0,0,0,0,0,1,1,0
#define byte$fromhex$value$7 0,0,0,0,0,1,1,1
#define byte$fromhex$value$8 0,0,0,0,1,0,0,0
#define byte$fromhex$value$9 0,0,0,0,1,0,0,1
#define byte$fromhex$value$a 0,0,0,0,1,0,1,0
#define byte$fromhex$value$b 0,0,0,0,1,0,1,1
#define byte$fromhex$value$c 0,0,0,0,1,1,0,0
#define byte$fromhex$value$d 0,0,0,0,1,1,0,1
#define byte$fromhex$value$e 0,0,0,0,1,1,1,0
#define byte$fromhex$value$f 0,0,0,0,1,1,1,1
#define byte$fromhex$value$00 0,0,0,0,0,0,0,0
#define byte$fromhex$value$01 0,0,0,0,0,0,0,1
#define byte$fromhex$value$02 0,0,0,0,0,0,1,0
#define byte$fromhex$value$03 0,0,0,0,0,0,1,1
#define byte$fromhex$value$04 0,0,0,0,0,1,0,0
#define byte$fromhex$value$05 0,0,0,0,0,1,0,1
#define byte$fromhex$value$06 0,0,0,0,0,1,1,0
#define byte$fromhex$value$07 0,0,0,0,0,1,1,1
#define byte$fromhex$value$08 0,0,0,0,1,0,0,0
#define byte$fromhex$value$09 0,0,0,0,1,0,0,1
#define byte$fromhex$value$0a 0,0,0,0,1,0,1,0
#define byte$fromhex$value$0b 0,0,0,0,1,0,1,1
#define byte$fromhex$value$0c 0,0,0,0,1,1,0,0
#define byte$fromhex$value$0d 0,0,0,0,1,1,0,1
#define byte$fromhex$value$0e 0,0,0,0,1,1,1,0
#define byte$fromhex$value$0f 0,0,0,0,1,1,1,1
#define byte$fromhex$value$10 0,0,0,1,0,0,0,0
#define byte$fromhex$value$11 0,0,0,1,0,0,0,1
#define byte$fromhex$value$12 0,0,0,1,0,0,1,0
#define byte$fromhex$value$13 0,0,0,1,0,0,1,1
#define byte$fromhex$value$14 0,0,0,1,0,1,0,0
#define byte$fromhex$value$15 0,0,0,1,0,1,0,1
#define byte$fromhex$value$16 0,0,0,1,0,1,1,0
#define byte$fromhex$value$17 0,0,0,1,0,1,1,1
#define byte$fromhex$value$18 0,0,0,1,1,0,0,0
#define byte$fromhex$value$19 0,0,0,1,1,0,0,1
#define byte$fromhex$value$1a 0,0,0,1,1,0,1,0
#define byte$fromhex$value$1b 0,0,0,1,1,0,1,1
#define byte$fromhex$value$1c 0,0,0,1,1,1,0,0
#define byte$fromhex$value$1d 0,0,0,1,1,1,0,1
#define byte$fromhex$value$1e 0,0,0,1,1,1,1,0
#define byte$fromhex$value$1f 0,0,0,1,1,1,1,1
#define byte$fromhex$value$20 0,0,1,0,0,0,0,0
#define byte$fromhex$value$21 0,0,1,0,0,0,0,1
#define byte$fromhex$value$22 0,0,1,0,0,0,1,0
#define byte$fromhex$value$23 0,0,1,0,0,0,1,1
#define byte$fromhex$value$24 0,0,1,0,0,1,0,0
#define byte$fromhex$value$25 0,0,1,0,0,1,0,1
#define byte$fromhex$value$26 0,0,1,0,0,1,1,0
#define byte$fromhex$value$27 0,0,1,0,0,1,1,1
#define byte$fromhex$value$28 0,0,1,0,1,0,0,0
#define byte$fromhex$value$29 0,0,1,0,1,0,0,1
#define byte$fromhex$value$2a 0,0,1,0,1,0,1,0
#define byte$fromhex$value$2b 0,0,1,0,1,0,1,1
#define byte$fromhex$value$2c 0,0,1,0,1,1,0,0
#define byte$fromhex$value$2d 0,0,1,0,1,1,0,1
#define byte$fromhex$value$2e 0,0,1,0,1,1,1,0
#define byte$fromhex$value$2f 0,0,1,0,1,1,1,1
#define byte$fromhex$value$30 0,0,1,1,0,0,0,0
#define byte$fromhex$value$31 0,0,1,1,0,0,0,1
#define byte$fromhex$value$32 0,0,1,1,0,0,1,0
#define byte$fromhex$value$33 0,0,1,1,0,0,1,1
#define byte$fromhex$value$34 0,0,1,1,0,1,0,0
#define byte$fromhex$value$35 0,0,1,1,0,1,0,1
#define byte$fromhex$value$36 0,0,1,1,0,1,1,0
#define byte$fromhex$value$37 0,0,1,1,0,1,1,1
#define byte$fromhex$value$38 0,0,1,1,1,0,0,0
#define byte$fromhex$value$39 0,0,1,1,1,0,0,1
#define byte$fromhex$value$3a 0,0,1,1,1,0,1,0
#define byte$fromhex$value$3b 0,0,1,1,1,0,1,1
#define byte$fromhex$value$3c 0,0,1,1,1,1,0,0
#define byte$fromhex$value$3d 0,0,1,1,1,1,0,1
#define byte$fromhex$value$3e 0,0,1,1,1,1,1,0
#define byte$fromhex$value$3f 0,0,1,1,1,1,1,1
#define byte$fromhex$value$40 0,1,0,0,0,0,0,0
#define byte$fromhex$value$41 0,1,0,0,0,0,0,1
#define byte$fromhex$value$42 0,1,0,0,0,0,1,0
#define byte$fromhex$value$43 0,1,0,0,0,0,1,1
#define byte$fromhex$value$44 0,1,0,0,0,1,0,0
#define byte$fromhex$value$45 0,1,0,0,0,1,0,1
#define byte$fromhex$value$46 0,1,0,0,0,1,1,0
#define byte$fromhex$value$47 0,1,0,0,0,1,1,1
#define byte$fromhex$value$48 0,1,0,0,1,0,0,0
#define byte$fromhex$value$49 0,1,0,0,1,0,0,1
#define byte$fromhex$value$4a 0,1,0,0,1,0,1,0
#define byte$fromhex$value$4b 0,1,0,0,1,0,1,1
#define byte$fromhex$value$4c 0,1,0,0,1,1,0,0
#define byte$fromhex$value$4d 0,1,0,0,1,1,0,1
#define byte$fromhex$value$4e 0,1,0,0,1,1,1,0
#define byte$fromhex$value$4f 0,1,0,0,1,1,1,1
#define byte$fromhex$value$50 0,1,0,1,0,0,0,0
#define byte$fromhex$value$51 0,1,0,1,0,0,0,1
#define byte$fromhex$value$52 0,1,0,1,0,0,1,0
#define byte$fromhex$value$53 0,1,0,1,0,0,1,1
#define byte$fromhex$value$54 0,1,0,1,0,1,0,0
#define byte$fromhex$value$55 0,1,0,1,0,1,0,1
#define byte$fromhex$value$56 0,1,0,1,0,1,1,0
#define byte$fromhex$value$57 0,1,0,1,0,1,1,1
#define byte$fromhex$value$58 0,1,0,1,1,0,0,0
#define byte$fromhex$value$59 0,1,0,1,1,0,0,1
#define byte$fromhex$value$5a 0,1,0,1,1,0,1,0
#define byte$fromhex$value$5b 0,1,0,1,1,0,1,1
#define byte$fromhex$value$5c 0,1,0,1,1,1,0,0
#define byte$fromhex$value$5d 0,1,0,1,1,1,0,1
#define byte$fromhex$value$5e 0,1,0,1,1,1,1,0
#define byte$fromhex$value$5f 0,1,0,1,1,1,1,1
#define byte$fromhex$value$60 0,1,1,0,0,0,0,0
#define byte$fromhex$value$61 0,1,1,0,0,0,0,1
#define byte$fromhex$value$62 0,1,1,0,0,0,1,0
#define byte$fromhex$value$63 0,1,1,0,0,0,1,1
#define byte$fromhex$value$64 0,1,1,0,0,1,0,0
#define byte$fromhex$value$65 0,1,1,0,0,1,0,1
#define byte$fromhex$value$66 0,1,1,0,0,1,1,0
#define byte$fromhex$value$67 0,1,1,0,0,1,1,1
#define byte$fromhex$value$68 0,1,1,0,1,0,0,0
#define byte$fromhex$value$69 0,1,1,0,1,0,0,1
#define byte$fromhex$value$6a 0,1,1,0,1,0,1,0
#define byte$fromhex$value$6b 0,1,1,0,1,0,1,1
#define byte$fromhex$value$6c 0,1,1,0,1,1,0,0
#define byte$fromhex$value$6d 0,1,1,0,1,1,0,1
#define byte$fromhex$value$6e 0,1,1,0,1,1,1,0
#define byte$fromhex$value$6f 0,1,1,0,1,1,1,1
#define byte$fromhex$value$70 0,1,1,1,0,0,0,0
#define byte$fromhex$value$71 0,1,1,1,0,0,0,1
#define byte$fromhex$value$72 0,1,1,1,0,0,1,0
#define byte$fromhex$value$73 0,1,1,1,0,0,1,1
#define byte$fromhex$value$74 0,1,1,1,0,1,0,0
#define byte$fromhex$value$75 0,1,1,1,0,1,0,1
#define byte$fromhex$value$76 0,1,1,1,0,1,1,0
#define byte$fromhex$value$77 0,1,1,1,0,1,1,1
#define byte$fromhex$value$78 0,1,1,1,1,0,0,0
#define byte$fromhex$value$79 0,1,1,1,1,0,0,1
#define byte$fromhex$value$7a 0,1,1,1,1,0,1,0
#define byte$fromhex$value$7b 0,1,1,1,1,0,1,1
#define byte$fromhex$value$7c 0,1,1,1,1,1,0,0
#define byte$fromhex$value$7d 0,1,1,1,1,1,0,1
#define byte$fromhex$value$7e 0,1,1,1,1,1,1,0
#define byte$fromhex$value$7f 0,1,1,1,1,1,1,1
#define byte$fromhex$value$80 1,0,0,0,0,0,0,0
#define byte$fromhex$value$81 1,0,0,0,0,0,0,1
#define byte$fromhex$value$82 1,0,0,0,0,0,1,0
#define byte$fromhex$value$83 1,0,0,0,0,0,1,1
#define byte$fromhex$value$84 1,0,0,0,0,1,0,0
#define byte$fromhex$value$85 1,0,0,0,0,1,0,1
#define byte$fromhex$value$86 1,0,0,0,0,1,1,0
#define byte$fromhex$value$87 1,0,0,0,0,1,1,1
#define byte$fromhex$value$88 1,0,0,0,1,0,0,0
#define byte$fromhex$value$89 1,0,0,0,1,0,0,1
#define byte$fromhex$value$8a 1,0,0,0,1,0,1,0
#define byte$fromhex$value$8b 1,0,0,0,1,0,1,1
#define byte$fromhex$value$8c 1,0,0,0,1,1,0,0
#define byte$fromhex$value$8d 1,0,0,0,1,1,0,1
#define byte$fromhex$value$8e 1,0,0,0,1,1,1,0
#define byte$fromhex$value$8f 1,0,0,0,1,1,1,1
#define byte$fromhex$value$90 1,0,0,1,0,0,0,0
#define byte$fromhex$value$91 1,0,0,1,0,0,0,1
#define byte$fromhex$value$92 1,0,0,1,0,0,1,0
#define byte$fromhex$value$93 1,0,0,1,0,0,1,1
#define byte$fromhex$value$94 1,0,0,1,0,1,0,0
#define byte$fromhex$value$95 1,0,0,1,0,1,0,1
#define byte$fromhex$value$96 1,0,0,1,0,1,1,0
#define byte$fromhex$value$97 1,0,0,1,0,1,1,1
#define byte$fromhex$value$98 1,0,0,1,1,0,0,0
#define byte$fromhex$value$99 1,0,0,1,1,0,0,1
#define byte$fromhex$value$9a 1,0,0,1,1,0,1,0
#define byte$fromhex$value$9b 1,0,0,1,1,0,1,1
#define byte$fromhex$value$9c 1,0,0,1,1,1,0,0
#define byte$fromhex$value$9d 1,0,0,1,1,1,0,1
#define byte$fromhex$value$9e 1,0,0,1,1,1,1,0
#define byte$fromhex$value$9f 1,0,0,1,1,1,1,1
#define byte$fromhex$value$a0 1,0,1,0,0,0,0,0
#define byte$fromhex$value$a1 1,0,1,0,0,0,0,1
#define byte$fromhex$value$a2 1,0,1,0,0,0,1,0
#define byte$fromhex$value$a3 1,0,1,0,0,0,1,1
#define byte$fromhex$value$a4 1,0,1,0,0,1,0,0
#define byte$fromhex$value$a5 1,0,1,0,0,1,0,1
#define byte$fromhex$value$a6 1,0,1,0,0,1,1,0
#define byte$fromhex$value$a7 1,0,1,0,0,1,1,1
#define byte$fromhex$value$a8 1,0,1,0,1,0,0,0
#define byte$fromhex$value$a9 1,0,1,0,1,0,0,1
#define byte$fromhex$value$aa 1,0,1,0,1,0,1,0
#define byte$fromhex$value$ab 1,0,1,0,1,0,1,1
#define byte$fromhex$value$ac 1,0,1,0,1,1,0,0
#define byte$fromhex$value$ad 1,0,1,0,1,1,0,1
#define byte$fromhex$value$ae 1,0,1,0,1,1,1,0
#define byte$fromhex$value$af 1,0,1,0,1,1,1,1
#define byte$fromhex$value$b0 1,0,1,1,0,0,0,0
#define byte$fromhex$value$b1 1,0,1,1,0,0,0,1
#define byte$fromhex$value$b2 1,0,1,1,0,0,1,0
#define byte$fromhex$value$b3 1,0,1,1,0,0,1,1
#define byte$fromhex$value$b4 1,0,1,1,0,1,0,0
#define byte$fromhex$value$b5 1,0,1,1,0,1,0,1
#define byte$fromhex$value$b6 1,0,1,1,0,1,1,0
#define byte$fromhex$value$b7 1,0,1,1,0,1,1,1
#define byte$fromhex$value$b8 1,0,1,1,1,0,0,0
#define byte$fromhex$value$b9 1,0,1,1,1,0,0,1
#define byte$fromhex$value$ba 1,0,1,1,1,0,1,0
#define byte$fromhex$value$bb 1,0,1,1,1,0,1,1
#define byte$fromhex$value$bc 1,0,1,1,1,1,0,0
#define byte$fromhex$value$bd 1,0,1,1,1,1,0,1
#define byte$fromhex$value$be 1,0,1,1,1,1,1,0
#define byte$fromhex$value$bf 1,0,1,1,1,1,1,1
#define byte$fromhex$value$c0 1,1,0,0,0,0,0,0
#define byte$fromhex$value$c1 1,1,0,0,0,0,0,1
#define byte$fromhex$value$c2 1,1,0,0,0,0,1,0
#define byte$fromhex$value$c3 1,1,0,0,0,0,1,1
#define byte$fromhex$value$c4 1,1,0,0,0,1,0,0
#define byte$fromhex$value$c5 1,1,0,0,0,1,0,1
#define byte$fromhex$value$c6 1,1,0,0,0,1,1,0
#define byte$fromhex$value$c7 1,1,0,0,0,1,1,1
#define byte$fromhex$value$c8 1,1,0,0,1,0,0,0
#define byte$fromhex$value$c9 1,1,0,0,1,0,0,1
#define byte$fromhex$value$ca 1,1,0,0,1,0,1,0
#define byte$fromhex$value$cb 1,1,0,0,1,0,1,1
#define byte$fromhex$value$cc 1,1,0,0,1,1,0,0
#define byte$fromhex$value$cd 1,1,0,0,1,1,0,1
#define byte$fromhex$value$ce 1,1,0,0,1,1,1,0
#define byte$fromhex$value$cf 1,1,0,0,1,1,1,1
#define byte$fromhex$value$d0 1,1,0,1,0,0,0,0
#define byte$fromhex$value$d1 1,1,0,1,0,0,0,1
#define byte$fromhex$value$d2 1,1,0,1,0,0,1,0
#define byte$fromhex$value$d3 1,1,0,1,0,0,1,1
#define byte$fromhex$value$d4 1,1,0,1,0,1,0,0
#define byte$fromhex$value$d5 1,1,0,1,0,1,0,1
#define byte$fromhex$value$d6 1,1,0,1,0,1,1,0
#define byte$fromhex$value$d7 1,1,0,1,0,1,1,1
#define byte$fromhex$value$d8 1,1,0,1,1,0,0,0
#define byte$fromhex$value$d9 1,1,0,1,1,0,0,1
#define byte$fromhex$value$da 1,1,0,1,1,0,1,0
#define byte$fromhex$value$db 1,1,0,1,1,0,1,1
#define byte$fromhex$value$dc 1,1,0,1,1,1,0,0
#define byte$fromhex$value$dd 1,1,0,1,1,1,0,1
#define byte$fromhex$value$de 1,1,0,1,1,1,1,0
#define byte$fromhex$value$df 1,1,0,1,1,1,1,1
#define byte$fromhex$value$e0 1,1,1,0,0,0,0,0
#define byte$fromhex$value$e1 1,1,1,0,0,0,0,1
#define byte$fromhex$value$e2 1,1,1,0,0,0,1,0
#define byte$fromhex$value$e3 1,1,1,0,0,0,1,1
#define byte$fromhex$value$e4 1,1,1,0,0,1,0,0
#define byte$fromhex$value$e5 1,1,1,0,0,1,0,1
#define byte$fromhex$value$e6 1,1,1,0,0,1,1,0
#define byte$fromhex$value$e7 1,1,1,0,0,1,1,1
#define byte$fromhex$value$e8 1,1,1,0,1,0,0,0
#define byte$fromhex$value$e9 1,1,1,0,1,0,0,1
#define byte$fromhex$value$ea 1,1,1,0,1,0,1,0
#define byte$fromhex$value$eb 1,1,1,0,1,0,1,1
#define byte$fromhex$value$ec 1,1,1,0,1,1,0,0
#define byte$fromhex$value$ed 1,1,1,0,1,1,0,1
#define byte$fromhex$value$ee 1,1,1,0,1,1,1,0
#define byte$fromhex$value$ef 1,1,1,0,1,1,1,1
#define byte$fromhex$value$f0 1,1,1,1,0,0,0,0
#define byte$fromhex$value$f1 1,1,1,1,0,0,0,1
#define byte$fromhex$value$f2 1,1,1,1,0,0,1,0
#define byte$fromhex$value$f3 1,1,1,1,0,0,1,1
#define byte$fromhex$value$f4 1,1,1,1,0,1,0,0
#define byte$fromhex$value$f5 1,1,1,1,0,1,0,1
#define byte$fromhex$value$f6 1,1,1,1,0,1,1,0
#define byte$fromhex$value$f7 1,1,1,1,0,1,1,1
#define byte$fromhex$value$f8 1,1,1,1,1,0,0,0
#define byte$fromhex$value$f9 1,1,1,1,1,0,0,1
#define byte$fromhex$value$fa 1,1,1,1,1,0,1,0
#define byte$fromhex$value$fb 1,1,1,1,1,0,1,1
#define byte$fromhex$value$fc 1,1,1,1,1,1,0,0
#define byte$fromhex$value$fd 1,1,1,1,1,1,0,1
#define byte$fromhex$value$fe 1,1,1,1,1,1,1,0
#define byte$fromhex$value$ff 1,1,1,1,1,1,1,1

// bit-wise operations on a whole byte
#define byte$or(...) byte$or$1(__VA_ARGS__)
#define byte$or$1(...) byte$or$2(__VA_ARGS__)
#define byte$or$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) bit$or(B0b7, B1b7), bit$or(B0b6, B1b6), bit$or(B0b5, B1b5), bit$or(B0b4, B1b4), bit$or(B0b3, B1b3), bit$or(B0b2, B1b2), bit$or(B0b1, B1b1), bit$or(B0b0, B1b0)
#define byte$and(...) byte$and$1(__VA_ARGS__)
#define byte$and$1(...) byte$and$2(__VA_ARGS__)
#define byte$and$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) bit$and(B0b7, B1b7), bit$and(B0b6, B1b6), bit$and(B0b5, B1b5), bit$and(B0b4, B1b4), bit$and(B0b3, B1b3), bit$and(B0b2, B1b2), bit$and(B0b1, B1b1), bit$and(B0b0, B1b0)
#define byte$xor(...) byte$xor$1(__VA_ARGS__)
#define byte$xor$1(...) byte$xor$2(__VA_ARGS__)
#define byte$xor$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) bit$xor(B0b7, B1b7), bit$xor(B0b6, B1b6), bit$xor(B0b5, B1b5), bit$xor(B0b4, B1b4), bit$xor(B0b3, B1b3), bit$xor(B0b2, B1b2), bit$xor(B0b1, B1b1), bit$xor(B0b0, B1b0)
#define byte$not(...) byte$inv$1(__VA_ARGS__)
#define byte$inv(...) byte$inv$1(__VA_ARGS__)
#define byte$inv$1(...) byte$inv$2(__VA_ARGS__)
#define byte$inv$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$not(B0b7), bit$not(B0b6), bit$not(B0b5), bit$not(B0b4), bit$not(B0b3), bit$not(B0b2), bit$not(B0b1), bit$not(B0b0)
#define byte$getbit(...) byte$getbit$1(__VA_ARGS__)
#define byte$getbit$1(...) byte$getbit$2(__VA_ARGS__)
#define byte$getbit$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) byte$getbit$no##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0)
#define byte$getbit$no00000000(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b0
#define byte$getbit$no00000001(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b1
#define byte$getbit$no00000010(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b2
#define byte$getbit$no00000011(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b3
#define byte$getbit$no00000100(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b4
#define byte$getbit$no00000101(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b5
#define byte$getbit$no00000110(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b6
#define byte$getbit$no00000111(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) B1b7
#define byte$iszero(...) byte$iszero$1(__VA_ARGS__)
#define byte$iszero$1(...) byte$iszero$2(__VA_ARGS__)
#define byte$iszero$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$not(bit$or(B0b0, bit$or(B0b1, bit$or(B0b2, bit$or(B0b3, bit$or(B0b4, bit$or(B0b5, bit$or(B0b6, B0b7))))))))
#define byte$eq(...) byte$iszero(byte$xor(__VA_ARGS__))
#define byte$neq(...) bit$not(byte$eq(__VA_ARGS__))

// bit-wise addition
#define bit$add(...) bit$add$1(__VA_ARGS__)
#define bit$add$1(...) bit$add$2(__VA_ARGS__)
#define bit$add$2(b0, b1, b2) bit$add$##b0##b1##b2
#define bit$add$000 0
#define bit$add$001 1
#define bit$add$010 1
#define bit$add$011 0
#define bit$add$100 1
#define bit$add$101 0
#define bit$add$110 0
#define bit$add$111 1
#define bit$adc(...) bit$adc$1(__VA_ARGS__)
#define bit$adc$1(...) bit$adc$2(__VA_ARGS__)
#define bit$adc$2(b0, b1, b2) bit$adc$##b0##b1##b2
#define bit$adc$000 0
#define bit$adc$001 0
#define bit$adc$010 0
#define bit$adc$011 1
#define bit$adc$100 0
#define bit$adc$101 1
#define bit$adc$110 1
#define bit$adc$111 1

// byte-wise addition
#define byte$addo(...) byte$addo$1(__VA_ARGS__)
#define byte$addo$1(...) byte$addo$2(__VA_ARGS__)
#define byte$addo$2(ci, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) byte$addo$off0$0(ci, 0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0)
#define byte$add(...) byte$add$1(__VA_ARGS__)
#define byte$add$1(...) byte$add$2(__VA_ARGS__)
#define byte$add$2(ci, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) byte$add$off0$0(ci, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0)
#define byte$addwithflags(...) byte$add$1(__VA_ARGS__)
#define byte$addwithoutflags(...) byte$add$removeflags(byte$add$1(__VA_ARGS__))
#define byte$add$removeflags(...) byte$add$removeflags$1(__VA_ARGS__)
#define byte$add$removeflags$1(...) byte$add$removeflags$2(__VA_ARGS__)
#define byte$add$removeflags$2(c,o, ...) __VA_ARGS__
#define byte$add$getcarry(...) byte$add$getcarry$1(__VA_ARGS__)
#define byte$add$getcarry$1(...) byte$add$getcarry$2(__VA_ARGS__)
#define byte$add$getcarry$2(c,o, ...) c
#define byte$add$getoverflow(...) byte$add$getoverflow$1(__VA_ARGS__)
#define byte$add$getoverflow$1(...) byte$add$getoverflow$2(__VA_ARGS__)
#define byte$add$getoverflow$2(c,o, ...) o
#define byte$addo$off8$0(c,c2,...) c, bit$xor(c,c2)
#define byte$addo$off0$0(...) byte$addo$off0$1(__VA_ARGS__)
#define byte$addo$off0$1(...) byte$addo$off0$2(__VA_ARGS__)
#define byte$addo$off0$2(c, o,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) byte$addo$off1$0(bit$adc(B0b0, B1b0, c),c,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1), bit$add(B0b0, B1b0, c)
#define byte$addo$off1$0(...) byte$addo$off1$1(__VA_ARGS__)
#define byte$addo$off1$1(...) byte$addo$off1$2(__VA_ARGS__)
#define byte$addo$off1$2(c, o,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1) byte$addo$off2$0(bit$adc(B0b1, B1b1, c),c,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2), bit$add(B0b1, B1b1, c)
#define byte$addo$off2$0(...) byte$addo$off2$1(__VA_ARGS__)
#define byte$addo$off2$1(...) byte$addo$off2$2(__VA_ARGS__)
#define byte$addo$off2$2(c, o,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2) byte$addo$off3$0(bit$adc(B0b2, B1b2, c),c,B0b7, B0b6, B0b5, B0b4, B0b3, B1b7, B1b6, B1b5, B1b4, B1b3), bit$add(B0b2, B1b2, c)
#define byte$addo$off3$0(...) byte$addo$off3$1(__VA_ARGS__)
#define byte$addo$off3$1(...) byte$addo$off3$2(__VA_ARGS__)
#define byte$addo$off3$2(c, o,B0b7, B0b6, B0b5, B0b4, B0b3, B1b7, B1b6, B1b5, B1b4, B1b3) byte$addo$off4$0(bit$adc(B0b3, B1b3, c),c,B0b7, B0b6, B0b5, B0b4, B1b7, B1b6, B1b5, B1b4), bit$add(B0b3, B1b3, c)
#define byte$addo$off4$0(...) byte$addo$off4$1(__VA_ARGS__)
#define byte$addo$off4$1(...) byte$addo$off4$2(__VA_ARGS__)
#define byte$addo$off4$2(c, o,B0b7, B0b6, B0b5, B0b4, B1b7, B1b6, B1b5, B1b4) byte$addo$off5$0(bit$adc(B0b4, B1b4, c),c,B0b7, B0b6, B0b5, B1b7, B1b6, B1b5), bit$add(B0b4, B1b4, c)
#define byte$addo$off5$0(...) byte$addo$off5$1(__VA_ARGS__)
#define byte$addo$off5$1(...) byte$addo$off5$2(__VA_ARGS__)
#define byte$addo$off5$2(c, o,B0b7, B0b6, B0b5, B1b7, B1b6, B1b5) byte$addo$off6$0(bit$adc(B0b5, B1b5, c),c,B0b7, B0b6, B1b7, B1b6), bit$add(B0b5, B1b5, c)
#define byte$addo$off6$0(...) byte$addo$off6$1(__VA_ARGS__)
#define byte$addo$off6$1(...) byte$addo$off6$2(__VA_ARGS__)
#define byte$addo$off6$2(c, o,B0b7, B0b6, B1b7, B1b6) byte$addo$off7$0(bit$adc(B0b6, B1b6, c),c,B0b7, B1b7), bit$add(B0b6, B1b6, c)
#define byte$addo$off7$0(...) byte$addo$off7$1(__VA_ARGS__)
#define byte$addo$off7$1(...) byte$addo$off7$2(__VA_ARGS__)
#define byte$addo$off7$2(c, o,B0b7, B1b7) byte$addo$off8$0(bit$adc(B0b7, B1b7, c),c,), bit$add(B0b7, B1b7, c)
#define byte$add$off8$0(c,...) c
#define byte$add$off0$0(...) byte$add$off0$1(__VA_ARGS__)
#define byte$add$off0$1(...) byte$add$off0$2(__VA_ARGS__)
#define byte$add$off0$2(c,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0) byte$add$off1$0(bit$adc(B0b0, B1b0, c),B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1), bit$add(B0b0, B1b0, c)
#define byte$add$off1$0(...) byte$add$off1$1(__VA_ARGS__)
#define byte$add$off1$1(...) byte$add$off1$2(__VA_ARGS__)
#define byte$add$off1$2(c,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1) byte$add$off2$0(bit$adc(B0b1, B1b1, c),B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2), bit$add(B0b1, B1b1, c)
#define byte$add$off2$0(...) byte$add$off2$1(__VA_ARGS__)
#define byte$add$off2$1(...) byte$add$off2$2(__VA_ARGS__)
#define byte$add$off2$2(c,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2) byte$add$off3$0(bit$adc(B0b2, B1b2, c),B0b7, B0b6, B0b5, B0b4, B0b3, B1b7, B1b6, B1b5, B1b4, B1b3), bit$add(B0b2, B1b2, c)
#define byte$add$off3$0(...) byte$add$off3$1(__VA_ARGS__)
#define byte$add$off3$1(...) byte$add$off3$2(__VA_ARGS__)
#define byte$add$off3$2(c,B0b7, B0b6, B0b5, B0b4, B0b3, B1b7, B1b6, B1b5, B1b4, B1b3) byte$add$off4$0(bit$adc(B0b3, B1b3, c),B0b7, B0b6, B0b5, B0b4, B1b7, B1b6, B1b5, B1b4), bit$add(B0b3, B1b3, c)
#define byte$add$off4$0(...) byte$add$off4$1(__VA_ARGS__)
#define byte$add$off4$1(...) byte$add$off4$2(__VA_ARGS__)
#define byte$add$off4$2(c,B0b7, B0b6, B0b5, B0b4, B1b7, B1b6, B1b5, B1b4) byte$add$off5$0(bit$adc(B0b4, B1b4, c),B0b7, B0b6, B0b5, B1b7, B1b6, B1b5), bit$add(B0b4, B1b4, c)
#define byte$add$off5$0(...) byte$add$off5$1(__VA_ARGS__)
#define byte$add$off5$1(...) byte$add$off5$2(__VA_ARGS__)
#define byte$add$off5$2(c,B0b7, B0b6, B0b5, B1b7, B1b6, B1b5) byte$add$off6$0(bit$adc(B0b5, B1b5, c),B0b7, B0b6, B1b7, B1b6), bit$add(B0b5, B1b5, c)
#define byte$add$off6$0(...) byte$add$off6$1(__VA_ARGS__)
#define byte$add$off6$1(...) byte$add$off6$2(__VA_ARGS__)
#define byte$add$off6$2(c,B0b7, B0b6, B1b7, B1b6) byte$add$off7$0(bit$adc(B0b6, B1b6, c),B0b7, B1b7), bit$add(B0b6, B1b6, c)
#define byte$add$off7$0(...) byte$add$off7$1(__VA_ARGS__)
#define byte$add$off7$1(...) byte$add$off7$2(__VA_ARGS__)
#define byte$add$off7$2(c,B0b7, B1b7) byte$add$off8$0(bit$adc(B0b7, B1b7, c),), bit$add(B0b7, B1b7, c)

// comparison
#define cmp$iseq(c,o,s,z) z
#define cmp$isneq(c,o,s,z) bit$not(z)
#define cmp$isa(c,o,s,z) bit$and(c, bit$not(z))
#define cmp$isae(c,o,s,z) bit$or(c, z)
#define cmp$isb(c,o,s,z) bit$and(bit$not(c), bit$not(z))
#define cmp$isbe(c,o,s,z) bit$or(z, bit$not(c))
#define cmp$isg(c,o,s,z) bit$and(bit$eq(s, o), bit$not(z))
#define cmp$isge(c,o,s,z) bit$eq(s, o)
#define cmp$isl(c,o,s,z) bit$xor(s, o)
#define cmp$isle(c,o,s,z) bit$or(bit$xor(s, o), z)
#define cmp$call(...) cmp$call$1(__VA_ARGS__)
#define cmp$call$1(...) cmp$call$2(__VA_ARGS__)
#define cmp$call$2(f,...) f(__VA_ARGS__)

// reduce byte to bit
#define byte$any(...) byte$any$1(__VA_ARGS__)
#define byte$any$1(...) byte$any$2(__VA_ARGS__)
#define byte$any$2(...) bit$any8(__VA_ARGS__)
#define byte$all(...) byte$all$1(__VA_ARGS__)
#define byte$all$1(...) byte$all$2(__VA_ARGS__)
#define byte$all$2(...) bit$all8(__VA_ARGS__)

// iNN type constants
#define repeat8(x) x,x,x,x,x,x,x,x
#define repeat16(x) repeat8(x),repeat8(x)
#define repeat32(x) repeat16(x),repeat16(x)
#define repeat64(x) repeat32(x),repeat32(x)
#define i08$zero repeat8(0)
#define i16$zero repeat16(0)
#define i32$zero repeat32(0)
#define i64$zero repeat64(0)
#define i08$one 0,0,0,0,0,0,0,1
#define i16$one repeat8(0),i08$one
#define i32$one repeat16(0),i16$one
#define i64$one repeat32(0),i32$one
#define i08$umax repeat8(1)
#define i16$umax repeat16(1)
#define i32$umax repeat32(1)
#define i64$umax repeat64(1)
#define i08$smax 0,1,1,1,1,1,1,1
#define i16$smax i08$smax, repeat8(1)
#define i32$smax i16$smax, repeat16(1)
#define i64$smax i32$smax, repeat32(1)
#define i08$smin 1,0,0,0,0,0,0,0
#define i16$smin i08$smin, repeat8(0)
#define i32$smin i16$smin, repeat16(0)
#define i64$smin i32$smin, repeat32(0)

// iNN type byte access
#define i08$getbyte(...) i08$getbyte$1(__VA_ARGS__)
#define i08$getbyte$1(...) i08$getbyte$2(__VA_ARGS__)
#define i08$getbyte$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i08$getbyte$byte##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i08$getbyte$byte00000000(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i16$getbyte(...) i16$getbyte$1(__VA_ARGS__)
#define i16$getbyte$1(...) i16$getbyte$2(__VA_ARGS__)
#define i16$getbyte$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i16$getbyte$byte##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i16$getbyte$byte00000000(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i16$getbyte$byte00000001(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0
#define i32$getbyte(...) i32$getbyte$1(__VA_ARGS__)
#define i32$getbyte$1(...) i32$getbyte$2(__VA_ARGS__)
#define i32$getbyte$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i32$getbyte$byte##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i32$getbyte$byte00000000(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i32$getbyte$byte00000001(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0
#define i32$getbyte$byte00000010(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0
#define i32$getbyte$byte00000011(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0
#define i64$getbyte(...) i64$getbyte$1(__VA_ARGS__)
#define i64$getbyte$1(...) i64$getbyte$2(__VA_ARGS__)
#define i64$getbyte$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i64$getbyte$byte##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i64$getbyte$byte00000000(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i64$getbyte$byte00000001(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0
#define i64$getbyte$byte00000010(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0
#define i64$getbyte$byte00000011(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0
#define i64$getbyte$byte00000100(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0
#define i64$getbyte$byte00000101(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0
#define i64$getbyte$byte00000110(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0
#define i64$getbyte$byte00000111(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0

// iNN to/from hex conversion
#define i08$fromhex(...) i08$fromhex$1(__VA_ARGS__)
#define i08$fromhex$1(...) i08$fromhex$2(__VA_ARGS__)
#define i08$fromhex$2(h0) byte$fromhex(h0)
#define i16$fromhex(...) i16$fromhex$1(__VA_ARGS__)
#define i16$fromhex$1(...) i16$fromhex$2(__VA_ARGS__)
#define i16$fromhex$2(h1,h0) byte$fromhex(h1), byte$fromhex(h0)
#define i32$fromhex(...) i32$fromhex$1(__VA_ARGS__)
#define i32$fromhex$1(...) i32$fromhex$2(__VA_ARGS__)
#define i32$fromhex$2(h3,h2,h1,h0) byte$fromhex(h3), byte$fromhex(h2), byte$fromhex(h1), byte$fromhex(h0)
#define i64$fromhex(...) i64$fromhex$1(__VA_ARGS__)
#define i64$fromhex$1(...) i64$fromhex$2(__VA_ARGS__)
#define i64$fromhex$2(h7,h6,h5,h4,h3,h2,h1,h0) byte$fromhex(h7), byte$fromhex(h6), byte$fromhex(h5), byte$fromhex(h4), byte$fromhex(h3), byte$fromhex(h2), byte$fromhex(h1), byte$fromhex(h0)
#define i08$tohex(...) i08$tohex$1(__VA_ARGS__)
#define i08$tohex$1(...) i08$tohex$2(__VA_ARGS__)
#define i08$tohex$2(p,j,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) byte$tohex(p, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i16$tohex(...) i16$tohex$1(__VA_ARGS__)
#define i16$tohex$1(...) i16$tohex$2(__VA_ARGS__)
#define i16$tohex$2(p,j,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) j(byte$tohex(p, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), byte$tohex(p, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i32$tohex(...) i32$tohex$1(__VA_ARGS__)
#define i32$tohex$1(...) i32$tohex$2(__VA_ARGS__)
#define i32$tohex$2(p,j,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) j(byte$tohex(p, B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0), j(byte$tohex(p, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0), j(byte$tohex(p, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), byte$tohex(p, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))))
#define i64$tohex(...) i64$tohex$1(__VA_ARGS__)
#define i64$tohex$1(...) i64$tohex$2(__VA_ARGS__)
#define i64$tohex$2(p,j,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) j(byte$tohex(p, B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0), j(byte$tohex(p, B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0), j(byte$tohex(p, B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0), j(byte$tohex(p, B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0), j(byte$tohex(p, B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0), j(byte$tohex(p, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0), j(byte$tohex(p, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), byte$tohex(p, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))))))))

// zero/sign-extend, shrink
#define i08$sx16(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat8(B0b7), B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i08$sx32(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat16(B0b7), repeat8(B0b7), B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i08$sx64(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat32(B0b7), repeat16(B0b7), repeat8(B0b7), B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i16$sx32(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat16(B1b7), B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i16$sx64(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat32(B1b7), repeat16(B1b7), B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i32$sx64(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat32(B3b7), B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i08$zx16(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat8(0), B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i08$zx32(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat16(0), repeat8(0), B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i08$zx64(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat32(0), repeat16(0), repeat32(0), B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i16$zx32(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat16(0), B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0
#define i16$zx64(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat32(0), repeat16(0), B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i32$zx64(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) repeat32(0), B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i16$to08(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i32$to08(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i32$to16(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i64$to08(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i64$to16(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0
#define i64$to32(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0

// iNN bit-wise operations
#define i08$bit1op(...) i08$bit1op$1(__VA_ARGS__)
#define i08$bit1op$1(...) i08$bit1op$2(__VA_ARGS__)
#define i08$bit1op$2(op,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i08$bit2op(...) i08$bit2op$1(__VA_ARGS__)
#define i08$bit2op$1(...) i08$bit2op$2(__VA_ARGS__)
#define i08$bit2op$2(op,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i16$bit1op(...) i16$bit1op$1(__VA_ARGS__)
#define i16$bit1op$1(...) i16$bit1op$2(__VA_ARGS__)
#define i16$bit1op$2(op,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), op(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i16$bit2op(...) i16$bit2op$1(__VA_ARGS__)
#define i16$bit2op$1(...) i16$bit2op$2(__VA_ARGS__)
#define i16$bit2op$2(op,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), op(B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i32$bit1op(...) i32$bit1op$1(__VA_ARGS__)
#define i32$bit1op$1(...) i32$bit1op$2(__VA_ARGS__)
#define i32$bit1op$2(op,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0), op(B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0), op(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), op(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i32$bit2op(...) i32$bit2op$1(__VA_ARGS__)
#define i32$bit2op$1(...) i32$bit2op$2(__VA_ARGS__)
#define i32$bit2op$2(op,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0, B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0), op(B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0), op(B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), op(B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i64$bit1op(...) i64$bit1op$1(__VA_ARGS__)
#define i64$bit1op$1(...) i64$bit1op$2(__VA_ARGS__)
#define i64$bit1op$2(op,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0), op(B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0), op(B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0), op(B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0), op(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0), op(B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0), op(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), op(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i64$bit2op(...) i64$bit2op$1(__VA_ARGS__)
#define i64$bit2op$1(...) i64$bit2op$2(__VA_ARGS__)
#define i64$bit2op$2(op,BFb7, BFb6, BFb5, BFb4, BFb3, BFb2, BFb1, BFb0,BEb7, BEb6, BEb5, BEb4, BEb3, BEb2, BEb1, BEb0,BDb7, BDb6, BDb5, BDb4, BDb3, BDb2, BDb1, BDb0,BCb7, BCb6, BCb5, BCb4, BCb3, BCb2, BCb1, BCb0,BBb7, BBb6, BBb5, BBb4, BBb3, BBb2, BBb1, BBb0,BAb7, BAb6, BAb5, BAb4, BAb3, BAb2, BAb1, BAb0,B9b7, B9b6, B9b5, B9b4, B9b3, B9b2, B9b1, B9b0,B8b7, B8b6, B8b5, B8b4, B8b3, B8b2, B8b1, B8b0,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) op(BFb7, BFb6, BFb5, BFb4, BFb3, BFb2, BFb1, BFb0, B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0), op(BEb7, BEb6, BEb5, BEb4, BEb3, BEb2, BEb1, BEb0, B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0), op(BDb7, BDb6, BDb5, BDb4, BDb3, BDb2, BDb1, BDb0, B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0), op(BCb7, BCb6, BCb5, BCb4, BCb3, BCb2, BCb1, BCb0, B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0), op(BBb7, BBb6, BBb5, BBb4, BBb3, BBb2, BBb1, BBb0, B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0), op(BAb7, BAb6, BAb5, BAb4, BAb3, BAb2, BAb1, BAb0, B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0), op(B9b7, B9b6, B9b5, B9b4, B9b3, B9b2, B9b1, B9b0, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0), op(B8b7, B8b6, B8b5, B8b4, B8b3, B8b2, B8b1, B8b0, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i08$inv(...) i08$bit1op(byte$inv,__VA_ARGS__)
#define i08$or(...) i08$bit2op(byte$or,__VA_ARGS__)
#define i08$and(...) i08$bit2op(byte$and,__VA_ARGS__)
#define i08$xor(...) i08$bit2op(byte$xor,__VA_ARGS__)
#define i16$inv(...) i16$bit1op(byte$inv,__VA_ARGS__)
#define i16$or(...) i16$bit2op(byte$or,__VA_ARGS__)
#define i16$and(...) i16$bit2op(byte$and,__VA_ARGS__)
#define i16$xor(...) i16$bit2op(byte$xor,__VA_ARGS__)
#define i32$inv(...) i32$bit1op(byte$inv,__VA_ARGS__)
#define i32$or(...) i32$bit2op(byte$or,__VA_ARGS__)
#define i32$and(...) i32$bit2op(byte$and,__VA_ARGS__)
#define i32$xor(...) i32$bit2op(byte$xor,__VA_ARGS__)
#define i64$inv(...) i64$bit1op(byte$inv,__VA_ARGS__)
#define i64$or(...) i64$bit2op(byte$or,__VA_ARGS__)
#define i64$and(...) i64$bit2op(byte$and,__VA_ARGS__)
#define i64$xor(...) i64$bit2op(byte$xor,__VA_ARGS__)

// iNN comparison-with-0 operations
#define i08$isnonzero(...) i08$isnonzero$1(__VA_ARGS__)
#define i08$isnonzero$1(...) i08$isnonzero$2(__VA_ARGS__)
#define i08$isnonzero$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) byte$any(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i16$isnonzero(...) i16$isnonzero$1(__VA_ARGS__)
#define i16$isnonzero$1(...) i16$isnonzero$2(__VA_ARGS__)
#define i16$isnonzero$2(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$any2(i16$bit1op(byte$any,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i32$isnonzero(...) i32$isnonzero$1(__VA_ARGS__)
#define i32$isnonzero$1(...) i32$isnonzero$2(__VA_ARGS__)
#define i32$isnonzero$2(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$any4(i32$bit1op(byte$any,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i64$isnonzero(...) i64$isnonzero$1(__VA_ARGS__)
#define i64$isnonzero$1(...) i64$isnonzero$2(__VA_ARGS__)
#define i64$isnonzero$2(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$any8(i64$bit1op(byte$any,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i08$iszero(...) i08$iszero$1(__VA_ARGS__)
#define i08$iszero$1(...) i08$iszero$2(__VA_ARGS__)
#define i08$iszero$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) byte$iszero(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0)
#define i16$iszero(...) i16$iszero$1(__VA_ARGS__)
#define i16$iszero$1(...) i16$iszero$2(__VA_ARGS__)
#define i16$iszero$2(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$all2(i16$bit1op(byte$iszero,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i32$iszero(...) i32$iszero$1(__VA_ARGS__)
#define i32$iszero$1(...) i32$iszero$2(__VA_ARGS__)
#define i32$iszero$2(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$all4(i32$bit1op(byte$iszero,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i64$iszero(...) i64$iszero$1(__VA_ARGS__)
#define i64$iszero$1(...) i64$iszero$2(__VA_ARGS__)
#define i64$iszero$2(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$all8(i64$bit1op(byte$iszero,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i08$isneg(...) i08$isneg$1(__VA_ARGS__)
#define i08$isneg$1(...) i08$isneg$2(__VA_ARGS__)
#define i08$isneg$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B0b7
#define i16$isneg(...) i16$isneg$1(__VA_ARGS__)
#define i16$isneg$1(...) i16$isneg$2(__VA_ARGS__)
#define i16$isneg$2(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B1b7
#define i32$isneg(...) i32$isneg$1(__VA_ARGS__)
#define i32$isneg$1(...) i32$isneg$2(__VA_ARGS__)
#define i32$isneg$2(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B3b7
#define i64$isneg(...) i64$isneg$1(__VA_ARGS__)
#define i64$isneg$1(...) i64$isneg$2(__VA_ARGS__)
#define i64$isneg$2(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) B7b7
#define i08$isnegorzero(...) bit$or(i08$iszero(__VA_ARGS__),i08$isneg(__VA_ARGS__))
#define i16$isnegorzero(...) bit$or(i16$iszero(__VA_ARGS__),i16$isneg(__VA_ARGS__))
#define i32$isnegorzero(...) bit$or(i32$iszero(__VA_ARGS__),i32$isneg(__VA_ARGS__))
#define i64$isnegorzero(...) bit$or(i64$iszero(__VA_ARGS__),i64$isneg(__VA_ARGS__))
#define i08$isposorzero(...) i08$isposorzero$1(__VA_ARGS__)
#define i08$isposorzero$1(...) i08$isposorzero$2(__VA_ARGS__)
#define i08$isposorzero$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$not(B0b7)
#define i16$isposorzero(...) i16$isposorzero$1(__VA_ARGS__)
#define i16$isposorzero$1(...) i16$isposorzero$2(__VA_ARGS__)
#define i16$isposorzero$2(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$not(B1b7)
#define i32$isposorzero(...) i32$isposorzero$1(__VA_ARGS__)
#define i32$isposorzero$1(...) i32$isposorzero$2(__VA_ARGS__)
#define i32$isposorzero$2(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$not(B3b7)
#define i64$isposorzero(...) i64$isposorzero$1(__VA_ARGS__)
#define i64$isposorzero$1(...) i64$isposorzero$2(__VA_ARGS__)
#define i64$isposorzero$2(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) bit$not(B7b7)
#define i08$ispos(...) bit$and(i08$isposorzero(__VA_ARGS__),i08$isnonzero(__VA_ARGS__))
#define i16$ispos(...) bit$and(i16$isposorzero(__VA_ARGS__),i16$isnonzero(__VA_ARGS__))
#define i32$ispos(...) bit$and(i32$isposorzero(__VA_ARGS__),i32$isnonzero(__VA_ARGS__))
#define i64$ispos(...) bit$and(i64$isposorzero(__VA_ARGS__),i64$isnonzero(__VA_ARGS__))

// iNN comparison and equality test
#define i08$iseq(...) i08$iszero(i08$xor(__VA_ARGS__))
#define i08$isneq(...) i08$isnonzero(i08$xor(__VA_ARGS__))
#define i08$isa(...) cmp$call(cmp$isa, i08$cmp(__VA_ARGS__))
#define i08$isae(...) cmp$call(cmp$isae, i08$cmp(__VA_ARGS__))
#define i08$isb(...) cmp$call(cmp$isb, i08$cmp(__VA_ARGS__))
#define i08$isbe(...) cmp$call(cmp$isbe, i08$cmp(__VA_ARGS__))
#define i08$isge(...) cmp$call(cmp$isge, i08$cmp(__VA_ARGS__))
#define i08$isgt(...) cmp$call(cmp$isg, i08$cmp(__VA_ARGS__))
#define i08$isle(...) cmp$call(cmp$isle, i08$cmp(__VA_ARGS__))
#define i08$islt(...) cmp$call(cmp$isl, i08$cmp(__VA_ARGS__))
#define i16$iseq(...) i16$iszero(i16$xor(__VA_ARGS__))
#define i16$isneq(...) i16$isnonzero(i16$xor(__VA_ARGS__))
#define i16$isa(...) cmp$call(cmp$isa, i16$cmp(__VA_ARGS__))
#define i16$isae(...) cmp$call(cmp$isae, i16$cmp(__VA_ARGS__))
#define i16$isb(...) cmp$call(cmp$isb, i16$cmp(__VA_ARGS__))
#define i16$isbe(...) cmp$call(cmp$isbe, i16$cmp(__VA_ARGS__))
#define i16$isge(...) cmp$call(cmp$isge, i16$cmp(__VA_ARGS__))
#define i16$isgt(...) cmp$call(cmp$isg, i16$cmp(__VA_ARGS__))
#define i16$isle(...) cmp$call(cmp$isle, i16$cmp(__VA_ARGS__))
#define i16$islt(...) cmp$call(cmp$isl, i16$cmp(__VA_ARGS__))
#define i32$iseq(...) i32$iszero(i32$xor(__VA_ARGS__))
#define i32$isneq(...) i32$isnonzero(i32$xor(__VA_ARGS__))
#define i32$isa(...) cmp$call(cmp$isa, i32$cmp(__VA_ARGS__))
#define i32$isae(...) cmp$call(cmp$isae, i32$cmp(__VA_ARGS__))
#define i32$isb(...) cmp$call(cmp$isb, i32$cmp(__VA_ARGS__))
#define i32$isbe(...) cmp$call(cmp$isbe, i32$cmp(__VA_ARGS__))
#define i32$isge(...) cmp$call(cmp$isge, i32$cmp(__VA_ARGS__))
#define i32$isgt(...) cmp$call(cmp$isg, i32$cmp(__VA_ARGS__))
#define i32$isle(...) cmp$call(cmp$isle, i32$cmp(__VA_ARGS__))
#define i32$islt(...) cmp$call(cmp$isl, i32$cmp(__VA_ARGS__))
#define i64$iseq(...) i64$iszero(i64$xor(__VA_ARGS__))
#define i64$isneq(...) i64$isnonzero(i64$xor(__VA_ARGS__))
#define i64$isa(...) cmp$call(cmp$isa, i64$cmp(__VA_ARGS__))
#define i64$isae(...) cmp$call(cmp$isae, i64$cmp(__VA_ARGS__))
#define i64$isb(...) cmp$call(cmp$isb, i64$cmp(__VA_ARGS__))
#define i64$isbe(...) cmp$call(cmp$isbe, i64$cmp(__VA_ARGS__))
#define i64$isge(...) cmp$call(cmp$isge, i64$cmp(__VA_ARGS__))
#define i64$isgt(...) cmp$call(cmp$isg, i64$cmp(__VA_ARGS__))
#define i64$isle(...) cmp$call(cmp$isle, i64$cmp(__VA_ARGS__))
#define i64$islt(...) cmp$call(cmp$isl, i64$cmp(__VA_ARGS__))

// iNN shift/rotate operations
#define i08$lshift(...) i08$lshift$1(__VA_ARGS__)
#define i08$lshift$1(...) i08$lshift$2(__VA_ARGS__)
#define i08$lshift$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i08$lshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i08$lshift$by00000000(b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0
#define i08$lshift$by00000001(b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, 0
#define i08$lshift$by00000010(b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, 0, 0
#define i08$lshift$by00000011(b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, 0, 0, 0
#define i08$lshift$by00000100(b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, 0, 0, 0, 0
#define i08$lshift$by00000101(b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, 0, 0, 0, 0, 0
#define i08$lshift$by00000110(b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, 0, 0, 0, 0, 0, 0
#define i08$lshift$by00000111(b7,b6,b5,b4,b3,b2,b1,b0) b0, 0, 0, 0, 0, 0, 0, 0
#define i08$rshift$zx(...) i08$rshift$zx$1(__VA_ARGS__)
#define i08$rshift$zx$1(...) i08$rshift$zx$2(__VA_ARGS__)
#define i08$rshift$zx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i08$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(0, __VA_ARGS__)
#define i08$rshift$sx(...) i08$rshift$sx$1( __VA_ARGS__)
#define i08$rshift$sx$1(...) i08$rshift$sx$2(__VA_ARGS__)
#define i08$rshift$sx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,hb,...) i08$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(hb, hb, __VA_ARGS__)
#define i08$rshift$by00000000(f, b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0
#define i08$rshift$by00000001(f, b7,b6,b5,b4,b3,b2,b1,b0) f, b7, b6, b5, b4, b3, b2, b1
#define i08$rshift$by00000010(f, b7,b6,b5,b4,b3,b2,b1,b0) f, f, b7, b6, b5, b4, b3, b2
#define i08$rshift$by00000011(f, b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, b7, b6, b5, b4, b3
#define i08$rshift$by00000100(f, b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, b7, b6, b5, b4
#define i08$rshift$by00000101(f, b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, b7, b6, b5
#define i08$rshift$by00000110(f, b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, b7, b6
#define i08$rshift$by00000111(f, b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, b7
#define i08$lrot(...) i08$lrot$1(__VA_ARGS__)
#define i08$lrot$1(...) i08$lrot$2(__VA_ARGS__)
#define i08$lrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i08$lrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i08$lrot$by00000000(b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0
#define i08$lrot$by00000001(b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b7
#define i08$lrot$by00000010(b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b7, b6
#define i08$lrot$by00000011(b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b7, b6, b5
#define i08$lrot$by00000100(b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b7, b6, b5, b4
#define i08$lrot$by00000101(b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b7, b6, b5, b4, b3
#define i08$lrot$by00000110(b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b7, b6, b5, b4, b3, b2
#define i08$lrot$by00000111(b7,b6,b5,b4,b3,b2,b1,b0) b0, b7, b6, b5, b4, b3, b2, b1
#define i08$rrot(...) i08$rrot$1(__VA_ARGS__)
#define i08$rrot$1(...) i08$rrot$2(__VA_ARGS__)
#define i08$rrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i08$rrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i08$rrot$by00000000(b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0
#define i08$rrot$by00000001(b7,b6,b5,b4,b3,b2,b1,b0) b0, b7, b6, b5, b4, b3, b2, b1
#define i08$rrot$by00000010(b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b7, b6, b5, b4, b3, b2
#define i08$rrot$by00000011(b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b7, b6, b5, b4, b3
#define i08$rrot$by00000100(b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b7, b6, b5, b4
#define i08$rrot$by00000101(b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b7, b6, b5
#define i08$rrot$by00000110(b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b7, b6
#define i08$rrot$by00000111(b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b7
#define i16$lshift(...) i16$lshift$1(__VA_ARGS__)
#define i16$lshift$1(...) i16$lshift$2(__VA_ARGS__)
#define i16$lshift$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i16$lshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i16$lshift$by00000000(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i16$lshift$by00000001(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0
#define i16$lshift$by00000010(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0
#define i16$lshift$by00000011(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0
#define i16$lshift$by00000100(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0
#define i16$lshift$by00000101(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0
#define i16$lshift$by00000110(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00000111(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001000(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001001(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001010(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001011(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001100(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001101(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001110(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$lshift$by00001111(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i16$rshift$zx(...) i16$rshift$zx$1(__VA_ARGS__)
#define i16$rshift$zx$1(...) i16$rshift$zx$2(__VA_ARGS__)
#define i16$rshift$zx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i16$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(0, __VA_ARGS__)
#define i16$rshift$sx(...) i16$rshift$sx$1( __VA_ARGS__)
#define i16$rshift$sx$1(...) i16$rshift$sx$2(__VA_ARGS__)
#define i16$rshift$sx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,hb,...) i16$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(hb, hb, __VA_ARGS__)
#define i16$rshift$by00000000(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i16$rshift$by00000001(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i16$rshift$by00000010(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i16$rshift$by00000011(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i16$rshift$by00000100(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i16$rshift$by00000101(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i16$rshift$by00000110(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i16$rshift$by00000111(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i16$rshift$by00001000(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, b15, b14, b13, b12, b11, b10, b9, b8
#define i16$rshift$by00001001(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, b15, b14, b13, b12, b11, b10, b9
#define i16$rshift$by00001010(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, b15, b14, b13, b12, b11, b10
#define i16$rshift$by00001011(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, b15, b14, b13, b12, b11
#define i16$rshift$by00001100(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, b15, b14, b13, b12
#define i16$rshift$by00001101(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, b15, b14, b13
#define i16$rshift$by00001110(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, b15, b14
#define i16$rshift$by00001111(f, b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b15
#define i16$lrot(...) i16$lrot$1(__VA_ARGS__)
#define i16$lrot$1(...) i16$lrot$2(__VA_ARGS__)
#define i16$lrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i16$lrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i16$lrot$by00000000(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i16$lrot$by00000001(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15
#define i16$lrot$by00000010(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14
#define i16$lrot$by00000011(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13
#define i16$lrot$by00000100(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12
#define i16$lrot$by00000101(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11
#define i16$lrot$by00000110(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10
#define i16$lrot$by00000111(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9
#define i16$lrot$by00001000(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8
#define i16$lrot$by00001001(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i16$lrot$by00001010(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i16$lrot$by00001011(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i16$lrot$by00001100(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i16$lrot$by00001101(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i16$lrot$by00001110(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i16$lrot$by00001111(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i16$rrot(...) i16$rrot$1(__VA_ARGS__)
#define i16$rrot$1(...) i16$rrot$2(__VA_ARGS__)
#define i16$rrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i16$rrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i16$rrot$by00000000(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i16$rrot$by00000001(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i16$rrot$by00000010(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i16$rrot$by00000011(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i16$rrot$by00000100(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i16$rrot$by00000101(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i16$rrot$by00000110(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i16$rrot$by00000111(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i16$rrot$by00001000(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9, b8
#define i16$rrot$by00001001(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10, b9
#define i16$rrot$by00001010(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11, b10
#define i16$rrot$by00001011(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12, b11
#define i16$rrot$by00001100(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13, b12
#define i16$rrot$by00001101(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14, b13
#define i16$rrot$by00001110(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15, b14
#define i16$rrot$by00001111(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b15
#define i32$lshift(...) i32$lshift$1(__VA_ARGS__)
#define i32$lshift$1(...) i32$lshift$2(__VA_ARGS__)
#define i32$lshift$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i32$lshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i32$lshift$by00000000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i32$lshift$by00000001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0
#define i32$lshift$by00000010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0
#define i32$lshift$by00000011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0
#define i32$lshift$by00000100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0
#define i32$lshift$by00000101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0
#define i32$lshift$by00000110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00000111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00001111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00010111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$lshift$by00011111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i32$rshift$zx(...) i32$rshift$zx$1(__VA_ARGS__)
#define i32$rshift$zx$1(...) i32$rshift$zx$2(__VA_ARGS__)
#define i32$rshift$zx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i32$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(0, __VA_ARGS__)
#define i32$rshift$sx(...) i32$rshift$sx$1( __VA_ARGS__)
#define i32$rshift$sx$1(...) i32$rshift$sx$2(__VA_ARGS__)
#define i32$rshift$sx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,hb,...) i32$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(hb, hb, __VA_ARGS__)
#define i32$rshift$by00000000(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i32$rshift$by00000001(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i32$rshift$by00000010(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i32$rshift$by00000011(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i32$rshift$by00000100(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i32$rshift$by00000101(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i32$rshift$by00000110(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i32$rshift$by00000111(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i32$rshift$by00001000(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8
#define i32$rshift$by00001001(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9
#define i32$rshift$by00001010(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10
#define i32$rshift$by00001011(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11
#define i32$rshift$by00001100(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12
#define i32$rshift$by00001101(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13
#define i32$rshift$by00001110(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14
#define i32$rshift$by00001111(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15
#define i32$rshift$by00010000(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16
#define i32$rshift$by00010001(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17
#define i32$rshift$by00010010(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18
#define i32$rshift$by00010011(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19
#define i32$rshift$by00010100(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20
#define i32$rshift$by00010101(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21
#define i32$rshift$by00010110(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22
#define i32$rshift$by00010111(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24, b23
#define i32$rshift$by00011000(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25, b24
#define i32$rshift$by00011001(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26, b25
#define i32$rshift$by00011010(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27, b26
#define i32$rshift$by00011011(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28, b27
#define i32$rshift$by00011100(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29, b28
#define i32$rshift$by00011101(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30, b29
#define i32$rshift$by00011110(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31, b30
#define i32$rshift$by00011111(f, b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b31
#define i32$lrot(...) i32$lrot$1(__VA_ARGS__)
#define i32$lrot$1(...) i32$lrot$2(__VA_ARGS__)
#define i32$lrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i32$lrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i32$lrot$by00000000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i32$lrot$by00000001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31
#define i32$lrot$by00000010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30
#define i32$lrot$by00000011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29
#define i32$lrot$by00000100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28
#define i32$lrot$by00000101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27
#define i32$lrot$by00000110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26
#define i32$lrot$by00000111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25
#define i32$lrot$by00001000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24
#define i32$lrot$by00001001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23
#define i32$lrot$by00001010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22
#define i32$lrot$by00001011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21
#define i32$lrot$by00001100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20
#define i32$lrot$by00001101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19
#define i32$lrot$by00001110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18
#define i32$lrot$by00001111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17
#define i32$lrot$by00010000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16
#define i32$lrot$by00010001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15
#define i32$lrot$by00010010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14
#define i32$lrot$by00010011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13
#define i32$lrot$by00010100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12
#define i32$lrot$by00010101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11
#define i32$lrot$by00010110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10
#define i32$lrot$by00010111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9
#define i32$lrot$by00011000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8
#define i32$lrot$by00011001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i32$lrot$by00011010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i32$lrot$by00011011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i32$lrot$by00011100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i32$lrot$by00011101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i32$lrot$by00011110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i32$lrot$by00011111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i32$rrot(...) i32$rrot$1(__VA_ARGS__)
#define i32$rrot$1(...) i32$rrot$2(__VA_ARGS__)
#define i32$rrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i32$rrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i32$rrot$by00000000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i32$rrot$by00000001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i32$rrot$by00000010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i32$rrot$by00000011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i32$rrot$by00000100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i32$rrot$by00000101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i32$rrot$by00000110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i32$rrot$by00000111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i32$rrot$by00001000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8
#define i32$rrot$by00001001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9
#define i32$rrot$by00001010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10
#define i32$rrot$by00001011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11
#define i32$rrot$by00001100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12
#define i32$rrot$by00001101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13
#define i32$rrot$by00001110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14
#define i32$rrot$by00001111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15
#define i32$rrot$by00010000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16
#define i32$rrot$by00010001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17
#define i32$rrot$by00010010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18
#define i32$rrot$by00010011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19
#define i32$rrot$by00010100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20
#define i32$rrot$by00010101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21
#define i32$rrot$by00010110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22
#define i32$rrot$by00010111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24, b23
#define i32$rrot$by00011000(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25, b24
#define i32$rrot$by00011001(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26, b25
#define i32$rrot$by00011010(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27, b26
#define i32$rrot$by00011011(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28, b27
#define i32$rrot$by00011100(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29, b28
#define i32$rrot$by00011101(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30, b29
#define i32$rrot$by00011110(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31, b30
#define i32$rrot$by00011111(b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b31
#define i64$lshift(...) i64$lshift$1(__VA_ARGS__)
#define i64$lshift$1(...) i64$lshift$2(__VA_ARGS__)
#define i64$lshift$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i64$lshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i64$lshift$by00000000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i64$lshift$by00000001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0
#define i64$lshift$by00000010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0
#define i64$lshift$by00000011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0
#define i64$lshift$by00000100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0
#define i64$lshift$by00000101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0
#define i64$lshift$by00000110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00000111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00001111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00010111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00011111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00100111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00101111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00110111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$lshift$by00111111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define i64$rshift$zx(...) i64$rshift$zx$1(__VA_ARGS__)
#define i64$rshift$zx$1(...) i64$rshift$zx$2(__VA_ARGS__)
#define i64$rshift$zx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i64$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(0, __VA_ARGS__)
#define i64$rshift$sx(...) i64$rshift$sx$1( __VA_ARGS__)
#define i64$rshift$sx$1(...) i64$rshift$sx$2(__VA_ARGS__)
#define i64$rshift$sx$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,hb,...) i64$rshift$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(hb, hb, __VA_ARGS__)
#define i64$rshift$by00000000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i64$rshift$by00000001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i64$rshift$by00000010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i64$rshift$by00000011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i64$rshift$by00000100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i64$rshift$by00000101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i64$rshift$by00000110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i64$rshift$by00000111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i64$rshift$by00001000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8
#define i64$rshift$by00001001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9
#define i64$rshift$by00001010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10
#define i64$rshift$by00001011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11
#define i64$rshift$by00001100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12
#define i64$rshift$by00001101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13
#define i64$rshift$by00001110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14
#define i64$rshift$by00001111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15
#define i64$rshift$by00010000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16
#define i64$rshift$by00010001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17
#define i64$rshift$by00010010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18
#define i64$rshift$by00010011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19
#define i64$rshift$by00010100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20
#define i64$rshift$by00010101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21
#define i64$rshift$by00010110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22
#define i64$rshift$by00010111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23
#define i64$rshift$by00011000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24
#define i64$rshift$by00011001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25
#define i64$rshift$by00011010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26
#define i64$rshift$by00011011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27
#define i64$rshift$by00011100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28
#define i64$rshift$by00011101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29
#define i64$rshift$by00011110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30
#define i64$rshift$by00011111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31
#define i64$rshift$by00100000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32
#define i64$rshift$by00100001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33
#define i64$rshift$by00100010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34
#define i64$rshift$by00100011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35
#define i64$rshift$by00100100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36
#define i64$rshift$by00100101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37
#define i64$rshift$by00100110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38
#define i64$rshift$by00100111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39
#define i64$rshift$by00101000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40
#define i64$rshift$by00101001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41
#define i64$rshift$by00101010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42
#define i64$rshift$by00101011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43
#define i64$rshift$by00101100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44
#define i64$rshift$by00101101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45
#define i64$rshift$by00101110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46
#define i64$rshift$by00101111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47
#define i64$rshift$by00110000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48
#define i64$rshift$by00110001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49
#define i64$rshift$by00110010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50
#define i64$rshift$by00110011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51
#define i64$rshift$by00110100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52
#define i64$rshift$by00110101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53
#define i64$rshift$by00110110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54
#define i64$rshift$by00110111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56, b55
#define i64$rshift$by00111000(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57, b56
#define i64$rshift$by00111001(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58, b57
#define i64$rshift$by00111010(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59, b58
#define i64$rshift$by00111011(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60, b59
#define i64$rshift$by00111100(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61, b60
#define i64$rshift$by00111101(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62, b61
#define i64$rshift$by00111110(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63, b62
#define i64$rshift$by00111111(f, b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, f, b63
#define i64$lrot(...) i64$lrot$1(__VA_ARGS__)
#define i64$lrot$1(...) i64$lrot$2(__VA_ARGS__)
#define i64$lrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i64$lrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i64$lrot$by00000000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i64$lrot$by00000001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63
#define i64$lrot$by00000010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62
#define i64$lrot$by00000011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61
#define i64$lrot$by00000100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60
#define i64$lrot$by00000101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59
#define i64$lrot$by00000110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58
#define i64$lrot$by00000111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57
#define i64$lrot$by00001000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56
#define i64$lrot$by00001001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55
#define i64$lrot$by00001010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54
#define i64$lrot$by00001011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53
#define i64$lrot$by00001100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52
#define i64$lrot$by00001101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51
#define i64$lrot$by00001110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50
#define i64$lrot$by00001111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49
#define i64$lrot$by00010000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48
#define i64$lrot$by00010001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47
#define i64$lrot$by00010010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46
#define i64$lrot$by00010011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45
#define i64$lrot$by00010100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44
#define i64$lrot$by00010101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43
#define i64$lrot$by00010110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42
#define i64$lrot$by00010111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41
#define i64$lrot$by00011000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40
#define i64$lrot$by00011001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39
#define i64$lrot$by00011010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38
#define i64$lrot$by00011011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37
#define i64$lrot$by00011100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36
#define i64$lrot$by00011101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35
#define i64$lrot$by00011110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34
#define i64$lrot$by00011111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33
#define i64$lrot$by00100000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32
#define i64$lrot$by00100001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31
#define i64$lrot$by00100010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30
#define i64$lrot$by00100011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29
#define i64$lrot$by00100100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28
#define i64$lrot$by00100101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27
#define i64$lrot$by00100110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26
#define i64$lrot$by00100111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25
#define i64$lrot$by00101000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24
#define i64$lrot$by00101001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23
#define i64$lrot$by00101010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22
#define i64$lrot$by00101011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21
#define i64$lrot$by00101100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20
#define i64$lrot$by00101101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19
#define i64$lrot$by00101110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18
#define i64$lrot$by00101111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17
#define i64$lrot$by00110000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16
#define i64$lrot$by00110001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15
#define i64$lrot$by00110010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14
#define i64$lrot$by00110011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13
#define i64$lrot$by00110100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12
#define i64$lrot$by00110101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11
#define i64$lrot$by00110110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10
#define i64$lrot$by00110111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9
#define i64$lrot$by00111000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8
#define i64$lrot$by00111001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i64$lrot$by00111010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i64$lrot$by00111011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i64$lrot$by00111100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i64$lrot$by00111101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i64$lrot$by00111110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i64$lrot$by00111111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i64$rrot(...) i64$rrot$1(__VA_ARGS__)
#define i64$rrot$1(...) i64$rrot$2(__VA_ARGS__)
#define i64$rrot$2(B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0,...) i64$rrot$by##B0b7##B0b6##B0b5##B0b4##B0b3##B0b2##B0b1##B0b0(__VA_ARGS__)
#define i64$rrot$by00000000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0
#define i64$rrot$by00000001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1
#define i64$rrot$by00000010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2
#define i64$rrot$by00000011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3
#define i64$rrot$by00000100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4
#define i64$rrot$by00000101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5
#define i64$rrot$by00000110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6
#define i64$rrot$by00000111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7
#define i64$rrot$by00001000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8
#define i64$rrot$by00001001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9
#define i64$rrot$by00001010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10
#define i64$rrot$by00001011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11
#define i64$rrot$by00001100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12
#define i64$rrot$by00001101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13
#define i64$rrot$by00001110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14
#define i64$rrot$by00001111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15
#define i64$rrot$by00010000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16
#define i64$rrot$by00010001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17
#define i64$rrot$by00010010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18
#define i64$rrot$by00010011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19
#define i64$rrot$by00010100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20
#define i64$rrot$by00010101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21
#define i64$rrot$by00010110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22
#define i64$rrot$by00010111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23
#define i64$rrot$by00011000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24
#define i64$rrot$by00011001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25
#define i64$rrot$by00011010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26
#define i64$rrot$by00011011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27
#define i64$rrot$by00011100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28
#define i64$rrot$by00011101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29
#define i64$rrot$by00011110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30
#define i64$rrot$by00011111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31
#define i64$rrot$by00100000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32
#define i64$rrot$by00100001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33
#define i64$rrot$by00100010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34
#define i64$rrot$by00100011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35
#define i64$rrot$by00100100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36
#define i64$rrot$by00100101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37
#define i64$rrot$by00100110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38
#define i64$rrot$by00100111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39
#define i64$rrot$by00101000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40
#define i64$rrot$by00101001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41
#define i64$rrot$by00101010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42
#define i64$rrot$by00101011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43
#define i64$rrot$by00101100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44
#define i64$rrot$by00101101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45
#define i64$rrot$by00101110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46
#define i64$rrot$by00101111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47
#define i64$rrot$by00110000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48
#define i64$rrot$by00110001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49
#define i64$rrot$by00110010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50
#define i64$rrot$by00110011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51
#define i64$rrot$by00110100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52
#define i64$rrot$by00110101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54, b53
#define i64$rrot$by00110110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55, b54
#define i64$rrot$by00110111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56, b55
#define i64$rrot$by00111000(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57, b56
#define i64$rrot$by00111001(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58, b57
#define i64$rrot$by00111010(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59, b58
#define i64$rrot$by00111011(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60, b59
#define i64$rrot$by00111100(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61, b60
#define i64$rrot$by00111101(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62, b61
#define i64$rrot$by00111110(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63, b62
#define i64$rrot$by00111111(b63,b62,b61,b60,b59,b58,b57,b56,b55,b54,b53,b52,b51,b50,b49,b48,b47,b46,b45,b44,b43,b42,b41,b40,b39,b38,b37,b36,b35,b34,b33,b32,b31,b30,b29,b28,b27,b26,b25,b24,b23,b22,b21,b20,b19,b18,b17,b16,b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0) b62, b61, b60, b59, b58, b57, b56, b55, b54, b53, b52, b51, b50, b49, b48, b47, b46, b45, b44, b43, b42, b41, b40, b39, b38, b37, b36, b35, b34, b33, b32, b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, b63

// iNN add/inc/neg/sub/cmp
#define i08$add(...) byte$add$removeflags(i08$add$1(0, __VA_ARGS__))
#define i08$add$0(...) i08$add$1(__VA_ARGS__)
#define i08$add$1(...) i08$add$2(__VA_ARGS__)
#define i08$add$2(c, B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) byte$addo(c, B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0)
#define i16$add(...) byte$add$removeflags(i16$add$1(0, __VA_ARGS__))
#define i16$add$0(...) i16$add$1(__VA_ARGS__)
#define i16$add$1(...) i16$add$2(__VA_ARGS__)
#define i16$add$2(c, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) i16$add$3(byte$add(c, B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0), B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0)
#define i16$add$3(...) i16$add$4(__VA_ARGS__)
#define	i16$add$4(c, B20b7, B20b6, B20b5, B20b4, B20b3, B20b2, B20b1, B20b0, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0) byte$addo(c, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0), B20b7, B20b6, B20b5, B20b4, B20b3, B20b2, B20b1, B20b0
#define i32$add(...) byte$add$removeflags(i32$add$1(0, __VA_ARGS__))
#define i32$add$0(...) i32$add$1(__VA_ARGS__)
#define i32$add$1(...) i32$add$2(__VA_ARGS__)
#define i32$add$2(c, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0,B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) i32$add$3(byte$add(c, B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0), B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0)
#define i32$add$3(...) i32$add$4(__VA_ARGS__)
#define i32$add$4(c, B20b7, B20b6, B20b5, B20b4, B20b3, B20b2, B20b1, B20b0, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0) i32$add$5(byte$add(c, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0), B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0), B20b7, B20b6, B20b5, B20b4, B20b3, B20b2, B20b1, B20b0
#define i32$add$5(...) i32$add$6(__VA_ARGS__)
#define i32$add$6(c, B21b7, B21b6, B21b5, B21b4, B21b3, B21b2, B21b1, B21b0, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0) i32$add$7(byte$add(c, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0), B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0), B21b7, B21b6, B21b5, B21b4, B21b3, B21b2, B21b1, B21b0
#define i32$add$7(...) i32$add$8(__VA_ARGS__)
#define i32$add$8(c, B22b7, B22b6, B22b5, B22b4, B22b3, B22b2, B22b1, B22b0, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0) byte$addo(c, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0), B22b7, B22b6, B22b5, B22b4, B22b3, B22b2, B22b1, B22b0
#define i64$add(...) byte$add$removeflags(i64$add$1(0, __VA_ARGS__))
#define i64$add$0(...) i64$add$1(__VA_ARGS__)
#define i64$add$1(...) i64$add$2(__VA_ARGS__)
#define i64$add$2(c, B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0,B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) i64$add$3(byte$add(c, B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0, B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0, B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0, B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0, B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0, B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0, B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0)
#define i64$add$3(...) i64$add$4(__VA_ARGS__)
#define i64$add$4(c, B20b7, B20b6, B20b5, B20b4, B20b3, B20b2, B20b1, B20b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0) i64$add$5(byte$add(c,B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0, B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0, B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0, B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0, B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0, B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0, B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0), B20b7, B20b6, B20b5, B20b4, B20b3, B20b2, B20b1, B20b0
#define i64$add$5(...) i64$add$6(__VA_ARGS__)
#define i64$add$6(c, B21b7, B21b6, B21b5, B21b4, B21b3, B21b2, B21b1, B21b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0) i64$add$7(byte$add(c,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0, B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0, B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0, B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0, B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0, B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0, B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0, B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0), B21b7, B21b6, B21b5, B21b4, B21b3, B21b2, B21b1, B21b0
#define i64$add$7(...) i64$add$8(__VA_ARGS__)
#define i64$add$8(c, B22b7, B22b6, B22b5, B22b4, B22b3, B22b2, B22b1, B22b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0) i64$add$9(byte$add(c,B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0, B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0, B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0, B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0, B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0, B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0), B22b7, B22b6, B22b5, B22b4, B22b3, B22b2, B22b1, B22b0
#define i64$add$9(...) i64$add$A(__VA_ARGS__)
#define i64$add$A(c, B23b7, B23b6, B23b5, B23b4, B23b3, B23b2, B23b1, B23b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0) i64$add$B(byte$add(c,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0, B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0, B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0, B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0), B23b7, B23b6, B23b5, B23b4, B23b3, B23b2, B23b1, B23b0
#define i64$add$B(...) i64$add$C(__VA_ARGS__)
#define i64$add$C(c, B24b7, B24b6, B24b5, B24b4, B24b3, B24b2, B24b1, B24b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0) i64$add$D(byte$add(c,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0, B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0), B24b7, B24b6, B24b5, B24b4, B24b3, B24b2, B24b1, B24b0
#define i64$add$D(...) i64$add$E(__VA_ARGS__)
#define i64$add$E(c, B25b7, B25b6, B25b5, B25b4, B25b3, B25b2, B25b1, B25b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0) i64$add$F(byte$add(c,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0), B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0, B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0), B25b7, B25b6, B25b5, B25b4, B25b3, B25b2, B25b1, B25b0
#define i64$add$F(...) i64$add$G(__VA_ARGS__)
#define i64$add$G(c, B26b7, B26b6, B26b5, B26b4, B26b3, B26b2, B26b1, B26b0,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0) byte$addo(c,B17b7, B17b6, B17b5, B17b4, B17b3, B17b2, B17b1, B17b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0), B26b7, B26b6, B26b5, B26b4, B26b3, B26b2, B26b1, B26b0
#define i08$inc(...) byte$add$removeflags(i08$inc$1(__VA_ARGS__))
#define i08$inc$1(...) i08$inc$2(__VA_ARGS__)
#define i08$inc$2(B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) byte$addo(1, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0, repeat8(0))
#define i16$inc(...) byte$add$removeflags(i16$inc$1(__VA_ARGS__))
#define i16$inc$1(...) i16$inc$2(__VA_ARGS__)
#define i16$inc$2(B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) i16$inc$3(byte$add(1,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0,repeat8(0)),B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0)
#define i16$inc$3(...) i16$inc$4(__VA_ARGS__)
#define i16$inc$4(c,B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0) byte$addo(c,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,repeat8(0)), B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0
#define i32$inc(...) byte$add$removeflags(i32$inc$1(__VA_ARGS__))
#define i32$inc$1(...) i32$inc$2(__VA_ARGS__)
#define i32$inc$2(B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) i32$inc$3(byte$add(1,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0,repeat8(0)),B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0)
#define i32$inc$3(...) i32$inc$4(__VA_ARGS__)
#define i32$inc$4(c,B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0) i32$inc$5(byte$add(c,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,repeat8(0)),B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0), B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0
#define i32$inc$5(...) i32$inc$6(__VA_ARGS__)
#define i32$inc$6(c,B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0) i32$inc$7(byte$add(c,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,repeat8(0)),B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0), B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0
#define i32$inc$7(...) i32$inc$8(__VA_ARGS__)
#define i32$inc$8(c,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0) byte$addo(c,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,repeat8(0)), B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0
#define i64$inc(...) byte$add$removeflags(i64$inc$1(__VA_ARGS__))
#define i64$inc$1(...) i64$inc$2(__VA_ARGS__)
#define i64$inc$2(B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0) i64$inc$3(byte$add(1, B00b7, B00b6, B00b5, B00b4, B00b3, B00b2, B00b1, B00b0, repeat8(0)), B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0)
#define i64$inc$3(...) i64$inc$4(__VA_ARGS__)
#define i64$inc$4(c,B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0) i64$inc$5(byte$add(c,B01b7, B01b6, B01b5, B01b4, B01b3, B01b2, B01b1, B01b0,repeat8(0)), B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0), B10b7, B10b6, B10b5, B10b4, B10b3, B10b2, B10b1, B10b0
#define i64$inc$5(...) i64$inc$6(__VA_ARGS__)
#define i64$inc$6(c,B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0) i64$inc$7(byte$add(c,B02b7, B02b6, B02b5, B02b4, B02b3, B02b2, B02b1, B02b0,repeat8(0)), B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0), B11b7, B11b6, B11b5, B11b4, B11b3, B11b2, B11b1, B11b0
#define i64$inc$7(...) i64$inc$8(__VA_ARGS__)
#define i64$inc$8(c,B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0) i64$inc$9(byte$add(c,B03b7, B03b6, B03b5, B03b4, B03b3, B03b2, B03b1, B03b0,repeat8(0)), B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0), B12b7, B12b6, B12b5, B12b4, B12b3, B12b2, B12b1, B12b0
#define i64$inc$9(...) i64$inc$A(__VA_ARGS__)
#define i64$inc$A(c,B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0,B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0) i64$inc$B(byte$add(c,B04b7, B04b6, B04b5, B04b4, B04b3, B04b2, B04b1, B04b0,repeat8(0)), B07b7, B07b6, B07b5, B07b4, B07b3, B07b2, B07b1, B07b0,B06b7, B06b6, B06b5, B06b4, B06b3, B06b2, B06b1, B06b0,B05b7, B05b6, B05b5, B05b4, B05b3, B05b2, B05b1, B05b0), B13b7, B13b6, B13b5, B13b4, B13b3, B13b2, B13b1, B13b0
#define i64$inc$B(...) i64$inc$C(__VA_ARGS__)
#define i64$inc$C(c,B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0) i64$inc$D(byte$add(c,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,repeat8(0)), B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0), B14b7, B14b6, B14b5, B14b4, B14b3, B14b2, B14b1, B14b0
#define i64$inc$D(...) i64$inc$E(__VA_ARGS__)
#define i64$inc$E(c,B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0) i64$inc$F(byte$add(c,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,repeat8(0)), B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0), B15b7, B15b6, B15b5, B15b4, B15b3, B15b2, B15b1, B15b0
#define i64$inc$F(...) i64$inc$G(__VA_ARGS__)
#define i64$inc$G(c,B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0) byte$addo(c,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,repeat8(0)), B16b7, B16b6, B16b5, B16b4, B16b3, B16b2, B16b1, B16b0
#define i08$neg(...) i08$neg$1(__VA_ARGS__)
#define i08$neg$1(...) i08$neg$2(__VA_ARGS__)
#define i08$neg$2(...) i08$add(i08$inv(__VA_ARGS__), i08$one)
#define i16$neg(...) i16$neg$1(__VA_ARGS__)
#define i16$neg$1(...) i16$neg$2(__VA_ARGS__)
#define i16$neg$2(...) i16$add(i16$inv(__VA_ARGS__), i16$one)
#define i32$neg(...) i32$neg$1(__VA_ARGS__)
#define i32$neg$1(...) i32$neg$2(__VA_ARGS__)
#define i32$neg$2(...) i32$add(i32$inv(__VA_ARGS__), i32$one)
#define i64$neg(...) i64$neg$1(__VA_ARGS__)
#define i64$neg$1(...) i64$neg$2(__VA_ARGS__)
#define i64$neg$2(...) i64$add(i64$inv(__VA_ARGS__), i64$one)
#define i08$sub(...) byte$add$removeflags(i08$sub$1(__VA_ARGS__))
#define i08$sub$0(...) i08$sub$1(__VA_ARGS__)
#define i08$sub$1(...) i08$sub$2(__VA_ARGS__)
#define i08$sub$2(B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) i08$add$0(1, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0, i08$bit1op(byte$inv, B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i16$sub(...) byte$add$removeflags(i16$sub$1(__VA_ARGS__))
#define i16$sub$0(...) i16$sub$1(__VA_ARGS__)
#define i16$sub$1(...) i16$sub$2(__VA_ARGS__)
#define i16$sub$2(B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) i16$add$0(1, B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0, i16$bit1op(byte$inv, B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i32$sub(...) byte$add$removeflags(i32$sub$1(__VA_ARGS__))
#define i32$sub$0(...) i32$sub$1(__VA_ARGS__)
#define i32$sub$1(...) i32$sub$2(__VA_ARGS__)
#define i32$sub$2(B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) i32$add$0(1, B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0, i32$bit1op(byte$inv, B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i64$sub(...) byte$add$removeflags(i64$sub$1(__VA_ARGS__))
#define i64$sub$0(...) i64$sub$1(__VA_ARGS__)
#define i64$sub$1(...) i64$sub$2(__VA_ARGS__)
#define i64$sub$2(BFb7, BFb6, BFb5, BFb4, BFb3, BFb2, BFb1, BFb0,BEb7, BEb6, BEb5, BEb4, BEb3, BEb2, BEb1, BEb0,BDb7, BDb6, BDb5, BDb4, BDb3, BDb2, BDb1, BDb0,BCb7, BCb6, BCb5, BCb4, BCb3, BCb2, BCb1, BCb0,BBb7, BBb6, BBb5, BBb4, BBb3, BBb2, BBb1, BBb0,BAb7, BAb6, BAb5, BAb4, BAb3, BAb2, BAb1, BAb0,B9b7, B9b6, B9b5, B9b4, B9b3, B9b2, B9b1, B9b0,B8b7, B8b6, B8b5, B8b4, B8b3, B8b2, B8b1, B8b0,B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0) i64$add$0(1, BFb7, BFb6, BFb5, BFb4, BFb3, BFb2, BFb1, BFb0,BEb7, BEb6, BEb5, BEb4, BEb3, BEb2, BEb1, BEb0,BDb7, BDb6, BDb5, BDb4, BDb3, BDb2, BDb1, BDb0,BCb7, BCb6, BCb5, BCb4, BCb3, BCb2, BCb1, BCb0,BBb7, BBb6, BBb5, BBb4, BBb3, BBb2, BBb1, BBb0,BAb7, BAb6, BAb5, BAb4, BAb3, BAb2, BAb1, BAb0,B9b7, B9b6, B9b5, B9b4, B9b3, B9b2, B9b1, B9b0,B8b7, B8b6, B8b5, B8b4, B8b3, B8b2, B8b1, B8b0, i64$bit1op(byte$inv, B7b7, B7b6, B7b5, B7b4, B7b3, B7b2, B7b1, B7b0,B6b7, B6b6, B6b5, B6b4, B6b3, B6b2, B6b1, B6b0,B5b7, B5b6, B5b5, B5b4, B5b3, B5b2, B5b1, B5b0,B4b7, B4b6, B4b5, B4b4, B4b3, B4b2, B4b1, B4b0,B3b7, B3b6, B3b5, B3b4, B3b3, B3b2, B3b1, B3b0,B2b7, B2b6, B2b5, B2b4, B2b3, B2b2, B2b1, B2b0,B1b7, B1b6, B1b5, B1b4, B1b3, B1b2, B1b1, B1b0,B0b7, B0b6, B0b5, B0b4, B0b3, B0b2, B0b1, B0b0))
#define i08$cmp(...) i08$cmp$1(__VA_ARGS__)
#define i08$cmp$1(...) i08$cmp$2(__VA_ARGS__)
#define i08$cmp$2(...) i08$cmp$3(i08$sub$0(__VA_ARGS__))
#define i08$cmp$3(...) i08$cmp$4(__VA_ARGS__)
#define i08$cmp$4(c,o,s,...) i08$cmp$5(c,o,s,i08$iszero(s,__VA_ARGS__))
#define i08$cmp$5(...) i08$cmp$6(__VA_ARGS__)
#define i08$cmp$6(c,o,s,z) c,o,s,z
#define i16$cmp(...) i16$cmp$1(__VA_ARGS__)
#define i16$cmp$1(...) i16$cmp$2(__VA_ARGS__)
#define i16$cmp$2(...) i16$cmp$3(i16$sub$0(__VA_ARGS__))
#define i16$cmp$3(...) i16$cmp$4(__VA_ARGS__)
#define i16$cmp$4(c,o,s,...) i16$cmp$5(c,o,s,i16$iszero(s,__VA_ARGS__))
#define i16$cmp$5(...) i16$cmp$6(__VA_ARGS__)
#define i16$cmp$6(c,o,s,z) c,o,s,z
#define i32$cmp(...) i32$cmp$1(__VA_ARGS__)
#define i32$cmp$1(...) i32$cmp$2(__VA_ARGS__)
#define i32$cmp$2(...) i32$cmp$3(i32$sub$0(__VA_ARGS__))
#define i32$cmp$3(...) i32$cmp$4(__VA_ARGS__)
#define i32$cmp$4(c,o,s,...) i32$cmp$5(c,o,s,i32$iszero(s,__VA_ARGS__))
#define i32$cmp$5(...) i32$cmp$6(__VA_ARGS__)
#define i32$cmp$6(c,o,s,z) c,o,s,z
#define i64$cmp(...) i64$cmp$1(__VA_ARGS__)
#define i64$cmp$1(...) i64$cmp$2(__VA_ARGS__)
#define i64$cmp$2(...) i64$cmp$3(i64$sub$0(__VA_ARGS__))
#define i64$cmp$3(...) i64$cmp$4(__VA_ARGS__)
#define i64$cmp$4(c,o,s,...) i64$cmp$5(c,o,s,i64$iszero(s,__VA_ARGS__))
#define i64$cmp$5(...) i64$cmp$6(__VA_ARGS__)
#define i64$cmp$6(c,o,s,z) c,o,s,z

// self-test
#if !(IMFEELINGLUCKY)
	_Static_assert(bit$not(0), "bit$not(0)");
	_Static_assert(!bit$not(1), "!bit$not(1)");
	_Static_assert(bit$eq(0,0), "bit$eq(0,0)");
	_Static_assert(bit$eq(1,1), "bit$eq(1,1)");
	_Static_assert(bit$not(bit$eq(0,1)), "bit$not(bit$eq(0,1))");
	_Static_assert(bit$not(bit$eq(1,0)), "bit$not(bit$eq(1,0))");
	_Static_assert(bit$eq(1,bit$not(0)), "bit$eq(1,bit$not(0))");
	_Static_assert(bit$eq(0,bit$not(1)), "bit$eq(0,bit$not(1))");
	_Static_assert(bit$eq(0,bit$and(0,0)), "bit$eq(0,bit$and(0,0))");
	_Static_assert(bit$eq(0,bit$and(1,0)), "bit$eq(0,bit$and(1,0))");
	_Static_assert(bit$eq(0,bit$and(0,1)), "bit$eq(0,bit$and(0,1))");
	_Static_assert(bit$eq(1,bit$and(1,1)), "bit$eq(1,bit$and(1,1))");
	_Static_assert(bit$eq(0,bit$or(0,0)), "bit$eq(0,bit$or(0,0))");
	_Static_assert(bit$eq(1,bit$or(0,1)), "bit$eq(1,bit$or(0,1))");
	_Static_assert(bit$eq(1,bit$or(1,0)), "bit$eq(1,bit$or(1,0))");
	_Static_assert(bit$eq(1,bit$or(1,1)), "bit$eq(1,bit$or(1,1))");
	_Static_assert(bit$eq(0,bit$xor(0,0)), "bit$eq(0,bit$xor(0,0))");
	_Static_assert(bit$eq(1,bit$xor(0,1)), "bit$eq(1,bit$xor(0,1))");
	_Static_assert(bit$eq(1,bit$xor(1,0)), "bit$eq(1,bit$xor(1,0))");
	_Static_assert(bit$eq(0,bit$xor(1,1)), "bit$eq(0,bit$xor(1,1))");
	_Static_assert(bit$not(bit$not(1)), "bit$not(bit$not(1))");
	_Static_assert(bit$not(bit$all2(0,0)), "bit$not(bit$all2(0,0))");
	_Static_assert(bit$not(bit$all2(0,1)), "bit$not(bit$all2(0,1))");
	_Static_assert(bit$not(bit$all2(1,0)), "bit$not(bit$all2(1,0))");
	_Static_assert(bit$all2(1,1), "bit$all2(1,1)");
	_Static_assert(bit$not(bit$all8(0,0,0,0,0,0,0,0)), "bit$not(bit$all8(0,0,0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,1,1,1,0)), "bit$not(bit$all8(1,1,1,1,1,1,1,0))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,1,1,0,1)), "bit$not(bit$all8(1,1,1,1,1,1,0,1))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,1,0,1,1)), "bit$not(bit$all8(1,1,1,1,1,0,1,1))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,0,1,1,1)), "bit$not(bit$all8(1,1,1,1,0,1,1,1))");
	_Static_assert(bit$not(bit$all8(1,1,1,0,1,1,1,1)), "bit$not(bit$all8(1,1,1,0,1,1,1,1))");
	_Static_assert(bit$not(bit$all8(1,1,0,1,1,1,1,1)), "bit$not(bit$all8(1,1,0,1,1,1,1,1))");
	_Static_assert(bit$not(bit$all8(1,0,1,1,1,1,1,1)), "bit$not(bit$all8(1,0,1,1,1,1,1,1))");
	_Static_assert(bit$not(bit$all8(0,1,1,1,1,1,1,1)), "bit$not(bit$all8(0,1,1,1,1,1,1,1))");
	_Static_assert(bit$all8(1,1,1,1,1,1,1,1), "bit$all8(1,1,1,1,1,1,1,1)");
	_Static_assert(bit$not(bit$any2(0,0)), "bit$not(bit$any2(0,0))");
	_Static_assert(bit$any2(0,1), "bit$any2(0,1)");
	_Static_assert(bit$any2(1,0), "bit$any2(1,0)");
	_Static_assert(bit$any2(1,1), "bit$any2(1,1)");
	_Static_assert(bit$not(bit$any8(0,0,0,0,0,0,0,0)), "bit$not(bit$any8(0,0,0,0,0,0,0,0))");
	_Static_assert(bit$all3(1,1,1), "bit$all3(1,1,1)");
	_Static_assert(bit$not(bit$any3(0,0,0)), "bit$not(bit$any3(0,0,0))");
	_Static_assert(bit$not(bit$all3(1,0,0)), "bit$not(bit$all3(1,0,0))");
	_Static_assert(bit$not(bit$all3(0,1,1)), "bit$not(bit$all3(0,1,1))");
	_Static_assert(bit$any3(1,0,0), "bit$any3(1,0,0)");
	_Static_assert(bit$not(bit$all3(0,1,0)), "bit$not(bit$all3(0,1,0))");
	_Static_assert(bit$not(bit$all3(1,0,1)), "bit$not(bit$all3(1,0,1))");
	_Static_assert(bit$any3(0,1,0), "bit$any3(0,1,0)");
	_Static_assert(bit$not(bit$all3(0,0,1)), "bit$not(bit$all3(0,0,1))");
	_Static_assert(bit$not(bit$all3(1,1,0)), "bit$not(bit$all3(1,1,0))");
	_Static_assert(bit$any3(0,0,1), "bit$any3(0,0,1)");
	_Static_assert(bit$all4(1,1,1,1), "bit$all4(1,1,1,1)");
	_Static_assert(bit$not(bit$any4(0,0,0,0)), "bit$not(bit$any4(0,0,0,0))");
	_Static_assert(bit$not(bit$all4(1,0,0,0)), "bit$not(bit$all4(1,0,0,0))");
	_Static_assert(bit$not(bit$all4(0,1,1,1)), "bit$not(bit$all4(0,1,1,1))");
	_Static_assert(bit$any4(1,0,0,0), "bit$any4(1,0,0,0)");
	_Static_assert(bit$not(bit$all4(0,1,0,0)), "bit$not(bit$all4(0,1,0,0))");
	_Static_assert(bit$not(bit$all4(1,0,1,1)), "bit$not(bit$all4(1,0,1,1))");
	_Static_assert(bit$any4(0,1,0,0), "bit$any4(0,1,0,0)");
	_Static_assert(bit$not(bit$all4(0,0,1,0)), "bit$not(bit$all4(0,0,1,0))");
	_Static_assert(bit$not(bit$all4(1,1,0,1)), "bit$not(bit$all4(1,1,0,1))");
	_Static_assert(bit$any4(0,0,1,0), "bit$any4(0,0,1,0)");
	_Static_assert(bit$not(bit$all4(0,0,0,1)), "bit$not(bit$all4(0,0,0,1))");
	_Static_assert(bit$not(bit$all4(1,1,1,0)), "bit$not(bit$all4(1,1,1,0))");
	_Static_assert(bit$any4(0,0,0,1), "bit$any4(0,0,0,1)");
	_Static_assert(bit$all5(1,1,1,1,1), "bit$all5(1,1,1,1,1)");
	_Static_assert(bit$not(bit$any5(0,0,0,0,0)), "bit$not(bit$any5(0,0,0,0,0))");
	_Static_assert(bit$not(bit$all5(1,0,0,0,0)), "bit$not(bit$all5(1,0,0,0,0))");
	_Static_assert(bit$not(bit$all5(0,1,1,1,1)), "bit$not(bit$all5(0,1,1,1,1))");
	_Static_assert(bit$any5(1,0,0,0,0), "bit$any5(1,0,0,0,0)");
	_Static_assert(bit$not(bit$all5(0,1,0,0,0)), "bit$not(bit$all5(0,1,0,0,0))");
	_Static_assert(bit$not(bit$all5(1,0,1,1,1)), "bit$not(bit$all5(1,0,1,1,1))");
	_Static_assert(bit$any5(0,1,0,0,0), "bit$any5(0,1,0,0,0)");
	_Static_assert(bit$not(bit$all5(0,0,1,0,0)), "bit$not(bit$all5(0,0,1,0,0))");
	_Static_assert(bit$not(bit$all5(1,1,0,1,1)), "bit$not(bit$all5(1,1,0,1,1))");
	_Static_assert(bit$any5(0,0,1,0,0), "bit$any5(0,0,1,0,0)");
	_Static_assert(bit$not(bit$all5(0,0,0,1,0)), "bit$not(bit$all5(0,0,0,1,0))");
	_Static_assert(bit$not(bit$all5(1,1,1,0,1)), "bit$not(bit$all5(1,1,1,0,1))");
	_Static_assert(bit$any5(0,0,0,1,0), "bit$any5(0,0,0,1,0)");
	_Static_assert(bit$not(bit$all5(0,0,0,0,1)), "bit$not(bit$all5(0,0,0,0,1))");
	_Static_assert(bit$not(bit$all5(1,1,1,1,0)), "bit$not(bit$all5(1,1,1,1,0))");
	_Static_assert(bit$any5(0,0,0,0,1), "bit$any5(0,0,0,0,1)");
	_Static_assert(bit$all6(1,1,1,1,1,1), "bit$all6(1,1,1,1,1,1)");
	_Static_assert(bit$not(bit$any6(0,0,0,0,0,0)), "bit$not(bit$any6(0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all6(1,0,0,0,0,0)), "bit$not(bit$all6(1,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all6(0,1,1,1,1,1)), "bit$not(bit$all6(0,1,1,1,1,1))");
	_Static_assert(bit$any6(1,0,0,0,0,0), "bit$any6(1,0,0,0,0,0)");
	_Static_assert(bit$not(bit$all6(0,1,0,0,0,0)), "bit$not(bit$all6(0,1,0,0,0,0))");
	_Static_assert(bit$not(bit$all6(1,0,1,1,1,1)), "bit$not(bit$all6(1,0,1,1,1,1))");
	_Static_assert(bit$any6(0,1,0,0,0,0), "bit$any6(0,1,0,0,0,0)");
	_Static_assert(bit$not(bit$all6(0,0,1,0,0,0)), "bit$not(bit$all6(0,0,1,0,0,0))");
	_Static_assert(bit$not(bit$all6(1,1,0,1,1,1)), "bit$not(bit$all6(1,1,0,1,1,1))");
	_Static_assert(bit$any6(0,0,1,0,0,0), "bit$any6(0,0,1,0,0,0)");
	_Static_assert(bit$not(bit$all6(0,0,0,1,0,0)), "bit$not(bit$all6(0,0,0,1,0,0))");
	_Static_assert(bit$not(bit$all6(1,1,1,0,1,1)), "bit$not(bit$all6(1,1,1,0,1,1))");
	_Static_assert(bit$any6(0,0,0,1,0,0), "bit$any6(0,0,0,1,0,0)");
	_Static_assert(bit$not(bit$all6(0,0,0,0,1,0)), "bit$not(bit$all6(0,0,0,0,1,0))");
	_Static_assert(bit$not(bit$all6(1,1,1,1,0,1)), "bit$not(bit$all6(1,1,1,1,0,1))");
	_Static_assert(bit$any6(0,0,0,0,1,0), "bit$any6(0,0,0,0,1,0)");
	_Static_assert(bit$not(bit$all6(0,0,0,0,0,1)), "bit$not(bit$all6(0,0,0,0,0,1))");
	_Static_assert(bit$not(bit$all6(1,1,1,1,1,0)), "bit$not(bit$all6(1,1,1,1,1,0))");
	_Static_assert(bit$any6(0,0,0,0,0,1), "bit$any6(0,0,0,0,0,1)");
	_Static_assert(bit$all7(1,1,1,1,1,1,1), "bit$all7(1,1,1,1,1,1,1)");
	_Static_assert(bit$not(bit$any7(0,0,0,0,0,0,0)), "bit$not(bit$any7(0,0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all7(1,0,0,0,0,0,0)), "bit$not(bit$all7(1,0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all7(0,1,1,1,1,1,1)), "bit$not(bit$all7(0,1,1,1,1,1,1))");
	_Static_assert(bit$any7(1,0,0,0,0,0,0), "bit$any7(1,0,0,0,0,0,0)");
	_Static_assert(bit$not(bit$all7(0,1,0,0,0,0,0)), "bit$not(bit$all7(0,1,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all7(1,0,1,1,1,1,1)), "bit$not(bit$all7(1,0,1,1,1,1,1))");
	_Static_assert(bit$any7(0,1,0,0,0,0,0), "bit$any7(0,1,0,0,0,0,0)");
	_Static_assert(bit$not(bit$all7(0,0,1,0,0,0,0)), "bit$not(bit$all7(0,0,1,0,0,0,0))");
	_Static_assert(bit$not(bit$all7(1,1,0,1,1,1,1)), "bit$not(bit$all7(1,1,0,1,1,1,1))");
	_Static_assert(bit$any7(0,0,1,0,0,0,0), "bit$any7(0,0,1,0,0,0,0)");
	_Static_assert(bit$not(bit$all7(0,0,0,1,0,0,0)), "bit$not(bit$all7(0,0,0,1,0,0,0))");
	_Static_assert(bit$not(bit$all7(1,1,1,0,1,1,1)), "bit$not(bit$all7(1,1,1,0,1,1,1))");
	_Static_assert(bit$any7(0,0,0,1,0,0,0), "bit$any7(0,0,0,1,0,0,0)");
	_Static_assert(bit$not(bit$all7(0,0,0,0,1,0,0)), "bit$not(bit$all7(0,0,0,0,1,0,0))");
	_Static_assert(bit$not(bit$all7(1,1,1,1,0,1,1)), "bit$not(bit$all7(1,1,1,1,0,1,1))");
	_Static_assert(bit$any7(0,0,0,0,1,0,0), "bit$any7(0,0,0,0,1,0,0)");
	_Static_assert(bit$not(bit$all7(0,0,0,0,0,1,0)), "bit$not(bit$all7(0,0,0,0,0,1,0))");
	_Static_assert(bit$not(bit$all7(1,1,1,1,1,0,1)), "bit$not(bit$all7(1,1,1,1,1,0,1))");
	_Static_assert(bit$any7(0,0,0,0,0,1,0), "bit$any7(0,0,0,0,0,1,0)");
	_Static_assert(bit$not(bit$all7(0,0,0,0,0,0,1)), "bit$not(bit$all7(0,0,0,0,0,0,1))");
	_Static_assert(bit$not(bit$all7(1,1,1,1,1,1,0)), "bit$not(bit$all7(1,1,1,1,1,1,0))");
	_Static_assert(bit$any7(0,0,0,0,0,0,1), "bit$any7(0,0,0,0,0,0,1)");
	_Static_assert(bit$all8(1,1,1,1,1,1,1,1), "bit$all8(1,1,1,1,1,1,1,1)");
	_Static_assert(bit$not(bit$any8(0,0,0,0,0,0,0,0)), "bit$not(bit$any8(0,0,0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all8(1,0,0,0,0,0,0,0)), "bit$not(bit$all8(1,0,0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all8(0,1,1,1,1,1,1,1)), "bit$not(bit$all8(0,1,1,1,1,1,1,1))");
	_Static_assert(bit$any8(1,0,0,0,0,0,0,0), "bit$any8(1,0,0,0,0,0,0,0)");
	_Static_assert(bit$not(bit$all8(0,1,0,0,0,0,0,0)), "bit$not(bit$all8(0,1,0,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all8(1,0,1,1,1,1,1,1)), "bit$not(bit$all8(1,0,1,1,1,1,1,1))");
	_Static_assert(bit$any8(0,1,0,0,0,0,0,0), "bit$any8(0,1,0,0,0,0,0,0)");
	_Static_assert(bit$not(bit$all8(0,0,1,0,0,0,0,0)), "bit$not(bit$all8(0,0,1,0,0,0,0,0))");
	_Static_assert(bit$not(bit$all8(1,1,0,1,1,1,1,1)), "bit$not(bit$all8(1,1,0,1,1,1,1,1))");
	_Static_assert(bit$any8(0,0,1,0,0,0,0,0), "bit$any8(0,0,1,0,0,0,0,0)");
	_Static_assert(bit$not(bit$all8(0,0,0,1,0,0,0,0)), "bit$not(bit$all8(0,0,0,1,0,0,0,0))");
	_Static_assert(bit$not(bit$all8(1,1,1,0,1,1,1,1)), "bit$not(bit$all8(1,1,1,0,1,1,1,1))");
	_Static_assert(bit$any8(0,0,0,1,0,0,0,0), "bit$any8(0,0,0,1,0,0,0,0)");
	_Static_assert(bit$not(bit$all8(0,0,0,0,1,0,0,0)), "bit$not(bit$all8(0,0,0,0,1,0,0,0))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,0,1,1,1)), "bit$not(bit$all8(1,1,1,1,0,1,1,1))");
	_Static_assert(bit$any8(0,0,0,0,1,0,0,0), "bit$any8(0,0,0,0,1,0,0,0)");
	_Static_assert(bit$not(bit$all8(0,0,0,0,0,1,0,0)), "bit$not(bit$all8(0,0,0,0,0,1,0,0))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,1,0,1,1)), "bit$not(bit$all8(1,1,1,1,1,0,1,1))");
	_Static_assert(bit$any8(0,0,0,0,0,1,0,0), "bit$any8(0,0,0,0,0,1,0,0)");
	_Static_assert(bit$not(bit$all8(0,0,0,0,0,0,1,0)), "bit$not(bit$all8(0,0,0,0,0,0,1,0))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,1,1,0,1)), "bit$not(bit$all8(1,1,1,1,1,1,0,1))");
	_Static_assert(bit$any8(0,0,0,0,0,0,1,0), "bit$any8(0,0,0,0,0,0,1,0)");
	_Static_assert(bit$not(bit$all8(0,0,0,0,0,0,0,1)), "bit$not(bit$all8(0,0,0,0,0,0,0,1))");
	_Static_assert(bit$not(bit$all8(1,1,1,1,1,1,1,0)), "bit$not(bit$all8(1,1,1,1,1,1,1,0))");
	_Static_assert(bit$any8(0,0,0,0,0,0,0,1), "bit$any8(0,0,0,0,0,0,0,1)");
	_Static_assert(byte$eq(byte$fromhex(00), repeat8(0)), "byte$eq(byte$fromhex(00), repeat8(0))");
	_Static_assert(byte$eq(byte$fromhex(ff), repeat8(1)), "byte$eq(byte$fromhex(ff), repeat8(1))");
	_Static_assert(byte$eq(byte$fromhex(b5), 1,0,1,1,0,1,0,1), "byte$eq(byte$fromhex(b5), 1,0,1,1,0,1,0,1)");
	_Static_assert(byte$eq(byte$fromhex(5b), 0,1,0,1,1,0,1,1), "byte$eq(byte$fromhex(5b), 0,1,0,1,1,0,1,1)");
	_Static_assert(byte$eq(repeat8(1), byte$inv(repeat8(0))), "byte$eq(repeat8(1), byte$inv(repeat8(0)))");
	_Static_assert(byte$eq(repeat8(0), byte$inv(repeat8(1))), "byte$eq(repeat8(0), byte$inv(repeat8(1)))");
	_Static_assert(byte$all(repeat8(1)), "byte$all(repeat8(1))");
	_Static_assert(byte$all(byte$inv(repeat8(0))), "byte$all(byte$inv(repeat8(0)))");
	_Static_assert(byte$any(byte$fromhex(01)), "byte$any(byte$fromhex(01))");
	_Static_assert(byte$any(byte$fromhex(10)), "byte$any(byte$fromhex(10))");
	_Static_assert(bit$not(byte$any(repeat8(0))), "bit$not(byte$any(repeat8(0)))");
	_Static_assert(bit$eq(1, byte$getbit(byte$fromhex(0), byte$fromhex(a3))), "bit$eq(1, byte$getbit(byte$fromhex(0), byte$fromhex(a3)))");
	_Static_assert(bit$eq(1, byte$getbit(byte$fromhex(1), byte$fromhex(a3))), "bit$eq(1, byte$getbit(byte$fromhex(1), byte$fromhex(a3)))");
	_Static_assert(bit$eq(0, byte$getbit(byte$fromhex(2), byte$fromhex(a3))), "bit$eq(0, byte$getbit(byte$fromhex(2), byte$fromhex(a3)))");
	_Static_assert(bit$eq(0, byte$getbit(byte$fromhex(3), byte$fromhex(a3))), "bit$eq(0, byte$getbit(byte$fromhex(3), byte$fromhex(a3)))");
	_Static_assert(bit$eq(0, byte$getbit(byte$fromhex(4), byte$fromhex(a3))), "bit$eq(0, byte$getbit(byte$fromhex(4), byte$fromhex(a3)))");
	_Static_assert(bit$eq(1, byte$getbit(byte$fromhex(5), byte$fromhex(a3))), "bit$eq(1, byte$getbit(byte$fromhex(5), byte$fromhex(a3)))");
	_Static_assert(bit$eq(0, byte$getbit(byte$fromhex(6), byte$fromhex(a3))), "bit$eq(0, byte$getbit(byte$fromhex(6), byte$fromhex(a3)))");
	_Static_assert(bit$eq(1, byte$getbit(byte$fromhex(7), byte$fromhex(a3))), "bit$eq(1, byte$getbit(byte$fromhex(7), byte$fromhex(a3)))");
	_Static_assert(byte$iszero(byte$fromhex(00)), "byte$iszero(byte$fromhex(00))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(01))), "bit$not(byte$iszero(byte$fromhex(01)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(02))), "bit$not(byte$iszero(byte$fromhex(02)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(04))), "bit$not(byte$iszero(byte$fromhex(04)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(08))), "bit$not(byte$iszero(byte$fromhex(08)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(10))), "bit$not(byte$iszero(byte$fromhex(10)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(20))), "bit$not(byte$iszero(byte$fromhex(20)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(40))), "bit$not(byte$iszero(byte$fromhex(40)))");
	_Static_assert(bit$not(byte$iszero(byte$fromhex(80))), "bit$not(byte$iszero(byte$fromhex(80)))");
	_Static_assert(byte$iszero(byte$and(byte$fromhex(00),byte$fromhex(ff))), "byte$iszero(byte$and(byte$fromhex(00),byte$fromhex(ff)))");
	_Static_assert(byte$iszero(byte$and(byte$fromhex(ff),byte$fromhex(00))), "byte$iszero(byte$and(byte$fromhex(ff),byte$fromhex(00)))");
	_Static_assert(byte$iszero(byte$and(byte$fromhex(a5),byte$fromhex(5a))), "byte$iszero(byte$and(byte$fromhex(a5),byte$fromhex(5a)))");
	_Static_assert(byte$iszero(i16$getbyte(byte$fromhex(0), i16$fromhex(01,00))), "byte$iszero(i16$getbyte(byte$fromhex(0), i16$fromhex(01,00)))");
	_Static_assert(byte$eq(i16$getbyte(byte$fromhex(0), i16$fromhex(12,ef)), byte$fromhex(ef)), "byte$eq(i16$getbyte(byte$fromhex(0), i16$fromhex(12,ef)), byte$fromhex(ef))");
	_Static_assert(byte$eq(i16$getbyte(byte$fromhex(1), i16$fromhex(12,ef)), byte$fromhex(12)), "byte$eq(i16$getbyte(byte$fromhex(1), i16$fromhex(12,ef)), byte$fromhex(12))");
	_Static_assert(byte$eq(i32$getbyte(byte$fromhex(0), i32$fromhex(12,34,56,78)), byte$fromhex(78)), "byte$eq(i32$getbyte(byte$fromhex(0), i32$fromhex(12,34,56,78)), byte$fromhex(78))");
	_Static_assert(byte$eq(i32$getbyte(byte$fromhex(1), i32$fromhex(12,23,56,78)), byte$fromhex(56)), "byte$eq(i32$getbyte(byte$fromhex(1), i32$fromhex(12,23,56,78)), byte$fromhex(56))");
	_Static_assert(byte$eq(i32$getbyte(byte$fromhex(2), i32$fromhex(12,23,56,78)), byte$fromhex(23)), "byte$eq(i32$getbyte(byte$fromhex(2), i32$fromhex(12,23,56,78)), byte$fromhex(23))");
	_Static_assert(byte$eq(i32$getbyte(byte$fromhex(3), i32$fromhex(12,23,56,78)), byte$fromhex(12)), "byte$eq(i32$getbyte(byte$fromhex(3), i32$fromhex(12,23,56,78)), byte$fromhex(12))");
	_Static_assert(byte$eq(i16$getbyte(byte$fromhex(0), i16$add(i16$fromhex(01, 01), i16$one)), byte$fromhex(02)), "byte$eq(i16$getbyte(byte$fromhex(0), i16$add(i16$fromhex(01, 01), i16$one)), byte$fromhex(02))");
	_Static_assert(byte$eq(i16$getbyte(byte$fromhex(1), i16$add(i16$fromhex(01, 01), i16$one)), byte$fromhex(01)), "byte$eq(i16$getbyte(byte$fromhex(1), i16$add(i16$fromhex(01, 01), i16$one)), byte$fromhex(01))");
	_Static_assert(byte$eq(i08$getbyte(byte$fromhex(0), i08$inc(i08$one)), byte$fromhex(02)), "byte$eq(i08$getbyte(byte$fromhex(0), i08$inc(i08$one)), byte$fromhex(02))");
	_Static_assert(i08$iseq(i08$one, i08$inc(i08$zero)), "i08$iseq(i08$one, i08$inc(i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(02), i08$inc(i08$one)), "i08$iseq(i08$fromhex(02), i08$inc(i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(03), i08$inc(i08$inc(i08$one))), "i08$iseq(i08$fromhex(03), i08$inc(i08$inc(i08$one)))");
	_Static_assert(byte$eq(i16$getbyte(byte$fromhex(0), i16$inc(i16$one)), byte$fromhex(02)), "byte$eq(i16$getbyte(byte$fromhex(0), i16$inc(i16$one)), byte$fromhex(02))");
	_Static_assert(i16$iseq(i16$one, i16$inc(i16$zero)), "i16$iseq(i16$one, i16$inc(i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,02), i16$inc(i16$one)), "i16$iseq(i16$fromhex(00,02), i16$inc(i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,03), i16$inc(i16$inc(i16$one))), "i16$iseq(i16$fromhex(00,03), i16$inc(i16$inc(i16$one)))");
	_Static_assert(byte$eq(i32$getbyte(byte$fromhex(0), i32$inc(i32$one)), byte$fromhex(02)), "byte$eq(i32$getbyte(byte$fromhex(0), i32$inc(i32$one)), byte$fromhex(02))");
	_Static_assert(i32$iseq(i32$one, i32$inc(i32$zero)), "i32$iseq(i32$one, i32$inc(i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,02), i32$inc(i32$one)), "i32$iseq(i32$fromhex(00,00,00,02), i32$inc(i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,03), i32$inc(i32$inc(i32$one))), "i32$iseq(i32$fromhex(00,00,00,03), i32$inc(i32$inc(i32$one)))");
	_Static_assert(byte$eq(i64$getbyte(byte$fromhex(0), i64$inc(i64$one)), byte$fromhex(02)), "byte$eq(i64$getbyte(byte$fromhex(0), i64$inc(i64$one)), byte$fromhex(02))");
	_Static_assert(i64$iseq(i64$one, i64$inc(i64$zero)), "i64$iseq(i64$one, i64$inc(i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$inc(i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$inc(i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,03), i64$inc(i64$inc(i64$one))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,03), i64$inc(i64$inc(i64$one)))");
	_Static_assert(byte$eq(byte$fromhex(00),byte$xor(byte$fromhex(00),byte$fromhex(00))), "byte$eq(byte$fromhex(00),byte$xor(byte$fromhex(00),byte$fromhex(00)))");
	_Static_assert(byte$eq(byte$fromhex(ff),byte$xor(byte$fromhex(00),byte$fromhex(ff))), "byte$eq(byte$fromhex(ff),byte$xor(byte$fromhex(00),byte$fromhex(ff)))");
	_Static_assert(byte$eq(byte$fromhex(ff),byte$xor(byte$fromhex(ff),byte$fromhex(00))), "byte$eq(byte$fromhex(ff),byte$xor(byte$fromhex(ff),byte$fromhex(00)))");
	_Static_assert(byte$eq(byte$fromhex(00),byte$xor(byte$fromhex(ff),byte$fromhex(ff))), "byte$eq(byte$fromhex(00),byte$xor(byte$fromhex(ff),byte$fromhex(ff)))");
	_Static_assert(byte$eq(byte$fromhex(12),byte$xor(byte$fromhex(83),byte$fromhex(91))), "byte$eq(byte$fromhex(12),byte$xor(byte$fromhex(83),byte$fromhex(91)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(01))), "bit$not(i08$iszero(i08$fromhex(01)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(02))), "bit$not(i08$iszero(i08$fromhex(02)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(04))), "bit$not(i08$iszero(i08$fromhex(04)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(08))), "bit$not(i08$iszero(i08$fromhex(08)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(10))), "bit$not(i08$iszero(i08$fromhex(10)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(20))), "bit$not(i08$iszero(i08$fromhex(20)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(40))), "bit$not(i08$iszero(i08$fromhex(40)))");
	_Static_assert(bit$not(i08$iszero(i08$fromhex(80))), "bit$not(i08$iszero(i08$fromhex(80)))");
	_Static_assert(i08$iszero(i08$zero), "i08$iszero(i08$zero)");
	_Static_assert(i08$isnonzero(i08$one), "i08$isnonzero(i08$one)");
	_Static_assert(bit$not(i08$iszero(i08$one)), "bit$not(i08$iszero(i08$one))");
	_Static_assert(bit$not(i08$isnonzero(i08$zero)), "bit$not(i08$isnonzero(i08$zero))");
	_Static_assert(i08$iszero(i08$xor(i08$one,i08$one)), "i08$iszero(i08$xor(i08$one,i08$one))");
	_Static_assert(i08$iszero(i08$and(i08$zero,i08$one)), "i08$iszero(i08$and(i08$zero,i08$one))");
	_Static_assert(i08$iszero(i08$and(i08$one,i08$zero)), "i08$iszero(i08$and(i08$one,i08$zero))");
	_Static_assert(i08$iszero(i08$or(i08$zero,i08$zero)), "i08$iszero(i08$or(i08$zero,i08$zero))");
	_Static_assert(bit$not(i08$iszero(i08$xor(i08$one,i08$zero))), "bit$not(i08$iszero(i08$xor(i08$one,i08$zero)))");
	_Static_assert(bit$not(i08$iszero(i08$and(i08$one,i08$one))), "bit$not(i08$iszero(i08$and(i08$one,i08$one)))");
	_Static_assert(bit$not(i08$iszero(i08$or(i08$one,i08$zero))), "bit$not(i08$iszero(i08$or(i08$one,i08$zero)))");
	_Static_assert(i08$isposorzero(i08$zero), "i08$isposorzero(i08$zero)");
	_Static_assert(i08$isposorzero(i08$one), "i08$isposorzero(i08$one)");
	_Static_assert(bit$not(i08$isposorzero(i08$inv(i08$zero))), "bit$not(i08$isposorzero(i08$inv(i08$zero)))");
	_Static_assert(bit$not(i08$isposorzero(i08$inv(i08$one))), "bit$not(i08$isposorzero(i08$inv(i08$one)))");
	_Static_assert(bit$not(i08$ispos(i08$zero)), "bit$not(i08$ispos(i08$zero))");
	_Static_assert(i08$ispos(i08$one), "i08$ispos(i08$one)");
	_Static_assert(bit$not(i08$ispos(i08$inv(i08$zero))), "bit$not(i08$ispos(i08$inv(i08$zero)))");
	_Static_assert(bit$not(i08$ispos(i08$inv(i08$one))), "bit$not(i08$ispos(i08$inv(i08$one)))");
	_Static_assert(i08$isnegorzero(i08$zero), "i08$isnegorzero(i08$zero)");
	_Static_assert(i08$isnegorzero(i08$inv(i08$zero)), "i08$isnegorzero(i08$inv(i08$zero))");
	_Static_assert(bit$not(i08$isnegorzero(i08$one)), "bit$not(i08$isnegorzero(i08$one))");
	_Static_assert(bit$not(i08$isneg(i08$zero)), "bit$not(i08$isneg(i08$zero))");
	_Static_assert(bit$not(i08$isneg(i08$one)), "bit$not(i08$isneg(i08$one))");
	_Static_assert(i08$isneg(i08$inv(i08$zero)), "i08$isneg(i08$inv(i08$zero))");
	_Static_assert(i08$isneg(i08$inv(i08$one)), "i08$isneg(i08$inv(i08$one))");
	_Static_assert(bit$not(i08$iszero(i08$smax)), "bit$not(i08$iszero(i08$smax))");
	_Static_assert(bit$not(i08$iszero(i08$smin)), "bit$not(i08$iszero(i08$smin))");
	_Static_assert(bit$not(i08$isnegorzero(i08$smax)), "bit$not(i08$isnegorzero(i08$smax))");
	_Static_assert(i08$isnegorzero(i08$smin), "i08$isnegorzero(i08$smin)");
	_Static_assert(i08$ispos(i08$smax), "i08$ispos(i08$smax)");
	_Static_assert(bit$not(i08$ispos(i08$smin)), "bit$not(i08$ispos(i08$smin))");
	_Static_assert(i08$isposorzero(i08$smax), "i08$isposorzero(i08$smax)");
	_Static_assert(bit$not(i08$isposorzero(i08$smin)), "bit$not(i08$isposorzero(i08$smin))");
	_Static_assert(i16$iszero(i16$zero), "i16$iszero(i16$zero)");
	_Static_assert(i16$isnonzero(i16$one), "i16$isnonzero(i16$one)");
	_Static_assert(bit$not(i16$iszero(i16$one)), "bit$not(i16$iszero(i16$one))");
	_Static_assert(bit$not(i16$isnonzero(i16$zero)), "bit$not(i16$isnonzero(i16$zero))");
	_Static_assert(i16$iszero(i16$xor(i16$one,i16$one)), "i16$iszero(i16$xor(i16$one,i16$one))");
	_Static_assert(i16$iszero(i16$and(i16$zero,i16$one)), "i16$iszero(i16$and(i16$zero,i16$one))");
	_Static_assert(i16$iszero(i16$and(i16$one,i16$zero)), "i16$iszero(i16$and(i16$one,i16$zero))");
	_Static_assert(i16$iszero(i16$or(i16$zero,i16$zero)), "i16$iszero(i16$or(i16$zero,i16$zero))");
	_Static_assert(bit$not(i16$iszero(i16$xor(i16$one,i16$zero))), "bit$not(i16$iszero(i16$xor(i16$one,i16$zero)))");
	_Static_assert(bit$not(i16$iszero(i16$and(i16$one,i16$one))), "bit$not(i16$iszero(i16$and(i16$one,i16$one)))");
	_Static_assert(bit$not(i16$iszero(i16$or(i16$one,i16$zero))), "bit$not(i16$iszero(i16$or(i16$one,i16$zero)))");
	_Static_assert(i16$isposorzero(i16$zero), "i16$isposorzero(i16$zero)");
	_Static_assert(i16$isposorzero(i16$one), "i16$isposorzero(i16$one)");
	_Static_assert(bit$not(i16$isposorzero(i16$inv(i16$zero))), "bit$not(i16$isposorzero(i16$inv(i16$zero)))");
	_Static_assert(bit$not(i16$isposorzero(i16$inv(i16$one))), "bit$not(i16$isposorzero(i16$inv(i16$one)))");
	_Static_assert(bit$not(i16$ispos(i16$zero)), "bit$not(i16$ispos(i16$zero))");
	_Static_assert(i16$ispos(i16$one), "i16$ispos(i16$one)");
	_Static_assert(bit$not(i16$ispos(i16$inv(i16$zero))), "bit$not(i16$ispos(i16$inv(i16$zero)))");
	_Static_assert(bit$not(i16$ispos(i16$inv(i16$one))), "bit$not(i16$ispos(i16$inv(i16$one)))");
	_Static_assert(i16$isnegorzero(i16$zero), "i16$isnegorzero(i16$zero)");
	_Static_assert(i16$isnegorzero(i16$inv(i16$zero)), "i16$isnegorzero(i16$inv(i16$zero))");
	_Static_assert(bit$not(i16$isnegorzero(i16$one)), "bit$not(i16$isnegorzero(i16$one))");
	_Static_assert(bit$not(i16$isneg(i16$zero)), "bit$not(i16$isneg(i16$zero))");
	_Static_assert(bit$not(i16$isneg(i16$one)), "bit$not(i16$isneg(i16$one))");
	_Static_assert(i16$isneg(i16$inv(i16$zero)), "i16$isneg(i16$inv(i16$zero))");
	_Static_assert(i16$isneg(i16$inv(i16$one)), "i16$isneg(i16$inv(i16$one))");
	_Static_assert(bit$not(i16$iszero(i16$smax)), "bit$not(i16$iszero(i16$smax))");
	_Static_assert(bit$not(i16$iszero(i16$smin)), "bit$not(i16$iszero(i16$smin))");
	_Static_assert(bit$not(i16$isnegorzero(i16$smax)), "bit$not(i16$isnegorzero(i16$smax))");
	_Static_assert(i16$isnegorzero(i16$smin), "i16$isnegorzero(i16$smin)");
	_Static_assert(i16$ispos(i16$smax), "i16$ispos(i16$smax)");
	_Static_assert(bit$not(i16$ispos(i16$smin)), "bit$not(i16$ispos(i16$smin))");
	_Static_assert(i16$isposorzero(i16$smax), "i16$isposorzero(i16$smax)");
	_Static_assert(bit$not(i16$isposorzero(i16$smin)), "bit$not(i16$isposorzero(i16$smin))");
	_Static_assert(i32$iszero(i32$zero), "i32$iszero(i32$zero)");
	_Static_assert(i32$isnonzero(i32$one), "i32$isnonzero(i32$one)");
	_Static_assert(bit$not(i32$iszero(i32$one)), "bit$not(i32$iszero(i32$one))");
	_Static_assert(bit$not(i32$isnonzero(i32$zero)), "bit$not(i32$isnonzero(i32$zero))");
	_Static_assert(i32$iszero(i32$xor(i32$one,i32$one)), "i32$iszero(i32$xor(i32$one,i32$one))");
	_Static_assert(i32$iszero(i32$and(i32$zero,i32$one)), "i32$iszero(i32$and(i32$zero,i32$one))");
	_Static_assert(i32$iszero(i32$and(i32$one,i32$zero)), "i32$iszero(i32$and(i32$one,i32$zero))");
	_Static_assert(i32$iszero(i32$or(i32$zero,i32$zero)), "i32$iszero(i32$or(i32$zero,i32$zero))");
	_Static_assert(bit$not(i32$iszero(i32$xor(i32$one,i32$zero))), "bit$not(i32$iszero(i32$xor(i32$one,i32$zero)))");
	_Static_assert(bit$not(i32$iszero(i32$and(i32$one,i32$one))), "bit$not(i32$iszero(i32$and(i32$one,i32$one)))");
	_Static_assert(bit$not(i32$iszero(i32$or(i32$one,i32$zero))), "bit$not(i32$iszero(i32$or(i32$one,i32$zero)))");
	_Static_assert(i32$isposorzero(i32$zero), "i32$isposorzero(i32$zero)");
	_Static_assert(i32$isposorzero(i32$one), "i32$isposorzero(i32$one)");
	_Static_assert(bit$not(i32$isposorzero(i32$inv(i32$zero))), "bit$not(i32$isposorzero(i32$inv(i32$zero)))");
	_Static_assert(bit$not(i32$isposorzero(i32$inv(i32$one))), "bit$not(i32$isposorzero(i32$inv(i32$one)))");
	_Static_assert(bit$not(i32$ispos(i32$zero)), "bit$not(i32$ispos(i32$zero))");
	_Static_assert(i32$ispos(i32$one), "i32$ispos(i32$one)");
	_Static_assert(bit$not(i32$ispos(i32$inv(i32$zero))), "bit$not(i32$ispos(i32$inv(i32$zero)))");
	_Static_assert(bit$not(i32$ispos(i32$inv(i32$one))), "bit$not(i32$ispos(i32$inv(i32$one)))");
	_Static_assert(i32$isnegorzero(i32$zero), "i32$isnegorzero(i32$zero)");
	_Static_assert(i32$isnegorzero(i32$inv(i32$zero)), "i32$isnegorzero(i32$inv(i32$zero))");
	_Static_assert(bit$not(i32$isnegorzero(i32$one)), "bit$not(i32$isnegorzero(i32$one))");
	_Static_assert(bit$not(i32$isneg(i32$zero)), "bit$not(i32$isneg(i32$zero))");
	_Static_assert(bit$not(i32$isneg(i32$one)), "bit$not(i32$isneg(i32$one))");
	_Static_assert(i32$isneg(i32$inv(i32$zero)), "i32$isneg(i32$inv(i32$zero))");
	_Static_assert(i32$isneg(i32$inv(i32$one)), "i32$isneg(i32$inv(i32$one))");
	_Static_assert(bit$not(i32$iszero(i32$smax)), "bit$not(i32$iszero(i32$smax))");
	_Static_assert(bit$not(i32$iszero(i32$smin)), "bit$not(i32$iszero(i32$smin))");
	_Static_assert(bit$not(i32$isnegorzero(i32$smax)), "bit$not(i32$isnegorzero(i32$smax))");
	_Static_assert(i32$isnegorzero(i32$smin), "i32$isnegorzero(i32$smin)");
	_Static_assert(i32$ispos(i32$smax), "i32$ispos(i32$smax)");
	_Static_assert(bit$not(i32$ispos(i32$smin)), "bit$not(i32$ispos(i32$smin))");
	_Static_assert(i32$isposorzero(i32$smax), "i32$isposorzero(i32$smax)");
	_Static_assert(bit$not(i32$isposorzero(i32$smin)), "bit$not(i32$isposorzero(i32$smin))");
	_Static_assert(i64$iszero(i64$zero), "i64$iszero(i64$zero)");
	_Static_assert(i64$isnonzero(i64$one), "i64$isnonzero(i64$one)");
	_Static_assert(bit$not(i64$iszero(i64$one)), "bit$not(i64$iszero(i64$one))");
	_Static_assert(bit$not(i64$isnonzero(i64$zero)), "bit$not(i64$isnonzero(i64$zero))");
	_Static_assert(i64$iszero(i64$xor(i64$one,i64$one)), "i64$iszero(i64$xor(i64$one,i64$one))");
	_Static_assert(i64$iszero(i64$and(i64$zero,i64$one)), "i64$iszero(i64$and(i64$zero,i64$one))");
	_Static_assert(i64$iszero(i64$and(i64$one,i64$zero)), "i64$iszero(i64$and(i64$one,i64$zero))");
	_Static_assert(i64$iszero(i64$or(i64$zero,i64$zero)), "i64$iszero(i64$or(i64$zero,i64$zero))");
	_Static_assert(bit$not(i64$iszero(i64$xor(i64$one,i64$zero))), "bit$not(i64$iszero(i64$xor(i64$one,i64$zero)))");
	_Static_assert(bit$not(i64$iszero(i64$and(i64$one,i64$one))), "bit$not(i64$iszero(i64$and(i64$one,i64$one)))");
	_Static_assert(bit$not(i64$iszero(i64$or(i64$one,i64$zero))), "bit$not(i64$iszero(i64$or(i64$one,i64$zero)))");
	_Static_assert(i64$isposorzero(i64$zero), "i64$isposorzero(i64$zero)");
	_Static_assert(i64$isposorzero(i64$one), "i64$isposorzero(i64$one)");
	_Static_assert(bit$not(i64$isposorzero(i64$inv(i64$zero))), "bit$not(i64$isposorzero(i64$inv(i64$zero)))");
	_Static_assert(bit$not(i64$isposorzero(i64$inv(i64$one))), "bit$not(i64$isposorzero(i64$inv(i64$one)))");
	_Static_assert(bit$not(i64$ispos(i64$zero)), "bit$not(i64$ispos(i64$zero))");
	_Static_assert(i64$ispos(i64$one), "i64$ispos(i64$one)");
	_Static_assert(bit$not(i64$ispos(i64$inv(i64$zero))), "bit$not(i64$ispos(i64$inv(i64$zero)))");
	_Static_assert(bit$not(i64$ispos(i64$inv(i64$one))), "bit$not(i64$ispos(i64$inv(i64$one)))");
	_Static_assert(i64$isnegorzero(i64$zero), "i64$isnegorzero(i64$zero)");
	_Static_assert(i64$isnegorzero(i64$inv(i64$zero)), "i64$isnegorzero(i64$inv(i64$zero))");
	_Static_assert(bit$not(i64$isnegorzero(i64$one)), "bit$not(i64$isnegorzero(i64$one))");
	_Static_assert(bit$not(i64$isneg(i64$zero)), "bit$not(i64$isneg(i64$zero))");
	_Static_assert(bit$not(i64$isneg(i64$one)), "bit$not(i64$isneg(i64$one))");
	_Static_assert(i64$isneg(i64$inv(i64$zero)), "i64$isneg(i64$inv(i64$zero))");
	_Static_assert(i64$isneg(i64$inv(i64$one)), "i64$isneg(i64$inv(i64$one))");
	_Static_assert(bit$not(i64$iszero(i64$smax)), "bit$not(i64$iszero(i64$smax))");
	_Static_assert(bit$not(i64$iszero(i64$smin)), "bit$not(i64$iszero(i64$smin))");
	_Static_assert(bit$not(i64$isnegorzero(i64$smax)), "bit$not(i64$isnegorzero(i64$smax))");
	_Static_assert(i64$isnegorzero(i64$smin), "i64$isnegorzero(i64$smin)");
	_Static_assert(i64$ispos(i64$smax), "i64$ispos(i64$smax)");
	_Static_assert(bit$not(i64$ispos(i64$smin)), "bit$not(i64$ispos(i64$smin))");
	_Static_assert(i64$isposorzero(i64$smax), "i64$isposorzero(i64$smax)");
	_Static_assert(bit$not(i64$isposorzero(i64$smin)), "bit$not(i64$isposorzero(i64$smin))");
	_Static_assert(i08$iseq(i08$zero, i08$zero), "i08$iseq(i08$zero, i08$zero)");
	_Static_assert(i08$iseq(i08$one, i08$one), "i08$iseq(i08$one, i08$one)");
	_Static_assert(bit$not(i08$isneq(i08$zero, i08$zero)), "bit$not(i08$isneq(i08$zero, i08$zero))");
	_Static_assert(bit$not(i08$isneq(i08$one, i08$one)), "bit$not(i08$isneq(i08$one, i08$one))");
	_Static_assert(i08$isneq(i08$zero, i08$one), "i08$isneq(i08$zero, i08$one)");
	_Static_assert(i08$isneq(i08$one, i08$zero), "i08$isneq(i08$one, i08$zero)");
	_Static_assert(bit$not(i08$iseq(i08$zero, i08$one)), "bit$not(i08$iseq(i08$zero, i08$one))");
	_Static_assert(bit$not(i08$iseq(i08$one, i08$zero)), "bit$not(i08$iseq(i08$one, i08$zero))");
	_Static_assert(i08$iseq(i08$zero,i08$or(i08$zero, i08$zero)), "i08$iseq(i08$zero,i08$or(i08$zero, i08$zero))");
	_Static_assert(i08$iseq(i08$one,i08$or(i08$zero, i08$one)), "i08$iseq(i08$one,i08$or(i08$zero, i08$one))");
	_Static_assert(i08$iseq(i08$one,i08$or(i08$one, i08$zero)), "i08$iseq(i08$one,i08$or(i08$one, i08$zero))");
	_Static_assert(i08$iseq(i08$one,i08$or(i08$one, i08$one)), "i08$iseq(i08$one,i08$or(i08$one, i08$one))");
	_Static_assert(i08$iseq(i08$zero,i08$xor(i08$zero,i08$zero)), "i08$iseq(i08$zero,i08$xor(i08$zero,i08$zero))");
	_Static_assert(i08$iseq(i08$one,i08$xor(i08$zero,i08$one)), "i08$iseq(i08$one,i08$xor(i08$zero,i08$one))");
	_Static_assert(i08$iseq(i08$one,i08$xor(i08$one,i08$zero)), "i08$iseq(i08$one,i08$xor(i08$one,i08$zero))");
	_Static_assert(i08$iseq(i08$zero,i08$xor(i08$one,i08$one)), "i08$iseq(i08$zero,i08$xor(i08$one,i08$one))");
	_Static_assert(i08$iseq(i08$zero,i08$and(i08$zero,i08$zero)), "i08$iseq(i08$zero,i08$and(i08$zero,i08$zero))");
	_Static_assert(i08$iseq(i08$zero,i08$and(i08$zero,i08$one)), "i08$iseq(i08$zero,i08$and(i08$zero,i08$one))");
	_Static_assert(i08$iseq(i08$zero,i08$and(i08$one,i08$zero)), "i08$iseq(i08$zero,i08$and(i08$one,i08$zero))");
	_Static_assert(i08$iseq(i08$one,i08$and(i08$one,i08$one)), "i08$iseq(i08$one,i08$and(i08$one,i08$one))");
	_Static_assert(i08$isneq(i08$zero, i08$inv(i08$zero)), "i08$isneq(i08$zero, i08$inv(i08$zero))");
	_Static_assert(i08$isneq(i08$zero, i08$inv(i08$one)), "i08$isneq(i08$zero, i08$inv(i08$one))");
	_Static_assert(i08$isneq(i08$one, i08$inv(i08$zero)), "i08$isneq(i08$one, i08$inv(i08$zero))");
	_Static_assert(i08$isneq(i08$one, i08$inv(i08$one)), "i08$isneq(i08$one, i08$inv(i08$one))");
	_Static_assert(i16$iseq(i16$zero, i16$zero), "i16$iseq(i16$zero, i16$zero)");
	_Static_assert(i16$iseq(i16$one, i16$one), "i16$iseq(i16$one, i16$one)");
	_Static_assert(bit$not(i16$isneq(i16$zero, i16$zero)), "bit$not(i16$isneq(i16$zero, i16$zero))");
	_Static_assert(bit$not(i16$isneq(i16$one, i16$one)), "bit$not(i16$isneq(i16$one, i16$one))");
	_Static_assert(i16$isneq(i16$zero, i16$one), "i16$isneq(i16$zero, i16$one)");
	_Static_assert(i16$isneq(i16$one, i16$zero), "i16$isneq(i16$one, i16$zero)");
	_Static_assert(bit$not(i16$iseq(i16$zero, i16$one)), "bit$not(i16$iseq(i16$zero, i16$one))");
	_Static_assert(bit$not(i16$iseq(i16$one, i16$zero)), "bit$not(i16$iseq(i16$one, i16$zero))");
	_Static_assert(i16$iseq(i16$zero,i16$or(i16$zero, i16$zero)), "i16$iseq(i16$zero,i16$or(i16$zero, i16$zero))");
	_Static_assert(i16$iseq(i16$one,i16$or(i16$zero, i16$one)), "i16$iseq(i16$one,i16$or(i16$zero, i16$one))");
	_Static_assert(i16$iseq(i16$one,i16$or(i16$one, i16$zero)), "i16$iseq(i16$one,i16$or(i16$one, i16$zero))");
	_Static_assert(i16$iseq(i16$one,i16$or(i16$one, i16$one)), "i16$iseq(i16$one,i16$or(i16$one, i16$one))");
	_Static_assert(i16$iseq(i16$zero,i16$xor(i16$zero,i16$zero)), "i16$iseq(i16$zero,i16$xor(i16$zero,i16$zero))");
	_Static_assert(i16$iseq(i16$one,i16$xor(i16$zero,i16$one)), "i16$iseq(i16$one,i16$xor(i16$zero,i16$one))");
	_Static_assert(i16$iseq(i16$one,i16$xor(i16$one,i16$zero)), "i16$iseq(i16$one,i16$xor(i16$one,i16$zero))");
	_Static_assert(i16$iseq(i16$zero,i16$xor(i16$one,i16$one)), "i16$iseq(i16$zero,i16$xor(i16$one,i16$one))");
	_Static_assert(i16$iseq(i16$zero,i16$and(i16$zero,i16$zero)), "i16$iseq(i16$zero,i16$and(i16$zero,i16$zero))");
	_Static_assert(i16$iseq(i16$zero,i16$and(i16$zero,i16$one)), "i16$iseq(i16$zero,i16$and(i16$zero,i16$one))");
	_Static_assert(i16$iseq(i16$zero,i16$and(i16$one,i16$zero)), "i16$iseq(i16$zero,i16$and(i16$one,i16$zero))");
	_Static_assert(i16$iseq(i16$one,i16$and(i16$one,i16$one)), "i16$iseq(i16$one,i16$and(i16$one,i16$one))");
	_Static_assert(i16$isneq(i16$zero, i16$inv(i16$zero)), "i16$isneq(i16$zero, i16$inv(i16$zero))");
	_Static_assert(i16$isneq(i16$zero, i16$inv(i16$one)), "i16$isneq(i16$zero, i16$inv(i16$one))");
	_Static_assert(i16$isneq(i16$one, i16$inv(i16$zero)), "i16$isneq(i16$one, i16$inv(i16$zero))");
	_Static_assert(i16$isneq(i16$one, i16$inv(i16$one)), "i16$isneq(i16$one, i16$inv(i16$one))");
	_Static_assert(i32$iseq(i32$zero, i32$zero), "i32$iseq(i32$zero, i32$zero)");
	_Static_assert(i32$iseq(i32$one, i32$one), "i32$iseq(i32$one, i32$one)");
	_Static_assert(bit$not(i32$isneq(i32$zero, i32$zero)), "bit$not(i32$isneq(i32$zero, i32$zero))");
	_Static_assert(bit$not(i32$isneq(i32$one, i32$one)), "bit$not(i32$isneq(i32$one, i32$one))");
	_Static_assert(i32$isneq(i32$zero, i32$one), "i32$isneq(i32$zero, i32$one)");
	_Static_assert(i32$isneq(i32$one, i32$zero), "i32$isneq(i32$one, i32$zero)");
	_Static_assert(bit$not(i32$iseq(i32$zero, i32$one)), "bit$not(i32$iseq(i32$zero, i32$one))");
	_Static_assert(bit$not(i32$iseq(i32$one, i32$zero)), "bit$not(i32$iseq(i32$one, i32$zero))");
	_Static_assert(i32$iseq(i32$zero,i32$or(i32$zero, i32$zero)), "i32$iseq(i32$zero,i32$or(i32$zero, i32$zero))");
	_Static_assert(i32$iseq(i32$one,i32$or(i32$zero, i32$one)), "i32$iseq(i32$one,i32$or(i32$zero, i32$one))");
	_Static_assert(i32$iseq(i32$one,i32$or(i32$one, i32$zero)), "i32$iseq(i32$one,i32$or(i32$one, i32$zero))");
	_Static_assert(i32$iseq(i32$one,i32$or(i32$one, i32$one)), "i32$iseq(i32$one,i32$or(i32$one, i32$one))");
	_Static_assert(i32$iseq(i32$zero,i32$xor(i32$zero,i32$zero)), "i32$iseq(i32$zero,i32$xor(i32$zero,i32$zero))");
	_Static_assert(i32$iseq(i32$one,i32$xor(i32$zero,i32$one)), "i32$iseq(i32$one,i32$xor(i32$zero,i32$one))");
	_Static_assert(i32$iseq(i32$one,i32$xor(i32$one,i32$zero)), "i32$iseq(i32$one,i32$xor(i32$one,i32$zero))");
	_Static_assert(i32$iseq(i32$zero,i32$xor(i32$one,i32$one)), "i32$iseq(i32$zero,i32$xor(i32$one,i32$one))");
	_Static_assert(i32$iseq(i32$zero,i32$and(i32$zero,i32$zero)), "i32$iseq(i32$zero,i32$and(i32$zero,i32$zero))");
	_Static_assert(i32$iseq(i32$zero,i32$and(i32$zero,i32$one)), "i32$iseq(i32$zero,i32$and(i32$zero,i32$one))");
	_Static_assert(i32$iseq(i32$zero,i32$and(i32$one,i32$zero)), "i32$iseq(i32$zero,i32$and(i32$one,i32$zero))");
	_Static_assert(i32$iseq(i32$one,i32$and(i32$one,i32$one)), "i32$iseq(i32$one,i32$and(i32$one,i32$one))");
	_Static_assert(i32$isneq(i32$zero, i32$inv(i32$zero)), "i32$isneq(i32$zero, i32$inv(i32$zero))");
	_Static_assert(i32$isneq(i32$zero, i32$inv(i32$one)), "i32$isneq(i32$zero, i32$inv(i32$one))");
	_Static_assert(i32$isneq(i32$one, i32$inv(i32$zero)), "i32$isneq(i32$one, i32$inv(i32$zero))");
	_Static_assert(i32$isneq(i32$one, i32$inv(i32$one)), "i32$isneq(i32$one, i32$inv(i32$one))");
	_Static_assert(i64$iseq(i64$zero, i64$zero), "i64$iseq(i64$zero, i64$zero)");
	_Static_assert(i64$iseq(i64$one, i64$one), "i64$iseq(i64$one, i64$one)");
	_Static_assert(bit$not(i64$isneq(i64$zero, i64$zero)), "bit$not(i64$isneq(i64$zero, i64$zero))");
	_Static_assert(bit$not(i64$isneq(i64$one, i64$one)), "bit$not(i64$isneq(i64$one, i64$one))");
	_Static_assert(i64$isneq(i64$zero, i64$one), "i64$isneq(i64$zero, i64$one)");
	_Static_assert(i64$isneq(i64$one, i64$zero), "i64$isneq(i64$one, i64$zero)");
	_Static_assert(bit$not(i64$iseq(i64$zero, i64$one)), "bit$not(i64$iseq(i64$zero, i64$one))");
	_Static_assert(bit$not(i64$iseq(i64$one, i64$zero)), "bit$not(i64$iseq(i64$one, i64$zero))");
	_Static_assert(i64$iseq(i64$zero,i64$or(i64$zero, i64$zero)), "i64$iseq(i64$zero,i64$or(i64$zero, i64$zero))");
	_Static_assert(i64$iseq(i64$one,i64$or(i64$zero, i64$one)), "i64$iseq(i64$one,i64$or(i64$zero, i64$one))");
	_Static_assert(i64$iseq(i64$one,i64$or(i64$one, i64$zero)), "i64$iseq(i64$one,i64$or(i64$one, i64$zero))");
	_Static_assert(i64$iseq(i64$one,i64$or(i64$one, i64$one)), "i64$iseq(i64$one,i64$or(i64$one, i64$one))");
	_Static_assert(i64$iseq(i64$zero,i64$xor(i64$zero,i64$zero)), "i64$iseq(i64$zero,i64$xor(i64$zero,i64$zero))");
	_Static_assert(i64$iseq(i64$one,i64$xor(i64$zero,i64$one)), "i64$iseq(i64$one,i64$xor(i64$zero,i64$one))");
	_Static_assert(i64$iseq(i64$one,i64$xor(i64$one,i64$zero)), "i64$iseq(i64$one,i64$xor(i64$one,i64$zero))");
	_Static_assert(i64$iseq(i64$zero,i64$xor(i64$one,i64$one)), "i64$iseq(i64$zero,i64$xor(i64$one,i64$one))");
	_Static_assert(i64$iseq(i64$zero,i64$and(i64$zero,i64$zero)), "i64$iseq(i64$zero,i64$and(i64$zero,i64$zero))");
	_Static_assert(i64$iseq(i64$zero,i64$and(i64$zero,i64$one)), "i64$iseq(i64$zero,i64$and(i64$zero,i64$one))");
	_Static_assert(i64$iseq(i64$zero,i64$and(i64$one,i64$zero)), "i64$iseq(i64$zero,i64$and(i64$one,i64$zero))");
	_Static_assert(i64$iseq(i64$one,i64$and(i64$one,i64$one)), "i64$iseq(i64$one,i64$and(i64$one,i64$one))");
	_Static_assert(i64$isneq(i64$zero, i64$inv(i64$zero)), "i64$isneq(i64$zero, i64$inv(i64$zero))");
	_Static_assert(i64$isneq(i64$zero, i64$inv(i64$one)), "i64$isneq(i64$zero, i64$inv(i64$one))");
	_Static_assert(i64$isneq(i64$one, i64$inv(i64$zero)), "i64$isneq(i64$one, i64$inv(i64$zero))");
	_Static_assert(i64$isneq(i64$one, i64$inv(i64$one)), "i64$isneq(i64$one, i64$inv(i64$one))");
	_Static_assert(i08$isa(i08$umax,i08$smax), "i08$isa(i08$umax,i08$smax)");
	_Static_assert(i08$isa(i08$umax,i08$one), "i08$isa(i08$umax,i08$one)");
	_Static_assert(i08$isa(i08$umax,i08$zero), "i08$isa(i08$umax,i08$zero)");
	_Static_assert(i08$isa(i08$smax,i08$zero), "i08$isa(i08$smax,i08$zero)");
	_Static_assert(i08$isa(i08$one,i08$zero), "i08$isa(i08$one,i08$zero)");
	_Static_assert(i08$isb(i08$zero,i08$one), "i08$isb(i08$zero,i08$one)");
	_Static_assert(i08$isb(i08$zero,i08$smax), "i08$isb(i08$zero,i08$smax)");
	_Static_assert(i08$isb(i08$zero,i08$umax), "i08$isb(i08$zero,i08$umax)");
	_Static_assert(i08$isb(i08$one,i08$umax), "i08$isb(i08$one,i08$umax)");
	_Static_assert(i08$isb(i08$smax,i08$umax), "i08$isb(i08$smax,i08$umax)");
	_Static_assert(i08$isae(i08$umax,i08$smax), "i08$isae(i08$umax,i08$smax)");
	_Static_assert(i08$isae(i08$umax,i08$one), "i08$isae(i08$umax,i08$one)");
	_Static_assert(i08$isae(i08$umax,i08$zero), "i08$isae(i08$umax,i08$zero)");
	_Static_assert(i08$isae(i08$smax,i08$zero), "i08$isae(i08$smax,i08$zero)");
	_Static_assert(i08$isae(i08$one,i08$zero), "i08$isae(i08$one,i08$zero)");
	_Static_assert(i08$isbe(i08$zero,i08$one), "i08$isbe(i08$zero,i08$one)");
	_Static_assert(i08$isbe(i08$zero,i08$smax), "i08$isbe(i08$zero,i08$smax)");
	_Static_assert(i08$isbe(i08$zero,i08$umax), "i08$isbe(i08$zero,i08$umax)");
	_Static_assert(i08$isbe(i08$one,i08$umax), "i08$isbe(i08$one,i08$umax)");
	_Static_assert(i08$isbe(i08$smax,i08$umax), "i08$isbe(i08$smax,i08$umax)");
	_Static_assert(i08$isae(i08$umax,i08$umax), "i08$isae(i08$umax,i08$umax)");
	_Static_assert(i08$isae(i08$smax,i08$smax), "i08$isae(i08$smax,i08$smax)");
	_Static_assert(i08$isae(i08$zero,i08$zero), "i08$isae(i08$zero,i08$zero)");
	_Static_assert(i08$isbe(i08$umax,i08$umax), "i08$isbe(i08$umax,i08$umax)");
	_Static_assert(i08$isbe(i08$smax,i08$smax), "i08$isbe(i08$smax,i08$smax)");
	_Static_assert(i08$isbe(i08$zero,i08$zero), "i08$isbe(i08$zero,i08$zero)");
	_Static_assert(bit$not(i08$isa(i08$smax,i08$umax)), "bit$not(i08$isa(i08$smax,i08$umax))");
	_Static_assert(bit$not(i08$isa(i08$one,i08$umax)), "bit$not(i08$isa(i08$one,i08$umax))");
	_Static_assert(bit$not(i08$isa(i08$zero,i08$umax)), "bit$not(i08$isa(i08$zero,i08$umax))");
	_Static_assert(bit$not(i08$isb(i08$umax,i08$smax)), "bit$not(i08$isb(i08$umax,i08$smax))");
	_Static_assert(bit$not(i08$isb(i08$umax,i08$one)), "bit$not(i08$isb(i08$umax,i08$one))");
	_Static_assert(bit$not(i08$isb(i08$umax,i08$zero)), "bit$not(i08$isb(i08$umax,i08$zero))");
	_Static_assert(bit$not(i08$isa(i08$umax,i08$umax)), "bit$not(i08$isa(i08$umax,i08$umax))");
	_Static_assert(bit$not(i08$isa(i08$smax,i08$smax)), "bit$not(i08$isa(i08$smax,i08$smax))");
	_Static_assert(bit$not(i08$isa(i08$one,i08$one)), "bit$not(i08$isa(i08$one,i08$one))");
	_Static_assert(bit$not(i08$isa(i08$zero,i08$zero)), "bit$not(i08$isa(i08$zero,i08$zero))");
	_Static_assert(bit$not(i08$isb(i08$umax,i08$umax)), "bit$not(i08$isb(i08$umax,i08$umax))");
	_Static_assert(bit$not(i08$isb(i08$smax,i08$smax)), "bit$not(i08$isb(i08$smax,i08$smax))");
	_Static_assert(bit$not(i08$isb(i08$one,i08$one)), "bit$not(i08$isb(i08$one,i08$one))");
	_Static_assert(bit$not(i08$isb(i08$zero,i08$zero)), "bit$not(i08$isb(i08$zero,i08$zero))");
	_Static_assert(bit$not(i08$isae(i08$smax,i08$umax)), "bit$not(i08$isae(i08$smax,i08$umax))");
	_Static_assert(bit$not(i08$isae(i08$one,i08$umax)), "bit$not(i08$isae(i08$one,i08$umax))");
	_Static_assert(bit$not(i08$isae(i08$zero,i08$umax)), "bit$not(i08$isae(i08$zero,i08$umax))");
	_Static_assert(bit$not(i08$isbe(i08$umax,i08$smax)), "bit$not(i08$isbe(i08$umax,i08$smax))");
	_Static_assert(bit$not(i08$isbe(i08$umax,i08$one)), "bit$not(i08$isbe(i08$umax,i08$one))");
	_Static_assert(bit$not(i08$isbe(i08$umax,i08$zero)), "bit$not(i08$isbe(i08$umax,i08$zero))");
	_Static_assert(i08$isge(i08$zero,i08$zero), "i08$isge(i08$zero,i08$zero)");
	_Static_assert(i08$isge(i08$one,i08$zero), "i08$isge(i08$one,i08$zero)");
	_Static_assert(i08$isgt(i08$one,i08$zero), "i08$isgt(i08$one,i08$zero)");
	_Static_assert(i08$isle(i08$zero,i08$one), "i08$isle(i08$zero,i08$one)");
	_Static_assert(i08$isge(i08$smax,i08$one), "i08$isge(i08$smax,i08$one)");
	_Static_assert(i08$isge(i08$smax,i08$zero), "i08$isge(i08$smax,i08$zero)");
	_Static_assert(i08$isge(i08$smax,i08$smin), "i08$isge(i08$smax,i08$smin)");
	_Static_assert(i08$isgt(i08$smax,i08$one), "i08$isgt(i08$smax,i08$one)");
	_Static_assert(i08$isgt(i08$smax,i08$zero), "i08$isgt(i08$smax,i08$zero)");
	_Static_assert(i08$isgt(i08$smax,i08$smin), "i08$isgt(i08$smax,i08$smin)");
	_Static_assert(i08$isle(i08$smin,i08$one), "i08$isle(i08$smin,i08$one)");
	_Static_assert(i08$isle(i08$smin,i08$zero), "i08$isle(i08$smin,i08$zero)");
	_Static_assert(i08$isle(i08$smin,i08$smax), "i08$isle(i08$smin,i08$smax)");
	_Static_assert(i08$islt(i08$smin,i08$one), "i08$islt(i08$smin,i08$one)");
	_Static_assert(i08$isle(i08$smin,i08$zero), "i08$isle(i08$smin,i08$zero)");
	_Static_assert(i08$isle(i08$smin,i08$smax), "i08$isle(i08$smin,i08$smax)");
	_Static_assert(bit$not(i08$isle(i08$smax,i08$one)), "bit$not(i08$isle(i08$smax,i08$one))");
	_Static_assert(bit$not(i08$isle(i08$smax,i08$zero)), "bit$not(i08$isle(i08$smax,i08$zero))");
	_Static_assert(bit$not(i08$isle(i08$smax,i08$smin)), "bit$not(i08$isle(i08$smax,i08$smin))");
	_Static_assert(bit$not(i08$isle(i08$one,i08$smin)), "bit$not(i08$isle(i08$one,i08$smin))");
	_Static_assert(bit$not(i08$isle(i08$zero,i08$smin)), "bit$not(i08$isle(i08$zero,i08$smin))");
	_Static_assert(bit$not(i08$islt(i08$smax,i08$one)), "bit$not(i08$islt(i08$smax,i08$one))");
	_Static_assert(bit$not(i08$islt(i08$smax,i08$zero)), "bit$not(i08$islt(i08$smax,i08$zero))");
	_Static_assert(bit$not(i08$islt(i08$smax,i08$smin)), "bit$not(i08$islt(i08$smax,i08$smin))");
	_Static_assert(bit$not(i08$islt(i08$one,i08$smin)), "bit$not(i08$islt(i08$one,i08$smin))");
	_Static_assert(bit$not(i08$islt(i08$zero,i08$smin)), "bit$not(i08$islt(i08$zero,i08$smin))");
	_Static_assert(bit$not(i08$isge(i08$smin,i08$smax)), "bit$not(i08$isge(i08$smin,i08$smax))");
	_Static_assert(bit$not(i08$isge(i08$smin,i08$one)), "bit$not(i08$isge(i08$smin,i08$one))");
	_Static_assert(bit$not(i08$isge(i08$smin,i08$zero)), "bit$not(i08$isge(i08$smin,i08$zero))");
	_Static_assert(bit$not(i08$isge(i08$zero,i08$smax)), "bit$not(i08$isge(i08$zero,i08$smax))");
	_Static_assert(bit$not(i08$isge(i08$one,i08$smax)), "bit$not(i08$isge(i08$one,i08$smax))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$one)), "bit$not(i08$isgt(i08$smin,i08$one))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$zero)), "bit$not(i08$isgt(i08$smin,i08$zero))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$smax)), "bit$not(i08$isgt(i08$smin,i08$smax))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$one)), "bit$not(i08$isgt(i08$smin,i08$one))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$zero)), "bit$not(i08$isgt(i08$smin,i08$zero))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$smax)), "bit$not(i08$isgt(i08$smin,i08$smax))");
	_Static_assert(i08$isge(i08$smax,i08$smax), "i08$isge(i08$smax,i08$smax)");
	_Static_assert(i08$isge(i08$smin,i08$smin), "i08$isge(i08$smin,i08$smin)");
	_Static_assert(i08$isge(i08$zero,i08$zero), "i08$isge(i08$zero,i08$zero)");
	_Static_assert(i08$isle(i08$smax,i08$smax), "i08$isle(i08$smax,i08$smax)");
	_Static_assert(i08$isle(i08$smin,i08$smin), "i08$isle(i08$smin,i08$smin)");
	_Static_assert(i08$isle(i08$zero,i08$zero), "i08$isle(i08$zero,i08$zero)");
	_Static_assert(bit$not(i08$isgt(i08$smax,i08$smax)), "bit$not(i08$isgt(i08$smax,i08$smax))");
	_Static_assert(bit$not(i08$isgt(i08$smin,i08$smin)), "bit$not(i08$isgt(i08$smin,i08$smin))");
	_Static_assert(bit$not(i08$isgt(i08$zero,i08$zero)), "bit$not(i08$isgt(i08$zero,i08$zero))");
	_Static_assert(bit$not(i08$islt(i08$smax,i08$smax)), "bit$not(i08$islt(i08$smax,i08$smax))");
	_Static_assert(bit$not(i08$islt(i08$smin,i08$smin)), "bit$not(i08$islt(i08$smin,i08$smin))");
	_Static_assert(bit$not(i08$islt(i08$zero,i08$zero)), "bit$not(i08$islt(i08$zero,i08$zero))");
	_Static_assert(i16$isa(i16$umax,i16$smax), "i16$isa(i16$umax,i16$smax)");
	_Static_assert(i16$isa(i16$umax,i16$one), "i16$isa(i16$umax,i16$one)");
	_Static_assert(i16$isa(i16$umax,i16$zero), "i16$isa(i16$umax,i16$zero)");
	_Static_assert(i16$isa(i16$smax,i16$zero), "i16$isa(i16$smax,i16$zero)");
	_Static_assert(i16$isa(i16$one,i16$zero), "i16$isa(i16$one,i16$zero)");
	_Static_assert(i16$isb(i16$zero,i16$one), "i16$isb(i16$zero,i16$one)");
	_Static_assert(i16$isb(i16$zero,i16$smax), "i16$isb(i16$zero,i16$smax)");
	_Static_assert(i16$isb(i16$zero,i16$umax), "i16$isb(i16$zero,i16$umax)");
	_Static_assert(i16$isb(i16$one,i16$umax), "i16$isb(i16$one,i16$umax)");
	_Static_assert(i16$isb(i16$smax,i16$umax), "i16$isb(i16$smax,i16$umax)");
	_Static_assert(i16$isae(i16$umax,i16$smax), "i16$isae(i16$umax,i16$smax)");
	_Static_assert(i16$isae(i16$umax,i16$one), "i16$isae(i16$umax,i16$one)");
	_Static_assert(i16$isae(i16$umax,i16$zero), "i16$isae(i16$umax,i16$zero)");
	_Static_assert(i16$isae(i16$smax,i16$zero), "i16$isae(i16$smax,i16$zero)");
	_Static_assert(i16$isae(i16$one,i16$zero), "i16$isae(i16$one,i16$zero)");
	_Static_assert(i16$isbe(i16$zero,i16$one), "i16$isbe(i16$zero,i16$one)");
	_Static_assert(i16$isbe(i16$zero,i16$smax), "i16$isbe(i16$zero,i16$smax)");
	_Static_assert(i16$isbe(i16$zero,i16$umax), "i16$isbe(i16$zero,i16$umax)");
	_Static_assert(i16$isbe(i16$one,i16$umax), "i16$isbe(i16$one,i16$umax)");
	_Static_assert(i16$isbe(i16$smax,i16$umax), "i16$isbe(i16$smax,i16$umax)");
	_Static_assert(i16$isae(i16$umax,i16$umax), "i16$isae(i16$umax,i16$umax)");
	_Static_assert(i16$isae(i16$smax,i16$smax), "i16$isae(i16$smax,i16$smax)");
	_Static_assert(i16$isae(i16$zero,i16$zero), "i16$isae(i16$zero,i16$zero)");
	_Static_assert(i16$isbe(i16$umax,i16$umax), "i16$isbe(i16$umax,i16$umax)");
	_Static_assert(i16$isbe(i16$smax,i16$smax), "i16$isbe(i16$smax,i16$smax)");
	_Static_assert(i16$isbe(i16$zero,i16$zero), "i16$isbe(i16$zero,i16$zero)");
	_Static_assert(bit$not(i16$isa(i16$smax,i16$umax)), "bit$not(i16$isa(i16$smax,i16$umax))");
	_Static_assert(bit$not(i16$isa(i16$one,i16$umax)), "bit$not(i16$isa(i16$one,i16$umax))");
	_Static_assert(bit$not(i16$isa(i16$zero,i16$umax)), "bit$not(i16$isa(i16$zero,i16$umax))");
	_Static_assert(bit$not(i16$isb(i16$umax,i16$smax)), "bit$not(i16$isb(i16$umax,i16$smax))");
	_Static_assert(bit$not(i16$isb(i16$umax,i16$one)), "bit$not(i16$isb(i16$umax,i16$one))");
	_Static_assert(bit$not(i16$isb(i16$umax,i16$zero)), "bit$not(i16$isb(i16$umax,i16$zero))");
	_Static_assert(bit$not(i16$isa(i16$umax,i16$umax)), "bit$not(i16$isa(i16$umax,i16$umax))");
	_Static_assert(bit$not(i16$isa(i16$smax,i16$smax)), "bit$not(i16$isa(i16$smax,i16$smax))");
	_Static_assert(bit$not(i16$isa(i16$one,i16$one)), "bit$not(i16$isa(i16$one,i16$one))");
	_Static_assert(bit$not(i16$isa(i16$zero,i16$zero)), "bit$not(i16$isa(i16$zero,i16$zero))");
	_Static_assert(bit$not(i16$isb(i16$umax,i16$umax)), "bit$not(i16$isb(i16$umax,i16$umax))");
	_Static_assert(bit$not(i16$isb(i16$smax,i16$smax)), "bit$not(i16$isb(i16$smax,i16$smax))");
	_Static_assert(bit$not(i16$isb(i16$one,i16$one)), "bit$not(i16$isb(i16$one,i16$one))");
	_Static_assert(bit$not(i16$isb(i16$zero,i16$zero)), "bit$not(i16$isb(i16$zero,i16$zero))");
	_Static_assert(bit$not(i16$isae(i16$smax,i16$umax)), "bit$not(i16$isae(i16$smax,i16$umax))");
	_Static_assert(bit$not(i16$isae(i16$one,i16$umax)), "bit$not(i16$isae(i16$one,i16$umax))");
	_Static_assert(bit$not(i16$isae(i16$zero,i16$umax)), "bit$not(i16$isae(i16$zero,i16$umax))");
	_Static_assert(bit$not(i16$isbe(i16$umax,i16$smax)), "bit$not(i16$isbe(i16$umax,i16$smax))");
	_Static_assert(bit$not(i16$isbe(i16$umax,i16$one)), "bit$not(i16$isbe(i16$umax,i16$one))");
	_Static_assert(bit$not(i16$isbe(i16$umax,i16$zero)), "bit$not(i16$isbe(i16$umax,i16$zero))");
	_Static_assert(i16$isge(i16$zero,i16$zero), "i16$isge(i16$zero,i16$zero)");
	_Static_assert(i16$isge(i16$one,i16$zero), "i16$isge(i16$one,i16$zero)");
	_Static_assert(i16$isgt(i16$one,i16$zero), "i16$isgt(i16$one,i16$zero)");
	_Static_assert(i16$isle(i16$zero,i16$one), "i16$isle(i16$zero,i16$one)");
	_Static_assert(i16$isge(i16$smax,i16$one), "i16$isge(i16$smax,i16$one)");
	_Static_assert(i16$isge(i16$smax,i16$zero), "i16$isge(i16$smax,i16$zero)");
	_Static_assert(i16$isge(i16$smax,i16$smin), "i16$isge(i16$smax,i16$smin)");
	_Static_assert(i16$isgt(i16$smax,i16$one), "i16$isgt(i16$smax,i16$one)");
	_Static_assert(i16$isgt(i16$smax,i16$zero), "i16$isgt(i16$smax,i16$zero)");
	_Static_assert(i16$isgt(i16$smax,i16$smin), "i16$isgt(i16$smax,i16$smin)");
	_Static_assert(i16$isle(i16$smin,i16$one), "i16$isle(i16$smin,i16$one)");
	_Static_assert(i16$isle(i16$smin,i16$zero), "i16$isle(i16$smin,i16$zero)");
	_Static_assert(i16$isle(i16$smin,i16$smax), "i16$isle(i16$smin,i16$smax)");
	_Static_assert(i16$islt(i16$smin,i16$one), "i16$islt(i16$smin,i16$one)");
	_Static_assert(i16$isle(i16$smin,i16$zero), "i16$isle(i16$smin,i16$zero)");
	_Static_assert(i16$isle(i16$smin,i16$smax), "i16$isle(i16$smin,i16$smax)");
	_Static_assert(bit$not(i16$isle(i16$smax,i16$one)), "bit$not(i16$isle(i16$smax,i16$one))");
	_Static_assert(bit$not(i16$isle(i16$smax,i16$zero)), "bit$not(i16$isle(i16$smax,i16$zero))");
	_Static_assert(bit$not(i16$isle(i16$smax,i16$smin)), "bit$not(i16$isle(i16$smax,i16$smin))");
	_Static_assert(bit$not(i16$isle(i16$one,i16$smin)), "bit$not(i16$isle(i16$one,i16$smin))");
	_Static_assert(bit$not(i16$isle(i16$zero,i16$smin)), "bit$not(i16$isle(i16$zero,i16$smin))");
	_Static_assert(bit$not(i16$islt(i16$smax,i16$one)), "bit$not(i16$islt(i16$smax,i16$one))");
	_Static_assert(bit$not(i16$islt(i16$smax,i16$zero)), "bit$not(i16$islt(i16$smax,i16$zero))");
	_Static_assert(bit$not(i16$islt(i16$smax,i16$smin)), "bit$not(i16$islt(i16$smax,i16$smin))");
	_Static_assert(bit$not(i16$islt(i16$one,i16$smin)), "bit$not(i16$islt(i16$one,i16$smin))");
	_Static_assert(bit$not(i16$islt(i16$zero,i16$smin)), "bit$not(i16$islt(i16$zero,i16$smin))");
	_Static_assert(bit$not(i16$isge(i16$smin,i16$smax)), "bit$not(i16$isge(i16$smin,i16$smax))");
	_Static_assert(bit$not(i16$isge(i16$smin,i16$one)), "bit$not(i16$isge(i16$smin,i16$one))");
	_Static_assert(bit$not(i16$isge(i16$smin,i16$zero)), "bit$not(i16$isge(i16$smin,i16$zero))");
	_Static_assert(bit$not(i16$isge(i16$zero,i16$smax)), "bit$not(i16$isge(i16$zero,i16$smax))");
	_Static_assert(bit$not(i16$isge(i16$one,i16$smax)), "bit$not(i16$isge(i16$one,i16$smax))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$one)), "bit$not(i16$isgt(i16$smin,i16$one))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$zero)), "bit$not(i16$isgt(i16$smin,i16$zero))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$smax)), "bit$not(i16$isgt(i16$smin,i16$smax))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$one)), "bit$not(i16$isgt(i16$smin,i16$one))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$zero)), "bit$not(i16$isgt(i16$smin,i16$zero))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$smax)), "bit$not(i16$isgt(i16$smin,i16$smax))");
	_Static_assert(i16$isge(i16$smax,i16$smax), "i16$isge(i16$smax,i16$smax)");
	_Static_assert(i16$isge(i16$smin,i16$smin), "i16$isge(i16$smin,i16$smin)");
	_Static_assert(i16$isge(i16$zero,i16$zero), "i16$isge(i16$zero,i16$zero)");
	_Static_assert(i16$isle(i16$smax,i16$smax), "i16$isle(i16$smax,i16$smax)");
	_Static_assert(i16$isle(i16$smin,i16$smin), "i16$isle(i16$smin,i16$smin)");
	_Static_assert(i16$isle(i16$zero,i16$zero), "i16$isle(i16$zero,i16$zero)");
	_Static_assert(bit$not(i16$isgt(i16$smax,i16$smax)), "bit$not(i16$isgt(i16$smax,i16$smax))");
	_Static_assert(bit$not(i16$isgt(i16$smin,i16$smin)), "bit$not(i16$isgt(i16$smin,i16$smin))");
	_Static_assert(bit$not(i16$isgt(i16$zero,i16$zero)), "bit$not(i16$isgt(i16$zero,i16$zero))");
	_Static_assert(bit$not(i16$islt(i16$smax,i16$smax)), "bit$not(i16$islt(i16$smax,i16$smax))");
	_Static_assert(bit$not(i16$islt(i16$smin,i16$smin)), "bit$not(i16$islt(i16$smin,i16$smin))");
	_Static_assert(bit$not(i16$islt(i16$zero,i16$zero)), "bit$not(i16$islt(i16$zero,i16$zero))");
	_Static_assert(i32$isa(i32$umax,i32$smax), "i32$isa(i32$umax,i32$smax)");
	_Static_assert(i32$isa(i32$umax,i32$one), "i32$isa(i32$umax,i32$one)");
	_Static_assert(i32$isa(i32$umax,i32$zero), "i32$isa(i32$umax,i32$zero)");
	_Static_assert(i32$isa(i32$smax,i32$zero), "i32$isa(i32$smax,i32$zero)");
	_Static_assert(i32$isa(i32$one,i32$zero), "i32$isa(i32$one,i32$zero)");
	_Static_assert(i32$isb(i32$zero,i32$one), "i32$isb(i32$zero,i32$one)");
	_Static_assert(i32$isb(i32$zero,i32$smax), "i32$isb(i32$zero,i32$smax)");
	_Static_assert(i32$isb(i32$zero,i32$umax), "i32$isb(i32$zero,i32$umax)");
	_Static_assert(i32$isb(i32$one,i32$umax), "i32$isb(i32$one,i32$umax)");
	_Static_assert(i32$isb(i32$smax,i32$umax), "i32$isb(i32$smax,i32$umax)");
	_Static_assert(i32$isae(i32$umax,i32$smax), "i32$isae(i32$umax,i32$smax)");
	_Static_assert(i32$isae(i32$umax,i32$one), "i32$isae(i32$umax,i32$one)");
	_Static_assert(i32$isae(i32$umax,i32$zero), "i32$isae(i32$umax,i32$zero)");
	_Static_assert(i32$isae(i32$smax,i32$zero), "i32$isae(i32$smax,i32$zero)");
	_Static_assert(i32$isae(i32$one,i32$zero), "i32$isae(i32$one,i32$zero)");
	_Static_assert(i32$isbe(i32$zero,i32$one), "i32$isbe(i32$zero,i32$one)");
	_Static_assert(i32$isbe(i32$zero,i32$smax), "i32$isbe(i32$zero,i32$smax)");
	_Static_assert(i32$isbe(i32$zero,i32$umax), "i32$isbe(i32$zero,i32$umax)");
	_Static_assert(i32$isbe(i32$one,i32$umax), "i32$isbe(i32$one,i32$umax)");
	_Static_assert(i32$isbe(i32$smax,i32$umax), "i32$isbe(i32$smax,i32$umax)");
	_Static_assert(i32$isae(i32$umax,i32$umax), "i32$isae(i32$umax,i32$umax)");
	_Static_assert(i32$isae(i32$smax,i32$smax), "i32$isae(i32$smax,i32$smax)");
	_Static_assert(i32$isae(i32$zero,i32$zero), "i32$isae(i32$zero,i32$zero)");
	_Static_assert(i32$isbe(i32$umax,i32$umax), "i32$isbe(i32$umax,i32$umax)");
	_Static_assert(i32$isbe(i32$smax,i32$smax), "i32$isbe(i32$smax,i32$smax)");
	_Static_assert(i32$isbe(i32$zero,i32$zero), "i32$isbe(i32$zero,i32$zero)");
	_Static_assert(bit$not(i32$isa(i32$smax,i32$umax)), "bit$not(i32$isa(i32$smax,i32$umax))");
	_Static_assert(bit$not(i32$isa(i32$one,i32$umax)), "bit$not(i32$isa(i32$one,i32$umax))");
	_Static_assert(bit$not(i32$isa(i32$zero,i32$umax)), "bit$not(i32$isa(i32$zero,i32$umax))");
	_Static_assert(bit$not(i32$isb(i32$umax,i32$smax)), "bit$not(i32$isb(i32$umax,i32$smax))");
	_Static_assert(bit$not(i32$isb(i32$umax,i32$one)), "bit$not(i32$isb(i32$umax,i32$one))");
	_Static_assert(bit$not(i32$isb(i32$umax,i32$zero)), "bit$not(i32$isb(i32$umax,i32$zero))");
	_Static_assert(bit$not(i32$isa(i32$umax,i32$umax)), "bit$not(i32$isa(i32$umax,i32$umax))");
	_Static_assert(bit$not(i32$isa(i32$smax,i32$smax)), "bit$not(i32$isa(i32$smax,i32$smax))");
	_Static_assert(bit$not(i32$isa(i32$one,i32$one)), "bit$not(i32$isa(i32$one,i32$one))");
	_Static_assert(bit$not(i32$isa(i32$zero,i32$zero)), "bit$not(i32$isa(i32$zero,i32$zero))");
	_Static_assert(bit$not(i32$isb(i32$umax,i32$umax)), "bit$not(i32$isb(i32$umax,i32$umax))");
	_Static_assert(bit$not(i32$isb(i32$smax,i32$smax)), "bit$not(i32$isb(i32$smax,i32$smax))");
	_Static_assert(bit$not(i32$isb(i32$one,i32$one)), "bit$not(i32$isb(i32$one,i32$one))");
	_Static_assert(bit$not(i32$isb(i32$zero,i32$zero)), "bit$not(i32$isb(i32$zero,i32$zero))");
	_Static_assert(bit$not(i32$isae(i32$smax,i32$umax)), "bit$not(i32$isae(i32$smax,i32$umax))");
	_Static_assert(bit$not(i32$isae(i32$one,i32$umax)), "bit$not(i32$isae(i32$one,i32$umax))");
	_Static_assert(bit$not(i32$isae(i32$zero,i32$umax)), "bit$not(i32$isae(i32$zero,i32$umax))");
	_Static_assert(bit$not(i32$isbe(i32$umax,i32$smax)), "bit$not(i32$isbe(i32$umax,i32$smax))");
	_Static_assert(bit$not(i32$isbe(i32$umax,i32$one)), "bit$not(i32$isbe(i32$umax,i32$one))");
	_Static_assert(bit$not(i32$isbe(i32$umax,i32$zero)), "bit$not(i32$isbe(i32$umax,i32$zero))");
	_Static_assert(i32$isge(i32$zero,i32$zero), "i32$isge(i32$zero,i32$zero)");
	_Static_assert(i32$isge(i32$one,i32$zero), "i32$isge(i32$one,i32$zero)");
	_Static_assert(i32$isgt(i32$one,i32$zero), "i32$isgt(i32$one,i32$zero)");
	_Static_assert(i32$isle(i32$zero,i32$one), "i32$isle(i32$zero,i32$one)");
	_Static_assert(i32$isge(i32$smax,i32$one), "i32$isge(i32$smax,i32$one)");
	_Static_assert(i32$isge(i32$smax,i32$zero), "i32$isge(i32$smax,i32$zero)");
	_Static_assert(i32$isge(i32$smax,i32$smin), "i32$isge(i32$smax,i32$smin)");
	_Static_assert(i32$isgt(i32$smax,i32$one), "i32$isgt(i32$smax,i32$one)");
	_Static_assert(i32$isgt(i32$smax,i32$zero), "i32$isgt(i32$smax,i32$zero)");
	_Static_assert(i32$isgt(i32$smax,i32$smin), "i32$isgt(i32$smax,i32$smin)");
	_Static_assert(i32$isle(i32$smin,i32$one), "i32$isle(i32$smin,i32$one)");
	_Static_assert(i32$isle(i32$smin,i32$zero), "i32$isle(i32$smin,i32$zero)");
	_Static_assert(i32$isle(i32$smin,i32$smax), "i32$isle(i32$smin,i32$smax)");
	_Static_assert(i32$islt(i32$smin,i32$one), "i32$islt(i32$smin,i32$one)");
	_Static_assert(i32$isle(i32$smin,i32$zero), "i32$isle(i32$smin,i32$zero)");
	_Static_assert(i32$isle(i32$smin,i32$smax), "i32$isle(i32$smin,i32$smax)");
	_Static_assert(bit$not(i32$isle(i32$smax,i32$one)), "bit$not(i32$isle(i32$smax,i32$one))");
	_Static_assert(bit$not(i32$isle(i32$smax,i32$zero)), "bit$not(i32$isle(i32$smax,i32$zero))");
	_Static_assert(bit$not(i32$isle(i32$smax,i32$smin)), "bit$not(i32$isle(i32$smax,i32$smin))");
	_Static_assert(bit$not(i32$isle(i32$one,i32$smin)), "bit$not(i32$isle(i32$one,i32$smin))");
	_Static_assert(bit$not(i32$isle(i32$zero,i32$smin)), "bit$not(i32$isle(i32$zero,i32$smin))");
	_Static_assert(bit$not(i32$islt(i32$smax,i32$one)), "bit$not(i32$islt(i32$smax,i32$one))");
	_Static_assert(bit$not(i32$islt(i32$smax,i32$zero)), "bit$not(i32$islt(i32$smax,i32$zero))");
	_Static_assert(bit$not(i32$islt(i32$smax,i32$smin)), "bit$not(i32$islt(i32$smax,i32$smin))");
	_Static_assert(bit$not(i32$islt(i32$one,i32$smin)), "bit$not(i32$islt(i32$one,i32$smin))");
	_Static_assert(bit$not(i32$islt(i32$zero,i32$smin)), "bit$not(i32$islt(i32$zero,i32$smin))");
	_Static_assert(bit$not(i32$isge(i32$smin,i32$smax)), "bit$not(i32$isge(i32$smin,i32$smax))");
	_Static_assert(bit$not(i32$isge(i32$smin,i32$one)), "bit$not(i32$isge(i32$smin,i32$one))");
	_Static_assert(bit$not(i32$isge(i32$smin,i32$zero)), "bit$not(i32$isge(i32$smin,i32$zero))");
	_Static_assert(bit$not(i32$isge(i32$zero,i32$smax)), "bit$not(i32$isge(i32$zero,i32$smax))");
	_Static_assert(bit$not(i32$isge(i32$one,i32$smax)), "bit$not(i32$isge(i32$one,i32$smax))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$one)), "bit$not(i32$isgt(i32$smin,i32$one))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$zero)), "bit$not(i32$isgt(i32$smin,i32$zero))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$smax)), "bit$not(i32$isgt(i32$smin,i32$smax))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$one)), "bit$not(i32$isgt(i32$smin,i32$one))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$zero)), "bit$not(i32$isgt(i32$smin,i32$zero))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$smax)), "bit$not(i32$isgt(i32$smin,i32$smax))");
	_Static_assert(i32$isge(i32$smax,i32$smax), "i32$isge(i32$smax,i32$smax)");
	_Static_assert(i32$isge(i32$smin,i32$smin), "i32$isge(i32$smin,i32$smin)");
	_Static_assert(i32$isge(i32$zero,i32$zero), "i32$isge(i32$zero,i32$zero)");
	_Static_assert(i32$isle(i32$smax,i32$smax), "i32$isle(i32$smax,i32$smax)");
	_Static_assert(i32$isle(i32$smin,i32$smin), "i32$isle(i32$smin,i32$smin)");
	_Static_assert(i32$isle(i32$zero,i32$zero), "i32$isle(i32$zero,i32$zero)");
	_Static_assert(bit$not(i32$isgt(i32$smax,i32$smax)), "bit$not(i32$isgt(i32$smax,i32$smax))");
	_Static_assert(bit$not(i32$isgt(i32$smin,i32$smin)), "bit$not(i32$isgt(i32$smin,i32$smin))");
	_Static_assert(bit$not(i32$isgt(i32$zero,i32$zero)), "bit$not(i32$isgt(i32$zero,i32$zero))");
	_Static_assert(bit$not(i32$islt(i32$smax,i32$smax)), "bit$not(i32$islt(i32$smax,i32$smax))");
	_Static_assert(bit$not(i32$islt(i32$smin,i32$smin)), "bit$not(i32$islt(i32$smin,i32$smin))");
	_Static_assert(bit$not(i32$islt(i32$zero,i32$zero)), "bit$not(i32$islt(i32$zero,i32$zero))");
	_Static_assert(i64$isa(i64$umax,i64$smax), "i64$isa(i64$umax,i64$smax)");
	_Static_assert(i64$isa(i64$umax,i64$one), "i64$isa(i64$umax,i64$one)");
	_Static_assert(i64$isa(i64$umax,i64$zero), "i64$isa(i64$umax,i64$zero)");
	_Static_assert(i64$isa(i64$smax,i64$zero), "i64$isa(i64$smax,i64$zero)");
	_Static_assert(i64$isa(i64$one,i64$zero), "i64$isa(i64$one,i64$zero)");
	_Static_assert(i64$isb(i64$zero,i64$one), "i64$isb(i64$zero,i64$one)");
	_Static_assert(i64$isb(i64$zero,i64$smax), "i64$isb(i64$zero,i64$smax)");
	_Static_assert(i64$isb(i64$zero,i64$umax), "i64$isb(i64$zero,i64$umax)");
	_Static_assert(i64$isb(i64$one,i64$umax), "i64$isb(i64$one,i64$umax)");
	_Static_assert(i64$isb(i64$smax,i64$umax), "i64$isb(i64$smax,i64$umax)");
	_Static_assert(i64$isae(i64$umax,i64$smax), "i64$isae(i64$umax,i64$smax)");
	_Static_assert(i64$isae(i64$umax,i64$one), "i64$isae(i64$umax,i64$one)");
	_Static_assert(i64$isae(i64$umax,i64$zero), "i64$isae(i64$umax,i64$zero)");
	_Static_assert(i64$isae(i64$smax,i64$zero), "i64$isae(i64$smax,i64$zero)");
	_Static_assert(i64$isae(i64$one,i64$zero), "i64$isae(i64$one,i64$zero)");
	_Static_assert(i64$isbe(i64$zero,i64$one), "i64$isbe(i64$zero,i64$one)");
	_Static_assert(i64$isbe(i64$zero,i64$smax), "i64$isbe(i64$zero,i64$smax)");
	_Static_assert(i64$isbe(i64$zero,i64$umax), "i64$isbe(i64$zero,i64$umax)");
	_Static_assert(i64$isbe(i64$one,i64$umax), "i64$isbe(i64$one,i64$umax)");
	_Static_assert(i64$isbe(i64$smax,i64$umax), "i64$isbe(i64$smax,i64$umax)");
	_Static_assert(i64$isae(i64$umax,i64$umax), "i64$isae(i64$umax,i64$umax)");
	_Static_assert(i64$isae(i64$smax,i64$smax), "i64$isae(i64$smax,i64$smax)");
	_Static_assert(i64$isae(i64$zero,i64$zero), "i64$isae(i64$zero,i64$zero)");
	_Static_assert(i64$isbe(i64$umax,i64$umax), "i64$isbe(i64$umax,i64$umax)");
	_Static_assert(i64$isbe(i64$smax,i64$smax), "i64$isbe(i64$smax,i64$smax)");
	_Static_assert(i64$isbe(i64$zero,i64$zero), "i64$isbe(i64$zero,i64$zero)");
	_Static_assert(bit$not(i64$isa(i64$smax,i64$umax)), "bit$not(i64$isa(i64$smax,i64$umax))");
	_Static_assert(bit$not(i64$isa(i64$one,i64$umax)), "bit$not(i64$isa(i64$one,i64$umax))");
	_Static_assert(bit$not(i64$isa(i64$zero,i64$umax)), "bit$not(i64$isa(i64$zero,i64$umax))");
	_Static_assert(bit$not(i64$isb(i64$umax,i64$smax)), "bit$not(i64$isb(i64$umax,i64$smax))");
	_Static_assert(bit$not(i64$isb(i64$umax,i64$one)), "bit$not(i64$isb(i64$umax,i64$one))");
	_Static_assert(bit$not(i64$isb(i64$umax,i64$zero)), "bit$not(i64$isb(i64$umax,i64$zero))");
	_Static_assert(bit$not(i64$isa(i64$umax,i64$umax)), "bit$not(i64$isa(i64$umax,i64$umax))");
	_Static_assert(bit$not(i64$isa(i64$smax,i64$smax)), "bit$not(i64$isa(i64$smax,i64$smax))");
	_Static_assert(bit$not(i64$isa(i64$one,i64$one)), "bit$not(i64$isa(i64$one,i64$one))");
	_Static_assert(bit$not(i64$isa(i64$zero,i64$zero)), "bit$not(i64$isa(i64$zero,i64$zero))");
	_Static_assert(bit$not(i64$isb(i64$umax,i64$umax)), "bit$not(i64$isb(i64$umax,i64$umax))");
	_Static_assert(bit$not(i64$isb(i64$smax,i64$smax)), "bit$not(i64$isb(i64$smax,i64$smax))");
	_Static_assert(bit$not(i64$isb(i64$one,i64$one)), "bit$not(i64$isb(i64$one,i64$one))");
	_Static_assert(bit$not(i64$isb(i64$zero,i64$zero)), "bit$not(i64$isb(i64$zero,i64$zero))");
	_Static_assert(bit$not(i64$isae(i64$smax,i64$umax)), "bit$not(i64$isae(i64$smax,i64$umax))");
	_Static_assert(bit$not(i64$isae(i64$one,i64$umax)), "bit$not(i64$isae(i64$one,i64$umax))");
	_Static_assert(bit$not(i64$isae(i64$zero,i64$umax)), "bit$not(i64$isae(i64$zero,i64$umax))");
	_Static_assert(bit$not(i64$isbe(i64$umax,i64$smax)), "bit$not(i64$isbe(i64$umax,i64$smax))");
	_Static_assert(bit$not(i64$isbe(i64$umax,i64$one)), "bit$not(i64$isbe(i64$umax,i64$one))");
	_Static_assert(bit$not(i64$isbe(i64$umax,i64$zero)), "bit$not(i64$isbe(i64$umax,i64$zero))");
	_Static_assert(i64$isge(i64$zero,i64$zero), "i64$isge(i64$zero,i64$zero)");
	_Static_assert(i64$isge(i64$one,i64$zero), "i64$isge(i64$one,i64$zero)");
	_Static_assert(i64$isgt(i64$one,i64$zero), "i64$isgt(i64$one,i64$zero)");
	_Static_assert(i64$isle(i64$zero,i64$one), "i64$isle(i64$zero,i64$one)");
	_Static_assert(i64$isge(i64$smax,i64$one), "i64$isge(i64$smax,i64$one)");
	_Static_assert(i64$isge(i64$smax,i64$zero), "i64$isge(i64$smax,i64$zero)");
	_Static_assert(i64$isge(i64$smax,i64$smin), "i64$isge(i64$smax,i64$smin)");
	_Static_assert(i64$isgt(i64$smax,i64$one), "i64$isgt(i64$smax,i64$one)");
	_Static_assert(i64$isgt(i64$smax,i64$zero), "i64$isgt(i64$smax,i64$zero)");
	_Static_assert(i64$isgt(i64$smax,i64$smin), "i64$isgt(i64$smax,i64$smin)");
	_Static_assert(i64$isle(i64$smin,i64$one), "i64$isle(i64$smin,i64$one)");
	_Static_assert(i64$isle(i64$smin,i64$zero), "i64$isle(i64$smin,i64$zero)");
	_Static_assert(i64$isle(i64$smin,i64$smax), "i64$isle(i64$smin,i64$smax)");
	_Static_assert(i64$islt(i64$smin,i64$one), "i64$islt(i64$smin,i64$one)");
	_Static_assert(i64$isle(i64$smin,i64$zero), "i64$isle(i64$smin,i64$zero)");
	_Static_assert(i64$isle(i64$smin,i64$smax), "i64$isle(i64$smin,i64$smax)");
	_Static_assert(bit$not(i64$isle(i64$smax,i64$one)), "bit$not(i64$isle(i64$smax,i64$one))");
	_Static_assert(bit$not(i64$isle(i64$smax,i64$zero)), "bit$not(i64$isle(i64$smax,i64$zero))");
	_Static_assert(bit$not(i64$isle(i64$smax,i64$smin)), "bit$not(i64$isle(i64$smax,i64$smin))");
	_Static_assert(bit$not(i64$isle(i64$one,i64$smin)), "bit$not(i64$isle(i64$one,i64$smin))");
	_Static_assert(bit$not(i64$isle(i64$zero,i64$smin)), "bit$not(i64$isle(i64$zero,i64$smin))");
	_Static_assert(bit$not(i64$islt(i64$smax,i64$one)), "bit$not(i64$islt(i64$smax,i64$one))");
	_Static_assert(bit$not(i64$islt(i64$smax,i64$zero)), "bit$not(i64$islt(i64$smax,i64$zero))");
	_Static_assert(bit$not(i64$islt(i64$smax,i64$smin)), "bit$not(i64$islt(i64$smax,i64$smin))");
	_Static_assert(bit$not(i64$islt(i64$one,i64$smin)), "bit$not(i64$islt(i64$one,i64$smin))");
	_Static_assert(bit$not(i64$islt(i64$zero,i64$smin)), "bit$not(i64$islt(i64$zero,i64$smin))");
	_Static_assert(bit$not(i64$isge(i64$smin,i64$smax)), "bit$not(i64$isge(i64$smin,i64$smax))");
	_Static_assert(bit$not(i64$isge(i64$smin,i64$one)), "bit$not(i64$isge(i64$smin,i64$one))");
	_Static_assert(bit$not(i64$isge(i64$smin,i64$zero)), "bit$not(i64$isge(i64$smin,i64$zero))");
	_Static_assert(bit$not(i64$isge(i64$zero,i64$smax)), "bit$not(i64$isge(i64$zero,i64$smax))");
	_Static_assert(bit$not(i64$isge(i64$one,i64$smax)), "bit$not(i64$isge(i64$one,i64$smax))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$one)), "bit$not(i64$isgt(i64$smin,i64$one))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$zero)), "bit$not(i64$isgt(i64$smin,i64$zero))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$smax)), "bit$not(i64$isgt(i64$smin,i64$smax))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$one)), "bit$not(i64$isgt(i64$smin,i64$one))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$zero)), "bit$not(i64$isgt(i64$smin,i64$zero))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$smax)), "bit$not(i64$isgt(i64$smin,i64$smax))");
	_Static_assert(i64$isge(i64$smax,i64$smax), "i64$isge(i64$smax,i64$smax)");
	_Static_assert(i64$isge(i64$smin,i64$smin), "i64$isge(i64$smin,i64$smin)");
	_Static_assert(i64$isge(i64$zero,i64$zero), "i64$isge(i64$zero,i64$zero)");
	_Static_assert(i64$isle(i64$smax,i64$smax), "i64$isle(i64$smax,i64$smax)");
	_Static_assert(i64$isle(i64$smin,i64$smin), "i64$isle(i64$smin,i64$smin)");
	_Static_assert(i64$isle(i64$zero,i64$zero), "i64$isle(i64$zero,i64$zero)");
	_Static_assert(bit$not(i64$isgt(i64$smax,i64$smax)), "bit$not(i64$isgt(i64$smax,i64$smax))");
	_Static_assert(bit$not(i64$isgt(i64$smin,i64$smin)), "bit$not(i64$isgt(i64$smin,i64$smin))");
	_Static_assert(bit$not(i64$isgt(i64$zero,i64$zero)), "bit$not(i64$isgt(i64$zero,i64$zero))");
	_Static_assert(bit$not(i64$islt(i64$smax,i64$smax)), "bit$not(i64$islt(i64$smax,i64$smax))");
	_Static_assert(bit$not(i64$islt(i64$smin,i64$smin)), "bit$not(i64$islt(i64$smin,i64$smin))");
	_Static_assert(bit$not(i64$islt(i64$zero,i64$zero)), "bit$not(i64$islt(i64$zero,i64$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(i08$one, i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(i08$one, i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(i08$one, i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(i08$one, i32$one))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(01), i32$fromhex(00,00,00,02))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(01), i32$fromhex(00,00,00,02)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(02), i32$fromhex(00,00,00,04))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(02), i32$fromhex(00,00,00,04)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(03), i32$fromhex(00,00,00,08))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(03), i32$fromhex(00,00,00,08)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(04), i32$fromhex(00,00,00,10))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(04), i32$fromhex(00,00,00,10)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(05), i32$fromhex(00,00,00,20))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(05), i32$fromhex(00,00,00,20)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(06), i32$fromhex(00,00,00,40))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(06), i32$fromhex(00,00,00,40)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(07), i32$fromhex(00,00,00,80))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(07), i32$fromhex(00,00,00,80)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(08), i32$fromhex(00,00,01,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(08), i32$fromhex(00,00,01,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(09), i32$fromhex(00,00,02,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(09), i32$fromhex(00,00,02,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0a), i32$fromhex(00,00,04,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0a), i32$fromhex(00,00,04,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0b), i32$fromhex(00,00,08,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0b), i32$fromhex(00,00,08,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0c), i32$fromhex(00,00,10,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0c), i32$fromhex(00,00,10,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0d), i32$fromhex(00,00,20,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0d), i32$fromhex(00,00,20,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0e), i32$fromhex(00,00,40,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0e), i32$fromhex(00,00,40,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0f), i32$fromhex(00,00,80,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(0f), i32$fromhex(00,00,80,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(10), i32$fromhex(00,01,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(10), i32$fromhex(00,01,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(11), i32$fromhex(00,02,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(11), i32$fromhex(00,02,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(12), i32$fromhex(00,04,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(12), i32$fromhex(00,04,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(13), i32$fromhex(00,08,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(13), i32$fromhex(00,08,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(14), i32$fromhex(00,10,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(14), i32$fromhex(00,10,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(15), i32$fromhex(00,20,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(15), i32$fromhex(00,20,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(16), i32$fromhex(00,40,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(16), i32$fromhex(00,40,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(17), i32$fromhex(00,80,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(17), i32$fromhex(00,80,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(18), i32$fromhex(01,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(18), i32$fromhex(01,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(19), i32$fromhex(02,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(19), i32$fromhex(02,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1a), i32$fromhex(04,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1a), i32$fromhex(04,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1b), i32$fromhex(08,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1b), i32$fromhex(08,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1c), i32$fromhex(10,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1c), i32$fromhex(10,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1d), i32$fromhex(20,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1d), i32$fromhex(20,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1e), i32$fromhex(40,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1e), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1f), i32$fromhex(80,00,00,00))), "i32$iseq(i32$one, i32$rshift$zx(i08$fromhex(1f), i32$fromhex(80,00,00,00)))");
	_Static_assert(i32$iseq(i32$fromhex(c0,01,c0,22), i32$rshift$sx(i08$one, i32$fromhex(80,03,80,44))), "i32$iseq(i32$fromhex(c0,01,c0,22), i32$rshift$sx(i08$one, i32$fromhex(80,03,80,44)))");
	_Static_assert(i32$iseq(i32$fromhex(40,01,c0,22), i32$rshift$zx(i08$one, i32$fromhex(80,03,80,44))), "i32$iseq(i32$fromhex(40,01,c0,22), i32$rshift$zx(i08$one, i32$fromhex(80,03,80,44)))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$add(i64$one, i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$add(i64$one, i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(06,05,04,03,02,01,00,ff), i64$sub(i64$fromhex(07,06,05,04,03,02,02,00), i64$fromhex(01,01,01,01,01,01,01,01))), "i64$iseq(i64$fromhex(06,05,04,03,02,01,00,ff), i64$sub(i64$fromhex(07,06,05,04,03,02,02,00), i64$fromhex(01,01,01,01,01,01,01,01)))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(00), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(00), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(01), i08$lshift(byte$fromhex(00), i08$one)), "i08$iseq(i08$fromhex(01), i08$lshift(byte$fromhex(00), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(01), i08$lrot(byte$fromhex(00), i08$one)), "i08$iseq(i08$fromhex(01), i08$lrot(byte$fromhex(00), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(01), i08$rrot(byte$fromhex(00), i08$one)), "i08$iseq(i08$fromhex(01), i08$rrot(byte$fromhex(00), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(00), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(00), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(00), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(00), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(40), i08$rshift$zx(byte$fromhex(00), i08$fromhex(40))), "i08$iseq(i08$fromhex(40), i08$rshift$zx(byte$fromhex(00), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(00), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(00), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(00), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(00), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(01), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(01), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(02), i08$lshift(byte$fromhex(01), i08$one)), "i08$iseq(i08$fromhex(02), i08$lshift(byte$fromhex(01), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(02), i08$lrot(byte$fromhex(01), i08$one)), "i08$iseq(i08$fromhex(02), i08$lrot(byte$fromhex(01), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(80), i08$rrot(byte$fromhex(01), i08$one)), "i08$iseq(i08$fromhex(80), i08$rrot(byte$fromhex(01), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(01), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(01), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(01), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(01), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(20), i08$rshift$zx(byte$fromhex(01), i08$fromhex(40))), "i08$iseq(i08$fromhex(20), i08$rshift$zx(byte$fromhex(01), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(01), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(01), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(01), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(01), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(02), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(02), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(04), i08$lshift(byte$fromhex(02), i08$one)), "i08$iseq(i08$fromhex(04), i08$lshift(byte$fromhex(02), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(04), i08$lrot(byte$fromhex(02), i08$one)), "i08$iseq(i08$fromhex(04), i08$lrot(byte$fromhex(02), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(40), i08$rrot(byte$fromhex(02), i08$one)), "i08$iseq(i08$fromhex(40), i08$rrot(byte$fromhex(02), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(02), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(02), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(02), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(02), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(10), i08$rshift$zx(byte$fromhex(02), i08$fromhex(40))), "i08$iseq(i08$fromhex(10), i08$rshift$zx(byte$fromhex(02), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(02), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(02), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(02), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(02), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(03), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(03), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(08), i08$lshift(byte$fromhex(03), i08$one)), "i08$iseq(i08$fromhex(08), i08$lshift(byte$fromhex(03), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(08), i08$lrot(byte$fromhex(03), i08$one)), "i08$iseq(i08$fromhex(08), i08$lrot(byte$fromhex(03), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(20), i08$rrot(byte$fromhex(03), i08$one)), "i08$iseq(i08$fromhex(20), i08$rrot(byte$fromhex(03), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(03), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(03), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(03), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(03), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(08), i08$rshift$zx(byte$fromhex(03), i08$fromhex(40))), "i08$iseq(i08$fromhex(08), i08$rshift$zx(byte$fromhex(03), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(03), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(03), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(03), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(03), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(04), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(04), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(10), i08$lshift(byte$fromhex(04), i08$one)), "i08$iseq(i08$fromhex(10), i08$lshift(byte$fromhex(04), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(10), i08$lrot(byte$fromhex(04), i08$one)), "i08$iseq(i08$fromhex(10), i08$lrot(byte$fromhex(04), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(10), i08$rrot(byte$fromhex(04), i08$one)), "i08$iseq(i08$fromhex(10), i08$rrot(byte$fromhex(04), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(04), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(04), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(04), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(04), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(04), i08$rshift$zx(byte$fromhex(04), i08$fromhex(40))), "i08$iseq(i08$fromhex(04), i08$rshift$zx(byte$fromhex(04), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(04), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(04), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(04), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(04), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(05), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(05), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(20), i08$lshift(byte$fromhex(05), i08$one)), "i08$iseq(i08$fromhex(20), i08$lshift(byte$fromhex(05), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(20), i08$lrot(byte$fromhex(05), i08$one)), "i08$iseq(i08$fromhex(20), i08$lrot(byte$fromhex(05), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(08), i08$rrot(byte$fromhex(05), i08$one)), "i08$iseq(i08$fromhex(08), i08$rrot(byte$fromhex(05), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(05), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(05), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(05), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(05), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(02), i08$rshift$zx(byte$fromhex(05), i08$fromhex(40))), "i08$iseq(i08$fromhex(02), i08$rshift$zx(byte$fromhex(05), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(05), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(05), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(05), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(05), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(06), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(06), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(40), i08$lshift(byte$fromhex(06), i08$one)), "i08$iseq(i08$fromhex(40), i08$lshift(byte$fromhex(06), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(40), i08$lrot(byte$fromhex(06), i08$one)), "i08$iseq(i08$fromhex(40), i08$lrot(byte$fromhex(06), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(04), i08$rrot(byte$fromhex(06), i08$one)), "i08$iseq(i08$fromhex(04), i08$rrot(byte$fromhex(06), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(06), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(06), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(06), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(06), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(01), i08$rshift$zx(byte$fromhex(06), i08$fromhex(40))), "i08$iseq(i08$fromhex(01), i08$rshift$zx(byte$fromhex(06), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(06), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(06), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(06), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(06), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$lshift(byte$fromhex(07), i08$zero)), "i08$iseq(i08$zero, i08$lshift(byte$fromhex(07), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(80), i08$lshift(byte$fromhex(07), i08$one)), "i08$iseq(i08$fromhex(80), i08$lshift(byte$fromhex(07), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(80), i08$lrot(byte$fromhex(07), i08$one)), "i08$iseq(i08$fromhex(80), i08$lrot(byte$fromhex(07), i08$one))");
	_Static_assert(i08$iseq(i08$fromhex(02), i08$rrot(byte$fromhex(07), i08$one)), "i08$iseq(i08$fromhex(02), i08$rrot(byte$fromhex(07), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$lrot(byte$fromhex(07), i08$zero)), "i08$iseq(i08$zero, i08$lrot(byte$fromhex(07), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rrot(byte$fromhex(07), i08$zero)), "i08$iseq(i08$zero, i08$rrot(byte$fromhex(07), i08$zero))");
	_Static_assert(i08$iseq(i08$fromhex(00), i08$rshift$zx(byte$fromhex(07), i08$fromhex(40))), "i08$iseq(i08$fromhex(00), i08$rshift$zx(byte$fromhex(07), i08$fromhex(40)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(07), i08$zero)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(07), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(07), i08$zero)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(07), i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(01), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(01), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(01), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(01), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(01), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(01), i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(02), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(02), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(02), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(02), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(02), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(02), i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(03), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(03), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(03), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(03), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(03), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(03), i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(04), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(04), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(04), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(04), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(04), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(04), i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(05), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(05), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(05), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(05), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(05), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(05), i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(06), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(06), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(06), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(06), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(06), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(06), i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(07), i08$one)), "i08$iseq(i08$zero, i08$rshift$zx(byte$fromhex(07), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(07), i08$one)), "i08$iseq(i08$zero, i08$rshift$sx(byte$fromhex(07), i08$one))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(07), i08$inv(i08$zero))), "i08$iseq(i08$inv(i08$zero), i08$rshift$sx(byte$fromhex(07), i08$inv(i08$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(00), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(00), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,01), i16$lshift(byte$fromhex(00), i16$one)), "i16$iseq(i16$fromhex(00,01), i16$lshift(byte$fromhex(00), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,01), i16$lrot(byte$fromhex(00), i16$one)), "i16$iseq(i16$fromhex(00,01), i16$lrot(byte$fromhex(00), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,01), i16$rrot(byte$fromhex(00), i16$one)), "i16$iseq(i16$fromhex(00,01), i16$rrot(byte$fromhex(00), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(00), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(00), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(00), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(00), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(40,00), i16$rshift$zx(byte$fromhex(00), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(40,00), i16$rshift$zx(byte$fromhex(00), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(00), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(00), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(00), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(00), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(01), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(01), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,02), i16$lshift(byte$fromhex(01), i16$one)), "i16$iseq(i16$fromhex(00,02), i16$lshift(byte$fromhex(01), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,02), i16$lrot(byte$fromhex(01), i16$one)), "i16$iseq(i16$fromhex(00,02), i16$lrot(byte$fromhex(01), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(80,00), i16$rrot(byte$fromhex(01), i16$one)), "i16$iseq(i16$fromhex(80,00), i16$rrot(byte$fromhex(01), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(01), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(01), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(01), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(01), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(20,00), i16$rshift$zx(byte$fromhex(01), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(20,00), i16$rshift$zx(byte$fromhex(01), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(01), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(01), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(01), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(01), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(02), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(02), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,04), i16$lshift(byte$fromhex(02), i16$one)), "i16$iseq(i16$fromhex(00,04), i16$lshift(byte$fromhex(02), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,04), i16$lrot(byte$fromhex(02), i16$one)), "i16$iseq(i16$fromhex(00,04), i16$lrot(byte$fromhex(02), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(40,00), i16$rrot(byte$fromhex(02), i16$one)), "i16$iseq(i16$fromhex(40,00), i16$rrot(byte$fromhex(02), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(02), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(02), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(02), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(02), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(10,00), i16$rshift$zx(byte$fromhex(02), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(10,00), i16$rshift$zx(byte$fromhex(02), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(02), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(02), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(02), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(02), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(03), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(03), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,08), i16$lshift(byte$fromhex(03), i16$one)), "i16$iseq(i16$fromhex(00,08), i16$lshift(byte$fromhex(03), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,08), i16$lrot(byte$fromhex(03), i16$one)), "i16$iseq(i16$fromhex(00,08), i16$lrot(byte$fromhex(03), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(20,00), i16$rrot(byte$fromhex(03), i16$one)), "i16$iseq(i16$fromhex(20,00), i16$rrot(byte$fromhex(03), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(03), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(03), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(03), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(03), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(08,00), i16$rshift$zx(byte$fromhex(03), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(08,00), i16$rshift$zx(byte$fromhex(03), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(03), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(03), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(03), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(03), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(04), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(04), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,10), i16$lshift(byte$fromhex(04), i16$one)), "i16$iseq(i16$fromhex(00,10), i16$lshift(byte$fromhex(04), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,10), i16$lrot(byte$fromhex(04), i16$one)), "i16$iseq(i16$fromhex(00,10), i16$lrot(byte$fromhex(04), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(10,00), i16$rrot(byte$fromhex(04), i16$one)), "i16$iseq(i16$fromhex(10,00), i16$rrot(byte$fromhex(04), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(04), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(04), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(04), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(04), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(04,00), i16$rshift$zx(byte$fromhex(04), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(04,00), i16$rshift$zx(byte$fromhex(04), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(04), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(04), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(04), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(04), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(05), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(05), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,20), i16$lshift(byte$fromhex(05), i16$one)), "i16$iseq(i16$fromhex(00,20), i16$lshift(byte$fromhex(05), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,20), i16$lrot(byte$fromhex(05), i16$one)), "i16$iseq(i16$fromhex(00,20), i16$lrot(byte$fromhex(05), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(08,00), i16$rrot(byte$fromhex(05), i16$one)), "i16$iseq(i16$fromhex(08,00), i16$rrot(byte$fromhex(05), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(05), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(05), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(05), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(05), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(02,00), i16$rshift$zx(byte$fromhex(05), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(02,00), i16$rshift$zx(byte$fromhex(05), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(05), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(05), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(05), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(05), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(06), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(06), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,40), i16$lshift(byte$fromhex(06), i16$one)), "i16$iseq(i16$fromhex(00,40), i16$lshift(byte$fromhex(06), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,40), i16$lrot(byte$fromhex(06), i16$one)), "i16$iseq(i16$fromhex(00,40), i16$lrot(byte$fromhex(06), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(04,00), i16$rrot(byte$fromhex(06), i16$one)), "i16$iseq(i16$fromhex(04,00), i16$rrot(byte$fromhex(06), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(06), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(06), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(06), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(06), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(01,00), i16$rshift$zx(byte$fromhex(06), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(01,00), i16$rshift$zx(byte$fromhex(06), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(06), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(06), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(06), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(06), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(07), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(07), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,80), i16$lshift(byte$fromhex(07), i16$one)), "i16$iseq(i16$fromhex(00,80), i16$lshift(byte$fromhex(07), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,80), i16$lrot(byte$fromhex(07), i16$one)), "i16$iseq(i16$fromhex(00,80), i16$lrot(byte$fromhex(07), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(02,00), i16$rrot(byte$fromhex(07), i16$one)), "i16$iseq(i16$fromhex(02,00), i16$rrot(byte$fromhex(07), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(07), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(07), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(07), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(07), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,80), i16$rshift$zx(byte$fromhex(07), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,80), i16$rshift$zx(byte$fromhex(07), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(07), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(07), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(07), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(07), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(08), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(08), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(01,00), i16$lshift(byte$fromhex(08), i16$one)), "i16$iseq(i16$fromhex(01,00), i16$lshift(byte$fromhex(08), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(01,00), i16$lrot(byte$fromhex(08), i16$one)), "i16$iseq(i16$fromhex(01,00), i16$lrot(byte$fromhex(08), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(01,00), i16$rrot(byte$fromhex(08), i16$one)), "i16$iseq(i16$fromhex(01,00), i16$rrot(byte$fromhex(08), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(08), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(08), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(08), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(08), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,40), i16$rshift$zx(byte$fromhex(08), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,40), i16$rshift$zx(byte$fromhex(08), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(08), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(08), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(08), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(08), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(09), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(09), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(02,00), i16$lshift(byte$fromhex(09), i16$one)), "i16$iseq(i16$fromhex(02,00), i16$lshift(byte$fromhex(09), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(02,00), i16$lrot(byte$fromhex(09), i16$one)), "i16$iseq(i16$fromhex(02,00), i16$lrot(byte$fromhex(09), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,80), i16$rrot(byte$fromhex(09), i16$one)), "i16$iseq(i16$fromhex(00,80), i16$rrot(byte$fromhex(09), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(09), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(09), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(09), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(09), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,20), i16$rshift$zx(byte$fromhex(09), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,20), i16$rshift$zx(byte$fromhex(09), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(09), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(09), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(09), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(09), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(0a), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(0a), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(04,00), i16$lshift(byte$fromhex(0a), i16$one)), "i16$iseq(i16$fromhex(04,00), i16$lshift(byte$fromhex(0a), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(04,00), i16$lrot(byte$fromhex(0a), i16$one)), "i16$iseq(i16$fromhex(04,00), i16$lrot(byte$fromhex(0a), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,40), i16$rrot(byte$fromhex(0a), i16$one)), "i16$iseq(i16$fromhex(00,40), i16$rrot(byte$fromhex(0a), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(0a), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(0a), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(0a), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(0a), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,10), i16$rshift$zx(byte$fromhex(0a), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,10), i16$rshift$zx(byte$fromhex(0a), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0a), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0a), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0a), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0a), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(0b), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(0b), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(08,00), i16$lshift(byte$fromhex(0b), i16$one)), "i16$iseq(i16$fromhex(08,00), i16$lshift(byte$fromhex(0b), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(08,00), i16$lrot(byte$fromhex(0b), i16$one)), "i16$iseq(i16$fromhex(08,00), i16$lrot(byte$fromhex(0b), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,20), i16$rrot(byte$fromhex(0b), i16$one)), "i16$iseq(i16$fromhex(00,20), i16$rrot(byte$fromhex(0b), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(0b), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(0b), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(0b), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(0b), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,08), i16$rshift$zx(byte$fromhex(0b), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,08), i16$rshift$zx(byte$fromhex(0b), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0b), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0b), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0b), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0b), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(0c), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(0c), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(10,00), i16$lshift(byte$fromhex(0c), i16$one)), "i16$iseq(i16$fromhex(10,00), i16$lshift(byte$fromhex(0c), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(10,00), i16$lrot(byte$fromhex(0c), i16$one)), "i16$iseq(i16$fromhex(10,00), i16$lrot(byte$fromhex(0c), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,10), i16$rrot(byte$fromhex(0c), i16$one)), "i16$iseq(i16$fromhex(00,10), i16$rrot(byte$fromhex(0c), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(0c), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(0c), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(0c), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(0c), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,04), i16$rshift$zx(byte$fromhex(0c), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,04), i16$rshift$zx(byte$fromhex(0c), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0c), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0c), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0c), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0c), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(0d), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(0d), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(20,00), i16$lshift(byte$fromhex(0d), i16$one)), "i16$iseq(i16$fromhex(20,00), i16$lshift(byte$fromhex(0d), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(20,00), i16$lrot(byte$fromhex(0d), i16$one)), "i16$iseq(i16$fromhex(20,00), i16$lrot(byte$fromhex(0d), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,08), i16$rrot(byte$fromhex(0d), i16$one)), "i16$iseq(i16$fromhex(00,08), i16$rrot(byte$fromhex(0d), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(0d), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(0d), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(0d), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(0d), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,02), i16$rshift$zx(byte$fromhex(0d), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,02), i16$rshift$zx(byte$fromhex(0d), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0d), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0d), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0d), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0d), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(0e), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(0e), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(40,00), i16$lshift(byte$fromhex(0e), i16$one)), "i16$iseq(i16$fromhex(40,00), i16$lshift(byte$fromhex(0e), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(40,00), i16$lrot(byte$fromhex(0e), i16$one)), "i16$iseq(i16$fromhex(40,00), i16$lrot(byte$fromhex(0e), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,04), i16$rrot(byte$fromhex(0e), i16$one)), "i16$iseq(i16$fromhex(00,04), i16$rrot(byte$fromhex(0e), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(0e), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(0e), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(0e), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(0e), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,01), i16$rshift$zx(byte$fromhex(0e), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,01), i16$rshift$zx(byte$fromhex(0e), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0e), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0e), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0e), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0e), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$lshift(byte$fromhex(0f), i16$zero)), "i16$iseq(i16$zero, i16$lshift(byte$fromhex(0f), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(80,00), i16$lshift(byte$fromhex(0f), i16$one)), "i16$iseq(i16$fromhex(80,00), i16$lshift(byte$fromhex(0f), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(80,00), i16$lrot(byte$fromhex(0f), i16$one)), "i16$iseq(i16$fromhex(80,00), i16$lrot(byte$fromhex(0f), i16$one))");
	_Static_assert(i16$iseq(i16$fromhex(00,02), i16$rrot(byte$fromhex(0f), i16$one)), "i16$iseq(i16$fromhex(00,02), i16$rrot(byte$fromhex(0f), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$lrot(byte$fromhex(0f), i16$zero)), "i16$iseq(i16$zero, i16$lrot(byte$fromhex(0f), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rrot(byte$fromhex(0f), i16$zero)), "i16$iseq(i16$zero, i16$rrot(byte$fromhex(0f), i16$zero))");
	_Static_assert(i16$iseq(i16$fromhex(00,00), i16$rshift$zx(byte$fromhex(0f), i16$fromhex(40,00))), "i16$iseq(i16$fromhex(00,00), i16$rshift$zx(byte$fromhex(0f), i16$fromhex(40,00)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0f), i16$zero)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0f), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0f), i16$zero)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0f), i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(01), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(01), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(01), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(01), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(01), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(01), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(02), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(02), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(02), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(02), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(02), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(02), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(03), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(03), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(03), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(03), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(03), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(03), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(04), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(04), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(04), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(04), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(04), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(04), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(05), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(05), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(05), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(05), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(05), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(05), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(06), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(06), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(06), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(06), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(06), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(06), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(07), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(07), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(07), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(07), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(07), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(07), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(08), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(08), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(08), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(08), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(08), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(08), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(09), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(09), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(09), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(09), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(09), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(09), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0a), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0a), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0a), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0a), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0a), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0a), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0b), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0b), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0b), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0b), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0b), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0b), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0c), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0c), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0c), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0c), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0c), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0c), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0d), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0d), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0d), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0d), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0d), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0d), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0e), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0e), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0e), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0e), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0e), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0e), i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0f), i16$one)), "i16$iseq(i16$zero, i16$rshift$zx(byte$fromhex(0f), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0f), i16$one)), "i16$iseq(i16$zero, i16$rshift$sx(byte$fromhex(0f), i16$one))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0f), i16$inv(i16$zero))), "i16$iseq(i16$inv(i16$zero), i16$rshift$sx(byte$fromhex(0f), i16$inv(i16$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(00), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(00), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,01), i32$lshift(byte$fromhex(00), i32$one)), "i32$iseq(i32$fromhex(00,00,00,01), i32$lshift(byte$fromhex(00), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,01), i32$lrot(byte$fromhex(00), i32$one)), "i32$iseq(i32$fromhex(00,00,00,01), i32$lrot(byte$fromhex(00), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,01), i32$rrot(byte$fromhex(00), i32$one)), "i32$iseq(i32$fromhex(00,00,00,01), i32$rrot(byte$fromhex(00), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(00), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(00), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(00), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(00), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(40,00,00,00), i32$rshift$zx(byte$fromhex(00), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(40,00,00,00), i32$rshift$zx(byte$fromhex(00), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(00), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(00), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(00), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(00), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(01), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(01), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,02), i32$lshift(byte$fromhex(01), i32$one)), "i32$iseq(i32$fromhex(00,00,00,02), i32$lshift(byte$fromhex(01), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,02), i32$lrot(byte$fromhex(01), i32$one)), "i32$iseq(i32$fromhex(00,00,00,02), i32$lrot(byte$fromhex(01), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(80,00,00,00), i32$rrot(byte$fromhex(01), i32$one)), "i32$iseq(i32$fromhex(80,00,00,00), i32$rrot(byte$fromhex(01), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(01), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(01), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(01), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(01), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(20,00,00,00), i32$rshift$zx(byte$fromhex(01), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(20,00,00,00), i32$rshift$zx(byte$fromhex(01), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(01), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(01), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(01), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(01), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(02), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(02), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,04), i32$lshift(byte$fromhex(02), i32$one)), "i32$iseq(i32$fromhex(00,00,00,04), i32$lshift(byte$fromhex(02), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,04), i32$lrot(byte$fromhex(02), i32$one)), "i32$iseq(i32$fromhex(00,00,00,04), i32$lrot(byte$fromhex(02), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(40,00,00,00), i32$rrot(byte$fromhex(02), i32$one)), "i32$iseq(i32$fromhex(40,00,00,00), i32$rrot(byte$fromhex(02), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(02), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(02), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(02), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(02), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(10,00,00,00), i32$rshift$zx(byte$fromhex(02), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(10,00,00,00), i32$rshift$zx(byte$fromhex(02), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(02), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(02), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(02), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(02), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(03), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(03), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,08), i32$lshift(byte$fromhex(03), i32$one)), "i32$iseq(i32$fromhex(00,00,00,08), i32$lshift(byte$fromhex(03), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,08), i32$lrot(byte$fromhex(03), i32$one)), "i32$iseq(i32$fromhex(00,00,00,08), i32$lrot(byte$fromhex(03), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(20,00,00,00), i32$rrot(byte$fromhex(03), i32$one)), "i32$iseq(i32$fromhex(20,00,00,00), i32$rrot(byte$fromhex(03), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(03), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(03), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(03), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(03), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(08,00,00,00), i32$rshift$zx(byte$fromhex(03), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(08,00,00,00), i32$rshift$zx(byte$fromhex(03), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(03), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(03), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(03), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(03), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(04), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(04), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,10), i32$lshift(byte$fromhex(04), i32$one)), "i32$iseq(i32$fromhex(00,00,00,10), i32$lshift(byte$fromhex(04), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,10), i32$lrot(byte$fromhex(04), i32$one)), "i32$iseq(i32$fromhex(00,00,00,10), i32$lrot(byte$fromhex(04), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(10,00,00,00), i32$rrot(byte$fromhex(04), i32$one)), "i32$iseq(i32$fromhex(10,00,00,00), i32$rrot(byte$fromhex(04), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(04), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(04), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(04), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(04), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(04,00,00,00), i32$rshift$zx(byte$fromhex(04), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(04,00,00,00), i32$rshift$zx(byte$fromhex(04), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(04), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(04), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(04), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(04), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(05), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(05), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,20), i32$lshift(byte$fromhex(05), i32$one)), "i32$iseq(i32$fromhex(00,00,00,20), i32$lshift(byte$fromhex(05), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,20), i32$lrot(byte$fromhex(05), i32$one)), "i32$iseq(i32$fromhex(00,00,00,20), i32$lrot(byte$fromhex(05), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(08,00,00,00), i32$rrot(byte$fromhex(05), i32$one)), "i32$iseq(i32$fromhex(08,00,00,00), i32$rrot(byte$fromhex(05), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(05), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(05), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(05), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(05), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(02,00,00,00), i32$rshift$zx(byte$fromhex(05), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(02,00,00,00), i32$rshift$zx(byte$fromhex(05), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(05), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(05), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(05), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(05), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(06), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(06), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,40), i32$lshift(byte$fromhex(06), i32$one)), "i32$iseq(i32$fromhex(00,00,00,40), i32$lshift(byte$fromhex(06), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,40), i32$lrot(byte$fromhex(06), i32$one)), "i32$iseq(i32$fromhex(00,00,00,40), i32$lrot(byte$fromhex(06), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(04,00,00,00), i32$rrot(byte$fromhex(06), i32$one)), "i32$iseq(i32$fromhex(04,00,00,00), i32$rrot(byte$fromhex(06), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(06), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(06), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(06), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(06), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(01,00,00,00), i32$rshift$zx(byte$fromhex(06), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(01,00,00,00), i32$rshift$zx(byte$fromhex(06), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(06), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(06), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(06), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(06), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(07), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(07), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,80), i32$lshift(byte$fromhex(07), i32$one)), "i32$iseq(i32$fromhex(00,00,00,80), i32$lshift(byte$fromhex(07), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,80), i32$lrot(byte$fromhex(07), i32$one)), "i32$iseq(i32$fromhex(00,00,00,80), i32$lrot(byte$fromhex(07), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(02,00,00,00), i32$rrot(byte$fromhex(07), i32$one)), "i32$iseq(i32$fromhex(02,00,00,00), i32$rrot(byte$fromhex(07), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(07), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(07), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(07), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(07), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,80,00,00), i32$rshift$zx(byte$fromhex(07), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,80,00,00), i32$rshift$zx(byte$fromhex(07), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(07), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(07), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(07), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(07), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(08), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(08), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,01,00), i32$lshift(byte$fromhex(08), i32$one)), "i32$iseq(i32$fromhex(00,00,01,00), i32$lshift(byte$fromhex(08), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,01,00), i32$lrot(byte$fromhex(08), i32$one)), "i32$iseq(i32$fromhex(00,00,01,00), i32$lrot(byte$fromhex(08), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(01,00,00,00), i32$rrot(byte$fromhex(08), i32$one)), "i32$iseq(i32$fromhex(01,00,00,00), i32$rrot(byte$fromhex(08), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(08), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(08), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(08), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(08), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,40,00,00), i32$rshift$zx(byte$fromhex(08), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,40,00,00), i32$rshift$zx(byte$fromhex(08), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(08), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(08), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(08), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(08), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(09), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(09), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,02,00), i32$lshift(byte$fromhex(09), i32$one)), "i32$iseq(i32$fromhex(00,00,02,00), i32$lshift(byte$fromhex(09), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,02,00), i32$lrot(byte$fromhex(09), i32$one)), "i32$iseq(i32$fromhex(00,00,02,00), i32$lrot(byte$fromhex(09), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,80,00,00), i32$rrot(byte$fromhex(09), i32$one)), "i32$iseq(i32$fromhex(00,80,00,00), i32$rrot(byte$fromhex(09), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(09), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(09), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(09), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(09), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,20,00,00), i32$rshift$zx(byte$fromhex(09), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,20,00,00), i32$rshift$zx(byte$fromhex(09), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(09), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(09), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(09), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(09), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(0a), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(0a), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,04,00), i32$lshift(byte$fromhex(0a), i32$one)), "i32$iseq(i32$fromhex(00,00,04,00), i32$lshift(byte$fromhex(0a), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,04,00), i32$lrot(byte$fromhex(0a), i32$one)), "i32$iseq(i32$fromhex(00,00,04,00), i32$lrot(byte$fromhex(0a), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,40,00,00), i32$rrot(byte$fromhex(0a), i32$one)), "i32$iseq(i32$fromhex(00,40,00,00), i32$rrot(byte$fromhex(0a), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(0a), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(0a), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(0a), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(0a), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,10,00,00), i32$rshift$zx(byte$fromhex(0a), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,10,00,00), i32$rshift$zx(byte$fromhex(0a), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0a), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0a), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0a), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0a), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(0b), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(0b), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,08,00), i32$lshift(byte$fromhex(0b), i32$one)), "i32$iseq(i32$fromhex(00,00,08,00), i32$lshift(byte$fromhex(0b), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,08,00), i32$lrot(byte$fromhex(0b), i32$one)), "i32$iseq(i32$fromhex(00,00,08,00), i32$lrot(byte$fromhex(0b), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,20,00,00), i32$rrot(byte$fromhex(0b), i32$one)), "i32$iseq(i32$fromhex(00,20,00,00), i32$rrot(byte$fromhex(0b), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(0b), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(0b), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(0b), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(0b), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,08,00,00), i32$rshift$zx(byte$fromhex(0b), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,08,00,00), i32$rshift$zx(byte$fromhex(0b), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0b), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0b), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0b), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0b), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(0c), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(0c), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,10,00), i32$lshift(byte$fromhex(0c), i32$one)), "i32$iseq(i32$fromhex(00,00,10,00), i32$lshift(byte$fromhex(0c), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,10,00), i32$lrot(byte$fromhex(0c), i32$one)), "i32$iseq(i32$fromhex(00,00,10,00), i32$lrot(byte$fromhex(0c), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,10,00,00), i32$rrot(byte$fromhex(0c), i32$one)), "i32$iseq(i32$fromhex(00,10,00,00), i32$rrot(byte$fromhex(0c), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(0c), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(0c), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(0c), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(0c), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,04,00,00), i32$rshift$zx(byte$fromhex(0c), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,04,00,00), i32$rshift$zx(byte$fromhex(0c), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0c), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0c), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0c), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0c), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(0d), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(0d), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,20,00), i32$lshift(byte$fromhex(0d), i32$one)), "i32$iseq(i32$fromhex(00,00,20,00), i32$lshift(byte$fromhex(0d), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,20,00), i32$lrot(byte$fromhex(0d), i32$one)), "i32$iseq(i32$fromhex(00,00,20,00), i32$lrot(byte$fromhex(0d), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,08,00,00), i32$rrot(byte$fromhex(0d), i32$one)), "i32$iseq(i32$fromhex(00,08,00,00), i32$rrot(byte$fromhex(0d), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(0d), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(0d), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(0d), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(0d), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,02,00,00), i32$rshift$zx(byte$fromhex(0d), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,02,00,00), i32$rshift$zx(byte$fromhex(0d), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0d), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0d), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0d), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0d), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(0e), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(0e), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,40,00), i32$lshift(byte$fromhex(0e), i32$one)), "i32$iseq(i32$fromhex(00,00,40,00), i32$lshift(byte$fromhex(0e), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,40,00), i32$lrot(byte$fromhex(0e), i32$one)), "i32$iseq(i32$fromhex(00,00,40,00), i32$lrot(byte$fromhex(0e), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,04,00,00), i32$rrot(byte$fromhex(0e), i32$one)), "i32$iseq(i32$fromhex(00,04,00,00), i32$rrot(byte$fromhex(0e), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(0e), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(0e), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(0e), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(0e), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,01,00,00), i32$rshift$zx(byte$fromhex(0e), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,01,00,00), i32$rshift$zx(byte$fromhex(0e), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0e), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0e), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0e), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0e), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(0f), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(0f), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,80,00), i32$lshift(byte$fromhex(0f), i32$one)), "i32$iseq(i32$fromhex(00,00,80,00), i32$lshift(byte$fromhex(0f), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,80,00), i32$lrot(byte$fromhex(0f), i32$one)), "i32$iseq(i32$fromhex(00,00,80,00), i32$lrot(byte$fromhex(0f), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,02,00,00), i32$rrot(byte$fromhex(0f), i32$one)), "i32$iseq(i32$fromhex(00,02,00,00), i32$rrot(byte$fromhex(0f), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(0f), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(0f), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(0f), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(0f), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,80,00), i32$rshift$zx(byte$fromhex(0f), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,80,00), i32$rshift$zx(byte$fromhex(0f), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0f), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0f), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0f), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0f), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(10), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(10), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,01,00,00), i32$lshift(byte$fromhex(10), i32$one)), "i32$iseq(i32$fromhex(00,01,00,00), i32$lshift(byte$fromhex(10), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,01,00,00), i32$lrot(byte$fromhex(10), i32$one)), "i32$iseq(i32$fromhex(00,01,00,00), i32$lrot(byte$fromhex(10), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,01,00,00), i32$rrot(byte$fromhex(10), i32$one)), "i32$iseq(i32$fromhex(00,01,00,00), i32$rrot(byte$fromhex(10), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(10), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(10), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(10), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(10), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,40,00), i32$rshift$zx(byte$fromhex(10), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,40,00), i32$rshift$zx(byte$fromhex(10), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(10), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(10), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(10), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(10), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(11), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(11), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,02,00,00), i32$lshift(byte$fromhex(11), i32$one)), "i32$iseq(i32$fromhex(00,02,00,00), i32$lshift(byte$fromhex(11), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,02,00,00), i32$lrot(byte$fromhex(11), i32$one)), "i32$iseq(i32$fromhex(00,02,00,00), i32$lrot(byte$fromhex(11), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,80,00), i32$rrot(byte$fromhex(11), i32$one)), "i32$iseq(i32$fromhex(00,00,80,00), i32$rrot(byte$fromhex(11), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(11), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(11), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(11), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(11), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,20,00), i32$rshift$zx(byte$fromhex(11), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,20,00), i32$rshift$zx(byte$fromhex(11), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(11), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(11), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(11), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(11), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(12), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(12), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,04,00,00), i32$lshift(byte$fromhex(12), i32$one)), "i32$iseq(i32$fromhex(00,04,00,00), i32$lshift(byte$fromhex(12), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,04,00,00), i32$lrot(byte$fromhex(12), i32$one)), "i32$iseq(i32$fromhex(00,04,00,00), i32$lrot(byte$fromhex(12), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,40,00), i32$rrot(byte$fromhex(12), i32$one)), "i32$iseq(i32$fromhex(00,00,40,00), i32$rrot(byte$fromhex(12), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(12), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(12), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(12), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(12), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,10,00), i32$rshift$zx(byte$fromhex(12), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,10,00), i32$rshift$zx(byte$fromhex(12), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(12), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(12), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(12), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(12), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(13), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(13), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,08,00,00), i32$lshift(byte$fromhex(13), i32$one)), "i32$iseq(i32$fromhex(00,08,00,00), i32$lshift(byte$fromhex(13), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,08,00,00), i32$lrot(byte$fromhex(13), i32$one)), "i32$iseq(i32$fromhex(00,08,00,00), i32$lrot(byte$fromhex(13), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,20,00), i32$rrot(byte$fromhex(13), i32$one)), "i32$iseq(i32$fromhex(00,00,20,00), i32$rrot(byte$fromhex(13), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(13), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(13), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(13), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(13), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,08,00), i32$rshift$zx(byte$fromhex(13), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,08,00), i32$rshift$zx(byte$fromhex(13), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(13), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(13), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(13), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(13), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(14), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(14), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,10,00,00), i32$lshift(byte$fromhex(14), i32$one)), "i32$iseq(i32$fromhex(00,10,00,00), i32$lshift(byte$fromhex(14), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,10,00,00), i32$lrot(byte$fromhex(14), i32$one)), "i32$iseq(i32$fromhex(00,10,00,00), i32$lrot(byte$fromhex(14), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,10,00), i32$rrot(byte$fromhex(14), i32$one)), "i32$iseq(i32$fromhex(00,00,10,00), i32$rrot(byte$fromhex(14), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(14), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(14), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(14), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(14), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,04,00), i32$rshift$zx(byte$fromhex(14), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,04,00), i32$rshift$zx(byte$fromhex(14), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(14), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(14), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(14), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(14), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(15), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(15), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,20,00,00), i32$lshift(byte$fromhex(15), i32$one)), "i32$iseq(i32$fromhex(00,20,00,00), i32$lshift(byte$fromhex(15), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,20,00,00), i32$lrot(byte$fromhex(15), i32$one)), "i32$iseq(i32$fromhex(00,20,00,00), i32$lrot(byte$fromhex(15), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,08,00), i32$rrot(byte$fromhex(15), i32$one)), "i32$iseq(i32$fromhex(00,00,08,00), i32$rrot(byte$fromhex(15), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(15), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(15), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(15), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(15), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,02,00), i32$rshift$zx(byte$fromhex(15), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,02,00), i32$rshift$zx(byte$fromhex(15), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(15), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(15), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(15), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(15), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(16), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(16), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,40,00,00), i32$lshift(byte$fromhex(16), i32$one)), "i32$iseq(i32$fromhex(00,40,00,00), i32$lshift(byte$fromhex(16), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,40,00,00), i32$lrot(byte$fromhex(16), i32$one)), "i32$iseq(i32$fromhex(00,40,00,00), i32$lrot(byte$fromhex(16), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,04,00), i32$rrot(byte$fromhex(16), i32$one)), "i32$iseq(i32$fromhex(00,00,04,00), i32$rrot(byte$fromhex(16), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(16), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(16), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(16), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(16), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,01,00), i32$rshift$zx(byte$fromhex(16), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,01,00), i32$rshift$zx(byte$fromhex(16), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(16), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(16), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(16), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(16), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(17), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(17), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,80,00,00), i32$lshift(byte$fromhex(17), i32$one)), "i32$iseq(i32$fromhex(00,80,00,00), i32$lshift(byte$fromhex(17), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,80,00,00), i32$lrot(byte$fromhex(17), i32$one)), "i32$iseq(i32$fromhex(00,80,00,00), i32$lrot(byte$fromhex(17), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,02,00), i32$rrot(byte$fromhex(17), i32$one)), "i32$iseq(i32$fromhex(00,00,02,00), i32$rrot(byte$fromhex(17), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(17), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(17), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(17), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(17), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,80), i32$rshift$zx(byte$fromhex(17), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,80), i32$rshift$zx(byte$fromhex(17), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(17), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(17), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(17), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(17), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(18), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(18), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(01,00,00,00), i32$lshift(byte$fromhex(18), i32$one)), "i32$iseq(i32$fromhex(01,00,00,00), i32$lshift(byte$fromhex(18), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(01,00,00,00), i32$lrot(byte$fromhex(18), i32$one)), "i32$iseq(i32$fromhex(01,00,00,00), i32$lrot(byte$fromhex(18), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,01,00), i32$rrot(byte$fromhex(18), i32$one)), "i32$iseq(i32$fromhex(00,00,01,00), i32$rrot(byte$fromhex(18), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(18), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(18), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(18), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(18), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,40), i32$rshift$zx(byte$fromhex(18), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,40), i32$rshift$zx(byte$fromhex(18), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(18), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(18), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(18), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(18), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(19), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(19), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(02,00,00,00), i32$lshift(byte$fromhex(19), i32$one)), "i32$iseq(i32$fromhex(02,00,00,00), i32$lshift(byte$fromhex(19), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(02,00,00,00), i32$lrot(byte$fromhex(19), i32$one)), "i32$iseq(i32$fromhex(02,00,00,00), i32$lrot(byte$fromhex(19), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,80), i32$rrot(byte$fromhex(19), i32$one)), "i32$iseq(i32$fromhex(00,00,00,80), i32$rrot(byte$fromhex(19), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(19), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(19), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(19), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(19), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,20), i32$rshift$zx(byte$fromhex(19), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,20), i32$rshift$zx(byte$fromhex(19), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(19), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(19), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(19), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(19), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(1a), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(1a), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(04,00,00,00), i32$lshift(byte$fromhex(1a), i32$one)), "i32$iseq(i32$fromhex(04,00,00,00), i32$lshift(byte$fromhex(1a), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(04,00,00,00), i32$lrot(byte$fromhex(1a), i32$one)), "i32$iseq(i32$fromhex(04,00,00,00), i32$lrot(byte$fromhex(1a), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,40), i32$rrot(byte$fromhex(1a), i32$one)), "i32$iseq(i32$fromhex(00,00,00,40), i32$rrot(byte$fromhex(1a), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(1a), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(1a), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(1a), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(1a), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,10), i32$rshift$zx(byte$fromhex(1a), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,10), i32$rshift$zx(byte$fromhex(1a), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1a), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1a), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1a), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1a), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(1b), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(1b), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(08,00,00,00), i32$lshift(byte$fromhex(1b), i32$one)), "i32$iseq(i32$fromhex(08,00,00,00), i32$lshift(byte$fromhex(1b), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(08,00,00,00), i32$lrot(byte$fromhex(1b), i32$one)), "i32$iseq(i32$fromhex(08,00,00,00), i32$lrot(byte$fromhex(1b), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,20), i32$rrot(byte$fromhex(1b), i32$one)), "i32$iseq(i32$fromhex(00,00,00,20), i32$rrot(byte$fromhex(1b), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(1b), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(1b), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(1b), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(1b), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,08), i32$rshift$zx(byte$fromhex(1b), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,08), i32$rshift$zx(byte$fromhex(1b), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1b), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1b), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1b), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1b), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(1c), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(1c), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(10,00,00,00), i32$lshift(byte$fromhex(1c), i32$one)), "i32$iseq(i32$fromhex(10,00,00,00), i32$lshift(byte$fromhex(1c), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(10,00,00,00), i32$lrot(byte$fromhex(1c), i32$one)), "i32$iseq(i32$fromhex(10,00,00,00), i32$lrot(byte$fromhex(1c), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,10), i32$rrot(byte$fromhex(1c), i32$one)), "i32$iseq(i32$fromhex(00,00,00,10), i32$rrot(byte$fromhex(1c), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(1c), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(1c), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(1c), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(1c), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,04), i32$rshift$zx(byte$fromhex(1c), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,04), i32$rshift$zx(byte$fromhex(1c), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1c), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1c), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1c), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1c), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(1d), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(1d), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(20,00,00,00), i32$lshift(byte$fromhex(1d), i32$one)), "i32$iseq(i32$fromhex(20,00,00,00), i32$lshift(byte$fromhex(1d), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(20,00,00,00), i32$lrot(byte$fromhex(1d), i32$one)), "i32$iseq(i32$fromhex(20,00,00,00), i32$lrot(byte$fromhex(1d), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,08), i32$rrot(byte$fromhex(1d), i32$one)), "i32$iseq(i32$fromhex(00,00,00,08), i32$rrot(byte$fromhex(1d), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(1d), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(1d), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(1d), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(1d), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,02), i32$rshift$zx(byte$fromhex(1d), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,02), i32$rshift$zx(byte$fromhex(1d), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1d), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1d), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1d), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1d), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(1e), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(1e), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(40,00,00,00), i32$lshift(byte$fromhex(1e), i32$one)), "i32$iseq(i32$fromhex(40,00,00,00), i32$lshift(byte$fromhex(1e), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(40,00,00,00), i32$lrot(byte$fromhex(1e), i32$one)), "i32$iseq(i32$fromhex(40,00,00,00), i32$lrot(byte$fromhex(1e), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,04), i32$rrot(byte$fromhex(1e), i32$one)), "i32$iseq(i32$fromhex(00,00,00,04), i32$rrot(byte$fromhex(1e), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(1e), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(1e), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(1e), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(1e), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,01), i32$rshift$zx(byte$fromhex(1e), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,01), i32$rshift$zx(byte$fromhex(1e), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1e), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1e), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1e), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1e), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$lshift(byte$fromhex(1f), i32$zero)), "i32$iseq(i32$zero, i32$lshift(byte$fromhex(1f), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(80,00,00,00), i32$lshift(byte$fromhex(1f), i32$one)), "i32$iseq(i32$fromhex(80,00,00,00), i32$lshift(byte$fromhex(1f), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(80,00,00,00), i32$lrot(byte$fromhex(1f), i32$one)), "i32$iseq(i32$fromhex(80,00,00,00), i32$lrot(byte$fromhex(1f), i32$one))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,02), i32$rrot(byte$fromhex(1f), i32$one)), "i32$iseq(i32$fromhex(00,00,00,02), i32$rrot(byte$fromhex(1f), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$lrot(byte$fromhex(1f), i32$zero)), "i32$iseq(i32$zero, i32$lrot(byte$fromhex(1f), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rrot(byte$fromhex(1f), i32$zero)), "i32$iseq(i32$zero, i32$rrot(byte$fromhex(1f), i32$zero))");
	_Static_assert(i32$iseq(i32$fromhex(00,00,00,00), i32$rshift$zx(byte$fromhex(1f), i32$fromhex(40,00,00,00))), "i32$iseq(i32$fromhex(00,00,00,00), i32$rshift$zx(byte$fromhex(1f), i32$fromhex(40,00,00,00)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1f), i32$zero)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1f), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1f), i32$zero)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1f), i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(01), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(01), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(01), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(01), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(01), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(01), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(02), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(02), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(02), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(02), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(02), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(02), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(03), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(03), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(03), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(03), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(03), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(03), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(04), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(04), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(04), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(04), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(04), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(04), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(05), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(05), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(05), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(05), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(05), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(05), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(06), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(06), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(06), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(06), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(06), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(06), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(07), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(07), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(07), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(07), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(07), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(07), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(08), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(08), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(08), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(08), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(08), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(08), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(09), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(09), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(09), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(09), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(09), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(09), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0a), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0a), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0a), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0a), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0a), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0a), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0b), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0b), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0b), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0b), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0b), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0b), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0c), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0c), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0c), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0c), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0c), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0c), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0d), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0d), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0d), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0d), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0d), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0d), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0e), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0e), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0e), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0e), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0e), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0e), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0f), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(0f), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0f), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(0f), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0f), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(0f), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(10), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(10), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(10), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(10), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(10), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(10), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(11), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(11), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(11), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(11), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(11), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(11), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(12), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(12), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(12), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(12), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(12), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(12), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(13), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(13), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(13), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(13), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(13), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(13), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(14), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(14), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(14), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(14), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(14), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(14), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(15), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(15), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(15), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(15), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(15), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(15), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(16), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(16), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(16), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(16), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(16), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(16), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(17), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(17), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(17), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(17), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(17), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(17), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(18), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(18), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(18), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(18), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(18), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(18), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(19), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(19), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(19), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(19), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(19), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(19), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1a), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1a), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1a), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1a), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1a), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1a), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1b), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1b), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1b), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1b), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1b), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1b), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1c), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1c), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1c), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1c), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1c), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1c), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1d), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1d), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1d), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1d), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1d), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1d), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1e), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1e), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1e), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1e), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1e), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1e), i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1f), i32$one)), "i32$iseq(i32$zero, i32$rshift$zx(byte$fromhex(1f), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1f), i32$one)), "i32$iseq(i32$zero, i32$rshift$sx(byte$fromhex(1f), i32$one))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1f), i32$inv(i32$zero))), "i32$iseq(i32$inv(i32$zero), i32$rshift$sx(byte$fromhex(1f), i32$inv(i32$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(00), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(00), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$lshift(byte$fromhex(00), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$lshift(byte$fromhex(00), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$lrot(byte$fromhex(00), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$lrot(byte$fromhex(00), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$rrot(byte$fromhex(00), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$rrot(byte$fromhex(00), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(00), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(00), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(00), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(00), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(00), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(00), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(00), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(00), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(00), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(00), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(01), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(01), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$lshift(byte$fromhex(01), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$lshift(byte$fromhex(01), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$lrot(byte$fromhex(01), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$lrot(byte$fromhex(01), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(80,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(01), i64$one)), "i64$iseq(i64$fromhex(80,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(01), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(01), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(01), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(01), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(01), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(01), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(01), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(01), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(01), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(01), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(01), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(02), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(02), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$lshift(byte$fromhex(02), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$lshift(byte$fromhex(02), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$lrot(byte$fromhex(02), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$lrot(byte$fromhex(02), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(02), i64$one)), "i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(02), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(02), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(02), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(02), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(02), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(02), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(02), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(02), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(02), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(02), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(02), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(03), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(03), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$lshift(byte$fromhex(03), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$lshift(byte$fromhex(03), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$lrot(byte$fromhex(03), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$lrot(byte$fromhex(03), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(03), i64$one)), "i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(03), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(03), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(03), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(03), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(03), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(03), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(03), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(03), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(03), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(03), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(03), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(04), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(04), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$lshift(byte$fromhex(04), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$lshift(byte$fromhex(04), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$lrot(byte$fromhex(04), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$lrot(byte$fromhex(04), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(04), i64$one)), "i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(04), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(04), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(04), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(04), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(04), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(04), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(04), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(04), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(04), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(04), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(04), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(05), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(05), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$lshift(byte$fromhex(05), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$lshift(byte$fromhex(05), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$lrot(byte$fromhex(05), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$lrot(byte$fromhex(05), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(05), i64$one)), "i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(05), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(05), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(05), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(05), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(05), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(05), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(05), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(05), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(05), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(05), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(05), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(06), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(06), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$lshift(byte$fromhex(06), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$lshift(byte$fromhex(06), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$lrot(byte$fromhex(06), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$lrot(byte$fromhex(06), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(06), i64$one)), "i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(06), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(06), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(06), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(06), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(06), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(06), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(06), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(06), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(06), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(06), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(06), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(07), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(07), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$lshift(byte$fromhex(07), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$lshift(byte$fromhex(07), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$lrot(byte$fromhex(07), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$lrot(byte$fromhex(07), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(07), i64$one)), "i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(07), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(07), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(07), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(07), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(07), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(07), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(07), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(07), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(07), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(07), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(07), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(08), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(08), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$lshift(byte$fromhex(08), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$lshift(byte$fromhex(08), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$lrot(byte$fromhex(08), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$lrot(byte$fromhex(08), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(08), i64$one)), "i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$rrot(byte$fromhex(08), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(08), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(08), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(08), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(08), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(08), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(08), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(08), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(08), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(08), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(08), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(09), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(09), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$lshift(byte$fromhex(09), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$lshift(byte$fromhex(09), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$lrot(byte$fromhex(09), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$lrot(byte$fromhex(09), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$rrot(byte$fromhex(09), i64$one)), "i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$rrot(byte$fromhex(09), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(09), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(09), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(09), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(09), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(09), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(09), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(09), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(09), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(09), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(09), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(0a), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(0a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$lshift(byte$fromhex(0a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$lshift(byte$fromhex(0a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$lrot(byte$fromhex(0a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$lrot(byte$fromhex(0a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$rrot(byte$fromhex(0a), i64$one)), "i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$rrot(byte$fromhex(0a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(0a), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(0a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(0a), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(0a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0a), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0a), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(0b), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(0b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$lshift(byte$fromhex(0b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$lshift(byte$fromhex(0b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$lrot(byte$fromhex(0b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$lrot(byte$fromhex(0b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$rrot(byte$fromhex(0b), i64$one)), "i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$rrot(byte$fromhex(0b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(0b), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(0b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(0b), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(0b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0b), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0b), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(0c), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(0c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$lshift(byte$fromhex(0c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$lshift(byte$fromhex(0c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$lrot(byte$fromhex(0c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$lrot(byte$fromhex(0c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$rrot(byte$fromhex(0c), i64$one)), "i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$rrot(byte$fromhex(0c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(0c), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(0c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(0c), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(0c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0c), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0c), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(0d), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(0d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$lshift(byte$fromhex(0d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$lshift(byte$fromhex(0d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$lrot(byte$fromhex(0d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$lrot(byte$fromhex(0d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$rrot(byte$fromhex(0d), i64$one)), "i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$rrot(byte$fromhex(0d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(0d), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(0d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(0d), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(0d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0d), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0d), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(0e), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(0e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$lshift(byte$fromhex(0e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$lshift(byte$fromhex(0e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$lrot(byte$fromhex(0e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$lrot(byte$fromhex(0e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$rrot(byte$fromhex(0e), i64$one)), "i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$rrot(byte$fromhex(0e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(0e), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(0e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(0e), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(0e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0e), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0e), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(0f), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(0f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$lshift(byte$fromhex(0f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$lshift(byte$fromhex(0f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$lrot(byte$fromhex(0f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$lrot(byte$fromhex(0f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$rrot(byte$fromhex(0f), i64$one)), "i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$rrot(byte$fromhex(0f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(0f), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(0f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(0f), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(0f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0f), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$rshift$zx(byte$fromhex(0f), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(10), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(10), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$lshift(byte$fromhex(10), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$lshift(byte$fromhex(10), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$lrot(byte$fromhex(10), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$lrot(byte$fromhex(10), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$rrot(byte$fromhex(10), i64$one)), "i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$rrot(byte$fromhex(10), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(10), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(10), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(10), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(10), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$rshift$zx(byte$fromhex(10), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$rshift$zx(byte$fromhex(10), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(10), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(10), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(10), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(10), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(11), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(11), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$lshift(byte$fromhex(11), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$lshift(byte$fromhex(11), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$lrot(byte$fromhex(11), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$lrot(byte$fromhex(11), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$rrot(byte$fromhex(11), i64$one)), "i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$rrot(byte$fromhex(11), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(11), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(11), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(11), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(11), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$rshift$zx(byte$fromhex(11), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$rshift$zx(byte$fromhex(11), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(11), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(11), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(11), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(11), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(12), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(12), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$lshift(byte$fromhex(12), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$lshift(byte$fromhex(12), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$lrot(byte$fromhex(12), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$lrot(byte$fromhex(12), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$rrot(byte$fromhex(12), i64$one)), "i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$rrot(byte$fromhex(12), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(12), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(12), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(12), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(12), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$rshift$zx(byte$fromhex(12), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$rshift$zx(byte$fromhex(12), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(12), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(12), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(12), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(12), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(13), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(13), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$lshift(byte$fromhex(13), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$lshift(byte$fromhex(13), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$lrot(byte$fromhex(13), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$lrot(byte$fromhex(13), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$rrot(byte$fromhex(13), i64$one)), "i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$rrot(byte$fromhex(13), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(13), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(13), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(13), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(13), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$rshift$zx(byte$fromhex(13), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$rshift$zx(byte$fromhex(13), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(13), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(13), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(13), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(13), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(14), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(14), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$lshift(byte$fromhex(14), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$lshift(byte$fromhex(14), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$lrot(byte$fromhex(14), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$lrot(byte$fromhex(14), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$rrot(byte$fromhex(14), i64$one)), "i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$rrot(byte$fromhex(14), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(14), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(14), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(14), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(14), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$rshift$zx(byte$fromhex(14), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$rshift$zx(byte$fromhex(14), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(14), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(14), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(14), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(14), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(15), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(15), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$lshift(byte$fromhex(15), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$lshift(byte$fromhex(15), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$lrot(byte$fromhex(15), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$lrot(byte$fromhex(15), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$rrot(byte$fromhex(15), i64$one)), "i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$rrot(byte$fromhex(15), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(15), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(15), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(15), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(15), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$rshift$zx(byte$fromhex(15), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$rshift$zx(byte$fromhex(15), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(15), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(15), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(15), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(15), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(16), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(16), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$lshift(byte$fromhex(16), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$lshift(byte$fromhex(16), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$lrot(byte$fromhex(16), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$lrot(byte$fromhex(16), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$rrot(byte$fromhex(16), i64$one)), "i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$rrot(byte$fromhex(16), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(16), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(16), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(16), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(16), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$rshift$zx(byte$fromhex(16), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$rshift$zx(byte$fromhex(16), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(16), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(16), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(16), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(16), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(17), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(17), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$lshift(byte$fromhex(17), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$lshift(byte$fromhex(17), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$lrot(byte$fromhex(17), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$lrot(byte$fromhex(17), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$rrot(byte$fromhex(17), i64$one)), "i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$rrot(byte$fromhex(17), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(17), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(17), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(17), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(17), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$rshift$zx(byte$fromhex(17), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$rshift$zx(byte$fromhex(17), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(17), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(17), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(17), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(17), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(18), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(18), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$lshift(byte$fromhex(18), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$lshift(byte$fromhex(18), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$lrot(byte$fromhex(18), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$lrot(byte$fromhex(18), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$rrot(byte$fromhex(18), i64$one)), "i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$rrot(byte$fromhex(18), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(18), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(18), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(18), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(18), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$rshift$zx(byte$fromhex(18), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$rshift$zx(byte$fromhex(18), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(18), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(18), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(18), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(18), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(19), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(19), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$lshift(byte$fromhex(19), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$lshift(byte$fromhex(19), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$lrot(byte$fromhex(19), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$lrot(byte$fromhex(19), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$rrot(byte$fromhex(19), i64$one)), "i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$rrot(byte$fromhex(19), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(19), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(19), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(19), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(19), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$rshift$zx(byte$fromhex(19), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$rshift$zx(byte$fromhex(19), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(19), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(19), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(19), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(19), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(1a), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(1a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$lshift(byte$fromhex(1a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$lshift(byte$fromhex(1a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$lrot(byte$fromhex(1a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$lrot(byte$fromhex(1a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$rrot(byte$fromhex(1a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$rrot(byte$fromhex(1a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(1a), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(1a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(1a), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(1a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$rshift$zx(byte$fromhex(1a), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$rshift$zx(byte$fromhex(1a), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(1b), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(1b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$lshift(byte$fromhex(1b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$lshift(byte$fromhex(1b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$lrot(byte$fromhex(1b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$lrot(byte$fromhex(1b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$rrot(byte$fromhex(1b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$rrot(byte$fromhex(1b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(1b), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(1b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(1b), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(1b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$rshift$zx(byte$fromhex(1b), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$rshift$zx(byte$fromhex(1b), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(1c), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(1c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$lshift(byte$fromhex(1c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$lshift(byte$fromhex(1c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$lrot(byte$fromhex(1c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$lrot(byte$fromhex(1c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$rrot(byte$fromhex(1c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$rrot(byte$fromhex(1c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(1c), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(1c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(1c), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(1c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$rshift$zx(byte$fromhex(1c), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$rshift$zx(byte$fromhex(1c), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(1d), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(1d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$lshift(byte$fromhex(1d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$lshift(byte$fromhex(1d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$lrot(byte$fromhex(1d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$lrot(byte$fromhex(1d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$rrot(byte$fromhex(1d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$rrot(byte$fromhex(1d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(1d), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(1d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(1d), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(1d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$rshift$zx(byte$fromhex(1d), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$rshift$zx(byte$fromhex(1d), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(1e), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(1e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$lshift(byte$fromhex(1e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$lshift(byte$fromhex(1e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$lrot(byte$fromhex(1e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$lrot(byte$fromhex(1e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$rrot(byte$fromhex(1e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$rrot(byte$fromhex(1e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(1e), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(1e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(1e), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(1e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$rshift$zx(byte$fromhex(1e), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$rshift$zx(byte$fromhex(1e), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(1f), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(1f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$lshift(byte$fromhex(1f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$lshift(byte$fromhex(1f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$lrot(byte$fromhex(1f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$lrot(byte$fromhex(1f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$rrot(byte$fromhex(1f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$rrot(byte$fromhex(1f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(1f), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(1f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(1f), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(1f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$rshift$zx(byte$fromhex(1f), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$rshift$zx(byte$fromhex(1f), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(20), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(20), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$lshift(byte$fromhex(20), i64$one)), "i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$lshift(byte$fromhex(20), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$lrot(byte$fromhex(20), i64$one)), "i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$lrot(byte$fromhex(20), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$rrot(byte$fromhex(20), i64$one)), "i64$iseq(i64$fromhex(00,00,00,01,00,00,00,00), i64$rrot(byte$fromhex(20), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(20), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(20), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(20), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(20), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$rshift$zx(byte$fromhex(20), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$rshift$zx(byte$fromhex(20), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(20), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(20), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(20), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(20), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(21), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(21), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$lshift(byte$fromhex(21), i64$one)), "i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$lshift(byte$fromhex(21), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$lrot(byte$fromhex(21), i64$one)), "i64$iseq(i64$fromhex(00,00,00,02,00,00,00,00), i64$lrot(byte$fromhex(21), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$rrot(byte$fromhex(21), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,80,00,00,00), i64$rrot(byte$fromhex(21), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(21), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(21), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(21), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(21), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$rshift$zx(byte$fromhex(21), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$rshift$zx(byte$fromhex(21), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(21), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(21), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(21), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(21), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(22), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(22), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$lshift(byte$fromhex(22), i64$one)), "i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$lshift(byte$fromhex(22), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$lrot(byte$fromhex(22), i64$one)), "i64$iseq(i64$fromhex(00,00,00,04,00,00,00,00), i64$lrot(byte$fromhex(22), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$rrot(byte$fromhex(22), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,40,00,00,00), i64$rrot(byte$fromhex(22), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(22), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(22), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(22), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(22), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$rshift$zx(byte$fromhex(22), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$rshift$zx(byte$fromhex(22), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(22), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(22), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(22), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(22), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(23), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(23), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$lshift(byte$fromhex(23), i64$one)), "i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$lshift(byte$fromhex(23), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$lrot(byte$fromhex(23), i64$one)), "i64$iseq(i64$fromhex(00,00,00,08,00,00,00,00), i64$lrot(byte$fromhex(23), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$rrot(byte$fromhex(23), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,20,00,00,00), i64$rrot(byte$fromhex(23), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(23), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(23), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(23), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(23), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$rshift$zx(byte$fromhex(23), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$rshift$zx(byte$fromhex(23), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(23), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(23), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(23), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(23), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(24), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(24), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$lshift(byte$fromhex(24), i64$one)), "i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$lshift(byte$fromhex(24), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$lrot(byte$fromhex(24), i64$one)), "i64$iseq(i64$fromhex(00,00,00,10,00,00,00,00), i64$lrot(byte$fromhex(24), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$rrot(byte$fromhex(24), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,10,00,00,00), i64$rrot(byte$fromhex(24), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(24), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(24), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(24), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(24), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$rshift$zx(byte$fromhex(24), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$rshift$zx(byte$fromhex(24), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(24), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(24), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(24), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(24), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(25), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(25), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$lshift(byte$fromhex(25), i64$one)), "i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$lshift(byte$fromhex(25), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$lrot(byte$fromhex(25), i64$one)), "i64$iseq(i64$fromhex(00,00,00,20,00,00,00,00), i64$lrot(byte$fromhex(25), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$rrot(byte$fromhex(25), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,08,00,00,00), i64$rrot(byte$fromhex(25), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(25), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(25), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(25), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(25), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$rshift$zx(byte$fromhex(25), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$rshift$zx(byte$fromhex(25), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(25), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(25), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(25), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(25), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(26), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(26), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$lshift(byte$fromhex(26), i64$one)), "i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$lshift(byte$fromhex(26), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$lrot(byte$fromhex(26), i64$one)), "i64$iseq(i64$fromhex(00,00,00,40,00,00,00,00), i64$lrot(byte$fromhex(26), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$rrot(byte$fromhex(26), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,04,00,00,00), i64$rrot(byte$fromhex(26), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(26), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(26), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(26), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(26), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$rshift$zx(byte$fromhex(26), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$rshift$zx(byte$fromhex(26), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(26), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(26), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(26), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(26), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(27), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(27), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$lshift(byte$fromhex(27), i64$one)), "i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$lshift(byte$fromhex(27), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$lrot(byte$fromhex(27), i64$one)), "i64$iseq(i64$fromhex(00,00,00,80,00,00,00,00), i64$lrot(byte$fromhex(27), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$rrot(byte$fromhex(27), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,02,00,00,00), i64$rrot(byte$fromhex(27), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(27), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(27), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(27), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(27), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$rshift$zx(byte$fromhex(27), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$rshift$zx(byte$fromhex(27), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(27), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(27), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(27), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(27), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(28), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(28), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$lshift(byte$fromhex(28), i64$one)), "i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$lshift(byte$fromhex(28), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$lrot(byte$fromhex(28), i64$one)), "i64$iseq(i64$fromhex(00,00,01,00,00,00,00,00), i64$lrot(byte$fromhex(28), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$rrot(byte$fromhex(28), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,01,00,00,00), i64$rrot(byte$fromhex(28), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(28), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(28), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(28), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(28), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$rshift$zx(byte$fromhex(28), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$rshift$zx(byte$fromhex(28), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(28), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(28), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(28), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(28), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(29), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(29), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$lshift(byte$fromhex(29), i64$one)), "i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$lshift(byte$fromhex(29), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$lrot(byte$fromhex(29), i64$one)), "i64$iseq(i64$fromhex(00,00,02,00,00,00,00,00), i64$lrot(byte$fromhex(29), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$rrot(byte$fromhex(29), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,80,00,00), i64$rrot(byte$fromhex(29), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(29), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(29), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(29), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(29), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$rshift$zx(byte$fromhex(29), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$rshift$zx(byte$fromhex(29), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(29), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(29), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(29), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(29), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(2a), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(2a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$lshift(byte$fromhex(2a), i64$one)), "i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$lshift(byte$fromhex(2a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$lrot(byte$fromhex(2a), i64$one)), "i64$iseq(i64$fromhex(00,00,04,00,00,00,00,00), i64$lrot(byte$fromhex(2a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$rrot(byte$fromhex(2a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,40,00,00), i64$rrot(byte$fromhex(2a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(2a), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(2a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(2a), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(2a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$rshift$zx(byte$fromhex(2a), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$rshift$zx(byte$fromhex(2a), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(2b), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(2b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$lshift(byte$fromhex(2b), i64$one)), "i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$lshift(byte$fromhex(2b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$lrot(byte$fromhex(2b), i64$one)), "i64$iseq(i64$fromhex(00,00,08,00,00,00,00,00), i64$lrot(byte$fromhex(2b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$rrot(byte$fromhex(2b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,20,00,00), i64$rrot(byte$fromhex(2b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(2b), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(2b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(2b), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(2b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$rshift$zx(byte$fromhex(2b), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$rshift$zx(byte$fromhex(2b), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(2c), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(2c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$lshift(byte$fromhex(2c), i64$one)), "i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$lshift(byte$fromhex(2c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$lrot(byte$fromhex(2c), i64$one)), "i64$iseq(i64$fromhex(00,00,10,00,00,00,00,00), i64$lrot(byte$fromhex(2c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$rrot(byte$fromhex(2c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,10,00,00), i64$rrot(byte$fromhex(2c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(2c), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(2c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(2c), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(2c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$rshift$zx(byte$fromhex(2c), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$rshift$zx(byte$fromhex(2c), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(2d), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(2d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$lshift(byte$fromhex(2d), i64$one)), "i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$lshift(byte$fromhex(2d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$lrot(byte$fromhex(2d), i64$one)), "i64$iseq(i64$fromhex(00,00,20,00,00,00,00,00), i64$lrot(byte$fromhex(2d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$rrot(byte$fromhex(2d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,08,00,00), i64$rrot(byte$fromhex(2d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(2d), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(2d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(2d), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(2d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$rshift$zx(byte$fromhex(2d), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$rshift$zx(byte$fromhex(2d), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(2e), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(2e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$lshift(byte$fromhex(2e), i64$one)), "i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$lshift(byte$fromhex(2e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$lrot(byte$fromhex(2e), i64$one)), "i64$iseq(i64$fromhex(00,00,40,00,00,00,00,00), i64$lrot(byte$fromhex(2e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$rrot(byte$fromhex(2e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,04,00,00), i64$rrot(byte$fromhex(2e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(2e), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(2e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(2e), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(2e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$rshift$zx(byte$fromhex(2e), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$rshift$zx(byte$fromhex(2e), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(2f), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(2f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$lshift(byte$fromhex(2f), i64$one)), "i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$lshift(byte$fromhex(2f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$lrot(byte$fromhex(2f), i64$one)), "i64$iseq(i64$fromhex(00,00,80,00,00,00,00,00), i64$lrot(byte$fromhex(2f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$rrot(byte$fromhex(2f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,02,00,00), i64$rrot(byte$fromhex(2f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(2f), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(2f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(2f), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(2f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$rshift$zx(byte$fromhex(2f), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$rshift$zx(byte$fromhex(2f), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(30), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(30), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$lshift(byte$fromhex(30), i64$one)), "i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$lshift(byte$fromhex(30), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$lrot(byte$fromhex(30), i64$one)), "i64$iseq(i64$fromhex(00,01,00,00,00,00,00,00), i64$lrot(byte$fromhex(30), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$rrot(byte$fromhex(30), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,01,00,00), i64$rrot(byte$fromhex(30), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(30), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(30), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(30), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(30), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$rshift$zx(byte$fromhex(30), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$rshift$zx(byte$fromhex(30), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(30), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(30), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(30), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(30), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(31), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(31), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$lshift(byte$fromhex(31), i64$one)), "i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$lshift(byte$fromhex(31), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$lrot(byte$fromhex(31), i64$one)), "i64$iseq(i64$fromhex(00,02,00,00,00,00,00,00), i64$lrot(byte$fromhex(31), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$rrot(byte$fromhex(31), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,80,00), i64$rrot(byte$fromhex(31), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(31), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(31), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(31), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(31), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$rshift$zx(byte$fromhex(31), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$rshift$zx(byte$fromhex(31), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(31), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(31), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(31), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(31), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(32), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(32), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$lshift(byte$fromhex(32), i64$one)), "i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$lshift(byte$fromhex(32), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$lrot(byte$fromhex(32), i64$one)), "i64$iseq(i64$fromhex(00,04,00,00,00,00,00,00), i64$lrot(byte$fromhex(32), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$rrot(byte$fromhex(32), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,40,00), i64$rrot(byte$fromhex(32), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(32), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(32), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(32), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(32), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$rshift$zx(byte$fromhex(32), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$rshift$zx(byte$fromhex(32), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(32), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(32), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(32), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(32), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(33), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(33), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$lshift(byte$fromhex(33), i64$one)), "i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$lshift(byte$fromhex(33), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$lrot(byte$fromhex(33), i64$one)), "i64$iseq(i64$fromhex(00,08,00,00,00,00,00,00), i64$lrot(byte$fromhex(33), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$rrot(byte$fromhex(33), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,20,00), i64$rrot(byte$fromhex(33), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(33), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(33), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(33), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(33), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$rshift$zx(byte$fromhex(33), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$rshift$zx(byte$fromhex(33), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(33), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(33), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(33), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(33), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(34), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(34), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$lshift(byte$fromhex(34), i64$one)), "i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$lshift(byte$fromhex(34), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$lrot(byte$fromhex(34), i64$one)), "i64$iseq(i64$fromhex(00,10,00,00,00,00,00,00), i64$lrot(byte$fromhex(34), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$rrot(byte$fromhex(34), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,10,00), i64$rrot(byte$fromhex(34), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(34), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(34), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(34), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(34), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$rshift$zx(byte$fromhex(34), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$rshift$zx(byte$fromhex(34), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(34), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(34), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(34), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(34), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(35), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(35), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$lshift(byte$fromhex(35), i64$one)), "i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$lshift(byte$fromhex(35), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$lrot(byte$fromhex(35), i64$one)), "i64$iseq(i64$fromhex(00,20,00,00,00,00,00,00), i64$lrot(byte$fromhex(35), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$rrot(byte$fromhex(35), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,08,00), i64$rrot(byte$fromhex(35), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(35), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(35), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(35), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(35), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$rshift$zx(byte$fromhex(35), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$rshift$zx(byte$fromhex(35), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(35), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(35), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(35), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(35), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(36), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(36), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$lshift(byte$fromhex(36), i64$one)), "i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$lshift(byte$fromhex(36), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$lrot(byte$fromhex(36), i64$one)), "i64$iseq(i64$fromhex(00,40,00,00,00,00,00,00), i64$lrot(byte$fromhex(36), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$rrot(byte$fromhex(36), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,04,00), i64$rrot(byte$fromhex(36), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(36), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(36), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(36), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(36), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$rshift$zx(byte$fromhex(36), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$rshift$zx(byte$fromhex(36), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(36), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(36), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(36), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(36), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(37), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(37), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$lshift(byte$fromhex(37), i64$one)), "i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$lshift(byte$fromhex(37), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$lrot(byte$fromhex(37), i64$one)), "i64$iseq(i64$fromhex(00,80,00,00,00,00,00,00), i64$lrot(byte$fromhex(37), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$rrot(byte$fromhex(37), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,02,00), i64$rrot(byte$fromhex(37), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(37), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(37), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(37), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(37), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$rshift$zx(byte$fromhex(37), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$rshift$zx(byte$fromhex(37), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(37), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(37), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(37), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(37), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(38), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(38), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(38), i64$one)), "i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(38), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(38), i64$one)), "i64$iseq(i64$fromhex(01,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(38), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$rrot(byte$fromhex(38), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,01,00), i64$rrot(byte$fromhex(38), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(38), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(38), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(38), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(38), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$rshift$zx(byte$fromhex(38), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$rshift$zx(byte$fromhex(38), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(38), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(38), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(38), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(38), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(39), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(39), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(39), i64$one)), "i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(39), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(39), i64$one)), "i64$iseq(i64$fromhex(02,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(39), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$rrot(byte$fromhex(39), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,80), i64$rrot(byte$fromhex(39), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(39), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(39), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(39), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(39), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$rshift$zx(byte$fromhex(39), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$rshift$zx(byte$fromhex(39), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(39), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(39), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(39), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(39), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(3a), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(3a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3a), i64$one)), "i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3a), i64$one)), "i64$iseq(i64$fromhex(04,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3a), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$rrot(byte$fromhex(3a), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,40), i64$rrot(byte$fromhex(3a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(3a), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(3a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(3a), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(3a), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$rshift$zx(byte$fromhex(3a), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$rshift$zx(byte$fromhex(3a), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3a), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3a), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(3b), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(3b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3b), i64$one)), "i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3b), i64$one)), "i64$iseq(i64$fromhex(08,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3b), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$rrot(byte$fromhex(3b), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,20), i64$rrot(byte$fromhex(3b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(3b), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(3b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(3b), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(3b), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$rshift$zx(byte$fromhex(3b), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$rshift$zx(byte$fromhex(3b), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3b), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3b), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(3c), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(3c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3c), i64$one)), "i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3c), i64$one)), "i64$iseq(i64$fromhex(10,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3c), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$rrot(byte$fromhex(3c), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,10), i64$rrot(byte$fromhex(3c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(3c), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(3c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(3c), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(3c), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$rshift$zx(byte$fromhex(3c), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$rshift$zx(byte$fromhex(3c), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3c), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3c), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(3d), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(3d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3d), i64$one)), "i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3d), i64$one)), "i64$iseq(i64$fromhex(20,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3d), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$rrot(byte$fromhex(3d), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,08), i64$rrot(byte$fromhex(3d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(3d), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(3d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(3d), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(3d), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$rshift$zx(byte$fromhex(3d), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$rshift$zx(byte$fromhex(3d), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3d), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3d), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(3e), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(3e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3e), i64$one)), "i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3e), i64$one)), "i64$iseq(i64$fromhex(40,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3e), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$rrot(byte$fromhex(3e), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,04), i64$rrot(byte$fromhex(3e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(3e), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(3e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(3e), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(3e), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$rshift$zx(byte$fromhex(3e), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,01), i64$rshift$zx(byte$fromhex(3e), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3e), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3e), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$lshift(byte$fromhex(3f), i64$zero)), "i64$iseq(i64$zero, i64$lshift(byte$fromhex(3f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(80,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3f), i64$one)), "i64$iseq(i64$fromhex(80,00,00,00,00,00,00,00), i64$lshift(byte$fromhex(3f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(80,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3f), i64$one)), "i64$iseq(i64$fromhex(80,00,00,00,00,00,00,00), i64$lrot(byte$fromhex(3f), i64$one))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$rrot(byte$fromhex(3f), i64$one)), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,02), i64$rrot(byte$fromhex(3f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$lrot(byte$fromhex(3f), i64$zero)), "i64$iseq(i64$zero, i64$lrot(byte$fromhex(3f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rrot(byte$fromhex(3f), i64$zero)), "i64$iseq(i64$zero, i64$rrot(byte$fromhex(3f), i64$zero))");
	_Static_assert(i64$iseq(i64$fromhex(00,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(3f), i64$fromhex(40,00,00,00,00,00,00,00))), "i64$iseq(i64$fromhex(00,00,00,00,00,00,00,00), i64$rshift$zx(byte$fromhex(3f), i64$fromhex(40,00,00,00,00,00,00,00)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3f), i64$zero)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3f), i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(01), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(01), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(01), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(01), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(01), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(01), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(02), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(02), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(02), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(02), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(02), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(02), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(03), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(03), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(03), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(03), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(03), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(03), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(04), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(04), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(04), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(04), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(04), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(04), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(05), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(05), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(05), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(05), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(05), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(05), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(06), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(06), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(06), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(06), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(06), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(06), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(07), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(07), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(07), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(07), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(07), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(07), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(08), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(08), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(08), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(08), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(08), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(08), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(09), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(09), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(09), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(09), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(09), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(09), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0a), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0a), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0a), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0a), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0a), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0b), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0b), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0b), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0b), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0b), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0c), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0c), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0c), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0c), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0c), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0d), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0d), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0d), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0d), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0d), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0e), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0e), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0e), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0e), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0e), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0f), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(0f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0f), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(0f), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0f), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(0f), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(10), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(10), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(10), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(10), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(10), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(10), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(11), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(11), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(11), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(11), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(11), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(11), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(12), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(12), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(12), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(12), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(12), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(12), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(13), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(13), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(13), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(13), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(13), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(13), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(14), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(14), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(14), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(14), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(14), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(14), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(15), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(15), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(15), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(15), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(15), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(15), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(16), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(16), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(16), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(16), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(16), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(16), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(17), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(17), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(17), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(17), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(17), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(17), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(18), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(18), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(18), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(18), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(18), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(18), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(19), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(19), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(19), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(19), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(19), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(19), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1a), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1a), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1a), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1a), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1a), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1b), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1b), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1b), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1b), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1b), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1c), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1c), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1c), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1c), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1c), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1d), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1d), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1d), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1d), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1d), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1e), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1e), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1e), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1e), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1e), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1f), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(1f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1f), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(1f), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1f), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(1f), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(20), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(20), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(20), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(20), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(20), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(20), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(21), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(21), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(21), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(21), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(21), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(21), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(22), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(22), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(22), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(22), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(22), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(22), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(23), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(23), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(23), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(23), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(23), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(23), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(24), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(24), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(24), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(24), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(24), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(24), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(25), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(25), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(25), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(25), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(25), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(25), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(26), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(26), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(26), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(26), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(26), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(26), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(27), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(27), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(27), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(27), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(27), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(27), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(28), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(28), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(28), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(28), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(28), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(28), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(29), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(29), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(29), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(29), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(29), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(29), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2a), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2a), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2a), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2a), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2a), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2b), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2b), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2b), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2b), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2b), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2c), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2c), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2c), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2c), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2c), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2d), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2d), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2d), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2d), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2d), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2e), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2e), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2e), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2e), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2e), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2f), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(2f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2f), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(2f), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2f), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(2f), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(30), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(30), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(30), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(30), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(30), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(30), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(31), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(31), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(31), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(31), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(31), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(31), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(32), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(32), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(32), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(32), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(32), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(32), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(33), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(33), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(33), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(33), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(33), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(33), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(34), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(34), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(34), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(34), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(34), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(34), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(35), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(35), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(35), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(35), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(35), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(35), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(36), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(36), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(36), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(36), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(36), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(36), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(37), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(37), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(37), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(37), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(37), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(37), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(38), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(38), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(38), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(38), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(38), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(38), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(39), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(39), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(39), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(39), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(39), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(39), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3a), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3a), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3a), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3a), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3a), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3a), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3b), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3b), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3b), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3b), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3b), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3b), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3c), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3c), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3c), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3c), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3c), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3c), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3d), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3d), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3d), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3d), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3d), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3d), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3e), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3e), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3e), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3e), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3e), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3e), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3f), i64$one)), "i64$iseq(i64$zero, i64$rshift$zx(byte$fromhex(3f), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3f), i64$one)), "i64$iseq(i64$zero, i64$rshift$sx(byte$fromhex(3f), i64$one))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3f), i64$inv(i64$zero))), "i64$iseq(i64$inv(i64$zero), i64$rshift$sx(byte$fromhex(3f), i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(00),i64$rrot(byte$fromhex(00),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(00),i64$rrot(byte$fromhex(00),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(00),i64$lrot(byte$fromhex(00),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(00),i64$lrot(byte$fromhex(00),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(01),i64$rrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(01),i64$rrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(01),i64$lrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(01),i64$lrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(02),i64$rrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(02),i64$rrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(02),i64$lrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(02),i64$lrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(03),i64$rrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(03),i64$rrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(03),i64$lrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(03),i64$lrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(04),i64$rrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(04),i64$rrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(04),i64$lrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(04),i64$lrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(05),i64$rrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(05),i64$rrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(05),i64$lrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(05),i64$lrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(06),i64$rrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(06),i64$rrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(06),i64$lrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(06),i64$lrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(07),i64$rrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(07),i64$rrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(07),i64$lrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(07),i64$lrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(08),i64$rrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(08),i64$rrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(08),i64$lrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(08),i64$lrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(09),i64$rrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(09),i64$rrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(09),i64$lrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(09),i64$lrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0a),i64$rrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0a),i64$rrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0a),i64$lrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0a),i64$lrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0b),i64$rrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0b),i64$rrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0b),i64$lrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0b),i64$lrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0c),i64$rrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0c),i64$rrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0c),i64$lrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0c),i64$lrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0d),i64$rrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0d),i64$rrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0d),i64$lrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0d),i64$lrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0e),i64$rrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0e),i64$rrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0e),i64$lrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0e),i64$lrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0f),i64$rrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0f),i64$rrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0f),i64$lrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0f),i64$lrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(10),i64$rrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(10),i64$rrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(10),i64$lrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(10),i64$lrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(11),i64$rrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(11),i64$rrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(11),i64$lrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(11),i64$lrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(12),i64$rrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(12),i64$rrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(12),i64$lrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(12),i64$lrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(13),i64$rrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(13),i64$rrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(13),i64$lrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(13),i64$lrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(14),i64$rrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(14),i64$rrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(14),i64$lrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(14),i64$lrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(15),i64$rrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(15),i64$rrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(15),i64$lrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(15),i64$lrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(16),i64$rrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(16),i64$rrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(16),i64$lrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(16),i64$lrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(17),i64$rrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(17),i64$rrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(17),i64$lrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(17),i64$lrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(18),i64$rrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(18),i64$rrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(18),i64$lrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(18),i64$lrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(19),i64$rrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(19),i64$rrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(19),i64$lrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(19),i64$lrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1a),i64$rrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1a),i64$rrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1a),i64$lrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1a),i64$lrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1b),i64$rrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1b),i64$rrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1b),i64$lrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1b),i64$lrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1c),i64$rrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1c),i64$rrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1c),i64$lrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1c),i64$lrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1d),i64$rrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1d),i64$rrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1d),i64$lrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1d),i64$lrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1e),i64$rrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1e),i64$rrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1e),i64$lrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1e),i64$lrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1f),i64$rrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1f),i64$rrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1f),i64$lrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1f),i64$lrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(20),i64$rrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(20),i64$rrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(20),i64$lrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(20),i64$lrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(21),i64$rrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(21),i64$rrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(21),i64$lrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(21),i64$lrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(22),i64$rrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(22),i64$rrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(22),i64$lrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(22),i64$lrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(23),i64$rrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(23),i64$rrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(23),i64$lrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(23),i64$lrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(24),i64$rrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(24),i64$rrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(24),i64$lrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(24),i64$lrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(25),i64$rrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(25),i64$rrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(25),i64$lrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(25),i64$lrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(26),i64$rrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(26),i64$rrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(26),i64$lrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(26),i64$lrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(27),i64$rrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(27),i64$rrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(27),i64$lrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(27),i64$lrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(28),i64$rrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(28),i64$rrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(28),i64$lrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(28),i64$lrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(29),i64$rrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(29),i64$rrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(29),i64$lrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(29),i64$lrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2a),i64$rrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2a),i64$rrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2a),i64$lrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2a),i64$lrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2b),i64$rrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2b),i64$rrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2b),i64$lrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2b),i64$lrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2c),i64$rrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2c),i64$rrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2c),i64$lrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2c),i64$lrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2d),i64$rrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2d),i64$rrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2d),i64$lrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2d),i64$lrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2e),i64$rrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2e),i64$rrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2e),i64$lrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2e),i64$lrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2f),i64$rrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2f),i64$rrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2f),i64$lrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2f),i64$lrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(30),i64$rrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(30),i64$rrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(30),i64$lrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(30),i64$lrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(31),i64$rrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(31),i64$rrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(31),i64$lrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(31),i64$lrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(32),i64$rrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(32),i64$rrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(32),i64$lrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(32),i64$lrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(33),i64$rrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(33),i64$rrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(33),i64$lrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(33),i64$lrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(34),i64$rrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(34),i64$rrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(34),i64$lrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(34),i64$lrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(35),i64$rrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(35),i64$rrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(35),i64$lrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(35),i64$lrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(36),i64$rrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(36),i64$rrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(36),i64$lrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(36),i64$lrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(37),i64$rrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(37),i64$rrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(37),i64$lrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(37),i64$lrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(38),i64$rrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(38),i64$rrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(38),i64$lrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(38),i64$lrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(39),i64$rrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(39),i64$rrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(39),i64$lrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(39),i64$lrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3a),i64$rrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3a),i64$rrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3a),i64$lrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3a),i64$lrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3b),i64$rrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3b),i64$rrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3b),i64$lrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3b),i64$lrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3c),i64$rrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3c),i64$rrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3c),i64$lrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3c),i64$lrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3d),i64$rrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3d),i64$rrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3d),i64$lrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3d),i64$lrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3e),i64$rrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3e),i64$rrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3e),i64$lrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3e),i64$lrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3f),i64$rrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3f),i64$rrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3f),i64$lrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3f),i64$lrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(01),i64$lrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(01),i64$lrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(01),i64$rrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(01),i64$rrot(byte$fromhex(3f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(02),i64$lrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(02),i64$lrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(02),i64$rrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(02),i64$rrot(byte$fromhex(3e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(03),i64$lrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(03),i64$lrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(03),i64$rrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(03),i64$rrot(byte$fromhex(3d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(04),i64$lrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(04),i64$lrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(04),i64$rrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(04),i64$rrot(byte$fromhex(3c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(05),i64$lrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(05),i64$lrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(05),i64$rrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(05),i64$rrot(byte$fromhex(3b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(06),i64$lrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(06),i64$lrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(06),i64$rrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(06),i64$rrot(byte$fromhex(3a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(07),i64$lrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(07),i64$lrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(07),i64$rrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(07),i64$rrot(byte$fromhex(39),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(08),i64$lrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(08),i64$lrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(08),i64$rrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(08),i64$rrot(byte$fromhex(38),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(09),i64$lrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(09),i64$lrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(09),i64$rrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(09),i64$rrot(byte$fromhex(37),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0a),i64$lrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0a),i64$lrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0a),i64$rrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0a),i64$rrot(byte$fromhex(36),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0b),i64$lrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0b),i64$lrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0b),i64$rrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0b),i64$rrot(byte$fromhex(35),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0c),i64$lrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0c),i64$lrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0c),i64$rrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0c),i64$rrot(byte$fromhex(34),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0d),i64$lrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0d),i64$lrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0d),i64$rrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0d),i64$rrot(byte$fromhex(33),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0e),i64$lrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0e),i64$lrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0e),i64$rrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0e),i64$rrot(byte$fromhex(32),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0f),i64$lrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(0f),i64$lrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0f),i64$rrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(0f),i64$rrot(byte$fromhex(31),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(10),i64$lrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(10),i64$lrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(10),i64$rrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(10),i64$rrot(byte$fromhex(30),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(11),i64$lrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(11),i64$lrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(11),i64$rrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(11),i64$rrot(byte$fromhex(2f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(12),i64$lrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(12),i64$lrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(12),i64$rrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(12),i64$rrot(byte$fromhex(2e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(13),i64$lrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(13),i64$lrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(13),i64$rrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(13),i64$rrot(byte$fromhex(2d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(14),i64$lrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(14),i64$lrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(14),i64$rrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(14),i64$rrot(byte$fromhex(2c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(15),i64$lrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(15),i64$lrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(15),i64$rrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(15),i64$rrot(byte$fromhex(2b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(16),i64$lrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(16),i64$lrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(16),i64$rrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(16),i64$rrot(byte$fromhex(2a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(17),i64$lrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(17),i64$lrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(17),i64$rrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(17),i64$rrot(byte$fromhex(29),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(18),i64$lrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(18),i64$lrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(18),i64$rrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(18),i64$rrot(byte$fromhex(28),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(19),i64$lrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(19),i64$lrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(19),i64$rrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(19),i64$rrot(byte$fromhex(27),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1a),i64$lrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1a),i64$lrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1a),i64$rrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1a),i64$rrot(byte$fromhex(26),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1b),i64$lrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1b),i64$lrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1b),i64$rrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1b),i64$rrot(byte$fromhex(25),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1c),i64$lrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1c),i64$lrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1c),i64$rrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1c),i64$rrot(byte$fromhex(24),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1d),i64$lrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1d),i64$lrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1d),i64$rrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1d),i64$rrot(byte$fromhex(23),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1e),i64$lrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1e),i64$lrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1e),i64$rrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1e),i64$rrot(byte$fromhex(22),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1f),i64$lrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(1f),i64$lrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1f),i64$rrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(1f),i64$rrot(byte$fromhex(21),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(20),i64$lrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(20),i64$lrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(20),i64$rrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(20),i64$rrot(byte$fromhex(20),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(21),i64$lrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(21),i64$lrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(21),i64$rrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(21),i64$rrot(byte$fromhex(1f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(22),i64$lrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(22),i64$lrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(22),i64$rrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(22),i64$rrot(byte$fromhex(1e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(23),i64$lrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(23),i64$lrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(23),i64$rrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(23),i64$rrot(byte$fromhex(1d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(24),i64$lrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(24),i64$lrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(24),i64$rrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(24),i64$rrot(byte$fromhex(1c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(25),i64$lrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(25),i64$lrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(25),i64$rrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(25),i64$rrot(byte$fromhex(1b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(26),i64$lrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(26),i64$lrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(26),i64$rrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(26),i64$rrot(byte$fromhex(1a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(27),i64$lrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(27),i64$lrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(27),i64$rrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(27),i64$rrot(byte$fromhex(19),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(28),i64$lrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(28),i64$lrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(28),i64$rrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(28),i64$rrot(byte$fromhex(18),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(29),i64$lrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(29),i64$lrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(29),i64$rrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(29),i64$rrot(byte$fromhex(17),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2a),i64$lrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2a),i64$lrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2a),i64$rrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2a),i64$rrot(byte$fromhex(16),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2b),i64$lrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2b),i64$lrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2b),i64$rrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2b),i64$rrot(byte$fromhex(15),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2c),i64$lrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2c),i64$lrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2c),i64$rrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2c),i64$rrot(byte$fromhex(14),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2d),i64$lrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2d),i64$lrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2d),i64$rrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2d),i64$rrot(byte$fromhex(13),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2e),i64$lrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2e),i64$lrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2e),i64$rrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2e),i64$rrot(byte$fromhex(12),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2f),i64$lrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(2f),i64$lrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2f),i64$rrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(2f),i64$rrot(byte$fromhex(11),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(30),i64$lrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(30),i64$lrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(30),i64$rrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(30),i64$rrot(byte$fromhex(10),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(31),i64$lrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(31),i64$lrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(31),i64$rrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(31),i64$rrot(byte$fromhex(0f),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(32),i64$lrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(32),i64$lrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(32),i64$rrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(32),i64$rrot(byte$fromhex(0e),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(33),i64$lrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(33),i64$lrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(33),i64$rrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(33),i64$rrot(byte$fromhex(0d),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(34),i64$lrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(34),i64$lrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(34),i64$rrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(34),i64$rrot(byte$fromhex(0c),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(35),i64$lrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(35),i64$lrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(35),i64$rrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(35),i64$rrot(byte$fromhex(0b),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(36),i64$lrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(36),i64$lrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(36),i64$rrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(36),i64$rrot(byte$fromhex(0a),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(37),i64$lrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(37),i64$lrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(37),i64$rrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(37),i64$rrot(byte$fromhex(09),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(38),i64$lrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(38),i64$lrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(38),i64$rrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(38),i64$rrot(byte$fromhex(08),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(39),i64$lrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(39),i64$lrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(39),i64$rrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(39),i64$rrot(byte$fromhex(07),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3a),i64$lrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3a),i64$lrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3a),i64$rrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3a),i64$rrot(byte$fromhex(06),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3b),i64$lrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3b),i64$lrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3b),i64$rrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3b),i64$rrot(byte$fromhex(05),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3c),i64$lrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3c),i64$lrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3c),i64$rrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3c),i64$rrot(byte$fromhex(04),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3d),i64$lrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3d),i64$lrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3d),i64$rrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3d),i64$rrot(byte$fromhex(03),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3e),i64$lrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3e),i64$lrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3e),i64$rrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3e),i64$rrot(byte$fromhex(02),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3f),i64$lrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$lrot(byte$fromhex(3f),i64$lrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3f),i64$rrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef)))), "i64$iseq(i64$fromhex(01,23,45,67,89,ab,cd,ef),i64$rrot(byte$fromhex(3f),i64$rrot(byte$fromhex(01),i64$fromhex(01,23,45,67,89,ab,cd,ef))))");
	_Static_assert(i08$iseq(i08$zero, i08$add(i08$zero, i08$zero)), "i08$iseq(i08$zero, i08$add(i08$zero, i08$zero))");
	_Static_assert(i08$iseq(i08$one, i08$add(i08$zero, i08$one)), "i08$iseq(i08$one, i08$add(i08$zero, i08$one))");
	_Static_assert(i08$iseq(i08$one, i08$add(i08$one, i08$zero)), "i08$iseq(i08$one, i08$add(i08$one, i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$add(i08$inv(i08$zero), i08$one)), "i08$iseq(i08$zero, i08$add(i08$inv(i08$zero), i08$one))");
	_Static_assert(i08$iseq(i08$zero, i08$add(i08$one, i08$inv(i08$zero))), "i08$iseq(i08$zero, i08$add(i08$one, i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$add(i08$smax, i08$smin)), "i08$iseq(i08$inv(i08$zero), i08$add(i08$smax, i08$smin))");
	_Static_assert(i08$iseq(i08$zero, i08$sub(i08$zero, i08$zero)), "i08$iseq(i08$zero, i08$sub(i08$zero, i08$zero))");
	_Static_assert(i08$iseq(i08$one, i08$sub(i08$one, i08$zero)), "i08$iseq(i08$one, i08$sub(i08$one, i08$zero))");
	_Static_assert(i08$iseq(i08$zero, i08$sub(i08$one, i08$one)), "i08$iseq(i08$zero, i08$sub(i08$one, i08$one))");
	_Static_assert(i08$iseq(i08$one, i08$sub(i08$zero, i08$inv(i08$zero))), "i08$iseq(i08$one, i08$sub(i08$zero, i08$inv(i08$zero)))");
	_Static_assert(i08$iseq(i08$inv(i08$zero), i08$sub(i08$zero, i08$one)), "i08$iseq(i08$inv(i08$zero), i08$sub(i08$zero, i08$one))");
	_Static_assert(i08$iseq(i08$neg(i08$zero), i08$zero), "i08$iseq(i08$neg(i08$zero), i08$zero)");
	_Static_assert(i08$iseq(i08$neg(i08$one), i08$inv(i08$zero)), "i08$iseq(i08$neg(i08$one), i08$inv(i08$zero))");
	_Static_assert(i08$iseq(i08$neg(i08$smax), i08$inc(i08$smin)), "i08$iseq(i08$neg(i08$smax), i08$inc(i08$smin))");
	_Static_assert(i16$iseq(i16$zero, i16$add(i16$zero, i16$zero)), "i16$iseq(i16$zero, i16$add(i16$zero, i16$zero))");
	_Static_assert(i16$iseq(i16$one, i16$add(i16$zero, i16$one)), "i16$iseq(i16$one, i16$add(i16$zero, i16$one))");
	_Static_assert(i16$iseq(i16$one, i16$add(i16$one, i16$zero)), "i16$iseq(i16$one, i16$add(i16$one, i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$add(i16$inv(i16$zero), i16$one)), "i16$iseq(i16$zero, i16$add(i16$inv(i16$zero), i16$one))");
	_Static_assert(i16$iseq(i16$zero, i16$add(i16$one, i16$inv(i16$zero))), "i16$iseq(i16$zero, i16$add(i16$one, i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$add(i16$smax, i16$smin)), "i16$iseq(i16$inv(i16$zero), i16$add(i16$smax, i16$smin))");
	_Static_assert(i16$iseq(i16$zero, i16$sub(i16$zero, i16$zero)), "i16$iseq(i16$zero, i16$sub(i16$zero, i16$zero))");
	_Static_assert(i16$iseq(i16$one, i16$sub(i16$one, i16$zero)), "i16$iseq(i16$one, i16$sub(i16$one, i16$zero))");
	_Static_assert(i16$iseq(i16$zero, i16$sub(i16$one, i16$one)), "i16$iseq(i16$zero, i16$sub(i16$one, i16$one))");
	_Static_assert(i16$iseq(i16$one, i16$sub(i16$zero, i16$inv(i16$zero))), "i16$iseq(i16$one, i16$sub(i16$zero, i16$inv(i16$zero)))");
	_Static_assert(i16$iseq(i16$inv(i16$zero), i16$sub(i16$zero, i16$one)), "i16$iseq(i16$inv(i16$zero), i16$sub(i16$zero, i16$one))");
	_Static_assert(i16$iseq(i16$neg(i16$zero), i16$zero), "i16$iseq(i16$neg(i16$zero), i16$zero)");
	_Static_assert(i16$iseq(i16$neg(i16$one), i16$inv(i16$zero)), "i16$iseq(i16$neg(i16$one), i16$inv(i16$zero))");
	_Static_assert(i16$iseq(i16$neg(i16$smax), i16$inc(i16$smin)), "i16$iseq(i16$neg(i16$smax), i16$inc(i16$smin))");
	_Static_assert(i32$iseq(i32$zero, i32$add(i32$zero, i32$zero)), "i32$iseq(i32$zero, i32$add(i32$zero, i32$zero))");
	_Static_assert(i32$iseq(i32$one, i32$add(i32$zero, i32$one)), "i32$iseq(i32$one, i32$add(i32$zero, i32$one))");
	_Static_assert(i32$iseq(i32$one, i32$add(i32$one, i32$zero)), "i32$iseq(i32$one, i32$add(i32$one, i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$add(i32$inv(i32$zero), i32$one)), "i32$iseq(i32$zero, i32$add(i32$inv(i32$zero), i32$one))");
	_Static_assert(i32$iseq(i32$zero, i32$add(i32$one, i32$inv(i32$zero))), "i32$iseq(i32$zero, i32$add(i32$one, i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$add(i32$smax, i32$smin)), "i32$iseq(i32$inv(i32$zero), i32$add(i32$smax, i32$smin))");
	_Static_assert(i32$iseq(i32$zero, i32$sub(i32$zero, i32$zero)), "i32$iseq(i32$zero, i32$sub(i32$zero, i32$zero))");
	_Static_assert(i32$iseq(i32$one, i32$sub(i32$one, i32$zero)), "i32$iseq(i32$one, i32$sub(i32$one, i32$zero))");
	_Static_assert(i32$iseq(i32$zero, i32$sub(i32$one, i32$one)), "i32$iseq(i32$zero, i32$sub(i32$one, i32$one))");
	_Static_assert(i32$iseq(i32$one, i32$sub(i32$zero, i32$inv(i32$zero))), "i32$iseq(i32$one, i32$sub(i32$zero, i32$inv(i32$zero)))");
	_Static_assert(i32$iseq(i32$inv(i32$zero), i32$sub(i32$zero, i32$one)), "i32$iseq(i32$inv(i32$zero), i32$sub(i32$zero, i32$one))");
	_Static_assert(i32$iseq(i32$neg(i32$zero), i32$zero), "i32$iseq(i32$neg(i32$zero), i32$zero)");
	_Static_assert(i32$iseq(i32$neg(i32$one), i32$inv(i32$zero)), "i32$iseq(i32$neg(i32$one), i32$inv(i32$zero))");
	_Static_assert(i32$iseq(i32$neg(i32$smax), i32$inc(i32$smin)), "i32$iseq(i32$neg(i32$smax), i32$inc(i32$smin))");
	_Static_assert(i64$iseq(i64$zero, i64$add(i64$zero, i64$zero)), "i64$iseq(i64$zero, i64$add(i64$zero, i64$zero))");
	_Static_assert(i64$iseq(i64$one, i64$add(i64$zero, i64$one)), "i64$iseq(i64$one, i64$add(i64$zero, i64$one))");
	_Static_assert(i64$iseq(i64$one, i64$add(i64$one, i64$zero)), "i64$iseq(i64$one, i64$add(i64$one, i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$add(i64$inv(i64$zero), i64$one)), "i64$iseq(i64$zero, i64$add(i64$inv(i64$zero), i64$one))");
	_Static_assert(i64$iseq(i64$zero, i64$add(i64$one, i64$inv(i64$zero))), "i64$iseq(i64$zero, i64$add(i64$one, i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$add(i64$smax, i64$smin)), "i64$iseq(i64$inv(i64$zero), i64$add(i64$smax, i64$smin))");
	_Static_assert(i64$iseq(i64$zero, i64$sub(i64$zero, i64$zero)), "i64$iseq(i64$zero, i64$sub(i64$zero, i64$zero))");
	_Static_assert(i64$iseq(i64$one, i64$sub(i64$one, i64$zero)), "i64$iseq(i64$one, i64$sub(i64$one, i64$zero))");
	_Static_assert(i64$iseq(i64$zero, i64$sub(i64$one, i64$one)), "i64$iseq(i64$zero, i64$sub(i64$one, i64$one))");
	_Static_assert(i64$iseq(i64$one, i64$sub(i64$zero, i64$inv(i64$zero))), "i64$iseq(i64$one, i64$sub(i64$zero, i64$inv(i64$zero)))");
	_Static_assert(i64$iseq(i64$inv(i64$zero), i64$sub(i64$zero, i64$one)), "i64$iseq(i64$inv(i64$zero), i64$sub(i64$zero, i64$one))");
	_Static_assert(i64$iseq(i64$neg(i64$zero), i64$zero), "i64$iseq(i64$neg(i64$zero), i64$zero)");
	_Static_assert(i64$iseq(i64$neg(i64$one), i64$inv(i64$zero)), "i64$iseq(i64$neg(i64$one), i64$inv(i64$zero))");
	_Static_assert(i64$iseq(i64$neg(i64$smax), i64$inc(i64$smin)), "i64$iseq(i64$neg(i64$smax), i64$inc(i64$smin))");
#endif /* IMFEELINGLUCKY */

#endif  /* __PPALU__ */
