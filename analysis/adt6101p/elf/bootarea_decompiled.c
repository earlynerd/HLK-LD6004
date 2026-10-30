
/* ===== entry @ 00008000 ===== */

void processEntry entry(undefined *param_1)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 *puVar3;
  
  *param_1 = (char)param_1;
  FUN_000080bc(0);
  FUN_00008128();
  iVar1 = DAT_000080e8;
  puVar3 = (undefined4 *)((int)&DAT_000080e8 + DAT_000080e8);
  iVar2 = DAT_000080e8 + 32999;
  if (puVar3 == (undefined4 *)((int)&DAT_000080e8 + DAT_000080ec)) {
    FUN_00008128();
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&UNK_000080f4 + iVar1);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE = (code *)(iVar2 - (int)UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x000080e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*puVar3,*(undefined4 *)((int)&DAT_000080ec + iVar1),
             *(undefined4 *)(&UNK_000080f0 + iVar1));
  return;
}


/* ===== FUN_000080bc @ 000080bc ===== */

void FUN_000080bc(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = DAT_000080e8;
  puVar3 = (undefined4 *)((int)&DAT_000080e8 + DAT_000080e8);
  iVar2 = DAT_000080e8 + 32999;
  if (puVar3 == (undefined4 *)((int)&DAT_000080e8 + DAT_000080ec)) {
    FUN_00008128();
  }
  UNRECOVERED_JUMPTABLE = *(code **)(&UNK_000080f4 + iVar1);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE = (code *)(iVar2 - (int)UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x000080e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*puVar3,*(undefined4 *)((int)&DAT_000080ec + iVar1),
             *(undefined4 *)(&UNK_000080f0 + iVar1));
  return;
}


/* ===== FUN_0000810a @ 0000810a ===== */

undefined4 FUN_0000810a(uint *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((param_2 != 100) && (param_2 != 0x75)) {
    if (param_2 != 0x78) {
      return 0;
    }
    uVar1 = *param_3;
    if ((int)((uint)*(ushort *)param_1 << 0x14) < 0) {
      puVar4 = (undefined *)(DAT_0000a124 + 0xa0ea);
    }
    else {
      puVar4 = (undefined *)(DAT_0000a124 + 0xa0fe);
    }
    iVar3 = 0;
    for (; uVar1 != 0; uVar1 = uVar1 >> 4) {
      *(undefined *)((int)param_1 + iVar3 + 0x24) = puVar4[uVar1 & 0xf];
      iVar3 = iVar3 + 1;
    }
    iVar5 = 0;
    if (((int)((uint)*(byte *)param_1 << 0x1c) < 0) && (iVar3 != 0)) {
      iVar5 = 2;
      puVar4 = puVar4 + 0x11;
    }
    goto LAB_0000a396;
  }
  iVar5 = 0;
  uVar1 = *param_3;
  puVar4 = &UNK_0000a0c0;
  if (param_2 != 0x75) {
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
      puVar4 = &UNK_0000a0c4;
    }
    else if ((int)(*param_1 << 0x1e) < 0) {
      puVar4 = &UNK_0000a0c8;
    }
    else {
      if (-1 < (int)(*param_1 << 0x1d)) goto LAB_0000a090;
      puVar4 = &UNK_0000a0cc;
    }
    iVar5 = 1;
  }
LAB_0000a090:
  iVar3 = 0;
  for (; uVar1 != 0; uVar1 = uVar1 / 10) {
    *(byte *)((int)param_1 + iVar3 + 0x24) = (char)uVar1 + (char)(uVar1 / 10) * -10 + 0x30;
    iVar3 = iVar3 + 1;
  }
