
/* ===== entry @ 00008000 ===== */

undefined4 processEntry entry(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 in_r1;
  int in_r2;
  int in_r3;
  int in_r4;
  int in_r5;
  int iVar3;
  undefined4 *in_r6;
  undefined2 in_r7;
  char in_OV;
  
  *in_r6 = param_1;
  *(undefined2 *)(in_r2 + 6) = in_r1;
  uVar1 = (undefined2)in_r3;
  *(undefined2 *)(in_r3 + 6) = uVar1;
  *(short *)(in_r3 + 6) = (short)in_r5;
  *(undefined2 *)(in_r3 + 6) = in_r7;
  *(undefined2 *)(in_r4 + 6) = in_r1;
  *(undefined2 *)(in_r4 + 6) = uVar1;
  *(short *)(in_r4 + 6) = (short)in_r5;
  *(undefined2 *)(in_r4 + 6) = in_r7;
  *(undefined2 *)(in_r5 + 6) = in_r1;
  iVar3 = in_r3 >> 9;
  if (in_OV != '\0') {
    return 0;
  }
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  *(undefined2 *)(iVar3 + 6) = uVar1;
  FUN_00008c78(0,0);
  uVar2 = (*DAT_000080c8)();
  return uVar2;
}


/* ===== thunk_FUN_0000eb08 @ 000080c4 ===== */

void thunk_FUN_0000eb08(void)

{
  (*DAT_000080c8)();
  return;
}


/* ===== FUN_000080f4 @ 000080f4 ===== */

void FUN_000080f4(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined *)param_1 = *(undefined *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}


/* ===== FUN_00008118 @ 00008118 ===== */

void FUN_00008118(undefined *param_1,int param_2,undefined param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}


/* ===== FUN_00008126 @ 00008126 ===== */

void FUN_00008126(undefined4 param_1,undefined4 param_2)

{
  FUN_00008118(param_1,param_2,0);
  return;
}


/* ===== FUN_0000812a @ 0000812a ===== */

undefined4 FUN_0000812a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00008118(param_1,param_3,param_2);
  return param_1;
}


/* ===== FUN_0000813c @ 0000813c ===== */

uint FUN_0000813c(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar4 = param_1 ^ param_2;
  uVar1 = param_1;
  if (param_1 << 1 < param_2 << 1) {
    uVar1 = param_2;
    param_2 = param_1;
  }
  if ((param_2 & 0x7fffffff) == 0) {
    return uVar1;
  }
  uVar6 = uVar1 >> 0x17;
  uVar7 = (uVar6 & 0xff) - ((param_2 << 1) >> 0x18);
  if ((int)uVar7 < 0x20) {
    uVar5 = param_2 & 0x7fffff | 0x800000;
    if ((int)uVar4 < 0) {
      uVar5 = -uVar5;
    }
    uVar3 = uVar5 << (0x20 - uVar7 & 0xff);
    uVar1 = uVar1 + ((int)uVar5 >> (uVar7 & 0xff));
    if (uVar6 != uVar1 >> 0x17) {
      if ((int)uVar4 < 0) {
        iVar2 = uVar1 + uVar6 * -0x800000;
        if ((int)uVar7 < 2) {
          iVar2 = iVar2 + 0x800000;
          iVar8 = LZCOUNT(iVar2);
          uVar1 = iVar2 << iVar8;
          if ((uVar1 | uVar3) == 0) {
            return uVar1;
          }
          if (uVar3 != 0) {
            uVar4 = uVar3 << iVar8;
            if (uVar4 != 0) {
              uVar4 = 1;
            }
            uVar1 = uVar1 | uVar4 | uVar3 >> (0x20U - iVar8 & 0xff);
          }
          iVar2 = ((uVar6 & 0xff) - iVar8) + 7;
          if (-1 < iVar2) {
            uVar4 = (uVar1 >> 8) + iVar2 * 0x800000 + (uVar6 & 0x100) * 0x800000;
            if ((int)(uVar1 * 0x1000000) < 0) {
              uVar4 = uVar4 + 1;
              if ((uVar1 & 0x7f) == 0) {
                uVar4 = uVar4 & 0xfffffffe;
              }
              return uVar4;
            }
            return uVar4;
          }
          return 0;
        }
        uVar1 = iVar2 * 2 + uVar6 * 0x800000 | uVar3 >> 0x1f;
        uVar3 = uVar3 << 1;
      }
      else {
        uVar3 = uVar3 >> 1 | uVar1 * -0x80000000;
        uVar1 = (uVar1 + uVar6 * -0x800000 + 0x800000 >> 1) + uVar6 * 0x800000;
      }
    }
  }
  else {
    uVar3 = ((int)uVar4 >> 0x1f) * 2 + 1;
    uVar1 = uVar1 + ((int)uVar4 >> 0x1f);
  }
  uVar1 = FUN_00008898(uVar1,uVar3);
  return uVar1;
}


/* ===== FUN_000081e0 @ 000081e0 ===== */

void FUN_000081e0(undefined4 param_1,uint param_2)

{
  FUN_0000813c(param_1,param_2 ^ 0x80000000);
  return;
}


/* ===== FUN_000081e6 @ 000081e6 ===== */

void FUN_000081e6(uint param_1)

{
  FUN_0000813c(param_1 ^ 0x80000000);
  return;
}


/* ===== FUN_000081ec @ 000081ec ===== */

uint FUN_000081ec(uint param_1,uint param_2)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = param_1 << 1;
  if (uVar2 != 0) {
    if (param_2 << 1 != 0) {
      iVar4 = (uVar2 >> 0x18) + ((param_2 << 1) >> 0x18);
      uVar1 = (ulonglong)(param_1 & 0x7fffff | 0x800000) *
              (ulonglong)(param_2 & 0x7fffff | 0x800000);
      uVar2 = (int)(uVar1 >> 0x20) * 0x10000;
      iVar5 = iVar4 + -0x7f;
      if ((uVar1 & 0xffff) != 0) {
        uVar2 = uVar2 + 1;
      }
      uVar2 = uVar2 | (uint)uVar1 >> 0x10;
      if (-1 < (int)uVar2) {
        uVar2 = uVar2 << 1;
        iVar5 = iVar4 + -0x80;
      }
      uVar3 = iVar5 * 0x1000000 + (uVar2 >> 7) + 1 >> 1;
      if ((uVar2 & 0xff) == 0x80) {
        uVar3 = uVar3 & 0xfffffffe;
      }
      if (iVar5 < 0) {
        uVar3 = 0;
      }
      return uVar3 | (param_1 ^ param_2) & 0x80000000;
    }
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== FUN_00008250 @ 00008250 ===== */

undefined4 FUN_00008250(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (((param_1 & 0x7fffffff) != 0) && ((param_2 & 0x7fffffff) != 0)) {
    iVar6 = ((param_1 & 0x7fffffff) >> 0x17) - ((param_2 & 0x7fffffff) >> 0x17);
    uVar3 = param_1 & 0x7fffff | 0x800000;
    uVar4 = param_2 & 0x7fffff | 0x800000;
    iVar7 = iVar6 + 0x7d;
    if (uVar3 < uVar4) {
      uVar3 = uVar3 << 1;
    }
    else {
      iVar7 = iVar6 + 0x7e;
    }
    if (-1 < iVar7) {
      uVar1 = 0x800000;
      uVar5 = 0;
      do {
        if (uVar4 <= uVar3) {
          uVar3 = uVar3 - uVar4;
          uVar5 = uVar5 | uVar1;
        }
        uVar1 = uVar1 >> 1;
        uVar3 = uVar3 * 2;
      } while (uVar1 != 0);
      if (uVar3 != 0) {
        if (uVar3 == uVar4) {
          uVar3 = 0x80000000;
        }
        else if (uVar3 < uVar4) {
          uVar3 = 1;
        }
        else {
          uVar3 = 0xfffffffe;
        }
      }
      uVar2 = FUN_00008898(uVar5 + iVar7 * 0x800000 + ((param_1 ^ param_2) & 0x80000000),uVar3);
      return uVar2;
    }
  }
  return 0;
}


/* ===== FUN_000082cc @ 000082cc ===== */

uint FUN_000082cc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  ulonglong uVar11;
  longlong lVar12;
  
  iVar1 = (int)(param_2 ^ param_4) >> 0x1f;
  uVar2 = -iVar1;
  uVar6 = param_3;
  uVar9 = param_4;
  if ((param_2 & 0x7fffffff) <= (param_4 & 0x7fffffff) &&
      (uint)(param_3 <= param_1) <= (param_2 & 0x7fffffff) - (param_4 & 0x7fffffff)) {
    uVar6 = param_1;
    uVar9 = param_2;
    param_2 = param_4;
    param_1 = param_3;
  }
  if ((uVar9 & 0x7fffffff | uVar6) != 0) {
    uVar8 = param_2 >> 0x14;
    uVar3 = uVar8 & 0x7ff;
    iVar4 = uVar3 - ((uVar9 << 1) >> 0x15);
    if (iVar4 < 0x40) {
      uVar9 = uVar9 & 0xfffff | 0x100000;
      if (uVar2 != 0) {
        bVar10 = uVar6 != 0;
        uVar6 = -uVar6;
        uVar9 = -(uint)bVar10 - uVar9;
      }
      uVar11 = FUN_00008836(uVar6,uVar9,0x40 - iVar4);
      uVar7 = (uint)(uVar11 >> 0x20);
      uVar5 = (uint)uVar11;
      lVar12 = FUN_00008874(uVar6,uVar9,iVar4);
      lVar12 = lVar12 + CONCAT44(param_2,param_1);
      uVar6 = (uint)lVar12;
      uVar9 = (uint)((ulonglong)lVar12 >> 0x20);
      if ((param_2 ^ uVar9) >> 0x14 != 0) {
        if (uVar2 == 0) {
          uVar11 = CONCAT44(uVar7 >> 1 | uVar6 * -0x80000000,
                            (uint)((uVar11 & 0x100000000) != 0) << 0x1f | uVar5 >> 1);
          uVar9 = uVar9 + uVar8 * -0x100000 + 0x100000;
          lVar12 = CONCAT44((uVar9 >> 1) + uVar8 * 0x100000,
                            (uint)((uVar9 & 1) != 0) << 0x1f | uVar6 >> 1);
        }
        else {
          if (iVar4 < 2) {
            uVar6 = FUN_000089ca(uVar6,uVar9 + uVar8 * -0x100000 + 0x100000,uVar5,uVar7,0,
                                 (uVar8 & 0x800) << 0x14,uVar3);
            return uVar6;
          }
          lVar12 = CONCAT44(uVar8 * -0x100000 + uVar9 * 2 + (uint)CARRY4(uVar6,uVar6),
                            uVar6 * 2 | uVar7 >> 0x1f);
          uVar11 = CONCAT44(uVar7 * 2 + (uint)CARRY4(uVar5,uVar5),uVar5 * 2);
        }
      }
    }
    else {
      uVar11 = CONCAT44(-(uint)(1 < (uint)(iVar1 * -2)),iVar1 * 2 + 1);
      lVar12 = CONCAT44(param_2 - (param_1 < uVar2),param_1 + iVar1);
    }
    uVar6 = FUN_000089ac((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),(int)uVar11,
                         (int)(uVar11 >> 0x20));
    return uVar6;
  }
  return param_1;
}


/* ===== FUN_0000840e @ 0000840e ===== */

void FUN_0000840e(void)

{
  FUN_000082cc();
  return;
}


/* ===== FUN_00008414 @ 00008414 ===== */

void FUN_00008414(undefined4 param_1,uint param_2)

{
  FUN_000082cc(param_1,param_2 ^ 0x80000000);
  return;
}


/* ===== FUN_0000841a @ 0000841a ===== */

void FUN_0000841a(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (((param_1 | param_2 & 0x7fffffff) != 0) && ((param_3 | param_4 & 0x7fffffff) != 0)) {
    uVar6 = (uint)((ulonglong)param_1 * (ulonglong)param_3);
    uVar2 = param_2 & 0xfffff | 0x100000;
    uVar3 = param_4 & 0xfffff | 0x100000;
    uVar4 = param_1 >> 10 | (param_2 & 0xfffff) << 0x16;
    uVar8 = param_3 >> 10 | (param_4 & 0xfffff) << 0x16;
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar8;
    uVar7 = (uint)lVar1;
    iVar5 = uVar4 * (uVar3 >> 10) + (uVar2 >> 10) * uVar8 + (int)((ulonglong)lVar1 >> 0x20);
    uVar8 = ((param_1 * uVar3 +
             uVar2 * param_3 + (int)((ulonglong)param_1 * (ulonglong)param_3 >> 0x20)) -
            (iVar5 * 0x100000 | uVar7 >> 0xc)) - (uint)(uVar6 < uVar7 * 0x100000);
    uVar4 = param_1 >> 0x1a | uVar2 << 6;
    uVar2 = param_3 >> 0x1a | uVar3 << 6;
    uVar3 = uVar6 + uVar7 * -0x100000 >> 0x14 | uVar8 * 0x1000;
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar2 +
            (ulonglong)((iVar5 - uVar4 * uVar2) + (uVar8 >> 0x14) + (uint)CARRY4(uVar3,uVar7));
    FUN_000089ca((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar6 * 0x1000,uVar3 + uVar7,0,
                 (param_2 ^ param_4) & 0x80000000,
                 (((param_4 & 0x7fffffff) << 1) >> 0x15) + (((param_2 & 0x7fffffff) << 1) >> 0x15) +
                 -0x3ff);
  }
  return;
}


/* ===== FUN_000084fe @ 000084fe ===== */

void FUN_000084fe(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  
  if (((param_1 | param_2 & 0x7fffffff) != 0) && ((param_3 | param_4 & 0x7fffffff) != 0)) {
    uVar5 = param_4 & 0xfffff | 0x100000;
    uVar4 = param_2 & 0xfffff | 0x100000;
    iVar7 = (((param_2 & 0x7fffffff) << 1) >> 0x15) - (((param_4 & 0x7fffffff) << 1) >> 0x15);
    iVar8 = iVar7 + 0x3fd;
    if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)(param_3 <= param_1)) {
      iVar8 = iVar7 + 0x3fe;
    }
    else {
      bVar10 = CARRY4(param_1,param_1);
      param_1 = param_1 * 2;
      uVar4 = uVar4 * 2 + (uint)bVar10;
    }
    if (-1 < iVar8) {
      uVar3 = 0x100000;
      uVar6 = 0;
      uVar9 = 0;
      for (uVar2 = 0; (uVar2 | uVar3) != 0; uVar2 = (uint)(uVar1 != 0) << 0x1f | uVar2 >> 1) {
        if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)(param_3 <= param_1)) {
          bVar10 = param_1 < param_3;
          param_1 = param_1 - param_3;
          uVar4 = (uVar4 - uVar5) - (uint)bVar10;
          uVar6 = uVar6 | uVar2;
          uVar9 = uVar9 | uVar3;
        }
        uVar1 = uVar3 & 1;
        uVar3 = uVar3 >> 1;
        bVar10 = CARRY4(param_1,param_1);
        param_1 = param_1 * 2;
        uVar4 = uVar4 * 2 + (uint)bVar10;
      }
      if ((param_1 | uVar4) != 0) {
        if ((param_1 ^ param_3 | uVar4 ^ uVar5) == 0) {
          param_1 = 0;
          uVar4 = 0x80000000;
        }
        else if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)(param_3 <= param_1)) {
          param_1 = 0xfffffffe;
          uVar4 = 0xffffffff;
        }
        else {
          param_1 = 1;
          uVar4 = 0;
        }
      }
      FUN_000089ac(uVar6,uVar9 + iVar8 * 0x100000 + ((param_2 ^ param_4) & 0x80000000),param_1,uVar4
                  );
      return;
    }
  }
  return;
}


/* ===== FUN_000085dc @ 000085dc ===== */

/* WARNING: Removing unreachable block (ram,0x000088c0) */
/* WARNING: Removing unreachable block (ram,0x000088ce) */
/* WARNING: Removing unreachable block (ram,0x000088d0) */

uint FUN_000085dc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (int)param_1 >> 0x1f;
  iVar1 = (param_1 ^ uVar3) - uVar3;
  iVar4 = LZCOUNT(iVar1);
  uVar2 = iVar1 << iVar4;
  if (uVar2 == 0) {
    return 0;
  }
  iVar4 = 0x9d - iVar4;
  if (-1 < iVar4) {
    uVar3 = (uVar2 >> 8) + iVar4 * 0x800000 + uVar3 * -0x80000000;
    if ((int)(uVar2 * 0x1000000) < 0) {
      uVar3 = uVar3 + 1;
      if ((uVar2 & 0x7f) == 0) {
        uVar3 = uVar3 & 0xfffffffe;
      }
      return uVar3;
    }
    return uVar3;
  }
  return 0;
}


/* ===== FUN_000085ee @ 000085ee ===== */

/* WARNING: Removing unreachable block (ram,0x000088c0) */
/* WARNING: Removing unreachable block (ram,0x000088ce) */
/* WARNING: Removing unreachable block (ram,0x000088d0) */

uint FUN_000085ee(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 << LZCOUNT(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  iVar3 = 0x9d - LZCOUNT(param_1);
  if (-1 < iVar3) {
    uVar2 = (uVar1 >> 8) + iVar3 * 0x800000;
    if ((int)(uVar1 * 0x1000000) < 0) {
      uVar2 = uVar2 + 1;
      if ((uVar1 & 0x7f) == 0) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return uVar2;
    }
    return uVar2;
  }
  return 0;
}


/* ===== FUN_000085f8 @ 000085f8 ===== */

void FUN_000085f8(uint param_1)

{
  uint uVar1;
  
  uVar1 = (int)param_1 >> 0x1f;
  FUN_000089ca((param_1 ^ uVar1) - uVar1,0,0,0,0,uVar1 * -0x80000000,0x433);
  return;
}


/* ===== FUN_0000861a @ 0000861a ===== */

void FUN_0000861a(undefined4 param_1)

{
  FUN_000089ca(param_1,0,0,0,0,0,0x433);
  return;
}


/* ===== FUN_00008634 @ 00008634 ===== */

uint FUN_00008634(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar1 = param_1 & 0x7fffff | 0x800000;
  if (uVar2 < 0x7f) {
    uVar1 = 0;
  }
  else {
    if (uVar2 < 0x97) {
      uVar1 = uVar1 >> (0x96 - uVar2 & 0xff);
    }
    else {
      uVar1 = uVar1 << (uVar2 - 0x96 & 0xff);
    }
    if ((param_1 & 0x80000000) != 0) {
      return -uVar1;
    }
  }
  return uVar1;
}


/* ===== FUN_00008666 @ 00008666 ===== */

uint FUN_00008666(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  uVar1 = param_1 & 0x7fffff | 0x800000;
  if (uVar2 < 0x7f) {
    return 0;
  }
  if (uVar2 < 0x97) {
    return uVar1 >> (0x96 - uVar2 & 0xff);
  }
  return uVar1 << (uVar2 - 0x96 & 0xff);
}


/* ===== FUN_0000868e @ 0000868e ===== */

int FUN_0000868e(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 << 1) >> 0x15;
  if (uVar2 < 0x3ff) {
    return 0;
  }
  if (uVar2 < 0x434) {
    iVar1 = FUN_00008854(param_1,param_2 & 0xfffff | 0x100000,-(uVar2 - 0x433));
    return iVar1;
  }
  return param_1 << (uVar2 - 0x433 & 0xff);
}


/* ===== FUN_000086c0 @ 000086c0 ===== */

undefined8 FUN_000086c0(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0x7fffffff;
  if (uVar1 != 0) {
    return CONCAT44(param_1 & 0x80000000 | ((uVar1 >> 0x17) + 0x380) * 0x100000 |
                    (uVar1 << 9) >> 0xc,param_1 << 0x1d);
  }
  return 0;
}


/* ===== FUN_000086e8 @ 000086e8 ===== */

int FUN_000086e8(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ===== FUN_00008718 @ 00008718 ===== */

int FUN_00008718(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ===== FUN_00008748 @ 00008748 ===== */

undefined4 FUN_00008748(uint param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 | param_2 & 0x7fffffff) != 0) {
    iVar2 = ((param_2 & 0x7fffffff) >> 0x14) - 0x380;
    if (0 < iVar2) {
      uVar1 = FUN_00008898((param_1 >> 0x1d | (param_2 & 0xfffff) << 3) + (param_2 & 0x80000000) +
                           iVar2 * 0x800000,param_1 << 3);
      return uVar1;
    }
  }
  return 0;
}


/* ===== FUN_00008780 @ 00008780 ===== */

undefined8 FUN_00008780(int param_1,int param_2)

