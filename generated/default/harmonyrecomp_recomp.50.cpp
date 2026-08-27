#include "harmonyrecomp_funcs.50.h"

DEFINE_REX_FUNC(sub_82214508) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82214510;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r29,r9,17136
	ctx.r29.s64 = ctx.r9.s64 + 17136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// addi r9,r29,-88
	ctx.r9.s64 = ctx.r29.s64 + -88;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82214534:
	// cmplwi cr6,r11,9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 9, ctx.xer);
	// bge cr6,0x82214544
	if (!ctx.cr6.lt) goto loc_82214544;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// b 0x82214548
	goto loc_82214548;
loc_82214544:
	// li r10,9
	ctx.r10.s64 = 9;
loc_82214548:
	// stbx r10,r11,r31
	REX_STORE_U8(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u8);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x82214534
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214534;
	// li r11,4
	ctx.r11.s64 = 4;
	// stb r28,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r28.u8);
	// addi r10,r29,-16
	ctx.r10.s64 = ctx.r29.s64 + -16;
	// addi r9,r31,8
	ctx.r9.s64 = ctx.r31.s64 + 8;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82214570:
	// lwzu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stwu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82214570
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214570;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_82214580:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lbzx r5,r30,r29
	ctx.r5.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r29.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823cb208
	ctx.lr = 0x82214590;
	sub_823CB208(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// blt cr6,0x82214580
	if (ctx.cr6.lt) goto loc_82214580;
	// li r11,240
	ctx.r11.s64 = 240;
	// stb r28,31(r31)
	REX_STORE_U8(ctx.r31.u32 + 31, ctx.r28.u8);
	// li r27,3
	ctx.r27.s64 = 3;
	// stb r28,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r28.u8);
	// li r30,2
	ctx.r30.s64 = 2;
	// li r29,-1
	ctx.r29.s64 = -1;
	// stb r27,32(r31)
	REX_STORE_U8(ctx.r31.u32 + 32, ctx.r27.u8);
	// li r26,1
	ctx.r26.s64 = 1;
	// stb r30,34(r31)
	REX_STORE_U8(ctx.r31.u32 + 34, ctx.r30.u8);
	// addi r10,r31,40
	ctx.r10.s64 = ctx.r31.s64 + 40;
	// stb r29,35(r31)
	REX_STORE_U8(ctx.r31.u32 + 35, ctx.r29.u8);
	// stb r27,36(r31)
	REX_STORE_U8(ctx.r31.u32 + 36, ctx.r27.u8);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// stb r26,37(r31)
	REX_STORE_U8(ctx.r31.u32 + 37, ctx.r26.u8);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822145DC:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x822145dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822145DC;
	// li r10,8331
	ctx.r10.s64 = 8331;
	// addi r11,r31,999
	ctx.r11.s64 = ctx.r31.s64 + 999;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_822145F0:
	// stbu r28,1(r11)
	ea = 1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r28.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x822145f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822145F0;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r31,9336
	ctx.r10.s64 = ctx.r31.s64 + 9336;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8221460C:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8221460c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8221460C;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r31,9400
	ctx.r10.s64 = ctx.r31.s64 + 9400;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82214628:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82214628
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214628;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r31,9464
	ctx.r10.s64 = ctx.r31.s64 + 9464;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82214644:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82214644
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214644;
	// li r11,240
	ctx.r11.s64 = 240;
	// addi r10,r31,9528
	ctx.r10.s64 = ctx.r31.s64 + 9528;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82214660:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82214660
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214660;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r31,9768
	ctx.r10.s64 = ctx.r31.s64 + 9768;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8221467C:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8221467c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8221467C;
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r31,12984
	ctx.r10.s64 = ctx.r31.s64 + 12984;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82214698:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x82214698
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214698;
	// li r11,800
	ctx.r11.s64 = 800;
	// addi r10,r31,9784
	ctx.r10.s64 = ctx.r31.s64 + 9784;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822146B4:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x822146b4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822146B4;
	// stw r28,9332(r31)
	REX_STORE_U32(ctx.r31.u32 + 9332, ctx.r28.u32);
	// bl 0x82213210
	ctx.lr = 0x822146C4;
	sub_82213210(ctx, base);
	// lbz r11,19280(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 19280);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822146d8
	if (ctx.cr0.eq) goto loc_822146D8;
	// stb r30,13000(r31)
	REX_STORE_U8(ctx.r31.u32 + 13000, ctx.r30.u8);
	// b 0x822146dc
	goto loc_822146DC;
loc_822146D8:
	// stb r26,13000(r31)
	REX_STORE_U8(ctx.r31.u32 + 13000, ctx.r26.u8);
loc_822146DC:
	// li r11,16
	ctx.r11.s64 = 16;
	// addi r10,r31,13001
	ctx.r10.s64 = ctx.r31.s64 + 13001;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_822146F0:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x822146f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822146F0;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r31,13016
	ctx.r11.s64 = ctx.r31.s64 + 13016;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82214704:
	// stw r29,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r29.u32);
	// stwu r29,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r29.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82214704
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214704;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r31,13272
	ctx.r11.s64 = ctx.r31.s64 + 13272;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,9
	ctx.r10.s64 = 589824;
	// ori r10,r10,10176
	ctx.r10.u64 = ctx.r10.u64 | 10176;
loc_82214724:
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// stwu r10,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82214724
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214724;
	// addi r8,r31,13916
	ctx.r8.s64 = ctx.r31.s64 + 13916;
	// addi r11,r31,13532
	ctx.r11.s64 = ctx.r31.s64 + 13532;
	// li r7,32
	ctx.r7.s64 = 32;
loc_8221473C:
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_82214748:
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stbx r28,r8,r10
	REX_STORE_U8(ctx.r8.u32 + ctx.r10.u32, ctx.r28.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x82214748
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214748;
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// addi r8,r8,3
	ctx.r8.s64 = ctx.r8.s64 + 3;
	// bne 0x8221473c
	if (!ctx.cr0.eq) goto loc_8221473C;
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r11,r31,14011
	ctx.r11.s64 = ctx.r31.s64 + 14011;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82214774:
	// stb r28,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r28.u8);
	// stbu r28,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r28.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x82214774
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214774;
	// li r11,256
	ctx.r11.s64 = 256;
	// stb r26,14076(r31)
	REX_STORE_U8(ctx.r31.u32 + 14076, ctx.r26.u8);
	// addi r10,r31,14080
	ctx.r10.s64 = ctx.r31.s64 + 14080;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82214798:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82214798
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82214798;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8222E490) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8222E498;
	__savegprlr_28(ctx, base);
	// stfd f30,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f30.u64);
	// stfd f31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f1,88(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f2,108(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r29,r11,4440
	ctx.r29.s64 = ctx.r11.s64 + 4440;
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r6,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// cmpwi cr6,r7,159
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 159, ctx.xer);
	// lfs f1,-2828(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2828);
	ctx.f1.f64 = double(temp.f32);
	// blt cr6,0x8222e530
	if (ctx.cr6.lt) goto loc_8222E530;
	// cmpwi cr6,r7,160
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 160, ctx.xer);
	// ble cr6,0x8222e508
	if (!ctx.cr6.gt) goto loc_8222E508;
	// cmpwi cr6,r7,162
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 162, ctx.xer);
	// bgt cr6,0x8222e530
	if (ctx.cr6.gt) goto loc_8222E530;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r31,r11,12468
	ctx.r31.s64 = ctx.r11.s64 + 12468;
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	ctx.cr6.compare(ctx.f2.f64, ctx.f31.f64);
	// lfs f0,-232(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bgt cr6,0x8222e558
	if (ctx.cr6.gt) goto loc_8222E558;
	// lfs f0,1908(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8222e554
	goto loc_8222E554;
loc_8222E508:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r31,r11,12468
	ctx.r31.s64 = ctx.r11.s64 + 12468;
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	ctx.cr6.compare(ctx.f2.f64, ctx.f31.f64);
	// lfs f0,-232(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bgt cr6,0x8222e558
	if (ctx.cr6.gt) goto loc_8222E558;
	// lfs f0,13940(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 13940);
	ctx.f0.f64 = double(temp.f32);
	// b 0x8222e554
	goto loc_8222E554;
loc_8222E530:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r31,r11,12468
	ctx.r31.s64 = ctx.r11.s64 + 12468;
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f2,f31
	ctx.cr6.compare(ctx.f2.f64, ctx.f31.f64);
	// lfs f0,-232(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bgt cr6,0x8222e558
	if (ctx.cr6.gt) goto loc_8222E558;
	// lfs f0,-2904(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2904);
	ctx.f0.f64 = double(temp.f32);
loc_8222E554:
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
loc_8222E558:
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,21588(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 21588);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8222E564;
	sub_825A4A40(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f1,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f2,-10852(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -10852);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,17984(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17984);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8222E57C;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f1,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f2,-232(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f30,80(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 80);
	ctx.f30.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8222E594;
	sub_825A4A40(ctx, base);
	// lfs f0,1908(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x8222e5a8
	if (!ctx.cr6.gt) goto loc_8222E5A8;
	// li r11,2
	ctx.r11.s64 = 2;
loc_8222E5A8:
	// addi r3,r30,24
	ctx.r3.s64 = ctx.r30.s64 + 24;
	// stb r11,68(r30)
	REX_STORE_U8(ctx.r30.u32 + 68, ctx.r11.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,32
	ctx.r5.s64 = 32;
	// bl 0x8273a030
	ctx.lr = 0x8222E5BC;
	sub_8273A030(ctx, base);
	// lfs f0,-232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,56(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 56, temp.u32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,52(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// stfs f30,60(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 60, temp.u32);
	// lfs f0,48(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,64(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 64, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-56(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f31,-48(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8223E1B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8223E1C0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne cr6,0x8223e1ec
	if (!ctx.cr6.eq) goto loc_8223E1EC;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8223e1ec
	if (ctx.cr6.gt) goto loc_8223E1EC;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// b 0x8223e2a0
	goto loc_8223E2A0;
loc_8223E1EC:
	// lwz r11,20(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 20);
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x8223e29c
	if (!ctx.cr6.lt) goto loc_8223E29C;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8223e29c
	if (ctx.cr6.gt) goto loc_8223E29C;
	// lwz r10,24(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// subf r11,r29,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r29.u64;
	// addi r26,r27,4
	ctx.r26.s64 = ctx.r27.s64 + 4;
	// addi r30,r11,1
	ctx.r30.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x8223e224
	if (ctx.cr6.lt) goto loc_8223E224;
	// lwz r11,4(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// b 0x8223e228
	goto loc_8223E228;
loc_8223E224:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8223E228:
	// add r31,r11,r5
	ctx.r31.u64 = ctx.r11.u64 + ctx.r5.u64;
	// b 0x8223e280
	goto loc_8223E280;
loc_8223E230:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi r29,0
	ctx.cr0.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq 0x8223e268
	if (ctx.cr0.eq) goto loc_8223E268;
	// add r8,r3,r29
	ctx.r8.u64 = ctx.r3.u64 + ctx.r29.u64;
loc_8223E248:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8223e268
	if (!ctx.cr0.eq) goto loc_8223E268;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8223e248
	if (!ctx.cr6.eq) goto loc_8223E248;
loc_8223E268:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x8223e2a8
	if (ctx.cr0.eq) goto loc_8223E2A8;
	// subf r11,r3,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r3.u64;
	// addi r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 1;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r30,r11,-1
	ctx.r30.s64 = ctx.r11.s64 + -1;
loc_8223E280:
	// lbz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsb r4,r10
	ctx.r4.s64 = ctx.r10.s8;
	// bl 0x82738ba0
	ctx.lr = 0x8223E294;
	sub_82738BA0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8223e230
	if (!ctx.cr0.eq) goto loc_8223E230;
loc_8223E29C:
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8223E2A0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_8223E2A8:
	// lwz r11,24(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 24);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// blt cr6,0x8223e2bc
	if (ctx.cr6.lt) goto loc_8223E2BC;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// b 0x8223e2c0
	goto loc_8223E2C0;
loc_8223E2BC:
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
loc_8223E2C0:
	// subf r3,r11,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r11.u64;
	// b 0x8223e2a0
	goto loc_8223E2A0;
}

DEFINE_REX_FUNC(sub_82248698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822486A0;
	__savegprlr_26(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r9,32(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + 32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// beq 0x822486c4
	if (ctx.cr0.eq) goto loc_822486C4;
	// addi r26,r26,-3076
	ctx.r26.s64 = ctx.r26.s64 + -3076;
	// b 0x822486c8
	goto loc_822486C8;
loc_822486C4:
	// addi r26,r26,-3072
	ctx.r26.s64 = ctx.r26.s64 + -3072;
loc_822486C8:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// addi r31,r28,31444
	ctx.r31.s64 = ctx.r28.s64 + 31444;
	// bne cr6,0x822486dc
	if (!ctx.cr6.eq) goto loc_822486DC;
	// addi r31,r28,596
	ctx.r31.s64 = ctx.r28.s64 + 596;
	// beq cr6,0x822486e8
	if (ctx.cr6.eq) goto loc_822486E8;
loc_822486DC:
	// lwz r11,268(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 268);
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// b 0x822486f0
	goto loc_822486F0;
loc_822486E8:
	// lwz r11,252(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 252);
	// lwz r10,248(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
loc_822486F0:
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x8224870c
	if (ctx.cr6.lt) goto loc_8224870C;
loc_82248704:
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x822489b4
	goto loc_822489B4;
loc_8224870C:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82248704
	if (!ctx.cr6.lt) goto loc_82248704;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x8224872c
	if (ctx.cr6.eq) goto loc_8224872C;
	// lwz r10,264(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// b 0x82248730
	goto loc_82248730;
loc_8224872C:
	// lwz r10,248(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
loc_82248730:
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82248744;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bge cr6,0x82248704
	if (!ctx.cr6.lt) goto loc_82248704;
	// lwz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
loc_8224875C:
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82248778
	if (ctx.cr0.eq) goto loc_82248778;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,28(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8224878c
	if (ctx.cr6.eq) goto loc_8224878C;
loc_82248778:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,3856
	ctx.r11.s64 = ctx.r11.s64 + 3856;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// blt cr6,0x8224875c
	if (ctx.cr6.lt) goto loc_8224875C;
	// b 0x82248790
	goto loc_82248790;
loc_8224878C:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
loc_82248790:
	// mulli r9,r9,3856
	ctx.r9.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(3856));
	// add r29,r9,r31
	ctx.r29.u64 = ctx.r9.u64 + ctx.r31.u64;
	// lwz r27,3852(r29)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r29.u32 + 3852);
	// cmplwi cr6,r27,64
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 64, ctx.xer);
	// bge cr6,0x82248704
	if (!ctx.cr6.lt) goto loc_82248704;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822487d4
	if (!ctx.cr0.eq) goto loc_822487D4;
	// stb r10,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r10.u8);
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_822487D4:
	// mulli r11,r27,60
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(60));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stb r10,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r10.u8);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// lwzx r3,r10,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82248814;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f1,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// lbz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// stb r11,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r11.u8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfs f0,24(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// lfs f0,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// lfs f0,12(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224885C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r26,r31,36
	ctx.r26.s64 = ctx.r31.s64 + 36;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// lwz r11,248(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 248);
	// lwz r6,4(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r5,0(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,28(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822488A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// li r10,255
	ctx.r10.s64 = 255;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// li r9,0
	ctx.r9.s64 = 0;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r31,52
	ctx.r30.s64 = ctx.r31.s64 + 52;
	// lvx128 v1,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r7,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r7.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// stw r10,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// stw r9,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r9.u32);
	// bl 0x8221ada0
	ctx.lr = 0x822488F0;
	sub_8221ADA0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x823bcf40
	ctx.lr = 0x82248900;
	sub_823BCF40(ctx, base);
	// lfs f0,40(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,36(r31)
	REX_STORE_U64(ctx.r31.u32 + 36, ctx.r11.u64);
	// lwz r11,3852(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 3852);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,3852(r29)
	REX_STORE_U32(ctx.r29.u32 + 3852, ctx.r11.u32);
loc_822489B4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8226BC70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8226BC78;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af10
	ctx.lr = 0x8226BC80;
	__savefpr_22(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r27,-32227
	ctx.r27.s64 = -2112028672;
	// addi r30,r11,12472
	ctx.r30.s64 = ctx.r11.s64 + 12472;
	// addi r11,r27,17696
	ctx.r11.s64 = ctx.r27.s64 + 17696;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// lfs f1,-236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -236);
	ctx.f1.f64 = double(temp.f32);
	// lfs f31,17712(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17712);
	ctx.f31.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8226BCB0;
	sub_825A4A40(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// addi r31,r11,1604
	ctx.r31.s64 = ctx.r11.s64 + 1604;
	// lfs f2,-8016(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -8016);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8226BCCC;
	sub_825A4A40(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// lfs f2,17696(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 17696);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lfs f1,-16652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16652);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8226BCE4;
	sub_825A4A40(ctx, base);
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f1.f64;
	// lfs f2,-3164(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -3164);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// bl 0x825a4a40
	ctx.lr = 0x8226BCF8;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r5,4(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// addi r29,r11,-4080
	ctx.r29.s64 = ctx.r11.s64 + -4080;
	// lfs f2,2800(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2800);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2796(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8226BD14;
	sub_825A4A40(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f30,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// fmr f26,f1
	ctx.f26.f64 = ctx.f1.f64;
	// lfs f25,244(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 244);
	ctx.f25.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lfs f23,-10560(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -10560);
	ctx.f23.f64 = double(temp.f32);
	// addi r29,r11,22072
	ctx.r29.s64 = ctx.r11.s64 + 22072;
	// lfs f22,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f22.f64 = double(temp.f32);
	// lfs f24,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
loc_8226BD40:
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// bne cr6,0x8226bd50
	if (!ctx.cr6.eq) goto loc_8226BD50;
	// fadds f30,f30,f23
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f30.f64 + ctx.f23.f64));
	// b 0x8226bd60
	goto loc_8226BD60;
loc_8226BD50:
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// bne cr6,0x8226bd60
	if (!ctx.cr6.eq) goto loc_8226BD60;
	// fsubs f30,f30,f23
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f30.f64 - ctx.f23.f64));
	// fmuls f31,f31,f22
	ctx.f31.f64 = double(float(ctx.f31.f64 * ctx.f22.f64));
loc_8226BD60:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 48);
	// li r4,140
	ctx.r4.s64 = 140;
	// stfs f30,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x8226BD74;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8226bdb8
	if (ctx.cr0.eq) goto loc_8226BDB8;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f27,100(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// stfs f24,128(r1)
	temp.f32 = float(ctx.f24.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f29,132(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f28,136(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// stfs f26,140(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmr f1,f25
	ctx.f1.f64 = ctx.f25.f64;
	// bl 0x8221e078
	ctx.lr = 0x8226BDB0;
	sub_8221E078(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8226bdbc
	goto loc_8226BDBC;
loc_8226BDB8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8226BDBC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8226be00
	if (ctx.cr6.eq) goto loc_8226BE00;
	// lis r11,-13210
	ctx.r11.s64 = -865730560;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// ori r11,r11,153
	ctx.r11.u64 = ctx.r11.u64 | 153;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x8226BDDC;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8226be00
	if (!ctx.cr6.eq) goto loc_8226BE00;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8226BE00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8226BE00:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r28,3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 3, ctx.xer);
	// blt cr6,0x8226bd40
	if (ctx.cr6.lt) goto loc_8226BD40;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af5c
	ctx.lr = 0x8226BE18;
	__restfpr_22(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8227BB60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r11,r11,2880
	ctx.r11.s64 = ctx.r11.s64 + 2880;
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r10,2
	ctx.r10.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8227bbfc
	if (!ctx.cr0.eq) goto loc_8227BBFC;
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// lfs f13,4(r3)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-20(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpeqfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq 0x8227bc00
	if (ctx.cr0.eq) goto loc_8227BC00;
loc_8227BBFC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8227BC00:
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82289210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82289218;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af0c
	ctx.lr = 0x82289220;
	__savefpr_21(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r28,r3,1
	ctx.r28.s64 = ctx.r3.s64 + 65536;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r28,r28,-3048
	ctx.r28.s64 = ctx.r28.s64 + -3048;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r4,r3,88
	ctx.r4.s64 = ctx.r3.s64 + 88;
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r7,204(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 204);
	// lwz r7,64(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 64);
	// lfs f0,4(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822892A4;
	sub_8255F918(ctx, base);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r8,r9,-30128
	ctx.r8.s64 = ctx.r9.s64 + -30128;
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// addi r7,r10,17284
	ctx.r7.s64 = ctx.r10.s64 + 17284;
	// lfs f25,17284(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17284);
	ctx.f25.f64 = double(temp.f32);
	// addis r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 65536;
	// lfs f23,-30128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30128);
	ctx.f23.f64 = double(temp.f32);
	// lfs f22,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f22.f64 = double(temp.f32);
	// li r29,16
	ctx.r29.s64 = 16;
	// lfs f29,1320(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 1320);
	ctx.f29.f64 = double(temp.f32);
	// addi r31,r31,-2196
	ctx.r31.s64 = ctx.r31.s64 + -2196;
	// lfs f26,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f26.f64 = double(temp.f32);
	// lfs f27,17600(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 17600);
	ctx.f27.f64 = double(temp.f32);
	// lfs f24,-3168(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -3168);
	ctx.f24.f64 = double(temp.f32);
	// lfs f30,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f30.f64 = double(temp.f32);
	// lfs f21,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f21.f64 = double(temp.f32);
loc_822892EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f26
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f26.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822892FC;
	sub_825A4A40(ctx, base);
	// stfs f1,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f25
	ctx.f1.f64 = ctx.f25.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82289310;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f24
	ctx.f1.f64 = ctx.f24.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82289324;
	sub_825A4A40(ctx, base);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f30.f64;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8228933c
	if (!ctx.cr6.eq) goto loc_8228933C;
	// fmr f31,f21
	ctx.f31.f64 = ctx.f21.f64;
loc_8228933C:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f31,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f28.f64));
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f1,140(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f1,136(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f1,132(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822893A0;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,6
	ctx.r4.s64 = 6;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// ld r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 12);
	// std r11,4(r31)
	REX_STORE_U64(ctx.r31.u32 + 4, ctx.r11.u64);
	// bl 0x825a49b0
	ctx.lr = 0x822893CC;
	sub_825A49B0(ctx, base);
	// addi r11,r3,5
	ctx.r11.s64 = ctx.r3.s64 + 5;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f23
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f23.f64;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822893E4;
	sub_825A4A40(ctx, base);
	// stfs f1,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,1132(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1132);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f22
	ctx.f1.f64 = ctx.f22.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822893F8;
	sub_825A4A40(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// stfsu f0,52(r31)
	ea = 52 + ctx.r31.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r31.u32 = ea;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x822892ec
	if (!ctx.cr0.eq) goto loc_822892EC;
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af58
	ctx.lr = 0x82289414;
	__restfpr_21(ctx, base);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8229AB48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8229AB50;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-948
	ctx.r30.s64 = ctx.r30.s64 + -948;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229ab7c
	if (ctx.cr0.eq) goto loc_8229AB7C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229AB7C;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229AB7C:
	// li r10,5
	ctx.r10.s64 = 5;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r9,r1,108
	ctx.r9.s64 = ctx.r1.s64 + 108;
	// addi r11,r11,-968
	ctx.r11.s64 = ctx.r11.s64 + -968;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8229AB94:
	// lwzu r10,4(r8)
	ea = 4 + ctx.r8.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r8.u32 = ea;
	// stwu r10,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8229ab94
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8229AB94;
	// li r28,0
	ctx.r28.s64 = 0;
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229abbc
	if (ctx.cr0.eq) goto loc_8229ABBC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229ABBC;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229ABBC:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lbz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lis r9,-32241
	ctx.r9.s64 = -2112946176;
	// lis r8,0
	ctx.r8.s64 = 0;
	// addi r26,r11,-8644
	ctx.r26.s64 = ctx.r11.s64 + -8644;
	// ori r29,r8,64556
	ctx.r29.u64 = ctx.r8.u64 | 64556;
	// lfs f30,-8644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f30.f64 = double(temp.f32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,20068(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20068);
	ctx.f31.f64 = double(temp.f32);
	// beq 0x8229ac8c
	if (ctx.cr0.eq) goto loc_8229AC8C;
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r3,120(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// bl 0x825a48b0
	ctx.lr = 0x8229ABF8;
	sub_825A48B0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lbz r8,124(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 124);
	// lbz r7,125(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 125);
	// ori r11,r11,62868
	ctx.r11.u64 = ctx.r11.u64 | 62868;
	// ori r10,r10,62869
	ctx.r10.u64 = ctx.r10.u64 | 62869;
	// lbz r4,126(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 126);
	// cmplwi cr6,r4,8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 8, ctx.xer);
	// stbx r8,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r8.u8);
	// stbx r7,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r7.u8);
	// bne cr6,0x8229ac34
	if (!ctx.cr6.eq) goto loc_8229AC34;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,11
	ctx.r10.s64 = 11;
	// ori r11,r11,62376
	ctx.r11.u64 = ctx.r11.u64 | 62376;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
loc_8229AC34:
	// cmplwi cr6,r4,10
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 10, ctx.xer);
	// bge cr6,0x8229ac44
	if (!ctx.cr6.lt) goto loc_8229AC44;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8229d048
	ctx.lr = 0x8229AC44;
	sub_8229D048(ctx, base);
loc_8229AC44:
	// bl 0x82429a18
	ctx.lr = 0x8229AC48;
	sub_82429A18(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// lwz r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8229ac6c
	if (!ctx.cr6.gt) goto loc_8229AC6C;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x8229ac70
	goto loc_8229AC70;
loc_8229AC6C:
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_8229AC70:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
loc_8229AC8C:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-884
	ctx.r30.s64 = ctx.r30.s64 + -884;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229aca8
	if (ctx.cr0.eq) goto loc_8229ACA8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229ACA8;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229ACA8:
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// addi r27,r27,-916
	ctx.r27.s64 = ctx.r27.s64 + -916;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8273a030
	ctx.lr = 0x8229ACC0;
	sub_8273A030(ctx, base);
	// stb r28,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r28.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229acd8
	if (ctx.cr0.eq) goto loc_8229ACD8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229ACD8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229ACD8:
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r25,-32111
	ctx.r25.s64 = -2104426496;
	// ori r24,r10,64552
	ctx.r24.u64 = ctx.r10.u64 | 64552;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229ad90
	if (ctx.cr0.eq) goto loc_8229AD90;
	// lwzx r10,r31,r24
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// add r11,r31,r24
	ctx.r11.u64 = ctx.r31.u64 + ctx.r24.u64;
	// ld r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 116);
	// lbz r8,124(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 124);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// std r9,20(r10)
	REX_STORE_U64(ctx.r10.u32 + 20, ctx.r9.u64);
	// lwzx r9,r31,r24
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// ld r10,2880(r25)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r25.u32 + 2880);
	// std r10,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r10.u64);
	// ld r10,2880(r25)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r25.u32 + 2880);
	// std r10,12(r9)
	REX_STORE_U64(ctx.r9.u32 + 12, ctx.r10.u64);
	// beq 0x8229ad48
	if (ctx.cr0.eq) goto loc_8229AD48;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lis r9,0
	ctx.r9.s64 = 0;
	// ld r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// lwz r7,136(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// ori r9,r9,63124
	ctx.r9.u64 = ctx.r9.u64 | 63124;
	// std r8,36(r10)
	REX_STORE_U64(ctx.r10.u32 + 36, ctx.r8.u64);
	// ld r10,2880(r25)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r25.u32 + 2880);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// std r10,28(r11)
	REX_STORE_U64(ctx.r11.u32 + 28, ctx.r10.u64);
	// stwx r7,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r7.u32);
loc_8229AD48:
	// bl 0x82429a18
	ctx.lr = 0x8229AD4C;
	sub_82429A18(ctx, base);
	// fmuls f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f31.f64));
	// lwz r10,140(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x8229ad70
	if (!ctx.cr6.gt) goto loc_8229AD70;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x8229ad74
	goto loc_8229AD74;
loc_8229AD70:
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
loc_8229AD74:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
loc_8229AD90:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-848
	ctx.r30.s64 = ctx.r30.s64 + -848;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229adac
	if (ctx.cr0.eq) goto loc_8229ADAC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229ADAC;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229ADAC:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-852
	ctx.r11.s64 = ctx.r11.s64 + -852;
	// lbz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229add0
	if (ctx.cr0.eq) goto loc_8229ADD0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229ADD0;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229ADD0:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r27,1
	ctx.r27.s64 = 1;
	// beq 0x8229ae38
	if (ctx.cr0.eq) goto loc_8229AE38;
	// bl 0x8242a5e0
	ctx.lr = 0x8229ADE0;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229adf0
	if (!ctx.cr0.eq) goto loc_8229ADF0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8229adf4
	goto loc_8229ADF4;
loc_8229ADF0:
	// bl 0x8242aa28
	ctx.lr = 0x8229ADF4;
	sub_8242AA28(ctx, base);
loc_8229ADF4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229ae38
	if (!ctx.cr0.eq) goto loc_8229AE38;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-2460
	ctx.r30.s64 = ctx.r30.s64 + -2460;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8229ae38
	if (!ctx.cr0.eq) goto loc_8229AE38;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229ae28
	if (ctx.cr6.eq) goto loc_8229AE28;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8257e030
	ctx.lr = 0x8229AE28;
	sub_8257E030(ctx, base);
loc_8229AE28:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,5
	ctx.r3.s64 = 5;
	// bl 0x822140d0
	ctx.lr = 0x8229AE34;
	sub_822140D0(ctx, base);
	// stb r27,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r27.u8);
loc_8229AE38:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-812
	ctx.r30.s64 = ctx.r30.s64 + -812;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229ae54
	if (ctx.cr0.eq) goto loc_8229AE54;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229AE54;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229AE54:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-816
	ctx.r11.s64 = ctx.r11.s64 + -816;
	// lbz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229ae78
	if (ctx.cr0.eq) goto loc_8229AE78;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229AE78;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229AE78:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8229aeac
	if (ctx.cr0.eq) goto loc_8229AEAC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,63100
	ctx.r11.u64 = ctx.r11.u64 | 63100;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8229aeac
	if (!ctx.cr6.gt) goto loc_8229AEAC;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2432
	ctx.r11.s64 = ctx.r11.s64 + -2432;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8229aeac
	if (!ctx.cr0.eq) goto loc_8229AEAC;
	// stb r27,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r27.u8);
loc_8229AEAC:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-776
	ctx.r30.s64 = ctx.r30.s64 + -776;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229aec8
	if (ctx.cr0.eq) goto loc_8229AEC8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229AEC8;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229AEC8:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-780
	ctx.r11.s64 = ctx.r11.s64 + -780;
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// sth r10,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r10.u16);
	// beq 0x8229aef0
	if (ctx.cr0.eq) goto loc_8229AEF0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229AEF0;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229AEF0:
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229af38
	if (ctx.cr0.eq) goto loc_8229AF38;
	// bl 0x8242a5e0
	ctx.lr = 0x8229AF00;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229af10
	if (!ctx.cr0.eq) goto loc_8229AF10;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8229af14
	goto loc_8229AF14;
loc_8229AF10:
	// bl 0x8242aa28
	ctx.lr = 0x8229AF14;
	sub_8242AA28(ctx, base);
loc_8229AF14:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229af38
	if (!ctx.cr0.eq) goto loc_8229AF38;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2330
	ctx.r11.s64 = ctx.r11.s64 + -2330;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// blt cr6,0x8229af38
	if (ctx.cr6.lt) goto loc_8229AF38;
	// lbz r10,81(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
loc_8229AF38:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-728
	ctx.r30.s64 = ctx.r30.s64 + -728;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229af54
	if (ctx.cr0.eq) goto loc_8229AF54;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229AF54;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229AF54:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-744
	ctx.r11.s64 = ctx.r11.s64 + -744;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r7,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// stw r11,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229af98
	if (ctx.cr0.eq) goto loc_8229AF98;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229AF98;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229AF98:
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b104
	if (ctx.cr0.eq) goto loc_8229B104;
	// bl 0x8242a5e0
	ctx.lr = 0x8229AFA8;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229afb8
	if (!ctx.cr0.eq) goto loc_8229AFB8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8229afbc
	goto loc_8229AFBC;
loc_8229AFB8:
	// bl 0x8242aa28
	ctx.lr = 0x8229AFBC;
	sub_8242AA28(ctx, base);
loc_8229AFBC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229b104
	if (!ctx.cr0.eq) goto loc_8229B104;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229b000
	if (ctx.cr6.eq) goto loc_8229B000;
	// lwz r8,24(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// lwz r7,20(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// subf r8,r7,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r7.u64;
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// cmpw cr6,r9,r8
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8229b000
	if (!ctx.cr6.lt) goto loc_8229B000;
	// rotlwi r11,r7,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r7.u32, 0);
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
loc_8229B000:
	// lis r9,0
	ctx.r9.s64 = 0;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lis r8,0
	ctx.r8.s64 = 0;
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// ld r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r31.u32 + 88);
	// ori r9,r9,63228
	ctx.r9.u64 = ctx.r9.u64 | 63228;
	// addi r30,r30,-2664
	ctx.r30.s64 = ctx.r30.s64 + -2664;
	// ori r8,r8,63232
	ctx.r8.u64 = ctx.r8.u64 | 63232;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r7,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r7.u64);
	// stwx r10,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r10.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// stdx r11,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x8229B044;
	sub_82322D08(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-30848
	ctx.r11.s64 = ctx.r11.s64 + -30848;
	// fabs f12,f13
	ctx.f12.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// addi r10,r10,-2660
	ctx.r10.s64 = ctx.r10.s64 + -2660;
	// lfs f0,-32268(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + -32268);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f11,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f10,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f10.f64 = double(temp.f32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r3,-32111
	ctx.r3.s64 = -2104426496;
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r5,0
	ctx.r5.s64 = 0;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r4,0
	ctx.r4.s64 = 0;
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// fdivs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 / ctx.f12.f64));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f13,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// ori r5,r5,63240
	ctx.r5.u64 = ctx.r5.u64 | 63240;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// ori r9,r4,63248
	ctx.r9.u64 = ctx.r4.u64 | 63248;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,0(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// ld r11,3456(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 3456);
	// stwx r28,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r28.u32);
	// stdx r11,r31,r5
	REX_STORE_U64(ctx.r31.u32 + ctx.r5.u32, ctx.r11.u64);
loc_8229B104:
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
loc_8229B108:
	// addi r9,r1,97
	ctx.r9.s64 = ctx.r1.s64 + 97;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// stbx r28,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r28.u8);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// blt cr6,0x8229b108
	if (ctx.cr6.lt) goto loc_8229B108;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-688
	ctx.r30.s64 = ctx.r30.s64 + -688;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b140
	if (ctx.cr0.eq) goto loc_8229B140;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229B140;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229B140:
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r29,r29,-696
	ctx.r29.s64 = ctx.r29.s64 + -696;
	// li r5,7
	ctx.r5.s64 = 7;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8229B158;
	sub_8273A030(ctx, base);
	// stb r28,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r28.u8);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b170
	if (ctx.cr0.eq) goto loc_8229B170;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229B170;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229B170:
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b1b0
	if (ctx.cr0.eq) goto loc_8229B1B0;
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stb r28,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r28.u8);
loc_8229B184:
	// addi r10,r1,97
	ctx.r10.s64 = ctx.r1.s64 + 97;
	// lis r9,0
	ctx.r9.s64 = 0;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// ori r9,r9,64968
	ctx.r9.u64 = ctx.r9.u64 | 64968;
	// lbzx r6,r11,r10
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// clrlwi r10,r7,24
	ctx.r10.u64 = ctx.r7.u32 & 0xFF;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 6, ctx.xer);
	// stbx r6,r8,r9
	REX_STORE_U8(ctx.r8.u32 + ctx.r9.u32, ctx.r6.u8);
	// blt cr6,0x8229b184
	if (ctx.cr6.lt) goto loc_8229B184;
loc_8229B1B0:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-648
	ctx.r30.s64 = ctx.r30.s64 + -648;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b1cc
	if (ctx.cr0.eq) goto loc_8229B1CC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229B1CC;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229B1CC:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-656
	ctx.r11.s64 = ctx.r11.s64 + -656;
	// ori r10,r10,64884
	ctx.r10.u64 = ctx.r10.u64 | 64884;
	// ld r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// stwx r28,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r28.u32);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b200
	if (ctx.cr0.eq) goto loc_8229B200;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229B200;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229B200:
	// lbz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b284
	if (ctx.cr0.eq) goto loc_8229B284;
	// bl 0x8242a5e0
	ctx.lr = 0x8229B210;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8229b220
	if (!ctx.cr0.eq) goto loc_8229B220;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x8229b224
	goto loc_8229B224;
loc_8229B220:
	// bl 0x8242aa28
	ctx.lr = 0x8229B224;
	sub_8242AA28(ctx, base);
loc_8229B224:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8229b284
	if (ctx.cr0.eq) goto loc_8229B284;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// addi r9,r9,-2332
	ctx.r9.s64 = ctx.r9.s64 + -2332;
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8229b284
	if (!ctx.cr0.eq) goto loc_8229B284;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-2372
	ctx.r11.s64 = ctx.r11.s64 + -2372;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8229b284
	if (!ctx.cr6.gt) goto loc_8229B284;
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// subf. r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// ble 0x8229b270
	if (!ctx.cr0.gt) goto loc_8229B270;
	// lbz r10,466(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 466);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8229b284
	if (ctx.cr0.eq) goto loc_8229B284;
loc_8229B270:
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
	// stb r27,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r27.u8);
	// ori r11,r10,63205
	ctx.r11.u64 = ctx.r10.u64 | 63205;
	// stbx r27,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r27.u8);
loc_8229B284:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-600
	ctx.r30.s64 = ctx.r30.s64 + -600;
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b2a0
	if (ctx.cr0.eq) goto loc_8229B2A0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b44
	ctx.lr = 0x8229B2A0;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8229B2A0:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,-616
	ctx.r11.s64 = ctx.r11.s64 + -616;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stb r28,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r28.u8);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// stw r7,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r7.u32);
	// stw r11,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r11.u32);
	// lbz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b2e4
	if (ctx.cr0.eq) goto loc_8229B2E4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82855b34
	ctx.lr = 0x8229B2E4;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8229B2E4:
	// lbz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8229b344
	if (ctx.cr0.eq) goto loc_8229B344;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwzx r10,r31,r24
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r24.u32);
	// ld r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 116);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stb r27,466(r31)
	REX_STORE_U8(ctx.r31.u32 + 466, ctx.r27.u8);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lwz r6,124(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// ori r8,r8,64560
	ctx.r8.u64 = ctx.r8.u64 | 64560;
	// ori r7,r7,64564
	ctx.r7.u64 = ctx.r7.u64 | 64564;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// ld r11,2880(r25)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r25.u32 + 2880);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// std r9,20(r10)
	REX_STORE_U64(ctx.r10.u32 + 20, ctx.r9.u64);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stbx r27,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r27.u8);
	// stwx r6,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r6.u32);
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8229B344;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8229B344:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D2918) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82237858
	ctx.lr = 0x822D2930;
	sub_82237858(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d294c
	if (!ctx.cr6.eq) goto loc_822D294C;
	// li r10,6
	ctx.r10.s64 = 6;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_822D294C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_822D4088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822D4090;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r29,r10,624
	ctx.r29.s64 = ctx.r10.s64 + 624;
	// addi r11,r11,-3100
	ctx.r11.s64 = ctx.r11.s64 + -3100;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3076
	ctx.r30.s64 = ctx.r30.s64 + -3076;
	// lfs f0,-2184(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -2184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f1,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f13.f64)));
	// lfs f0,16468(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f12,f12,f1
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f1.f64));
	// stfs f12,0(r30)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822d40e0
	if (!ctx.cr6.gt) goto loc_822D40E0;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822D40E0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822d48c0
	ctx.lr = 0x822D40E8;
	sub_822D48C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// beq 0x822d419c
	if (ctx.cr0.eq) goto loc_822D419C;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r30,r30,-3144
	ctx.r30.s64 = ctx.r30.s64 + -3144;
	// bl 0x8222ff78
	ctx.lr = 0x822D410C;
	sub_8222FF78(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x822d4858
	ctx.lr = 0x822D4114;
	sub_822D4858(ctx, base);
	// clrlwi. r30,r3,24
	ctx.r30.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x822d4158
	if (ctx.cr0.eq) goto loc_822D4158;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822D4134;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x822d4158
	if (!ctx.cr0.eq) goto loc_822D4158;
loc_822D413C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d4408
	if (!ctx.cr6.eq) goto loc_822D4408;
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x822d4404
	goto loc_822D4404;
loc_822D4158:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x822d4180
	if (!ctx.cr6.eq) goto loc_822D4180;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822D4178;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// beq cr6,0x822d413c
	if (ctx.cr6.eq) goto loc_822D413C;
loc_822D4180:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d4408
	if (!ctx.cr6.eq) goto loc_822D4408;
	// li r10,1
	ctx.r10.s64 = 1;
	// b 0x822d4404
	goto loc_822D4404;
loc_822D419C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f31,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x822d43ac
	if (!ctx.cr6.lt) goto loc_822D43AC;
	// lfs f0,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822D41C4;
	sub_8222FF78(ctx, base);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-3128
	ctx.r10.s64 = ctx.r10.s64 + -3128;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x822D427C;
	sub_8231E0D8(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// ld r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r10,-3120
	ctx.r10.s64 = ctx.r10.s64 + -3120;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r8,1
	ctx.r8.s64 = 1;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bgt cr6,0x822d42c8
	if (ctx.cr6.gt) goto loc_822D42C8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D42C8:
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d4310
	if (ctx.cr0.eq) goto loc_822D4310;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f31
	ctx.cr6.compare(ctx.f12.f64, ctx.f31.f64);
	// blt cr6,0x822d4308
	if (ctx.cr6.lt) goto loc_822D4308;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D4308:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822d4388
	if (!ctx.cr0.eq) goto loc_822D4388;
loc_822D4310:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x822d4344
	if (ctx.cr6.lt) goto loc_822D4344;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D4344:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d43a4
	if (ctx.cr0.eq) goto loc_822D43A4;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r8
	ctx.r11.u64 = ctx.r8.u64;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x822d4380
	if (ctx.cr6.gt) goto loc_822D4380;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D4380:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d43a4
	if (ctx.cr0.eq) goto loc_822D43A4;
loc_822D4388:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d4408
	if (!ctx.cr6.eq) goto loc_822D4408;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// b 0x822d4408
	goto loc_822D4408;
loc_822D43A4:
	// std r9,0(r10)
	REX_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// b 0x822d4408
	goto loc_822D4408;
loc_822D43AC:
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x822D43B4;
	sub_8222FF78(ctx, base);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,-3128
	ctx.r4.s64 = ctx.r4.s64 + -3128;
	// bl 0x822d6708
	ctx.lr = 0x822D43C0;
	sub_822D6708(ctx, base);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x822d43d4
	if (ctx.cr6.lt) goto loc_822D43D4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822D43D4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d4408
	if (ctx.cr0.eq) goto loc_822D4408;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// ori r10,r10,62464
	ctx.r10.u64 = ctx.r10.u64 | 62464;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stbx r9,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u8);
	// cmpwi cr6,r8,-1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -1, ctx.xer);
	// bne cr6,0x822d4408
	if (!ctx.cr6.eq) goto loc_822D4408;
	// li r10,0
	ctx.r10.s64 = 0;
loc_822D4404:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_822D4408:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822F7BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addis r10,r3,1
	ctx.r10.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// addi r10,r10,13332
	ctx.r10.s64 = ctx.r10.s64 + 13332;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lfs f0,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,120(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1
	ctx.r9.s64 = 1;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822f7c04
	if (ctx.cr6.lt) goto loc_822F7C04;
	// li r9,0
	ctx.r9.s64 = 0;
loc_822F7C04:
	// clrlwi. r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x822f7c14
	if (ctx.cr0.eq) goto loc_822F7C14;
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
loc_822F7C14:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822f7c44
	if (!ctx.cr6.gt) goto loc_822F7C44;
	// lis r11,1
	ctx.r11.s64 = 65536;
	// li r9,1
	ctx.r9.s64 = 1;
	// ori r11,r11,13396
	ctx.r11.u64 = ctx.r11.u64 | 13396;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// stw r9,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r9.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
loc_822F7C44:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,92(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r11,r11,-32400
	ctx.r11.s64 = ctx.r11.s64 + -32400;
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 92, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82300990) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82300998;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// ori r11,r11,62440
	ctx.r11.u64 = ctx.r11.u64 | 62440;
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,116
	ctx.r4.s64 = 116;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// lwz r3,48(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x825e02a0
	ctx.lr = 0x823009CC;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82300a10
	if (ctx.cr0.eq) goto loc_82300A10;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r4,24(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f1,244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82240940
	ctx.lr = 0x823009EC;
	sub_82240940(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,5124
	ctx.r11.s64 = ctx.r11.s64 + 5124;
	// addi r10,r10,5184
	ctx.r10.s64 = ctx.r10.s64 + 5184;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// sth r11,112(r31)
	REX_STORE_U16(ctx.r31.u32 + 112, ctx.r11.u16);
	// b 0x82300a14
	goto loc_82300A14;
loc_82300A10:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82300A14:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82300a74
	if (ctx.cr6.eq) goto loc_82300A74;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82300A34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82300A40;
	sub_82222AD8(ctx, base);
	// addis r10,r29,1
	ctx.r10.s64 = ctx.r29.s64 + 65536;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,-2656
	ctx.r10.s64 = ctx.r10.s64 + -2656;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82300a74
	if (!ctx.cr6.eq) goto loc_82300A74;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82300A74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82300A74:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823039E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,466(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 466);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82303a18
	if (ctx.cr0.eq) goto loc_82303A18;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82303A18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82303A18:
	// lis r11,0
	ctx.r11.s64 = 0;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82303A34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823061A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r30,r30,-3076
	ctx.r30.s64 = ctx.r30.s64 + -3076;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f1,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// lbz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82306204
	if (ctx.cr0.eq) goto loc_82306204;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,9
	ctx.r4.s64 = 9;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x823061FC;
	sub_8224A2A0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r11.u8);
loc_82306204:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r10,r10,-3096
	ctx.r10.s64 = ctx.r10.s64 + -3096;
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f12
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// lfs f0,-25240(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r10)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8230625c
	if (!ctx.cr6.gt) goto loc_8230625C;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// addi r11,r11,-3080
	ctx.r11.s64 = ctx.r11.s64 + -3080;
	// addi r9,r9,19392
	ctx.r9.s64 = ctx.r9.s64 + 19392;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x8230625c
	if (ctx.cr6.eq) goto loc_8230625C;
	// lis r9,-32208
	ctx.r9.s64 = -2110783488;
	// stfs f1,0(r10)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r9,19392
	ctx.r9.s64 = ctx.r9.s64 + 19392;
	// stb r10,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r10.u8);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
loc_8230625C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82309BC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82309BD0;
	__savegprlr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r23,r3,1
	ctx.r23.s64 = ctx.r3.s64 + 65536;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r23,r23,-3160
	ctx.r23.s64 = ctx.r23.s64 + -3160;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309ee4
	if (ctx.cr6.eq) goto loc_82309EE4;
	// addis r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 65536;
	// lis r8,0
	ctx.r8.s64 = 0;
	// addi r9,r9,-2980
	ctx.r9.s64 = ctx.r9.s64 + -2980;
	// ori r24,r8,62552
	ctx.r24.u64 = ctx.r8.u64 | 62552;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// li r22,1
	ctx.r22.s64 = 1;
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// li r26,0
	ctx.r26.s64 = 0;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// addi r28,r11,32720
	ctx.r28.s64 = ctx.r11.s64 + 32720;
	// addi r25,r10,-588
	ctx.r25.s64 = ctx.r10.s64 + -588;
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x82309dd8
	if (ctx.cr0.eq) goto loc_82309DD8;
	// lwzx r11,r3,r24
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r24.u32);
	// add r29,r3,r24
	ctx.r29.u64 = ctx.r3.u64 + ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309c70
	if (ctx.cr6.eq) goto loc_82309C70;
	// lwz r10,-12816(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -12816);
	// rlwinm r8,r11,4,12,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82309c6c
	if (!ctx.cr6.eq) goto loc_82309C6C;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309c6c
	if (ctx.cr6.eq) goto loc_82309C6C;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82309c6c
	if (!ctx.cr0.eq) goto loc_82309C6C;
	// stb r22,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r22.u8);
loc_82309C6C:
	// stw r26,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r26.u32);
loc_82309C70:
	// stb r26,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r26.u8);
	// addi r4,r30,88
	ctx.r4.s64 = ctx.r30.s64 + 88;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8255f918
	ctx.lr = 0x82309C84;
	sub_8255F918(ctx, base);
	// addis r31,r30,1
	ctx.r31.s64 = ctx.r30.s64 + 65536;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r31,r31,-3136
	ctx.r31.s64 = ctx.r31.s64 + -3136;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfs f0,1608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82309CEC;
	sub_8255F918(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r4,336
	ctx.r4.s64 = 336;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,44(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x82309D38;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82309da0
	if (ctx.cr0.eq) goto loc_82309DA0;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x824ae330
	ctx.lr = 0x82309D98;
	sub_824AE330(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82309da4
	goto loc_82309DA4;
loc_82309DA0:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
loc_82309DA4:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82309dd8
	if (ctx.cr6.eq) goto loc_82309DD8;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,52(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bl 0x8246ca70
	ctx.lr = 0x82309DC8;
	sub_8246CA70(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stb r26,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r26.u8);
	// stb r22,287(r31)
	REX_STORE_U8(ctx.r31.u32 + 287, ctx.r22.u8);
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_82309DD8:
	// addis r7,r30,1
	ctx.r7.s64 = ctx.r30.s64 + 65536;
	// addi r7,r7,-2979
	ctx.r7.s64 = ctx.r7.s64 + -2979;
	// lbz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82309e68
	if (ctx.cr0.eq) goto loc_82309E68;
	// lwzx r11,r30,r24
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r24.u32);
	// add r8,r30,r24
	ctx.r8.u64 = ctx.r30.u64 + ctx.r24.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309e64
	if (ctx.cr6.eq) goto loc_82309E64;
	// lwz r10,-12816(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -12816);
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82309e60
	if (!ctx.cr6.eq) goto loc_82309E60;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82309e60
	if (ctx.cr6.eq) goto loc_82309E60;
	// lbz r10,23(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82309e60
	if (!ctx.cr0.eq) goto loc_82309E60;
	// lis r10,-32181
	ctx.r10.s64 = -2109014016;
	// lwz r9,292(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 292);
	// addi r10,r10,-4896
	ctx.r10.s64 = ctx.r10.s64 + -4896;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82309e60
	if (ctx.cr6.eq) goto loc_82309E60;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r22,296(r11)
	REX_STORE_U8(ctx.r11.u32 + 296, ctx.r22.u8);
	// lis r9,-32181
	ctx.r9.s64 = -2109014016;
	// addi r9,r9,-4896
	ctx.r9.s64 = ctx.r9.s64 + -4896;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,292(r11)
	REX_STORE_U32(ctx.r11.u32 + 292, ctx.r9.u32);
	// stfs f0,280(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 280, temp.u32);
loc_82309E60:
	// stw r26,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r26.u32);
loc_82309E64:
	// stb r26,0(r7)
	REX_STORE_U8(ctx.r7.u32 + 0, ctx.r26.u8);
loc_82309E68:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r4,r30,88
	ctx.r4.s64 = ctx.r30.s64 + 88;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82309EA0;
	sub_8255F918(ctx, base);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8255f918
	ctx.lr = 0x82309EB0;
	sub_8255F918(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62328
	ctx.r11.u64 = ctx.r11.u64 | 62328;
	// lbzx r11,r30,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82309edc
	if (ctx.cr0.eq) goto loc_82309EDC;
	// addis r10,r30,1
	ctx.r10.s64 = ctx.r30.s64 + 65536;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,-3204
	ctx.r10.s64 = ctx.r10.s64 + -3204;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
loc_82309EDC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82309ef0
	ctx.lr = 0x82309EE4;
	sub_82309EF0(ctx, base);
loc_82309EE4:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82329238) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,62412
	ctx.r4.u64 = ctx.r4.u64 | 62412;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82329260;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82329270
	if (ctx.cr0.eq) goto loc_82329270;
	// bl 0x82329098
	ctx.lr = 0x8232926C;
	sub_82329098(ctx, base);
	// b 0x82329274
	goto loc_82329274;
loc_82329270:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82329274:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8232B178) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x8232b030
	ctx.lr = 0x8232B198;
	sub_8232B030(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232b1b0
	if (ctx.cr0.eq) goto loc_8232B1B0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8232b1b0
	if (ctx.cr6.eq) goto loc_8232B1B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8232B1B0;
	sub_825E0378(ctx, base);
loc_8232B1B0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8232D170) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8232D178;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af28
	ctx.lr = 0x8232D180;
	__savefpr_28(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f31,f3
	ctx.f31.f64 = ctx.f3.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f29,f4
	ctx.f29.f64 = ctx.f4.f64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8222ff78
	ctx.lr = 0x8232D1AC;
	sub_8222FF78(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,-3160
	ctx.r28.s64 = ctx.r28.s64 + -3160;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f28.f64));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8232d218
	if (!ctx.cr6.lt) goto loc_8232D218;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8232D218:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232d460
	if (ctx.cr0.eq) goto loc_8232D460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8222ff78
	ctx.lr = 0x8232D234;
	sub_8222FF78(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8232d298
	if (!ctx.cr6.gt) goto loc_8232D298;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8232D298:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232d460
	if (ctx.cr0.eq) goto loc_8232D460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8222ff78
	ctx.lr = 0x8232D2B4;
	sub_8222FF78(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r29,r29,-3156
	ctx.r29.s64 = ctx.r29.s64 + -3156;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x8232d320
	if (!ctx.cr6.lt) goto loc_8232D320;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8232D320:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232d460
	if (ctx.cr0.eq) goto loc_8232D460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8222ff78
	ctx.lr = 0x8232D33C;
	sub_8222FF78(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f29.f64));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8232d3a0
	if (!ctx.cr6.gt) goto loc_8232D3A0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8232D3A0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8232d460
	if (ctx.cr0.eq) goto loc_8232D460;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x8232D3BC;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x8232D3D8;
	sub_8222FF78(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8232d414
	if (ctx.cr6.eq) goto loc_8232D414;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f31
	ctx.f13.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x8232D410;
	sub_823AEFA8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8232D414:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8232d448
	if (ctx.cr6.eq) goto loc_8232D448;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x8232D448;
	sub_823AEFA8(ctx, base);
loc_8232D448:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r30,24
	ctx.r10.u64 = ctx.r30.u32 & 0xFF;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x8232d464
	goto loc_8232D464;
loc_8232D460:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8232D464:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af74
	ctx.lr = 0x8232D470;
	__restfpr_28(ctx, base);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82342ED8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r4,0
	ctx.r4.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r5,0
	ctx.r5.s64 = 0;
	// ori r4,r4,62740
	ctx.r4.u64 = ctx.r4.u64 | 62740;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82342F00;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82342f10
	if (ctx.cr0.eq) goto loc_82342F10;
	// bl 0x82342ab8
	ctx.lr = 0x82342F0C;
	sub_82342AB8(ctx, base);
	// b 0x82342f14
	goto loc_82342F14;
loc_82342F10:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82342F14:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82346DB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-2800
	ctx.r30.s64 = ctx.r30.s64 + -2800;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// bl 0x824281d8
	ctx.lr = 0x82346DE8;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82346f7c
	if (ctx.cr0.eq) goto loc_82346F7C;
	// bl 0x8242a5e0
	ctx.lr = 0x82346DF4;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82346e04
	if (!ctx.cr0.eq) goto loc_82346E04;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82346e08
	goto loc_82346E08;
loc_82346E04:
	// bl 0x8242aa28
	ctx.lr = 0x82346E08;
	sub_8242AA28(ctx, base);
loc_82346E08:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82346f7c
	if (!ctx.cr0.eq) goto loc_82346F7C;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,-2816
	ctx.r4.s64 = ctx.r4.s64 + -2816;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// bl 0x8225f588
	ctx.lr = 0x82346E20;
	sub_8225F588(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82346f7c
	if (ctx.cr0.eq) goto loc_82346F7C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82346e5c
	if (ctx.cr6.lt) goto loc_82346E5C;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r9,r11,62728
	ctx.r9.u64 = ctx.r11.u64 | 62728;
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// std r11,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r11.u64);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// stdx r11,r31,r9
	REX_STORE_U64(ctx.r31.u32 + ctx.r9.u32, ctx.r11.u64);
	// b 0x82346f7c
	goto loc_82346F7C;
loc_82346E5C:
	// addis r5,r31,1
	ctx.r5.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// addi r5,r5,-2808
	ctx.r5.s64 = ctx.r5.s64 + -2808;
	// bl 0x82322d08
	ctx.lr = 0x82346E6C;
	sub_82322D08(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f13,88(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,104(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r11.u64);
loc_82346F7C:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823567D0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82237858
	ctx.lr = 0x823567E8;
	sub_82237858(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,-792
	ctx.r11.s64 = ctx.r11.s64 + -792;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8235680c
	if (ctx.cr6.eq) goto loc_8235680C;
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r9,23(r10)
	REX_STORE_U8(ctx.r10.u32 + 23, ctx.r9.u8);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_8235680C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,64748
	ctx.r11.u64 = ctx.r11.u64 | 64748;
	// stbx r9,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u8);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82359028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f29.u64);
	// stfd f30,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// addi r10,r11,17092
	ctx.r10.s64 = ctx.r11.s64 + 17092;
	// addi r30,r30,-1440
	ctx.r30.s64 = ctx.r30.s64 + -1440;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f30,17092(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17092);
	ctx.f30.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,-18652(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f29,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f29.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82359088
	if (!ctx.cr6.lt) goto loc_82359088;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x82359094
	goto loc_82359094;
loc_82359088:
	// fcmpu cr6,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// ble cr6,0x82359094
	if (!ctx.cr6.gt) goto loc_82359094;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
loc_82359094:
	// stfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825a4a40
	ctx.lr = 0x823590A8;
	sub_825A4A40(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x823590bc
	if (!ctx.cr6.gt) goto loc_823590BC;
	// li r3,-1
	ctx.r3.s64 = -1;
	// b 0x823591b4
	goto loc_823591B4;
loc_823590BC:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r11,31900
	ctx.r9.s64 = ctx.r11.s64 + 31900;
	// ori r10,r10,64104
	ctx.r10.u64 = ctx.r10.u64 | 64104;
	// ld r11,31900(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 31900);
	// lwzx r7,r31,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// cmpwi cr6,r7,-1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, -1, ctx.xer);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// beq cr6,0x82359158
	if (ctx.cr6.eq) goto loc_82359158;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,64108
	ctx.r11.u64 = ctx.r11.u64 | 64108;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82359158
	if (!ctx.cr6.gt) goto loc_82359158;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// rlwinm r11,r7,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r8,2
	ctx.r8.s64 = 2;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfsx f13,r11,r10
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f12,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// stfsx f0,r11,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
loc_82359138:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// beq cr6,0x8235914c
	if (ctx.cr6.eq) goto loc_8235914C;
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f13,0(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
loc_8235914C:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// bdnz 0x82359138
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82359138;
loc_82359158:
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r31,-1
	ctx.r31.s64 = -1;
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82359170;
	sub_825A4A40(ctx, base);
	// addi r10,r1,76
	ctx.r10.s64 = ctx.r1.s64 + 76;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82359178:
	// fcmpu cr6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f31.f64);
	// blt cr6,0x82359190
	if (ctx.cr6.lt) goto loc_82359190;
	// lfs f0,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x823591a8
	if (ctx.cr6.lt) goto loc_823591A8;
loc_82359190:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfsu f0,4(r10)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// fadds f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x82359178
	if (ctx.cr6.lt) goto loc_82359178;
	// b 0x823591ac
	goto loc_823591AC;
loc_823591A8:
	// mr r31,r11
	ctx.r31.u64 = ctx.r11.u64;
loc_823591AC:
	// stfs f29,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_823591B4:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f29,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f30,-40(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82361058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82361060;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// li r29,6
	ctx.r29.s64 = 6;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x823612ac
	if (ctx.cr6.lt) goto loc_823612AC;
	// beq cr6,0x82361108
	if (ctx.cr6.eq) goto loc_82361108;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x823610d8
	if (ctx.cr6.eq) goto loc_823610D8;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bne cr6,0x82361304
	if (!ctx.cr6.eq) goto loc_82361304;
	// lfs f0,56(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f12,f0,f1
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stfs f12,56(r3)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r3.u32 + 56, temp.u32);
	// addi r10,r10,12468
	ctx.r10.s64 = ctx.r10.s64 + 12468;
	// lfs f0,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x823610cc
	if (ctx.cr6.lt) goto loc_823610CC;
	// li r11,0
	ctx.r11.s64 = 0;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// stw r29,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r29.u32);
	// stb r11,129(r3)
	REX_STORE_U8(ctx.r3.u32 + 129, ctx.r11.u8);
loc_823610CC:
	// fsubs f0,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,132(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 132, temp.u32);
	// b 0x82361304
	goto loc_82361304;
loc_823610D8:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82361304
	if (!ctx.cr0.eq) goto loc_82361304;
	// lfs f0,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f9
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// lfs f13,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82361304
	if (ctx.cr6.lt) goto loc_82361304;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r10.u32);
	// b 0x823612f8
	goto loc_823612F8;
loc_82361108:
	// lfs f0,56(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// fadds f13,f0,f9
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f9.f64));
	// stfs f13,56(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lfs f11,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f12,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f12.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,28576(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28576);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// lwa r11,84(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x8236119C;
	sub_822EA1A8(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f11.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f12,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-8956(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8956);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f6,f9,f0,f13
	ctx.f6.f64 = double(float(std::fma(ctx.f9.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,-13032(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// fmadds f5,f1,f0,f11
	ctx.f5.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f11.f64)));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fadds f0,f12,f6
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f6.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x82361250
	if (ctx.cr6.eq) goto loc_82361250;
	// fctiwz f0,f5
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aebd8
	ctx.lr = 0x823611F0;
	sub_823AEBD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82361250
	if (ctx.cr0.eq) goto loc_82361250;
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stb r11,129(r31)
	REX_STORE_U8(ctx.r31.u32 + 129, ctx.r11.u8);
	// li r11,4
	ctx.r11.s64 = 4;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f12,88(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lfs f5,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f5.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// fadds f6,f13,f6
	ctx.f6.f64 = double(float(ctx.f13.f64 + ctx.f6.f64));
loc_82361250:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f5,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f5,80(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f5,92(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f5,88(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f6,108(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r31)
	REX_STORE_U64(ctx.r31.u32 + 88, ctx.r11.u64);
	// b 0x82361304
	goto loc_82361304;
loc_823612AC:
	// lwz r3,152(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823612cc
	if (ctx.cr6.eq) goto loc_823612CC;
	// bl 0x823bdef8
	ctx.lr = 0x823612C0;
	sub_823BDEF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// bne 0x823612d0
	if (!ctx.cr0.eq) goto loc_823612D0;
loc_823612CC:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823612D0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82361304
	if (!ctx.cr0.eq) goto loc_82361304;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82361a48
	ctx.lr = 0x823612E0;
	sub_82361A48(ctx, base);
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823612f0
	if (!ctx.cr0.eq) goto loc_823612F0;
	// stb r30,129(r31)
	REX_STORE_U8(ctx.r31.u32 + 129, ctx.r30.u8);
loc_823612F0:
	// stb r30,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r30.u8);
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
loc_823612F8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
loc_82361304:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82361ae8
	ctx.lr = 0x8236130C;
	sub_82361AE8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82361318
	if (ctx.cr0.eq) goto loc_82361318;
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
loc_82361318:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r11,r11,-6
	ctx.r11.s64 = ctx.r11.s64 + -6;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82376DA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82376DD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82376e88
	if (ctx.cr0.eq) goto loc_82376E88;
	// lfs f13,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,252(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 252);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f11,248(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 248);
	ctx.f11.f64 = double(temp.f32);
	// fmr f2,f11
	ctx.f2.f64 = ctx.f11.f64;
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82376e14
	if (ctx.cr6.lt) goto loc_82376E14;
	// lfs f13,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bgt cr6,0x82376e14
	if (ctx.cr6.gt) goto loc_82376E14;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
loc_82376E14:
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f0,27368(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 27368);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f13,f0
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f0,29512(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29512);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fsubs f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fabs f10,f13
	ctx.f10.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// bgt cr6,0x82376e44
	if (ctx.cr6.gt) goto loc_82376E44;
	// stfs f12,248(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
	// b 0x82376e60
	goto loc_82376E60;
loc_82376E44:
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x82376e58
	if (!ctx.cr6.lt) goto loc_82376E58;
	// fsubs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// b 0x82376e5c
	goto loc_82376E5C;
loc_82376E58:
	// fadds f0,f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
loc_82376E5C:
	// stfs f0,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 248, temp.u32);
loc_82376E60:
	// lfs f1,248(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 248);
	ctx.f1.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f1,f2
	ctx.cr6.compare(ctx.f1.f64, ctx.f2.f64);
	// bne cr6,0x82376e74
	if (!ctx.cr6.eq) goto loc_82376E74;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82376E74:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,284(r31)
	REX_STORE_U8(ctx.r31.u32 + 284, ctx.r11.u8);
	// beq 0x82376e88
	if (ctx.cr0.eq) goto loc_82376E88;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82377198
	ctx.lr = 0x82376E88;
	sub_82377198(ctx, base);
loc_82376E88:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237C478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8235f428
	ctx.lr = 0x8237C490;
	sub_8235F428(ctx, base);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// addi r8,r10,12472
	ctx.r8.s64 = ctx.r10.s64 + 12472;
	// addi r9,r9,22960
	ctx.r9.s64 = ctx.r9.s64 + 22960;
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stw r11,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r11.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r11.u8);
	// stfs f0,232(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 232, temp.u32);
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// stw r11,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r11.u32);
	// addi r8,r7,2688
	ctx.r8.s64 = ctx.r7.s64 + 2688;
	// stb r11,248(r31)
	REX_STORE_U8(ctx.r31.u32 + 248, ctx.r11.u8);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// lfs f13,12472(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f13.f64 = double(temp.f32);
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// stfs f0,272(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 272, temp.u32);
	// stfs f0,276(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 276, temp.u32);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// stfs f0,284(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 284, temp.u32);
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
	// stfs f13,292(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stw r11,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r11.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stb r11,280(r31)
	REX_STORE_U8(ctx.r31.u32 + 280, ctx.r11.u8);
	// stb r11,281(r31)
	REX_STORE_U8(ctx.r31.u32 + 281, ctx.r11.u8);
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// li r5,-1
	ctx.r5.s64 = -1;
	// stw r7,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r8.u32);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r10,308(r31)
	REX_STORE_U64(ctx.r31.u32 + 308, ctx.r10.u64);
	// ld r10,3128(r6)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r6.u32 + 3128);
	// std r10,316(r31)
	REX_STORE_U64(ctx.r31.u32 + 316, ctx.r10.u64);
	// stw r11,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// stfs f0,344(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// rlwinm r10,r10,0,31,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFFD;
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// stw r5,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r5.u32);
	// stb r11,348(r31)
	REX_STORE_U8(ctx.r31.u32 + 348, ctx.r11.u8);
	// stw r11,352(r31)
	REX_STORE_U32(ctx.r31.u32 + 352, ctx.r11.u32);
	// stw r10,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8237FC50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8237FC58;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r25,260(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 260);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f0,248(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 248);
	ctx.f0.f64 = double(temp.f32);
	// lwz r24,284(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 284);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r3,260
	ctx.r29.s64 = ctx.r3.s64 + 260;
	// fmuls f31,f0,f1
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
	// stw r25,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r25.u32);
	// addi r28,r11,20580
	ctx.r28.s64 = ctx.r11.s64 + 20580;
	// addi r27,r10,20580
	ctx.r27.s64 = ctx.r10.s64 + 20580;
loc_8237FC90:
	// lwz r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// lwz r10,28(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// cmplw cr6,r25,r9
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r9.u32, ctx.xer);
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bne cr6,0x8237fcb8
	if (!ctx.cr6.eq) goto loc_8237FCB8;
	// cmplw cr6,r24,r11
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x8237fcbc
	if (ctx.cr6.eq) goto loc_8237FCBC;
loc_8237FCB8:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8237FCBC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8237fd30
	if (!ctx.cr0.eq) goto loc_8237FD30;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8236c610
	ctx.lr = 0x8237FCCC;
	sub_8236C610(ctx, base);
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// addi r5,r31,4
	ctx.r5.s64 = ctx.r31.s64 + 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8237fa60
	ctx.lr = 0x8237FCE4;
	sub_8237FA60(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8237fd28
	if (ctx.cr0.eq) goto loc_8237FD28;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r10,517
	ctx.r10.s64 = 517;
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stw r8,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// stw r27,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r27.u32);
	// stw r11,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// ld r7,88(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// lwz r3,-12816(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + -12816);
	// std r7,116(r1)
	REX_STORE_U64(ctx.r1.u32 + 116, ctx.r7.u64);
	// bl 0x825a2f98
	ctx.lr = 0x8237FD24;
	sub_825A2F98(ctx, base);
	// stw r28,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r28.u32);
loc_8237FD28:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// b 0x8237fc90
	goto loc_8237FC90;
loc_8237FD30:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823853E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82385440
	ctx.lr = 0x82385408;
	sub_82385440(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82385420
	if (ctx.cr0.eq) goto loc_82385420;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82385420
	if (ctx.cr6.eq) goto loc_82385420;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82385420;
	sub_825E0378(ctx, base);
loc_82385420:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82386E50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f11,152(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 152);
	ctx.f11.f64 = double(temp.f32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// addi r5,r10,12468
	ctx.r5.s64 = ctx.r10.s64 + 12468;
	// beq cr6,0x82386ed0
	if (ctx.cr6.eq) goto loc_82386ED0;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82386ec0
	if (ctx.cr6.eq) goto loc_82386EC0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82386eb8
	if (ctx.cr6.eq) goto loc_82386EB8;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82386eb8
	if (ctx.cr6.eq) goto loc_82386EB8;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x82386eb0
	if (ctx.cr6.eq) goto loc_82386EB0;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82386ef4
	if (!ctx.cr6.eq) goto loc_82386EF4;
	// lfs f11,156(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// bl 0x82387740
	ctx.lr = 0x82386EAC;
	sub_82387740(ctx, base);
	// b 0x82386ef4
	goto loc_82386EF4;
loc_82386EB0:
	// lfs f11,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// b 0x82386ef4
	goto loc_82386EF4;
loc_82386EB8:
	// li r4,0
	ctx.r4.s64 = 0;
	// b 0x82386ec4
	goto loc_82386EC4;
loc_82386EC0:
	// li r4,1
	ctx.r4.s64 = 1;
loc_82386EC4:
	// lfs f11,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f11.f64 = double(temp.f32);
	// bl 0x82387648
	ctx.lr = 0x82386ECC;
	sub_82387648(ctx, base);
	// b 0x82386ef4
	goto loc_82386EF4;
loc_82386ED0:
	// lbz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 168);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82386ef4
	if (ctx.cr0.eq) goto loc_82386EF4;
	// lfs f0,156(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// fadds f13,f0,f11
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f11.f64));
	// lfs f0,1908(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 1908);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,168(r3)
	REX_STORE_U8(ctx.r3.u32 + 168, ctx.r11.u8);
	// fmuls f11,f13,f0
	ctx.f11.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
loc_82386EF4:
	// addi r11,r3,64
	ctx.r11.s64 = ctx.r3.s64 + 64;
	// lfs f0,0(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// lis r7,-32242
	ctx.r7.s64 = -2113011712;
	// li r6,4
	ctx.r6.s64 = 4;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,0
	ctx.r4.s64 = 0;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r10,r7,31600
	ctx.r10.s64 = ctx.r7.s64 + 31600;
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r7,64
	ctx.r7.s64 = 64;
	// addi r8,r8,-4080
	ctx.r8.s64 = ctx.r8.s64 + -4080;
	// lvsr v7,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r31,8
	ctx.r31.s64 = 8;
	// vperm128 v12,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lfs f0,140(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvsl v7,r0,r4
	temp.u32 = ctx.r4.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r6,0
	ctx.r6.s64 = 0;
	// lvsl v5,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// addi r31,r1,80
	ctx.r31.s64 = ctx.r1.s64 + 80;
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,8
	ctx.r9.s64 = 8;
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lvsr v6,r0,r6
	temp.u32 = ctx.r6.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// li r6,64
	ctx.r6.s64 = 64;
	// lvsr v4,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableR[(temp.u32 & 0xF) * 16]));
	// fctid f10,f10
	ctx.f10.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fnmsubs f12,f10,f13,f12
	ctx.f12.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v13,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vor128 v63,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v0,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vperm128 v63,v63,v63,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// fmuls f10,f12,f0
	ctx.f10.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lvx128 v63,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v12,v63,v63,v6
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// fctid f10,f10
	ctx.f10.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f10.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f10.f64));
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fnmsubs f12,f10,f13,f12
	ctx.f12.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v13,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v0,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vor128 v63,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v13,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vperm128 v63,v63,v63,v5
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// vspltw128 v62,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// lvx128 v63,r10,r6
	ea = (ctx.r10.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// vperm128 v12,v63,v63,v4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f0,f0,f13,f12
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v12,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x8238706c
	if (!ctx.cr6.gt) goto loc_8238706C;
	// bl 0x823873d0
	ctx.lr = 0x8238706C;
	sub_823873D0(ctx, base);
loc_8238706C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8239F388) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8239F390;
	__savegprlr_25(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r5,15
	ctx.r11.s64 = ctx.r5.s64 + 15;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r4,4
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 4;
	// rlwinm r29,r11,4,0,27
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addze r11,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r11.s64 = temp.s64;
	// addi r26,r29,16
	ctx.r26.s64 = ctx.r29.s64 + 16;
	// rlwinm r28,r11,4,0,27
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r31,r28,448
	ctx.r31.s64 = ctx.r28.s64 + 448;
	// addi r27,r31,64
	ctx.r27.s64 = ctx.r31.s64 + 64;
	// cmpw cr6,r31,r27
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x8239f418
	if (!ctx.cr6.lt) goto loc_8239F418;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r25,-13032(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
loc_8239F3D0:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x8239f3f4
	if (ctx.cr6.eq) goto loc_8239F3F4;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ae578
	ctx.lr = 0x8239F3EC;
	sub_823AE578(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x8239f404
	if (!ctx.cr0.eq) goto loc_8239F404;
loc_8239F3F4:
	// addi r31,r31,16
	ctx.r31.s64 = ctx.r31.s64 + 16;
	// cmpw cr6,r31,r27
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r27.s32, ctx.xer);
	// blt cr6,0x8239f3d0
	if (ctx.cr6.lt) goto loc_8239F3D0;
	// b 0x8239f418
	goto loc_8239F418;
loc_8239F404:
	// add r11,r3,r31
	ctx.r11.u64 = ctx.r3.u64 + ctx.r31.u64;
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r31,r11,4,0,27
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
loc_8239F418:
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// extsw r10,r29
	ctx.r10.s64 = ctx.r29.s32;
	// stw r26,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r26.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r28,-16
	ctx.r11.s64 = ctx.r28.s64 + -16;
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// subf r11,r28,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r28.u64;
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// ld r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stw r11,304(r30)
	REX_STORE_U32(ctx.r30.u32 + 304, ctx.r11.u32);
	// std r10,296(r30)
	REX_STORE_U64(ctx.r30.u32 + 296, ctx.r10.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// std r9,288(r30)
	REX_STORE_U64(ctx.r30.u32 + 288, ctx.r9.u64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,260(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 260, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,256(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 256, temp.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A8050) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8235f428
	ctx.lr = 0x823A806C;
	sub_8235F428(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r10,r10,30264
	ctx.r10.s64 = ctx.r10.s64 + 30264;
	// li r30,0
	ctx.r30.s64 = 0;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// li r7,-1
	ctx.r7.s64 = -1;
	// stfs f0,232(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 232, temp.u32);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r30,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r30.u32);
	// addi r8,r8,2688
	ctx.r8.s64 = ctx.r8.s64 + 2688;
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// addi r3,r31,340
	ctx.r3.s64 = ctx.r31.s64 + 340;
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// stfs f0,256(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// stb r30,244(r31)
	REX_STORE_U8(ctx.r31.u32 + 244, ctx.r30.u8);
	// stw r30,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r30.u32);
	// stw r30,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r30.u32);
	// stb r30,260(r31)
	REX_STORE_U8(ctx.r31.u32 + 260, ctx.r30.u8);
	// std r10,236(r31)
	REX_STORE_U64(ctx.r31.u32 + 236, ctx.r10.u64);
	// stw r7,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r7.u32);
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// stw r8,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r8.u32);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r10,276(r31)
	REX_STORE_U64(ctx.r31.u32 + 276, ctx.r10.u64);
	// ld r10,3128(r6)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r6.u32 + 3128);
	// std r10,284(r31)
	REX_STORE_U64(ctx.r31.u32 + 284, ctx.r10.u64);
	// stw r11,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r11.u32);
	// stw r8,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r8.u32);
	// ld r10,3456(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r10,300(r31)
	REX_STORE_U64(ctx.r31.u32 + 300, ctx.r10.u64);
	// ld r10,3128(r6)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r6.u32 + 3128);
	// std r10,308(r31)
	REX_STORE_U64(ctx.r31.u32 + 308, ctx.r10.u64);
	// stw r11,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r11.u32);
	// stw r8,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r8.u32);
	// ld r11,3456(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 3456);
	// std r11,324(r31)
	REX_STORE_U64(ctx.r31.u32 + 324, ctx.r11.u64);
	// ld r11,3128(r6)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r6.u32 + 3128);
	// std r11,332(r31)
	REX_STORE_U64(ctx.r31.u32 + 332, ctx.r11.u64);
	// bl 0x8236c5a0
	ctx.lr = 0x823A8114;
	sub_8236C5A0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r30,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r30.u32);
	// addi r11,r11,-27424
	ctx.r11.s64 = ctx.r11.s64 + -27424;
	// stw r30,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r30.u32);
	// stw r10,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r10.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// stw r30,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823AEBD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823AEBE0;
	__savegprlr_23(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// lwz r27,-13032(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x823aec10
	if (ctx.cr6.eq) goto loc_823AEC10;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
loc_823AEC10:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r24,r11,32256
	ctx.r24.s64 = ctx.r11.s64 + 32256;
	// addi r23,r10,-11392
	ctx.r23.s64 = ctx.r10.s64 + -11392;
loc_823AEC20:
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823afc28
	ctx.lr = 0x823AEC3C;
	sub_823AFC28(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x823aee60
	if (ctx.cr0.eq) goto loc_823AEE60;
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// lwz r6,8(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// extsw r10,r28
	ctx.r10.s64 = ctx.r28.s32;
	// std r11,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r11.u64);
	// lfd f0,264(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// std r10,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r10.u64);
	// lfd f13,256(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 256);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// lwz r11,4(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// beq cr6,0x823aedd8
	if (ctx.cr6.eq) goto loc_823AEDD8;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x823aed00
	if (ctx.cr6.eq) goto loc_823AED00;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x823aecec
	if (ctx.cr6.eq) goto loc_823AECEC;
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823aee38
	goto loc_823AEE38;
loc_823AECEC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x823b0400
	ctx.lr = 0x823AECFC;
	sub_823B0400(ctx, base);
	// b 0x823aee38
	goto loc_823AEE38;
loc_823AED00:
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f12,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r11,r6,16
	ctx.r11.s64 = ctx.r6.s64 + 16;
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v8,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,12(r6)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v59,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v62,v62,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsubfp128 v59,v58,v59
	simde_mm_store_ps(ctx.v59.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vsubfp128 v62,v61,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vrsqrtefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v62.f32))));
	// vor128 v13,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vmulfp128 v12,v62,v8
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v8.f32)));
	// vcmpeqfp128 v9,v62,v63
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpeqfp128 v11,v62,v63
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v10,v0,v0
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vcmpeqfp128 v7,v0,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vnmsubfp v8,v12,v10,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v8.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v10,v9,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vmaddfp v12,v0,v8,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v10,v12,v0,v10
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vcmpeqfp128 v12,v10,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v0,v62,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vsel v10,v11,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v12,v0,v13,v10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsubfp128 v63,v12,v59
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v59.f32)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x823aee38
	goto loc_823AEE38;
loc_823AEDD8:
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f0,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r8,r1,192
	ctx.r8.s64 = ctx.r1.s64 + 192;
	// lfs f0,20(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f13,240(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vminfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_min_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_823AEE38:
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,320(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.f0.u64);
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
loc_823AEE58:
	// subfic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 <= 4294967295;
	ctx.r11.u64 = static_cast<uint64_t>(-1) - ctx.r11.u64;
	// b 0x823aef18
	goto loc_823AEF18;
loc_823AEE60:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x823aee7c
	if (ctx.cr6.eq) goto loc_823AEE7C;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823af008
	ctx.lr = 0x823AEE7C;
	sub_823AF008(ctx, base);
loc_823AEE7C:
	// clrlwi. r10,r3,31
	ctx.r10.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// beq 0x823aef3c
	if (ctx.cr0.eq) goto loc_823AEF3C;
	// clrlwi. r10,r25,24
	ctx.r10.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823aee98
	if (ctx.cr0.eq) goto loc_823AEE98;
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823aef3c
	if (ctx.cr0.eq) goto loc_823AEF3C;
loc_823AEE98:
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x823aeea8
	if (!ctx.cr6.eq) goto loc_823AEEA8;
	// clrlwi r11,r31,28
	ctx.r11.u64 = ctx.r31.u32 & 0xF;
	// b 0x823aee58
	goto loc_823AEE58;
loc_823AEEA8:
	// rlwinm. r9,r11,0,24,25
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xC0;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x823aeeb8
	if (ctx.cr0.eq) goto loc_823AEEB8;
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823aef48
	if (ctx.cr0.eq) goto loc_823AEF48;
loc_823AEEB8:
	// andi. r10,r11,196
	ctx.r10.u64 = ctx.r11.u64 & 196;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x823aeecc
	if (ctx.cr0.eq) goto loc_823AEECC;
loc_823AEEC4:
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x823aeee8
	goto loc_823AEEE8;
loc_823AEECC:
	// rlwinm. r10,r11,0,26,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823aeec4
	if (ctx.cr0.eq) goto loc_823AEEC4;
	// rlwinm r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// xori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 ^ 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_823AEEE8:
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x823aeef8
	if (ctx.cr6.eq) goto loc_823AEEF8;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x823aef3c
	if (!ctx.cr0.eq) goto loc_823AEF3C;
loc_823AEEF8:
	// clrlwi r11,r31,28
	ctx.r11.u64 = ctx.r31.u32 & 0xF;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// subfic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 <= 4294967295;
	ctx.r11.u64 = static_cast<uint64_t>(-1) - ctx.r11.u64;
	// beq cr6,0x823aef94
	if (ctx.cr6.eq) goto loc_823AEF94;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x823aef18
	if (!ctx.cr6.eq) goto loc_823AEF18;
	// cmpwi cr6,r11,-8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8, ctx.xer);
	// blt cr6,0x823aef3c
	if (ctx.cr6.lt) goto loc_823AEF3C;
loc_823AEF18:
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x823aef34
	if (ctx.cr6.eq) goto loc_823AEF34;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x823aef34
	if (ctx.cr6.eq) goto loc_823AEF34;
	// stw r29,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r29.u32);
loc_823AEF34:
	// cmpwi cr6,r30,-16
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -16, ctx.xer);
	// bge cr6,0x823aec20
	if (!ctx.cr6.lt) goto loc_823AEC20;
loc_823AEF3C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_823AEF40:
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
loc_823AEF48:
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r9,r11,30,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0xC;
	// subfic r10,r28,15
	ctx.xer.ca = ctx.r28.u32 <= 15;
	ctx.r10.u64 = static_cast<uint64_t>(15) - ctx.r28.u64;
	// bne 0x823aef5c
	if (!ctx.cr0.eq) goto loc_823AEF5C;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_823AEF5C:
	// rlwinm r11,r11,26,6,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x3FFFFFF;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// clrlwi r8,r31,28
	ctx.r8.u64 = ctx.r31.u32 & 0xF;
	// sraw r11,r10,r11
	temp.u32 = ctx.r11.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r11.s64 = ctx.r10.s32 >> temp.u32;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// rlwinm r9,r11,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// subfze r10,r9
	temp.u8 = ~ctx.r9.u32 + ctx.xer.ca < ~ctx.r9.u32;
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	// b 0x823aef40
	goto loc_823AEF40;
loc_823AEF94:
	// cmpwi cr6,r11,-8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8, ctx.xer);
	// bgt cr6,0x823aef3c
	if (ctx.cr6.gt) goto loc_823AEF3C;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// b 0x823aef40
	goto loc_823AEF40;
}

DEFINE_REX_FUNC(sub_823CF408) {
	REX_FUNC_PROLOGUE();
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bge cr6,0x823cf440
	if (!ctx.cr6.lt) goto loc_823CF440;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// blr 
	return;
loc_823CF440:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823cf450
	if (ctx.cr6.eq) goto loc_823CF450;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_823CF450:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823D0340) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,12
	ctx.r10.s64 = 12;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// li r11,13
	ctx.r11.s64 = 13;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,9
	ctx.r9.s64 = 9;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// li r10,11
	ctx.r10.s64 = 11;
	// li r9,2
	ctx.r9.s64 = 2;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// li r10,5
	ctx.r10.s64 = 5;
	// li r9,4
	ctx.r9.s64 = 4;
	// stw r11,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r11.u32);
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r9,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// li r10,7
	ctx.r10.s64 = 7;
	// li r9,14
	ctx.r9.s64 = 14;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r10.u32);
	// stw r9,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r9.u32);
	// bl 0x82213210
	ctx.lr = 0x823D03D0;
	sub_82213210(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lbz r10,4032(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 4032);
	// rlwinm r9,r31,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// lwzx r8,r9,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823d0430
	if (ctx.cr6.eq) goto loc_823D0430;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r7,808
	ctx.r7.s64 = 808;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// divw r11,r11,r7
	ctx.r11.u64 = uint32_t((ctx.r7.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r7.s32 == -1)) ? ctx.r11.s32 / ctx.r7.s32 : 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x823d0430
	if (!ctx.cr6.gt) goto loc_823D0430;
	// cmpwi cr6,r8,-1
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -1, ctx.xer);
	// ble cr6,0x823d0430
	if (!ctx.cr6.gt) goto loc_823D0430;
	// cmpwi cr6,r8,15
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 15, ctx.xer);
	// bge cr6,0x823d0430
	if (!ctx.cr6.lt) goto loc_823D0430;
	// mulli r11,r10,808
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(808));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lbz r3,712(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 712);
	// b 0x823d0434
	goto loc_823D0434;
loc_823D0430:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823D0434:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823D8FA8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823d9250
	sub_823D9250(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D8FB8) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823d9888
	sub_823D9888(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D9768) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823D9770;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r3,260
	ctx.r28.s64 = ctx.r3.s64 + 260;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// li r31,2
	ctx.r31.s64 = 2;
	// addi r30,r28,-4
	ctx.r30.s64 = ctx.r28.s64 + -4;
loc_823D978C:
	// lwzu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// bl 0x823bdef8
	ctx.lr = 0x823D9794;
	sub_823BDEF8(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x823d978c
	if (!ctx.cr0.eq) goto loc_823D978C;
	// lwz r3,268(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 268);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c8488
	ctx.lr = 0x823D97A8;
	sub_823C8488(ctx, base);
	// lwz r3,300(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 300);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d97bc
	if (ctx.cr6.eq) goto loc_823D97BC;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c7628
	ctx.lr = 0x823D97BC;
	sub_823C7628(ctx, base);
loc_823D97BC:
	// lwz r10,308(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 308);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x823d97e4
	if (!ctx.cr6.eq) goto loc_823D97E4;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,15656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 15656);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x823d9808
	if (!ctx.cr6.lt) goto loc_823D9808;
loc_823D97E4:
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// lwz r9,52(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x823d9810
	if (!ctx.cr6.eq) goto loc_823D9810;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f13,44(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,18380(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18380);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x823d9810
	if (ctx.cr6.gt) goto loc_823D9810;
loc_823D9808:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823d9814
	goto loc_823D9814;
loc_823D9810:
	// li r11,1
	ctx.r11.s64 = 1;
loc_823D9814:
	// lbz r9,152(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x823d9838
	if (ctx.cr0.eq) goto loc_823D9838;
	// lbz r9,153(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 153);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x823d9838
	if (!ctx.cr0.eq) goto loc_823D9838;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x823d983c
	if (!ctx.cr0.eq) goto loc_823D983C;
loc_823D9838:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823D983C:
	// lwz r9,0(r28)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stb r11,285(r29)
	REX_STORE_U8(ctx.r29.u32 + 285, ctx.r11.u8);
	// lbz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823d9860
	if (!ctx.cr0.eq) goto loc_823D9860;
	// lbz r11,152(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 152);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bne 0x823d9864
	if (!ctx.cr0.eq) goto loc_823D9864;
loc_823D9860:
	// li r11,0
	ctx.r11.s64 = 0;
loc_823D9864:
	// lwz r3,292(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 292);
	// stb r11,284(r29)
	REX_STORE_U8(ctx.r29.u32 + 284, ctx.r11.u8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823d987c
	if (ctx.cr6.eq) goto loc_823D987C;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x823c9570
	ctx.lr = 0x823D987C;
	sub_823C9570(ctx, base);
loc_823D987C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E3100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,200(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lbz r11,153(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 153);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823e33b4
	if (!ctx.cr0.eq) goto loc_823E33B4;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12976(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12976);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823e314c
	if (ctx.cr6.eq) goto loc_823E314C;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823e314c
	if (ctx.cr6.eq) goto loc_823E314C;
	// bl 0x823ec500
	ctx.lr = 0x823E3144;
	sub_823EC500(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x823e33b4
	if (!ctx.cr0.eq) goto loc_823E33B4;
loc_823E314C:
	// bl 0x82213210
	ctx.lr = 0x823E3150;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x823E3160;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e322c
	if (ctx.cr0.eq) goto loc_823E322C;
	// bl 0x82213210
	ctx.lr = 0x823E316C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,7
	ctx.r3.s64 = 7;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x823E317C;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e33b4
	if (ctx.cr0.eq) goto loc_823E33B4;
	// lbz r11,182(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 182);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823e33b4
	if (ctx.cr0.eq) goto loc_823E33B4;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f13,144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,17132(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17132);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x823e33b4
	if (ctx.cr6.lt) goto loc_823E33B4;
	// rotlwi r10,r11,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,26
	ctx.r9.s64 = 26;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stb r11,153(r10)
	REX_STORE_U8(ctx.r10.u32 + 153, ctx.r11.u8);
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// std r9,136(r11)
	REX_STORE_U64(ctx.r11.u32 + 136, ctx.r9.u64);
	// bl 0x823c7bd8
	ctx.lr = 0x823E31D4;
	sub_823C7BD8(ctx, base);
	// lwz r9,196(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// subf r7,r10,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addic. r11,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r11.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt 0x823e3214
	if (ctx.cr0.lt) goto loc_823E3214;
	// lwz r10,16(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
loc_823E31F8:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r8,5(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 5);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq 0x823e3220
	if (ctx.cr0.eq) goto loc_823E3220;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// bge 0x823e31f8
	if (!ctx.cr0.lt) goto loc_823E31F8;
loc_823E3214:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
loc_823E3218:
	// stw r11,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// b 0x823e33b4
	goto loc_823E33B4;
loc_823E3220:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x823e3218
	goto loc_823E3218;
loc_823E322C:
	// bl 0x82213210
	ctx.lr = 0x823E3230;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d5f8
	ctx.lr = 0x823E3240;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e3334
	if (ctx.cr0.eq) goto loc_823E3334;
	// bl 0x82213210
	ctx.lr = 0x823E324C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,8
	ctx.r3.s64 = 8;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d6e8
	ctx.lr = 0x823E325C;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e33b4
	if (ctx.cr0.eq) goto loc_823E33B4;
	// lbz r11,183(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 183);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823e33b4
	if (ctx.cr0.eq) goto loc_823E33B4;
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f13,144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,17132(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17132);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x823e33b4
	if (ctx.cr6.lt) goto loc_823E33B4;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r9,26
	ctx.r9.s64 = 26;
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stb r10,153(r11)
	REX_STORE_U8(ctx.r11.u32 + 153, ctx.r10.u8);
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
	// bl 0x823c7bd8
	ctx.lr = 0x823E32B8;
	sub_823C7BD8(ctx, base);
	// lwz r9,196(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// addi r11,r9,12
	ctx.r11.s64 = ctx.r9.s64 + 12;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r8,20(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// lwz r6,16(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// clrlwi r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	// subf r7,r7,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r7.u64;
	// subf r8,r6,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r6.u64;
	// addi r10,r7,2
	ctx.r10.s64 = ctx.r7.s64 + 2;
	// srawi r8,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 2;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x823e3214
	if (!ctx.cr6.lt) goto loc_823E3214;
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// subf r6,r5,r6
	ctx.r6.u64 = ctx.r6.u64 - ctx.r5.u64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// srawi r8,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r6.s32 >> 2;
loc_823E3304:
	// lwz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r6,5(r6)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r6.u32 + 5);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x823e3328
	if (ctx.cr0.eq) goto loc_823E3328;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// blt cr6,0x823e3304
	if (ctx.cr6.lt) goto loc_823E3304;
	// b 0x823e3214
	goto loc_823E3214;
loc_823E3328:
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// b 0x823e3218
	goto loc_823E3218;
loc_823E3334:
	// bl 0x82213210
	ctx.lr = 0x823E3338;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x823E3348;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823e33b4
	if (ctx.cr0.eq) goto loc_823E33B4;
	// lwz r10,200(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,27
	ctx.r9.s64 = 27;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stb r11,153(r10)
	REX_STORE_U8(ctx.r10.u32 + 153, ctx.r11.u8);
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,200(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 200);
	// std r9,136(r11)
	REX_STORE_U64(ctx.r11.u32 + 136, ctx.r9.u64);
	// bl 0x823c7bd8
	ctx.lr = 0x823E337C;
	sub_823C7BD8(ctx, base);
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x823c7bd8
	ctx.lr = 0x823E3384;
	sub_823C7BD8(ctx, base);
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lbz r11,5(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823e33b4
	if (ctx.cr0.eq) goto loc_823E33B4;
	// lwz r10,196(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_823E33B4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823F5D28) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823f6748
	sub_823F6748(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F6978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x823F6980;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// li r24,0
	ctx.r24.s64 = 0;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lfs f31,-19936(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -19936);
	ctx.f31.f64 = double(temp.f32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// li r22,255
	ctx.r22.s64 = 255;
	// lis r23,-32112
	ctx.r23.s64 = -2104492032;
	// addi r28,r11,-18544
	ctx.r28.s64 = ctx.r11.s64 + -18544;
	// addi r26,r10,-20336
	ctx.r26.s64 = ctx.r10.s64 + -20336;
	// addi r25,r9,-20440
	ctx.r25.s64 = ctx.r9.s64 + -20440;
loc_823F69C0:
	// addi r11,r28,21668
	ctx.r11.s64 = ctx.r28.s64 + 21668;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r31,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823F69D4;
	sub_823C7AF0(ctx, base);
	// addi r27,r28,21720
	ctx.r27.s64 = ctx.r28.s64 + 21720;
	// lwz r11,-13064(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r4,r31,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	// bne cr6,0x823f69f0
	if (!ctx.cr6.eq) goto loc_823F69F0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// b 0x823f69fc
	goto loc_823F69FC;
loc_823F69F0:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235d7f0
	ctx.lr = 0x823F69FC;
	sub_8235D7F0(ctx, base);
loc_823F69FC:
	// stwx r3,r31,r30
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, ctx.r3.u32);
	// add r11,r29,r25
	ctx.r11.u64 = ctx.r29.u64 + ctx.r25.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f0,r29,r25
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r25.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823F6A24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// lwzx r9,r31,r30
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lfsx f0,r29,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r28,21772
	ctx.r10.s64 = ctx.r28.s64 + 21772;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfsx f13,r29,r11
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f0,60(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lwzx r11,r31,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823f6a8c
	if (!ctx.cr6.eq) goto loc_823F6A8C;
	// lfs f12,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// b 0x823f6a90
	goto loc_823F6A90;
loc_823F6A8C:
	// lfs f12,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_823F6A90:
	// addi r11,r28,21824
	ctx.r11.s64 = ctx.r28.s64 + 21824;
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x823c7f28
	ctx.lr = 0x823F6A9C;
	sub_823C7F28(ctx, base);
	// lwzx r11,r31,r30
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// fmuls f0,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// li r10,68
	ctx.r10.s64 = 68;
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfiwx f0,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.f0.u32);
	// stb r24,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r24.u8);
	// stb r24,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r24.u8);
	// stb r24,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r24.u8);
	// stb r22,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r22.u8);
	// lwzx r3,r31,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r30.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823F6AE4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r29,104
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 104, ctx.xer);
	// blt cr6,0x823f69c0
	if (ctx.cr6.lt) goto loc_823F69C0;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x823c80a8
	ctx.lr = 0x823F6AFC;
	sub_823C80A8(ctx, base);
	// addi r11,r28,21896
	ctx.r11.s64 = ctx.r28.s64 + 21896;
	// li r31,2
	ctx.r31.s64 = 2;
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_823F6B08:
	// lwzu r11,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r30
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// bl 0x823c7f90
	ctx.lr = 0x823F6B18;
	sub_823C7F90(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x823f6b08
	if (!ctx.cr0.eq) goto loc_823F6B08;
	// lwz r3,40(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// bl 0x823c7f90
	ctx.lr = 0x823F6B28;
	sub_823C7F90(ctx, base);
	// bl 0x82213210
	ctx.lr = 0x823F6B2C;
	sub_82213210(ctx, base);
	// lwz r11,19228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// addi r10,r28,21876
	ctx.r10.s64 = ctx.r28.s64 + 21876;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lbz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,29,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x4;
	// lwzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823F6B50;
	sub_823C7AF0(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823F6B74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r22,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r22.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r22,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r22.u8);
	// stb r24,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r24.u8);
	// stb r24,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r24.u8);
	// lwz r3,28(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823F6B9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r22,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r22.u8);
	// stb r24,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r24.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stb r24,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r24.u8);
	// stb r22,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r22.u8);
	// lwz r3,40(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 40);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823F6BC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82406A78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,56(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82406ac0
	if (ctx.cr6.lt) goto loc_82406AC0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
	// b 0x82406ba4
	goto loc_82406BA4;
loc_82406AC0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lbz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// stb r10,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r10.u8);
	// lbz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stb r11,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r11.u8);
	// lbz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 40);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82406ba4
	if (ctx.cr0.eq) goto loc_82406BA4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r30,-32227
	ctx.r30.s64 = -2112028672;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f30,18652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18652);
	ctx.f30.f64 = double(temp.f32);
	// lfs f31,12472(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f31.f64 = double(temp.f32);
	// beq cr6,0x82406b30
	if (ctx.cr6.eq) goto loc_82406B30;
	// bl 0x8259be58
	ctx.lr = 0x82406B08;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82406b30
	if (ctx.cr0.eq) goto loc_82406B30;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f3,17244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 17244);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f2,-12348(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12348);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x82406B30;
	sub_823C5A58(ctx, base);
loc_82406B30:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82406b68
	if (ctx.cr6.eq) goto loc_82406B68;
	// bl 0x8259be58
	ctx.lr = 0x82406B40;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82406b68
	if (ctx.cr0.eq) goto loc_82406B68;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f3,17244(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 17244);
	ctx.f3.f64 = double(temp.f32);
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// fmr f5,f31
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f2,-18216(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18216);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x82406B68;
	sub_823C5A58(ctx, base);
loc_82406B68:
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82406ba4
	if (ctx.cr6.eq) goto loc_82406BA4;
	// bl 0x8259be58
	ctx.lr = 0x82406B78;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82406ba4
	if (ctx.cr0.eq) goto loc_82406BA4;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r5,32(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// fmr f5,f31
	ctx.fpscr.disableFlushMode();
	ctx.f5.f64 = ctx.f31.f64;
	// fmr f4,f31
	ctx.f4.f64 = ctx.f31.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f3,-18200(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18200);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-18204(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18204);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x823c5a58
	ctx.lr = 0x82406BA4;
	sub_823C5A58(ctx, base);
loc_82406BA4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82411620) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x82411628;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-464(r1)
	ea = -464 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// li r23,0
	ctx.r23.s64 = 0;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lfs f31,-19936(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -19936);
	ctx.f31.f64 = double(temp.f32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r30,r23
	ctx.r30.u64 = ctx.r23.u64;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// li r22,255
	ctx.r22.s64 = 255;
	// lis r21,-32112
	ctx.r21.s64 = -2104492032;
	// addi r28,r11,-18544
	ctx.r28.s64 = ctx.r11.s64 + -18544;
	// addi r26,r10,-16168
	ctx.r26.s64 = ctx.r10.s64 + -16168;
	// addi r25,r9,-16280
	ctx.r25.s64 = ctx.r9.s64 + -16280;
loc_82411668:
	// addi r11,r28,2260
	ctx.r11.s64 = ctx.r28.s64 + 2260;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r30,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x823c7af0
	ctx.lr = 0x8241167C;
	sub_823C7AF0(ctx, base);
	// addi r27,r28,2316
	ctx.r27.s64 = ctx.r28.s64 + 2316;
	// lwz r11,-13064(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r4,r30,r27
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// bne cr6,0x82411698
	if (!ctx.cr6.eq) goto loc_82411698;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// b 0x824116a4
	goto loc_824116A4;
loc_82411698:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235d7f0
	ctx.lr = 0x824116A4;
	sub_8235D7F0(ctx, base);
loc_824116A4:
	// stwx r3,r30,r24
	REX_STORE_U32(ctx.r30.u32 + ctx.r24.u32, ctx.r3.u32);
	// add r11,r29,r25
	ctx.r11.u64 = ctx.r29.u64 + ctx.r25.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f0,r29,r25
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r25.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// add r31,r30,r24
	ctx.r31.u64 = ctx.r30.u64 + ctx.r24.u64;
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824116D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// lwzx r9,r30,r24
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r24.u32);
	// lfsx f0,r29,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r26.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r28,2372
	ctx.r10.s64 = ctx.r28.s64 + 2372;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lfsx f13,r29,r11
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f0,60(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 60, temp.u32);
	// lwz r11,16(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfs f13,64(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 64, temp.u32);
	// lwzx r11,r30,r24
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r24.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwzx r10,r30,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r10.u32);
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// lwzx r11,r30,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r27.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82411738
	if (!ctx.cr6.eq) goto loc_82411738;
	// lfs f12,-4(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8241173c
	goto loc_8241173C;
loc_82411738:
	// lfs f12,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_8241173C:
	// addi r11,r28,2428
	ctx.r11.s64 = ctx.r28.s64 + 2428;
	// lwzx r3,r30,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
	// bl 0x823c7f28
	ctx.lr = 0x82411748;
	sub_823C7F28(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// fmuls f0,f1,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f12.f64));
	// li r10,68
	ctx.r10.s64 = 68;
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stfiwx f0,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.f0.u32);
	// stb r23,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r23.u8);
	// stb r23,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r23.u8);
	// stb r23,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r23.u8);
	// stb r22,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r22.u8);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82411790;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// stb r23,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r23.u8);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplwi cr6,r29,112
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 112, ctx.xer);
	// blt cr6,0x82411668
	if (ctx.cr6.lt) goto loc_82411668;
	// lwz r3,0(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// bl 0x823c80a8
	ctx.lr = 0x824117B0;
	sub_823C80A8(ctx, base);
	// lwz r10,4(r24)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r31,r28,2504
	ctx.r31.s64 = ctx.r28.s64 + 2504;
	// li r29,5
	ctx.r29.s64 = 5;
	// li r30,128
	ctx.r30.s64 = 128;
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r11,124(r10)
	REX_STORE_U32(ctx.r10.u32 + 124, ctx.r11.u32);
loc_824117D4:
	// bl 0x82213210
	ctx.lr = 0x824117D8;
	sub_82213210(ctx, base);
	// lbz r11,19280(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 19280);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// beq 0x82411828
	if (ctx.cr0.eq) goto loc_82411828;
	// cmplwi cr6,r11,10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 10, ctx.xer);
	// blt cr6,0x82411810
	if (ctx.cr6.lt) goto loc_82411810;
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bgt cr6,0x82411810
	if (ctx.cr6.gt) goto loc_82411810;
	// stb r30,93(r1)
	REX_STORE_U8(ctx.r1.u32 + 93, ctx.r30.u8);
	// addi r4,r1,92
	ctx.r4.s64 = ctx.r1.s64 + 92;
	// stb r30,92(r1)
	REX_STORE_U8(ctx.r1.u32 + 92, ctx.r30.u8);
	// stb r30,94(r1)
	REX_STORE_U8(ctx.r1.u32 + 94, ctx.r30.u8);
	// stb r22,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r22.u8);
	// b 0x8241183c
	goto loc_8241183C;
loc_82411810:
	// stb r22,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r22.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r23,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r23.u8);
	// stb r23,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r23.u8);
	// stb r22,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r22.u8);
	// b 0x8241183c
	goto loc_8241183C;
loc_82411828:
	// stb r22,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r22.u8);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stb r23,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r23.u8);
	// stb r23,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r23.u8);
	// stb r22,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r22.u8);
loc_8241183C:
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r24
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r24.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82411854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// bne 0x824117d4
	if (!ctx.cr0.eq) goto loc_824117D4;
	// addi r1,r1,464
	ctx.r1.s64 = ctx.r1.s64 + 464;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82429A18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12964(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82429a54
	if (ctx.cr6.eq) goto loc_82429A54;
	// ld r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r11.u32 + 0);
	// bl 0x8273acd0
	ctx.lr = 0x82429A3C;
	sub_8273ACD0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,1188(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1188);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// b 0x82429a5c
	goto loc_82429A5C;
loc_82429A54:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f1,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
loc_82429A5C:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8242AB00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82213210
	ctx.lr = 0x8242AB14;
	sub_82213210(ctx, base);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpwi cr6,r11,254
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 254, ctx.xer);
	// bne cr6,0x8242ab28
	if (!ctx.cr6.eq) goto loc_8242AB28;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8242ab64
	goto loc_8242AB64;
loc_8242AB28:
	// bl 0x82213210
	ctx.lr = 0x8242AB2C;
	sub_82213210(ctx, base);
	// lbz r11,4043(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4043);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8242ab40
	if (ctx.cr0.eq) goto loc_8242AB40;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8242ab64
	goto loc_8242AB64;
loc_8242AB40:
	// bl 0x82213210
	ctx.lr = 0x8242AB44;
	sub_82213210(ctx, base);
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// bl 0x82213210
	ctx.lr = 0x8242AB4C;
	sub_82213210(ctx, base);
	// addi r11,r31,1024
	ctx.r11.s64 = ctx.r31.s64 + 1024;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r3,r11,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_8242AB64:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8242F500) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8242F508;
	__savegprlr_29(ctx, base);
	// stfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242f8a4
	if (ctx.cr6.eq) goto loc_8242F8A4;
	// lbz r11,2321(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 2321);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8242f8a4
	if (ctx.cr0.eq) goto loc_8242F8A4;
	// bl 0x82430458
	ctx.lr = 0x8242F538;
	sub_82430458(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f8a4
	if (!ctx.cr0.eq) goto loc_8242F8A4;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lwz r11,-12856(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12856);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242f588
	if (ctx.cr6.eq) goto loc_8242F588;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r11,-12848(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -12848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242f578
	if (ctx.cr6.eq) goto loc_8242F578;
	// lbz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 72);
	// b 0x8242f57c
	goto loc_8242F57C;
loc_8242F578:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8242F57C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f588
	if (!ctx.cr0.eq) goto loc_8242F588;
	// li r10,1
	ctx.r10.s64 = 1;
loc_8242F588:
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f8a4
	if (!ctx.cr0.eq) goto loc_8242F8A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8244ac68
	ctx.lr = 0x8242F598;
	sub_8244AC68(ctx, base);
	// lwz r11,2380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2380);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// blt cr6,0x8242f5cc
	if (ctx.cr6.lt) goto loc_8242F5CC;
	// lwz r11,2452(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2452);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8242f8a4
	if (ctx.cr6.eq) goto loc_8242F8A4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242f5c0
	if (ctx.cr6.eq) goto loc_8242F5C0;
	// bl 0x825e0378
	ctx.lr = 0x8242F5C0;
	sub_825E0378(ctx, base);
loc_8242F5C0:
	// stw r30,2452(r31)
	REX_STORE_U32(ctx.r31.u32 + 2452, ctx.r30.u32);
	// stw r30,2452(r31)
	REX_STORE_U32(ctx.r31.u32 + 2452, ctx.r30.u32);
	// b 0x8242f8a4
	goto loc_8242F8A4;
loc_8242F5CC:
	// lwz r11,2932(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2932);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f7a4
	if (!ctx.cr0.eq) goto loc_8242F7A4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82440058
	ctx.lr = 0x8242F5EC;
	sub_82440058(ctx, base);
	// lfs f0,2264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f1,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f1.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,2268(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 2268, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,2272(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2272, temp.u32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f31,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f31.f64 = double(temp.f32);
	// fsubs f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8243d490
	ctx.lr = 0x8242F61C;
	sub_8243D490(ctx, base);
	// lwz r11,408(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 408);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F630;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,2264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f1.f64 = double(temp.f32);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8243d6e8
	ctx.lr = 0x8242F648;
	sub_8243D6E8(ctx, base);
	// lwz r11,348(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 348);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F65C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,2264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f1.f64 = double(temp.f32);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8243d1c8
	ctx.lr = 0x8242F674;
	sub_8243D1C8(ctx, base);
	// lwz r11,412(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 412);
	// lwz r6,2404(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 2404);
	// lwz r5,2408(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 2408);
	// lwz r4,2400(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 2400);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F690;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,2264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8243d8a8
	ctx.lr = 0x8242F6B0;
	sub_8243D8A8(ctx, base);
	// lwz r11,416(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 416);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F6C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,2340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f2,2264(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f1.f64 = double(temp.f32);
	// fmr f3,f31
	ctx.f3.f64 = ctx.f31.f64;
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8243d8a8
	ctx.lr = 0x8242F6E4;
	sub_8243D8A8(ctx, base);
	// lwz r11,420(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 420);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F6F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82435be0
	ctx.lr = 0x8242F700;
	sub_82435BE0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824331c8
	ctx.lr = 0x8242F708;
	sub_824331C8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82430db0
	ctx.lr = 0x8242F710;
	sub_82430DB0(ctx, base);
	// lwz r11,2352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8242f79c
	if (!ctx.cr6.eq) goto loc_8242F79C;
	// lwz r11,2476(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2476);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x8242f778
	if (!ctx.cr6.eq) goto loc_8242F778;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82435428
	ctx.lr = 0x8242F730;
	sub_82435428(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f778
	if (!ctx.cr0.eq) goto loc_8242F778;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,452(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 452);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F750;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// stfs f0,2500(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2500, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82438808
	ctx.lr = 0x8242F764;
	sub_82438808(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8242f79c
	if (!ctx.cr0.eq) goto loc_8242F79C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82438c30
	ctx.lr = 0x8242F774;
	sub_82438C30(ctx, base);
	// b 0x8242f79c
	goto loc_8242F79C;
loc_8242F778:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,452(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 452);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F790;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,2500(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2500);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// stfs f0,2500(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2500, temp.u32);
loc_8242F79C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82430120
	ctx.lr = 0x8242F7A4;
	sub_82430120(ctx, base);
loc_8242F7A4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82436af0
	ctx.lr = 0x8242F7B0;
	sub_82436AF0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82430fa0
	ctx.lr = 0x8242F7BC;
	sub_82430FA0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82435730
	ctx.lr = 0x8242F7C4;
	sub_82435730(ctx, base);
	// lbz r11,2464(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2464);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8242f7dc
	if (!ctx.cr0.eq) goto loc_8242F7DC;
	// lwz r3,2868(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2868);
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8223ace0
	ctx.lr = 0x8242F7DC;
	sub_8223ACE0(ctx, base);
loc_8242F7DC:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// li r4,16
	ctx.r4.s64 = 16;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1060);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F7F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8242f810
	if (ctx.cr0.eq) goto loc_8242F810;
	// lwz r3,2724(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2724);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242f810
	if (ctx.cr6.eq) goto loc_8242F810;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x8223ace0
	ctx.lr = 0x8242F810;
	sub_8223ACE0(ctx, base);
loc_8242F810:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F824;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq 0x8242f844
	if (ctx.cr0.eq) goto loc_8242F844;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243b8b8
	ctx.lr = 0x8242F834;
	sub_8243B8B8(ctx, base);
	// b 0x8242f844
	goto loc_8242F844;
loc_8242F838:
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8243b870
	ctx.lr = 0x8242F844;
	sub_8243B870(ctx, base);
loc_8242F844:
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F858;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8242f838
	if (!ctx.cr6.eq) goto loc_8242F838;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,492(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 492);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8242F874;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 30, ctx.xer);
	// blt cr6,0x8242f8a4
	if (ctx.cr6.lt) goto loc_8242F8A4;
	// lwz r11,2352(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8242f8a4
	if (!ctx.cr6.eq) goto loc_8242F8A4;
	// lwz r11,2948(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 2948);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8242f8a4
	if (!ctx.cr0.eq) goto loc_8242F8A4;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r11,2948(r31)
	REX_STORE_U32(ctx.r31.u32 + 2948, ctx.r11.u32);
	// bl 0x82217158
	ctx.lr = 0x8242F8A4;
	sub_82217158(ctx, base);
loc_8242F8A4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f30,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8244BB78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f30.u64);
	// stfd f31,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f31,f2
	ctx.f31.f64 = ctx.f2.f64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8244bc0c
	if (ctx.cr6.eq) goto loc_8244BC0C;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82432538
	ctx.lr = 0x8244BBB8;
	sub_82432538(ctx, base);
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// fadds f31,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 + ctx.f31.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 952);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244BBD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8244bc04
	if (ctx.cr0.eq) goto loc_8244BC04;
	// lwz r3,2340(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 2340);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,956(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 956);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8244BBF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// fadds f30,f0,f30
	ctx.f30.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fadds f31,f13,f31
	ctx.f31.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
loc_8244BC04:
	// stfs f30,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 16, temp.u32);
	// stfs f31,20(r30)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
loc_8244BC0C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f30,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f31,-32(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82450628) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r3)
	REX_STORE_U32(ctx.r3.u32 + 52, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82450C48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82450C50;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// clrlwi. r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82450d60
	if (ctx.cr0.eq) goto loc_82450D60;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82450d68
	if (ctx.cr6.eq) goto loc_82450D68;
	// lwz r9,2504(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 2504);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82450c98
	if (ctx.cr6.eq) goto loc_82450C98;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,-24072
	ctx.r11.s64 = ctx.r11.s64 + -24072;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x82450ca0
	if (!ctx.cr6.eq) goto loc_82450CA0;
loc_82450C98:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// b 0x82450cac
	goto loc_82450CAC;
loc_82450CA0:
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
loc_82450CAC:
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82450cc0
	if (!ctx.cr6.eq) goto loc_82450CC0;
loc_82450CB8:
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// b 0x82450d68
	goto loc_82450D68;
loc_82450CC0:
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// rlwinm r9,r11,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// lwz r10,-12816(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82450cb8
	if (!ctx.cr6.eq) goto loc_82450CB8;
	// lwz r30,4(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82450cb8
	if (ctx.cr6.eq) goto loc_82450CB8;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82450d18
	if (ctx.cr6.eq) goto loc_82450D18;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82450D0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// beq cr6,0x82450d2c
	if (ctx.cr6.eq) goto loc_82450D2C;
loc_82450D18:
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stb r29,65(r31)
	REX_STORE_U8(ctx.r31.u32 + 65, ctx.r29.u8);
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
loc_82450D2C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82450D40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// stw r3,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r3.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82450d58
	if (!ctx.cr6.eq) goto loc_82450D58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82451208
	ctx.lr = 0x82450D58;
	sub_82451208(ctx, base);
loc_82450D58:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x82450d64
	goto loc_82450D64;
loc_82450D60:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82450D64:
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
loc_82450D68:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82456360) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82453078
	ctx.lr = 0x8245637C;
	sub_82453078(ctx, base);
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// addi r30,r31,56
	ctx.r30.s64 = ctx.r31.s64 + 56;
	// lwz r10,60(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824563a4
	if (ctx.cr0.eq) goto loc_824563A4;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stb r10,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r10.u8);
loc_824563A4:
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r5,8(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x824563d4
	if (ctx.cr6.eq) goto loc_824563D4;
	// subf r11,r5,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r31,r6,r3
	ctx.r31.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x824563d0
	if (!ctx.cr0.gt) goto loc_824563D0;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x824563D0;
	sub_827388E8(ctx, base);
loc_824563D0:
	// stw r31,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r31.u32);
loc_824563D4:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8245D190) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8245d1bc
	if (!ctx.cr6.eq) goto loc_8245D1BC;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x8259be58
	ctx.lr = 0x8245D1B8;
	sub_8259BE58(ctx, base);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
loc_8245D1BC:
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8245E748) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8245E750;
	__savegprlr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r28,-12864(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + -12864);
	// lwz r11,28(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245e9dc
	if (ctx.cr6.eq) goto loc_8245E9DC;
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8245e9dc
	if (!ctx.cr6.eq) goto loc_8245E9DC;
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8245e9dc
	if (!ctx.cr6.eq) goto loc_8245E9DC;
	// bl 0x82213210
	ctx.lr = 0x8245E784;
	sub_82213210(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// bl 0x82213210
	ctx.lr = 0x8245E78C;
	sub_82213210(ctx, base);
	// addi r31,r3,4120
	ctx.r31.s64 = ctx.r3.s64 + 4120;
	// addi r9,r1,81
	ctx.r9.s64 = ctx.r1.s64 + 81;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// li r11,1
	ctx.r11.s64 = 1;
	// lbz r8,36(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 36);
	// stb r30,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r30.u8);
	// stb r30,1(r9)
	REX_STORE_U8(ctx.r9.u32 + 1, ctx.r30.u8);
	// stb r30,2(r9)
	REX_STORE_U8(ctx.r9.u32 + 2, ctx.r30.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stb r8,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r8.u8);
loc_8245E7B8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x8245e7d4
	if (ctx.cr6.lt) goto loc_8245E7D4;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bge cr6,0x8245e7d4
	if (!ctx.cr6.lt) goto loc_8245E7D4;
	// add r10,r11,r31
	ctx.r10.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r10,32(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 32);
	// b 0x8245e7d8
	goto loc_8245E7D8;
loc_8245E7D4:
	// li r10,-1
	ctx.r10.s64 = -1;
loc_8245E7D8:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stbx r10,r11,r9
	REX_STORE_U8(ctx.r11.u32 + ctx.r9.u32, ctx.r10.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x8245e7b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245E7B8;
	// lbz r11,104(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 104);
	// lbz r10,105(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 105);
	// rotlwi r11,r11,8
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 8);
	// lbz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r9,81(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// lbz r10,106(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 106);
	// rlwimi r9,r8,8,16,23
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r9.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r8,82(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// lbz r7,83(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// clrlwi r9,r9,16
	ctx.r9.u64 = ctx.r9.u32 & 0xFFFF;
	// lbz r6,107(r28)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r28.u32 + 107);
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// rlwimi r8,r9,8,0,23
	ctx.r8.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r8.u64 & 0xFFFFFFFF000000FF);
	// rlwinm r11,r11,8,0,23
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFFFFFF00;
	// rlwimi r7,r8,8,0,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r7.u64 & 0xFFFFFFFF000000FF);
	// or r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 | ctx.r6.u64;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8245e84c
	if (ctx.cr6.eq) goto loc_8245E84C;
	// lwz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// ori r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 32;
	// stw r11,52(r28)
	REX_STORE_U32(ctx.r28.u32 + 52, ctx.r11.u32);
	// stw r10,104(r28)
	REX_STORE_U32(ctx.r28.u32 + 104, ctx.r10.u32);
loc_8245E84C:
	// li r11,12
	ctx.r11.s64 = 12;
	// addi r10,r1,87
	ctx.r10.s64 = ctx.r1.s64 + 87;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_8245E85C:
	// stbu r9,1(r10)
	ea = 1 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r9.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x8245e85c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245E85C;
	// li r5,9
	ctx.r5.s64 = 9;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8273a4b8
	ctx.lr = 0x8245E874;
	sub_8273A4B8(ctx, base);
	// addi r3,r28,108
	ctx.r3.s64 = ctx.r28.s64 + 108;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_8245E884:
	// li r10,4
	ctx.r10.s64 = 4;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8245E894:
	// lbzx r10,r7,r11
	ctx.r10.u64 = REX_LOAD_U8(ctx.r7.u32 + ctx.r11.u32);
	// rlwinm r9,r8,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 | ctx.r9.u64;
	// bdnz 0x8245e894
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245E894;
	// li r9,4
	ctx.r9.s64 = 4;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8245E8B8:
	// lbzx r9,r6,r11
	ctx.r9.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r11.u32);
	// rlwinm r10,r10,8,0,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFFFFFF00;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// bdnz 0x8245e8b8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245E8B8;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8245e8ec
	if (!ctx.cr6.eq) goto loc_8245E8EC;
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmpwi cr6,r5,3
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 3, ctx.xer);
	// blt cr6,0x8245e884
	if (ctx.cr6.lt) goto loc_8245E884;
	// b 0x8245e904
	goto loc_8245E904;
loc_8245E8EC:
	// lwz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// li r5,12
	ctx.r5.s64 = 12;
	// ori r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 64;
	// stw r11,52(r28)
	REX_STORE_U32(ctx.r28.u32 + 52, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x8245E904;
	sub_8273A030(ctx, base);
loc_8245E904:
	// li r10,15
	ctx.r10.s64 = 15;
	// lbz r11,4033(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 4033);
	// addi r9,r1,108
	ctx.r9.s64 = ctx.r1.s64 + 108;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8245E918:
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x8245e918
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245E918;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// li r9,15
	ctx.r9.s64 = 15;
	// addi r8,r1,108
	ctx.r8.s64 = ctx.r1.s64 + 108;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// lbz r7,12983(r7)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r7.u32 + 12983);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stw r7,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r7.u32);
loc_8245E93C:
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8245e964
	if (!ctx.cr6.lt) goto loc_8245E964;
	// cmplwi cr6,r10,15
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 15, ctx.xer);
	// bge cr6,0x8245e964
	if (!ctx.cr6.lt) goto loc_8245E964;
	// mulli r9,r11,15
	ctx.r9.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(15));
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r9,-5
	ctx.r9.s64 = ctx.r9.s64 + -5;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r9,r31
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
loc_8245E964:
	// stwu r9,4(r8)
	ea = 4 + ctx.r8.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r8.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x8245e93c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245E93C;
	// addi r3,r28,120
	ctx.r3.s64 = ctx.r28.s64 + 120;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8245E97C:
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// bge cr6,0x8245e990
	if (!ctx.cr6.lt) goto loc_8245E990;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwzx r9,r11,r10
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x8245e994
	goto loc_8245E994;
loc_8245E990:
	// lwz r9,172(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 172);
loc_8245E994:
	// cmplwi cr6,r8,16
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 16, ctx.xer);
	// bge cr6,0x8245e9a4
	if (!ctx.cr6.lt) goto loc_8245E9A4;
	// lwzx r10,r11,r3
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// b 0x8245e9a8
	goto loc_8245E9A8;
loc_8245E9A4:
	// lwz r10,60(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
loc_8245E9A8:
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8245e9c4
	if (!ctx.cr6.eq) goto loc_8245E9C4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmpwi cr6,r11,64
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 64, ctx.xer);
	// blt cr6,0x8245e97c
	if (ctx.cr6.lt) goto loc_8245E97C;
	// b 0x8245e9dc
	goto loc_8245E9DC;
loc_8245E9C4:
	// lwz r11,52(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 52);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// li r5,64
	ctx.r5.s64 = 64;
	// ori r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 128;
	// stw r11,52(r28)
	REX_STORE_U32(ctx.r28.u32 + 52, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x8245E9DC;
	sub_8273A030(ctx, base);
loc_8245E9DC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824738D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824738E0;
	__savegprlr_27(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// lfs f13,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x8247390c
	if (!ctx.cr6.eq) goto loc_8247390C;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_8247390C:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,-1560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r10,-31120
	ctx.r10.s64 = ctx.r10.s64 + -31120;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82473968;
	sub_8255F918(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,352
	ctx.r4.s64 = 352;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82473984;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824739b4
	if (ctx.cr0.eq) goto loc_824739B4;
	// addic r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	// li r10,2
	ctx.r10.s64 = 2;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// and r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 & ctx.r10.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x824be840
	ctx.lr = 0x824739AC;
	sub_824BE840(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x824739b8
	goto loc_824739B8;
loc_824739B4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_824739B8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824739c8
	if (!ctx.cr6.eq) goto loc_824739C8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x824739d0
	goto loc_824739D0;
loc_824739C8:
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stb r27,80(r11)
	REX_STORE_U8(ctx.r11.u32 + 80, ctx.r27.u8);
loc_824739D0:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8247BD28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8247BD30;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247BD4C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8247bf1c
	if (!ctx.cr0.eq) goto loc_8247BF1C;
	// lhz r11,6(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,128(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 128);
	// addi r31,r30,120
	ctx.r31.s64 = ctx.r30.s64 + 120;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r8,124(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// lis r27,-32111
	ctx.r27.s64 = -2104426496;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// subf r11,r8,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r8.u64;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r28,0
	ctx.r28.s64 = 0;
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x8247bddc
	if (ctx.cr0.eq) goto loc_8247BDDC;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8247BD9C:
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// lfs f0,-29316(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -29316);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247BDBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8247bd9c
	if (ctx.cr6.lt) goto loc_8247BD9C;
loc_8247BDDC:
	// lwz r11,144(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 144);
	// addi r31,r30,136
	ctx.r31.s64 = ctx.r30.s64 + 136;
	// lwz r10,140(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// li r28,0
	ctx.r28.s64 = 0;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8247be3c
	if (ctx.cr0.eq) goto loc_8247BE3C;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8247BDFC:
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// lfs f0,-29316(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -29316);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247BE1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8247bdfc
	if (ctx.cr6.lt) goto loc_8247BDFC;
loc_8247BE3C:
	// addi r4,r30,296
	ctx.r4.s64 = ctx.r30.s64 + 296;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8231e0d8
	ctx.lr = 0x8247BE48;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a45a0
	ctx.lr = 0x8247BE58;
	sub_825A45A0(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// stfs f1,312(r30)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r30.u32 + 312, temp.u32);
	// blt cr6,0x8247be9c
	if (ctx.cr6.lt) goto loc_8247BE9C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8247BE9C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8247beac
	if (ctx.cr0.eq) goto loc_8247BEAC;
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,312(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 312, temp.u32);
loc_8247BEAC:
	// lwz r11,336(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 336);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8247bed4
	if (!ctx.cr6.eq) goto loc_8247BED4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,312(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfs f0,312(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 312, temp.u32);
	// b 0x8247bef4
	goto loc_8247BEF4;
loc_8247BED4:
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,160(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 160);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247BEF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8247BEF4:
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// lfs f0,312(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247BF14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,271(r30)
	REX_STORE_U8(ctx.r30.u32 + 271, ctx.r11.u8);
loc_8247BF1C:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824901A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824901D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lhz r10,6(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// lfs f0,-8644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwa r11,732(r31)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 732));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// bctrl 
	ctx.lr = 0x82490220;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82495428) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4032(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4032);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82495464
	if (ctx.cr6.eq) goto loc_82495464;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8249545C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
loc_82495464:
	// lwz r11,4036(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4036);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8249548c
	if (ctx.cr6.eq) goto loc_8249548C;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82495484;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
loc_8249548C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,4072(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4072);
	// mulli r10,r10,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(52));
	// lwz r11,-12824(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824954c4
	if (ctx.cr6.eq) goto loc_824954C4;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x824954c4
	if (ctx.cr6.eq) goto loc_824954C4;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x824954c8
	if (!ctx.cr6.eq) goto loc_824954C8;
loc_824954C4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824954C8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
	// lwz r11,4080(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4080);
	// mulli r11,r11,52
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824954fc
	if (ctx.cr6.eq) goto loc_824954FC;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x824954fc
	if (ctx.cr6.eq) goto loc_824954FC;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x82495500
	if (!ctx.cr6.eq) goto loc_82495500;
loc_824954FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82495500:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
	// lwz r11,4040(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4040);
	// mulli r11,r11,52
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82495534
	if (ctx.cr6.eq) goto loc_82495534;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82495534
	if (ctx.cr6.eq) goto loc_82495534;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x82495538
	if (!ctx.cr6.eq) goto loc_82495538;
loc_82495534:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82495538:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
	// lwz r11,4048(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4048);
	// mulli r11,r11,52
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8249556c
	if (ctx.cr6.eq) goto loc_8249556C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8249556c
	if (ctx.cr6.eq) goto loc_8249556C;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x82495570
	if (!ctx.cr6.eq) goto loc_82495570;
loc_8249556C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82495570:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
	// lwz r11,4056(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4056);
	// mulli r11,r11,52
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824955a4
	if (ctx.cr6.eq) goto loc_824955A4;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x824955a4
	if (ctx.cr6.eq) goto loc_824955A4;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x824955a8
	if (!ctx.cr6.eq) goto loc_824955A8;
loc_824955A4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824955A8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
	// lwz r11,4064(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4064);
	// mulli r11,r11,52
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(52));
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x824955dc
	if (ctx.cr6.eq) goto loc_824955DC;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x824955dc
	if (ctx.cr6.eq) goto loc_824955DC;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// bne cr6,0x824955e0
	if (!ctx.cr6.eq) goto loc_824955E0;
loc_824955DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824955E0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824955f0
	if (!ctx.cr0.eq) goto loc_824955F0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8246a168
	ctx.lr = 0x824955F0;
	sub_8246A168(ctx, base);
loc_824955F0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824A70C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,-20936
	ctx.r11.s64 = ctx.r11.s64 + -20936;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824A70F4;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a7104
	if (ctx.cr0.eq) goto loc_824A7104;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824A7104;
	sub_825E0378(ctx, base);
loc_824A7104:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824A92D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A9308;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-3896(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -3896);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25804);
	ctx.f12.f64 = double(temp.f32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f0,f11,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f12
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// bctrl 
	ctx.lr = 0x824A9358;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r9,32688
	ctx.r9.s64 = ctx.r9.s64 + 32688;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// ld r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 60);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// bl 0x825a4da8
	ctx.lr = 0x824A93A4;
	sub_825A4DA8(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// stfs f1,356(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A93CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,360(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 360, temp.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824B08C0) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,136(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_824B0E48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824B0E50;
	__savegprlr_29(ctx, base);
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f29.u64);
	// stfd f30,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,2
	ctx.r11.s64 = 2;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r11,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r11.u32);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r9,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r9.u32);
	// li r4,3
	ctx.r4.s64 = 3;
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x824B0E90;
	sub_825A49B0(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,144
	ctx.r4.s64 = 144;
	// clrlwi r31,r3,24
	ctx.r31.u64 = ctx.r3.u32 & 0xFF;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x824B0EAC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824b0ed4
	if (ctx.cr0.eq) goto loc_824B0ED4;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// rlwinm r10,r31,2,22,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0x3FC;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f1,-24876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24876);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r4,r10,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// bl 0x8221d738
	ctx.lr = 0x824B0ECC;
	sub_8221D738(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x824b0ed8
	goto loc_824B0ED8;
loc_824B0ED4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_824B0ED8:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824b0ff4
	if (ctx.cr6.eq) goto loc_824B0FF4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B0EF8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-3440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3440);
	ctx.f2.f64 = double(temp.f32);
	// fneg f1,f2
	ctx.f1.u64 = ctx.f2.u64 ^ 0x8000000000000000;
	// bl 0x825a4a40
	ctx.lr = 0x824B0F0C;
	sub_825A4A40(ctx, base);
	// lis r29,-32240
	ctx.r29.s64 = -2112880640;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r10,r29,15284
	ctx.r10.s64 = ctx.r29.s64 + 15284;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-7108(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7108);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-2816(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2816);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824B0F2C;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,15284(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 15284);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// addi r29,r11,-4080
	ctx.r29.s64 = ctx.r11.s64 + -4080;
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// lfs f2,1504(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1504);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824B0F4C;
	sub_825A4A40(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x824B0F58;
	sub_822EA1A8(ctx, base);
	// lfs f0,236(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f29
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f29.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fadds f1,f30,f0
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x824B0F6C;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f29
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f29.f64));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B0F90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B0FA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// stb r30,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r30.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b0fbc
	if (ctx.cr6.eq) goto loc_824B0FBC;
	// stb r30,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r30.u8);
loc_824B0FBC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824B0FD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,171
	ctx.r10.s64 = 171;
	// sth r10,88(r31)
	REX_STORE_U16(ctx.r31.u32 + 88, ctx.r10.u16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824b0fec
	if (ctx.cr6.eq) goto loc_824B0FEC;
	// sth r10,84(r11)
	REX_STORE_U16(ctx.r11.u32 + 84, ctx.r10.u16);
loc_824B0FEC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824b0ff8
	goto loc_824B0FF8;
loc_824B0FF4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824B0FF8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824BAF70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824BAF78;
	__savegprlr_27(ctx, base);
	// stfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f30.u64);
	// stfd f31,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,280(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 280);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f30,f1
	ctx.f30.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824bb258
	if (ctx.cr6.lt) goto loc_824BB258;
	// beq cr6,0x824bb210
	if (ctx.cr6.eq) goto loc_824BB210;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x824bafb4
	if (ctx.cr6.lt) goto loc_824BAFB4;
	// bne cr6,0x824bb5e8
	if (!ctx.cr6.eq) goto loc_824BB5E8;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x824bb5e8
	goto loc_824BB5E8;
loc_824BAFB4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f1,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824BAFD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// lfs f10,-232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f10.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// bge cr6,0x824baff8
	if (!ctx.cr6.lt) goto loc_824BAFF8;
	// lfs f13,1812(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1812);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// b 0x824baffc
	goto loc_824BAFFC;
loc_824BAFF8:
	// stfs f10,324(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
loc_824BAFFC:
	// addi r28,r31,68
	ctx.r28.s64 = ctx.r31.s64 + 68;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8231e0d8
	ctx.lr = 0x824BB00C;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r9,332(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r10,32496
	ctx.r10.s64 = ctx.r10.s64 + 32496;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r5,-32227
	ctx.r5.s64 = -2112028672;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r5,30176
	ctx.r5.s64 = ctx.r5.s64 + 30176;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f31,25504(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 25504);
	ctx.f31.f64 = double(temp.f32);
	// std r11,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r11.u64);
	// ble cr6,0x824bb14c
	if (!ctx.cr6.gt) goto loc_824BB14C;
	// lfs f0,2012(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2012);
	ctx.f0.f64 = double(temp.f32);
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stb r30,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r30.u8);
	// stb r30,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r30.u8);
	// lfs f12,320(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f12.f64 = double(temp.f32);
	// stb r27,186(r31)
	REX_STORE_U8(ctx.r31.u32 + 186, ctx.r27.u8);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwa r11,84(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 84));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fsubs f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bge cr6,0x824bb124
	if (!ctx.cr6.lt) goto loc_824BB124;
	// stb r30,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r30.u8);
	// stb r30,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r30.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// stb r30,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r30.u8);
	// b 0x824bb140
	goto loc_824BB140;
loc_824BB124:
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lbz r10,87(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// stb r10,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// stb r10,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r10.u8);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
loc_824BB140:
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x824BB148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f10,-232(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f10.f64 = double(temp.f32);
loc_824BB14C:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f10
	ctx.cr6.compare(ctx.f0.f64, ctx.f10.f64);
	// ble cr6,0x824bb16c
	if (!ctx.cr6.gt) goto loc_824BB16C;
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824bb16c
	if (!ctx.cr6.eq) goto loc_824BB16C;
	// stw r27,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r27.u32);
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
loc_824BB16C:
	// lfs f13,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// blt cr6,0x824bb180
	if (ctx.cr6.lt) goto loc_824BB180;
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_824BB180:
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f12,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lfs f13,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r28)
	REX_STORE_U64(ctx.r28.u32 + 0, ctx.r11.u64);
	// b 0x824bb5e8
	goto loc_824BB5E8;
loc_824BB210:
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fadds f13,f0,f30
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stfs f13,304(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f0,1812(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1812);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824bb5e8
	if (ctx.cr6.lt) goto loc_824BB5E8;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824BB24C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// b 0x824bb5dc
	goto loc_824BB5DC;
loc_824BB258:
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lwz r9,288(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r8,292(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 292);
	// addi r29,r10,30176
	ctx.r29.s64 = ctx.r10.s64 + 30176;
	// li r27,1
	ctx.r27.s64 = 1;
	// addi r30,r31,296
	ctx.r30.s64 = ctx.r31.s64 + 296;
	// stb r27,328(r31)
	REX_STORE_U8(ctx.r31.u32 + 328, ctx.r27.u8);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f31,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// stb r27,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r27.u8);
	// lfs f0,6552(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 6552);
	ctx.f0.f64 = double(temp.f32);
	// stw r9,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r9.u32);
	// stfs f31,304(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stw r8,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r28,r11,12468
	ctx.r28.s64 = ctx.r11.s64 + 12468;
	// bl 0x8231e0d8
	ctx.lr = 0x824BB2A4;
	sub_8231E0D8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,340(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// stw r9,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r9.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r10.u32);
	// beq cr6,0x824bb3ac
	if (ctx.cr6.eq) goto loc_824BB3AC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824bb3ac
	if (ctx.cr6.eq) goto loc_824BB3AC;
	// lwz r10,344(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// clrlwi. r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824bb37c
	if (!ctx.cr0.eq) goto loc_824BB37C;
	// lfs f2,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a7c80
	ctx.lr = 0x824BB2E4;
	sub_825A7C80(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,1404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1404);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
loc_824BB2F4:
	// lfs f0,140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 140);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfs f13,144(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fctid f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvtsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fnmsubs f30,f0,f13,f12
	ctx.f30.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f12.f64)));
loc_824BB310:
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82738be0
	ctx.lr = 0x824BB318;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x824BB334;
	sub_82738CC0(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// b 0x824bb528
	goto loc_824BB528;
loc_824BB37C:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x824bb530
	if (!ctx.cr6.eq) goto loc_824BB530;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824bb530
	if (ctx.cr6.eq) goto loc_824BB530;
	// lfs f2,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a7c80
	ctx.lr = 0x824BB398;
	sub_825A7C80(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,1404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1404);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f1,f0
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// b 0x824bb2f4
	goto loc_824BB2F4;
loc_824BB3AC:
	// lwz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824bb3e0
	if (!ctx.cr6.eq) goto loc_824BB3E0;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// li r3,62
	ctx.r3.s64 = 62;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82240a58
	ctx.lr = 0x824BB3E0;
	sub_82240A58(ctx, base);
loc_824BB3E0:
	// lwz r11,344(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x824bb450
	if (!ctx.cr0.eq) goto loc_824BB450;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824bb450
	if (ctx.cr6.eq) goto loc_824BB450;
	// lwz r10,340(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f31.f64;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// blt cr6,0x824bb43c
	if (ctx.cr6.lt) goto loc_824BB43C;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fmuls f4,f0,f13
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
loc_824BB43C:
	// lfs f2,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a7c80
	ctx.lr = 0x824BB448;
	sub_825A7C80(ctx, base);
	// fadds f30,f1,f4
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64 + ctx.f4.f64));
	// b 0x824bb310
	goto loc_824BB310;
loc_824BB450:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x824bb530
	if (!ctx.cr6.eq) goto loc_824BB530;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824bb530
	if (ctx.cr6.eq) goto loc_824BB530;
	// lwz r10,340(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 340);
	// fmr f4,f31
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f31.f64;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// blt cr6,0x824bb4b0
	if (ctx.cr6.lt) goto loc_824BB4B0;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrldi r10,r10,32
	ctx.r10.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f12.f64));
	// fmuls f4,f0,f13
	ctx.f4.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
loc_824BB4B0:
	// lfs f2,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,300(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a7c80
	ctx.lr = 0x824BB4BC;
	sub_825A7C80(ctx, base);
	// fsubs f30,f1,f4
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f1.f64 - ctx.f4.f64));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x82738be0
	ctx.lr = 0x824BB4C8;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x824BB4E4;
	sub_82738CC0(ctx, base);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_824BB528:
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
loc_824BB530:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x824BB53C;
	sub_8231E0D8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// bl 0x8231e0d8
	ctx.lr = 0x824BB558;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a45a0
	ctx.lr = 0x824BB568;
	sub_825A45A0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f1,308(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x824bb5a4
	if (ctx.cr6.lt) goto loc_824BB5A4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_824BB5A4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824bb5b4
	if (ctx.cr0.eq) goto loc_824BB5B4;
	// fneg f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 ^ 0x8000000000000000;
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
loc_824BB5B4:
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// fneg f13,f0
	ctx.f13.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lfs f0,1132(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 1132);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fsubs f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824BB5DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824BB5DC:
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
loc_824BB5E8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// lfd f31,-56(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824F1C00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x824F1C08;
	__savegprlr_24(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// li r29,-1
	ctx.r29.s64 = -1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r29,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r29.u32);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824F1C34;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,1532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1532);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,99(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 99);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x824f1e84
	if (ctx.cr6.lt) goto loc_824F1E84;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lwz r9,1056(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1056);
	// lfs f10,1116(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1116);
	ctx.f10.f64 = double(temp.f32);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// lfs f9,1120(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1120);
	ctx.f9.f64 = double(temp.f32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfs f11,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f11.f64 = double(temp.f32);
	// beq cr6,0x824f1c88
	if (ctx.cr6.eq) goto loc_824F1C88;
	// lfs f11,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
loc_824F1C88:
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r8,r10,-1560
	ctx.r8.s64 = ctx.r10.s64 + -1560;
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// lfs f12,2184(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 2184);
	ctx.f12.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fmuls f9,f9,f12
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfs f9,124(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// fmuls f12,f11,f12
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfs f9,116(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r28,r1,160
	ctx.r28.s64 = ctx.r1.s64 + 160;
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r25,-32226
	ctx.r25.s64 = -2111963136;
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r26,r1,176
	ctx.r26.s64 = ctx.r1.s64 + 176;
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwz r30,-13032(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r5,r25,2688
	ctx.r5.s64 = ctx.r25.s64 + 2688;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stw r24,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r24.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stw r5,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r5.u32);
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v60,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f9,140(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f9,136(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f9,132(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v58,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,19380(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 19380);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f10,f10,f12
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f8,1124(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1124);
	ctx.f8.f64 = double(temp.f32);
	// lfs f12,-1560(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1560);
	ctx.f12.f64 = double(temp.f32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// fmadds f12,f8,f12,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f8.f64, ctx.f12.f64, ctx.f10.f64)));
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// vsubfp128 v62,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lfs f0,1760(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1760);
	ctx.f0.f64 = double(temp.f32);
	// vaddfp128 v61,v61,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v58.f32)));
	// fadds f0,f12,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f11.f64));
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stvx128 v61,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// lfs f0,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,176
	ctx.r8.s64 = ctx.r1.s64 + 176;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r10,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r10.u64);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// beq cr6,0x824f1e38
	if (ctx.cr6.eq) goto loc_824F1E38;
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lfs f0,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x823aefa8
	ctx.lr = 0x824F1E34;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_824F1E38:
	// lfs f0,196(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,81(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r8,132(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// beq cr6,0x824f1e80
	if (ctx.cr6.eq) goto loc_824F1E80;
	// clrlwi r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	// addi r10,r31,68
	ctx.r10.s64 = ctx.r31.s64 + 68;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x823b0938
	ctx.lr = 0x824F1E7C;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_824F1E80:
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
loc_824F1E84:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82506148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82506150;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af20
	ctx.lr = 0x82506158;
	__savefpr_26(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f1.f64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,88(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// addi r30,r11,12236
	ctx.r30.s64 = ctx.r11.s64 + 12236;
	// ld r11,2880(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 2880);
	// lfs f26,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f26.f64 = double(temp.f32);
	// fmr f29,f26
	ctx.f29.f64 = ctx.f26.f64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x824443c8
	ctx.lr = 0x82506188;
	sub_824443C8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r29,r11,32256
	ctx.r29.s64 = ctx.r11.s64 + 32256;
	// beq 0x825063c4
	if (ctx.cr0.eq) goto loc_825063C4;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82430a88
	ctx.lr = 0x825061A0;
	sub_82430A88(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f11,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,660(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 660);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f11,f13
	ctx.cr6.compare(ctx.f11.f64, ctx.f13.f64);
	// blt cr6,0x8250635c
	if (ctx.cr6.lt) goto loc_8250635C;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r28,-32240
	ctx.r28.s64 = -2112880640;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// vsubfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f13,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v58,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v59,v59,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vsubfp128 v63,v63,v59
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lvx128 v6,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stfs f13,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f11,-29492(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -29492);
	ctx.f11.f64 = double(temp.f32);
	// vrsqrtefp v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// vmulfp128 v12,v0,v6
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vcmpeqfp128 v10,v0,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v8,v0,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v11,v13,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v5,v13,v62
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vnmsubfp v6,v12,v11,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v6.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v11,v10,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmaddfp v13,v13,v6,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v12,v13,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vor128 v63,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpeqfp128 v12,v63,v62
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v13,v0,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vsel v12,v8,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v0,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fmr f29,f13
	ctx.f29.f64 = ctx.f13.f64;
	// fcmpu cr6,f13,f11
	ctx.cr6.compare(ctx.f13.f64, ctx.f11.f64);
	// bgt cr6,0x82506310
	if (ctx.cr6.gt) goto loc_82506310;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_82506310:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f13,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f28,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f28.f64 = double(temp.f32);
	// stfs f28,84(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x82506360
	goto loc_82506360;
loc_8250635C:
	// lfs f28,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f28.f64 = double(temp.f32);
loc_82506360:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f12,124(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r9,32752
	ctx.r9.s64 = ctx.r9.s64 + 32752;
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,316(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// b 0x825063c8
	goto loc_825063C8;
loc_825063C4:
	// lfs f28,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f28.f64 = double(temp.f32);
loc_825063C8:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lbz r10,312(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 312);
	// lfs f31,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f30.f64 = double(temp.f32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f0,684(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 684);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f0,f27,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f27.f64, ctx.f13.f64)));
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// beq 0x825063f8
	if (ctx.cr0.eq) goto loc_825063F8;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x825063fc
	goto loc_825063FC;
loc_825063F8:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_825063FC:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// fmuls f1,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82506418;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,680(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 680);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x825064dc
	if (!ctx.cr6.gt) goto loc_825064DC;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f13,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r31,68
	ctx.r11.s64 = ctx.r31.s64 + 68;
	// fcmpu cr6,f29,f13
	ctx.cr6.compare(ctx.f29.f64, ctx.f13.f64);
	// std r10,68(r31)
	REX_STORE_U64(ctx.r31.u32 + 68, ctx.r10.u64);
	// bge cr6,0x8250653c
	if (!ctx.cr6.lt) goto loc_8250653C;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lfs f0,17096(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17096);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// fmadds f0,f27,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f27.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,308(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// fdivs f0,f0,f29
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f29.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// b 0x8250653c
	goto loc_8250653C;
loc_825064DC:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lbz r10,312(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 312);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f13,676(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 676);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f13,f27,f0
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f27.f64, ctx.f0.f64)));
	// stfs f1,304(r31)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// beq 0x825064fc
	if (ctx.cr0.eq) goto loc_825064FC;
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
loc_825064FC:
	// bl 0x82738cc0
	ctx.lr = 0x82506500;
	sub_82738CC0(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f28,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f28,112(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f28,116(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f13,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
loc_8250653C:
	// lfs f0,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f27.f64));
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
	// fcmpu cr6,f0,f26
	ctx.cr6.compare(ctx.f0.f64, ctx.f26.f64);
	// bge cr6,0x82506590
	if (!ctx.cr6.lt) goto loc_82506590;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r3,199
	ctx.r3.s64 = 199;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x82506588;
	sub_82240A58(ctx, base);
	// lfs f0,3420(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3420);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,340(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 340, temp.u32);
loc_82506590:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bl 0x82738be0
	ctx.lr = 0x825065A4;
	sub_82738BE0(ctx, base);
	// frsp f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64));
	// lfs f0,2852(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2852);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,344(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 344, temp.u32);
	// lfs f13,320(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,140(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f12,136(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f12,132(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f31.f64 = double(temp.f32);
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f30.f64 = double(temp.f32);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x827397e8
	ctx.lr = 0x82506690;
	sub_827397E8(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f31,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v7,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,156(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f30,152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f30,148(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f30,144(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// vmulfp128 v12,v0,v7
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)));
	// vcmpeqfp128 v10,v0,v62
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vcmpeqfp128 v8,v0,v62
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v11,v13,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v6,v13,v62
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vnmsubfp v7,v12,v11,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v7.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v11,v10,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8))));
	// vmaddfp v13,v13,v7,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v12,v13,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vcmpeqfp128 v13,v12,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v12,v0,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vsel v11,v8,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsel v13,v12,v0,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,336(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 336, temp.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af6c
	ctx.lr = 0x82506730;
	__restfpr_26(ctx, base);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82543F70) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82543F78;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,328
	ctx.r4.s64 = 328;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// bl 0x825e02a0
	ctx.lr = 0x82543FAC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82543fd4
	if (ctx.cr0.eq) goto loc_82543FD4;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82543ff8
	ctx.lr = 0x82543FCC;
	sub_82543FF8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x82543fd8
	goto loc_82543FD8;
loc_82543FD4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82543FD8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82543fe8
	if (!ctx.cr6.eq) goto loc_82543FE8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82543ff0
	goto loc_82543FF0;
loc_82543FE8:
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r26,316(r11)
	REX_STORE_U32(ctx.r11.u32 + 316, ctx.r26.u32);
loc_82543FF0:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82545A70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82545A78;
	__savegprlr_22(ctx, base);
	// addi r12,r1,-88
	ctx.r12.s64 = ctx.r1.s64 + -88;
	// bl 0x8273af28
	ctx.lr = 0x82545A80;
	__savefpr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,124(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// lis r22,-32226
	ctx.r22.s64 = -2111963136;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r29,-32111
	ctx.r29.s64 = -2104426496;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,-8644(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// lfs f13,-8580(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8580);
	ctx.f13.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// bctrl 
	ctx.lr = 0x82545ACC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545AE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545B04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r11,12236
	ctx.r30.s64 = ctx.r11.s64 + 12236;
	// lfs f31,232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82545b38
	if (!ctx.cr6.lt) goto loc_82545B38;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545B38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82545B38:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lis r28,-32114
	ctx.r28.s64 = -2104623104;
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,3824(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 3824);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545B64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// lfs f0,-8644(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,-8580(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8580);
	ctx.f13.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f13,f12,f0,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x82545BA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545BC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545BDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82545c04
	if (!ctx.cr6.lt) goto loc_82545C04;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545C04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82545C04:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,3824(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 3824);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f31,3420(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3420);
	ctx.f31.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f30,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// addi r27,r11,-1628
	ctx.r27.s64 = ctx.r11.s64 + -1628;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r24,r31,316
	ctx.r24.s64 = ctx.r31.s64 + 316;
	// lfs f29,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// addi r26,r10,5184
	ctx.r26.s64 = ctx.r10.s64 + 5184;
	// addi r25,r11,5124
	ctx.r25.s64 = ctx.r11.s64 + 5124;
	// addi r23,r9,22072
	ctx.r23.s64 = ctx.r9.s64 + 22072;
loc_82545C5C:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,48(r23)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r23.u32 + 48);
	// li r4,116
	ctx.r4.s64 = 116;
	// bl 0x825e02a0
	ctx.lr = 0x82545C6C;
	sub_825E02A0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82545cd0
	if (ctx.cr0.eq) goto loc_82545CD0;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r28,r29,r11
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545C90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lfs f0,-8644(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// fsubs f28,f1,f0
	ctx.f28.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545CAC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f28.f64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82240940
	ctx.lr = 0x82545CBC;
	sub_82240940(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
	// stw r26,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r26.u32);
	// sth r11,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r11.u16);
	// b 0x82545cd4
	goto loc_82545CD4;
loc_82545CD0:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82545CD4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82545dc0
	if (ctx.cr6.eq) goto loc_82545DC0;
	// addi r11,r27,3804
	ctx.r11.s64 = ctx.r27.s64 + 3804;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// sth r11,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r11.u16);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545D18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545D30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-26215
	ctx.r11.s64 = -1718026240;
	// stb r3,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r3.u8);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// stb r9,86(r30)
	REX_STORE_U8(ctx.r30.u32 + 86, ctx.r9.u8);
	// stw r11,104(r30)
	REX_STORE_U32(ctx.r30.u32 + 104, ctx.r11.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545D64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,36(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545D74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r3,r30,60
	ctx.r3.s64 = ctx.r30.s64 + 60;
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f29.f64;
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82224038
	ctx.lr = 0x82545D88;
	sub_82224038(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x82545D94;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82545dc0
	if (!ctx.cr6.eq) goto loc_82545DC0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82545DC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82545DC0:
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// cmplwi cr6,r29,8
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 8, ctx.xer);
	// blt cr6,0x82545c5c
	if (ctx.cr6.lt) goto loc_82545C5C;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r3,324
	ctx.r3.s64 = 324;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f0,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82240a58
	ctx.lr = 0x82545E08;
	sub_82240A58(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-88
	ctx.r12.s64 = ctx.r1.s64 + -88;
	// bl 0x8273af74
	ctx.lr = 0x82545E14;
	__restfpr_28(ctx, base);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8255AAA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r11,308(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 308);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,7496
	ctx.r10.s64 = ctx.r10.s64 + 7496;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq cr6,0x8255ab00
	if (ctx.cr6.eq) goto loc_8255AB00;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8255AAE0;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255aaf8
	if (ctx.cr0.eq) goto loc_8255AAF8;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x82222bb0
	ctx.lr = 0x8255AAF8;
	sub_82222BB0(ctx, base);
loc_8255AAF8:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
loc_8255AB00:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x8255AB08;
	sub_82469FB0(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x8255AB1C;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255ab2c
	if (ctx.cr0.eq) goto loc_8255AB2C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8255AB2C;
	sub_825E0378(ctx, base);
loc_8255AB2C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8255F914) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8255F918) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// addi r10,r1,-16
	ctx.r10.s64 = ctx.r1.s64 + -16;
	// lfs f13,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// lfs f0,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lfs f12,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// stfs f13,-16(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// stfs f13,-4(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r11,r1,-32
	ctx.r11.s64 = ctx.r1.s64 + -32;
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,-28(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f12,-32(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f12,-20(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f12,-24(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,-4(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f13,-8(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f13,-12(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f13,-16(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// ld r11,-32(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82566348) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x825663a0
	ctx.lr = 0x82566368;
	sub_825663A0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82566380
	if (ctx.cr0.eq) goto loc_82566380;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82566380
	if (ctx.cr6.eq) goto loc_82566380;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82566380;
	sub_825E0378(ctx, base);
loc_82566380:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82568660) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,9912
	ctx.r11.s64 = ctx.r11.s64 + 9912;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x82568684;
	sub_82469FB0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x8256868C;
	sub_825A4750(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x825686A0;
	sub_82469EE8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8256A430) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r5,59
	ctx.r5.s64 = 59;
	// addi r4,r11,1340
	ctx.r4.s64 = ctx.r11.s64 + 1340;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x8256A454;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8256a468
	if (!ctx.cr0.eq) goto loc_8256A468;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8256a474
	goto loc_8256A474;
loc_8256A468:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
loc_8256A474:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8256DAF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,6(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// addi r30,r11,32240
	ctx.r30.s64 = ctx.r11.s64 + 32240;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// frsp f12,f0
	ctx.f12.f64 = double(float(ctx.f0.f64));
	// lfs f0,24652(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 24652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2048(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -2048);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256DB54;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256DB70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8256DB8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// li r4,2
	ctx.r4.s64 = 2;
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// blt cr6,0x8256dbbc
	if (ctx.cr6.lt) goto loc_8256DBBC;
	// li r4,0
	ctx.r4.s64 = 0;
loc_8256DBBC:
	// bctrl 
	ctx.lr = 0x8256DBC0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f12,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r8,32368
	ctx.r8.s64 = ctx.r8.s64 + 32368;
	// stfs f31,320(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 320, temp.u32);
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// li r9,432
	ctx.r9.s64 = 432;
	// vspltisw128 v62,-1
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-8900(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8900);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lvx128 v9,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// vrefp v0,v9
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v9.f32)));
	// stfs f0,316(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vcmpeqfp128 v10,v9,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vslw128 v62,v62,v62
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r9,1
	ctx.r9.s64 = 1;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,328(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// vnmsubfp v6,v9,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v8,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vcmpeqfp128 v7,v0,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vxor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vmaddfp v0,v0,v6,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v11,v10,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// vnmsubfp v13,v9,v0,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v0,v0,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v13,v0,v8,v11
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// vmulfp128 v63,v62,v13
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,324(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// stb r9,116(r31)
	REX_STORE_U8(ctx.r31.u32 + 116, ctx.r9.u8);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lwz r3,280(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// bl 0x82453a68
	ctx.lr = 0x8256DC94;
	sub_82453A68(ctx, base);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x82240a58
	ctx.lr = 0x8256DCA0;
	sub_82240A58(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// lfd f31,-32(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8257C2E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257c358
	if (ctx.cr6.eq) goto loc_8257C358;
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// lfs f0,736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 736);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,-32
	ctx.r9.s64 = ctx.r1.s64 + -32;
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// addi r7,r1,-32
	ctx.r7.s64 = ctx.r1.s64 + -32;
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,740(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 740);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-32(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// ld r11,-32(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// b 0x8257c360
	goto loc_8257C360;
loc_8257C358:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
loc_8257C360:
	// std r11,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r11.u64);
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// lfs f0,-28(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -28);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// addi r8,r1,-16
	ctx.r8.s64 = ctx.r1.s64 + -16;
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// addi r6,r1,-16
	ctx.r6.s64 = ctx.r1.s64 + -16;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lfs f13,-32(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-24(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// stfs f13,-28(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f13,-32(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// stfs f13,-20(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,0(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// stfs f0,-16(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-16(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82587F78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82587F80;
	__savegprlr_27(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,76(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82587fa0
	if (!ctx.cr6.eq) goto loc_82587FA0;
loc_82587F94:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,18(r30)
	REX_STORE_U8(ctx.r30.u32 + 18, ctx.r11.u8);
	// b 0x825881d8
	goto loc_825881D8;
loc_82587FA0:
	// bl 0x8259be58
	ctx.lr = 0x82587FA4;
	sub_8259BE58(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x82587f94
	if (ctx.cr0.eq) goto loc_82587F94;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x82587FB8;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// beq 0x82587fe4
	if (ctx.cr0.eq) goto loc_82587FE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x82587FCC;
	sub_825F8B88(ctx, base);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,60
	ctx.r5.s64 = 60;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x82587FE0;
	sub_825F8BF8(ctx, base);
	// b 0x82587fe8
	goto loc_82587FE8;
loc_82587FE4:
	// mr r31,r29
	ctx.r31.u64 = ctx.r29.u64;
loc_82587FE8:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82587ff8
	if (!ctx.cr6.eq) goto loc_82587FF8;
loc_82587FF0:
	// stb r29,18(r30)
	REX_STORE_U8(ctx.r30.u32 + 18, ctx.r29.u8);
	// b 0x825881d8
	goto loc_825881D8;
loc_82587FF8:
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82587ff0
	if (ctx.cr6.eq) goto loc_82587FF0;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r8,r9,12236
	ctx.r8.s64 = ctx.r9.s64 + 12236;
	// li r10,60
	ctx.r10.s64 = 60;
	// lfs f0,12236(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f0,232(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
loc_82588034:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r7,r11,-32
	ctx.r7.s64 = ctx.r11.s64 + -32;
	// stw r29,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r29.u32);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,4(r9)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// std r8,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r8.u64);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// stw r6,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r6.u32);
	// stw r5,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r5.u32);
	// stw r4,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r4.u32);
	// stw r9,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r9.u32);
	// bne 0x82588034
	if (!ctx.cr0.eq) goto loc_82588034;
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// li r10,1
	ctx.r10.s64 = 1;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// lfs f0,7672(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7672);
	ctx.f0.f64 = double(temp.f32);
	// stb r10,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r10.u8);
	// vupkd3d128 v59,v63,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v59 = vTemp;
	// stw r28,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r28.u32);
	// addi r11,r7,-31424
	ctx.r11.s64 = ctx.r7.s64 + -31424;
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lwz r10,408(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// lfs f13,28(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28);
	ctx.f13.f64 = double(temp.f32);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// lfs f12,24(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 24);
	ctx.f12.f64 = double(temp.f32);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// vspltw128 v57,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// vspltw128 v56,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stfs f0,412(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lwz r11,3596(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 3596);
	// vmulfp128 v1,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v13,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vspltw128 v57,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// vmulfp128 v10,v56,v58
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v2,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vmulfp128 v30,v55,v58
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v11,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v28,v57,v58
	simde_mm_store_ps(ctx.v28.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v31,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v29,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// vmaddfp v2,v2,v13,v1
	simde_mm_store_ps(ctx.v2.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vpermwi128 v12,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// vspltw128 v4,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vspltw128 v5,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// lwz r11,408(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// vspltw128 v6,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// ori r11,r11,1472
	ctx.r11.u64 = ctx.r11.u64 | 1472;
	// vmaddfp v3,v11,v13,v10
	simde_mm_store_ps(ctx.v3.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vspltw128 v7,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// vmaddfp v1,v31,v13,v30
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v30.f32)));
	// vspltw128 v8,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vmaddfp v31,v29,v13,v28
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v28.f32)));
	// vspltw128 v9,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v9.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vmaddfp v5,v5,v12,v2
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vspltw128 v10,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vspltw128 v11,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// addi r28,r1,128
	ctx.r28.s64 = ctx.r1.s64 + 128;
	// stw r11,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r11.u32);
	// addi r27,r1,144
	ctx.r27.s64 = ctx.r1.s64 + 144;
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// vmaddfp v4,v4,v12,v3
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vmaddfp v13,v6,v12,v1
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v7,v7,v12,v31
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v12,v9,v0,v5
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmaddfp v8,v8,v0,v4
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v13,v10,v0,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v11,v0,v7
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// stvx128 v8,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x825881CC;
	sub_8273A030(ctx, base);
	// li r11,60
	ctx.r11.s64 = 60;
	// stw r31,64(r30)
	REX_STORE_U32(ctx.r30.u32 + 64, ctx.r31.u32);
	// stw r11,68(r30)
	REX_STORE_U32(ctx.r30.u32 + 68, ctx.r11.u32);
loc_825881D8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A03C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mulli r10,r4,144
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(144));
	// lwz r11,-12824(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r8,r9,13724
	ctx.r8.s64 = ctx.r9.s64 + 13724;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r8,-4
	ctx.r9.s64 = ctx.r8.s64 + -4;
	// lbz r10,143(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 143);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r11,17
	ctx.r10.s64 = ctx.r11.s64 + 17;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_825A0408:
	// lbz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// lbz r6,0(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// subf r7,r6,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r6.u64;
	// beq 0x825a042c
	if (ctx.cr0.eq) goto loc_825A042C;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x825a0408
	if (ctx.cr6.eq) goto loc_825A0408;
loc_825A042C:
	// cmpwi r7,0
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq 0x825a04ec
	if (ctx.cr0.eq) goto loc_825A04EC;
loc_825A0434:
	// lbz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// beq 0x825a0458
	if (ctx.cr0.eq) goto loc_825A0458;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825a0434
	if (ctx.cr6.eq) goto loc_825A0434;
loc_825A0458:
	// cmpwi r11,0
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a04ec
	if (ctx.cr0.eq) goto loc_825A04EC;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,100
	ctx.r4.s64 = 100;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x825A0478;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x825a04ec
	if (ctx.cr0.eq) goto loc_825A04EC;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,15908
	ctx.r10.s64 = ctx.r10.s64 + 15908;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r11,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r11.u8);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r9,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r9.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// stb r11,10(r31)
	REX_STORE_U8(ctx.r31.u32 + 10, ctx.r11.u8);
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// bl 0x8235ec48
	ctx.lr = 0x825A04CC;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r31,72
	ctx.r3.s64 = ctx.r31.s64 + 72;
	// bl 0x8235ec48
	ctx.lr = 0x825A04DC;
	sub_8235EC48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8259f260
	ctx.lr = 0x825A04E4;
	sub_8259F260(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x825a04f0
	goto loc_825A04F0;
loc_825A04EC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825A04F0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A81C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825A81D0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bne cr6,0x825a827c
	if (!ctx.cr6.eq) goto loc_825A827C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r29,0
	ctx.r29.s64 = 0;
	// rlwinm r30,r3,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// li r31,736
	ctx.r31.s64 = 736;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
loc_825A81F8:
	// lwz r11,-12768(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12768);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r10,r31,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A8220;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fabs f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bgt cr6,0x825a8240
	if (ctx.cr6.gt) goto loc_825A8240;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplwi cr6,r31,752
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 752, ctx.xer);
	// blt cr6,0x825a81f8
	if (ctx.cr6.lt) goto loc_825A81F8;
	// b 0x825a8274
	goto loc_825A8274;
loc_825A8240:
	// addi r10,r29,184
	ctx.r10.s64 = ctx.r29.s64 + 184;
	// lwz r11,-12768(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12768);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A8270;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
loc_825A8274:
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// b 0x825a82b0
	goto loc_825A82B0;
loc_825A827C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r10,r4,184
	ctx.r10.s64 = ctx.r4.s64 + 184;
	// rlwinm r4,r3,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,-12768(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12768);
	// lwzx r10,r10,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825A82B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825A82B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825AF6A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// ble cr6,0x825af6c8
	if (!ctx.cr6.gt) goto loc_825AF6C8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f1.f64));
	// b 0x825af6d4
	goto loc_825AF6D4;
loc_825AF6C8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
loc_825AF6D4:
	// stfs f0,28(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 28, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825B0BA0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-16196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -16196);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825b0be0
	if (!ctx.cr6.eq) goto loc_825B0BE0;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
loc_825B0BC8:
	// lwz r3,-16184(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -16184);
	// bl 0x8263a258
	ctx.lr = 0x825B0BD0;
	sub_8263A258(ctx, base);
	// bl 0x825b1170
	ctx.lr = 0x825B0BD4;
	sub_825B1170(ctx, base);
	// lwz r11,-16196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -16196);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b0bc8
	if (ctx.cr6.eq) goto loc_825B0BC8;
loc_825B0BE0:
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82639f58
	ctx.lr = 0x825B0BE8;
	sub_82639F58(ctx, base);
}

DEFINE_REX_FUNC(sub_825B3BB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825B3BB8;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r25,r3,204
	ctx.r25.s64 = ctx.r3.s64 + 204;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b44
	ctx.lr = 0x825B3BCC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825b3350
	ctx.lr = 0x825B3BD4;
	sub_825B3350(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825b3dd8
	if (ctx.cr6.lt) goto loc_825B3DD8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825b5cc0
	ctx.lr = 0x825B3BE8;
	sub_825B5CC0(ctx, base);
	// lwz r3,176(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 176);
	// addi r30,r29,172
	ctx.r30.s64 = ctx.r29.s64 + 172;
	// cmplw cr6,r3,r30
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825b3c38
	if (ctx.cr6.eq) goto loc_825B3C38;
loc_825B3BF8:
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// stw r3,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r3.u32);
	// stw r3,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r3.u32);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825B3C2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825b3bf8
	if (!ctx.cr6.eq) goto loc_825B3BF8;
loc_825B3C38:
	// lwz r11,92(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 92);
	// addi r27,r29,88
	ctx.r27.s64 = ctx.r29.s64 + 88;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// beq cr6,0x825b3c6c
	if (ctx.cr6.eq) goto loc_825B3C6C;
loc_825B3C48:
	// lwz r10,-12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -12);
	// addi r3,r11,-12
	ctx.r3.s64 = ctx.r11.s64 + -12;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,76(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825B3C60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r27
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x825b3c48
	if (!ctx.cr6.eq) goto loc_825B3C48;
loc_825B3C6C:
	// lwz r11,120(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 120);
	// addi r30,r29,116
	ctx.r30.s64 = ctx.r29.s64 + 116;
	// cmplw cr6,r11,r30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x825b3ca0
	if (ctx.cr6.eq) goto loc_825B3CA0;
loc_825B3C7C:
	// lwz r10,-8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// addi r3,r11,-8
	ctx.r3.s64 = ctx.r11.s64 + -8;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r9,92(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 92);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825B3C94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x825b3c7c
	if (!ctx.cr6.eq) goto loc_825B3C7C;
loc_825B3CA0:
	// lwz r3,256(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 256);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B3CB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,260(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 260);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r8,92(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 92);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825B3CC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r26,r29,188
	ctx.r26.s64 = ctx.r29.s64 + 188;
	// lwz r31,192(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 192);
	// cmplw cr6,r31,r26
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r26.u32, ctx.xer);
	// beq cr6,0x825b3d9c
	if (ctx.cr6.eq) goto loc_825B3D9C;
loc_825B3CD8:
	// lwz r3,184(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 184);
	// lwz r28,4(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b3d90
	if (ctx.cr6.eq) goto loc_825B3D90;
	// addi r30,r31,-12
	ctx.r30.s64 = ctx.r31.s64 + -12;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x825b7b50
	ctx.lr = 0x825B3CF4;
	sub_825B7B50(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b3d90
	if (ctx.cr6.eq) goto loc_825B3D90;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// addi r11,r30,12
	ctx.r11.s64 = ctx.r30.s64 + 12;
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r8,4(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// stw r31,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r31.u32);
	// stw r31,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r31.u32);
	// bne cr6,0x825b3d2c
	if (!ctx.cr6.eq) goto loc_825B3D2C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825B3D2C:
	// stw r27,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r27.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,8(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r9,8(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 8);
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
	// stw r11,8(r27)
	REX_STORE_U32(ctx.r27.u32 + 8, ctx.r11.u32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x825B3D58;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge cr6,0x825b3d90
	if (!ctx.cr6.lt) goto loc_825B3D90;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,148(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 148);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B3D74;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825b3d90
	if (ctx.cr6.eq) goto loc_825B3D90;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825B3D90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825B3D90:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r26
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x825b3cd8
	if (!ctx.cr6.eq) goto loc_825B3CD8;
loc_825B3D9C:
	// lwz r11,240(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 240);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825b3dd8
	if (ctx.cr6.eq) goto loc_825B3DD8;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b44
	ctx.lr = 0x825B3DB0;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r3,36(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// stw r11,240(r29)
	REX_STORE_U32(ctx.r29.u32 + 240, ctx.r11.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825B3DCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b34
	ctx.lr = 0x825B3DD8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_825B3DD8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82855b34
	ctx.lr = 0x825B3DE0;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C11D8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C1208;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x825c1230
	if (ctx.cr6.eq) goto loc_825C1230;
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lhz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,156(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C1228;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r30,56(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// b 0x825c1284
	goto loc_825C1284;
loc_825C1230:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x825c1258
	if (ctx.cr6.lt) goto loc_825C1258;
	// beq cr6,0x825c1250
	if (ctx.cr6.eq) goto loc_825C1250;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bne cr6,0x825c1284
	if (!ctx.cr6.eq) goto loc_825C1284;
	// b 0x825c125c
	goto loc_825C125C;
loc_825C1250:
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x825c125c
	goto loc_825C125C;
loc_825C1258:
	// li r11,0
	ctx.r11.s64 = 0;
loc_825C125C:
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x825c1280
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825C1280;
	// bdzf 4*cr6+eq,0x825c1270
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_825C1270;
	// bne cr6,0x825c1270
	if (!ctx.cr6.eq) goto loc_825C1270;
loc_825C1270:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825c1128
	ctx.lr = 0x825C1278;
	sub_825C1128(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x825c1284
	goto loc_825C1284;
loc_825C1280:
	// li r30,2048
	ctx.r30.s64 = 2048;
loc_825C1284:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C6928) {
	REX_FUNC_PROLOGUE();
	// lwz r11,68(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 68);
	// addi r9,r3,64
	ctx.r9.s64 = ctx.r3.s64 + 64;
	// lwz r8,48(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_825C6940:
	// lwz r10,44(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r7,16(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x825c6974
	if (!ctx.cr6.eq) goto loc_825C6974;
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// lwz r6,0(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// clrlwi r5,r6,27
	ctx.r5.u64 = ctx.r6.u32 & 0x1F;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x825c6984
	if (ctx.cr6.eq) goto loc_825C6984;
	// cmpw cr6,r10,r3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r3.s32, ctx.xer);
	// ble cr6,0x825c6974
	if (!ctx.cr6.gt) goto loc_825C6974;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
loc_825C6974:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x825c6940
	if (!ctx.cr6.eq) goto loc_825C6940;
	// blr 
	return;
loc_825C6984:
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C90C0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x825c9118
	ctx.lr = 0x825C90E0;
	sub_825C9118(ctx, base);
	// clrlwi r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c9100
	if (ctx.cr6.eq) goto loc_825C9100;
	// lis r4,8324
	ctx.r4.s64 = 545521664;
	// ori r4,r4,32779
	ctx.r4.u64 = ctx.r4.u64 | 32779;
	// bl 0x8263b710
	ctx.lr = 0x825C90FC;
	sub_8263B710(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_825C9100:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825CC668) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825c3bf8
	ctx.lr = 0x825CC680;
	sub_825C3BF8(ctx, base);
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r10,r11,0,21,21
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400;
	// cmplwi cr6,r10,1024
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1024, ctx.xer);
	// bne cr6,0x825cc6bc
	if (!ctx.cr6.eq) goto loc_825CC6BC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CC6A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_825CC6BC:
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x825cc6f4
	if (ctx.cr6.eq) goto loc_825CC6F4;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x825cc6f4
	if (!ctx.cr6.eq) goto loc_825CC6F4;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,24(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825CC6EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stw r8,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r8.u32);
loc_825CC6F4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825D0DD8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825ce460
	ctx.lr = 0x825D0DF4;
	sub_825CE460(ctx, base);
	// lwz r31,44(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x825d0e74
	if (!ctx.cr6.eq) goto loc_825D0E74;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x825d0e74
	if (ctx.cr6.eq) goto loc_825D0E74;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bne cr6,0x825d0e24
	if (!ctx.cr6.eq) goto loc_825D0E24;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825d0e74
	if (!ctx.cr6.eq) goto loc_825D0E74;
loc_825D0E24:
	// li r11,5
	ctx.r11.s64 = 5;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// bl 0x825c4c40
	ctx.lr = 0x825D0E3C;
	sub_825C4C40(ctx, base);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825d0e64
	if (ctx.cr6.eq) goto loc_825D0E64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,68(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825D0E64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825D0E64:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x825d0e74
	if (!ctx.cr6.eq) goto loc_825D0E74;
	// li r11,6
	ctx.r11.s64 = 6;
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
loc_825D0E74:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825DB2A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825DB2A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825db2e0
	if (!ctx.cr6.eq) goto loc_825DB2E0;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r4,r11,22708
	ctx.r4.s64 = ctx.r11.s64 + 22708;
	// addi r3,r10,22772
	ctx.r3.s64 = ctx.r10.s64 + 22772;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,153
	ctx.r5.s64 = 153;
	// bl 0x825da098
	ctx.lr = 0x825DB2E0;
	sub_825DA098(ctx, base);
loc_825DB2E0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825db314
	if (ctx.cr6.eq) goto loc_825DB314;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x825db308
	if (!ctx.cr6.eq) goto loc_825DB308;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825DB308;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825DB308:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_825DB30C:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_825DB314:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825DB32C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825db30c
	goto loc_825DB30C;
}

DEFINE_REX_FUNC(sub_825E0828) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r11,r11,-15588
	ctx.r11.s64 = ctx.r11.s64 + -15588;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x825e0880
	if (!ctx.cr6.eq) goto loc_825E0880;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,-12672(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -12672);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825e0874
	if (ctx.cr6.eq) goto loc_825E0874;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E0874;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E0874:
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// b 0x825e08b8
	goto loc_825E08B8;
loc_825E0880:
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_825E0884:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stwcx. r10,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825e0884
	if (!ctx.cr0.eq) goto loc_825E0884;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825e08b4
	if (ctx.cr6.eq) goto loc_825E08B4;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x825e08b8
	goto loc_825E08B8;
loc_825E08B4:
	// bl 0x825e0768
	ctx.lr = 0x825E08B8;
	sub_825E0768(ctx, base);
loc_825E08B8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825E51F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825E5200;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r3,72
	ctx.r30.s64 = ctx.r3.s64 + 72;
	// addi r11,r11,23144
	ctx.r11.s64 = ctx.r11.s64 + 23144;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 72);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and. r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825e5270
	if (ctx.cr0.eq) goto loc_825E5270;
	// li r11,1
	ctx.r11.s64 = 1;
	// addi r8,r3,64
	ctx.r8.s64 = ctx.r3.s64 + 64;
loc_825E5238:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r8
	ea = ctx.r8.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r8
	ea = ctx.r8.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825e5238
	if (!ctx.cr0.eq) goto loc_825E5238;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e4c00
	ctx.lr = 0x825E5258;
	sub_825E4C00(ctx, base);
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825E5270;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825E5270:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825e5280
	if (ctx.cr6.eq) goto loc_825E5280;
	// bl 0x822130c8
	ctx.lr = 0x825E5280;
	sub_822130C8(ctx, base);
loc_825E5280:
	// lwz r3,40(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825e5298
	if (ctx.cr6.eq) goto loc_825E5298;
	// bl 0x8263a978
	ctx.lr = 0x825E5294;
	sub_8263A978(ctx, base);
	// stw r30,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r30.u32);
loc_825E5298:
	// lbz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 36);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x825e52ac
	if (ctx.cr0.eq) goto loc_825E52AC;
	// stb r30,28(r11)
	REX_STORE_U8(ctx.r11.u32 + 28, ctx.r30.u8);
loc_825E52AC:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// clrlwi. r10,r29,31
	ctx.r10.u64 = ctx.r29.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq 0x825e52c8
	if (ctx.cr0.eq) goto loc_825E52C8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x825E52C8;
	sub_825E0378(ctx, base);
loc_825E52C8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E91F8) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// b 0x825e8a38
	sub_825E8A38(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E93E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825E93E8;
	__savegprlr_24(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r10,8(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lhz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r5.u32 + 4);
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// lbz r8,6(r5)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r5.u32 + 6);
	// addi r24,r4,20
	ctx.r24.s64 = ctx.r4.s64 + 20;
	// lbz r7,48(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 48);
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// cmplwi r7,0
	ctx.cr0.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// sth r9,92(r1)
	REX_STORE_U16(ctx.r1.u32 + 92, ctx.r9.u16);
	// stb r8,94(r1)
	REX_STORE_U8(ctx.r1.u32 + 94, ctx.r8.u8);
	// beq 0x825e9430
	if (ctx.cr0.eq) goto loc_825E9430;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82855b44
	ctx.lr = 0x825E9430;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_825E9430:
	// lwz r30,12(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// li r25,0
	ctx.r25.s64 = 0;
	// addi r29,r27,8
	ctx.r29.s64 = ctx.r27.s64 + 8;
	// stw r25,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r25.u32);
	// lwz r31,4(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// b 0x825e946c
	goto loc_825E946C;
loc_825E9448:
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// addi r3,r31,12
	ctx.r3.s64 = ctx.r31.s64 + 12;
	// bl 0x825e9cb8
	ctx.lr = 0x825E9454;
	sub_825E9CB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825e9464
	if (ctx.cr0.eq) goto loc_825E9464;
	// lwz r31,8(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// b 0x825e946c
	goto loc_825E946C;
loc_825E9464:
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_825E946C:
	// lbz r11,29(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 29);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825e9448
	if (ctx.cr0.eq) goto loc_825E9448;
	// lwz r31,4(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825e94a4
	if (ctx.cr6.eq) goto loc_825E94A4;
	// addi r4,r30,12
	ctx.r4.s64 = ctx.r30.s64 + 12;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x825e9cb8
	ctx.lr = 0x825E9494;
	sub_825E9CB8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825e94a4
	if (!ctx.cr0.eq) goto loc_825E94A4;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// b 0x825e94ac
	goto loc_825E94AC;
loc_825E94A4:
	// stw r31,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r31.u32);
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
loc_825E94AC:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,12(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 12);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x825e94c8
	if (ctx.cr6.eq) goto loc_825E94C8;
	// addi r4,r11,24
	ctx.r4.s64 = ctx.r11.s64 + 24;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x825e98c0
	ctx.lr = 0x825E94C8;
	sub_825E98C0(ctx, base);
loc_825E94C8:
	// lbz r11,28(r24)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r24.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825e94dc
	if (ctx.cr0.eq) goto loc_825E94DC;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82855b34
	ctx.lr = 0x825E94DC;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_825E94DC:
	// lwz r3,0(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x8273c660
	ctx.lr = 0x825E94E4;
	sub_8273C660(ctx, base);
	// lbz r11,6(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 6);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// stw r25,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r25.u32);
	// rlwinm r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	// stb r11,6(r28)
	REX_STORE_U8(ctx.r28.u32 + 6, ctx.r11.u8);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F1970) {
	REX_FUNC_PROLOGUE();
	// stw r4,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F1A00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825F1A08;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r29,r11,-16084
	ctx.r29.s64 = ctx.r11.s64 + -16084;
	// lwz r11,-16084(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -16084);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x825f1a48
	if (!ctx.cr6.eq) goto loc_825F1A48;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f1a3c
	if (ctx.cr6.eq) goto loc_825F1A3C;
	// bl 0x822130c8
	ctx.lr = 0x825F1A34;
	sub_822130C8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_825F1A3C:
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// b 0x825f1ab0
	goto loc_825F1AB0;
loc_825F1A48:
	// lwz r11,528(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 528);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825f1a78
	if (ctx.cr6.eq) goto loc_825F1A78;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825f1a6c
	if (ctx.cr6.eq) goto loc_825F1A6C;
	// bl 0x822130c8
	ctx.lr = 0x825F1A64;
	sub_822130C8(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_825F1A6C:
	// lis r3,-16381
	ctx.r3.s64 = -1073545216;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// b 0x825f1ab0
	goto loc_825F1AB0;
loc_825F1A78:
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r3,r11,-30584
	ctx.r3.s64 = ctx.r11.s64 + -30584;
	// bl 0x825f0df0
	ctx.lr = 0x825F1A84;
	sub_825F0DF0(ctx, base);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r3,528(r29)
	REX_STORE_U32(ctx.r29.u32 + 528, ctx.r3.u32);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825f1aac
	if (ctx.cr6.eq) goto loc_825F1AAC;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825f1aa8
	if (ctx.cr0.eq) goto loc_825F1AA8;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x822130c8
	ctx.lr = 0x825F1AA8;
	sub_822130C8(ctx, base);
loc_825F1AA8:
	// stw r31,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r31.u32);
loc_825F1AAC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825F1AB0:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F56C8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r3,464
	ctx.r11.s64 = ctx.r3.s64 + 464;
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,48
	ctx.r8.s64 = 48;
	// vspltw128 v11,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// li r7,32
	ctx.r7.s64 = 32;
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// li r10,16
	ctx.r10.s64 = 16;
	// vspltw128 v0,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// mr r9,r4
	ctx.r9.u64 = ctx.r4.u64;
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lvx128 v9,r11,r8
	ea = (ctx.r11.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v10,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// vmaddfp v10,v10,v11,v9
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// lvx128 v11,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r10
	ea = (ctx.r9.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,76(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 76);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// vmaddfp v12,v11,v12,v10
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v0,v13,v0,v12
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x825F573C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F9F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x825F9F70;
	__savegprlr_18(ctx, base);
	// stfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f31.u64);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// addi r30,r11,-15480
	ctx.r30.s64 = ctx.r11.s64 + -15480;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r19,r5
	ctx.r19.u64 = ctx.r5.u64;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x825F9F98;
	sub_825F8ED0(ctx, base);
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// beq cr6,0x825fa190
	if (ctx.cr6.eq) goto loc_825FA190;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// clrlwi r10,r20,17
	ctx.r10.u64 = ctx.r20.u32 & 0x7FFF;
	// mulli r10,r10,116
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(116));
	// lwz r11,-15484(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15484);
	// lwzx r9,r10,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r9,r20
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r20.u32, ctx.xer);
	// bne cr6,0x825fa190
	if (!ctx.cr6.eq) goto loc_825FA190;
	// lbz r11,14(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 14);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825fa190
	if (ctx.cr0.eq) goto loc_825FA190;
	// lbz r11,15(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 15);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x825fa190
	if (ctx.cr0.eq) goto loc_825FA190;
	// addi r3,r31,112
	ctx.r3.s64 = ctx.r31.s64 + 112;
	// bl 0x825f8f28
	ctx.lr = 0x825F9FE0;
	sub_825F8F28(ctx, base);
	// lwsync 
	// li r27,0
	ctx.r27.s64 = 0;
loc_825F9FE8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r27,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r27.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825f9fe8
	if (!ctx.cr0.eq) goto loc_825F9FE8;
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8260fce0
	ctx.lr = 0x825FA014;
	sub_8260FCE0(ctx, base);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// bl 0x82749ab8
	ctx.lr = 0x825FA028;
	sub_82749AB8(ctx, base);
	// lwz r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r4,120(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// clrlwi r22,r11,26
	ctx.r22.u64 = ctx.r11.u32 & 0x3F;
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r26,r11,24,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0x1;
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// lwz r11,48(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// rlwinm r30,r10,1,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// rlwinm r29,r11,21,31,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 21) & 0x1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x82749ac0
	ctx.lr = 0x825FA058;
	sub_82749AC0(ctx, base);
	// mr r25,r27
	ctx.r25.u64 = ctx.r27.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x825fa080
	if (ctx.cr6.eq) goto loc_825FA080;
	// subfic r11,r30,0
	ctx.xer.ca = ctx.r30.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r30.u64;
	// cntlzw r10,r29
	ctx.r10.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// li r9,2
	ctx.r9.s64 = 2;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// and r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 & ctx.r9.u64;
	// or r25,r10,r11
	ctx.r25.u64 = ctx.r10.u64 | ctx.r11.u64;
loc_825FA080:
	// mr r24,r27
	ctx.r24.u64 = ctx.r27.u64;
	// cmplwi cr6,r18,0
	ctx.cr6.compare<uint32_t>(ctx.r18.u32, 0, ctx.xer);
	// beq cr6,0x825fa17c
	if (ctx.cr6.eq) goto loc_825FA17C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f31,14376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f31.f64 = double(temp.f32);
loc_825FA094:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// beq cr6,0x825fa170
	if (ctx.cr6.eq) goto loc_825FA170;
loc_825FA0A0:
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82749ab8
	ctx.lr = 0x825FA0B0;
	sub_82749AB8(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lwz r28,8(r23)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// bl 0x82749368
	ctx.lr = 0x825FA0C4;
	sub_82749368(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825fa0d4
	if (!ctx.cr6.eq) goto loc_825FA0D4;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// b 0x825fa0d8
	goto loc_825FA0D8;
loc_825FA0D4:
	// lwz r11,108(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 108);
loc_825FA0D8:
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// add r29,r11,r21
	ctx.r29.u64 = ctx.r11.u64 + ctx.r21.u64;
	// beq cr6,0x825fa12c
	if (ctx.cr6.eq) goto loc_825FA12C;
	// lwz r11,0(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// lwz r10,220(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 220);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x825fa0fc
	if (ctx.cr6.gt) goto loc_825FA0FC;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_825FA0FC:
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// lwz r4,120(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// mr r6,r22
	ctx.r6.u64 = ctx.r22.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// bl 0x8274de70
	ctx.lr = 0x825FA128;
	sub_8274DE70(ctx, base);
	// b 0x825fa160
	goto loc_825FA160;
loc_825FA12C:
	// lwz r7,192(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 192);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r10,0(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r6,184(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r5,180(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r4,196(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// stw r7,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r7.u32);
	// bl 0x8274cd50
	ctx.lr = 0x825FA160;
	sub_8274CD50(ctx, base);
loc_825FA160:
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r23,r23,12
	ctx.r23.s64 = ctx.r23.s64 + 12;
	// cmplw cr6,r30,r19
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r19.u32, ctx.xer);
	// blt cr6,0x825fa0a0
	if (ctx.cr6.lt) goto loc_825FA0A0;
loc_825FA170:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// cmplw cr6,r24,r18
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r18.u32, ctx.xer);
	// blt cr6,0x825fa094
	if (ctx.cr6.lt) goto loc_825FA094;
loc_825FA17C:
	// lwz r3,100(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// bl 0x8260fe98
	ctx.lr = 0x825FA184;
	sub_8260FE98(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x825f9cf8
	ctx.lr = 0x825FA18C;
	sub_825F9CF8(ctx, base);
	// b 0x825fa1b0
	goto loc_825FA1B0;
loc_825FA190:
	// lwsync 
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FA198:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r30
	ea = ctx.r30.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r11,0,r30
	ea = ctx.r30.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825fa198
	if (!ctx.cr0.eq) goto loc_825FA198;
loc_825FA1B0:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// lfd f31,-128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8260F850) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8260F858;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8260f8c0
	if (ctx.cr6.lt) goto loc_8260F8C0;
	// bne cr6,0x8260f8c8
	if (!ctx.cr6.eq) goto loc_8260F8C8;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r29,44(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// addi r28,r11,-14948
	ctx.r28.s64 = ctx.r11.s64 + -14948;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825f8ed0
	ctx.lr = 0x8260F88C;
	sub_825F8ED0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,-14940(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -14940);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8260F8A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwsync 
loc_8260F8A4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r28
	ea = ctx.r28.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// stwcx. r30,0,r28
	ea = ctx.r28.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r30.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8260f8a4
	if (!ctx.cr0.eq) goto loc_8260F8A4;
	// b 0x8260f8c8
	goto loc_8260F8C8;
loc_8260F8C0:
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x8260f420
	ctx.lr = 0x8260F8C8;
	sub_8260F420(ctx, base);
loc_8260F8C8:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// mulli r10,r10,5
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(5));
	// stw r30,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r30.u32);
	// lwz r7,12(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r9,-14880
	ctx.r11.s64 = ctx.r9.s64 + -14880;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// lis r6,-32112
	ctx.r6.s64 = -2104492032;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r10,r31,20
	ctx.r10.s64 = ctx.r31.s64 + 20;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// subf r7,r7,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r7.u64;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lwz r9,-14888(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -14888);
	// stw r5,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r5.u32);
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// lwz r11,-14920(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + -14920);
	// stw r9,-14888(r8)
	REX_STORE_U32(ctx.r8.u32 + -14888, ctx.r9.u32);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82616948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82616950;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,4(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r26,1
	ctx.r26.s64 = 1;
	// lwz r5,8(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplw cr6,r3,r5
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x82616990
	if (ctx.cr6.eq) goto loc_82616990;
	// subf r11,r5,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r5.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r30,r6,r3
	ctx.r30.u64 = ctx.r6.u64 + ctx.r3.u64;
	// ble 0x8261698c
	if (!ctx.cr0.gt) goto loc_8261698C;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x827388e8
	ctx.lr = 0x8261698C;
	sub_827388E8(ctx, base);
loc_8261698C:
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
loc_82616990:
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,28(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwzx r29,r10,r11
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82616e10
	ctx.lr = 0x826169AC;
	sub_82616E10(ctx, base);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x826169ec
	if (ctx.cr6.eq) goto loc_826169EC;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r30,r27,4
	ctx.r30.s64 = ctx.r27.s64 + 4;
loc_826169BC:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// add r3,r11,r27
	ctx.r3.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bl 0x8259b6a0
	ctx.lr = 0x826169C8;
	sub_8259B6A0(ctx, base);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// subfic r10,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwx r3,r11,r28
	REX_STORE_U32(ctx.r11.u32 + ctx.r28.u32, ctx.r3.u32);
	// and r26,r10,r26
	ctx.r26.u64 = ctx.r10.u64 & ctx.r26.u64;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// bne 0x826169bc
	if (!ctx.cr0.eq) goto loc_826169BC;
loc_826169EC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82616a14
	if (ctx.cr6.eq) goto loc_82616A14;
	// rotlwi r10,r10,0
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lhz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// stw r10,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r10.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r11,10(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 10);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
loc_82616A14:
	// lwz r9,8(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r10,20(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// lbz r9,14(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 14);
	// extsb r9,r9
	ctx.r9.s64 = ctx.r9.s8;
	// divwu r11,r11,r9
	ctx.r11.u64 = uint32_t(ctx.r9.u32 ? ctx.r11.u32 / ctx.r9.u32 : 0);
	// twllei r9,0
	if (ctx.r9.s32 == 0 || ctx.r9.u32 < 0u) ppc_trap(ctx, base, 0);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r11,8(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 8);
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lbz r11,15(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 15);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r10,r11
	ctx.r11.u64 = uint32_t(ctx.r11.u32 ? ctx.r10.u32 / ctx.r11.u32 : 0);
	// mullw r10,r9,r11
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r11.s32);
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8261D060) {
	REX_FUNC_PROLOGUE();
	// lwz r11,10544(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 10544);
	// rlwinm r10,r4,20,0,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 20) & 0xFFF00000;
	// rlwinm r11,r11,0,12,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF0FFFFF;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// stw r11,10544(r3)
	REX_STORE_U32(ctx.r3.u32 + 10544, ctx.r11.u32);
	// ld r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// ori r11,r11,4096
	ctx.r11.u64 = ctx.r11.u64 | 4096;
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261D6C0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,10696(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 10696);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261D808) {
	REX_FUNC_PROLOGUE();
	// lbz r3,10562(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 10562);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8261DAB0) {
	REX_FUNC_PROLOGUE();
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r9,12(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r11,r10,22,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1;
	// rlwinm r10,r9,13,19,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 13) & 0x1FFF;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwimi r10,r11,0,29,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFB);
	// clrlwi r3,r10,29
	ctx.r3.u64 = ctx.r10.u32 & 0x7;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82620740) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82620748;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lis r4,25728
	ctx.r4.s64 = 1686110208;
	// li r3,48
	ctx.r3.s64 = 48;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x8263b678
	ctx.lr = 0x82620768;
	sub_8263B678(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82620778
	if (!ctx.cr0.eq) goto loc_82620778;
loc_82620770:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82620890
	goto loc_82620890;
loc_82620778:
	// addi r10,r1,84
	ctx.r10.s64 = ctx.r1.s64 + 84;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82620390
	ctx.lr = 0x8262079C;
	sub_82620390(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// oris r9,r11,16
	ctx.r9.u64 = ctx.r11.u64 | 1048576;
	// clrlwi r11,r10,26
	ctx.r11.u64 = ctx.r10.u32 & 0x3F;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// cmplwi cr6,r11,22
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 22, ctx.xer);
	// beq cr6,0x826207c4
	if (ctx.cr6.eq) goto loc_826207C4;
	// cmplwi cr6,r11,23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 23, ctx.xer);
	// li r27,0
	ctx.r27.s64 = 0;
	// bne cr6,0x826207c8
	if (!ctx.cr6.eq) goto loc_826207C8;
loc_826207C4:
	// li r27,1
	ctx.r27.s64 = 1;
loc_826207C8:
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8262f450
	ctx.lr = 0x826207D8;
	sub_8262F450(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne 0x826207f0
	if (!ctx.cr0.eq) goto loc_826207F0;
loc_826207E0:
	// lis r4,9344
	ctx.r4.s64 = 612368384;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8263b710
	ctx.lr = 0x826207EC;
	sub_8263B710(ctx, base);
	// b 0x82620770
	goto loc_82620770;
loc_826207F0:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r29,r30,r28
	ctx.r29.u64 = ctx.r30.u64 + ctx.r28.u64;
	// cmplwi cr6,r29,2048
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 2048, ctx.xer);
	// ble cr6,0x82620838
	if (!ctx.cr6.gt) goto loc_82620838;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r3,-14440(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -14440);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// bl 0x82855b44
	ctx.lr = 0x82620810;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,28(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r11,28(r27)
	REX_STORE_U32(ctx.r27.u32 + 28, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8262f310
	ctx.lr = 0x82620830;
	sub_8262F310(ctx, base);
	// bl 0x82855b34
	ctx.lr = 0x82620834;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// b 0x826207e0
	goto loc_826207E0;
loc_82620838:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82620880
	if (ctx.cr6.eq) goto loc_82620880;
	// lwz r10,28(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwimi r10,r30,0,20,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFF) | (ctx.r10.u64 & 0xFFFFFFFFFFFFF000);
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// lwz r10,-14468(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -14468);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8262088c
	if (!ctx.cr6.eq) goto loc_8262088C;
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r10,1
	ctx.r10.s64 = 1;
	// clrlwi r9,r9,15
	ctx.r9.u64 = ctx.r9.u32 & 0x1FFFF;
	// stw r10,-14468(r11)
	REX_STORE_U32(ctx.r11.u32 + -14468, ctx.r10.u32);
	// stw r9,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// b 0x8262088c
	goto loc_8262088C;
loc_82620880:
	// lwz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// rlwimi r11,r30,0,20,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0xFFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFF000);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
loc_8262088C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82620890:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8262ECE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8262ECF0;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273aef0
	ctx.lr = 0x8262ECF8;
	__savefpr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
	// subfe r31,r11,r30
	temp.u8 = (~ctx.r11.u32 + ctx.r30.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r30.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r31.u64 = ~ctx.r11.u64 + ctx.r30.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// bl 0x82856224
	ctx.lr = 0x8262ED14;
	__imp__VdGetCurrentDisplayGamma(ctx, base);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// rlwinm r11,r31,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,13056
	ctx.r10.s64 = ctx.r10.s64 + 13056;
	// addi r9,r9,30152
	ctx.r9.s64 = ctx.r9.s64 + 30152;
	// rlwinm r8,r31,11,0,20
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 11) & 0xFFFFF800;
	// lis r7,-32111
	ctx.r7.s64 = -2104426496;
	// add r28,r8,r9
	ctx.r28.u64 = ctx.r8.u64 + ctx.r9.u64;
	// addi r9,r7,3988
	ctx.r9.s64 = ctx.r7.s64 + 3988;
	// lwzx r7,r11,r10
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8262ed58
	if (!ctx.cr6.eq) goto loc_8262ED58;
	// lfsx f0,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// beq cr6,0x8262ef38
	if (ctx.cr6.eq) goto loc_8262EF38;
loc_8262ED58:
	// stfsx f2,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// stwx r8,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r28,-2
	ctx.r29.s64 = ctx.r28.s64 + -2;
	// lfs f21,12236(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12236);
	ctx.f21.f64 = double(temp.f32);
	// lfs f0,800(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 800);
	ctx.f0.f64 = double(temp.f32);
	// lfd f13,616(r11)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r11.u32 + 616);
	// lfd f12,568(r11)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r11.u32 + 568);
	// lfd f11,384(r11)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r11.u32 + 384);
	// lfd f19,808(r11)
	ctx.f19.u64 = REX_LOAD_U64(ctx.r11.u32 + 808);
	// lfs f20,-25244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25244);
	ctx.f20.f64 = double(temp.f32);
	// lfd f29,656(r11)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r11.u32 + 656);
	// lfs f28,652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 652);
	ctx.f28.f64 = double(temp.f32);
	// lfs f18,648(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 648);
	ctx.f18.f64 = double(temp.f32);
	// lfd f17,640(r11)
	ctx.f17.u64 = REX_LOAD_U64(ctx.r11.u32 + 640);
	// lfd f27,632(r11)
	ctx.f27.u64 = REX_LOAD_U64(ctx.r11.u32 + 632);
	// lfs f26,628(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 628);
	ctx.f26.f64 = double(temp.f32);
	// lfs f31,624(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 624);
	ctx.f31.f64 = double(temp.f32);
	// lfs f16,612(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 612);
	ctx.f16.f64 = double(temp.f32);
	// lfs f25,608(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 608);
	ctx.f25.f64 = double(temp.f32);
	// lfd f24,600(r11)
	ctx.f24.u64 = REX_LOAD_U64(ctx.r11.u32 + 600);
	// lfd f15,592(r11)
	ctx.f15.u64 = REX_LOAD_U64(ctx.r11.u32 + 592);
	// lfd f23,584(r11)
	ctx.f23.u64 = REX_LOAD_U64(ctx.r11.u32 + 584);
	// lfs f22,580(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 580);
	ctx.f22.f64 = double(temp.f32);
	// lfs f30,576(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 576);
	ctx.f30.f64 = double(temp.f32);
	// lfs f14,564(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 564);
	ctx.f14.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfd f13,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// stfd f12,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f12.u64);
	// stfd f11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f11.u64);
	// b 0x8262edec
	goto loc_8262EDEC;
loc_8262EDE4:
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8262EDEC:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bne cr6,0x8262ee40
	if (!ctx.cr6.eq) goto loc_8262EE40;
	// lfd f0,104(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bgt cr6,0x8262ee24
	if (ctx.cr6.gt) goto loc_8262EE24;
	// fmuls f1,f1,f16
	ctx.f1.f64 = double(float(ctx.f1.f64 * ctx.f16.f64));
	// b 0x8262ee38
	goto loc_8262EE38;
loc_8262EE24:
	// fadds f0,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f31.f64));
	// fmr f2,f27
	ctx.f2.f64 = ctx.f27.f64;
	// fmuls f1,f0,f26
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f26.f64));
	// bl 0x82738fd8
	ctx.lr = 0x8262EE34;
	sub_82738FD8(ctx, base);
	// frsp f1,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f1.f64));
loc_8262EE38:
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_8262EE40:
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// beq cr6,0x8262eec0
	if (ctx.cr6.eq) goto loc_8262EEC0;
	// cmplwi cr6,r8,2
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 2, ctx.xer);
	// beq cr6,0x8262ee70
	if (ctx.cr6.eq) goto loc_8262EE70;
	// cmplwi cr6,r8,3
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 3, ctx.xer);
	// bne cr6,0x8262ee70
	if (!ctx.cr6.eq) goto loc_8262EE70;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x8262ee64
	if (!ctx.cr6.eq) goto loc_8262EE64;
	// fdivs f2,f21,f2
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f21.f64 / ctx.f2.f64));
loc_8262EE64:
	// bl 0x82738fd8
	ctx.lr = 0x8262EE68;
	sub_82738FD8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// b 0x8262eecc
	goto loc_8262EECC;
loc_8262EE70:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8262ee9c
	if (ctx.cr6.eq) goto loc_8262EE9C;
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// bge cr6,0x8262ee8c
	if (!ctx.cr6.lt) goto loc_8262EE8C;
	// fmuls f0,f1,f14
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f14.f64));
	// b 0x8262eecc
	goto loc_8262EECC;
loc_8262EE8C:
	// fadds f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f30.f64));
	// fmr f2,f23
	ctx.f2.f64 = ctx.f23.f64;
	// fmuls f1,f0,f22
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f22.f64));
	// b 0x8262ee64
	goto loc_8262EE64;
loc_8262EE9C:
	// fcmpu cr6,f1,f15
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f15.f64);
	// bge cr6,0x8262eeac
	if (!ctx.cr6.lt) goto loc_8262EEAC;
	// fmuls f0,f1,f20
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f20.f64));
	// b 0x8262eecc
	goto loc_8262EECC;
loc_8262EEAC:
	// fmr f2,f24
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f24.f64;
	// bl 0x82738fd8
	ctx.lr = 0x8262EEB4;
	sub_82738FD8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmsubs f0,f0,f25,f30
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f25.f64, -ctx.f30.f64)));
	// b 0x8262eecc
	goto loc_8262EECC;
loc_8262EEC0:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8262ec48
	ctx.lr = 0x8262EEC8;
	sub_8262EC48(ctx, base);
	// fmr f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f1.f64;
loc_8262EECC:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x8262eef8
	if (ctx.cr6.eq) goto loc_8262EEF8;
	// fmr f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f0.f64;
	// fcmpu cr6,f0,f17
	ctx.cr6.compare(ctx.f0.f64, ctx.f17.f64);
	// bgt cr6,0x8262eee8
	if (ctx.cr6.gt) goto loc_8262EEE8;
	// fmuls f0,f0,f18
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f18.f64));
	// b 0x8262eef8
	goto loc_8262EEF8;
loc_8262EEE8:
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x82738fd8
	ctx.lr = 0x8262EEF0;
	sub_82738FD8(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmsubs f0,f0,f28,f31
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f28.f64, -ctx.f31.f64)));
loc_8262EEF8:
	// lfd f13,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fmadd f0,f0,f19,f13
	ctx.f0.f64 = std::fma(ctx.f0.f64, ctx.f19.f64, ctx.f13.f64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r11,132(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x8262ef1c
	if (!ctx.cr6.lt) goto loc_8262EF1C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8262ef28
	goto loc_8262EF28;
loc_8262EF1C:
	// cmpwi cr6,r11,1023
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1023, ctx.xer);
	// ble cr6,0x8262ef28
	if (!ctx.cr6.gt) goto loc_8262EF28;
	// li r11,1023
	ctx.r11.s64 = 1023;
loc_8262EF28:
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// sthu r11,2(r29)
	ea = 2 + ctx.r29.u32;
	REX_STORE_U16(ea, ctx.r11.u16);
	ctx.r29.u32 = ea;
	// cmpwi cr6,r31,1024
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1024, ctx.xer);
	// blt cr6,0x8262ede4
	if (ctx.cr6.lt) goto loc_8262EDE4;
loc_8262EF38:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af3c
	ctx.lr = 0x8262EF48;
	__restfpr_14(ctx, base);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826422F8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32761
	ctx.r10.s64 = -2147024896;
	// ori r10,r10,14
	ctx.r10.u64 = ctx.r10.u64 | 14;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// ori r10,r10,16385
	ctx.r10.u64 = ctx.r10.u64 | 16385;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// srawi r10,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 16;
	// clrlwi r10,r10,19
	ctx.r10.u64 = ctx.r10.u32 & 0x1FFF;
	// cmpwi cr6,r10,2198
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2198, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lis r10,-30600
	ctx.r10.s64 = -2005401600;
	// ori r10,r10,120
	ctx.r10.u64 = ctx.r10.u64 | 120;
	// subf. r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82642378
	if (ctx.cr0.eq) goto loc_82642378;
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// beq cr6,0x82642378
	if (ctx.cr6.eq) goto loc_82642378;
	// lis r10,15
	ctx.r10.s64 = 983040;
	// ori r10,r10,65417
	ctx.r10.u64 = ctx.r10.u64 | 65417;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82642378
	if (ctx.cr6.eq) goto loc_82642378;
	// lis r10,30
	ctx.r10.s64 = 1966080;
	// ori r10,r10,65417
	ctx.r10.u64 = ctx.r10.u64 | 65417;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,-30570
	ctx.r11.s64 = -2003435520;
	// ori r11,r11,3
	ctx.r11.u64 = ctx.r11.u64 | 3;
	// b 0x82642380
	goto loc_82642380;
loc_82642378:
	// lis r11,-30570
	ctx.r11.s64 = -2003435520;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
loc_82642380:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82644A10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x826444b8
	ctx.lr = 0x82644A30;
	sub_826444B8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82644a40
	if (ctx.cr0.eq) goto loc_82644A40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x82644A40;
	sub_8264CF40(ctx, base);
loc_82644A40:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82645F28) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32116
	ctx.r11.s64 = -2104754176;
	// addi r31,r11,13360
	ctx.r31.s64 = ctx.r11.s64 + 13360;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b44
	ctx.lr = 0x82645F48;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lis r11,32746
	ctx.r11.s64 = 2146041856;
	// lis r10,512
	ctx.r10.s64 = 33554432;
	// ori r11,r11,6148
	ctx.r11.u64 = ctx.r11.u64 | 6148;
	// stwx r10,0,r11
	REX_MM_STORE_U32(ctx.r11.u32, ctx.r10.u32);
	// eieio 
	// li r11,320
	ctx.r11.s64 = 320;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r4,r10,13248
	ctx.r4.s64 = ctx.r10.s64 + 13248;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82645F70:
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8264605c
	if (ctx.cr6.eq) goto loc_8264605C;
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// rlwinm. r10,r11,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8264605c
	if (ctx.cr0.eq) goto loc_8264605C;
	// rlwinm. r11,r11,0,14,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8264605c
	if (!ctx.cr0.eq) goto loc_8264605C;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x82646050
	if (!ctx.cr6.gt) goto loc_82646050;
	// mr r8,r5
	ctx.r8.u64 = ctx.r5.u64;
loc_82645FA4:
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r10,r10,0,10,11
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x300000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82646014
	if (ctx.cr0.eq) goto loc_82646014;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 64);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r3,r10,12,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// rlwinm r7,r10,12,30,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 12) & 0x3;
	// bne 0x82645fe4
	if (!ctx.cr0.eq) goto loc_82645FE4;
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stw r5,20(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// stw r5,84(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 84, ctx.r5.u32);
	// stw r10,0(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82645FE4:
	// rlwinm. r10,r7,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82646000
	if (!ctx.cr0.eq) goto loc_82646000;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 4);
	// stw r5,24(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 24, ctx.r5.u32);
	// rlwinm r10,r10,0,0,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFF000;
	// stw r5,88(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 88, ctx.r5.u32);
	// stw r10,4(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_82646000:
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82646014
	if (!ctx.cr6.eq) goto loc_82646014;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_MM_LOAD_U32(ctx.r11.u32 + 16);
	// clrlwi r10,r10,1
	ctx.r10.u64 = ctx.r10.u32 & 0x7FFFFFFF;
	// stw r10,16(r11)
	REX_MM_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
loc_82646014:
	// lhz r11,80(r11)
	ctx.r11.u64 = REX_MM_LOAD_U16(ctx.r11.u32 + 80);
	// li r10,1
	ctx.r10.s64 = 1;
	// rlwinm r7,r11,27,5,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// clrlwi r11,r11,27
	ctx.r11.u64 = ctx.r11.u32 & 0x1F;
	// addis r7,r7,8187
	ctx.r7.s64 = ctx.r7.s64 + 536543232;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r7,r7,-31088
	ctx.r7.s64 = ctx.r7.s64 + -31088;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// stwbrx r11,0,r10
	REX_MM_STORE_U32(ctx.r10.u32, __builtin_bswap32(ctx.r11.u32));
	// eieio 
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r8,r8,96
	ctx.r8.s64 = ctx.r8.s64 + 96;
	// cmplw cr6,r6,r11
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82645fa4
	if (ctx.cr6.lt) goto loc_82645FA4;
loc_82646050:
	// lwz r11,4(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// oris r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 131072;
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
loc_8264605C:
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// bdnz 0x82645f70
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82645F70;
	// lis r11,32746
	ctx.r11.s64 = 2146041856;
	// lis r10,768
	ctx.r10.s64 = 50331648;
	// ori r11,r11,6148
	ctx.r11.u64 = ctx.r11.u64 | 6148;
	// stwx r10,0,r11
	REX_MM_STORE_U32(ctx.r11.u32, ctx.r10.u32);
	// eieio 
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b34
	ctx.lr = 0x82646080;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8264F498) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,7848
	ctx.r11.s64 = ctx.r11.s64 + 7848;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82662240
	ctx.lr = 0x8264F4C4;
	sub_82662240(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8264f4d4
	if (ctx.cr0.eq) goto loc_8264F4D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x8264F4D4;
	sub_8264CF40(ctx, base);
loc_8264F4D4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82652A48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// bl 0x82652748
	ctx.lr = 0x82652A68;
	sub_82652748(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82652a78
	if (ctx.cr0.eq) goto loc_82652A78;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x82652A78;
	sub_8264CF40(ctx, base);
loc_82652A78:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82654498) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x826544A0;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,48(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826544C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lis r11,4919
	ctx.r11.s64 = 322371584;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// ori r26,r11,61441
	ctx.r26.u64 = ctx.r11.u64 | 61441;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// bne cr6,0x826544f8
	if (!ctx.cr6.eq) goto loc_826544F8;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826546f8
	if (ctx.cr6.eq) goto loc_826546F8;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82652b28
	ctx.lr = 0x826544EC;
	sub_82652B28(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// b 0x826546f8
	goto loc_826546F8;
loc_826544F8:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r5,8343
	ctx.r5.s64 = 546766848;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// ori r5,r5,4
	ctx.r5.u64 = ctx.r5.u64 | 4;
	// li r4,60
	ctx.r4.s64 = 60;
	// bl 0x82641ff8
	ctx.lr = 0x82654514;
	sub_82641FF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8265452c
	if (ctx.cr0.eq) goto loc_8265452C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82652d58
	ctx.lr = 0x82654524;
	sub_82652D58(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// b 0x82654530
	goto loc_82654530;
loc_8265452C:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82654530:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82654544
	if (!ctx.cr6.eq) goto loc_82654544;
	// lis r30,-32761
	ctx.r30.s64 = -2147024896;
	// ori r30,r30,14
	ctx.r30.u64 = ctx.r30.u64 | 14;
	// b 0x82654718
	goto loc_82654718;
loc_82654544:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82652e30
	ctx.lr = 0x82654550;
	sub_82652E30(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bge 0x8265456c
	if (!ctx.cr0.lt) goto loc_8265456C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82652db0
	ctx.lr = 0x82654560;
	sub_82652DB0(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8264cf40
	ctx.lr = 0x82654568;
	sub_8264CF40(ctx, base);
	// b 0x82654718
	goto loc_82654718;
loc_8265456C:
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82654580
	if (ctx.cr6.eq) goto loc_82654580;
	// lwz r28,8(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82654584
	goto loc_82654584;
loc_82654580:
	// lwz r28,120(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
loc_82654584:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82654594
	if (ctx.cr6.eq) goto loc_82654594;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x82652b28
	ctx.lr = 0x82654594;
	sub_82652B28(ctx, base);
loc_82654594:
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826546f0
	if (ctx.cr6.eq) goto loc_826546F0;
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826545d0
	if (ctx.cr6.eq) goto loc_826545D0;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,68(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826545C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x826546f0
	goto loc_826546F0;
loc_826545D0:
	// lwz r27,32(r31)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// b 0x826546e8
	goto loc_826546E8;
loc_826545D8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82654718
	if (ctx.cr6.lt) goto loc_82654718;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x826545f8
	if (ctx.cr6.eq) goto loc_826545F8;
	// lwz r27,4(r27)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x826545fc
	goto loc_826545FC;
loc_826545F8:
	// li r29,0
	ctx.r29.s64 = 0;
loc_826545FC:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r10,52(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// lwz r28,4(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// beq cr6,0x8265461c
	if (ctx.cr6.eq) goto loc_8265461C;
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// b 0x82654620
	goto loc_82654620;
loc_8265461C:
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
loc_82654620:
	// lwz r7,128(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82654664
	if (!ctx.cr6.eq) goto loc_82654664;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82654640
	if (ctx.cr6.eq) goto loc_82654640;
	// lwz r7,12(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// b 0x82654664
	goto loc_82654664;
loc_82654640:
	// lwz r7,132(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82654664
	if (!ctx.cr6.eq) goto loc_82654664;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82654660;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
loc_82654664:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lwz r6,0(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826538c0
	ctx.lr = 0x82654684;
	sub_826538C0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x826546e8
	if (ctx.cr0.lt) goto loc_826546E8;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x826424a8
	ctx.lr = 0x8265469C;
	sub_826424A8(ctx, base);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r3,8(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// bl 0x82646748
	ctx.lr = 0x826546B4;
	sub_82646748(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x826546e8
	if (ctx.cr0.lt) goto loc_826546E8;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x826546e8
	if (ctx.cr6.eq) goto loc_826546E8;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826546E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_826546E8:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x826545d8
	if (!ctx.cr6.eq) goto loc_826545D8;
loc_826546F0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82654718
	if (ctx.cr6.lt) goto loc_82654718;
loc_826546F8:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r3,176(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82654714;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82654718:
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82654730;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82654748
	if (ctx.cr6.eq) goto loc_82654748;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82652db0
	ctx.lr = 0x82654740;
	sub_82652DB0(ctx, base);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x8264cf40
	ctx.lr = 0x82654748;
	sub_8264CF40(ctx, base);
loc_82654748:
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x826424b0
	ctx.lr = 0x82654750;
	sub_826424B0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826735A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826735d0
	if (ctx.cr6.eq) goto loc_826735D0;
	// bl 0x8264cf40
	ctx.lr = 0x826735CC;
	sub_8264CF40(ctx, base);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
loc_826735D0:
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826735e4
	if (ctx.cr6.eq) goto loc_826735E4;
	// bl 0x8264cf40
	ctx.lr = 0x826735E0;
	sub_8264CF40(ctx, base);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
loc_826735E4:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826735f8
	if (ctx.cr6.eq) goto loc_826735F8;
	// bl 0x8264cf40
	ctx.lr = 0x826735F4;
	sub_8264CF40(ctx, base);
	// stw r30,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r30.u32);
loc_826735F8:
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82675178) {
	REX_FUNC_PROLOGUE();
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lwzx r10,r11,r3
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// srawi r3,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r3.s64 = ctx.r10.s32 >> 8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82675348) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r3,824
	ctx.r3.s64 = 824;
	// bl 0x82673618
	ctx.lr = 0x82675360;
	sub_82673618(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82675380
	if (!ctx.cr6.eq) goto loc_82675380;
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
loc_82675380:
	// li r5,824
	ctx.r5.s64 = 824;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a590
	ctx.lr = 0x82675390;
	sub_8273A590(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r10,16
	ctx.r10.s64 = 16;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// li r7,9
	ctx.r7.s64 = 9;
	// sth r10,110(r31)
	REX_STORE_U16(ctx.r31.u32 + 110, ctx.r10.u16);
	// li r6,511
	ctx.r6.s64 = 511;
	// li r5,2
	ctx.r5.s64 = 2;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// li r4,61
	ctx.r4.s64 = 61;
	// lfs f0,2524(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// li r3,-1
	ctx.r3.s64 = -1;
	// lfs f13,28204(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 28204);
	ctx.f13.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stfs f0,44(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stfs f13,292(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// li r9,64
	ctx.r9.s64 = 64;
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// sth r11,28(r31)
	REX_STORE_U16(ctx.r31.u32 + 28, ctx.r11.u16);
	// sth r11,30(r31)
	REX_STORE_U16(ctx.r31.u32 + 30, ctx.r11.u16);
	// sth r11,32(r31)
	REX_STORE_U16(ctx.r31.u32 + 32, ctx.r11.u16);
	// stw r11,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r11.u32);
	// stw r7,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r7.u32);
	// stw r6,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r6.u32);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// sth r11,34(r31)
	REX_STORE_U16(ctx.r31.u32 + 34, ctx.r11.u16);
	// stw r5,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r5.u32);
	// stw r4,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r4.u32);
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// sth r3,108(r31)
	REX_STORE_U16(ctx.r31.u32 + 108, ctx.r3.u16);
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// stw r11,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
	// stw r11,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r11.u32);
	// stw r11,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r11.u32);
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// stw r11,176(r31)
	REX_STORE_U32(ctx.r31.u32 + 176, ctx.r11.u32);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// stw r11,656(r31)
	REX_STORE_U32(ctx.r31.u32 + 656, ctx.r11.u32);
	// stw r11,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r11.u32);
	// stb r11,200(r31)
	REX_STORE_U8(ctx.r31.u32 + 200, ctx.r11.u8);
	// stw r11,204(r31)
	REX_STORE_U32(ctx.r31.u32 + 204, ctx.r11.u32);
	// sth r11,210(r31)
	REX_STORE_U16(ctx.r31.u32 + 210, ctx.r11.u16);
	// stw r11,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r11.u32);
	// stw r11,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r11.u32);
	// stw r11,220(r31)
	REX_STORE_U32(ctx.r31.u32 + 220, ctx.r11.u32);
	// sth r11,202(r31)
	REX_STORE_U16(ctx.r31.u32 + 202, ctx.r11.u16);
	// stw r11,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r11.u32);
	// stw r10,228(r31)
	REX_STORE_U32(ctx.r31.u32 + 228, ctx.r10.u32);
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// stw r11,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r11.u32);
	// stw r11,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r11.u32);
	// stw r11,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r11.u32);
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
	// stw r11,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
	// stw r11,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r11.u32);
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// stw r9,296(r31)
	REX_STORE_U32(ctx.r31.u32 + 296, ctx.r9.u32);
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// stw r11,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r11.u32);
	// lis r8,-32151
	ctx.r8.s64 = -2107047936;
	// stw r11,784(r31)
	REX_STORE_U32(ctx.r31.u32 + 784, ctx.r11.u32);
	// lis r7,-32153
	ctx.r7.s64 = -2107179008;
	// stw r11,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r11.u32);
	// addi r6,r8,-23328
	ctx.r6.s64 = ctx.r8.s64 + -23328;
	// stw r11,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r11.u32);
	// lis r5,-32151
	ctx.r5.s64 = -2107047936;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// addi r4,r7,20376
	ctx.r4.s64 = ctx.r7.s64 + 20376;
	// stw r11,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// lis r3,-32151
	ctx.r3.s64 = -2107047936;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// addi r9,r5,-18200
	ctx.r9.s64 = ctx.r5.s64 + -18200;
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// addi r8,r3,-19400
	ctx.r8.s64 = ctx.r3.s64 + -19400;
	// stw r11,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r11.u32);
	// stw r11,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r11.u32);
	// stw r11,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
	// stw r11,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// stw r11,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r11.u32);
	// stw r11,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r11.u32);
	// stw r11,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r11.u32);
	// stw r11,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r11.u32);
	// stw r11,348(r31)
	REX_STORE_U32(ctx.r31.u32 + 348, ctx.r11.u32);
	// stw r11,352(r31)
	REX_STORE_U32(ctx.r31.u32 + 352, ctx.r11.u32);
	// stw r11,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r11.u32);
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
	// stw r11,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r11.u32);
	// stw r11,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r11.u32);
	// stw r11,372(r31)
	REX_STORE_U32(ctx.r31.u32 + 372, ctx.r11.u32);
	// stw r11,376(r31)
	REX_STORE_U32(ctx.r31.u32 + 376, ctx.r11.u32);
	// stw r11,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// stw r11,388(r31)
	REX_STORE_U32(ctx.r31.u32 + 388, ctx.r11.u32);
	// stw r11,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r11.u32);
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// stw r10,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r10.u32);
	// stw r11,412(r31)
	REX_STORE_U32(ctx.r31.u32 + 412, ctx.r11.u32);
	// stw r11,416(r31)
	REX_STORE_U32(ctx.r31.u32 + 416, ctx.r11.u32);
	// stw r11,420(r31)
	REX_STORE_U32(ctx.r31.u32 + 420, ctx.r11.u32);
	// stw r11,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r11.u32);
	// stw r11,428(r31)
	REX_STORE_U32(ctx.r31.u32 + 428, ctx.r11.u32);
	// stw r11,432(r31)
	REX_STORE_U32(ctx.r31.u32 + 432, ctx.r11.u32);
	// stw r11,436(r31)
	REX_STORE_U32(ctx.r31.u32 + 436, ctx.r11.u32);
	// stw r11,440(r31)
	REX_STORE_U32(ctx.r31.u32 + 440, ctx.r11.u32);
	// stw r11,444(r31)
	REX_STORE_U32(ctx.r31.u32 + 444, ctx.r11.u32);
	// stw r11,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
	// stw r11,452(r31)
	REX_STORE_U32(ctx.r31.u32 + 452, ctx.r11.u32);
	// stw r11,456(r31)
	REX_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
	// stw r11,460(r31)
	REX_STORE_U32(ctx.r31.u32 + 460, ctx.r11.u32);
	// stw r11,464(r31)
	REX_STORE_U32(ctx.r31.u32 + 464, ctx.r11.u32);
	// stw r11,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r11.u32);
	// stw r11,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r11.u32);
	// stw r6,476(r31)
	REX_STORE_U32(ctx.r31.u32 + 476, ctx.r6.u32);
	// stw r11,480(r31)
	REX_STORE_U32(ctx.r31.u32 + 480, ctx.r11.u32);
	// stw r11,484(r31)
	REX_STORE_U32(ctx.r31.u32 + 484, ctx.r11.u32);
	// stw r4,488(r31)
	REX_STORE_U32(ctx.r31.u32 + 488, ctx.r4.u32);
	// stw r11,492(r31)
	REX_STORE_U32(ctx.r31.u32 + 492, ctx.r11.u32);
	// stw r9,496(r31)
	REX_STORE_U32(ctx.r31.u32 + 496, ctx.r9.u32);
	// stw r8,516(r31)
	REX_STORE_U32(ctx.r31.u32 + 516, ctx.r8.u32);
	// stw r11,520(r31)
	REX_STORE_U32(ctx.r31.u32 + 520, ctx.r11.u32);
	// stw r11,524(r31)
	REX_STORE_U32(ctx.r31.u32 + 524, ctx.r11.u32);
	// stw r11,540(r31)
	REX_STORE_U32(ctx.r31.u32 + 540, ctx.r11.u32);
	// stw r11,544(r31)
	REX_STORE_U32(ctx.r31.u32 + 544, ctx.r11.u32);
	// stw r11,548(r31)
	REX_STORE_U32(ctx.r31.u32 + 548, ctx.r11.u32);
	// stw r11,552(r31)
	REX_STORE_U32(ctx.r31.u32 + 552, ctx.r11.u32);
	// stw r11,556(r31)
	REX_STORE_U32(ctx.r31.u32 + 556, ctx.r11.u32);
	// stw r11,560(r31)
	REX_STORE_U32(ctx.r31.u32 + 560, ctx.r11.u32);
	// stw r11,564(r31)
	REX_STORE_U32(ctx.r31.u32 + 564, ctx.r11.u32);
	// stb r11,201(r31)
	REX_STORE_U8(ctx.r31.u32 + 201, ctx.r11.u8);
	// stw r11,568(r31)
	REX_STORE_U32(ctx.r31.u32 + 568, ctx.r11.u32);
	// stw r11,572(r31)
	REX_STORE_U32(ctx.r31.u32 + 572, ctx.r11.u32);
	// stw r11,576(r31)
	REX_STORE_U32(ctx.r31.u32 + 576, ctx.r11.u32);
	// sth r11,580(r31)
	REX_STORE_U16(ctx.r31.u32 + 580, ctx.r11.u16);
	// stw r11,584(r31)
	REX_STORE_U32(ctx.r31.u32 + 584, ctx.r11.u32);
	// stw r11,588(r31)
	REX_STORE_U32(ctx.r31.u32 + 588, ctx.r11.u32);
	// stw r11,600(r31)
	REX_STORE_U32(ctx.r31.u32 + 600, ctx.r11.u32);
	// stw r11,604(r31)
	REX_STORE_U32(ctx.r31.u32 + 604, ctx.r11.u32);
	// stw r11,596(r31)
	REX_STORE_U32(ctx.r31.u32 + 596, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,608(r31)
	REX_STORE_U32(ctx.r31.u32 + 608, ctx.r11.u32);
	// stw r11,624(r31)
	REX_STORE_U32(ctx.r31.u32 + 624, ctx.r11.u32);
	// stw r11,740(r31)
	REX_STORE_U32(ctx.r31.u32 + 740, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8268D370) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x8268D378;
	__savegprlr_20(ctx, base);
	// stfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.f29.u64);
	// stfd f30,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.f30.u64);
	// stfd f31,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f31.u64);
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b374
	ctx.lr = 0x8268D38C;
	__savevmx_124(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// srawi r11,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// mr r22,r7
	ctx.r22.u64 = ctx.r7.u64;
	// mr r21,r8
	ctx.r21.u64 = ctx.r8.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// addze r26,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r26.s64 = temp.s64;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// ble cr6,0x8268d3c4
	if (!ctx.cr6.gt) goto loc_8268D3C4;
loc_8268D3B4:
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// srw r11,r6,r24
	ctx.r11.u64 = ctx.r24.u8 & 0x20 ? 0 : (ctx.r6.u32 >> (ctx.r24.u8 & 0x3F));
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bgt cr6,0x8268d3b4
	if (ctx.cr6.gt) goto loc_8268D3B4;
loc_8268D3C4:
	// addi r11,r26,-1
	ctx.r11.s64 = ctx.r26.s64 + -1;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// addi r10,r6,-4
	ctx.r10.s64 = ctx.r6.s64 + -4;
	// and r9,r11,r26
	ctx.r9.u64 = ctx.r11.u64 & ctx.r26.u64;
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// add r25,r11,r29
	ctx.r25.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r23,r8,27,31,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// cmpwi cr6,r6,64
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 64, ctx.xer);
	// blt cr6,0x8268d46c
	if (ctx.cr6.lt) goto loc_8268D46C;
	// cmpwi cr6,r6,2048
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 2048, ctx.xer);
	// bgt cr6,0x8268d46c
	if (ctx.cr6.gt) goto loc_8268D46C;
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// beq cr6,0x8268d46c
	if (ctx.cr6.eq) goto loc_8268D46C;
	// srawi r11,r6,7
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7F) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 7;
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,9896
	ctx.r8.s64 = ctx.r10.s64 + 9896;
	// lwzx r7,r9,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f11,4(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,12(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f11,f0
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// lfs f8,8(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f7,f10,f0
	ctx.f7.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// lfs f6,40(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 40);
	ctx.f6.f64 = double(temp.f32);
	// fmuls f5,f8,f0
	ctx.f5.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// lfs f4,20(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 20);
	ctx.f4.f64 = double(temp.f32);
	// fneg f3,f6
	ctx.f3.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// lfs f2,16(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// stfs f9,80(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f4,160(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// fneg f1,f12
	ctx.f1.u64 = ctx.f12.u64 ^ 0x8000000000000000;
	// stfs f3,112(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// b 0x8268d540
	goto loc_8268D540;
loc_8268D46C:
	// extsw r11,r6
	ctx.r11.s64 = ctx.r6.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f30,f0
	ctx.f30.f64 = double(ctx.f0.s64);
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// lfd f0,24232(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 24232);
	// fdiv f13,f0,f30
	ctx.f13.f64 = ctx.f0.f64 / ctx.f30.f64;
	// lfd f0,536(r9)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r9.u32 + 536);
	// fmul f29,f13,f0
	ctx.f29.f64 = ctx.f13.f64 * ctx.f0.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82738cc0
	ctx.lr = 0x8268D49C;
	sub_82738CC0(ctx, base);
	// fmul f12,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64 * ctx.f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bl 0x82738be0
	ctx.lr = 0x8268D4B0;
	sub_82738BE0(ctx, base);
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// fmul f10,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f1.f64 * ctx.f31.f64;
	// lfd f0,6304(r8)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 6304);
	// fdiv f30,f0,f30
	ctx.f30.f64 = ctx.f0.f64 / ctx.f30.f64;
	// lfd f0,528(r7)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r7.u32 + 528);
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// fmul f29,f30,f0
	ctx.f29.f64 = ctx.f30.f64 * ctx.f0.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x82738cc0
	ctx.lr = 0x8268D4DC;
	sub_82738CC0(ctx, base);
	// fmul f8,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = ctx.f1.f64 * ctx.f31.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// frsp f7,f8
	ctx.f7.f64 = double(float(ctx.f8.f64));
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x82738be0
	ctx.lr = 0x8268D4F0;
	sub_82738BE0(ctx, base);
	// lis r6,-32254
	ctx.r6.s64 = -2113798144;
	// fmul f6,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = ctx.f1.f64 * ctx.f31.f64;
	// lfd f0,520(r6)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r6.u32 + 520);
	// fmul f31,f30,f0
	ctx.f31.f64 = ctx.f30.f64 * ctx.f0.f64;
	// frsp f5,f6
	ctx.f5.f64 = double(float(ctx.f6.f64));
	// stfs f5,96(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82738be0
	ctx.lr = 0x8268D510;
	sub_82738BE0(ctx, base);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lfd f0,24264(r5)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r5.u32 + 24264);
	// fmul f4,f1,f0
	ctx.f4.f64 = ctx.f1.f64 * ctx.f0.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// frsp f31,f4
	ctx.f31.f64 = double(float(ctx.f4.f64));
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x82738cc0
	ctx.lr = 0x8268D52C;
	sub_82738CC0(ctx, base);
	// lis r4,-32256
	ctx.r4.s64 = -2113929216;
	// frsp f3,f1
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = double(float(ctx.f1.f64));
	// stfs f3,160(r1)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f0,28280(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 28280);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f31,f0
	ctx.f2.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
loc_8268D540:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f2,176(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// vspltw128 v13,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r31,r11,736
	ctx.r31.s64 = ctx.r11.s64 + 736;
	// li r5,32
	ctx.r5.s64 = 32;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v12,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v127,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// vspltw128 v0,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// lvx128 v62,r31,r5
	ea = (ctx.r31.u32 + ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v10,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// vxor128 v126,v127,v62
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// li r11,16
	ctx.r11.s64 = 16;
	// vmaddcfp128 v9,v127,v9,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vor v8,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// vsldoi v11,v12,v0,8
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 8));
	// srawi r10,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r26.s32 >> 2;
	// lvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsldoi v12,v10,v13,8
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8), 8));
	// vmaddcfp128 v8,v126,v8,v10
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// addze r27,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r27.s64 = temp.s64;
	// lvx128 v63,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v125,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v125.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// lvx128 v57,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v124,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v124.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// vsldoi v0,v0,v9,8
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8), 8));
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// vsldoi v13,v13,v8,8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8), 8));
	// vxor128 v10,v0,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// ble cr6,0x8268d674
	if (!ctx.cr6.gt) goto loc_8268D674;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8268D5EC:
	// lvx128 v56,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v12,v126,v0,v12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vor128 v55,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// lvx128 v54,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v11,v127,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vor128 v53,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// vrlimi128 v55,v54,5,2
	simde_mm_store_ps(ctx.v55.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v54.f32), 78), 5));
	// vrlimi128 v53,v56,5,2
	simde_mm_store_ps(ctx.v53.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v56.f32), 78), 5));
	// vmulfp128 v9,v13,v55
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v55.f32)));
	// vpermwi128 v8,v55,78
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v55.u32), 0xB1));
	// stvx128 v53,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r28,-16
	ctx.r28.s64 = ctx.r28.s64 + -16;
	// vmaddfp128 v0,v127,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp128 v13,v126,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v10,v10,v8,v9
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// stvx128 v10,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// vxor128 v10,v0,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// bdnz 0x8268d5ec
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D5EC;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x8268d674
	if (!ctx.cr6.gt) goto loc_8268D674;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8268D644:
	// lvx128 v52,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v12,v126,v0,v12
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmulfp128 v9,v13,v52
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v52.f32)));
	// vpermwi128 v8,v52,78
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v52.u32), 0xB1));
	// vmaddfp128 v11,v127,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp128 v0,v127,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v10,v10,v8,v9
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vmaddfp128 v13,v126,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v10,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r30,r30,16
	ctx.r30.s64 = ctx.r30.s64 + 16;
	// vxor128 v10,v0,v63
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// bdnz 0x8268d644
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D644;
loc_8268D674:
	// cmpwi cr6,r23,0
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 0, ctx.xer);
	// addi r5,r24,-1
	ctx.r5.s64 = ctx.r24.s64 + -1;
	// bne cr6,0x8268d684
	if (!ctx.cr6.eq) goto loc_8268D684;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
loc_8268D684:
	// li r6,0
	ctx.r6.s64 = 0;
	// mtctr r22
	ctx.ctr.u64 = ctx.r22.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bctrl 
	ctx.lr = 0x8268D698;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r10,48
	ctx.r10.s64 = 48;
	// lvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,16
	ctx.r9.s64 = 16;
	// vor v9,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vsldoi128 v11,v124,v0,12
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 4));
	// li r8,32
	ctx.r8.s64 = 32;
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
	// lvx128 v10,r31,r10
	ea = (ctx.r31.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r10,r25
	ctx.r10.u64 = ctx.r25.u64;
	// vmaddcfp128 v9,v126,v9,v125
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v125.f32)));
	// vor v8,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vsldoi128 v12,v125,v10,12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8), 4));
	// lvx128 v63,r31,r9
	ea = (ctx.r31.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r31,r8
	ea = (ctx.r31.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// vmaddcfp128 v8,v127,v8,v124
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v124.f32)));
	// vor v7,v9,v9
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v9.u8));
	// vsldoi v13,v10,v9,12
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8), 4));
	// vrlimi128 v12,v9,1,0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v9.f32), 228), 1));
	// vmaddcfp128 v7,v127,v7,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsldoi v0,v0,v8,12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8), 4));
	// vmaddfp128 v10,v126,v8,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vrlimi128 v11,v8,1,0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v8.f32), 228), 1));
	// vrlimi128 v0,v7,1,0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v7.f32), 228), 1));
	// vrlimi128 v13,v10,1,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v10.f32), 228), 1));
	// vxor128 v8,v0,v63
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v9,v13,v63
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v62,v0,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// ble cr6,0x8268d774
	if (!ctx.cr6.gt) goto loc_8268D774;
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
loc_8268D710:
	// lvx128 v51,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v10,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vor128 v50,v51,v51
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_load_si128((simde__m128i*)ctx.v51.u8));
	// lvx128 v49,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp128 v11,v127,v13,v11
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddcfp128 v10,v126,v10,v12
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vpermwi128 v12,v51,78
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v51.u32), 0xB1));
	// vrlimi128 v50,v49,5,1
	simde_mm_store_ps(ctx.v50.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v50.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v49.f32), 147), 5));
	// vrlimi128 v12,v49,5,2
	simde_mm_store_ps(ctx.v12.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v49.f32), 78), 5));
	// vmulfp128 v6,v62,v50
	simde_mm_store_ps(ctx.v6.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v50.f32)));
	// vmulfp128 v7,v13,v50
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v50.f32)));
	// vmaddfp128 v13,v126,v11,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v126.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp128 v0,v127,v10,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v9,v9,v12,v6
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v8,v8,v12,v7
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vor v12,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// vxor128 v62,v0,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vpermwi128 v48,v9,228
	simde_mm_store_si128((simde__m128i*)ctx.v48.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v9.u32), 0x1B));
	// vxor128 v9,v13,v63
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v8,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// vxor128 v8,v0,v63
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v48,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-16
	ctx.r10.s64 = ctx.r10.s64 + -16;
	// bdnz 0x8268d710
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8268D710;
loc_8268D774:
	// cmplwi cr6,r20,0
	ctx.cr6.compare<uint32_t>(ctx.r20.u32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// beq cr6,0x8268d788
	if (ctx.cr6.eq) goto loc_8268D788;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r20)
	REX_STORE_U32(ctx.r20.u32 + 0, ctx.r11.u32);
loc_8268D788:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// addi r12,r1,-128
	ctx.r12.s64 = ctx.r1.s64 + -128;
	// bl 0x8273b60c
	ctx.lr = 0x8268D794;
	__restvmx_124(ctx, base);
	// lfd f29,-128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// lfd f30,-120(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// lfd f31,-112(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826D4800) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x826D4808;
	__savegprlr_29(ctx, base);
	// lhz r30,50(r3)
	ctx.r30.u64 = REX_LOAD_U16(ctx.r3.u32 + 50);
	// srawi r31,r6,16
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFFFF) != 0);
	ctx.r31.s64 = ctx.r6.s32 >> 16;
	// lhz r29,52(r3)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r3.u32 + 52);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bne cr6,0x826d4830
	if (!ctx.cr6.eq) goto loc_826D4830;
	// rlwinm r3,r3,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r31,r31,1,0,30
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x826d4838
	goto loc_826D4838;
loc_826D4830:
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// bne cr6,0x826d483c
	if (!ctx.cr6.eq) goto loc_826D483C;
loc_826D4838:
	// li r11,1
	ctx.r11.s64 = 1;
loc_826D483C:
	// srawi r6,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r5.s32 >> 1;
	// lhz r9,18(r7)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r7.u32 + 18);
	// lhz r8,16(r7)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + 16);
	// clrlwi r10,r5,31
	ctx.r10.u64 = ctx.r5.u32 & 0x1;
	// clrlwi r7,r6,31
	ctx.r7.u64 = ctx.r6.u32 & 0x1;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r9,r5,5,0,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 5) & 0xFFFFFFE0;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r7,r10,r31
	ctx.r7.u64 = ctx.r10.u64 + ctx.r31.u64;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// subfic r10,r11,-15
	ctx.xer.ca = ctx.r11.u32 <= 4294967281;
	ctx.r10.u64 = static_cast<uint64_t>(-15) - ctx.r11.u64;
	// beq cr6,0x826d4878
	if (ctx.cr6.eq) goto loc_826D4878;
	// subfic r10,r11,-7
	ctx.xer.ca = ctx.r11.u32 <= 4294967289;
	ctx.r10.u64 = static_cast<uint64_t>(-7) - ctx.r11.u64;
loc_826D4878:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// slw r6,r9,r11
	ctx.r6.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 << (ctx.r11.u8 & 0x3F));
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r29,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// mullw r5,r5,r11
	ctx.r5.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r11.s32);
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// not r5,r5
	ctx.r5.u64 = ~ctx.r5.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// and r11,r5,r8
	ctx.r11.u64 = ctx.r5.u64 & ctx.r8.u64;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// and r10,r5,r7
	ctx.r10.u64 = ctx.r5.u64 & ctx.r7.u64;
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d48c8
	if (!ctx.cr6.lt) goto loc_826D48C8;
	// subf r11,r11,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r11.u64;
	// b 0x826d48d4
	goto loc_826D48D4;
loc_826D48C8:
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x826d48d8
	if (!ctx.cr6.gt) goto loc_826D48D8;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
loc_826D48D4:
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_826D48D8:
	// cmpw cr6,r10,r6
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d48e8
	if (!ctx.cr6.lt) goto loc_826D48E8;
	// subf r11,r10,r6
	ctx.r11.u64 = ctx.r6.u64 - ctx.r10.u64;
	// b 0x826d48f4
	goto loc_826D48F4;
loc_826D48E8:
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x826d48f8
	if (!ctx.cr6.gt) goto loc_826D48F8;
	// subf r11,r10,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r10.u64;
loc_826D48F4:
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_826D48F8:
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// bne cr6,0x826d4908
	if (!ctx.cr6.eq) goto loc_826D4908;
	// srawi r3,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 1;
	// srawi r31,r31,1
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 1;
loc_826D4908:
	// rlwimi r3,r31,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826E3360) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// vspltish v15,15
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_set1_epi16(short(0xF)));
	// li r0,0
	ctx.r0.s64 = 0;
	// addi r8,r3,128
	ctx.r8.s64 = ctx.r3.s64 + 128;
	// add r12,r6,r6
	ctx.r12.u64 = ctx.r6.u64 + ctx.r6.u64;
	// rlwinm r9,r6,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// vslb v8,v15,v15
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// add r11,r7,r7
	ctx.r11.u64 = ctx.r7.u64 + ctx.r7.u64;
	// lvx128 v0,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r12,r9
	ctx.r10.u64 = ctx.r12.u64 + ctx.r9.u64;
	// lvx128 v1,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v2,r3,r12
	ea = (ctx.r3.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v16,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v3,r8,r12
	ea = (ctx.r8.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v17,v1,v8
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v4,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v18,v2,v8
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v5,r8,r9
	ea = (ctx.r8.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v19,v3,v8
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v7,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v6,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v20,v4,v8
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvx v16,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r11,r6
	ctx.r7.u64 = ctx.r11.u64 + ctx.r6.u64;
	// vaddshs v21,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvx v17,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v22,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvx v18,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v23,v7,v8
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvx v19,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v20,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v21,r5,r6
	ea = (ctx.r5.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v22,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v23,r5,r7
	ea = (ctx.r5.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r9,r9
	ctx.r7.u64 = ctx.r9.u64 + ctx.r9.u64;
	// add r10,r12,r7
	ctx.r10.u64 = ctx.r12.u64 + ctx.r7.u64;
	// lvx128 v1,r8,r7
	ea = (ctx.r8.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v17,v1,v8
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v0,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r12,r10
	ctx.r7.u64 = ctx.r12.u64 + ctx.r10.u64;
	// lvx128 v3,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v16,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v2,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r12,r7
	ctx.r10.u64 = ctx.r12.u64 + ctx.r7.u64;
	// lvx128 v4,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v18,v2,v8
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v6,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v19,v3,v8
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v7,r8,r10
	ea = (ctx.r8.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v20,v4,v8
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// lvx128 v5,r8,r7
	ea = (ctx.r8.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r6,r6
	ctx.r7.u64 = ctx.r6.u64 + ctx.r6.u64;
	// vaddshs v21,v5,v8
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// add r8,r11,r7
	ctx.r8.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stvx v16,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r9,r6,r7
	ctx.r9.u64 = ctx.r6.u64 + ctx.r7.u64;
	// stvx v17,r5,r7
	ea = (ctx.r5.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// vaddshs v22,v6,v8
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v23,v7,v8
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvx v18,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v19,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v20,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v21,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v22,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx v23,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826F1178) {
	REX_FUNC_PROLOGUE();
	// cmpwi cr6,r4,5
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 5, ctx.xer);
	// bge cr6,0x826f119c
	if (!ctx.cr6.lt) goto loc_826F119C;
	// addi r11,r3,2488
	ctx.r11.s64 = ctx.r3.s64 + 2488;
	// addi r10,r3,2504
	ctx.r10.s64 = ctx.r3.s64 + 2504;
	// addi r9,r3,2544
	ctx.r9.s64 = ctx.r3.s64 + 2544;
	// stw r11,2500(r3)
	REX_STORE_U32(ctx.r3.u32 + 2500, ctx.r11.u32);
	// stw r10,2540(r3)
	REX_STORE_U32(ctx.r3.u32 + 2540, ctx.r10.u32);
	// stw r9,2580(r3)
	REX_STORE_U32(ctx.r3.u32 + 2580, ctx.r9.u32);
	// blr 
	return;
loc_826F119C:
	// cmpwi cr6,r4,13
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 13, ctx.xer);
	// bge cr6,0x826f11c0
	if (!ctx.cr6.lt) goto loc_826F11C0;
	// addi r11,r3,2476
	ctx.r11.s64 = ctx.r3.s64 + 2476;
	// addi r10,r3,2516
	ctx.r10.s64 = ctx.r3.s64 + 2516;
	// addi r9,r3,2556
	ctx.r9.s64 = ctx.r3.s64 + 2556;
	// stw r11,2500(r3)
	REX_STORE_U32(ctx.r3.u32 + 2500, ctx.r11.u32);
	// stw r10,2540(r3)
	REX_STORE_U32(ctx.r3.u32 + 2540, ctx.r10.u32);
	// stw r9,2580(r3)
	REX_STORE_U32(ctx.r3.u32 + 2580, ctx.r9.u32);
	// blr 
	return;
loc_826F11C0:
	// addi r11,r3,2464
	ctx.r11.s64 = ctx.r3.s64 + 2464;
	// addi r10,r3,2528
	ctx.r10.s64 = ctx.r3.s64 + 2528;
	// addi r9,r3,2568
	ctx.r9.s64 = ctx.r3.s64 + 2568;
	// stw r11,2500(r3)
	REX_STORE_U32(ctx.r3.u32 + 2500, ctx.r11.u32);
	// stw r10,2540(r3)
	REX_STORE_U32(ctx.r3.u32 + 2540, ctx.r10.u32);
	// stw r9,2580(r3)
	REX_STORE_U32(ctx.r3.u32 + 2580, ctx.r9.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826F20E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x826F20E8;
	__savegprlr_27(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,144(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 144);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,20912(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20912);
	// lwz r9,268(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mullw r11,r11,r10
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// lwz r8,22164(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 22164);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r7,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r31,r11,r9
	ctx.r31.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lwz r11,140(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// beq cr6,0x826f21ec
	if (ctx.cr6.eq) goto loc_826F21EC;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826f2290
	if (!ctx.cr6.gt) goto loc_826F2290;
	// lwz r11,136(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// li r28,0
	ctx.r28.s64 = 0;
loc_826F2134:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826f21d0
	if (!ctx.cr6.gt) goto loc_826F21D0;
loc_826F2140:
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r10,r11,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r10,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r10.u64;
	// addi r10,r11,14
	ctx.r10.s64 = ctx.r11.s64 + 14;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// beq cr6,0x826f2178
	if (ctx.cr6.eq) goto loc_826F2178;
	// lwz r11,22192(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22192);
	// lwzx r9,r11,r28
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r28.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x826f217c
	if (ctx.cr6.eq) goto loc_826F217C;
loc_826F2178:
	// li r11,1
	ctx.r11.s64 = 1;
loc_826F217C:
	// cntlzw r9,r29
	ctx.r9.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r5,r31,-10
	ctx.r5.s64 = ctx.r31.s64 + -10;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// addi r10,r31,14
	ctx.r10.s64 = ctx.r31.s64 + 14;
	// stw r4,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// addi r9,r31,-16
	ctx.r9.s64 = ctx.r31.s64 + -16;
	// addi r7,r31,8
	ctx.r7.s64 = ctx.r31.s64 + 8;
	// rlwinm r6,r6,24,29,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0x7;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826ed810
	ctx.lr = 0x826F21BC;
	sub_826ED810(ctx, base);
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826f2140
	if (ctx.cr6.lt) goto loc_826F2140;
loc_826F21D0:
	// lwz r10,140(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// cmpw cr6,r27,r10
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826f2134
	if (ctx.cr6.lt) goto loc_826F2134;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_826F21EC:
	// li r28,0
	ctx.r28.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826f2290
	if (!ctx.cr6.gt) goto loc_826F2290;
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
loc_826F21FC:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826f2280
	if (!ctx.cr6.gt) goto loc_826F2280;
	// cntlzw r11,r28
	ctx.r11.u64 = ctx.r28.u32 == 0 ? 32 : __builtin_clz(ctx.r28.u32);
	// rlwinm r27,r11,27,31,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_826F2210:
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// addi r5,r31,-10
	ctx.r5.s64 = ctx.r31.s64 + -10;
	// cntlzw r9,r29
	ctx.r9.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r5,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r5.u32);
	// rlwinm r4,r9,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r4,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r4.u32);
	// addi r10,r31,14
	ctx.r10.s64 = ctx.r31.s64 + 14;
	// rlwinm r11,r3,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r9,r31,-16
	ctx.r9.s64 = ctx.r31.s64 + -16;
	// subf r11,r11,r31
	ctx.r11.u64 = ctx.r31.u64 - ctx.r11.u64;
	// addi r7,r31,8
	ctx.r7.s64 = ctx.r31.s64 + 8;
	// addi r5,r11,14
	ctx.r5.s64 = ctx.r11.s64 + 14;
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// rlwinm r6,r6,24,29,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 24) & 0x7;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826ed810
	ctx.lr = 0x826F226C;
	sub_826ED810(ctx, base);
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,24
	ctx.r31.s64 = ctx.r31.s64 + 24;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x826f2210
	if (ctx.cr6.lt) goto loc_826F2210;
loc_826F2280:
	// lwz r10,140(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmpw cr6,r28,r10
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x826f21fc
	if (ctx.cr6.lt) goto loc_826F21FC;
loc_826F2290:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82700468) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82700470;
	__savegprlr_27(ctx, base);
	// stwu r1,-640(r1)
	ea = -640 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,152(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// rlwinm r27,r10,0,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8270049c
	if (ctx.cr6.eq) goto loc_8270049C;
	// lwz r10,15652(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 15652);
	// bl 0x826fe8b8
	ctx.lr = 0x82700494;
	sub_826FE8B8(ctx, base);
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_8270049C:
	// li r10,32
	ctx.r10.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826fe8b8
	ctx.lr = 0x827004AC;
	sub_826FE8B8(ctx, base);
	// lwz r30,724(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 724);
	// addi r29,r1,80
	ctx.r29.s64 = ctx.r1.s64 + 80;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// ble cr6,0x827004e4
	if (!ctx.cr6.gt) goto loc_827004E4;
	// rlwinm r27,r27,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
loc_827004C0:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x827004D0;
	sub_8273A030(ctx, base);
	// lwz r11,15652(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15652);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,32
	ctx.r29.s64 = ctx.r29.s64 + 32;
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bne 0x827004c0
	if (!ctx.cr0.eq) goto loc_827004C0;
loc_827004E4:
	// addi r1,r1,640
	ctx.r1.s64 = ctx.r1.s64 + 640;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82704468) {
	REX_FUNC_PROLOGUE();
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lis r10,-32116
	ctx.r10.s64 = -2104754176;
	// addi r9,r10,27768
	ctx.r9.s64 = ctx.r10.s64 + 27768;
	// rlwinm r8,r11,2,28,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r8,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r9.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// stw r6,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r6.u32);
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm r10,r11,2,28,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xC;
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// stw r8,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
	// lwz r7,1792(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 1792);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827044d4
	if (ctx.cr6.eq) goto loc_827044D4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827044cc
	if (!ctx.cr6.gt) goto loc_827044CC;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x827044d0
	goto loc_827044D0;
loc_827044CC:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_827044D0:
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
loc_827044D4:
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x827044f8
	if (!ctx.cr6.gt) goto loc_827044F8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
loc_827044F8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8270A808) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x8270A810;
	__savegprlr_21(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// li r23,0
	ctx.r23.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// stw r23,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r23.u32);
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// stw r23,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r23.u32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r24,r7
	ctx.r24.u64 = ctx.r7.u64;
	// mr r21,r10
	ctx.r21.u64 = ctx.r10.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8270a870
	if (!ctx.cr6.eq) goto loc_8270A870;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,24
	ctx.r3.s64 = 24;
	// bl 0x826bedb8
	ctx.lr = 0x8270A850;
	sub_826BEDB8(ctx, base);
	// stw r3,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8270a948
	if (ctx.cr6.eq) goto loc_8270A948;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// bl 0x8270a740
	ctx.lr = 0x8270A864;
	sub_8270A740(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270a94c
	if (!ctx.cr6.eq) goto loc_8270A94C;
loc_8270A870:
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// ble cr6,0x8270a93c
	if (!ctx.cr6.gt) goto loc_8270A93C;
	// li r22,-1
	ctx.r22.s64 = -1;
loc_8270A880:
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,644
	ctx.r3.s64 = 644;
	// bl 0x826bedb8
	ctx.lr = 0x8270A88C;
	sub_826BEDB8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8270a948
	if (ctx.cr6.eq) goto loc_8270A948;
	// cmpwi cr6,r21,0
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 0, ctx.xer);
	// beq cr6,0x8270a8b4
	if (ctx.cr6.eq) goto loc_8270A8B4;
	// li r5,644
	ctx.r5.s64 = 644;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8273a590
	ctx.lr = 0x8270A8AC;
	sub_8273A590(ctx, base);
	// stw r22,636(r30)
	REX_STORE_U32(ctx.r30.u32 + 636, ctx.r22.u32);
	// b 0x8270a8d0
	goto loc_8270A8D0;
loc_8270A8B4:
	// mr r6,r24
	ctx.r6.u64 = ctx.r24.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// bl 0x826c1c28
	ctx.lr = 0x8270A8C4;
	sub_826C1C28(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x8270a94c
	if (!ctx.cr6.eq) goto loc_8270A94C;
loc_8270A8D0:
	// stw r29,636(r30)
	REX_STORE_U32(ctx.r30.u32 + 636, ctx.r29.u32);
	// lwz r11,12(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8270a948
	if (ctx.cr6.eq) goto loc_8270A948;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// blt cr6,0x8270a948
	if (ctx.cr6.lt) goto loc_8270A948;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bne cr6,0x8270a904
	if (!ctx.cr6.eq) goto loc_8270A904;
	// stw r23,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r23.u32);
loc_8270A904:
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// bne cr6,0x8270a924
	if (!ctx.cr6.eq) goto loc_8270A924;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
loc_8270A924:
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r29,r27
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r27.s32, ctx.xer);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// blt cr6,0x8270a880
	if (ctx.cr6.lt) goto loc_8270A880;
loc_8270A93C:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
loc_8270A948:
	// li r31,2
	ctx.r31.s64 = 2;
loc_8270A94C:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8270a520
	ctx.lr = 0x8270A954;
	sub_8270A520(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827119C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x827119C8;
	__savegprlr_18(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r5,10
	ctx.r11.s64 = ctx.r5.s64 + 10;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// srawi r29,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r29.s64 = ctx.r11.s32 >> 3;
	// mr r20,r5
	ctx.r20.u64 = ctx.r5.u64;
	// addi r31,r3,-5
	ctx.r31.s64 = ctx.r3.s64 + -5;
	// li r19,8
	ctx.r19.s64 = 8;
	// rlwinm r28,r29,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// li r27,-1
	ctx.r27.s64 = -1;
loc_827119EC:
	// lbz r24,3(r31)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r31.u32 + 3);
	// lbz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r4,2(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 2);
	// subf r11,r6,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r6.u64;
	// lbz r22,1(r31)
	ctx.r22.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// subf r10,r24,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r24.u64;
	// lbz r25,5(r31)
	ctx.r25.u64 = REX_LOAD_U8(ctx.r31.u32 + 5);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lbz r26,6(r31)
	ctx.r26.u64 = REX_LOAD_U8(ctx.r31.u32 + 6);
	// add r9,r10,r29
	ctx.r9.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lbz r30,7(r31)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r31.u32 + 7);
	// subfc r11,r11,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r28.u64 - ctx.r11.u64;
	// lbz r23,8(r31)
	ctx.r23.u64 = REX_LOAD_U8(ctx.r31.u32 + 8);
	// subf r10,r4,r22
	ctx.r10.u64 = ctx.r22.u64 - ctx.r4.u64;
	// subfze r8,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r8.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfc r11,r9,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r9.u32;
	ctx.r11.u64 = ctx.r28.u64 - ctx.r9.u64;
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// subf r21,r25,r6
	ctx.r21.u64 = ctx.r6.u64 - ctx.r25.u64;
	// subfze r10,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r10.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfc r11,r7,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r7.u32;
	ctx.r11.u64 = ctx.r28.u64 - ctx.r7.u64;
	// add r5,r21,r29
	ctx.r5.u64 = ctx.r21.u64 + ctx.r29.u64;
	// subfze r9,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r9.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// subfc r11,r5,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r5.u32;
	ctx.r11.u64 = ctx.r28.u64 - ctx.r5.u64;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// subfze r11,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r11.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add. r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82711ac8
	if (ctx.cr0.eq) goto loc_82711AC8;
	// lbz r10,9(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 9);
	// subf r8,r23,r30
	ctx.r8.u64 = ctx.r30.u64 - ctx.r23.u64;
	// lbz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// subf r9,r10,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r10.u64;
	// subf r10,r22,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r22.u64;
	// add r5,r9,r29
	ctx.r5.u64 = ctx.r9.u64 + ctx.r29.u64;
	// add r3,r10,r29
	ctx.r3.u64 = ctx.r10.u64 + ctx.r29.u64;
	// subfc r10,r5,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r5.u32;
	ctx.r10.u64 = ctx.r28.u64 - ctx.r5.u64;
	// add r7,r8,r29
	ctx.r7.u64 = ctx.r8.u64 + ctx.r29.u64;
	// subfze r9,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r9.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfc r10,r3,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r3.u32;
	ctx.r10.u64 = ctx.r28.u64 - ctx.r3.u64;
	// subf r8,r30,r26
	ctx.r8.u64 = ctx.r26.u64 - ctx.r30.u64;
	// subfze r5,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r5.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// subfc r10,r7,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r7.u32;
	ctx.r10.u64 = ctx.r28.u64 - ctx.r7.u64;
	// add r3,r8,r29
	ctx.r3.u64 = ctx.r8.u64 + ctx.r29.u64;
	// subf r8,r26,r25
	ctx.r8.u64 = ctx.r25.u64 - ctx.r26.u64;
	// subfze r7,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r7.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// subfc r10,r3,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r3.u32;
	ctx.r10.u64 = ctx.r28.u64 - ctx.r3.u64;
	// add r5,r8,r29
	ctx.r5.u64 = ctx.r8.u64 + ctx.r29.u64;
	// subfze r8,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r8.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// subfc r10,r5,r28
	ctx.xer.ca = ctx.r28.u32 >= ctx.r5.u32;
	ctx.r10.u64 = ctx.r28.u64 - ctx.r5.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// subfze r10,r27
	temp.u8 = ~ctx.r27.u32 + ctx.xer.ca < ~ctx.r27.u32;
	ctx.r10.u64 = ~ctx.r27.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82711AC8:
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x82711b70
	if (ctx.cr6.lt) goto loc_82711B70;
	// rlwinm r11,r20,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r25
	ctx.r7.u64 = ctx.r25.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x827114d8
	ctx.lr = 0x82711AF4;
	sub_827114D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82711b70
	if (ctx.cr6.eq) goto loc_82711B70;
	// add r10,r24,r4
	ctx.r10.u64 = ctx.r24.u64 + ctx.r4.u64;
	// add r9,r30,r26
	ctx.r9.u64 = ctx.r30.u64 + ctx.r26.u64;
	// add r11,r30,r4
	ctx.r11.u64 = ctx.r30.u64 + ctx.r4.u64;
	// rlwinm r7,r6,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r10,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r25,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r26,r9,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 + ctx.r7.u64;
	// rlwinm r8,r11,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r6,r25,r5
	ctx.r6.u64 = ctx.r25.u64 + ctx.r5.u64;
	// add r9,r9,r26
	ctx.r9.u64 = ctx.r9.u64 + ctx.r26.u64;
	// add r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add r7,r3,r11
	ctx.r7.u64 = ctx.r3.u64 + ctx.r11.u64;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r11,r8,r30
	ctx.r11.u64 = ctx.r8.u64 + ctx.r30.u64;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// addi r6,r9,4
	ctx.r6.s64 = ctx.r9.s64 + 4;
	// srawi r4,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 3;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// addi r5,r10,4
	ctx.r5.s64 = ctx.r10.s64 + 4;
	// stb r4,3(r31)
	REX_STORE_U8(ctx.r31.u32 + 3, ctx.r4.u8);
	// srawi r11,r6,3
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 3;
	// srawi r10,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 3;
	// srawi r9,r3,3
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 3;
	// stb r11,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r11.u8);
	// b 0x82711c54
	goto loc_82711C54;
loc_82711B70:
	// subf r10,r26,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r26.u64;
	// rlwinm r11,r21,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// add r9,r21,r11
	ctx.r9.u64 = ctx.r21.u64 + ctx.r11.u64;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r7,r9,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r9.u64;
	// srawi r5,r7,3
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 3;
	// srawi r3,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 31;
	// xor r11,r5,r3
	ctx.r11.u64 = ctx.r5.u64 ^ ctx.r3.u64;
	// subf r3,r3,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r3.u64;
	// cmpw cr6,r3,r20
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r20.s32, ctx.xer);
	// bge cr6,0x82711c5c
	if (!ctx.cr6.lt) goto loc_82711C5C;
	// subf r8,r6,r22
	ctx.r8.u64 = ctx.r22.u64 - ctx.r6.u64;
	// subf r10,r4,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r4.u64;
	// subf r11,r26,r30
	ctx.r11.u64 = ctx.r30.u64 - ctx.r26.u64;
	// subf r9,r23,r25
	ctx.r9.u64 = ctx.r25.u64 - ctx.r23.u64;
	// addi r4,r8,2
	ctx.r4.s64 = ctx.r8.s64 + 2;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r30,r9,2
	ctx.r30.s64 = ctx.r9.s64 + 2;
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rlwinm r10,r30,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r8,r10,r11
	ctx.r8.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r11,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 3;
	// srawi r10,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 3;
	// srawi r7,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 31;
	// srawi r4,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 31;
	// xor r10,r10,r7
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r7.u64;
	// xor r9,r11,r4
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r4.u64;
	// subf r11,r7,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r7.u64;
	// subf r10,r4,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r4.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82711c04
	if (!ctx.cr6.lt) goto loc_82711C04;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82711C04:
	// subf. r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x82711c5c
	if (!ctx.cr0.gt) goto loc_82711C5C;
	// xor r10,r5,r21
	ctx.r10.u64 = ctx.r5.u64 ^ ctx.r21.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bge cr6,0x82711c5c
	if (!ctx.cr6.lt) goto loc_82711C5C;
	// srawi r10,r21,31
	ctx.xer.ca = (ctx.r21.s32 < 0) & ((ctx.r21.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r21.s32 >> 31;
	// srawi r8,r21,31
	ctx.xer.ca = (ctx.r21.s32 < 0) & ((ctx.r21.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r21.s32 >> 31;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// xor r7,r21,r8
	ctx.r7.u64 = ctx.r21.u64 ^ ctx.r8.u64;
	// add r5,r11,r9
	ctx.r5.u64 = ctx.r11.u64 + ctx.r9.u64;
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// srawi r9,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 1;
	// srawi r11,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 3;
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x82711c44
	if (!ctx.cr6.gt) goto loc_82711C44;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
loc_82711C44:
	// xor r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// subf r10,r11,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r11.u64;
	// add r9,r11,r25
	ctx.r9.u64 = ctx.r11.u64 + ctx.r25.u64;
loc_82711C54:
	// stb r9,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r9.u8);
	// stb r10,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r10.u8);
loc_82711C5C:
	// addic. r19,r19,-1
	ctx.xer.ca = ctx.r19.u32 > 0;
	ctx.r19.s64 = ctx.r19.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// add r31,r31,r18
	ctx.r31.u64 = ctx.r31.u64 + ctx.r18.u64;
	// bne 0x827119ec
	if (!ctx.cr0.eq) goto loc_827119EC;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8272BB38) {
	REX_FUNC_PROLOGUE();
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8272bb54
	if (ctx.cr6.eq) goto loc_8272BB54;
	// cmplwi cr6,r9,3
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 3, ctx.xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// bne cr6,0x8272bb58
	if (!ctx.cr6.eq) goto loc_8272BB58;
loc_8272BB54:
	// li r6,1
	ctx.r6.s64 = 1;
loc_8272BB58:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r10,12849
	ctx.r10.s64 = 842072064;
	// lis r8,12338
	ctx.r8.s64 = 808583168;
	// ori r10,r10,22105
	ctx.r10.u64 = ctx.r10.u64 | 22105;
	// lis r7,22101
	ctx.r7.s64 = 1448411136;
	// ori r8,r8,13385
	ctx.r8.u64 = ctx.r8.u64 | 13385;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r7,r7,22857
	ctx.r7.u64 = ctx.r7.u64 | 22857;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x8272bc00
	if (ctx.cr6.gt) goto loc_8272BC00;
	// beq cr6,0x8272bc20
	if (ctx.cr6.eq) goto loc_8272BC20;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8272bc20
	if (ctx.cr6.eq) goto loc_8272BC20;
	// lis r10,12593
	ctx.r10.s64 = 825294848;
	// ori r7,r10,13392
	ctx.r7.u64 = ctx.r10.u64 | 13392;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8272bc18
	if (!ctx.cr6.eq) goto loc_8272BC18;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x8272bc28
	if (!ctx.cr6.eq) goto loc_8272BC28;
	// lis r11,12889
	ctx.r11.s64 = 844693504;
	// ori r10,r11,21849
	ctx.r10.u64 = ctx.r11.u64 | 21849;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8272bbc8
	if (!ctx.cr6.eq) goto loc_8272BBC8;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-21096
	ctx.r10.s64 = ctx.r11.s64 + -21096;
	// stw r10,14664(r3)
	REX_STORE_U32(ctx.r3.u32 + 14664, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272BBC8:
	// lis r11,22101
	ctx.r11.s64 = 1448411136;
	// ori r10,r11,22857
	ctx.r10.u64 = ctx.r11.u64 | 22857;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8272bbe0
	if (ctx.cr6.eq) goto loc_8272BBE0;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8272bc28
	if (!ctx.cr6.eq) goto loc_8272BC28;
loc_8272BBE0:
	// lwz r11,14620(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14620);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x8272bc28
	if (ctx.cr6.eq) goto loc_8272BC28;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-11856
	ctx.r10.s64 = ctx.r11.s64 + -11856;
	// stw r10,14660(r3)
	REX_STORE_U32(ctx.r3.u32 + 14660, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272BC00:
	// lis r5,12850
	ctx.r5.s64 = 842137600;
	// ori r4,r5,13392
	ctx.r4.u64 = ctx.r5.u64 | 13392;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x8272bca0
	if (ctx.cr6.eq) goto loc_8272BCA0;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8272bc20
	if (ctx.cr6.eq) goto loc_8272BC20;
loc_8272BC18:
	// li r3,3
	ctx.r3.s64 = 3;
	// blr 
	return;
loc_8272BC20:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x8272bc30
	if (ctx.cr6.eq) goto loc_8272BC30;
loc_8272BC28:
	// li r3,5
	ctx.r3.s64 = 5;
	// blr 
	return;
loc_8272BC30:
	// lis r11,12889
	ctx.r11.s64 = 844693504;
	// ori r6,r11,21849
	ctx.r6.u64 = ctx.r11.u64 | 21849;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8272bc74
	if (!ctx.cr6.eq) goto loc_8272BC74;
	// lwz r11,14620(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 14620);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x8272bc60
	if (!ctx.cr6.eq) goto loc_8272BC60;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-20768
	ctx.r10.s64 = ctx.r11.s64 + -20768;
	// stw r10,14664(r3)
	REX_STORE_U32(ctx.r3.u32 + 14664, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272BC60:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-18456
	ctx.r10.s64 = ctx.r11.s64 + -18456;
	// stw r10,14664(r3)
	REX_STORE_U32(ctx.r3.u32 + 14664, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272BC74:
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8272bc8c
	if (ctx.cr6.eq) goto loc_8272BC8C;
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x8272bc8c
	if (ctx.cr6.eq) goto loc_8272BC8C;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8272bc28
	if (!ctx.cr6.eq) goto loc_8272BC28;
loc_8272BC8C:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-7680
	ctx.r10.s64 = ctx.r11.s64 + -7680;
	// stw r10,14660(r3)
	REX_STORE_U32(ctx.r3.u32 + 14660, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272BCA0:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// bne cr6,0x8272bc28
	if (!ctx.cr6.eq) goto loc_8272BC28;
	// lis r11,12889
	ctx.r11.s64 = 844693504;
	// ori r8,r11,21849
	ctx.r8.u64 = ctx.r11.u64 | 21849;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8272bccc
	if (!ctx.cr6.eq) goto loc_8272BCCC;
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-19640
	ctx.r10.s64 = ctx.r11.s64 + -19640;
	// stw r10,14664(r3)
	REX_STORE_U32(ctx.r3.u32 + 14664, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8272BCCC:
	// lis r11,12338
	ctx.r11.s64 = 808583168;
	// ori r8,r11,13385
	ctx.r8.u64 = ctx.r11.u64 | 13385;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8272bcf4
	if (ctx.cr6.eq) goto loc_8272BCF4;
	// lis r11,22101
	ctx.r11.s64 = 1448411136;
	// ori r8,r11,22857
	ctx.r8.u64 = ctx.r11.u64 | 22857;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8272bcf4
	if (ctx.cr6.eq) goto loc_8272BCF4;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x8272bc28
	if (!ctx.cr6.eq) goto loc_8272BC28;
loc_8272BCF4:
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// addi r10,r11,-9408
	ctx.r10.s64 = ctx.r11.s64 + -9408;
	// stw r10,14660(r3)
	REX_STORE_U32(ctx.r3.u32 + 14660, ctx.r10.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82734C60) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82734C68;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// not r11,r6
	ctx.r11.u64 = ~ctx.r6.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r26,r9
	ctx.r26.u64 = ctx.r9.u64;
	// rlwinm r24,r11,30,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// cmplwi cr6,r4,1088
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1088, ctx.xer);
	// bge cr6,0x82734ccc
	if (!ctx.cr6.lt) goto loc_82734CCC;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82734cac
	if (ctx.cr6.eq) goto loc_82734CAC;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,122
	ctx.r31.u64 = ctx.r31.u64 | 122;
	// b 0x82734d28
	goto loc_82734D28;
loc_82734CAC:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,1088
	ctx.r4.s64 = 1088;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82855cb4
	ctx.lr = 0x82734CBC;
	__imp__XamAlloc(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82734d18
	if (ctx.cr0.lt) goto loc_82734D18;
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82734cd0
	goto loc_82734CD0;
loc_82734CCC:
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82734CD0:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,0(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// addi r4,r11,-28808
	ctx.r4.s64 = ctx.r11.s64 + -28808;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82736ef8
	ctx.lr = 0x82734CF8;
	sub_82736EF8(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82734d18
	if (ctx.cr0.lt) goto loc_82734D18;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82737808
	ctx.lr = 0x82734D08;
	sub_82737808(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82734d18
	if (ctx.cr0.lt) goto loc_82734D18;
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
loc_82734D18:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82734d28
	if (ctx.cr6.eq) goto loc_82734D28;
	// bl 0x82855ca4
	ctx.lr = 0x82734D28;
	__imp__XamFree(ctx, base);
loc_82734D28:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736450) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855d14
	__imp__NetDll_XNetCleanup(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736468) {
	REX_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855d34
	__imp__NetDll_XNetRegisterKey(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827364B8) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855d74
	__imp__NetDll_XNetConnect(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736590) {
	REX_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855de4
	__imp__NetDll_XNetGetOpt(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736C70) {
	REX_FUNC_PROLOGUE();
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82736bc0
	sub_82736BC0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736CB0) {
	REX_FUNC_PROLOGUE();
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855e34
	__imp__NetDll_ioctlsocket(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736E18) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82736E20;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mr r24,r10
	ctx.r24.u64 = ctx.r10.u64;
	// rlwinm. r11,r7,0,25,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82736e5c
	if (ctx.cr0.eq) goto loc_82736E5C;
	// bl 0x82855964
	ctx.lr = 0x82736E50;
	__imp__KeGetCurrentProcessType(ctx, base);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x82736e5c
	if (!ctx.cr6.eq) goto loc_82736E5C;
	// ori r30,r30,16
	ctx.r30.u64 = ctx.r30.u64 | 16;
loc_82736E5C:
	// lwz r11,252(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 252);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,260(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 260);
	// li r7,1
	ctx.r7.s64 = 1;
	// lwz r8,244(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 244);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r5,284(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// addi r3,r31,52
	ctx.r3.s64 = ctx.r31.s64 + 52;
	// lwz r4,292(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// stw r29,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r29.u32);
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// stw r27,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r27.u32);
	// stw r5,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// stw r4,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r4.u32);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// stw r26,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r26.u32);
	// stw r25,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r25.u32);
	// stw r11,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r11.u32);
	// stw r10,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// stw r9,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r9.u32);
	// stw r24,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r24.u32);
	// stw r8,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
	// lwz r5,276(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// bl 0x827378a8
	ctx.lr = 0x82736EC0;
	sub_827378A8(ctx, base);
	// lwz r11,300(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r11.u32);
	// beq cr6,0x82736eec
	if (ctx.cr6.eq) goto loc_82736EEC;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82736ee0
	if (ctx.cr6.eq) goto loc_82736EE0;
	// bl 0x82748a60
	ctx.lr = 0x82736EE0;
	sub_82748A60(ctx, base);
loc_82736EE0:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r10,997
	ctx.r10.s64 = 997;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82736EEC:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(__savegprlr_19) {
	REX_FUNC_PROLOGUE();
	// std r19,-112(r1)
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.r19.u64);
	// std r20,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.r20.u64);
	// std r21,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.r21.u64);
	// std r22,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.r22.u64);
	// std r23,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.r23.u64);
	// std r24,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.r24.u64);
	// std r25,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.r25.u64);
	// std r26,-56(r1)
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.r26.u64);
	// std r27,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r27.u64);
	// std r28,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.r28.u64);
	// std r29,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r29.u64);
	// std r30,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r30.u64);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8273A030) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r3,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r3.u64);
	// clrlwi r6,r3,29
	ctx.r6.u64 = ctx.r3.u32 & 0x7;
	// dcbt r0,r4
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,8
	ctx.xer.ca = ctx.r6.u32 <= 8;
	ctx.r6.u64 = static_cast<uint64_t>(8) - ctx.r6.u64;
	// beq 0x8273a094
	if (ctx.cr0.eq) goto loc_8273A094;
	// cmplw r5,r6
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, ctx.r6.u32, ctx.xer);
	// ble 0x8273a0b0
	if (!ctx.cr0.gt) goto loc_8273A0B0;
	// cmplwi r6,4
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// beq 0x8273a080
	if (ctx.cr0.eq) goto loc_8273A080;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// subf r5,r6,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r6.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A068:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	REX_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a068
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A068;
	// addi r3,r3,1
	ctx.r3.s64 = ctx.r3.s64 + 1;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// b 0x8273a094
	goto loc_8273A094;
loc_8273A080:
	// subf r5,r6,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r6.u64;
	// lwz r6,0(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// stw r6,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
loc_8273A094:
	// clrlwi r6,r4,29
	ctx.r6.u64 = ctx.r4.u32 & 0x7;
	// cmplwi cr6,r6,4
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// cmplwi cr1,r6,0
	ctx.cr1.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// cmplwi cr7,r5,128
	ctx.cr7.compare<uint32_t>(ctx.r5.u32, 128, ctx.xer);
	// beq cr6,0x8273a278
	if (ctx.cr6.eq) goto loc_8273A278;
	// bne cr1,0x8273a3a8
	if (!ctx.cr1.eq) goto loc_8273A3A8;
	// bge cr7,0x8273a14c
	if (!ctx.cr7.lt) goto loc_8273A14C;
loc_8273A0B0:
	// dcbtst r0,r3
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
loc_8273A0BC:
	// rlwinm r7,r5,29,28,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 29) & 0xF;
	// clrlwi r6,r5,29
	ctx.r6.u64 = ctx.r5.u32 & 0x7;
	// cmplwi cr1,r7,0
	ctx.cr1.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr1,0x8273a0e0
	if (ctx.cr1.eq) goto loc_8273A0E0;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8273A0D4:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	REX_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a0d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A0D4;
loc_8273A0E0:
	// cmplwi cr1,r6,4
	ctx.cr1.compare<uint32_t>(ctx.r6.u32, 4, ctx.xer);
	// beq cr6,0x8273a104
	if (ctx.cr6.eq) goto loc_8273A104;
	// beq cr1,0x8273a10c
	if (ctx.cr1.eq) goto loc_8273A10C;
	// addi r3,r3,7
	ctx.r3.s64 = ctx.r3.s64 + 7;
	// addi r4,r4,7
	ctx.r4.s64 = ctx.r4.s64 + 7;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A0F8:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a0f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A0F8;
loc_8273A104:
	// ld r3,-8(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8273A10C:
	// clrlwi r6,r3,30
	ctx.r6.u64 = ctx.r3.u32 & 0x3;
	// lwz r5,8(r4)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// bne 0x8273a128
	if (!ctx.cr0.eq) goto loc_8273A128;
	// stw r5,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r5.u32);
	// ld r3,-8(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8273A128:
	// lbz r8,8(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 8);
	// lbz r7,9(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 9);
	// lbz r6,10(r4)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r4.u32 + 10);
	// stb r8,8(r3)
	REX_STORE_U8(ctx.r3.u32 + 8, ctx.r8.u8);
	// stb r7,9(r3)
	REX_STORE_U8(ctx.r3.u32 + 9, ctx.r7.u8);
	// stb r6,10(r3)
	REX_STORE_U8(ctx.r3.u32 + 10, ctx.r6.u8);
	// stb r5,11(r3)
	REX_STORE_U8(ctx.r3.u32 + 11, ctx.r5.u8);
	// ld r3,-8(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8273A14C:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-8
	ctx.r3.s64 = ctx.r3.s64 + -8;
	// addi r4,r4,-8
	ctx.r4.s64 = ctx.r4.s64 + -8;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.u64 = static_cast<uint64_t>(128) - ctx.r6.u64;
	// beq 0x8273a17c
	if (ctx.cr0.eq) goto loc_8273A17C;
	// rlwinm r7,r6,29,3,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 29) & 0x1FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r6.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8273A170:
	// ldu r7,8(r4)
	ea = 8 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// stdu r7,8(r3)
	ea = 8 + ctx.r3.u32;
	REX_STORE_U64(ea, ctx.r7.u64);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a170
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A170;
loc_8273A17C:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8273a0bc
	if (ctx.cr0.eq) goto loc_8273A0BC;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,8
	ctx.r9.s64 = 8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8273A1AC:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8273a1ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A1AC;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	ctx.r11.u64 = ctx.r12.u64 - ctx.r9.u64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A1CC:
	// ld r6,8(r4)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r4.u32 + 8);
	// ld r7,16(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 16);
	// ld r8,24(r4)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r4.u32 + 24);
	// std r6,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r6.u64);
	// ld r6,32(r4)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r4.u32 + 32);
	// std r7,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r7.u64);
	// ld r7,40(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 40);
	// std r8,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r8.u64);
	// ld r8,48(r4)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r4.u32 + 48);
	// std r6,32(r3)
	REX_STORE_U64(ctx.r3.u32 + 32, ctx.r6.u64);
	// ld r6,56(r4)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r4.u32 + 56);
	// std r7,40(r3)
	REX_STORE_U64(ctx.r3.u32 + 40, ctx.r7.u64);
	// ld r7,64(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 64);
	// std r8,48(r3)
	REX_STORE_U64(ctx.r3.u32 + 48, ctx.r8.u64);
	// ld r8,72(r4)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r4.u32 + 72);
	// std r6,56(r3)
	REX_STORE_U64(ctx.r3.u32 + 56, ctx.r6.u64);
	// ld r6,80(r4)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r4.u32 + 80);
	// std r7,64(r3)
	REX_STORE_U64(ctx.r3.u32 + 64, ctx.r7.u64);
	// ld r7,88(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 88);
	// std r8,72(r3)
	REX_STORE_U64(ctx.r3.u32 + 72, ctx.r8.u64);
	// ld r8,96(r4)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r4.u32 + 96);
	// std r6,80(r3)
	REX_STORE_U64(ctx.r3.u32 + 80, ctx.r6.u64);
	// ld r6,104(r4)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r4.u32 + 104);
	// std r7,88(r3)
	REX_STORE_U64(ctx.r3.u32 + 88, ctx.r7.u64);
	// ld r7,112(r4)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r4.u32 + 112);
	// std r8,96(r3)
	REX_STORE_U64(ctx.r3.u32 + 96, ctx.r8.u64);
	// ld r8,120(r4)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r4.u32 + 120);
	// std r6,104(r3)
	REX_STORE_U64(ctx.r3.u32 + 104, ctx.r6.u64);
	// ldu r6,128(r4)
	ea = 128 + ctx.r4.u32;
	ctx.r6.u64 = REX_LOAD_U64(ea);
	ctx.r4.u32 = ea;
	// std r7,112(r3)
	REX_STORE_U64(ctx.r3.u32 + 112, ctx.r7.u64);
	// std r8,120(r3)
	REX_STORE_U64(ctx.r3.u32 + 120, ctx.r8.u64);
	// stdu r6,128(r3)
	ea = 128 + ctx.r3.u32;
	REX_STORE_U64(ea, ctx.r6.u64);
	ctx.r3.u32 = ea;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8273a260
	if (!ctx.cr0.lt) goto loc_8273A260;
	// dcbt r9,r4
	// bdnz 0x8273a1cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A1CC;
	// b 0x8273a0bc
	goto loc_8273A0BC;
loc_8273A260:
	// beq cr1,0x8273a270
	if (ctx.cr1.eq) goto loc_8273A270;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8273A270:
	// bdnz 0x8273a1cc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A1CC;
	// b 0x8273a0bc
	goto loc_8273A0BC;
loc_8273A278:
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// bge cr7,0x8273a2d0
	if (!ctx.cr7.lt) goto loc_8273A2D0;
	// dcbtst r0,r3
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
loc_8273A288:
	// rlwinm r7,r5,30,27,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x1F;
	// clrlwi r6,r5,30
	ctx.r6.u64 = ctx.r5.u32 & 0x3;
	// cmplwi cr1,r7,0
	ctx.cr1.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr1,0x8273a2ac
	if (ctx.cr1.eq) goto loc_8273A2AC;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8273A2A0:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a2a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A2A0;
loc_8273A2AC:
	// beq cr6,0x8273a2c8
	if (ctx.cr6.eq) goto loc_8273A2C8;
	// addi r3,r3,3
	ctx.r3.s64 = ctx.r3.s64 + 3;
	// addi r4,r4,3
	ctx.r4.s64 = ctx.r4.s64 + 3;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A2BC:
	// lbzu r7,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r7,1(r3)
	ea = 1 + ctx.r3.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a2bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A2BC;
loc_8273A2C8:
	// ld r3,-8(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8273A2D0:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.u64 = static_cast<uint64_t>(128) - ctx.r6.u64;
	// beq 0x8273a2fc
	if (ctx.cr0.eq) goto loc_8273A2FC;
	// rlwinm r7,r6,30,2,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 30) & 0x3FFFFFFF;
	// subf r5,r6,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r6.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_8273A2F0:
	// lwzu r7,4(r4)
	ea = 4 + ctx.r4.u32;
	ctx.r7.u64 = REX_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stwu r7,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a2f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A2F0;
loc_8273A2FC:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8273a288
	if (ctx.cr0.eq) goto loc_8273A288;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,4
	ctx.r9.s64 = 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8273A32C:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8273a32c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A32C;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// subf r11,r9,r12
	ctx.r11.u64 = ctx.r12.u64 - ctx.r9.u64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A34C:
	// li r6,8
	ctx.r6.s64 = 8;
loc_8273A350:
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// lwz r0,4(r4)
	ctx.r0.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// lwz r7,8(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// lwz r8,12(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r0,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r0.u32);
	// lwzu r0,16(r4)
	ea = 16 + ctx.r4.u32;
	ctx.r0.u64 = REX_LOAD_U32(ea);
	ctx.r4.u32 = ea;
	// stw r7,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r7.u32);
	// stw r8,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// stwu r0,16(r3)
	ea = 16 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r0.u32);
	ctx.r3.u32 = ea;
	// bne 0x8273a350
	if (!ctx.cr0.eq) goto loc_8273A350;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8273a390
	if (!ctx.cr0.lt) goto loc_8273A390;
	// dcbt r9,r4
	// bdnz 0x8273a34c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A34C;
	// b 0x8273a288
	goto loc_8273A288;
loc_8273A390:
	// beq cr1,0x8273a3a0
	if (ctx.cr1.eq) goto loc_8273A3A0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8273A3A0:
	// bdnz 0x8273a34c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A34C;
	// b 0x8273a288
	goto loc_8273A288;
loc_8273A3A8:
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// bge cr7,0x8273a3dc
	if (!ctx.cr7.lt) goto loc_8273A3DC;
	// dcbtst r0,r3
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_8273A3B8:
	// clrlwi r6,r5,25
	ctx.r6.u64 = ctx.r5.u32 & 0x7F;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// beq 0x8273a3d4
	if (ctx.cr0.eq) goto loc_8273A3D4;
loc_8273A3C8:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	REX_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a3c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A3C8;
loc_8273A3D4:
	// ld r3,-8(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_8273A3DC:
	// clrlwi r6,r3,25
	ctx.r6.u64 = ctx.r3.u32 & 0x7F;
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// subfic r6,r6,128
	ctx.xer.ca = ctx.r6.u32 <= 128;
	ctx.r6.u64 = static_cast<uint64_t>(128) - ctx.r6.u64;
	// beq 0x8273a404
	if (ctx.cr0.eq) goto loc_8273A404;
	// subf r5,r6,r5
	ctx.r5.u64 = ctx.r5.u64 - ctx.r6.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A3F8:
	// lbzu r6,1(r4)
	ea = 1 + ctx.r4.u32;
	ctx.r6.u64 = REX_LOAD_U8(ea);
	ctx.r4.u32 = ea;
	// stbu r6,1(r3)
	ea = 1 + ctx.r3.u32;
	REX_STORE_U8(ea, ctx.r6.u8);
	ctx.r3.u32 = ea;
	// bdnz 0x8273a3f8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A3F8;
loc_8273A404:
	// rlwinm r6,r5,25,7,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq 0x8273a3b8
	if (ctx.cr0.eq) goto loc_8273A3B8;
	// addi r10,r5,127
	ctx.r10.s64 = ctx.r5.s64 + 127;
	// clrlwi r8,r5,25
	ctx.r8.u64 = ctx.r5.u32 & 0x7F;
	// rlwinm r10,r10,25,7,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 25) & 0x1FFFFFF;
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r10,r10,29
	ctx.r10.u64 = ctx.r10.u32 & 0x7;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// li r9,1
	ctx.r9.s64 = 1;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8273A434:
	// dcbt r9,r4
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// bdnz 0x8273a434
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A434;
	// add r12,r4,r5
	ctx.r12.u64 = ctx.r4.u64 + ctx.r5.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// subf r11,r9,r12
	ctx.r11.u64 = ctx.r12.u64 - ctx.r9.u64;
	// add r12,r3,r5
	ctx.r12.u64 = ctx.r3.u64 + ctx.r5.u64;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8273A454:
	// li r6,32
	ctx.r6.s64 = 32;
loc_8273A458:
	// lbz r7,4(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + 4);
	// lbz r8,3(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// addi r6,r6,-1
	ctx.r6.s64 = ctx.r6.s64 + -1;
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,2(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi r6,0
	ctx.cr0.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,1(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// stw r7,1(r3)
	REX_STORE_U32(ctx.r3.u32 + 1, ctx.r7.u32);
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// bne 0x8273a458
	if (!ctx.cr0.eq) goto loc_8273A458;
	// cmplw r4,r11
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge 0x8273a4a0
	if (!ctx.cr0.lt) goto loc_8273A4A0;
	// dcbt r9,r4
	// bdnz 0x8273a454
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A454;
	// b 0x8273a3b8
	goto loc_8273A3B8;
loc_8273A4A0:
	// beq cr1,0x8273a4b0
	if (ctx.cr1.eq) goto loc_8273A4B0;
	// li r8,-1
	ctx.r8.s64 = -1;
	// dcbtst r8,r12
	// cmplwi cr1,r8,0
	ctx.cr1.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
loc_8273A4B0:
	// bdnz 0x8273a454
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273A454;
	// b 0x8273a3b8
	goto loc_8273A3B8;
}

DEFINE_REX_FUNC(sub_8273C1B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x8273c1dc
	if (!ctx.cr6.eq) goto loc_8273C1DC;
loc_8273C1D0:
	// bl 0x8273dc40
	ctx.lr = 0x8273C1D4;
	sub_8273DC40(ctx, base);
	// li r11,22
	ctx.r11.s64 = 22;
	// b 0x8273c228
	goto loc_8273C228;
loc_8273C1DC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8273c1d0
	if (ctx.cr6.eq) goto loc_8273C1D0;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8273c1d0
	if (ctx.cr6.eq) goto loc_8273C1D0;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// lis r11,-32140
	ctx.r11.s64 = -2106327040;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r11,9936
	ctx.r3.s64 = ctx.r11.s64 + 9936;
	// bl 0x8273c098
	ctx.lr = 0x8273C208;
	sub_8273C098(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x8273c218
	if (!ctx.cr0.lt) goto loc_8273C218;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r11.u8);
loc_8273C218:
	// cmpwi cr6,r3,-2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -2, ctx.xer);
	// bne cr6,0x8273c248
	if (!ctx.cr6.eq) goto loc_8273C248;
	// bl 0x8273dc40
	ctx.lr = 0x8273C224;
	sub_8273DC40(ctx, base);
	// li r11,34
	ctx.r11.s64 = 34;
loc_8273C228:
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x8273db00
	ctx.lr = 0x8273C244;
	sub_8273DB00(ctx, base);
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8273C248:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8273D8A0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r10,-7752
	ctx.r9.s64 = ctx.r10.s64 + -7752;
	// mr r10,r9
	ctx.r10.u64 = ctx.r9.u64;
loc_8273D8B0:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmpw cr6,r3,r8
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r8.s32, ctx.xer);
	// beq cr6,0x8273d8cc
	if (ctx.cr6.eq) goto loc_8273D8CC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r11,23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 23, ctx.xer);
	// blt cr6,0x8273d8b0
	if (ctx.cr6.lt) goto loc_8273D8B0;
loc_8273D8CC:
	// cmplwi cr6,r11,23
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 23, ctx.xer);
	// bgelr cr6
	if (!ctx.cr6.lt) return;
	// rlwinm r11,r11,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r9,4
	ctx.r10.s64 = ctx.r9.s64 + 4;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x827484b0
	sub_827484B0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8273F7B0) {
	REX_FUNC_PROLOGUE();
	// mffs f0
	ctx.f0.u64 = ctx.fpscr.loadFromHost();
	// li r3,4
	ctx.r3.s64 = 4;
	// stfd f0,-8(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.f0.u64);
	// lwz r5,-4(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + -4);
	// and r5,r3,r5
	ctx.r5.u64 = ctx.r3.u64 & ctx.r5.u64;
	// stw r5,-4(r1)
	REX_STORE_U32(ctx.r1.u32 + -4, ctx.r5.u32);
	// lfd f1,-8(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// mtfsf 255,f1
	ctx.fpscr.storeFromGuest(ctx.f1.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827414E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x827414F0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// addi r30,r10,-6648
	ctx.r30.s64 = ctx.r10.s64 + -6648;
	// addi r28,r11,-28608
	ctx.r28.s64 = ctx.r11.s64 + -28608;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8274150C:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82741534
	if (!ctx.cr6.eq) goto loc_82741534;
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// rotlwi r3,r28,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r28.u32, 0);
	// li r4,4000
	ctx.r4.s64 = 4000;
	// addi r28,r28,28
	ctx.r28.s64 = ctx.r28.s64 + 28;
	// bl 0x82741a70
	ctx.lr = 0x8274152C;
	sub_82741A70(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82741554
	if (ctx.cr0.eq) goto loc_82741554;
loc_82741534:
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// addi r11,r30,288
	ctx.r11.s64 = ctx.r30.s64 + 288;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8274150c
	if (ctx.cr6.lt) goto loc_8274150C;
	// li r3,1
	ctx.r3.s64 = 1;
loc_8274154C:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
loc_82741554:
	// rlwinm r11,r29,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stwx r10,r11,r30
	REX_STORE_U32(ctx.r11.u32 + ctx.r30.u32, ctx.r10.u32);
	// b 0x8274154c
	goto loc_8274154C;
}

DEFINE_REX_FUNC(sub_827449B0) {
	REX_FUNC_PROLOGUE();
	// li r3,1
	ctx.r3.s64 = 1;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82744D10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-96(r1)
	ea = -96 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r3,4096
	ctx.r3.s64 = 4096;
	// lwz r11,-28648(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + -28648);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,-28648(r10)
	REX_STORE_U32(ctx.r10.u32 + -28648, ctx.r11.u32);
	// bl 0x8273c6c0
	ctx.lr = 0x82744D3C;
	sub_8273C6C0(ctx, base);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// beq 0x82744d5c
	if (ctx.cr0.eq) goto loc_82744D5C;
	// li r10,4096
	ctx.r10.s64 = 4096;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// b 0x82744d70
	goto loc_82744D70;
loc_82744D5C:
	// addi r10,r31,20
	ctx.r10.s64 = ctx.r31.s64 + 20;
	// li r9,2
	ctx.r9.s64 = 2;
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r9,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r9.u32);
loc_82744D70:
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82749360) {
	REX_FUNC_PROLOGUE();
	// twi 31,r0,20
	ppc_trap(ctx, base, 20);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82749AC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// cntlzw r11,r5
	ctx.r11.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r11,r11,27,5,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7FFFFFF;
	// xori r9,r11,1
	ctx.r9.u64 = ctx.r11.u64 ^ 1;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r11,r10,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r10.u64;
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subf r10,r10,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r10.u64;
	// addi r11,r11,32
	ctx.r11.s64 = ctx.r11.s64 + 32;
	// addi r10,r10,32
	ctx.r10.s64 = ctx.r10.s64 + 32;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// blt cr6,0x82749b04
	if (ctx.cr6.lt) goto loc_82749B04;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82749B04:
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// rlwinm r10,r11,1,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1;
	// addme r10,r10
	temp.u8 = (ctx.r10.u32 + 0xFFFFFFFFu < ctx.r10.u32) | (ctx.r10.u32 + 0xFFFFFFFFu + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ctx.r10.u64 + ctx.xer.ca + 0xFFFFFFFFFFFFFFFFull;
	ctx.xer.ca = temp.u8;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8274BFF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// subf r9,r9,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r9.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8274C00C:
	// lwzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// addic r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x8274c00c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8274C00C;
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r9,r1,-16
	ctx.r9.s64 = ctx.r1.s64 + -16;
	// lvrx128 v63,r10,r11
	temp.u32 = ctx.r10.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// lvlx128 v62,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// vor128 v1,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82751FC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82751FC8;
	__savegprlr_14(ctx, base);
	// stfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -176, ctx.f29.u64);
	// stfd f30,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.f30.u64);
	// stfd f31,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// not r8,r11
	ctx.r8.u64 = ~ctx.r11.u64;
	// not r7,r11
	ctx.r7.u64 = ~ctx.r11.u64;
	// stw r22,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r22.u32);
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// rlwinm r5,r8,16,31,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 16) & 0x1;
	// lwz r4,104(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 104);
	// mr r20,r22
	ctx.r20.u64 = ctx.r22.u64;
	// lwz r3,104(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 104);
	// mr r18,r22
	ctx.r18.u64 = ctx.r22.u64;
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
	// mr r29,r22
	ctx.r29.u64 = ctx.r22.u64;
	// rlwinm r31,r7,15,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 15) & 0x1;
	// rlwinm r30,r11,14,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 14) & 0x1;
	// bl 0x82751c50
	ctx.lr = 0x82752024;
	sub_82751C50(ctx, base);
	// mr. r16,r3
	ctx.r16.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r16.s32, 0, ctx.xer);
	// beq 0x8275274c
	if (ctx.cr0.eq) goto loc_8275274C;
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r4,108(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r3,108(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 108);
	// bl 0x82751c50
	ctx.lr = 0x82752044;
	sub_82751C50(ctx, base);
	// mr. r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq 0x8275274c
	if (ctx.cr0.eq) goto loc_8275274C;
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lwz r4,112(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// lwz r3,112(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 112);
	// bl 0x82751c50
	ctx.lr = 0x82752064;
	sub_82751C50(ctx, base);
	// mr. r18,r3
	ctx.r18.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r18.s32, 0, ctx.xer);
	// beq 0x8275274c
	if (ctx.cr0.eq) goto loc_8275274C;
	// lwz r8,4(r25)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// lis r9,5461
	ctx.r9.s64 = 357892096;
	// lwz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r16.u32 + 0);
	// li r30,-1
	ctx.r30.s64 = -1;
	// ori r7,r9,21845
	ctx.r7.u64 = ctx.r9.u64 | 21845;
	// lwz r10,0(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// lwz r9,0(r18)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r18.u32 + 0);
	// add r15,r11,r16
	ctx.r15.u64 = ctx.r11.u64 + ctx.r16.u64;
	// add r14,r10,r20
	ctx.r14.u64 = ctx.r10.u64 + ctx.r20.u64;
	// lwz r31,112(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + 112);
	// add r19,r9,r18
	ctx.r19.u64 = ctx.r9.u64 + ctx.r18.u64;
	// cmplw cr6,r31,r7
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r7.u32, ctx.xer);
	// mulli r11,r31,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r31.u64 * static_cast<uint64_t>(12));
	// ble cr6,0x827520a8
	if (!ctx.cr6.gt) goto loc_827520A8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_827520A8:
	// li r10,-5
	ctx.r10.s64 = -5;
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x827520bc
	if (!ctx.cr6.gt) goto loc_827520BC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_827520BC:
	// bl 0x825dfbe0
	ctx.lr = 0x827520C0;
	sub_825DFBE0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x827520fc
	if (ctx.cr0.eq) goto loc_827520FC;
	// addic. r11,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r11.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// addi r9,r3,4
	ctx.r9.s64 = ctx.r3.s64 + 4;
	// blt 0x827520f4
	if (ctx.cr0.lt) goto loc_827520F4;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_827520E4:
	// stw r22,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r22.u32);
	// stw r22,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r22.u32);
	// stwu r22,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r22.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x827520e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827520E4;
loc_827520F4:
	// mr r21,r9
	ctx.r21.u64 = ctx.r9.u64;
	// b 0x82752100
	goto loc_82752100;
loc_827520FC:
	// mr r21,r22
	ctx.r21.u64 = ctx.r22.u64;
loc_82752100:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82752740
	if (ctx.cr6.eq) goto loc_82752740;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// lis r10,4095
	ctx.r10.s64 = 268369920;
	// ori r17,r10,65535
	ctx.r17.u64 = ctx.r10.u64 | 65535;
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// cmplw cr6,r11,r17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r17.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x82752128
	if (!ctx.cr6.gt) goto loc_82752128;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82752128:
	// bl 0x825dfbe0
	ctx.lr = 0x8275212C;
	sub_825DFBE0(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r3,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82752740
	if (ctx.cr6.eq) goto loc_82752740;
	// addi r7,r18,4
	ctx.r7.s64 = ctx.r18.s64 + 4;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r19
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r19.u32, ctx.xer);
	// bge cr6,0x827521a4
	if (!ctx.cr6.lt) goto loc_827521A4;
loc_8275214C:
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r11,r10,4
	ctx.r11.s64 = ctx.r10.s64 + 4;
	// add r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bge cr6,0x82752198
	if (!ctx.cr6.lt) goto loc_82752198;
	// subf r9,r11,r8
	ctx.r9.u64 = ctx.r8.u64 - ctx.r11.u64;
	// addi r10,r11,-8
	ctx.r10.s64 = ctx.r11.s64 + -8;
	// addi r11,r9,-1
	ctx.r11.s64 = ctx.r9.s64 + -1;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
loc_82752178:
	// lwzu r11,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r21
	ctx.r11.u64 = ctx.r11.u64 + ctx.r21.u64;
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stw r9,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r9.u32);
	// bdnz 0x82752178
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82752178;
loc_82752198:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// cmplw cr6,r8,r19
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r19.u32, ctx.xer);
	// blt cr6,0x8275214c
	if (ctx.cr6.lt) goto loc_8275214C;
loc_827521A4:
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmplw cr6,r7,r19
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r19.u32, ctx.xer);
	// bge cr6,0x82752734
	if (!ctx.cr6.lt) goto loc_82752734;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lfs f29,2524(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f29.f64 = double(temp.f32);
	// lfs f31,5864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5864);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,8220(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 8220);
	ctx.f30.f64 = double(temp.f32);
loc_827521C8:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r24,r11,4
	ctx.r24.s64 = ctx.r11.s64 + 4;
	// add r23,r10,r11
	ctx.r23.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
	// cmplw cr6,r24,r23
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x82752278
	if (!ctx.cr6.lt) goto loc_82752278;
	// lwz r29,80(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_827521E4:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mulli r31,r11,12
	ctx.r31.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// lwzx r11,r31,r21
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8275226c
	if (!ctx.cr6.eq) goto loc_8275226C;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8275221c
	if (ctx.cr6.eq) goto loc_8275221C;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// stwx r11,r31,r21
	REX_STORE_U32(ctx.r31.u32 + ctx.r21.u32, ctx.r11.u32);
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// lwz r29,4(r29)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// stw r29,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r29.u32);
	// b 0x8275224c
	goto loc_8275224C;
loc_8275221C:
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// cmplw cr6,r11,r17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r17.u32, ctx.xer);
	// rlwinm r3,r11,4,0,27
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// ble cr6,0x8275223c
	if (!ctx.cr6.gt) goto loc_8275223C;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_8275223C:
	// bl 0x825dfbe0
	ctx.lr = 0x82752240;
	sub_825DFBE0(ctx, base);
	// stwx r3,r31,r21
	REX_STORE_U32(ctx.r31.u32 + ctx.r21.u32, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8275273c
	if (ctx.cr6.eq) goto loc_8275273C;
loc_8275224C:
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwzx r3,r31,r21
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r21.u32);
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mullw r11,r10,r11
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// rlwinm r5,r11,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// bl 0x8273a590
	ctx.lr = 0x8275226C;
	sub_8273A590(ctx, base);
loc_8275226C:
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// cmplw cr6,r30,r23
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x827521e4
	if (ctx.cr6.lt) goto loc_827521E4;
loc_82752278:
	// addi r30,r20,4
	ctx.r30.s64 = ctx.r20.s64 + 4;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplw cr6,r30,r14
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r14.u32, ctx.xer);
	// bge cr6,0x827523fc
	if (!ctx.cr6.lt) goto loc_827523FC;
	// addi r26,r16,4
	ctx.r26.s64 = ctx.r16.s64 + 4;
loc_8275228C:
	// lwz r3,0(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r29,r11,r30
	ctx.r29.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827522B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// cmplw cr6,r26,r15
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r15.u32, ctx.xer);
	// bge cr6,0x827523ec
	if (!ctx.cr6.lt) goto loc_827523EC;
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r8,r11,8
	ctx.r8.s64 = ctx.r11.s64 + 8;
loc_827522C8:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// cmplw cr6,r24,r23
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r23.u32, ctx.xer);
	// add r3,r11,r31
	ctx.r3.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bge cr6,0x827523dc
	if (!ctx.cr6.lt) goto loc_827523DC;
	// addi r28,r30,4
	ctx.r28.s64 = ctx.r30.s64 + 4;
loc_827522E0:
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// cmplw cr6,r28,r29
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r29.u32, ctx.xer);
	// bge cr6,0x827523d0
	if (!ctx.cr6.lt) goto loc_827523D0;
	// addi r4,r31,4
	ctx.r4.s64 = ctx.r31.s64 + 4;
loc_827522F0:
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// cmplw cr6,r4,r3
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r3.u32, ctx.xer);
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// mulli r10,r10,12
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(12));
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// lwzx r10,r10,r21
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r21.u32);
	// mullw r11,r11,r9
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bge cr6,0x827523c4
	if (!ctx.cr6.lt) goto loc_827523C4;
	// subf r9,r4,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r4.u64;
	// addi r11,r4,-8
	ctx.r11.s64 = ctx.r4.s64 + -8;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// rlwinm r9,r9,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82752334:
	// lfs f13,4(r5)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lfs f0,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f13,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f12,-8(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -8);
	ctx.f12.f64 = double(temp.f32);
	// lfsx f11,r9,r10
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// fmadds f13,f0,f12,f11
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f12.f64, ctx.f11.f64)));
	// stfsx f13,r9,r10
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + ctx.r10.u32, temp.u32);
	// lfs f13,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r9,4
	ctx.r7.s64 = ctx.r9.s64 + 4;
	// lfs f12,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f13,4(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// lwz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lfs f13,0(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r9,8
	ctx.r7.s64 = ctx.r9.s64 + 8;
	// lfs f12,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f13,8(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// lwzu r9,8(r11)
	ea = 8 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// lfs f13,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r7,r9,12
	ctx.r7.s64 = ctx.r9.s64 + 12;
	// lfs f12,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// bdnz 0x82752334
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82752334;
loc_827523C4:
	// addi r6,r6,8
	ctx.r6.s64 = ctx.r6.s64 + 8;
	// cmplw cr6,r6,r29
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r29.u32, ctx.xer);
	// blt cr6,0x827522f0
	if (ctx.cr6.lt) goto loc_827522F0;
loc_827523D0:
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// cmplw cr6,r5,r23
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x827522e0
	if (ctx.cr6.lt) goto loc_827522E0;
loc_827523DC:
	// addi r8,r8,16
	ctx.r8.s64 = ctx.r8.s64 + 16;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplw cr6,r3,r15
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r15.u32, ctx.xer);
	// blt cr6,0x827522c8
	if (ctx.cr6.lt) goto loc_827522C8;
loc_827523EC:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// cmplw cr6,r29,r14
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r14.u32, ctx.xer);
	// blt cr6,0x8275228c
	if (ctx.cr6.lt) goto loc_8275228C;
loc_827523FC:
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmplw cr6,r24,r23
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, ctx.r23.u32, ctx.xer);
	// bge cr6,0x8275271c
	if (!ctx.cr6.lt) goto loc_8275271C;
loc_82752408:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mulli r11,r11,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// add r30,r11,r21
	ctx.r30.u64 = ctx.r11.u64 + ctx.r21.u64;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// bne 0x82752710
	if (!ctx.cr0.eq) goto loc_82752710;
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82752704
	if (!ctx.cr6.gt) goto loc_82752704;
loc_82752438:
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mullw r9,r11,r31
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r31.s32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// beq cr6,0x827525fc
	if (ctx.cr6.eq) goto loc_827525FC;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// beq cr6,0x82752534
	if (ctx.cr6.eq) goto loc_82752534;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bne cr6,0x827526c0
	if (!ctx.cr6.eq) goto loc_827526C0;
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827526c0
	if (ctx.cr6.eq) goto loc_827526C0;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
loc_8275247C:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// bge cr6,0x82752490
	if (!ctx.cr6.lt) goto loc_82752490;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x8275249c
	goto loc_8275249C;
loc_82752490:
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// blt cr6,0x8275249c
	if (ctx.cr6.lt) goto loc_8275249C;
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
loc_8275249C:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x827524b4
	if (!ctx.cr6.lt) goto loc_827524B4;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x827524c8
	goto loc_827524C8;
loc_827524B4:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x827524c4
	if (!ctx.cr6.lt) goto loc_827524C4;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x827524c8
	goto loc_827524C8;
loc_827524C4:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_827524C8:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x827524e0
	if (!ctx.cr6.lt) goto loc_827524E0;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x827524f4
	goto loc_827524F4;
loc_827524E0:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x827524f0
	if (!ctx.cr6.lt) goto loc_827524F0;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x827524f4
	goto loc_827524F4;
loc_827524F0:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_827524F4:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,12(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x8275250c
	if (!ctx.cr6.lt) goto loc_8275250C;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x82752518
	goto loc_82752518;
loc_8275250C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x82752518
	if (ctx.cr6.lt) goto loc_82752518;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_82752518:
	// stfsu f0,16(r11)
	ctx.fpscr.disableFlushMode();
	ea = 16 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,104(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 104);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8275247c
	if (ctx.cr6.lt) goto loc_8275247C;
	// b 0x827526c0
	goto loc_827526C0;
loc_82752534:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827526c0
	if (ctx.cr6.eq) goto loc_827526C0;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
loc_82752544:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f30
	ctx.cr6.compare(ctx.f13.f64, ctx.f30.f64);
	// bge cr6,0x82752558
	if (!ctx.cr6.lt) goto loc_82752558;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x82752564
	goto loc_82752564;
loc_82752558:
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// blt cr6,0x82752564
	if (ctx.cr6.lt) goto loc_82752564;
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
loc_82752564:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x8275257c
	if (!ctx.cr6.lt) goto loc_8275257C;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x82752590
	goto loc_82752590;
loc_8275257C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8275258c
	if (!ctx.cr6.lt) goto loc_8275258C;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x82752590
	goto loc_82752590;
loc_8275258C:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_82752590:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x827525a8
	if (!ctx.cr6.lt) goto loc_827525A8;
	// fmr f13,f30
	ctx.f13.f64 = ctx.f30.f64;
	// b 0x827525bc
	goto loc_827525BC;
loc_827525A8:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x827525b8
	if (!ctx.cr6.lt) goto loc_827525B8;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x827525bc
	goto loc_827525BC;
loc_827525B8:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_827525BC:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,12(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x827525d4
	if (!ctx.cr6.lt) goto loc_827525D4;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x827525e0
	goto loc_827525E0;
loc_827525D4:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x827525e0
	if (ctx.cr6.lt) goto loc_827525E0;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_827525E0:
	// stfsu f0,16(r11)
	ctx.fpscr.disableFlushMode();
	ea = 16 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// lwz r9,104(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 104);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x82752544
	if (ctx.cr6.lt) goto loc_82752544;
	// b 0x827526c0
	goto loc_827526C0;
loc_827525FC:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827526c0
	if (ctx.cr6.eq) goto loc_827526C0;
	// addi r11,r9,-4
	ctx.r11.s64 = ctx.r9.s64 + -4;
loc_8275260C:
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f29
	ctx.cr6.compare(ctx.f13.f64, ctx.f29.f64);
	// bge cr6,0x82752620
	if (!ctx.cr6.lt) goto loc_82752620;
	// fmr f13,f29
	ctx.f13.f64 = ctx.f29.f64;
	// b 0x8275262c
	goto loc_8275262C;
loc_82752620:
	// fcmpu cr6,f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// blt cr6,0x8275262c
	if (ctx.cr6.lt) goto loc_8275262C;
	// fmr f13,f31
	ctx.f13.f64 = ctx.f31.f64;
loc_8275262C:
	// lfs f0,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82752644
	if (!ctx.cr6.lt) goto loc_82752644;
	// fmr f13,f29
	ctx.f13.f64 = ctx.f29.f64;
	// b 0x82752658
	goto loc_82752658;
loc_82752644:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82752654
	if (!ctx.cr6.lt) goto loc_82752654;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x82752658
	goto loc_82752658;
loc_82752654:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_82752658:
	// lfs f0,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,8(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x82752670
	if (!ctx.cr6.lt) goto loc_82752670;
	// fmr f13,f29
	ctx.f13.f64 = ctx.f29.f64;
	// b 0x82752684
	goto loc_82752684;
loc_82752670:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x82752680
	if (!ctx.cr6.lt) goto loc_82752680;
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// b 0x82752684
	goto loc_82752684;
loc_82752680:
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
loc_82752684:
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,12(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 12, temp.u32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// bge cr6,0x8275269c
	if (!ctx.cr6.lt) goto loc_8275269C;
	// fmr f0,f29
	ctx.f0.f64 = ctx.f29.f64;
	// b 0x827526a8
	goto loc_827526A8;
loc_8275269C:
	// fcmpu cr6,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// blt cr6,0x827526a8
	if (ctx.cr6.lt) goto loc_827526A8;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_827526A8:
	// stfsu f0,16(r11)
	ctx.fpscr.disableFlushMode();
	ea = 16 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// lwz r9,4(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,104(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 104);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x8275260c
	if (ctx.cr6.lt) goto loc_8275260C;
loc_827526C0:
	// lwz r3,4(r25)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r5,0(r29)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,104(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// mullw r9,r9,r31
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r31.s32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// rlwinm r11,r9,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x827526F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 4);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// lwz r10,108(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82752438
	if (ctx.cr6.lt) goto loc_82752438;
loc_82752704:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
loc_82752710:
	// addi r29,r29,8
	ctx.r29.s64 = ctx.r29.s64 + 8;
	// cmplw cr6,r29,r23
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r23.u32, ctx.xer);
	// blt cr6,0x82752408
	if (ctx.cr6.lt) goto loc_82752408;
loc_8275271C:
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// cmplw cr6,r23,r19
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r19.u32, ctx.xer);
	// blt cr6,0x827521c8
	if (ctx.cr6.lt) goto loc_827521C8;
	// lwz r29,84(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r22,0
	ctx.r22.s64 = 0;
loc_82752734:
	// mr r31,r22
	ctx.r31.u64 = ctx.r22.u64;
	// b 0x82752754
	goto loc_82752754;
loc_8275273C:
	// lwz r29,84(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
loc_82752740:
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,14
	ctx.r31.u64 = ctx.r31.u64 | 14;
	// b 0x82752754
	goto loc_82752754;
loc_8275274C:
	// lis r31,-32768
	ctx.r31.s64 = -2147483648;
	// ori r31,r31,16389
	ctx.r31.u64 = ctx.r31.u64 | 16389;
loc_82752754:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x82752768
	if (ctx.cr6.eq) goto loc_82752768;
	// li r4,3
	ctx.r4.s64 = 3;
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// bl 0x82751f40
	ctx.lr = 0x82752768;
	sub_82751F40(ctx, base);
loc_82752768:
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x825ac978
	ctx.lr = 0x82752770;
	sub_825AC978(ctx, base);
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// bl 0x825ac978
	ctx.lr = 0x82752778;
	sub_825AC978(ctx, base);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// bl 0x825ac978
	ctx.lr = 0x82752780;
	sub_825AC978(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x825ac978
	ctx.lr = 0x82752788;
	sub_825AC978(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825ac978
	ctx.lr = 0x82752790;
	sub_825AC978(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f29,-176(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -176);
	// lfd f30,-168(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// lfd f31,-160(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82785768) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r11,r11,-28936
	ctx.r11.s64 = ctx.r11.s64 + -28936;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82785C00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
loc_82785C00:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r4
	ea = ctx.r4.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r4
	ea = ctx.r4.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82785c00
	if (!ctx.cr0.eq) goto loc_82785C00;
	// stw r4,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r4.u32);
	// addi r11,r3,20
	ctx.r11.s64 = ctx.r3.s64 + 20;
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r4,240
	ctx.r10.s64 = ctx.r4.s64 + 240;
	// lwz r8,24(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// stw r8,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r8.u32);
	// lwz r9,24(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// stw r11,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// stw r11,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r11.u32);
	// stw r10,20(r3)
	REX_STORE_U32(ctx.r3.u32 + 20, ctx.r10.u32);
	// lwz r10,244(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 244);
	// stw r10,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r10.u32);
	// lwz r10,244(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 244);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,244(r4)
	REX_STORE_U32(ctx.r4.u32 + 244, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82788388) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739eec
	ctx.lr = 0x82788390;
	__savegprlr_17(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,92(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// li r18,0
	ctx.r18.s64 = 0;
	// addi r21,r3,28
	ctx.r21.s64 = ctx.r3.s64 + 28;
	// rlwinm r11,r11,0,3,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFF9FFFFFFF;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r11.u32);
	// mr r17,r4
	ctx.r17.u64 = ctx.r4.u64;
	// stw r18,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r18.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmplw cr6,r11,r21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r21.u32, ctx.xer);
	// beq cr6,0x82788688
	if (ctx.cr6.eq) goto loc_82788688;
	// mr r19,r11
	ctx.r19.u64 = ctx.r11.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82788688
	if (ctx.cr0.eq) goto loc_82788688;
	// lis r11,4626
	ctx.r11.s64 = 303169536;
	// lis r10,13364
	ctx.r10.s64 = 875823104;
	// li r20,1
	ctx.r20.s64 = 1;
	// ori r22,r11,4626
	ctx.r22.u64 = ctx.r11.u64 | 4626;
	// ori r23,r10,13364
	ctx.r23.u64 = ctx.r10.u64 | 13364;
loc_827883E0:
	// lwz r11,0(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// addi r31,r19,-4
	ctx.r31.s64 = ctx.r19.s64 + -4;
	// lwz r10,20(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 20);
	// subf r9,r11,r21
	ctx.r9.u64 = ctx.r21.u64 - ctx.r11.u64;
	// lwz r8,16(r29)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// subfic r9,r9,0
	ctx.xer.ca = ctx.r9.u32 <= 0;
	ctx.r9.u64 = static_cast<uint64_t>(0) - ctx.r9.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// subfe r10,r9,r9
	temp.u8 = (~ctx.r9.u32 + ctx.r9.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r9.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r9.u64 + ctx.r9.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r19,r10,r11
	ctx.r19.u64 = ctx.r10.u64 & ctx.r11.u64;
	// bne cr6,0x82788680
	if (!ctx.cr6.eq) goto loc_82788680;
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8278841c
	if (!ctx.cr6.eq) goto loc_8278841C;
	// stw r20,0(r17)
	REX_STORE_U32(ctx.r17.u32 + 0, ctx.r20.u32);
	// b 0x82788680
	goto loc_82788680;
loc_8278841C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8278841c
	if (!ctx.cr0.eq) goto loc_8278841C;
	// lwz r10,16(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// addi r27,r31,112
	ctx.r27.s64 = ctx.r31.s64 + 112;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// mr r28,r20
	ctx.r28.u64 = ctx.r20.u64;
	// lwz r25,40(r31)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// addi r10,r25,28
	ctx.r10.s64 = ctx.r25.s64 + 28;
	// cntlzw r9,r11
	ctx.r9.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm. r24,r9,27,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// add r26,r11,r31
	ctx.r26.u64 = ctx.r11.u64 + ctx.r31.u64;
	// bne 0x827884c0
	if (!ctx.cr0.eq) goto loc_827884C0;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// li r28,2
	ctx.r28.s64 = 2;
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x827884c0
	if (!ctx.cr6.eq) goto loc_827884C0;
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82788698
	if (!ctx.cr6.eq) goto loc_82788698;
	// addic. r11,r11,1
	ctx.xer.ca = ctx.r11.u32 > 4294967294;
	ctx.r11.s64 = ctx.r11.s64 + 1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// bne 0x8278849c
	if (!ctx.cr0.eq) goto loc_8278849C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
loc_8278849C:
	// stw r23,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r23.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827884B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82788628
	if (!ctx.cr0.eq) goto loc_82788628;
loc_827884C0:
	// mr r8,r18
	ctx.r8.u64 = ctx.r18.u64;
	// cmplw cr6,r28,r25
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x82788578
	if (!ctx.cr6.lt) goto loc_82788578;
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r28,r25
	ctx.r7.u64 = ctx.r25.u64 - ctx.r28.u64;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_827884E0:
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpw cr6,r7,r22
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x827884f0
	if (!ctx.cr6.eq) goto loc_827884F0;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
loc_827884F0:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x827884e0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827884E0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82788578
	if (ctx.cr6.eq) goto loc_82788578;
	// stw r8,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
loc_82788504:
	// mfmsr r8
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r8.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r9,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r9.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stwcx. r9,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r9.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r8,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r8.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82788504
	if (!ctx.cr0.eq) goto loc_82788504;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// mr r26,r10
	ctx.r26.u64 = ctx.r10.u64;
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
loc_8278852C:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x82788560
	if (!ctx.cr6.eq) goto loc_82788560;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82788558;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82788628
	if (!ctx.cr0.eq) goto loc_82788628;
loc_82788560:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmplw cr6,r28,r25
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x8278852c
	if (ctx.cr6.lt) goto loc_8278852C;
	// b 0x82788674
	goto loc_82788674;
loc_82788578:
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// lwz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// cmpw cr6,r10,r22
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x827885f4
	if (!ctx.cr6.eq) goto loc_827885F4;
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// beq cr6,0x827885a4
	if (ctx.cr6.eq) goto loc_827885A4;
	// stw r23,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r23.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82786bb8
	ctx.lr = 0x827885A0;
	sub_82786BB8(ctx, base);
	// b 0x82788620
	goto loc_82788620;
loc_827885A4:
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// cmpw cr6,r11,r22
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r22.s32, ctx.xer);
	// bne cr6,0x82788674
	if (!ctx.cr6.eq) goto loc_82788674;
	// stw r23,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r23.u32);
	// stw r20,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r20.u32);
loc_827885B8:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x827885b8
	if (!ctx.cr0.eq) goto loc_827885B8;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x827885F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82788620
	goto loc_82788620;
loc_827885F4:
	// stw r23,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r23.u32);
	// lwz r6,-4(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// cmpw cr6,r6,r23
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r23.s32, ctx.xer);
	// beq cr6,0x82788674
	if (ctx.cr6.eq) goto loc_82788674;
	// stw r23,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r23.u32);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// beq cr6,0x82788638
	if (ctx.cr6.eq) goto loc_82788638;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// bl 0x82787510
	ctx.lr = 0x82788620;
	sub_82787510(ctx, base);
loc_82788620:
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82788674
	if (ctx.cr0.eq) goto loc_82788674;
loc_82788628:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82786970
	ctx.lr = 0x82788634;
	sub_82786970(ctx, base);
	// b 0x8278868c
	goto loc_8278868C;
loc_82788638:
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r5,0(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// stw r18,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r18.u32);
	// bl 0x82786ea8
	ctx.lr = 0x8278864C;
	sub_82786EA8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82788628
	if (!ctx.cr0.eq) goto loc_82788628;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82788674
	if (ctx.cr6.eq) goto loc_82788674;
	// lwz r11,0(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// subf r10,r11,r21
	ctx.r10.u64 = ctx.r21.u64 - ctx.r11.u64;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r19,r10,r11
	ctx.r19.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_82788674:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82786970
	ctx.lr = 0x82788680;
	sub_82786970(ctx, base);
loc_82788680:
	// cmplwi cr6,r19,0
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, 0, ctx.xer);
	// bne cr6,0x827883e0
	if (!ctx.cr6.eq) goto loc_827883E0;
loc_82788688:
	// mr r30,r18
	ctx.r30.u64 = ctx.r18.u64;
loc_8278868C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f3c
	__restgprlr_17(ctx, base);
	return;
loc_82788698:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r31
	ea = ctx.r31.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r31
	ea = ctx.r31.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82788698
	if (!ctx.cr0.eq) goto loc_82788698;
	// b 0x82788688
	goto loc_82788688;
}

DEFINE_REX_FUNC(sub_8279D280) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8279D288;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r26,r3,232
	ctx.r26.s64 = ctx.r3.s64 + 232;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x82855b44
	ctx.lr = 0x8279D2AC;
	__imp__RtlEnterCriticalSection(ctx, base);
	// li r5,8
	ctx.r5.s64 = 8;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82639688
	ctx.lr = 0x8279D2BC;
	sub_82639688(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x8279ca18
	ctx.lr = 0x8279D2C8;
	sub_8279CA18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8279d2dc
	if (!ctx.cr0.eq) goto loc_8279D2DC;
	// lis r29,-32768
	ctx.r29.s64 = -2147483648;
	// ori r29,r29,16389
	ctx.r29.u64 = ctx.r29.u64 | 16389;
	// b 0x8279d374
	goto loc_8279D374;
loc_8279D2DC:
	// li r8,0
	ctx.r8.s64 = 0;
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x827a13f8
	ctx.lr = 0x8279D2F4;
	sub_827A13F8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// blt 0x8279d374
	if (ctx.cr0.lt) goto loc_8279D374;
	// lis r12,-1057
	ctx.r12.s64 = -69271552;
	// lis r11,-5413
	ctx.r11.s64 = -354746368;
	// ori r12,r12,221
	ctx.r12.u64 = ctx.r12.u64 | 221;
	// lis r10,-1057
	ctx.r10.s64 = -69271552;
	// rldicr r12,r12,32,31
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 32) & 0xFFFFFFFF00000000;
	// ori r11,r11,61168
	ctx.r11.u64 = ctx.r11.u64 | 61168;
	// oris r12,r12,60123
	ctx.r12.u64 = ctx.r12.u64 | 3940220928;
	// ori r10,r10,221
	ctx.r10.u64 = ctx.r10.u64 | 221;
	// ori r12,r12,61168
	ctx.r12.u64 = ctx.r12.u64 | 61168;
	// rldimi r11,r10,32,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r11.u64 & 0xFFFFFFFF);
	// and r9,r31,r12
	ctx.r9.u64 = ctx.r31.u64 & ctx.r12.u64;
	// cmpld cr6,r9,r11
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r11.u64, ctx.xer);
	// beq cr6,0x8279d374
	if (ctx.cr6.eq) goto loc_8279D374;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,72
	ctx.r11.s64 = ctx.r30.s64 + 72;
loc_8279D338:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x8279d358
	if (ctx.cr6.eq) goto loc_8279D358;
	// lwz r9,208(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 208);
	// lis r8,1
	ctx.r8.s64 = 65536;
	// rlwinm r9,r9,0,12,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xF0000;
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8279d36c
	if (ctx.cr6.eq) goto loc_8279D36C;
loc_8279D358:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,4
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 4, ctx.xer);
	// blt cr6,0x8279d338
	if (ctx.cr6.lt) goto loc_8279D338;
	// b 0x8279d374
	goto loc_8279D374;
loc_8279D36C:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,276(r30)
	REX_STORE_U32(ctx.r30.u32 + 276, ctx.r11.u32);
loc_8279D374:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82855b34
	ctx.lr = 0x8279D37C;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A5778) {
	REX_FUNC_PROLOGUE();
	// b 0x827a5630
	sub_827A5630(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A57B0) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-27576(r10)
	REX_STORE_U32(ctx.r10.u32 + -27576, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827A6170) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x827A6178;
	__savegprlr_24(ctx, base);
	// ld r12,-4096(r1)
	ctx.r12.u64 = REX_LOAD_U64(ctx.r1.u32 + -4096);
	// stwu r1,-4336(r1)
	ea = -4336 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,32(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,40(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 40);
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// lwz r30,0(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r29,r5,8
	ctx.r29.s64 = ctx.r5.s64 + 8;
	// lwz r25,72(r4)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r4.u32 + 72);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x827a61ac
	if (!ctx.cr0.eq) goto loc_827A61AC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827a6364
	goto loc_827A6364;
loc_827A61AC:
	// li r9,160
	ctx.r9.s64 = 160;
	// addi r10,r1,92
	ctx.r10.s64 = ctx.r1.s64 + 92;
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827A61BC:
	// lhau r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.s64 = int16_t(REX_LOAD_U16(ea));
	ctx.r11.u32 = ea;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfsu f0,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x827a61bc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A61BC;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// li r5,160
	ctx.r5.s64 = 160;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827a8218
	ctx.lr = 0x827A61EC;
	sub_827A8218(ctx, base);
	// addi r26,r31,44
	ctx.r26.s64 = ctx.r31.s64 + 44;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r4,16(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// bl 0x827a5c40
	ctx.lr = 0x827A6200;
	sub_827A5C40(ctx, base);
	// stfs f1,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// lwz r28,24(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// bl 0x827a8ad0
	ctx.lr = 0x827A620C;
	sub_827A8AD0(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// li r5,145
	ctx.r5.s64 = 145;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827a7578
	ctx.lr = 0x827A6228;
	sub_827A7578(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r4,r3,145
	ctx.r4.s64 = ctx.r3.s64 + 145;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827a8338
	ctx.lr = 0x827A6240;
	sub_827A8338(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f1,8680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8680);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827a86a0
	ctx.lr = 0x827A6258;
	sub_827A86A0(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827a88d8
	ctx.lr = 0x827A6264;
	sub_827A88D8(ctx, base);
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// addi r7,r1,1152
	ctx.r7.s64 = ctx.r1.s64 + 1152;
	// addi r6,r1,2192
	ctx.r6.s64 = ctx.r1.s64 + 2192;
	// li r5,9
	ctx.r5.s64 = 9;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x827a8498
	ctx.lr = 0x827A627C;
	sub_827A8498(ctx, base);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r24
	ctx.r8.u64 = ctx.r24.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r5,r1,1152
	ctx.r5.s64 = ctx.r1.s64 + 1152;
	// addi r4,r1,2192
	ctx.r4.s64 = ctx.r1.s64 + 2192;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827a5ef0
	ctx.lr = 0x827A62A0;
	sub_827A5EF0(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f1,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f1.f64 = double(temp.f32);
	// li r5,225
	ctx.r5.s64 = 225;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// extsh r6,r11
	ctx.r6.s64 = ctx.r11.s16;
	// bl 0x827a9e40
	ctx.lr = 0x827A62C0;
	sub_827A9E40(ctx, base);
	// lwz r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 40);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,76(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// stfs f0,52(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
	// beq cr6,0x827a62f0
	if (ctx.cr6.eq) goto loc_827A62F0;
	// lfs f2,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827a9ce8
	ctx.lr = 0x827A62F0;
	sub_827A9CE8(ctx, base);
loc_827A62F0:
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827a6360
	if (ctx.cr6.eq) goto loc_827A6360;
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f10,20(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 20);
	ctx.f10.f64 = double(temp.f32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f9,16(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 16);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,24(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 24);
	ctx.f8.f64 = double(temp.f32);
	// lfs f11,12(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// lfs f12,10960(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10960);
	ctx.f12.f64 = double(temp.f32);
	// fdivs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// lfs f7,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f7.f64 = double(temp.f32);
	// lfs f13,24244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24244);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f11,f7
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f7.f64));
	// fmuls f0,f0,f10
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f10.f64));
	// fmadds f0,f0,f9,f8
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f9.f64, ctx.f8.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x827a6340
	if (!ctx.cr6.lt) goto loc_827A6340;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_827A6340:
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,7992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7992);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x827a6354
	if (!ctx.cr6.gt) goto loc_827A6354;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_827A6354:
	// fdivs f0,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// stfs f0,0(r29)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r29.u32 + 0, temp.u32);
	// stfs f11,4(r29)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r29.u32 + 4, temp.u32);
loc_827A6360:
	// li r3,0
	ctx.r3.s64 = 0;
loc_827A6364:
	// addi r1,r1,4336
	ctx.r1.s64 = ctx.r1.s64 + 4336;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AF330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-9460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9460);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-9456(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9364(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0BF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,23016
	ctx.r9.s64 = ctx.r11.s64 + 23016;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8720(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8720, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8468);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8352(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2A90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7804(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7804, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B35B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-7476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7476);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7472(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-7264(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7264);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7260(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B47D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,23784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6996(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6996);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6940(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5790) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6476(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6476, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B65F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5760(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5760);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5656(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5156(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5156);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5096(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA800) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4132(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4132);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4128(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4128, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3684(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC528) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD748) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2824(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2824);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2236(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF5F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0538) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,26344
	ctx.r9.s64 = ctx.r11.s64 + 26344;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,26344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1344(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1910) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C26E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,27144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,96(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 96, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C46A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,576(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27680(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 27680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3436(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3436);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,1044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1556(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1556);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C76B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,28584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2400(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2400);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2480(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2480, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C96F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA5B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,3420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3420);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3424(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CAED0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,3540(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3540);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,3684(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 3684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB9A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,29096
	ctx.r9.s64 = ctx.r11.s64 + 29096;
	// lfs f0,29096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4028(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 4028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC8B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD670) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,4864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,4868(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 4868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CE4A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5224(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5224);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CF728) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5776(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5776);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5824(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D09C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,6364(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6364);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1AA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,6740(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 6740);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6856(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,7292(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7292);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7396(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3B48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D59E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8584(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8584);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8700(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9136(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9136);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9244(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7F30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9688(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9688);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9788(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D91A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10216(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10216);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10328(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,31496
	ctx.r9.s64 = ctx.r11.s64 + 31496;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB6F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,31688
	ctx.r9.s64 = ctx.r11.s64 + 31688;
	// lfs f0,31688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11416(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11768(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11768);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD970) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,12440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12440);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12444(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE2D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,12620(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12620);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12716(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DEDE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,32216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12940(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12940);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13044(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFF98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0F38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14024(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14508(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14508);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14512(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15004(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3F30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15424(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4EE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15860);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15864(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15864, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5D28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,16276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16276);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6C38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-28596(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28596);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16700(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16700, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E7C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-27432
	ctx.r11.s64 = ctx.r11.s64 + -27432;
	// lfs f0,17108(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 17108);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 8, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8818) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-25912
	ctx.r9.s64 = ctx.r11.s64 + -25912;
	// lfs f0,-25912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17472(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 17472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E97B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-24004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17924(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17924, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA6F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18336(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC5F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,19192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-22040(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -22040);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,19208(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EDA38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEAA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF940) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21044);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21048(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21048, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F17C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21452);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21456(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2750) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F37D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-17192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12348(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12348);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,14376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,22360(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 22360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5D90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-15864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2460(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2460);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23668(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6B90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24056(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24504(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8DB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-11960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24920(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24920);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9C98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-10248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25952(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26404(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26404);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26504(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26504, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD668) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,26956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 26956);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27064(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE9D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27508(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27508);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27628(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FFD08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800AC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28588(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28588);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28592(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28592, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,29016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29016);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,29020(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 29020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802398) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29316(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29724);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29728(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29728, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828042C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30224(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828050C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30636(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30988(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30988);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31092(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807420) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-7704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31664(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828087F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32240(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828095D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32644(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32644);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A488) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-32464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32464);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-32460(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -32460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280AF18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32156);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32152(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32152, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BE30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-6936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31800(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31800);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D1B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-6680
	ctx.r9.s64 = ctx.r11.s64 + -6680;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-6680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31124(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F490) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30104(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810510) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29612(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828114B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-29152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812338) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-5656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28804);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28724(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828136B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814480) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-27692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816520) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26716(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26716, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817530) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-26248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26248);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-26244(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -26244, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818EE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-3512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25128);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25040(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B2C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-3160
	ctx.r9.s64 = ctx.r11.s64 + -3160;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-3160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C658) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-2632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23416(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23416);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23300(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281EA70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FB28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22240(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820DD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-21692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21692);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-21688(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -21688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828226E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-1560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828239F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-1240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20428(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20428);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825CF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-19376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -19376);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-19328(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -19328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826F60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18792(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828108) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18284);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A1C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-17424(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -17424);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17320(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17320, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16884(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282BEB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16456(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D3A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-15956(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15956);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15388(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F188) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830288) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14456(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14456, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828313D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,1576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14016(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13944(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13944, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832560) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,1768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13540(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13540);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833A68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834B70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,2296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12408(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12408);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12292(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835DA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,2520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11748(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828370A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11188(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838278) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10276);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10272(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839EA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283AFD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9344(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283BE68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8916(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8916, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CE68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-8452(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8452);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-8448(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -8448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D8A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8148(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E840) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-7696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7696);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7692(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F300) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840208) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-7036(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -7036);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6932(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6932, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842248) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4912(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4912);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6108(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6108);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5988(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828435A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,5144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5536(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5536);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5420(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828448E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,5624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4524);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846E00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3748(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3748);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847C90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6112(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6112);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3348);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3300(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849008) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,6336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2780(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2780);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2732(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2732, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A380) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1660(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1660);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2100(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2100);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,-1656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C430) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D5C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284E3D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -268);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-264(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EE28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,7496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-72(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -72);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,44(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 44, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828502A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,660(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 660, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,1156(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1156);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1160(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1160, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851CE0) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,1432
	ctx.r6.s64 = ctx.r8.s64 + 1432;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,1432(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 1432);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,1432(r8)
	REX_STORE_U32(ctx.r8.u32 + 1432, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,1432(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 1432);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,1432(r8)
	REX_STORE_U32(ctx.r8.u32 + 1432, ctx.r11.u32);
	// stb r9,1432(r8)
	REX_STORE_U8(ctx.r8.u32 + 1432, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853568) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2156(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82854BC8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32123
	ctx.r11.s64 = -2105212928;
	// addi r3,r11,21880
	ctx.r3.s64 = ctx.r11.s64 + 21880;
	// b 0x827387e8
	sub_827387E8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8285BFA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8285BFA8;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r4,8(r4)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r4.u32 + 8);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// subfic r10,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r10.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrldi r9,r10,32
	ctx.r9.u64 = ctx.r10.u64 & 0xFFFFFFFF;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// srd r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r9.u8 & 0x7F));
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r6,r7,r28
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r28.u32);
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8285c0a4
	if (ctx.cr6.lt) goto loc_8285C0A4;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x8285c09c
	if (!ctx.cr6.lt) goto loc_8285C09C;
loc_8285C004:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x8285c030
	if (ctx.cr6.lt) goto loc_8285C030;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x8285C020;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x8285c004
	if (ctx.cr6.eq) goto loc_8285C004;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8285c0e4
	goto loc_8285C0E4;
loc_8285C030:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r10,1(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r9,r9,8,63
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r5,5(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r8,r11,r5
	ctx.r8.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r8,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r3.u8 & 0x7F));
	// add r7,r11,r4
	ctx.r7.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r7,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r7.u64);
loc_8285C09C:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x8285c0e4
	goto loc_8285C0E4;
loc_8285C0A4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x8285C0AC;
	sub_826C8C48(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r29,r11,32768
	ctx.r29.u64 = ctx.r11.u64 | 32768;
loc_8285C0B4:
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x826c8c48
	ctx.lr = 0x8285C0CC;
	sub_826C8C48(ctx, base);
	// add r10,r30,r29
	ctx.r10.u64 = ctx.r30.u64 + ctx.r29.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r28
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x8285c0b4
	if (ctx.cr6.lt) goto loc_8285C0B4;
loc_8285C0E4:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// li r29,0
	ctx.r29.s64 = 0;
	// bne cr6,0x8285c288
	if (!ctx.cr6.eq) goto loc_8285C288;
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x8285c1d0
	if (ctx.cr6.eq) goto loc_8285C1D0;
	// li r30,2
	ctx.r30.s64 = 2;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x8285c16c
	if (!ctx.cr6.lt) goto loc_8285C16C;
loc_8285C114:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8285c16c
	if (ctx.cr6.eq) goto loc_8285C16C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x8285c15c
	if (!ctx.cr0.lt) goto loc_8285C15C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C15C;
	sub_826C8B78(ctx, base);
loc_8285C15C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8285c114
	if (ctx.cr6.gt) goto loc_8285C114;
loc_8285C16C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x8285c1a8
	if (!ctx.cr0.lt) goto loc_8285C1A8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C1A8;
	sub_826C8B78(ctx, base);
loc_8285C1A8:
	// srawi r11,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 1;
	// clrlwi r10,r30,31
	ctx.r10.u64 = ctx.r30.u32 & 0x1;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// neg r9,r10
	ctx.r9.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// li r11,0
	ctx.r11.s64 = 0;
	// xor r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 ^ ctx.r9.u64;
	// subf r3,r9,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r9.u64;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_8285C1D0:
	// li r30,1
	ctx.r30.s64 = 1;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8285c234
	if (!ctx.cr6.lt) goto loc_8285C234;
loc_8285C1DC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8285c234
	if (ctx.cr6.eq) goto loc_8285C234;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x8285c224
	if (!ctx.cr0.lt) goto loc_8285C224;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C224;
	sub_826C8B78(ctx, base);
loc_8285C224:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8285c1dc
	if (ctx.cr6.gt) goto loc_8285C1DC;
loc_8285C234:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x8285c270
	if (!ctx.cr0.lt) goto loc_8285C270;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C270;
	sub_826C8B78(ctx, base);
loc_8285C270:
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r3,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r3.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_8285C288:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r30,71
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 71, ctx.xer);
	// bne cr6,0x8285c380
	if (!ctx.cr6.eq) goto loc_8285C380;
	// lhz r11,72(r27)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + 72);
	// lhz r9,70(r27)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r27.u32 + 70);
	// add r30,r9,r11
	ctx.r30.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x8285c2b4
	if (!ctx.cr6.gt) goto loc_8285C2B4;
loc_8285C2AC:
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x8285c35c
	goto loc_8285C35C;
loc_8285C2B4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8285c2ac
	if (ctx.cr6.eq) goto loc_8285C2AC;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8285c31c
	if (!ctx.cr6.gt) goto loc_8285C31C;
loc_8285C2C4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8285c31c
	if (ctx.cr6.eq) goto loc_8285C31C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x8285c30c
	if (!ctx.cr0.lt) goto loc_8285C30C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C30C;
	sub_826C8B78(ctx, base);
loc_8285C30C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8285c2c4
	if (ctx.cr6.gt) goto loc_8285C2C4;
loc_8285C31C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x8285c358
	if (!ctx.cr0.lt) goto loc_8285C358;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C358;
	sub_826C8B78(ctx, base);
loc_8285C358:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_8285C35C:
	// lhz r9,72(r27)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r27.u32 + 72);
	// li r8,1
	ctx.r8.s64 = 1;
	// slw r10,r8,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// addi r7,r10,-1
	ctx.r7.s64 = ctx.r10.s64 + -1;
	// sraw r3,r11,r9
	temp.u32 = ctx.r9.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r11.s32 < 0) & (((ctx.r11.s32 >> temp.u32) << temp.u32) != ctx.r11.s32);
	ctx.r3.s64 = ctx.r11.s32 >> temp.u32;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_8285C380:
	// lwz r11,16(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 16);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r11
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// srawi r7,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 4;
	// clrlwi r11,r8,28
	ctx.r11.u64 = ctx.r8.u32 & 0xF;
	// clrlwi r28,r7,28
	ctx.r28.u64 = ctx.r7.u32 & 0xF;
	// srawi r6,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 8;
	// srawi r5,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 16;
	// add r30,r11,r28
	ctx.r30.u64 = ctx.r11.u64 + ctx.r28.u64;
	// srawi r4,r8,24
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 24;
	// clrlwi r27,r6,24
	ctx.r27.u64 = ctx.r6.u32 & 0xFF;
	// clrlwi r26,r5,24
	ctx.r26.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r25,r4,24
	ctx.r25.u64 = ctx.r4.u32 & 0xFF;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x8285c3c8
	if (!ctx.cr6.gt) goto loc_8285C3C8;
loc_8285C3C0:
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x8285c470
	goto loc_8285C470;
loc_8285C3C8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8285c3c0
	if (ctx.cr6.eq) goto loc_8285C3C0;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x8285c430
	if (!ctx.cr6.gt) goto loc_8285C430;
loc_8285C3D8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8285c430
	if (ctx.cr6.eq) goto loc_8285C430;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x8285c420
	if (!ctx.cr0.lt) goto loc_8285C420;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C420;
	sub_826C8B78(ctx, base);
loc_8285C420:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x8285c3d8
	if (ctx.cr6.gt) goto loc_8285C3D8;
loc_8285C430:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x8285c46c
	if (!ctx.cr0.lt) goto loc_8285C46C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8285C46C;
	sub_826C8B78(ctx, base);
loc_8285C46C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_8285C470:
	// sraw r11,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r11.s64 = ctx.r10.s32 >> temp.u32;
	// and r9,r10,r25
	ctx.r9.u64 = ctx.r10.u64 & ctx.r25.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// clrlwi r7,r9,31
	ctx.r7.u64 = ctx.r9.u32 & 0x1;
	// neg r6,r8
	ctx.r6.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// neg r5,r7
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// add r4,r11,r26
	ctx.r4.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r3,r10,r27
	ctx.r3.u64 = ctx.r10.u64 + ctx.r27.u64;
	// xor r11,r4,r5
	ctx.r11.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// xor r10,r3,r6
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r6.u64;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// subf r3,r6,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r6.u64;
	// rlwimi r3,r11,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