LAB_0000a396:
  if ((int)(*param_1 << 0x1a) < 0) {
    uVar1 = param_1[7];
    *param_1 = *param_1 & 0xffffffef;
  }
  else {
    uVar1 = 1;
  }
  if (iVar3 < (int)uVar1) {
    iVar7 = uVar1 - iVar3;
  }
  else {
    iVar7 = 0;
  }
  param_1[6] = param_1[6] - (iVar7 + iVar3 + iVar5);
  if (-1 < (int)((uint)*(byte *)param_1 << 0x1b)) {
    FUN_0000a008(param_1);
  }
  for (iVar6 = 0; iVar6 < iVar5; iVar6 = iVar6 + 1) {
    (*(code *)param_1[1])(puVar4[iVar6],param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  if ((int)((uint)*(byte *)param_1 << 0x1b) < 0) {
    FUN_0000a008(param_1);
  }
  while (0 < iVar7) {
    (*(code *)param_1[1])(0x30,param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar7 = iVar7 + -1;
  }
  while (0 < iVar3) {
    (*(code *)param_1[1])(*(byte *)((int)param_1 + iVar3 + 0x23),param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar3 = iVar3 + -1;
  }
  FUN_0000a034(param_1);
  if ((int)((uint)*(byte *)param_1 << 0x18) < 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* ===== FUN_00008120 @ 00008120 ===== */

undefined8 FUN_00008120(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}


/* ===== FUN_00008124 @ 00008124 ===== */

void FUN_00008124(void)

{
  return;
}


/* ===== FUN_00008128 @ 00008128 ===== */

void FUN_00008128(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar3;
  
  uVar2 = FUN_0000a558();
  FUN_00008120(uVar2,param_3);
  FUN_00008190();
  uVar3 = FUN_0000a5a2();
  FUN_00008124();
  UNRECOVERED_JUMPTABLE = (code *)0x8146;
  uVar2 = FUN_000091e4((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x0000814c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


/* ===== FUN_0000813a @ 0000813a ===== */

void FUN_0000813a(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  FUN_00008124();
  UNRECOVERED_JUMPTABLE = (code *)0x8146;
  uVar2 = FUN_000091e4(param_1,param_2);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(uVar2);
  }
                    /* WARNING: Could not recover jumptable at 0x0000814c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2);
  return;
}


/* ===== FUN_0000814e @ 0000814e ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000814e(void)

{
                    /* WARNING: Could not recover jumptable at 0x00008158. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*entry)();
  return;
}


/* ===== FUN_0000815c @ 0000815c ===== */

void FUN_0000815c(void)

{
  FUN_000093ac();
  *DAT_000081f8 = 0xb0;
  FUN_00009202(0x1c200,DAT_000081fc);
  FUN_00009b34();
  FUN_00009c4a();
  return;
}


/* ===== FUN_0000817c @ 0000817c ===== */

void FUN_0000817c(void)

{
  FUN_00009a9e(8,1);
  FUN_00009a9e(3,1);
  return;
}


/* ===== FUN_00008190 @ 00008190 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008190(void)

{
  int iVar1;
  
  FUN_00009ff0(_DAT_00008200);
  FUN_00009a7a(0x20000000);
  enableIRQinterrupts();
  FUN_0000817c();
  FUN_0000815c();
  FUN_00008ab2();
  FUN_00009ff0("\r\n*********************************************************\r\n");
  FUN_00009ff0("\r\n**************Location: boot area!***********************\r\n");
  FUN_00009ff0("\r\n**************Version: v2.0.7****************************\r\n");
  FUN_00009ff0("\r\n*********************************************************\r\n");
  FUN_000082e8(DAT_000082c4);
  FUN_00008322(DAT_000082c4,DAT_000082c8);
  do {
    FUN_000092a0(0x43);
    FUN_00008924(0x3c);
    for (iVar1 = 0; iVar1 < DAT_000082cc; iVar1 = iVar1 + 1) {
      FUN_00008e8c(DAT_000082c4);
    }
  } while( true );
}


/* ===== FUN_000082d0 @ 000082d0 ===== */

void FUN_000082d0(undefined *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00009950(0x1c);
  if (iVar1 == 0) {
    *param_1 = 2;
    FUN_00009ff0("\r\n[Boot Area] Enter the appx update mode\r\n");
  }
  return;
}


/* ===== FUN_000082e8 @ 000082e8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000082e8(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_3;
  uStack_10 = param_4;
  FUN_00009c9a(&uStack_14,0x10000,8,param_4,param_2);
  *param_1 = uStack_14._1_1_;
  param_1[1] = uStack_14._3_1_;
  param_1[2] = uStack_10._1_1_;
  param_1[3] = uStack_10._3_1_;
  FUN_00009ff0(_DAT_000085d0,*param_1,param_1[1],param_1[2],param_1[3]);
  return;
}


/* ===== FUN_00008322 @ 00008322 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008322(char *param_1,code *param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined uVar6;
  code *local_30;
  undefined4 local_2c;
  uint local_28;
  
  cVar3 = param_1[1];
  cVar1 = param_1[2];
  bVar2 = param_1[3];
  local_28 = (uint)bVar2;
  local_30 = param_2;
  local_2c = param_3;
  if (bVar2 == 2) {
    FUN_00009a9e(0,1);
    FUN_00009ff0("\r\n[Boot Area] go to factory mode.\r\n");
    disableIRQinterrupts();
    *DAT_000085f8 = 0xffffffff;
    (*param_2)(5);
    local_28 = 0xff;
    FUN_000087bc(&local_28,DAT_000085fc,1);
    FUN_00009ae0(0x8000);
  }
  else if (bVar2 == 0xff) {
    if (*param_1 == -0x56) {
      bVar4 = false;
      uVar6 = 0;
      if (cVar1 == '\x04') {
        uVar6 = 0xff;
        FUN_00009ff0("\r\n[Boot Area] Checking APP2 integrity before loading...\r\n");
        iVar5 = FUN_00008a42(0x28000);
        if (iVar5 != 0) {
          FUN_00009ff0("\r\n[Boot Area] APP2 integrity check passed, loading APP2.\r\n");
          disableIRQinterrupts();
          *DAT_000085f8 = 0xffffffff;
          (*param_2)(4);
          FUN_00009ae0(0x8000);
        }
        else {
          FUN_00009ff0(_DAT_00008734);
        }
        bVar4 = iVar5 == 0;
      }
      else if (cVar1 == -1) {
        uVar6 = 4;
        FUN_00009ff0("\r\n[Boot Area] Checking APP1 integrity before loading...\r\n");
        iVar5 = FUN_00008a42(0x18000);
        if (iVar5 != 0) {
          FUN_00009ff0("\r\n[Boot Area] APP1 integrity check passed, loading APP1.\r\n");
          disableIRQinterrupts();
          *DAT_000085f8 = 0xffffffff;
          (*param_2)(0xff);
          FUN_00009ae0(0x8000);
        }
        else {
          FUN_00009ff0(_DAT_000086b8);
        }
        bVar4 = iVar5 == 0;
      }
      if (bVar4) {
        local_30 = (code *)CONCAT13(uVar6,0xff02ff);
        FUN_000087bc(&local_30,0x10000,6);
        FUN_00009ff0(DAT_00008774);
        FUN_00009ab6(DAT_00008778);
        FUN_00009a86();
      }
    }
    else {
      FUN_00009a9e(0,1);
      FUN_00009ff0("uart rx in open\r\n");
      local_2c = 0xaa;
      FUN_000087bc(&local_2c,0x10001,1);
      if (cVar3 == '\x04') {
        FUN_00009ff0("\r\n[Boot Ready to upgrade App2.\r\n");
        *(undefined4 *)(param_1 + 4) = 0x18000;
        *(undefined4 *)(param_1 + 8) = 0x8000;
      }
      else if (cVar3 == -1) {
        FUN_00009ff0("\r\n[Boot Area] Ready to upgrade App1.\r\n");
        *(undefined4 *)(param_1 + 4) = 0x28000;
        *(undefined4 *)(param_1 + 8) = 0x8000;
      }
      else {
        FUN_00009ff0("\r\n[Boot Area] No Update.\r\n");
      }
      FUN_00009ff0("\r\n");
    }
  }
  return;
}


/* ===== FUN_000084c6 @ 000084c6 ===== */

void FUN_000084c6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = CONCAT31((int3)((uint)param_3 >> 8),0xff);
  uVar1 = local_20;
  local_20._0_2_ = (undefined2)uVar1;
  local_20._0_3_ = CONCAT12(0xff,(undefined2)local_20);
  local_1c = CONCAT31((int3)((uint)param_4 >> 8),0xff);
  if (*(char *)(param_1 + 1) == '\x04') {
    FUN_00009ff0("\r\n[Boot Area] Setting App1.\r\n");
    local_20._0_2_ = CONCAT11(0xaa,(undefined)local_20);
    local_20 = CONCAT13(0xff,(undefined3)local_20);
    local_1c._0_2_ = CONCAT11(0xff,(undefined)local_1c);
  }
  else if (*(char *)(param_1 + 1) == -1) {
    FUN_00009ff0("\r\n[Boot Area] Setting App2.\r\n");
    local_20._0_2_ = CONCAT11(0xaa,(undefined)local_20);
    local_20 = CONCAT13(4,(undefined3)local_20);
    local_1c._0_2_ = CONCAT11(4,(undefined)local_1c);
  }
  else {
    FUN_0000a33a(&local_20,6,0xff);
    FUN_00009ff0("\r\n[Boot Area] No Update.\r\n");
  }
  FUN_000087bc(&local_20,0x10000,6);
  return;
}


/* ===== FUN_0000853c @ 0000853c ===== */

void FUN_0000853c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (*(char *)(param_1 + 1) == '\x04') {
    FUN_00009ff0("\r\n[Boot Area] Setting App2.\r\n");
    uStack_20._0_2_ = CONCAT11(0xaa,(undefined)uStack_20);
    uStack_20 = CONCAT13(4,(undefined3)uStack_20);
    uStack_1c._0_2_ = CONCAT11(4,(undefined)uStack_1c);
  }
  else if (*(char *)(param_1 + 1) == -1) {
    FUN_00009ff0("\r\n[Boot Area] Setting App1.\r\n");
    uStack_20._0_2_ = CONCAT11(0xaa,(undefined)uStack_20);
    uStack_20 = CONCAT13(0xff,(undefined3)uStack_20);
    uStack_1c._0_2_ = CONCAT11(0xff,(undefined)uStack_1c);
  }
  else {
    FUN_0000a33a(&uStack_20,6,0xff);
    FUN_00009ff0("\r\n[Boot Area] No Update.\r\n");
  }
  FUN_000087bc(&uStack_20,0x10000,6);
  return;
}


/* ===== FUN_000087bc @ 000087bc ===== */

void FUN_000087bc(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = DAT_000088bc;
  FUN_0000a34a(DAT_000088bc,0x1000);
  uVar4 = param_2 >> 0xc;
  uVar5 = param_2 & 0xfff;
  uVar2 = 0x1000 - uVar5;
  if (param_3 <= uVar2) {
    uVar2 = param_3 & 0xffff;
  }
  while( true ) {
    FUN_00009c9a(iVar1,uVar4 << 0xc,0x1000);
    for (uVar3 = 0; ((int)uVar3 < (int)uVar2 && (*(char *)(iVar1 + uVar5 + uVar3) == -1));
        uVar3 = uVar3 + 1 & 0xffff) {
    }
    if ((int)uVar3 < (int)uVar2) {
      FUN_00009d28(uVar4);
      for (uVar3 = 0; (int)uVar3 < (int)uVar2; uVar3 = uVar3 + 1 & 0xffff) {
        *(undefined *)(iVar1 + uVar3 + uVar5) = *(undefined *)(param_1 + uVar3);
      }
      FUN_00009dee(iVar1,uVar4 << 0xc,0x1000);
    }
    else {
      FUN_00009dee(param_1,param_2,uVar2);
    }
    if (param_3 == uVar2) break;
    uVar4 = uVar4 + 1;
    uVar5 = 0;
    param_1 = param_1 + uVar2;
    param_2 = param_2 + uVar2;
    param_3 = param_3 - uVar2;
    if (param_3 < 0x1001) {
      uVar2 = param_3 & 0xffff;
    }
    else {
      uVar2 = 0x1000;
    }
  }
  return;
}


/* ===== FUN_00008878 @ 00008878 ===== */

void FUN_00008878(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if (param_3 <= uVar1) {
    uVar1 = param_3 & 0xffff;
  }
  while (FUN_00009c9a(param_1,param_2,uVar1), param_3 != uVar1) {
    param_1 = param_1 + uVar1;
    param_2 = param_2 + uVar1;
    param_3 = param_3 - uVar1;
    if (param_3 < 0x101) {
      uVar1 = param_3 & 0xffff;
    }
    else {
      uVar1 = 0x100;
    }
  }
  return;
}


/* ===== FUN_00008924 @ 00008924 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008924(int param_1)

{
  if (*DAT_00008c70 == '\x01') {
    FUN_00009ec4(DAT_00008c74);
    *DAT_00008c70 = '\0';
  }
  *_DAT_00008c78 = 1;
  if (*DAT_00008c6c == param_1) {
    FUN_00009ff0("\r\nUnreceived data timeout!\r\n");
    FUN_00009ff0("\r\nReady to go back to the App\r\n");
    FUN_00009eea(DAT_00008c74);
    *DAT_00008cbc = 0xffffffff;
    disableIRQinterrupts();
    FUN_00009ab6(DAT_00008cc0);
    FUN_00009a86();
  }
  return;
}


/* ===== FUN_00008972 @ 00008972 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008972(void)

{
  FUN_00009eea(DAT_00008c74);
  *DAT_00008c70 = 1;
  *DAT_00008c6c = 0;
  *_DAT_00008c78 = 0;
  return;
}


/* ===== FUN_0000898c @ 0000898c ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0000898c(undefined2 *param_1,undefined4 param_2)

{
  undefined2 local_1c;
  undefined2 local_1a;
  undefined local_18;
  uint3 local_17;
  undefined local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  byte local_10;
  
  FUN_00009c9a(&local_1c,param_2,0x10);
  *param_1 = local_1c;
  param_1[1] = local_1a;
  *(undefined *)(param_1 + 2) = local_18;
  *(uint *)(param_1 + 4) = (uint)local_17;
  *(undefined *)(param_1 + 6) = local_14;
  *(uint *)(param_1 + 8) =
       (uint)local_13 << 0x18 | (uint)local_12 << 0x10 | (uint)local_11 << 8 | (uint)local_10;
  FUN_00009ff0(_DAT_00008cc4,*param_1,param_1[1],*(undefined *)(param_1 + 2),
               *(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
  return;
}


/* ===== FUN_00008a12 @ 00008a12 ===== */

bool FUN_00008a12(undefined2 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = FUN_000099f4(param_2 + 0x10,*param_1);
  FUN_00009ff0("\r\n[CRC32] Stored: 0x%08lX, Calculated: 0x%08lX\r\n",iVar2,iVar1);
  return iVar2 == iVar1;
}


/* ===== FUN_00008a42 @ 00008a42 ===== */

undefined4 FUN_00008a42(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  short local_1c;
  short local_1a;
  char local_18;
  int local_c;
  
  FUN_0000898c(&local_1c,param_1);
  if (local_18 == 'Z') {
    if ((local_1c == local_1a) && (local_1c != 0)) {
      if (local_c == 0) {
        FUN_00009ff0("\n\n\r NO CRC check of the bin file! \n\r");
        uVar1 = 1;
      }
      else {
        iVar2 = FUN_00008a12(&local_1c,param_1);
        if (iVar2 == 0) {
          uVar1 = 0;
        }
        else {
          FUN_00009ff0("\r\n[CRC32] Integrity check passed.\r\n");
          uVar1 = 1;
        }
      }
    }
    else {
      FUN_00009ff0("\r\n[CRC32] Length mismatch: %u vs %u\r\n",local_1c,local_1a);
      uVar1 = 0;
    }
  }
  else {
    FUN_00009ff0("\r\n[CRC32] Invalid code flag: 0x%02X\r\n",local_18);
    uVar1 = 0;
  }
  return uVar1;
}


/* ===== FUN_00008ab2 @ 00008ab2 ===== */

void FUN_00008ab2(void)

{
  FUN_0000a33a(DAT_00008c64,0x85,0xff);
  FUN_0000a33a(DAT_00008d98,0x10000,0xff);
  FUN_0000a33a(DAT_00008d9c,0x10000,0xff);
  return;
}


/* ===== FUN_00008ad8 @ 00008ad8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008ad8(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 4);
  FUN_000087bc(DAT_00008d9c,uVar1,*_DAT_00008da0 << 7);
  FUN_00009ff0("\r\n[Download] Write flash done.\r\n");
  FUN_000084c6(param_1);
  FUN_00009ff0("\r\n[Boot Area] Boot setting area is set.\r\n");
  FUN_0000a33a(DAT_00008d98,0x10000,0xff);
  FUN_00008878(DAT_00008d98,uVar1,*_DAT_00008da0 << 7);
  return;
}


/* ===== FUN_00008b1c @ 00008b1c ===== */

bool FUN_00008b1c(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = *DAT_00008c64;
  if (cVar1 == '\x04') {
    FUN_000092a0(6);
    FUN_00008972();
    FUN_00009ff0("\r\n[Download] User bin received from uart correctly.\r\n");
    FUN_00009ff0("\r\n[Download] Write flash start. \r\n");
    FUN_00009ff0("\r\n");
    FUN_00008ad8(param_1);
  }
  return cVar1 == '\x04';
}


/* ===== FUN_00008b54 @ 00008b54 ===== */

undefined4 FUN_00008b54(int param_1,char *param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    cVar1 = '\0';
    for (; param_3 != 0; param_3 = param_3 + -1) {
      cVar1 = *param_2 + cVar1;
      param_2 = param_2 + 1;
    }
    if (*param_2 == cVar1) {
      return 1;
    }
  }
  else {
    uVar2 = FUN_00009970(param_2,param_3);
    if (uVar2 == ((uint)(byte)param_2[param_3 + 1] + (uint)(byte)param_2[param_3] * 0x100 & 0xffff))
    {
      return 1;
    }
  }
  return 0;
}


/* ===== FUN_00008ba8 @ 00008ba8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00008ba8(undefined4 param_1)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  
  piVar2 = _DAT_00009064;
  if (*DAT_00008c64 == '\x01') {
    cVar3 = FUN_00008b54(1,DAT_00008c64 + 3,0x80);
    if (((DAT_00008c64[1] == ~DAT_00008c64[2]) && (DAT_00008c64[1] == *DAT_00008e50)) &&
       (cVar3 == '\x01')) {
      if (*_DAT_00008da0 * 0x80 + 0x80U < 0x10000) {
        FUN_0000a2b0(DAT_00008d9c + *_DAT_00008da0 * 0x80,DAT_00008c64 + 3,0x80);
      }
      FUN_000092a0(6);
      *DAT_00008e50 = *DAT_00008e50 + '\x01';
      *_DAT_00008da0 = *_DAT_00008da0 + 1;
      *DAT_00008e54 = 0;
    }
    else {
      FUN_000092a0(0x15);
      puVar1 = DAT_00008e54;
      *DAT_00008e54 = *DAT_00008e54 + 1;
      FUN_00009ff0(DAT_00008e58,*puVar1,*DAT_00008e50,DAT_00008c64[1]);
      if (4 < *DAT_00008e54) {
        FUN_00009ff0("\r\nMax error cnt reached! Upgrade failed, reset...\r\n");
        FUN_0000853c(param_1);
        FUN_00009ab6(DAT_00009060);
        FUN_00009a86();
      }
    }
  }
  else {
    *_DAT_00009064 = *_DAT_00009064 + 1;
    FUN_00009ff0("\r\nInvalid frame start (not SOH)! Err cnt: %d\r\n",*piVar2);
  }
  return;
}


/* ===== FUN_00008e8c @ 00008e8c ===== */

void FUN_00008e8c(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  if ((*DAT_00009098 != '\0') && (*param_1 != -0x56)) {
    while (*DAT_00009098 != '\0') {
      FUN_00008924(5);
      if (*DAT_0000909c == 0x85) {
        *DAT_0000909c = 0;
        FUN_00008ba8(param_1);
      }
      else if (*DAT_000090a0 % 0x85 == 1) {
        iVar1 = FUN_00008b1c(param_1);
        if (iVar1 == 0) {
          FUN_00008924(2);
        }
        else {
          iVar1 = FUN_00008a42(uVar2);
          if (iVar1 != 0) {
            FUN_00008ab2();
            *DAT_000090a4 = 0xffffffff;
            disableIRQinterrupts();
            FUN_00009ab6(DAT_00009060);
            FUN_00009a86();
            return;
          }
          FUN_00009ff0("\r\n[CRC32] Checksum verification failed!\r\n");
          FUN_00009ff0("\r\nUpgrade failure ready to go back to app........\r\n");
          FUN_0000853c(param_1);
          FUN_00009ab6(DAT_00009060);
          FUN_00009a86();
        }
      }
    }
  }
  return;
}


/* ===== FUN_00008f5a @ 00008f5a ===== */

void FUN_00008f5a(undefined4 param_1,undefined *param_2,int param_3)

{
  uint uVar1;
  
  FUN_00009ff0("\r\n=========================================\r\n");
  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
    FUN_00009ff0("%02x, ",*param_2);
    if (uVar1 + 1 + ((int)(uVar1 + 1) >> 4) * -0x10 == 0) {
      FUN_00009ff0("\r\n");
    }
    param_2 = param_2 + 1;
  }
  FUN_00009ff0("\r\n[Boot Area] successful. Bytes = %d \r\n",uVar1);
  return;
}


/* ===== FUN_00008faa @ 00008faa ===== */

void FUN_00008faa(int param_1)

{
  undefined4 unaff_r4;
  undefined4 uVar1;
  
  uVar1 = DAT_00009168;
  if (((param_1 != 0xff) && (uVar1 = DAT_0000916c, param_1 != 4)) &&
     (uVar1 = unaff_r4, param_1 == 5)) {
    uVar1 = DAT_00009170;
  }
  FUN_00008878(DAT_00009174,uVar1,0x10000);
  FUN_00009ff0("\r\n[Boot Area] Flash read done.\r\n");
  FUN_00009ab6(DAT_0000919c);
  return;
}


/* ===== FUN_00008fde @ 00008fde ===== */

void FUN_00008fde(void)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_000092a0(6);
  for (uVar2 = 0; uVar2 < 1000; uVar2 = uVar2 + 1) {
  }
  iVar5 = 1;
  iVar4 = 3;
  for (uVar1 = 0; uVar1 < *DAT_000090a0; uVar1 = uVar1 + 1) {
    *(undefined *)(DAT_00009174 + uVar1) = *(undefined *)(DAT_000091a0 + iVar4);
    iVar3 = iVar4 + 1;
    if (iVar5 * 0x85 + -2 == iVar3) {
      iVar3 = iVar4 + 6;
      iVar5 = iVar5 + 1;
    }
    iVar4 = iVar3;
  }
  return;
}


/* ===== FUN_000091c0 @ 000091c0 ===== */

undefined8 FUN_000091c0(void)

{
  return CONCAT44(DAT_000091d8,DAT_000091d4);
}


/* ===== FUN_000091e4 @ 000091e4 ===== */

void FUN_000091e4(void)

{
  return;
}


/* ===== FUN_00009202 @ 00009202 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00009202(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000933c;
  *(undefined4 *)(DAT_0000933c + 0x30) = 1;
  *(undefined4 *)(iVar1 + 0x34) = 0x81;
  _DAT_40004010 = DAT_00009340 / param_1;
  _DAT_40004008 = 0xb;
  if (param_2 != 0) {
    *DAT_00009344 = param_2;
  }
  return;
}


/* ===== FUN_0000922a @ 0000922a ===== */

void FUN_0000922a(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000933c;
  *(undefined4 *)(DAT_0000933c + 0x58) = 1;
  *(undefined4 *)(iVar1 + 0x5c) = 0x81;
  *(uint *)(DAT_00009348 + 0x10) = DAT_00009340 / param_1;
  *(undefined4 *)(DAT_00009348 + 8) = 0xb;
  if (param_2 != 0) {
    *(int *)(DAT_00009344 + 4) = param_2;
  }
  return;
}


/* ===== FUN_0000924e @ 0000924e ===== */

void FUN_0000924e(int param_1,int param_2)

{
  *(undefined4 *)(DAT_0000933c + 0x80) = 1;
  *(undefined4 *)(DAT_0000933c + 0x84) = 0x81;
  *(int *)(DAT_0000934c + 0x10) = DAT_00009340 / param_1;
  *(undefined4 *)(DAT_0000934c + 8) = 0xb;
  if (param_2 != 0) {
    *(int *)(DAT_00009344 + 8) = param_2;
  }
  return;
}


/* ===== FUN_00009278 @ 00009278 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00009278(int param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    _DAT_40004000 = (uint)*(byte *)(param_1 + uVar1);
    do {
    } while ((_DAT_40004004 & 1) != 0);
  }
  return;
}


/* ===== FUN_000092a0 @ 000092a0 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000092a0(undefined4 param_1)

{
  _DAT_40004000 = param_1;
  do {
  } while ((_DAT_40004004 & 1) != 0);
  return;
}


/* ===== FUN_000093ac @ 000093ac ===== */

void FUN_000093ac(void)

{
  int iVar1;
  
  iVar1 = DAT_00009730;
  *(undefined4 *)(DAT_00009730 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x40) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined4 *)(iVar1 + 0x60) = 0;
  *(undefined4 *)(iVar1 + 100) = 0;
  *(undefined4 *)(iVar1 + 0x68) = 0;
  *(undefined4 *)(iVar1 + 0x6c) = 0;
  *(undefined4 *)(iVar1 + 0x70) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x7c) = 0;
  *(undefined4 *)(DAT_00009730 + 0x80) = 0;
  *(undefined4 *)(DAT_00009730 + 0x84) = 0;
  iVar1 = DAT_00009730;
  *(undefined4 *)(DAT_00009730 + 0x88) = 0;
  *(undefined4 *)(iVar1 + 0x8c) = 0;
  *(undefined4 *)(iVar1 + 0x90) = 0;
  *(undefined4 *)(iVar1 + 0x94) = 0;
  *(undefined4 *)(iVar1 + 0x98) = 0;
  *(undefined4 *)(iVar1 + 0x9c) = 0;
  *(undefined4 *)(iVar1 + 0xa0) = 0;
  *(undefined4 *)(iVar1 + 0xa4) = 0;
  *(undefined4 *)(iVar1 + 0xa8) = 0;
  return;
}


/* ===== FUN_00009950 @ 00009950 ===== */

uint FUN_00009950(uint param_1)

{
  *(undefined4 *)(DAT_0000996c + param_1 * 4 + -0x68) = 0x30;
  return *(uint *)(DAT_0000996c + -0x6c) >> (param_1 & 0xff) & 1;
}


/* ===== FUN_00009970 @ 00009970 ===== */

void FUN_00009970(undefined4 param_1,int param_2)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
  }
  return;
}