{
  if (-1 < param_1) {
    param_1 = -0x80000000 - param_1;
  }
  if (-1 < param_2) {
    param_2 = -0x80000000 - param_2;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00008794 @ 00008794 ===== */

undefined8 FUN_00008794(int param_1,int param_2)

{
  if (-1 < param_1) {
    param_1 = -0x80000000 - param_1;
  }
  if (-1 < param_2) {
    param_2 = -0x80000000 - param_2;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_000087a8 @ 000087a8 ===== */

int FUN_000087a8(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0x20;
  while (uVar3 = uVar2 - 1, 0 < (int)uVar2) {
    uVar2 = uVar3;
    if (param_2 <= param_1 >> (uVar3 & 0xff)) {
      param_1 = param_1 - (param_2 << (uVar3 & 0xff));
      iVar1 = iVar1 + (1 << (uVar3 & 0xff));
    }
  }
  return iVar1;
}


/* ===== FUN_000087d4 @ 000087d4 ===== */

longlong FUN_000087d4(uint param_1,int param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  lVar1 = 0;
  iVar3 = 0x40;
  while (iVar4 = iVar3 + -1, 0 < iVar3) {
    uVar6 = FUN_00008854(param_1,param_2,iVar4);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = iVar4;
    if (param_4 < uVar2 || uVar2 - param_4 < (uint)(param_3 <= (uint)uVar6)) {
      uVar6 = FUN_00008836(param_3,param_4,iVar4);
      bVar5 = param_1 < (uint)uVar6;
      param_1 = param_1 - (uint)uVar6;
      param_2 = (param_2 - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;
      lVar7 = FUN_00008836(1,0,iVar4);
      lVar1 = lVar7 + lVar1;
    }
  }
  return lVar1;
}


/* ===== FUN_00008836 @ 00008836 ===== */

longlong FUN_00008836(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}


/* ===== FUN_00008854 @ 00008854 ===== */

ulonglong FUN_00008854(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}


/* ===== FUN_00008874 @ 00008874 ===== */

undefined8 FUN_00008874(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((int)param_3 < 0x20) {
    iVar2 = (int)param_2 >> (param_3 & 0xff);
    uVar1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
  }
  else {
    uVar1 = (int)param_2 >> (param_3 - 0x20 & 0xff);
    iVar2 = (int)(param_2 | uVar1) >> 0x1f;
  }
  return CONCAT44(iVar2,uVar1);
}


/* ===== FUN_00008898 @ 00008898 ===== */

uint FUN_00008898(uint param_1,uint param_2)

{
  if (-1 < (int)param_2) {
    return param_1;
  }
  param_1 = param_1 + 1;
  if ((param_2 & 0x7fffffff) == 0) {
    param_1 = param_1 & 0xfffffffe;
  }
  return param_1;
}


/* ===== FUN_00008906 @ 00008906 ===== */

uint FUN_00008906(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 & 0x7fffffff) != 0) {
    uVar2 = (param_1 << 1) >> 0x18;
    iVar1 = -uVar2;
    if (param_2 != iVar1 && (int)(param_2 + uVar2) < 0 == SBORROW4(param_2,iVar1)) {
      return param_1 + param_2 * 0x800000;
    }
    param_1 = 0;
  }
  return param_1;
}


/* ===== FUN_0000891e @ 0000891e ===== */

uint FUN_0000891e(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  if (((param_1 & 0x7fffffff) != 0) && (uVar2 = (param_1 << 1) >> 0x18, uVar2 < 0x97)) {
    if (0x7e < uVar2) {
      uVar2 = 0x96 - uVar2;
      iVar1 = FUN_00008898(param_1 >> (uVar2 & 0xff),param_1 << (0x20 - uVar2 & 0xff));
      return iVar1 << (uVar2 & 0xff);
    }
    if ((uVar2 < 0x7e) || ((param_1 & 0x7fffff) == 0)) {
      return 0;
    }
    param_1 = param_1 & 0x80000000 | 0x3f800000;
  }
  return param_1;
}


/* ===== FUN_0000895a @ 0000895a ===== */

/* WARNING: Removing unreachable block (ram,0x000088c0) */
/* WARNING: Removing unreachable block (ram,0x000088ce) */
/* WARNING: Removing unreachable block (ram,0x000088d0) */

uint FUN_0000895a(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = param_2 & 0x7fffff | 0x800000;
  uVar2 = param_1 & 0x7fffff | 0x800000;
  uVar1 = param_1 & 0x80000000;
  for (uVar5 = (param_1 & 0x7fffffff) >> 0x17;
      (int)(((param_2 & 0x7fffffff) >> 0x17) - 1) <= (int)uVar5; uVar5 = uVar5 - 1) {
    while (uVar3 < uVar2) {
      uVar2 = uVar2 + uVar3 * -2;
      if ((int)uVar2 < 0) {
        uVar1 = uVar1 ^ 0x80000000;
        uVar2 = -uVar2;
      }
    }
    uVar2 = uVar2 << 1;
  }
  if (uVar2 == 0) {
    return param_1 & 0x80000000;
  }
  uVar3 = uVar2 << LZCOUNT(uVar2);
  if (uVar3 == 0) {
    return 0;
  }
  iVar4 = (uVar5 - LZCOUNT(uVar2)) + 7;
  if (-1 < iVar4) {
    uVar1 = (uVar3 >> 8) + iVar4 * 0x800000 + uVar1;
    if ((int)(uVar3 * 0x1000000) < 0) {
      uVar1 = uVar1 + 1;
      if ((uVar3 & 0x7f) == 0) {
        uVar1 = uVar1 & 0xfffffffe;
      }
      return uVar1;
    }
    return uVar1;
  }
  return 0;
}


/* ===== FUN_000089ac @ 000089ac ===== */

undefined8 FUN_000089ac(uint param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  
  if (param_4 < 0) {
    bVar1 = 0xfffffffe < param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + (uint)bVar1;
    if ((param_3 * 2 | param_4 * 2 + (uint)CARRY4(param_3,param_3)) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_000089ca @ 000089ca ===== */

ulonglong FUN_000089ca(undefined4 param_1,int param_2,uint param_3,uint param_4,uint param_5,
                      int param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  longlong lVar5;
  
  if (param_2 == 0) {
    iVar1 = LZCOUNT(param_1) + 0x20;
  }
  else {
    iVar1 = LZCOUNT(param_2);
  }
  uVar3 = FUN_00008836();
  uVar2 = (uint)(uVar3 >> 0x20);
  if (((uint)uVar3 | param_3 | uVar2 | param_4) != 0) {
    if ((param_3 | param_4) != 0) {
      uVar4 = FUN_00008854(param_3,param_4,0x40 - iVar1);
      lVar5 = FUN_00008836(param_3,param_4,iVar1);
      uVar3 = CONCAT44(uVar2 | (uint)((ulonglong)uVar4 >> 0x20),
                       (uint)uVar3 | (uint)uVar4 | (uint)(lVar5 != 0));
    }
    uVar2 = (uint)(uVar3 >> 0xb);
    iVar1 = (param_7 - iVar1) + 10;
    if (-1 < iVar1) {
      uVar3 = FUN_000089ac(uVar2 + param_5,
                           iVar1 * 0x100000 + (int)((uVar3 >> 0xb) >> 0x20) + param_6 +
                           (uint)CARRY4(uVar2,param_5),0,(int)uVar3 << 0x15);
      return uVar3;
    }
    uVar3 = 0;
  }
  return uVar3;
}


/* ===== FUN_00008a66 @ 00008a66 ===== */

undefined8 FUN_00008a66(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  if ((param_2 & 0x7fffffff | param_1) != 0) {
    uVar2 = (param_2 << 1) >> 0x15;
    iVar1 = -(uint)(uVar2 != 0);
    iVar3 = (int)param_3 >> 0x1f;
    bVar4 = -uVar2 < param_3;
    if ((int)((iVar1 - iVar3) - (uint)bVar4) < 0 !=
        (SBORROW4(iVar1,iVar3) != SBORROW4(iVar1 - iVar3,(uint)bVar4))) {
      return CONCAT44(param_2 + param_3 * 0x100000,param_1);
    }
    param_1 = 0;
    param_2 = 0;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00008a94 @ 00008a94 ===== */

void FUN_00008a94(uint param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  bool bVar11;
  longlong lVar12;
  
  uVar6 = -param_1;
  if ((int)(-(uint)(param_1 != 0) - param_2) < 0 ==
      (SBORROW4(-param_2,(uint)(param_1 != 0)) != false)) {
    return;
  }
  uVar4 = (param_2 << 1) >> 0x15;
  uVar8 = param_2 & 0xfffff | 0x100000;
  if ((uVar4 & 1) == 0) {
    bVar11 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    uVar8 = uVar8 * 2 + (uint)bVar11;
    uVar4 = uVar4 - 1;
  }
  lVar2 = 0;
  iVar10 = 0;
  do {
    lVar12 = FUN_00008854(0,0x100000,iVar10,uVar6);
    lVar1 = lVar12 + lVar2 + lVar2;
    uVar6 = (uint)lVar1;
    uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
    if (uVar3 < uVar8 || uVar8 - uVar3 < (uint)(uVar6 <= param_1)) {
      bVar11 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      uVar8 = (uVar8 - uVar3) - (uint)bVar11;
      lVar2 = lVar12 + lVar2;
    }
    iVar9 = (int)((ulonglong)lVar2 >> 0x20);
    uVar3 = (uint)lVar2;
    bVar11 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    iVar10 = iVar10 + 1;
    uVar8 = uVar8 * 2 + (uint)bVar11;
  } while (iVar10 < 0x35);
  uVar6 = iVar9 * 2 + (uint)CARRY4(uVar3,uVar3);
  if (uVar8 < uVar6 || uVar6 - uVar8 < (uint)(param_1 <= uVar3 * 2)) {
    uVar5 = 0;
    uVar7 = 0;
  }
  else {
    uVar5 = 0xffffffff;
    uVar7 = 0xffffffff;
  }
  FUN_000089ac(uVar3,iVar9 + (((int)uVar4 >> 1) + 0x1ff) * 0x100000,uVar5,uVar7);
  return;
}


/* ===== FUN_00008b38 @ 00008b38 ===== */

undefined8 FUN_00008b38(uint param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (((param_2 & 0x7fffffff | param_1) != 0) && (uVar1 = (param_2 << 1) >> 0x15, uVar1 < 0x434)) {
    if (0x3fe < uVar1) {
      uVar2 = FUN_00008836(param_1,param_2,uVar1 - 0x3f3);
      uVar3 = FUN_00008854(param_1,param_2,-(uVar1 - 0x433));
      uVar2 = FUN_000089ac((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                           (int)((ulonglong)uVar2 >> 0x20));
      uVar2 = FUN_00008836((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),-(uVar1 - 0x433));
      return uVar2;
    }
    if ((uVar1 < 0x3fe) || ((param_2 << 0xc | param_1 >> 0x14 | param_1 << 0xc) == 0)) {
      param_1 = 0;
      param_2 = 0;
    }
    else {
      param_2 = param_2 & 0x80000000 | DAT_00008bbc;
      param_1 = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00008bc0 @ 00008bc0 ===== */

undefined4 FUN_00008bc0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar3 = 0;
  uVar2 = param_4 & 0xfffff | 0x100000;
  uVar1 = param_2 & 0xfffff | 0x100000;
  for (uVar4 = (param_2 << 1) >> 0x15; (int)(((param_4 << 1) >> 0x15) - 1) <= (int)uVar4;
      uVar4 = uVar4 - 1) {
    while (uVar2 <= uVar1 && (uint)(param_1 <= param_3) <= uVar2 - uVar1) {
      bVar5 = param_1 < param_3 * 2;
      param_1 = param_1 + param_3 * -2;
      uVar1 = (uVar1 - (uVar2 * 2 + (uint)CARRY4(param_3,param_3))) - (uint)bVar5;
      if ((int)uVar1 < 0) {
        bVar5 = param_1 != 0;
        param_1 = -param_1;
        uVar1 = -(uint)bVar5 - uVar1;
      }
    }
    bVar5 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    uVar1 = uVar1 * 2 + (uint)bVar5;
  }
  if ((param_1 | uVar1) != 0) {
    uVar3 = FUN_000089ca();
  }
  return uVar3;
}


/* ===== FUN_00008c46 @ 00008c46 ===== */

void FUN_00008c46(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar1 = param_2 & 0xfffff | 0x100000;
  if (uVar2 < 0x3ff) {
    return;
  }
  if (uVar2 < 0x434) {
    FUN_00008854(param_1,uVar1,-(uVar2 - 0x433));
    return;
  }
  FUN_00008836(param_1,uVar1);
  return;
}


/* ===== FUN_00008c78 @ 00008c78 ===== */

longlong FUN_00008c78(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  longlong lVar10;
  
  puVar1 = puRam00008c98;
  for (puVar8 = puRam00008c94; puVar8 < puVar1; puVar8 = puVar8 + 4) {
    (*(code *)puVar8[3])(*puVar8,puVar8[1],puVar8[2]);
  }
  uVar2 = thunk_FUN_0000eb08();
  if ((int)uVar2 < 1) {
    return (ulonglong)uVar2 << 0x20;
  }
  uVar3 = (uVar2 << 1) >> 0x18;
  uVar2 = uVar2 & 0x7fffff | 0x800000;
  if ((uVar3 & 1) == 0) {
    uVar2 = uVar2 << 1;
    uVar3 = uVar3 - 1;
  }
  iVar6 = 0;
  uVar4 = 0;
  do {
    iVar7 = (0x800000U >> (uVar4 & 0xff)) + iVar6;
    uVar9 = iVar6 + iVar7;
    if (uVar9 <= uVar2) {
      uVar2 = uVar2 - uVar9;
      iVar6 = iVar7;
    }
    uVar2 = uVar2 << 1;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x18);
  if ((uint)(iVar6 << 1) < uVar2) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar5 = 0;
  }
  lVar10 = FUN_00008898(iVar6 + (((int)uVar3 >> 1) + 0x3f) * 0x800000,uVar5);
  return lVar10;
}


/* ===== FUN_00008c9c @ 00008c9c ===== */

undefined4 FUN_00008c9c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if ((int)param_1 < 1) {
    return 0;
  }
  uVar2 = (param_1 << 1) >> 0x18;
  uVar1 = param_1 & 0x7fffff | 0x800000;
  if ((uVar2 & 1) == 0) {
    uVar1 = uVar1 << 1;
    uVar2 = uVar2 - 1;
  }
  iVar5 = 0;
  uVar3 = 0;
  do {
    iVar6 = (0x800000U >> (uVar3 & 0xff)) + iVar5;
    uVar7 = iVar5 + iVar6;
    if (uVar7 <= uVar1) {
      uVar1 = uVar1 - uVar7;
      iVar5 = iVar6;
    }
    uVar1 = uVar1 << 1;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x18);
  if ((uint)(iVar5 << 1) < uVar1) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 0;
  }
  uVar4 = FUN_00008898(iVar5 + (((int)uVar2 >> 1) + 0x3f) * 0x800000,uVar4);
  return uVar4;
}


/* ===== FUN_00008cfc @ 00008cfc ===== */

undefined4 FUN_00008cfc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined in_ZR;
  bool bVar7;
  bool bVar8;
  char in_CY;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  char cVar12;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
  do {
    uVar5 = FUN_000100c4();
    FUN_0000a6bc(&local_20);
    uVar4 = local_1c;
    uVar3 = local_20;
    FUN_00008780(local_20,DAT_00008dd0);
    bVar1 = !(bool)in_ZR;
    bVar9 = (bool)in_CY;
    FUN_00008780(uVar4,DAT_00008dd0);
    bVar2 = !(bool)in_ZR;
    bVar7 = bVar9 && bVar2;
    bVar10 = bVar9;
    FUN_00008794(uVar3,DAT_00008dd4);
    bVar7 = !bVar7;
    bVar8 = bVar10 && bVar7;
    bVar11 = bVar10;
    FUN_00008794(uVar4,DAT_00008dd4);
    cVar12 = '\x01';
    in_ZR = (((bool)in_CY && bVar1 || bVar9 && bVar2) || bVar10 && bVar7) || bVar11 && !bVar8;
    if ((((!(bool)in_CY || !bVar1) && (!bVar9 || !bVar2)) && (!bVar10 || !bVar7)) &&
        (!bVar11 || bVar8)) {
      return 1;
    }
    FUN_00008780(uVar3,DAT_00008dd4);
    if (cVar12 == '\0') {
      iVar6 = FUN_0000a7c0(uVar5);
    }
    else {
      FUN_00008794(uVar3,DAT_00008dd0);
      if (cVar12 == '\0') {
        iVar6 = FUN_0000a764(uVar5);
      }
      else {
        FUN_00008780(uVar4,DAT_00008dd4);
        if (cVar12 == '\0') {
          iVar6 = FUN_0000a850(uVar5);
        }
        else {
          FUN_00008794(uVar4,DAT_00008dd0);
          if (cVar12 != '\0') {
            return 1;
          }
          iVar6 = FUN_0000a7f4(uVar5);
        }
      }
    }
    in_CY = cVar12;
  } while (iVar6 != 0);
  return 0;
}


/* ===== FUN_00008dd8 @ 00008dd8 ===== */

undefined4 FUN_00008dd8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined in_ZR;
  bool bVar7;
  bool bVar8;
  char in_CY;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  char cVar12;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
  do {
    uVar5 = FUN_000100e0();
    FUN_0000a884(&local_20);
    uVar4 = local_1c;
    uVar3 = local_20;
    FUN_00008780(local_20,DAT_00008eac);
    bVar1 = !(bool)in_ZR;
    bVar9 = (bool)in_CY;
    FUN_00008780(uVar4,DAT_00008eac);
    bVar2 = !(bool)in_ZR;
    bVar7 = bVar9 && bVar2;
    bVar10 = bVar9;
    FUN_00008794(uVar3,DAT_00008eb0);
    bVar7 = !bVar7;
    bVar8 = bVar10 && bVar7;
    bVar11 = bVar10;
    FUN_00008794(uVar4,DAT_00008eb0);
    cVar12 = '\x01';
    in_ZR = (((bool)in_CY && bVar1 || bVar9 && bVar2) || bVar10 && bVar7) || bVar11 && !bVar8;
    if ((((!(bool)in_CY || !bVar1) && (!bVar9 || !bVar2)) && (!bVar10 || !bVar7)) &&
        (!bVar11 || bVar8)) {
      return 1;
    }
    FUN_00008780(uVar3,DAT_00008eb0);
    if (cVar12 == '\0') {
      iVar6 = FUN_0000a988(uVar5);
    }
    else {
      FUN_00008794(uVar3,DAT_00008eac);
      if (cVar12 == '\0') {
        iVar6 = FUN_0000a92c(uVar5);
      }
      else {
        FUN_00008780(uVar4,DAT_00008eb0);
        if (cVar12 == '\0') {
          iVar6 = FUN_0000aa18(uVar5);
        }
        else {
          FUN_00008794(uVar4,DAT_00008eac);
          if (cVar12 != '\0') {
            return 1;
          }
          iVar6 = FUN_0000a9bc(uVar5);
        }
      }
    }
    in_CY = cVar12;
  } while (iVar6 != 0);
  return 0;
}


/* ===== FUN_00008eb4 @ 00008eb4 ===== */

undefined4 FUN_00008eb4(byte *param_1)

{
  int iVar1;
  
  if ((param_1[1] & 1) == 0) {
    *(uint *)(DAT_00008f9c + 0x44) =
         *(uint *)(DAT_00008f9c + 0x44) & 0xffff |
         (*(uint *)(DAT_00008f9c + 0x44) >> 0x10 & ~(1 << *param_1)) << 0x10;
  }
  else {
    *(uint *)(DAT_00008f9c + 0x44) = *(uint *)(DAT_00008f9c + 0x44) & 0xffffff00 | (uint)*param_1;
    iVar1 = DAT_00008f9c;
    if (*(int *)(param_1 + 8) << 0xe < 0) {
      if (*(int *)(param_1 + 8) << 0xf < 0) {
        *(uint *)(DAT_00008f9c + 0x58) = ~(*(uint *)(param_1 + 0x14) & 0x1fffffff);
        *(uint *)(iVar1 + 0x48) = *(uint *)(param_1 + 4) & 0x1fffffff;
      }
      else {
        *(uint *)(DAT_00008f9c + 0x58) = ~((uint)*(ushort *)(param_1 + 0x14) << 0x12);
        *(uint *)(iVar1 + 0x48) = (uint)*(ushort *)(param_1 + 4) << 0x12;
      }
    }
    else if (*(int *)(param_1 + 8) << 0xf < 0) {
      *(uint *)(DAT_00008f9c + 0x58) = ~(*(uint *)(param_1 + 0x14) & 0x1fffffff);
      *(uint *)(iVar1 + 0x48) = *(uint *)(param_1 + 4) & 0x1fffffff;
    }
    else {
      *(uint *)(DAT_00008f9c + 0x58) = ~((uint)*(ushort *)(param_1 + 0x14) << 0x12);
      *(uint *)(iVar1 + 0x48) = (uint)*(ushort *)(param_1 + 4) << 0x12;
    }
    iVar1 = DAT_00008f9c;
    *(undefined4 *)(DAT_00008f9c + 0x5c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar1 + 100) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x50) = 0;
    *(undefined4 *)(iVar1 + 0x54) = 0;
    *(uint *)(DAT_00008f9c + 0x44) =
         *(uint *)(DAT_00008f9c + 0x44) & 0xffff |
         (1 << *param_1 | *(uint *)(DAT_00008f9c + 0x44) >> 0x10) << 0x10;
  }
  *(uint *)(DAT_00008f9c + 0x2c) = (*(uint *)(DAT_00008f9c + 0x2c) & 0xffffff0f) + 0x20;
  return 0;
}


/* ===== FUN_00008fa0 @ 00008fa0 ===== */

void FUN_00008fa0(int param_1,uint param_2,int param_3)

{
  undefined uVar1;
  uint uVar2;
  
  FUN_00010ed8(DAT_00009010);
  FUN_0000c974(5,0);
  FUN_00010eac(DAT_00009010);
  FUN_00010f84(DAT_00009010,3);
  FUN_00010f84(DAT_00009010,(param_2 << 8) >> 0x18);
  FUN_00010f84(DAT_00009010,(param_2 << 0x10) >> 0x18);
  FUN_00010f84(DAT_00009010,param_2 & 0xff);
  for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
    uVar1 = FUN_00010f84(DAT_00009010,0xff);
    *(undefined *)(param_1 + uVar2) = uVar1;
  }
  *(undefined4 *)(DAT_00009014 + 0x1c) = 1;
  FUN_000099f0(DAT_00009010);
  FUN_00010ed8(DAT_00009010);
  return;
}


/* ===== FUN_00009018 @ 00009018 ===== */

void FUN_00009018(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if ((int)param_3 <= (int)uVar1) {
    uVar1 = param_3;
  }
  while (FUN_00008fa0(param_1,param_2,uVar1), param_3 != uVar1) {
    param_1 = param_1 + uVar1;
    param_2 = param_2 + uVar1;
    param_3 = param_3 - uVar1 & 0xffff;
    uVar1 = param_3;
    if (0x100 < param_3) {
      uVar1 = 0x100;
    }
  }
  return;
}


/* ===== FUN_0000905e @ 0000905e ===== */

void FUN_0000905e(void)

{
  uint uVar1;
  
  do {
    uVar1 = FUN_000091bc();
  } while ((uVar1 & 1) != 0);
  return;
}


/* ===== FUN_00009070 @ 00009070 ===== */

void FUN_00009070(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char acStack_1024 [4096];
  
  FUN_00008126(acStack_1024,0x1000);
  uVar3 = param_2 >> 0xc;
  uVar4 = param_2 & 0xfff;
  uVar1 = 0x1000 - uVar4;
  if ((int)param_3 <= (int)(0x1000 - uVar4)) {
    uVar1 = param_3;
  }
  while( true ) {
    FUN_00008fa0(acStack_1024,uVar3 << 0xc,0x1000);
    for (uVar2 = 0; ((int)uVar2 < (int)uVar1 && (acStack_1024[uVar4 + uVar2] == -1));
        uVar2 = uVar2 + 1 & 0xffff) {
    }
    if ((int)uVar2 < (int)uVar1) {
      FUN_000107c4(uVar3);
      for (uVar2 = 0; (int)uVar2 < (int)uVar1; uVar2 = uVar2 + 1 & 0xffff) {
        acStack_1024[uVar2 + uVar4] = *(char *)(param_1 + uVar2);
      }
      FUN_00009a24(acStack_1024,uVar3 << 0xc,0x1000);
    }
    else {
      FUN_00009a24(param_1,param_2,uVar1);
    }
    if (param_3 == uVar1) break;
    uVar3 = uVar3 + 1;
    uVar4 = 0;
    param_1 = param_1 + uVar1;
    param_2 = param_2 + uVar1;
    param_3 = param_3 - uVar1 & 0xffff;
    uVar1 = param_3;
    if (0x1000 < param_3) {
      uVar1 = 0x1000;
    }
  }
  return;
}


/* ===== FUN_0000913c @ 0000913c ===== */

void FUN_0000913c(uint param_1,uint param_2)

{
  *DAT_00009150 = DAT_0000914c & param_2 | param_1;
  enableIRQinterrupts();
  return;
}


/* ===== FUN_00009158 @ 00009158 ===== */

short FUN_00009158(void)

{
  short sVar1;
  short sVar2;
  
  FUN_00010ed8(DAT_000091b8);
  FUN_0000c974(5,0);
  FUN_00010eac(DAT_000091b8);
  FUN_00010f84(DAT_000091b8,0x90);
  FUN_00010f84(DAT_000091b8,0);
  FUN_00010f84(DAT_000091b8,0);
  FUN_00010f84(DAT_000091b8,0);
  sVar1 = FUN_00010f84(DAT_000091b8,0xff);
  sVar2 = FUN_00010f84(DAT_000091b8,0xff);
  FUN_00010ed8(DAT_000091b8);
  FUN_000099f0(DAT_000091b8);
  return sVar2 + sVar1 * 0x100;
}


/* ===== FUN_000091bc @ 000091bc ===== */

undefined4 FUN_000091bc(void)

{
  undefined4 uVar1;
  
  FUN_00010eac(DAT_000091e4);
  FUN_00010f84(DAT_000091e4,5);
  uVar1 = FUN_00010f84(DAT_000091e4,0xff);
  FUN_00010ed8(DAT_000091e4);
  return uVar1;
}


/* ===== FUN_000091f8 @ 000091f8 ===== */

int FUN_000091f8(int param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  undefined uVar3;
  undefined uVar4;
  short sVar5;
  short *psVar6;
  char cVar7;
  
  cVar7 = -100;
  if ((9 < *(ushort *)(param_1 + 0xe)) && (*(char *)(param_1 + 0xc) != '\0')) {
    FUN_00009782(param_1);
    FUN_00009acc("[TF] Parser timeout\n");
  }
  *(undefined2 *)(param_1 + 0xe) = 0;
  uVar4 = (undefined)param_2;
  uVar2 = (ushort)param_2;
  switch(*(undefined *)(param_1 + 0xc)) {
  case 0:
    if (param_2 == 1) {
      FUN_0000ef70(param_1);
      cVar7 = '\x01';
    }
    else {
      cVar7 = -1;
    }
    break;
  case 1:
    uVar4 = FUN_00009600(*(undefined *)(param_1 + 0x96),param_2);
    *(undefined *)(param_1 + 0x96) = uVar4;
    *(ushort *)(param_1 + 0x12) = uVar2 | (ushort)*(byte *)(param_1 + 0x12) << 8;
    sVar5 = *(short *)(param_1 + 0x94) + 1;
    *(short *)(param_1 + 0x94) = sVar5;
    if (sVar5 == 2) {
      *(undefined *)(param_1 + 0xc) = 4;
      *(undefined2 *)(param_1 + 0x94) = 0;
      cVar7 = '\x03';
    }
    else {
      cVar7 = -3;
    }
    break;
  case 2:
    psVar6 = (short *)(param_1 + 0x94);
    *(undefined *)(param_1 + 0x97) = uVar4;
    sVar5 = *psVar6;
    *psVar6 = sVar5 + 1;
    if ((short)(sVar5 + 1) == 1) {
      uVar4 = FUN_00009608(*(undefined *)(param_1 + 0x96));
      *(undefined *)(param_1 + 0x96) = uVar4;
      if (*(char *)(param_1 + 0x96) == *(char *)(param_1 + 0x97)) {
        if (*(short *)(param_1 + 0x12) == 0) {
          FUN_00009782(param_1);
          cVar7 = '\0';
        }
        else {
          cVar7 = '\x05';
          *(undefined *)(param_1 + 0xc) = 5;
          *psVar6 = 0;
          uVar4 = FUN_00009610();
          *(undefined *)(param_1 + 0x96) = uVar4;
        }
      }
      else {
        FUN_00009acc("[TF] Rx head cksum mismatch\n");
        FUN_00009782(param_1);
        cVar7 = -8;
      }
      if (0x80 < *(ushort *)(param_1 + 0x12)) {
        FUN_00009acc("[TF] Rx payload too long: %d\n",*(undefined2 *)(param_1 + 0x12));
        *(undefined *)(param_1 + 0x9a) = 1;
        cVar7 = -9;
      }
    }
    else {
      cVar7 = -5;
    }
    break;
  case 3:
    uVar4 = FUN_00009600(*(undefined *)(param_1 + 0x96),param_2);
    *(undefined *)(param_1 + 0x96) = uVar4;
    *(ushort *)(param_1 + 0x10) = uVar2 | (ushort)*(byte *)(param_1 + 0x10) << 8;
    sVar5 = *(short *)(param_1 + 0x94) + 1;
    *(short *)(param_1 + 0x94) = sVar5;
    if (sVar5 == 2) {
      *(undefined *)(param_1 + 0xc) = 1;
      *(undefined2 *)(param_1 + 0x94) = 0;
      cVar7 = '\x02';
    }
    else {
      cVar7 = -2;
    }
    break;
  case 4:
    uVar4 = FUN_00009600(*(undefined *)(param_1 + 0x96),param_2);
    *(undefined *)(param_1 + 0x96) = uVar4;
    psVar6 = (short *)(param_1 + 0x94);
    *(ushort *)(param_1 + 0x98) = uVar2 | (ushort)*(byte *)(param_1 + 0x98) << 8;
    sVar5 = *psVar6;
    *psVar6 = sVar5 + 1;
    if ((short)(sVar5 + 1) == 2) {
      *(undefined *)(param_1 + 0xc) = 2;
      *psVar6 = 0;
      *(undefined *)(param_1 + 0x97) = 0;
      cVar7 = '\x04';
    }
    else {
      cVar7 = -4;
    }
    break;
  case 5:
    if (*(char *)(param_1 + 0x9a) == '\0') {
      uVar3 = FUN_00009600(*(undefined *)(param_1 + 0x96),param_2);
      *(undefined *)(param_1 + 0x96) = uVar3;
      puVar1 = (ushort *)(param_1 + 0x94);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + 1;
      *(undefined *)(param_1 + 0x14 + (uint)uVar2) = uVar4;
      cVar7 = '\x06';
    }
    else {
      *(short *)(param_1 + 0x94) = *(short *)(param_1 + 0x94) + 1;
      cVar7 = -6;
    }
    if (*(short *)(param_1 + 0x94) == *(short *)(param_1 + 0x12)) {
      *(undefined *)(param_1 + 0xc) = 6;
      *(undefined2 *)(param_1 + 0x94) = 0;
      *(undefined *)(param_1 + 0x97) = 0;
    }
    break;
  case 6:
    *(undefined *)(param_1 + 0x97) = uVar4;
    sVar5 = *(short *)(param_1 + 0x94) + 1;
    *(short *)(param_1 + 0x94) = sVar5;
    if (sVar5 == 1) {
      uVar4 = FUN_00009608(*(undefined *)(param_1 + 0x96));
      *(undefined *)(param_1 + 0x96) = uVar4;
      if (*(char *)(param_1 + 0x9a) == '\0') {
        if (*(char *)(param_1 + 0x96) == *(char *)(param_1 + 0x97)) {
          cVar7 = '\0';
        }
        else {
          FUN_00009acc("[TF] Body cksum mismatch\n");
          cVar7 = -10;
        }
      }
      FUN_00009782(param_1);
    }
    else {
      cVar7 = -7;
    }
  }
  return (int)cVar7;
}


/* ===== FUN_000094b0 @ 000094b0 ===== */

void FUN_000094b0(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  FUN_0000c42c(DAT_000095b8);
  FUN_0001191c(DAT_000095bc,DAT_000095b8);
  if (*DAT_000095bc == 0x4ee && *(char *)(DAT_000095bc + 2) == '\0') {
    if ((*(byte *)(DAT_000095bc + 3) & 0xf0) == 0x10) {
      uVar2 = FUN_000085dc((uint)*(byte *)((int)DAT_000095bc + 0xd) +
                           (*(byte *)(DAT_000095bc + 3) & 0xf) * 0x100);
      uVar2 = FUN_000081ec(uVar2,0x3f800000);
      FUN_00008250(uVar2,DAT_000095c0);
      FUN_000086c0();
      FUN_0000c5f4();
      uVar3 = FUN_0000868e();
      *DAT_000095c4 = uVar3;
      *DAT_000095c8 = 1;
    }
    else if ((*(byte *)(DAT_000095bc + 3) & 0xf0) == 0x20) {
      *DAT_000095c8 = *DAT_000095c8 + 1;
    }
    if (*DAT_000095c8 < *DAT_000095c4) {
      FUN_00011288(DAT_000095d0,DAT_000095cc,0);
    }
    else if (*DAT_000095c4 <= *DAT_000095c8) {
      FUN_00010c94(1);
      *DAT_000095c8 = 0;
      *DAT_000095c4 = 0;
      FUN_000112c0(DAT_000095d0);
    }
    for (uVar3 = 2; uVar3 < 8; uVar3 = uVar3 + 1) {
      *(undefined *)(DAT_000095d4 + *DAT_000095d8) = *(undefined *)((int)DAT_000095bc + uVar3 + 0xc)
      ;
      puVar1 = DAT_000095d8;
      *DAT_000095d8 = *DAT_000095d8 + 1;
      *puVar1 = *puVar1 & 0x7f;
    }
  }
  return;
}


/* ===== FUN_00009600 @ 00009600 ===== */

uint FUN_00009600(uint param_1,uint param_2)

{
  return param_1 ^ param_2;
}


/* ===== FUN_00009608 @ 00009608 ===== */

byte FUN_00009608(byte param_1)

{
  return ~param_1;
}


/* ===== FUN_00009610 @ 00009610 ===== */

undefined4 FUN_00009610(void)

{
  return 0;
}


/* ===== FUN_00009614 @ 00009614 ===== */

bool FUN_00009614(int param_1)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 0x2a5) == '\0';
  if (bVar1) {
    *(undefined *)(param_1 + 0x2a5) = 1;
  }
  else {
    FUN_00009acc("[TF] TF already locked for tx!\n");
  }
  return bVar1;
}


/* ===== FUN_00009654 @ 00009654 ===== */

void FUN_00009654(undefined4 param_1)

{
  FUN_00008126(param_1,0x18);
  return;
}


/* ===== FUN_00009662 @ 00009662 ===== */

int FUN_00009662(int param_1,undefined *param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  FUN_00009610();
  if (*(char *)(param_3 + 1) == '\0') {
    uVar1 = *(ushort *)(param_1 + 10);
    *(ushort *)(param_1 + 10) = uVar1 + 1;
    uVar7 = uVar1 & 0x7fff;
    if (*(char *)(param_1 + 8) != '\0') {
      uVar7 = uVar7 | 0x8000;
    }
  }
  else {
    uVar7 = (uint)*param_3;
  }
  *param_3 = (ushort)uVar7;
  uVar2 = FUN_00009610();
  *param_2 = 1;
  uVar2 = FUN_00009600(uVar2,1);
  iVar6 = 1;
  for (uVar5 = 1; -1 < (int)uVar5; uVar5 = (uint)(char)((char)uVar5 + -1)) {
    uVar3 = (int)uVar7 >> ((uVar5 & 0x1f) << 3);
    param_2[iVar6] = (char)uVar3;
    uVar2 = FUN_00009600(uVar2,uVar3 & 0xff);
    iVar6 = iVar6 + 1;
  }
  for (uVar7 = 1; -1 < (int)uVar7; uVar7 = (uint)(char)((char)uVar7 + -1)) {
    uVar5 = (int)(uint)param_3[6] >> ((uVar7 & 0x1f) << 3);
    param_2[iVar6] = (char)uVar5;
    uVar2 = FUN_00009600(uVar2,uVar5 & 0xff);
    iVar6 = iVar6 + 1;
  }
  for (uVar7 = 1; -1 < (int)uVar7; uVar7 = (uint)(char)((char)uVar7 + -1)) {
    uVar5 = (int)(uint)param_3[2] >> ((uVar7 & 0x1f) << 3);
    param_2[iVar6] = (char)uVar5;
    uVar2 = FUN_00009600(uVar2,uVar5 & 0xff);
    iVar6 = iVar6 + 1;
  }
  iVar4 = FUN_00009608(uVar2);
  for (uVar7 = 0; -1 < (int)uVar7; uVar7 = (uint)(char)((char)uVar7 + -1)) {
    param_2[iVar6] = (char)(iVar4 >> ((uVar7 & 0x1f) << 3));
    iVar6 = iVar6 + 1;
  }
  return iVar6;
}


/* ===== FUN_0000977a @ 0000977a ===== */

void FUN_0000977a(int param_1)

{
  *(undefined *)(param_1 + 0x2a5) = 0;
  return;
}


/* ===== FUN_00009782 @ 00009782 ===== */

void FUN_00009782(int param_1)

{
  *(undefined *)(param_1 + 0xc) = 0;
  return;
}


/* ===== FUN_00009788 @ 00009788 ===== */

void FUN_00009788(undefined4 param_1,undefined4 param_2)

{
  FUN_0000979a(param_1,param_2,0);
  return;
}


/* ===== FUN_0000979a @ 0000979a ===== */

undefined4 FUN_0000979a(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000097d2(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if ((*(short *)(param_2 + 0xc) == 0) || (*(int *)(param_2 + 8) != 0)) {
      FUN_00009810(param_1,*(undefined4 *)(param_2 + 8),*(undefined2 *)(param_2 + 0xc));
      FUN_000098ce(param_1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* ===== FUN_000097d2 @ 000097d2 ===== */

bool FUN_000097d2(int param_1,int param_2)

{
  undefined uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_00009614(param_1);
  if (iVar2 != 0) {
    uVar3 = FUN_00009662(param_1,param_1 + 0x9b,param_2);
    *(undefined4 *)(param_1 + 0x29c) = uVar3;
    *(uint *)(param_1 + 0x2a0) = (uint)*(ushort *)(param_2 + 0xc);
    uVar1 = FUN_00009610();
    *(undefined *)(param_1 + 0x2a4) = uVar1;
  }
  return iVar2 != 0;
}


/* ===== FUN_00009810 @ 00009810 ===== */

void FUN_00009810(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  undefined uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar7 = 0;
  while (param_3 != 0) {
    uVar3 = param_3;
    if (0x200U - *(int *)(param_1 + 0x29c) < param_3) {
      uVar3 = 0x200 - *(int *)(param_1 + 0x29c);
    }
    iVar4 = *(int *)(param_1 + 0x29c);
    uVar9 = 0;
    iVar8 = 0;
    for (uVar6 = 0; uVar6 < (uVar3 & 0xffff); uVar6 = uVar6 + 1 & 0xffff) {
      bVar1 = *(byte *)(param_2 + iVar7 + uVar6);
      uVar9 = (uint)bVar1;
      iVar5 = iVar8 + 1;
      *(byte *)(param_1 + 0x9b + iVar4 + iVar8) = bVar1;
      uVar2 = FUN_00009600(*(undefined *)(param_1 + 0x2a4),uVar9);
      *(undefined *)(param_1 + 0x2a4) = uVar2;
      iVar8 = iVar5;
    }
    *(int *)(param_1 + 0x29c) = iVar8 + *(int *)(param_1 + 0x29c);
    param_3 = param_3 - uVar3;
    iVar7 = iVar7 + uVar3;
    if (*(int *)(param_1 + 0x29c) == 0x200) {
      FUN_000099a6(param_1,param_1 + 0x9b,*(undefined4 *)(param_1 + 0x29c),param_4,iVar8,uVar9);
      *(undefined4 *)(param_1 + 0x29c) = 0;
    }
  }
  return;
}


/* ===== FUN_000098ce @ 000098ce ===== */

void FUN_000098ce(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x2a0) != 0) {
    if (*(int *)(param_1 + 0x29c) == 0x200) {
      FUN_000099a6(param_1,param_1 + 0x9b,*(undefined4 *)(param_1 + 0x29c));
      *(undefined4 *)(param_1 + 0x29c) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x29c);
    pbVar3 = (byte *)(param_1 + 0x2a4);
    bVar1 = FUN_00009608(*pbVar3);
    *pbVar3 = bVar1;
    iVar5 = 0;
    for (uVar4 = 0; -1 < (int)uVar4; uVar4 = (uint)(char)((char)uVar4 + -1)) {
      *(char *)(iVar2 + param_1 + 0x9b + iVar5) =
           (char)((int)(uint)*pbVar3 >> ((uVar4 & 0x1f) << 3));
      iVar5 = iVar5 + 1;
    }
    *(int *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + iVar5;
  }
  FUN_000099a6(param_1,param_1 + 0x9b,*(undefined4 *)(param_1 + 0x29c));
  FUN_0000977a(param_1);
  return;
}


/* ===== FUN_0000995e @ 0000995e ===== */

void FUN_0000995e(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined auStack_2c [4];
  undefined2 local_28;
  undefined4 local_24;
  undefined2 local_20;
  
  FUN_00009654(auStack_2c);
  local_28 = param_2;
  local_24 = param_3;
  local_20 = param_4;
  FUN_00009788(param_1,auStack_2c);
  return;
}


/* ===== FUN_00009986 @ 00009986 ===== */

void FUN_00009986(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    *param_1 = (uint)*(byte *)(param_2 + uVar1);
    do {
    } while ((param_1[1] & 1) != 0);
  }
  return;
}


/* ===== FUN_000099a6 @ 000099a6 ===== */

void FUN_000099a6(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(int *)(param_1 + 0x2a8) != 0) {
    (**(code **)(param_1 + 0x2a8))(*(undefined4 *)(param_1 + 0x2ac),param_2,param_3);
  }
  return;
}


/* ===== FUN_000099c4 @ 000099c4 ===== */

void FUN_000099c4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_000099e8;
  *(undefined **)(DAT_000099e8 + 0x2ac) = &DAT_40004000;
  *(undefined4 *)(iVar1 + 0x2a8) = DAT_000099ec;
  FUN_000115ac(param_1,param_2,param_3);
  return;
}


/* ===== FUN_000099f0 @ 000099f0 ===== */

void FUN_000099f0(int param_1)

{
  do {
  } while ((*(uint *)(param_1 + 0xc) & 0x10) == 0x10);
  return;
}


/* ===== FUN_00009a00 @ 00009a00 ===== */

void FUN_00009a00(void)

{
  FUN_00010eac(DAT_00009a20);
  FUN_00010f84(DAT_00009a20,6);
  FUN_00010ed8(DAT_00009a20);
  FUN_000099f0(DAT_00009a20);
  return;
}


/* ===== FUN_00009a24 @ 00009a24 ===== */

void FUN_00009a24(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if ((int)param_3 <= (int)uVar1) {
    uVar1 = param_3;
  }
  while (FUN_00009a6c(param_1,param_2,uVar1), param_3 != uVar1) {
    param_1 = param_1 + uVar1;
    param_2 = param_2 + uVar1;
    param_3 = param_3 - uVar1 & 0xffff;
    uVar1 = param_3;
    if (0x100 < param_3) {
      uVar1 = 0x100;
    }
  }
  return;
}


/* ===== FUN_00009a6c @ 00009a6c ===== */

void FUN_00009a6c(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  FUN_00009a00();
  FUN_00010eac(DAT_00009ac8);
  FUN_00010f84(DAT_00009ac8,2);
  FUN_00010f84(DAT_00009ac8,(param_2 << 8) >> 0x18);
  FUN_00010f84(DAT_00009ac8,(param_2 << 0x10) >> 0x18);
  FUN_00010f84(DAT_00009ac8,param_2 & 0xff);
  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
    FUN_00010f84(DAT_00009ac8,*(undefined *)(param_1 + uVar1));
  }
  FUN_00010ed8(DAT_00009ac8);
  FUN_0000905e();
  return;
}


/* ===== FUN_00009acc @ 00009acc ===== */

void FUN_00009acc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_00009f50(param_1,&uStack_c,DAT_00009ae8,DAT_00009ae4);
  return;
}


/* ===== FUN_00009aec @ 00009aec ===== */

undefined8 FUN_00009aec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uVar1 = FUN_00009f50(param_2,param_3,&uStack_18,DAT_00009b0c);
  FUN_0000a67e(0,&uStack_18);
  return CONCAT44(uStack_18,uVar1);
}


/* ===== FUN_00009b10 @ 00009b10 ===== */

uint FUN_00009b10(uint param_1,int param_2)

{
  param_1 = param_1 | param_2 << 0xc;
  if (param_1 != 0) {
    param_1 = 4;
  }
  if ((uint)(param_2 << 1) >> 0x15 != 0) {
    param_1 = param_1 | 1;
  }
  if ((uint)(param_2 << 1) >> 0x15 == 0x7ff) {
    param_1 = param_1 | 2;
  }
  if (param_1 == 1) {
    param_1 = 5;
  }
  return param_1;
}


/* ===== FUN_00009b38 @ 00009b38 ===== */

uint FUN_00009b38(int param_1)

{
  uint uVar1;
  
  uVar1 = param_1 << 9;
  if (uVar1 != 0) {
    uVar1 = 4;
  }
  if ((uint)(param_1 << 1) >> 0x18 != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((~(param_1 << 1) & 0xff000000U) == 0) {
    uVar1 = uVar1 | 2;
  }
  if (uVar1 == 1) {
    uVar1 = 5;
  }
  return uVar1;
}


/* ===== FUN_00009b5e @ 00009b5e ===== */

void FUN_00009b5e(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = param_2 - 1;
  uVar3 = *(undefined8 *)(param_1 + uVar2 * 2);
  while (uVar1 = (undefined4)((ulonglong)uVar3 >> 0x20), (uVar2 & 0xfffffff9) != 0) {
    uVar3 = FUN_0000841a((int)uVar3,uVar1,param_3,param_4);
    uVar2 = uVar2 - 1;
    uVar3 = FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[uVar2 * 2],
                         (param_1 + uVar2 * 2)[1]);
  }
  if (uVar2 != 2) {
    if (uVar2 != 4) {
      if (uVar2 != 6) {
        return;
      }
      uVar3 = FUN_0000841a((int)uVar3,uVar1,param_3,param_4);
      uVar3 = FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[10],param_1[0xb]);
      uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
      uVar3 = FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[8],param_1[9]);
    }
    uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
    uVar3 = FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[6],param_1[7]);
    uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
    uVar3 = FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[4],param_1[5]);
  }
  uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
  uVar3 = FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_1[2],param_1[3]);
  uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),param_3,param_4);
  FUN_000082cc((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),*param_1,param_1[1]);
  return;
}


/* ===== FUN_00009c08 @ 00009c08 ===== */

void FUN_00009c08(void)

{
  FUN_000084fe(0,DAT_00009c14,0,0);
  return;
}


/* ===== FUN_00009c2c @ 00009c2c ===== */

void FUN_00009c2c(void)

{
  FUN_00008a66(0,DAT_00009c38 << 0x1c);
  return;
}


/* ===== FUN_00009c4e @ 00009c4e ===== */

void FUN_00009c4e(void)

{
  FUN_00008906(0x10000000);
  return;
}


/* ===== FUN_00009c58 @ 00009c58 ===== */

uint FUN_00009c58(uint param_1,uint *param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  if (0xfeffffff < param_3 * 2) {
    *param_2 = 0xffffffff;
    return param_1;
  }
  uVar8 = param_3 << 8 | 0x80000000;
  uVar2 = ((param_3 << 1) >> 0x18) - 0x78;
  uVar9 = uVar2 & 0x1f;
  uVar10 = 0x20 - uVar9;
  iVar3 = DAT_00009db0 + 0x9c94 + ((int)(((param_3 << 1) >> 0x18) - 0x78) >> 5) * 4;
  uVar2 = *(uint *)(DAT_00009db0 + 0x9c94 + ((int)uVar2 >> 5) * 4);
  if (uVar9 == 0) {
    uVar12 = *(uint *)(iVar3 + 4);
    uVar9 = *(uint *)(iVar3 + 8);
  }
  else {
    uVar2 = uVar2 << uVar9 | *(uint *)(iVar3 + 4) >> (uVar10 & 0xff);
    uVar12 = *(uint *)(iVar3 + 4) << uVar9 | *(uint *)(iVar3 + 8) >> (uVar10 & 0xff);
    uVar9 = *(uint *)(iVar3 + 8) << uVar9 | *(uint *)(iVar3 + 0xc) >> (uVar10 & 0xff);
  }
  uVar10 = (uint)((ulonglong)uVar12 * (ulonglong)uVar8 >> 0x20);
  uVar9 = (uint)((ulonglong)uVar9 * (ulonglong)uVar8 >> 0x20);
  lVar1 = (ulonglong)uVar12 * (ulonglong)uVar8 +
          CONCAT44((int)((ulonglong)uVar2 * (ulonglong)uVar8),uVar9);
  uVar11 = (uint)lVar1;
  uVar12 = (uint)((ulonglong)lVar1 >> 0x20);
  if (uVar11 < uVar9) {
    if (uVar12 <= uVar10) {
LAB_00009d04:
      iVar3 = 1;
      goto LAB_00009d0a;
    }
  }
  else if (uVar12 < uVar10) goto LAB_00009d04;
  iVar3 = 0;
LAB_00009d0a:
  iVar3 = iVar3 + (int)((ulonglong)uVar2 * (ulonglong)uVar8 >> 0x20);
  uVar8 = iVar3 + 0x20U >> 6;
  *param_2 = uVar8;
  uVar4 = FUN_000085dc(iVar3 * 0x4000000 | (uVar12 >> 0x13) << 0xd);
  uVar5 = FUN_000085ee(uVar12 * 0x2000);
  uVar5 = FUN_00008906(uVar5,0xffffffed);
  uVar6 = FUN_000085ee(uVar11);
  uVar6 = FUN_00008906(uVar6,0xffffffda);
  uVar7 = FUN_0000813c(uVar4,uVar5);
  iVar3 = FUN_0000813c(uVar7,uVar6);
  uVar2 = iVar3 + 0x800U & 0xfffff000;
  uVar4 = FUN_000081e0(uVar2,uVar4);
  uVar4 = FUN_000081e0(uVar4,uVar5);
  uVar4 = FUN_000081e6(uVar4,uVar6);
  uVar4 = FUN_000081ec(uVar4,DAT_00009db4);
  uVar5 = FUN_000081ec(uVar2,DAT_00009db8);
  uVar4 = FUN_0000813c(uVar5,uVar4);
  uVar5 = FUN_000081ec(uVar2,DAT_00009dbc);
  uVar2 = FUN_0000813c(uVar5,uVar4);
  if ((param_3 & 0x80000000) != 0) {
    *param_2 = 0x10000000 - uVar8;
    return uVar2 ^ 0x80000000;
  }
  return uVar2;
}


/* ===== thunk_FUN_00009dc8 @ 00009dc0 ===== */

void thunk_FUN_00009dc8(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}


/* ===== FUN_00009dc8 @ 00009dc8 ===== */

void FUN_00009dc8(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}


/* ===== FUN_00009de0 @ 00009de0 ===== */

void FUN_00009de0(undefined4 param_1)

{
  *DAT_00009de8 = param_1;
  return;
}


/* ===== FUN_00009dec @ 00009dec ===== */

