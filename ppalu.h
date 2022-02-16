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

#endif  /* __PPALU__ */