/* ===== FUN_00009998 @ 00009998 ===== */

uint FUN_00009998(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {
    uVar2 = *(uint *)(DAT_00009a74 + (uVar2 & 0xff ^ (uint)*(byte *)(param_1 + iVar1)) * 4) ^
            uVar2 >> 8;
  }
  return ~uVar2;
}


/* ===== FUN_000099c0 @ 000099c0 ===== */

uint FUN_000099c0(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_18;
  
  uVar1 = 0xffffffff;
  local_18 = param_4;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    FUN_00009c9a(&local_18,param_1 + uVar2,1);
    uVar1 = *(uint *)(DAT_00009a74 + (uVar1 & 0xff ^ local_18 & 0xff) * 4) ^ uVar1 >> 8;
  }
  return ~uVar1;
}


/* ===== FUN_000099f4 @ 000099f4 ===== */

uint FUN_000099f4(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte local_11c [256];
  
  uVar3 = 0xffffffff;
  for (; param_2 != 0; param_2 = param_2 - uVar1) {
    uVar1 = param_2;
    if (0x100 < param_2) {
      uVar1 = 0x100;
    }
    FUN_00009c9a(local_11c,param_1,uVar1 & 0xffff);
    for (uVar2 = 0; uVar2 < uVar1; uVar2 = uVar2 + 1) {
      uVar3 = *(uint *)(DAT_00009a74 + (uVar3 & 0xff ^ (uint)local_11c[uVar2]) * 4) ^ uVar3 >> 8;
    }
    param_1 = param_1 + uVar1;
  }
  return ~uVar3;
}