undefined8 FUN_00009dec(int *param_1,int param_2,uint param_3,uint param_4,uint param_5,int param_6)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined uVar10;
  longlong lVar11;
  undefined8 uVar12;
  longlong lVar13;
  
  if ((param_3 | param_4) == 0) {
    if (param_6 == 1) {
      param_5 = ~param_5;
    }
    else {
      param_5 = 0;
    }
    *param_1 = (int)&DAT_00009f44;
    param_1[1] = param_5;
    param_1[2] = 1;
    param_1[3] = param_6;
  }
  else {
    iVar5 = (int)(((param_4 >> 0x14) - 0x3ff) * 0x4d10) >> 0x10;
    do {
      while( true ) {
        if (param_6 == 1) {
          uVar1 = -param_5;
        }
        else {
          uVar1 = (iVar5 - param_5) + 1;
        }
        lVar11 = (ulonglong)DAT_00009f3c << 0x20;
        lVar13 = (ulonglong)DAT_00009f40 << 0x20;
        uVar7 = uVar1;
        if ((int)uVar1 < 0) {
          uVar7 = -uVar1;
          lVar13 = (ulonglong)DAT_00009f40 << 0x20;
          lVar11 = (ulonglong)DAT_00009f3c << 0x20;
        }
        while( true ) {
          uVar6 = (undefined4)((ulonglong)lVar11 >> 0x20);
          uVar8 = (undefined4)((ulonglong)lVar13 >> 0x20);
          if (uVar7 == 0) break;
          if ((uVar7 & 1) != 0) {
            lVar13 = FUN_0000841a((int)lVar13,uVar8,(int)lVar11,uVar6);
          }
          lVar11 = FUN_0000841a((int)lVar11,uVar6);
          uVar7 = (int)uVar7 >> 1;
        }
        uVar10 = 1;
        if ((int)uVar1 < 0) {
          uVar12 = FUN_0000841a();
        }
        else {
          uVar12 = FUN_000084fe(param_3,param_4,(int)lVar13,uVar8);
        }
        bVar9 = true;
        FUN_00008718();
        if ((bool)uVar10 && !bVar9) {
          FUN_000082cc((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_00009f4c);
          lVar13 = FUN_00008c46();
        }
        else {
          lVar13 = -1;
        }
        for (iVar4 = 0x10; (lVar13 != 0 && (-1 < iVar4)); iVar4 = iVar4 + -1) {
          cVar2 = '\n';
          lVar13 = FUN_000087d4();
          *(char *)(param_2 + iVar4) = cVar2 + '0';
        }
        iVar3 = 0x11 - (iVar4 + 1);
        if (param_6 != 1) break;
        if (lVar13 == 0) {
          iVar5 = (iVar3 - param_5) + -1;
          goto LAB_00009f2c;
        }
        param_5 = 0x11;
        param_6 = 0;
      }
      bVar9 = true;
      if ((lVar13 == 0) && (iVar3 <= (int)param_5)) {
        if (iVar3 < (int)param_5) {
          bVar9 = false;
          iVar5 = iVar5 + -1;
        }
      }
      else {
        bVar9 = false;
        iVar5 = iVar5 + 1;
      }
    } while (!bVar9);
LAB_00009f2c:
    param_1[2] = iVar3;
    param_1[3] = param_6;
    *param_1 = iVar4 + 1 + param_2;
    param_1[1] = iVar5;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00009f50 @ 00009f50 ===== */

int FUN_00009f50(byte *param_1,int **param_2,undefined4 param_3,code *param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char extraout_r1;
  int *piVar6;
  undefined uVar7;
  int **ppiVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  int *piVar14;
  byte *pbVar15;
  int **ppiVar16;
  int *unaff_r10;
  int *piVar17;
  undefined4 *puVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  longlong lVar22;
  undefined4 local_88;
  undefined4 local_84;
  int *local_80;
  char *local_7c;
  int *local_78;
  int *local_74;
  undefined auStack_70 [32];
  int local_50;
  int *local_4c;
  int *piStack_48;
  int local_44;
  byte local_3b [3];
  byte *local_38;
  byte *pbStack_34;
  int **ppiStack_30;
  undefined4 local_2c;
  code *pcStack_28;
  
  pcStack_28 = param_4;
  local_2c = param_3;
  ppiStack_30 = param_2;
  pbStack_34 = param_1;
  iVar12 = 0;
LAB_0000a380:
  uVar4 = (uint)*param_1;
  if (uVar4 == 0) {
    return iVar12;
  }
  if (uVar4 == 0x25) {
    uVar11 = 0;
    piVar14 = (int *)0x0;
    local_74 = (int *)0x0;
    while( true ) {
      pbVar13 = param_1 + 1;
      uVar4 = 1 << (*pbVar13 - 0x20 & 0xff);
      if ((uVar4 & DAT_0000a34c) == 0) break;
      uVar11 = uVar11 | uVar4;
      param_1 = pbVar13;
    }
    if (*pbVar13 == 0x2a) {
      ppiVar8 = param_2 + 1;
      local_74 = *param_2;
      if ((int)local_74 < 0) {
        uVar11 = uVar11 | 0x2000;
        local_74 = (int *)-(int)local_74;
      }
      uVar11 = uVar11 | 2;
      pbVar13 = param_1 + 2;
    }
    else {
      for (; ppiVar8 = param_2, *pbVar13 - 0x30 < 10; pbVar13 = pbVar13 + 1) {
        uVar11 = uVar11 | 2;
        local_74 = (int *)((uint)*pbVar13 + (int)local_74 * 10 + -0x30);
      }
    }
    param_1 = pbVar13;
    ppiVar16 = ppiVar8;
    if (*pbVar13 == 0x2e) {
      param_1 = pbVar13 + 1;
      uVar11 = uVar11 | 4;
      if (*param_1 == 0x2a) {
        ppiVar16 = ppiVar8 + 1;
        piVar14 = *ppiVar8;
        param_1 = pbVar13 + 2;
      }
      else {
        for (; *param_1 - 0x30 < 10; param_1 = param_1 + 1) {
          piVar14 = (int *)((uint)*param_1 + (int)piVar14 * 10 + -0x30);
        }
      }
    }
    bVar1 = *param_1;
    if (bVar1 == 0x6c) {
      uVar11 = uVar11 | 0x100000;
LAB_0000a026:
      if (param_1[1] == bVar1) {
        uVar11 = uVar11 + 0x100000;
        param_1 = param_1 + 1;
      }
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 != 0x4c) {
        if (bVar1 == 0x68) {
          uVar11 = uVar11 | 0x300000;
          goto LAB_0000a026;
        }
        if (bVar1 != 0x6a) goto LAB_0000a034;
        uVar11 = uVar11 | 0x200000;
      }
    }
    else if ((bVar1 != 0x74) && (bVar1 != 0x7a)) goto LAB_0000a034;
    param_1 = param_1 + 1;
LAB_0000a034:
    uVar4 = (uint)*param_1;
    bVar21 = SBORROW4(uVar4,0x66);
    bVar19 = (int)(uVar4 - 0x66) < 0;
    bVar20 = uVar4 == 0x66;
LAB_0000a038:
    while (!bVar20) {
      param_2 = ppiVar16;
      if (!bVar20 && bVar19 == bVar21) {
        if (uVar4 == 0x70) {
          uVar11 = uVar11 | 4;
          piVar14 = (int *)0x8;
          local_88 = (int *)0x10;
        }
        else if (uVar4 < 0x71) {
          if (uVar4 == 0x67) break;
          if (uVar4 == 0x69) goto LAB_0000a152;
          if (uVar4 == 0x6e) {
            uVar4 = (uVar11 << 9) >> 0x1d;
            if (uVar4 == 2) {
              piVar14 = *ppiVar16;
              *piVar14 = iVar12;
              piVar14[1] = iVar12 >> 0x1f;
            }
            else if (uVar4 == 3) {
              *(short *)*ppiVar16 = (short)iVar12;
            }
            else if (uVar4 == 4) {
              *(char *)*ppiVar16 = (char)iVar12;
            }
            else {
              **ppiVar16 = iVar12;
            }
            param_2 = ppiVar16 + 1;
            goto LAB_0000a37e;
          }
          if (uVar4 != 0x6f) goto LAB_0000a088;
          local_88 = (int *)0x8;
        }
        else {
          if (uVar4 == 0x73) {
            unaff_r10 = *ppiVar16;
            iVar5 = -1;
            goto LAB_0000a0e2;
          }
          if (uVar4 == 0x75) {
            local_88 = (int *)0xa;
          }
          else {
            if (uVar4 != 0x78) goto LAB_0000a088;
            local_88 = (int *)0x10;
          }
        }
LAB_0000a1f0:
        uVar10 = (uVar11 << 9) >> 0x1d;
        if (uVar10 == 2) {
          ppiVar8 = (int **)((int)ppiVar16 + 7U & 0xfffffff8);
          param_2 = ppiVar8 + 2;
          piVar17 = *ppiVar8;
          piVar6 = ppiVar8[1];
        }
        else {
          param_2 = ppiVar16 + 1;
          piVar17 = *ppiVar16;
          piVar6 = (int *)0x0;
          if (uVar10 == 3) {
            piVar17 = (int *)((uint)piVar17 & 0xffff);
          }
          if (uVar10 == 4) {
            piVar17 = (int *)((uint)piVar17 & 0xff);
          }
        }
        iVar5 = 0;
        if ((int)(uVar11 << 0x1c) < 0) {
          if (uVar4 == 0x70) {
            local_84 = (char *)CONCAT31(local_84._1_3_,0x40);
            iVar5 = 1;
          }
          else if ((local_88 == (int *)0x10) && (((uint)piVar17 | (uint)piVar6) != 0)) {
            iVar5 = 2;
          }
          if ((local_88 == (int *)0x8) &&
             ((((uint)piVar17 | (uint)piVar6) != 0 || ((int)(uVar11 << 0x1d) < 0)))) {
            local_84 = (char *)CONCAT31(local_84._1_3_,0x30);
            iVar5 = 1;
            piVar14 = (int *)((int)piVar14 + -1);
          }
        }
LAB_0000a27a:
        lVar22 = CONCAT44(piVar6,piVar17);
        if (uVar4 == 0x58) {
          local_7c = "0123456789ABCDEF";
        }
        else {
          local_7c = "0123456789abcdef";
        }
        local_80 = &local_50;
        while( true ) {
          if (lVar22 == 0) break;
          iVar3 = (int)local_88;
          lVar22 = FUN_000087d4((int)lVar22,(int)((ulonglong)lVar22 >> 0x20),local_88,0);
          local_80 = (int *)((int)local_80 + -1);
          *(char *)local_80 = *(char *)((int)local_7c + iVar3);
        }
        piVar6 = (int *)((int)&local_50 - (int)local_80);
        if ((int)(uVar11 << 0x1d) < 0) {
          uVar11 = uVar11 & 0xfffeffff;
        }
        else {
          piVar14 = (int *)0x1;
        }
        if ((int)piVar6 < (int)piVar14) {
          local_88 = (int *)((int)piVar14 - (int)piVar6);
        }
        else {
          local_88 = (int *)0x0;
        }
        local_74 = (int *)((int)local_74 - (int)((int)piVar6 + iVar5 + (int)local_88));
        if (-1 < (int)(uVar11 << 0xf)) {
          iVar3 = FUN_0000a650(local_74,uVar11,local_2c,param_4);
          iVar12 = iVar12 + iVar3;
        }
        for (iVar3 = 0; iVar3 < iVar5; iVar3 = iVar3 + 1) {
          (*param_4)(*(undefined *)((int)&local_84 + iVar3),local_2c);
          iVar12 = iVar12 + 1;
        }
        if ((int)(uVar11 << 0xf) < 0) {
          iVar5 = FUN_0000a650(local_74,uVar11,local_2c,param_4);
          iVar12 = iVar12 + iVar5;
        }
        while (iVar5 = (int)local_88 + -1, bVar20 = 0 < (int)local_88, local_88 = (int *)iVar5,
              bVar20) {
          (*param_4)(0x30,local_2c);
          iVar12 = iVar12 + 1;
        }
        while (unaff_r10 = (int *)((int)piVar6 + -1), piVar14 = local_74, 0 < (int)piVar6) {
          cVar2 = *(char *)local_80;
          local_80 = (int *)((int)local_80 + 1);
          (*param_4)(cVar2,local_2c);
          iVar12 = iVar12 + 1;
          piVar6 = unaff_r10;
        }
        goto LAB_0000a378;
      }
      if (uVar4 == 0x58) {
        local_88 = (int *)0x10;
        goto LAB_0000a1f0;
      }
      if (0x58 < uVar4) {
        if (uVar4 == 99) {
          iVar5 = 1;
          unaff_r10 = &local_88;
LAB_0000a0e2:
          param_2 = ppiVar16 + 1;
          iVar3 = 0;
          if ((int)(uVar11 << 0x1d) < 0) {
            for (; (iVar3 < (int)piVar14 &&
                   ((iVar3 < iVar5 || (*(char *)((int)unaff_r10 + iVar3) != '\0'))));
                iVar3 = iVar3 + 1) {
            }
          }
          else {
            for (; (iVar3 < iVar5 || (*(char *)((int)unaff_r10 + iVar3) != '\0')); iVar3 = iVar3 + 1
                ) {
            }
          }
          piVar14 = (int *)((int)local_74 - iVar3);
          iVar5 = FUN_0000a650(piVar14,uVar11,local_2c,param_4);
          iVar12 = iVar5 + iVar12 + iVar3;
          while (bVar20 = iVar3 != 0, iVar3 = iVar3 + -1, bVar20) {
            (*param_4)(*(char *)unaff_r10,local_2c);
            unaff_r10 = (int *)((int)unaff_r10 + 1);
          }
          goto LAB_0000a378;
        }
        if (uVar4 == 100) {
LAB_0000a152:
          local_88 = (int *)0xa;
          uVar10 = (uVar11 << 9) >> 0x1d;
          if (uVar10 == 2) {
            ppiVar8 = (int **)((int)ppiVar16 + 7U & 0xfffffff8);
            param_2 = ppiVar8 + 2;
            piVar17 = *ppiVar8;
            piVar6 = ppiVar8[1];
          }
          else {
            param_2 = ppiVar16 + 1;
            piVar17 = *ppiVar16;
            if (uVar10 == 3) {
              piVar17 = (int *)(int)(short)piVar17;
            }
            piVar6 = (int *)((int)piVar17 >> 0x1f);
            if (uVar10 == 4) {
              piVar17 = (int *)(int)(char)piVar17;
              piVar6 = (int *)((int)piVar17 >> 0x1f);
            }
          }
          if ((int)piVar6 < 0) {
            bVar20 = piVar17 != (int *)0x0;
            piVar17 = (int *)-(int)piVar17;
            piVar6 = (int *)(-(uint)bVar20 - (int)piVar6);
            uVar7 = 0x2d;
LAB_0000a1b2:
            local_84 = (char *)CONCAT31(local_84._1_3_,uVar7);
            iVar5 = 1;
          }
          else {
            if ((int)(uVar11 << 0x14) < 0) {
              uVar7 = 0x2b;
              goto LAB_0000a1b2;
            }
            iVar5 = uVar11 << 0x1f;
            if (iVar5 != 0) {
              uVar7 = 0x20;
              goto LAB_0000a1b2;
            }
          }
          goto LAB_0000a27a;
        }
        if (uVar4 != 0x65) goto LAB_0000a088;
        break;
      }
      if (uVar4 == 0) {
        return iVar12;
      }
      bVar21 = SBORROW4(uVar4,0x45);
      bVar19 = (int)(uVar4 - 0x45) < 0;
      bVar20 = uVar4 == 0x45;
      if (!bVar20) goto code_r0x0000a04a;
    }
    goto LAB_0000a390;
  }
  goto LAB_0000a088;
code_r0x0000a04a:
  bVar21 = SBORROW4(uVar4,0x46);
  bVar19 = (int)(uVar4 - 0x46) < 0;
  bVar20 = uVar4 == 0x46;
  if (!bVar20) goto code_r0x0000a04e;
  goto LAB_0000a038;
code_r0x0000a04e:
  if (uVar4 != 0x47) {
LAB_0000a088:
    (*param_4)(uVar4,local_2c);
    iVar12 = iVar12 + 1;
    goto LAB_0000a37e;
  }
LAB_0000a390:
  if (-1 < (int)(uVar11 << 0x1d)) {
    piVar14 = (int *)0x6;
  }
  puVar18 = (undefined4 *)((int)ppiVar16 + 7U & 0xfffffff8);
  param_2 = (int **)(puVar18 + 2);
  uVar9 = *puVar18;
  if ((puVar18[1] & 0x80000000) == 0) {
    if ((int)(uVar11 << 0x14) < 0) {
      local_38 = &DAT_0000a624;
    }
    else if ((uVar11 & 1) == 0) {
      local_38 = (byte *)0xa360;
    }
    else {
      local_38 = &DAT_0000a628;
    }
  }
  else {
    local_38 = &DAT_0000a620;
  }
  uVar10 = puVar18[1] & 0x7fffffff;
  if (uVar4 == 0x65) {
LAB_0000a3fa:
    if ((int)piVar14 < 0x11) {
      local_88 = (int *)((int)piVar14 + 1);
    }
    else {
      local_88 = (int *)0x11;
    }
    local_84 = (char *)0x0;
    FUN_00009dec(&local_50,auStack_70,uVar9,uVar10);
    local_7c = (char *)piStack_48;
    local_88 = (int *)local_50;
    unaff_r10 = (int *)((int)piVar14 + 1);
    local_78 = (int *)0x0;
LAB_0000a4c2:
    local_78 = (int *)0x0;
    local_84 = (char *)0x1;
    local_80 = local_4c;
    local_88 = (int *)local_50;
    local_7c = (char *)piStack_48;
  }
  else if (uVar4 < 0x66) {
    if (uVar4 == 0x45) goto LAB_0000a3fa;
    if (uVar4 == 0x46) goto LAB_0000a426;
    if (uVar4 == 0x47) goto LAB_0000a46c;
  }
  else if (uVar4 == 0x66) {
LAB_0000a426:
    local_84 = (char *)0x1;
    local_80 = (int *)0x80000000;
    local_88 = piVar14;
    FUN_00009dec(&local_50,auStack_70,uVar9,uVar10);
    local_7c = (char *)piStack_48;
    local_88 = (int *)local_50;
    local_78 = (int *)0x0;
    unaff_r10 = piStack_48;
    if (local_44 == 0) {
      unaff_r10 = (int *)((int)local_4c + (int)((int)piVar14 + 1));
    }
    iVar5 = (int)piVar14 - (int)unaff_r10;
    if (-1 < iVar5) {
      unaff_r10 = (int *)((int)piVar14 + 1);
      local_78 = (int *)(-1 - iVar5);
    }
    local_84 = (char *)((int)unaff_r10 - (int)piVar14);
  }
  else {
    if (uVar4 != 0x67) goto LAB_0000a4f6;
LAB_0000a46c:
    if ((int)piVar14 < 1) {
      piVar14 = (int *)0x1;
    }
    local_88 = piVar14;
    if (0x11 < (int)piVar14) {
      local_88 = (int *)0x11;
    }
    local_84 = (char *)0x0;
    FUN_00009dec(&local_50,auStack_70,uVar9,uVar10);
    local_7c = (char *)piStack_48;
    local_78 = (int *)0x0;
    local_88 = (int *)local_50;
    unaff_r10 = piVar14;
    if (-1 < (int)(uVar11 << 0x1c)) {
      piVar6 = piStack_48;
      if ((int)piVar14 <= (int)piStack_48) goto LAB_0000a4a6;
      while( true ) {
        unaff_r10 = piVar6;
LAB_0000a4a6:
        if (((int)unaff_r10 < 2) || (*(char *)((int)unaff_r10 + local_50 + -1) != '0')) break;
        piVar6 = (int *)((int)unaff_r10 + -1);
      }
    }
    if (((int)piVar14 <= (int)local_4c) || ((int)(local_4c + 1) < 0 != SCARRY4((int)local_4c,4)))
    goto LAB_0000a4c2;
    if ((int)local_4c < 1) {
      local_78 = local_4c;
      piVar14 = (int *)((int)unaff_r10 - (int)local_4c);
LAB_0000a4e6:
      unaff_r10 = piVar14;
    }
    else {
      piVar14 = (int *)((int)local_4c + 1);
      if ((int)unaff_r10 < (int)piVar14) goto LAB_0000a4e6;
    }
    local_84 = (char *)((int)local_4c + (1 - (int)local_78));
    local_80 = (int *)0x80000000;
  }
LAB_0000a4f6:
  if ((-1 < (int)(uVar11 << 0x1c)) && ((int)unaff_r10 <= (int)local_84)) {
    local_84 = (char *)0xffffffff;
  }
  local_3b[2] = 0;
  pbVar13 = local_3b + 2;
  if (local_80 != (int *)0x80000000) {
    local_50 = 0x2b;
    iVar5 = 2;
    if ((int)local_80 < 0) {
      local_80 = (int *)-(int)local_80;
      local_50 = 0x2d;
    }
    while ((0 < iVar5 || (local_80 != (int *)0x0))) {
      local_80 = (int *)FUN_000087a8(local_80,10);
      pbVar13 = pbVar13 + -1;
      *pbVar13 = extraout_r1 + 0x30;
      iVar5 = iVar5 + -1;
    }
    pbVar13[-1] = (byte)local_50;
    pbVar13 = pbVar13 + -2;
    *pbVar13 = *param_1 & 0x20 | 0x45;
  }
  pbVar15 = local_3b + (2 - (int)pbVar13);
  uVar4 = (uint)*local_38;
  if (uVar4 != 0) {
    uVar4 = 1;
  }
  local_74 = (int *)((int)local_74 +
                    (-1 - (int)((int)unaff_r10 + (int)(pbVar15 + ((int)local_84 >> 0x1f) + uVar4))))
  ;
  if (-1 < (int)(uVar11 << 0xf)) {
    iVar5 = FUN_0000a650(local_74,uVar11,local_2c,param_4);
    iVar12 = iVar12 + iVar5;
  }
  if (*local_38 != 0) {
    (*param_4)(*local_38,local_2c);
    iVar12 = iVar12 + 1;
  }
  iVar5 = iVar12;
  piVar14 = unaff_r10;
  if ((int)(uVar11 << 0xf) < 0) {
    iVar5 = FUN_0000a650(local_74,uVar11,local_2c,param_4);
    iVar5 = iVar12 + iVar5;
  }
  while (iVar12 = iVar5, unaff_r10 = (int *)((int)piVar14 + -1), 0 < (int)piVar14) {
    if (((int)local_78 < 0) || ((int)local_7c <= (int)local_78)) {
      cVar2 = '0';
    }
    else {
      cVar2 = *(char *)((int)local_88 + (int)local_78);
    }
    (*param_4)(cVar2,local_2c);
    local_78 = (int *)((int)local_78 + 1);
    local_84 = local_84 + -1;
    iVar5 = iVar12 + 1;
    piVar14 = unaff_r10;
    if (local_84 == (char *)0x0) {
      (*param_4)(0x2e,local_2c);
      iVar5 = iVar12 + 2;
    }
  }
  while (piVar14 = local_74, 0 < (int)pbVar15) {
    (*param_4)(*pbVar13,local_2c);
    iVar12 = iVar12 + 1;
    pbVar13 = pbVar13 + 1;
    pbVar15 = pbVar15 + -1;
  }
LAB_0000a378:
  iVar5 = FUN_0000a62c(piVar14,uVar11,local_2c,param_4);
  iVar12 = iVar12 + iVar5;
LAB_0000a37e:
  param_1 = param_1 + 1;
  goto LAB_0000a380;
}


/* ===== FUN_0000a62c @ 0000a62c ===== */

int FUN_0000a62c(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_2 << 0x12 < 0) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(0x20,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


/* ===== FUN_0000a650 @ 0000a650 ===== */

int FUN_0000a650(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if (param_2 << 0xf < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if (-1 < param_2 << 0x12) {
    while (param_1 = param_1 + -1, -1 < param_1) {
      (*param_4)(uVar2,param_3);
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}


/* ===== FUN_0000a67e @ 0000a67e ===== */

void FUN_0000a67e(undefined param_1,undefined4 *param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)*param_2;
  *param_2 = puVar1 + 1;
  *puVar1 = param_1;
  return;
}


/* ===== FUN_0000a688 @ 0000a688 ===== */

void FUN_0000a688(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 + param_1 * param_2 * -2 < 0 != SBORROW4(iVar1,param_1 * param_2 * 2);
      iVar1 = iVar1 + 2) {
    iVar4 = (int)*(short *)(param_3 + iVar1 * 2);
    iVar3 = (int)*(short *)(param_3 + iVar1 * 2 + 2);
    *(int *)(param_4 + iVar2 * 4) = iVar3 * iVar3 + iVar4 * iVar4;
    iVar2 = iVar2 + 1;
  }
  return;
}


/* ===== FUN_0000a6bc @ 0000a6bc ===== */

void FUN_0000a6bc(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_0000ad34(2,0x20,0x22,DAT_0000a758 + -4,DAT_0000a75c,DAT_0000a758,DAT_0000a754);
  uVar3 = 0;
  uVar4 = 0;
  for (uVar2 = 0; uVar2 < 0x800; uVar2 = uVar2 + 2) {
    uVar1 = FUN_000085dc((int)(uint)*(ushort *)(DAT_0000a760 + uVar2 * 2) >> 4);
    uVar3 = FUN_0000813c(uVar3,uVar1);
    uVar1 = FUN_000085dc((int)(uint)*(ushort *)(DAT_0000a760 + (uVar2 + 1) * 2) >> 4);
    uVar4 = FUN_0000813c(uVar4,uVar1);
  }
  uVar3 = FUN_00008250(uVar3,0x44800000);
  uVar4 = FUN_00008250(uVar4,0x44800000);
  *param_1 = uVar3;
  param_1[1] = uVar4;
  return;
}


/* ===== FUN_0000a764 @ 0000a764 ===== */

undefined4 FUN_0000a764(uint param_1)

{
  if ((param_1 & 0x100) == 0x100) {
    if ((param_1 & 0xf) == 0xf) {
      return 0;
    }
    FUN_0000a7ac();
  }
  else if ((param_1 & 0xf) == 0) {
    FUN_00010938();
  }
  else {
    FUN_0000a798();
  }
  return 1;
}


/* ===== FUN_0000a798 @ 0000a798 ===== */

void FUN_0000a798(void)

{
  *DAT_0000a7a8 = *DAT_0000a7a8 + -1;
  return;
}


/* ===== FUN_0000a7ac @ 0000a7ac ===== */

void FUN_0000a7ac(void)

{
  *DAT_0000a7bc = *DAT_0000a7bc + 1;
  return;
}


/* ===== FUN_0000a7c0 @ 0000a7c0 ===== */

undefined4 FUN_0000a7c0(uint param_1)

{
  if ((param_1 & 0x100) == 0x100) {
    if ((param_1 & 0xf) == 0) {
      FUN_00010950();
    }
    else {
      FUN_0000a798();
    }
  }
  else {
    if ((param_1 & 0xf) == 0xf) {
      return 0;
    }
    FUN_0000a7ac();
  }
  return 1;
}


/* ===== FUN_0000a7f4 @ 0000a7f4 ===== */

undefined4 FUN_0000a7f4(uint param_1)

{
  if ((param_1 & 0x200) == 0x200) {
    if ((param_1 & 0xf0) == 0xf0) {
      return 0;
    }
    FUN_0000a83c();
  }
  else if ((param_1 & 0xf0) == 0) {
    FUN_00010988();
  }
  else {
    FUN_0000a828();
  }
  return 1;
}


/* ===== FUN_0000a828 @ 0000a828 ===== */

void FUN_0000a828(void)

{
  *DAT_0000a838 = *DAT_0000a838 + -0x10;
  return;
}


/* ===== FUN_0000a83c @ 0000a83c ===== */

void FUN_0000a83c(void)

{
  *DAT_0000a84c = *DAT_0000a84c + 0x10;
  return;
}


/* ===== FUN_0000a850 @ 0000a850 ===== */

undefined4 FUN_0000a850(uint param_1)

{
  if ((param_1 & 0x200) == 0x200) {
    if ((param_1 & 0xf0) == 0) {
      FUN_000109a0();
    }
    else {
      FUN_0000a828();
    }
  }
  else {
    if ((param_1 & 0xf0) == 0xf0) {
      return 0;
    }
    FUN_0000a83c();
  }
  return 1;
}


/* ===== FUN_0000a884 @ 0000a884 ===== */

void FUN_0000a884(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_0000ad34(2,0x20,0x22,DAT_0000a920 + -4,DAT_0000a924,DAT_0000a920,DAT_0000a91c);
  uVar3 = 0;
  uVar4 = 0;
  for (uVar2 = 0; uVar2 < 0x800; uVar2 = uVar2 + 2) {
    uVar1 = FUN_000085dc((int)(uint)*(ushort *)(DAT_0000a928 + uVar2 * 2) >> 4);
    uVar3 = FUN_0000813c(uVar3,uVar1);
    uVar1 = FUN_000085dc((int)(uint)*(ushort *)(DAT_0000a928 + (uVar2 + 1) * 2) >> 4);
    uVar4 = FUN_0000813c(uVar4,uVar1);
  }
  uVar3 = FUN_00008250(uVar3,0x44800000);
  uVar4 = FUN_00008250(uVar4,0x44800000);
  *param_1 = uVar3;
  param_1[1] = uVar4;
  return;
}


/* ===== FUN_0000a92c @ 0000a92c ===== */

undefined4 FUN_0000a92c(uint param_1)

{
  if ((param_1 & 0x100) == 0x100) {
    if ((param_1 & 0xf) == 0xf) {
      return 0;
    }
    FUN_0000a974();
  }
  else if ((param_1 & 0xf) == 0) {
    FUN_000109c4();
  }
  else {
    FUN_0000a960();
  }
  return 1;
}


/* ===== FUN_0000a960 @ 0000a960 ===== */

void FUN_0000a960(void)

{
  *DAT_0000a970 = *DAT_0000a970 + -1;
  return;
}


/* ===== FUN_0000a974 @ 0000a974 ===== */

void FUN_0000a974(void)

{
  *DAT_0000a984 = *DAT_0000a984 + 1;
  return;
}


/* ===== FUN_0000a988 @ 0000a988 ===== */

undefined4 FUN_0000a988(uint param_1)

{
  if ((param_1 & 0x100) == 0x100) {
    if ((param_1 & 0xf) == 0) {
      FUN_000109dc();
    }
    else {
      FUN_0000a960();
    }
  }
  else {
    if ((param_1 & 0xf) == 0xf) {
      return 0;
    }
    FUN_0000a974();
  }
  return 1;
}


/* ===== FUN_0000a9bc @ 0000a9bc ===== */

undefined4 FUN_0000a9bc(uint param_1)

{
  if ((param_1 & 0x200) == 0x200) {
    if ((param_1 & 0xf0) == 0xf0) {
      return 0;
    }
    FUN_0000aa04();
  }
  else if ((param_1 & 0xf0) == 0) {
    FUN_00010a14();
  }
  else {
    FUN_0000a9f0();
  }
  return 1;
}


/* ===== FUN_0000a9f0 @ 0000a9f0 ===== */

void FUN_0000a9f0(void)

{
  *DAT_0000aa00 = *DAT_0000aa00 + -0x10;
  return;
}


/* ===== FUN_0000aa04 @ 0000aa04 ===== */

void FUN_0000aa04(void)

{
  *DAT_0000aa14 = *DAT_0000aa14 + 0x10;
  return;
}


/* ===== FUN_0000aa18 @ 0000aa18 ===== */

undefined4 FUN_0000aa18(uint param_1)

{
  if ((param_1 & 0x200) == 0x200) {
    if ((param_1 & 0xf0) == 0) {
      FUN_00010a2c();
    }
    else {
      FUN_0000a9f0();
    }
  }
  else {
    if ((param_1 & 0xf0) == 0xf0) {
      return 0;
    }
    FUN_0000aa04();
  }
  return 1;
}


/* ===== FUN_0000aa4c @ 0000aa4c ===== */

void FUN_0000aa4c(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11,int param_12)

{
  int iVar1;
  
  iVar1 = DAT_0000aac4;
  *(uint *)(DAT_0000aac4 + 300) =
       (((*(uint *)(DAT_0000aac4 + 300) & 0xfff0ffff | param_1 << 0x10) & 0xff0fffff |
        param_2 << 0x14) & 0xf0ffffff | param_3 << 0x18) & 0xfffffff | param_4 << 0x1c;
  *(uint *)(iVar1 + 0x130) =
       ((*(uint *)(iVar1 + 0x130) | param_5 | param_7 << 4 | param_8 << 8 | param_9 << 0xc |
         param_10 << 0x10 | param_11 << 0x14) & 0xf0ffffff | param_6 << 0x18) & 0xfffffff |
       param_12 << 0x1c;
  return;
}


/* ===== FUN_0000aac8 @ 0000aac8 ===== */

uint FUN_0000aac8(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  FUN_0000ab30();
  iVar2 = 0;
  iVar3 = 0;
  uVar1 = 0;
  do {
    if (iVar2 == 0) {
      iVar2 = FUN_000100b4();
      if (iVar2 < 0xf) {
        FUN_00010968();
        iVar2 = FUN_00008cfc();
      }
      else {
        uVar1 = uVar1 & 2;
        iVar2 = 2;
      }
    }
    else {
      uVar1 = uVar1 | 1;
      iVar2 = 2;
    }
    if (iVar3 == 0) {
      iVar3 = FUN_000100d0();
      if (iVar3 < 0xf) {
        FUN_000109f4();
        iVar3 = FUN_00008dd8();
      }
      else {
        uVar1 = uVar1 & 1;
        iVar3 = 2;
      }
    }
    else {
      uVar1 = uVar1 | 2;
      iVar3 = 2;
    }
  } while ((iVar2 != 2) || (iVar3 != 2));
  return uVar1;
}


/* ===== FUN_0000ab30 @ 0000ab30 ===== */

void FUN_0000ab30(void)

{
  FUN_0001162c(0);
  FUN_00010774(0);
  FUN_0000ed30(0);
  FUN_0000ae50(0,1,0x20);
  FUN_0000ab9c(1);
  FUN_0000f27c();
  FUN_0000ab64();
  return;
}


/* ===== FUN_0000ab64 @ 0000ab64 ===== */

void FUN_0000ab64(void)

{
  int iVar1;
  
  iVar1 = DAT_0000ab8c;
  *(undefined4 *)(DAT_0000ab8c + 0x24) = 0x1f;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *DAT_0000ab90 = 0x38;
  *(undefined4 *)(DAT_0000ab94 + 0x274) = 0x60;
  *(undefined4 *)(DAT_0000ab8c + 0x4c) = 0;
  *DAT_0000ab98 = 0x15;
  return;
}


/* ===== FUN_0000ab9c @ 0000ab9c ===== */

void FUN_0000ab9c(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0000abf0;
  *(undefined4 *)(DAT_0000abf0 + 0x68) = 0;
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(DAT_0000abf0 + 0x80) = 0;
  *(undefined4 *)(DAT_0000abf0 + 0x84) = 0;
  iVar1 = DAT_0000abf0;
  *(undefined4 *)(DAT_0000abf0 + 0x88) = 0;
  *(undefined4 *)(iVar1 + 0x8c) = 0;
  *(undefined4 *)(iVar1 + 0x90) = 0;
  *(undefined4 *)(iVar1 + 0x94) = 0;
  *(undefined4 *)(iVar1 + 0x98) = 0;
  *(undefined4 *)(iVar1 + 0x9c) = 0;
  *(undefined4 *)(iVar1 + 0xa0) = 0;
  *(undefined4 *)(DAT_0000abf0 + 0xa4) = 0;
  *(int *)(DAT_0000abf0 + 0xa8) = param_1 * 0x2000 + 0xfff;
  return;
}


/* ===== FUN_0000abf4 @ 0000abf4 ===== */

void FUN_0000abf4(int param_1)

{
  if (param_1 == 0) {
    *(uint *)(DAT_0000ac0c + 0x274) = *DAT_0000ac08 | 0x20;
  }
  return;
}


/* ===== FUN_0000ac10 @ 0000ac10 ===== */

void FUN_0000ac10(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x30000;
  }
  *DAT_0000ac54 = uVar2;
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x30000;
  }
  DAT_0000ac54[6] = uVar2;
  puVar1 = DAT_0000ac54;
  DAT_0000ac54[0x65] = 0x20;
  puVar1[0x66] = *DAT_0000ac58 & 3 | 0x78;
  return;
}


/* ===== FUN_0000ac5c @ 0000ac5c ===== */

void FUN_0000ac5c(int param_1,int param_2)

{
  uint *puVar1;
  
  *DAT_0000acf0 = param_2 << 0xd | param_1 << 0x11 | DAT_0000acec[0x10];
  puVar1 = DAT_0000acf0;
  DAT_0000acf0[-0x10] = *DAT_0000acec;
  puVar1[-0xf] = DAT_0000acec[1];
  puVar1[-0xe] = DAT_0000acec[2];
  puVar1[-0xd] = DAT_0000acec[3];
  puVar1[-0xc] = DAT_0000acec[4];
  puVar1[-0xb] = DAT_0000acec[5];
  puVar1[-10] = DAT_0000acec[6];
  puVar1[-9] = DAT_0000acec[7];
  puVar1[-8] = DAT_0000acec[8];
  puVar1[-7] = DAT_0000acec[9];
  puVar1[-6] = DAT_0000acec[10];
  puVar1[-5] = DAT_0000acec[0xb];
  puVar1[-4] = DAT_0000acec[0xc];
  puVar1[-3] = DAT_0000acec[0xd];
  puVar1[-2] = DAT_0000acec[0xe];
  DAT_0000acf0[-1] = DAT_0000acec[0xf];
  return;
}


/* ===== FUN_0000acf4 @ 0000acf4 ===== */

void FUN_0000acf4(void)

{
  *(undefined4 *)(DAT_0000acfc + 0x48) = 1;
  return;
}


/* ===== FUN_0000ad00 @ 0000ad00 ===== */

void FUN_0000ad00(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *(uint *)(DAT_0000ad30 + 0x24) | 3;
  }
  else {
    uVar1 = *(uint *)(DAT_0000ad30 + 0x24) & 0xfffffffc;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 0xc;
  }
  else {
    uVar1 = uVar1 & 0xfffffff3;
  }
  *(uint *)(DAT_0000ad30 + 0x24) = uVar1;
  *(undefined4 *)(DAT_0000ad30 + 0x30) = 0x60;
  return;
}


/* ===== FUN_0000ad34 @ 0000ad34 ===== */

undefined8
FUN_0000ad34(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = param_3 * param_2 & 0xffff;
    param_1 = 4;
    FUN_0000d084(1,param_4,param_5,0,4,uVar1,0xc,0);
    FUN_0000acf4();
    do {
    } while (*(uint *)(DAT_0000ae4c + 0x28) <= param_3 * param_2 &&
             param_3 * param_2 - *(uint *)(DAT_0000ae4c + 0x28) != 0);
    FUN_0000d1e0(1);
  }
  else if (param_1 == 1) {
    uVar1 = param_3 * param_2 & 0xffff;
    param_1 = 4;
    FUN_0000d084(2,param_6,param_7,0,4,uVar1,0xd,0);
    FUN_0000acf4();
    do {
    } while (*(uint *)(DAT_0000ae4c + 0x38) <= param_3 * param_2 &&
             param_3 * param_2 - *(uint *)(DAT_0000ae4c + 0x38) != 0);
    FUN_0000d1e0(2);
  }
  else {
    uVar1 = param_2;
    if (param_1 == 2) {
      FUN_0000d084(1,param_4,param_5,0,4,param_3 * param_2 & 0xffff,0xc,0);
      uVar1 = param_3 * param_2 & 0xffff;
      param_1 = 4;
      FUN_0000d084(2,param_6,param_7,0,4,uVar1,0xd,0);
      FUN_0000acf4();
      do {
        do {
        } while (*(uint *)(DAT_0000ae4c + 0x28) <= param_3 * param_2 &&
                 param_3 * param_2 - *(uint *)(DAT_0000ae4c + 0x28) != 0);
      } while (*(uint *)(DAT_0000ae4c + 0x38) <= param_3 * param_2 &&
               param_3 * param_2 - *(uint *)(DAT_0000ae4c + 0x38) != 0);
      FUN_0000d1e0(1);
      FUN_0000d1e0(2);
    }
  }
  FUN_0000c974(0xc,0);
  return CONCAT44(uVar1,param_1);
}


/* ===== FUN_0000ae50 @ 0000ae50 ===== */

void FUN_0000ae50(uint param_1,int param_2,int param_3)

{
  *(uint *)(DAT_0000ae64 + 0x34) = param_3 << 2 | param_2 << 1 | 0x1000U | param_1;
  return;
}


/* ===== FUN_0000ae68 @ 0000ae68 ===== */

void FUN_0000ae68(int param_1)

{
  *DAT_0000ae78 = *(undefined4 *)(param_1 + 0x10);
  *DAT_0000ae7c = *(undefined4 *)(param_1 + 0x14);
  return;
}


/* ===== FUN_0000ae80 @ 0000ae80 ===== */

void FUN_0000ae80(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  iVar1 = param_1 * 7;
  iVar2 = param_2 * 7;
  FUN_0000ac10(param_1,param_2);
  FUN_0000aa4c(iVar1,iVar1,iVar1,param_1 << 3,param_1 << 3,8,iVar2,iVar2,iVar2,param_2 << 3,
               param_2 << 3,0xc);
  FUN_0000abf4(param_4);
  FUN_0000ad00(param_1,param_2);
  FUN_0000ae50(param_3,1,0x100);
  FUN_0000ac5c(0,1);
  FUN_0000c5f4(DAT_0000af34,DAT_0000af38);
  uVar3 = FUN_0000868e();
  FUN_0000d9a0(0,DAT_0000af3c);
  uVar4 = FUN_0000868e();
  FUN_0000c94c(uVar4,uVar3,0x100,1,param_5);
  return;
}


/* ===== FUN_0000af40 @ 0000af40 ===== */

void FUN_0000af40(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar1 = *param_1;
  bVar2 = param_1[1];
  bVar3 = *param_1;
  bVar4 = param_1[1];
  FUN_0001162c(param_1[2],param_1[3]);
  FUN_00011604(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
  FUN_00010774(*param_1,param_1[1]);
  FUN_0000ed30(*param_1,param_1[1]);
  FUN_0000e414(*param_1,param_1[1]);
  FUN_0000e3ec((uint)bVar3 * 0xf,(uint)bVar4 * 0xf);
  FUN_0000bcc0(1);
  FUN_00010368(*param_1,param_1[1]);
  FUN_000103bc(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0x10));
  FUN_00010340((uint)bVar1 << 3,(uint)bVar2 << 3);
  FUN_0001042c(*param_1,param_1[1]);
  FUN_00010480(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0xc),
               *(undefined4 *)(param_1 + 0x14));
  FUN_00010404((uint)bVar1 << 3,(uint)bVar2 << 3);
  FUN_00010228(0,0,0);
  FUN_00010274(2,2,2);
  FUN_000111a4(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x24));
  FUN_00010054(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x1c),
               *(undefined4 *)(param_1 + 0x28));
  FUN_0000f238(*(undefined4 *)(param_1 + 0x30));
  FUN_0000f1bc(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x20),
               *(undefined4 *)(param_1 + 0x2c));
  FUN_00010304(*(undefined4 *)(param_1 + 0x3c));
  *DAT_0000b028 = 0x16;
  DAT_0000b028[1] = 0x16;
  return;
}


/* ===== FUN_0000b02c @ 0000b02c ===== */

void FUN_0000b02c(void)

{
  do {
  } while (*DAT_0000b054 == 0);
  *DAT_0000b054 = 0;
  FUN_000108c0(DAT_0000b058);
  FUN_0000ae68(DAT_0000b058);
  FUN_0000fc9c();
  FUN_0000f6bc();
  return;
}


/* ===== FUN_0000b05c @ 0000b05c ===== */

void FUN_0000b05c(undefined4 param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined auStack_2c [24];
  
  FUN_0000e96e(1);
  uStack_44 = *(undefined4 *)(param_2 + 0x28);
  local_40 = *(undefined4 *)(param_2 + 0x2c);
  FUN_0000e858(*param_2,param_2[1],param_2[2],param_2[3],*(undefined4 *)(param_2 + 0x24));
  uVar1 = FUN_0000aac8();
  FUN_0001010c(&uStack_44,uVar1);
  FUN_000080f4(auStack_2c,&uStack_44,0x18);
  FUN_000099c4(0xa1a,auStack_2c,0x18);
  FUN_00010188();
  FUN_0000b164();
  FUN_00010c6c(0);
  FUN_000080f4(param_1,auStack_2c,0x18);
  return;
}


/* ===== FUN_0000b0c4 @ 0000b0c4 ===== */

void FUN_0000b0c4(void)

{
  FUN_00010c50(1,0);
  FUN_0000e184(10,2);
  FUN_0000e184(0xb,2);
  FUN_0000e1fc(3,0);
  FUN_0000e1fc(4,1);
  FUN_0000e184(5,2);
  FUN_0000e1fc(6,0);
  FUN_0000e184(0x17,2);
  FUN_0000e184(0x18,2);
  FUN_0000e184(0x19,2);
  FUN_0000e184(0x1a,2);
  FUN_0000e184(0x1b,2);
  FUN_0000e184(0x1c,2);
  FUN_0000e184(0x1d,2);
  FUN_0000e184(0x1e,2);
  FUN_0000ec7c(1);
  FUN_000105b8(1,1000,0x20,0);
  FUN_0000ffcc();
  *DAT_0000b160 = 8;
  return;
}


/* ===== FUN_0000b164 @ 0000b164 ===== */

void FUN_0000b164(void)

{
  FUN_0000b20c(1);
  FUN_0000b0c4();
  FUN_0000e368();
  FUN_0000e358();
  FUN_0000b2e8(DAT_0000b204,0x42);
  FUN_0000af40(DAT_0000b204);
  FUN_0000ae80(*DAT_0000b204,DAT_0000b204[1],1,0,0x42);
  FUN_00011120();
  FUN_000116a8(&DAT_40004000,0x1c200,0);
  FUN_000116a8(&DAT_40004000,0x1c200,0);
  FUN_00011288(DAT_0000b208 << 0x12,DAT_0000b208,0);
  FUN_0000e184(9,0);
  FUN_0000e184(2,0);
  FUN_0000e348();
  FUN_0000c6d0();
  FUN_0000e96e(1,0);
  FUN_0000e858(0,0,0,0,*(undefined4 *)(DAT_0000b204 + 0x24),*(undefined4 *)(DAT_0000b204 + 0x28),
               *(undefined4 *)(DAT_0000b204 + 0x2c));
  return;
}


