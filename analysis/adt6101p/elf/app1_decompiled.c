
/* ===== entry @ 00008000 ===== */

/* WARNING: Control flow encountered bad instruction data */

void processEntry entry(undefined4 param_1)

{
  undefined2 in_r1;
  int in_r2;
  int in_r4;
  int in_r5;
  undefined4 *in_r6;
  undefined2 in_r7;
  
  *in_r6 = param_1;
  *(undefined2 *)(in_r2 + 6) = in_r1;
  uRam000081b6 = in_r7;
  *(undefined2 *)(in_r4 + 6) = in_r1;
  *(undefined2 *)(in_r4 + 6) = 0x81b0;
  *(short *)(in_r4 + 6) = (short)in_r5;
  *(undefined2 *)(in_r4 + 6) = in_r7;
  *(undefined2 *)(in_r5 + 6) = in_r1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


/* ===== thunk_FUN_00011368 @ 000080c4 ===== */

void thunk_FUN_00011368(void)

{
  (*DAT_000080c8)();
  return;
}


/* ===== FUN_000080f4 @ 000080f4 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_000080f4(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar1 = FUN_00008bca(param_1,DAT_00008164);
  iVar2 = FUN_0000902a();
  if (0x807fffff < param_1) {
    iVar2 = iVar2 + -1;
  }
  uVar3 = FUN_00008fd2(iVar2);
  uVar1 = FUN_00008bc4(uVar3,uVar1);
  uVar1 = FUN_00008caa(uVar1,9);
  uVar4 = FUN_0000905c();
  uVar4 = uVar4 & 0x1ff;
  uVar3 = FUN_00008fe4(uVar4);
  uVar1 = FUN_00008bc4(uVar3,uVar1);
  uVar3 = *(undefined4 *)(_UNK_00008168 + uVar4 * 4);
  uVar5 = FUN_00008bca(uVar1,*(undefined4 *)(_UNK_00008168 + uVar4 * 4 + 4));
  uVar1 = FUN_00008bbe(0x3f800000,uVar1);
  uVar6 = FUN_00008bca(uVar1,uVar3);
  uVar7 = uVar6 ^ uVar5;
  uVar4 = uVar6;
  if (uVar6 << 1 < uVar5 << 1) {
    uVar4 = uVar5;
    uVar5 = uVar6;
  }
  if ((uVar5 & 0x7fffffff) == 0) {
    return uVar4;
  }
  uVar6 = uVar4 >> 0x17;
  uVar9 = (uVar6 & 0xff) - ((uVar5 << 1) >> 0x18);
  if ((int)uVar9 < 0x20) {
    uVar8 = uVar5 & 0x7fffff | 0x800000;
    if ((int)uVar7 < 0) {
      uVar8 = -uVar8;
    }
    uVar5 = uVar8 << (0x20 - uVar9 & 0xff);
    uVar4 = uVar4 + ((int)uVar8 >> (uVar9 & 0xff));
    if (uVar6 != uVar4 >> 0x17) {
      if ((int)uVar7 < 0) {
        iVar2 = uVar4 + uVar6 * -0x800000;
        if ((int)uVar9 < 2) {
          iVar2 = iVar2 + 0x800000;
          iVar10 = LZCOUNT(iVar2);
          uVar4 = iVar2 << iVar10;
          if ((uVar4 | uVar5) == 0) {
            return uVar4;
          }
          if (uVar5 != 0) {
            uVar7 = uVar5 << iVar10;
            if (uVar7 != 0) {
              uVar7 = 1;
            }
            uVar4 = uVar4 | uVar7 | uVar5 >> (0x20U - iVar10 & 0xff);
          }
          iVar2 = ((uVar6 & 0xff) - iVar10) + 7;
          if (-1 < iVar2) {
            uVar5 = (uVar4 >> 8) + iVar2 * 0x800000 + (uVar6 & 0x100) * 0x800000;
            if ((int)(uVar4 * 0x1000000) < 0) {
              uVar5 = uVar5 + 1;
              if ((uVar4 & 0x7f) == 0) {
                uVar5 = uVar5 & 0xfffffffe;
              }
              return uVar5;
            }
            return uVar5;
          }
          return 0;
        }
        uVar4 = iVar2 * 2 + uVar6 * 0x800000 | uVar5 >> 0x1f;
        uVar5 = uVar5 << 1;
      }
      else {
        uVar5 = uVar5 >> 1 | uVar4 * -0x80000000;
        uVar4 = (uVar4 + uVar6 * -0x800000 + 0x800000 >> 1) + uVar6 * 0x800000;
      }
    }
  }
  else {
    uVar5 = ((int)uVar7 >> 0x1f) * 2 + 1;
    uVar4 = uVar4 + ((int)uVar7 >> 0x1f);
  }
  if ((int)uVar5 < 0) {
    uVar4 = uVar4 + 1;
    if ((uVar5 & 0x7fffffff) == 0) {
      uVar4 = uVar4 & 0xfffffffe;
    }
    return uVar4;
  }
  return uVar4;
}


/* ===== FUN_0000816c @ 0000816c ===== */

undefined4 FUN_0000816c(ushort *param_1,ushort *param_2,ushort *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  bool bVar15;
  bool bVar16;
  
  uVar5 = (uint)*param_1;
  puVar10 = *(undefined4 **)(param_1 + 2);
  puVar8 = *(undefined4 **)(param_2 + 2);
  puVar6 = *(undefined4 **)(param_3 + 2);
  if (uVar5 == *param_2) {
    uVar1 = (uint)param_1[1];
    uVar3 = (uint)param_2[1];
    bVar15 = uVar1 == uVar3;
    if (bVar15) {
      uVar3 = (uint)*param_3;
    }
    bVar16 = bVar15 && uVar5 == uVar3;
    if (bVar15 && uVar5 == uVar3) {
      bVar16 = uVar1 == param_3[1];
    }
    if (bVar16) {
      uVar5 = uVar5 * uVar1;
      for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        uVar13 = puVar10[1];
        uVar2 = FUN_00008b1a(*puVar10,*puVar8);
        uVar12 = puVar10[2];
        uVar13 = FUN_00008b1a(uVar13,puVar8[1]);
        uVar4 = puVar8[2];
        *puVar6 = uVar2;
        puVar6[1] = uVar13;
        uVar13 = puVar10[3];
        uVar14 = puVar8[3];
        uVar2 = FUN_00008b1a(uVar12,uVar4);
        uVar13 = FUN_00008b1a(uVar13,uVar14);
        puVar6[2] = uVar2;
        puVar6[3] = uVar13;
        puVar6 = puVar6 + 4;
        puVar8 = puVar8 + 4;
        puVar10 = puVar10 + 4;
      }
      uVar3 = uVar5 & 3;
      if (uVar3 != 0) {
        if (uVar3 < 0x80000000) {
          if (uVar3 != 0) {
            puVar7 = puVar6 + -1;
            puVar9 = puVar8 + -1;
            puVar11 = puVar10 + -1;
            if ((uVar5 & 1) != 0) {
              uVar2 = FUN_00008b1a(*puVar10,*puVar8);
              *puVar6 = uVar2;
              puVar7 = puVar6;
              puVar9 = puVar8;
              puVar11 = puVar10;
            }
            for (uVar3 = uVar3 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
              uVar2 = FUN_00008b1a(puVar11[1],puVar9[1]);
              puVar7[1] = uVar2;
              puVar9 = puVar9 + 2;
              puVar11 = puVar11 + 2;
              uVar2 = FUN_00008b1a(*puVar11,*puVar9);
              puVar7 = puVar7 + 2;
              *puVar7 = uVar2;
            }
          }
        }
        else {
          do {
            uVar2 = FUN_00008b1a(*puVar10,*puVar8);
            puVar8 = puVar8 + 1;
            *puVar6 = uVar2;
            uVar3 = uVar3 - 1;
            puVar10 = puVar10 + 1;
            puVar6 = puVar6 + 1;
          } while (uVar3 != 0);
        }
      }
      return 0;
    }
  }
  return 0xfffffffd;
}


/* ===== FUN_00008258 @ 00008258 ===== */

void FUN_00008258(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 2) = param_4;
  return;
}


/* ===== FUN_00008260 @ 00008260 ===== */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_00008260(ushort *param_1,ushort *param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 uVar15;
  bool bVar16;
  bool bVar17;
  undefined4 *puStack_6c;
  uint local_60;
  undefined4 *local_5c;
  uint local_4c;
  uint uStack_48;
  
  local_5c = *(undefined4 **)(param_1 + 2);
  iVar7 = *(int *)(param_3 + 2);
  local_4c = (uint)*param_1;
  uVar1 = param_1[1];
  uVar4 = (uint)uVar1;
  uVar8 = (uint)param_2[1];
  local_60 = 0;
  bVar16 = uVar4 == *param_2;
  uVar5 = uVar4;
  if (bVar16) {
    uVar5 = (uint)*param_3;
  }
  bVar17 = bVar16 && local_4c == uVar5;
  if (bVar16 && local_4c == uVar5) {
    bVar17 = uVar8 == param_3[1];
  }
  if (bVar17) {
    uVar5 = (uVar4 << 0x1e) >> 0x1f;
    do {
      puStack_6c = (undefined4 *)(iVar7 + local_60 * 4);
      puVar12 = *(undefined4 **)(param_2 + 2);
      uStack_48 = 0;
      uVar14 = uVar8;
      do {
        uVar10 = 0;
        puVar9 = local_5c;
        for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          uVar15 = puVar9[1];
          puVar13 = puVar12 + uVar8;
          uVar6 = FUN_00008bca(*puVar9,*puVar12);
          uVar10 = FUN_00008b1a(uVar6,uVar10);
          puVar11 = puVar13 + uVar8;
          uVar6 = FUN_00008bca(uVar15,*puVar13);
          uVar10 = FUN_00008b1a(uVar6,uVar10);
          uVar15 = puVar9[3];
          uVar6 = FUN_00008bca(puVar9[2],*puVar11);
          uVar10 = FUN_00008b1a(uVar6,uVar10);
          puVar12 = puVar11 + uVar8 + uVar8;
          uVar6 = FUN_00008bca(uVar15,puVar11[uVar8]);
          uVar10 = FUN_00008b1a(uVar6,uVar10);
          puVar9 = puVar9 + 4;
        }
        if ((uVar1 & 3) != 0) {
          puVar12 = puVar12 + -uVar8;
          uVar2 = uVar5;
          puVar11 = puVar9 + -1;
          if ((uVar1 & 1) != 0) {
            puVar12 = puVar12 + uVar8;
            uVar6 = FUN_00008bca(*puVar9,*puVar12);
            uVar10 = FUN_00008b1a(uVar6,uVar10);
            puVar11 = puVar9;
          }
          for (; uVar2 != 0; uVar2 = uVar2 - 1) {
            uVar6 = FUN_00008bca(puVar11[1],puVar12[uVar8]);
            uVar10 = FUN_00008b1a(uVar6,uVar10);
            puVar12 = puVar12 + uVar8 * 2;
            uVar6 = FUN_00008bca(puVar11[2],*puVar12);
            uVar10 = FUN_00008b1a(uVar6,uVar10);
            puVar11 = puVar11 + 2;
          }
        }
        *puStack_6c = uVar10;
        puStack_6c = puStack_6c + 1;
        uStack_48 = uStack_48 + 1 & 0xffff;
        puVar12 = (undefined4 *)(*(int *)(param_2 + 2) + uStack_48 * 4);
        uVar14 = uVar14 - 1 & 0xffff;
      } while (uVar14 != 0);
      local_60 = local_60 + uVar8 & 0xffff;
      local_5c = local_5c + uVar4;
      local_4c = local_4c - 1 & 0xffff;
    } while (local_4c != 0);
    return 0;
  }
  return 0xfffffffd;
}


/* ===== FUN_000083de @ 000083de ===== */

undefined4 FUN_000083de(ushort *param_1,ushort *param_2)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  ushort *puVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  int iVar17;
  
  uVar6 = (uint)*param_1;
  puVar11 = *(undefined4 **)(param_1 + 2);
  uVar2 = param_1[1];
  puVar12 = (ushort *)(uint)uVar2;
  puVar1 = param_2 + 1;
  iVar17 = *(int *)(param_2 + 2);
  uVar13 = 0;
  if (uVar6 == *puVar1) {
    param_2 = (ushort *)(uint)*param_2;
  }
  if (uVar6 == *puVar1 && puVar12 == param_2) {
    uVar14 = (uint)(uVar2 >> 2);
    uVar3 = (uint)((int)puVar12 << 0x1e) >> 0x1f;
    uVar10 = uVar6;
    do {
      puVar5 = (undefined4 *)(iVar17 + uVar13 * 4);
      if (uVar14 != 0) {
        puVar15 = puVar5 + uVar6;
        puVar8 = puVar5 + uVar6 * 3;
        puVar9 = puVar5 + uVar6 * 2;
        uVar4 = uVar14;
        puVar7 = puVar11;
        puVar16 = puVar15;
        do {
          *puVar5 = *puVar7;
          *puVar16 = puVar7[1];
          *puVar9 = puVar7[2];
          *puVar8 = puVar7[3];
          puVar5 = puVar5 + uVar6 * 4;
          puVar16 = puVar16 + uVar6 * 4;
          puVar9 = puVar9 + uVar6 * 4;
          puVar8 = puVar8 + uVar6 * 4;
          uVar4 = uVar4 - 1;
          puVar7 = puVar7 + 4;
        } while (uVar4 != 0);
        puVar11 = puVar11 + uVar14 * 4;
        puVar5 = puVar15 + uVar6 * 3 + uVar6 * (uVar14 - 1) * 4;
      }
      if ((uVar2 & 3) != 0) {
        puVar5 = puVar5 + -uVar6;
        uVar4 = uVar3;
        puVar7 = puVar11 + -1;
        if ((uVar2 & 1) != 0) {
          puVar5 = puVar5 + uVar6;
          *puVar5 = *puVar11;
          puVar7 = puVar11;
        }
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          puVar5[uVar6] = puVar7[1];
          puVar5 = puVar5 + uVar6 * 2;
          *puVar5 = puVar7[2];
          puVar7 = puVar7 + 2;
        }
        puVar11 = puVar11 + ((uint)puVar12 & 3);
      }
      uVar13 = uVar13 + 1 & 0xffff;
      uVar10 = uVar10 - 1 & 0xffff;
    } while (uVar10 != 0);
    return 0;
  }
  return 0xfffffffd;
}


/* ===== FUN_000084dc @ 000084dc ===== */

undefined4 FUN_000084dc(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  undefined8 *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  undefined8 *puVar19;
  undefined8 *puVar20;
  uint uVar21;
  undefined8 *puVar22;
  int iVar23;
  int iVar24;
  undefined4 uVar25;
  char cVar26;
  char cVar27;
  undefined8 uVar28;
  uint local_84;
  uint local_74;
  undefined8 *local_54;
  uint local_38;
  
  uVar15 = 0;
  uVar16 = 0;
  local_54 = *(undefined8 **)(param_1 + 2);
  puVar6 = *(undefined8 **)(param_2 + 2);
  uVar7 = (uint)*param_1;
  uVar1 = param_1[1];
  uVar11 = (uint)uVar1;
  bVar4 = false;
  if ((uVar7 == uVar11) &&
     (puVar8 = puVar6, uVar17 = uVar7, (uint)*param_2 == (uint)param_2[1] && uVar7 == *param_2)) {
    for (; uVar17 != 0; uVar17 = uVar17 - 1) {
      uVar12 = uVar7 - uVar17;
      if (uVar12 != 0) {
        puVar10 = puVar8;
        if (uVar12 < 0x80000000) {
          if (0 < (int)uVar12) {
            if ((uVar12 & 1) != 0) {
              puVar10 = puVar8 + 1;
              *(undefined4 *)puVar8 = 0;
              *(undefined4 *)((int)puVar8 + 4) = 0;
            }
            puVar8 = puVar10;
            for (iVar13 = (int)uVar12 >> 1; iVar13 != 0; iVar13 = iVar13 + -1) {
              *(undefined4 *)puVar8 = 0;
              *(undefined4 *)((int)puVar8 + 4) = 0;
              *(undefined4 *)(puVar8 + 1) = 0;
              *(undefined4 *)((int)puVar8 + 0xc) = 0;
              puVar8 = puVar8 + 2;
            }
          }
        }
        else {
          do {
            puVar8 = puVar10 + 1;
            *(undefined4 *)puVar10 = 0;
            *(undefined4 *)((int)puVar10 + 4) = 0;
            uVar12 = uVar12 - 1;
            puVar10 = puVar8;
          } while (uVar12 != 0);
        }
      }
      uVar18 = DAT_0000894c;
      puVar10 = puVar8 + 1;
      *(undefined4 *)puVar8 = 0;
      *(undefined4 *)((int)puVar8 + 4) = uVar18;
      uVar12 = uVar17 - 1;
      if (uVar12 != 0) {
        puVar9 = puVar10;
        if (uVar12 < 0x80000000) {
          if (0 < (int)uVar12) {
            if ((uVar12 & 1) != 0) {
              puVar9 = puVar8 + 2;
              *(undefined4 *)puVar10 = 0;
              *(undefined4 *)((int)puVar8 + 0xc) = 0;
            }
            puVar10 = puVar9;
            for (iVar13 = (int)uVar12 >> 1; iVar13 != 0; iVar13 = iVar13 + -1) {
              *(undefined4 *)puVar10 = 0;
              *(undefined4 *)((int)puVar10 + 4) = 0;
              *(undefined4 *)(puVar10 + 1) = 0;
              *(undefined4 *)((int)puVar10 + 0xc) = 0;
              puVar10 = puVar10 + 2;
            }
          }
        }
        else {
          do {
            puVar10 = puVar9 + 1;
            *(undefined4 *)puVar9 = 0;
            *(undefined4 *)((int)puVar9 + 4) = 0;
            uVar12 = uVar12 - 1;
            puVar9 = puVar10;
          } while (uVar12 != 0);
        }
      }
      puVar8 = puVar10;
    }
    local_74 = 0;
    local_38 = uVar11;
    if (uVar11 != 0) {
      do {
        uVar15 = 0;
        puVar10 = local_54 + uVar11 * local_74;
        puVar8 = puVar6 + uVar11 * local_74;
        uVar16 = *(undefined4 *)puVar10;
        uVar12 = *(uint *)((int)puVar10 + 4);
        uVar17 = 0;
        cVar27 = local_74 <= uVar7;
        if ((local_74 < uVar7) && (cVar27 = local_74 <= uVar7, local_74 < uVar7)) {
          cVar27 = local_74 <= uVar7;
          uVar21 = uVar7 - local_74;
          puVar9 = puVar10;
          if ((uVar21 & 1) != 0) {
            FUN_0000910c();
            if (cVar27 == '\0') {
              FUN_0000910c(*(undefined4 *)puVar10,*(undefined4 *)((int)puVar10 + 4),0,0);
              if (cVar27 == '\0') {
                uVar15 = *(undefined4 *)puVar10;
                uVar17 = *(uint *)((int)puVar10 + 4);
              }
            }
            else {
              FUN_0000910c(*(undefined4 *)puVar10,*(uint *)((int)puVar10 + 4) ^ 0x80000000,0,0);
              if (cVar27 == '\0') {
                uVar15 = *(undefined4 *)puVar10;
                uVar17 = *(uint *)((int)puVar10 + 4) ^ 0x80000000;
              }
            }
            puVar9 = puVar10 + uVar11;
          }
          uVar5 = (int)uVar21 >> 1;
          uVar21 = uVar21 & 1;
          while (uVar3 = uVar5, cVar27 = uVar21 != 0, uVar3 != 0) {
            FUN_0000910c(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),0,0);
            if (cVar27 == '\0') {
              FUN_0000910c(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),uVar15,uVar17);
              if (cVar27 == '\0') {
                uVar15 = *(undefined4 *)puVar9;
                uVar17 = *(uint *)((int)puVar9 + 4);
              }
            }
            else {
              FUN_0000910c(*(undefined4 *)puVar9,*(uint *)((int)puVar9 + 4) ^ 0x80000000,uVar15,
                           uVar17);
              if (cVar27 == '\0') {
                uVar15 = *(undefined4 *)puVar9;
                uVar17 = *(uint *)((int)puVar9 + 4) ^ 0x80000000;
              }
            }
            puVar9 = puVar9 + uVar11;
            FUN_0000910c(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),0,0);
            if (cVar27 == '\0') {
              FUN_0000910c(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),uVar15,uVar17);
              if (cVar27 == '\0') {
                uVar15 = *(undefined4 *)puVar9;
                uVar17 = *(uint *)((int)puVar9 + 4);
              }
            }
            else {
              FUN_0000910c(*(undefined4 *)puVar9,*(uint *)((int)puVar9 + 4) ^ 0x80000000,uVar15,
                           uVar17);
              if (cVar27 == '\0') {
                uVar15 = *(undefined4 *)puVar9;
                uVar17 = *(uint *)((int)puVar9 + 4) ^ 0x80000000;
              }
            }
            puVar9 = puVar9 + uVar11;
            uVar21 = uVar3;
            uVar5 = uVar3 - 1;
          }
        }
        cVar26 = '\x01';
        FUN_000090dc(uVar15,uVar17,0,0);
        if (cVar26 != '\0') {
          return 0xfffffffb;
        }
        cVar26 = '\x01';
        iVar13 = 1;
        FUN_0000910c(uVar16,uVar12,0,0);
        uVar21 = uVar12;
        if (cVar27 != '\0') {
          uVar21 = uVar12 ^ 0x80000000;
        }
        FUN_000090dc(uVar16,uVar21,uVar15,uVar17);
        if (cVar26 == '\0') {
          iVar23 = (uVar7 - local_74) + -1;
          if (iVar23 != 0) {
            puVar9 = local_54 + uVar11 * local_74;
            iVar2 = uVar7 - local_74;
LAB_000086f4:
            iVar24 = iVar23;
            cVar26 = iVar2 != 0;
            cVar27 = '\x01';
            puVar20 = puVar8 + uVar11 * iVar13;
            FUN_0000910c(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),0,0);
            uVar21 = *(uint *)((int)puVar9 + 4);
            if (cVar26 != '\0') {
              uVar21 = uVar21 ^ 0x80000000;
            }
            FUN_000090dc(*(undefined4 *)puVar9,uVar21,uVar15,uVar17);
            if (cVar27 == '\0') goto LAB_00008776;
            uVar17 = uVar11 - local_74;
            if (uVar17 != 0) {
              puVar19 = local_54;
              if (uVar17 < 0x80000000) {
                if (0 < (int)uVar17) {
                  do {
                    uVar15 = *(undefined4 *)puVar9;
                    uVar16 = *(undefined4 *)((int)puVar9 + 4);
                    uVar18 = *(undefined4 *)((int)puVar19 + 4);
                    *(undefined4 *)puVar9 = *(undefined4 *)puVar19;
                    *(undefined4 *)((int)puVar9 + 4) = uVar18;
                    *(undefined4 *)puVar19 = uVar15;
                    *(undefined4 *)((int)puVar19 + 4) = uVar16;
                    uVar17 = uVar17 - 1;
                    puVar19 = puVar19 + 1;
                    puVar9 = puVar9 + 1;
                  } while (uVar17 != 0);
                }
              }
              else {
                do {
                  uVar15 = *(undefined4 *)puVar9;
                  uVar16 = *(undefined4 *)((int)puVar9 + 4);
                  uVar18 = *(undefined4 *)((int)puVar19 + 4);
                  *(undefined4 *)puVar9 = *(undefined4 *)puVar19;
                  *(undefined4 *)((int)puVar9 + 4) = uVar18;
                  *(undefined4 *)puVar19 = uVar15;
                  *(undefined4 *)((int)puVar19 + 4) = uVar16;
                  uVar17 = uVar17 - 1;
                  puVar19 = puVar19 + 1;
                  puVar9 = puVar9 + 1;
                } while (uVar17 != 0);
              }
            }
            if (uVar11 != 0) {
              uVar17 = uVar11;
              puVar9 = puVar8;
              if (uVar11 < 0x80000000) {
                for (; uVar17 != 0; uVar17 = uVar17 - 1) {
                  uVar15 = *(undefined4 *)puVar20;
                  uVar16 = *(undefined4 *)((int)puVar20 + 4);
                  uVar18 = *(undefined4 *)((int)puVar9 + 4);
                  *(undefined4 *)puVar20 = *(undefined4 *)puVar9;
                  *(undefined4 *)((int)puVar20 + 4) = uVar18;
                  *(undefined4 *)puVar9 = uVar15;
                  *(undefined4 *)((int)puVar9 + 4) = uVar16;
                  puVar9 = puVar9 + 1;
                  puVar20 = puVar20 + 1;
                }
              }
              else {
                do {
                  uVar15 = *(undefined4 *)puVar20;
                  uVar16 = *(undefined4 *)((int)puVar20 + 4);
                  uVar18 = *(undefined4 *)((int)puVar9 + 4);
                  *(undefined4 *)puVar20 = *(undefined4 *)puVar9;
                  *(undefined4 *)((int)puVar20 + 4) = uVar18;
                  *(undefined4 *)puVar9 = uVar15;
                  *(undefined4 *)((int)puVar9 + 4) = uVar16;
                  uVar17 = uVar17 - 1;
                  puVar9 = puVar9 + 1;
                  puVar20 = puVar20 + 1;
                } while (uVar17 != 0);
              }
            }
            bVar4 = true;
            goto LAB_0000879e;
          }
        }
LAB_00008780:
        if (!bVar4) {
          cVar27 = '\x01';
          FUN_000090dc(uVar16,uVar12,0,0);
          if (cVar27 != '\0') {
            return 0xfffffffb;
          }
        }
LAB_0000879e:
        uVar15 = *(undefined4 *)puVar10;
        uVar16 = *(undefined4 *)((int)puVar10 + 4);
        uVar17 = uVar11 - local_74;
        if (uVar17 != 0) {
          puVar9 = puVar10;
          uVar12 = uVar17;
          if (uVar17 < 0x80000000) {
            if (0 < (int)uVar17) {
              if ((uVar17 & 1) != 0) {
                uVar28 = FUN_00008ef4(uVar15,uVar16,uVar15,uVar16);
                puVar9 = puVar10 + 1;
                *puVar10 = uVar28;
              }
              for (iVar13 = (int)uVar17 >> 1; iVar13 != 0; iVar13 = iVar13 + -1) {
                uVar28 = FUN_00008ef4(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),uVar15,
                                      uVar16);
                puVar20 = puVar9 + 1;
                *puVar9 = uVar28;
                uVar28 = FUN_00008ef4(*(undefined4 *)puVar20,*(undefined4 *)((int)puVar9 + 0xc),
                                      uVar15,uVar16);
                puVar9 = puVar9 + 2;
                *puVar20 = uVar28;
              }
            }
          }
          else {
            do {
              uVar28 = FUN_00008ef4(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),uVar15,
                                    uVar16);
              *puVar9 = uVar28;
              uVar12 = uVar12 - 1;
              puVar9 = puVar9 + 1;
            } while (uVar12 != 0);
          }
        }
        if (uVar11 != 0) {
          uVar12 = uVar11;
          puVar9 = puVar8;
          if (uVar11 < 0x80000000) {
            if (uVar11 != 0) {
              if ((uVar1 & 1) != 0) {
                uVar28 = FUN_00008ef4(*(undefined4 *)puVar8,*(undefined4 *)((int)puVar8 + 4),uVar15,
                                      uVar16);
                puVar9 = puVar8 + 1;
                *puVar8 = uVar28;
              }
              for (iVar13 = (int)uVar11 >> 1; iVar13 != 0; iVar13 = iVar13 + -1) {
                uVar28 = FUN_00008ef4(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),uVar15,
                                      uVar16);
                *puVar9 = uVar28;
                uVar28 = FUN_00008ef4(*(undefined4 *)(puVar9 + 1),*(undefined4 *)((int)puVar9 + 0xc)
                                      ,uVar15,uVar16);
                puVar9[1] = uVar28;
                puVar9 = puVar9 + 2;
              }
            }
          }
          else {
            do {
              uVar28 = FUN_00008ef4(*(undefined4 *)puVar9,*(undefined4 *)((int)puVar9 + 4),uVar15,
                                    uVar16);
              *puVar9 = uVar28;
              uVar12 = uVar12 - 1;
              puVar9 = puVar9 + 1;
            } while (uVar12 != 0);
          }
        }
        local_84 = 0;
        puVar9 = puVar6;
        puVar20 = local_54;
        for (uVar12 = uVar7; uVar12 != 0; uVar12 = uVar12 - 1) {
          if (local_84 == local_74) {
            puVar19 = puVar20 + uVar17;
            puVar22 = puVar9 + uVar11;
          }
          else {
            uVar15 = *(undefined4 *)puVar20;
            uVar16 = *(undefined4 *)((int)puVar20 + 4);
            puVar19 = puVar20;
            if (uVar17 != 0) {
              uVar21 = uVar17;
              puVar22 = puVar10;
              if (uVar17 < 0x80000000) {
                if (0 < (int)uVar17) {
                  do {
                    uVar25 = *(undefined4 *)puVar20;
                    uVar18 = *(undefined4 *)((int)puVar20 + 4);
                    uVar28 = FUN_00008e10(uVar15,uVar16,*(undefined4 *)puVar22,
                                          *(undefined4 *)((int)puVar22 + 4));
                    uVar28 = FUN_00008e0a((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),uVar25,uVar18
                                         );
                    puVar19 = puVar20 + 1;
                    *puVar20 = uVar28;
                    uVar21 = uVar21 - 1;
                    puVar22 = puVar22 + 1;
                    puVar20 = puVar19;
                  } while (uVar21 != 0);
                }
              }
              else {
                do {
                  uVar25 = *(undefined4 *)puVar20;
                  uVar18 = *(undefined4 *)((int)puVar20 + 4);
                  uVar28 = FUN_00008e10(uVar15,uVar16,*(undefined4 *)puVar22,
                                        *(undefined4 *)((int)puVar22 + 4));
                  uVar28 = FUN_00008e0a((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),uVar25,uVar18);
                  puVar19 = puVar20 + 1;
                  *puVar20 = uVar28;
                  uVar21 = uVar21 - 1;
                  puVar20 = puVar19;
                  puVar22 = puVar22 + 1;
                } while (uVar21 != 0);
              }
            }
            puVar22 = puVar9;
            if (uVar11 != 0) {
              uVar21 = uVar11;
              puVar20 = puVar8;
              if (uVar11 < 0x80000000) {
                for (; uVar21 != 0; uVar21 = uVar21 - 1) {
                  uVar18 = *(undefined4 *)puVar22;
                  uVar25 = *(undefined4 *)((int)puVar22 + 4);
                  uVar28 = FUN_00008e10(uVar15,uVar16,*(undefined4 *)puVar20,
                                        *(undefined4 *)((int)puVar20 + 4));
                  uVar28 = FUN_00008e0a((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),uVar18,uVar25);
                  *puVar22 = uVar28;
                  puVar20 = puVar20 + 1;
                  puVar22 = puVar22 + 1;
                }
              }
              else {
                do {
                  uVar25 = *(undefined4 *)puVar9;
                  uVar18 = *(undefined4 *)((int)puVar9 + 4);
                  uVar28 = FUN_00008e10(uVar15,uVar16,*(undefined4 *)puVar20,
                                        *(undefined4 *)((int)puVar20 + 4));
                  uVar28 = FUN_00008e0a((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),uVar25,uVar18);
                  puVar22 = puVar9 + 1;
                  *puVar9 = uVar28;
                  uVar21 = uVar21 - 1;
                  puVar9 = puVar22;
                  puVar20 = puVar20 + 1;
                } while (uVar21 != 0);
              }
            }
          }
          puVar20 = puVar19 + local_74;
          local_84 = local_84 + 1;
          puVar9 = puVar22;
        }
        local_54 = local_54 + 1;
        local_38 = local_38 - 1;
        local_74 = local_74 + 1;
      } while (local_38 != 0);
      if (bVar4) {
        return 0;
      }
    }
    uVar18 = 0;
    cVar27 = '\x01';
    FUN_000090dc(uVar15,uVar16,0,0);
    if (cVar27 != '\0') {
      iVar13 = *(int *)(param_1 + 2);
      uVar17 = 0;
      uVar7 = uVar7 * uVar11;
      cVar27 = uVar7 == 0;
      if (!(bool)cVar27) {
        do {
          puVar14 = (undefined4 *)(iVar13 + uVar17 * 8);
          FUN_000090dc(*puVar14,puVar14[1],0,0);
          if (cVar27 == '\0') break;
          uVar17 = uVar17 + 1;
          cVar27 = uVar7 - uVar17 == 0;
        } while (uVar17 <= uVar7 && !(bool)cVar27);
      }
      if (uVar7 - uVar17 == 0) {
        uVar18 = 0xfffffffb;
      }
    }
  }
  else {
    uVar18 = 0xfffffffd;
  }
  return uVar18;
LAB_00008776:
  iVar13 = iVar13 + 1;
  iVar23 = iVar24 + -1;
  iVar2 = iVar24;
  if (iVar23 == 0) goto LAB_00008780;
  goto LAB_000086f4;
}


/* ===== FUN_00008a54 @ 00008a54 ===== */

longlong FUN_00008a54(uint param_1,int param_2,uint param_3,uint param_4)

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
    uVar6 = FUN_000091e6(param_1,param_2,iVar4);
    uVar2 = (uint)((ulonglong)uVar6 >> 0x20);
    iVar3 = iVar4;
    if (param_4 < uVar2 || uVar2 - param_4 < (uint)(param_3 <= (uint)uVar6)) {
      uVar6 = FUN_000091c8(param_3,param_4,iVar4);
      bVar5 = param_1 < (uint)uVar6;
      param_1 = param_1 - (uint)uVar6;
      param_2 = (param_2 - (int)((ulonglong)uVar6 >> 0x20)) - (uint)bVar5;
      lVar7 = FUN_000091c8(1,0,iVar4);
      lVar1 = lVar7 + lVar1;
    }
  }
  return lVar1;
}


/* ===== FUN_00008ab6 @ 00008ab6 ===== */

void FUN_00008ab6(undefined4 *param_1,undefined4 *param_2,uint param_3)

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


/* ===== FUN_00008ada @ 00008ada ===== */

void FUN_00008ada(undefined *param_1,int param_2,undefined param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}


/* ===== FUN_00008ae8 @ 00008ae8 ===== */

void FUN_00008ae8(undefined4 param_1,undefined4 param_2)

{
  FUN_00008ada(param_1,param_2,0);
  return;
}


/* ===== FUN_00008aec @ 00008aec ===== */

undefined4 FUN_00008aec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00008ada(param_1,param_3,param_2);
  return param_1;
}


/* ===== FUN_00008afe @ 00008afe ===== */

void FUN_00008afe(int param_1,int param_2)

{
  int iVar1;
  
  param_2 = param_2 * param_1;
  iVar1 = FUN_000113f8();
  if (iVar1 != 0) {
    while (param_2 != 0) {
      param_2 = param_2 + -1;
      *(undefined *)(iVar1 + param_2) = 0;
    }
  }
  return;
}


/* ===== FUN_00008b1a @ 00008b1a ===== */

uint FUN_00008b1a(uint param_1,uint param_2)

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
  if ((int)uVar3 < 0) {
    uVar1 = uVar1 + 1;
    if ((uVar3 & 0x7fffffff) == 0) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  return uVar1;
}


/* ===== FUN_00008bbe @ 00008bbe ===== */

void FUN_00008bbe(undefined4 param_1,uint param_2)

{
  FUN_00008b1a(param_1,param_2 ^ 0x80000000);
  return;
}


/* ===== FUN_00008bc4 @ 00008bc4 ===== */

void FUN_00008bc4(uint param_1)

{
  FUN_00008b1a(param_1 ^ 0x80000000);
  return;
}


/* ===== FUN_00008bca @ 00008bca ===== */

uint FUN_00008bca(uint param_1,uint param_2)

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


/* ===== FUN_00008c2e @ 00008c2e ===== */

uint FUN_00008c2e(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (((param_1 & 0x7fffffff) != 0) && ((param_2 & 0x7fffffff) != 0)) {
    iVar5 = ((param_1 & 0x7fffffff) >> 0x17) - ((param_2 & 0x7fffffff) >> 0x17);
    uVar2 = param_1 & 0x7fffff | 0x800000;
    uVar3 = param_2 & 0x7fffff | 0x800000;
    iVar6 = iVar5 + 0x7d;
    if (uVar2 < uVar3) {
      uVar2 = uVar2 << 1;
    }
    else {
      iVar6 = iVar5 + 0x7e;
    }
    if (-1 < iVar6) {
      uVar1 = 0x800000;
      uVar4 = 0;
      do {
        if (uVar3 <= uVar2) {
          uVar2 = uVar2 - uVar3;
          uVar4 = uVar4 | uVar1;
        }
        uVar1 = uVar1 >> 1;
        uVar2 = uVar2 * 2;
      } while (uVar1 != 0);
      if (uVar2 != 0) {
        if (uVar2 == uVar3) {
          uVar2 = 0x80000000;
        }
        else if (uVar2 < uVar3) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0xfffffffe;
        }
      }
      uVar3 = uVar4 + iVar6 * 0x800000 + ((param_1 ^ param_2) & 0x80000000);
      if (-1 < (int)uVar2) {
        return uVar3;
      }
      uVar3 = uVar3 + 1;
      if ((uVar2 & 0x7fffffff) == 0) {
        uVar3 = uVar3 & 0xfffffffe;
      }
      return uVar3;
    }
  }
  return 0;
}


/* ===== FUN_00008caa @ 00008caa ===== */

uint FUN_00008caa(uint param_1,int param_2)

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


/* ===== FUN_00008cc2 @ 00008cc2 ===== */

uint FUN_00008cc2(uint param_1,uint param_2,uint param_3,uint param_4)

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
      uVar11 = FUN_000091c8(uVar6,uVar9,0x40 - iVar4);
      uVar7 = (uint)(uVar11 >> 0x20);
      uVar5 = (uint)uVar11;
      lVar12 = FUN_00009206(uVar6,uVar9,iVar4);
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
            uVar6 = FUN_00009366(uVar6,uVar9 + uVar8 * -0x100000 + 0x100000,uVar5,uVar7,0,
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
    uVar6 = FUN_00009348((int)lVar12,(int)((ulonglong)lVar12 >> 0x20),(int)uVar11,
                         (int)(uVar11 >> 0x20));
    return uVar6;
  }
  return param_1;
}


/* ===== FUN_00008e04 @ 00008e04 ===== */

void FUN_00008e04(void)

{
  FUN_00008cc2();
  return;
}


/* ===== FUN_00008e0a @ 00008e0a ===== */

void FUN_00008e0a(undefined4 param_1,uint param_2)

{
  FUN_00008cc2(param_1,param_2 ^ 0x80000000);
  return;
}


/* ===== FUN_00008e10 @ 00008e10 ===== */

void FUN_00008e10(uint param_1,uint param_2,uint param_3,uint param_4)

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
    FUN_00009366((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar6 * 0x1000,uVar3 + uVar7,0,
                 (param_2 ^ param_4) & 0x80000000,
                 (((param_4 & 0x7fffffff) << 1) >> 0x15) + (((param_2 & 0x7fffffff) << 1) >> 0x15) +
                 -0x3ff);
  }
  return;
}


/* ===== FUN_00008ef4 @ 00008ef4 ===== */

void FUN_00008ef4(uint param_1,uint param_2,uint param_3,uint param_4)

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
      FUN_00009348(uVar6,uVar9 + iVar8 * 0x100000 + ((param_2 ^ param_4) & 0x80000000),param_1,uVar4
                  );
      return;
    }
  }
  return;
}


/* ===== FUN_00008fd2 @ 00008fd2 ===== */

/* WARNING: Removing unreachable block (ram,0x00009252) */
/* WARNING: Removing unreachable block (ram,0x00009260) */
/* WARNING: Removing unreachable block (ram,0x00009262) */

uint FUN_00008fd2(uint param_1)

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


/* ===== FUN_00008fe4 @ 00008fe4 ===== */

/* WARNING: Removing unreachable block (ram,0x00009252) */
/* WARNING: Removing unreachable block (ram,0x00009260) */
/* WARNING: Removing unreachable block (ram,0x00009262) */

uint FUN_00008fe4(int param_1)

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


/* ===== FUN_00008fee @ 00008fee ===== */

void FUN_00008fee(uint param_1)

{
  uint uVar1;
  
  uVar1 = (int)param_1 >> 0x1f;
  FUN_00009366((param_1 ^ uVar1) - uVar1,0,0,0,0,uVar1 * -0x80000000,0x433);
  return;
}


/* ===== FUN_00009010 @ 00009010 ===== */

void FUN_00009010(undefined4 param_1)

{
  FUN_00009366(param_1,0,0,0,0,0,0x433);
  return;
}


/* ===== FUN_0000902a @ 0000902a ===== */

uint FUN_0000902a(uint param_1)

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


/* ===== FUN_0000905c @ 0000905c ===== */

uint FUN_0000905c(uint param_1)

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


/* ===== FUN_00009084 @ 00009084 ===== */

int FUN_00009084(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 << 1) >> 0x15;
  if (uVar2 < 0x3ff) {
    return 0;
  }
  if (uVar2 < 0x434) {
    iVar1 = FUN_000091e6(param_1,param_2 & 0xfffff | 0x100000,-(uVar2 - 0x433));
    return iVar1;
  }
  return param_1 << (uVar2 - 0x433 & 0xff);
}


/* ===== FUN_000090b6 @ 000090b6 ===== */

undefined8 FUN_000090b6(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0x7fffffff;
  if (uVar1 != 0) {
    return CONCAT44(param_1 & 0x80000000 | ((uVar1 >> 0x17) + 0x380) * 0x100000 |
                    (uVar1 << 9) >> 0xc,param_1 << 0x1d);
  }
  return 0;
}


/* ===== FUN_000090dc @ 000090dc ===== */

int FUN_000090dc(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ===== FUN_0000910c @ 0000910c ===== */

int FUN_0000910c(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}


/* ===== FUN_0000913c @ 0000913c ===== */

uint FUN_0000913c(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 | param_2 & 0x7fffffff) != 0) {
    iVar2 = ((param_2 & 0x7fffffff) >> 0x14) - 0x380;
    if (0 < iVar2) {
      uVar1 = (param_1 >> 0x1d | (param_2 & 0xfffff) << 3) + (param_2 & 0x80000000) +
              iVar2 * 0x800000;
      if (-1 < (int)(param_1 * 8)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      if ((param_1 & 0xfffffff) == 0) {
        uVar1 = uVar1 & 0xfffffffe;
      }
      return uVar1;
    }
  }
  return 0;
}


/* ===== FUN_00009174 @ 00009174 ===== */

undefined8 FUN_00009174(int param_1,int param_2)

{
  if (-1 < param_1) {
    param_1 = -0x80000000 - param_1;
  }
  if (-1 < param_2) {
    param_2 = -0x80000000 - param_2;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00009188 @ 00009188 ===== */

undefined8 FUN_00009188(int param_1,int param_2)

{
  if (-1 < param_1) {
    param_1 = -0x80000000 - param_1;
  }
  if (-1 < param_2) {
    param_2 = -0x80000000 - param_2;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_0000919c @ 0000919c ===== */

int FUN_0000919c(uint param_1,uint param_2)

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


/* ===== FUN_000091c8 @ 000091c8 ===== */

longlong FUN_000091c8(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}


/* ===== FUN_000091e6 @ 000091e6 ===== */

ulonglong FUN_000091e6(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}


/* ===== FUN_00009206 @ 00009206 ===== */

undefined8 FUN_00009206(uint param_1,uint param_2,uint param_3)

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


/* ===== FUN_00009298 @ 00009298 ===== */

uint FUN_00009298(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((int)param_1 < 1) {
    return 0;
  }
  uVar2 = (param_1 << 1) >> 0x18;
  uVar1 = param_1 & 0x7fffff | 0x800000;
  if ((uVar2 & 1) == 0) {
    uVar1 = uVar1 << 1;
    uVar2 = uVar2 - 1;
  }
  iVar4 = 0;
  uVar3 = 0;
  do {
    iVar5 = (0x800000U >> (uVar3 & 0xff)) + iVar4;
    uVar6 = iVar4 + iVar5;
    if (uVar6 <= uVar1) {
      uVar1 = uVar1 - uVar6;
      iVar4 = iVar5;
    }
    uVar1 = uVar1 << 1;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x18);
  if ((uint)(iVar4 << 1) < uVar1) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
  }
  uVar2 = iVar4 + (((int)uVar2 >> 1) + 0x3f) * 0x800000;
  if (-1 < (int)uVar1) {
    return uVar2;
  }
  uVar2 = uVar2 + 1;
  if ((uVar1 & 0x7fffffff) == 0) {
    uVar2 = uVar2 & 0xfffffffe;
  }
  return uVar2;
}


/* ===== FUN_000092f6 @ 000092f6 ===== */

/* WARNING: Removing unreachable block (ram,0x00009252) */
/* WARNING: Removing unreachable block (ram,0x00009260) */
/* WARNING: Removing unreachable block (ram,0x00009262) */

uint FUN_000092f6(uint param_1,uint param_2)

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


/* ===== FUN_00009348 @ 00009348 ===== */

undefined8 FUN_00009348(uint param_1,int param_2,uint param_3,int param_4)

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


/* ===== FUN_00009366 @ 00009366 ===== */

ulonglong FUN_00009366(undefined4 param_1,int param_2,uint param_3,uint param_4,uint param_5,
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
  uVar3 = FUN_000091c8();
  uVar2 = (uint)(uVar3 >> 0x20);
  if (((uint)uVar3 | param_3 | uVar2 | param_4) != 0) {
    if ((param_3 | param_4) != 0) {
      uVar4 = FUN_000091e6(param_3,param_4,0x40 - iVar1);
      lVar5 = FUN_000091c8(param_3,param_4,iVar1);
      uVar3 = CONCAT44(uVar2 | (uint)((ulonglong)uVar4 >> 0x20),
                       (uint)uVar3 | (uint)uVar4 | (uint)(lVar5 != 0));
    }
    uVar2 = (uint)(uVar3 >> 0xb);
    iVar1 = (param_7 - iVar1) + 10;
    if (-1 < iVar1) {
      uVar3 = FUN_00009348(uVar2 + param_5,
                           iVar1 * 0x100000 + (int)((uVar3 >> 0xb) >> 0x20) + param_6 +
                           (uint)CARRY4(uVar2,param_5),0,(int)uVar3 << 0x15);
      return uVar3;
    }
    uVar3 = 0;
  }
  return uVar3;
}


/* ===== FUN_00009404 @ 00009404 ===== */

undefined8 FUN_00009404(uint param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (((param_2 & 0x7fffffff | param_1) != 0) && (uVar1 = (param_2 << 1) >> 0x15, uVar1 < 0x434)) {
    if (0x3fe < uVar1) {
      uVar2 = FUN_000091c8(param_1,param_2,uVar1 - 0x3f3);
      uVar3 = FUN_000091e6(param_1,param_2,-(uVar1 - 0x433));
      uVar2 = FUN_00009348((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),(int)uVar2,
                           (int)((ulonglong)uVar2 >> 0x20));
      uVar2 = FUN_000091c8((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),-(uVar1 - 0x433));
      return uVar2;
    }
    if ((uVar1 < 0x3fe) || ((param_2 << 0xc | param_1 >> 0x14 | param_1 << 0xc) == 0)) {
      param_1 = 0;
      param_2 = 0;
    }
    else {
      param_2 = param_2 & 0x80000000 | DAT_00009488;
      param_1 = 0;
    }
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_0000948c @ 0000948c ===== */

undefined4 FUN_0000948c(uint param_1,uint param_2,uint param_3,uint param_4)

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
    uVar3 = FUN_00009366();
  }
  return uVar3;
}


/* ===== FUN_00009512 @ 00009512 ===== */

void FUN_00009512(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (param_2 << 1) >> 0x15;
  uVar1 = param_2 & 0xfffff | 0x100000;
  if (uVar2 < 0x3ff) {
    return;
  }
  if (uVar2 < 0x434) {
    FUN_000091e6(param_1,uVar1,-(uVar2 - 0x433));
    return;
  }
  FUN_000091c8(param_1,uVar1);
  return;
}


/* ===== FUN_00009544 @ 00009544 ===== */

void FUN_00009544(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar2 = puRam00009564;
  for (puVar9 = puRam00009560; puVar9 < puVar2; puVar9 = puVar9 + 4) {
    param_3 = puVar9[2];
    (*(code *)puVar9[3])(*puVar9,puVar9[1]);
  }
  UNRECOVERED_JUMPTABLE = (code *)0x9561;
  iVar3 = thunk_FUN_00011368();
  pbVar4 = (byte *)(uint)*(ushort *)((uint)*(ushort *)((int)puVar2 + iVar3) * 2);
  pbVar10 = pbVar4 + param_3;
  pbVar6 = pbVar4;
  do {
    bVar1 = *pbVar4;
    uVar8 = bVar1 & 0xf;
    pbVar5 = pbVar4 + 1;
    if ((bVar1 & 0xf) == 0) {
      pbVar5 = pbVar4 + 2;
      uVar8 = (uint)pbVar4[1];
    }
    uVar7 = (uint)(bVar1 >> 4);
    pbVar4 = pbVar5;
    if (uVar7 == 0) {
      uVar7 = (uint)*pbVar5;
      pbVar4 = pbVar5 + 1;
    }
    while (uVar8 = uVar8 - 1, uVar8 != 0) {
      *pbVar6 = *pbVar4;
      pbVar4 = pbVar4 + 1;
      pbVar6 = pbVar6 + 1;
    }
    while (uVar7 = uVar7 - 1, uVar7 != 0) {
      *pbVar6 = 0;
      pbVar6 = pbVar6 + 1;
    }
  } while (pbVar6 < pbVar10);
                    /* WARNING: Could not recover jumptable at 0x000095a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0);
  return;
}


/* ===== FUN_00009568 @ 00009568 ===== */

void FUN_00009568(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  pbVar5 = param_2 + param_3;
  do {
    bVar1 = *param_1;
    uVar4 = bVar1 & 0xf;
    pbVar2 = param_1 + 1;
    if ((bVar1 & 0xf) == 0) {
      pbVar2 = param_1 + 2;
      uVar4 = (uint)param_1[1];
    }
    uVar3 = (uint)(bVar1 >> 4);
    param_1 = pbVar2;
    if (uVar3 == 0) {
      uVar3 = (uint)*pbVar2;
      param_1 = pbVar2 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    while (uVar3 = uVar3 - 1, uVar3 != 0) {
      *param_2 = 0;
      param_2 = param_2 + 1;
    }
  } while (param_2 < pbVar5);
                    /* WARNING: Could not recover jumptable at 0x000095a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(0);
  return;
}


/* ===== FUN_000095a2 @ 000095a2 ===== */

undefined4
FUN_000095a2(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_3c;
  
  uVar3 = param_3 & 0xff;
  uVar2 = param_3 >> 8 & 0xff;
  local_3c = 0;
  iVar4 = 0;
  if (uVar2 + uVar3 * 2 < param_2) {
    for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
      if (uVar1 == 0) {
        for (uVar5 = 0; (int)(uVar5 + uVar3 * -2) < 0 != SBORROW4(uVar5,uVar3 * 2);
            uVar5 = uVar5 + 1 & 0xff) {
          iVar4 = iVar4 + *(int *)(param_1 + (uVar2 + 1 + uVar5) * 4);
        }
      }
      else if (uVar2 < uVar1) {
        if (uVar3 + uVar2 < uVar1) {
          if (((param_2 - uVar3) - uVar2) - 1 < uVar1) {
            if ((param_2 - uVar2) - 1 < uVar1) {
              iVar4 = (iVar4 - *(int *)(param_1 + ((uVar1 - uVar2) + uVar3 * -2 + -1) * 4)) +
                      *(int *)(param_1 + ((uVar1 - uVar2) + -1) * 4);
            }
            else {
              iVar4 = (iVar4 - *(int *)(param_1 + (uVar1 + uVar2) * 4)) +
                      *(int *)(param_1 + ((uVar1 - uVar2) + -1) * 4);
            }
          }
          else {
            iVar4 = (((iVar4 - *(int *)(param_1 + (((uVar1 - uVar2) - uVar3) + -1) * 4)) +
                     *(int *)(param_1 + ((uVar1 - uVar2) + -1) * 4)) -
                    *(int *)(param_1 + (uVar1 + uVar2) * 4)) +
                    *(int *)(param_1 + (uVar1 + uVar2 + uVar3) * 4);
          }
        }
        else {
          iVar4 = (iVar4 - *(int *)(param_1 + (uVar1 + uVar2) * 4)) +
                  *(int *)(param_1 + ((uVar1 - uVar2) + -1) * 4);
        }
      }
      else {
        iVar4 = *(int *)(param_1 + (uVar1 + uVar2 + uVar3 * 2) * 4) +
                (iVar4 - *(int *)(param_1 + (uVar1 + uVar2) * 4));
      }
      if ((uint)(iVar4 * param_4) < *(int *)(param_1 + uVar1 * 4) * uVar3 * 2) {
        *(undefined *)(param_6 + uVar1) = 1;
        local_3c = 1;
      }
    }
  }
  else {
    local_3c = 0;
  }
  return local_3c;
}


/* ===== FUN_00009720 @ 00009720 ===== */

undefined4
FUN_00009720(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6,
            int param_7,int param_8)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  longlong lVar7;
  undefined4 local_64;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  
  uVar5 = param_4 & 0xff;
  uVar4 = param_4 >> 8 & 0xff;
  lVar6 = 0;
  lVar7 = 0;
  local_64 = 0;
  if (uVar4 + uVar5 * 2 < param_3) {
    for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
      if (*(char *)(param_7 + uVar3 * 0x20 + param_8) == '\x01') {
        if ((int)uVar4 < (int)uVar3) {
          if ((int)(uVar5 + uVar4) < (int)uVar3) {
            if ((int)(((param_3 - uVar5) - uVar4) + -1) < (int)uVar3) {
              if ((int)((param_3 - uVar4) + -2) < (int)uVar3) {
                local_3c = (uVar5 << 0x19) >> 0x18;
                local_40 = 0;
                local_44 = ((uVar3 - uVar4) - local_3c) * param_2 + param_1;
                local_48 = 0;
              }
              else {
                local_3c = uVar5 * 2 - (((param_3 - uVar3) - uVar4) + -1) & 0xff;
                local_40 = ((param_3 - uVar3) - uVar4) - 1 & 0xff;
                local_44 = ((uVar3 - uVar4) - local_3c) * param_2 + param_1;
                local_48 = (uVar4 + uVar3 + 1) * param_2 + param_1;
              }
            }
            else {
              local_44 = ((uVar3 - uVar4) - uVar5) * param_2 + param_1;
              local_48 = (uVar4 + uVar3 + 1) * param_2 + param_1;
              local_40 = uVar5;
              local_3c = uVar5;
            }
          }
          else {
            local_48 = (uVar4 + uVar3 + 1) * param_2 + param_1;
            local_44 = param_1;
            local_40 = uVar5 * 2 - (uVar3 - uVar4) & 0xff;
            local_3c = uVar3 - uVar4 & 0xff;
          }
        }
        else {
          local_3c = 0;
          local_44 = 0;
          local_48 = (uVar4 + uVar3 + 1) * param_2 + param_1;
          local_40 = (uVar5 << 0x19) >> 0x18;
        }
        if ((char)local_3c != '\0') {
          lVar6 = FUN_0000bd6c(local_44,param_2,local_3c);
        }
        if ((char)local_40 != '\0') {
          lVar7 = FUN_0000bd6c(local_48,param_2,local_40);
        }
        lVar1 = (lVar6 + lVar7 & 0xffffffffU) * (ulonglong)param_5;
        uVar2 = (int)((ulonglong)(lVar6 + lVar7) >> 0x20) * param_5 +
                (int)((ulonglong)lVar1 >> 0x20);
        if (uVar2 == 0 && (*(int *)(param_1 + uVar3 * param_2) * uVar5 * 2 <= (uint)lVar1) <= uVar2)
        {
          *(undefined *)(param_7 + uVar3 * 0x20 + param_8) = 1;
          local_64 = 1;
        }
        else {
          *(undefined *)(param_7 + uVar3 * 0x20 + param_8) = 0;
        }
      }
    }
  }
  else {
    local_64 = 0;
  }
  return local_64;
}


/* ===== FUN_000098e4 @ 000098e4 ===== */

void FUN_000098e4(int param_1,uint param_2,int param_3)

{
  undefined uVar1;
  uint uVar2;
  
  FUN_00013d58(DAT_00009954);
  FUN_0000d4bc(5,0);
  FUN_00013d2c(DAT_00009954);
  FUN_00013e04(DAT_00009954,3);
  FUN_00013e04(DAT_00009954,(param_2 << 8) >> 0x18);
  FUN_00013e04(DAT_00009954,(param_2 << 0x10) >> 0x18);
  FUN_00013e04(DAT_00009954,param_2 & 0xff);
  for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
    uVar1 = FUN_00013e04(DAT_00009954,0xff);
    *(undefined *)(param_1 + uVar2) = uVar1;
  }
  *(undefined4 *)(DAT_00009958 + 0x1c) = 1;
  FUN_0000b284(DAT_00009954);
  FUN_00013d58(DAT_00009954);
  return;
}


/* ===== FUN_0000995c @ 0000995c ===== */

void FUN_0000995c(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if ((int)param_3 <= (int)uVar1) {
    uVar1 = param_3;
  }
  while (FUN_000098e4(param_1,param_2,uVar1), param_3 != uVar1) {
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


/* ===== FUN_000099a2 @ 000099a2 ===== */

void FUN_000099a2(void)

{
  uint uVar1;
  
  do {
    uVar1 = FUN_0000a728();
  } while ((uVar1 & 1) != 0);
  return;
}


/* ===== FUN_000099b4 @ 000099b4 ===== */

void FUN_000099b4(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char acStack_1024 [4096];
  
  FUN_00008ae8(acStack_1024,0x1000);
  uVar3 = param_2 >> 0xc;
  uVar4 = param_2 & 0xfff;
  uVar1 = 0x1000 - uVar4;
  if ((int)param_3 <= (int)(0x1000 - uVar4)) {
    uVar1 = param_3;
  }
  while( true ) {
    FUN_000098e4(acStack_1024,uVar3 << 0xc,0x1000);
    for (uVar2 = 0; ((int)uVar2 < (int)uVar1 && (acStack_1024[uVar4 + uVar2] == -1));
        uVar2 = uVar2 + 1 & 0xffff) {
    }
    if ((int)uVar2 < (int)uVar1) {
      FUN_00013218(uVar3);
      for (uVar2 = 0; (int)uVar2 < (int)uVar1; uVar2 = uVar2 + 1 & 0xffff) {
        acStack_1024[uVar2 + uVar4] = *(char *)(param_1 + uVar2);
      }
      FUN_0000b2b8(acStack_1024,uVar3 << 0xc,0x1000);
    }
    else {
      FUN_0000b2b8(param_1,param_2,uVar1);
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


/* ===== FUN_00009a7e @ 00009a7e ===== */

undefined8
FUN_00009a7e(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6,
            int param_7)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined4 local_68;
  uint local_64;
  int local_5c;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  
  uVar9 = param_4 & 0xff;
  uVar8 = param_4 >> 8 & 0xff;
  uVar11 = 0;
  iVar6 = 0;
  uVar12 = 0;
  uVar3 = 0;
  local_68 = 0;
  if (uVar8 + uVar9 * 2 < param_3) {
    for (uVar7 = 0; uVar7 < param_3; uVar7 = uVar7 + 1) {
      if ((int)uVar8 < (int)uVar7) {
        if ((int)(uVar9 + uVar8) < (int)uVar7) {
          if ((int)(((param_3 - uVar9) - uVar8) + -1) < (int)uVar7) {
            if ((int)((param_3 - uVar8) + -2) < (int)uVar7) {
              local_3c = (uVar9 << 0x19) >> 0x18;
              local_40 = 0;
              local_44 = ((uVar7 - uVar8) - local_3c) * param_2 + param_1;
              local_48 = 0;
            }
            else {
              local_3c = uVar9 * 2 - (((param_3 - uVar7) - uVar8) + -1) & 0xff;
              local_40 = ((param_3 - uVar7) - uVar8) - 1 & 0xff;
              local_44 = ((uVar7 - uVar8) - local_3c) * param_2 + param_1;
              local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
            }
          }
          else {
            local_44 = ((uVar7 - uVar8) - uVar9) * param_2 + param_1;
            local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
            local_40 = uVar9;
            local_3c = uVar9;
          }
        }
        else {
          local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
          local_44 = param_1;
          local_40 = uVar9 * 2 - (uVar7 - uVar8) & 0xff;
          local_3c = uVar7 - uVar8 & 0xff;
        }
      }
      else {
        local_3c = 0;
        local_44 = 0;
        local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
        local_40 = (uVar9 << 0x19) >> 0x18;
      }
      if ((char)local_3c != '\0') {
        uVar11 = FUN_0000bd6c(local_44,param_2,local_3c);
      }
      local_4c = (int)(uVar11 >> 0x20);
      if ((char)local_40 == '\0') {
LAB_00009c4c:
        if ((char)local_3c == '\0') {
          if ((char)local_40 != '\0') {
            local_64 = local_40 * *(int *)(param_1 + uVar7 * param_2);
            uVar3 = uVar12;
          }
        }
        else {
          local_64 = local_3c * *(int *)(param_1 + uVar7 * param_2);
          uVar3 = uVar11;
        }
      }
      else {
        uVar12 = FUN_0000bd6c(local_48,param_2,local_40);
        if ((char)local_3c == '\0') goto LAB_00009c4c;
        lVar1 = (uVar12 & 0xffffffff) * (ulonglong)local_3c;
        uVar4 = (int)(uVar12 >> 0x20) * local_3c + (int)((ulonglong)lVar1 >> 0x20);
        lVar2 = (uVar11 & 0xffffffff) * (ulonglong)local_40;
        uVar5 = local_4c * local_40 + (int)((ulonglong)lVar2 >> 0x20);
        if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)((uint)lVar2 <= (uint)lVar1)) {
          local_64 = local_40 * *(int *)(param_1 + uVar7 * param_2);
          uVar3 = uVar12;
        }
        else {
          local_64 = local_3c * *(int *)(param_1 + uVar7 * param_2);
          uVar3 = uVar11;
        }
      }
      local_5c = (int)(uVar3 >> 0x20);
      lVar1 = (uVar3 & 0xffffffff) * (ulonglong)param_5;
      uVar4 = local_5c * param_5 + (int)((ulonglong)lVar1 >> 0x20);
      bVar10 = local_64 <= (uint)lVar1;
      iVar6 = uVar4 - !bVar10;
      if (uVar4 == 0 && bVar10 <= uVar4) {
        iVar6 = 1;
        *(undefined *)(param_7 + uVar7) = 1;
        local_68 = 1;
      }
    }
  }
  else {
    local_68 = 0;
  }
  return CONCAT44(iVar6,local_68);
}


/* ===== FUN_00009cbe @ 00009cbe ===== */

undefined4
FUN_00009cbe(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6,
            int param_7,int param_8)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined4 local_68;
  uint local_64;
  int local_5c;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  
  uVar8 = param_4 & 0xff;
  uVar7 = param_4 >> 8 & 0xff;
  uVar9 = 0;
  uVar10 = 0;
  uVar3 = 0;
  local_68 = 0;
  if (uVar7 + uVar8 * 2 < param_3) {
    for (uVar6 = 0; uVar6 < param_3; uVar6 = uVar6 + 1) {
      if (*(char *)(param_7 + uVar6 * 0x20 + param_8) == '\x01') {
        if ((int)uVar7 < (int)uVar6) {
          if ((int)(uVar8 + uVar7) < (int)uVar6) {
            if ((int)(((param_3 - uVar8) - uVar7) + -1) < (int)uVar6) {
              if ((int)((param_3 - uVar7) + -2) < (int)uVar6) {
                local_3c = (uVar8 << 0x19) >> 0x18;
                local_40 = 0;
                local_44 = ((uVar6 - uVar7) - local_3c) * param_2 + param_1;
                local_48 = 0;
              }
              else {
                local_3c = uVar8 * 2 - (((param_3 - uVar6) - uVar7) + -1) & 0xff;
                local_40 = ((param_3 - uVar6) - uVar7) - 1 & 0xff;
                local_44 = ((uVar6 - uVar7) - local_3c) * param_2 + param_1;
                local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
              }
            }
            else {
              local_44 = ((uVar6 - uVar7) - uVar8) * param_2 + param_1;
              local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
              local_40 = uVar8;
              local_3c = uVar8;
            }
          }
          else {
            local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
            local_44 = param_1;
            local_40 = uVar8 * 2 - (uVar6 - uVar7) & 0xff;
            local_3c = uVar6 - uVar7 & 0xff;
          }
        }
        else {
          local_3c = 0;
          local_44 = 0;
          local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
          local_40 = (uVar8 << 0x19) >> 0x18;
        }
        if ((char)local_3c != '\0') {
          uVar9 = FUN_0000bd6c(local_44,param_2,local_3c);
        }
        local_4c = (int)(uVar9 >> 0x20);
        if ((char)local_40 == '\0') {
LAB_00009e9c:
          if ((char)local_3c == '\0') {
            if ((char)local_40 != '\0') {
              local_64 = local_40 * *(int *)(param_1 + uVar6 * param_2);
              uVar3 = uVar10;
            }
          }
          else {
            local_64 = local_3c * *(int *)(param_1 + uVar6 * param_2);
            uVar3 = uVar9;
          }
        }
        else {
          uVar10 = FUN_0000bd6c(local_48,param_2,local_40);
          if ((char)local_3c == '\0') goto LAB_00009e9c;
          lVar1 = (uVar10 & 0xffffffff) * (ulonglong)local_3c;
          uVar4 = (int)(uVar10 >> 0x20) * local_3c + (int)((ulonglong)lVar1 >> 0x20);
          lVar2 = (uVar9 & 0xffffffff) * (ulonglong)local_40;
          uVar5 = local_4c * local_40 + (int)((ulonglong)lVar2 >> 0x20);
          if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)((uint)lVar2 <= (uint)lVar1)) {
            local_64 = local_40 * *(int *)(param_1 + uVar6 * param_2);
            uVar3 = uVar10;
          }
          else {
            local_64 = local_3c * *(int *)(param_1 + uVar6 * param_2);
            uVar3 = uVar9;
          }
        }
        local_5c = (int)(uVar3 >> 0x20);
        lVar1 = (uVar3 & 0xffffffff) * (ulonglong)param_5;
        uVar4 = local_5c * param_5 + (int)((ulonglong)lVar1 >> 0x20);
        if (uVar4 == 0 && (local_64 <= (uint)lVar1) <= uVar4) {
          *(undefined *)(param_7 + uVar6 * 0x20 + param_8) = 1;
          local_68 = 1;
        }
        else {
          *(undefined *)(param_7 + uVar6 * 0x20 + param_8) = 0;
        }
      }
    }
  }
  else {
    local_68 = 0;
  }
  return local_68;
}


/* ===== FUN_00009f28 @ 00009f28 ===== */

void FUN_00009f28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  FUN_00008ae8(DAT_0000a11c,0x40,param_3,param_4,param_4);
  FUN_00008ae8(DAT_0000a120,0x40);
  FUN_00008ae8(DAT_0000a124,0x40);
  *DAT_0000a12c = DAT_0000a128;
  puVar1 = DAT_0000a124;
  *DAT_0000a124 = 0x3f800000;
  puVar1[5] = 0x3f800000;
  puVar1[10] = 0x3f800000;
  puVar1[0xf] = 0x3f800000;
  puVar1[2] = *DAT_0000a12c;
  puVar1[7] = *DAT_0000a12c;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  uVar2 = FUN_00008bca(uVar2,*DAT_0000a12c);
  FUN_00008bca(uVar2,*DAT_0000a12c);
  uVar3 = FUN_000090b6();
  uVar3 = FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a130);
  FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a134);
  uVar2 = FUN_0000913c();
  *DAT_0000a11c = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  FUN_00008bca(uVar2,*DAT_0000a12c);
  uVar3 = FUN_000090b6();
  uVar3 = FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a138);
  FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a134);
  uVar2 = FUN_0000913c();
  DAT_0000a11c[2] = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  uVar2 = FUN_00008bca(uVar2,*DAT_0000a12c);
  FUN_00008bca(uVar2,*DAT_0000a12c);
  uVar3 = FUN_000090b6();
  uVar3 = FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a130);
  FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a134);
  uVar2 = FUN_0000913c();
  DAT_0000a11c[5] = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  FUN_00008bca(uVar2,*DAT_0000a12c);
  uVar3 = FUN_000090b6();
  uVar3 = FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a138);
  FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a134);
  uVar2 = FUN_0000913c();
  DAT_0000a11c[7] = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  FUN_00008bca(uVar2,*DAT_0000a12c);
  uVar3 = FUN_000090b6();
  uVar3 = FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a138);
  FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a134);
  uVar2 = FUN_0000913c();
  DAT_0000a11c[8] = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  uVar2 = FUN_00008bca(uVar2,DAT_0000a13c);
  DAT_0000a11c[10] = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  FUN_00008bca(uVar2,*DAT_0000a12c);
  uVar3 = FUN_000090b6();
  uVar3 = FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a138);
  FUN_00008e10((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_0000a134);
  uVar2 = FUN_0000913c();
  DAT_0000a11c[0xd] = uVar2;
  uVar2 = FUN_00008bca(*DAT_0000a12c,*DAT_0000a12c);
  uVar2 = FUN_00008bca(uVar2,DAT_0000a13c);
  DAT_0000a11c[0xf] = uVar2;
  puVar1 = DAT_0000a120;
  *DAT_0000a120 = DAT_0000a140;
  puVar1[5] = DAT_0000a144;
  puVar1[10] = DAT_0000a140;
  puVar1[0xf] = DAT_0000a148;
  return;
}


/* ===== FUN_0000a14c @ 0000a14c ===== */

void FUN_0000a14c(undefined4 *param_1)

{
  FUN_00008ae8(param_1 + 4,0x40);
  param_1[4] = 0x40800000;
  param_1[9] = 0x40800000;
  param_1[0xe] = 0x40800000;
  param_1[0x13] = 0x40800000;
  param_1[0x14] = *param_1;
  param_1[0x15] = param_1[1];
  param_1[0x16] = param_1[2];
  param_1[0x17] = param_1[3];
  return;
}


/* ===== FUN_0000a17c @ 0000a17c ===== */

void FUN_0000a17c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 local_228 [4];
  uint local_218 [16];
  undefined auStack_1d8 [64];
  undefined4 local_198 [16];
  uint local_158 [16];
  undefined4 local_118 [64];
  
  FUN_00008ae8(local_158,0x40);
  FUN_00008ae8(local_198,0x40);
  FUN_00008ae8(auStack_1d8,0x40);
  FUN_00008ae8(local_218,0x40);
  local_228[0] = 0;
  local_228[1] = 0;
  local_228[2] = 0;
  local_228[3] = 0;
  uVar1 = FUN_00008bca(*DAT_0000a340,*(undefined4 *)(param_1 + 0x58));
  uVar1 = FUN_00008b1a(uVar1,*(undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  uVar1 = FUN_00008bca(*DAT_0000a340,*(undefined4 *)(param_1 + 0x5c));
  uVar1 = FUN_00008b1a(uVar1,*(undefined4 *)(param_1 + 0x54));
  *(undefined4 *)(param_1 + 0x54) = uVar1;
  FUN_000114c8(DAT_0000a344,param_1 + 0x10,local_158);
  FUN_00011504(DAT_0000a344,local_198);
  FUN_000114c8(local_158,local_198,auStack_1d8);
  FUN_00011464(auStack_1d8,DAT_0000a348,param_1 + 0x10);
  if (param_2 != 0) {
    for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1 & 0xff) {
      uVar1 = FUN_00008bbe(*(undefined4 *)(param_1 + uVar4 * 4),
                           *(undefined4 *)(param_1 + 0x50 + uVar4 * 4));
      local_228[uVar4] = uVar1;
    }
    FUN_00011464(DAT_0000a34c,param_1 + 0x10,local_158);
    for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1 & 0xff) {
      uVar6 = FUN_000090b6(local_158[uVar4]);
      local_118[uVar4 * 2 + 0x20] = (int)uVar6;
      local_118[uVar4 * 2 + 0x21] = (int)((ulonglong)uVar6 >> 0x20);
    }
    iVar2 = FUN_000114a0(local_118 + 0x20,local_118);
    if (iVar2 == 0) {
      for (uVar4 = 0; uVar4 < 0x10; uVar4 = uVar4 + 1 & 0xff) {
        uVar1 = FUN_0000913c(local_118[uVar4 * 2],local_118[uVar4 * 2 + 1]);
        local_198[uVar4] = uVar1;
      }
      FUN_000114c8(param_1 + 0x10,local_198,local_218);
      for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1 & 0xff) {
        for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1 & 0xff) {
          uVar1 = FUN_00008bca(local_218[uVar5 + uVar4 * 4],local_228[uVar5]);
          uVar1 = FUN_00008b1a(uVar1,*(undefined4 *)(param_1 + 0x50 + uVar4 * 4));
          *(undefined4 *)(param_1 + 0x50 + uVar4 * 4) = uVar1;
        }
      }
      for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1 & 0xff) {
        for (uVar5 = 0; uVar5 < 4; uVar5 = uVar5 + 1 & 0xff) {
          local_158[uVar5 + uVar4 * 4] = local_218[uVar5 + uVar4 * 4] ^ 0x80000000;
          if (uVar4 == uVar5) {
            uVar3 = FUN_00008b1a(local_158[uVar5 + uVar4 * 4],0x3f800000);
            local_158[uVar5 + uVar4 * 4] = uVar3;
          }
        }
      }
      FUN_000114c8(local_158,param_1 + 0x10,local_198);
      FUN_00008ab6(param_1 + 0x10,local_198,0x40);
    }
  }
  return;
}


/* ===== FUN_0000a350 @ 0000a350 ===== */

void FUN_0000a350(uint param_1,uint param_2)

{
  *DAT_0000a364 = DAT_0000a360 & param_2 | param_1;
  enableIRQinterrupts();
  return;
}


/* ===== FUN_0000a36a @ 0000a36a ===== */

undefined4
FUN_0000a36a(int param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_5c;
  int local_50;
  int local_4c;
  uint local_48;
  
  uVar5 = param_4 & 0xff;
  uVar4 = param_4 >> 8 & 0xff;
  iVar1 = FUN_000113f8(uVar5 << 3);
  local_5c = 0;
  if (uVar4 + uVar5 * 2 < param_3) {
    for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
      if ((int)uVar4 < (int)uVar3) {
        if ((int)(uVar5 + uVar4) < (int)uVar3) {
          if ((int)(((param_3 - uVar5) - uVar4) + -1) < (int)uVar3) {
            if ((int)((param_3 - uVar4) + -2) < (int)uVar3) {
              uVar6 = uVar5 * 2;
              local_48 = 0;
              local_4c = ((uVar3 - uVar4) + uVar5 * -2) * param_2 + param_1;
              local_50 = 0;
            }
            else {
              uVar6 = uVar5 * 2 - (((param_3 - uVar3) - uVar4) + -1);
              local_48 = ((param_3 - uVar3) - uVar4) - 1;
              local_4c = ((uVar3 - uVar4) - uVar6) * param_2 + param_1;
              local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
            }
          }
          else {
            local_4c = ((uVar3 - uVar4) - uVar5) * param_2 + param_1;
            local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
            uVar6 = uVar5;
            local_48 = uVar5;
          }
        }
        else {
          local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
          uVar6 = uVar3 - uVar4;
          local_4c = param_1;
          local_48 = uVar5 * 2 - (uVar3 - uVar4);
        }
      }
      else {
        local_4c = 0;
        local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
        uVar6 = 0;
        local_48 = uVar5 << 1;
      }
      if (uVar6 != 0) {
        FUN_000115bc(local_4c,iVar1,param_2 & 0xffff,4,uVar6 & 0xffff);
      }
      if (local_50 != 0) {
        FUN_000115bc(local_50,iVar1 + uVar6 * 4,param_2 & 0xffff,4,local_48 & 0xffff);
      }
      iVar2 = FUN_0000bce8(iVar1,uVar5 << 1,param_6);
      if ((uint)(iVar2 * param_5) < *(uint *)(param_1 + uVar3 * param_2)) {
        *(undefined *)(param_7 + uVar3) = 1;
        local_5c = 1;
      }
    }
    FUN_00010644(iVar1);
  }
  else {
    local_5c = 0;
    FUN_00010644(iVar1);
  }
  return local_5c;
}


/* ===== FUN_0000a504 @ 0000a504 ===== */

undefined4
FUN_0000a504(int param_1,uint param_2,uint param_3,uint param_4,int param_5,undefined4 param_6,
            int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_5c;
  int local_50;
  int local_4c;
  uint local_48;
  
  uVar5 = param_4 & 0xff;
  uVar4 = param_4 >> 8 & 0xff;
  iVar1 = FUN_000113f8(uVar5 << 3);
  local_5c = 0;
  if (uVar4 + uVar5 * 2 < param_3) {
    for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
      if (*(char *)(param_7 + uVar3 * 0x20 + param_8) == '\x01') {
        if ((int)uVar4 < (int)uVar3) {
          if ((int)(uVar5 + uVar4) < (int)uVar3) {
            if ((int)(((param_3 - uVar5) - uVar4) + -1) < (int)uVar3) {
              if ((int)((param_3 - uVar4) + -2) < (int)uVar3) {
                uVar6 = uVar5 * 2;
                local_48 = 0;
                local_4c = ((uVar3 - uVar4) + uVar5 * -2) * param_2 + param_1;
                local_50 = 0;
              }
              else {
                uVar6 = uVar5 * 2 - (((param_3 - uVar3) - uVar4) + -1);
                local_48 = ((param_3 - uVar3) - uVar4) - 1;
                local_4c = ((uVar3 - uVar4) - uVar6) * param_2 + param_1;
                local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
              }
            }
            else {
              local_4c = ((uVar3 - uVar4) - uVar5) * param_2 + param_1;
              local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
              uVar6 = uVar5;
              local_48 = uVar5;
            }
          }
          else {
            local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
            uVar6 = uVar3 - uVar4;
            local_4c = param_1;
            local_48 = uVar5 * 2 - (uVar3 - uVar4);
          }
        }
        else {
          local_4c = 0;
          local_50 = (uVar4 + uVar3 + 1) * param_2 + param_1;
          uVar6 = 0;
          local_48 = uVar5 << 1;
        }
        if (uVar6 != 0) {
          FUN_000115bc(local_4c,iVar1,param_2 & 0xffff,4,uVar6 & 0xffff);
        }
        if (local_50 != 0) {
          FUN_000115bc(local_50,iVar1 + uVar6 * 4,param_2 & 0xffff,4,local_48 & 0xffff);
        }
        iVar2 = FUN_0000bce8(iVar1,uVar5 << 1,param_6);
        if ((uint)(iVar2 * param_5) < *(uint *)(param_1 + uVar3 * param_2)) {
          *(undefined *)(param_7 + uVar3 * 0x20 + param_8) = 1;
          local_5c = 1;
        }
        else {
          *(undefined *)(param_7 + uVar3 * 0x20 + param_8) = 0;
        }
      }
    }
    FUN_00010644(iVar1);
  }
  else {
    local_5c = 0;
    FUN_00010644(iVar1);
  }
  return local_5c;
}


/* ===== FUN_0000a6c4 @ 0000a6c4 ===== */

short FUN_0000a6c4(void)

{
  short sVar1;
  short sVar2;
  
  FUN_00013d58(DAT_0000a724);
  FUN_0000d4bc(5,0);
  FUN_00013d2c(DAT_0000a724);
  FUN_00013e04(DAT_0000a724,0x90);
  FUN_00013e04(DAT_0000a724,0);
  FUN_00013e04(DAT_0000a724,0);
  FUN_00013e04(DAT_0000a724,0);
  sVar1 = FUN_00013e04(DAT_0000a724,0xff);
  sVar2 = FUN_00013e04(DAT_0000a724,0xff);
  FUN_00013d58(DAT_0000a724);
  FUN_0000b284(DAT_0000a724);
  return sVar2 + sVar1 * 0x100;
}


/* ===== FUN_0000a728 @ 0000a728 ===== */

undefined4 FUN_0000a728(void)

{
  undefined4 uVar1;
  
  FUN_00013d2c(DAT_0000a750);
  FUN_00013e04(DAT_0000a750,5);
  uVar1 = FUN_00013e04(DAT_0000a750,0xff);
  FUN_00013d58(DAT_0000a750);
  return uVar1;
}


/* ===== FUN_0000a754 @ 0000a754 ===== */

undefined8
FUN_0000a754(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6,
            int param_7)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  undefined4 local_68;
  uint local_64;
  int local_5c;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  
  uVar9 = param_4 & 0xff;
  uVar8 = param_4 >> 8 & 0xff;
  uVar11 = 0;
  iVar6 = 0;
  uVar12 = 0;
  uVar3 = 0;
  local_68 = 0;
  if (uVar8 + uVar9 * 2 < param_3) {
    for (uVar7 = 0; uVar7 < param_3; uVar7 = uVar7 + 1) {
      if ((int)uVar8 < (int)uVar7) {
        if ((int)(uVar9 + uVar8) < (int)uVar7) {
          if ((int)(((param_3 - uVar9) - uVar8) + -1) < (int)uVar7) {
            if ((int)((param_3 - uVar8) + -2) < (int)uVar7) {
              local_3c = (uVar9 << 0x19) >> 0x18;
              local_40 = 0;
              local_44 = ((uVar7 - uVar8) - local_3c) * param_2 + param_1;
              local_48 = 0;
            }
            else {
              local_3c = uVar9 * 2 - (((param_3 - uVar7) - uVar8) + -1) & 0xff;
              local_40 = ((param_3 - uVar7) - uVar8) - 1 & 0xff;
              local_44 = ((uVar7 - uVar8) - local_3c) * param_2 + param_1;
              local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
            }
          }
          else {
            local_44 = ((uVar7 - uVar8) - uVar9) * param_2 + param_1;
            local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
            local_40 = uVar9;
            local_3c = uVar9;
          }
        }
        else {
          local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
          local_44 = param_1;
          local_40 = uVar9 * 2 - (uVar7 - uVar8) & 0xff;
          local_3c = uVar7 - uVar8 & 0xff;
        }
      }
      else {
        local_3c = 0;
        local_44 = 0;
        local_48 = (uVar8 + uVar7 + 1) * param_2 + param_1;
        local_40 = (uVar9 << 0x19) >> 0x18;
      }
      if ((char)local_3c != '\0') {
        uVar11 = FUN_0000bd6c(local_44,param_2,local_3c);
      }
      local_4c = (int)(uVar11 >> 0x20);
      if ((char)local_40 == '\0') {
LAB_0000a922:
        if ((char)local_3c == '\0') {
          if ((char)local_40 != '\0') {
            local_64 = local_40 * *(int *)(param_1 + uVar7 * param_2);
            uVar3 = uVar12;
          }
        }
        else {
          local_64 = local_3c * *(int *)(param_1 + uVar7 * param_2);
          uVar3 = uVar11;
        }
      }
      else {
        uVar12 = FUN_0000bd6c(local_48,param_2,local_40);
        if ((char)local_3c == '\0') goto LAB_0000a922;
        lVar1 = (uVar11 & 0xffffffff) * (ulonglong)local_40;
        uVar4 = local_4c * local_40 + (int)((ulonglong)lVar1 >> 0x20);
        lVar2 = (uVar12 & 0xffffffff) * (ulonglong)local_3c;
        uVar5 = (int)(uVar12 >> 0x20) * local_3c + (int)((ulonglong)lVar2 >> 0x20);
        if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)((uint)lVar2 <= (uint)lVar1)) {
          local_64 = local_40 * *(int *)(param_1 + uVar7 * param_2);
          uVar3 = uVar12;
        }
        else {
          local_64 = local_3c * *(int *)(param_1 + uVar7 * param_2);
          uVar3 = uVar11;
        }
      }
      local_5c = (int)(uVar3 >> 0x20);
      lVar1 = (uVar3 & 0xffffffff) * (ulonglong)param_5;
      uVar4 = local_5c * param_5 + (int)((ulonglong)lVar1 >> 0x20);
      bVar10 = local_64 <= (uint)lVar1;
      iVar6 = uVar4 - !bVar10;
      if (uVar4 == 0 && bVar10 <= uVar4) {
        iVar6 = 1;
        *(undefined *)(param_7 + uVar7) = 1;
        local_68 = 1;
      }
    }
  }
  else {
    local_68 = 0;
  }
  return CONCAT44(iVar6,local_68);
}


/* ===== FUN_0000a994 @ 0000a994 ===== */

undefined4
FUN_0000a994(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 param_6,
            int param_7,int param_8)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulonglong uVar9;
  ulonglong uVar10;
  undefined4 local_68;
  uint local_64;
  int local_5c;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  
  uVar8 = param_4 & 0xff;
  uVar7 = param_4 >> 8 & 0xff;
  uVar9 = 0;
  uVar10 = 0;
  uVar3 = 0;
  local_68 = 0;
  if (uVar7 + uVar8 * 2 < param_3) {
    for (uVar6 = 0; uVar6 < param_3; uVar6 = uVar6 + 1) {
      if (*(char *)(param_7 + uVar6 * 0x20 + param_8) == '\x01') {
        if ((int)uVar7 < (int)uVar6) {
          if ((int)(uVar8 + uVar7) < (int)uVar6) {
            if ((int)(((param_3 - uVar8) - uVar7) + -1) < (int)uVar6) {
              if ((int)((param_3 - uVar7) + -2) < (int)uVar6) {
                local_3c = (uVar8 << 0x19) >> 0x18;
                local_40 = 0;
                local_44 = ((uVar6 - uVar7) - local_3c) * param_2 + param_1;
                local_48 = 0;
              }
              else {
                local_3c = uVar8 * 2 - (((param_3 - uVar6) - uVar7) + -1) & 0xff;
                local_40 = ((param_3 - uVar6) - uVar7) - 1 & 0xff;
                local_44 = ((uVar6 - uVar7) - local_3c) * param_2 + param_1;
                local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
              }
            }
            else {
              local_44 = ((uVar6 - uVar7) - uVar8) * param_2 + param_1;
              local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
              local_40 = uVar8;
              local_3c = uVar8;
            }
          }
          else {
            local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
            local_44 = param_1;
            local_40 = uVar8 * 2 - (uVar6 - uVar7) & 0xff;
            local_3c = uVar6 - uVar7 & 0xff;
          }
        }
        else {
          local_3c = 0;
          local_44 = 0;
          local_48 = (uVar7 + uVar6 + 1) * param_2 + param_1;
          local_40 = (uVar8 << 0x19) >> 0x18;
        }
        if ((char)local_3c != '\0') {
          uVar9 = FUN_0000bd6c(local_44,param_2,local_3c);
        }
        local_4c = (int)(uVar9 >> 0x20);
        if ((char)local_40 == '\0') {
LAB_0000ab72:
          if ((char)local_3c == '\0') {
            if ((char)local_40 != '\0') {
              local_64 = local_40 * *(int *)(param_1 + uVar6 * param_2);
              uVar3 = uVar10;
            }
          }
          else {
            local_64 = local_3c * *(int *)(param_1 + uVar6 * param_2);
            uVar3 = uVar9;
          }
        }
        else {
          uVar10 = FUN_0000bd6c(local_48,param_2,local_40);
          if ((char)local_3c == '\0') goto LAB_0000ab72;
          lVar1 = (uVar9 & 0xffffffff) * (ulonglong)local_40;
          uVar4 = local_4c * local_40 + (int)((ulonglong)lVar1 >> 0x20);
          lVar2 = (uVar10 & 0xffffffff) * (ulonglong)local_3c;
          uVar5 = (int)(uVar10 >> 0x20) * local_3c + (int)((ulonglong)lVar2 >> 0x20);
          if (uVar5 < uVar4 || uVar4 - uVar5 < (uint)((uint)lVar2 <= (uint)lVar1)) {
            local_64 = local_40 * *(int *)(param_1 + uVar6 * param_2);
            uVar3 = uVar10;
          }
          else {
            local_64 = local_3c * *(int *)(param_1 + uVar6 * param_2);
            uVar3 = uVar9;
          }
        }
        local_5c = (int)(uVar3 >> 0x20);
        lVar1 = (uVar3 & 0xffffffff) * (ulonglong)param_5;
        uVar4 = local_5c * param_5 + (int)((ulonglong)lVar1 >> 0x20);
        if (uVar4 == 0 && (local_64 <= (uint)lVar1) <= uVar4) {
          *(undefined *)(param_7 + uVar6 * 0x20 + param_8) = 1;
          local_68 = 1;
        }
        else {
          *(undefined *)(param_7 + uVar6 * 0x20 + param_8) = 0;
        }
      }
    }
  }
  else {
    local_68 = 0;
  }
  return local_68;
}


/* ===== FUN_0000ac0c @ 0000ac0c ===== */

int FUN_0000ac0c(int param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  undefined uVar3;
  undefined uVar4;
  short sVar5;
  short *psVar6;
  char cVar7;
  
  cVar7 = -100;
  uVar4 = (undefined)param_2;
  uVar2 = (ushort)param_2;
  switch(*(undefined *)(param_1 + 0xc)) {
  case 0:
    if (param_2 == 1) {
      FUN_00011678(param_1);
      cVar7 = '\x01';
    }
    else {
      cVar7 = -1;
    }
    break;
  case 1:
    uVar4 = FUN_0000ae94(*(undefined *)(param_1 + 0x96),param_2);
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
      uVar4 = FUN_0000ae9c(*(undefined *)(param_1 + 0x96));
      *(undefined *)(param_1 + 0x96) = uVar4;
      if (*(char *)(param_1 + 0x96) == *(char *)(param_1 + 0x97)) {
        if (*(short *)(param_1 + 0x12) == 0) {
          FUN_0000b016(param_1);
          cVar7 = '\0';
        }
        else {
          cVar7 = '\x05';
          *(undefined *)(param_1 + 0xc) = 5;
          *psVar6 = 0;
          uVar4 = FUN_0000aea4();
          *(undefined *)(param_1 + 0x96) = uVar4;
        }
      }
      else {
        FUN_0000b360("[TF] Rx head cksum mismatch\n");
        FUN_0000b016(param_1);
        cVar7 = -8;
      }
      if (0x80 < *(ushort *)(param_1 + 0x12)) {
        FUN_0000b360("[TF] Rx payload too long: %d\n",*(undefined2 *)(param_1 + 0x12));
        *(undefined *)(param_1 + 0x9a) = 1;
        cVar7 = -9;
      }
    }
    else {
      cVar7 = -5;
    }
    break;
  case 3:
    uVar4 = FUN_0000ae94(*(undefined *)(param_1 + 0x96),param_2);
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
    uVar4 = FUN_0000ae94(*(undefined *)(param_1 + 0x96),param_2);
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
      uVar3 = FUN_0000ae94(*(undefined *)(param_1 + 0x96),param_2);
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
      uVar4 = FUN_0000ae9c(*(undefined *)(param_1 + 0x96));
      *(undefined *)(param_1 + 0x96) = uVar4;
      if (*(char *)(param_1 + 0x9a) == '\0') {
        if (*(char *)(param_1 + 0x96) == *(char *)(param_1 + 0x97)) {
          cVar7 = '\0';
        }
        else {
          FUN_0000b360("[TF] Body cksum mismatch\n");
          cVar7 = -10;
        }
      }
      FUN_0000b016(param_1);
    }
    else {
      cVar7 = -7;
    }
  }
  return (int)cVar7;
}


/* ===== FUN_0000ae94 @ 0000ae94 ===== */

uint FUN_0000ae94(uint param_1,uint param_2)

{
  return param_1 ^ param_2;
}


/* ===== FUN_0000ae9c @ 0000ae9c ===== */

byte FUN_0000ae9c(byte param_1)

{
  return ~param_1;
}


/* ===== FUN_0000aea4 @ 0000aea4 ===== */

undefined4 FUN_0000aea4(void)

{
  return 0;
}


/* ===== FUN_0000aea8 @ 0000aea8 ===== */

bool FUN_0000aea8(int param_1)

{
  bool bVar1;
  
  bVar1 = *(char *)(param_1 + 0x2a5) == '\0';
  if (bVar1) {
    *(undefined *)(param_1 + 0x2a5) = 1;
  }
  else {
    FUN_0000b360("[TF] TF already locked for tx!\n");
  }
  return bVar1;
}


/* ===== FUN_0000aee8 @ 0000aee8 ===== */

void FUN_0000aee8(undefined4 param_1)

{
  FUN_00008ae8(param_1,0x18);
  return;
}


/* ===== FUN_0000aef6 @ 0000aef6 ===== */

int FUN_0000aef6(int param_1,undefined *param_2,ushort *param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  FUN_0000aea4();
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
  uVar2 = FUN_0000aea4();
  *param_2 = 1;
  uVar2 = FUN_0000ae94(uVar2,1);
  iVar6 = 1;
  for (uVar5 = 1; -1 < (int)uVar5; uVar5 = (uint)(char)((char)uVar5 + -1)) {
    uVar3 = (int)uVar7 >> ((uVar5 & 0x1f) << 3);
    param_2[iVar6] = (char)uVar3;
    uVar2 = FUN_0000ae94(uVar2,uVar3 & 0xff);
    iVar6 = iVar6 + 1;
  }
  for (uVar7 = 1; -1 < (int)uVar7; uVar7 = (uint)(char)((char)uVar7 + -1)) {
    uVar5 = (int)(uint)param_3[6] >> ((uVar7 & 0x1f) << 3);
    param_2[iVar6] = (char)uVar5;
    uVar2 = FUN_0000ae94(uVar2,uVar5 & 0xff);
    iVar6 = iVar6 + 1;
  }
  for (uVar7 = 1; -1 < (int)uVar7; uVar7 = (uint)(char)((char)uVar7 + -1)) {
    uVar5 = (int)(uint)param_3[2] >> ((uVar7 & 0x1f) << 3);
    param_2[iVar6] = (char)uVar5;
    uVar2 = FUN_0000ae94(uVar2,uVar5 & 0xff);
    iVar6 = iVar6 + 1;
  }
  iVar4 = FUN_0000ae9c(uVar2);
  for (uVar7 = 0; -1 < (int)uVar7; uVar7 = (uint)(char)((char)uVar7 + -1)) {
    param_2[iVar6] = (char)(iVar4 >> ((uVar7 & 0x1f) << 3));
    iVar6 = iVar6 + 1;
  }
  return iVar6;
}


/* ===== FUN_0000b00e @ 0000b00e ===== */

void FUN_0000b00e(int param_1)

{
  *(undefined *)(param_1 + 0x2a5) = 0;
  return;
}


/* ===== FUN_0000b016 @ 0000b016 ===== */

void FUN_0000b016(int param_1)

{
  *(undefined *)(param_1 + 0xc) = 0;
  return;
}


/* ===== FUN_0000b01c @ 0000b01c ===== */

void FUN_0000b01c(undefined4 param_1,undefined4 param_2)

{
  FUN_0000b02e(param_1,param_2,0);
  return;
}


/* ===== FUN_0000b02e @ 0000b02e ===== */

undefined4 FUN_0000b02e(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0000b066(param_1,param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if ((*(short *)(param_2 + 0xc) == 0) || (*(int *)(param_2 + 8) != 0)) {
      FUN_0000b0a4(param_1,*(undefined4 *)(param_2 + 8),*(undefined2 *)(param_2 + 0xc));
      FUN_0000b162(param_1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* ===== FUN_0000b066 @ 0000b066 ===== */

bool FUN_0000b066(int param_1,int param_2)

{
  undefined uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0000aea8(param_1);
  if (iVar2 != 0) {
    uVar3 = FUN_0000aef6(param_1,param_1 + 0x9b,param_2);
    *(undefined4 *)(param_1 + 0x29c) = uVar3;
    *(uint *)(param_1 + 0x2a0) = (uint)*(ushort *)(param_2 + 0xc);
    uVar1 = FUN_0000aea4();
    *(undefined *)(param_1 + 0x2a4) = uVar1;
  }
  return iVar2 != 0;
}


/* ===== FUN_0000b0a4 @ 0000b0a4 ===== */

void FUN_0000b0a4(int param_1,int param_2,uint param_3,undefined4 param_4)

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
      uVar2 = FUN_0000ae94(*(undefined *)(param_1 + 0x2a4),uVar9);
      *(undefined *)(param_1 + 0x2a4) = uVar2;
      iVar8 = iVar5;
    }
    *(int *)(param_1 + 0x29c) = iVar8 + *(int *)(param_1 + 0x29c);
    param_3 = param_3 - uVar3;
    iVar7 = iVar7 + uVar3;
    if (*(int *)(param_1 + 0x29c) == 0x200) {
      FUN_0000b23a(param_1,param_1 + 0x9b,*(undefined4 *)(param_1 + 0x29c),param_4,iVar8,uVar9);
      *(undefined4 *)(param_1 + 0x29c) = 0;
    }
  }
  return;
}


/* ===== FUN_0000b162 @ 0000b162 ===== */

void FUN_0000b162(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x2a0) != 0) {
    if (*(int *)(param_1 + 0x29c) == 0x200) {
      FUN_0000b23a(param_1,param_1 + 0x9b,*(undefined4 *)(param_1 + 0x29c));
      *(undefined4 *)(param_1 + 0x29c) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x29c);
    pbVar3 = (byte *)(param_1 + 0x2a4);
    bVar1 = FUN_0000ae9c(*pbVar3);
    *pbVar3 = bVar1;
    iVar5 = 0;
    for (uVar4 = 0; -1 < (int)uVar4; uVar4 = (uint)(char)((char)uVar4 + -1)) {
      *(char *)(iVar2 + param_1 + 0x9b + iVar5) =
           (char)((int)(uint)*pbVar3 >> ((uVar4 & 0x1f) << 3));
      iVar5 = iVar5 + 1;
    }
    *(int *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + iVar5;
  }
  FUN_0000b23a(param_1,param_1 + 0x9b,*(undefined4 *)(param_1 + 0x29c));
  FUN_0000b00e(param_1);
  return;
}


/* ===== FUN_0000b1f2 @ 0000b1f2 ===== */

void FUN_0000b1f2(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4)

{
  undefined auStack_2c [4];
  undefined2 local_28;
  undefined4 local_24;
  undefined2 local_20;
  
  FUN_0000aee8(auStack_2c);
  local_28 = param_2;
  local_24 = param_3;
  local_20 = param_4;
  FUN_0000b01c(param_1,auStack_2c);
  return;
}


/* ===== FUN_0000b21a @ 0000b21a ===== */

void FUN_0000b21a(uint *param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    *param_1 = (uint)*(byte *)(param_2 + uVar1);
    do {
    } while ((param_1[1] & 1) != 0);
  }
  return;
}


/* ===== FUN_0000b23a @ 0000b23a ===== */

void FUN_0000b23a(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(int *)(param_1 + 0x2a8) != 0) {
    (**(code **)(param_1 + 0x2a8))(*(undefined4 *)(param_1 + 0x2ac),param_2,param_3);
  }
  return;
}


/* ===== FUN_0000b258 @ 0000b258 ===== */

void FUN_0000b258(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = DAT_0000b27c;
  *(undefined **)(DAT_0000b27c + 0x2ac) = &DAT_40004000;
  *(undefined4 *)(iVar1 + 0x2a8) = DAT_0000b280;
  FUN_00014c10(param_1,param_2,param_3);
  return;
}


/* ===== FUN_0000b284 @ 0000b284 ===== */

void FUN_0000b284(int param_1)

{
  do {
  } while ((*(uint *)(param_1 + 0xc) & 0x10) == 0x10);
  return;
}


/* ===== FUN_0000b294 @ 0000b294 ===== */

void FUN_0000b294(void)

{
  FUN_00013d2c(DAT_0000b2b4);
  FUN_00013e04(DAT_0000b2b4,6);
  FUN_00013d58(DAT_0000b2b4);
  FUN_0000b284(DAT_0000b2b4);
  return;
}


/* ===== FUN_0000b2b8 @ 0000b2b8 ===== */

void FUN_0000b2b8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if ((int)param_3 <= (int)uVar1) {
    uVar1 = param_3;
  }
  while (FUN_0000b300(param_1,param_2,uVar1), param_3 != uVar1) {
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


/* ===== FUN_0000b300 @ 0000b300 ===== */

void FUN_0000b300(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  FUN_0000b294();
  FUN_00013d2c(DAT_0000b35c);
  FUN_00013e04(DAT_0000b35c,2);
  FUN_00013e04(DAT_0000b35c,(param_2 << 8) >> 0x18);
  FUN_00013e04(DAT_0000b35c,(param_2 << 0x10) >> 0x18);
  FUN_00013e04(DAT_0000b35c,param_2 & 0xff);
  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
    FUN_00013e04(DAT_0000b35c,*(undefined *)(param_1 + uVar1));
  }
  FUN_00013d58(DAT_0000b35c);
  FUN_000099a2();
  return;
}


/* ===== FUN_0000b360 @ 0000b360 ===== */

void FUN_0000b360(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0000b57c(param_1,&uStack_c,DAT_0000b37c,DAT_0000b378);
  return;
}


/* ===== FUN_0000b380 @ 0000b380 ===== */

undefined8 FUN_0000b380(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uVar1 = FUN_0000b57c(param_2,param_3,&uStack_18,DAT_0000b3a0);
  FUN_0000bcaa(0,&uStack_18);
  return CONCAT44(uStack_18,uVar1);
}


/* ===== FUN_0000b3a4 @ 0000b3a4 ===== */

uint FUN_0000b3a4(int param_1)

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


/* ===== FUN_0000b3e2 @ 0000b3e2 ===== */

void FUN_0000b3e2(void)

{
  FUN_00008caa(0x10000000);
  return;
}


/* ===== FUN_0000b40c @ 0000b40c ===== */

void FUN_0000b40c(undefined4 param_1)

{
  *DAT_0000b414 = param_1;
  return;
}


/* ===== FUN_0000b418 @ 0000b418 ===== */

undefined8 FUN_0000b418(int *param_1,int param_2,uint param_3,uint param_4,uint param_5,int param_6)

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
    *param_1 = (int)&DAT_0000b570;
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
        lVar11 = (ulonglong)DAT_0000b568 << 0x20;
        lVar13 = (ulonglong)DAT_0000b56c << 0x20;
        uVar7 = uVar1;
        if ((int)uVar1 < 0) {
          uVar7 = -uVar1;
          lVar13 = (ulonglong)DAT_0000b56c << 0x20;
          lVar11 = (ulonglong)DAT_0000b568 << 0x20;
        }
        while( true ) {
          uVar6 = (undefined4)((ulonglong)lVar11 >> 0x20);
          uVar8 = (undefined4)((ulonglong)lVar13 >> 0x20);
          if (uVar7 == 0) break;
          if ((uVar7 & 1) != 0) {
            lVar13 = FUN_00008e10((int)lVar13,uVar8,(int)lVar11,uVar6);
          }
          lVar11 = FUN_00008e10((int)lVar11,uVar6);
          uVar7 = (int)uVar7 >> 1;
        }
        uVar10 = 1;
        if ((int)uVar1 < 0) {
          uVar12 = FUN_00008e10();
        }
        else {
          uVar12 = FUN_00008ef4(param_3,param_4,(int)lVar13,uVar8);
        }
        bVar9 = true;
        FUN_0000910c();
        if ((bool)uVar10 && !bVar9) {
          FUN_00008cc2((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,DAT_0000b578);
          lVar13 = FUN_00009512();
        }
        else {
          lVar13 = -1;
        }
        for (iVar4 = 0x10; (lVar13 != 0 && (-1 < iVar4)); iVar4 = iVar4 + -1) {
          cVar2 = '\n';
          lVar13 = FUN_00008a54();
          *(char *)(param_2 + iVar4) = cVar2 + '0';
        }
        iVar3 = 0x11 - (iVar4 + 1);
        if (param_6 != 1) break;
        if (lVar13 == 0) {
          iVar5 = (iVar3 - param_5) + -1;
          goto LAB_0000b558;
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
LAB_0000b558:
    param_1[2] = iVar3;
    param_1[3] = param_6;
    *param_1 = iVar4 + 1 + param_2;
    param_1[1] = iVar5;
  }
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_0000b57c @ 0000b57c ===== */

int FUN_0000b57c(byte *param_1,int **param_2,undefined4 param_3,code *param_4)

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
LAB_0000b9ac:
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
      if ((uVar4 & DAT_0000b978) == 0) break;
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
LAB_0000b652:
      if (param_1[1] == bVar1) {
        uVar11 = uVar11 + 0x100000;
        param_1 = param_1 + 1;
      }
    }
    else if (bVar1 < 0x6d) {
      if (bVar1 != 0x4c) {
        if (bVar1 == 0x68) {
          uVar11 = uVar11 | 0x300000;
          goto LAB_0000b652;
        }
        if (bVar1 != 0x6a) goto LAB_0000b660;
        uVar11 = uVar11 | 0x200000;
      }
    }
    else if ((bVar1 != 0x74) && (bVar1 != 0x7a)) goto LAB_0000b660;
    param_1 = param_1 + 1;
LAB_0000b660:
    uVar4 = (uint)*param_1;
    bVar21 = SBORROW4(uVar4,0x66);
    bVar19 = (int)(uVar4 - 0x66) < 0;
    bVar20 = uVar4 == 0x66;
LAB_0000b664:
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
          if (uVar4 == 0x69) goto LAB_0000b77e;
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
            goto LAB_0000b9aa;
          }
          if (uVar4 != 0x6f) goto LAB_0000b6b4;
          local_88 = (int *)0x8;
        }
        else {
          if (uVar4 == 0x73) {
            unaff_r10 = *ppiVar16;
            iVar5 = -1;
            goto LAB_0000b70e;
          }
          if (uVar4 == 0x75) {
            local_88 = (int *)0xa;
          }
          else {
            if (uVar4 != 0x78) goto LAB_0000b6b4;
            local_88 = (int *)0x10;
          }
        }
LAB_0000b81c:
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
LAB_0000b8a6:
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
          lVar22 = FUN_00008a54((int)lVar22,(int)((ulonglong)lVar22 >> 0x20),local_88,0);
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
          iVar3 = FUN_0000bc7c(local_74,uVar11,local_2c,param_4);
          iVar12 = iVar12 + iVar3;
        }
        for (iVar3 = 0; iVar3 < iVar5; iVar3 = iVar3 + 1) {
          (*param_4)(*(undefined *)((int)&local_84 + iVar3),local_2c);
          iVar12 = iVar12 + 1;
        }
        if ((int)(uVar11 << 0xf) < 0) {
          iVar5 = FUN_0000bc7c(local_74,uVar11,local_2c,param_4);
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
        goto LAB_0000b9a4;
      }
      if (uVar4 == 0x58) {
        local_88 = (int *)0x10;
        goto LAB_0000b81c;
      }
      if (0x58 < uVar4) {
        if (uVar4 == 99) {
          iVar5 = 1;
          unaff_r10 = &local_88;
LAB_0000b70e:
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
          iVar5 = FUN_0000bc7c(piVar14,uVar11,local_2c,param_4);
          iVar12 = iVar5 + iVar12 + iVar3;
          while (bVar20 = iVar3 != 0, iVar3 = iVar3 + -1, bVar20) {
            (*param_4)(*(char *)unaff_r10,local_2c);
            unaff_r10 = (int *)((int)unaff_r10 + 1);
          }
          goto LAB_0000b9a4;
        }
        if (uVar4 == 100) {
LAB_0000b77e:
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
LAB_0000b7de:
            local_84 = (char *)CONCAT31(local_84._1_3_,uVar7);
            iVar5 = 1;
          }
          else {
            if ((int)(uVar11 << 0x14) < 0) {
              uVar7 = 0x2b;
              goto LAB_0000b7de;
            }
            iVar5 = uVar11 << 0x1f;
            if (iVar5 != 0) {
              uVar7 = 0x20;
              goto LAB_0000b7de;
            }
          }
          goto LAB_0000b8a6;
        }
        if (uVar4 != 0x65) goto LAB_0000b6b4;
        break;
      }
      if (uVar4 == 0) {
        return iVar12;
      }
      bVar21 = SBORROW4(uVar4,0x45);
      bVar19 = (int)(uVar4 - 0x45) < 0;
      bVar20 = uVar4 == 0x45;
      if (!bVar20) goto code_r0x0000b676;
    }
    goto LAB_0000b9bc;
  }
  goto LAB_0000b6b4;
code_r0x0000b676:
  bVar21 = SBORROW4(uVar4,0x46);
  bVar19 = (int)(uVar4 - 0x46) < 0;
  bVar20 = uVar4 == 0x46;
  if (!bVar20) goto code_r0x0000b67a;
  goto LAB_0000b664;
code_r0x0000b67a:
  if (uVar4 != 0x47) {
LAB_0000b6b4:
    (*param_4)(uVar4,local_2c);
    iVar12 = iVar12 + 1;
    goto LAB_0000b9aa;
  }
LAB_0000b9bc:
  if (-1 < (int)(uVar11 << 0x1d)) {
    piVar14 = (int *)0x6;
  }
  puVar18 = (undefined4 *)((int)ppiVar16 + 7U & 0xfffffff8);
  param_2 = (int **)(puVar18 + 2);
  uVar9 = *puVar18;
  if ((puVar18[1] & 0x80000000) == 0) {
    if ((int)(uVar11 << 0x14) < 0) {
      local_38 = &DAT_0000bc50;
    }
    else if ((uVar11 & 1) == 0) {
      local_38 = (byte *)0xb98c;
    }
    else {
      local_38 = &DAT_0000bc54;
    }
  }
  else {
    local_38 = &DAT_0000bc4c;
  }
  uVar10 = puVar18[1] & 0x7fffffff;
  if (uVar4 == 0x65) {
LAB_0000ba26:
    if ((int)piVar14 < 0x11) {
      local_88 = (int *)((int)piVar14 + 1);
    }
    else {
      local_88 = (int *)0x11;
    }
    local_84 = (char *)0x0;
    FUN_0000b418(&local_50,auStack_70,uVar9,uVar10);
    local_7c = (char *)piStack_48;
    local_88 = (int *)local_50;
    unaff_r10 = (int *)((int)piVar14 + 1);
    local_78 = (int *)0x0;
LAB_0000baee:
    local_78 = (int *)0x0;
    local_84 = (char *)0x1;
    local_80 = local_4c;
    local_88 = (int *)local_50;
    local_7c = (char *)piStack_48;
  }
  else if (uVar4 < 0x66) {
    if (uVar4 == 0x45) goto LAB_0000ba26;
    if (uVar4 == 0x46) goto LAB_0000ba52;
    if (uVar4 == 0x47) goto LAB_0000ba98;
  }
  else if (uVar4 == 0x66) {
LAB_0000ba52:
    local_84 = (char *)0x1;
    local_80 = (int *)0x80000000;
    local_88 = piVar14;
    FUN_0000b418(&local_50,auStack_70,uVar9,uVar10);
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
    if (uVar4 != 0x67) goto LAB_0000bb22;
LAB_0000ba98:
    if ((int)piVar14 < 1) {
      piVar14 = (int *)0x1;
    }
    local_88 = piVar14;
    if (0x11 < (int)piVar14) {
      local_88 = (int *)0x11;
    }
    local_84 = (char *)0x0;
    FUN_0000b418(&local_50,auStack_70,uVar9,uVar10);
    local_7c = (char *)piStack_48;
    local_78 = (int *)0x0;
    local_88 = (int *)local_50;
    unaff_r10 = piVar14;
    if (-1 < (int)(uVar11 << 0x1c)) {
      piVar6 = piStack_48;
      if ((int)piVar14 <= (int)piStack_48) goto LAB_0000bad2;
      while( true ) {
        unaff_r10 = piVar6;
LAB_0000bad2:
        if (((int)unaff_r10 < 2) || (*(char *)((int)unaff_r10 + local_50 + -1) != '0')) break;
        piVar6 = (int *)((int)unaff_r10 + -1);
      }
    }
    if (((int)piVar14 <= (int)local_4c) || ((int)(local_4c + 1) < 0 != SCARRY4((int)local_4c,4)))
    goto LAB_0000baee;
    if ((int)local_4c < 1) {
      local_78 = local_4c;
      piVar14 = (int *)((int)unaff_r10 - (int)local_4c);
LAB_0000bb12:
      unaff_r10 = piVar14;
    }
    else {
      piVar14 = (int *)((int)local_4c + 1);
      if ((int)unaff_r10 < (int)piVar14) goto LAB_0000bb12;
    }
    local_84 = (char *)((int)local_4c + (1 - (int)local_78));
    local_80 = (int *)0x80000000;
  }
LAB_0000bb22:
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
      local_80 = (int *)FUN_0000919c(local_80,10);
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
    iVar5 = FUN_0000bc7c(local_74,uVar11,local_2c,param_4);
    iVar12 = iVar12 + iVar5;
  }
  if (*local_38 != 0) {
    (*param_4)(*local_38,local_2c);
    iVar12 = iVar12 + 1;
  }
  iVar5 = iVar12;
  piVar14 = unaff_r10;
  if ((int)(uVar11 << 0xf) < 0) {
    iVar5 = FUN_0000bc7c(local_74,uVar11,local_2c,param_4);
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
LAB_0000b9a4:
  iVar5 = FUN_0000bc58(piVar14,uVar11,local_2c,param_4);
  iVar12 = iVar12 + iVar5;
LAB_0000b9aa:
  param_1 = param_1 + 1;
  goto LAB_0000b9ac;
}


/* ===== FUN_0000bc58 @ 0000bc58 ===== */

int FUN_0000bc58(int param_1,int param_2,undefined4 param_3,code *param_4)

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


/* ===== FUN_0000bc7c @ 0000bc7c ===== */

int FUN_0000bc7c(int param_1,int param_2,undefined4 param_3,code *param_4)

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


/* ===== FUN_0000bcaa @ 0000bcaa ===== */

void FUN_0000bcaa(undefined param_1,undefined4 *param_2)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)*param_2;
  *param_2 = puVar1 + 1;
  *puVar1 = param_1;
  return;
}


/* ===== FUN_0000bcb4 @ 0000bcb4 ===== */

void FUN_0000bcb4(int param_1,int param_2,int param_3,int param_4)

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


/* ===== FUN_0000bce8 @ 0000bce8 ===== */

undefined4 FUN_0000bce8(undefined4 param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  *DAT_0000bd64 = param_3;
  DAT_0000bd64[-6] = param_2;
  DAT_0000bd64[-7] = 0;
  if (param_2 == 0x40) {
    iVar2 = -1;
    iVar3 = iVar2;
  }
  else {
    iVar2 = (1 << (param_2 & 0xff)) + -1;
    iVar3 = iVar2 >> 0x1f;
  }
  DAT_0000bd64[-5] = iVar2;
  DAT_0000bd64[-4] = iVar3;
  DAT_0000bd64[-7] = 1;
  FUN_000115bc(param_1,DAT_0000bd68,4,0,param_2 & 0xffff);
  bVar1 = false;
  while (!bVar1) {
    bVar1 = DAT_0000bd64[-3] != 0;
  }
  return DAT_0000bd64[1];
}


/* ===== FUN_0000bd6c @ 0000bd6c ===== */

ulonglong FUN_0000bd6c(undefined4 param_1,undefined2 param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  
  *DAT_0000be04 = param_3;
  DAT_0000be04[-1] = 0;
  if (param_3 != 0x40) {
    uVar2 = (1 << (param_3 & 0xff)) - 1;
    DAT_0000be04[1] = uVar2;
    DAT_0000be04[2] = (int)uVar2 >> 0x1f;
    DAT_0000be04[-1] = 1;
  }
  FUN_000115bc(param_1,DAT_0000be08,param_2,0,param_3 & 0xffff);
  bVar1 = false;
  while (!bVar1) {
    bVar1 = DAT_0000be04[3] != 0;
  }
  return CONCAT44(DAT_0000be04[4],DAT_0000be04[5]) & 0x3fffffffff;
}


/* ===== FUN_0000be0c @ 0000be0c ===== */

void FUN_0000be0c(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                 int param_7,int param_8,int param_9,int param_10,int param_11,int param_12)

{
  int iVar1;
  
  iVar1 = DAT_0000be84;
  *(uint *)(DAT_0000be84 + 300) =
       (((*(uint *)(DAT_0000be84 + 300) & 0xfff0ffff | param_1 << 0x10) & 0xff0fffff |
        param_2 << 0x14) & 0xf0ffffff | param_3 << 0x18) & 0xfffffff | param_4 << 0x1c;
  *(uint *)(iVar1 + 0x130) =
       ((param_5 | param_7 << 4 | param_8 << 8 | param_9 << 0xc | param_10 << 0x10 |
        param_11 << 0x14) & 0xf0ffffff | param_6 << 0x18) & 0xfffffff | param_12 << 0x1c;
  return;
}


/* ===== FUN_0000be88 @ 0000be88 ===== */

void FUN_0000be88(int param_1)

{
  if (param_1 == 0) {
    *(uint *)(DAT_0000bea0 + 0x274) = *DAT_0000be9c | 0x20;
  }
  return;
}


/* ===== FUN_0000bea4 @ 0000bea4 ===== */

void FUN_0000bea4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  uVar4 = 0;
  if (param_1 != 0) {
    uVar3 = 0x30000;
  }
  if (param_2 != 0) {
    uVar3 = 0x30000;
    uVar4 = 0x30000;
  }
  *(uint *)(DAT_0000bf30 + 0x160) = *DAT_0000bf2c & 0xfffffffe;
  DAT_0000bf2c[-0x20] = uVar3;
  iVar1 = DAT_0000bf30;
  *(undefined4 *)(DAT_0000bf30 + 0xf8) = uVar4;
  iVar2 = DAT_0000bf30;
  *(uint *)(DAT_0000bf30 + 0x160) = *(uint *)(iVar1 + 0x160) | 1;
  *(uint *)(iVar2 + 0x160) = *(uint *)(iVar2 + 0x160) & 0xfffffffe;
  *DAT_0000bf2c = *(uint *)(iVar2 + 0x160) | 1;
  *(undefined4 *)(DAT_0000bf30 + 0x274) = 0x20;
  *DAT_0000bf34 = *DAT_0000bf34 & 3 | 0x78;
  return;
}


/* ===== FUN_0000bf38 @ 0000bf38 ===== */

void FUN_0000bf38(int param_1,int param_2)

{
  uint *puVar1;
  
  *DAT_0000bfd0 = param_2 << 0xd | param_1 << 0x11 | DAT_0000bfcc[0x10];
  puVar1 = DAT_0000bfd0;
  DAT_0000bfd0[-0x11] = 0x5f;
  puVar1[-0x10] = *DAT_0000bfcc;
  puVar1[-0xf] = DAT_0000bfcc[1];
  puVar1[-0xe] = DAT_0000bfcc[2];
  puVar1[-0xd] = DAT_0000bfcc[3];
  puVar1[-0xc] = DAT_0000bfcc[4];
  puVar1[-0xb] = DAT_0000bfcc[5];
  puVar1[-10] = DAT_0000bfcc[6];
  puVar1[-9] = DAT_0000bfcc[7];
  puVar1[-8] = DAT_0000bfcc[8];
  puVar1[-7] = DAT_0000bfcc[9];
  puVar1[-6] = DAT_0000bfcc[10];
  puVar1[-5] = DAT_0000bfcc[0xb];
  puVar1[-4] = DAT_0000bfcc[0xc];
  puVar1[-3] = DAT_0000bfcc[0xd];
  puVar1[-2] = DAT_0000bfcc[0xe];
  DAT_0000bfd0[-1] = DAT_0000bfcc[0xf];
  return;
}


/* ===== FUN_0000bfd4 @ 0000bfd4 ===== */

void FUN_0000bfd4(void)

{
  *(undefined4 *)(DAT_0000bfdc + 0x48) = 1;
  return;
}


/* ===== FUN_0000bfe0 @ 0000bfe0 ===== */

void FUN_0000bfe0(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *(uint *)(DAT_0000c010 + 0x24) | 3;
  }
  else {
    uVar1 = *(uint *)(DAT_0000c010 + 0x24) & 0xfffffffc;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 0xc;
  }
  else {
    uVar1 = uVar1 & 0xfffffff3;
  }
  *(uint *)(DAT_0000c010 + 0x24) = uVar1;
  *(undefined4 *)(DAT_0000c010 + 0x30) = 0x20;
  return;
}


/* ===== FUN_0000c014 @ 0000c014 ===== */

undefined8
FUN_0000c014(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = param_3 * param_2 & 0xffff;
    param_1 = 4;
    FUN_0000e43c(1,param_4,param_5,0,4,uVar1,0xc,0);
    FUN_0000bfd4();
    do {
    } while (*(uint *)(DAT_0000c12c + 0x28) <= param_3 * param_2 &&
             param_3 * param_2 - *(uint *)(DAT_0000c12c + 0x28) != 0);
    FUN_0000e598(1);
  }
  else if (param_1 == 1) {
    uVar1 = param_3 * param_2 & 0xffff;
    param_1 = 4;
    FUN_0000e43c(2,param_6,param_7,0,4,uVar1,0xd,0);
    FUN_0000bfd4();
    do {
    } while (*(uint *)(DAT_0000c12c + 0x38) <= param_3 * param_2 &&
             param_3 * param_2 - *(uint *)(DAT_0000c12c + 0x38) != 0);
    FUN_0000e598(2);
  }
  else {
    uVar1 = param_2;
    if (param_1 == 2) {
      FUN_0000e43c(1,param_4,param_5,0,4,param_3 * param_2 & 0xffff,0xc,0);
      uVar1 = param_3 * param_2 & 0xffff;
      param_1 = 4;
      FUN_0000e43c(2,param_6,param_7,0,4,uVar1,0xd,0);
      FUN_0000bfd4();
      do {
        do {
        } while (*(uint *)(DAT_0000c12c + 0x28) <= param_3 * param_2 &&
                 param_3 * param_2 - *(uint *)(DAT_0000c12c + 0x28) != 0);
      } while (*(uint *)(DAT_0000c12c + 0x38) <= param_3 * param_2 &&
               param_3 * param_2 - *(uint *)(DAT_0000c12c + 0x38) != 0);
      FUN_0000e598(1);
      FUN_0000e598(2);
    }
  }
  FUN_0000d4bc(0xc,0);
  return CONCAT44(uVar1,param_1);
}


/* ===== FUN_0000c130 @ 0000c130 ===== */

void FUN_0000c130(uint param_1,int param_2,int param_3)

{
  *(uint *)(DAT_0000c144 + 0x34) = param_3 << 2 | param_2 << 1 | 0x1000U | param_1;
  return;
}


/* ===== FUN_0000c148 @ 0000c148 ===== */

void FUN_0000c148(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1 << 3;
  iVar3 = param_2 << 3;
  FUN_0000bea4(param_1,param_2);
  FUN_0000be0c(iVar2,iVar2,iVar2,param_1 << 3,param_1 << 3,param_1 << 3,iVar3,iVar3,iVar3,
               param_2 << 3,param_2 << 3,param_2 << 3);
  FUN_0000be88(param_4);
  FUN_0000bfe0(param_1,param_2);
  FUN_0000c130(param_3,1,0x100);
  FUN_0000bf38(0,1);
  FUN_0000cdf4(DAT_0000c1e4,DAT_0000c1e8);
  uVar1 = FUN_00009084();
  FUN_0000d434(0x2e6,uVar1,0x100,1,param_5);
  return;
}


/* ===== FUN_0000c1ec @ 0000c1ec ===== */

void FUN_0000c1ec(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  
  bVar1 = *param_1;
  bVar2 = param_1[1];
  bVar3 = *param_1;
  bVar4 = param_1[1];
  FUN_00014cb4(param_1[2],param_1[3]);
  FUN_00014c8c(*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
  FUN_0001301c(*param_1,param_1[1]);
  FUN_0001160c(*param_1,param_1[1]);
  FUN_00010de0(*param_1,param_1[1]);
  FUN_00010db8((uint)bVar3 * 0xf,(uint)bVar4 * 0xf);
  FUN_0000cd38(1);
  FUN_000127ac(*param_1,param_1[1]);
  FUN_00012800(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0x10));
  FUN_00012784((uint)bVar1 << 3,(uint)bVar2 << 3);
  FUN_00012880(*param_1,param_1[1]);
  FUN_000128d4(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0xc),
               *(undefined4 *)(param_1 + 0x14));
  FUN_00012858((uint)bVar1 << 3,(uint)bVar2 << 3);
  FUN_0001266c(0,0,0);
  FUN_000126b8(2,2,2);
  FUN_000148ec(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x18),
               *(undefined4 *)(param_1 + 0x24));
  FUN_00012398(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x1c),
               *(undefined4 *)(param_1 + 0x28));
  FUN_00011728(*(undefined4 *)(param_1 + 0x30));
  FUN_000116ac(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x20),
               *(undefined4 *)(param_1 + 0x2c));
  FUN_00012748(*(undefined4 *)(param_1 + 0x3c));
  *DAT_0000c2d4 = 0x16;
  DAT_0000c2d4[1] = 0x16;
  return;
}


/* ===== FUN_0000c2d8 @ 0000c2d8 ===== */

void FUN_0000c2d8(void)

{
  FUN_00013990(1,0);
  *DAT_0000c378 = 6;
  FUN_00010b98(10,2);
  FUN_00010b98(0xb,2);
  FUN_00010c5c(3,0);
  FUN_00010c5c(4,1);
  FUN_00010b98(5,2);
  FUN_00010c5c(6,0);
  FUN_00010b98(0x17,2);
  FUN_00010b98(0x18,2);
  FUN_00010b98(0x19,2);
  FUN_00010b98(0x1a,2);
  FUN_00010b98(0x1b,2);
  FUN_00010b98(0x1c,2);
  FUN_00010b98(0x1d,2);
  FUN_00010b98(0x1e,2);
  FUN_00011558(1);
  FUN_00012a0c(1,1000,0x20,0);
  FUN_00012310();
  *DAT_0000c37c = 8;
  return;
}


/* ===== FUN_0000c380 @ 0000c380 ===== */

void FUN_0000c380(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_0000c3c4;
  *DAT_0000c3c4 = 1;
  puVar1[1] = 1;
  puVar1[2] = 1;
  puVar1[3] = 0;
  puVar1[4] = 0;
  *(undefined4 *)(puVar1 + 0x34) = 0xe;
  *(undefined4 *)(puVar1 + 0x38) = 0;
  *(undefined4 *)(puVar1 + 0x18) = 1;
  *(undefined4 *)(puVar1 + 0x1c) = 1;
  *(undefined4 *)(puVar1 + 0x20) = 1;
  *(undefined4 *)(puVar1 + 8) = 2;
  *(undefined4 *)(puVar1 + 0xc) = 0x12;
  *(undefined4 *)(puVar1 + 0x10) = 2;
  *(undefined4 *)(puVar1 + 0x14) = 0x12;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *(undefined4 *)(puVar1 + 0x28) = 0x96;
  *(undefined4 *)(puVar1 + 0x2c) = 0;
  *(undefined4 *)(puVar1 + 0x30) = 1;
  return;
}


/* ===== FUN_0000c3c8 @ 0000c3c8 ===== */

void FUN_0000c3c8(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0000c41c(1);
  FUN_0000c2d8();
  FUN_0000c4d8(param_1,2);
  FUN_0000c1ec(param_1);
  FUN_0000c148(*param_1,param_1[1],1,0,2,param_3,param_4);
  FUN_00013fbc();
  FUN_000111cc(1,0);
  FUN_00010fb0(0,0,0,0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c));
  return;
}


/* ===== FUN_0000c41c @ 0000c41c ===== */

void FUN_0000c41c(int param_1)

{
  *DAT_0000c4d4 = 1;
  if (param_1 == 1) {
    FUN_0000cd64(1,0,0);
    FUN_0000d4bc(0x32,0);
    FUN_0000cd64(1,0);
    FUN_0000d4bc(0x32,0);
    FUN_00011874(1);
    FUN_0000d4bc(0x32,0);
    FUN_00011cc8(1,0);
    FUN_0000d4bc(0x32,0);
    FUN_00011c74(1,3);
    FUN_0000d4bc(0x32,0);
    FUN_0000d3fc(1,0);
    FUN_0000d4bc(0x32,0);
    FUN_00010bf0(0x16,1);
    FUN_00010b98(0x16,0);
  }
  else {
    FUN_00011874(0,1);
    FUN_00011cc8(0);
    FUN_00011c74(0,3);
    FUN_0000cd64(0,0,0);
    FUN_0000d3fc(0,1);
  }
  return;
}


/* ===== FUN_0000c4d8 @ 0000c4d8 ===== */

undefined8 FUN_0000c4d8(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  FUN_00011854();
  FUN_00011818(1);
  FUN_000118e0(DAT_0000c568,0xa28,param_2);
  FUN_00010034(DAT_0000c568,0xa28,0x5c,0xc,0,param_2,param_3,param_4);
  *DAT_0000c56c = 1;
  FUN_00010500(0);
  FUN_0001291c(*param_1 | param_1[1] | param_1[2] | param_1[3],
               *param_1 | param_1[1] | param_1[2] | param_1[3]);
  FUN_00014c48(param_1[4]);
  FUN_000125b8(1,param_1[2],param_1[3],*param_1,param_1[1]);
  uVar1 = 8;
  uVar2 = 10;
  FUN_0000cdb4(8,8,8);
  return CONCAT44(uVar2,uVar1);
}


/* ===== FUN_0000c570 @ 0000c570 ===== */

void FUN_0000c570(void)

{
  undefined *puVar1;
  
  puVar1 = DAT_0000c5ac;
  *DAT_0000c5ac = 1;
  puVar1[1] = 1;
  puVar1[2] = 1;
  puVar1[3] = 1;
  puVar1[4] = 1;
  *(undefined4 *)(puVar1 + 0x34) = 0xe;
  *(undefined4 *)(puVar1 + 0x38) = 0xe;
  *(undefined4 *)(puVar1 + 0x18) = 1;
  *(undefined4 *)(puVar1 + 0x1c) = 1;
  *(undefined4 *)(puVar1 + 0x20) = 1;
  *(undefined4 *)(puVar1 + 8) = 1;
  *(undefined4 *)(puVar1 + 0xc) = 0xf;
  *(undefined4 *)(puVar1 + 0x10) = 1;
  *(undefined4 *)(puVar1 + 0x14) = 0xf;
  *(undefined4 *)(puVar1 + 0x24) = 0;
  *(undefined4 *)(puVar1 + 0x28) = 0x96;
  *(undefined4 *)(puVar1 + 0x2c) = 0;
  *(undefined4 *)(puVar1 + 0x30) = 1;
  return;
}


/* ===== FUN_0000c5b0 @ 0000c5b0 ===== */

void FUN_0000c5b0(void)

{
  FUN_0000a350(0,0x8000);
  FUN_00013990(1,0);
  FUN_00013990(0,1);
  FUN_00013990(3,1);
  FUN_00013990(4,1);
  FUN_00013990(5,1);
  FUN_00013990(0xd,1);
  FUN_00013990(7,1);
  FUN_00013990(10,1);
  FUN_00013990(0x15,0);
  FUN_000139f8(0x15,0);
  FUN_000139f8(4,1);
  FUN_000139f8(0xf,2);
  FUN_000139f8(3,3);
  FUN_000139f8(0,4);
  FUN_000139f8(5,5);
  return;
}


/* ===== FUN_0000c642 @ 0000c642 ===== */

void FUN_0000c642(undefined *param_1)

{
  *param_1 = 1;
  param_1[1] = 1;
  param_1[2] = 1;
  param_1[3] = 1;
  param_1[4] = 1;
  *(undefined4 *)(param_1 + 0x34) = 0xe;
  *(undefined4 *)(param_1 + 0x38) = 0xe;
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0xc) = 0x14;
  *(undefined4 *)(param_1 + 0x10) = 1;
  *(undefined4 *)(param_1 + 0x14) = 0x14;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0x96;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 1;
  return;
}


/* ===== FUN_0000c67c @ 0000c67c ===== */

void FUN_0000c67c(void)

{
  undefined uVar1;
  
  uVar1 = FUN_0000c904(0);
  *(undefined *)(DAT_0000c694 + 1) = uVar1;
  uVar1 = FUN_0000c904(DAT_0000c698);
  *(undefined *)(DAT_0000c694 + 2) = uVar1;
  return;
}


/* ===== FUN_0000c69c @ 0000c69c ===== */

void FUN_0000c69c(undefined4 param_1)

{
  *DAT_0000c6a4 = param_1;
  return;
}


/* ===== FUN_0000c6a8 @ 0000c6a8 ===== */

void FUN_0000c6a8(uint param_1,int param_2,undefined4 *param_3,int param_4)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  param_1 = param_1 & 0xffff;
  if (param_2 < 0x10) {
    uVar5 = (short)param_2 + 0x10;
  }
  else {
    uVar5 = (short)param_2 - 0x10;
  }
  uVar14 = (uint)uVar5;
  sVar1 = *(short *)(DAT_0000c7e8 + (uVar14 + param_1 * 0x20) * 4 + 0xd00);
  sVar2 = *(short *)(DAT_0000c7ec + (uVar14 + param_1 * 0x20) * 4 + 2);
  sVar3 = *(short *)(DAT_0000c7f0 + (uVar14 + param_1 * 0x20) * 4 + 0x200);
  sVar4 = *(short *)(DAT_0000c7f4 + (uVar14 + param_1 * 0x20) * 4 + 2);
  iVar6 = (int)*(short *)(DAT_0000c7f8 + (uVar14 + param_1 * 0x20) * 4 + 0x700);
  iVar7 = (int)*(short *)(DAT_0000c7fc + (uVar14 + param_1 * 0x20) * 4 + 2);
  if (param_4 == 1) {
    uVar8 = FUN_00008fd2(param_2 + -0x10);
    uVar8 = FUN_00008bca(uVar8,0x3f800000);
    uVar8 = FUN_00008c2e(uVar8,DAT_0000c800);
    uVar8 = FUN_00008bca(DAT_0000c804,uVar8);
    uVar8 = FUN_00008bca(uVar8,DAT_0000c808);
  }
  else {
    uVar8 = 0;
  }
  uVar14 = *DAT_0000c80c;
  uVar8 = FUN_00008b1a(*DAT_0000c810 ^ 0x80000000,uVar8);
  uVar9 = FUN_00008fd2(iVar7);
  uVar10 = FUN_00008fd2(iVar6);
  uVar11 = FUN_00008fd2((int)sVar2);
  uVar12 = FUN_00008fd2((int)sVar1);
  uVar9 = FUN_0001176c(uVar12,uVar11,uVar10,uVar9,uVar14 ^ 0x80000000);
  uVar10 = FUN_00008fd2(iVar7);
  uVar11 = FUN_00008fd2(iVar6);
  uVar12 = FUN_00008fd2((int)sVar4);
  uVar13 = FUN_00008fd2((int)sVar3);
  uVar8 = FUN_0001176c(uVar13,uVar12,uVar11,uVar10,uVar8);
  param_3[1] = uVar9;
  *param_3 = uVar8;
  return;
}


/* ===== FUN_0000c814 @ 0000c814 ===== */

void FUN_0000c814(void)

{
  FUN_0000c888((int)*(char *)(DAT_0000c824 + 2));
  return;
}


/* ===== FUN_0000c828 @ 0000c828 ===== */

void FUN_0000c828(void)

{
  FUN_0000c96c((int)*(char *)(DAT_0000c83c + 2),*DAT_0000c840);
  return;
}


/* ===== FUN_0000c844 @ 0000c844 ===== */

void FUN_0000c844(void)

{
  FUN_0000c99c((int)*(char *)(DAT_0000c854 + 2));
  return;
}


/* ===== FUN_0000c858 @ 0000c858 ===== */

void FUN_0000c858(void)

{
  FUN_0000c96c((int)*(char *)(DAT_0000c86c + 1),*DAT_0000c870);
  return;
}


/* ===== FUN_0000c874 @ 0000c874 ===== */

void FUN_0000c874(void)

{
  FUN_0000c888((int)*(char *)(DAT_0000c884 + 1));
  return;
}


/* ===== FUN_0000c888 @ 0000c888 ===== */

undefined4 FUN_0000c888(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (0xb < param_1)) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(undefined4 *)(DAT_0000c8a8 + param_1 * 0xc + 4);
  }
  return uVar1;
}


/* ===== FUN_0000c8ac @ 0000c8ac ===== */

void FUN_0000c8ac(void)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar1 = DAT_0000c8e4, iVar2 < 0xc; iVar2 = iVar2 + 1) {
    *(char *)(DAT_0000c8e4 + iVar2 * 0xc) = (char)iVar2;
    *(undefined *)(iVar1 + iVar2 * 0xc + 1) = 0;
    *(undefined4 *)(iVar1 + iVar2 * 0xc + 4) = 0;
    *(undefined *)(iVar1 + iVar2 * 0xc + 2) = 0;
  }
  return;
}


/* ===== FUN_0000c8e8 @ 0000c8e8 ===== */

void FUN_0000c8e8(undefined4 param_1,undefined4 param_2)

{
  FUN_000149d8(param_1,DAT_0000c900,param_2);
  FUN_0000c8ac();
  return;
}


/* ===== FUN_0000c904 @ 0000c904 ===== */

int FUN_0000c904(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  
  iVar1 = DAT_0000c968;
  cVar3 = -1;
  iVar2 = 0;
  do {
    if (0xb < iVar2) {
code_r0x0000c964:
      return (int)cVar3;
    }
    if (*(char *)(DAT_0000c968 + iVar2 * 0xc + 1) == '\0') {
      *(undefined *)(DAT_0000c968 + iVar2 * 0xc + 1) = 1;
      *(undefined4 *)(iVar1 + iVar2 * 0xc + 4) = 0;
      *(undefined *)(iVar1 + iVar2 * 0xc + 2) = 0;
      *(undefined4 *)(iVar1 + iVar2 * 0xc + 8) = param_1;
      cVar3 = *(char *)(iVar1 + iVar2 * 0xc);
      goto code_r0x0000c964;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


/* ===== FUN_0000c96c @ 0000c96c ===== */

void FUN_0000c96c(int param_1,undefined4 param_2)

{
  if ((-1 < param_1) && (param_1 < 0xc)) {
    *(undefined4 *)(DAT_0000c998 + param_1 * 0xc + 4) = param_2;
    *(undefined *)(DAT_0000c998 + param_1 * 0xc + 2) = 1;
  }
  return;
}


/* ===== FUN_0000c99c @ 0000c99c ===== */

void FUN_0000c99c(int param_1)

{
  if ((-1 < param_1) && (param_1 < 0xc)) {
    *(undefined *)(DAT_0000c9b8 + param_1 * 0xc + 2) = 0;
  }
  return;
}


/* ===== FUN_0000c9bc @ 0000c9bc ===== */

void FUN_0000c9bc(void)

{
  int iVar1;
  
  if (*DAT_0000ca38 == 1) {
    *DAT_0000ca38 = 0;
    for (iVar1 = 0; iVar1 < 0xc; iVar1 = iVar1 + 1) {
      if (*(char *)(DAT_0000ca3c + iVar1 * 0xc + 1) == '\x01') {
        if (*(int *)(DAT_0000ca3c + iVar1 * 0xc + 4) < 1) {
          if ((*(char *)(DAT_0000ca3c + iVar1 * 0xc + 2) != '\0') &&
             (*(int *)(DAT_0000ca3c + iVar1 * 0xc + 8) != 0)) {
            (**(code **)(DAT_0000ca3c + iVar1 * 0xc + 8))();
          }
        }
        else {
          *(int *)(DAT_0000ca3c + iVar1 * 0xc + 4) = *(int *)(DAT_0000ca3c + iVar1 * 0xc + 4) + -1;
        }
      }
    }
  }
  return;
}


/* ===== FUN_0000ca40 @ 0000ca40 ===== */

undefined4 FUN_0000ca40(undefined4 param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0000d218(param_1);
  if (iVar1 == 0) {
    FUN_00010644(param_2);
    uVar2 = 0xfffffffd;
  }
  else {
    if (*(int *)(param_2 + 2) == 0) {
      *(int *)(param_2 + 2) = iVar1;
      *(int *)(param_2 + 4) = iVar1;
    }
    else {
      *(int *)(*(int *)(param_2 + 4) + 4) = iVar1;
      *(int *)(param_2 + 4) = iVar1;
    }
    *param_2 = *param_2 + 1;
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== FUN_0000ca76 @ 0000ca76 ===== */

undefined4 FUN_0000ca76(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined in_CY;
  bool bVar2;
  
  bVar2 = true;
  FUN_00009188(param_1);
  if ((bool)in_CY && !bVar2) {
    *param_2 = 0;
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = FUN_00013eac(param_1);
    *param_2 = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== FUN_0000ca9c @ 0000ca9c ===== */

void FUN_0000ca9c(undefined4 param_1,undefined4 param_2)

{
  FUN_0000b360("Wrong parameters value: file%s oneline%d \r\n",param_1,param_2);
  return;
}


/* ===== FUN_0000cadc @ 0000cadc ===== */

undefined4 FUN_0000cadc(uint param_1,uint param_2)

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
      uVar1 = FUN_00008b1a();
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
        param_1 = FUN_00008bca(param_1,uVar1);
        param_2 = FUN_00008bca(param_2,uVar1);
        uVar7 = param_2;
        uVar8 = param_1;
      }
    }
  }
  uVar1 = DAT_0000cd10;
  iVar6 = ((param_1 << 1) >> 0x18) - ((param_2 << 1) >> 0x18);
  if (0x1b < iVar6) {
    uVar1 = DAT_0000ccec;
    if ((param_1 & 0x80000000) == 0) {
      uVar1 = DAT_0000ccf0;
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
        uVar3 = DAT_0000cd18;
        uVar2 = DAT_0000cd14;
        if ((param_1 & 0x80000000) == 0) {
          uVar3 = DAT_0000cd20;
          uVar2 = DAT_0000cd1c;
        }
      }
    }
    else {
      uVar3 = DAT_0000cd00;
      uVar2 = DAT_0000ccfc;
      if ((param_1 & 0x80000000) == 0) {
        uVar3 = DAT_0000cd08;
        uVar2 = DAT_0000cd04;
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
        uVar2 = FUN_00008b1a(uVar2,DAT_0000cd0c);
        uVar3 = FUN_00008b1a(uVar3,uVar1);
      }
      else {
        uVar9 = 0xbf000000;
        uVar2 = FUN_00008bbe(uVar2);
        uVar3 = FUN_00008bbe(uVar3,uVar1);
      }
      uVar1 = FUN_00008bca(uVar8,uVar9);
      uVar1 = FUN_00008b1a(uVar1,uVar5);
      uVar9 = FUN_00008bca(uVar9,uVar5);
      uVar9 = FUN_00008bc4(uVar9,uVar8);
      uVar1 = FUN_00008c2e(uVar9,uVar1);
    }
    else {
      uVar1 = FUN_00008c2e(uVar8,uVar5);
    }
    uVar9 = FUN_00008bca(uVar1,uVar1);
    uVar4 = FUN_00008bca(uVar9,DAT_0000cd24);
    uVar4 = FUN_00008b1a(uVar4,DAT_0000cd28);
    uVar4 = FUN_00008bca(uVar4,uVar9);
    uVar4 = FUN_00008b1a(uVar4,DAT_0000cd2c);
    uVar4 = FUN_00008bca(uVar4,uVar9);
    uVar4 = FUN_00008b1a(uVar4,DAT_0000cd30);
    uVar4 = FUN_00008bca(uVar4,uVar9);
    uVar4 = FUN_00008b1a(uVar4,DAT_0000cd34);
    uVar9 = FUN_00008bca(uVar1,uVar9);
    uVar9 = FUN_00008bca(uVar9,uVar4);
    uVar3 = FUN_00008b1a(uVar9,uVar3);
    uVar1 = FUN_00008b1a(uVar3,uVar1);
    uVar1 = FUN_00008b1a(uVar1,uVar2);
    return uVar1;
  }
  if ((param_2 & 0x80000000) == 0) {
    uVar1 = FUN_00008c2e(uVar8,uVar7);
    iVar6 = FUN_0000b3a4();
    if (iVar6 == 4) {
      FUN_0000b3e2();
    }
    return uVar1;
  }
  uVar1 = DAT_0000ccf4;
  if ((param_1 & 0x80000000) != 0) {
    uVar1 = DAT_0000ccf8;
  }
  return uVar1;
}


/* ===== FUN_0000cd38 @ 0000cd38 ===== */

void FUN_0000cd38(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_0000cd60 + 0x120) = *DAT_0000cd5c | 0x100;
  }
  else {
    *(uint *)(DAT_0000cd60 + 0x120) = *DAT_0000cd5c & 0xfffffeff;
  }
  return;
}


/* ===== FUN_0000cd64 @ 0000cd64 ===== */

void FUN_0000cd64(int param_1,uint param_2,int param_3,int param_4)

{
  *DAT_0000cdac = param_2 | param_4 << 3;
  if (param_1 == 1) {
    *(uint *)(DAT_0000cdb0 + 0x1c) = *(uint *)(DAT_0000cdb0 + 0x1c) | 0x100;
  }
  else {
    *(uint *)(DAT_0000cdb0 + 0x1c) = *(uint *)(DAT_0000cdb0 + 0x1c) & 0xfffffeff;
  }
  if (param_3 == 1) {
    *(uint *)(DAT_0000cdb0 + 0x1c) = *(uint *)(DAT_0000cdb0 + 0x1c) | 0x200;
  }
  else {
    *(uint *)(DAT_0000cdb0 + 0x1c) = *(uint *)(DAT_0000cdb0 + 0x1c) & 0xfffffdff;
  }
  return;
}


/* ===== FUN_0000cdb4 @ 0000cdb4 ===== */

void FUN_0000cdb4(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,uint param_8)

{
  *(uint *)(DAT_0000cdf0 + 0x118) =
       param_1 << 0x1c | param_2 << 0x18 | param_3 << 0x14 | param_4 << 0x10 | param_5 << 0xc |
       param_6 << 8 | param_7 << 4 | param_8;
  return;
}


/* ===== FUN_0000cdf4 @ 0000cdf4 ===== */

undefined8 FUN_0000cdf4(uint param_1,uint param_2)

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
    FUN_00008e0a(param_1,param_2,DAT_0000cec0,DAT_0000cec4);
    FUN_0000910c();
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
    goto LAB_0000ceb8;
  }
  cVar4 = '\x01';
  if ((int)uVar3 < 0) {
    FUN_00008cc2();
    FUN_0000910c();
    if (cVar4 != '\0') goto LAB_0000ceb8;
    if ((int)param_2 < 0) {
      param_1 = 0;
      param_2 = 0x80000000;
      goto LAB_0000ceb8;
    }
    uVar2 = DAT_0000cec8;
    if ((param_2 | param_1) == 0) goto LAB_0000ceb8;
  }
  else {
    uVar2 = DAT_0000cecc >> (uVar3 & 0xff);
    cVar4 = '\x01';
    if ((param_2 & uVar2 | param_1) == 0) {
      return CONCAT44(param_2,param_1);
    }
    FUN_00008cc2();
    FUN_0000910c();
    if (cVar4 != '\0') goto LAB_0000ceb8;
    if (0 < (int)param_2) {
      param_2 = param_2 + (0x100000U >> (uVar3 & 0xff));
    }
    uVar2 = param_2 & ~uVar2;
  }
  param_1 = 0;
  param_2 = uVar2;
LAB_0000ceb8:
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_0000ced0 @ 0000ced0 ===== */

uint FUN_0000ced0(int param_1,int param_2,char param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,char param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined auStack_44 [32];
  
  uVar2 = 0;
  for (uVar3 = 3; uVar3 < 0x6a; uVar3 = uVar3 + 1 & 0xffff) {
    FUN_00008ae8(auStack_44,0x20);
    if (param_3 == '\0') {
      uVar1 = FUN_000095a2(param_2 + uVar3 * 0x80,0x20,param_4,param_5,param_6,auStack_44);
      uVar2 = uVar2 | uVar1;
    }
    else if (param_3 == '\x01') {
      uVar1 = FUN_0000a36a(param_2 + uVar3 * 0x80,4,0x20,param_4,param_5,param_6,auStack_44);
      uVar2 = uVar2 | uVar1;
    }
    else if (param_3 == '\x02') {
      uVar1 = FUN_0000a754(param_2 + uVar3 * 0x80,4,0x20,param_4,param_5,param_6,auStack_44);
      uVar2 = uVar2 | uVar1;
    }
    else if (param_3 == '\x03') {
      uVar1 = FUN_00009a7e(param_2 + uVar3 * 0x80,4,0x20,param_4,param_5,param_6,auStack_44);
      uVar2 = uVar2 | uVar1;
    }
    FUN_00008ab6(param_1 + uVar3 * 0x20,auStack_44,0x20);
  }
  if (uVar2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 1 & 0xffff) {
      if (param_7 == '\0') {
        uVar1 = FUN_00009720(param_2 + uVar3 * 4,0x80,0x6a,param_8,param_9,param_10,param_1,uVar3);
        uVar2 = uVar2 | uVar1;
      }
      else if (param_7 == '\x01') {
        uVar1 = FUN_0000a504(param_2 + uVar3 * 4,0x80,0x6a,param_8,param_9,param_10,param_1,uVar3);
        uVar2 = (uVar1 | uVar2) & 0xff;
      }
      else if (param_7 == '\x02') {
        uVar1 = FUN_0000a994(param_2 + uVar3 * 4,0x80,0x6a,param_8,param_9,param_10,param_1,uVar3);
        uVar2 = uVar2 | uVar1;
      }
      else if (param_7 == '\x03') {
        uVar1 = FUN_00009cbe(param_2 + uVar3 * 4,0x80,0x6a,param_8,param_9,param_10,param_1,uVar3);
        uVar2 = uVar2 | uVar1;
      }
    }
  }
  return uVar2;
}


/* ===== FUN_0000d038 @ 0000d038 ===== */

void FUN_0000d038(void)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; iVar1 = DAT_0000d094, uVar2 < 4; uVar2 = uVar2 + 1 & 0xffff) {
    *(undefined4 *)(DAT_0000d094 + uVar2 * 0x18) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 4) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 8) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 0xc) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 0x10) = DAT_0000d098;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 0x14) = DAT_0000d09c;
  }
  FUN_000136b8();
  FUN_000139d0(DAT_0000d094);
  return;
}


/* ===== FUN_0000d0a0 @ 0000d0a0 ===== */

void FUN_0000d0a0(void)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1 & 0xff) {
    *(undefined *)(DAT_0000d190 + uVar1 * 0x84 + 0x80) = 0;
    for (uVar2 = 0; cVar3 = 3 < uVar2, uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
      FUN_00009188(*(undefined4 *)(DAT_0000d190 + uVar1 * 0x84 + 0x70),
                   *(undefined4 *)(DAT_0000d194 + uVar2 * 0x18));
      if ((((cVar3 == '\0') &&
           (FUN_00009174(*(undefined4 *)(DAT_0000d190 + uVar1 * 0x84 + 0x70),
                         *(undefined4 *)(DAT_0000d194 + uVar2 * 0x18 + 4)), cVar3 == '\0')) &&
          (FUN_00009188(*(undefined4 *)(DAT_0000d190 + uVar1 * 0x84 + 0x74),
                        *(undefined4 *)(DAT_0000d194 + uVar2 * 0x18 + 8)), cVar3 == '\0')) &&
         (((FUN_00009174(*(undefined4 *)(DAT_0000d190 + uVar1 * 0x84 + 0x74),
                         *(undefined4 *)(DAT_0000d194 + uVar2 * 0x18 + 0xc)), cVar3 == '\0' &&
           (FUN_00009188(*(undefined4 *)(DAT_0000d190 + uVar1 * 0x84 + 8),
                         *(undefined4 *)(DAT_0000d194 + uVar2 * 0x18 + 0x10)), cVar3 == '\0')) &&
          (FUN_00009174(*(undefined4 *)(DAT_0000d190 + uVar1 * 0x84 + 8),
                        *(undefined4 *)(DAT_0000d194 + uVar2 * 0x18 + 0x14)), cVar3 == '\0')))) {
        *(undefined *)(DAT_0000d190 + uVar1 * 0x84 + 0x80) = 1;
      }
    }
  }
  return;
}


/* ===== FUN_0000d198 @ 0000d198 ===== */

void FUN_0000d198(void)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; iVar1 = DAT_0000d1f4, uVar2 < 4; uVar2 = uVar2 + 1 & 0xffff) {
    *(undefined4 *)(DAT_0000d1f4 + uVar2 * 0x18) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 4) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 8) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 0xc) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 0x10) = DAT_0000d1f8;
    *(undefined4 *)(iVar1 + uVar2 * 0x18 + 0x14) = DAT_0000d1fc;
  }
  FUN_0001371c();
  FUN_00013aec(DAT_0000d1f4);
  return;
}


/* ===== FUN_0000d200 @ 0000d200 ===== */

void FUN_0000d200(void)

{
  *DAT_0000d208 = 0;
  return;
}


/* ===== FUN_0000d20c @ 0000d20c ===== */

void FUN_0000d20c(void)

{
  *DAT_0000d214 = 0;
  return;
}


/* ===== FUN_0000d218 @ 0000d218 ===== */

undefined2 * FUN_0000d218(undefined2 param_1)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_00008afe(1,8);
  if (puVar1 != (undefined2 *)0x0) {
    *puVar1 = param_1;
    *(undefined4 *)(puVar1 + 2) = 0;
  }
  return puVar1;
}


/* ===== FUN_0000d234 @ 0000d234 ===== */

void FUN_0000d234(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  char cVar6;
  undefined8 uVar7;
  
  if (*DAT_0000d3e0 == 0) {
    *DAT_0000d3e4 = '\0';
  }
  else {
    *DAT_0000d3e4 = '\x01';
    *DAT_0000d3e0 = *DAT_0000d3e0 + -1;
  }
  iVar1 = FUN_000106a8();
  bVar5 = iVar1 == 0;
  do {
    if (!bVar5) {
      return;
    }
    bVar5 = *DAT_0000d3e4 == '\x01';
  } while (!bVar5);
  uVar4 = 0;
  do {
    if (3 < uVar4) {
      FUN_000136b8();
      FUN_000139d0(DAT_0000d3ec);
      FUN_0000e308();
      return;
    }
    bVar5 = *(char *)(DAT_0000d3e8 + uVar4 * 0x84 + 0x1a) == '\x02';
    do {
      if (!bVar5) goto LAB_0000d3bc;
      bVar5 = *(char *)(DAT_0000d3e8 + uVar4 * 0x84 + 0x80) == '\0';
    } while (!bVar5);
    for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1 & 0xffff) {
      cVar6 = '\x01';
      FUN_00009174(*(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18));
      if (cVar6 != '\0') {
        cVar6 = '\x01';
        FUN_00009174(*(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18 + 4));
        if (cVar6 != '\0') {
          cVar6 = '\x01';
          FUN_00009174(*(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18 + 8));
          if (cVar6 != '\0') {
            cVar6 = '\x01';
            FUN_00009174(*(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18 + 0xc));
            if (cVar6 != '\0') {
              uVar7 = FUN_000090b6(*(undefined4 *)(DAT_0000d3e8 + uVar4 * 0x84 + 0x70));
              FUN_00008e04((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,DAT_0000d3f0);
              uVar2 = FUN_0000913c();
              *(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18) = uVar2;
              uVar7 = FUN_000090b6(*(undefined4 *)(DAT_0000d3e8 + uVar4 * 0x84 + 0x70));
              FUN_00008cc2((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,DAT_0000d3f0);
              uVar2 = FUN_0000913c();
              *(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18 + 4) = uVar2;
              uVar7 = FUN_000090b6(*(undefined4 *)(DAT_0000d3e8 + uVar4 * 0x84 + 0x74));
              FUN_00008e04((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,DAT_0000d3f0);
              uVar2 = FUN_0000913c();
              *(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18 + 8) = uVar2;
              uVar7 = FUN_000090b6(*(undefined4 *)(DAT_0000d3e8 + uVar4 * 0x84 + 0x74));
              FUN_00008cc2((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,DAT_0000d3f0);
              uVar2 = FUN_0000913c();
              iVar1 = DAT_0000d3ec;
              *(undefined4 *)(DAT_0000d3ec + uVar3 * 0x18 + 0xc) = uVar2;
              *(undefined4 *)(iVar1 + uVar3 * 0x18 + 0x10) = DAT_0000d3f4;
              *(undefined4 *)(iVar1 + uVar3 * 0x18 + 0x14) = DAT_0000d3f8;
              break;
            }
          }
        }
      }
    }
LAB_0000d3bc:
    uVar4 = uVar4 + 1 & 0xffff;
  } while( true );
}


/* ===== FUN_0000d3fc @ 0000d3fc ===== */

void FUN_0000d3fc(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_0000d430 | 0xe058;
  }
  else {
    uVar1 = *DAT_0000d430 & 0xfffffff7 | 0xe050;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 1;
  }
  else {
    uVar1 = uVar1 & 0xfffffffe;
  }
  *DAT_0000d430 = uVar1 & 0xfffff8ff;
  return;
}


/* ===== FUN_0000d434 @ 0000d434 ===== */

void FUN_0000d434(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = DAT_0000d458;
  *(int *)(DAT_0000d458 + 0x54) = (param_1 - param_3 * (param_4 + 1)) - param_2;
  *(int *)(iVar1 + 0x58) = param_3 * (param_4 + 1);
  *(int *)(iVar1 + 0x50) = param_1;
  *(undefined4 *)(iVar1 + 0x5c) = param_5;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  return;
}


/* ===== FUN_0000d45c @ 0000d45c ===== */

short FUN_0000d45c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  undefined4 param_6,short param_7)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  sVar1 = 0;
  for (uVar3 = 0; (int)uVar3 < param_2; uVar3 = uVar3 + 1 & 0xffff) {
    if (*(int *)(param_1 + uVar3 * 0x14) == -1) {
      iVar2 = FUN_0000e728(uVar3,sVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7 + -1)
      ;
      if (iVar2 == 1) {
        sVar1 = sVar1 + 1;
      }
    }
  }
  return sVar1;
}


/* ===== FUN_0000d4bc @ 0000d4bc ===== */

void FUN_0000d4bc(int param_1,int param_2)

{
  *DAT_0000d504 = 0;
  if (param_2 == 1) {
    FUN_0000e674(param_1 * 0x32 + -1,0);
  }
  else {
    FUN_0000e674(param_1 * 100 + -1,0);
  }
  do {
  } while (*DAT_0000d504 != 1);
  return;
}


/* ===== FUN_0000d508 @ 0000d508 ===== */

void FUN_0000d508(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 4);
    while (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 4);
      FUN_00010644(iVar1);
      iVar1 = iVar2;
    }
    FUN_00010644(param_1);
  }
  return;
}


/* ===== FUN_0000d52c @ 0000d52c ===== */

void FUN_0000d52c(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_00010844();
  puVar1 = DAT_0000d61c;
  if (iVar2 == 0) {
    *DAT_0000d61c = DAT_0000d618;
    puVar1[1] = DAT_0000d620;
    puVar1[2] = DAT_0000d618;
    puVar1[3] = DAT_0000d620;
    puVar1[4] = 0x3f000000;
    puVar1[5] = DAT_0000d620;
    puVar1[6] = 0;
    puVar1 = DAT_0000d61c;
    DAT_0000d61c[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0x3f000000;
    puVar1[0xb] = DAT_0000d620;
    DAT_0000d61c[0xc] = 0;
    puVar1 = DAT_0000d61c;
    DAT_0000d61c[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1[0x10] = 0x3f000000;
    puVar1[0x11] = DAT_0000d620;
    DAT_0000d61c[0x12] = 0;
    puVar1 = DAT_0000d61c;
    DAT_0000d61c[0x13] = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x16] = 0x3f000000;
    puVar1[0x17] = DAT_0000d620;
    puVar1 = DAT_0000d624;
    *DAT_0000d624 = 0x3f000000;
    puVar1[1] = DAT_0000d620;
  }
  else {
    *DAT_0000d61c = DAT_0000d618;
    puVar1[1] = DAT_0000d620;
    puVar1[2] = 0;
    puVar1[3] = DAT_0000d628;
    puVar1[4] = DAT_0000d618;
    puVar1[5] = DAT_0000d620;
    puVar1[6] = 0;
    puVar1 = DAT_0000d61c;
    DAT_0000d61c[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = DAT_0000d618;
    puVar1[0xb] = DAT_0000d620;
    DAT_0000d61c[0xc] = 0;
    puVar1 = DAT_0000d61c;
    DAT_0000d61c[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1[0x10] = DAT_0000d618;
    puVar1[0x11] = DAT_0000d620;
    DAT_0000d61c[0x12] = 0;
    puVar1 = DAT_0000d61c;
    DAT_0000d61c[0x13] = 0;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x16] = DAT_0000d618;
    puVar1[0x17] = DAT_0000d620;
    puVar1 = DAT_0000d624;
    *DAT_0000d624 = DAT_0000d618;
    puVar1[1] = DAT_0000d620;
  }
  return;
}


/* ===== FUN_0000d62c @ 0000d62c ===== */

void FUN_0000d62c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  
  if (*DAT_0000d754 != '\0') {
    for (uVar1 = 0; cVar2 = 3 < uVar1, uVar1 < 4; uVar1 = uVar1 + 1 & 0xff) {
      FUN_00009188(param_1,*(undefined4 *)(DAT_0000d758 + uVar1 * 0x18));
      if ((((cVar2 == '\0') &&
           (FUN_00009174(param_1,*(undefined4 *)(DAT_0000d758 + uVar1 * 0x18 + 4)), cVar2 == '\0'))
          && (FUN_00009188(param_2,*(undefined4 *)(DAT_0000d758 + uVar1 * 0x18 + 8)), cVar2 == '\0')
          ) && (((FUN_00009174(param_2,*(undefined4 *)(DAT_0000d758 + uVar1 * 0x18 + 0xc)),
                 cVar2 == '\0' &&
                 (FUN_00009188(param_3,*(undefined4 *)(DAT_0000d758 + uVar1 * 0x18 + 0x10)),
                 cVar2 == '\0')) &&
                (FUN_00009174(param_3,*(undefined4 *)(DAT_0000d758 + uVar1 * 0x18 + 0x14)),
                cVar2 == '\0')))) {
        return;
      }
    }
    for (uVar1 = 0; cVar2 = 3 < uVar1, uVar1 < 4; uVar1 = uVar1 + 1 & 0xff) {
      FUN_00009188(param_1,*(undefined4 *)(DAT_0000d75c + uVar1 * 0x18));
      if (((cVar2 == '\0') &&
          (FUN_00009174(param_1,*(undefined4 *)(DAT_0000d75c + uVar1 * 0x18 + 4)), cVar2 == '\0'))
         && ((FUN_00009188(param_2,*(undefined4 *)(DAT_0000d75c + uVar1 * 0x18 + 8)), cVar2 == '\0'
             && (((FUN_00009174(param_2,*(undefined4 *)(DAT_0000d75c + uVar1 * 0x18 + 0xc)),
                  cVar2 == '\0' &&
                  (FUN_00009188(param_3,*(undefined4 *)(DAT_0000d75c + uVar1 * 0x18 + 0x10)),
                  cVar2 == '\0')) &&
                 (FUN_00009174(param_3,*(undefined4 *)(DAT_0000d75c + uVar1 * 0x18 + 0x14)),
                 cVar2 == '\0')))))) {
        *(undefined *)(DAT_0000d760 + uVar1 * 0xc) = 1;
      }
    }
  }
  return;
}


/* ===== FUN_0000d764 @ 0000d764 ===== */

void FUN_0000d764(void)

{
  FUN_0000d52c();
  FUN_00013654();
  FUN_000137b8(DAT_0000d784);
  FUN_00013744();
  FUN_00013b64(*DAT_0000d788,DAT_0000d788[1]);
  return;
}


/* ===== FUN_0000d78c @ 0000d78c ===== */

void FUN_0000d78c(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  for (uVar2 = 0; iVar3 = DAT_0000db5c, uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    if ((*(char *)(DAT_0000db58 + uVar2 * 0x84 + 0x1a) == '\x02') &&
       (0x8b < *(int *)(DAT_0000db58 + uVar2 * 0x84 + 0x14))) {
      *(undefined4 *)(DAT_0000db5c + uVar2 * 0x14) =
           *(undefined4 *)(DAT_0000db58 + uVar2 * 0x84 + 0x70);
      *(undefined4 *)(iVar3 + uVar2 * 0x14 + 4) =
           *(undefined4 *)(DAT_0000db58 + uVar2 * 0x84 + 0x74);
      *(undefined4 *)(iVar3 + uVar2 * 0x14 + 8) = *(undefined4 *)(DAT_0000db58 + uVar2 * 0x84 + 8);
      *(undefined4 *)(iVar3 + uVar2 * 0x14 + 0xc) =
           *(undefined4 *)(DAT_0000db58 + uVar2 * 0x84 + 0x14);
      *(undefined *)(iVar3 + uVar2 * 0x14 + 0x10) = 2;
      *(undefined *)(iVar3 + uVar2 * 0x14 + 0x11) =
           *(undefined *)(DAT_0000db58 + uVar2 * 0x84 + 0x80);
    }
    else {
      *(undefined4 *)(DAT_0000db5c + uVar2 * 0x14) = 0;
      *(undefined4 *)(iVar3 + uVar2 * 0x14 + 4) = 0;
      *(undefined4 *)(iVar3 + uVar2 * 0x14 + 8) = 0;
      *(undefined4 *)(iVar3 + uVar2 * 0x14 + 0xc) = 0;
      *(undefined *)(iVar3 + uVar2 * 0x14 + 0x10) = 0;
      *(undefined *)(iVar3 + uVar2 * 0x14 + 0x11) = 1;
    }
  }
  uVar2 = 0;
  do {
    if (3 < uVar2) {
      return;
    }
    if (*(char *)(DAT_0000db60 + uVar2 * 0xc + 4) == '\0') {
      bVar1 = false;
      for (uVar4 = 0; iVar3 = DAT_0000db60, cVar5 = 3 < uVar4, uVar4 < 4; uVar4 = uVar4 + 1 & 0xff)
      {
        FUN_00009188(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14),
                     *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18));
        if ((((cVar5 == '\0') &&
             (FUN_00009174(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14),
                           *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 4)), cVar5 == '\0')) &&
            (FUN_00009188(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 4),
                          *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 8)), cVar5 == '\0')) &&
           (((FUN_00009174(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 4),
                           *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 0xc)), cVar5 == '\0' &&
             (FUN_00009188(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 8),
                           *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 0x10)), cVar5 == '\0')) &&
            ((FUN_00009174(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 8),
                           *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 0x14)), cVar5 == '\0' &&
             ((*(char *)(DAT_0000db5c + uVar4 * 0x14 + 0x10) == '\x02' &&
              (*(char *)(DAT_0000db5c + uVar4 * 0x14 + 0x11) == '\0')))))))) {
          bVar1 = true;
        }
      }
      if (bVar1) {
        *(int *)(DAT_0000db60 + uVar2 * 0xc + 8) = *(int *)(DAT_0000db60 + uVar2 * 0xc + 8) + 2;
        if (*DAT_0000db68 <= *(uint *)(iVar3 + uVar2 * 0xc + 8)) {
          *(undefined *)(iVar3 + uVar2 * 0xc + 4) = 1;
          *(undefined4 *)(iVar3 + uVar2 * 0xc + 8) = 0;
        }
        goto LAB_0000db1e;
      }
      *(undefined4 *)(DAT_0000db60 + uVar2 * 0xc + 8) = 0;
    }
    else {
      if (*(char *)(DAT_0000db60 + uVar2 * 0xc + 4) == '\x01') {
        bVar1 = false;
        for (uVar4 = 0; iVar3 = DAT_0000db60, cVar5 = 3 < uVar4, uVar4 < 4; uVar4 = uVar4 + 1 & 0xff
            ) {
          FUN_00009188(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14),
                       *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18));
          if (((((cVar5 == '\0') &&
                (FUN_00009174(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14),
                              *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 4)), cVar5 == '\0')) &&
               (FUN_00009188(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 4),
                             *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 8)), cVar5 == '\0')) &&
              ((FUN_00009174(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 4),
                             *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 0xc)), cVar5 == '\0' &&
               (FUN_00009188(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 8),
                             *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 0x10)), cVar5 == '\0'))))
             && ((FUN_00009174(*(undefined4 *)(DAT_0000db5c + uVar4 * 0x14 + 8),
                               *(undefined4 *)(DAT_0000db64 + uVar2 * 0x18 + 0x14)), cVar5 == '\0'
                 && ((*(char *)(DAT_0000db5c + uVar4 * 0x14 + 0x10) == '\x02' &&
                     (*(char *)(DAT_0000db5c + uVar4 * 0x14 + 0x11) == '\0')))))) {
            bVar1 = true;
          }
        }
        if ((*(char *)(DAT_0000db60 + uVar2 * 0xc) == '\x01') && (*DAT_0000db6c != '\0')) {
          bVar1 = true;
        }
        if (bVar1) {
          *(undefined4 *)(DAT_0000db60 + uVar2 * 0xc + 8) = 0;
          goto LAB_0000db4a;
        }
        *(int *)(DAT_0000db60 + uVar2 * 0xc + 8) = *(int *)(DAT_0000db60 + uVar2 * 0xc + 8) + 2;
        if (*DAT_0000db70 <= *(uint *)(iVar3 + uVar2 * 0xc + 8)) {
          *(undefined *)(iVar3 + uVar2 * 0xc + 4) = 0;
          *(undefined4 *)(iVar3 + uVar2 * 0xc + 8) = 0;
        }
      }
LAB_0000db1e:
      if (*(int *)(DAT_0000db60 + uVar2 * 0xc + 8) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(DAT_0000db60 + uVar2 * 0xc + 8) + -1;
      }
      *(int *)(DAT_0000db60 + uVar2 * 0xc + 8) = iVar3;
    }
LAB_0000db4a:
    uVar2 = uVar2 + 1 & 0xff;
  } while( true );
}


/* ===== FUN_0000db74 @ 0000db74 ===== */

char FUN_0000db74(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10 = param_4;
  uVar1 = FUN_00010a00();
  switch(uVar1) {
  case 0:
    if (*DAT_0000dc54 != '\x01') {
      FUN_00013168();
      FUN_0000e308();
    }
    *DAT_0000dc54 = '\x01';
    break;
  case 1:
    if ((param_1 == 1) || (iVar2 = FUN_0000c874(), iVar2 != 0)) {
      if (*DAT_0000dc54 != '\x01') {
        FUN_00013168();
        FUN_0000e308();
        local_10 = 1;
        FUN_0000b258(0xa14,&local_10,1);
      }
      *DAT_0000dc54 = '\x01';
    }
    else if (param_1 == 0) {
      if (*DAT_0000dc54 != '\x02') {
        FUN_00010f54();
        local_10 = 0;
        FUN_0000b258(0xa14,&local_10,1);
      }
      *DAT_0000dc54 = '\x02';
    }
    break;
  case 2:
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,1);
    *DAT_0000dc54 = '\x03';
    break;
  case 3:
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,0);
    *DAT_0000dc54 = '\x03';
    break;
  case 4:
    if (*DAT_0000dc54 != '\x04') {
      FUN_000131c0();
      FUN_0000e308();
    }
    *DAT_0000dc54 = '\x04';
    break;
  default:
    *DAT_0000dc54 = '\x01';
  }
  return *DAT_0000dc54;
}


/* ===== FUN_0000dc58 @ 0000dc58 ===== */

undefined4 FUN_0000dc58(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = 0;
  while( true ) {
    cVar2 = 3 < uVar1;
    if (3 < uVar1) {
      return 0;
    }
    FUN_00009188(param_1,*(undefined4 *)(DAT_0000dcec + uVar1 * 0x18));
    if ((((cVar2 == '\0') &&
         (FUN_00009174(param_1,*(undefined4 *)(DAT_0000dcec + uVar1 * 0x18 + 4)), cVar2 == '\0')) &&
        (FUN_00009188(param_2,*(undefined4 *)(DAT_0000dcec + uVar1 * 0x18 + 8)), cVar2 == '\0')) &&
       (((FUN_00009174(param_2,*(undefined4 *)(DAT_0000dcec + uVar1 * 0x18 + 0xc)), cVar2 == '\0' &&
         (FUN_00009188(param_3,*(undefined4 *)(DAT_0000dcec + uVar1 * 0x18 + 0x10)), cVar2 == '\0'))
        && (FUN_00009174(param_3,*(undefined4 *)(DAT_0000dcec + uVar1 * 0x18 + 0x14)), cVar2 == '\0'
           )))) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return 1;
}


/* ===== FUN_0000dcf0 @ 0000dcf0 ===== */

uint FUN_0000dcf0(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char cVar8;
  undefined8 uVar9;
  int param_11;
  int param_12;
  undefined auStack_da0 [4];
  undefined4 local_d9c;
  undefined4 local_d98;
  uint local_d94;
  undefined8 local_d90;
  undefined4 local_d88;
  undefined4 local_d84;
  undefined4 local_d80;
  undefined4 local_d7c;
  char acStack_d78 [3396];
  
  iVar1 = param_11;
  FUN_00008ae8(acStack_d78,0xd40);
  local_d7c = 0;
  FUN_00008ab6(auStack_da0,&stack0x00000000,0x18);
  iVar2 = FUN_0000ced0(acStack_d78,DAT_0000df98,param_3,param_4);
  if (iVar2 != 0) {
    for (uVar6 = 0; uVar6 < 0x20; uVar6 = uVar6 + 1 & 0xffff) {
      if (uVar6 != 0x10) {
        for (uVar7 = 3; (int)uVar7 < 0x6a; uVar7 = (uint)(short)((short)uVar7 + 1)) {
          if (acStack_d78[uVar6 + uVar7 * 0x20] == '\x01') {
            if (iVar1 == 0) {
              if (999 < *(uint *)(DAT_0000df98 + uVar7 * 0x80 + uVar6 * 4)) {
LAB_0000dd84:
                cVar8 = '\x01';
                if (iVar1 == 0) {
                  FUN_0000c6a8(uVar7,uVar6,&local_d84,1);
                }
                else {
                  FUN_0000c6a8(uVar7,uVar6,&local_d84,0);
                }
                uVar5 = local_d80;
                local_d7c = local_d84;
                *(undefined4 *)(param_2 + param_1 * 0x14) = 0xffffffff;
                *(uint *)(param_2 + param_1 * 0x14 + 4) = uVar6;
                local_d88 = 0;
                uVar3 = FUN_00008fd2(uVar7);
                local_d90._4_4_ = uVar3;
                uVar3 = FUN_00008b1a(uVar3,local_d88);
                uVar3 = FUN_00008bca(uVar3,DAT_0000df9c);
                if (param_12 == 0) {
                  uVar4 = FUN_00008bca(uVar3,local_d7c);
                  *(undefined4 *)(param_2 + param_1 * 0x14 + 8) = uVar4;
                  uVar5 = FUN_00008bca(uVar3,uVar5);
                  *(undefined4 *)(param_2 + param_1 * 0x14 + 0xc) = uVar5;
                  local_d90._4_4_ =
                       FUN_00008bca(*(undefined4 *)(param_2 + param_1 * 0x14 + 0xc),
                                    *(undefined4 *)(param_2 + param_1 * 0x14 + 0xc));
                  local_d94 = FUN_00008bca(*(undefined4 *)(param_2 + param_1 * 0x14 + 8),
                                           *(undefined4 *)(param_2 + param_1 * 0x14 + 8));
                  local_d98 = FUN_00008bca(uVar3,uVar3);
                  local_d90._0_4_ = FUN_00008bbe(local_d98,local_d94);
                  uVar5 = FUN_00008bbe((undefined4)local_d90,local_d90._4_4_);
                  FUN_00009188(uVar5,0);
                  if (cVar8 == '\0') {
                    FUN_0000ca76(uVar5,param_2 + param_1 * 0x14 + 0x10);
LAB_0000df40:
                    FUN_00009174(*(undefined4 *)(param_2 + param_1 * 0x14 + 0x10),*DAT_0000dfa4);
                    if (cVar8 != '\0') {
                      FUN_00009188(*(undefined4 *)(param_2 + param_1 * 0x14 + 0x10),DAT_0000dfa4[1])
                      ;
                      if ((cVar8 != '\0') &&
                         (param_1 = param_1 + 1 & 0xffff,
                         local_d90 = CONCAT44(local_d90._4_4_,(undefined4)local_d90),
                         param_1 == 0x1ff)) {
                        return 0x1ff;
                      }
                    }
                  }
                }
                else {
                  local_d9c = FUN_000080f4(DAT_0000dfa0);
                  local_d90 = FUN_000090b6();
                  uVar9 = FUN_000090b6(uVar5);
                  local_d98 = (undefined4)uVar9;
                  local_d94 = (uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff;
                  FUN_0000910c(local_d98,local_d94,(undefined4)local_d90,local_d90._4_4_);
                  if ((cVar8 != '\0') || (cVar8 = 0x31 < uVar7, 0x32 < (int)uVar7)) {
                    uVar4 = FUN_00008bca(uVar3,local_d7c);
                    *(undefined4 *)(param_2 + param_1 * 0x14 + 8) = uVar4;
                    uVar5 = FUN_00008bca(uVar3,uVar5);
                    *(undefined4 *)(param_2 + param_1 * 0x14 + 0x10) = uVar5;
                    uVar5 = FUN_00008bca(*(undefined4 *)(param_2 + param_1 * 0x14 + 0x10),
                                         *(undefined4 *)(param_2 + param_1 * 0x14 + 0x10));
                    local_d90._4_4_ = uVar5;
                    local_d94 = FUN_00008bca(*(undefined4 *)(param_2 + param_1 * 0x14 + 8),
                                             *(undefined4 *)(param_2 + param_1 * 0x14 + 8));
                    local_d98 = FUN_00008bca(uVar3,uVar3);
                    local_d90._0_4_ = FUN_00008bbe(local_d98,local_d94);
                    uVar5 = FUN_00008bbe((undefined4)local_d90,local_d90._4_4_);
                    FUN_00009188(uVar5,0);
                    if (cVar8 == '\0') {
                      FUN_0000ca76(uVar5,param_2 + param_1 * 0x14 + 0xc);
                      goto LAB_0000df40;
                    }
                  }
                }
              }
            }
            else if ((iVar1 != 1) || (199 < *(uint *)(DAT_0000df98 + uVar7 * 0x80 + uVar6 * 4)))
            goto LAB_0000dd84;
          }
        }
      }
    }
  }
  return param_1;
}


/* ===== FUN_0000dfa8 @ 0000dfa8 ===== */

uint FUN_0000dfa8(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined auStack_d80 [24];
  char acStack_d68 [3392];
  
  FUN_00008ab6(auStack_d80,&stack0x00000000,0x18);
  iVar1 = FUN_0000ced0(acStack_d68,DAT_0000e064,param_3,param_4);
  if (iVar1 != 0) {
    for (uVar3 = 0; uVar3 < 0x20; uVar3 = uVar3 + 1 & 0xffff) {
      if (uVar3 != 0x10) {
        for (iVar1 = 2; iVar1 < 0x6a; iVar1 = (int)(short)((short)iVar1 + 1)) {
          if (acStack_d68[uVar3 + iVar1 * 0x20] == '\x01') {
            *(undefined4 *)(param_2 + param_1 * 0x14) = 0xffffffff;
            *(uint *)(param_2 + param_1 * 0x14 + 4) = uVar3;
            *(undefined4 *)(param_2 + param_1 * 0x14 + 8) = 0;
            uVar2 = FUN_00008fd2(iVar1);
            uVar2 = FUN_00008bca(uVar2,DAT_0000e068);
            *(undefined4 *)(param_2 + param_1 * 0x14 + 0xc) = uVar2;
            *(undefined4 *)(param_2 + param_1 * 0x14 + 0x10) = 0;
            param_1 = param_1 + 1 & 0xffff;
            if (param_1 == 0x200) {
              return 0x200;
            }
          }
        }
      }
    }
  }
  return param_1;
}


/* ===== FUN_0000e06c @ 0000e06c ===== */

undefined4 FUN_0000e06c(void)

{
  undefined4 uVar1;
  
  FUN_0000d0a0();
  FUN_0000d78c();
  uVar1 = FUN_0000e084();
  return uVar1;
}


/* ===== FUN_0000e084 @ 0000e084 ===== */

uint FUN_0000e084(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_18 [4];
  
  local_18[3] = param_4;
  local_18[2] = param_3;
  local_18[1] = param_2;
  local_18[0] = param_1;
  uVar3 = 0;
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1 & 0xff) {
    local_18[uVar1] = (uint)*(byte *)(DAT_0000e264 + uVar1 * 0xc + 4);
    uVar3 = uVar3 | local_18[uVar1];
    *(undefined *)(DAT_0000e264 + uVar1 * 0xc) = 0;
  }
  iVar2 = FUN_00011654();
  if (iVar2 == 1) {
    FUN_00014c10(0xa0a,local_18,0x10);
  }
  if (uVar3 == 0) {
    FUN_000147dc();
  }
  if (*DAT_0000e268 < 6) {
                    /* WARNING: Could not recover jumptable at 0x0000e0d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(&switchD_0000e0d8::switchdataD_0000e0dc +
                      (uint)(&switchD_0000e0d8::switchdataD_0000e0dc)[*DAT_0000e268] * 2))();
    return uVar1;
  }
  return (uint)*DAT_0000e26c;
}


/* ===== FUN_0000e270 @ 0000e270 ===== */

undefined4 FUN_0000e270(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = 0;
  while( true ) {
    cVar2 = 3 < uVar1;
    if (3 < uVar1) {
      return 0;
    }
    FUN_00009188(param_1,*(undefined4 *)(DAT_0000e304 + uVar1 * 0x18));
    if ((((cVar2 == '\0') &&
         (FUN_00009174(param_1,*(undefined4 *)(DAT_0000e304 + uVar1 * 0x18 + 4)), cVar2 == '\0')) &&
        (FUN_00009188(param_2,*(undefined4 *)(DAT_0000e304 + uVar1 * 0x18 + 8)), cVar2 == '\0')) &&
       (((FUN_00009174(param_2,*(undefined4 *)(DAT_0000e304 + uVar1 * 0x18 + 0xc)), cVar2 == '\0' &&
         (FUN_00009188(param_3,*(undefined4 *)(DAT_0000e304 + uVar1 * 0x18 + 0x10)), cVar2 == '\0'))
        && (FUN_00009174(param_3,*(undefined4 *)(DAT_0000e304 + uVar1 * 0x18 + 0x14)), cVar2 == '\0'
           )))) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return 1;
}


/* ===== FUN_0000e308 @ 0000e308 ===== */

void FUN_0000e308(void)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; iVar1 = DAT_0000e428, uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined *)(DAT_0000e428 + uVar2 * 0x84 + 0x1a) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0x84 + 0x14) = 0;
  }
  for (uVar2 = 0; iVar1 = DAT_0000e42c, uVar2 < 4; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined *)(DAT_0000e42c + uVar2 * 0xc + 4) = 0;
    *(undefined4 *)(iVar1 + uVar2 * 0xc + 8) = 0;
    *(undefined *)(iVar1 + uVar2 * 0xc) = 0;
  }
  if (*DAT_0000e430 == '\0') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,0);
    *DAT_0000e434 = 0;
  }
  else if (*DAT_0000e430 == '\x01') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,1);
    *DAT_0000e434 = 0;
  }
  else if (*DAT_0000e430 == '\x02') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,0);
    *DAT_0000e434 = 0;
  }
  else if (*DAT_0000e430 == '\x03') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,1);
    *DAT_0000e434 = 0;
  }
  else if (*DAT_0000e430 == '\x02') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,0);
    FUN_0000c828();
    *DAT_0000e434 = 0;
  }
  else if (*DAT_0000e430 == '\x03') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,1);
    FUN_0000c828();
    *DAT_0000e434 = 0;
  }
  return;
}


/* ===== FUN_0000e43c @ 0000e43c ===== */

uint FUN_0000e43c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 uint param_6,int param_7,int param_8)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0000e590;
  uVar2 = 0;
  switch(param_1) {
  case 0:
    *(undefined4 *)(DAT_0000e590 + 0x10) = param_2;
    *(undefined4 *)(iVar1 + 0x14) = param_3;
    iVar1 = DAT_0000e590;
    *(int *)(DAT_0000e590 + 0x68) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    uVar2 = param_6 | DAT_0000e594 | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0xc) = uVar2;
    break;
  case 1:
    *(undefined4 *)(DAT_0000e590 + 0x20) = param_2;
    *(undefined4 *)(iVar1 + 0x24) = param_3;
    iVar1 = DAT_0000e590;
    *(int *)(DAT_0000e590 + 0x6c) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    uVar2 = param_6 | DAT_0000e594 | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x1c) = uVar2;
    break;
  case 2:
    *(undefined4 *)(DAT_0000e590 + 0x30) = param_2;
    *(undefined4 *)(iVar1 + 0x34) = param_3;
    iVar1 = DAT_0000e590;
    *(int *)(DAT_0000e590 + 0x70) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x2c) = 0;
    uVar2 = param_6 | DAT_0000e594 | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x2c) = uVar2;
    break;
  case 3:
    *(undefined4 *)(DAT_0000e590 + 0x40) = param_2;
    *(undefined4 *)(iVar1 + 0x44) = param_3;
    iVar1 = DAT_0000e590;
    *(int *)(DAT_0000e590 + 0x74) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x3c) = 0;
    uVar2 = param_6 | DAT_0000e594 | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x3c) = uVar2;
    break;
  case 4:
    *(undefined4 *)(DAT_0000e590 + 0x50) = param_2;
    *(undefined4 *)(iVar1 + 0x54) = param_3;
    iVar1 = DAT_0000e590;
    *(int *)(DAT_0000e590 + 0x78) = param_4 + param_5 * 0x10000;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    uVar2 = param_6 | DAT_0000e594 | param_8 << 0x17 | 0x1b000000 | param_7 << 0x12;
    *(uint *)(iVar1 + 0x4c) = uVar2;
  }
  return uVar2;
}


/* ===== FUN_0000e598 @ 0000e598 ===== */

void FUN_0000e598(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    *(uint *)(DAT_0000e5f4 + 0xc) = *(uint *)(DAT_0000e5f4 + 0xc) & 0x7fffffff;
    break;
  case 1:
    *(uint *)(DAT_0000e5f4 + 0x1c) = *(uint *)(DAT_0000e5f4 + 0x1c) & 0x7fffffff;
    break;
  case 2:
    *(uint *)(DAT_0000e5f4 + 0x2c) = *(uint *)(DAT_0000e5f4 + 0x2c) & 0x7fffffff;
    break;
  case 3:
    *(uint *)(DAT_0000e5f4 + 0x3c) = *(uint *)(DAT_0000e5f4 + 0x3c) & 0x7fffffff;
    break;
  case 4:
    *(uint *)(DAT_0000e5f4 + 0x4c) = *(uint *)(DAT_0000e5f4 + 0x4c) & 0x7fffffff;
  }
  return;
}


/* ===== FUN_0000e5f8 @ 0000e5f8 ===== */

void FUN_0000e5f8(int param_1,uint param_2,int param_3)

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


/* ===== FUN_0000e674 @ 0000e674 ===== */

void FUN_0000e674(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000e688;
  *(uint *)(DAT_0000e688 + 0x28) = (param_2 << 2 | 0xe0U) + 3;
  *(undefined4 *)(iVar1 + 0x20) = param_1;
  return;
}


/* ===== FUN_0000e68c @ 0000e68c ===== */

uint FUN_0000e68c(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  param_1 = param_1 & 7;
  if (7 - param_1 < 4) {
    uVar1 = 7 - param_1;
  }
  else {
    uVar1 = 3;
  }
  if (param_1 + 3 < 7) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 - 4;
  }
  return ((1 << (uVar1 & 0xff)) - 1U & param_2) << (param_1 & 0xff) |
         (1 << (param_1 & 0xff)) - 1U & param_3;
}


/* ===== FUN_0000e6cc @ 0000e6cc ===== */

void FUN_0000e6cc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < 0x1a80; iVar2 = iVar2 + 2) {
    if (iVar1 == ((int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x1b)) >> 5) * 0x20) {
      *(undefined4 *)(DAT_0000e71c + iVar1 * 4) = 0;
    }
    else {
      iVar4 = (int)*(short *)(DAT_0000e720 + iVar2 * 2 + 0x700);
      iVar3 = (int)*(short *)(DAT_0000e724 + iVar2 * 2 + 2);
      *(int *)(DAT_0000e71c + iVar1 * 4) = iVar3 * iVar3 + iVar4 * iVar4;
    }
    iVar1 = iVar1 + 1;
  }
  return;
}


/* ===== FUN_0000e728 @ 0000e728 ===== */

undefined4
FUN_0000e728(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9)

{
  ushort *puVar1;
  int iVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  undefined4 local_28;
  
  local_28 = 0;
  puVar1 = (ushort *)FUN_000106fc(param_1,param_3,param_4,param_5,param_6,param_7,param_8);
  if (puVar1 == (ushort *)0x0) {
    local_28 = 0xfffffffd;
  }
  else {
    if ((int)(uint)*puVar1 < param_9) {
      *(undefined4 *)(param_3 + param_1 * 0x14) = 0xfffffffe;
    }
    else {
      *(undefined4 *)(param_3 + param_1 * 0x14) = param_2;
      for (puVar3 = *(ushort **)(puVar1 + 2); puVar3 != (ushort *)0x0;
          puVar3 = *(ushort **)(puVar3 + 2)) {
        *(undefined4 *)(param_3 + (uint)*puVar3 * 0x14) = param_2;
      }
      for (puVar4 = *(undefined2 **)(puVar1 + 2); puVar4 != (undefined2 *)0x0;
          puVar4 = *(undefined2 **)(puVar4 + 2)) {
        iVar2 = FUN_00013e26(*puVar4,puVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                             param_9);
        if (iVar2 == -3) {
          FUN_0000d508(puVar1);
          return 0xfffffffd;
        }
      }
      local_28 = 1;
    }
    FUN_0000d508(puVar1);
  }
  return local_28;
}


/* ===== FUN_0000e7d8 @ 0000e7d8 ===== */

void FUN_0000e7d8(int param_1,undefined4 param_2)

{
  FUN_00015178(DAT_0000e7f8,param_2,param_1);
  FUN_00015158(param_1 * DAT_0000e7fc);
  FUN_00015178(0xffffffff);
  return;
}


/* ===== FUN_0000e818 @ 0000e818 ===== */

void FUN_0000e818(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    FUN_0000e864(param_1,param_3 + iVar1 * param_1 * 4,param_4 + iVar1 * param_1 * 4,param_5,param_6
                );
  }
  *(uint *)(DAT_0000e860 + 8) = *(uint *)(DAT_0000e860 + 8) & 0xfffffbff;
  return;
}


/* ===== FUN_0000e864 @ 0000e864 ===== */

void FUN_0000e864(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_0000e9bc;
  *(uint *)(DAT_0000e9bc + 0x14) = *(uint *)(DAT_0000e9bc + 0x14) & 0xfffffeff;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x100;
  iVar1 = DAT_0000e9c4;
  *(uint *)(DAT_0000e9c4 + 8) = DAT_0000e9c0 | param_1 | 0x100000;
  *(undefined4 *)(iVar1 + 4) = 4;
  *DAT_0000e9c8 = 1;
  iVar1 = (int)param_1 >> 0x1f;
  FUN_0000e43c(0,param_2,DAT_0000e9cc,param_4,4,(param_1 - iVar1) * 0x8000 >> 0x10,0,1);
  do {
  } while (*(uint *)(DAT_0000e9d0 + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000e598(0);
  uVar2 = param_1;
  FUN_0000e43c(0,((int)param_1 / 2) * param_4 + param_2,DAT_0000e9d4,param_4,4,
               (param_1 - iVar1) * 0x8000 >> 0x10,0,1,param_1);
  do {
  } while (*(uint *)(DAT_0000e9d0 + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000e598(0);
  do {
  } while (*DAT_0000e9c8 == 1);
  FUN_0000e43c(0,DAT_0000e9cc,param_3,4,param_5,(param_1 - iVar1) * 0x8000 >> 0x10,0,1,uVar2);
  FUN_0000e43c(1,DAT_0000e9d4,((int)param_1 / 2) * param_5 + param_3,4,param_5,
               (param_1 - iVar1) * 0x8000 >> 0x10,0,1,param_1);
  do {
    do {
    } while (*(uint *)(DAT_0000e9d0 + 0x18) < (uint)((int)param_1 / 2));
  } while (*(uint *)(DAT_0000e9d0 + 0x28) < (uint)((int)param_1 / 2));
  FUN_0000e598(0);
  FUN_0000e598(1);
  *DAT_0000e9c8 = 1;
  return;
}


/* ===== FUN_0000e9d8 @ 0000e9d8 ===== */

undefined8 FUN_0000e9d8(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = DAT_0000eb68;
  *(uint *)(DAT_0000eb68 + 0x14) = *(uint *)(DAT_0000eb68 + 0x14) & 0xfffffeff;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x100;
  iVar1 = DAT_0000eb70;
  *(uint *)(DAT_0000eb70 + 8) = DAT_0000eb6c | param_1 | 0x100000;
  *(undefined4 *)(iVar1 + 4) = 4;
  *DAT_0000eb74 = 1;
  iVar1 = (int)param_1 >> 0x1f;
  FUN_0000e43c(0,param_3,DAT_0000eb78,4,4,(param_1 - iVar1) * 0x8000 >> 0x10,0,1);
  do {
  } while (*(uint *)(DAT_0000eb7c + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000e598(0);
  FUN_0000e43c(0,param_3 + ((int)param_1 / 2) * 4,DAT_0000eb80,4,4,
               (param_1 - iVar1) * 0x8000 >> 0x10,0,1);
  do {
  } while (*(uint *)(DAT_0000eb7c + 0x18) < (uint)((int)param_1 / 2));
  FUN_0000e598(0);
  do {
  } while (*DAT_0000eb74 == 1);
  if ((int)param_1 / 2 < (int)param_2) {
    FUN_0000e43c(0,DAT_0000eb78,param_4,4,4,(param_1 - iVar1) * 0x8000 >> 0x10,0,1);
    uVar2 = param_2 - (int)param_1 / 2 & 0xffff;
    uVar3 = 4;
    FUN_0000e43c(1,DAT_0000eb80,param_4 + ((int)param_1 / 2) * 4);
    do {
      do {
      } while (*(uint *)(DAT_0000eb7c + 0x18) < (uint)((int)param_1 / 2));
    } while (*(uint *)(DAT_0000eb7c + 0x28) < param_2 - (int)param_1 / 2);
    FUN_0000e598(0);
    FUN_0000e598(1);
  }
  else {
    uVar2 = param_2 & 0xffff;
    uVar3 = 4;
    FUN_0000e43c(0,DAT_0000eb78,param_4);
    do {
    } while (*(uint *)(DAT_0000eb7c + 0x18) < param_2);
    FUN_0000e598(0);
  }
  *DAT_0000eb74 = 1;
  return CONCAT44(uVar2,uVar3);
}


/* ===== FUN_0000eb84 @ 0000eb84 ===== */

/* WARNING: Removing unreachable block (ram,0x0000f6a8) */
/* WARNING: Removing unreachable block (ram,0x0000ed44) */
/* WARNING: Removing unreachable block (ram,0x0000fbf2) */

void FUN_0000eb84(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined uVar13;
  char cVar14;
  undefined uVar15;
  undefined8 uVar16;
  uint local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  uint local_44;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar2 = FUN_00010838();
  uVar2 = FUN_00008c2e(uVar2,DAT_0000ef88);
  iVar3 = FUN_000113f8();
  iVar4 = FUN_000113f8();
  for (local_30 = 0; uVar9 = DAT_0000ef8c, (int)local_30 < param_3; local_30 = local_30 + 1 & 0xffff
      ) {
    *(undefined4 *)(iVar3 + local_30 * 4) = DAT_0000ef8c;
    *(undefined4 *)(iVar4 + local_30 * 4) = uVar9;
  }
  for (local_30 = 0; (int)local_30 < param_3; local_30 = local_30 + 1 & 0xffff) {
    if ((param_4 == 1) && (iVar6 = FUN_000106a8(), iVar6 == 0)) {
      puVar5 = (undefined4 *)(param_2 + local_30 * 0x14);
      iVar6 = FUN_00014714(*puVar5,puVar5[1],puVar5[2],puVar5[3],
                           *(undefined4 *)(param_2 + local_30 * 0x14 + 0x10));
      if (iVar6 != 0) goto LAB_0000ec2a;
      *(undefined4 *)(param_2 + local_30 * 0x14 + 0x10) = 0xffffffff;
    }
    else {
LAB_0000ec2a:
      local_34 = 4;
      local_44 = DAT_0000ef90;
      local_4c = DAT_0000ef8c;
      local_50 = DAT_0000ef8c;
      for (local_54 = 0; local_54 < 4; local_54 = local_54 + 1 & 0xff) {
        local_38 = (uint)*(byte *)(param_1 + local_54 * 0x84 + 0x1a);
        cVar14 = 1 < local_38;
        uVar13 = local_38 == 2;
        if ((bool)uVar13) {
          uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                               *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
          uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
          uVar9 = FUN_00008bca(uVar10,uVar9);
          uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
          uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
          uVar10 = FUN_00008bca(uVar11,uVar10);
          uVar9 = FUN_00008b1a(uVar10,uVar9);
          uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
          uVar10 = FUN_00008c2e(uVar10,uVar2);
          uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x7c));
          uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
          uVar11 = FUN_00008c2e(uVar11,uVar2);
          uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x7c));
          uVar10 = FUN_00008bca(uVar11,uVar10);
          uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
          uVar11 = FUN_00008c2e(uVar11,uVar2);
          uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x78));
          uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
          uVar12 = FUN_00008c2e(uVar12,uVar2);
          uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x78));
          uVar11 = FUN_00008bca(uVar12,uVar11);
          uVar10 = FUN_00008b1a(uVar11,uVar10);
          FUN_00009174(uVar9,DAT_0000ef98);
          if ((!(bool)cVar14 || (bool)uVar13) && (FUN_00009174(uVar10,local_44), cVar14 == '\0')) {
            local_34 = (uint)(char)local_54;
            local_50 = uVar10;
            local_4c = uVar9;
            local_44 = uVar10;
          }
        }
      }
      if (local_34 == 4) {
        local_48 = DAT_0000ef94;
        for (local_54 = 0; local_54 < 4; local_54 = local_54 + 1 & 0xff) {
          local_38 = (uint)*(byte *)(param_1 + local_54 * 0x84 + 0x1a);
          uVar15 = 1 < local_38;
          uVar13 = local_38 == 2;
          if ((bool)uVar13) {
            uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                 *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar9 = FUN_00008bca(uVar10,uVar9);
            uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar10 = FUN_00008bca(uVar11,uVar10);
            uVar9 = FUN_00008b1a(uVar10,uVar9);
            uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar10 = FUN_00008c2e(uVar10,uVar2);
            uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x7c));
            uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar11 = FUN_00008c2e(uVar11,uVar2);
            uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x7c));
            uVar10 = FUN_00008bca(uVar11,uVar10);
            uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar11 = FUN_00008c2e(uVar11,uVar2);
            uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x78));
            uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar12 = FUN_00008c2e(uVar12,uVar2);
            uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x78));
            uVar11 = FUN_00008bca(uVar12,uVar11);
            FUN_00008b1a(uVar11,uVar10);
            FUN_00009174(uVar9,local_48);
            if (!(bool)uVar15 || (bool)uVar13) {
              local_34 = (uint)(char)local_54;
              local_50 = local_44;
              local_4c = uVar9;
              local_48 = uVar9;
            }
          }
        }
        if (local_34 != 4) {
          *(undefined4 *)(iVar3 + local_34 * 4) = local_4c;
          *(undefined4 *)(iVar4 + local_34 * 4) = local_50;
        }
      }
      else {
        *(undefined4 *)(iVar3 + local_34 * 4) = local_4c;
        *(undefined4 *)(iVar4 + local_34 * 4) = local_50;
      }
      if (local_34 == 4) {
        local_48 = DAT_0000f520;
        for (local_54 = 0; local_54 < 4; local_54 = local_54 + 1 & 0xff) {
          local_38 = (uint)*(byte *)(param_1 + local_54 * 0x84 + 0x1a);
          uVar15 = local_38 != 0;
          uVar13 = local_38 == 1;
          if ((bool)uVar13) {
            uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                 *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar9 = FUN_00008bca(uVar10,uVar9);
            uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar10 = FUN_00008bca(uVar11,uVar10);
            uVar9 = FUN_00008b1a(uVar10,uVar9);
            uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar10 = FUN_00008c2e(uVar10,uVar2);
            uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x7c));
            uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14 + 4),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x74));
            uVar11 = FUN_00008c2e(uVar11,uVar2);
            uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x7c));
            uVar10 = FUN_00008bca(uVar11,uVar10);
            uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar11 = FUN_00008c2e(uVar11,uVar2);
            uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x78));
            uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_30 * 0x14),
                                  *(undefined4 *)(param_1 + local_54 * 0x84 + 0x70));
            uVar12 = FUN_00008c2e(uVar12,uVar2);
            uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_54 * 0x84 + 0x78));
            uVar11 = FUN_00008bca(uVar12,uVar11);
            FUN_00008b1a(uVar11,uVar10);
            FUN_00009174(uVar9,local_48);
            if (!(bool)uVar15 || (bool)uVar13) {
              local_34 = (uint)(char)local_54;
              local_50 = local_44;
              local_4c = uVar9;
              local_48 = uVar9;
            }
          }
        }
        if (local_34 != 4) {
          *(undefined4 *)(iVar3 + local_34 * 4) = local_4c;
          *(undefined4 *)(iVar4 + local_34 * 4) = local_50;
        }
      }
      *(uint *)(param_2 + local_30 * 0x14 + 0x10) = local_34;
    }
  }
  local_2c = 0;
  while (local_2c < 10) {
    uVar13 = false;
    local_2c = local_2c + 1;
    for (local_3c = 0; (int)local_3c < param_3 + -1; local_3c = local_3c + 1 & 0xffff) {
      iVar6 = (int)*(char *)(param_2 + local_3c * 0x14 + 0x10);
      if ((iVar6 != -1) && (local_44 = local_3c, iVar6 != 4)) {
        do {
          uVar7 = local_44 + 1;
          local_44 = uVar7 & 0xffff;
          if (param_3 <= (int)local_44) goto code_r0x0000f41e;
        } while (*(int *)(param_2 + local_44 * 0x14 + 0x10) != iVar6);
        local_34 = uVar7 & 0xff;
        local_38 = local_3c & 0xff;
        uVar13 = true;
code_r0x0000f41e:
        if ((bool)uVar13) break;
      }
    }
    uVar7 = local_34;
    if (!(bool)uVar13) break;
    uVar8 = (uint)*(char *)(param_2 + local_34 * 0x14 + 0x10);
    cVar14 = uVar13;
    FUN_00009174(*(undefined4 *)(iVar4 + local_38 * 4),*(undefined4 *)(iVar4 + local_34 * 4));
    if (cVar14 == '\0') {
      local_34 = local_38;
      local_38 = uVar7 & 0xff;
    }
    uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                         *(undefined4 *)(param_2 + local_38 * 0x14 + 4));
    uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                          *(undefined4 *)(param_2 + local_38 * 0x14 + 4));
    uVar9 = FUN_00008bca(uVar10,uVar9);
    uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                          *(undefined4 *)(param_2 + local_38 * 0x14));
    uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                          *(undefined4 *)(param_2 + local_38 * 0x14));
    uVar10 = FUN_00008bca(uVar11,uVar10);
    uVar9 = FUN_00008b1a(uVar10,uVar9);
    uVar16 = FUN_000090b6(uVar9);
    FUN_000090dc((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),DAT_0000f938,DAT_0000f93c);
    if (cVar14 == '\0') {
      FUN_00009174(*(undefined4 *)(iVar3 + local_34 * 4),*(undefined4 *)(iVar3 + local_38 * 4));
      if ((bool)cVar14 && !(bool)uVar13) {
        *(undefined4 *)(param_2 + local_34 * 0x14 + 0x10) = 0xffffffff;
      }
      else {
        *(undefined4 *)(param_2 + local_38 * 0x14 + 0x10) = 0xffffffff;
      }
    }
    else {
      FUN_00009174(*(undefined4 *)(iVar3 + local_34 * 4),*(undefined4 *)(iVar3 + local_38 * 4));
      if (!(bool)cVar14 || (bool)uVar13) {
        local_48 = 4;
        local_54 = DAT_0000f940;
        local_5c = DAT_0000f944;
        local_60 = DAT_0000f944;
        for (local_64 = 0; local_64 < 4; local_64 = local_64 + 1 & 0xff) {
          if (uVar8 != local_64) {
            bVar1 = *(byte *)(param_1 + local_64 * 0x84 + 0x1a);
            uVar15 = 1 < bVar1;
            uVar13 = bVar1 == 2;
            if ((bool)uVar13) {
              uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                   *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
              uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
              uVar9 = FUN_00008bca(uVar10,uVar9);
              uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
              uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
              uVar10 = FUN_00008bca(uVar11,uVar10);
              uVar9 = FUN_00008b1a(uVar10,uVar9);
              uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
              uVar10 = FUN_00008c2e(uVar10,uVar2);
              uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
              uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
              uVar11 = FUN_00008c2e(uVar11,uVar2);
              uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
              uVar10 = FUN_00008bca(uVar11,uVar10);
              uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
              uVar11 = FUN_00008c2e(uVar11,uVar2);
              uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
              uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                    *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
              uVar12 = FUN_00008c2e(uVar12,uVar2);
              uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
              uVar11 = FUN_00008bca(uVar12,uVar11);
              uVar10 = FUN_00008b1a(uVar11,uVar10);
              FUN_00009174(uVar9,local_54);
              if (!(bool)uVar15 || (bool)uVar13) {
                local_48 = (int)(char)local_64;
                local_60 = uVar10;
                local_5c = uVar9;
                local_54 = uVar9;
              }
            }
          }
        }
        if (local_48 == 4) {
          local_54 = DAT_0000f940;
          for (local_64 = 0; local_64 < 4; local_64 = local_64 + 1 & 0xff) {
            if (uVar8 != local_64) {
              cVar14 = *(char *)(param_1 + local_64 * 0x84 + 0x1a);
              uVar15 = cVar14 != '\0';
              uVar13 = cVar14 == '\x01';
              if ((bool)uVar13) {
                uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                     *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar9 = FUN_00008bca(uVar10,uVar9);
                uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar10 = FUN_00008bca(uVar11,uVar10);
                uVar9 = FUN_00008b1a(uVar10,uVar9);
                uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar10 = FUN_00008c2e(uVar10,uVar2);
                uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
                uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14 + 4),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar11 = FUN_00008c2e(uVar11,uVar2);
                uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
                uVar10 = FUN_00008bca(uVar11,uVar10);
                uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar11 = FUN_00008c2e(uVar11,uVar2);
                uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
                uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_38 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar12 = FUN_00008c2e(uVar12,uVar2);
                uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
                uVar11 = FUN_00008bca(uVar12,uVar11);
                uVar10 = FUN_00008b1a(uVar11,uVar10);
                FUN_00009174(uVar9,local_54);
                if (!(bool)uVar15 || (bool)uVar13) {
                  local_48 = (int)(char)local_64;
                  local_60 = uVar10;
                  local_5c = uVar9;
                  local_54 = uVar9;
                }
              }
            }
          }
          if (local_48 != 4) {
            *(undefined4 *)(iVar3 + local_48 * 4) = local_5c;
            *(undefined4 *)(iVar4 + local_48 * 4) = local_60;
          }
        }
        else {
          *(undefined4 *)(iVar3 + local_48 * 4) = local_5c;
          *(undefined4 *)(iVar4 + local_48 * 4) = local_60;
        }
        *(int *)(param_2 + local_38 * 0x14 + 0x10) = local_48;
      }
      else {
        FUN_00009188(*(undefined4 *)(iVar3 + local_34 * 4),*(undefined4 *)(iVar3 + local_38 * 4));
        if (cVar14 == '\0') {
          local_48 = 4;
          local_54 = DAT_0000fee0;
          local_5c = DAT_0000fee4;
          local_60 = DAT_0000fee4;
          for (local_64 = 0; local_64 < 4; local_64 = local_64 + 1 & 0xff) {
            if (uVar8 != local_64) {
              bVar1 = *(byte *)(param_1 + local_64 * 0x84 + 0x1a);
              uVar15 = 1 < bVar1;
              uVar13 = bVar1 == 2;
              if ((bool)uVar13) {
                uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                     *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar9 = FUN_00008bca(uVar10,uVar9);
                uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar10 = FUN_00008bca(uVar11,uVar10);
                uVar9 = FUN_00008b1a(uVar10,uVar9);
                uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar10 = FUN_00008c2e(uVar10,uVar2);
                uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
                uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                uVar11 = FUN_00008c2e(uVar11,uVar2);
                uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
                uVar10 = FUN_00008bca(uVar11,uVar10);
                uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar11 = FUN_00008c2e(uVar11,uVar2);
                uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
                uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                      *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                uVar12 = FUN_00008c2e(uVar12,uVar2);
                uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
                uVar11 = FUN_00008bca(uVar12,uVar11);
                uVar10 = FUN_00008b1a(uVar11,uVar10);
                FUN_00009174(uVar9,local_54);
                if (!(bool)uVar15 || (bool)uVar13) {
                  local_48 = (int)(char)local_64;
                  local_60 = uVar10;
                  local_5c = uVar9;
                  local_54 = uVar9;
                }
              }
            }
          }
          if (local_48 == 4) {
            local_54 = DAT_0000fee0;
            for (local_64 = 0; local_64 < 4; local_64 = local_64 + 1 & 0xff) {
              if (uVar8 != local_64) {
                cVar14 = *(char *)(param_1 + local_64 * 0x84 + 0x1a);
                uVar15 = cVar14 != '\0';
                uVar13 = cVar14 == '\x01';
                if ((bool)uVar13) {
                  uVar9 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                       *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                  uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                  uVar9 = FUN_00008bca(uVar10,uVar9);
                  uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                  uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                  uVar10 = FUN_00008bca(uVar11,uVar10);
                  uVar9 = FUN_00008b1a(uVar10,uVar9);
                  uVar10 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                  uVar10 = FUN_00008c2e(uVar10,uVar2);
                  uVar10 = FUN_00008bc4(uVar10,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
                  uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14 + 4),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x74));
                  uVar11 = FUN_00008c2e(uVar11,uVar2);
                  uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x7c));
                  uVar10 = FUN_00008bca(uVar11,uVar10);
                  uVar11 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                  uVar11 = FUN_00008c2e(uVar11,uVar2);
                  uVar11 = FUN_00008bc4(uVar11,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
                  uVar12 = FUN_00008bbe(*(undefined4 *)(param_2 + local_34 * 0x14),
                                        *(undefined4 *)(param_1 + local_64 * 0x84 + 0x70));
                  uVar12 = FUN_00008c2e(uVar12,uVar2);
                  uVar12 = FUN_00008bc4(uVar12,*(undefined4 *)(param_1 + local_64 * 0x84 + 0x78));
                  uVar11 = FUN_00008bca(uVar12,uVar11);
                  uVar10 = FUN_00008b1a(uVar11,uVar10);
                  FUN_00009174(uVar9,local_54);
                  if (!(bool)uVar15 || (bool)uVar13) {
                    local_48 = (int)(char)local_64;
                    local_60 = uVar10;
                    local_5c = uVar9;
                    local_54 = uVar9;
                  }
                }
              }
            }
            if (local_48 != 4) {
              *(undefined4 *)(iVar3 + local_48 * 4) = local_5c;
              *(undefined4 *)(iVar4 + local_48 * 4) = local_60;
            }
          }
          else {
            *(undefined4 *)(iVar3 + local_48 * 4) = local_5c;
            *(undefined4 *)(iVar4 + local_48 * 4) = local_60;
          }
          *(int *)(param_2 + local_34 * 0x14 + 0x10) = local_48;
        }
        else {
          *(undefined4 *)(param_2 + local_38 * 0x14 + 0x10) = 0xffffffff;
        }
      }
    }
  }
  FUN_00010644();
  FUN_00010644();
  return;
}


/* ===== FUN_00010028 @ 00010028 ===== */

void FUN_00010028(void)

{
  *DAT_00010030 = 1;
  return;
}


/* ===== FUN_00010034 @ 00010034 ===== */

void FUN_00010034(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
                 uint param_6)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint *puVar12;
  int *piVar13;
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
  uint local_78;
  int local_74;
  uint local_6c;
  int local_68;
  uint local_64;
  
  uVar9 = DAT_000103c8;
  if (param_5 < 0x2711) {
    if (param_5 < 0xa3d) {
      uVar11 = 0x14;
    }
    else {
      uVar11 = 0x50;
    }
  }
  else {
    uVar11 = 0x9c4;
  }
  uVar3 = FUN_00008fd2(uVar11);
  uVar11 = DAT_000103cc;
  uVar4 = FUN_00008fe4(param_4 * 1000);
  FUN_00008c2e(uVar4,uVar9);
  FUN_000090b6();
  FUN_00012968();
  uVar4 = FUN_0000913c();
  uVar5 = FUN_00008fe4(param_5 * 1000);
  FUN_00008c2e(uVar5,uVar3);
  FUN_000090b6();
  FUN_00012968();
  uVar5 = FUN_0000913c();
  uVar6 = FUN_00008fe4(param_3 * 1000);
  uVar7 = FUN_00008bca(uVar5,uVar3);
  uVar8 = FUN_00008bca(uVar4,uVar9);
  uVar7 = FUN_00008b1a(uVar8,uVar7);
  uVar6 = FUN_00008b1a(uVar7,uVar6);
  uVar11 = FUN_000105bc(uVar6,uVar11);
  uVar6 = FUN_00008fe4(param_3 * 1000);
  uVar11 = FUN_00008bbe(uVar6,uVar11);
  uVar9 = FUN_00008c2e(uVar11,uVar9);
  uVar18 = FUN_000090b6(uVar9);
  uVar19 = FUN_00009010(param_2);
  uVar20 = FUN_00008e10((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),DAT_000103d0,DAT_000103d4,
                        uVar19);
  uVar22 = (undefined4)uVar18;
  FUN_00008ef4((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar22,(int)((ulonglong)uVar18 >> 0x20),
               uVar19,uVar20);
  FUN_00012968();
  uVar11 = FUN_0000913c();
  uVar6 = FUN_00008bca(uVar11,uVar9);
  FUN_00008c2e(uVar6,uVar4);
  FUN_000090b6();
  FUN_00012968();
  uVar7 = FUN_0000913c();
  puVar1 = DAT_000103d8;
  *DAT_000103d8 = param_6 & 0xff;
  puVar1[1] = (param_6 << 0x10) >> 0x18;
  FUN_00008bca(param_1,DAT_000103dc);
  uVar18 = FUN_000090b6();
  uVar19 = FUN_00012968();
  uVar8 = FUN_00009084();
  uVar20 = FUN_00009010(uVar8);
  uVar21 = FUN_00008e04((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,DAT_000103e0,uVar20);
  uVar18 = FUN_00008e10((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),DAT_000103e4,DAT_000103e8,
                        uVar20,uVar21,uVar22,uVar6,uVar18,uVar19);
  FUN_00008ef4((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,DAT_000103ec);
  FUN_00012968();
  uVar10 = FUN_00009084();
  puVar1 = DAT_000103d8;
  DAT_000103d8[8] = uVar10 & 0xff;
  puVar12 = puVar1 + 9;
  *puVar12 = (uVar10 << 0x10) >> 0x18;
  uVar17 = (uint *)0xfffffffb < puVar12;
  puVar1[10] = (uVar10 << 9) >> 0x19;
  FUN_00009010(uVar8);
  uVar15 = 1;
  uVar18 = FUN_00010528();
  FUN_0000910c((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),DAT_000103e4,DAT_000103f4);
  for (iVar14 = 0; iVar14 < 3; iVar14 = iVar14 + 1) {
    bVar16 = false;
    local_68 = 1;
    if (iVar14 == 0) {
      bVar16 = true;
      unaff_r4 = 0;
      FUN_00008bbe(uVar9,0x3f800000);
      local_64 = FUN_0000905c();
      local_6c = FUN_0000905c(uVar11);
      local_78 = (uint)((bool)uVar17 && !(bool)uVar15);
      local_74 = 0;
    }
    else if (iVar14 == 1) {
      bVar16 = param_4 != 0;
      if (bVar16) {
        unaff_r4 = unaff_r4 + 1 & 0xff;
        FUN_00008bbe(uVar4,0x3f800000);
        local_64 = FUN_0000905c();
        local_6c = FUN_0000905c(uVar7);
        local_78 = 0;
        local_74 = 1;
      }
    }
    else if ((iVar14 == 2) && (bVar16 = param_5 != 0, bVar16)) {
      unaff_r4 = unaff_r4 + 1 & 0xff;
      FUN_00008bbe(uVar5,0x3f800000);
      local_64 = FUN_0000905c();
      local_6c = 0;
      local_78 = (uint)((bool)uVar17 && !(bool)uVar15);
      uVar6 = FUN_00008c2e(uVar3,DAT_000103f8);
      FUN_00008bbe(uVar6,0x3f800000);
      local_68 = FUN_0000905c();
      local_74 = 3;
    }
    iVar2 = DAT_000103fc;
    if (bVar16) {
      *(uint *)(DAT_000103fc + unaff_r4 * 0x14 + 0x840) = local_64 & 0xff;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x844) = (local_64 << 0x10) >> 0x18;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x848) =
           (uint)(local_68 << 0x1c) >> 0x18 | local_74 << 2 | local_78 << 1 |
           (local_64 << 0xf) >> 0x1f;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x84c) =
           (uint)(local_68 << 0x18) >> 0x1c | (local_6c & 0xf) << 4;
      *(uint *)(iVar2 + unaff_r4 * 0x14 + 0x850) = (local_6c << 0x14) >> 0x18;
    }
  }
  DAT_000103d8[2] = unaff_r4;
  if (param_6 == 0) {
    FUN_00010404(0);
  }
  else {
    FUN_00010404(1);
  }
  uVar10 = DAT_000103d8[2];
  *DAT_00010400 = 1;
  piVar13 = DAT_00010400 + 1;
  *piVar13 = 1 << (uVar10 + 1 & 0xff);
  DAT_00010400[-5] = (int)piVar13 >> 0xe | (uVar10 + 1) * 2;
  return;
}


/* ===== FUN_00010404 @ 00010404 ===== */

void FUN_00010404(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_00010470;
  if (param_1 == 1) {
    *DAT_00010470 = *DAT_00010470 & 0xffffff7c;
    *DAT_00010470 = *puVar1 | param_2 << 1 | 0xc0U;
    DAT_00010470[7] = DAT_00010470[7] | 0x80;
  }
  else {
    *DAT_00010470 = *DAT_00010470 & 0xffffff7c;
    *DAT_00010470 = *puVar1 | (param_2 << 1 | 0x80U) + 1 | 0x40;
    DAT_00010470[7] = DAT_00010470[7] & 0xffffff7f;
  }
  return;
}


/* ===== FUN_00010474 @ 00010474 ===== */

void FUN_00010474(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = FUN_00010a00();
  if (iVar2 == 1) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 2;
  }
  uVar4 = *DAT_000104f8;
  if ((uVar4 & 2) != 0) {
    FUN_000110c0(0,0,0,0,0,0,0,1,1);
    DAT_000104f8[1] = 2;
  }
  puVar1 = DAT_000104fc;
  if ((uVar4 & 4) != 0) {
    *DAT_000104fc = *DAT_000104fc + 1;
    if (*puVar1 < uVar3) {
      FUN_000110c0(1,1,1,1,0,0x96,0,1,1);
    }
    else {
      *DAT_000104fc = 0;
    }
    DAT_000104f8[1] = 4;
  }
  return;
}


/* ===== FUN_00010500 @ 00010500 ===== */

void FUN_00010500(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00010524;
  *(uint *)(DAT_00010524 + 0x204) = *DAT_00010520 & 0xfffffff3;
  *(uint *)(iVar1 + 0x204) = *(uint *)(iVar1 + 0x204) | param_1 << 2;
  return;
}


/* ===== FUN_00010528 @ 00010528 ===== */

undefined4 FUN_00010528(int param_1,uint param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (((-1 < (int)(0x7ff00000 - ((uint)(param_1 != 0) | param_2 & 0x7fffffff))) &&
      (-1 < (int)(0x7ff00000 - ((uint)(param_3 != 0) | param_4 & 0x7fffffff)))) &&
     ((DAT_000105b8 == param_2 * 2 && param_1 == 0 || ((param_4 & 0x7fffffff) == 0 && param_3 == 0))
     )) {
    FUN_0000b40c(1);
    uVar1 = FUN_00008ef4(0,0,0,0);
    return uVar1;
  }
  uVar3 = FUN_0000948c(param_1,param_2);
  uVar2 = (uint)((ulonglong)uVar3 >> 0x20);
  uVar1 = (undefined4)uVar3;
  if (((~(uVar2 >> 0x14) & 0x7ff) != 0) && ((int)param_2 >> 0x1f != (int)uVar2 >> 0x1f)) {
    uVar1 = FUN_00008e0a(param_3,uVar2 & 0x80000000 | param_4 & 0x7fffffff,uVar1,uVar2);
  }
  return uVar1;
}


/* ===== FUN_000105bc @ 000105bc ===== */

void FUN_000105bc(uint param_1,uint param_2)

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
      FUN_0000b40c(1);
      FUN_00008c2e(0);
      return;
    }
  }
  uVar1 = FUN_000092f6(param_1);
  if ((~(uVar1 >> 0x17) & 0xff) == 0) {
    return;
  }
  if ((int)param_1 >> 0x1f == (int)uVar1 >> 0x1f) {
    return;
  }
  FUN_00008bc4(uVar1 & 0x80000000 | param_2 & 0x7fffffff,uVar1);
  return;
}


/* ===== FUN_00010644 @ 00010644 ===== */

void FUN_00010644(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    piVar2 = (int *)(param_1 - 4);
    piVar1 = *DAT_00010690;
    piVar4 = (int *)0x0;
    while ((piVar3 = piVar1, piVar3 != (int *)0x0 && (piVar3 <= piVar2))) {
      piVar4 = piVar3;
      piVar1 = (int *)piVar3[1];
    }
    if (piVar4 == (int *)0x0) {
      *DAT_00010690 = piVar2;
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


/* ===== FUN_00010694 @ 00010694 ===== */

void FUN_00010694(undefined4 param_1)

{
  FUN_00008ab6(param_1,DAT_000106a4,0x44);
  return;
}


/* ===== FUN_000106a8 @ 000106a8 ===== */

undefined4 FUN_000106a8(void)

{
  return *DAT_000106b0;
}


/* ===== FUN_000106b4 @ 000106b4 ===== */

undefined4 FUN_000106b4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00010a44();
  if ((iVar1 == 0) || (iVar1 = FUN_000106f0(), iVar1 == 0)) {
    *DAT_000106e4 = 0;
  }
  if (*DAT_000106e4 < 0x3c) {
    uVar2 = 5;
    *DAT_000106e4 = *DAT_000106e4 + 1;
  }
  else {
    uVar2 = 8;
  }
  return uVar2;
}


/* ===== FUN_000106e8 @ 000106e8 ===== */

undefined4 FUN_000106e8(void)

{
  return DAT_000106ec;
}


/* ===== FUN_000106f0 @ 000106f0 ===== */

undefined FUN_000106f0(void)

{
  return *DAT_000106f8;
}


/* ===== FUN_000106fc @ 000106fc ===== */

int FUN_000106fc(uint param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  
  uVar10 = param_1;
  iVar1 = FUN_00008afe(1,0xc,param_3,param_4,param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    for (uVar6 = 0; (int)uVar6 < param_3; uVar6 = (uint)(short)((short)uVar6 + 1)) {
      cVar7 = param_1 <= uVar6;
      if (uVar6 != param_1) {
        uVar8 = FUN_000090b6(param_4);
        uVar2 = FUN_00008bbe(*(undefined4 *)(param_2 + param_1 * 0x14 + 8),
                             *(undefined4 *)(param_2 + uVar6 * 0x14 + 8));
        uVar9 = FUN_000090b6();
        uVar4 = (uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff;
        FUN_0000910c((int)uVar9,uVar4,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar10,uVar2,
                     (int)uVar9,uVar4);
        if (cVar7 != '\0') {
          uVar8 = FUN_000090b6(param_5);
          uVar2 = FUN_00008bbe(*(undefined4 *)(param_2 + param_1 * 0x14 + 0xc),
                               *(undefined4 *)(param_2 + uVar6 * 0x14 + 0xc));
          uVar9 = FUN_000090b6();
          uVar4 = (uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff;
          FUN_0000910c((int)uVar9,uVar4,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar10,uVar2,
                       (int)uVar9,uVar4);
          if (cVar7 != '\0') {
            uVar8 = FUN_000090b6(param_6);
            uVar2 = FUN_00008bbe(*(undefined4 *)(param_2 + param_1 * 0x14 + 0x10),
                                 *(undefined4 *)(param_2 + uVar6 * 0x14 + 0x10));
            uVar9 = FUN_000090b6();
            FUN_0000910c((int)uVar9,(uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,(int)uVar8,
                         (int)((ulonglong)uVar8 >> 0x20),uVar10,uVar2);
            if (cVar7 != '\0') {
              uVar8 = FUN_000090b6(param_7);
              uVar4 = *(uint *)(param_2 + param_1 * 0x14 + 4);
              uVar5 = *(uint *)(param_2 + uVar6 * 0x14 + 4);
              cVar7 = uVar5 <= uVar4;
              uVar9 = FUN_00008fee(uVar4 - uVar5);
              uVar4 = (uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff;
              FUN_0000910c((int)uVar9,uVar4,(int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar10,uVar2,
                           (int)uVar9,uVar4);
              if ((cVar7 != '\0') && (iVar3 = FUN_0000ca40(uVar6 & 0xffff,iVar1), iVar3 == -3)) {
                FUN_0000d508(iVar1);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return iVar1;
}


/* ===== FUN_00010838 @ 00010838 ===== */

undefined4 FUN_00010838(void)

{
  return *DAT_00010840;
}


/* ===== FUN_00010844 @ 00010844 ===== */

undefined FUN_00010844(void)

{
  return *DAT_0001084c;
}


/* ===== FUN_00010850 @ 00010850 ===== */

undefined4 FUN_00010850(void)

{
  return *DAT_00010858;
}


/* ===== FUN_0001085c @ 0001085c ===== */

void FUN_0001085c(uint param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  for (; (int)param_1 < param_2; param_1 = param_1 + 1 & 0xffff) {
    iVar2 = *(int *)(param_3 + param_1 * 0x14);
    if (-1 < iVar2) {
      uVar1 = FUN_00008b1a(*(undefined4 *)(param_5 + iVar2 * 0x14),
                           *(undefined4 *)(param_3 + param_1 * 0x14 + 8));
      *(undefined4 *)(param_5 + iVar2 * 0x14) = uVar1;
      uVar1 = FUN_00008b1a(*(undefined4 *)(param_5 + iVar2 * 0x14 + 4),
                           *(undefined4 *)(param_3 + param_1 * 0x14 + 0xc));
      *(undefined4 *)(param_5 + iVar2 * 0x14 + 4) = uVar1;
      uVar1 = FUN_00008b1a(*(undefined4 *)(param_5 + iVar2 * 0x14 + 8),
                           *(undefined4 *)(param_3 + param_1 * 0x14 + 0x10));
      *(undefined4 *)(param_5 + iVar2 * 0x14 + 8) = uVar1;
      uVar1 = FUN_00008fd2(*(undefined4 *)(param_3 + param_1 * 0x14 + 4));
      uVar1 = FUN_00008b1a(uVar1,*(undefined4 *)(param_5 + iVar2 * 0x14 + 0xc));
      *(undefined4 *)(param_5 + iVar2 * 0x14 + 0xc) = uVar1;
      *(int *)(param_5 + iVar2 * 0x14 + 0x10) = *(int *)(param_5 + iVar2 * 0x14 + 0x10) + 1;
    }
  }
  for (uVar3 = 0; (int)uVar3 < param_4; uVar3 = uVar3 + 1 & 0xffff) {
    uVar1 = FUN_00008fd2(*(undefined4 *)(param_5 + uVar3 * 0x14 + 0x10));
    uVar1 = FUN_00008c2e(*(undefined4 *)(param_5 + uVar3 * 0x14),uVar1);
    *(undefined4 *)(param_5 + uVar3 * 0x14) = uVar1;
    uVar1 = FUN_00008fd2(*(undefined4 *)(param_5 + uVar3 * 0x14 + 0x10));
    uVar1 = FUN_00008c2e(*(undefined4 *)(param_5 + uVar3 * 0x14 + 4),uVar1);
    *(undefined4 *)(param_5 + uVar3 * 0x14 + 4) = uVar1;
    uVar1 = FUN_00008fd2(*(undefined4 *)(param_5 + uVar3 * 0x14 + 0x10));
    uVar1 = FUN_00008c2e(*(undefined4 *)(param_5 + uVar3 * 0x14 + 8),uVar1);
    *(undefined4 *)(param_5 + uVar3 * 0x14 + 8) = uVar1;
    uVar1 = FUN_00008fd2(*(undefined4 *)(param_5 + uVar3 * 0x14 + 0x10));
    uVar1 = FUN_00008c2e(*(undefined4 *)(param_5 + uVar3 * 0x14 + 0xc),uVar1);
    *(undefined4 *)(param_5 + uVar3 * 0x14 + 0xc) = uVar1;
    *(undefined4 *)(param_5 + uVar3 * 0x14 + 0x10) = 0xffffffff;
  }
  return;
}


/* ===== FUN_000109e8 @ 000109e8 ===== */

undefined4 FUN_000109e8(void)

{
  return DAT_000109ec;
}


/* ===== FUN_000109f0 @ 000109f0 ===== */

uint FUN_000109f0(void)

{
  return ((uint)*DAT_000109fc << 0x15) >> 0x1d;
}


/* ===== FUN_00010a00 @ 00010a00 ===== */

undefined FUN_00010a00(void)

{
  return *DAT_00010a08;
}


/* ===== FUN_00010a0c @ 00010a0c ===== */

undefined4 FUN_00010a0c(void)

{
  return *DAT_00010a14;
}


/* ===== FUN_00010a18 @ 00010a18 ===== */

undefined4 FUN_00010a18(void)

{
  return *DAT_00010a20;
}


/* ===== FUN_00010a24 @ 00010a24 ===== */

undefined4 FUN_00010a24(void)

{
  return DAT_00010a28;
}


/* ===== FUN_00010a2c @ 00010a2c ===== */

undefined4 FUN_00010a2c(void)

{
  return *DAT_00010a34;
}


/* ===== FUN_00010a38 @ 00010a38 ===== */

undefined FUN_00010a38(void)

{
  return *DAT_00010a40;
}


/* ===== FUN_00010a44 @ 00010a44 ===== */

int FUN_00010a44(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1 & 0xffff) {
    if ((*(char *)(DAT_00010a78 + uVar1 * 0x84 + 0x1a) == '\x02') &&
       (*(char *)(DAT_00010a78 + uVar1 * 0x84 + 0x80) == '\0')) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}


/* ===== FUN_00010a7c @ 00010a7c ===== */

undefined FUN_00010a7c(void)

{
  return *DAT_00010a84;
}


/* ===== FUN_00010a88 @ 00010a88 ===== */

void FUN_00010a88(void)

{
  return;
}


/* ===== FUN_00010a98 @ 00010a98 ===== */

int FUN_00010a98(void)

{
  int iVar1;
  char local_c;
  
  FUN_0000cd38(1);
  *(uint *)(DAT_00010b40 + 0x134) = *DAT_00010b3c & 0xfffffff0 | 2;
  *(uint *)(DAT_00010b44 + 0xc) = *(uint *)(DAT_00010b44 + 0xc) & 0xfff0ffff | 0x50000;
  iVar1 = DAT_00010b40;
  *(undefined4 *)(DAT_00010b40 + 0xd8) = DAT_00010b48;
  DAT_00010b3c[8] = *(uint *)(iVar1 + 0x154) | 8;
  FUN_0000d4bc(0x3c,0);
  FUN_0000d4bc(0x3c,0);
  FUN_0000d4bc(0x3c,0);
  iVar1 = DAT_00010b40;
  local_c = (char)*(undefined4 *)(DAT_00010b40 + 0xd4);
  *(undefined4 *)(DAT_00010b40 + 0xd8) = 0;
  DAT_00010b3c[8] = *(uint *)(iVar1 + 0x154) & 0xfffffff7;
  return (int)(char)(local_c + -0x80);
}


/* ===== FUN_00010b4c @ 00010b4c ===== */

void FUN_00010b4c(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0000cd38(1,param_2,param_3,0);
  *(uint *)(DAT_00010b90 + 0x134) = *DAT_00010b8c & 0xfffffff0 | 2;
  *(uint *)(DAT_00010b94 + 0xc) = *(uint *)(DAT_00010b94 + 0xc) & 0xfff0ffff | 0x50000;
  DAT_00010b8c[-0x17] = 1 << (param_1 + 7U & 0xff) | 1;
  return;
}


/* ===== FUN_00010b98 @ 00010b98 ===== */

void FUN_00010b98(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(undefined4 *)(DAT_00010be0 + param_1 * 4 + 0x30) = 0;
  }
  else if (param_2 == 1) {
    *(undefined4 *)(DAT_00010be0 + param_1 * 4 + 0x30) = 0x30;
  }
  else if (param_2 == 2) {
    *(undefined4 *)(DAT_00010be0 + param_1 * 4 + 0x30) = 0x10;
  }
  else if (param_2 == 3) {
    *(undefined4 *)(DAT_00010be0 + param_1 * 4 + 0x30) = 0x20;
  }
  return;
}


/* ===== FUN_00010bf0 @ 00010bf0 ===== */

void FUN_00010bf0(uint param_1,int param_2)

{
  if (param_2 == 1) {
    *(uint *)(DAT_00010c14 + 0x20) = *(uint *)(DAT_00010c14 + 0x20) | 1 << (param_1 & 0xff);
  }
  else {
    *(uint *)(DAT_00010c14 + 0x24) = *(uint *)(DAT_00010c14 + 0x24) | 1 << (param_1 & 0xff);
  }
  return;
}


/* ===== FUN_00010c18 @ 00010c18 ===== */

void FUN_00010c18(void)

{
  if (*DAT_00010c58 == '\x04') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,1);
  }
  else if (*DAT_00010c58 == '\x05') {
    FUN_00010b98(0x14,0);
    FUN_00010bf0(0x14,0);
  }
  FUN_0000c844();
  return;
}


/* ===== FUN_00010c5c @ 00010c5c ===== */

void FUN_00010c5c(int param_1,int param_2)

{
  *(uint *)(DAT_00010c70 + param_1 * 4 + 0x30) = 1 << (param_2 + 6U & 0xff) | 0x10;
  return;
}


/* ===== FUN_00010c78 @ 00010c78 ===== */

void FUN_00010c78(void)

{
  FUN_00012a44();
  FUN_00015184();
  return;
}


/* ===== FUN_00010c84 @ 00010c84 ===== */

void FUN_00010c84(void)

{
  undefined4 uVar1;
  undefined uStack_7;
  undefined uStack_6;
  undefined uStack_5;
  
  FUN_00010ce4(10);
  FUN_00014a1c();
  FUN_000130b8();
  FUN_000123f8();
  uVar1 = FUN_00010a88();
  uStack_5 = (undefined)((uint)uVar1 >> 0x18);
  uStack_6 = (undefined)((uint)uVar1 >> 0x10);
  uStack_7 = (undefined)((uint)uVar1 >> 8);
  FUN_00011fc0("Andar ADT6101P human detection 3d V%d.%d.%d \r\n",uStack_7,uStack_6,uStack_5);
  return;
}


/* ===== FUN_00010ce4 @ 00010ce4 ===== */

void FUN_00010ce4(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00015178(DAT_00010d04,param_2,param_3,param_1);
  FUN_00015164(param_1 * DAT_00010d08);
  FUN_00015178(0xffffffff);
  return;
}


/* ===== FUN_00010d0c @ 00010d0c ===== */

void FUN_00010d0c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (3 < uVar1) {
      return;
    }
    if ((*(char *)(param_1 + uVar1 * 0x84 + 0x1a) == '\0') &&
       (*(char *)(param_1 + uVar1 * 0x84 + 0x18) == '\0')) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  *(undefined *)(param_1 + uVar1 * 0x84 + 0x18) = 1;
  *(undefined *)(param_1 + uVar1 * 0x84 + 0x1a) = 1;
  *(undefined4 *)(param_1 + uVar1 * 0x84 + 0x20) = *param_2;
  *(undefined4 *)(param_1 + uVar1 * 0x84 + 0x24) = param_2[1];
  *(undefined4 *)(param_1 + uVar1 * 0x84 + 0x28) = 0;
  *(undefined4 *)(param_1 + uVar1 * 0x84 + 0x2c) = 0;
  *(undefined4 *)(param_1 + uVar1 * 0x84 + 8) = param_2[2];
  *(undefined2 *)(param_1 + uVar1 * 0x84 + 0x1c) = 1;
  *(undefined4 *)(param_1 + uVar1 * 0x84 + 0x14) = 0x32;
  FUN_0000a14c(param_1 + uVar1 * 0x84 + 0x20);
  return;
}


/* ===== FUN_00010db8 @ 00010db8 ===== */

void FUN_00010db8(int param_1,int param_2)

{
  *(uint *)(DAT_00010ddc + 0x114) =
       (*DAT_00010dd8 & 0xfffff0ff | param_1 << 8) & 0xffff0fff | param_2 << 0xc;
  return;
}


/* ===== FUN_00010de0 @ 00010de0 ===== */

void FUN_00010de0(void)

{
  return;
}


/* ===== FUN_00010de4 @ 00010de4 ===== */

void FUN_00010de4(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_2850;
  undefined4 uStack_284c;
  undefined4 local_2848;
  undefined auStack_2810 [10240];
  
  FUN_00008ab6(&local_2850,DAT_00010e58,0x18);
  iVar1 = FUN_0000dfa8(0,auStack_2810,*(undefined4 *)(DAT_00010e58 + -8),
                       *(undefined4 *)(DAT_00010e58 + -4));
  iVar2 = iVar1;
  if (4 < iVar1) {
    local_2850 = DAT_00010e5c;
    uStack_284c = 0x41800000;
    local_2848 = 5;
    iVar2 = FUN_0000d45c(auStack_2810,iVar1,DAT_00010e60);
    if (4 < iVar2) {
      iVar2 = 4;
    }
  }
  iVar2 = FUN_00010a0c(iVar2);
  if (iVar2 == 1) {
    FUN_00011e18(auStack_2810,iVar1,0);
  }
  FUN_00010e64(auStack_2810,iVar1);
  return;
}


/* ===== FUN_00010e64 @ 00010e64 ===== */

bool FUN_00010e64(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar2 = 0;
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    if (-1 < *(int *)(param_1 + uVar1 * 0x14)) {
      uVar2 = uVar2 + 1;
    }
  }
  if (uVar2 < 6) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    FUN_00014c10(0xa0a,&local_28,0x10);
    FUN_0000d4bc(200,0);
  }
  return uVar2 >= 6;
}


/* ===== FUN_00010ebc @ 00010ebc ===== */

int FUN_00010ebc(void)

{
  int iVar1;
  int iVar2;
  
  FUN_000132dc(DAT_00010f3c);
  FUN_0000e818(0x100,0x10,DAT_00010f40,DAT_00010f40,4,4);
  FUN_00008ae8(DAT_00010f44,0x4000);
  FUN_00013ed8(DAT_00010f40,0x100,0x6a,0x10,4);
  FUN_00015074(0x20,0x6a,DAT_00010f40,DAT_00010f48,0x400,4);
  FUN_0000bcb4(0x20,0x6a,DAT_00010f48,DAT_00010f4c);
  FUN_0000e5f8(0x20,0x6a,DAT_00010f50);
  iVar1 = FUN_00010de4(0);
  if (iVar1 == 1) {
    FUN_0000c858();
  }
  else if ((iVar1 == 0) && (iVar2 = FUN_0000c874(), iVar2 == 0)) {
    FUN_00013bcc();
  }
  return iVar1;
}


/* ===== FUN_00010f54 @ 00010f54 ===== */

void FUN_00010f54(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0000c380();
  FUN_0000c4d8(DAT_00010fac,0x11);
  FUN_0000c1ec(DAT_00010fac);
  FUN_0000c148(*DAT_00010fac,DAT_00010fac[1],1,0,0x11,param_3,param_4);
  FUN_00014c68(DAT_00010fac[4]);
  FUN_000111cc(1,0);
  FUN_00010fb0(0,0,0,0,*(undefined4 *)(DAT_00010fac + 0x24),*(undefined4 *)(DAT_00010fac + 0x28),
               *(undefined4 *)(DAT_00010fac + 0x2c));
  return;
}


/* ===== FUN_00010fb0 @ 00010fb0 ===== */

void FUN_00010fb0(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = param_1 << 3;
  iVar3 = param_2 << 3;
  uVar4 = param_1 | param_2 | param_3 | param_4;
  iVar1 = uVar4 * 0xf;
  FUN_0000d3fc(uVar4,uVar4 != 1);
  FUN_0000cd38(param_1 | param_2);
  FUN_000127ac(param_1,param_2);
  FUN_00012784(param_1 << 3,param_2 << 3);
  FUN_00012880(param_1,param_2);
  FUN_00012858(param_1 << 3,param_2 << 3);
  FUN_000116ac(param_1,param_2,param_7);
  FUN_0000bea4(param_1,param_2);
  FUN_0000be0c(iVar2,iVar2,iVar2,param_1 << 3,param_1 << 3,param_1 << 3,iVar3,iVar3,iVar3,
               param_2 << 3,param_2 << 3,param_2 << 3);
  FUN_0001301c(param_1,param_2);
  FUN_0001160c(param_1,param_2);
  FUN_0001291c(param_1 | param_2 | param_3 | param_4,param_1 | param_2 | param_3 | param_4);
  FUN_000125b8(uVar4,param_3,param_4,param_1,param_2);
  FUN_0000cdb4(iVar1,iVar1,iVar1,iVar1,iVar1,iVar1,iVar1,iVar1);
  FUN_00014cb4(param_3,param_4);
  return;
}


/* ===== FUN_000110c0 @ 000110c0 ===== */

void FUN_000110c0(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 << 3;
  iVar5 = param_1 << 3;
  iVar6 = param_2 << 3;
  iVar2 = param_2 << 3;
  uVar3 = param_1 | param_2 | param_3 | param_4;
  iVar1 = uVar3 * 0xf;
  FUN_0000d3fc(uVar3,uVar3 != 1);
  FUN_0000cd38(param_1 | param_2);
  FUN_000127ac(param_1,param_2);
  FUN_00012784(param_1 << 3,param_2 << 3);
  FUN_00012880(param_1,param_2);
  FUN_00012858(param_1 << 3,param_2 << 3);
  FUN_000116ac(param_1,param_2,param_7);
  FUN_0000bea4(param_8,param_9);
  FUN_0000be0c(iVar5,iVar5,iVar5,iVar4,iVar4,iVar4,iVar2,iVar2,iVar2,iVar6,iVar6,iVar6);
  FUN_0001301c(param_1,param_2);
  FUN_0001160c(param_1,param_2);
  FUN_0001291c(param_1 | param_2 | param_3 | param_4,param_1 | param_2 | param_3 | param_4);
  FUN_000125b8(uVar3,param_3,param_4,param_1,param_2);
  FUN_0000cdb4(iVar1,iVar1,iVar1,iVar1,iVar1,iVar1,iVar1,iVar1);
  FUN_00014cb4(param_3,param_4);
  return;
}


/* ===== FUN_000111cc @ 000111cc ===== */

void FUN_000111cc(int param_1,int param_2)

{
  FUN_00011d10(param_2);
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000d4bc(10,0);
  }
  FUN_000117ec(param_2);
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000d4bc(1,0);
  }
  FUN_00011c48(param_2);
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000d4bc(1,0);
  }
  if ((param_1 == 1) || (param_2 == 1)) {
    FUN_0000d4bc(0x32,0);
  }
  return;
}


/* ===== FUN_00011228 @ 00011228 ===== */

void FUN_00011228(uint param_1,uint param_2,uint param_3,uint param_4)

{
  param_4 = param_1 | param_2 | param_3 | param_4;
  if (param_4 == 0) {
    FUN_00010bf0(0x16,0);
    FUN_00010bf0(0x1d,0);
    FUN_00011cc8(0);
    FUN_00011c74(0,3);
    FUN_0000cd64(0,0,0);
    FUN_00011874(0);
    *DAT_00011358 = 0x888;
    *(undefined4 *)(DAT_0001135c + 0x158) = 0;
    *(uint *)(DAT_00011360 + 0x1c) = *(uint *)(DAT_00011360 + 0x1c) | 0x10;
    FUN_0000d4bc(100,0);
    *(uint *)(DAT_00011360 + 0x1c) = *(uint *)(DAT_00011360 + 0x1c) & 0xffffffef;
  }
  else {
    FUN_00010bf0(0x16,1);
    FUN_00010bf0(0x1d,1);
    FUN_0000d4bc(200,0);
    FUN_00011874(1);
    FUN_0000d4bc(100,0);
    FUN_00011cc8(1,0);
    FUN_0000d4bc(100,0);
    FUN_00011c74(1,3,param_4);
    FUN_0000d4bc(100,0);
    FUN_0000cd64(param_1,0,0);
    FUN_0000d4bc(100,0);
    FUN_0000cd64(param_1,0,param_2);
    FUN_0000d4bc(100,0);
    *DAT_00011358 = 0x8f8;
    *(undefined4 *)(DAT_0001135c + 0x158) = DAT_00011364;
    *(uint *)(DAT_00011360 + 0x1c) = *(uint *)(DAT_00011360 + 0x1c) | 0x10;
    FUN_0000d4bc(100,0);
    *(uint *)(DAT_00011360 + 0x1c) = *(uint *)(DAT_00011360 + 0x1c) & 0xffffffef;
  }
  return;
}


/* ===== FUN_00011368 @ 00011368 ===== */

void FUN_00011368(void)

{
  FUN_0000a350(0,0x8000);
  FUN_00013b54(3,0x12,0);
  FUN_00010c84();
  while (4 < *DAT_000113f0) {
    FUN_0000e7d8(10);
  }
                    /* WARNING: Could not recover jumptable at 0x0001138a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_0001138a::switchdataD_0001138e +
            (uint)(&switchD_0001138a::switchdataD_0001138e)[*DAT_000113f0] * 2))();
  return;
}


/* ===== FUN_000113f8 @ 000113f8 ===== */

uint * FUN_000113f8(int param_1)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint **ppuVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  
  piVar1 = DAT_00011454;
  uVar3 = param_1 + 0xbU & 0xfffffff8;
  ppuVar4 = DAT_00011458;
  do {
    while (puVar2 = *ppuVar4, puVar2 == (uint *)0x0) {
      puVar2 = (uint *)0x0;
LAB_00011430:
      puVar6 = DAT_0001145c;
      if (puVar2 != (uint *)0x0) {
        return puVar2;
      }
      if (*piVar1 != 0) {
        return (uint *)0x0;
      }
      *DAT_00011458 = DAT_0001145c;
      *puVar6 = DAT_00011460 - (int)puVar6 & 0xfffffff8;
      puVar6[1] = 0;
      *piVar1 = 1;
      ppuVar4 = DAT_00011458;
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
      goto LAB_00011430;
    }
    ppuVar4 = (uint **)(puVar2 + 1);
  } while( true );
}


/* ===== FUN_00011464 @ 00011464 ===== */

void FUN_00011464(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_28 [8];
  undefined auStack_20 [8];
  undefined auStack_18 [8];
  
  FUN_00008258(auStack_18,4,4,param_1);
  FUN_00008258(auStack_20,4,4,param_2);
  FUN_00008258(auStack_28,4,4,param_3);
  FUN_0000816c(auStack_18,auStack_20,auStack_28);
  return;
}


/* ===== FUN_000114a0 @ 000114a0 ===== */

void FUN_000114a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0x40004;
  local_20 = 0x40004;
  local_1c = param_2;
  local_14 = param_1;
  FUN_000084dc(&local_18,&local_20);
  return;
}


/* ===== FUN_000114c8 @ 000114c8 ===== */

void FUN_000114c8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack_28 [8];
  undefined auStack_20 [8];
  undefined auStack_18 [8];
  
  FUN_00008258(auStack_18,4,4,param_1);
  FUN_00008258(auStack_20,4,4,param_2);
  FUN_00008258(auStack_28,4,4,param_3);
  FUN_00008260(auStack_18,auStack_20,auStack_28);
  return;
}


/* ===== FUN_00011504 @ 00011504 ===== */

undefined8 FUN_00011504(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = param_1;
  uStack_1c = param_2;
  uStack_18 = param_3;
  uStack_14 = param_4;
  FUN_00008258(&uStack_18,4,4,param_1);
  FUN_00008258(&uStack_20,4,4,param_2);
  FUN_000083de(&uStack_18,&uStack_20);
  return CONCAT44(uStack_1c,uStack_20);
}


/* ===== FUN_0001152c @ 0001152c ===== */

void FUN_0001152c(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_00011550 + 0x20);
  while ((uVar1 & 0x70000) != 0) {
    uVar1 = *(uint *)(DAT_00011550 + 0x20);
  }
  *DAT_00011554 = 4;
  WaitForInterrupt();
  return;
}


/* ===== FUN_00011558 @ 00011558 ===== */

void FUN_00011558(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(DAT_000115ac + 0x28) = 0;
  *(uint *)(DAT_000115b4 + 0x108) = *DAT_000115b0 | 0x800;
  *(undefined4 *)(DAT_000115ac + 4) = 3;
  FUN_00010bf0(0x16,1);
  FUN_00010b98(0x16,0);
  iVar1 = DAT_000115ac;
  *(undefined4 *)(DAT_000115ac + 0x24) = DAT_000115b8;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x50) = 0xc00;
  if (param_1 == 0) {
    *(undefined4 *)(DAT_000115ac + 0x4c) = 7;
  }
  else {
    *(undefined4 *)(iVar1 + 0x4c) = 0x1f;
  }
  return;
}


/* ===== FUN_000115bc @ 000115bc ===== */

void FUN_000115bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5)

{
  FUN_0000e43c(4,param_1,param_2,param_3,param_4,param_5,0,1);
  do {
  } while (*(uint *)(DAT_00011608 + 0x58) < param_5);
  FUN_0000e598(4);
  return;
}


/* ===== FUN_0001160c @ 0001160c ===== */

void FUN_0001160c(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_00011638 | 0x10;
  }
  else {
    uVar1 = *DAT_00011638 & 0xffffffef;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 0x20;
  }
  else {
    uVar1 = uVar1 & 0xffffffdf;
  }
  *DAT_00011638 = uVar1;
  return;
}


/* ===== FUN_0001163c @ 0001163c ===== */

void FUN_0001163c(void)

{
  *DAT_00011644 = 1;
  return;
}


/* ===== FUN_00011648 @ 00011648 ===== */

void FUN_00011648(void)

{
  *DAT_00011650 = 1;
  return;
}


/* ===== FUN_00011654 @ 00011654 ===== */

bool FUN_00011654(void)

{
  return *DAT_00011670 == *DAT_00011674 * (*DAT_00011670 / *DAT_00011674);
}


/* ===== FUN_00011678 @ 00011678 ===== */

void FUN_00011678(int param_1)

{
  undefined uVar1;
  
  uVar1 = FUN_0000aea4();
  *(undefined *)(param_1 + 0x96) = uVar1;
  uVar1 = FUN_0000ae94(*(undefined *)(param_1 + 0x96),1);
  *(undefined *)(param_1 + 0x96) = uVar1;
  *(undefined *)(param_1 + 0x9a) = 0;
  *(undefined *)(param_1 + 0xc) = 3;
  *(undefined2 *)(param_1 + 0x94) = 0;
  return;
}


/* ===== FUN_000116ac @ 000116ac ===== */

void FUN_000116ac(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = DAT_00011724;
  *(uint *)(DAT_00011724 + 0x220) = *DAT_00011720 & 0xffffff7f;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) | param_1 << 7;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) & 0xffffff7f;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) | param_2 << 7;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) & 0xffffff9f;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) | param_3 << 5;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) & 0xffffff9f;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) | param_4 << 5;
  return;
}


/* ===== FUN_00011728 @ 00011728 ===== */

void FUN_00011728(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_00011768;
  *(uint *)(DAT_00011768 + 0x220) = *DAT_00011764 & 0xffffffe7;
  *(uint *)(iVar1 + 0x220) = *(uint *)(iVar1 + 0x220) | param_1 << 3;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) & 0xffffffe7;
  *(uint *)(iVar1 + 0x224) = *(uint *)(iVar1 + 0x224) | param_2 << 3;
  return;
}


/* ===== FUN_0001176c @ 0001176c ===== */

undefined4
FUN_0001176c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined in_ZR;
  undefined in_CY;
  
  uVar1 = FUN_0000cadc(param_2,param_1,param_3,param_4,param_3,param_4);
  uVar2 = FUN_0000cadc(param_4,param_3);
  uVar1 = FUN_00008bbe(uVar1,uVar2);
  uVar1 = FUN_00008b1a(uVar1,param_5);
  while (FUN_00009188(uVar1,DAT_000117e4), !(bool)in_CY || (bool)in_ZR) {
    uVar1 = FUN_00008bbe(uVar1,DAT_000117e0);
  }
  while (FUN_00009174(uVar1,DAT_000117e8), !(bool)in_CY || (bool)in_ZR) {
    uVar1 = FUN_00008b1a(uVar1,DAT_000117e0);
  }
  uVar1 = FUN_00008c2e(uVar1,DAT_000117e4);
  return uVar1;
}


/* ===== FUN_000117ec @ 000117ec ===== */

void FUN_000117ec(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_00011814 + 0x184) = *DAT_00011810 | 0x18;
  }
  else {
    *(uint *)(DAT_00011814 + 0x184) = *DAT_00011810 & 0xffffffe7;
  }
  return;
}


/* ===== FUN_00011818 @ 00011818 ===== */

void FUN_00011818(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00011848;
  *DAT_00011848 = DAT_00011844;
  puVar1[1] = DAT_00011850 | *(uint *)(DAT_0001184c + 0x188) & 0xf00;
  puVar1[2] = 0x492;
  puVar1[3] = 7;
  return;
}


/* ===== FUN_00011854 @ 00011854 ===== */

void FUN_00011854(void)

{
  *DAT_0001186c = DAT_00011868;
  *(undefined4 *)(DAT_00011870 + 0x15c) = 0x44;
  return;
}


/* ===== FUN_00011874 @ 00011874 ===== */

void FUN_00011874(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  *DAT_000118d4 = 0x8f8;
  iVar1 = DAT_000118d8;
  *(undefined4 *)(DAT_000118d8 + 0x1b8) = 0x210;
  *(undefined4 *)(iVar1 + 0x154) = DAT_000118d4[1];
  uVar2 = 0xca0;
  if (param_1 == 1) {
    uVar2 = 0x1fa3;
  }
  DAT_000118d4[4] = uVar2;
  *(uint *)(DAT_000118dc + 0x1c) = *(uint *)(DAT_000118dc + 0x1c) | 0x10;
  FUN_0000d4bc(100,0);
  *(uint *)(DAT_000118dc + 0x1c) = *(uint *)(DAT_000118dc + 0x1c) & 0xffffffef;
  return;
}


/* ===== FUN_000118e0 @ 000118e0 ===== */

void FUN_000118e0(undefined4 param_1,uint param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  undefined uVar13;
  bool bVar14;
  undefined uVar15;
  char cVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  uint local_44;
  
  sVar11 = 0;
  sVar3 = 0;
  bVar1 = false;
  bVar4 = false;
  *(uint *)(DAT_00011c3c + 0x188) = *DAT_00011c38 & 0xfffff0ff;
  uVar9 = *DAT_00011c38;
  do {
    iVar12 = -1;
    local_44 = 0xffffffff;
    for (uVar10 = 0; iVar5 = DAT_00011c3c, uVar10 < 0x10; uVar10 = uVar10 + 1 & 0xff) {
      *(uint *)(DAT_00011c3c + 0x188) = *DAT_00011c38 & 0xfffff0ff;
      uVar9 = *DAT_00011c38;
      *(uint *)(iVar5 + 0x188) = uVar9 | uVar10 << 8;
      FUN_00010034(param_1,0,0x5c,0xc,0,param_3);
      FUN_00010404(0);
      FUN_0000d4bc(100,0);
      bVar14 = (DAT_00011c38[3] & 4) == 4;
      if ((param_2 == 0) || (!bVar14)) {
        bVar2 = true;
      }
      else {
        uVar6 = FUN_00008fe4();
        uVar6 = FUN_00008b1a(uVar6,param_1);
        FUN_00010034(uVar6,0,0x5c,0xc,0,param_3);
        FUN_00010404(0);
        FUN_0000d4bc(100,0);
        if ((DAT_00011c38[3] & 4) == 4) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      }
      if ((bVar14) && (bVar2)) {
        cVar16 = (char)uVar10;
        bVar1 = bVar2;
        if (iVar12 < 0) {
          iVar12 = (int)cVar16;
          local_44 = (uint)cVar16;
        }
        else {
          local_44 = (uint)cVar16;
          sVar11 = sVar11 + 1;
        }
      }
      if (((0 < sVar11) && (bVar1)) && (sVar3 == sVar11)) break;
      sVar3 = sVar11;
    }
    if (bVar1) {
      iVar5 = local_44 + iVar12 + 1;
      uVar10 = (uint)((iVar5 - (iVar5 >> 0x1f)) * 0x800000) >> 0x18;
      uVar6 = FUN_00010a98();
      *DAT_00011c40 = uVar6;
      *DAT_00011c38 = uVar9 | uVar10 << 8;
      cVar16 = (param_2 / 1000 & 1) != 0;
      uVar6 = FUN_00008fe4();
      uVar6 = FUN_00008b1a(uVar6,param_1);
      FUN_00010034(uVar6,0,0x5c,0xc,0,param_3);
      FUN_00010404(0);
      FUN_0000d4bc(100,0);
      uVar6 = FUN_000150bc();
      *(undefined4 *)(DAT_00011c3c + 0xd8) = 0;
      FUN_00009174(uVar6,DAT_00011c44);
      if (cVar16 == '\0') {
        uVar7 = uVar10 + 1;
        cVar16 = local_44 <= uVar7;
        if ((int)uVar7 <= (int)local_44) {
          *DAT_00011c38 = uVar9 | uVar7 * 0x100;
          uVar13 = (param_2 / 1000 & 1) != 0;
          uVar8 = FUN_00008fe4();
          uVar8 = FUN_00008b1a(uVar8,param_1);
          uVar19 = 0;
          FUN_00010034(uVar8,0,0x5c,0xc,0,param_3);
          FUN_00010404(0);
          FUN_0000d4bc(100,0);
          uVar8 = FUN_000150bc();
          uVar15 = 1;
          *(undefined4 *)(DAT_00011c3c + 0xd8) = 0;
          FUN_00008bbe(DAT_00011c44,uVar6);
          uVar17 = FUN_000090b6();
          uVar6 = FUN_00008bbe(DAT_00011c44,uVar8);
          uVar18 = FUN_000090b6();
          uVar7 = (uint)((ulonglong)uVar18 >> 0x20) & 0x7fffffff;
          FUN_0000910c((int)uVar18,uVar7,(int)uVar17,(uint)((ulonglong)uVar17 >> 0x20) & 0x7fffffff,
                       uVar19,uVar6,(int)uVar18,uVar7);
          if ((bool)uVar13 && !(bool)uVar15) {
            *DAT_00011c38 = uVar9 | (uVar10 + 1) * 0x100;
          }
          else {
            *DAT_00011c38 = uVar9 | uVar10 << 8;
          }
          goto LAB_00011c22;
        }
      }
      FUN_00009188(uVar6,DAT_00011c44);
      if ((cVar16 == '\0') && (iVar12 <= (int)(uVar10 - 1))) {
        *DAT_00011c38 = uVar9 | (uVar10 - 1) * 0x100;
        uVar13 = (param_2 / 1000 & 1) != 0;
        uVar8 = FUN_00008fe4();
        uVar8 = FUN_00008b1a(uVar8,param_1);
        uVar19 = 0;
        FUN_00010034(uVar8,0,0x5c,0xc,0,param_3);
        FUN_00010404(0);
        FUN_0000d4bc(100,0);
        uVar8 = FUN_000150bc();
        uVar15 = 1;
        *(undefined4 *)(DAT_00011c3c + 0xd8) = 0;
        FUN_00008bbe(DAT_00011c44,uVar6);
        uVar17 = FUN_000090b6();
        uVar6 = FUN_00008bbe(DAT_00011c44,uVar8);
        uVar18 = FUN_000090b6();
        uVar7 = (uint)((ulonglong)uVar18 >> 0x20) & 0x7fffffff;
        FUN_0000910c((int)uVar18,uVar7,(int)uVar17,(uint)((ulonglong)uVar17 >> 0x20) & 0x7fffffff,
                     uVar19,uVar6,(int)uVar18,uVar7);
        if ((bool)uVar13 && !(bool)uVar15) {
          *DAT_00011c38 = uVar9 | (uVar10 - 1) * 0x100;
        }
        else {
          *DAT_00011c38 = uVar9 | uVar10 << 8;
        }
      }
      else {
        *DAT_00011c38 = uVar9 | uVar10 << 8;
      }
    }
    else {
      bVar4 = true;
    }
LAB_00011c22:
    if ((bVar1) || (bVar4)) {
      return;
    }
  } while( true );
}


/* ===== FUN_00011c48 @ 00011c48 ===== */

void FUN_00011c48(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_00011c70 + 0x184) = *DAT_00011c6c | 4;
  }
  else {
    *(uint *)(DAT_00011c70 + 0x184) = *DAT_00011c6c & 0xfffffffb;
  }
  return;
}


/* ===== FUN_00011c74 @ 00011c74 ===== */

void FUN_00011c74(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 1) {
    uVar2 = *DAT_00011cc0 | 0x800;
  }
  else {
    uVar2 = *DAT_00011cc0 & 0xfffff7ff;
  }
  if (param_3 == 1) {
    uVar2 = uVar2 | 0x400;
  }
  else {
    uVar2 = uVar2 & 0xfffffbff;
  }
  *DAT_00011cc0 = uVar2;
  iVar1 = DAT_00011cc4;
  *(uint *)(DAT_00011cc4 + 0x198) = *(uint *)(DAT_00011cc4 + 0x198) & 0xffffffcf;
  DAT_00011cc0[0xe] = *(uint *)(iVar1 + 0x198) | param_2 << 4;
  return;
}


/* ===== FUN_00011cc8 @ 00011cc8 ===== */

void FUN_00011cc8(int param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 1) {
    *(uint *)(DAT_00011d0c + 0x160) = *DAT_00011d08 | 0x1000;
  }
  else {
    *(uint *)(DAT_00011d0c + 0x160) = *DAT_00011d08 & 0xffffefff;
  }
  iVar1 = DAT_00011d0c;
  *(uint *)(DAT_00011d0c + 0x198) = DAT_00011d08[0xe] & 0xfffffffc;
  *(uint *)(iVar1 + 0x198) = *(uint *)(iVar1 + 0x198) | param_2;
  return;
}


/* ===== FUN_00011d10 @ 00011d10 ===== */

void FUN_00011d10(int param_1)

{
  if (param_1 == 1) {
    *(uint *)(DAT_00011d38 + 0x184) = *DAT_00011d34 | 2;
  }
  else {
    *(uint *)(DAT_00011d38 + 0x184) = *DAT_00011d34 & 0xfffffffd;
  }
  return;
}


/* ===== FUN_00011d3c @ 00011d3c ===== */

void FUN_00011d3c(uint param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(DAT_00011d78 + param_1 * 4 + 0x30) = 0x30;
  iVar1 = DAT_00011d78;
  *(uint *)(DAT_00011d78 + 0x18) = *(uint *)(DAT_00011d78 + 0x18) | 1 << (param_1 & 0xff);
  if (param_2 == 0) {
    *(uint *)(DAT_00011d78 + 0x14) = *(uint *)(DAT_00011d78 + 0x14) & ~(1 << (param_1 & 0xff));
  }
  else {
    *(uint *)(DAT_00011d78 + 0x14) = *(uint *)(iVar1 + 0x14) | 1 << (param_1 & 0xff);
  }
  return;
}


/* ===== FUN_00011d7c @ 00011d7c ===== */

void FUN_00011d7c(void)

{
  if ((*DAT_00011d98 & 1) != 0) {
    FUN_0000c858();
  }
  DAT_00011d98[2] = 0x1f;
  return;
}


/* ===== FUN_00011d9c @ 00011d9c ===== */

void FUN_00011d9c(void)

{
  int iVar1;
  undefined auStack_48 [72];
  
  FUN_00010694(auStack_48);
  iVar1 = FUN_00010a38();
  if (iVar1 == 0) {
    FUN_00013fc4();
    FUN_00014d58(&DAT_40004000,0x1c200,1);
  }
  FUN_00011228(0,0,0,0,auStack_48);
  return;
}


/* ===== FUN_00011dd2 @ 00011dd2 ===== */

void FUN_00011dd2(void)

{
  undefined local_4c;
  undefined local_4b;
  undefined local_4a;
  undefined local_49;
  
  FUN_00010694(&local_4c);
  FUN_00014d58(&DAT_40004000,0x1c200,0);
  FUN_00011228(local_4c,local_4b,local_4a,local_49,&local_4c);
  FUN_00013fbc();
  FUN_00014d58(&DAT_40004000,0x1c200,0);
  return;
}


/* ===== FUN_00011e18 @ 00011e18 ===== */

void FUN_00011e18(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint local_1f64;
  uint local_1f60 [2000];
  
  local_1f64 = 0;
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xffff) {
    if (-1 < *(int *)(param_1 + uVar1 * 0x14)) {
      local_1f60[local_1f64 * 5] = *(uint *)(param_1 + uVar1 * 0x14 + 8);
      local_1f60[local_1f64 * 5 + 1] = *(uint *)(param_1 + uVar1 * 0x14 + 0xc);
      local_1f60[local_1f64 * 5 + 2] = *(uint *)(param_1 + uVar1 * 0x14 + 0x10);
      local_1f60[local_1f64 * 5 + 3] = *(int *)(param_1 + uVar1 * 0x14 + 4) - 0x10;
      local_1f60[local_1f64 * 5 + 4] = (uint)(param_3 != 0);
      local_1f64 = local_1f64 + 1;
      if (0x1fe < local_1f64) break;
    }
  }
  FUN_0000b258(0xa08,&local_1f64,local_1f64 * 0x14 + 4 & 0xffff);
  return;
}


/* ===== FUN_00011ede @ 00011ede ===== */

void FUN_00011ede(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_1f5c;
  int local_1f58 [2000];
  
  uVar3 = 0;
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1 & 0xffff) {
    if (((*(char *)(param_1 + uVar2 * 0x84 + 0x1a) == '\x02') &&
        (0x8b < *(int *)(param_1 + uVar2 * 0x84 + 0x14))) &&
       (*(char *)(param_1 + uVar2 * 0x84 + 0x80) == '\0')) {
      local_1f58[uVar3 * 5] = *(int *)(param_1 + uVar2 * 0x84 + 0x70);
      local_1f58[uVar3 * 5 + 1] = *(int *)(param_1 + uVar2 * 0x84 + 0x74);
      local_1f58[uVar3 * 5 + 2] = *(int *)(param_1 + uVar2 * 0x84 + 8);
      FUN_00008bbe(*(undefined4 *)(param_1 + uVar2 * 0x84 + 0xc),0x41800000);
      iVar1 = FUN_0000902a();
      local_1f58[uVar3 * 5 + 3] = iVar1;
      local_1f58[uVar3 * 5 + 4] = uVar2 + 1;
      uVar3 = uVar3 + 1 & 0xff;
    }
  }
  local_1f5c = uVar3;
  FUN_0000b258(0xa04,&local_1f5c,uVar3 * 0x14 + 4);
  return;
}


/* ===== FUN_00011fb8 @ 00011fb8 ===== */

undefined4 FUN_00011fb8(void)

{
  return 0;
}


/* ===== FUN_00011fc0 @ 00011fc0 ===== */

int FUN_00011fc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short sVar2;
  undefined auStack_118 [256];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  sVar2 = FUN_0000b380(auStack_118,param_1,&uStack_c);
  iVar1 = DAT_00012000;
  *(undefined **)(DAT_00012000 + 0x2ac) = &DAT_40004000;
  *(undefined4 *)(iVar1 + 0x2a8) = DAT_00012004;
  FUN_00014c10(0x100,auStack_118,sVar2);
  return (int)sVar2;
}


/* ===== FUN_00012008 @ 00012008 ===== */

undefined4 FUN_00012008(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint uStack_1c;
  
  iVar4 = 0;
  if (param_1 == 0) {
    FUN_000121ac(0);
    uStack_1c = (uint)*DAT_00012184;
    local_20 = 0;
    FUN_00008ab6(&local_38,DAT_00012188,0x18);
    iVar4 = FUN_0000dcf0(0,DAT_0001218c,*(undefined4 *)(DAT_00012188 + -8),
                         *(undefined4 *)(DAT_00012188 + -4));
  }
  if (param_1 == 1) {
    FUN_000121ac(1);
    uStack_1c = (uint)*DAT_00012184;
    local_20 = 1;
    FUN_00008ab6(&local_38,DAT_00012190,0x18);
    iVar4 = FUN_0000dcf0(iVar4,DAT_0001218c,*(undefined4 *)(DAT_00012190 + -8),
                         *(undefined4 *)(DAT_00012190 + -4));
  }
  if (4 < iVar4) {
    if (param_1 == 0) {
      local_30 = FUN_000106b4();
      local_34 = 0x41800000;
      local_38 = DAT_00012194;
      uVar1 = FUN_0000d45c(DAT_0001218c,iVar4,DAT_00012198);
      if (0 < (int)uVar1) {
        local_38 = DAT_0001218c;
        local_34 = 0;
        FUN_00013c98(DAT_0001219c,uVar1 & 0xff,0,iVar4);
      }
    }
    if (param_1 == 1) {
      local_38 = DAT_00012194;
      local_34 = 0x41800000;
      local_30 = 8;
      uVar1 = FUN_0000d45c(DAT_0001218c,iVar4,DAT_00012198);
      if (0 < (int)uVar1) {
        iVar2 = FUN_00010a44();
        if ((iVar2 == 0) || (iVar2 = FUN_000106a8(), iVar2 != 0)) {
          iVar2 = FUN_00010a44();
          if (((iVar2 == 0) && (iVar2 = FUN_000106f0(), iVar2 == 1)) ||
             (iVar2 = FUN_000106a8(), iVar2 != 0)) {
            local_38 = DAT_0001218c;
            local_34 = 1;
            FUN_00013c98(DAT_0001219c,uVar1 & 0xff,0,iVar4);
          }
        }
        else {
          local_38 = DAT_0001218c;
          FUN_00014394(DAT_0001219c,uVar1 & 0xff,0,iVar4);
        }
        if (199 < *DAT_000121a0) {
          local_38 = DAT_0001218c;
          FUN_00014040(DAT_0001219c,uVar1 & 0xff,0,iVar4);
        }
      }
    }
  }
  FUN_00014e26(DAT_0001219c,DAT_000121a0);
  FUN_0001480c(DAT_0001219c);
  uVar3 = FUN_0000e06c(DAT_0001218c,iVar4);
  FUN_0000d234();
  if ((*DAT_000121a4 == 1) && (iVar2 = FUN_00011654(), iVar2 == 1)) {
    FUN_00011e18(DAT_0001218c,iVar4,param_1);
  }
  if ((*DAT_000121a8 == 1) && (iVar4 = FUN_00011654(), iVar4 == 1)) {
    FUN_00011ede(DAT_0001219c);
  }
  return uVar3;
}


/* ===== FUN_000121ac @ 000121ac ===== */

void FUN_000121ac(int param_1)

{
  if (param_1 == 1) {
    FUN_00015074(0x20,0x6a,DAT_0001227c,DAT_00012278,0x1a8,4);
    FUN_00015074(0x20,0x6a,DAT_00012284,DAT_00012280,0x1a8,4);
    FUN_00015074(0x20,0x6a,DAT_0001228c,DAT_00012288,0x1a8,4);
    FUN_00015074(0x20,0x6a,DAT_00012294,DAT_00012290,0x1a8,4);
  }
  else if (param_1 == 0) {
    FUN_00015074(0x20,0x6a,DAT_00012298,DAT_00012278,0x1a8,4);
    FUN_00015074(0x20,0x6a,DAT_0001229c,DAT_00012280,0x1a8,4);
    FUN_00015074(0x20,0x6a,DAT_000122a0,DAT_00012288,0x1a8,4);
    FUN_00015074(0x20,0x6a,DAT_000122a4,DAT_00012290,0x1a8,4);
  }
  FUN_0000e6cc();
  FUN_0000e5f8(0x20,0x6a,DAT_000122a8);
  return;
}


/* ===== FUN_000122ac @ 000122ac ===== */

void FUN_000122ac(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  short *psVar2;
  
  for (iVar1 = 0; iVar1 < param_1; iVar1 = iVar1 + 1) {
    psVar2 = (short *)(param_2 + iVar1 * 4);
    *(int *)(param_3 + iVar1 * 4) = *(int *)(param_3 + iVar1 * 4) + (int)*psVar2;
    *(int *)(param_4 + iVar1 * 4) = *(int *)(param_4 + iVar1 * 4) + (int)psVar2[1];
  }
  return;
}


/* ===== FUN_000122e0 @ 000122e0 ===== */

void FUN_000122e0(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = 0; iVar1 < param_1; iVar1 = iVar1 + 1) {
    iVar2 = *(int *)(param_4 + iVar1 * 4);
    *(short *)(param_3 + iVar1 * 4) = (short)(*(int *)(param_3 + iVar1 * 4) >> (param_2 & 0xff));
    *(short *)(param_3 + iVar1 * 4 + 2) = (short)(iVar2 >> (param_2 & 0xff));
  }
  return;
}


/* ===== FUN_00012310 @ 00012310 ===== */

void FUN_00012310(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = DAT_00012390;
  *(uint *)(DAT_00012390 + 0x28) = *(uint *)(DAT_00012390 + 0x28) & 0xfffffdff;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x20;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0x20;
  *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 0x400;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  FUN_0000d4bc(100,0);
  uVar2 = 0;
  for (uVar3 = 5; -1 < (int)uVar3; uVar3 = uVar3 - 1) {
    uVar2 = uVar2 | 1 << (uVar3 & 0xff);
    if (uVar2 < 0x20) {
      uVar4 = ~uVar2 & 0xff;
    }
    else {
      uVar4 = uVar2 - 0x20;
    }
    *DAT_00012394 = uVar4;
    FUN_0000d4bc(100,0);
    if ((*(uint *)(DAT_00012390 + 0x20) & 0xffff) < 0x5f5e) {
      uVar2 = uVar2 & ~(1 << (uVar3 & 0xff));
    }
  }
  *(undefined4 *)(DAT_00012390 + 0x18) = 5;
  return;
}


/* ===== FUN_00012398 @ 00012398 ===== */

void FUN_00012398(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_000123f0 & 0xffffffef;
  }
  else {
    uVar1 = *DAT_000123f0 | 0x10;
  }
  uVar1 = uVar1 & 0xfffffff7;
  if (param_3 != 0x96) {
    uVar1 = uVar1 | 8;
  }
  *DAT_000123f0 = uVar1;
  if (param_2 == 1) {
    uVar1 = *(uint *)(DAT_000123f4 + 0x21c) & 0xffffffef;
  }
  else {
    uVar1 = *(uint *)(DAT_000123f4 + 0x21c) | 0x10;
  }
  uVar1 = uVar1 & 0xfffffff7;
  if (param_4 != 0x96) {
    uVar1 = uVar1 | 8;
  }
  DAT_000123f0[1] = uVar1;
  return;
}


/* ===== FUN_000123f8 @ 000123f8 ===== */

void FUN_000123f8(void)

{
  FUN_00013d84(DAT_0001258c,0);
  FUN_000098e4(DAT_00012590,0x14000,0x184);
  if (*DAT_00012590 + DAT_00012594 == 0) {
    if (DAT_00012590[1] + DAT_00012594 == 0) {
      FUN_000139b8();
    }
    if (DAT_00012590[0x1a] + DAT_00012594 == 0) {
      FUN_00013764();
    }
    if (DAT_00012590[0x44] + DAT_00012594 == 0) {
      FUN_00013ad4();
    }
    if (DAT_00012590[0x33] + DAT_00012594 == 0) {
      FUN_0000c69c(DAT_00012590[0x34]);
      FUN_0001377c();
    }
    if (DAT_00012590[0x5d] + DAT_00012594 == 0) {
      FUN_00013b18(DAT_00012590[0x5e]);
    }
    if (DAT_00012590[0x5f] + DAT_00012594 == 0) {
      FUN_00013a54(DAT_00012590[0x60]);
    }
    if (DAT_00012590[0x35] + DAT_00012594 == 0) {
      FUN_00013804(*(undefined *)(DAT_00012590 + 0x36));
    }
    if (DAT_00012590[0x37] + DAT_00012594 == 0) {
      FUN_00013890(*(undefined *)(DAT_00012590 + 0x38));
    }
    if (DAT_00012590[0x39] + DAT_00012594 == 0) {
      FUN_00013b8c(DAT_00012590[0x3a],DAT_00012590[0x3b]);
    }
    if (DAT_00012590[0x3c] + DAT_00012594 == 0) {
      FUN_00013984(*(undefined *)(DAT_00012590 + 0x3d));
    }
    if (DAT_00012590[0x3e] + DAT_00012594 == 0) {
      FUN_00013a24(*(undefined *)(DAT_00012590 + 0x3f));
    }
    if (DAT_00012590[0x40] + DAT_00012594 == 0) {
      FUN_00013ac8(DAT_00012590[0x41]);
    }
    if (DAT_00012590[0x42] + DAT_00012594 == 0) {
      FUN_00013930(*(undefined *)(DAT_00012590 + 0x43));
    }
  }
  return;
}


/* ===== FUN_00012598 @ 00012598 ===== */

void FUN_00012598(void)

{
  FUN_0000d52c();
  FUN_00013804(2);
  FUN_00013890(2);
  FUN_00008ae8(DAT_000125b4,0x60);
  return;
}


/* ===== FUN_000125b8 @ 000125b8 ===== */

void FUN_000125b8(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  
  if (param_5 == 1) {
    uVar1 = *DAT_00012664 | 1;
  }
  else {
    uVar1 = *DAT_00012664 & 0xfffffffe;
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
  *DAT_00012664 = uVar1;
  if (param_1 == 1) {
    uVar1 = *(uint *)(DAT_00012668 + 0x164) | 1;
  }
  else {
    uVar1 = *(uint *)(DAT_00012668 + 0x164) & 0xfffffffe;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 0xe;
  }
  else {
    uVar1 = uVar1 & 0xfffffff1;
  }
  if (param_3 == 1) {
    uVar1 = uVar1 | 0x70;
  }
  else {
    uVar1 = uVar1 & 0xffffff8f;
  }
  if (param_4 == 1) {
    uVar1 = uVar1 | 0x380;
  }
  else {
    uVar1 = uVar1 & 0xfffffc7f;
  }
  if (param_5 == 1) {
    uVar1 = uVar1 | 0x1c00;
  }
  else {
    uVar1 = uVar1 & 0xffffe3ff;
  }
  DAT_00012664[-0x29] = uVar1;
  return;
}


/* ===== FUN_0001266c @ 0001266c ===== */

void FUN_0001266c(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_000126b4 | 0x10;
  }
  else {
    uVar1 = *DAT_000126b4 & 0xffffffef;
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
  *DAT_000126b4 = uVar1;
  return;
}


/* ===== FUN_000126b8 @ 000126b8 ===== */

void FUN_000126b8(int param_1,uint param_2,int param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = DAT_00012744;
  *(uint *)(DAT_00012744 + 0x218) =
       *DAT_00012740 & 0xfffffff8 | param_1 << 1 | (param_2 << 0x1e) >> 0x1f;
  *(uint *)(DAT_00012744 + 0x220) = *(uint *)(iVar2 + 0x220) & 0xfffffeff;
  puVar1 = DAT_00012740;
  DAT_00012740[2] = DAT_00012740[2] | (param_2 & 1) << 8;
  iVar2 = DAT_00012744;
  *(uint *)(DAT_00012744 + 0x21c) =
       puVar1[1] & 0xfffffff8 | param_3 << 1 | (param_4 << 0x1e) >> 0x1f;
  *(uint *)(DAT_00012744 + 0x224) = *(uint *)(iVar2 + 0x224) & 0xfffffeff;
  *(uint *)(DAT_00012744 + 0x224) = DAT_00012740[3] | (param_4 & 1) << 8;
  return;
}


/* ===== FUN_00012748 @ 00012748 ===== */

void FUN_00012748(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  *(uint *)(DAT_00012780 + 0x210) = *DAT_0001277c | 0x100000;
  FUN_0000d4bc(1,0);
  iVar1 = DAT_00012780;
  *(undefined4 *)(DAT_00012780 + 4) = param_1;
  *(undefined4 *)(iVar1 + 0xc) = param_2;
  FUN_0000d4bc(1,0);
  *(undefined4 *)(DAT_00012780 + 0x80) = 1;
  return;
}


/* ===== FUN_00012784 @ 00012784 ===== */

void FUN_00012784(uint param_1,int param_2)

{
  *(uint *)(DAT_000127a8 + 300) = *DAT_000127a4 & 0xfffff0f0 | param_2 << 8 | param_1;
  return;
}


/* ===== FUN_000127ac @ 000127ac ===== */

void FUN_000127ac(int param_1,int param_2)

{
  if (param_1 == 1) {
    *(uint *)(DAT_000127fc + 0x218) = *DAT_000127f8 | 0x1000;
  }
  else {
    *(uint *)(DAT_000127fc + 0x218) = *DAT_000127f8 & 0xffffefff;
  }
  if (param_2 == 1) {
    *(uint *)(DAT_000127fc + 0x21c) = DAT_000127f8[1] | 0x1000;
  }
  else {
    *(uint *)(DAT_000127fc + 0x21c) = DAT_000127f8[1] & 0xffffefff;
  }
  return;
}


/* ===== FUN_00012800 @ 00012800 ===== */

void FUN_00012800(int param_1,int param_2,int param_3,int param_4)

{
  *(uint *)(DAT_00012854 + 0x218) =
       (*DAT_00012850 & 0xfffffcff | param_1 << 8) & 0xfffff39f | param_2 << 10 | param_1 << 5;
  *(uint *)(DAT_00012854 + 0x21c) =
       (DAT_00012850[1] & 0xfffffcff | param_3 << 8) & 0xfffff39f | param_4 << 10 | param_4 << 5;
  return;
}


/* ===== FUN_00012858 @ 00012858 ===== */

void FUN_00012858(int param_1,int param_2)

{
  *(uint *)(DAT_0001287c + 300) =
       (*DAT_00012878 & 0xffffff0f | param_1 << 4) & 0xffff0fff | param_2 << 0xc;
  return;
}


/* ===== FUN_00012880 @ 00012880 ===== */

void FUN_00012880(int param_1,int param_2)

{
  if (param_1 == 1) {
    *(uint *)(DAT_000128d0 + 0x220) = *DAT_000128cc | 0x4000000;
  }
  else {
    *(uint *)(DAT_000128d0 + 0x220) = *DAT_000128cc & 0xfbffffff;
  }
  if (param_2 == 1) {
    *(uint *)(DAT_000128d0 + 0x224) = DAT_000128cc[1] | 0x4000000;
  }
  else {
    *(uint *)(DAT_000128d0 + 0x224) = DAT_000128cc[1] & 0xfbffffff;
  }
  return;
}


/* ===== FUN_000128d4 @ 000128d4 ===== */

void FUN_000128d4(int param_1,int param_2,int param_3,int param_4)

{
  *(uint *)(DAT_00012918 + 0x220) =
       (*DAT_00012914 & 0xffe0ffff | param_1 << 0x10) & 0xfc1fffff | param_2 << 0x15;
  *(uint *)(DAT_00012918 + 0x224) =
       (DAT_00012914[1] & 0xffe0ffff | param_3 << 0x10) & 0xfc1fffff | param_4 << 0x15;
  return;
}


/* ===== FUN_0001291c @ 0001291c ===== */

void FUN_0001291c(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 1) {
    uVar1 = *DAT_00012960 | 1;
  }
  else {
    uVar1 = *DAT_00012960 & 0xfffffffe;
  }
  if (param_1 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  *DAT_00012960 = uVar1;
  if (param_2 == 1) {
    uVar1 = *(uint *)(DAT_00012964 + 0x214) | 4;
  }
  else {
    uVar1 = *(uint *)(DAT_00012964 + 0x214) & 0xfffffffb;
  }
  DAT_00012960[4] = uVar1;
  return;
}


/* ===== FUN_00012968 @ 00012968 ===== */

undefined8 FUN_00012968(undefined4 param_1,uint param_2)

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
  
  uVar9 = FUN_00009404();
  uVar5 = (undefined4)((ulonglong)uVar9 >> 0x20);
  uVar3 = (undefined4)uVar9;
  uVar10 = FUN_00008e0a(uVar3,uVar5,param_1,param_2);
  uVar2 = DAT_000129f4;
  uVar1 = DAT_000129f0;
  uVar6 = (undefined4)((ulonglong)uVar10 >> 0x20);
  uVar4 = (undefined4)uVar10;
  cVar8 = true;
  bVar7 = (param_2 & 0x80000000) == 0;
  if (bVar7) {
    FUN_000090dc(uVar4,uVar6,0,DAT_000129f8);
    if (cVar8 == '\0') goto LAB_000129b4;
    bVar7 = true;
    FUN_0000910c(uVar4,uVar6,0,uVar2);
    if ((bool)cVar8 && !bVar7) goto LAB_000129e4;
  }
  else {
    FUN_000090dc(uVar4,uVar6,0,DAT_000129f8);
    if (!(bool)cVar8 || bVar7) {
LAB_000129b4:
      uVar9 = FUN_00008e04(uVar3,uVar5,0,uVar1);
      goto LAB_000129e4;
    }
    FUN_0000910c(uVar4,uVar6,0,uVar2);
    if (cVar8 != '\0') goto LAB_000129e4;
  }
  uVar9 = FUN_00008cc2(uVar3,uVar5,0,uVar1);
LAB_000129e4:
  return CONCAT44(param_2 & 0x80000000 | (uint)((ulonglong)uVar9 >> 0x20) & 0x7fffffff,(int)uVar9);
}


/* ===== FUN_00012a0c @ 00012a0c ===== */

void FUN_00012a0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  *(undefined4 *)(DAT_00012a2c + 0xc) = param_1;
  *(undefined4 *)(DAT_00012a2c + 0x10) = 1;
  *(uint *)(DAT_00012a30 + 0xc) = *(uint *)(DAT_00012a30 + 0xc) & 0xfffffff3 | param_4 << 2;
  return;
}


/* ===== FUN_00012a34 @ 00012a34 ===== */

void FUN_00012a34(undefined4 param_1)

{
  *(undefined4 *)(DAT_00012a40 + 4) = param_1;
  *(undefined4 *)(DAT_00012a40 + 8) = 0;
  return;
}


/* ===== FUN_00012a44 @ 00012a44 ===== */

void FUN_00012a44(void)

{
  int iVar1;
  undefined auStack_24 [36];
  
  iVar1 = FUN_00010a7c();
  if (iVar1 == 1) {
    FUN_00014a58(auStack_24);
    FUN_00013b48(0);
  }
  else {
    FUN_00014bbc();
  }
  return;
}


/* ===== FUN_00012a68 @ 00012a68 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00012a68(short param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  undefined uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = param_3;
  local_1c = param_4;
  FUN_0000b258(param_1,0);
  if (param_1 == 0x201) {
    if (param_2 == 1) {
      FUN_00013758(200);
    }
    else if (param_2 == 2) {
      FUN_000136b8();
      FUN_00013654();
      FUN_0001371c();
    }
    else if (param_2 == 3) {
      FUN_0000d038();
    }
    else if (param_2 == 4) {
      FUN_0000d764();
    }
    else if (param_2 == 5) {
      FUN_000136f4();
    }
    else if (param_2 == 6) {
      FUN_0001163c();
    }
    else if (param_2 == 7) {
      FUN_0000d200();
    }
    else if (param_2 == 8) {
      FUN_00011648();
    }
    else if (param_2 == 9) {
      FUN_0000d20c();
    }
    else if (param_2 == 10) {
      FUN_00013804(0);
      FUN_000137e0(0);
    }
    else if (param_2 == 0xb) {
      FUN_00013804(1);
      FUN_000137e0(1);
    }
    else if (param_2 == 0xc) {
      FUN_00013804(2);
      FUN_000137e0(2);
    }
    else if (param_2 == 0xd) {
      FUN_00013668();
    }
    else if (param_2 == 0xe) {
      FUN_00013890(0);
      FUN_0001386c(0);
    }
    else if (param_2 == 0xf) {
      FUN_00013890(1);
      FUN_0001386c(1);
    }
    else if (param_2 == 0x10) {
      FUN_00013890(2);
      FUN_0001386c(2);
    }
    else if (param_2 == 0x11) {
      FUN_0001367c();
    }
    else if (param_2 == 0x12) {
      FUN_00013744();
    }
    else if (param_2 == 0x13) {
      FUN_00013984(0);
      FUN_00013960(0);
      FUN_0000d764();
      FUN_0000d038();
      FUN_0000e308();
      FUN_0000d198();
    }
    else if (param_2 == 0x14) {
      FUN_00013984(1);
      FUN_00013960(1);
      FUN_0000d764();
      FUN_0000d038();
      FUN_0000e308();
      FUN_0000d198();
    }
    else if (param_2 == 0x15) {
      FUN_000136a4();
    }
    else if (param_2 == 0x16) {
      FUN_00013a24(1);
      FUN_00013a30(1);
    }
    else if (param_2 == 0x17) {
      FUN_00013a24(0);
      FUN_00013a30(0);
    }
    else if (param_2 == 0x18) {
      FUN_000136cc();
    }
    else if (param_2 == 0x19) {
      FUN_00013708();
    }
    else if (param_2 == 0x1a) {
      FUN_0000e308();
    }
    else if (param_2 == 0x1b) {
      FUN_00013a24(2);
      FUN_00013a30(2);
    }
    else if (param_2 == 0x1c) {
      FUN_00013a24(3);
      FUN_00013a30(3);
    }
    else if (param_2 == 0x1d) {
      FUN_00013930(0);
      FUN_0001393c(0);
    }
    else if (param_2 == 0x1e) {
      FUN_00013930(1);
      FUN_0001393c(1);
    }
    else if (param_2 == 0x1f) {
      FUN_00013690();
    }
    else if (param_2 == 0x20) {
      FUN_00013930(2);
      FUN_0001393c(2);
    }
    else if (param_2 == 0x21) {
      FUN_00013930(3);
      FUN_0001393c(3);
    }
    else if (param_2 == 0x22) {
      FUN_00013930(4);
      FUN_0001393c(4);
    }
    else if (param_2 == 0x23) {
      FUN_00013930(5);
      FUN_0001393c(5);
    }
    else if (param_2 == 0x24) {
      FUN_00013a24(4);
      FUN_00013a30(4);
    }
    else if (param_2 == 0x25) {
      FUN_0000d198();
    }
    else if (param_2 == 0x26) {
      FUN_00013730();
    }
    else if (param_2 == 0x27) {
      FUN_000136e0();
    }
  }
  else if (param_1 == 0x202) {
    if (param_2 < 4) {
      iVar3 = FUN_000109e8();
      *(undefined4 *)(iVar3 + param_2 * 0x18) = param_3;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + 4) = param_4;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + 8) = param_5;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + 0xc) = param_6;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + 0x10) = param_7;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + 0x14) = param_8;
      FUN_000139d0(iVar3);
    }
    else if ((param_2 < 4) || (7 < param_2)) {
      if ((7 < param_2) && (param_2 < 0xc)) {
        iVar3 = FUN_00010a24();
        *(undefined4 *)(iVar3 + param_2 * 0x18 + -0xc0) = param_3;
        *(undefined4 *)(iVar3 + param_2 * 0x18 + -0xbc) = param_4;
        *(undefined4 *)(iVar3 + param_2 * 0x18 + -0xb8) = param_5;
        *(undefined4 *)(iVar3 + param_2 * 0x18 + -0xb4) = param_6;
        *(undefined4 *)(iVar3 + param_2 * 0x18 + -0xb0) = param_7;
        *(undefined4 *)(iVar3 + param_2 * 0x18 + -0xac) = param_8;
        FUN_00013aec(iVar3);
      }
    }
    else {
      iVar3 = FUN_000106e8();
      *(undefined4 *)(iVar3 + param_2 * 0x18 + -0x60) = param_3;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + -0x5c) = param_4;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + -0x58) = param_5;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + -0x54) = param_6;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + -0x50) = param_7;
      *(undefined4 *)(iVar3 + param_2 * 0x18 + -0x4c) = param_8;
      FUN_000137b8(iVar3);
    }
  }
  else if (param_1 == 0x203) {
    FUN_0000c69c(param_2);
    FUN_00013a98(param_2);
    FUN_0001377c();
  }
  else if (param_1 == 0x204) {
    local_20 = param_2;
    local_1c = param_3;
    FUN_00013b8c(param_2,param_3);
    FUN_00013b64(local_20,local_1c);
  }
  else if (param_1 == 0x205) {
    FUN_00013ac8(param_2);
    FUN_00013b9c(param_2);
  }
  else if (param_1 == 0x206) {
    FUN_00013b18(param_2);
    FUN_00013b24(param_2);
  }
  else if (param_1 == 0x207) {
    FUN_00013a54(param_2);
    FUN_00013a60(param_2);
  }
  else if (param_1 == -1) {
    uVar4 = FUN_00010a88();
    local_1c = CONCAT31((int3)((uint)uVar4 >> 8),6);
    FUN_0000b258(0xffff,&local_1c,4);
  }
  else if (param_1 == 0x3000) {
    FUN_00013d84(_DAT_00012fe4,0);
    FUN_0000a6c4();
    FUN_0000995c(&local_20,0x10000,6);
    uVar4 = local_20;
    uVar1 = local_20;
    local_20._3_1_ = SUB41(uVar4,3);
    uVar2 = local_20._3_1_;
    local_20 = uVar1;
    FUN_00011fb8("tmp[1] = %0#2x,tmp[3] = %0#2x,tmp[4] = %0#2x,",0xff,uVar2,local_1c._1_1_);
    FUN_000099b4(&local_20,0x10000,6);
    FUN_0000b258(0x3000,(int)&local_20 + 1,1);
    FUN_00015138();
    FUN_0000d4bc(50000,0);
    FUN_00014024();
  }
  else if (param_1 == 0x4000) {
    FUN_00015138();
    FUN_00013d84(_DAT_00012fe4,0);
    FUN_0000a6c4();
    local_1c = 2;
    FUN_000099b4(&local_1c,DAT_00013018,1);
    FUN_0000d4bc(50000,0);
    FUN_00014024();
  }
  return;
}


/* ===== FUN_0001301c @ 0001301c ===== */

void FUN_0001301c(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_00013068 | 1;
  }
  else {
    uVar1 = *DAT_00013068 & 0xfffffffe;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  *DAT_00013068 = uVar1;
  if ((param_1 | param_2) == 1) {
    uVar1 = *(uint *)(DAT_0001306c + 0x19c) & 0xff00ffff | 0xb60000;
  }
  else {
    uVar1 = *(uint *)(DAT_0001306c + 0x19c) & 0xff49ffff;
  }
  DAT_00013068[-0x1e] = uVar1;
  return;
}


/* ===== FUN_00013070 @ 00013070 ===== */

undefined4 FUN_00013070(void)

{
  undefined4 uVar1;
  uint in_r3;
  uint local_10;
  
  do {
  } while (*DAT_000130ac == 0);
  *DAT_000130ac = 0;
  *DAT_000130b0 = *DAT_000130b0 + 1;
  local_10 = in_r3;
  FUN_00013128(&local_10);
  FUN_00013264(DAT_000130b4,local_10 & 0xff);
  uVar1 = FUN_00012008(local_10 & 0xff);
  return uVar1;
}


/* ===== FUN_000130b8 @ 000130b8 ===== */

void FUN_000130b8(void)

{
  FUN_0000c5b0();
  FUN_0000c642(DAT_0001311c);
  FUN_0000c3c8(DAT_0001311c);
  FUN_00014d58(&DAT_40004000,0x1c200,0);
  FUN_00010b98(9,0);
  FUN_00010b98(2,0);
  FUN_00010b98(0x14,0);
  FUN_00012598();
  FUN_00009f28();
  FUN_0000c8e8(DAT_00013120,0);
  FUN_0000c67c();
  FUN_00013bc0();
  FUN_0000c380();
  FUN_0000c570();
  FUN_000149d8(DAT_00013124 << 0x12,DAT_00013124,0);
  return;
}


/* ===== FUN_00013128 @ 00013128 ===== */

void FUN_00013128(undefined *param_1)

{
  *DAT_00013160 = *DAT_00013160 + 1;
  if (*DAT_00013164 == 0) {
    *param_1 = 0;
  }
  else if (*DAT_00013160 == *DAT_00013164 * (*DAT_00013160 / *DAT_00013164)) {
    *param_1 = 1;
  }
  else {
    *param_1 = 0;
  }
  return;
}


/* ===== FUN_00013168 @ 00013168 ===== */

void FUN_00013168(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0000c4d8(DAT_000131bc,2,param_3,param_4,param_2,param_3,param_4);
  FUN_0000c1ec(DAT_000131bc);
  FUN_0000c148(*DAT_000131bc,DAT_000131bc[1],1,0,2);
  FUN_00014c68(DAT_000131bc[4]);
  FUN_000111cc(1,0);
  FUN_00010fb0(0,0,0,0,*(undefined4 *)(DAT_000131bc + 0x24),*(undefined4 *)(DAT_000131bc + 0x28),
               *(undefined4 *)(DAT_000131bc + 0x2c));
  return;
}


/* ===== FUN_000131c0 @ 000131c0 ===== */

void FUN_000131c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0000c4d8(DAT_00013214,2,param_3,param_4,param_2,param_3,param_4);
  FUN_0000c1ec(DAT_00013214);
  FUN_0000c148(*DAT_00013214,DAT_00013214[1],1,0,2);
  FUN_00014c68(DAT_00013214[4]);
  FUN_000111cc(1,0);
  FUN_00010fb0(0,0,0,0,*(undefined4 *)(DAT_00013214 + 0x24),*(undefined4 *)(DAT_00013214 + 0x28),
               *(undefined4 *)(DAT_00013214 + 0x2c));
  return;
}


/* ===== FUN_00013218 @ 00013218 ===== */

void FUN_00013218(int param_1)

{
  FUN_0000b294();
  FUN_00013d2c(DAT_00013260);
  FUN_00013e04(DAT_00013260,0x20);
  FUN_00013e04(DAT_00013260,(uint)(param_1 << 0x14) >> 0x18);
  FUN_00013e04(DAT_00013260,(uint)(param_1 << 0x1c) >> 0x18);
  FUN_00013e04(DAT_00013260,0);
  FUN_00013d58(DAT_00013260);
  FUN_0000b284(DAT_00013260);
  FUN_000099a2();
  return;
}


/* ===== FUN_00013264 @ 00013264 ===== */

void FUN_00013264(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_00013344(param_1);
  }
  if (param_2 == 1) {
    FUN_00013428(param_1);
  }
  return;
}


/* ===== FUN_00013280 @ 00013280 ===== */

void FUN_00013280(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_000132cc;
  if (param_1 == 1) {
    *DAT_000132cc = 4;
    *DAT_000132d0 = 0x20 / *puVar1;
    *DAT_000132d4 = 4;
    *DAT_000132d8 = 2;
  }
  else if (param_1 == 2) {
    *DAT_000132cc = 0x10;
    *DAT_000132d0 = 0x20 / *puVar1;
    *DAT_000132d4 = 0x10;
    *DAT_000132d8 = 4;
  }
  return;
}


/* ===== FUN_000132dc @ 000132dc ===== */

void FUN_000132dc(undefined *param_1)

{
  FUN_000111cc(1);
  FUN_00010fb0(*param_1,param_1[1],param_1[2],param_1[3],*(undefined4 *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
  FUN_0000c014(2,DAT_0001333c >> 0x15,0x11,DAT_00013340 + -4,0,DAT_00013340,DAT_0001333c);
  FUN_000111cc(1,0);
  FUN_00010fb0(0,0,0,0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c));
  return;
}


/* ===== FUN_00013344 @ 00013344 ===== */

void FUN_00013344(undefined *param_1)

{
  uint uVar1;
  
  FUN_000111cc(1);
  FUN_00010fb0(*param_1,param_1[1],param_1[2],param_1[3],*(undefined4 *)(param_1 + 0x24),
               *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
  for (uVar1 = 0; uVar1 < 0x20; uVar1 = uVar1 + 1) {
    FUN_0000c014(2,DAT_00013404 >> 0x15,2,DAT_00013408 + -4,DAT_0001340c,DAT_00013408,DAT_00013404);
    FUN_0000e9d8(DAT_0001340c >> 0x15,0x6a,DAT_0001340c,DAT_00013410 + uVar1 * 0x1a8);
    FUN_0000e9d8(DAT_00013418 >> 0x15,0x6a,DAT_00013418,DAT_00013414 + uVar1 * 0x1a8);
    FUN_0000e9d8(DAT_00013404 >> 0x15,0x6a,DAT_00013404,DAT_0001341c + uVar1 * 0x1a8);
    FUN_0000e9d8(DAT_00013424 >> 0x15,0x6a,DAT_00013424,DAT_00013420 + uVar1 * 0x1a8);
  }
  FUN_000111cc(1,0);
  FUN_00010fb0(0,0,0,0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x2c));
  return;
}


/* ===== FUN_00013428 @ 00013428 ===== */

void FUN_00013428(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  FUN_000111cc(1);
  for (uVar2 = 0; uVar2 < *DAT_00013638; uVar2 = uVar2 + 1) {
    FUN_00008ae8(DAT_000135fc,0xd40);
    for (uVar4 = 0; uVar4 < *DAT_00013630; uVar4 = uVar4 + 1) {
      FUN_00010fb0(*param_1,param_1[1],param_1[2],param_1[3],*(undefined4 *)(param_1 + 0x24),
                   *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c));
      FUN_0000c014(2,DAT_00013600 >> 0x15,2,DAT_00013604 + -4,DAT_00013608,DAT_00013604,DAT_00013600
                  );
      param_2 = *(undefined4 *)(param_1 + 0x24);
      param_3 = *(undefined4 *)(param_1 + 0x28);
      param_4 = *(undefined4 *)(param_1 + 0x2c);
      FUN_00010fb0(0,0,0,0,param_2,param_3,param_4);
      FUN_0000e9d8(DAT_00013608 >> 0x15,0x6a,DAT_00013608);
      FUN_0000e9d8(DAT_0001360c >> 0x15,0x6a,DAT_0001360c);
      FUN_0000e9d8(DAT_00013600 >> 0x15,0x6a,DAT_00013600);
      FUN_0000e9d8(DAT_00013610 >> 0x15,0x6a,DAT_00013610);
      FUN_000122ac(0x6a,DAT_00013608,DAT_000135fc,DAT_00013614);
      FUN_000122ac(0x6a,DAT_0001360c,DAT_0001361c,DAT_00013618);
      FUN_000122ac(0x6a,DAT_00013600,DAT_00013624,DAT_00013620);
      FUN_000122ac(0x6a,DAT_00013610,DAT_0001362c,DAT_00013628);
      if (uVar3 < 0x20) {
        uVar3 = uVar3 + 1;
      }
    }
    FUN_000122e0(0x6a,*DAT_00013634,DAT_000135fc,DAT_00013614,param_2,param_3,param_4);
    FUN_000122e0(0x6a,*DAT_00013634,DAT_0001361c,DAT_00013618);
    FUN_000122e0(0x6a,*DAT_00013634,DAT_00013624,DAT_00013620);
    FUN_000122e0(0x6a,*DAT_00013634,DAT_0001362c,DAT_00013628);
    FUN_000115bc(DAT_000135fc,DAT_00013640 + (*DAT_00013638 * *DAT_0001363c + uVar2) * 0x1a8,4,4,
                 0x6a);
    FUN_000115bc(DAT_0001361c,DAT_00013644 + (*DAT_00013638 * *DAT_0001363c + uVar2) * 0x1a8,4,4,
                 0x6a);
    FUN_000115bc(DAT_00013624,DAT_00013648 + (*DAT_00013638 * *DAT_0001363c + uVar2) * 0x1a8,4,4,
                 0x6a);
    param_2 = 0x6a;
    FUN_000115bc(DAT_0001362c,DAT_0001364c + (*DAT_00013638 * *DAT_0001363c + uVar2) * 0x1a8,4);
  }
  FUN_000111cc(1,0);
  puVar1 = DAT_0001363c;
  *DAT_0001363c = *DAT_0001363c + 1;
  *DAT_0001363c = *puVar1 - *DAT_00013650 * (*puVar1 / *DAT_00013650);
  return;
}


/* ===== FUN_00013654 @ 00013654 ===== */

void FUN_00013654(void)

{
  FUN_0000b258(0xa0c,DAT_00013664,0x60);
  return;
}


/* ===== FUN_00013668 @ 00013668 ===== */

void FUN_00013668(void)

{
  FUN_0000b258(0xa0e,DAT_00013678,1);
  return;
}


/* ===== FUN_0001367c @ 0001367c ===== */

void FUN_0001367c(void)

{
  FUN_0000b258(0xa0f,DAT_0001368c,1);
  return;
}


/* ===== FUN_00013690 @ 00013690 ===== */

void FUN_00013690(void)

{
  FUN_0000b258(0xa15,DAT_000136a0,1);
  return;
}


/* ===== FUN_000136a4 @ 000136a4 ===== */

void FUN_000136a4(void)

{
  FUN_0000b258(0xa11,DAT_000136b4,1);
  return;
}


/* ===== FUN_000136b8 @ 000136b8 ===== */

void FUN_000136b8(void)

{
  FUN_0000b258(0xa0b,DAT_000136c8,0x60);
  return;
}


/* ===== FUN_000136cc @ 000136cc ===== */

void FUN_000136cc(void)

{
  FUN_0000b258(0xa12,DAT_000136dc,4);
  return;
}


/* ===== FUN_000136e0 @ 000136e0 ===== */

void FUN_000136e0(void)

{
  FUN_0000b258(0xa18,DAT_000136f0,4);
  return;
}


/* ===== FUN_000136f4 @ 000136f4 ===== */

void FUN_000136f4(void)

{
  FUN_0000b258(0xa0d,DAT_00013704,4);
  return;
}


/* ===== FUN_00013708 @ 00013708 ===== */

void FUN_00013708(void)

{
  FUN_0000b258(0xa13,DAT_00013718,4);
  return;
}


/* ===== FUN_0001371c @ 0001371c ===== */

void FUN_0001371c(void)

{
  FUN_0000b258(0xa16,DAT_0001372c,0x60);
  return;
}


/* ===== FUN_00013730 @ 00013730 ===== */

void FUN_00013730(void)

{
  FUN_0000b258(0xa17,DAT_00013740,4);
  return;
}


/* ===== FUN_00013744 @ 00013744 ===== */

void FUN_00013744(void)

{
  FUN_0000b258(0xa10,DAT_00013754,8);
  return;
}


/* ===== FUN_00013758 @ 00013758 ===== */

void FUN_00013758(undefined4 param_1)

{
  *DAT_00013760 = param_1;
  return;
}


/* ===== FUN_00013764 @ 00013764 ===== */

void FUN_00013764(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000106e8();
  FUN_00008ab6(uVar1,DAT_00013778,0x60);
  return;
}


/* ===== FUN_0001377c @ 0001377c ===== */

void FUN_0001377c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00008c2e(DAT_000137b0,*DAT_000137ac);
  FUN_00010a18();
  uVar2 = FUN_00008fe4();
  FUN_00008bca(uVar2,uVar1);
  uVar1 = FUN_0000905c();
  *DAT_000137b4 = uVar1;
  return;
}


/* ===== FUN_000137b8 @ 000137b8 ===== */

void FUN_000137b8(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_00008ab6(DAT_000137d8,param_1,0x60);
  uVar1 = DAT_000137dc;
  puVar2 = (undefined4 *)(DAT_000137d8 + -0x6c);
  *(undefined4 *)(DAT_000137d8 + -4) = DAT_000137dc;
  *puVar2 = uVar1;
  FUN_00010028();
  return;
}


/* ===== FUN_000137e0 @ 000137e0 ===== */

void FUN_000137e0(undefined param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *(undefined *)(DAT_000137fc + 0x36) = param_1;
  uVar2 = DAT_00013800;
  puVar1 = DAT_000137fc;
  DAT_000137fc[0x35] = DAT_00013800;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013804 @ 00013804 ===== */

void FUN_00013804(int param_1)

{
  *DAT_00013860 = (char)param_1;
  if (param_1 == 0) {
    FUN_00013abc(0);
    *DAT_00013868 = DAT_00013864;
    FUN_0001377c();
  }
  else if (param_1 == 1) {
    FUN_00013abc(5);
    *DAT_00013868 = DAT_00013864;
    FUN_0001377c();
    FUN_00013280(1);
  }
  else if (param_1 == 2) {
    FUN_00013abc(5);
    *DAT_00013868 = DAT_00013864;
    FUN_0001377c();
    FUN_00013280(2);
  }
  return;
}


/* ===== FUN_0001386c @ 0001386c ===== */

void FUN_0001386c(undefined param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *(undefined *)(DAT_00013888 + 0x38) = param_1;
  uVar2 = DAT_0001388c;
  puVar1 = DAT_00013888;
  DAT_00013888[0x37] = DAT_0001388c;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013890 @ 00013890 ===== */

void FUN_00013890(int param_1)

{
  undefined4 uVar1;
  
  *DAT_0001391c = (char)param_1;
  if (param_1 == 0) {
    uVar1 = FUN_00008c2e(DAT_00013924,*DAT_00013920);
    FUN_00008bca(uVar1,0x40000000);
    uVar1 = FUN_0000905c();
    *DAT_00013928 = uVar1;
    FUN_000139ac(6);
  }
  else if (param_1 == 1) {
    uVar1 = FUN_00008c2e(DAT_00013924,*DAT_00013920);
    FUN_00008bca(uVar1,0x3f800000);
    uVar1 = FUN_0000905c();
    *DAT_00013928 = uVar1;
    FUN_000139ac(4);
  }
  else if (param_1 == 2) {
    uVar1 = FUN_00008c2e(DAT_00013924,*DAT_00013920);
    FUN_00008bca(uVar1,DAT_0001392c);
    uVar1 = FUN_0000905c();
    *DAT_00013928 = uVar1;
    FUN_000139ac(3);
  }
  return;
}


/* ===== FUN_00013930 @ 00013930 ===== */

void FUN_00013930(undefined param_1)

{
  *DAT_00013938 = param_1;
  return;
}


/* ===== FUN_0001393c @ 0001393c ===== */

void FUN_0001393c(undefined param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *(undefined *)(DAT_00013958 + 0x43) = param_1;
  uVar2 = DAT_0001395c;
  puVar1 = DAT_00013958;
  DAT_00013958[0x42] = DAT_0001395c;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013960 @ 00013960 ===== */

void FUN_00013960(undefined param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *(undefined *)(DAT_0001397c + 0x3d) = param_1;
  uVar2 = DAT_00013980;
  puVar1 = DAT_0001397c;
  DAT_0001397c[0x3c] = DAT_00013980;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013984 @ 00013984 ===== */

void FUN_00013984(undefined param_1)

{
  *DAT_0001398c = param_1;
  return;
}


/* ===== FUN_00013990 @ 00013990 ===== */

void FUN_00013990(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *DAT_000139a8 = 1 << (param_1 & 0xff);
  }
  else {
    DAT_000139a8[-0x20] = 1 << (param_1 & 0xff);
  }
  return;
}


/* ===== FUN_000139ac @ 000139ac ===== */

void FUN_000139ac(undefined4 param_1)

{
  *DAT_000139b4 = param_1;
  return;
}


/* ===== FUN_000139b8 @ 000139b8 ===== */

void FUN_000139b8(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000109e8();
  FUN_00008ab6(uVar1,DAT_000139cc,0x60);
  return;
}


/* ===== FUN_000139d0 @ 000139d0 ===== */

void FUN_000139d0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_00008ab6(DAT_000139f0,param_1,0x60);
  uVar1 = DAT_000139f4;
  puVar2 = (undefined4 *)(DAT_000139f0 + -8);
  *(undefined4 *)(DAT_000139f0 + -4) = DAT_000139f4;
  *puVar2 = uVar1;
  FUN_00010028();
  return;
}


/* ===== FUN_000139f8 @ 000139f8 ===== */

void FUN_000139f8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000109f0();
  uVar1 = FUN_0000e68c(uVar1,param_2,param_3);
  FUN_00013a84(param_1,uVar1);
  return;
}


/* ===== FUN_00013a24 @ 00013a24 ===== */

void FUN_00013a24(undefined param_1)

{
  *DAT_00013a2c = param_1;
  return;
}


/* ===== FUN_00013a30 @ 00013a30 ===== */

void FUN_00013a30(undefined param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  *(undefined *)(DAT_00013a4c + 0x3f) = param_1;
  uVar2 = DAT_00013a50;
  puVar1 = DAT_00013a4c;
  DAT_00013a4c[0x3e] = DAT_00013a50;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013a54 @ 00013a54 ===== */

void FUN_00013a54(undefined4 param_1)

{
  *DAT_00013a5c = param_1;
  return;
}


/* ===== FUN_00013a60 @ 00013a60 ===== */

void FUN_00013a60(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  DAT_00013a7c[0x60] = param_1;
  uVar2 = DAT_00013a80;
  puVar1 = DAT_00013a7c;
  DAT_00013a7c[0x5f] = DAT_00013a80;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013a84 @ 00013a84 ===== */

void FUN_00013a84(int param_1,int param_2)

{
  if (-1 < param_1) {
    *(char *)(DAT_00013a94 + param_1) = (char)((uint)(param_2 << 0x1d) >> 0x18);
  }
  return;
}


/* ===== FUN_00013a98 @ 00013a98 ===== */

void FUN_00013a98(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  DAT_00013ab4[0x34] = param_1;
  uVar2 = DAT_00013ab8;
  puVar1 = DAT_00013ab4;
  DAT_00013ab4[0x33] = DAT_00013ab8;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013abc @ 00013abc ===== */

void FUN_00013abc(undefined4 param_1)

{
  *DAT_00013ac4 = param_1;
  return;
}


/* ===== FUN_00013ac8 @ 00013ac8 ===== */

void FUN_00013ac8(undefined4 param_1)

{
  *DAT_00013ad0 = param_1;
  return;
}


/* ===== FUN_00013ad4 @ 00013ad4 ===== */

void FUN_00013ad4(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00010a24();
  FUN_00008ab6(uVar1,DAT_00013ae8,0x60);
  return;
}


/* ===== FUN_00013aec @ 00013aec ===== */

void FUN_00013aec(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_00008ab6(DAT_00013b0c,param_1,0x60);
  puVar2 = DAT_00013b14;
  uVar1 = DAT_00013b10;
  DAT_00013b14[0x44] = DAT_00013b10;
  *puVar2 = uVar1;
  FUN_00010028();
  return;
}


/* ===== FUN_00013b18 @ 00013b18 ===== */

void FUN_00013b18(undefined4 param_1)

{
  *DAT_00013b20 = param_1;
  return;
}


/* ===== FUN_00013b24 @ 00013b24 ===== */

void FUN_00013b24(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  DAT_00013b40[0x5e] = param_1;
  uVar2 = DAT_00013b44;
  puVar1 = DAT_00013b40;
  DAT_00013b40[0x5d] = DAT_00013b44;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013b48 @ 00013b48 ===== */

void FUN_00013b48(undefined param_1)

{
  *DAT_00013b50 = param_1;
  return;
}


/* ===== FUN_00013b54 @ 00013b54 ===== */

void FUN_00013b54(undefined param_1,undefined param_2,undefined param_3)

{
  int iVar1;
  
  iVar1 = DAT_00013b60;
  *(undefined *)(DAT_00013b60 + 1) = param_1;
  *(undefined *)(iVar1 + 2) = param_2;
  *(undefined *)(iVar1 + 3) = param_3;
  return;
}


/* ===== FUN_00013b64 @ 00013b64 ===== */

void FUN_00013b64(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_00013b84;
  *(undefined4 *)(DAT_00013b84 + 0x68) = param_1;
  *(undefined4 *)(iVar1 + 0x6c) = param_2;
  uVar2 = DAT_00013b88;
  puVar3 = (undefined4 *)(DAT_00013b84 + -0x80);
  *(undefined4 *)(DAT_00013b84 + 100) = DAT_00013b88;
  *puVar3 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013b8c @ 00013b8c ===== */

undefined4 * FUN_00013b8c(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00013b98;
  *DAT_00013b98 = param_1;
  puVar1[1] = param_2;
  return puVar1 + 2;
}


/* ===== FUN_00013b9c @ 00013b9c ===== */

void FUN_00013b9c(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  DAT_00013bb8[0x41] = param_1;
  uVar2 = DAT_00013bbc;
  puVar1 = DAT_00013bb8;
  DAT_00013bb8[0x40] = DAT_00013bbc;
  *puVar1 = uVar2;
  FUN_00010028();
  return;
}


/* ===== FUN_00013bc0 @ 00013bc0 ===== */

void FUN_00013bc0(void)

{
  *DAT_00013bc8 = 100;
  return;
}


/* ===== FUN_00013bcc @ 00013bcc ===== */

void FUN_00013bcc(void)

{
  int iVar1;
  int iVar2;
  
  FUN_00011d9c();
  FUN_00011558(0);
  for (iVar2 = 0; iVar1 = DAT_00013c2c, iVar2 < 0x1f; iVar2 = iVar2 + 1) {
    if ((iVar2 != 0x16) && (iVar2 != 0x14)) {
      *(undefined4 *)(DAT_00013c2c + iVar2 * 4 + 0x30) = 0x50;
    }
  }
  *(undefined4 *)(DAT_00013c2c + 0x40) = 0x90;
  *(undefined4 *)(iVar1 + 0x5c) = 0x90;
  FUN_00010bf0(0x16,0);
  FUN_00012a34(*DAT_00013c30 << 5);
  FUN_00011d3c(1);
  iVar2 = FUN_0000c874();
  if (iVar2 == 0) {
    FUN_0001152c();
  }
  FUN_00011dd2();
  return;
}


/* ===== FUN_00013c34 @ 00013c34 ===== */

void FUN_00013c34(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0000c874();
  if (iVar2 == 0) {
    FUN_00011d9c();
    FUN_00011558(0);
    for (iVar2 = 0; iVar1 = DAT_00013c94, iVar2 < 0x1f; iVar2 = iVar2 + 1) {
      if ((iVar2 != 0x16) && (iVar2 != 0x14)) {
        *(undefined4 *)(DAT_00013c94 + iVar2 * 4 + 0x30) = 0x50;
      }
    }
    *(undefined4 *)(DAT_00013c94 + 0x40) = 0x90;
    *(undefined4 *)(iVar1 + 0x5c) = 0x90;
    FUN_00010bf0(0x16,0);
    FUN_00011d3c(1);
    iVar2 = FUN_0000c874();
    if (iVar2 == 0) {
      FUN_0001152c();
    }
    FUN_00011dd2();
  }
  return;
}


/* ===== FUN_00013c98 @ 00013c98 ===== */

void FUN_00013c98(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_000113f8(param_2 * 0x14);
  FUN_00008ae8(iVar1,param_2 * 0x14);
  FUN_0001085c(param_3,param_4,param_5,param_2,iVar1);
  FUN_0000eb84(param_1,iVar1,param_2,param_6);
  for (uVar2 = 0; (int)uVar2 < param_2; uVar2 = uVar2 + 1 & 0xffff) {
    iVar3 = (int)*(char *)(iVar1 + uVar2 * 0x14 + 0x10);
    if ((iVar3 < 0) || (3 < iVar3)) {
      if (iVar3 == 4) {
        FUN_00010d0c(param_1,iVar1);
      }
    }
    else {
      FUN_00014f74(param_1 + iVar3 * 0x84,iVar1 + uVar2 * 0x14,param_6);
    }
  }
  FUN_00010644(iVar1);
  return;
}


/* ===== FUN_00013d2c @ 00013d2c ===== */

void FUN_00013d2c(int param_1)

{
  FUN_00010b98(4,0);
  if (param_1 == DAT_00013d54) {
    FUN_00010bf0(4,0);
  }
  else {
    FUN_00010bf0(0xe,0);
  }
  return;
}


/* ===== FUN_00013d58 @ 00013d58 ===== */

void FUN_00013d58(int param_1)

{
  FUN_00010b98(4,0);
  if (param_1 == DAT_00013d80) {
    FUN_00010bf0(4,1);
  }
  else {
    FUN_00010bf0(0xe,1);
  }
  return;
}


/* ===== FUN_00013d84 @ 00013d84 ===== */

void FUN_00013d84(undefined4 *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DAT_00013e00;
  if (param_1 == DAT_00013dfc) {
    *(uint *)(DAT_00013e00 + 0x3c) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x40) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x44) = 1 << (param_2 & 0xff) | 0x600;
    *(uint *)(iVar1 + 0x48) = 1 << (param_2 & 0xff) | 0x600;
  }
  else {
    *(uint *)(DAT_00013e00 + 100) = 1 << (param_2 & 0xff) | 0x600;
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


/* ===== FUN_00013e04 @ 00013e04 ===== */

uint FUN_00013e04(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  do {
  } while ((*(uint *)(param_1 + 0xc) & 1) == 0);
  do {
  } while ((*(uint *)(param_1 + 0xc) & 4) != 4);
  return *(uint *)(param_1 + 8) & 0xff;
}


/* ===== FUN_00013e26 @ 00013e26 ===== */

undefined4
FUN_00013e26(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10
            )

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  ushort *puVar5;
  
  puVar1 = (ushort *)
           FUN_000106fc(param_1,param_4,param_5,param_6,param_7,param_8,param_9,param_1,param_2,
                        param_3,param_4);
  if (puVar1 == (ushort *)0x0) {
    uVar2 = 0xfffffffd;
  }
  else {
    if (param_10 <= (int)(uint)*puVar1) {
      for (puVar5 = *(ushort **)(puVar1 + 2); puVar5 != (ushort *)0x0;
          puVar5 = *(ushort **)(puVar5 + 2)) {
        piVar4 = (int *)(param_4 + (uint)*puVar5 * 0x14);
        if ((*piVar4 == -2) || (*piVar4 == -1)) {
          if ((*piVar4 == -1) && (iVar3 = FUN_0000ca40(*puVar5,param_2), iVar3 == -3)) {
            FUN_0000d508(puVar1);
            return 0xfffffffd;
          }
          *piVar4 = param_3;
        }
      }
    }
    FUN_0000d508(puVar1);
    uVar2 = 0;
  }
  return uVar2;
}


/* ===== FUN_00013eac @ 00013eac ===== */

uint FUN_00013eac(uint param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00009298();
  if (((int)(0x7f800000 - (uVar1 & 0x7fffffff)) < 0) &&
     (-1 < (int)(0x7f800000 - (param_1 & 0x7fffffff)))) {
    FUN_0000b40c(1);
  }
  return uVar1;
}


/* ===== FUN_00013ed8 @ 00013ed8 ===== */

void FUN_00013ed8(int param_1,int param_2,uint param_3,int param_4,uint param_5)

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
  
  iVar3 = FUN_000113f8(param_3 << 1);
  iVar4 = FUN_000113f8(param_3 << 1);
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
  FUN_00010644(iVar4);
  FUN_00010644(iVar3);
  return;
}


/* ===== FUN_00013fbc @ 00013fbc ===== */

void FUN_00013fbc(void)

{
  FUN_00013ff8();
  return;
}


/* ===== FUN_00013fc4 @ 00013fc4 ===== */

void FUN_00013fc4(void)

{
  int iVar1;
  
  *(uint *)(DAT_00013ff0 + 0xc) = *(uint *)(DAT_00013ff0 + 0xc) & 0xfffffffc;
  FUN_0000d4bc(100,0);
  for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
  }
  *DAT_00013ff4 = 1;
  return;
}


/* ===== FUN_00013ff8 @ 00013ff8 ===== */

void FUN_00013ff8(void)

{
  int iVar1;
  
  *(uint *)(DAT_0001401c + 0xc) = *(uint *)(DAT_0001401c + 0xc) & 0xfffffffc | 1;
  for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
  }
  *DAT_00014020 = 0;
  return;
}


/* ===== FUN_00014024 @ 00014024 ===== */

void FUN_00014024(void)

{
  *DAT_00014038 = *DAT_00014038 & 0xffff | DAT_0001403c;
  return;
}


/* ===== FUN_00014040 @ 00014040 ===== */

void FUN_00014040(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  char cVar10;
  undefined uVar11;
  undefined uVar12;
  
  iVar2 = FUN_000113f8(param_2 * 0x14);
  FUN_00008ae8(iVar2,param_2 * 0x14);
  for (; (int)param_3 < param_4; param_3 = param_3 + 1 & 0xffff) {
    iVar4 = *(int *)(param_5 + param_3 * 0x14);
    if (-1 < iVar4) {
      uVar3 = FUN_00008b1a(*(undefined4 *)(iVar2 + iVar4 * 0x14),
                           *(undefined4 *)(param_5 + param_3 * 0x14 + 8));
      *(undefined4 *)(iVar2 + iVar4 * 0x14) = uVar3;
      uVar3 = FUN_00008b1a(*(undefined4 *)(iVar2 + iVar4 * 0x14 + 4),
                           *(undefined4 *)(param_5 + param_3 * 0x14 + 0xc));
      *(undefined4 *)(iVar2 + iVar4 * 0x14 + 4) = uVar3;
      uVar3 = FUN_00008b1a(*(undefined4 *)(iVar2 + iVar4 * 0x14 + 8),
                           *(undefined4 *)(param_5 + param_3 * 0x14 + 0x10));
      *(undefined4 *)(iVar2 + iVar4 * 0x14 + 8) = uVar3;
      uVar3 = FUN_00008fd2(*(undefined4 *)(param_5 + param_3 * 0x14 + 4));
      uVar3 = FUN_00008b1a(uVar3,*(undefined4 *)(iVar2 + iVar4 * 0x14 + 0xc));
      *(undefined4 *)(iVar2 + iVar4 * 0x14 + 0xc) = uVar3;
      *(int *)(iVar2 + iVar4 * 0x14 + 0x10) = *(int *)(iVar2 + iVar4 * 0x14 + 0x10) + 1;
    }
  }
  uVar7 = 0;
  do {
    if (param_2 <= (int)uVar7) {
      FUN_00010644(iVar2);
      return;
    }
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar7 * 0x14),uVar3);
    *(undefined4 *)(iVar2 + uVar7 * 0x14) = uVar3;
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 4),uVar3);
    *(undefined4 *)(iVar2 + uVar7 * 0x14 + 4) = uVar3;
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 8),uVar3);
    *(undefined4 *)(iVar2 + uVar7 * 0x14 + 8) = uVar3;
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 0xc),uVar3);
    *(undefined4 *)(iVar2 + uVar7 * 0x14 + 0xc) = uVar3;
    if (0x31 < *(int *)(iVar2 + uVar7 * 0x14 + 0x10)) {
      puVar8 = (undefined4 *)(iVar2 + uVar7 * 0x14);
      iVar4 = FUN_00014714(*puVar8,puVar8[1],puVar8[2],puVar8[3],
                           *(undefined4 *)(iVar2 + uVar7 * 0x14 + 0x10));
      if (iVar4 != 0) {
        cVar10 = '\x04';
        for (uVar9 = 0; uVar9 < 4; uVar9 = uVar9 + 1 & 0xff) {
          bVar1 = *(byte *)(param_1 + uVar9 * 0x84 + 0x1a);
          uVar12 = 1 < bVar1;
          uVar11 = bVar1 == 2;
          if ((bool)uVar11) {
            uVar3 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 4),
                                 *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x74));
            uVar5 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar7 * 0x14 + 4),
                                 *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x74));
            uVar3 = FUN_00008bca(uVar5,uVar3);
            uVar5 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar7 * 0x14),
                                 *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x70));
            uVar6 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar7 * 0x14),
                                 *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x70));
            uVar5 = FUN_00008bca(uVar6,uVar5);
            uVar3 = FUN_00008b1a(uVar5,uVar3);
            FUN_00009174(uVar3,DAT_00014390);
            if (!(bool)uVar12 || (bool)uVar11) {
              cVar10 = (char)uVar9;
            }
          }
        }
        if (cVar10 == '\x04') {
          for (uVar9 = 0; uVar9 < 4; uVar9 = uVar9 + 1 & 0xff) {
            if ((*(char *)(param_1 + uVar9 * 0x84 + 0x1a) == '\0') &&
               (*(char *)(param_1 + uVar9 * 0x84 + 0x18) == '\0')) {
              *(undefined *)(param_1 + uVar9 * 0x84 + 0x18) = 0;
              *(undefined *)(param_1 + uVar9 * 0x84 + 0x1a) = 2;
              *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x20) = *(undefined4 *)(iVar2 + uVar7 * 0x14)
              ;
              *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x24) =
                   *(undefined4 *)(iVar2 + uVar7 * 0x14 + 4);
              *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x28) = 0;
              *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x2c) = 0;
              *(undefined4 *)(param_1 + uVar9 * 0x84 + 8) =
                   *(undefined4 *)(iVar2 + uVar7 * 0x14 + 8);
              *(undefined2 *)(param_1 + uVar9 * 0x84 + 0x1c) = 1;
              *(undefined4 *)(param_1 + uVar9 * 0x84 + 0x14) = 200;
              FUN_0000a14c(param_1 + uVar9 * 0x84 + 0x20);
              break;
            }
          }
        }
      }
    }
    uVar7 = uVar7 + 1 & 0xffff;
  } while( true );
}


/* ===== FUN_00014394 @ 00014394 ===== */

void FUN_00014394(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined uVar13;
  undefined uVar14;
  undefined4 uStack_44;
  undefined4 local_40;
  
  iVar2 = FUN_000113f8(param_2 * 0x14);
  FUN_00008ae8(iVar2,param_2 * 0x14);
  for (; (int)param_3 < param_4; param_3 = param_3 + 1 & 0xffff) {
    iVar4 = *(int *)(param_5 + param_3 * 0x14);
    if (-1 < iVar4) {
      uVar3 = FUN_00008b1a(*(undefined4 *)(iVar2 + iVar4 * 0x14),
                           *(undefined4 *)(param_5 + param_3 * 0x14 + 8));
      *(undefined4 *)(iVar2 + iVar4 * 0x14) = uVar3;
      uVar3 = FUN_00008b1a(*(undefined4 *)(iVar2 + iVar4 * 0x14 + 4),
                           *(undefined4 *)(param_5 + param_3 * 0x14 + 0xc));
      *(undefined4 *)(iVar2 + iVar4 * 0x14 + 4) = uVar3;
      uVar3 = FUN_00008b1a(*(undefined4 *)(iVar2 + iVar4 * 0x14 + 8),
                           *(undefined4 *)(param_5 + param_3 * 0x14 + 0x10));
      *(undefined4 *)(iVar2 + iVar4 * 0x14 + 8) = uVar3;
      uVar3 = FUN_00008fd2(*(undefined4 *)(param_5 + param_3 * 0x14 + 4));
      uVar3 = FUN_00008b1a(uVar3,*(undefined4 *)(iVar2 + iVar4 * 0x14 + 0xc));
      *(undefined4 *)(iVar2 + iVar4 * 0x14 + 0xc) = uVar3;
      *(int *)(iVar2 + iVar4 * 0x14 + 0x10) = *(int *)(iVar2 + iVar4 * 0x14 + 0x10) + 1;
    }
  }
  for (uVar10 = 0; (int)uVar10 < param_2; uVar10 = uVar10 + 1 & 0xffff) {
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar10 * 0x14),uVar3);
    *(undefined4 *)(iVar2 + uVar10 * 0x14) = uVar3;
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 4),uVar3);
    *(undefined4 *)(iVar2 + uVar10 * 0x14 + 4) = uVar3;
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 8),uVar3);
    *(undefined4 *)(iVar2 + uVar10 * 0x14 + 8) = uVar3;
    uVar3 = FUN_00008fd2(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10));
    uVar3 = FUN_00008c2e(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 0xc),uVar3);
    *(undefined4 *)(iVar2 + uVar10 * 0x14 + 0xc) = uVar3;
    *(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10) = 0xffffffff;
    puVar12 = (undefined4 *)(iVar2 + uVar10 * 0x14);
    iVar4 = FUN_00014714(*puVar12,puVar12[1],puVar12[2],puVar12[3],
                         *(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10));
    if (iVar4 != 0) {
      puVar12 = (undefined4 *)(iVar2 + uVar10 * 0x14);
      FUN_0000d62c(*puVar12,puVar12[1],puVar12[2],puVar12[3],
                   *(undefined4 *)(iVar2 + uVar10 * 0x14 + 0x10));
      for (uVar11 = 0; uVar11 < 4; uVar11 = uVar11 + 1 & 0xff) {
        bVar1 = *(byte *)(param_1 + uVar11 * 0x84 + 0x1a);
        uVar14 = 1 < bVar1;
        uVar13 = bVar1 == 2;
        if ((bool)uVar13) {
          uVar3 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 4),
                               *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x74));
          uVar5 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar10 * 0x14 + 4),
                               *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x74));
          uVar3 = FUN_00008bca(uVar5,uVar3);
          uVar5 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar10 * 0x14),
                               *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x70));
          uVar6 = FUN_00008bbe(*(undefined4 *)(iVar2 + uVar10 * 0x14),
                               *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x70));
          uVar6 = FUN_00008bca(uVar6,uVar5);
          uVar3 = FUN_00008b1a(uVar6,uVar3);
          FUN_00009174(uVar3,0x3f800000);
          if (!(bool)uVar14 || (bool)uVar13) {
            uVar3 = *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x70);
            uVar7 = *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x74);
            uVar8 = *(undefined4 *)(param_1 + uVar11 * 0x84 + 8);
            if ((*(char *)(param_1 + uVar11 * 0x84 + 0x1a) == '\x02') &&
               (iVar4 = FUN_0000dc58(uVar3,uVar7,uVar8,uStack_44,local_40,uVar5,uVar6), iVar4 == 0))
            {
              iVar4 = FUN_0000e270(uVar3,uVar7,uVar8,uStack_44,local_40);
              if (iVar4 == 1) {
                uVar9 = FUN_00010a2c();
                *(int *)(param_1 + uVar11 * 0x84 + 0x14) =
                     *(int *)(param_1 + uVar11 * 0x84 + 0x14) + 200;
                if (*(uint *)(param_1 + uVar11 * 0x84 + 0x14) < uVar9) {
                  uVar9 = *(uint *)(param_1 + uVar11 * 0x84 + 0x14);
                }
                *(uint *)(param_1 + uVar11 * 0x84 + 0x14) = uVar9;
              }
              else {
                *(int *)(param_1 + uVar11 * 0x84 + 0x14) =
                     *(int *)(param_1 + uVar11 * 0x84 + 0x14) + 200;
                if (*(int *)(param_1 + uVar11 * 0x84 + 0x14) < 200) {
                  uVar3 = *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x14);
                }
                else {
                  uVar3 = 200;
                }
                *(undefined4 *)(param_1 + uVar11 * 0x84 + 0x14) = uVar3;
              }
            }
          }
        }
      }
    }
  }
  FUN_00010644(iVar2);
  return;
}


/* ===== FUN_00014714 @ 00014714 ===== */

uint FUN_00014714(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  
  uVar11 = 0;
  if (*DAT_000147d4 == '\0') {
    uVar10 = 10;
  }
  else {
    uVar10 = 0;
  }
  uVar4 = FUN_00008fd2(10);
  uVar5 = FUN_00008c2e(param_1,0x3f000000);
  FUN_00008b1a(uVar5,uVar4);
  cVar2 = FUN_0000902a();
  iVar8 = (int)cVar2;
  uVar10 = FUN_00008fd2(uVar10);
  uVar4 = FUN_00008c2e(param_2,0x3f000000);
  FUN_00008b1a(uVar4,uVar10);
  cVar3 = FUN_0000902a();
  iVar9 = (int)cVar3;
  if ((((iVar8 < 0) || (0x14 < iVar8)) || (iVar9 < 0)) || (0x14 < iVar9)) {
    uVar11 = 0;
  }
  else {
    for (cVar2 = cVar2 + -2; iVar6 = (int)cVar2, iVar6 <= iVar8 + 2; cVar2 = cVar2 + '\x01') {
      for (cVar1 = cVar3 + -2; iVar7 = (int)cVar1, iVar7 <= iVar9 + 2; cVar1 = cVar1 + '\x01') {
        if (((-1 < iVar6) && (iVar6 < 0x15)) && ((-1 < iVar7 && (iVar7 < 0x15)))) {
          uVar11 = (int)*(char *)(iVar6 * 0x15 + DAT_000147d8 + iVar7) | uVar11;
        }
      }
    }
  }
  return uVar11;
}


/* ===== FUN_000147dc @ 000147dc ===== */

void FUN_000147dc(void)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar1 = 0; uVar1 < 0x15; uVar1 = uVar1 + 1 & 0xffff) {
    for (uVar2 = 0; uVar2 < 0x15; uVar2 = uVar2 + 1 & 0xffff) {
      *(undefined *)(uVar1 * 0x15 + DAT_00014808 + uVar2) = 0;
    }
  }
  return;
}


/* ===== FUN_0001480c @ 0001480c ===== */

void FUN_0001480c(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  if (*DAT_000148e4 == '\0') {
    uVar5 = 10;
  }
  else {
    uVar5 = 0;
  }
  for (uVar4 = 0; uVar4 < 4; uVar4 = uVar4 + 1 & 0xffff) {
    if (((*(char *)(param_1 + uVar4 * 0x84 + 0x1a) == '\x02') &&
        (0x8b < *(int *)(param_1 + uVar4 * 0x84 + 0x14))) &&
       (*(char *)(param_1 + uVar4 * 0x84 + 0x80) == '\0')) {
      uVar2 = FUN_00008fd2(10);
      uVar3 = FUN_00008c2e(*(undefined4 *)(param_1 + uVar4 * 0x84 + 0x70),0x3f000000);
      FUN_00008b1a(uVar3,uVar2);
      cVar1 = FUN_0000902a();
      iVar6 = (int)cVar1;
      uVar2 = FUN_00008fd2(uVar5);
      uVar3 = FUN_00008c2e(*(undefined4 *)(param_1 + uVar4 * 0x84 + 0x74),0x3f000000);
      FUN_00008b1a(uVar3,uVar2);
      cVar1 = FUN_0000902a();
      iVar7 = (int)cVar1;
      if (((-1 < iVar6) && (iVar6 < 0x15)) && ((-1 < iVar7 && (iVar7 < 0x15)))) {
        *(undefined *)(iVar6 * 0x15 + DAT_000148e8 + iVar7) = 1;
      }
    }
  }
  return;
}


/* ===== FUN_000148ec @ 000148ec ===== */

void FUN_000148ec(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = DAT_00014978;
  if (param_1 == 1) {
    uVar3 = *(uint *)(DAT_00014978 + 0x218) | 0x80;
  }
  else {
    uVar3 = *(uint *)(DAT_00014978 + 0x218) & 0xffffff7f;
  }
  *(uint *)(DAT_00014978 + 0x218) =
       uVar3 & 0xffffff9f | ((uint)(*(int *)(DAT_00014978 + 0x218) << 0x16) >> 0x1e) << 5;
  iVar2 = DAT_00014978;
  uVar3 = *(uint *)(iVar1 + 0x21c);
  if (param_2 == 1) {
    uVar3 = uVar3 | 0x80;
  }
  else {
    uVar3 = uVar3 & 0xffffff7f;
  }
  *(uint *)(DAT_00014978 + 0x21c) =
       uVar3 & 0xffffff9f | ((uint)(*(int *)(iVar1 + 0x21c) << 0x16) >> 0x1e) << 5;
  *(uint *)(DAT_00014978 + 0x1a0) =
       (*(uint *)(iVar2 + 0x1a0) & 0xfffff8ff | param_3 << 8) & 0xffff8fff | param_4 << 0xc;
  return;
}


/* ===== FUN_000149d8 @ 000149d8 ===== */

void FUN_000149d8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    FUN_00008bca(param_2,DAT_00014a0c);
  }
  else {
    FUN_00008bca(param_2,DAT_00014a08);
  }
  uVar1 = FUN_0000905c();
  param_1[2] = uVar1;
  *param_1 = 9;
  return;
}


/* ===== FUN_00014a10 @ 00014a10 ===== */

void FUN_00014a10(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


/* ===== FUN_00014a1c @ 00014a1c ===== */

void FUN_00014a1c(void)

{
  int iVar1;
  
  *DAT_00014a44 = 0;
  *DAT_00014a48 = 0;
  FUN_00008ae8(DAT_00014a4c,0x80);
  iVar1 = DAT_00014a50;
  *(undefined **)(DAT_00014a50 + 0x2ac) = &DAT_40004000;
  *(undefined4 *)(iVar1 + 0x2a8) = DAT_00014a54;
  return;
}


/* ===== FUN_00014a58 @ 00014a58 ===== */

void FUN_00014a58(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  while( true ) {
    do {
      if (*DAT_00014bb0 == *DAT_00014bb8) {
        FUN_00008ab6(param_1,&local_30,0x20);
        return;
      }
      iVar2 = FUN_0000ac0c(DAT_00014bb4,*(undefined *)(DAT_00014bac + *DAT_00014bb0));
      puVar1 = DAT_00014bb0;
      *DAT_00014bb0 = *DAT_00014bb0 + 1;
      *puVar1 = *(byte *)puVar1 & 0x7f;
    } while (iVar2 != 0);
    if (*(ushort *)(DAT_00014bb4 + 0x98) - 0x201 < 7) break;
    local_30 = CONCAT22(*(undefined2 *)(DAT_00014bb4 + 0x12),*(short *)(DAT_00014bb4 + 0x98));
    if (*(short *)(DAT_00014bb4 + 0x98) != 0) {
      FUN_00012a68(local_30,local_2c,local_28,uStack_24,local_20,uStack_1c,uStack_18,uStack_14);
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00014a9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&switchD_00014a9a::switchdataD_00014a9e +
            (uint)*(byte *)(*(ushort *)(DAT_00014bb4 + 0x98) + 0x1489d) * 2))();
  return;
}


/* ===== FUN_00014bbc @ 00014bbc ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014bbc(void)

{
  if (*(ushort *)(_DAT_00014be8 + 0xe) < 100) {
    *(short *)(_DAT_00014be8 + 0xe) = *(short *)(_DAT_00014be8 + 0xe) + 1;
  }
  else if (*(char *)(_DAT_00014be8 + 0xc) != '\0') {
    FUN_0000b016(_DAT_00014be8);
    FUN_0000b360("[TF] Parser timeout\n");
  }
  return;
}


/* ===== FUN_00014c10 @ 00014c10 ===== */

void FUN_00014c10(undefined4 param_1,undefined4 param_2,undefined2 param_3)

{
  FUN_0000b1f2(DAT_00014c30,param_1,param_2,param_3);
  return;
}


/* ===== FUN_00014c48 @ 00014c48 ===== */

void FUN_00014c48(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    uVar1 = *DAT_00014c64 | 8;
  }
  else {
    uVar1 = *DAT_00014c64 & 0xfffffff7;
  }
  *DAT_00014c64 = uVar1;
  return;
}


/* ===== FUN_00014c68 @ 00014c68 ===== */

void FUN_00014c68(int param_1)

{
  if (param_1 == 0) {
    *DAT_00014c88 = *DAT_00014c88 & 0xfffeffff;
  }
  else {
    *DAT_00014c88 = *DAT_00014c88 | 0x10000;
  }
  return;
}


/* ===== FUN_00014c8c @ 00014c8c ===== */

void FUN_00014c8c(uint param_1,int param_2)

{
  *(uint *)(DAT_00014cb0 + 0x114) = *DAT_00014cac & 0xffffff00 | param_2 << 4 | param_1;
  return;
}


/* ===== FUN_00014cb4 @ 00014cb4 ===== */

void FUN_00014cb4(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = *DAT_00014ce0 | 1;
  }
  else {
    uVar1 = *DAT_00014ce0 & 0xfffffffe;
  }
  if (param_2 == 1) {
    uVar1 = uVar1 | 2;
  }
  else {
    uVar1 = uVar1 & 0xfffffffd;
  }
  *DAT_00014ce0 = uVar1;
  return;
}


/* ===== FUN_00014d58 @ 00014d58 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014d58(undefined *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((param_1 != &DAT_40004000) && (param_1 != DAT_00014dd0)) && (param_1 != _DAT_00014dd4)) {
    FUN_0000ca9c("..\\..\\..\\lib\\adt6101P_hardwarelib\\adt6101P_uart\\adt6101P_uart.c",0x53);
  }
  iVar1 = DAT_00014e18;
  if (param_1 == &DAT_40004000) {
    *(undefined4 *)(DAT_00014e18 + 0x30) = 1;
    *(undefined4 *)(iVar1 + 0x34) = 0x81;
  }
  else if (param_1 == DAT_00014dd0) {
    *(undefined4 *)(DAT_00014e18 + 0x58) = 1;
    *(undefined4 *)(iVar1 + 0x5c) = 0x81;
  }
  else {
    *(undefined4 *)(DAT_00014e18 + 0x80) = 1;
    *(undefined4 *)(DAT_00014e18 + 0x84) = 0x81;
  }
  uVar2 = DAT_00014e20;
  if (param_3 != 0) {
    uVar2 = DAT_00014e1c;
  }
  *(uint *)(param_1 + 0x10) = uVar2 / param_2;
  *(undefined4 *)(param_1 + 8) = 0xb;
  return;
}


/* ===== FUN_00014e26 @ 00014e26 ===== */

void FUN_00014e26(int param_1,uint *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  undefined4 *puVar5;
  
  bVar4 = 0;
  for (uVar3 = 0; uVar3 < 4; uVar3 = uVar3 + 1 & 0xff) {
    puVar5 = (undefined4 *)(param_1 + uVar3 * 0x84);
    iVar2 = FUN_0000dc58(*puVar5,puVar5[1],puVar5[2],puVar5[3],
                         *(undefined4 *)(param_1 + uVar3 * 0x84 + 0x10));
    if (iVar2 == 0) {
      bVar4 = bVar4 | *(byte *)(param_1 + uVar3 * 0x84 + 0x18);
    }
    *(undefined *)(param_1 + uVar3 * 0x84 + 0x18) = 0;
    *(undefined *)(param_1 + uVar3 * 0x84 + 0x19) = 0;
  }
  uVar3 = 0;
  do {
    if (3 < uVar3) {
      if (bVar4 == 1) {
        *param_2 = 0;
      }
      else {
        iVar2 = FUN_000106f0();
        if ((iVar2 == 1) && (*param_2 < 200)) {
          *param_2 = *param_2 + 1;
        }
      }
      return;
    }
    iVar2 = FUN_000106a8();
    if (iVar2 == 0) {
      if ((*(char *)(param_1 + uVar3 * 0x84 + 0x1a) == '\x02') && (bVar4 == 1)) {
        puVar5 = (undefined4 *)(param_1 + uVar3 * 0x84);
        iVar2 = FUN_0000dc58(*puVar5,puVar5[1],puVar5[2],puVar5[3],
                             *(undefined4 *)(param_1 + uVar3 * 0x84 + 0x10));
        if (iVar2 != 0) goto LAB_00014ee0;
        if (*(int *)(param_1 + uVar3 * 0x84 + 0x14) < 1) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + uVar3 * 0x84 + 0x14) + -1;
        }
        *(int *)(param_1 + uVar3 * 0x84 + 0x14) = iVar2;
      }
      else {
LAB_00014ee0:
        if (*(int *)(param_1 + uVar3 * 0x84 + 0x14) < 1) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(param_1 + uVar3 * 0x84 + 0x14) + -2;
        }
        *(int *)(param_1 + uVar3 * 0x84 + 0x14) = iVar2;
      }
      if (*(short *)(param_1 + uVar3 * 0x84 + 0x1c) == 0) {
        sVar1 = 0;
      }
      else {
        sVar1 = *(short *)(param_1 + uVar3 * 0x84 + 0x1c) + -1;
      }
      *(short *)(param_1 + uVar3 * 0x84 + 0x1c) = sVar1;
    }
    if (*(int *)(param_1 + uVar3 * 0x84 + 0x14) < 1) {
      *(undefined *)(param_1 + uVar3 * 0x84 + 0x1a) = 0;
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while( true );
}


/* ===== FUN_00014f74 @ 00014f74 ===== */

void FUN_00014f74(int param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 uStack_20;
  undefined4 local_1c;
  
  uVar3 = DAT_00015070;
  *(undefined4 *)(param_1 + 0x20) = *param_2;
  *(undefined4 *)(param_1 + 0x24) = param_2[1];
  uVar2 = FUN_00008bbe(*param_2,*(undefined4 *)(param_1 + 0x70));
  uVar2 = FUN_00008c2e(uVar2,uVar3);
  *(undefined4 *)(param_1 + 0x28) = uVar2;
  uVar2 = FUN_00008bbe(param_2[1],*(undefined4 *)(param_1 + 0x74));
  uVar3 = FUN_00008c2e(uVar2,uVar3);
  *(undefined4 *)(param_1 + 0x2c) = uVar3;
  *(undefined4 *)(param_1 + 8) = param_2[2];
  *(undefined4 *)(param_1 + 0xc) = param_2[3];
  *(undefined *)(param_1 + 0x18) = 1;
  if (*(char *)(param_1 + 0x1a) == '\x01') {
    if (*(int *)(param_1 + 0x14) < 0x32) {
      iVar4 = *(int *)(param_1 + 0x14) + 10;
    }
    else {
      iVar4 = 0x32;
    }
    *(int *)(param_1 + 0x14) = iVar4;
    *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + 2;
    iVar4 = FUN_00010a44();
    if (iVar4 == 0) {
      if (param_3 == 1) {
        uVar6 = 2;
      }
      else {
        bVar1 = FUN_00010850();
        uVar6 = (ushort)bVar1;
      }
      if (uVar6 <= *(ushort *)(param_1 + 0x1c)) {
        *(undefined *)(param_1 + 0x1a) = 2;
        *(undefined4 *)(param_1 + 0x14) = 200;
      }
    }
    else if (5 < *(ushort *)(param_1 + 0x1c)) {
      *(undefined *)(param_1 + 0x1a) = 2;
      *(undefined4 *)(param_1 + 0x14) = 0x3c;
    }
  }
  else if (*(char *)(param_1 + 0x1a) == '\x02') {
    iVar4 = FUN_0000e270(*(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0x74),
                         *(undefined4 *)(param_1 + 8),uStack_20,local_1c);
    if (iVar4 == 1) {
      uVar5 = FUN_00010a2c();
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 0x28;
      if (*(uint *)(param_1 + 0x14) < uVar5) {
        uVar5 = *(uint *)(param_1 + 0x14);
      }
      *(uint *)(param_1 + 0x14) = uVar5;
    }
    else {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 0x28;
      if (*(int *)(param_1 + 0x14) < 200) {
        uVar3 = *(undefined4 *)(param_1 + 0x14);
      }
      else {
        uVar3 = 200;
      }
      *(undefined4 *)(param_1 + 0x14) = uVar3;
    }
  }
  FUN_0000a17c(param_1 + 0x20,1);
  return;
}


/* ===== FUN_00015074 @ 00015074 ===== */

void FUN_00015074(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    FUN_0000e864(param_1,param_3 + iVar1 * 4,param_4 + iVar1 * param_1 * 4,param_5,param_6);
  }
  *(uint *)(DAT_000150b8 + 8) = *(uint *)(DAT_000150b8 + 8) & 0xfffffbff;
  return;
}


/* ===== FUN_000150bc @ 000150bc ===== */

undefined4 FUN_000150bc(void)

{
  undefined4 uVar1;
  
  *(uint *)(DAT_00015130 + 0x18c) = *DAT_0001512c | 0x2300000;
  FUN_00010b4c(10);
  FUN_0000d4bc(0x3c,0);
  FUN_0000d4bc(0x3c,0);
  FUN_0000d4bc(0x3c,0);
  uVar1 = FUN_00008fd2((DAT_0001512c[-0x2e] & 0xff) - *DAT_00015134);
  *DAT_0001512c = *(uint *)(DAT_00015130 + 0x18c) & 0xfffff;
  return uVar1;
}


/* ===== FUN_00015138 @ 00015138 ===== */

void FUN_00015138(void)

{
  FUN_00015178(DAT_00015150);
  *(undefined4 *)(DAT_00015154 + 8) = 0;
  FUN_00015178(0xffffffff);
  return;
}


/* ===== FUN_00015158 @ 00015158 ===== */

void FUN_00015158(undefined4 param_1)

{
  *DAT_00015160 = param_1;
  return;
}


/* ===== FUN_00015164 @ 00015164 ===== */

void FUN_00015164(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00015174;
  DAT_00015174[3] = 1;
  *puVar1 = param_1;
  puVar1[2] = 3;
  return;
}


/* ===== FUN_00015178 @ 00015178 ===== */

void FUN_00015178(undefined4 param_1)

{
  *DAT_00015180 = param_1;
  return;
}


/* ===== FUN_00015184 @ 00015184 ===== */

/* WARNING: Removing unreachable block (ram,0x000151a6) */

void FUN_00015184(void)

{
  if (*DAT_000151b8 != '\0') {
    *DAT_000151b8 = '\0';
    FUN_00013d84(DAT_000151bc,0);
    FUN_000099b4(DAT_000151c0,0x14000,0x184);
  }
  return;
}