/* ===== FUN_00009a4e @ 00009a4e ===== */

bool FUN_00009a4e(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_000099f4(param_1,param_2);
  return iVar1 == param_3;
}


/* ===== FUN_00009a7a @ 00009a7a ===== */

void FUN_00009a7a(uint param_1,uint param_2)

{
  *DAT_00009afc = DAT_00009af8 & param_2 | param_1;
  return;
}


/* ===== FUN_00009a86 @ 00009a86 ===== */

void FUN_00009a86(void)

{
  *(uint *)(DAT_00009afc + 4) = *(uint *)(DAT_00009afc + 4) & 0xffff | DAT_00009b00;
  return;
}


/* ===== FUN_00009a9e @ 00009a9e ===== */

void FUN_00009a9e(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *DAT_00009b04 = 1 << (param_1 & 0xff);
  }
  else {
    DAT_00009b04[-0x20] = 1 << (param_1 & 0xff);
  }
  return;
}


/* ===== FUN_00009ab6 @ 00009ab6 ===== */

void FUN_00009ab6(uint param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_1; uVar1 = uVar1 + 1) {
  }
  return;
}


/* ===== FUN_00009aca @ 00009aca ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00009aca(void)

{
  *_DAT_00009b08 = 0;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  FUN_0000814e();
  return;
}


/* ===== FUN_00009ae0 @ 00009ae0 ===== */