/* ===== FUN_0000b20c @ 0000b20c ===== */

void FUN_0000b20c(int param_1)

{
  *DAT_0000b2c4 = 1;
  if (param_1 == 1) {
    FUN_0000bcec(1,0,0);
    FUN_0000c974(0x32,0);
    FUN_0000bcec(1,0);
    FUN_0000c974(0x32,0);
    FUN_0000f7b8(1);
    FUN_0000c974(0x32,0);
    FUN_0000fb2c(1,0);
    FUN_0000c974(0x32,0);
    FUN_0000fad8(1,3);
    FUN_0000c974(0x32,0);
    FUN_0000c918(1,0);
    FUN_0000c974(0x32,0);
    FUN_0000e1d4(0x16,1);
    FUN_0000e184(0x16,0);
  }
  else {
    FUN_0000f7b8(0,1);
    FUN_0000fb2c(0);
    FUN_0000fad8(0,3);
    FUN_0000bcec(0,0,0);
    FUN_0000c918(0,1);
  }
  return;
}


/* ===== FUN_0000b2c8 @ 0000b2c8 ===== */

void FUN_0000b2c8(void)

{
  FUN_00010828(DAT_0000b2e4);
  FUN_0000ae68(DAT_0000b2e4);
  FUN_0000fc0c();
  FUN_0000f0d8();
  FUN_0000be04();
  return;
}


/* ===== FUN_0000b2e8 @ 0000b2e8 ===== */

undefined8 FUN_0000b2e8(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0000f798();
  FUN_0000f75c(1);
  FUN_0000f820(DAT_0000b378,4000,param_2);
  FUN_0000da7c(DAT_0000b378,4000,0x60,0xc,0,param_2,param_3,param_4);
  *DAT_0000b37c = 1;
  FUN_0000debc(0);
  FUN_000104c8(*param_1 | param_1[1] | param_1[2] | param_1[3],
               *param_1 | param_1[1] | param_1[2] | param_1[3]);
  FUN_000115e4(param_1[4]);
  FUN_000101a4(1,param_1[2],param_1[3],*param_1,param_1[1]);
  uVar1 = 8;
  uVar2 = 10;
  FUN_0000bd3c(8,8,8);
  return CONCAT44(uVar2,uVar1);
}


/* ===== FUN_0000b380 @ 0000b380 ===== */

void FUN_0000b380(void)

{
  FUN_00010c50(1,0);
  FUN_00010c50(0,1);
  FUN_00010c50(3,1);
  FUN_00010c50(4,1);
  FUN_00010c50(0x14,1);
  FUN_00010c50(5,1);
  FUN_00010c50(0xd,1);
  FUN_00010c50(7,1);
  FUN_00010c50(10,1);
  return;
}


/* ===== FUN_0000b3cc @ 0000b3cc ===== */

void FUN_0000b3cc(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_0000b40c;
  *DAT_0000b40c = 1;
  puVar1[1] = 1;
  puVar1[2] = 1;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(undefined4 *)(puVar1 + 0x34) = 0xe;
  *(undefined4 *)(puVar1 + 0x38) = 0;
  *(undefined4 *)(puVar1 + 0x18) = 0;
  *(undefined4 *)(puVar1 + 0x1c) = 1;
  *(undefined4 *)(puVar1 + 0x20) = 1;
  *(undefined4 *)(puVar1 + 8) = 1;
  *(undefined4 *)(puVar1 + 0xc) = 0xf;
  *(undefined4 *)(puVar1 + 0x10) = 1;
  *(undefined4 *)(puVar1 + 0x14) = 0xf;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *(undefined4 *)(puVar1 + 0x28) = 0x96;
  *(undefined4 *)(puVar1 + 0x2c) = 2;
  *(undefined4 *)(puVar1 + 0x30) = 1;
  return;
}


/* ===== FUN_0000b410 @ 0000b410 ===== */

void FUN_0000b410(ushort param_1,int param_2,uint *param_3,uint *param_4)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_80;
  undefined4 local_78;
  uint local_74;
  undefined8 local_70;
  undefined4 local_68;
  uint local_64;
  undefined8 local_60;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  
  uVar7 = (uint)param_1;
  if (param_2 < 0x10) {
    uVar1 = (short)param_2 + 0x10;
  }
  else {
    uVar1 = (short)param_2 - 0x10;
  }
  uVar8 = (uint)uVar1;
  local_2c = (int)*(short *)(DAT_0000b678 + (uVar8 + uVar7 * 0x20) * 4);
  local_28 = (int)*(short *)(DAT_0000b678 + (uVar8 + uVar7 * 0x20) * 4 + 2);
  local_34 = (int)*(short *)(DAT_0000b67c + (uVar8 + uVar7 * 0x20) * 4);
  local_30 = (int)*(short *)(DAT_0000b67c + (uVar8 + uVar7 * 0x20) * 4 + 2);
  local_3c = (int)*(short *)(DAT_0000b680 + (uVar8 + uVar7 * 0x20) * 4);
  local_38 = (int)*(short *)(DAT_0000b680 + (uVar8 + uVar7 * 0x20) * 4 + 2);
  local_44 = (int)*(short *)(DAT_0000b684 + (uVar8 + uVar7 * 0x20) * 4);
  local_40 = (int)*(short *)(DAT_0000b684 + (uVar8 + uVar7 * 0x20) * 4 + 2);
  local_48 = *param_4 ^ 0x80000000;
  uVar7 = param_4[1];
  local_a0 = FUN_000085f8(param_2 + -0x10);
  local_98 = FUN_0000841a((int)local_a0,(int)((ulonglong)local_a0 >> 0x20),DAT_0000b688,DAT_0000b68c
                         );
  local_4c = FUN_00008748();
  local_98._4_4_ = param_4[2] ^ 0x80000000;
  local_50 = FUN_0000813c(local_98._4_4_,local_4c);
  local_98._4_4_ = param_4[3] ^ 0x80000000;
  uVar6 = FUN_0000813c(local_98._4_4_,local_4c);
  FUN_000085dc(local_38);
  sVar2 = FUN_00008634();
  FUN_000085dc(local_3c);
  sVar3 = FUN_00008634();
  FUN_000085dc(local_28);
  sVar4 = FUN_00008634();
  FUN_000085dc(local_2c);
  sVar5 = FUN_00008634();
  FUN_0000f2b4(&local_a0,(int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2,local_48);
  local_68 = (undefined4)local_98;
  local_64 = local_98._4_4_;
  local_70 = local_a0;
  FUN_000085dc(local_40);
  sVar2 = FUN_00008634();
  FUN_000085dc(local_44);
  sVar3 = FUN_00008634();
  FUN_000085dc(local_30);
  sVar4 = FUN_00008634();
  FUN_000085dc(local_34);
  sVar5 = FUN_00008634();
  FUN_0000f2b4(&local_a0,(int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2,uVar7 ^ 0x80000000);
  local_58 = (undefined4)local_98;
  local_54 = local_98._4_4_;
  local_60 = local_a0;
  FUN_000085dc(local_30);
  sVar2 = FUN_00008634();
  FUN_000085dc(local_34);
  sVar3 = FUN_00008634();
  FUN_000085dc(local_28);
  sVar4 = FUN_00008634();
  FUN_000085dc(local_2c);
  sVar5 = FUN_00008634();
  FUN_0000f2b4(&local_a0,(int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2,local_50);
  local_78 = (undefined4)local_98;
  local_74 = local_98._4_4_;
  local_80 = local_a0;
  FUN_000085dc(local_40);
  sVar2 = FUN_00008634();
  FUN_000085dc(local_44);
  sVar3 = FUN_00008634();
  FUN_000085dc(local_38);
  sVar4 = FUN_00008634();
  FUN_000085dc(local_3c);
  sVar5 = FUN_00008634();
  FUN_0000f2b4(&local_a0,(int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2,uVar6);
  *param_3 = local_64;
  param_3[1] = local_54;
  param_3[2] = local_74;
  param_3[3] = local_98._4_4_;
  return;
}


/* ===== FUN_0000b690 @ 0000b690 ===== */

uint FUN_0000b690(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  
  iVar1 = DAT_0000b8cc;
  uVar8 = param_2 & 0x7fffffff;
  if ((int)uVar8 < DAT_0000b8cc) {
    if (DAT_0000b8e4 <= (int)uVar8) {
      uVar9 = FUN_00008414(param_1,param_2 & 0x7fffffff,0,DAT_0000b8cc);
      uVar9 = FUN_00008a66((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0xffffffff);
      uVar2 = (undefined4)((ulonglong)uVar9 >> 0x20);
      uVar6 = (undefined4)uVar9;
      uVar9 = FUN_00009b5e(DAT_0000b8f0 + 0xb7ae,6,uVar6,uVar2);
      uVar9 = FUN_0000841a((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar6,uVar2);
      uVar3 = (undefined4)((ulonglong)uVar9 >> 0x20);
      uVar10 = FUN_00009b5e(DAT_0000b8f4 + 0xb7c8,4,uVar6,uVar2);
      uVar10 = FUN_0000841a((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar6,uVar2);
      uVar10 = FUN_000082cc((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,iVar1);
      uVar4 = (undefined4)((ulonglong)uVar10 >> 0x20);
      uVar11 = FUN_00010fa6(uVar6,uVar2);
      uVar5 = (undefined4)((ulonglong)uVar11 >> 0x20);
      uVar7 = (undefined4)uVar11;
      if ((int)uVar8 < DAT_0000b8f8) {
        uVar11 = FUN_000082cc(uVar7,uVar5,0,uVar5);
        uVar12 = FUN_0000841a(0,uVar5);
        uVar12 = FUN_00008414((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar6,uVar2);
        uVar11 = FUN_000084fe((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
                              (int)((ulonglong)uVar11 >> 0x20));
        uVar9 = FUN_000084fe((int)uVar9,uVar3,(int)uVar10,uVar4);
        uVar10 = FUN_00008a66((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),1);
        uVar10 = FUN_00008414((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_0000b8d4,DAT_0000b8d8
                             );
        uVar11 = FUN_00008a66(uVar7,uVar5,1);
        uVar9 = FUN_0000841a((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),(int)uVar9,
                             (int)((ulonglong)uVar9 >> 0x20));
        uVar9 = FUN_0000840e((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,
                             (int)((ulonglong)uVar10 >> 0x20));
        uVar10 = FUN_00008a66(0,uVar5,1);
        uVar7 = DAT_0000b8fc;
        uVar6 = DAT_0000b8dc;
        uVar10 = FUN_00008414((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),DAT_0000b8dc,DAT_0000b8fc
                             );
        uVar9 = FUN_00008414((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar9,
                             (int)((ulonglong)uVar9 >> 0x20));
      }
      else {
        uVar9 = FUN_000084fe((int)uVar9,uVar3,(int)uVar10,uVar4);
        uVar9 = FUN_0000841a((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar7,uVar5);
        uVar9 = FUN_000082cc((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar7,uVar5);
        uVar9 = FUN_00008a66((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),1);
        uVar9 = FUN_0000840e((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_0000b8d4,DAT_0000b8d8);
        uVar6 = DAT_0000b8dc;
        uVar7 = DAT_0000b8e0;
      }
      uVar8 = FUN_00008414((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar6,uVar7);
      return uVar8;
    }
    if (uVar8 < 0x3e400000) {
      iVar1 = FUN_00009b10(param_1);
      if (iVar1 == 4) {
        FUN_00009c2c();
      }
      return param_1;
    }
    uVar9 = FUN_0000841a(param_1,param_2,param_1,param_2);
    uVar7 = (undefined4)((ulonglong)uVar9 >> 0x20);
    uVar6 = (undefined4)uVar9;
    uVar9 = FUN_00009b5e(DAT_0000b8e8 + 0xb738,6,uVar6,uVar7);
    uVar9 = FUN_0000841a((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),uVar6,uVar7);
    uVar10 = FUN_00009b5e(DAT_0000b8ec + 0xb752,4,uVar6,uVar7);
    uVar10 = FUN_0000841a((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),uVar6,uVar7);
    uVar10 = FUN_000082cc((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,iVar1);
    uVar9 = FUN_000084fe((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,
                         (int)((ulonglong)uVar10 >> 0x20));
    uVar9 = FUN_0000841a((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),param_1,param_2);
    uVar8 = FUN_000082cc((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),param_1,param_2);
    return uVar8;
  }
  if ((uVar8 - DAT_0000b8cc | param_1) == 0) {
    uVar9 = FUN_0000841a(param_1,param_2,DAT_0000b8d4,DAT_0000b8d8);
    uVar10 = FUN_0000841a(param_1,param_2,DAT_0000b8dc,DAT_0000b8e0);
    uVar8 = FUN_000082cc((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar9,
                         (int)((ulonglong)uVar9 >> 0x20));
    return uVar8;
  }
  if (((int)uVar8 <= (int)DAT_0000b8d0) && ((uVar8 != DAT_0000b8d0 || (param_1 == 0)))) {
    FUN_00009de0(1);
    uVar8 = FUN_000084fe(0,0,0,0);
    return uVar8;
  }
  uVar8 = FUN_00008a66(param_1,param_2,1);
  return uVar8;
}


/* ===== FUN_0000b900 @ 0000b900 ===== */

uint FUN_0000b900(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (param_1 * 2 + 0x8e000000 < 0xd000001) {
    if (param_1 << 1 < 0x7e000001) {
      uVar1 = 0;
      uVar5 = 0;
      uVar2 = FUN_000081ec(param_1,param_1);
    }
    else {
      uVar1 = FUN_000081e6(param_1 & 0x7fffffff,0x3f800000);
      uVar2 = FUN_00008906(uVar1,0xffffffff);
      uVar3 = FUN_00010ff2();
      uVar5 = DAT_0000ba0c;
      uVar1 = DAT_0000ba08;
      if ((param_1 & 0x80000000) != 0) {
        uVar3 = uVar3 ^ 0x80000000;
        uVar5 = DAT_0000ba04;
        uVar1 = DAT_0000ba00;
      }
      param_1 = FUN_000081ec(uVar3,0xc0000000);
    }
    uVar4 = FUN_000081ec(uVar2,DAT_0000ba10);
    uVar4 = FUN_0000813c(uVar4,DAT_0000ba14);
    uVar4 = FUN_000081ec(uVar4,uVar2);
    uVar4 = FUN_0000813c(uVar4,DAT_0000ba18);
    uVar4 = FUN_000081ec(uVar4,uVar2);
    uVar4 = FUN_0000813c(uVar4,DAT_0000ba1c);
    uVar4 = FUN_000081ec(uVar4,uVar2);
    uVar4 = FUN_0000813c(uVar4,DAT_0000ba20);
    uVar2 = FUN_000081ec(param_1,uVar2);
    uVar2 = FUN_000081ec(uVar2,uVar4);
    uVar5 = FUN_0000813c(param_1,uVar5);
    uVar5 = FUN_0000813c(uVar5,uVar2);
    uVar3 = FUN_0000813c(uVar5,uVar1);
    return uVar3;
  }
  if (param_1 * 2 < 0x72000000) {
    iVar6 = FUN_00009b38();
    if (iVar6 == 4) {
      FUN_00009c4e();
    }
    return param_1;
  }
  if (0xff000000 < param_1 << 1) {
    uVar3 = FUN_00008906(param_1,1);
    return uVar3;
  }
  FUN_00009de0(1);
  uVar3 = FUN_00008250(0);
  return uVar3;
}


/* ===== FUN_0000ba24 @ 0000ba24 ===== */

void FUN_0000ba24(undefined4 param_1,undefined4 param_2)

{
  FUN_00009acc("Wrong parameters value: file%s oneline%d \r\n",param_1,param_2);
  return;
}


/* ===== FUN_0000ba64 @ 0000ba64 ===== */

undefined4 FUN_0000ba64(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  bool bVar10;
  
  uVar5 = 0xe8000000;
  bVar10 = 0xe4ffffff < param_1 * 2 + 0xe8000000;
  if (!bVar10) {
    uVar5 = param_2 * 2 + 0xe8000000;
  }
  uVar7 = param_2;
  uVar8 = param_1;
  if (bVar10 || 0xe4ffffff < uVar5) {
    if (0xff000000 < param_1 << 1 || 0xff000000 < param_2 << 1) {
      uVar1 = FUN_0000813c();
      return uVar1;
    }
    if (((param_1 | param_2) & 0x7fffffff) == 0) {
      param_2 = param_2 | 0x7f800000;
      uVar7 = param_2;
    }
    else if ((param_1 & 0x7fffffff) == 0x7f800000 && (param_2 & 0x7fffffff) == 0x7f800000) {
      param_1 = param_1 & 0xbfffffff;
      param_2 = param_2 & 0xbfffffff;
      uVar7 = param_2;
      uVar8 = param_1;
    }
    else {
      bVar10 = (param_1 & 0x7fffffff) == 0x7f800000;
      if (!bVar10) {
        bVar10 = (param_2 & 0x7fffffff) == 0;
      }
      if (bVar10) {
        param_1 = param_1 | 0x7f800000;
        param_2 = param_2 & 0x80000000;
      }
      else if (-1 < (int)(param_2 * 2 ^ param_1 << 1)) {
        if ((int)(param_2 * 2) < 0) {
          uVar1 = 0x2f800000;
        }
        else {
          uVar1 = 0x4f800000;
        }
        param_1 = FUN_000081ec(param_1,uVar1);
        param_2 = FUN_000081ec(param_2,uVar1);
        uVar7 = param_2;
        uVar8 = param_1;
      }
    }
  }
  uVar1 = DAT_0000bc98;
  iVar6 = ((param_1 << 1) >> 0x18) - ((param_2 << 1) >> 0x18);
  if (0x1b < iVar6) {
    uVar1 = DAT_0000bc74;
    if ((param_1 & 0x80000000) == 0) {
      uVar1 = DAT_0000bc78;
    }
    return uVar1;
  }
  if (iVar6 + 0x1a < 0 == SCARRY4(iVar6,0x1a)) {
    if (param_1 * 2 < param_2 * 2 || param_1 * 2 + param_2 * -2 == 0) {
      uVar5 = uVar7;
      if ((param_2 & 0x80000000) == 0) {
        uVar3 = 0;
        uVar2 = 0;
      }
      else {
        uVar3 = DAT_0000bca0;
        uVar2 = DAT_0000bc9c;
        if ((param_1 & 0x80000000) == 0) {
          uVar3 = DAT_0000bca8;
          uVar2 = DAT_0000bca4;
        }
      }
    }
    else {
      uVar3 = DAT_0000bc88;
      uVar2 = DAT_0000bc84;
      if ((param_1 & 0x80000000) == 0) {
        uVar3 = DAT_0000bc90;
        uVar2 = DAT_0000bc8c;
      }
      uVar5 = param_1 ^ 0x80000000;
      param_1 = param_2;
      param_2 = uVar5;
      uVar5 = uVar8 ^ 0x80000000;
      uVar8 = uVar7;
    }
    if ((param_2 - param_1) * 2 < 0x1000000) {
      if (((param_1 ^ param_2) & 0x80000000) == 0) {
        uVar9 = 0x3f000000;
        uVar2 = FUN_0000813c(uVar2,DAT_0000bc94);
        uVar3 = FUN_0000813c(uVar3,uVar1);
      }
      else {
        uVar9 = 0xbf000000;
        uVar2 = FUN_000081e0(uVar2);
        uVar3 = FUN_000081e0(uVar3,uVar1);
      }
      uVar1 = FUN_000081ec(uVar8,uVar9);
      uVar1 = FUN_0000813c(uVar1,uVar5);
      uVar9 = FUN_000081ec(uVar9,uVar5);
      uVar9 = FUN_000081e6(uVar9,uVar8);
      uVar1 = FUN_00008250(uVar9,uVar1);
    }
    else {
      uVar1 = FUN_00008250(uVar8,uVar5);
    }
    uVar9 = FUN_000081ec(uVar1,uVar1);
    uVar4 = FUN_000081ec(uVar9,DAT_0000bcac);
    uVar4 = FUN_0000813c(uVar4,DAT_0000bcb0);
    uVar4 = FUN_000081ec(uVar4,uVar9);
    uVar4 = FUN_0000813c(uVar4,DAT_0000bcb4);
    uVar4 = FUN_000081ec(uVar4,uVar9);
    uVar4 = FUN_0000813c(uVar4,DAT_0000bcb8);
    uVar4 = FUN_000081ec(uVar4,uVar9);
    uVar4 = FUN_0000813c(uVar4,DAT_0000bcbc);
    uVar9 = FUN_000081ec(uVar1,uVar9);
    uVar9 = FUN_000081ec(uVar9,uVar4);
    uVar3 = FUN_0000813c(uVar9,uVar3);
    uVar1 = FUN_0000813c(uVar3,uVar1);
    uVar1 = FUN_0000813c(uVar1,uVar2);
    return uVar1;
  }
  if ((param_2 & 0x80000000) == 0) {
    uVar1 = FUN_00008250(uVar8,uVar7);
    iVar6 = FUN_00009b38();
    if (iVar6 == 4) {
      FUN_00009c4e();
    }
    return uVar1;
  }
  uVar1 = DAT_0000bc7c;
  if ((param_1 & 0x80000000) != 0) {
    uVar1 = DAT_0000bc80;
  }
  return uVar1;
}


/* ===== FUN_0000bcc0 @ 0000bcc0 ===== */

void FUN_0000bcc0(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_0000bce8 + 0x120) = *DAT_0000bce4 | 0x100;
  }
  else {
    *(uint *)(DAT_0000bce8 + 0x120) = *DAT_0000bce4 & 0xfffffeff;
  }
  return;
}


/* ===== FUN_0000bcec @ 0000bcec ===== */

void FUN_0000bcec(int param_1,uint param_2,int param_3,int param_4)

{
  *DAT_0000bd34 = param_2 | param_4 << 3;
  if (param_1 == 1) {
    *(uint *)(DAT_0000bd38 + 0x1c) = *(uint *)(DAT_0000bd38 + 0x1c) | 0x100;
  }
  else {
    *(uint *)(DAT_0000bd38 + 0x1c) = *(uint *)(DAT_0000bd38 + 0x1c) & 0xfffffeff;
  }
  if (param_3 == 1) {
    *(uint *)(DAT_0000bd38 + 0x1c) = *(uint *)(DAT_0000bd38 + 0x1c) | 0x200;
  }
  else {
    *(uint *)(DAT_0000bd38 + 0x1c) = *(uint *)(DAT_0000bd38 + 0x1c) & 0xfffffdff;
  }
  return;
}


/* ===== FUN_0000bd3c @ 0000bd3c ===== */

void FUN_0000bd3c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,uint param_8)

{
  *(uint *)(DAT_0000bd78 + 0x118) =
       param_1 << 0x1c | param_2 << 0x18 | param_3 << 0x14 | param_4 << 0x10 | param_5 << 0xc |
       param_6 << 8 | param_7 << 4 | param_8;
  return;
}


/* ===== FUN_0000bd7c @ 0000bd7c ===== */

void FUN_0000bd7c(void)

{
  *DAT_0000bd84 = 1;
  return;
}


/* ===== FUN_0000bd88 @ 0000bd88 ===== */

void FUN_0000bd88(void)

{
  int iVar1;
  
  FUN_00010f04(DAT_0000bdf8,0);
  FUN_00008fa0(DAT_0000bdfc,0x48000,0x3c);
  if (*DAT_0000bdfc + DAT_0000be00 == 0) {
    iVar1 = FUN_0000c70c(DAT_0000bdfc + 2,4);
    if (iVar1 == DAT_0000bdfc[1]) {
      FUN_00010ad0(DAT_0000bdfc[2],DAT_0000bdfc[3],DAT_0000bdfc[4],DAT_0000bdfc[5]);
    }
    iVar1 = FUN_0000c70c(DAT_0000bdfc + 7,3);
    if (iVar1 == DAT_0000bdfc[6]) {
      FUN_00010b28(DAT_0000bdfc[7],DAT_0000bdfc[8],DAT_0000bdfc[9]);
    }
    FUN_00010a68();
  }
  return;
}


/* ===== FUN_0000be04 @ 0000be04 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000be04(void)

{
  undefined4 unaff_r10;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined8 local_28;
  
  local_3c = 1;
  local_28 = FUN_0000fec4(DAT_0000c0cc,DAT_0000c0c8);
  if (*DAT_0000c0c8 == '\x01') {
    unaff_r10 = FUN_000085dc(*(int *)(DAT_0000c0c8 + 0xc) -
                             (*DAT_0000c0d0 * 6 + *DAT_0000c0d4 * 2 + -0x3c));
    uVar1 = FUN_000085f8(*(undefined4 *)(DAT_0000c0c8 + 4));
    uVar1 = FUN_000082cc((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),(undefined4)local_28,
                         local_28._4_4_);
    uVar1 = FUN_0000840e((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,DAT_0000c0d8);
    uVar1 = FUN_0000841a((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_0000c0dc,DAT_0000c0e0);
    FUN_000084fe((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,DAT_0000c0e4);
    local_38 = FUN_00008748();
    uVar1 = FUN_000085f8(*(int *)(DAT_0000c0c8 + 8) + -0x20);
    uVar1 = FUN_0000841a((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_0000c0e8,DAT_0000c0ec);
    FUN_000084fe((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,DAT_0000c0e4);
    local_34 = FUN_00008748();
    local_30 = unaff_r10;
  }
  if ((*_DAT_0000c0f0 == '\x01') || (*_DAT_0000c0f0 == '\x02')) {
    FUN_000117b8(*(undefined4 *)(DAT_0000c0c8 + 0x10),*DAT_0000c0d0,*DAT_0000c0d4);
  }
  else if (*_DAT_0000c0f0 == '\x03') {
    local_2c = 0;
    FUN_000099c4(0xa10,&local_3c,0x14);
    uVar1 = FUN_000086c0(unaff_r10);
    uVar2 = FUN_000085f8(*(int *)(DAT_0000c0c8 + 8) + -0x20);
    uVar2 = FUN_0000841a((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_0000c0e8,DAT_0000c0ec);
    uVar2 = FUN_000084fe((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,DAT_0000c0e4);
    uVar3 = FUN_000085f8(*(undefined4 *)(DAT_0000c0c8 + 4));
    uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0000c0dc,DAT_0000c0e0);
    uVar3 = FUN_000084fe((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000c0e4);
    FUN_0000fbb4("TX0RX0: Distance: %.3f, Speed: %.3f, Power(dBFS): %.0f",
                 (int)((ulonglong)uVar2 >> 0x20),(int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar2,
                 uVar1);
  }
  else if (*_DAT_0000c0f0 == '\x04') {
    local_2c = 1;
    FUN_000099c4(0xa10,&local_3c,0x14);
    uVar1 = FUN_000086c0(unaff_r10);
    uVar2 = FUN_000085f8(*(int *)(DAT_0000c0c8 + 8) + -0x20);
    uVar2 = FUN_0000841a((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_0000c0e8,DAT_0000c0ec);
    uVar2 = FUN_000084fe((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,DAT_0000c0e4);
    uVar3 = FUN_000085f8(*(undefined4 *)(DAT_0000c0c8 + 4));
    uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0000c0dc,DAT_0000c0e0);
    uVar3 = FUN_000084fe((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000c0e4);
    FUN_0000fbb4("TX0RX1: Distance: %.3f, Speed: %.3f, Power(dBFS): %.0f",
                 (int)((ulonglong)uVar2 >> 0x20),(int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar2,
                 uVar1);
  }
  else if (*_DAT_0000c0f0 == '\x05') {
    local_2c = 2;
    FUN_000099c4(0xa10,&local_3c,0x14);
    uVar1 = FUN_000086c0(unaff_r10);
    uVar2 = FUN_000085f8(*(int *)(DAT_0000c0c8 + 8) + -0x20);
    uVar2 = FUN_0000841a((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_0000c0e8,DAT_0000c0ec);
    uVar2 = FUN_000084fe((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,DAT_0000c0e4);
    uVar3 = FUN_000085f8(*(undefined4 *)(DAT_0000c0c8 + 4));
    uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0000c0dc,DAT_0000c0e0);
    uVar3 = FUN_000084fe((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000c0e4);
    FUN_0000fbb4("TX1RX0: Distance: %.3f, Speed: %.3f, Power(dBFS): %.0f",
                 (int)((ulonglong)uVar1 >> 0x20),(int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar2,
                 uVar1);
  }
  else if (*_DAT_0000c0f0 == '\x06') {
    local_2c = 3;
    FUN_000099c4(0xa10,&local_3c,0x14);
    uVar1 = FUN_000086c0(unaff_r10);
    uVar2 = FUN_000085f8(*(int *)(DAT_0000c0c8 + 8) + -0x20);
    uVar2 = FUN_0000841a((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_0000c0e8,DAT_0000c0ec);
    uVar2 = FUN_000084fe((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,DAT_0000c0e4);
    uVar3 = FUN_000085f8(*(undefined4 *)(DAT_0000c0c8 + 4));
    uVar3 = FUN_0000841a((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),DAT_0000c0dc,DAT_0000c0e0);
    uVar3 = FUN_000084fe((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000c0e4);
    FUN_0000fbb4("TX1RX1: Distance: %.3f, Speed: %.3f, Power(dBFS): %.0f",
                 (int)((ulonglong)uVar2 >> 0x20),(int)uVar3,(int)((ulonglong)uVar3 >> 0x20),uVar2,
                 uVar1);
  }
  return;
}


/* ===== FUN_0000c1d4 @ 0000c1d4 ===== */

/* WARNING: Removing unreachable block (ram,0x0000c1ec) */

void FUN_0000c1d4(void)

{
  if (*DAT_0000c208 != '\0') {
    *DAT_0000c208 = '\0';
    FUN_00010f04(DAT_0000c20c,0);
    FUN_00009070(DAT_0000c210,0x48000,0x3c);
  }
  return;
}


/* ===== FUN_0000c214 @ 0000c214 ===== */

void FUN_0000c214(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_0000c294;
  switch(param_1) {
  case 0:
    *(undefined4 *)(DAT_0000c294 + 0x30) = 3;
    *(undefined4 *)(iVar1 + 0x34) = 3;
    break;
  case 1:
    *(undefined4 *)(DAT_0000c294 + 0x4c) = 3;
    *(undefined4 *)(iVar1 + 0x50) = 3;
    break;
  case 2:
    *(undefined4 *)(DAT_0000c294 + 0x58) = 3;
    *(undefined4 *)(iVar1 + 0x5c) = 3;
    break;
  case 3:
    *(undefined4 *)(DAT_0000c294 + 0x60) = 3;
    *(undefined4 *)(iVar1 + 100) = 3;
    break;
  case 4:
    *(undefined4 *)(DAT_0000c294 + 0x68) = 3;
    *(undefined4 *)(iVar1 + 0x6c) = 3;
    break;
  case 5:
    *(undefined4 *)(DAT_0000c294 + 0x70) = 3;
    *(undefined4 *)(iVar1 + 0x74) = 3;
    break;
  case 6:
    *(undefined4 *)(DAT_0000c294 + 0x78) = 3;
    *(undefined4 *)(iVar1 + 0x7c) = 3;
    break;
  case 7:
    *(undefined4 *)(DAT_0000c294 + 0x8c) = 3;
    *(undefined4 *)(DAT_0000c294 + 0x90) = 3;
  }
  iVar1 = DAT_0000c298;
  *(uint *)(DAT_0000c298 + 0x14) = *(uint *)(DAT_0000c298 + 0x14) | 0x3800;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x1c000;
  return;
}


/* ===== FUN_0000c2f0 @ 0000c2f0 ===== */

void FUN_0000c2f0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (char *)0x0) {
    FUN_0000c54c(param_2,param_3);
    for (iVar2 = 0; iVar1 = DAT_0000c3f8, iVar2 < 9; iVar2 = iVar2 + 1) {
      FUN_00008eb4(param_1 + iVar2 * 0x24 + 4);
    }
    *(uint *)(DAT_0000c3f8 + 0x28) = *(uint *)(DAT_0000c3f8 + 0x28) & 0xffffff7f;
    *(uint *)(iVar1 + 0x2c) = (*(uint *)(iVar1 + 0x2c) & 0xffffff0f) + 0x20;
    if (*param_1 == '\x03') {
      *(uint *)(iVar1 + 0x28) = (*(uint *)(iVar1 + 0x28) & 0xffffbfff) + 0x4000;
    }
    else if (*param_1 == '\x04') {
      *(uint *)(DAT_0000c3f8 + 0x28) = (*(uint *)(DAT_0000c3f8 + 0x28) & 0xffffffdf) + 0x20;
    }
    else if (*param_1 == '\x05') {
      *(uint *)(DAT_0000c3f8 + 0x28) = (*(uint *)(DAT_0000c3f8 + 0x28) & 0xffffffbf) + 0x40;
    }
    *(uint *)(DAT_0000c3f8 + 0x28) = (*(uint *)(DAT_0000c3f8 + 0x28) & 0xffdfffff) + 0x200000;
    iVar2 = DAT_0000c3f8;
    *(uint *)(DAT_0000c3f8 + 0x28) =
         *(uint *)(DAT_0000c3f8 + 0x28) & 0xbfffffff | ((byte)param_1[1] & 1) << 0x1e;
    *(uint *)(iVar2 + 0x28) = (*(uint *)(iVar2 + 0x28) & 0xefffffff) + 0x10000000;
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & 0x8fffffff;
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & 0xf8ffffff;
    *(uint *)(iVar2 + 0x18) = (*(uint *)(iVar2 + 0x18) & 0xfffffff7) + 8;
    *(uint *)(iVar2 + 0x18) = (*(uint *)(iVar2 + 0x18) & 0xfffffffb) + 4;
    *(uint *)(iVar2 + 0x18) = (*(uint *)(iVar2 + 0x18) & 0xfffffeff) + 0x100;
    *(uint *)(iVar2 + 0x18) = (*(uint *)(iVar2 + 0x18) & 0xfffffffd) + 2;
    *(uint *)(iVar2 + 0x18) = (*(uint *)(iVar2 + 0x18) & 0xffffff7f) + 0x80;
  }
  return;
}


/* ===== FUN_0000c3fc @ 0000c3fc ===== */

uint FUN_0000c3fc(void)

{
  return (uint)(*(int *)(DAT_0000c408 + 0x28) << 6) >> 0x1e;
}


/* ===== FUN_0000c40c @ 0000c40c ===== */

undefined4 FUN_0000c40c(void)

{
  undefined4 uVar1;
  
  if ((*(int *)(DAT_0000c428 + 0x14) << 0x1c < 0) || (*(int *)(DAT_0000c428 + 0x14) << 0x1d < 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== FUN_0000c42c @ 0000c42c ===== */

void FUN_0000c42c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_0000c3fc(0,param_1,param_3,param_4,0);
  puVar2 = (uint *)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 != 0) {
    *puVar2 = *(uint *)(DAT_0000c538 + 0x70) & 0x1fffffff;
    puVar2[1] = *(uint *)(DAT_0000c538 + 0x74) & 0x7ff;
    *(byte *)(puVar2 + 2) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 0xf) >> 0x1f);
    *(byte *)((int)puVar2 + 9) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 0xe) >> 0x1f);
    *(byte *)((int)puVar2 + 10) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 0xd) >> 0x1f);
    *(byte *)((int)puVar2 + 0xb) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 0xc) >> 0x1f);
    *(byte *)(puVar2 + 3) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 0xb) >> 0x1f);
    *(byte *)((int)puVar2 + 0xd) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 10) >> 0x1f);
    *(byte *)((int)puVar2 + 0xe) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 5) >> 0x1d);
    *(byte *)((int)puVar2 + 0xf) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 4) >> 0x1f);
    *(byte *)(puVar2 + 4) = (byte)((uint)(*(int *)(DAT_0000c538 + 0x74) << 3) >> 0x1f);
    *(char *)((int)puVar2 + 0x11) = (char)*(undefined4 *)(DAT_0000c538 + 0x78);
    *(char *)((int)puVar2 + 0x12) = (char)((uint)*(undefined4 *)(DAT_0000c538 + 0x78) >> 8);
    *(char *)((int)puVar2 + 0x13) = (char)((uint)*(undefined4 *)(DAT_0000c538 + 0x78) >> 0x18);
    puVar2[5] = *(uint *)(DAT_0000c538 + 0x7c);
    switch(puVar2[1]) {
    case 9:
      uVar3 = 0xc;
      break;
    case 10:
      uVar3 = 0x10;
      break;
    case 0xb:
      uVar3 = 0x14;
      break;
    case 0xc:
      uVar3 = 0x18;
      break;
    case 0xd:
      uVar3 = 0x20;
      break;
    case 0xe:
      uVar3 = 0x30;
      break;
    case 0xf:
      uVar3 = 0x40;
      break;
    default:
      uVar3 = 8;
    }
    if ((*(char *)(puVar2 + 3) == '\0') && (puVar2[1] != 0)) {
      for (uVar1 = 0; uVar1 < uVar3 >> 2; uVar1 = uVar1 + 1) {
        puVar2[uVar1 + 6] = *(uint *)(DAT_0000c538 + 0x8c + uVar1 * 4);
      }
    }
    *(uint *)(DAT_0000c538 + 0x28) = (*(uint *)(DAT_0000c538 + 0x28) & 0xefffffff) + 0x10000000;
  }
  return;
}


/* ===== FUN_0000c53c @ 0000c53c ===== */

uint FUN_0000c53c(void)

{
  return (uint)(*(int *)(DAT_0000c548 + 0x14) << 0x18) >> 0x1f;
}


/* ===== FUN_0000c54c @ 0000c54c ===== */

void FUN_0000c54c(byte *param_1,int param_2)

{
  *(uint *)(DAT_0000c5f0 + 0x28) = (*(uint *)(DAT_0000c5f0 + 0x28) & 0xffffff7f) + 0x80;
  if (param_2 == 0) {
    *(uint *)(DAT_0000c5f0 + 4) = *(uint *)(DAT_0000c5f0 + 4) & 0xfffffe00 | (uint)param_1[1];
    *(uint *)(DAT_0000c5f0 + 4) =
         *(uint *)(DAT_0000c5f0 + 4) & 0xff80ffff | (param_1[2] & 0x7f) << 0x10;
    *(uint *)(DAT_0000c5f0 + 4) =
         *(uint *)(DAT_0000c5f0 + 4) & 0x80ffffff | (param_1[3] & 0x7f) << 0x18;
  }
  else if (param_2 == 1) {
    *(uint *)(DAT_0000c5f0 + 4) = *(uint *)(DAT_0000c5f0 + 4) & 0xfffffe00 | (uint)param_1[1];
    *(uint *)(DAT_0000c5f0 + 4) =
         *(uint *)(DAT_0000c5f0 + 4) & 0xff80ffff | (param_1[2] & 0x7f) << 0x10;
    *(uint *)(DAT_0000c5f0 + 4) =
         *(uint *)(DAT_0000c5f0 + 4) & 0x80ffffff | (param_1[3] & 0x7f) << 0x18;
    *(uint *)(DAT_0000c5f0 + 8) = *(uint *)(DAT_0000c5f0 + 8) & 0xffffff00 | (uint)param_1[4];
    *(uint *)(DAT_0000c5f0 + 8) =
         *(uint *)(DAT_0000c5f0 + 8) & 0xff80ffff | (param_1[5] & 0x7f) << 0x10;
    *(uint *)(DAT_0000c5f0 + 8) =
         *(uint *)(DAT_0000c5f0 + 8) & 0x80ffffff | (param_1[6] & 0x7f) << 0x18;
  }
  *(uint *)(DAT_0000c5f0 + 0x10) = *(uint *)(DAT_0000c5f0 + 0x10) & 0xffffffe0 | *param_1 & 0x1f;
  return;
}


/* ===== FUN_0000c5f4 @ 0000c5f4 ===== */

undefined8 FUN_0000c5f4(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = uVar2 - 0x3ff;
  if (0x13 < (int)uVar3) {
    cVar4 = 0x32 < uVar3;
    if (0x33 < (int)uVar3) {
      return CONCAT44(param_2,param_1);
    }
    uVar2 = 0xffffffff >> (uVar2 - 0x413 & 0xff);
    if ((param_1 & uVar2) == 0) {
      return CONCAT44(param_2,param_1);
    }
    FUN_00008414(param_1,param_2,DAT_0000c6c0,DAT_0000c6c4);
    FUN_00008718();
    if (cVar4 == '\0') {
      uVar1 = param_1;
      if (0 < (int)param_2) {
        if (uVar3 == 0x14) {
          param_2 = param_2 + 1;
        }
        else {
          uVar1 = (1 << (0x34 - uVar3 & 0xff)) + param_1;
          if (uVar1 < param_1) {
            param_2 = param_2 + 1;
          }
        }
      }
      param_1 = uVar1 & ~uVar2;
    }
    goto LAB_0000c6b8;
  }
  cVar4 = '\x01';
  if ((int)uVar3 < 0) {
    FUN_000082cc();
    FUN_00008718();
    if (cVar4 != '\0') goto LAB_0000c6b8;
    if ((int)param_2 < 0) {
      param_1 = 0;
      param_2 = 0x80000000;
      goto LAB_0000c6b8;
    }
    uVar2 = DAT_0000c6c8;
    if ((param_2 | param_1) == 0) goto LAB_0000c6b8;
  }
  else {
    uVar2 = DAT_0000c6cc >> (uVar3 & 0xff);
    cVar4 = '\x01';
    if ((param_2 & uVar2 | param_1) == 0) {
      return CONCAT44(param_2,param_1);
    }
    FUN_000082cc();
    FUN_00008718();
    if (cVar4 != '\0') goto LAB_0000c6b8;
    if (0 < (int)param_2) {
      param_2 = param_2 + (0x100000U >> (uVar3 & 0xff));
    }
    uVar2 = param_2 & ~uVar2;
  }
  param_1 = 0;
  param_2 = uVar2;
LAB_0000c6b8:
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_0000c6d0 @ 0000c6d0 ===== */

void FUN_0000c6d0(void)

{
  undefined4 in_r3;
  undefined4 local_8 [2];
  
  local_8[0] = in_r3;
  FUN_00010f04(DAT_0000c6f8,0);
  FUN_00009158();
  FUN_0000c974(50000,0);
  local_8[0] = 0xff;
  FUN_00009070(local_8,DAT_0000c6fc,1);
  return;
}


/* ===== FUN_0000c700 @ 0000c700 ===== */

undefined FUN_0000c700(void)

{
  return *DAT_0000c708;
}


/* ===== FUN_0000c70c @ 0000c70c ===== */

uint FUN_0000c70c(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    uVar2 = uVar2 ^ *(uint *)(param_1 + uVar1 * 4);
  }
  return ~(uVar2 + 1);
}


/* ===== FUN_0000c728 @ 0000c728 ===== */

void FUN_0000c728(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = FUN_000085dc(param_4);
  uVar2 = FUN_000081ec(uVar2,param_6);
  uVar3 = FUN_000085dc(param_3);
  uVar3 = FUN_000081ec(uVar3,param_5);
  FUN_000081e0(uVar3,uVar2);
  uVar1 = FUN_00008634();
  *param_1 = uVar1;
  uVar2 = FUN_000085dc(param_4);
  uVar2 = FUN_000081ec(uVar2,param_5);
  uVar3 = FUN_000085dc(param_3);
  uVar3 = FUN_000081ec(uVar3,param_6);
  FUN_0000813c(uVar3,uVar2);
  uVar1 = FUN_00008634();
  *param_2 = uVar1;
  return;
}


/* ===== FUN_0000c79c @ 0000c79c ===== */

uint FUN_0000c79c(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_20;
  
  if (param_1 * 2 < DAT_0000c8e4) {
    if (param_1 * 2 < 0x73000000) {
      local_20 = 0xffffffff;
    }
    else {
      local_20 = 0;
    }
  }
  else {
    local_20 = param_4;
    if ((param_1 & 0x7fffffff) < DAT_0000c8e8) {
      FUN_000081ec(param_1,DAT_0000c8ec);
      uVar4 = FUN_0000891e();
      local_20 = FUN_00008634();
      local_20 = local_20 & 3;
      uVar5 = FUN_000081ec(uVar4,DAT_0000c8f0);
      uVar2 = FUN_000081ec(uVar4,DAT_0000c8f4);
      uVar3 = FUN_000081ec(uVar4,DAT_0000c8f8);
      uVar4 = FUN_000081ec(uVar4,DAT_0000c8fc);
      uVar4 = FUN_000081e6(uVar4,param_1);
      uVar4 = FUN_000081e0(uVar4,uVar3);
      uVar4 = FUN_000081e0(uVar4,uVar2);
      param_1 = FUN_000081e0(uVar4,uVar5);
    }
    else {
      param_1 = FUN_00009c58(param_1,&local_20);
    }
  }
  uVar1 = local_20;
  if (-1 < (int)local_20) {
    if ((local_20 & 1) == 0) {
      uVar4 = FUN_000081ec(param_1);
      uVar5 = FUN_000081ec(uVar4,DAT_0000c90c);
      uVar5 = FUN_0000813c(uVar5,DAT_0000c910);
      uVar5 = FUN_000081ec(uVar5,uVar4);
      uVar5 = FUN_0000813c(uVar5,DAT_0000c914);
      uVar4 = FUN_000081ec(uVar5,uVar4);
      uVar6 = FUN_0000813c(uVar4,0x3f800000);
      if ((uVar1 & 2) == 0) {
        return uVar6;
      }
    }
    else {
      uVar4 = FUN_000081ec(param_1);
      uVar5 = FUN_000081ec(uVar4,DAT_0000c900);
      uVar5 = FUN_000081e6(uVar5,DAT_0000c904);
      uVar5 = FUN_000081ec(uVar5,uVar4);
      uVar5 = FUN_0000813c(uVar5,DAT_0000c908);
      uVar4 = FUN_000081ec(uVar5,uVar4);
      uVar4 = FUN_000081ec(uVar4,param_1);
      uVar6 = FUN_0000813c(uVar4,param_1);
      if ((uVar1 & 2) != 0) {
        return uVar6;
      }
    }
    return uVar6 ^ 0x80000000;
  }
  if (param_1 * 2 < 0xff000000) {
    return 0x3f800000;
  }
  if (param_1 * 2 == 0xff000000) {
    FUN_00009de0(1);
    uVar1 = FUN_00008250(0);
    return uVar1;
  }
  uVar1 = FUN_00008906(param_1,1);
  return uVar1;
}


/* ===== FUN_0000c918 @ 0000c918 ===== */

void FUN_0000c918(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_0000c948 | 0xe058;
  }
  else {
    uVar1 = *DAT_0000c948 & 0xfffffff7 | 0xe050;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffffe;
  }
  *DAT_0000c948 = uVar1;
  return;
}


/* ===== FUN_0000c94c @ 0000c94c ===== */

void FUN_0000c94c(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = DAT_0000c970;
  *(int *)(DAT_0000c970 + 0x54) = (param_1 - param_3 * (param_4 + 1)) - param_2;
  *(int *)(iVar1 + 0x58) = param_3 * (param_4 + 1);
  *(int *)(iVar1 + 0x50) = param_1;
  *(undefined4 *)(iVar1 + 0x5c) = param_5;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  return;
}


/* ===== FUN_0000c974 @ 0000c974 ===== */

void FUN_0000c974(int param_1,int param_2)

{
  *DAT_0000c9bc = 0;
  if (param_2 == 1) {
    FUN_0000d73c(param_1 * 0x32 + -1,0);
  }
  else {
    FUN_0000d73c(param_1 * 100 + -1,0);
  }
  do {
  } while (*DAT_0000c9bc != 1);
  return;
}


/* ===== FUN_0000c9c0 @ 0000c9c0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000c9c0(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  undefined uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar6 = 0;
  for (iVar3 = 3; iVar3 < 0x3c; iVar3 = iVar3 + 1) {
    for (uVar5 = 0; uVar5 < 0x20; uVar5 = uVar5 + 1 & 0xffff) {
      if (uVar6 < *(uint *)(DAT_0000cc58 + iVar3 * 0x80 + uVar5 * 4)) {
        uVar6 = *(uint *)(DAT_0000cc58 + iVar3 * 0x80 + uVar5 * 4);
        *(int *)(param_1 + 4) = iVar3;
        *(uint *)(param_1 + 8) = uVar5;
      }
    }
  }
  FUN_0000f384(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),&local_44);
  if (*DAT_0000cc5c != 0) {
    uVar4 = FUN_0000813c(*DAT_0000cc60,local_44);
    *DAT_0000cc60 = uVar4;
    uVar4 = FUN_0000813c(DAT_0000cc60[1],local_40);
    DAT_0000cc60[1] = uVar4;
    uVar4 = FUN_0000813c(DAT_0000cc60[2],local_3c);
    DAT_0000cc60[2] = uVar4;
    uVar4 = FUN_0000813c(DAT_0000cc60[3],local_38);
    DAT_0000cc60[3] = uVar4;
  }
  puVar1 = DAT_0000cc5c;
  uVar8 = 0xfffffffe < *DAT_0000cc5c;
  uVar6 = *DAT_0000cc5c + 1;
  cVar7 = uVar6 == 0;
  *DAT_0000cc5c = uVar6;
  uVar4 = FUN_000085ee(*puVar1);
  FUN_00008780(uVar4,DAT_0000cc64);
  if (cVar7 == '\0') {
    return;
  }
  uVar4 = FUN_00008250(*DAT_0000cc60,DAT_0000cc68);
  puVar2 = DAT_0000cc60;
  *DAT_0000cc60 = uVar4;
  uVar4 = FUN_00008250(puVar2[1],DAT_0000cc68);
  puVar2 = DAT_0000cc60;
  DAT_0000cc60[1] = uVar4;
  uVar4 = FUN_00008250(puVar2[2],DAT_0000cc68);
  puVar2 = DAT_0000cc60;
  DAT_0000cc60[2] = uVar4;
  uVar4 = FUN_00008250(puVar2[3],DAT_0000cc68);
  puVar2 = DAT_0000cc60;
  DAT_0000cc60[3] = uVar4;
  uVar4 = FUN_00011778(*puVar2);
  puVar2 = DAT_0000cc60;
  *DAT_0000cc60 = uVar4;
  uVar4 = FUN_00011778(puVar2[1]);
  puVar2 = DAT_0000cc60;
  DAT_0000cc60[1] = uVar4;
  uVar4 = FUN_00011778(puVar2[2]);
  puVar2 = DAT_0000cc60;
  DAT_0000cc60[2] = uVar4;
  uVar4 = FUN_00011778(puVar2[3]);
  puVar2 = DAT_0000cc60;
  DAT_0000cc60[3] = uVar4;
  uVar9 = FUN_000086c0(puVar2[3]);
  uVar10 = FUN_000086c0(DAT_0000cc60[2]);
  uVar11 = FUN_000086c0(DAT_0000cc60[1]);
  uVar12 = FUN_000086c0(*DAT_0000cc60);
  FUN_0000fbb4(DAT_0000cc6c,(int)((ulonglong)uVar11 >> 0x20),(int)uVar12,
               (int)((ulonglong)uVar12 >> 0x20),uVar11,uVar10,uVar9);
  FUN_0000b410(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),&local_34,DAT_0000cc60);
  uVar9 = FUN_000086c0(local_28);
  uVar10 = FUN_000086c0(local_2c);
  uVar11 = FUN_000086c0(local_30);
  uVar12 = FUN_000086c0(local_34);
  FUN_0000fbb4("angle: horiOdd = %f, horiEven = %f,elevCh0 = %f, elevCh1 = %f",
               (int)((ulonglong)uVar10 >> 0x20),(int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar11,
               uVar10,uVar9);
  uVar9 = FUN_000086c0(local_34);
  FUN_000086e8((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,DAT_0000ccb0,_DAT_0000ccb4);
  if (!(bool)uVar8 || (bool)cVar7) {
    uVar9 = FUN_000086c0(local_30);
    FUN_000086e8((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,DAT_0000ccb0,_DAT_0000ccb4
                );
    if (!(bool)uVar8 || (bool)cVar7) {
      uVar9 = FUN_000086c0(local_2c);
      FUN_000086e8((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,DAT_0000ccb0,
                   _DAT_0000ccb4);
      if (!(bool)uVar8 || (bool)cVar7) {
        uVar9 = FUN_000086c0(local_28);
        FUN_000086e8((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,DAT_0000ccb0,
                     _DAT_0000ccb4);
        if (!(bool)uVar8 || (bool)cVar7) {
          FUN_000081e0(*DAT_0000cc60,DAT_0000cc60[1]);
          uVar9 = FUN_000086c0();
          FUN_000086e8((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,DAT_0000ccb0,
                       _DAT_0000ccb4);
          if (!(bool)uVar8 || (bool)cVar7) {
            FUN_000081e0(DAT_0000cc60[2],DAT_0000cc60[3]);
            uVar9 = FUN_000086c0();
            FUN_000086e8((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,DAT_0000ccb0,
                         _DAT_0000ccb4);
            if (!(bool)uVar8 || (bool)cVar7) {
              FUN_0000fbb4("Calibration success");
              FUN_00010afc(*DAT_0000cc60,DAT_0000cc60[1],DAT_0000cc60[2],DAT_0000cc60[3]);
              local_58 = 1;
              goto LAB_0000cc0c;
            }
          }
        }
      }
    }
  }
  FUN_0000fbb4("Calibration failure");
  local_58 = 0;
LAB_0000cc0c:
  local_54 = *DAT_0000cc60;
  local_50 = DAT_0000cc60[1];
  local_4c = DAT_0000cc60[2];
  local_48 = DAT_0000cc60[3];
  FUN_000099c4(0xa16,&local_58,0x14);
  FUN_000099c4(0xa17,&local_34,0x10);
  FUN_00010c6c(0);
  puVar2 = DAT_0000cc60;
  *DAT_0000cc60 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  *DAT_0000cc5c = 0;
  return;
}


/* ===== FUN_0000cce0 @ 0000cce0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000cce0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined uVar7;
  char cVar8;
  undefined uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  uVar6 = 0;
  for (iVar3 = 3; iVar3 < 0x3c; iVar3 = iVar3 + 1) {
    for (uVar5 = 0; uVar5 < 0x20; uVar5 = uVar5 + 1 & 0xffff) {
      if (uVar6 < *(uint *)(DAT_0000cfcc + iVar3 * 0x80 + uVar5 * 4)) {
        uVar6 = *(uint *)(DAT_0000cfcc + iVar3 * 0x80 + uVar5 * 4);
        *(int *)(param_1 + 4) = iVar3;
        *(uint *)(param_1 + 8) = uVar5;
      }
    }
  }
  FUN_0000f544(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),&local_3c);
  if (*DAT_0000cfd0 != 0) {
    uVar4 = FUN_0000813c(*DAT_0000cfd4,local_3c);
    *DAT_0000cfd4 = uVar4;
    uVar4 = FUN_0000813c(DAT_0000cfd4[1],local_38);
    DAT_0000cfd4[1] = uVar4;
    uVar4 = FUN_0000813c(DAT_0000cfd4[2],local_34);
    DAT_0000cfd4[2] = uVar4;
  }
  piVar1 = DAT_0000cfd0;
  cVar8 = *DAT_0000cfd0 + 1 == 0;
  *DAT_0000cfd0 = *DAT_0000cfd0 + 1;
  uVar4 = FUN_000085ee(*piVar1);
  FUN_00008780(uVar4,DAT_0000cfd8);
  if (cVar8 == '\0') {
    return;
  }
  uVar4 = FUN_00008250(*DAT_0000cfd4,DAT_0000cfdc);
  puVar2 = DAT_0000cfd4;
  *DAT_0000cfd4 = uVar4;
  uVar4 = FUN_00008250(puVar2[1],DAT_0000cfdc);
  puVar2 = DAT_0000cfd4;
  DAT_0000cfd4[1] = uVar4;
  uVar4 = FUN_00008250(puVar2[2],DAT_0000cfdc);
  puVar2 = DAT_0000cfd4;
  DAT_0000cfd4[2] = uVar4;
  uVar4 = FUN_00011778(*puVar2);
  puVar2 = DAT_0000cfd4;
  *DAT_0000cfd4 = uVar4;
  uVar4 = FUN_00011778(puVar2[1]);
  puVar2 = DAT_0000cfd4;
  DAT_0000cfd4[1] = uVar4;
  uVar4 = FUN_00011778(puVar2[2]);
  puVar2 = DAT_0000cfd4;
  DAT_0000cfd4[2] = uVar4;
  uVar10 = FUN_000086c0(puVar2[2]);
  uVar11 = FUN_000086c0(DAT_0000cfd4[1]);
  uVar12 = FUN_000086c0(*DAT_0000cfd4);
  uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
  FUN_0000fbb4(DAT_0000cfe0,uVar4,(int)uVar12,uVar4,uVar11,uVar10);
  local_60 = 0;
  local_64 = 0;
  local_68 = 0;
  local_6c = 0;
  local_70 = 0;
  uVar6 = (uint)*(ushort *)(param_1 + 4);
  if (*(int *)(param_1 + 8) < 0x10) {
    uVar9 = 0xffffffef < *(uint *)(param_1 + 8);
    uVar5 = *(uint *)(param_1 + 8) + 0x10;
  }
  else {
    uVar9 = 0xf < *(uint *)(param_1 + 8);
    uVar5 = *(uint *)(param_1 + 8) - 0x10;
  }
  uVar7 = uVar5 == 0;
  uVar5 = uVar5 & 0xffff;
  local_5c = CONCAT22(*(undefined2 *)(DAT_0000cfe4 + (uVar5 + uVar6 * 0x20) * 4 + 2),
                      *(undefined2 *)(DAT_0000cfe4 + (uVar5 + uVar6 * 0x20) * 4));
  local_58 = CONCAT22(*(undefined2 *)(DAT_0000cfe8 + (uVar5 + uVar6 * 0x20) * 4 + 2),
                      *(undefined2 *)(DAT_0000cfe8 + (uVar5 + uVar6 * 0x20) * 4));
  local_54 = CONCAT22(*(undefined2 *)(DAT_0000cfec + (uVar5 + uVar6 * 0x20) * 4 + 2),
                      *(undefined2 *)(DAT_0000cfec + (uVar5 + uVar6 * 0x20) * 4));
  local_50 = CONCAT22(*(undefined2 *)(DAT_0000cff0 + (uVar5 + uVar6 * 0x20) * 4 + 2),
                      *(undefined2 *)(DAT_0000cff0 + (uVar5 + uVar6 * 0x20) * 4));
  FUN_0000d240(&local_68,&local_6c,&local_70,&local_60,&local_64,*(undefined2 *)(param_1 + 4),
               *(undefined2 *)(param_1 + 8),&local_5c,*DAT_0000cfd4,DAT_0000cfd4[1],DAT_0000cfd4[2])
  ;
  uVar10 = FUN_000086c0(local_64);
  uVar11 = FUN_000086c0(local_60);
  uVar12 = FUN_000086c0(local_70);
  uVar13 = FUN_000086c0(local_6c);
  uVar14 = FUN_000086c0(local_68);
  FUN_0000fbb4(DAT_0000cff4,(int)((ulonglong)uVar13 >> 0x20),(int)uVar14,
               (int)((ulonglong)uVar14 >> 0x20),uVar13,uVar12,uVar11,uVar10);
  uVar10 = FUN_000086c0(local_68);
  FUN_000086e8((int)uVar10,(uint)((ulonglong)uVar10 >> 0x20) & 0x7fffffff,DAT_0000cff8,_DAT_0000cffc
              );
  if (!(bool)uVar9 || (bool)uVar7) {
    uVar10 = FUN_000086c0(local_6c);
    FUN_000086e8((int)uVar10,(uint)((ulonglong)uVar10 >> 0x20) & 0x7fffffff,DAT_0000cff8,
                 _DAT_0000cffc);
    if (!(bool)uVar9 || (bool)uVar7) {
      uVar10 = FUN_000086c0(local_70);
      FUN_000086e8((int)uVar10,(uint)((ulonglong)uVar10 >> 0x20) & 0x7fffffff,DAT_0000cff8,
                   _DAT_0000cffc);
      if (!(bool)uVar9 || (bool)uVar7) {
        FUN_0000fbb4("Calibration success");
        FUN_00010b4c(*DAT_0000cfd4,DAT_0000cfd4[1],DAT_0000cfd4[2]);
        local_4c = 1;
        goto LAB_0000cf78;
      }
    }
  }
  FUN_0000fbb4("Calibration failure");
  local_4c = 0;
LAB_0000cf78:
  local_48 = *DAT_0000cfd4;
  local_44 = DAT_0000cfd4[1];
  local_40 = DAT_0000cfd4[2];
  local_30 = local_68;
  local_2c = local_6c;
  local_28 = local_70;
  FUN_000099c4(0xa18,&local_4c,0x10);
  FUN_000099c4(0xa19,&local_30,0xc);
  FUN_00010c6c(0);
  puVar2 = DAT_0000cfd4;
  *DAT_0000cfd4 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  *DAT_0000cfd0 = 0;
  return;
}


/* ===== FUN_0000d028 @ 0000d028 ===== */

undefined8 FUN_0000d028(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_0001162c(0);
  FUN_00011604(0);
  FUN_000101a4(1,0,0,1,1,param_2,param_3,param_4);
  uVar2 = 0;
  uVar1 = 8;
  FUN_0000bd3c(8,8,8);
  FUN_000115e4(0);
  *DAT_0000d07c = *DAT_0000d07c & 0xfffeffff;
  FUN_0000c974(100,0);
  return CONCAT44(uVar2,uVar1);
}


/* ===== FUN_0000d084 @ 0000d084 ===== */

uint FUN_0000d084(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 uint param_6,int param_7,int param_8)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0000d1d8;
  uVar2 = 0;
  switch(param_1) {
  case 0:
    *(undefined4 *)(DAT_0000d1d8 + 0x10) = param_2;
    *(undefined4 *)(iVar1 + 0x14) = param_3;
    iVar1 = DAT_0000d1d8;
    *(int *)(DAT_0000d1d8 + 0x68) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    uVar2 = param_6 | DAT_0000d1dc | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0xc) = uVar2;
    break;
  case 1:
    *(undefined4 *)(DAT_0000d1d8 + 0x20) = param_2;
    *(undefined4 *)(iVar1 + 0x24) = param_3;
    iVar1 = DAT_0000d1d8;
    *(int *)(DAT_0000d1d8 + 0x6c) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    uVar2 = param_6 | DAT_0000d1dc | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x1c) = uVar2;
    break;
  case 2:
    *(undefined4 *)(DAT_0000d1d8 + 0x30) = param_2;
    *(undefined4 *)(iVar1 + 0x34) = param_3;
    iVar1 = DAT_0000d1d8;
    *(int *)(DAT_0000d1d8 + 0x70) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    uVar2 = param_6 | DAT_0000d1dc | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x2c) = uVar2;
    break;
  case 3:
    *(undefined4 *)(DAT_0000d1d8 + 0x40) = param_2;
    *(undefined4 *)(iVar1 + 0x44) = param_3;
    iVar1 = DAT_0000d1d8;
    *(int *)(DAT_0000d1d8 + 0x74) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x3c) = 0;
    uVar2 = param_6 | DAT_0000d1dc | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x3c) = uVar2;
    break;
  case 4:
    *(undefined4 *)(DAT_0000d1d8 + 0x50) = param_2;
    *(undefined4 *)(iVar1 + 0x54) = param_3;
    iVar1 = DAT_0000d1d8;
    *(int *)(DAT_0000d1d8 + 0x78) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    uVar2 = param_6 | DAT_0000d1dc | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x4c) = uVar2;
  }
  return uVar2;
}


/* ===== FUN_0000d1e0 @ 0000d1e0 ===== */

void FUN_0000d1e0(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    *(uint *)(DAT_0000d23c + 0xc) = *(uint *)(DAT_0000d23c + 0xc) & 0x7fffffff;
    break;
  case 1:
    *(uint *)(DAT_0000d23c + 0x1c) = *(uint *)(DAT_0000d23c + 0x1c) & 0x7fffffff;
    break;
  case 2:
    *(uint *)(DAT_0000d23c + 0x2c) = *(uint *)(DAT_0000d23c + 0x2c) & 0x7fffffff;
    break;
  case 3:
    *(uint *)(DAT_0000d23c + 0x3c) = *(uint *)(DAT_0000d23c + 0x3c) & 0x7fffffff;
    break;
  case 4:
    *(uint *)(DAT_0000d23c + 0x4c) = *(uint *)(DAT_0000d23c + 0x4c) & 0x7fffffff;
  }
  return;
}


/* ===== FUN_0000d240 @ 0000d240 ===== */

/* WARNING: Removing unreachable block (ram,0x0000d5ee) */

bool FUN_0000d240(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 local_a08;
  undefined8 local_a00;
  uint local_9f8;
  undefined4 local_9f4;
  undefined4 uStack_9f0;
  undefined4 uStack_9ec;
  undefined4 local_9e8;
  undefined4 local_9e4;
  undefined4 uStack_9e0;
  undefined4 uStack_9dc;
  undefined4 local_9d8;
  undefined4 local_9d4;
  undefined4 uStack_9d0;
  undefined4 uStack_9cc;
  undefined4 local_9c8;
  undefined4 local_9c4;
  undefined4 local_9c0;
  uint local_9bc;
  int local_9b8;
  uint local_9b4 [126];
  undefined2 auStack_7ba [126];
  char acStack_6bd [129];
  undefined4 local_63c;
  undefined4 local_638;
  undefined4 local_634;
  undefined4 local_630;
  undefined4 local_62c;
  uint local_628 [129];
  undefined auStack_424 [512];
  short local_224 [4];
  short local_21c;
  short local_21a;
  short local_218;
  short local_216 [249];
  
  FUN_00008126(local_224,0x200);
  FUN_00008126(auStack_424,0x200);
  FUN_00008126(local_628 + 1,0x200);
  local_628[0] = 0;
  local_62c = 0;
  *DAT_0000d648 = param_9;
  *DAT_0000d64c = param_10;
  *DAT_0000d650 = param_11;
  local_628[0] = FUN_0000c79c(*DAT_0000d648);
  local_62c = FUN_00010ca0(*DAT_0000d648);
  local_630 = 0;
  local_634 = 0;
  local_638 = 0;
  local_63c = 0;
  FUN_00008126(acStack_6bd + 1,0x80);
  FUN_00008126(auStack_7ba + 1,0xfc);
  FUN_00008126(local_9b4 + 1,0x1f8);
  local_9b4[0] = 0;
  local_9b8 = 0;
  local_9bc = 0;
  local_9c0 = 0;
  local_9c4 = 0;
  local_a00._0_4_ = FUN_000085dc(param_7 + -0x10);
  local_a00._4_4_ = FUN_000081ec((undefined4)local_a00,DAT_0000d654);
  local_9c0 = FUN_00008250(local_a00._4_4_,0x42000000);
  uVar1 = FUN_0000813c(*DAT_0000d64c,local_9c0);
  *DAT_0000d64c = uVar1;
  uVar1 = FUN_0000813c(*DAT_0000d650,local_9c0);
  *DAT_0000d650 = uVar1;
  local_630 = FUN_0000c79c(*DAT_0000d64c);
  local_634 = FUN_00010ca0(*DAT_0000d64c);
  local_638 = FUN_0000c79c(*DAT_0000d650);
  local_63c = FUN_00010ca0(*DAT_0000d650);
  local_9f8 = 0;
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    for (uVar7 = 0; uVar7 < 2; uVar7 = uVar7 + 1 & 0xff) {
      local_224[local_9f8] = *(short *)(param_8 + uVar2 * 4 + uVar7 * 2);
      local_9f8 = local_9f8 + 1 & 0xff;
    }
  }
  FUN_0000c728(local_224 + 2,local_224 + 3,(int)local_224[2],(int)local_224[3],local_628[0],
               local_62c);
  FUN_0000c728(&local_21c,&local_21a,(int)local_21c,(int)local_21a,local_630,local_634);
  FUN_0000c728(&local_218,local_216,(int)local_218,(int)local_216[0],local_638,local_63c);
  FUN_0000f2b4(&local_a08,(int)local_224[0],(int)local_224[1],(int)local_224[2],(int)local_224[3],0)
  ;
  local_9d4 = (undefined4)local_a08;
  uStack_9d0 = local_a08._4_4_;
  uStack_9cc = (undefined4)local_a00;
  local_9c8 = local_a00._4_4_;
  FUN_0000f2b4(&local_a08,(int)local_224[2],(int)local_224[3],(int)local_21c,(int)local_21a,0);
  local_9e4 = (undefined4)local_a08;
  uStack_9e0 = local_a08._4_4_;
  uStack_9dc = (undefined4)local_a00;
  local_9d8 = local_a00._4_4_;
  FUN_0000f2b4(&local_a08,(int)local_21c,(int)local_21a,(int)local_218,(int)local_216[0],0);
  local_9f4 = (undefined4)local_a08;
  uStack_9f0 = local_a08._4_4_;
  uStack_9ec = (undefined4)local_a00;
  local_9e8 = local_a00._4_4_;
  *param_1 = local_9c8;
  *param_2 = local_9d8;
  *param_3 = local_a00._4_4_;
  uVar1 = 4;
  FUN_0000d840(0x80,local_224,auStack_424,4,4);
  *(uint *)(DAT_0000d658 + 8) = *(uint *)(DAT_0000d658 + 8) & 0xfffffbff;
  FUN_0000a688(0x80,1,auStack_424,local_628 + 1);
  for (iVar3 = 0; iVar3 < 0x40; iVar3 = (int)(short)((short)iVar3 + 1)) {
    uVar2 = local_628[iVar3 + 1];
    local_628[iVar3 + 1] = local_628[iVar3 + 0x41];
    local_628[iVar3 + 0x41] = uVar2;
  }
  for (uVar2 = 0; uVar2 < 0x7f; uVar2 = uVar2 + 1 & 0xffff) {
    acStack_6bd[uVar2 + 1] = '\0';
  }
  for (uVar2 = 1; uVar2 < 0x80; uVar2 = uVar2 + 1 & 0xffff) {
    local_9b4[0] = local_628[uVar2 + 1] - local_628[uVar2];
    if ((int)local_9b4[0] < 1) {
      acStack_6bd[uVar2] = -1;
    }
    else {
      acStack_6bd[uVar2] = '\x01';
    }
  }
  for (uVar2 = 0; uVar2 < 0x7e; uVar2 = uVar2 + 1 & 0xffff) {
    auStack_7ba[uVar2 + 1] = 0;
    local_9b4[uVar2 + 1] = 0;
  }
  for (uVar2 = 1; uVar2 < 0x7f; uVar2 = uVar2 + 1 & 0xffff) {
    local_9b4[0] = (int)acStack_6bd[uVar2 + 1] - (int)acStack_6bd[uVar2];
    if ((int)local_9b4[0] < 0) {
      auStack_7ba[uVar2] = (short)uVar2;
      local_9b4[uVar2] = local_628[uVar2 + 1];
    }
  }
  uVar8 = 0;
  uVar7 = 0x7e;
  for (uVar2 = 0; uVar2 < 0x7e; uVar2 = uVar2 + 1 & 0xffff) {
    if ((0x31 < local_9b4[uVar2 + 1]) && (uVar8 < local_9b4[uVar2 + 1])) {
      uVar7 = (uint)(short)uVar2;
      uVar8 = local_9b4[uVar2 + 1];
    }
  }
  if (uVar7 != 0x7e) {
    local_9bc = uVar7 & 0xffff;
    local_9b8 = local_9b4[uVar7 + 1] + 1;
    local_9b4[uVar7 + 1] = 0;
    uVar4 = FUN_000085dc((int)(short)(0x40 - (short)uVar7));
    uVar5 = FUN_000081ec(uVar4,0x40000000);
    uVar6 = FUN_00008250(uVar5,0x43000000);
    uVar9 = FUN_000086c0();
    uVar10 = FUN_0000b690();
    local_a08 = FUN_000084fe((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0x60000000,DAT_0000d65c,
                             uVar1,uVar4,uVar5,uVar6,uVar9,uVar10);
    local_a00 = FUN_0000841a((int)local_a08,(int)((ulonglong)local_a08 >> 0x20),0,DAT_0000d660);
    uVar1 = FUN_00008748();
    *param_4 = uVar1;
  }
  return uVar7 != 0x7e;
}


/* ===== FUN_0000d664 @ 0000d664 ===== */

void FUN_0000d664(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    for (uVar2 = 0; (int)uVar2 < param_1 / 2; uVar2 = uVar2 + 1 & 0xff) {
      uVar3 = *(undefined4 *)(param_3 + uVar1 * 0x100 + uVar2 * 4);
      *(undefined4 *)(param_3 + uVar1 * 0x100 + uVar2 * 4) =
           *(undefined4 *)(param_3 + uVar1 * 0x100 + (uVar2 + param_1 / 2) * 4);
      *(undefined4 *)(param_3 + uVar1 * 0x100 + (uVar2 + param_1 / 2) * 4) = uVar3;
    }
  }
  return;
}


/* ===== FUN_0000d6c0 @ 0000d6c0 ===== */

void FUN_0000d6c0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    for (uVar2 = 0; (int)uVar2 < param_1 / 2; uVar2 = uVar2 + 1 & 0xff) {
      uVar3 = *(undefined4 *)(param_3 + uVar1 * 0x80 + uVar2 * 4);
      *(undefined4 *)(param_3 + uVar1 * 0x80 + uVar2 * 4) =
           *(undefined4 *)(param_3 + uVar1 * 0x80 + (uVar2 + param_1 / 2) * 4);
      *(undefined4 *)(param_3 + uVar1 * 0x80 + (uVar2 + param_1 / 2) * 4) = uVar3;
    }
  }
  return;
}


/* ===== FUN_0000d73c @ 0000d73c ===== */

void FUN_0000d73c(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000d750;
  *(uint *)(DAT_0000d750 + 0x28) = (param_2 << 2 | 0xe0U) + 3;
  *(undefined4 *)(iVar1 + 0x20) = param_1;
  return;
}


/* ===== FUN_0000d754 @ 0000d754 ===== */

undefined8 FUN_0000d754(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *(char *)(param_1 + 2) = (char)param_2;
  *(char *)(param_1 + 3) = (char)param_3;
  *(int *)(param_1 + 0x34) = param_2 * 0xe;
  *(int *)(param_1 + 0x38) = param_3 * 0xe;
  FUN_0001162c(*(undefined *)(param_1 + 2),*(undefined *)(param_1 + 3),param_3,param_4,param_1,
               param_2,param_3,param_4);
  FUN_00011604(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
  FUN_000101a4(1,*(undefined *)(param_1 + 2),*(undefined *)(param_1 + 3),1,1);
  uVar1 = 8;
  uVar2 = 10;
  FUN_0000bd3c(8,8,8);
  FUN_0000c974(100,0);
  FUN_000115e4(param_4);
  if (param_4 == 0) {
    *DAT_0000d7d8 = *DAT_0000d7d8 & 0xfffeffff;
  }
  else {
    *DAT_0000d7d8 = *DAT_0000d7d8 | 0x10000;
  }
  return CONCAT44(uVar2,uVar1);
}


/* ===== FUN_0000d7f4 @ 0000d7f4 ===== */

void FUN_0000d7f4(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    FUN_0000d840(param_1,param_3 + iVar1 * param_1 * 4,param_4 + iVar1 * param_1 * 4,param_5,param_6
                );
  }
  *(uint *)(DAT_0000d83c + 8) = *(uint *)(DAT_0000d83c + 8) & 0xfffffbff;
  return;
}


/* ===== FUN_0000d840 @ 0000d840 ===== */