void FUN_00009ae0(undefined4 *param_1)

{
  (*(code *)param_1[1])();
  FUN_00009aca();
  FUN_00009ff0("init sp: %08x, reset handler: %08x\r\n",*param_1,param_1[1]);
  return;
}


/* ===== FUN_00009b34 @ 00009b34 ===== */

void FUN_00009b34(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_00009eb8;
  *(undefined4 *)(DAT_00009eb8 + 0x3c) = 0x601;
  *(undefined4 *)(iVar1 + 0x44) = 0x601;
  *(undefined4 *)(iVar1 + 0x48) = 0x601;
  puVar2 = DAT_00009ebc;
  *DAT_00009ebc = 199;
  puVar2[4] = 0x10;
  puVar2[1] = 2;
  return;
}


/* ===== FUN_00009b50 @ 00009b50 ===== */

uint FUN_00009b50(undefined4 param_1)

{
  *(undefined4 *)(DAT_00009ebc + 8) = param_1;
  do {
  } while ((*(uint *)(DAT_00009ebc + 0xc) & 1) == 0);
  do {
  } while ((*(uint *)(DAT_00009ebc + 0xc) & 4) != 4);
  return *(uint *)(DAT_00009ebc + 8) & 0xff;
}


/* ===== FUN_00009b7a @ 00009b7a ===== */

void FUN_00009b7a(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_00009eb8;
  *(undefined4 *)(DAT_00009eb8 + 0x40) = 0;
  if (param_1 == 1) {
    *(uint *)(DAT_00009eb8 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x10;
  }
  else {
    *(uint *)(DAT_00009eb8 + 0x24) = *(uint *)(DAT_00009eb8 + 0x24) | 0x10;
  }
  return;
}


/* ===== FUN_00009b9e @ 00009b9e ===== */

void FUN_00009b9e(void)

{
  do {
  } while ((*(uint *)(DAT_00009ebc + 0xc) & 0x10) == 0x10);
  return;
}


/* ===== FUN_00009bae @ 00009bae ===== */

void FUN_00009bae(void)

{
  FUN_00009b7a(0);
  FUN_00009b50(6);
  FUN_00009b7a(1);
  FUN_00009b9e();
  return;
}


/* ===== FUN_00009bc8 @ 00009bc8 ===== */

void FUN_00009bc8(void)

{
  FUN_00009b7a(0);
  FUN_00009b50(4);
  FUN_00009b7a(1);
  FUN_00009b9e();
  return;
}


/* ===== FUN_00009be2 @ 00009be2 ===== */

undefined4 FUN_00009be2(void)

{
  undefined4 uVar1;
  
  FUN_00009b7a(0);
  FUN_00009b50(5);
  uVar1 = FUN_00009b50(0xff);
  FUN_00009b7a(1);
  return uVar1;
}


/* ===== FUN_00009c04 @ 00009c04 ===== */

void FUN_00009c04(undefined param_1)

{
  uint uVar1;
  
  FUN_00009bae();
  FUN_00009b7a(0);
  FUN_00009b50(1);
  FUN_00009b50(param_1);
  FUN_00009b7a(1);
  FUN_00009b9e();
  do {
    uVar1 = FUN_00009be2();
  } while ((uVar1 & 2) == 2);
  return;
}


/* ===== FUN_00009c38 @ 00009c38 ===== */

void FUN_00009c38(void)

{
  uint uVar1;
  
  do {
    uVar1 = FUN_00009be2();
  } while ((uVar1 & 1) != 0);
  return;
}


/* ===== FUN_00009c4a @ 00009c4a ===== */

short FUN_00009c4a(void)

{
  short sVar1;
  short sVar2;
  
  FUN_00009b7a(1);
  FUN_00009ab6(5);
  FUN_00009b7a(0);
  FUN_00009b50(0x90);
  FUN_00009b50(0);
  FUN_00009b50(0);
  FUN_00009b50(0);
  sVar1 = FUN_00009b50(0xff);
  sVar2 = FUN_00009b50(0xff);
  FUN_00009b7a(1);
  FUN_00009b9e();
  return sVar2 + sVar1 * 0x100;
}


/* ===== FUN_00009c9a @ 00009c9a ===== */

void FUN_00009c9a(int param_1,uint param_2,int param_3)

{
  undefined uVar1;
  uint uVar2;
  
  FUN_00009b7a(1);
  FUN_00009ab6(5);
  FUN_00009b7a(0);
  FUN_00009b50(3);
  FUN_00009b50((param_2 << 8) >> 0x18);
  FUN_00009b50((param_2 << 0x10) >> 0x18);
  FUN_00009b50(param_2 & 0xff);
  for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 1 & 0xffff) {
    uVar1 = FUN_00009b50(0xff);
    *(undefined *)(param_1 + uVar2) = uVar1;
  }
  *(undefined4 *)(DAT_00009ec0 + 0x1c) = 1;
  FUN_00009b9e();
  FUN_00009b7a(1);
  return;
}


/* ===== FUN_00009cfa @ 00009cfa ===== */

void FUN_00009cfa(void)

{
  FUN_00009bae();
  FUN_00009b7a(1);
  FUN_00009ab6(5);
  FUN_00009b7a(0);
  FUN_00009b50(199);
  FUN_00009b7a(1);
  FUN_00009b9e();
  FUN_00009c38();
  return;
}


/* ===== FUN_00009d28 @ 00009d28 ===== */

void FUN_00009d28(int param_1)

{
  FUN_00009bae();
  FUN_00009b7a(0);
  FUN_00009b50(0x20);
  FUN_00009b50((uint)(param_1 << 0x14) >> 0x18);
  FUN_00009b50((uint)(param_1 << 0x1c) >> 0x18);
  FUN_00009b50(0);
  FUN_00009b7a(1);
  FUN_00009b9e();
  FUN_00009c38();
  return;
}


/* ===== FUN_00009d64 @ 00009d64 ===== */

void FUN_00009d64(uint param_1)

{
  FUN_00009bae();
  FUN_00009b7a(0);
  FUN_00009b50(0x52);
  FUN_00009b50((param_1 << 8) >> 0x18);
  FUN_00009b50((param_1 << 0x10) >> 0x18);
  FUN_00009b50(param_1 & 0xff);
  FUN_00009b7a(1);
  FUN_00009b9e();
  FUN_00009c38();
  return;
}


/* ===== FUN_00009d9e @ 00009d9e ===== */

void FUN_00009d9e(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  FUN_00009bae();
  FUN_00009b7a(0);
  FUN_00009b50(2);
  FUN_00009b50((param_2 << 8) >> 0x18);
  FUN_00009b50((param_2 << 0x10) >> 0x18);
  FUN_00009b50(param_2 & 0xff);
  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
    FUN_00009b50(*(undefined *)(param_1 + uVar1));
  }
  FUN_00009b7a(1);
  FUN_00009c38();
  return;
}


/* ===== FUN_00009dee @ 00009dee ===== */