undefined8 FUN_0000d840(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0000d98c;
  *(uint *)(DAT_0000d98c + 8) = DAT_0000d988 | param_1 | 0x100000;
  *(undefined4 *)(iVar1 + 4) = 4;
  *DAT_0000d990 = 1;
  iVar1 = (int)param_1 >> 0x1f;
  FUN_0000d084(0,param_2,DAT_0000d994,param_4,4,(param_1 - iVar1) * 0x8000 >> 0x10,0,1);
  do {
  } while (*(uint *)(DAT_0000d998 + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000d1e0(0);
  FUN_0000d084(0,((int)param_1 / 2) * param_4 + param_2,DAT_0000d99c,param_4,4,
               (param_1 - iVar1) * 0x8000 >> 0x10,0,1);
  do {
  } while (*(uint *)(DAT_0000d998 + 0x18) < (uint)((int)param_1 / 2));
  do {
  } while (*DAT_0000d990 == 1);
  FUN_0000d1e0(0);
  FUN_0000d084(0,DAT_0000d994,param_3,4,param_5,(param_1 - iVar1) * 0x8000 >> 0x10,0,1);
  do {
  } while (*(uint *)(DAT_0000d998 + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000d1e0(0);
  uVar2 = (param_1 - iVar1) * 0x8000 >> 0x10;
  FUN_0000d084(0,DAT_0000d99c,((int)param_1 / 2) * param_5 + param_3,4,param_5,uVar2,0,1);
  do {
  } while (*(uint *)(DAT_0000d998 + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000d1e0(0);
  *DAT_0000d990 = 1;
  return CONCAT44(uVar2,param_5);
}


/* ===== FUN_0000d9a0 @ 0000d9a0 ===== */

undefined8 FUN_0000d9a0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar3 = uVar2 - 0x3ff;
  if (0x13 < (int)uVar3) {
    cVar4 = 0x32 < uVar3;
    if (0x33 < (int)uVar3) {
      return CONCAT44(param_2,param_1);
    }
    uVar2 = 0xffffffff >> (uVar2 - 0x413 & 0xff);
    if ((param_1 & uVar2) == 0) {
      return CONCAT44(param_2,param_1);
    }
    FUN_00008414(param_1,param_2,DAT_0000da6c,DAT_0000da70);
    FUN_00008718();
    if (cVar4 == '\0') {
      uVar1 = param_1;
      if ((int)param_2 < 0) {
        if (uVar3 == 0x14) {
          param_2 = param_2 + 1;
        }
        else {
          uVar1 = (1 << (0x34 - uVar3 & 0xff)) + param_1;
          if (uVar1 < param_1) {
            param_2 = param_2 + 1;
          }
        }
      }
      param_1 = uVar1 & ~uVar2;
    }
    goto LAB_0000da64;
  }
  cVar4 = '\x01';
  if ((int)uVar3 < 0) {
    FUN_000082cc();
    FUN_00008718();
    if (cVar4 != '\0') goto LAB_0000da64;
    if (-1 < (int)param_2) {
      param_1 = 0;
      param_2 = param_1;
      goto LAB_0000da64;
    }
    uVar2 = DAT_0000da74;
    if ((param_2 & 0x7fffffff | param_1) == 0) goto LAB_0000da64;
  }
  else {
    uVar2 = DAT_0000da78 >> (uVar3 & 0xff);
    cVar4 = '\x01';
    if ((param_2 & uVar2 | param_1) == 0) {
      return CONCAT44(param_2,param_1);
    }
    FUN_000082cc();
    FUN_00008718();
    if (cVar4 != '\0') goto LAB_0000da64;
    if ((int)param_2 < 0) {
      param_2 = param_2 + (0x100000U >> (uVar3 & 0xff));
    }
    uVar2 = param_2 & ~uVar2;
  }
  param_2 = uVar2;
  param_1 = 0;
LAB_0000da64:
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_0000da7c @ 0000da7c ===== */

void FUN_0000da7c(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
                 uint param_6)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint *puVar13;
  uint unaff_r4;
  int iVar14;
  undefined uVar15;
  bool bVar16;
  undefined uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined4 uVar22;
  uint local_74;
  int local_70;
  uint local_68;
  int local_64;
  uint local_60;
  
  uVar10 = DAT_0000de10;
  if (param_5 < 0x2711) {
    if (param_5 < 0xa3d) {
      uVar12 = 0x14;
    }
    else {
      uVar12 = 0x50;
    }
  }
  else {
    uVar12 = 0x9c4;
  }
  uVar4 = FUN_000085dc(uVar12);
  uVar12 = DAT_0000de14;
  uVar5 = FUN_000085ee(param_4 * 1000);
  FUN_00008250(uVar5,uVar10);
  FUN_000086c0();
  FUN_00010514();
  uVar5 = FUN_00008748();
  uVar6 = FUN_000085ee(param_5 * 1000);
  FUN_00008250(uVar6,uVar4);
  FUN_000086c0();
  FUN_00010514();
  uVar6 = FUN_00008748();
  uVar7 = FUN_000085ee(param_3 * 1000);
  uVar8 = FUN_000081ec(uVar6,uVar4);
  uVar9 = FUN_000081ec(uVar5,uVar10);
  uVar8 = FUN_0000813c(uVar9,uVar8);
  uVar7 = FUN_0000813c(uVar8,uVar7);
  uVar12 = FUN_0000df78(uVar7,uVar12);
  uVar7 = FUN_000085ee(param_3 * 1000);
  uVar12 = FUN_000081e0(uVar7,uVar12);
  uVar10 = FUN_00008250(uVar12,uVar10);
  uVar18 = FUN_000086c0(uVar10);
  uVar19 = FUN_0000861a(param_2);
  uVar20 = FUN_0000841a((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),DAT_0000de18,DAT_0000de1c,
                        uVar19);
  uVar22 = (undefined4)uVar18;
  FUN_000084fe((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar22,(int)((ulonglong)uVar18 >> 0x20),
               uVar19,uVar20);
  FUN_00010514();
  uVar12 = FUN_00008748();
  uVar7 = FUN_000081ec(uVar12,uVar10);
  FUN_00008250(uVar7,uVar5);
  FUN_000086c0();
  FUN_00010514();
  uVar8 = FUN_00008748();
  puVar1 = DAT_0000de20;
  *DAT_0000de20 = param_6 & 0xff;
  puVar1[1] = (param_6 << 0x10) >> 0x18;
  FUN_000081ec(param_1,DAT_0000de24);
  uVar18 = FUN_000086c0();
  uVar19 = FUN_00010514();
  uVar9 = FUN_0000868e();
  uVar20 = FUN_0000861a(uVar9);
  uVar21 = FUN_0000840e((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,DAT_0000de28,uVar20);
  uVar18 = FUN_0000841a((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),0,DAT_0000de2c,uVar20,uVar21,
                        uVar22,uVar7,uVar18,uVar19);
  FUN_000084fe((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,DAT_0000de30);
  FUN_00010514();
  uVar11 = FUN_0000868e();
  puVar1 = DAT_0000de20;
  DAT_0000de20[8] = uVar11 & 0xff;
  puVar13 = puVar1 + 9;
  *puVar13 = (uVar11 << 0x10) >> 0x18;
  uVar17 = (uint *)0xfffffffb < puVar13;
  puVar1[10] = (uVar11 << 9) >> 0x19;
  FUN_0000861a(uVar9);
  uVar15 = 1;
  uVar18 = FUN_0000dee4();
  FUN_00008718((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_0000de38,DAT_0000de3c);
  for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
    bVar16 = false;
    local_64 = 1;
    if (iVar14 == 0) {
      bVar16 = true;
      unaff_r4 = 0;
      FUN_000081e0(uVar10,0x3f800000);
      local_60 = FUN_00008666();
      local_68 = FUN_00008666(uVar12);
      local_74 = (uint)((bool)uVar17 && !(bool)uVar15);
      local_70 = 0;
    }
    else if (iVar14 == 1) {
      bVar16 = param_4 != 0;
      if (bVar16) {
        unaff_r4 = unaff_r4 + 1 & 0xff;
        FUN_000081e0(uVar5,0x3f800000);
        local_60 = FUN_00008666();
        local_68 = FUN_00008666(uVar8);
        local_74 = 0;
        local_70 = 1;
      }
    }
    else if ((iVar14 == 2) && (bVar16 = param_5 != 0, bVar16)) {
      unaff_r4 = unaff_r4 + 1 & 0xff;
      FUN_000081e0(uVar6,0x3f800000);
      local_60 = FUN_00008666();
      local_68 = 0;
      local_74 = (uint)((bool)uVar17 && !(bool)uVar15);
      uVar7 = FUN_00008250(uVar4,DAT_0000de40);
      FUN_000081e0(uVar7,0x3f800000);
      local_64 = FUN_00008666();
      local_70 = 3;
    }
    iVar2 = DAT_0000de44;
    if (bVar16) {
      *(uint *)(DAT_0000de44 + unaff_r4 * 0x14 + 0x840) = local_60 & 0xff;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x844) = (local_60 << 0x10) >> 0x18;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x848) =
           (uint)(local_64 << 0x1c) >> 0x18 | local_70 << 2 | local_74 << 1 |
           (local_60 << 0xf) >> 0x1f;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x84c) =
           (uint)(local_64 << 0x18) >> 0x1c | (local_68 & 0xf) << 4;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x850) = (local_68 << 0x14) >> 0x18;
    }
  }
  DAT_0000de20[2] = unaff_r4;
  if (param_6 == 0) {
    FUN_0000de4c(0);
  }
  else {
    FUN_0000de4c(1);
  }
  piVar3 = DAT_0000de48;
  uVar11 = DAT_0000de20[2] + 1;
  iVar14 = (1 << (uVar11 & 0xff)) + -1;
  *DAT_0000de48 = iVar14;
  piVar3[1] = iVar14 << (uVar11 & 0xff);
  DAT_0000de48[-5] = (int)(piVar3 + 1) >> 0xe | uVar11 * 2;
  return;
}


/* ===== FUN_0000de4c @ 0000de4c ===== */

void FUN_0000de4c(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_0000deb8;
  if (param_1 == 1) {
    *DAT_0000deb8 = *DAT_0000deb8 & 0xffffff7c;
    *DAT_0000deb8 = *puVar1 | param_2 << 1 | 0xc0U;
    DAT_0000deb8[7] = DAT_0000deb8[7] | 0x80;
  }
  else {
    *DAT_0000deb8 = *DAT_0000deb8 & 0xffffff7c;
    *DAT_0000deb8 = *puVar1 | (param_2 << 1 | 0x80U) + 1 | 0x40;
    DAT_0000deb8[7] = DAT_0000deb8[7] & 0xffffff7f;
  }
  return;
}


/* ===== FUN_0000debc @ 0000debc ===== */

void FUN_0000debc(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0000dee0;
  *(uint *)(DAT_0000dee0 + 0x204) = *DAT_0000dedc & 0xfffffff3;
  *(uint *)(iVar1 + 0x204) = *(uint *)(iVar1 + 0x204) | param_1 << 2;
  return;
}


/* ===== FUN_0000dee4 @ 0000dee4 ===== */

undefined4 FUN_0000dee4(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (((-1 < (int)(0x7ff00000 - ((uint)(param_1 != 0) | param_2 & 0x7fffffff))) &&
      (-1 < (int)(0x7ff00000 - ((uint)(param_3 != 0) | param_4 & 0x7fffffff)))) &&
     ((DAT_0000df74 == param_2 * 2 && param_1 == 0 || ((param_4 & 0x7fffffff) == 0 && param_3 == 0))
     )) {
    FUN_00009de0(1);
    uVar1 = FUN_000084fe(0,0,0,0);
    return uVar1;
  }
  uVar3 = FUN_00008bc0(param_1,param_2);
  uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  uVar1 = (undefined4)uVar3;
  if (((~(uVar2 >> 0x14) & 0x7ff) != 0) && ((int)param_2 >> 0x1f != (int)uVar2 >> 0x1f)) {
    uVar1 = FUN_00008414(param_3,uVar2 & 0x80000000 | param_4 & 0x7fffffff,uVar1,uVar2);
  }
  return uVar1;
}


/* ===== FUN_0000df78 @ 0000df78 ===== */

void FUN_0000df78(uint param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  
  if ((-1 < (int)(0x7f800000 - (param_1 & 0x7fffffff))) &&
     (-1 < (int)(0x7f800000 - (param_2 & 0x7fffffff)))) {
    bVar2 = (param_1 & 0x7fffffff) == 0x7f800000;
    if (!bVar2) {
      bVar2 = (param_2 & 0x7fffffff) == 0;
    }
    if (bVar2) {
      FUN_00009de0(1);
      FUN_00008250(0);
      return;
    }
  }
  uVar1 = FUN_0000895a(param_1);
  if ((~(uVar1 >> 0x17) & 0xff) == 0) {
    return;
  }
  if ((int)param_1 >> 0x1f == (int)uVar1 >> 0x1f) {
    return;
  }
  FUN_000081e6(uVar1 & 0x80000000 | param_2 & 0x7fffffff,uVar1);
  return;
}


/* ===== FUN_0000e000 @ 0000e000 ===== */

void FUN_0000e000(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 - 4);
    piVar1 = *DAT_0000e04c;
    piVar4 = (int *)0x0;
    while ((piVar3 = piVar1, piVar3 != (int *)0x0 && (piVar3 <= piVar2))) {
      piVar4 = piVar3;
      piVar1 = (int *)piVar3[1];
    }
    if (piVar4 == (int *)0x0) {
      *DAT_0000e04c = piVar2;
    }
    else if ((int)piVar2 - (int)piVar4 == *piVar4) {
      *piVar4 = *piVar2 + *piVar4;
      piVar2 = piVar4;
    }
    else {
      piVar4[1] = (int)piVar2;
    }
    if ((piVar3 != (int *)0x0) && ((int)piVar3 - (int)piVar2 == *piVar2)) {
      *piVar2 = *piVar2 + *piVar3;
      piVar3 = (int *)piVar3[1];
    }
    piVar2[1] = (int)piVar3;
  }
  return;
}


/* ===== FUN_0000e050 @ 0000e050 ===== */

int FUN_0000e050(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 < 4) {
    iVar1 = param_1 * 0xd + DAT_0000e068;
  }
  return iVar1;
}


/* ===== FUN_0000e06c @ 0000e06c ===== */

undefined FUN_0000e06c(void)

{
  return *DAT_0000e074;
}


/* ===== FUN_0000e078 @ 0000e078 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0000e078(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_r3;
  undefined4 local_c;
  
  local_c = in_r3;
  FUN_0000e96e(1);
  puVar1 = _DAT_0000e0e4;
  FUN_0000e858(*_DAT_0000e0e4,_DAT_0000e0e4[1],_DAT_0000e0e4[2],_DAT_0000e0e4[3],
               *(undefined4 *)(_DAT_0000e0e4 + 0x24),*(undefined4 *)(_DAT_0000e0e4 + 0x28),
               *(undefined4 *)(_DAT_0000e0e4 + 0x2c));
  local_c = FUN_0000e144();
  FUN_0000fbb4("gpadcValue = %d",local_c);
  FUN_000099c4(0xa14,&local_c,4);
  FUN_0000e96e(1,0);
  uVar2 = *(undefined4 *)(puVar1 + 0x28);
  uVar3 = *(undefined4 *)(puVar1 + 0x24);
  FUN_0000e858(0,0,0);
  return CONCAT44(uVar2,uVar3);
}


/* ===== FUN_0000e0f8 @ 0000e0f8 ===== */

void FUN_0000e0f8(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0000bcc0(1,param_2,param_3,0);
  *(uint *)(DAT_0000e13c + 0x134) = *DAT_0000e138 & 0xfffffff0 | 2;
  *(uint *)(DAT_0000e140 + 0xc) = *(uint *)(DAT_0000e140 + 0xc) & 0xfff0ffff | 0x50000;
  DAT_0000e138[-0x17] = 1 << (param_1 + 7U & 0xff) | 1;
  return;
}


/* ===== FUN_0000e144 @ 0000e144 ===== */

uint FUN_0000e144(void)

{
  FUN_0000e0f8(1);
  FUN_0000c974(0x3c,0);
  FUN_0000c974(0x3c,0);
  FUN_0000c974(0x3c,0);
  return *DAT_0000e180 & 0xff;
}


/* ===== FUN_0000e184 @ 0000e184 ===== */

void FUN_0000e184(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(DAT_0000e1cc + param_1 * 4 + 0x30) = 0;
  }
  else if (param_2 == 1) {
    *(undefined4 *)(DAT_0000e1cc + param_1 * 4 + 0x30) = 0x30;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(DAT_0000e1cc + param_1 * 4 + 0x30) = 0x10;
  }
  else if (param_2 == 3) {
    *(undefined4 *)(DAT_0000e1cc + param_1 * 4 + 0x30) = 0x20;
  }
  return;
}


/* ===== FUN_0000e1d4 @ 0000e1d4 ===== */

void FUN_0000e1d4(uint param_1,int param_2)

{
  if (param_2 == 1) {
    *(uint *)(DAT_0000e1f8 + 0x20) = *(uint *)(DAT_0000e1f8 + 0x20) | 1 << (param_1 & 0xff);
  }
  else {
    *(uint *)(DAT_0000e1f8 + 0x24) = *(uint *)(DAT_0000e1f8 + 0x24) | 1 << (param_1 & 0xff);
  }
  return;
}


/* ===== FUN_0000e1fc @ 0000e1fc ===== */

void FUN_0000e1fc(int param_1,int param_2)

{
  *(uint *)(DAT_0000e210 + param_1 * 4 + 0x30) = 1 << (param_2 + 6U & 0xff) | 0x10;
  return;
}


/* ===== FUN_0000e214 @ 0000e214 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000e214(void)

{
  uint in_r3;
  uint local_8 [2];
  
  local_8[0] = in_r3;
  FUN_0000e258();
  FUN_0000c974(100,0);
  local_8[0] = *(uint *)(_DAT_0000e244 + 0x2c) & 0x7fffffff;
  FUN_000099c4(0xa15,local_8,4);
  FUN_0000fbb4("gpioStatus = %x",local_8[0]);
  return;
}


/* ===== FUN_0000e258 @ 0000e258 ===== */

void FUN_0000e258(void)

{
  FUN_0000e184(2,1);
  FUN_0000e184(3,1);
  FUN_0000e184(4,1);
  FUN_0000e184(5,1);
  FUN_0000e184(6,1);
  FUN_0000e184(7,1);
  FUN_0000e184(8,1);
  FUN_0000e184(9,1);
  FUN_0000e184(0xd,1);
  FUN_0000e184(0xe,1);
  FUN_0000e184(0xf,1);
  FUN_0000e184(0x10,1);
  FUN_0000e184(0x11,1);
  FUN_0000e184(0x12,1);
  FUN_0000e184(0x14,1);
  FUN_0000e184(0x15,1);
  FUN_0000e184(10,1);
  FUN_0000e184(0xb,1);
  FUN_0000e184(0x17,1);
  FUN_0000e184(0x18,1);
  FUN_0000e184(0x19,1);
  FUN_0000e184(0x1a,1);
  FUN_0000e184(0x1b,1);
  FUN_0000e184(0x1c,1);
  FUN_0000e184(0x1d,1);
  FUN_0000e184(0x1e,1);
  return;
}


/* ===== FUN_0000e330 @ 0000e330 ===== */

void FUN_0000e330(void)

{
  FUN_000112cc();
  FUN_0000b380();
  FUN_0000b3cc();
  FUN_0000b164();
  FUN_0000bd88();
  return;
}


/* ===== FUN_0000e348 @ 0000e348 ===== */

void FUN_0000e348(void)

{
  *(undefined4 *)(DAT_0000e354 + 0x24) = DAT_0000e350;
  return;
}


/* ===== FUN_0000e358 @ 0000e358 ===== */

void FUN_0000e358(void)

{
  *(undefined4 *)(DAT_0000e364 + 0x20) = DAT_0000e360;
  return;
}


/* ===== FUN_0000e368 @ 0000e368 ===== */

void FUN_0000e368(void)

{
  FUN_0000e184(2,0);
  FUN_0000e184(3,0);
  FUN_0000e184(4,0);
  FUN_0000e184(5,0);
  FUN_0000e184(6,0);
  FUN_0000e184(7,0);
  FUN_0000e184(8,0);
  FUN_0000e184(9,0);
  FUN_0000e184(10,0);
  FUN_0000e184(0xb,0);
  FUN_0000e184(0xc,0);
  FUN_0000e184(0xd,0);
  FUN_0000e184(0xe,0);
  FUN_0000e184(0xf,0);
  FUN_0000e184(0x10,0);
  FUN_0000e184(0x11,0);
  return;
}


/* ===== FUN_0000e3ec @ 0000e3ec ===== */

void FUN_0000e3ec(int param_1,int param_2)

{
  *(uint *)(DAT_0000e410 + 0x114) =
       (*DAT_0000e40c & 0xfffff0ff | param_1 << 8) & 0xffff0fff | param_2 << 0xc;
  return;
}


/* ===== FUN_0000e414 @ 0000e414 ===== */

void FUN_0000e414(void)

{
  return;
}


/* ===== FUN_0000e418 @ 0000e418 ===== */

void FUN_0000e418(uint param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 extraout_r1;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  char cVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  uVar16 = CONCAT44(param_2,param_1);
  iVar13 = 0;
  if ((int)param_2 < (int)DAT_0000e740) {
    uVar12 = param_2 & 0x7fffffff;
    if ((uVar12 <= DAT_0000e740) && ((uVar12 != DAT_0000e740 || (param_1 == 0)))) {
      if ((int)param_2 < 0x100000) {
        if ((uVar12 | param_1) == 0) {
          FUN_00009de0(2);
          FUN_00009c08();
          return;
        }
        if ((int)param_2 < 0) {
          FUN_00009de0(1);
          FUN_000084fe(0,0,0,0);
          return;
        }
        iVar13 = -0x36;
        uVar16 = FUN_00008a66(param_1,param_2,0x36);
      }
      uVar12 = (uint)((ulonglong)uVar16 >> 0x20);
      uVar14 = uVar12 & 0xfffff;
      uVar11 = DAT_0000e744 + uVar14 & 0x100000;
      iVar13 = iVar13 + ((int)uVar12 >> 0x14) + -0x3ff + ((int)uVar11 >> 0x14);
      uVar16 = FUN_0000840e((int)uVar16,uVar11 ^ 0x3ff00000 | uVar14,0,DAT_0000e748);
      uVar6 = (undefined4)((ulonglong)uVar16 >> 0x20);
      uVar1 = (undefined4)uVar16;
      uVar12 = uVar14 + 2 & 0xfffff;
      cVar15 = uVar12 == 3;
      if (2 < uVar12) {
        uVar16 = FUN_000082cc(uVar1,uVar6,0,0x40000000);
        uVar16 = FUN_000084fe(uVar1,uVar6,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
        uVar7 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar2 = (undefined4)uVar16;
        uVar16 = FUN_000085f8(iVar13);
        uVar8 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar3 = (undefined4)uVar16;
        uVar16 = FUN_0000841a(uVar2,uVar7,uVar2,uVar7);
        uVar9 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar4 = (undefined4)uVar16;
        uVar12 = DAT_0000e768 + uVar14;
        uVar16 = FUN_0000841a(uVar4,uVar9,uVar4,uVar9);
        uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar5 = (undefined4)uVar16;
        uVar16 = FUN_00009b5e(DAT_0000e76c + 0xe5ea,3,uVar5,uVar10);
        uVar16 = FUN_0000841a((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar5,uVar10);
        uVar17 = FUN_00009b5e(DAT_0000e770 + 0xe604,4,uVar5,uVar10);
        uVar17 = FUN_0000841a((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar4,uVar9);
        uVar16 = FUN_000082cc((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                              (int)((ulonglong)uVar16 >> 0x20));
        uVar5 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar4 = (undefined4)uVar16;
        if ((int)(uVar12 | 0x6b851 - uVar14) < 1) {
          if (iVar13 == 0) {
            uVar16 = FUN_0000840e(uVar1,uVar6,uVar4,uVar5);
            uVar16 = FUN_0000841a((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar2,uVar7);
            FUN_00008414((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar1,uVar6);
            return;
          }
          uVar16 = FUN_0000841a(uVar3,uVar8,DAT_0000e750,DAT_0000e754);
          uVar17 = FUN_0000840e(uVar1,uVar6,uVar4,uVar5);
          uVar17 = FUN_0000841a((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar7);
          uVar16 = FUN_0000840e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                                (int)((ulonglong)uVar16 >> 0x20));
          uVar16 = FUN_0000840e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar1,uVar6);
          uVar17 = FUN_0000841a(uVar3,uVar8,DAT_0000e758,DAT_0000e75c);
          FUN_0000840e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                       (int)((ulonglong)uVar16 >> 0x20));
          return;
        }
        uVar16 = FUN_00008a66(uVar1,uVar6,0xffffffff);
        uVar16 = FUN_0000841a((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar1,uVar6);
        uVar10 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar9 = (undefined4)uVar16;
        if (iVar13 == 0) {
          uVar16 = FUN_000082cc(uVar9,uVar10,uVar4,uVar5);
          uVar16 = FUN_0000841a((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar2,uVar7);
          uVar16 = FUN_00008414((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar10);
          FUN_00008414((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar1,uVar6);
          return;
        }
        uVar16 = FUN_0000841a(uVar3,uVar8,DAT_0000e750,DAT_0000e754);
        uVar17 = FUN_000082cc(uVar9,uVar10,uVar4,uVar5);
        uVar17 = FUN_0000841a((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar2,uVar7);
        uVar16 = FUN_000082cc((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                              (int)((ulonglong)uVar16 >> 0x20));
        uVar16 = FUN_00008414((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar9,uVar10);
        uVar16 = FUN_0000840e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar1,uVar6);
        uVar17 = FUN_0000841a(uVar3,uVar8,DAT_0000e758,DAT_0000e75c);
        FUN_0000840e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                     (int)((ulonglong)uVar16 >> 0x20));
        return;
      }
      FUN_000086e8(uVar1,uVar6,*(undefined4 *)(DAT_0000e74c + 0xe4ba),
                   *(undefined4 *)(DAT_0000e74c + 0xe4be));
      if (cVar15 == '\0') {
        uVar16 = FUN_0000841a(uVar1,uVar6,0x55555555,DAT_0000e760);
        uVar16 = FUN_00008414((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,DAT_0000e764);
        uVar17 = FUN_0000841a(uVar1,uVar6);
        uVar16 = FUN_0000841a((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                              (int)((ulonglong)uVar16 >> 0x20));
        uVar2 = (undefined4)((ulonglong)uVar16 >> 0x20);
        if (iVar13 == 0) {
          FUN_0000840e(uVar1,uVar6,(int)uVar16,uVar2);
          return;
        }
        uVar17 = FUN_000085f8();
        uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
        uVar18 = FUN_0000841a((int)uVar17,uVar3,DAT_0000e750,DAT_0000e754);
        uVar16 = FUN_00008414((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,uVar2);
        uVar16 = FUN_0000840e((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar1,uVar6);
        uVar17 = FUN_0000841a((int)uVar17,uVar3,DAT_0000e758,DAT_0000e75c);
        FUN_0000840e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,
                     (int)((ulonglong)uVar16 >> 0x20));
        return;
      }
      if (iVar13 != 0) {
        uVar16 = FUN_000085f8(iVar13,extraout_r1);
        uVar1 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar17 = FUN_0000841a((int)uVar16,uVar1,DAT_0000e750,DAT_0000e754);
        uVar16 = FUN_0000841a((int)uVar16,uVar1,DAT_0000e758,DAT_0000e75c);
        FUN_000082cc((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,
                     (int)((ulonglong)uVar17 >> 0x20));
        return;
      }
      return;
    }
  }
  FUN_00008a66(param_1,param_2,1);
  return;
}


/* ===== FUN_0000e774 @ 0000e774 ===== */

void FUN_0000e774(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  
  uVar5 = CONCAT44(param_2,param_1);
  iVar4 = 0;
  if ((int)param_2 < (int)DAT_0000e83c) {
    uVar2 = param_2 & 0x7fffffff;
    if ((uVar2 <= DAT_0000e83c) && ((uVar2 != DAT_0000e83c || (param_1 == 0)))) {
      if ((int)param_2 < 0x100000) {
        if ((uVar2 | param_1) == 0) {
          FUN_00009de0(2);
          FUN_00009c08();
          return;
        }
        if ((int)param_2 < 0) {
          FUN_00009de0(1);
          FUN_000084fe(0,0,0,0);
          return;
        }
        iVar4 = -0x36;
        uVar5 = FUN_00008a66(param_1,param_2,0x36);
      }
      uVar2 = (uint)((ulonglong)uVar5 >> 0x20);
      iVar3 = iVar4 + ((int)uVar2 >> 0x14) + -0x3ff;
      iVar4 = iVar3 >> 0x1f;
      uVar6 = FUN_000085f8(iVar3 - iVar4);
      uVar1 = (undefined4)((ulonglong)uVar6 >> 0x20);
      uVar5 = FUN_0000e418((int)uVar5,uVar2 & 0xfffff | (iVar4 + 0x3ff) * 0x100000);
      uVar5 = FUN_0000841a((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_0000e840,DAT_0000e844);
      uVar7 = FUN_0000841a((int)uVar6,uVar1,DAT_0000e848,DAT_0000e84c);
      uVar5 = FUN_000082cc((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar5,
                           (int)((ulonglong)uVar5 >> 0x20));
      uVar6 = FUN_0000841a((int)uVar6,uVar1,DAT_0000e850,DAT_0000e854);
      FUN_000082cc((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                   (int)((ulonglong)uVar5 >> 0x20));
      return;
    }
  }
  FUN_00008a66(param_1,param_2,1);
  return;
}


/* ===== FUN_0000e858 @ 0000e858 ===== */

void FUN_0000e858(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = param_1 << 3;
  iVar2 = param_1 * 7;
  iVar4 = param_2 << 3;
  iVar3 = param_2 * 7;
  uVar5 = param_1 | param_2 | param_3 | param_4;
  iVar1 = uVar5 * 0xf;
  FUN_0000c918(uVar5,uVar5 != 1);
  FUN_0000bcc0(param_1 | param_2);
  FUN_00010368(param_1,param_2);
  FUN_00010340((param_1 | param_2) << 3,param_2 << 3);
  FUN_0001042c(param_1,param_2);
  FUN_00010404((param_1 | param_2) << 3,param_2 << 3);
  FUN_0000f1bc(param_1,param_2,param_7);
  FUN_0000ac10(param_1 | param_2,param_2);
  FUN_0000aa4c(iVar2,iVar2,iVar2,iVar6,iVar6,iVar6,iVar3,iVar3,iVar3,iVar4,iVar4,iVar4);
  FUN_00010774(param_1,param_2);
  FUN_0000ed30(param_1,param_2);
  FUN_000104c8(param_1 | param_2 | param_3 | param_4,param_1 | param_2 | param_3 | param_4);
  FUN_000101a4(uVar5,param_3,param_4,param_1,param_2);
  FUN_0000bd3c(iVar1,iVar1,iVar1,iVar1,iVar1,iVar1,iVar1,iVar1);
  FUN_0001162c(param_3,param_4);
  return;
}


/* ===== FUN_0000e96e @ 0000e96e ===== */

void FUN_0000e96e(int param_1,int param_2)

{
  FUN_0000fb74(param_2);
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000c974(10,0);
  }
  FUN_0000f730(param_2);
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000c974(1,0);
  }
  FUN_0000faac(param_2);
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000c974(1,0);
  }
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000c974(0x32,0);
  }
  return;
}


/* ===== FUN_0000e9c8 @ 0000e9c8 ===== */

void FUN_0000e9c8(uint param_1,uint param_2,uint param_3,uint param_4)

{
  param_4 = param_1 | param_2 | param_3 | param_4;
  if (param_4 == 0) {
    FUN_0000e1d4(0x16,0);
    FUN_0000e1d4(0x1d,0);
    FUN_0000fb2c(0);
    FUN_0000fad8(0,3);
    FUN_0000bcec(0,0,0);
    FUN_0000f7b8(0);
    *DAT_0000eaf8 = 0x888;
    *(undefined4 *)(DAT_0000eafc + 0x158) = 0;
    *(uint *)(DAT_0000eb00 + 0x1c) = *(uint *)(DAT_0000eb00 + 0x1c) | 0x10;
    FUN_0000c974(100,0);
    *(uint *)(DAT_0000eb00 + 0x1c) = *(uint *)(DAT_0000eb00 + 0x1c) & 0xffffffef;
  }
  else {
    FUN_0000e1d4(0x16,1);
    FUN_0000e1d4(0x1d,1);
    FUN_0000c974(200,0);
    FUN_0000f7b8(1);
    FUN_0000c974(100,0);
    FUN_0000fb2c(1,0);
    FUN_0000c974(100,0);
    FUN_0000fad8(1,3,param_4);
    FUN_0000c974(100,0);
    FUN_0000bcec(param_1,0,0);
    FUN_0000c974(100,0);
    FUN_0000bcec(param_1,0,param_2);
    FUN_0000c974(100,0);
    *DAT_0000eaf8 = 0x8f8;
    *(undefined4 *)(DAT_0000eafc + 0x158) = DAT_0000eb04;
    *(uint *)(DAT_0000eb00 + 0x1c) = *(uint *)(DAT_0000eb00 + 0x1c) | 0x10;
    FUN_0000c974(100,0);
    *(uint *)(DAT_0000eb00 + 0x1c) = *(uint *)(DAT_0000eb00 + 0x1c) & 0xffffffef;
  }
  return;
}


/* ===== FUN_0000eb08 @ 0000eb08 ===== */

void FUN_0000eb08(void)

{
  undefined4 uVar1;
  undefined auStack_18 [24];
  
  FUN_0000913c(0,0x8000);
  *DAT_0000ebd0 = 3;
  *DAT_0000ebd4 = 6;
  *DAT_0000ebd8 = 0;
  FUN_0000e330();
  do {
    do {
      while (*DAT_0000ebdc == '\0') {
        FUN_000105e0();
        FUN_0000c1d4();
        *DAT_0000ebdc = '\x01';
      }
    } while (*DAT_0000ebdc != '\x01');
    uVar1 = FUN_0000c700();
    switch(uVar1) {
    case 0:
      break;
    case 1:
      FUN_0000b2c8();
      break;
    case 2:
      FUN_0000b2c8();
      break;
    case 3:
      FUN_0000b2c8();
      break;
    case 4:
      FUN_0000b2c8();
      break;
    case 5:
      FUN_0000b2c8();
      break;
    case 6:
      FUN_0000b2c8();
      break;
    case 7:
      FUN_000119ac();
      break;
    case 8:
      FUN_0000e078();
      break;
    case 9:
      FUN_0000e214();
      break;
    case 10:
      FUN_00010e28();
      break;
    case 0xb:
      FUN_0000b02c();
      break;
    case 0xc:
      FUN_0000b02c();
      break;
    case 0xd:
      FUN_0000b05c(auStack_18,DAT_0000ebe0);
      break;
    default:
      *DAT_0000ebdc = '\0';
    }
    *DAT_0000ebdc = '\0';
  } while( true );
}


/* ===== FUN_0000ebe4 @ 0000ebe4 ===== */

uint * FUN_0000ebe4(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint **ppuVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  piVar1 = DAT_0000ec40;
  uVar3 = param_1 + 0xbU & 0xfffffff8;
  ppuVar4 = DAT_0000ec44;
  do {
    while (puVar2 = *ppuVar4, puVar2 == (uint *)0x0) {
      puVar2 = (uint *)0x0;
LAB_0000ec1c:
      puVar6 = DAT_0000ec48;
      if (puVar2 != (uint *)0x0) {
        return puVar2;
      }
      if (*piVar1 != 0) {
        return (uint *)0x0;
      }
      *DAT_0000ec44 = DAT_0000ec48;
      *puVar6 = DAT_0000ec4c - (int)puVar6 & 0xfffffff8;
      puVar6[1] = 0;
      *piVar1 = 1;
      ppuVar4 = DAT_0000ec44;
    }
    uVar5 = *puVar2;
    if (uVar3 <= uVar5) {
      if (uVar3 < uVar5) {
        puVar6 = (uint *)((int)puVar2 + uVar3);
        uVar7 = puVar2[1];
        *puVar6 = uVar5 - uVar3;
        puVar6[1] = uVar7;
      }
      else {
        puVar6 = (uint *)puVar2[1];
      }
      *ppuVar4 = puVar6;
      *puVar2 = uVar3;
      puVar2 = puVar2 + 1;
      goto LAB_0000ec1c;
    }
    ppuVar4 = (uint **)(puVar2 + 1);
  } while( true );
}


/* ===== FUN_0000ec50 @ 0000ec50 ===== */

void FUN_0000ec50(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0000ec74 + 0x20);
  while ((uVar1 & 0x70000) != 0) {
    uVar1 = *(uint *)(DAT_0000ec74 + 0x20);
  }
  *DAT_0000ec78 = 4;
  WaitForInterrupt();
  return;
}


/* ===== FUN_0000ec7c @ 0000ec7c ===== */

void FUN_0000ec7c(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(DAT_0000ecd0 + 0x28) = 0;
  *(uint *)(DAT_0000ecd8 + 0x108) = *DAT_0000ecd4 | 0x800;
  *(undefined4 *)(DAT_0000ecd0 + 4) = 3;
  FUN_0000e1d4(0x16,1);
  FUN_0000e184(0x16,0);
  iVar1 = DAT_0000ecd0;
  *(undefined4 *)(DAT_0000ecd0 + 0x24) = DAT_0000ecdc;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x50) = 0xc00;
  if (param_1 == 0) {
    *(undefined4 *)(DAT_0000ecd0 + 0x4c) = 7;
  }
  else {
    *(undefined4 *)(iVar1 + 0x4c) = 0x1f;
  }
  return;
}


/* ===== FUN_0000ece0 @ 0000ece0 ===== */

void FUN_0000ece0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5)

{
  FUN_0000d084(4,param_1,param_2,param_3,param_4,param_5,0,1);
  do {
  } while (*(uint *)(DAT_0000ed2c + 0x58) < param_5);
  FUN_0000d1e0(4);
  return;
}


/* ===== FUN_0000ed30 @ 0000ed30 ===== */

void FUN_0000ed30(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_0000ed5c | 0x10;
  }
  else {
    uVar1 = *DAT_0000ed5c & 0xffffffef;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 0x20;
  }
  else {
    uVar1 = uVar1 & 0xffffffdf;
  }
  *DAT_0000ed5c = uVar1;
  return;
}


/* ===== FUN_0000ed60 @ 0000ed60 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000ed60(int param_1,int param_2)

{
  undefined *puVar1;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_10 = param_1;
  local_c = param_2;
  if (param_1 == 0) {
    if (param_2 == 1) {
      FUN_0000d754(_DAT_0000ef3c,1,0);
      FUN_00010c6c(0);
    }
    else if (param_2 == 2) {
      FUN_0000d754(_DAT_0000ef3c,1,0);
      FUN_00010c6c(0);
    }
  }
  else if (param_1 == 1) {
    switch(param_2) {
    case 1:
      FUN_0000fbb4("noise rx0 test");
      FUN_00010c6c(1);
      FUN_0000d028();
      FUN_00011020();
      break;
    case 2:
      FUN_0000fbb4("noise rx1 test");
      FUN_00010c6c(2);
      FUN_0000d028();
      FUN_00011020();
      break;
    case 3:
      FUN_0000fbb4("tx0rx0 test");
      FUN_0000d754(_DAT_0000ef3c,1,0);
      FUN_00010c6c(3);
      break;
    case 4:
      FUN_0000fbb4("tx0rx1 test");
      FUN_0000d754(_DAT_0000ef3c,1,0);
      FUN_00010c6c(4);
      break;
    case 5:
      FUN_0000fbb4("tx1rx0 test");
      FUN_0000d754(_DAT_0000ef3c,0,1);
      FUN_00010c6c(5);
      break;
    case 6:
      FUN_0000fbb4("tx1rx1 test");
      FUN_0000d754(_DAT_0000ef3c,0,1);
      FUN_00010c6c(6);
      break;
    case 7:
      FUN_0000b380();
      FUN_0000b3cc();
      FUN_0000b164();
      FUN_0000e96e(1);
      puVar1 = _DAT_0000ef3c;
      FUN_0000e858(*_DAT_0000ef3c,_DAT_0000ef3c[1],_DAT_0000ef3c[2],_DAT_0000ef3c[3],
                   *(undefined4 *)(_DAT_0000ef3c + 0x24),*(undefined4 *)(_DAT_0000ef3c + 0x28),
                   *(undefined4 *)(_DAT_0000ef3c + 0x2c));
      local_14 = 1;
      FUN_000099c4(0xa12,&local_14,4);
      FUN_0000fbb4("VDDRF test");
      FUN_0000d754(puVar1,1,1,0);
      FUN_00010c6c(7);
      break;
    case 8:
      FUN_00010c6c(8);
      break;
    case 9:
      FUN_00010c6c(9);
      break;
    case 10:
      FUN_00010c6c(10);
      break;
    case 0xb:
      FUN_00010c6c(0xb);
      FUN_0000d754(_DAT_0000ef3c,1,1);
      break;
    case 0xc:
      FUN_00010c6c(0xc);
      FUN_0000d754(_DAT_0000ef3c,1,1);
      break;
    case 0xd:
      FUN_00010c6c(0xd);
    }
  }
  return;
}


/* ===== FUN_0000ef70 @ 0000ef70 ===== */

void FUN_0000ef70(int param_1)

{
  undefined uVar1;
  
  uVar1 = FUN_00009610();
  *(undefined *)(param_1 + 0x96) = uVar1;
  uVar1 = FUN_00009600(*(undefined *)(param_1 + 0x96),1);
  *(undefined *)(param_1 + 0x96) = uVar1;
  *(undefined *)(param_1 + 0x9a) = 0;
  *(undefined *)(param_1 + 0xc) = 3;
  *(undefined2 *)(param_1 + 0x94) = 0;
  return;
}


/* ===== FUN_0000efa4 @ 0000efa4 ===== */

void FUN_0000efa4(int param_1,int param_2,uint param_3,uint param_4,int param_5,undefined4 param_6,
                 int param_7,int param_8,int param_9)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 local_58;
  uint local_48;
  uint local_44;
  uint local_40;
  
  local_40 = 0xfff;
  local_44 = 0xfff;
  local_48 = 0;
  uVar8 = 0;
  bVar1 = false;
  local_58 = DAT_0000f0cc;
  for (iVar2 = 0; iVar2 < (int)param_4; iVar2 = iVar2 + 1) {
    iVar5 = param_1 / 2 - param_2;
    while (iVar5 = iVar5 + 1, iVar5 < param_2 + param_1 / 2) {
      *(undefined4 *)(param_5 + iVar2 * 0x100 + iVar5 * 4) = 0;
    }
  }
  for (; cVar9 = param_4 <= param_3, (int)param_3 < (int)param_4; param_3 = param_3 + 1) {
    uVar6 = 0;
    for (uVar3 = 0; (int)uVar3 < param_1; uVar3 = uVar3 + 1 & 0xffff) {
      uVar7 = *(uint *)(param_5 + param_3 * 0x100 + uVar3 * 4);
      if (uVar6 < uVar7) {
        uVar6 = uVar7;
        local_48 = uVar3;
      }
    }
    if (param_8 == 1) {
      uVar6 = uVar6 * param_3 * param_3;
    }
    if ((param_7 == 0) || ((param_7 == 1 && (!bVar1)))) {
      cVar9 = true;
    }
    else {
      cVar9 = false;
    }
    if ((uVar8 < uVar6) && ((bool)cVar9)) {
      local_40 = param_3 & 0xffff;
      local_44 = local_48;
      uVar10 = FUN_0000861a(uVar6);
      uVar11 = FUN_0000e774();
      uVar10 = FUN_0000841a((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,DAT_0000f0d0,uVar10,
                            uVar11);
      FUN_0000840e((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,DAT_0000f0d4);
      local_58 = FUN_00008748();
      FUN_00008794(local_58,param_6);
      uVar8 = uVar6;
      if (cVar9 == '\0') {
        bVar1 = true;
      }
    }
  }
  FUN_00008794(local_58,param_6);
  *(bool *)param_9 = cVar9 == '\0';
  uVar4 = FUN_00008634(local_58);
  *(undefined4 *)(param_9 + 0xc) = uVar4;
  *(uint *)(param_9 + 0x10) = uVar8;
  *(uint *)(param_9 + 4) = local_40;
  *(uint *)(param_9 + 8) = local_44;
  return;
}


/* ===== FUN_0000f0d8 @ 0000f0d8 ===== */

void FUN_0000f0d8(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_r4;
  int iVar3;
  
  FUN_0000a688(0x40,0x3c,DAT_0000f198,DAT_0000f194);
  FUN_0000a688(0x40,0x3c,DAT_0000f1a0,DAT_0000f19c);
  iVar3 = DAT_0000f194;
  if ((((*DAT_0000f1a4 != '\x01') && (*DAT_0000f1a4 != '\x03')) && (*DAT_0000f1a4 != '\x05')) &&
     (((*DAT_0000f1a4 == '\x02' || (*DAT_0000f1a4 == '\x04')) ||
      (iVar3 = unaff_r4, *DAT_0000f1a4 == '\x06')))) {
    iVar3 = DAT_0000f19c;
  }
  for (iVar1 = 0; iVar1 < 0xf00; iVar1 = iVar1 + 1) {
    *(undefined4 *)(DAT_0000f1a0 + iVar1 * 4) = *(undefined4 *)(iVar3 + iVar1 * 4);
  }
  FUN_0000d664(0x40,0x3c,DAT_0000f1a8);
  uVar2 = FUN_000085dc(*DAT_0000f1ac * 6 + *DAT_0000f1b0 * 2 + -0x3c + *DAT_0000f1b4);
  FUN_0000efa4(0x40,0,3,0x3c,DAT_0000f1a8,uVar2,0,0,DAT_0000f1b8);
  return;
}


/* ===== FUN_0000f1bc @ 0000f1bc ===== */

void FUN_0000f1bc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = DAT_0000f234;
  *(uint *)(DAT_0000f234 + 0x220) = *DAT_0000f230 & 0xffffff7f;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) | param_1 << 7;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) & 0xffffff7f;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) | param_2 << 7;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) & 0xffffff9f;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) | param_3 << 5;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) & 0xffffff9f;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) | param_4 << 5;
  return;
}


/* ===== FUN_0000f238 @ 0000f238 ===== */

void FUN_0000f238(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000f278;
  *(uint *)(DAT_0000f278 + 0x220) = *DAT_0000f274 & 0xffffffe7;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) | param_1 << 3;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) & 0xffffffe7;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) | param_2 << 3;
  return;
}