void FUN_00009dee(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = 0x100 - (param_2 & 0xff);
  if ((int)param_3 <= (int)uVar1) {
    uVar1 = param_3;
  }
  while (FUN_00009d9e(param_1,param_2,uVar1), param_3 != uVar1) {
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


/* ===== FUN_00009e34 @ 00009e34 ===== */

void FUN_00009e34(undefined *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  
  FUN_00009bae();
  FUN_00009b50(0xaf);
  FUN_00009b50((param_2 << 8) >> 0x18);
  FUN_00009b50((param_2 << 0x10) >> 0x18);
  FUN_00009b50(param_2 & 0xff);
  FUN_00009b50(*param_1);
  for (uVar1 = 0; uVar1 < 800; uVar1 = uVar1 + 1 & 0xff) {
  }
  while (bVar3 = param_3 != 0, param_3 = param_3 - 1 & 0xffff, bVar3) {
    FUN_00009b50(0xaf);
    FUN_00009b50(param_1[1]);
    param_1 = param_1 + 1;
    for (uVar1 = 0; uVar1 < 800; uVar1 = uVar1 + 1 & 0xff) {
    }
  }
  FUN_00009bc8();
  for (iVar2 = 0; iVar2 < 800; iVar2 = iVar2 + 1) {
  }
  FUN_00009be2();
  return;
}


/* ===== FUN_00009ec4 @ 00009ec4 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00009ec4(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  FUN_0000a608(param_1,DAT_00009fd8);
  uVar2 = FUN_0000a5c8();
  puVar1 = DAT_00009fdc;
  *DAT_00009fdc = uVar2;
  _DAT_40000008 = *puVar1;
  _DAT_40000000 = 9;
  return;
}


/* ===== FUN_00009eea @ 00009eea ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00009eea(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  FUN_0000a608(param_1,DAT_00009fd8);
  uVar2 = FUN_0000a5c8();
  puVar1 = DAT_00009fdc;
  *DAT_00009fdc = uVar2;
  _DAT_40000008 = *puVar1;
  _DAT_40000000 = 0;
  _DAT_40000004 = 0;
  return;
}


/* ===== FUN_00009f28 @ 00009f28 ===== */

void FUN_00009f28(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  FUN_0000a608(param_1,DAT_00009fd8);
  uVar3 = FUN_0000a5c8();
  puVar1 = DAT_00009fdc;
  *DAT_00009fdc = uVar3;
  puVar2 = DAT_00009fe0;
  DAT_00009fe0[2] = *puVar1;
  *puVar2 = 0;
  puVar2[1] = 0;
  return;
}


/* ===== FUN_00009ff0 @ 00009ff0 ===== */

void FUN_00009ff0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0000a448(param_1,DAT_0000a004,&uStack_c);
  return;
}


/* ===== FUN_0000a008 @ 0000a008 ===== */

void FUN_0000a008(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = param_1[6];
  if ((int)(*param_1 << 0x1b) < 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0x20;
  }
  if ((*param_1 & 1) != 0) {
    return;
  }
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    (*(code *)param_1[1])(uVar2,param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  return;
}


/* ===== FUN_0000a034 @ 0000a034 ===== */

void FUN_0000a034(byte *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((*param_1 & 1) == 0) {
    return;
  }
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    (**(code **)(param_1 + 4))(0x20,*(undefined4 *)(param_1 + 8));
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  return;
}


/* ===== FUN_0000a128 @ 0000a128 ===== */

uint FUN_0000a128(uint *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar1 = DAT_0000a2ac;
  param_1[8] = 0;
  while (uVar2 = (*(code *)param_1[3])(param_1), uVar2 != 0) {
    if (uVar2 == 0x25) {
      uVar5 = 0;
      while (((uVar2 = (*(code *)param_1[3])(param_1), 0x1f < (int)uVar2 && (uVar2 < 0x31)) &&
             (uVar3 = (uint)*(byte *)(iVar1 + uVar2 + 0xa11c), uVar3 != 0))) {
        uVar5 = uVar5 | uVar3;
      }
      if ((int)(uVar5 << 0x1e) < 0) {
        uVar5 = uVar5 & 0xfffffffb;
      }
      param_1[7] = 0;
      iVar6 = 0;
      param_1[6] = 0;
      puVar7 = param_2;
      do {
        if (uVar2 == 0x2a) {
          param_2 = puVar7 + 1;
          param_1[iVar6 + 6] = *puVar7;
          uVar2 = (*(code *)param_1[3])(param_1);
          if (iVar6 == 1) {
            if ((int)param_1[7] < 0) {
              uVar5 = uVar5 & 0xffffffdf;
            }
            break;
          }
        }
        else {
          iVar4 = FUN_0000a5b8(uVar2);
          if (iVar4 != 0) {
            param_1[iVar6 + 6] = uVar2 - 0x30;
            while( true ) {
              uVar2 = (*(code *)param_1[3])(param_1);
              iVar4 = FUN_0000a5b8();
              if (iVar4 == 0) break;
              param_1[iVar6 + 6] = (uVar2 + param_1[iVar6 + 6] * 10) - 0x30;
            }
          }
          param_2 = puVar7;
          if (iVar6 == 1) break;
        }
        if (uVar2 != 0x2e) break;
        uVar2 = (*(code *)param_1[3])(param_1);
        iVar6 = iVar6 + 1;
        uVar5 = uVar5 | 0x20;
        puVar7 = param_2;
      } while (iVar6 < 2);
      if ((int)param_1[6] < 0) {
        uVar5 = uVar5 | 1;
        param_1[6] = -param_1[6];
      }
      if ((uVar5 & 1) != 0) {
        uVar5 = uVar5 & 0xffffffef;
      }
      if ((uVar2 == 0x6c) || (uVar2 == 0x68)) {
        uVar3 = (*(code *)param_1[3])(param_1);
        if (uVar3 == uVar2) {
          if (uVar2 == 0x6c) goto LAB_0000a294;
          uVar2 = 0x400;
          goto LAB_0000a24a;
        }
        if (uVar2 == 0x6c) {
          uVar2 = 0x40;
        }
        else {
          uVar2 = 0x100;
        }
        uVar5 = uVar5 | uVar2;
        uVar2 = uVar3;
      }
      else {
        if (uVar2 != 0x4c) {
          if (uVar2 == 0x6a) {
LAB_0000a294:
            uVar2 = 0x80;
            goto LAB_0000a24a;
          }
          if ((uVar2 != 0x74) && (uVar2 != 0x7a)) goto LAB_0000a260;
        }
        uVar2 = 0;
LAB_0000a24a:
        uVar5 = uVar5 | uVar2;
        uVar2 = (*(code *)param_1[3])(param_1);
      }
LAB_0000a260:
      if (uVar2 == 0) break;
      if (uVar2 - 0x41 < 0x1a) {
        uVar2 = uVar2 + 0x20;
        uVar5 = uVar5 | 0x800;
      }
      *param_1 = uVar5;
      iVar6 = FUN_0000810a(param_1,uVar2,param_2);
      if (iVar6 == 0) goto LAB_0000a14c;
      if (iVar6 == 1) {
        param_2 = param_2 + 1;
      }
      else {
        param_2 = (uint *)(((int)param_2 + 7U & 0xfffffff8) + 8);
      }
    }
    else {
LAB_0000a14c:
      (*(code *)param_1[1])(uVar2,param_1[2]);
      param_1[8] = param_1[8] + 1;
    }
  }
  return param_1[8];
}


/* ===== FUN_0000a2b0 @ 0000a2b0 ===== */

undefined8 FUN_0000a2b0(uint *param_1,uint *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  byte *pbVar5;
  byte bVar6;
  undefined2 uVar7;
  byte in_r12;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  puVar4 = param_2;
  if (3 < param_3) {
    uVar8 = (uint)param_1 & 3;
    puVar2 = param_1;
    uVar9 = uVar8;
    if (uVar8 != 0) {
      bVar6 = *(byte *)param_2;
      puVar4 = (uint *)((int)param_2 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_2 + 2);
        uVar9 = (uint)*(byte *)(uint *)((int)param_2 + 1);
      }
      *(byte *)param_1 = bVar6;
      param_2 = puVar4;
      if (uVar8 < 2) {
        param_2 = (uint *)((int)puVar4 + 1);
        bVar6 = *(byte *)puVar4;
      }
      param_3 = (param_3 + uVar8) - 4;
      puVar4 = (uint *)((int)param_1 + 1);
      if (uVar8 < 3) {
        puVar4 = (uint *)((int)param_1 + 2);
        *(byte *)(uint *)((int)param_1 + 1) = (byte)uVar9;
      }
      puVar2 = puVar4;
      if (uVar8 < 2) {
        puVar2 = (uint *)((int)puVar4 + 1);
        *(byte *)puVar4 = bVar6;
      }
    }
    param_4 = (uint)param_2 & 3;
    if (param_4 == 0) {
      uVar9 = 0;
      while (uVar8 = param_3 - 0x20, 0x1f < param_3) {
        uVar9 = param_2[1];
        uVar10 = param_2[2];
        uVar11 = param_2[3];
        *puVar2 = *param_2;
        puVar2[1] = uVar9;
        puVar2[2] = uVar10;
        puVar2[3] = uVar11;
        uVar9 = param_2[4];
        uVar10 = param_2[5];
        uVar11 = param_2[6];
        uVar12 = param_2[7];
        param_2 = param_2 + 8;
        puVar2[4] = uVar9;
        puVar2[5] = uVar10;
        puVar2[6] = uVar11;
        puVar2[7] = uVar12;
        puVar2 = puVar2 + 8;
        param_3 = uVar8;
      }
      if ((uVar8 & 0x10) != 0) {
        uVar9 = *param_2;
        uVar10 = param_2[1];
        uVar11 = param_2[2];
        uVar12 = param_2[3];
        param_2 = param_2 + 4;
        *puVar2 = uVar9;
        puVar2[1] = uVar10;
        puVar2[2] = uVar11;
        puVar2[3] = uVar12;
        puVar2 = puVar2 + 4;
      }
      if ((int)(param_3 << 0x1c) < 0) {
        uVar9 = *param_2;
        uVar10 = param_2[1];
        param_2 = param_2 + 2;
        *puVar2 = uVar9;
        puVar2[1] = uVar10;
        puVar2 = puVar2 + 2;
      }
      puVar3 = puVar2;
      puVar4 = param_2;
      if ((uVar8 & 4) != 0) {
        puVar4 = param_2 + 1;
        uVar9 = *param_2;
        puVar3 = puVar2 + 1;
        *puVar2 = uVar9;
      }
      uVar7 = (undefined2)uVar9;
      if ((uVar8 & 3) != 0) {
        bVar1 = (uVar8 & 2) != 0;
        param_3 = param_3 << 0x1f;
        bVar13 = (int)param_3 < 0;
        puVar2 = puVar4;
        if (bVar1) {
          puVar2 = (uint *)((int)puVar4 + 2);
          uVar7 = *(undefined2 *)puVar4;
        }
        puVar4 = puVar2;
        if (bVar13) {
          puVar4 = (uint *)((int)puVar2 + 1);
          param_3 = (uint)*(byte *)puVar2;
        }
        puVar2 = puVar3;
        if (bVar1) {
          puVar2 = (uint *)((int)puVar3 + 2);
          *(undefined2 *)puVar3 = uVar7;
        }
        puVar3 = puVar2;
        if (bVar13) {
          puVar3 = (uint *)((int)puVar2 + 1);
          *(byte *)puVar2 = (byte)param_3;
        }
        return CONCAT44(puVar4,puVar3);
      }
      return CONCAT44(puVar4,puVar3);
    }
    while( true ) {
      in_r12 = (byte)uVar9;
      if (param_3 < 8) break;
      puVar4 = param_2 + 1;
      param_4 = *param_2;
      param_2 = param_2 + 2;
      uVar9 = *puVar4;
      *puVar2 = param_4;
      puVar2[1] = uVar9;
      puVar2 = puVar2 + 2;
      param_3 = param_3 - 8;
    }
    param_3 = param_3 - 4;
    param_1 = puVar2;
    puVar4 = param_2;
    if (-1 < (int)param_3) {
      puVar4 = param_2 + 1;
      param_4 = *param_2;
      param_1 = puVar2 + 1;
      *puVar2 = param_4;
    }
  }
  bVar6 = (byte)param_4;
  bVar1 = (param_3 & 2) != 0;
  param_3 = param_3 << 0x1f;
  bVar13 = (int)param_3 < 0;
  if (bVar1) {
    pbVar5 = (byte *)((int)puVar4 + 1);
    bVar6 = *(byte *)puVar4;
    puVar4 = (uint *)((int)puVar4 + 2);
    in_r12 = *pbVar5;
  }
  puVar2 = puVar4;
  if (bVar13) {
    puVar2 = (uint *)((int)puVar4 + 1);
    param_3 = (uint)*(byte *)puVar4;
  }
  if (bVar1) {
    pbVar5 = (byte *)((int)param_1 + 1);
    *(byte *)param_1 = bVar6;
    param_1 = (uint *)((int)param_1 + 2);
    *pbVar5 = in_r12;
  }
  puVar4 = param_1;
  if (bVar13) {
    puVar4 = (uint *)((int)param_1 + 1);
    *(byte *)param_1 = (byte)param_3;
  }
  return CONCAT44(puVar2,puVar4);
}


/* ===== FUN_0000a33a @ 0000a33a ===== */

undefined4 * FUN_0000a33a(undefined4 *param_1,uint param_2,undefined param_3)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  bool bVar8;
  
  uVar1 = CONCAT11(param_3,param_3);
  uVar6 = CONCAT22(uVar1,uVar1);
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar3 = (undefined *)((int)param_1 + 1);
      *(undefined *)param_1 = param_3;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar3 = param_3;
    }
    puVar2 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = param_3;
    }
    return puVar2;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar7 = 4 - ((uint)param_1 & 3);
    puVar2 = param_1;
    if (iVar7 != 2) {
      puVar2 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = param_3;
    }
    param_1 = puVar2;
    if (1 < iVar7) {
      param_1 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    param_2 = param_2 - iVar7;
  }
  bVar8 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar8) {
      *param_1 = uVar6;
      param_1[1] = uVar6;
      param_1[2] = uVar6;
      param_1[3] = uVar6;
      param_1[4] = uVar6;
      param_1[5] = uVar6;
      param_1[6] = uVar6;
      param_1[7] = uVar6;
      param_1 = param_1 + 8;
      bVar8 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar8);
  if ((param_2 & 0x10) != 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1[2] = uVar6;
    param_1[3] = uVar6;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = uVar6;
    param_1[1] = uVar6;
    param_1 = param_1 + 2;
  }
  uVar5 = param_2 << 0x1e;
  puVar2 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar2 = param_1 + 1;
    *param_1 = uVar6;
  }
  if (uVar5 != 0) {
    puVar4 = puVar2;
    if ((int)uVar5 < 0) {
      puVar4 = (undefined4 *)((int)puVar2 + 2);
      *(undefined2 *)puVar2 = uVar1;
    }
    puVar2 = puVar4;
    if ((uVar5 & 0x40000000) != 0) {
      puVar2 = (undefined4 *)((int)puVar4 + 1);
      *(undefined *)puVar4 = param_3;
    }
    return puVar2;
  }
  return puVar2;
}


/* ===== FUN_0000a34a @ 0000a34a ===== */

undefined4 * FUN_0000a34a(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  if (param_2 < 4) {
    if ((param_2 & 2) != 0) {
      puVar2 = (undefined *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      *puVar2 = 0;
    }
    puVar1 = param_1;
    if ((int)(param_2 << 0x1f) < 0) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
    }
    return puVar1;
  }
  if (((uint)param_1 & 3) != 0) {
    iVar5 = 4 - ((uint)param_1 & 3);
    puVar1 = param_1;
    if (iVar5 != 2) {
      puVar1 = (undefined4 *)((int)param_1 + 1);
      *(undefined *)param_1 = 0;
    }
    param_1 = puVar1;
    if (1 < iVar5) {
      param_1 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    param_2 = param_2 - iVar5;
  }
  bVar6 = 0x1f < param_2;
  param_2 = param_2 - 0x20;
  do {
    if (bVar6) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      param_1[6] = 0;
      param_1[7] = 0;
      param_1 = param_1 + 8;
      bVar6 = 0x1f < param_2;
      param_2 = param_2 - 0x20;
    }
  } while (bVar6);
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1 = param_1 + 4;
  }
  if ((int)(param_2 << 0x1c) < 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1 = param_1 + 2;
  }
  uVar4 = param_2 << 0x1e;
  puVar1 = param_1;
  if ((param_2 << 0x1c & 0x40000000) != 0) {
    puVar1 = param_1 + 1;
    *param_1 = 0;
  }
  if (uVar4 != 0) {
    puVar3 = puVar1;
    if ((int)uVar4 < 0) {
      puVar3 = (undefined4 *)((int)puVar1 + 2);
      *(undefined2 *)puVar1 = 0;
    }
    puVar1 = puVar3;
    if ((uVar4 & 0x40000000) != 0) {
      puVar1 = (undefined4 *)((int)puVar3 + 1);
      *(undefined *)puVar3 = 0;
    }
    return puVar1;
  }
  return puVar1;
}