/* ===== FUN_0000f27c @ 0000f27c ===== */

void FUN_0000f27c(void)

{
  undefined4 *puVar1;
  
  *DAT_0000f2a4 = 0;
  *(undefined4 *)(DAT_0000f2a8 + 0x21c) = 0;
  puVar1 = DAT_0000f2a4;
  DAT_0000f2a4[2] = 0;
  puVar1[3] = 0;
  DAT_0000f2a4[-0x3b] = DAT_0000f2ac;
  *(undefined4 *)(DAT_0000f2a8 + 0x130) = DAT_0000f2b0;
  return;
}


/* ===== FUN_0000f2b4 @ 0000f2b4 ===== */

void FUN_0000f2b4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined in_ZR;
  undefined in_CY;
  
  uVar1 = FUN_000085dc(param_2);
  uVar2 = FUN_000085dc(param_3);
  uVar1 = FUN_0000ba64(uVar2,uVar1);
  uVar2 = FUN_000085dc(param_4);
  uVar3 = FUN_000085dc(param_5);
  uVar2 = FUN_0000ba64(uVar3,uVar2);
  uVar3 = FUN_000081e0(uVar1,uVar2);
  uVar3 = FUN_0000813c(uVar3,param_6);
  while (FUN_00008794(uVar3,DAT_0000f378), !(bool)in_CY || (bool)in_ZR) {
    uVar3 = FUN_000081e0(uVar3,DAT_0000f374);
  }
  while (FUN_00008780(uVar3,DAT_0000f37c), !(bool)in_CY || (bool)in_ZR) {
    uVar3 = FUN_0000813c(uVar3,DAT_0000f374);
  }
  uVar4 = FUN_00008250(uVar3,DAT_0000f378);
  uVar4 = FUN_0000b900(uVar4);
  uVar4 = FUN_000081ec(uVar4,DAT_0000f380);
  uVar4 = FUN_00008250(uVar4,DAT_0000f378);
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  return;
}


/* ===== FUN_0000f384 @ 0000f384 ===== */

void FUN_0000f384(ushort param_1,int param_2,undefined4 *param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  
  uVar12 = (uint)param_1;
  if (param_2 < 0x10) {
    uVar1 = (short)param_2 + 0x10;
  }
  else {
    uVar1 = (short)param_2 - 0x10;
  }
  uVar13 = (uint)uVar1;
  iVar15 = (int)*(short *)(DAT_0000f534 + (uVar13 + uVar12 * 0x20) * 4);
  iVar14 = (int)*(short *)(DAT_0000f534 + (uVar13 + uVar12 * 0x20) * 4 + 2);
  iVar6 = (int)*(short *)(DAT_0000f538 + (uVar13 + uVar12 * 0x20) * 4);
  iVar16 = (int)*(short *)(DAT_0000f538 + (uVar13 + uVar12 * 0x20) * 4 + 2);
  iVar7 = (int)*(short *)(DAT_0000f53c + (uVar13 + uVar12 * 0x20) * 4);
  iVar8 = (int)*(short *)(DAT_0000f53c + (uVar13 + uVar12 * 0x20) * 4 + 2);
  iVar9 = (int)*(short *)(DAT_0000f540 + (uVar13 + uVar12 * 0x20) * 4);
  iVar10 = (int)*(short *)(DAT_0000f540 + (uVar13 + uVar12 * 0x20) * 4 + 2);
  FUN_000085dc(iVar8);
  sVar2 = FUN_00008634();
  FUN_000085dc(iVar7);
  sVar3 = FUN_00008634();
  FUN_000085dc(iVar14);
  sVar4 = FUN_00008634();
  FUN_000085dc(iVar15);
  sVar5 = FUN_00008634();
  uVar11 = FUN_0000f6e4((int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2);
  *param_3 = uVar11;
  FUN_000085dc(iVar10);
  sVar2 = FUN_00008634();
  FUN_000085dc(iVar9);
  sVar3 = FUN_00008634();
  FUN_000085dc(iVar16);
  sVar4 = FUN_00008634();
  FUN_000085dc(iVar6);
  sVar5 = FUN_00008634();
  uVar11 = FUN_0000f6e4((int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2);
  param_3[1] = uVar11;
  FUN_000085dc(iVar16);
  sVar2 = FUN_00008634();
  FUN_000085dc(iVar6);
  sVar3 = FUN_00008634();
  FUN_000085dc(iVar14);
  sVar4 = FUN_00008634();
  FUN_000085dc(iVar15);
  sVar5 = FUN_00008634();
  uVar11 = FUN_0000f6e4((int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2);
  param_3[2] = uVar11;
  FUN_000085dc(iVar10);
  sVar2 = FUN_00008634();
  FUN_000085dc(iVar9);
  sVar3 = FUN_00008634();
  FUN_000085dc(iVar8);
  sVar4 = FUN_00008634();
  FUN_000085dc(iVar7);
  sVar5 = FUN_00008634();
  uVar11 = FUN_0000f6e4((int)sVar5,(int)sVar4,(int)sVar3,(int)sVar2);
  param_3[3] = uVar11;
  return;
}


/* ===== FUN_0000f544 @ 0000f544 ===== */

void FUN_0000f544(ushort param_1,int param_2,undefined4 *param_3)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  uVar11 = (uint)param_1;
  if (param_2 < 0x10) {
    uVar2 = (short)param_2 + 0x10;
  }
  else {
    uVar2 = (short)param_2 - 0x10;
  }
  uVar12 = (uint)uVar2;
  iVar14 = (int)*(short *)(DAT_0000f6ac + (uVar12 + uVar11 * 0x20) * 4);
  iVar13 = (int)*(short *)(DAT_0000f6ac + (uVar12 + uVar11 * 0x20) * 4 + 2);
  sVar8 = *(short *)(DAT_0000f6b0 + (uVar12 + uVar11 * 0x20) * 4);
  sVar7 = *(short *)(DAT_0000f6b0 + (uVar12 + uVar11 * 0x20) * 4 + 2);
  sVar4 = *(short *)(DAT_0000f6b4 + (uVar12 + uVar11 * 0x20) * 4);
  sVar1 = *(short *)(DAT_0000f6b8 + (uVar12 + uVar11 * 0x20) * 4);
  sVar9 = *(short *)(DAT_0000f6b8 + (uVar12 + uVar11 * 0x20) * 4 + 2);
  FUN_000085dc((int)*(short *)(DAT_0000f6b4 + (uVar12 + uVar11 * 0x20) * 4 + 2));
  sVar3 = FUN_00008634();
  FUN_000085dc((int)sVar4);
  sVar4 = FUN_00008634();
  FUN_000085dc(iVar13);
  sVar5 = FUN_00008634();
  FUN_000085dc(iVar14);
  sVar6 = FUN_00008634();
  uVar10 = FUN_0000f6e4((int)sVar6,(int)sVar5,(int)sVar4,(int)sVar3);
  *param_3 = uVar10;
  FUN_000085dc((int)sVar7);
  sVar7 = FUN_00008634();
  FUN_000085dc((int)sVar8);
  sVar8 = FUN_00008634();
  FUN_000085dc(iVar13);
  sVar4 = FUN_00008634();
  FUN_000085dc(iVar14);
  sVar3 = FUN_00008634();
  uVar10 = FUN_0000f6e4((int)sVar3,(int)sVar4,(int)sVar8,(int)sVar7);
  param_3[1] = uVar10;
  FUN_000085dc((int)sVar9);
  sVar7 = FUN_00008634();
  FUN_000085dc((int)sVar1);
  sVar9 = FUN_00008634();
  FUN_000085dc(iVar13);
  sVar8 = FUN_00008634();
  FUN_000085dc(iVar14);
  sVar4 = FUN_00008634();
  uVar10 = FUN_0000f6e4((int)sVar4,(int)sVar8,(int)sVar9,(int)sVar7);
  param_3[2] = uVar10;
  return;
}


/* ===== FUN_0000f6bc @ 0000f6bc ===== */

void FUN_0000f6bc(void)

{
  int iVar1;
  
  iVar1 = FUN_0000c700();
  if (iVar1 == 0xb) {
    FUN_0000c9c0(DAT_0000f6e0);
  }
  else {
    iVar1 = FUN_0000c700();
    if (iVar1 == 0xc) {
      FUN_0000cce0(DAT_0000f6e0);
    }
  }
  return;
}


/* ===== FUN_0000f6e4 @ 0000f6e4 ===== */

undefined4 FUN_0000f6e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_000085dc(param_1);
  uVar2 = FUN_000085dc(param_2);
  uVar1 = FUN_0000ba64(uVar2,uVar1);
  uVar2 = FUN_000085dc(param_3);
  uVar3 = FUN_000085dc(param_4);
  uVar2 = FUN_0000ba64(uVar3,uVar2);
  uVar1 = FUN_000081e0(uVar1,uVar2);
  return uVar1;
}


/* ===== FUN_0000f730 @ 0000f730 ===== */

void FUN_0000f730(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_0000f758 + 0x184) = *DAT_0000f754 | 0x18;
  }
  else {
    *(uint *)(DAT_0000f758 + 0x184) = *DAT_0000f754 & 0xffffffe7;
  }
  return;
}


/* ===== FUN_0000f75c @ 0000f75c ===== */

void FUN_0000f75c(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0000f78c;
  *DAT_0000f78c = DAT_0000f788;
  puVar1[1] = DAT_0000f794 | *(uint *)(DAT_0000f790 + 0x188) & 0xf00;
  puVar1[2] = 0x492;
  puVar1[3] = 7;
  return;
}


/* ===== FUN_0000f798 @ 0000f798 ===== */

void FUN_0000f798(void)

{
  *DAT_0000f7b0 = DAT_0000f7ac;
  *(undefined4 *)(DAT_0000f7b4 + 0x15c) = 0x44;
  return;
}


/* ===== FUN_0000f7b8 @ 0000f7b8 ===== */

void FUN_0000f7b8(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_0000f814;
  *DAT_0000f814 = 0x8f8;
  iVar2 = DAT_0000f818;
  *(int *)(DAT_0000f818 + 0x1b8) = (int)puVar1 >> 0x15;
  *(undefined4 *)(iVar2 + 0x154) = DAT_0000f814[1];
  uVar3 = 0xca0;
  if (param_1 == 1) {
    uVar3 = 0x1fa3;
  }
  DAT_0000f814[4] = uVar3;
  *(uint *)(DAT_0000f81c + 0x1c) = *(uint *)(DAT_0000f81c + 0x1c) | 0x10;
  FUN_0000c974(100,0);
  *(uint *)(DAT_0000f81c + 0x1c) = *(uint *)(DAT_0000f81c + 0x1c) & 0xffffffef;
  return;
}


/* ===== FUN_0000f820 @ 0000f820 ===== */

void FUN_0000f820(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  byte bVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  short sVar10;
  uint uVar11;
  char cVar12;
  bool bVar13;
  char cVar14;
  undefined uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  undefined4 local_58;
  undefined4 local_4c;
  int local_44;
  int local_40;
  
  sVar10 = 0;
  sVar3 = 0;
  bVar6 = 0;
  bVar1 = false;
  bVar4 = false;
  local_58 = 0;
  *(uint *)(DAT_0000fa9c + 0x188) = *DAT_0000fa98 & 0xfffff0ff;
  uVar11 = *DAT_0000fa98;
  do {
    local_40 = -1;
    local_44 = -1;
    local_4c = DAT_0000fa94;
    for (uVar9 = 0; iVar5 = DAT_0000fa9c, uVar9 < 0x10; uVar9 = uVar9 + 1 & 0xff) {
      *(uint *)(DAT_0000fa9c + 0x188) = *DAT_0000fa98 & 0xfffff0ff;
      uVar11 = *DAT_0000fa98;
      *(uint *)(iVar5 + 0x188) = uVar11 | uVar9 << 8;
      uVar8 = FUN_0000813c(param_1,local_58);
      FUN_0000da7c(uVar8,0,0x60,0xc,0,param_3);
      FUN_0000de4c(0);
      FUN_0000c974(100,0);
      bVar13 = (DAT_0000fa98[3] & 4) != 4;
      if ((param_2 == 0) || (bVar13)) {
        bVar2 = true;
      }
      else {
        uVar8 = FUN_000085ee();
        uVar7 = FUN_0000813c(param_1,local_58);
        uVar8 = FUN_0000813c(uVar7,uVar8);
        FUN_0000da7c(uVar8,0,0x60,0xc,0,param_3);
        FUN_0000de4c(0);
        FUN_0000c974(100,0);
        if ((DAT_0000fa98[3] & 4) == 4) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      }
      if ((!bVar13) && (bVar2)) {
        cVar12 = (char)uVar9;
        bVar1 = bVar2;
        if (local_40 < 0) {
          local_40 = (int)cVar12;
          local_44 = (int)cVar12;
        }
        else {
          local_44 = (int)cVar12;
          sVar10 = sVar10 + 1;
        }
      }
      if (((0 < sVar10) && (bVar1)) && (sVar3 == sVar10)) break;
      sVar3 = sVar10;
    }
    if (bVar1) {
      *DAT_0000fa98 = uVar11 | (local_40 + local_44 + 1) / 2 << 8;
    }
    else {
      cVar12 = '\0';
      bVar6 = bVar6 + 1;
      for (uVar9 = 0; iVar5 = DAT_0000fa9c, uVar9 < 0x10; uVar9 = uVar9 + 1 & 0xff) {
        *(uint *)(DAT_0000fa9c + 0x188) = *DAT_0000fa98 & 0xfffff0ff;
        uVar11 = *DAT_0000fa98;
        *(uint *)(iVar5 + 0x188) = uVar11 | uVar9 << 8;
        uVar8 = FUN_0000813c(param_1,local_58);
        FUN_0000da7c(uVar8,0,0x60,0xc,0,param_3);
        FUN_0000de4c(0);
        FUN_0000c974(100,0);
        cVar14 = 3 < (DAT_0000fa98[3] & 4);
        if ((DAT_0000fa98[3] & 4) == 4) {
          cVar12 = '\x01';
          uVar8 = FUN_00011a1c();
          FUN_00008780(uVar8,local_4c);
          if (cVar14 == '\0') {
            local_4c = uVar8;
          }
        }
      }
      uVar15 = cVar12 != '\0';
      if (cVar12 != '\0') {
        uVar16 = FUN_000086c0(local_4c);
        FUN_00008718((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0x66666666,DAT_0000faa0);
        if (!(bool)uVar15 || (bool)cVar12) {
          uVar17 = FUN_000086c0(local_58);
          FUN_0000840e((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),DAT_0000faa4,DAT_0000faa8,uVar17
                       ,uVar16);
          local_58 = FUN_00008748();
          bVar6 = 0;
        }
      }
      if (5 < bVar6) {
        bVar4 = true;
      }
    }
    if ((bVar1) || (bVar4)) {
      return;
    }
  } while( true );
}


/* ===== FUN_0000faac @ 0000faac ===== */

void FUN_0000faac(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_0000fad4 + 0x184) = *DAT_0000fad0 | 4;
  }
  else {
    *(uint *)(DAT_0000fad4 + 0x184) = *DAT_0000fad0 & 0xfffffffb;
  }
  return;
}


/* ===== FUN_0000fad8 @ 0000fad8 ===== */

void FUN_0000fad8(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 1) {
    uVar2 = *DAT_0000fb24 | 0x800;
  }
  else {
    uVar2 = *DAT_0000fb24 & 0xfffff7ff;
  }
  if (param_3 == 1) {
    uVar2 = uVar2 | 0x400;
  }
  else {
    uVar2 = uVar2 & 0xfffffbff;
  }
  *DAT_0000fb24 = uVar2;
  iVar1 = DAT_0000fb28;
  *(uint *)(DAT_0000fb28 + 0x198) = *(uint *)(DAT_0000fb28 + 0x198) & 0xffffffcf;
  DAT_0000fb24[0xe] = *(uint *)(iVar1 + 0x198) | param_2 << 4;
  return;
}


/* ===== FUN_0000fb2c @ 0000fb2c ===== */

void FUN_0000fb2c(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 1) {
    *(uint *)(DAT_0000fb70 + 0x160) = *DAT_0000fb6c | 0x1000;
  }
  else {
    *(uint *)(DAT_0000fb70 + 0x160) = *DAT_0000fb6c & 0xffffefff;
  }
  iVar1 = DAT_0000fb70;
  *(uint *)(DAT_0000fb70 + 0x198) = DAT_0000fb6c[0xe] & 0xfffffffc;
  *(uint *)(iVar1 + 0x198) = *(uint *)(iVar1 + 0x198) | param_2;
  return;
}


/* ===== FUN_0000fb74 @ 0000fb74 ===== */

void FUN_0000fb74(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_0000fb9c + 0x184) = *DAT_0000fb98 | 2;
  }
  else {
    *(uint *)(DAT_0000fb9c + 0x184) = *DAT_0000fb98 & 0xfffffffd;
  }
  return;
}


/* ===== FUN_0000fbac @ 0000fbac ===== */

undefined4 FUN_0000fbac(void)

{
  return 0;
}


/* ===== FUN_0000fbb4 @ 0000fbb4 ===== */

int FUN_0000fbb4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short sVar2;
  int iVar3;
  undefined auStack_118 [256];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*DAT_0000fc00 == '\x01') {
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    sVar2 = FUN_00009aec(auStack_118,param_1,&uStack_c);
    iVar1 = DAT_0000fc04;
    iVar3 = (int)sVar2;
    *(undefined **)(DAT_0000fc04 + 0x2ac) = &DAT_40004000;
    *(undefined4 *)(iVar1 + 0x2a8) = DAT_0000fc08;
    FUN_000115ac(0x100,auStack_118,sVar2);
  }
  else {
    iVar3 = 1;
  }
  return iVar3;
}


/* ===== FUN_0000fc0c @ 0000fc0c ===== */

void FUN_0000fc0c(void)

{
  FUN_0000d7f4(0x100,0x40,DAT_0000fc8c,DAT_0000fc8c,4,4);
  FUN_0000d7f4(0x100,0x40,DAT_0000fc90,DAT_0000fc90,4,4);
  if ((*DAT_0000fc94 == '\x01') || (*DAT_0000fc94 == '\x02')) {
    FUN_0001103c(DAT_0000fc8c,0x100,0x3c,0x40,6);
    FUN_0001103c(DAT_0000fc90,0x100,0x3c,0x40,6);
  }
  FUN_000119d4(0x40,0x3c,DAT_0000fc8c,DAT_0000fc98,0x400,4);
  FUN_000119d4(0x40,0x3c,DAT_0000fc90,DAT_0000fc8c,0x400,4);
  return;
}


/* ===== FUN_0000fc9c @ 0000fc9c ===== */

void FUN_0000fc9c(void)

{
  int iVar1;
  undefined4 in_r3;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0000ece0(DAT_0000fea0 + (uVar2 * 2 + 1) * 0x400,DAT_0000fe9c + uVar2 * 0x400,4,4,0x100,in_r3
                );
  }
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0000ece0(DAT_0000fea0 + uVar2 * 0x800,DAT_0000fea0 + uVar2 * 0x400,4,4,0x100,in_r3);
  }
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0000ece0(DAT_0000fe9c + uVar2 * 0x400,DAT_0000fea4 + uVar2 * 0x400,4,4,0x100,in_r3);
  }
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0000ece0(DAT_0000fea8 + (uVar2 * 2 + 1) * 0x400,DAT_0000fe9c + uVar2 * 0x400,4,4,0x100,in_r3
                );
  }
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0000ece0(DAT_0000fea8 + uVar2 * 0x800,DAT_0000fea8 + uVar2 * 0x400,4,4,0x100);
  }
  for (uVar2 = 0; uVar2 < 0x20; uVar2 = uVar2 + 1 & 0xff) {
    FUN_0000ece0(DAT_0000fe9c + uVar2 * 0x400,DAT_0000feac + uVar2 * 0x400,4,4,0x100);
  }
  FUN_0000d7f4(0x100,0x20,DAT_0000fea0,DAT_0000fea0,4,4);
  FUN_0000d7f4(0x100,0x20,DAT_0000fea4,DAT_0000fea4,4,4);
  FUN_0000d7f4(0x100,0x20,DAT_0000fea8,DAT_0000fea8,4,4);
  FUN_0000d7f4(0x100,0x20,DAT_0000feac,DAT_0000feac,4,4);
  FUN_000119d4(0x20,0x3c,DAT_0000fea0,DAT_0000fe9c,0x400,4);
  FUN_000119d4(0x20,0x3c,DAT_0000fea4,DAT_0000feb0,0x400,4);
  FUN_000119d4(0x20,0x3c,DAT_0000fea8,DAT_0000fea0,0x400,4);
  FUN_000119d4(0x20,0x3c,DAT_0000feac,DAT_0000feb4,0x400,4);
  FUN_0000a688(0x20,0x3c,DAT_0000fe9c,DAT_0000fea4);
  FUN_0000a688(0x20,0x3c,DAT_0000feb0,DAT_0000feb8);
  FUN_0000a688(0x20,0x3c,DAT_0000fea0,DAT_0000fea8);
  FUN_0000a688(0x20,0x3c,DAT_0000feb4,DAT_0000febc);
  for (iVar1 = 0; iVar1 < 0x780; iVar1 = iVar1 + 1) {
    *(uint *)(DAT_0000fea4 + iVar1 * 4) =
         (*(uint *)(DAT_0000fea4 + iVar1 * 4) >> 2) + (*(uint *)(DAT_0000feb8 + iVar1 * 4) >> 2) +
         (*(uint *)(DAT_0000fea8 + iVar1 * 4) >> 2) + (*(uint *)(DAT_0000febc + iVar1 * 4) >> 2);
  }
  FUN_0000d6c0(0x20,0x3c,DAT_0000fec0);
  return;
}


/* ===== FUN_0000fec4 @ 0000fec4 ===== */

undefined8 FUN_0000fec4(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar3 = (uint)*(ushort *)(param_2 + 4);
  uVar2 = (uint)*(ushort *)(param_2 + 8);
  uVar1 = *(undefined4 *)(param_1 + uVar3 * 0x100 + uVar2 * 4);
  uVar5 = uVar3 - 1 & 0xffff;
  uVar3 = uVar3 + 1 & 0xffff;
  if (*(uint *)(param_1 + uVar3 * 0x100 + uVar2 * 4) <
      *(uint *)(param_1 + uVar5 * 0x100 + uVar2 * 4)) {
    uVar4 = *(undefined4 *)(param_1 + uVar5 * 0x100 + uVar2 * 4);
    FUN_0000861a(uVar4);
    uVar6 = FUN_00010fa6();
    uVar7 = FUN_0000861a(uVar1);
    uVar8 = FUN_00010fa6();
    uVar6 = FUN_000082cc((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,
                         (int)((ulonglong)uVar6 >> 0x20),uVar7,uVar8);
    FUN_0000861a(uVar4);
    uVar7 = FUN_00010fa6();
    uVar6 = FUN_000084fe((int)uVar7,(uint)((ulonglong)uVar7 >> 0x20) ^ 0x80000000,(int)uVar6,
                         (int)((ulonglong)uVar6 >> 0x20));
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + uVar3 * 0x100 + uVar2 * 4);
    FUN_0000861a(uVar4);
    uVar6 = FUN_00010fa6();
    uVar7 = FUN_0000861a(uVar1);
    uVar8 = FUN_00010fa6();
    uVar6 = FUN_000082cc((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar6,
                         (int)((ulonglong)uVar6 >> 0x20),uVar7,uVar8);
    FUN_0000861a(uVar4);
    uVar7 = FUN_00010fa6();
    uVar6 = FUN_000084fe((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),(int)uVar6,
                         (int)((ulonglong)uVar6 >> 0x20));
  }
  return uVar6;
}


/* ===== FUN_0000ffcc @ 0000ffcc ===== */

void FUN_0000ffcc(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = DAT_0001004c;
  *(uint *)(DAT_0001004c + 0x28) = *(uint *)(DAT_0001004c + 0x28) & 0xfffffdff;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x20;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x20;
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  FUN_0000c974(100,0);
  uVar2 = 0;
  for (uVar3 = 5; -1 < (int)uVar3; uVar3 = uVar3 - 1) {
    uVar2 = uVar2 | 1 << (uVar3 & 0xff);
    if (uVar2 < 0x20) {
      uVar4 = ~uVar2 & 0xff;
    }
    else {
      uVar4 = uVar2 - 0x20;
    }
    *DAT_00010050 = uVar4;
    FUN_0000c974(100,0);
    if ((*(uint *)(DAT_0001004c + 0x20) & 0xffff) < 0x5f5e) {
      uVar2 = uVar2 & ~(1 << (uVar3 & 0xff));
    }
  }
  *(undefined4 *)(DAT_0001004c + 0x18) = 5;
  return;
}


/* ===== FUN_00010054 @ 00010054 ===== */

void FUN_00010054(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_000100ac & 0xffffffef;
  }
  else {
    uVar1 = *DAT_000100ac | 0x10;
  }
  uVar1 = uVar1 & 0xfffffff7;
  if (param_3 != 0x96) {
    uVar1 = uVar1 | 8;
  }
  *DAT_000100ac = uVar1;
  if (param_2 == 1) {
    uVar1 = *(uint *)(DAT_000100b0 + 0x21c) & 0xffffffef;
  }
  else {
    uVar1 = *(uint *)(DAT_000100b0 + 0x21c) | 0x10;
  }
  uVar1 = uVar1 & 0xfffffff7;
  if (param_4 != 0x96) {
    uVar1 = uVar1 | 8;
  }
  DAT_000100ac[1] = uVar1;
  return;
}


/* ===== FUN_000100b4 @ 000100b4 ===== */

uint FUN_000100b4(void)

{
  return *DAT_000100c0 & 0xf;
}


/* ===== FUN_000100c4 @ 000100c4 ===== */

undefined4 FUN_000100c4(void)

{
  return *DAT_000100cc;
}


/* ===== FUN_000100d0 @ 000100d0 ===== */

uint FUN_000100d0(void)

{
  return (uint)(*DAT_000100dc << 8) >> 0x1c;
}


/* ===== FUN_000100e0 @ 000100e0 ===== */

undefined4 FUN_000100e0(void)

{
  return *DAT_000100e8;
}


/* ===== FUN_000100ec @ 000100ec ===== */

undefined4 FUN_000100ec(void)