/* ===== FUN_0000a448 @ 0000a448 ===== */

undefined4 FUN_0000a448(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_0000a52a();
  iVar2 = FUN_0000a550(param_2);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  return uVar1;
}


/* ===== FUN_0000a52a @ 0000a52a ===== */

void FUN_0000a52a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined auStack_40 [4];
  undefined4 local_3c;
  undefined4 uStack_38;
  int local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  
  local_2c = 0;
  local_34 = DAT_0000a54c + 0xa53c;
  local_3c = param_4;
  uStack_38 = param_2;
  uStack_30 = param_1;
  FUN_0000a128(auStack_40,param_3);
  return;
}


/* ===== FUN_0000a550 @ 0000a550 ===== */

byte FUN_0000a550(int param_1)

{
  return *(byte *)(param_1 + 0xc) & 0x80;
}


/* ===== FUN_0000a558 @ 0000a558 ===== */

void FUN_0000a558(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 in_lr;
  uint *puVar3;
  
  uVar1 = FUN_0000a5b0();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = in_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_000091c0();
  puVar2 = (undefined4 *)*puVar3;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  return;
}


/* ===== FUN_0000a5a2 @ 0000a5a2 ===== */

undefined4 FUN_0000a5a2(undefined4 param_1)

{
  FUN_0000813a(param_1);
  return DAT_0000a5b4;
}


/* ===== FUN_0000a5b0 @ 0000a5b0 ===== */

undefined4 FUN_0000a5b0(void)

{
  return DAT_0000a5b4;
}


/* ===== FUN_0000a5b8 @ 0000a5b8 ===== */

undefined4 FUN_0000a5b8(int param_1)

{
  if (param_1 - 0x30U < 10) {
    return 1;
  }
  return 0;
}


/* ===== FUN_0000a5c8 @ 0000a5c8 ===== */

uint FUN_0000a5c8(uint param_1)

{
  uint uVar1;
  undefined2 *unaff_r4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 >> 0x17 < 0x9f) {
    return (param_1 << 8 | 0x80000000) >> (0x9e - (param_1 >> 0x17) & 0xff);
  }
  if (((int)param_1 < 0) && (param_1 << 1 < 0x7f000000)) {
    return 0;
  }
  UNRECOVERED_JUMPTABLE = (code *)0xa5f8;
  FUN_0000a70a();
  *unaff_r4 = (short)unaff_r4;
                    /* WARNING: Could not recover jumptable at 0x0000a5fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)(0);
  return uVar1;
}


/* ===== FUN_0000a608 @ 0000a608 ===== */

uint FUN_0000a608(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined8 uVar7;
  
  uVar2 = param_1 >> 7 & 0xff0000;
  bVar6 = uVar2 == 0;
  if (!bVar6) {
    param_4 = param_2 >> 7 & 0xff0000;
    bVar6 = param_4 == 0;
  }
  if (!bVar6) {
    bVar6 = uVar2 == 0xff0000;
  }
  if (!bVar6) {
    bVar6 = param_4 == 0xff0000;
  }
  if (bVar6) {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar2 = uVar2 | 0x100;
    }
    if (uVar2 < 0xff0000 && (param_2 >> 7 & 0xff0000) < 0xff0000) {
      return (param_1 ^ param_2) & 0x80000000;
    }
    uVar7 = FUN_0000a70a();
    uVar2 = (uint)uVar7 ^ (int)((ulonglong)uVar7 >> 0x20) << 2;
  }
  else {
    if ((int)(param_1 ^ param_2) < 0) {
      uVar2 = uVar2 | 0x100;
    }
    lVar1 = (ulonglong)(param_1 << 8 | 0x80000000) * (ulonglong)(param_2 << 8 | 0x80000000);
    uVar4 = (uint)((ulonglong)lVar1 >> 0x20);
    iVar3 = uVar2 + param_4 + -0x800000;
    if ((int)lVar1 != 0) {
      uVar4 = uVar4 | 1;
    }
    bVar6 = (uVar4 & 0x80000000) != 0;
    uVar5 = uVar4 << 1;
    if (bVar6) {
      uVar5 = (uint)bVar6 << 0x1f | uVar4 & 0x7fffffff;
    }
    uVar4 = iVar3 + (iVar3 >> 0x10) + (uint)bVar6;
    bVar6 = (uVar5 >> 7 & 1) != 0;
    uVar2 = (uVar5 >> 8) + uVar4 * 0x800000 + (uint)bVar6;
    if ((!bVar6 || uVar5 >> 8 < uVar5 << 0x19) && uVar4 < 0xfc0000) {
      return uVar2;
    }
    if ((uVar5 & 0xff) == 0x80) {
      uVar2 = uVar2 & 0xfffffffe;
    }
    if (uVar4 < 0xfc0000) {
      return uVar2;
    }
    if ((int)(uVar4 - 0xfc0000) < 0) {
      uVar4 = uVar4 ^ 0xff;
      bVar6 = (int)(uVar4 + 0x10000) < 0;
      if (uVar4 != 0xffff0000 && bVar6 == SCARRY4(uVar4,0x10000)) {
        return uVar2;
      }
      uVar2 = uVar2 + 0x60000000;
      if (uVar4 == 0xffff0000 || bVar6 != SCARRY4(uVar4,0x10000)) {
        uVar2 = uVar2 & 0x80000000;
      }
      return uVar2;
    }
    if ((int)((uVar2 + 0x800000) * 2) < 0) {
      return uVar2;
    }
    uVar2 = uVar2 + 0xa0000000;
  }
  return (uVar2 >> 0x17 | 0xff) << 0x17;
}


/* ===== FUN_0000a70a @ 0000a70a ===== */

uint FUN_0000a70a(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int in_lr;
  uint *puVar3;
  bool bVar4;
  
  puVar3 = (uint *)(in_lr + 2U & 0xfffffffc);
  uVar1 = *puVar3;
  if ((((int)uVar1 < 0) || (param_3 = param_2 * 2, param_3 < 0xff000001)) &&
     (param_1 * 2 < 0xff000001)) {
    if (param_1 * 2 == 0xff000000) {
      uVar2 = ((int)param_1 >> 0x1f) * -3 + 2;
      if (param_3 == 0xff000000) {
        uVar2 = uVar2 + ((uint)(0xfeffffff < param_3) - ((int)param_2 >> 0x1f));
      }
    }
    else {
      uVar2 = param_2 >> 0x1f;
    }
  }
  else {
    uVar2 = 8;
  }
  uVar1 = uVar1 >> (uVar2 * 3 & 0xff) & 7;
  switch(uVar1) {
  case 4:
    param_1 = param_2;
switchD_0000a772_caseD_5:
    bVar4 = (param_1 & 0x80000000) != 0;
    uVar1 = param_1 * 2;
    if (uVar1 != 0) {
      bVar4 = uVar1 < 0x1000001;
    }
    if (bVar4 && (uVar1 != 0 && uVar1 != 0x1000000)) {
      param_1 = param_1 & 0x80000000;
    }
    return param_1;
  case 5:
    goto switchD_0000a772_caseD_5;
  case 6:
  case 7:
    return 0x7fc00000;
  default:
                    /* WARNING: Could not recover jumptable at 0x0000a770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)(puVar3 + uVar1 + 1))();
    return uVar1;
  }
}