{
  undefined4 uVar1;
  
  if ((*(int *)(DAT_00010108 + 0x14) << 0x1e < 0) || (*(int *)(DAT_00010108 + 0x14) << 0x17 < 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== FUN_0001010c @ 0001010c ===== */

void FUN_0001010c(undefined4 param_1,uint param_2)

{
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = FUN_000100c4();
  local_10 = FUN_000100e0();
  local_1c = FUN_000100b4();
  local_18 = FUN_000100d0();
  local_24 = param_2 & 1;
  local_20 = (param_2 << 0x1e) >> 0x1f;
  FUN_0000fbb4(DAT_00010184,local_24,local_20,local_14,local_10,local_1c,local_18);
  if ((local_24 == 1) && (local_20 == 1)) {
    FUN_00010aa4(local_1c,local_18,local_14,local_10);
  }
  FUN_000080f4(param_1,&local_24,0x18);
  return;
}


/* ===== FUN_00010188 @ 00010188 ===== */

void FUN_00010188(void)

{
  *(undefined4 *)(DAT_0001019c + 0x30) = 0x60;
  *DAT_000101a0 = 0x79;
  *(undefined4 *)(DAT_0001019c + 0x24) = 0xf;
  return;
}


/* ===== FUN_000101a4 @ 000101a4 ===== */

void FUN_000101a4(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  
  if (param_5 == 1) {
    uVar1 = *DAT_00010220 | 1;
  }
  else {
    uVar1 = *DAT_00010220 & 0xfffffffe;
  }
  if (param_4 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  if (param_3 == 1) {
    uVar1 = uVar1 | 4;
  }
  else {
    uVar1 = uVar1 & 0xfffffffb;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 8;
  }
  else {
    uVar1 = uVar1 & 0xfffffff7;
  }
  if (param_1 == 1) {
    uVar1 = uVar1 | 0x10;
  }
  else {
    uVar1 = uVar1 & 0xffffffef;
  }
  *DAT_00010220 = uVar1;
  if ((param_5 | param_4 | param_3 | param_2) == 1) {
    uVar1 = *(uint *)(DAT_00010224 + 0x164) | 0x1ff;
  }
  else {
    uVar1 = *(uint *)(DAT_00010224 + 0x164) & 0xfffffe00;
  }
  DAT_00010220[-0x29] = uVar1;
  return;
}


/* ===== FUN_00010228 @ 00010228 ===== */

void FUN_00010228(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_00010270 | 0x10;
  }
  else {
    uVar1 = *DAT_00010270 & 0xffffffef;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 0x20;
  }
  else {
    uVar1 = uVar1 & 0xffffffdf;
  }
  if (param_3 == 1) {
    uVar1 = uVar1 | 0x40;
  }
  else {
    uVar1 = uVar1 & 0xffffffbf;
  }
  if (param_4 == 1) {
    uVar1 = uVar1 | 0x80;
  }
  else {
    uVar1 = uVar1 & 0xffffff7f;
  }
  *DAT_00010270 = uVar1;
  return;
}


/* ===== FUN_00010274 @ 00010274 ===== */

void FUN_00010274(int param_1,uint param_2,int param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = DAT_00010300;
  *(uint *)(DAT_00010300 + 0x218) =
       *DAT_000102fc & 0xfffffff8 | param_1 << 1 | (param_2 << 0x1e) >> 0x1f;
  *(uint *)(DAT_00010300 + 0x220) = *(uint *)(iVar2 + 0x220) & 0xfffffeff;
  puVar1 = DAT_000102fc;
  DAT_000102fc[2] = DAT_000102fc[2] | (param_2 & 1) << 8;
  iVar2 = DAT_00010300;
  *(uint *)(DAT_00010300 + 0x21c) =
       puVar1[1] & 0xfffffff8 | param_3 << 1 | (param_4 << 0x1e) >> 0x1f;
  *(uint *)(DAT_00010300 + 0x224) = *(uint *)(iVar2 + 0x224) & 0xfffffeff;
  *(uint *)(DAT_00010300 + 0x224) = DAT_000102fc[3] | (param_4 & 1) << 8;
  return;
}


/* ===== FUN_00010304 @ 00010304 ===== */

void FUN_00010304(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *(uint *)(DAT_0001033c + 0x210) = *DAT_00010338 | 0x100000;
  FUN_0000c974(1,0);
  iVar1 = DAT_0001033c;
  *(undefined4 *)(DAT_0001033c + 4) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  FUN_0000c974(1,0);
  *(undefined4 *)(DAT_0001033c + 0x80) = 1;
  return;
}


/* ===== FUN_00010340 @ 00010340 ===== */

void FUN_00010340(int param_1,uint param_2)

{
  *(uint *)(DAT_00010364 + 300) = *DAT_00010360 & 0xfffff0f0 | param_1 << 8 | param_2;
  return;
}


/* ===== FUN_00010368 @ 00010368 ===== */

void FUN_00010368(int param_1,int param_2)

{
  if (param_1 == 1) {
    *(uint *)(DAT_000103b8 + 0x218) = *DAT_000103b4 | 0x1000;
  }
  else {
    *(uint *)(DAT_000103b8 + 0x218) = *DAT_000103b4 & 0xffffefff;
  }
  if (param_2 == 1) {
    *(uint *)(DAT_000103b8 + 0x21c) = DAT_000103b4[1] | 0x1000;
  }
  else {
    *(uint *)(DAT_000103b8 + 0x21c) = DAT_000103b4[1] & 0xffffefff;
  }
  return;
}


/* ===== FUN_000103bc @ 000103bc ===== */

void FUN_000103bc(int param_1,int param_2,int param_3,int param_4)

{
  *(uint *)(DAT_00010400 + 0x218) =
       (*DAT_000103fc & 0xfffffcff | param_1 << 8) & 0xfffff3ff | param_2 << 10;
  *(uint *)(DAT_00010400 + 0x21c) =
       (DAT_000103fc[1] & 0xfffffcff | param_3 << 8) & 0xfffff3ff | param_4 << 10;
  return;
}


/* ===== FUN_00010404 @ 00010404 ===== */

void FUN_00010404(int param_1,int param_2)

{
  *(uint *)(DAT_00010428 + 300) =
       (*DAT_00010424 & 0xffffff0f | param_2 << 4) & 0xffff0fff | param_1 << 0xc;
  return;
}


/* ===== FUN_0001042c @ 0001042c ===== */

void FUN_0001042c(int param_1,int param_2)

{
  if (param_1 == 1) {
    *(uint *)(DAT_0001047c + 0x220) = *DAT_00010478 | 0x4000000;
  }
  else {
    *(uint *)(DAT_0001047c + 0x220) = *DAT_00010478 & 0xfbffffff;
  }
  if (param_2 == 1) {
    *(uint *)(DAT_0001047c + 0x224) = DAT_00010478[1] | 0x4000000;
  }
  else {
    *(uint *)(DAT_0001047c + 0x224) = DAT_00010478[1] & 0xfbffffff;
  }
  return;
}


/* ===== FUN_00010480 @ 00010480 ===== */

void FUN_00010480(int param_1,int param_2,int param_3,int param_4)

{
  *(uint *)(DAT_000104c4 + 0x220) =
       (*DAT_000104c0 & 0xffe0ffff | param_1 << 0x10) & 0xfc1fffff | param_2 << 0x15;
  *(uint *)(DAT_000104c4 + 0x224) =
       (DAT_000104c0[1] & 0xffe0ffff | param_3 << 0x10) & 0xfc1fffff | param_4 << 0x15;
  return;
}


/* ===== FUN_000104c8 @ 000104c8 ===== */

void FUN_000104c8(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = *DAT_0001050c | 1;
  }
  else {
    uVar1 = *DAT_0001050c & 0xfffffffe;
  }
  if (param_1 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  *DAT_0001050c = uVar1;
  if (param_2 == 1) {
    uVar1 = *(uint *)(DAT_00010510 + 0x214) | 4;
  }
  else {
    uVar1 = *(uint *)(DAT_00010510 + 0x214) & 0xfffffffb;
  }
  DAT_0001050c[4] = uVar1;
  return;
}


/* ===== FUN_00010514 @ 00010514 ===== */

undefined8 FUN_00010514(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  char cVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  
  uVar9 = FUN_00008b38();
  uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar3 = (undefined4)uVar9;
  uVar10 = FUN_00008414(uVar3,uVar5,param_1,param_2);
  uVar2 = DAT_000105a0;
  uVar1 = DAT_0001059c;
  uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar4 = (undefined4)uVar10;
  cVar8 = true;
  bVar7 = (param_2 & 0x80000000) == 0;
  if (bVar7) {
    FUN_000086e8(uVar4,uVar6,0,DAT_000105a4);
    if (cVar8 == '\0') goto LAB_00010560;
    bVar7 = true;
    FUN_00008718(uVar4,uVar6,0,uVar2);
    if ((bool)cVar8 && !bVar7) goto LAB_00010590;
  }
  else {
    FUN_000086e8(uVar4,uVar6,0,DAT_000105a4);
    if (!(bool)cVar8 || bVar7) {
LAB_00010560:
      uVar9 = FUN_0000840e(uVar3,uVar5,0,uVar1);
      goto LAB_00010590;
    }
    FUN_00008718(uVar4,uVar6,0,uVar2);
    if (cVar8 != '\0') goto LAB_00010590;
  }
  uVar9 = FUN_000082cc(uVar3,uVar5,0,uVar1);
LAB_00010590:
  return CONCAT44(param_2 & 0x80000000 | (uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,(int)uVar9);
}


/* ===== FUN_000105b8 @ 000105b8 ===== */

void FUN_000105b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(DAT_000105d8 + 0xc) = param_1;
  *(undefined4 *)(DAT_000105d8 + 0x10) = 1;
  *(uint *)(DAT_000105dc + 0xc) = *(uint *)(DAT_000105dc + 0xc) & 0xfffffff3 | param_4 << 2;
  return;
}


/* ===== FUN_000105e0 @ 000105e0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000105e0(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined uVar4;
  int iVar5;
  undefined auStack_1c [12];
  undefined4 local_10;
  undefined4 uStack_c;
  
  iVar5 = FUN_0000e06c();
  if (iVar5 == 1) {
    FUN_00011310(auStack_1c);
    FUN_000080f4(DAT_0001072c,auStack_1c,0x14);
    puVar1 = DAT_00010730;
    if (*DAT_0001072c == 0x10a) {
      local_10 = *(undefined4 *)(DAT_0001072c + 2);
      uStack_c = *(undefined4 *)(DAT_0001072c + 4);
      FUN_0000ed60(local_10,uStack_c);
    }
    else if (*DAT_0001072c == 0x200) {
      FUN_00010810();
    }
    else if (*DAT_0001072c == 0x201) {
      FUN_00010afc(*(undefined4 *)(DAT_0001072c + 2),*(undefined4 *)(DAT_0001072c + 4),
                   *(undefined4 *)(DAT_0001072c + 6),*(undefined4 *)(DAT_0001072c + 8));
    }
    else if (*DAT_0001072c == 0x202) {
      FUN_00010b4c(*(undefined4 *)(DAT_0001072c + 2),*(undefined4 *)(DAT_0001072c + 4),
                   *(undefined4 *)(DAT_0001072c + 6));
    }
    else if (*DAT_0001072c == 0x203) {
      FUN_00010aa4(*(undefined4 *)(DAT_0001072c + 2),*(undefined4 *)(DAT_0001072c + 4),
                   *(undefined4 *)(DAT_0001072c + 6),*(undefined4 *)(DAT_0001072c + 8));
    }
    else if (*DAT_0001072c == 0x10e) {
      FUN_00010c78(*(uint *)(DAT_0001072c + 2) & 0xff);
    }
    else if (*DAT_0001072c == -1) {
      *DAT_00010730 = 5;
      puVar1[1] = *DAT_00010734;
      puVar1[2] = *DAT_00010738;
      puVar1[3] = *DAT_0001073c;
      FUN_000099c4(0xffff,puVar1,4);
    }
    else if (*DAT_0001072c == 0x3000) {
      FUN_00010f04(_DAT_00010740,0);
      FUN_00009158();
      FUN_00009018(&local_10,0x10000,6);
      uVar2 = local_10;
      uVar3 = local_10;
      local_10._3_1_ = SUB41(uVar2,3);
      uVar4 = local_10._3_1_;
      local_10 = uVar3;
      FUN_0000fbac("tmp[1] = %0#2x,tmp[3] = %0#2x,tmp[5] = %0#2x,",0xff,uVar4,uStack_c._1_1_);
      FUN_00009070(&local_10,0x10000,6);
      FUN_000099c4(0x3000,(int)&local_10 + 1,1);
      FUN_0000c974(50000,0);
      FUN_00011188();
    }
    FUN_00010c94(0);
  }
  return;
}


/* ===== FUN_00010774 @ 00010774 ===== */

void FUN_00010774(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_000107bc | 1;
  }
  else {
    uVar1 = *DAT_000107bc & 0xfffffffe;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  *DAT_000107bc = uVar1;
  if ((param_1 | param_2) == 1) {
    uVar1 = *(uint *)(DAT_000107c0 + 0x19c) | 0xb60000;
  }
  else {
    uVar1 = *(uint *)(DAT_000107c0 + 0x19c) & 0xff49ffff;
  }
  DAT_000107bc[-0x1e] = uVar1;
  return;
}


/* ===== FUN_000107c4 @ 000107c4 ===== */

void FUN_000107c4(int param_1)

{
  FUN_00009a00();
  FUN_00010eac(DAT_0001080c);
  FUN_00010f84(DAT_0001080c,0x20);
  FUN_00010f84(DAT_0001080c,(uint)(param_1 << 0x14) >> 0x18);
  FUN_00010f84(DAT_0001080c,(uint)(param_1 << 0x1c) >> 0x18);
  FUN_00010f84(DAT_0001080c,0);
  FUN_00010ed8(DAT_0001080c);
  FUN_000099f0(DAT_0001080c);
  FUN_0000905e();
  return;
}


/* ===== FUN_00010810 @ 00010810 ===== */

void FUN_00010810(void)

{
  FUN_0000bd88();
  FUN_000115ac(0x200,DAT_00010824,0x3c);
  return;
}


/* ===== FUN_00010828 @ 00010828 ===== */

void FUN_00010828(undefined *param_1)

{
  do {
  } while (*DAT_000108ac == 0);
  *DAT_000108ac = 0;
  FUN_0000e96e(1);
  FUN_0000e858(*param_1,param_1[1],param_1[2],param_1[3],*(undefined4 *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
  if ((*DAT_000108b0 == '\x01') || (*DAT_000108b0 == '\x02')) {
    FUN_0000d028();
  }
  FUN_0000ad34(2,DAT_000108b4 >> 0x15,0x42,DAT_000108b8 + -4,DAT_000108bc,DAT_000108b8,DAT_000108b4)
  ;
  FUN_0000e96e(1,0);
  FUN_0000e858(0,0,0,0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c));
  return;
}


/* ===== FUN_000108c0 @ 000108c0 ===== */

void FUN_000108c0(undefined *param_1)

{
  FUN_0000e96e(1);
  FUN_0000e858(*param_1,param_1[1],param_1[2],param_1[3],*(undefined4 *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
  FUN_0000ad34(2,DAT_00010920 >> 0x15,0x42,DAT_00010924 + -4,DAT_00010928,DAT_00010924,DAT_00010920)
  ;
  FUN_0000e96e(1,0);
  FUN_0000e858(0,0,0,0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c));
  return;
}


/* ===== FUN_0001092c @ 0001092c ===== */

void FUN_0001092c(undefined4 param_1)

{
  *DAT_00010934 = param_1;
  return;
}


/* ===== FUN_00010938 @ 00010938 ===== */

void FUN_00010938(void)

{
  *DAT_0001094c = *DAT_0001094c | 0x100;
  return;
}


/* ===== FUN_00010950 @ 00010950 ===== */

void FUN_00010950(void)

{
  *DAT_00010964 = *DAT_00010964 & 0xfffffeff;
  return;
}


/* ===== FUN_00010968 @ 00010968 ===== */

void FUN_00010968(void)

{
  int iVar1;
  
  iVar1 = DAT_00010984;
  *(int *)(DAT_00010984 + 0x130) = *DAT_00010980 + 1;
  DAT_00010980[-0x14] = iVar1 << 4;
  return;
}


/* ===== FUN_00010988 @ 00010988 ===== */

void FUN_00010988(void)

{
  *DAT_0001099c = *DAT_0001099c | 0x200;
  return;
}


/* ===== FUN_000109a0 @ 000109a0 ===== */

void FUN_000109a0(void)

{
  *DAT_000109b4 = *DAT_000109b4 & 0xfffffdff;
  return;
}


/* ===== FUN_000109b8 @ 000109b8 ===== */

void FUN_000109b8(undefined4 param_1)

{
  *DAT_000109c0 = param_1;
  return;
}


/* ===== FUN_000109c4 @ 000109c4 ===== */

void FUN_000109c4(void)

{
  *DAT_000109d8 = *DAT_000109d8 | 0x100;
  return;
}


/* ===== FUN_000109dc @ 000109dc ===== */

void FUN_000109dc(void)

{
  *DAT_000109f0 = *DAT_000109f0 & 0xfffffeff;
  return;
}


/* ===== FUN_000109f4 @ 000109f4 ===== */

void FUN_000109f4(void)

{
  int iVar1;
  
  iVar1 = DAT_00010a10;
  *(int *)(DAT_00010a10 + 0x130) = *DAT_00010a0c + 0x100000;
  DAT_00010a0c[-0xe] = iVar1 << 4;
  return;
}


/* ===== FUN_00010a14 @ 00010a14 ===== */

void FUN_00010a14(void)

{
  *DAT_00010a28 = *DAT_00010a28 | 0x200;
  return;
}


/* ===== FUN_00010a2c @ 00010a2c ===== */

void FUN_00010a2c(void)

{
  *DAT_00010a40 = *DAT_00010a40 & 0xfffffdff;
  return;
}


/* ===== FUN_00010a44 @ 00010a44 ===== */

void FUN_00010a44(uint param_1,int param_2)

{
  *(uint *)(DAT_00010a64 + 0x130) =
       (*DAT_00010a60 & 0xfffffff0 | param_1) & 0xff0fffff | param_2 << 0x14;
  return;
}


/* ===== FUN_00010a68 @ 00010a68 ===== */

void FUN_00010a68(void)

{
  int iVar1;
  
  iVar1 = FUN_0000c70c(DAT_00010aa0,4);
  if (iVar1 == DAT_00010aa0[-1]) {
    FUN_00010a44(*DAT_00010aa0,DAT_00010aa0[1]);
    FUN_0001092c(DAT_00010aa0[2]);
    FUN_000109b8(DAT_00010aa0[3]);
  }
  return;
}


/* ===== FUN_00010aa4 @ 00010aa4 ===== */

undefined8 FUN_00010aa4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00010ac8;
  DAT_00010ac8[0xb] = param_1;
  puVar1[0xc] = param_2;
  puVar1[0xd] = param_3;
  puVar1[0xe] = param_4;
  uVar2 = FUN_0000c70c(puVar1 + 0xb,4);
  puVar1 = DAT_00010ac8;
  DAT_00010ac8[10] = uVar2;
  *puVar1 = DAT_00010acc;
  FUN_0000bd7c();
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00010ad0 @ 00010ad0 ===== */

undefined8 FUN_00010ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *DAT_00010aec = param_1;
  *DAT_00010af0 = param_2;
  *DAT_00010af4 = param_3;
  *DAT_00010af8 = param_4;
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00010afc @ 00010afc ===== */

undefined8 FUN_00010afc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00010b20;
  DAT_00010b20[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  puVar1[5] = param_4;
  uVar2 = FUN_0000c70c(puVar1 + 2,4);
  puVar1 = DAT_00010b20;
  DAT_00010b20[1] = uVar2;
  *puVar1 = DAT_00010b24;
  FUN_0000bd7c();
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00010b28 @ 00010b28 ===== */

void FUN_00010b28(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  *DAT_00010b40 = param_1;
  *DAT_00010b44 = param_2;
  *DAT_00010b48 = param_3;
  return;
}


/* ===== FUN_00010b4c @ 00010b4c ===== */

void FUN_00010b4c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_00010b70;
  DAT_00010b70[7] = param_1;
  puVar1[8] = param_2;
  puVar1[9] = param_3;
  uVar2 = FUN_0000c70c(puVar1 + 7,3);
  puVar1 = DAT_00010b70;
  DAT_00010b70[6] = uVar2;
  *puVar1 = DAT_00010b74;
  FUN_0000bd7c();
  return;
}


/* ===== FUN_00010b78 @ 00010b78 ===== */

void FUN_00010b78(void)

{
  undefined4 uVar1;
  undefined local_150;
  undefined local_14f;
  undefined local_128;
  undefined local_127;
  undefined4 local_124;
  undefined4 local_114;
  
  FUN_0000e184(0x1a,0);
  FUN_0000e184(0x19,0);
  FUN_0000c214(7);
  FUN_00008126(&local_150,0x148);
  local_150 = 1;
  local_14f = 0;
  local_128 = 1;
  local_127 = 1;
  local_124 = 0x4ee;
  local_114 = 0x4ee;
  uVar1 = FUN_0000e050(1);
  FUN_0000c2f0(&local_150,uVar1,0);
  FUN_00010bdc(0);
  FUN_00010bdc(1);
  return;
}


/* ===== FUN_00010bdc @ 00010bdc ===== */

void FUN_00010bdc(int param_1)

{
  if (param_1 == 0) {
    FUN_0000e1d4(0x19,0);
    FUN_0000e1d4(0x1a,0);
  }
  else if (param_1 == 1) {
    FUN_0000e1d4(0x19,1);
    FUN_0000e1d4(0x1a,1);
  }
  else if (param_1 == 2) {
    FUN_0000e1d4(0x19,0);
    FUN_0000e1d4(0x1a,1);
  }
  else if (param_1 == 3) {
    FUN_0000e1d4(0x19,1);
    FUN_0000e1d4(0x1a,0);
  }
  else {
    FUN_0000e1d4(0x19,0);
    FUN_0000e1d4(0x1a,0);
  }
  return;
}


/* ===== FUN_00010c50 @ 00010c50 ===== */

void FUN_00010c50(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *DAT_00010c68 = 1 << (param_1 & 0xff);
  }
  else {
    DAT_00010c68[-0x20] = 1 << (param_1 & 0xff);
  }
  return;
}


/* ===== FUN_00010c6c @ 00010c6c ===== */

void FUN_00010c6c(undefined param_1)

{
  *DAT_00010c74 = param_1;
  return;
}


/* ===== FUN_00010c78 @ 00010c78 ===== */

void FUN_00010c78(int param_1)

{
  if (param_1 == 1) {
    *DAT_00010c90 = 1;
  }
  else if (param_1 == 0) {
    *DAT_00010c90 = 0;
  }
  return;
}


/* ===== FUN_00010c94 @ 00010c94 ===== */

void FUN_00010c94(undefined param_1)

{
  *DAT_00010c9c = param_1;
  return;
}


/* ===== FUN_00010ca0 @ 00010ca0 ===== */

uint FUN_00010ca0(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint local_20;
  
  if (param_1 * 2 < DAT_00010df4) {
    if (param_1 * 2 < 0x73000000) {
      local_20 = 0xffffffff;
    }
    else {
      local_20 = 0;
    }
  }
  else {
    local_20 = param_4;
    if ((param_1 & 0x7fffffff) < DAT_00010df8) {
      FUN_000081ec(param_1,DAT_00010dfc);
      uVar4 = FUN_0000891e();
      local_20 = FUN_00008634();
      local_20 = local_20 & 3;
      uVar5 = FUN_000081ec(uVar4,DAT_00010e00);
      uVar2 = FUN_000081ec(uVar4,DAT_00010e04);
      uVar3 = FUN_000081ec(uVar4,DAT_00010e08);
      uVar4 = FUN_000081ec(uVar4,DAT_00010e0c);
      uVar4 = FUN_000081e6(uVar4,param_1);
      uVar4 = FUN_000081e0(uVar4,uVar3);
      uVar4 = FUN_000081e0(uVar4,uVar2);
      param_1 = FUN_000081e0(uVar4,uVar5);
    }
    else {
      param_1 = FUN_00009c58(param_1,&local_20);
    }
  }
  uVar1 = local_20;
  if (-1 < (int)local_20) {
    if ((local_20 & 1) == 0) {
      uVar4 = FUN_000081ec(param_1);
      uVar5 = FUN_000081ec(uVar4,DAT_00010e1c);
      uVar5 = FUN_000081e6(uVar5,DAT_00010e20);
      uVar5 = FUN_000081ec(uVar5,uVar4);
      uVar5 = FUN_0000813c(uVar5,DAT_00010e24);
      uVar4 = FUN_000081ec(uVar5,uVar4);
      uVar4 = FUN_000081ec(uVar4,param_1);
      uVar6 = FUN_0000813c(uVar4,param_1);
      if ((uVar1 & 2) == 0) {
        return uVar6;
      }
    }
    else {
      uVar4 = FUN_000081ec(param_1);
      uVar5 = FUN_000081ec(uVar4,DAT_00010e10);
      uVar5 = FUN_0000813c(uVar5,DAT_00010e14);
      uVar5 = FUN_000081ec(uVar5,uVar4);
      uVar5 = FUN_0000813c(uVar5,DAT_00010e18);
      uVar4 = FUN_000081ec(uVar5,uVar4);
      uVar6 = FUN_0000813c(uVar4,0x3f800000);
      if ((uVar1 & 2) == 0) {
        return uVar6;
      }
    }
    return uVar6 ^ 0x80000000;
  }
  if (param_1 * 2 < 0xff000000) {
    iVar7 = FUN_00009b38(param_1);
    if (iVar7 == 4) {
      FUN_00009c4e();
    }
    return param_1;
  }
  if (param_1 * 2 == 0xff000000) {
    FUN_00009de0(1);
    uVar1 = FUN_00008250(0);
    return uVar1;
  }
  uVar1 = FUN_00008906(param_1,1);
  return uVar1;
}


/* ===== FUN_00010e28 @ 00010e28 ===== */

void FUN_00010e28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  FUN_0000e96e(1,0,param_3,param_4,param_2,param_3,param_4);
  FUN_0000e858(0,0,0,0,*(undefined4 *)(DAT_00010ea0 + 0x24),*(undefined4 *)(DAT_00010ea0 + 0x28),
               *(undefined4 *)(DAT_00010ea0 + 0x2c));
  FUN_00011128();
  FUN_0000c974(100,0);
  FUN_0000e9c8(0,0,0,0,DAT_00010ea0);
  FUN_0000c974(100,0);
  FUN_0000ec7c(0);
  for (iVar2 = 0; iVar1 = DAT_00010ea4, iVar2 < 0x1f; iVar2 = iVar2 + 1) {
    *(undefined4 *)(DAT_00010ea4 + iVar2 * 4 + 0x30) = 0x50;
  }
  *(undefined4 *)(DAT_00010ea4 + 0x40) = 0x90;
  *(undefined4 *)(iVar1 + 0x5c) = 0x90;
  FUN_0000ec50();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


/* ===== FUN_00010eac @ 00010eac ===== */

void FUN_00010eac(int param_1)

{
  FUN_0000e184(4,0);
  if (param_1 == DAT_00010ed4) {
    FUN_0000e1d4(4,0);
  }
  else {
    FUN_0000e1d4(0xe,0);
  }
  return;
}


/* ===== FUN_00010ed8 @ 00010ed8 ===== */

void FUN_00010ed8(int param_1)

{
  FUN_0000e184(4,0);
  if (param_1 == DAT_00010f00) {
    FUN_0000e1d4(4,1);
  }
  else {
    FUN_0000e1d4(0xe,1);
  }
  return;
}


/* ===== FUN_00010f04 @ 00010f04 ===== */

void FUN_00010f04(undefined4 *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DAT_00010f80;
  if (param_1 == DAT_00010f7c) {
    *(uint *)(DAT_00010f80 + 0x3c) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x40) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x44) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x48) = 1 << (param_2 & 0xff) | 0x600;
  }
  else {
    *(uint *)(DAT_00010f80 + 100) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x68) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x6c) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x70) = 1 << (param_2 & 0xff) | 0x600;
  }
  *param_1 = 7;
  param_1[1] = 4;
  param_1[4] = 0x10;
  param_1[1] = param_2 << 2 | 2;
  param_1[5] = 2;
  return;
}


/* ===== FUN_00010f84 @ 00010f84 ===== */

uint FUN_00010f84(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  do {
  } while ((*(uint *)(param_1 + 0xc) & 1) == 0);
  do {
  } while ((*(uint *)(param_1 + 0xc) & 4) != 4);
  return *(uint *)(param_1 + 8) & 0xff;
}


/* ===== FUN_00010fa6 @ 00010fa6 ===== */

undefined8 FUN_00010fa6(uint param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00008a94();
  uVar1 = (uint)uVar2;
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  if ((int)(0x7ff00000 - ((uVar1 | (uint)((ulonglong)uVar2 >> 0x20)) & 0x7fffffff)) < 0) {
    if (param_1 != 0) {
      param_1 = 1;
    }
    if (-1 < (int)(0x7ff00000 - ((param_1 | param_2) & 0x7fffffff))) {
      FUN_00009de0(1);
    }
  }
  return uVar2;
}


/* ===== FUN_00010ff2 @ 00010ff2 ===== */

uint FUN_00010ff2(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00008c9c();
  if (((int)(0x7f800000 - (uVar1 & 0x7fffffff)) < 0) &&
     (-1 < (int)(0x7f800000 - (param_1 & 0x7fffffff)))) {
    FUN_00009de0(1);
  }
  return uVar1;
}


/* ===== FUN_00011020 @ 00011020 ===== */

void FUN_00011020(void)

{
  int iVar1;
  
  iVar1 = DAT_00011038;
  *(undefined2 *)(DAT_00011038 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  FUN_00008126(DAT_00011038,0x20);
  return;
}


/* ===== FUN_0001103c @ 0001103c ===== */

void FUN_0001103c(int param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int local_40;
  int local_3c;
  
  iVar3 = FUN_0000ebe4(param_3 << 1);
  iVar4 = FUN_0000ebe4(param_3 << 1);
  for (uVar5 = 0; uVar5 < param_3; uVar5 = uVar5 + 1) {
    local_3c = 0;
    local_40 = 0;
    piVar7 = (int *)(param_1 + uVar5 * 4);
    for (uVar6 = 0; (int)uVar6 < param_4; uVar6 = uVar6 + 1 & 0xffff) {
      local_3c = (short)*piVar7 + local_3c;
      local_40 = (*piVar7 >> 0x10) + local_40;
      piVar7 = piVar7 + param_2;
    }
    *(short *)(iVar3 + uVar5 * 2) = (short)(local_3c >> (param_5 & 0xff));
    *(short *)(iVar4 + uVar5 * 2) = (short)(local_40 >> (param_5 & 0xff));
  }
  for (uVar5 = 0; uVar5 < param_3; uVar5 = uVar5 + 1) {
    piVar7 = (int *)(param_1 + uVar5 * 4);
    sVar1 = *(short *)(iVar3 + uVar5 * 2);
    sVar2 = *(short *)(iVar4 + uVar5 * 2);
    for (uVar6 = 0; (int)uVar6 < param_4; uVar6 = uVar6 + 1 & 0xffff) {
      *piVar7 = (int)(short)((short)*piVar7 - sVar1) +
                (short)((short)((uint)*piVar7 >> 0x10) - sVar2) * 0x10000;
      piVar7 = piVar7 + param_2;
    }
  }
  FUN_0000e000(iVar4);
  FUN_0000e000(iVar3);
  return;
}


/* ===== FUN_00011120 @ 00011120 ===== */

void FUN_00011120(void)

{
  FUN_0001115c();
  return;
}


/* ===== FUN_00011128 @ 00011128 ===== */

void FUN_00011128(void)

{
  int iVar1;
  
  *(uint *)(DAT_00011154 + 0xc) = *(uint *)(DAT_00011154 + 0xc) & 0xfffffffc;
  FUN_0000c974(100,0);
  for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
  }
  *DAT_00011158 = 1;
  return;
}


/* ===== FUN_0001115c @ 0001115c ===== */

void FUN_0001115c(void)

{
  int iVar1;
  
  *(uint *)(DAT_00011180 + 0xc) = *(uint *)(DAT_00011180 + 0xc) & 0xfffffffc | 1;
  for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
  }
  *DAT_00011184 = 0;
  return;
}


/* ===== FUN_00011188 @ 00011188 ===== */

void FUN_00011188(void)

{
  *DAT_0001119c = *DAT_0001119c & 0xffff | DAT_000111a0;
  return;
}


/* ===== FUN_000111a4 @ 000111a4 ===== */

void FUN_000111a4(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_00011230;
  if (param_1 == 1) {
    uVar3 = *(uint *)(DAT_00011230 + 0x218) | 0x80;
  }
  else {
    uVar3 = *(uint *)(DAT_00011230 + 0x218) & 0xffffff7f;
  }
  *(uint *)(DAT_00011230 + 0x218) =
       uVar3 & 0xffffff9f | ((uint)(*(int *)(DAT_00011230 + 0x218) << 0x16) >> 0x1e) << 5;
  iVar2 = DAT_00011230;
  uVar3 = *(uint *)(iVar1 + 0x21c);
  if (param_2 == 1) {
    uVar3 = uVar3 | 0x80;
  }
  else {
    uVar3 = uVar3 & 0xffffff7f;
  }
  *(uint *)(DAT_00011230 + 0x21c) =
       uVar3 & 0xffffff9f | ((uint)(*(int *)(iVar1 + 0x21c) << 0x16) >> 0x1e) << 5;
  *(uint *)(DAT_00011230 + 0x1a0) =
       (*(uint *)(iVar2 + 0x1a0) & 0xfffff8ff | param_3 << 8) & 0xffff8fff | param_4 << 0xc;
  return;
}


/* ===== FUN_00011288 @ 00011288 ===== */

void FUN_00011288(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    FUN_000081ec(param_2,DAT_000112bc);
  }
  else {
    FUN_000081ec(param_2,DAT_000112b8);
  }
  uVar1 = FUN_00008666();
  param_1[2] = uVar1;
  *param_1 = 9;
  return;
}


/* ===== FUN_000112c0 @ 000112c0 ===== */

void FUN_000112c0(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


/* ===== FUN_000112cc @ 000112cc ===== */

void FUN_000112cc(void)

{
  int iVar1;
  
  *DAT_000112f8 = 0;
  *DAT_000112fc = 0;
  *DAT_00011300 = 0;
  FUN_00008126(DAT_00011304,0x80);
  iVar1 = DAT_00011308;
  *(undefined **)(DAT_00011308 + 0x2ac) = &DAT_40004000;
  *(undefined4 *)(iVar1 + 0x2a8) = DAT_0001130c;
  return;
}


/* ===== FUN_00011310 @ 00011310 ===== */

void FUN_00011310(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined2 local_24;
  undefined2 local_22;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  do {
    if (*DAT_000115a0 == *DAT_000115a8) goto code_r0x0001158e;
    iVar2 = FUN_000091f8(DAT_000115a4,*(undefined *)(DAT_0001159c + *DAT_000115a0));
    puVar1 = DAT_000115a0;
    *DAT_000115a0 = *DAT_000115a0 + 1;
    *puVar1 = *(byte *)puVar1 & 0x7f;
  } while (iVar2 != 0);
  uVar3 = (uint)*(ushort *)(DAT_000115a4 + 0x98);
  iVar2 = uVar3 - 0x10b;
  if (uVar3 != 0x10b) {
    if (uVar3 < 0x10c) {
      if (uVar3 - 0x100 < 0xb) {
                    /* WARNING: Could not recover jumptable at 0x0001135e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)(&switchD_0001135e::switchdataD_00011362 + (uint)(byte)(&DAT_00011262)[uVar3] * 2)
        )();
        return;
      }
      goto code_r0x0001156a;
    }
    if (iVar2 == 0xf6) {
      local_20 = (uint)*(byte *)(DAT_000115a4 + 0x14) + (uint)*(byte *)(DAT_000115a4 + 0x15) * 0x100
                 + (uint)*(byte *)(DAT_000115a4 + 0x16) * 0x10000 +
                 (uint)*(byte *)(DAT_000115a4 + 0x17) * 0x1000000;
      local_1c = (uint)*(byte *)(DAT_000115a4 + 0x18) + (uint)*(byte *)(DAT_000115a4 + 0x19) * 0x100
                 + (uint)*(byte *)(DAT_000115a4 + 0x1a) * 0x10000 +
                 (uint)*(byte *)(DAT_000115a4 + 0x1b) * 0x1000000;
      local_18 = (uint)*(byte *)(DAT_000115a4 + 0x1c) + (uint)*(byte *)(DAT_000115a4 + 0x1d) * 0x100
                 + (uint)*(byte *)(DAT_000115a4 + 0x1e) * 0x10000 +
                 (uint)*(byte *)(DAT_000115a4 + 0x1f) * 0x1000000;
      local_14 = (uint)*(byte *)(DAT_000115a4 + 0x20) + (uint)*(byte *)(DAT_000115a4 + 0x21) * 0x100
                 + (uint)*(byte *)(DAT_000115a4 + 0x22) * 0x10000 +
                 (uint)*(byte *)(DAT_000115a4 + 0x23) * 0x1000000;
      goto code_r0x0001156a;
    }
    if (iVar2 < 0xf7) {
      if ((iVar2 == 1) || (iVar2 == 3)) goto LAB_0001150e;
      bVar4 = iVar2 == 0xf5;
    }
    else {
      if (iVar2 == 0xf7) {
        local_20 = (uint)*(byte *)(DAT_000115a4 + 0x14) +
                   (uint)*(byte *)(DAT_000115a4 + 0x15) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x16) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x17) * 0x1000000;
        local_1c = (uint)*(byte *)(DAT_000115a4 + 0x18) +
                   (uint)*(byte *)(DAT_000115a4 + 0x19) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1a) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1b) * 0x1000000;
        local_18 = (uint)*(byte *)(DAT_000115a4 + 0x1c) +
                   (uint)*(byte *)(DAT_000115a4 + 0x1d) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1e) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1f) * 0x1000000;
        goto code_r0x0001156a;
      }
      bVar4 = iVar2 == 0xf8;
      if (bVar4) {
        local_20 = (uint)*(byte *)(DAT_000115a4 + 0x14) +
                   (uint)*(byte *)(DAT_000115a4 + 0x15) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x16) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x17) * 0x1000000;
        local_1c = (uint)*(byte *)(DAT_000115a4 + 0x18) +
                   (uint)*(byte *)(DAT_000115a4 + 0x19) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1a) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1b) * 0x1000000;
        local_18 = (uint)*(byte *)(DAT_000115a4 + 0x1c) +
                   (uint)*(byte *)(DAT_000115a4 + 0x1d) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1e) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x1f) * 0x1000000;
        local_14 = (uint)*(byte *)(DAT_000115a4 + 0x20) +
                   (uint)*(byte *)(DAT_000115a4 + 0x21) * 0x100 +
                   (uint)*(byte *)(DAT_000115a4 + 0x22) * 0x10000 +
                   (uint)*(byte *)(DAT_000115a4 + 0x23) * 0x1000000;
        goto code_r0x0001156a;
      }
    }
    if (!bVar4) goto code_r0x0001156a;
  }
LAB_0001150e:
  local_20 = (uint)*(byte *)(DAT_000115a4 + 0x14) + (uint)*(byte *)(DAT_000115a4 + 0x15) * 0x100 +
             (uint)*(byte *)(DAT_000115a4 + 0x16) * 0x10000 +
             (uint)*(byte *)(DAT_000115a4 + 0x17) * 0x1000000;
code_r0x0001156a:
  local_24 = *(undefined2 *)(DAT_000115a4 + 0x98);
  local_22 = *(undefined2 *)(DAT_000115a4 + 0x12);
code_r0x0001158e:
  FUN_000080f4(param_1,&local_24,0x14);
  return;
}


/* ===== FUN_000115ac @ 000115ac ===== */

void FUN_000115ac(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  FUN_0000995e(DAT_000115cc,param_1,param_2,param_3);
  return;
}


/* ===== FUN_000115e4 @ 000115e4 ===== */

void FUN_000115e4(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *DAT_00011600 | 8;
  }
  else {
    uVar1 = *DAT_00011600 & 0xfffffff7;
  }
  *DAT_00011600 = uVar1;
  return;
}


/* ===== FUN_00011604 @ 00011604 ===== */

void FUN_00011604(uint param_1,int param_2)

{
  *(uint *)(DAT_00011628 + 0x114) = *DAT_00011624 & 0xffffff00 | param_2 << 4 | param_1;
  return;
}


/* ===== FUN_0001162c @ 0001162c ===== */

void FUN_0001162c(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_00011658 | 1;
  }
  else {
    uVar1 = *DAT_00011658 & 0xfffffffe;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  *DAT_00011658 = uVar1;
  return;
}


/* ===== FUN_000116a8 @ 000116a8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000116a8(undefined *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((param_1 != &DAT_40004000) && (param_1 != DAT_00011720)) && (param_1 != _DAT_00011724)) {
    FUN_0000ba24("..\\..\\..\\lib\\adt6101P_hardwarelib\\adt6101P_uart\\adt6101P_uart.c",0x53);
  }
  iVar1 = DAT_00011768;
  if (param_1 == &DAT_40004000) {
    *(undefined4 *)(DAT_00011768 + 0x30) = 1;
    *(undefined4 *)(iVar1 + 0x34) = 0x81;
  }
  else if (param_1 == DAT_00011720) {
    *(undefined4 *)(DAT_00011768 + 0x58) = 1;
    *(undefined4 *)(iVar1 + 0x5c) = 0x81;
  }
  else {
    *(undefined4 *)(DAT_00011768 + 0x80) = 1;
    *(undefined4 *)(DAT_00011768 + 0x84) = 0x81;
  }
  uVar2 = DAT_00011770;
  if (param_3 != 0) {
    uVar2 = DAT_0001176c;
  }
  *(uint *)(param_1 + 0x10) = uVar2 / param_2;
  *(undefined4 *)(param_1 + 8) = 0xb;
  return;
}


/* ===== FUN_00011778 @ 00011778 ===== */

undefined4 FUN_00011778(undefined4 param_1)

{
  undefined in_ZR;
  undefined in_CY;
  
  while (FUN_00008794(param_1,DAT_000117b0), !(bool)in_CY || (bool)in_ZR) {
    param_1 = FUN_000081e0(param_1,DAT_000117ac);
  }
  while (FUN_00008780(param_1,DAT_000117b4), !(bool)in_CY || (bool)in_ZR) {
    param_1 = FUN_0000813c(param_1,DAT_000117ac);
  }
  return param_1;
}


/* ===== FUN_000117b8 @ 000117b8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000117b8(undefined4 param_1,int param_2,int param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  int iStack_2c;
  int iStack_28;
  
  local_38 = 0x54;
  local_30 = param_1;
  iStack_2c = param_2;
  iStack_28 = param_3;
  uVar2 = FUN_000085ee(param_1);
  iVar3 = DAT_000118e8;
  uVar1 = *(ushort *)(DAT_000118e8 + 0x2c);
  *(short *)(DAT_000118e8 + 0x2c) = *(short *)(DAT_000118e8 + 0x2c) + 1;
  *(undefined4 *)(iVar3 + (uint)uVar1 * 4) = uVar2;
  *(short *)(iVar3 + 0x2c) = *(short *)(iVar3 + 0x2c) + 1;
  uVar2 = FUN_0000813c(*(undefined4 *)(iVar3 + 0x24),0x3f800000);
  *(undefined4 *)(DAT_000118e8 + 0x24) = uVar2;
  uVar2 = FUN_000085ee(local_30);
  uVar2 = FUN_0000813c(uVar2,*(undefined4 *)(DAT_000118e8 + 0x20));
  iVar3 = DAT_000118e8;
  *(undefined4 *)(DAT_000118e8 + 0x20) = uVar2;
  if (*(short *)(iVar3 + 0x2c) == 8) {
    *(undefined2 *)(iVar3 + 0x2c) = 0;
    *(undefined4 *)(iVar3 + 0x28) = 0;
    for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {
      uVar2 = FUN_0000813c(*(undefined4 *)(DAT_000118e8 + 0x28),
                           *(undefined4 *)(DAT_000118e8 + iVar3 * 4));
      *(undefined4 *)(DAT_000118e8 + 0x28) = uVar2;
    }
    uVar2 = FUN_00008250(*(undefined4 *)(DAT_000118e8 + 0x28),0x41000000);
    iVar3 = DAT_000118e8;
    *(undefined4 *)(DAT_000118e8 + 0x28) = uVar2;
    uVar4 = FUN_000086c0(*(undefined4 *)(iVar3 + 0x28));
    uVar5 = FUN_0000e774();
    uVar4 = FUN_0000841a((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,DAT_000118ec,uVar4);
    FUN_0000840e((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,_DAT_000118f0);
    uVar2 = FUN_00008748();
    *(undefined4 *)(DAT_000118e8 + 0x28) = uVar2;
    uVar2 = FUN_000085dc(param_2 * 6 + param_3 * 2 + -0x3c);
    uVar2 = FUN_000081e6(uVar2,*(undefined4 *)(DAT_000118e8 + 0x28));
    iVar3 = DAT_000118e8;
    *(undefined4 *)(DAT_000118e8 + 0x28) = uVar2;
    local_3c = *(undefined4 *)(iVar3 + 0x28);
    iVar3 = FUN_0000c700();
    if (iVar3 == 1) {
      uVar4 = FUN_000086c0(local_3c);
      uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
      FUN_0000fbb4("rx0 noise pwoer %f:",uVar2,(int)uVar4,uVar2);
      local_40 = 0;
    }
    else {
      iVar3 = FUN_0000c700();
      if (iVar3 == 2) {
        uVar4 = FUN_000086c0(local_3c);
        uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
        FUN_0000fbb4("rx1 noise pwoer %f:",uVar2,(int)uVar4,uVar2);
        local_40 = 1;
      }
    }
    FUN_000099c4(0xa11,&local_40,8);
  }
  return;
}


/* ===== FUN_0001191c @ 0001191c ===== */

undefined4 FUN_0001191c(uint *param_1,uint *param_2)

{
  undefined4 uVar1;
  
  if (*(char *)((int)param_2 + 9) == '\0') {
    if (*(char *)((int)param_2 + 0xb) == '\0') {
      if (*(char *)(param_2 + 2) == '\0') {
        *param_1 = *param_2 >> 0x12;
      }
      else {
        *param_1 = *param_2;
      }
    }
    else {
      *param_1 = *param_2 >> 0x12;
    }
  }
  else if (*(char *)(param_2 + 2) == '\0') {
    *param_1 = *param_2 >> 0x12;
  }
  else {
    *param_1 = *param_2;
  }
  switch(param_2[1]) {
  case 9:
    uVar1 = 0xc;
    break;
  case 10:
    uVar1 = 0x10;
    break;
  case 0xb:
    uVar1 = 0x14;
    break;
  case 0xc:
    uVar1 = 0x18;
    break;
  case 0xd:
    uVar1 = 0x20;
    break;
  case 0xe:
    uVar1 = 0x30;
    break;
  case 0xf:
    uVar1 = 0x40;
    break;
  default:
    uVar1 = 8;
  }
  param_1[1] = param_2[1];
  *(undefined *)(param_1 + 2) = *(undefined *)(param_2 + 2);
  *(undefined *)((int)param_1 + 9) = *(undefined *)((int)param_2 + 9);
  *(undefined *)((int)param_1 + 10) = *(undefined *)((int)param_2 + 0xb);
  FUN_000080f4(param_1 + 3,param_2 + 6,uVar1);
  return 0;
}


/* ===== FUN_000119ac @ 000119ac ===== */

void FUN_000119ac(void)

{
  FUN_0000ad34(2,DAT_000119c8 >> 0x15,0x42,DAT_000119cc + -4,DAT_000119d0,DAT_000119cc,DAT_000119c8)
  ;
  return;
}


/* ===== FUN_000119d4 @ 000119d4 ===== */

void FUN_000119d4(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    FUN_0000d840(param_1,param_3 + iVar1 * 4,param_4 + iVar1 * param_1 * 4,param_5,param_6);
  }
  *(uint *)(DAT_00011a18 + 8) = *(uint *)(DAT_00011a18 + 8) & 0xfffffbff;
  return;
}


/* ===== FUN_00011a1c @ 00011a1c ===== */

undefined4 FUN_00011a1c(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  *(uint *)(DAT_00011ab8 + 0x18c) = *DAT_00011ab4 | 0x2300000;
  FUN_0000e0f8(10);
  FUN_0000c974(0x3c,0);
  FUN_0000c974(0x3c,0);
  FUN_0000c974(0x3c,0);
  uVar2 = FUN_0000861a(DAT_00011ab4[-0x2e] & 0xff);
  FUN_000084fe((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,DAT_00011abc);
  FUN_00008748();
  uVar2 = FUN_000086c0();
  FUN_0000841a((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,DAT_00011ac0);
  uVar1 = FUN_00008748();
  *DAT_00011ab4 = *(uint *)(DAT_00011ab8 + 0x18c) & 0xfffff;
  return uVar1;
}

