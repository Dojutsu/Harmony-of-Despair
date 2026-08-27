#include "harmonyrecomp_funcs.57.h"

DEFINE_REX_FUNC(sub_82214B80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82214B88;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x82443da0
	ctx.lr = 0x82214BA0;
	sub_82443DA0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82214bf4
	if (ctx.cr6.eq) goto loc_82214BF4;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// li r9,808
	ctx.r9.s64 = 808;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// divw r11,r11,r9
	ctx.r11.u64 = uint32_t((ctx.r9.s32 && !(ctx.r11.s32 == INT32_MIN && ctx.r9.s32 == -1)) ? ctx.r11.s32 / ctx.r9.s32 : 0);
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x82214bf4
	if (!ctx.cr6.gt) goto loc_82214BF4;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// ble cr6,0x82214bf4
	if (!ctx.cr6.gt) goto loc_82214BF4;
	// cmpwi cr6,r5,15
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 15, ctx.xer);
	// bge cr6,0x82214bf4
	if (!ctx.cr6.lt) goto loc_82214BF4;
	// mulli r11,r3,202
	ctx.r11.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(202));
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// addi r11,r11,182
	ctx.r11.s64 = ctx.r11.s64 + 182;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r31,r11,r10
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x82214bf8
	goto loc_82214BF8;
loc_82214BF4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82214BF8:
	// cmplwi cr6,r31,8331
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 8331, ctx.xer);
	// blt cr6,0x82214c08
	if (ctx.cr6.lt) goto loc_82214C08;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82214c14
	goto loc_82214C14;
loc_82214C08:
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// lbz r11,1000(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 1000);
	// rlwinm r11,r11,28,4,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0xFFFFFFF;
loc_82214C14:
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// clrlwi r30,r11,24
	ctx.r30.u64 = ctx.r11.u32 & 0xFF;
	// bl 0x82214e30
	ctx.lr = 0x82214C2C;
	sub_82214E30(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// bgt cr6,0x82214ca4
	if (ctx.cr6.gt) goto loc_82214CA4;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq cr6,0x82214c78
	if (ctx.cr6.eq) goto loc_82214C78;
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// beq cr6,0x82214c78
	if (ctx.cr6.eq) goto loc_82214C78;
	// li r5,1
	ctx.r5.s64 = 1;
	// cmplwi cr6,r31,2161
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2161, ctx.xer);
	// blt cr6,0x82214c98
	if (ctx.cr6.lt) goto loc_82214C98;
	// cmplwi cr6,r31,2163
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2163, ctx.xer);
	// ble cr6,0x82214c70
	if (!ctx.cr6.gt) goto loc_82214C70;
	// cmplwi cr6,r31,2210
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2210, ctx.xer);
	// ble cr6,0x82214c98
	if (!ctx.cr6.gt) goto loc_82214C98;
	// cmplwi cr6,r31,2213
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2213, ctx.xer);
	// ble cr6,0x82214c70
	if (!ctx.cr6.gt) goto loc_82214C70;
	// cmplwi cr6,r31,2215
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 2215, ctx.xer);
	// bne cr6,0x82214c98
	if (!ctx.cr6.eq) goto loc_82214C98;
loc_82214C70:
	// subfic r5,r30,4
	ctx.xer.ca = ctx.r30.u32 <= 4;
	ctx.r5.u64 = static_cast<uint64_t>(4) - ctx.r30.u64;
	// b 0x82214c98
	goto loc_82214C98;
loc_82214C78:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823b47e8
	ctx.lr = 0x82214C80;
	sub_823B47E8(ctx, base);
	// bl 0x82453810
	ctx.lr = 0x82214C84;
	sub_82453810(ctx, base);
	// rlwinm. r11,r3,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82214c94
	if (ctx.cr0.eq) goto loc_82214C94;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82214ca4
	if (!ctx.cr6.eq) goto loc_82214CA4;
loc_82214C94:
	// li r5,1
	ctx.r5.s64 = 1;
loc_82214C98:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82214a48
	ctx.lr = 0x82214CA4;
	sub_82214A48(ctx, base);
loc_82214CA4:
	// mulli r11,r27,15
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(15));
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r31,r11,r29
	REX_STORE_U32(ctx.r11.u32 + ctx.r29.u32, ctx.r31.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82223A50) {
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
	// lbz r11,93(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 93);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82223ab0
	if (ctx.cr0.eq) goto loc_82223AB0;
	// lwz r3,60(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82223a88
	if (!ctx.cr6.eq) goto loc_82223A88;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,93(r31)
	REX_STORE_U8(ctx.r31.u32 + 93, ctx.r11.u8);
	// b 0x82223ab0
	goto loc_82223AB0;
loc_82223A88:
	// bl 0x823bdef8
	ctx.lr = 0x82223A8C;
	sub_823BDEF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82223ab0
	if (!ctx.cr0.eq) goto loc_82223AB0;
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,93(r31)
	REX_STORE_U8(ctx.r31.u32 + 93, ctx.r11.u8);
	// lwz r11,64(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82223AB0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82223AB0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82218310
	ctx.lr = 0x82223AB8;
	sub_82218310(ctx, base);
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

DEFINE_REX_FUNC(sub_82227848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x82227850;
	__savegprlr_21(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822278a0
	if (ctx.cr6.eq) goto loc_822278A0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x822278A0;
	sub_823AF008(ctx, base);
loc_822278A0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227e28
	if (ctx.cr0.eq) goto loc_82227E28;
	// lfs f0,0(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r10,r11,12468
	ctx.r10.s64 = ctx.r11.s64 + 12468;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// lfs f6,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f6.f64 = double(temp.f32);
	// li r26,0
	ctx.r26.s64 = 0;
	// li r24,0
	ctx.r24.s64 = 0;
	// lfs f5,1736(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1736);
	ctx.f5.f64 = double(temp.f32);
	// li r22,0
	ctx.r22.s64 = 0;
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// ble cr6,0x82227998
	if (!ctx.cr6.gt) goto loc_82227998;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
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
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// bgt cr6,0x82227914
	if (ctx.cr6.gt) goto loc_82227914;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82227914:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x82227944
	if (ctx.cr0.eq) goto loc_82227944;
	// li r27,-1
	ctx.r27.s64 = -1;
	// beq cr6,0x82227960
	if (ctx.cr6.eq) goto loc_82227960;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ae578
	ctx.lr = 0x82227940;
	sub_823AE578(ctx, base);
	// b 0x82227960
	goto loc_82227960;
loc_82227944:
	// li r27,1
	ctx.r27.s64 = 1;
	// beq cr6,0x82227960
	if (ctx.cr6.eq) goto loc_82227960;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ae2c0
	ctx.lr = 0x82227960;
	sub_823AE2C0(ctx, base);
loc_82227960:
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82227984
	if (ctx.cr6.eq) goto loc_82227984;
	// rlwinm r11,r27,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r4,r11,r30
	ctx.r4.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x82227984;
	sub_823AF008(ctx, base);
loc_82227984:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227998
	if (ctx.cr0.eq) goto loc_82227998;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x82227998
	if (ctx.cr6.eq) goto loc_82227998;
	// li r24,1
	ctx.r24.s64 = 1;
loc_82227998:
	// lfs f0,4(r21)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f5
	ctx.cr6.compare(ctx.f13.f64, ctx.f5.f64);
	// ble cr6,0x82227a5c
	if (!ctx.cr6.gt) goto loc_82227A5C;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
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
	// fcmpu cr6,f0,f6
	ctx.cr6.compare(ctx.f0.f64, ctx.f6.f64);
	// bgt cr6,0x822279dc
	if (ctx.cr6.gt) goto loc_822279DC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822279DC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x82227a0c
	if (ctx.cr0.eq) goto loc_82227A0C;
	// li r28,-1
	ctx.r28.s64 = -1;
	// beq cr6,0x82227a24
	if (ctx.cr6.eq) goto loc_82227A24;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823aebd8
	ctx.lr = 0x82227A08;
	sub_823AEBD8(ctx, base);
	// b 0x82227a24
	goto loc_82227A24;
loc_82227A0C:
	// li r28,1
	ctx.r28.s64 = 1;
	// beq cr6,0x82227a24
	if (ctx.cr6.eq) goto loc_82227A24;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823ae820
	ctx.lr = 0x82227A24;
	sub_823AE820(ctx, base);
loc_82227A24:
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82227a48
	if (ctx.cr6.eq) goto loc_82227A48;
	// rlwinm r11,r28,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFFFFF0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r5,r11,r29
	ctx.r5.u64 = ctx.r11.u64 + ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823af008
	ctx.lr = 0x82227A48;
	sub_823AF008(ctx, base);
loc_82227A48:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227a5c
	if (ctx.cr0.eq) goto loc_82227A5C;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x82227a5c
	if (ctx.cr6.eq) goto loc_82227A5C;
	// li r22,1
	ctx.r22.s64 = 1;
loc_82227A5C:
	// extsw r11,r25
	ctx.r11.s64 = ctx.r25.s32;
	// extsw r10,r26
	ctx.r10.s64 = ctx.r26.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// addi r10,r11,32720
	ctx.r10.s64 = ctx.r11.s64 + 32720;
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f9,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fabs f12,f0
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fabs f11,f13
	ctx.f11.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// bne 0x82227ca0
	if (!ctx.cr0.eq) goto loc_82227CA0;
	// clrlwi. r10,r22,24
	ctx.r10.u64 = ctx.r22.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82227ca0
	if (!ctx.cr0.eq) goto loc_82227CA0;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r10,9232
	ctx.r10.s64 = ctx.r10.s64 + 9232;
	// vslw128 v60,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v60,v61,v60
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vmaxfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vcmpgefp128. v61,v62,v61
	simde_mm_store_ps(ctx.v61.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v61.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227b54
	if (ctx.cr0.eq) goto loc_82227B54;
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// lfs f13,4(r23)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// b 0x82227c88
	goto loc_82227C88;
loc_82227B54:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f12,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// vslw128 v61,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v61,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vmaxfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_max_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vcmpgefp128. v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227be0
	if (ctx.cr0.eq) goto loc_82227BE0;
	// extsw r9,r27
	ctx.r9.s64 = ctx.r27.s32;
	// lfs f0,0(r23)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
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
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// b 0x82227d84
	goto loc_82227D84;
loc_82227BE0:
	// fcmpu cr6,f11,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f12.f64);
	// bgt cr6,0x82227c40
	if (ctx.cr6.gt) goto loc_82227C40;
	// extsw r9,r27
	ctx.r9.s64 = ctx.r27.s32;
	// lfs f0,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// b 0x82227d84
	goto loc_82227D84;
loc_82227C40:
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// lfs f13,4(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
loc_82227C88:
	// fcfid f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f12.s64);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,4(r23)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r23.u32 + 4, temp.u32);
	// frsp f9,f0
	ctx.f9.f64 = double(float(ctx.f0.f64));
	// b 0x82227d8c
	goto loc_82227D8C;
loc_82227CA0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82227d20
	if (ctx.cr6.eq) goto loc_82227D20;
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// fcmpu cr6,f12,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f5.f64);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f9,f12
	ctx.f9.f64 = double(float(ctx.f12.f64));
	// ble cr6,0x82227d14
	if (!ctx.cr6.gt) goto loc_82227D14;
	// mullw. r11,r26,r28
	ctx.r11.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r28.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x82227d14
	if (!ctx.cr0.gt) goto loc_82227D14;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f12,4(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r23)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r23.u32 + 4, temp.u32);
loc_82227D14:
	// clrlwi. r11,r22,24
	ctx.r11.u64 = ctx.r22.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82227d8c
	if (ctx.cr0.eq) goto loc_82227D8C;
	// b 0x82227d34
	goto loc_82227D34;
loc_82227D20:
	// extsw r11,r27
	ctx.r11.s64 = ctx.r27.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
loc_82227D34:
	// fcmpu cr6,f11,f5
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f5.f64);
	// ble cr6,0x82227d8c
	if (!ctx.cr6.gt) goto loc_82227D8C;
	// mullw. r11,r25,r27
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r27.s32);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble 0x82227d8c
	if (!ctx.cr0.gt) goto loc_82227D8C;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
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
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82227D84:
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r23)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r23.u32 + 0, temp.u32);
loc_82227D8C:
	// fabs f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f10.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f5
	ctx.cr6.compare(ctx.f0.f64, ctx.f5.f64);
	// ble cr6,0x82227dd8
	if (!ctx.cr6.gt) goto loc_82227DD8;
	// lfs f0,0(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r10,32608
	ctx.r10.s64 = ctx.r10.s64 + 32608;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r21)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r21.u32 + 0, temp.u32);
	// b 0x82227e20
	goto loc_82227E20;
loc_82227DD8:
	// fabs f0,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f9.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f5
	ctx.cr6.compare(ctx.f0.f64, ctx.f5.f64);
	// ble cr6,0x82227e20
	if (!ctx.cr6.gt) goto loc_82227E20;
	// lfs f0,4(r21)
	temp.u32 = REX_LOAD_U32(ctx.r21.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r10,r10,32608
	ctx.r10.s64 = ctx.r10.s64 + 32608;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r21)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r21.u32 + 4, temp.u32);
loc_82227E20:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82227e2c
	goto loc_82227E2C;
loc_82227E28:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82227E2C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82276FC0) {
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
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82276FF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r31,r11,12468
	ctx.r31.s64 = ctx.r11.s64 + 12468;
	// lfs f1,-232(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82277014;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 248);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,64
	ctx.r5.s64 = 64;
	// li r4,64
	ctx.r4.s64 = 64;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82277038;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r9,r30,1
	ctx.r9.s64 = ctx.r30.s64 + 65536;
	// lfs f0,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r9,r9,-2504
	ctx.r9.s64 = ctx.r9.s64 + -2504;
	// li r10,0
	ctx.r10.s64 = 0;
loc_8227704C:
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// li r6,64
	ctx.r6.s64 = 64;
loc_82277054:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lbz r8,52(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 52);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// li r8,4
	ctx.r8.s64 = 4;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bne 0x8227708c
	if (!ctx.cr0.eq) goto loc_8227708C;
	// addi r11,r11,-9
	ctx.r11.s64 = ctx.r11.s64 + -9;
loc_8227707C:
	// li r8,0
	ctx.r8.s64 = 0;
	// stbu r8,40(r11)
	ea = 40 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r8.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x8227707c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8227707C;
	// b 0x822770e8
	goto loc_822770E8;
loc_8227708C:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
loc_82277090:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f12,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwz r8,28(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 28);
	// stw r8,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r8.u32);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f13,44(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// lfs f13,-4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,16(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 16);
	ctx.f11.f64 = double(temp.f32);
	// fadds f13,f11,f13
	ctx.f13.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// stfs f13,-4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + -4, temp.u32);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// add r8,r10,r8
	ctx.r8.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lfs f13,20(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r11,r11,40
	ctx.r11.s64 = ctx.r11.s64 + 40;
	// bdnz 0x82277090
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82277090;
loc_822770E8:
	// addic. r6,r6,-1
	ctx.xer.ca = ctx.r6.u32 > 0;
	ctx.r6.s64 = ctx.r6.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// addi r7,r7,160
	ctx.r7.s64 = ctx.r7.s64 + 160;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// bne 0x82277054
	if (!ctx.cr0.eq) goto loc_82277054;
	// lis r11,3
	ctx.r11.s64 = 196608;
	// ori r8,r11,32768
	ctx.r8.u64 = ctx.r11.u64 | 32768;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// cmplw cr6,r10,r8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x8227704c
	if (ctx.cr6.lt) goto loc_8227704C;
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

DEFINE_REX_FUNC(sub_82287640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82287648;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af10
	ctx.lr = 0x82287650;
	__savefpr_22(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r29,r11,-32216
	ctx.r29.s64 = ctx.r11.s64 + -32216;
	// addi r30,r10,12472
	ctx.r30.s64 = ctx.r10.s64 + 12472;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// lfs f31,2088(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2088);
	ctx.f31.f64 = double(temp.f32);
	// lfs f1,-236(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -236);
	ctx.f1.f64 = double(temp.f32);
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82287680;
	sub_825A4A40(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f28,f1
	ctx.fpscr.disableFlushMode();
	ctx.f28.f64 = ctx.f1.f64;
	// addi r31,r11,1604
	ctx.r31.s64 = ctx.r11.s64 + 1604;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// lfs f2,-8016(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -8016);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8228769C;
	sub_825A4A40(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-15624(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -15624);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,-16652(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16652);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822876B4;
	sub_825A4A40(ctx, base);
	// lfs f0,-4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f27,f1
	ctx.f27.f64 = ctx.f1.f64;
	// lfs f2,-3164(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -3164);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822876CC;
	sub_825A4A40(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f2,2800(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2800);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,2796(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2796);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822876E8;
	sub_825A4A40(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f25,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// lfs f12,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// fmr f26,f1
	ctx.f26.f64 = ctx.f1.f64;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lwzx r11,r28,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82287748
	if (ctx.cr6.eq) goto loc_82287748;
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// beq cr6,0x82287748
	if (ctx.cr6.eq) goto loc_82287748;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82287720
	if (!ctx.cr6.eq) goto loc_82287720;
	// fmuls f30,f30,f31
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f31.f64));
	// b 0x82287750
	goto loc_82287750;
loc_82287720:
	// cmplwi cr6,r11,11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 11, ctx.xer);
	// bne cr6,0x82287750
	if (!ctx.cr6.eq) goto loc_82287750;
	// lfs f0,24424(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24424);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f29,f29,f31
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f31.f64));
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f28,f28,f0
	ctx.f28.f64 = double(float(ctx.f28.f64 * ctx.f0.f64));
	// fmuls f30,f30,f31
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f31.f64));
	// fmuls f27,f27,f0
	ctx.f27.f64 = double(float(ctx.f27.f64 * ctx.f0.f64));
	// fmuls f26,f26,f13
	ctx.f26.f64 = double(float(ctx.f26.f64 * ctx.f13.f64));
	// b 0x82287750
	goto loc_82287750;
loc_82287748:
	// lfs f0,1904(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1904);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f29,f29,f0
	ctx.f29.f64 = double(float(ctx.f29.f64 * ctx.f0.f64));
loc_82287750:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f22,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f22.f64 = double(temp.f32);
	// lfs f23,-10560(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + -10560);
	ctx.f23.f64 = double(temp.f32);
	// li r28,0
	ctx.r28.s64 = 0;
	// lfs f24,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f24.f64 = double(temp.f32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f31,-5116(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5116);
	ctx.f31.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r30,r11,22072
	ctx.r30.s64 = ctx.r11.s64 + 22072;
loc_82287774:
	// cmplwi cr6,r28,1
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 1, ctx.xer);
	// bne cr6,0x82287784
	if (!ctx.cr6.eq) goto loc_82287784;
	// fadds f25,f25,f23
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = double(float(ctx.f25.f64 + ctx.f23.f64));
	// b 0x82287794
	goto loc_82287794;
loc_82287784:
	// cmplwi cr6,r28,2
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 2, ctx.xer);
	// bne cr6,0x82287794
	if (!ctx.cr6.eq) goto loc_82287794;
	// fsubs f25,f25,f23
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = double(float(ctx.f25.f64 - ctx.f23.f64));
	// fmuls f30,f30,f22
	ctx.f30.f64 = double(float(ctx.f30.f64 * ctx.f22.f64));
loc_82287794:
	// lfs f0,23572(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 23572);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,140
	ctx.r4.s64 = 140;
	// lwz r3,48(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 48);
	// stfs f25,88(r1)
	temp.f32 = float(ctx.f25.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// fsubs f31,f31,f0
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f0.f64));
	// bl 0x825e02a0
	ctx.lr = 0x822877B0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822877f4
	if (ctx.cr0.eq) goto loc_822877F4;
	// stfs f30,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
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
	// stfs f28,132(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f29,136(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// stfs f26,140(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8221e078
	ctx.lr = 0x822877EC;
	sub_8221E078(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x822877f8
	goto loc_822877F8;
loc_822877F4:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822877F8:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82287854
	if (ctx.cr6.eq) goto loc_82287854;
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
	ctx.lr = 0x82287818;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
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
	ctx.lr = 0x82287830;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82287854
	if (!ctx.cr6.eq) goto loc_82287854;
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
	ctx.lr = 0x82287854;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82287854:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// cmplwi cr6,r28,3
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 3, ctx.xer);
	// blt cr6,0x82287774
	if (ctx.cr6.lt) goto loc_82287774;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af5c
	ctx.lr = 0x8228786C;
	__restfpr_22(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82298640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82298648;
	__savegprlr_14(ctx, base);
	// li r12,-176
	ctx.r12.s64 = -176;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-736(r1)
	ea = -736 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r11,r4,1
	ctx.r11.s64 = ctx.r4.s64 + 65536;
	// stw r3,756(r1)
	REX_STORE_U32(ctx.r1.u32 + 756, ctx.r3.u32);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// addi r11,r11,-2208
	ctx.r11.s64 = ctx.r11.s64 + -2208;
	// mr r15,r4
	ctx.r15.u64 = ctx.r4.u64;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// lbz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822986cc
	if (!ctx.cr0.eq) goto loc_822986CC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// addi r11,r11,-29856
	ctx.r11.s64 = ctx.r11.s64 + -29856;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// lis r7,0
	ctx.r7.s64 = 0;
	// addi r9,r9,-29872
	ctx.r9.s64 = ctx.r9.s64 + -29872;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r10,r7,63340
	ctx.r10.u64 = ctx.r7.u64 | 63340;
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stwx r11,r4,r10
	REX_STORE_U32(ctx.r4.u32 + ctx.r10.u32, ctx.r11.u32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// b 0x82299114
	goto loc_82299114;
loc_822986CC:
	// bl 0x824281d8
	ctx.lr = 0x822986D0;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82299108
	if (ctx.cr0.eq) goto loc_82299108;
	// bl 0x8242a5e0
	ctx.lr = 0x822986DC;
	sub_8242A5E0(ctx, base);
	// li r14,0
	ctx.r14.s64 = 0;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822986f0
	if (!ctx.cr0.eq) goto loc_822986F0;
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// b 0x822986f4
	goto loc_822986F4;
loc_822986F0:
	// bl 0x8242aa28
	ctx.lr = 0x822986F4;
	sub_8242AA28(ctx, base);
loc_822986F4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82299108
	if (ctx.cr0.eq) goto loc_82299108;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13068(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13068);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82298724
	if (ctx.cr6.eq) goto loc_82298724;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r31,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r31.s64 = ctx.r11.s32 >> 2;
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// b 0x8229872c
	goto loc_8229872C;
loc_82298724:
	// stw r14,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r14.u32);
	// rotlwi r31,r14,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r14.u32, 0);
loc_8229872C:
	// addis r16,r15,1
	ctx.r16.s64 = ctx.r15.s64 + 65536;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r16,r16,-2206
	ctx.r16.s64 = ctx.r16.s64 + -2206;
	// stb r14,0(r16)
	REX_STORE_U8(ctx.r16.u32 + 0, ctx.r14.u8);
	// beq cr6,0x82299108
	if (ctx.cr6.eq) goto loc_82299108;
	// addis r18,r15,1
	ctx.r18.s64 = ctx.r15.s64 + 65536;
	// stb r14,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r14.u8);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stb r14,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r14.u8);
	// addi r18,r18,-2205
	ctx.r18.s64 = ctx.r18.s64 + -2205;
	// mr r24,r14
	ctx.r24.u64 = ctx.r14.u64;
	// lwz r3,-13032(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// stb r14,0(r18)
	REX_STORE_U8(ctx.r18.u32 + 0, ctx.r14.u8);
	// lfs f0,88(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r19,92(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82298794
	if (ctx.cr6.eq) goto loc_82298794;
	// lfs f0,92(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r19
	ctx.r4.u64 = ctx.r19.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823aefa8
	ctx.lr = 0x82298790;
	sub_823AEFA8(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
loc_82298794:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r14,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r14.u32);
	// mr r17,r14
	ctx.r17.u64 = ctx.r14.u64;
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// addi r25,r11,32752
	ctx.r25.s64 = ctx.r11.s64 + 32752;
	// beq cr6,0x82298b60
	if (ctx.cr6.eq) goto loc_82298B60;
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// lvx128 v127,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// addi r22,r11,-4
	ctx.r22.s64 = ctx.r11.s64 + -4;
	// addi r28,r10,-4
	ctx.r28.s64 = ctx.r10.s64 + -4;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// clrlwi r21,r24,24
	ctx.r21.u64 = ctx.r24.u32 & 0xFF;
	// li r20,1
	ctx.r20.s64 = 1;
	// lis r23,-32228
	ctx.r23.s64 = -2112094208;
	// addi r29,r11,-15500
	ctx.r29.s64 = ctx.r11.s64 + -15500;
	// addi r27,r10,15384
	ctx.r27.s64 = ctx.r10.s64 + 15384;
	// b 0x822987e8
	goto loc_822987E8;
loc_822987E4:
	// li r14,0
	ctx.r14.s64 = 0;
loc_822987E8:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8242a650
	ctx.lr = 0x822987F0;
	sub_8242A650(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82429a18
	ctx.lr = 0x822987F8;
	sub_82429A18(ctx, base);
	// clrlwi r4,r31,24
	ctx.r4.u64 = ctx.r31.u32 & 0xFF;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x82429668
	ctx.lr = 0x82298804;
	sub_82429668(ctx, base);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lfs f0,220(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,464
	ctx.r9.s64 = ctx.r1.s64 + 464;
	// stfs f0,348(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stfs f0,344(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// mr r8,r14
	ctx.r8.u64 = ctx.r14.u64;
	// stfs f0,340(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f0,336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lwz r3,-13032(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lfs f0,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.f0.u64);
	// lwz r4,196(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,464(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.f13.u64);
	// lwz r5,196(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 196);
	// beq cr6,0x82298868
	if (ctx.cr6.eq) goto loc_82298868;
	// bl 0x823aefa8
	ctx.lr = 0x82298864;
	sub_823AEFA8(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
loc_82298868:
	// lbz r11,0(r16)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r16.u32 + 0);
	// lfs f2,40(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 40);
	ctx.f2.f64 = double(temp.f32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82298908
	if (!ctx.cr0.eq) goto loc_82298908;
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// lfs f4,-1476(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -1476);
	ctx.f4.f64 = double(temp.f32);
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// lfs f3,36(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 36);
	ctx.f3.f64 = double(temp.f32);
	// std r10,368(r1)
	REX_STORE_U64(ctx.r1.u32 + 368, ctx.r10.u64);
	// lfd f13,368(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 368);
	// std r11,376(r1)
	REX_STORE_U64(ctx.r1.u32 + 376, ctx.r11.u64);
	// lfd f0,376(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 376);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r9,r1,448
	ctx.r9.s64 = ctx.r1.s64 + 448;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,480
	ctx.r7.s64 = ctx.r1.s64 + 480;
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// lfs f1,32(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 32);
	ctx.f1.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,364(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// stfs f13,352(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// stfs f13,360(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// stfs f13,356(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,480(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 480);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lfs f0,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// bl 0x8225dfd8
	ctx.lr = 0x82298904;
	sub_8225DFD8(ctx, base);
	// stb r3,0(r16)
	REX_STORE_U8(ctx.r16.u32 + 0, ctx.r3.u8);
loc_82298908:
	// extsw r10,r4
	ctx.r10.s64 = ctx.r4.s32;
	// lfs f0,24(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r5
	ctx.r11.s64 = ctx.r5.s32;
	// fmr f4,f2
	ctx.f4.f64 = ctx.f2.f64;
	// std r10,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r10.u64);
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// std r11,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r11.u64);
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// addi r9,r1,544
	ctx.r9.s64 = ctx.r1.s64 + 544;
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// addi r7,r1,512
	ctx.r7.s64 = ctx.r1.s64 + 512;
	// lfs f3,-10268(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -10268);
	ctx.f3.f64 = double(temp.f32);
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// lfs f1,16(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 16);
	ctx.f1.f64 = double(temp.f32);
	// lfd f12,176(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// lfd f13,184(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 184);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// stfs f11,300(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f11,296(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// stfs f11,292(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f12,316(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f11,288(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f12,312(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f12,308(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// stfs f12,304(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,512(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,544(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// bl 0x8225dfd8
	ctx.lr = 0x8229899C;
	sub_8225DFD8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822989a8
	if (ctx.cr0.eq) goto loc_822989A8;
	// stb r20,0(r18)
	REX_STORE_U8(ctx.r18.u32 + 0, ctx.r20.u8);
loc_822989A8:
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// stfs f12,324(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f12,320(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// addi r7,r1,256
	ctx.r7.s64 = ctx.r1.s64 + 256;
	// stfs f12,332(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// stfs f12,328(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// addi r9,r1,528
	ctx.r9.s64 = ctx.r1.s64 + 528;
	// stfs f12,264(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f12,260(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r14,r1,496
	ctx.r14.s64 = ctx.r1.s64 + 496;
	// stfs f12,256(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f12,268(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// addi r30,r1,160
	ctx.r30.s64 = ctx.r1.s64 + 160;
	// stfs f11,284(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r3,r1,208
	ctx.r3.s64 = ctx.r1.s64 + 208;
	// stfs f11,280(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f11,276(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f11,272(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f11,156(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f11,152(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f11,148(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lfs f4,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,-8(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,496(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stvx128 v60,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,528(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// bl 0x8225dfd8
	ctx.lr = 0x82298A60;
	sub_8225DFD8(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lfs f3,-12(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -12);
	ctx.f3.f64 = double(temp.f32);
	// lfs f1,-16(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -16);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8225dfd8
	ctx.lr = 0x82298A74;
	sub_8225DFD8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82298a88
	if (ctx.cr0.eq) goto loc_82298A88;
	// mr r14,r20
	ctx.r14.u64 = ctx.r20.u64;
	// stb r20,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r20.u8);
	// b 0x82298a8c
	goto loc_82298A8C;
loc_82298A88:
	// lbz r14,96(r1)
	ctx.r14.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
loc_82298A8C:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82298a98
	if (ctx.cr0.eq) goto loc_82298A98;
	// stb r20,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r20.u8);
loc_82298A98:
	// clrlwi r11,r8,24
	ctx.r11.u64 = ctx.r8.u32 & 0xFF;
	// cmplw cr6,r11,r21
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r21.u32, ctx.xer);
	// bne cr6,0x82298b40
	if (!ctx.cr6.eq) goto loc_82298B40;
	// cmpw cr6,r4,r19
	ctx.cr6.compare<int32_t>(ctx.r4.s32, ctx.r19.s32, ctx.xer);
	// bge cr6,0x82298b40
	if (!ctx.cr6.lt) goto loc_82298B40;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824299b8
	ctx.lr = 0x82298AB4;
	sub_824299B8(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r3,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// stwu r3,4(r28)
	ea = 4 + ctx.r28.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r28.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82298b40
	if (!ctx.cr6.eq) goto loc_82298B40;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82298b40
	if (ctx.cr6.eq) goto loc_82298B40;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82298B00;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82298b40
	if (!ctx.cr0.eq) goto loc_82298B40;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82298B1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82298b40
	if (!ctx.cr0.eq) goto loc_82298B40;
	// lbz r11,2364(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82298b40
	if (!ctx.cr0.eq) goto loc_82298B40;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stwu r31,4(r22)
	ea = 4 + ctx.r22.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r22.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_82298B40:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x822987e4
	if (ctx.cr6.lt) goto loc_822987E4;
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// bne cr6,0x82298cd0
	if (!ctx.cr6.eq) goto loc_82298CD0;
	// lwz r23,756(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 756);
	// li r14,0
	ctx.r14.s64 = 0;
loc_82298B60:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// mr r26,r14
	ctx.r26.u64 = ctx.r14.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82298fe4
	if (ctx.cr6.eq) goto loc_82298FE4;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// rlwinm r8,r17,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v127,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r27,r24,24
	ctx.r27.u64 = ctx.r24.u32 & 0xFF;
	// addi r28,r11,-4
	ctx.r28.s64 = ctx.r11.s64 + -4;
	// addi r30,r10,-4
	ctx.r30.s64 = ctx.r10.s64 + -4;
loc_82298B9C:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8242a650
	ctx.lr = 0x82298BA4;
	sub_8242A650(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82429a18
	ctx.lr = 0x82298BAC;
	sub_82429A18(ctx, base);
	// clrlwi r4,r31,24
	ctx.r4.u64 = ctx.r31.u32 & 0xFF;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82429668
	ctx.lr = 0x82298BB8;
	sub_82429668(ctx, base);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v127
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v127.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82298c1c
	if (ctx.cr6.eq) goto loc_82298C1C;
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.f0.u64);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.f0.u64);
	// lwz r4,188(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 188);
	// lwz r5,180(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 180);
	// bl 0x823aefa8
	ctx.lr = 0x82298C1C;
	sub_823AEFA8(ctx, base);
loc_82298C1C:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r11,r27
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82298cbc
	if (!ctx.cr6.eq) goto loc_82298CBC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824299b8
	ctx.lr = 0x82298C30;
	sub_824299B8(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r3,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 4) & 0xFFFF0;
	// stwu r3,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r30.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// bne cr6,0x82298cbc
	if (!ctx.cr6.eq) goto loc_82298CBC;
	// lwz r29,4(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82298cbc
	if (ctx.cr6.eq) goto loc_82298CBC;
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82298C7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82298cbc
	if (!ctx.cr0.eq) goto loc_82298CBC;
	// lwz r3,2340(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82298C98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82298cbc
	if (!ctx.cr0.eq) goto loc_82298CBC;
	// lbz r11,2364(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82298cbc
	if (!ctx.cr0.eq) goto loc_82298CBC;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stwu r31,4(r28)
	ea = 4 + ctx.r28.u32;
	REX_STORE_U32(ea, ctx.r31.u32);
	ctx.r28.u32 = ea;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_82298CBC:
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82298b9c
	if (ctx.cr6.lt) goto loc_82298B9C;
	// b 0x82298fdc
	goto loc_82298FDC;
loc_82298CD0:
	// addis r27,r15,1
	ctx.r27.s64 = ctx.r15.s64 + 65536;
	// addi r27,r27,-2196
	ctx.r27.s64 = ctx.r27.s64 + -2196;
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82298ed0
	if (!ctx.cr6.eq) goto loc_82298ED0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lbz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// addis r31,r15,1
	ctx.r31.s64 = ctx.r15.s64 + 65536;
	// ori r11,r11,63352
	ctx.r11.u64 = ctx.r11.u64 | 63352;
	// addi r31,r31,-2188
	ctx.r31.s64 = ctx.r31.s64 + -2188;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// li r28,100
	ctx.r28.s64 = 100;
	// lwzx r11,r15,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + ctx.r11.u32);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mulli r30,r11,20
	ctx.r30.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(20));
	// mulli r29,r10,70
	ctx.r29.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(70));
	// beq 0x82298db0
	if (ctx.cr0.eq) goto loc_82298DB0;
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82298D24;
	sub_825A49B0(ctx, base);
	// divw r10,r3,r28
	ctx.r10.u64 = uint32_t((ctx.r28.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r3.s32 / ctx.r28.s32 : 0);
	// addi r11,r30,50
	ctx.r11.s64 = ctx.r30.s64 + 50;
	// mulli r10,r10,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(100));
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82298db0
	if (!ctx.cr6.gt) goto loc_82298DB0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r11,r11,-29856
	ctx.r11.s64 = ctx.r11.s64 + -29856;
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// addi r8,r8,-29888
	ctx.r8.s64 = ctx.r8.s64 + -29888;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addic. r11,r10,-30
	ctx.xer.ca = ctx.r10.u32 > 29;
	ctx.r11.s64 = ctx.r10.s64 + -30;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r7,r7,63325
	ctx.r7.u64 = ctx.r7.u64 | 63325;
	// li r10,2
	ctx.r10.s64 = 2;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stbx r20,r15,r7
	REX_STORE_U8(ctx.r15.u32 + ctx.r7.u32, ctx.r20.u8);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// bge 0x82298da0
	if (!ctx.cr0.lt) goto loc_82298DA0;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82298DA0:
	// lwz r3,756(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 756);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// b 0x82299118
	goto loc_82299118;
loc_82298DB0:
	// clrlwi. r11,r14,24
	ctx.r11.u64 = ctx.r14.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82298e30
	if (ctx.cr0.eq) goto loc_82298E30;
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82298DC8;
	sub_825A49B0(ctx, base);
	// divw r10,r3,r28
	ctx.r10.u64 = uint32_t((ctx.r28.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r3.s32 / ctx.r28.s32 : 0);
	// addi r11,r29,30
	ctx.r11.s64 = ctx.r29.s64 + 30;
	// mulli r10,r10,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(100));
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82298e30
	if (!ctx.cr6.gt) goto loc_82298E30;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r11,-29904
	ctx.r11.s64 = ctx.r11.s64 + -29904;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// addi r9,r9,-29920
	ctx.r9.s64 = ctx.r9.s64 + -29920;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r11,r7,63326
	ctx.r11.u64 = ctx.r7.u64 | 63326;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,3
	ctx.r10.s64 = 3;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stbx r20,r15,r11
	REX_STORE_U8(ctx.r15.u32 + ctx.r11.u32, ctx.r20.u8);
loc_82298E28:
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// b 0x82298da0
	goto loc_82298DA0;
loc_82298E30:
	// lbz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82298eb4
	if (ctx.cr0.eq) goto loc_82298EB4;
	// li r4,10000
	ctx.r4.s64 = 10000;
	// lwz r5,4(r15)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r15.u32 + 4);
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x825a49b0
	ctx.lr = 0x82298E4C;
	sub_825A49B0(ctx, base);
	// divw r10,r3,r28
	ctx.r10.u64 = uint32_t((ctx.r28.s32 && !(ctx.r3.s32 == INT32_MIN && ctx.r28.s32 == -1)) ? ctx.r3.s32 / ctx.r28.s32 : 0);
	// addi r11,r29,30
	ctx.r11.s64 = ctx.r29.s64 + 30;
	// mulli r10,r10,100
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(100));
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82298eb4
	if (!ctx.cr6.gt) goto loc_82298EB4;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r11,-29936
	ctx.r11.s64 = ctx.r11.s64 + -29936;
	// addi r10,r10,-29952
	ctx.r10.s64 = ctx.r10.s64 + -29952;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ori r11,r7,63326
	ctx.r11.u64 = ctx.r7.u64 | 63326;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,4
	ctx.r10.s64 = 4;
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
	// stbx r20,r15,r11
	REX_STORE_U8(ctx.r15.u32 + ctx.r11.u32, ctx.r20.u8);
loc_82298E90:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// b 0x82298da0
	goto loc_82298DA0;
loc_82298EB4:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addic. r11,r11,-30
	ctx.xer.ca = ctx.r11.u32 > 29;
	ctx.r11.s64 = ctx.r11.s64 + -30;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bge 0x82298fd4
	if (!ctx.cr0.lt) goto loc_82298FD4;
	// li r14,0
	ctx.r14.s64 = 0;
	// stw r14,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r14.u32);
	// b 0x82298fd8
	goto loc_82298FD8;
loc_82298ED0:
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x82298f50
	if (!ctx.cr6.eq) goto loc_82298F50;
	// addis r11,r15,1
	ctx.r11.s64 = ctx.r15.s64 + 65536;
	// addi r11,r11,-2211
	ctx.r11.s64 = ctx.r11.s64 + -2211;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82298ef0
	if (!ctx.cr0.eq) goto loc_82298EF0;
	// stw r20,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r20.u32);
loc_82298EF0:
	// lbz r10,0(r18)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r18.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82298f34
	if (ctx.cr0.eq) goto loc_82298F34;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// addi r11,r11,-29888
	ctx.r11.s64 = ctx.r11.s64 + -29888;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r9,-29856
	ctx.r9.s64 = ctx.r9.s64 + -29856;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// b 0x82298e28
	goto loc_82298E28;
loc_82298F34:
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lbz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82298fd4
	if (ctx.cr0.eq) goto loc_82298FD4;
loc_82298F44:
	// li r14,0
	ctx.r14.s64 = 0;
	// stb r14,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r14.u8);
	// b 0x82298fd8
	goto loc_82298FD8;
loc_82298F50:
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bne cr6,0x82298f94
	if (!ctx.cr6.eq) goto loc_82298F94;
	// addis r11,r15,1
	ctx.r11.s64 = ctx.r15.s64 + 65536;
	// addi r11,r11,-2210
	ctx.r11.s64 = ctx.r11.s64 + -2210;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82298f70
	if (!ctx.cr0.eq) goto loc_82298F70;
	// stw r20,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r20.u32);
loc_82298F70:
	// clrlwi. r10,r14,24
	ctx.r10.u64 = ctx.r14.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82298f44
	if (ctx.cr0.eq) goto loc_82298F44;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r11,-29920
	ctx.r11.s64 = ctx.r11.s64 + -29920;
	// addi r10,r10,-29904
	ctx.r10.s64 = ctx.r10.s64 + -29904;
loc_82298F88:
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82298e90
	goto loc_82298E90;
loc_82298F94:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82298fd4
	if (!ctx.cr6.eq) goto loc_82298FD4;
	// addis r11,r15,1
	ctx.r11.s64 = ctx.r15.s64 + 65536;
	// addi r11,r11,-2209
	ctx.r11.s64 = ctx.r11.s64 + -2209;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x82298fb4
	if (!ctx.cr0.eq) goto loc_82298FB4;
	// stw r20,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r20.u32);
loc_82298FB4:
	// lbz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82298f44
	if (ctx.cr0.eq) goto loc_82298F44;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r11,r11,-29936
	ctx.r11.s64 = ctx.r11.s64 + -29936;
	// addi r10,r10,-29952
	ctx.r10.s64 = ctx.r10.s64 + -29952;
	// b 0x82298f88
	goto loc_82298F88;
loc_82298FD4:
	// li r14,0
	ctx.r14.s64 = 0;
loc_82298FD8:
	// lwz r23,756(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 756);
loc_82298FDC:
	// cmplwi cr6,r17,0
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 0, ctx.xer);
	// bne cr6,0x82299048
	if (!ctx.cr6.eq) goto loc_82299048;
loc_82298FE4:
	// lwz r11,4(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 4);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x82298FF4;
	sub_825A4A90(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82299008;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13068(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13068);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229903c
	if (ctx.cr6.eq) goto loc_8229903C;
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// divwu r9,r3,r10
	ctx.r9.u64 = uint32_t(ctx.r10.u32 ? ctx.r3.u32 / ctx.r10.u32 : 0);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r10,r9,r10
	ctx.r10.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r10,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// b 0x82299040
	goto loc_82299040;
loc_8229903C:
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
loc_82299040:
	// stw r4,44(r15)
	REX_STORE_U32(ctx.r15.u32 + 44, ctx.r4.u32);
	// b 0x8229910c
	goto loc_8229910C;
loc_82299048:
	// cmplwi cr6,r17,1
	ctx.cr6.compare<uint32_t>(ctx.r17.u32, 1, ctx.xer);
	// bne cr6,0x82299058
	if (!ctx.cr6.eq) goto loc_82299058;
	// lwz r4,416(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 416);
	// b 0x8229910c
	goto loc_8229910C;
loc_82299058:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822990ac
	if (!ctx.cr6.eq) goto loc_822990AC;
	// lwz r11,4(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 4);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x82299074;
	sub_825A4A90(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82299088;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// divwu r9,r3,r17
	ctx.r9.u64 = uint32_t(ctx.r17.u32 ? ctx.r3.u32 / ctx.r17.u32 : 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mullw r9,r9,r17
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r17.s32);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// twllei r17,0
	if (ctx.r17.s32 == 0 || ctx.r17.u32 < 0u) ppc_trap(ctx, base, 0);
	// lwzx r4,r11,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// b 0x82299040
	goto loc_82299040;
loc_822990AC:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x822990bc
	if (!ctx.cr6.eq) goto loc_822990BC;
	// lwz r4,384(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 384);
	// b 0x82299040
	goto loc_82299040;
loc_822990BC:
	// lwz r11,4(r15)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r15.u32 + 4);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x825a4a90
	ctx.lr = 0x822990CC;
	sub_825A4A90(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822990E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// divwu r8,r3,r11
	ctx.r8.u64 = uint32_t(ctx.r11.u32 ? ctx.r3.u32 / ctx.r11.u32 : 0);
	// twllei r11,0
	if (ctx.r11.s32 == 0 || ctx.r11.u32 < 0u) ppc_trap(ctx, base, 0);
	// mullw r11,r8,r11
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// subf r11,r11,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r9
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// b 0x82299040
	goto loc_82299040;
loc_82299108:
	// lwz r4,44(r15)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r15.u32 + 44);
loc_8229910C:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x8223f3c0
	ctx.lr = 0x82299114;
	sub_8223F3C0(ctx, base);
loc_82299114:
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
loc_82299118:
	// addi r1,r1,736
	ctx.r1.s64 = ctx.r1.s64 + 736;
	// li r0,-176
	ctx.r0.s64 = -176;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822F70A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x822F70B0;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 40);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822f7474
	if (ctx.cr0.eq) goto loc_822F7474;
	// lfs f0,44(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// lbz r10,41(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 41);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,44(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 44, temp.u32);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x822f70ec
	if (!ctx.cr0.eq) goto loc_822F70EC;
	// lfs f13,48(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 48);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x822f7474
	if (!ctx.cr6.gt) goto loc_822F7474;
loc_822F70EC:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r29,1
	ctx.r29.s64 = 1;
	// addi r28,r11,12236
	ctx.r28.s64 = ctx.r11.s64 + 12236;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lfs f31,232(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// bne cr6,0x822f710c
	if (!ctx.cr6.eq) goto loc_822F710C;
	// stfs f31,44(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stb r29,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r29.u8);
loc_822F710C:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f1,140(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f1,136(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r26,r1,128
	ctx.r26.s64 = ctx.r1.s64 + 128;
	// stfs f1,128(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f1,132(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,32(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r25,r1,112
	ctx.r25.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r24,r1,128
	ctx.r24.s64 = ctx.r1.s64 + 128;
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r1,128
	ctx.r23.s64 = ctx.r1.s64 + 128;
	// lfs f0,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// addi r22,r1,128
	ctx.r22.s64 = ctx.r1.s64 + 128;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r30,r31,12
	ctx.r30.s64 = ctx.r31.s64 + 12;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,28(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
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
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
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
	// lvx128 v59,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f1,108(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f1,104(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f1,100(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f1,96(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// lvx128 v61,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,20(r31)
	REX_STORE_U64(ctx.r31.u32 + 20, ctx.r11.u64);
	// lfs f0,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f13,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x822F72A8;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,8
	ctx.r10.s64 = 8;
	// li r9,12
	ctx.r9.s64 = 12;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r8.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.f0.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.f0.u32);
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f0,52(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f13,56(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 56);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f1,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f1.f64, ctx.f13.f64)));
	// stfs f0,56(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// bl 0x822f7480
	ctx.lr = 0x822F7304;
	sub_822F7480(ctx, base);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// fctiwz f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f1.f64) ? int64_t(0x80000000U) : (ctx.f1.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f1.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// lwz r10,-13032(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x822f7340
	if (ctx.cr6.eq) goto loc_822F7340;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// lwz r10,12(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r4,8(r9)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x823af008
	ctx.lr = 0x822F7340;
	sub_823AF008(ctx, base);
loc_822F7340:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822f7414
	if (ctx.cr0.eq) goto loc_822F7414;
	// lbz r11,42(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 42);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822f7368
	if (!ctx.cr0.eq) goto loc_822F7368;
	// lfs f2,16(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x822f6e20
	ctx.lr = 0x822F7360;
	sub_822F6E20(ctx, base);
	// stfs f31,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 44, temp.u32);
	// stb r29,42(r31)
	REX_STORE_U8(ctx.r31.u32 + 42, ctx.r29.u8);
loc_822F7368:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,24(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,-30880
	ctx.r8.s64 = ctx.r8.s64 + -30880;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lfs f0,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r10,r10,32256
	ctx.r10.s64 = ctx.r10.s64 + 32256;
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// vmulfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,-29492(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29492);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fabs f12,f0
	ctx.f12.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// stfs f0,24(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// bge cr6,0x822f7414
	if (!ctx.cr6.lt) goto loc_822F7414;
	// stfs f31,20(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// stfs f31,24(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 24, temp.u32);
	// stfs f31,28(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 28, temp.u32);
	// stfs f31,32(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 32, temp.u32);
	// stfs f31,52(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
loc_822F7414:
	// lbz r11,42(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 42);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822f7474
	if (ctx.cr0.eq) goto loc_822F7474;
	// lfs f12,44(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,2140(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 2140);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// bge cr6,0x822f746c
	if (!ctx.cr6.lt) goto loc_822F746C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lfs f0,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// lfs f0,412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r11,r11,-256
	ctx.xer.ca = ctx.r11.u32 <= 4294967040;
	ctx.r11.u64 = static_cast<uint64_t>(-256) - ctx.r11.u64;
	// stw r11,4(r9)
	REX_STORE_U32(ctx.r9.u32 + 4, ctx.r11.u32);
	// b 0x822f7474
	goto loc_822F7474;
loc_822F746C:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r11.u8);
loc_822F7474:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8231AEF8) {
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
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f0,4(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r7,-32115
	ctx.r7.s64 = -2104688640;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f0,27048(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 27048);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r7,22072
	ctx.r10.s64 = ctx.r7.s64 + 22072;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// li r4,100
	ctx.r4.s64 = 100;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,48(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x825e02a0
	ctx.lr = 0x8231AF84;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8231afe8
	if (ctx.cr0.eq) goto loc_8231AFE8;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f0,-30100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30100);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r7,-4080
	ctx.r11.s64 = ctx.r7.s64 + -4080;
	// fmuls f12,f31,f0
	ctx.f12.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f0,1608(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1608);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfs f13,14376(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 14376);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f1,244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 244);
	ctx.f1.f64 = double(temp.f32);
	// fctiwz f0,f12
	ctx.f0.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// subfic r11,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r11.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x82218490
	ctx.lr = 0x8231AFE0;
	sub_82218490(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8231afec
	goto loc_8231AFEC;
loc_8231AFE8:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8231AFEC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8231b030
	if (ctx.cr6.eq) goto loc_8231B030;
	// lis r11,-32206
	ctx.r11.s64 = -2110652416;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r11,r11,-21024
	ctx.r11.s64 = ctx.r11.s64 + -21024;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// bl 0x82222ad8
	ctx.lr = 0x8231B00C;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8231b030
	if (!ctx.cr6.eq) goto loc_8231B030;
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
	ctx.lr = 0x8231B030;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8231B030:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
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

DEFINE_REX_FUNC(sub_82329C68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82329C70;
	__savegprlr_23(ctx, base);
	// stwu r1,-480(r1)
	ea = -480 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,466(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 466);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82329f5c
	if (!ctx.cr0.eq) goto loc_82329F5C;
	// lwz r25,264(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r24,-1
	ctx.r24.s64 = -1;
	// lwz r23,268(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// stw r24,452(r3)
	REX_STORE_U32(ctx.r3.u32 + 452, ctx.r24.u32);
	// cmplw cr6,r25,r23
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r23.u32, ctx.xer);
	// beq cr6,0x82329f5c
	if (ctx.cr6.eq) goto loc_82329F5C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// addi r26,r11,2668
	ctx.r26.s64 = ctx.r11.s64 + 2668;
	// addi r29,r10,2688
	ctx.r29.s64 = ctx.r10.s64 + 2688;
	// addi r28,r9,2880
	ctx.r28.s64 = ctx.r9.s64 + 2880;
loc_82329CB8:
	// lwz r31,0(r25)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329CD0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82329f50
	if (!ctx.cr0.eq) goto loc_82329F50;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329CEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82329f50
	if (ctx.cr0.eq) goto loc_82329F50;
	// lhz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x82329D00;
	sub_823BFA70(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329D24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82329f50
	if (ctx.cr0.eq) goto loc_82329F50;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329D44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,124(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stw r7,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r7.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lwa r4,140(r1)
	ctx.r4.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 140));
	// lwa r31,132(r1)
	ctx.r31.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 132));
	// lfs f13,120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwa r7,128(r1)
	ctx.r7.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 128));
	// std r7,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r7.u64);
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// std r7,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r7.u64);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// lwa r3,136(r1)
	ctx.r3.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 136));
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// std r4,320(r1)
	REX_STORE_U64(ctx.r1.u32 + 320, ctx.r4.u64);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// std r3,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r3.u64);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// lfd f9,272(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
	// addi r8,r1,336
	ctx.r8.s64 = ctx.r1.s64 + 336;
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfd f12,280(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 280);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lwz r31,-13032(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + -13032);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stw r29,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r29.u32);
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// stfs f9,204(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f9,200(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// stfs f9,196(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f9,192(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f11,320(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 320);
	// lfd f10,312(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 312);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// frsp f11,f11
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// stfs f11,252(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f11,248(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f11,244(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f11,240(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f10,236(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f10,232(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f10,228(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f10,224(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// lfs f12,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,384(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r10,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r10.u64);
	// lfs f11,352(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f11.f64 = double(temp.f32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,112(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r11.u64);
	// beq cr6,0x82329f00
	if (ctx.cr6.eq) goto loc_82329F00;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,328(r1)
	REX_STORE_U64(ctx.r1.u32 + 328, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,332(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 332);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x82329EFC;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_82329F00:
	// lfs f0,168(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f1,520(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 520);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82329f48
	if (ctx.cr6.eq) goto loc_82329F48;
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// bl 0x823b0938
	ctx.lr = 0x82329F44;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82329F48:
	// stw r11,452(r30)
	REX_STORE_U32(ctx.r30.u32 + 452, ctx.r11.u32);
	// stw r26,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r26.u32);
loc_82329F50:
	// addi r25,r25,4
	ctx.r25.s64 = ctx.r25.s64 + 4;
	// cmplw cr6,r25,r23
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r23.u32, ctx.xer);
	// bne cr6,0x82329cb8
	if (!ctx.cr6.eq) goto loc_82329CB8;
loc_82329F5C:
	// addi r1,r1,480
	ctx.r1.s64 = ctx.r1.s64 + 480;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8233FB68) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,18240
	ctx.r11.s64 = ctx.r11.s64 + 18240;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82231c80
	ctx.lr = 0x8233FB94;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8233fba4
	if (ctx.cr0.eq) goto loc_8233FBA4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8233FBA4;
	sub_825E0378(ctx, base);
loc_8233FBA4:
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

DEFINE_REX_FUNC(sub_82342150) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82342158;
	__savegprlr_29(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// ld r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 96);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x8222ff78
	ctx.lr = 0x8234217C;
	sub_8222FF78(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f11,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ori r6,r6,62376
	ctx.r6.u64 = ctx.r6.u64 | 62376;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,88(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lwzx r11,r31,r6
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r6.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// neg r6,r11
	ctx.r6.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f10,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f10.f64 = double(temp.f32);
	// fctiwz f10,f10
	ctx.f10.s64 = std::isnan(ctx.f10.f64) ? int64_t(0x80000000U) : (ctx.f10.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f10.f64));
	// stfd f10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f9,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f9.f64 = double(temp.f32);
	// fctiwz f10,f9
	ctx.f10.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// lwz r9,92(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpw cr6,r6,r10
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82342370
	if (!ctx.cr6.lt) goto loc_82342370;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82342370
	if (!ctx.cr6.lt) goto loc_82342370;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// neg r10,r11
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82342370
	if (!ctx.cr6.lt) goto loc_82342370;
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// bge cr6,0x82342370
	if (!ctx.cr6.lt) goto loc_82342370;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823422a0
	if (ctx.cr6.eq) goto loc_823422A0;
	// fctiwz f10,f13
	ctx.f10.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f9,f0
	ctx.f9.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// stfd f9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f9.u64);
	// lwz r5,92(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x8234229C;
	sub_823AEFA8(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_823422A0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823422cc
	if (ctx.cr6.eq) goto loc_823422CC;
	// fctiwz f10,f12
	ctx.fpscr.disableFlushMode();
	ctx.f10.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f10.u64);
	// fctiwz f10,f11
	ctx.f10.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfd f10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f10.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823aefa8
	ctx.lr = 0x823422CC;
	sub_823AEFA8(ctx, base);
loc_823422CC:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r29,24
	ctx.r10.u64 = ctx.r29.u32 & 0xFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823422e4
	if (!ctx.cr6.eq) goto loc_823422E4;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82342374
	goto loc_82342374;
loc_823422E4:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// stw r30,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r30.u32);
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
	// stw r30,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r30.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stw r30,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r30.u32);
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// std r11,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r11.u64);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82342364
	if (ctx.cr6.eq) goto loc_82342364;
	// fctiwz f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r7,92(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// li r8,3
	ctx.r8.s64 = 3;
	// fctiwz f13,f12
	ctx.f13.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r6,84(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x823af5b0
	ctx.lr = 0x82342364;
	sub_823AF5B0(ctx, base);
loc_82342364:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,1
	ctx.r3.s64 = 1;
	// beq 0x82342374
	if (ctx.cr0.eq) goto loc_82342374;
loc_82342370:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82342374:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823554B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823554B8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,19456
	ctx.r11.s64 = ctx.r11.s64 + 19456;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82358ed8
	ctx.lr = 0x823554D4;
	sub_82358ED8(ctx, base);
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r11,-792
	ctx.r11.s64 = ctx.r11.s64 + -792;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x823554f8
	if (ctx.cr6.eq) goto loc_823554F8;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,23(r10)
	REX_STORE_U8(ctx.r10.u32 + 23, ctx.r9.u8);
	// stw r28,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r28.u32);
loc_823554F8:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-768
	ctx.r30.s64 = ctx.r30.s64 + -768;
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82355514
	if (ctx.cr6.eq) goto loc_82355514;
	// bl 0x8221bd98
	ctx.lr = 0x82355510;
	sub_8221BD98(ctx, base);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
loc_82355514:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// li r29,18
	ctx.r29.s64 = 18;
	// addi r11,r11,-1616
	ctx.r11.s64 = ctx.r11.s64 + -1616;
	// addi r30,r11,64
	ctx.r30.s64 = ctx.r11.s64 + 64;
loc_82355524:
	// lwzu r3,-80(r30)
	ea = -80 + ctx.r30.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82355534
	if (ctx.cr6.eq) goto loc_82355534;
	// bl 0x825e0378
	ctx.lr = 0x82355534;
	sub_825E0378(ctx, base);
loc_82355534:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r28,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r28.u32);
	// stw r28,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r28.u32);
	// stw r28,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r28.u32);
	// bge 0x82355524
	if (!ctx.cr0.lt) goto loc_82355524;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82231c80
	ctx.lr = 0x82355550;
	sub_82231C80(ctx, base);
	// clrlwi. r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82355560
	if (ctx.cr0.eq) goto loc_82355560;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82355560;
	sub_825E0378(ctx, base);
loc_82355560:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8235A078) {
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
	// bl 0x82230a18
	ctx.lr = 0x8235A094;
	sub_82230A18(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,31
	ctx.r4.s64 = 31;
	// stb r11,285(r31)
	REX_STORE_U8(ctx.r31.u32 + 285, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232b18
	ctx.lr = 0x8235A0A8;
	sub_82232B18(ctx, base);
	// li r4,22
	ctx.r4.s64 = 22;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82232b18
	ctx.lr = 0x8235A0B4;
	sub_82232B18(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r10,r11,-20372
	ctx.r10.s64 = ctx.r11.s64 + -20372;
	// addi r30,r30,-3148
	ctx.r30.s64 = ctx.r30.s64 + -3148;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f1,-20372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20372);
	ctx.f1.f64 = double(temp.f32);
	// lfs f0,22872(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 22872);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lfs f2,-8956(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8956);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x8235A0E0;
	sub_825A4A40(ctx, base);
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
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

DEFINE_REX_FUNC(sub_8235DD48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r9,2
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 2, ctx.xer);
	// ble cr6,0x8235dd68
	if (!ctx.cr6.gt) goto loc_8235DD68;
	// li r10,1
	ctx.r10.s64 = 1;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235DD68:
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lwz r9,3652(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 3652);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8235dd88
	if (ctx.cr6.eq) goto loc_8235DD88;
	// clrlwi. r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8235dd88
	if (!ctx.cr0.eq) goto loc_8235DD88;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235DD88:
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// clrlwi. r7,r10,24
	ctx.r7.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// add r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 + ctx.r8.u64;
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// beq 0x8235ddac
	if (ctx.cr0.eq) goto loc_8235DDAC;
	// li r9,3
	ctx.r9.s64 = 3;
	// subfc r10,r9,r10
	ctx.xer.ca = ctx.r10.u32 >= ctx.r9.u32;
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
loc_8235DDAC:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8235F358) {
	REX_FUNC_PROLOGUE();
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lwz r10,152(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r3,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 2;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8235F848) {
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
	// lbz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 124);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r3,96
	ctx.r31.s64 = ctx.r3.s64 + 96;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8235f878
	if (ctx.cr0.eq) goto loc_8235F878;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b44
	ctx.lr = 0x8235F878;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8235F878:
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// lwz r30,128(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 128);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8235f890
	if (ctx.cr0.eq) goto loc_8235F890;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82855b34
	ctx.lr = 0x8235F890;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8235F890:
	// rlwinm r3,r30,30,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 30) & 0x1;
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

DEFINE_REX_FUNC(sub_823607D0) {
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
	// lwz r3,184(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,20328
	ctx.r11.s64 = ctx.r11.s64 + 20328;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// beq cr6,0x82360804
	if (ctx.cr6.eq) goto loc_82360804;
	// bl 0x8221bd98
	ctx.lr = 0x82360804;
	sub_8221BD98(ctx, base);
loc_82360804:
	// lwz r3,152(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 152);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82360820
	if (ctx.cr6.eq) goto loc_82360820;
	// bl 0x8221cc98
	ctx.lr = 0x8236081C;
	sub_8221CC98(ctx, base);
	// stw r30,152(r31)
	REX_STORE_U32(ctx.r31.u32 + 152, ctx.r30.u32);
loc_82360820:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r3,r31,156
	ctx.r3.s64 = ctx.r31.s64 + 156;
	// addi r11,r11,-27424
	ctx.r11.s64 = ctx.r11.s64 + -27424;
	// stw r11,156(r31)
	REX_STORE_U32(ctx.r31.u32 + 156, ctx.r11.u32);
	// bl 0x8245d0d8
	ctx.lr = 0x82360834;
	sub_8245D0D8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,2668
	ctx.r11.s64 = ctx.r11.s64 + 2668;
	// stw r11,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r11.u32);
	// bl 0x825a1938
	ctx.lr = 0x82360848;
	sub_825A1938(ctx, base);
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

DEFINE_REX_FUNC(sub_82364918) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r9,24(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r8,20(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r9,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 2;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82364954
	if (!ctx.cr6.lt) goto loc_82364954;
	// rotlwi r11,r8,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_82364954:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_823665E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823665F0;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82366730
	if (ctx.cr6.eq) goto loc_82366730;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82366728
	if (ctx.cr6.eq) goto loc_82366728;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f31,-9856(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9856);
	ctx.f31.f64 = double(temp.f32);
loc_82366628:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82366714
	if (ctx.cr0.eq) goto loc_82366714;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,40(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslw128 v61,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lfs f0,36(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stb r27,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r27.u8);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// li r10,-256
	ctx.r10.s64 = -256;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v62,v62,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lbz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 60);
	// lfs f12,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f12.f64 = double(temp.f32);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lhz r8,102(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// lfs f13,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// sth r8,116(r31)
	REX_STORE_U16(ctx.r31.u32 + 116, ctx.r8.u16);
	// fctiwz f0,f12
	ctx.f0.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lhz r8,102(r1)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r1.u32 + 102);
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// sth r8,118(r31)
	REX_STORE_U16(ctx.r31.u32 + 118, ctx.r8.u16);
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f13.u64);
	// lfs f0,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// lbz r8,111(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 111);
	// lfs f13,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// or r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 | ctx.r10.u64;
	// lfs f1,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
	// lhz r4,16(r29)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r29.u32 + 16);
	// bl 0x823c09e0
	ctx.lr = 0x82366714;
	sub_823C09E0(ctx, base);
loc_82366714:
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// lwz r11,32(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 32);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82366628
	if (!ctx.cr6.eq) goto loc_82366628;
loc_82366728:
	// sth r27,116(r31)
	REX_STORE_U16(ctx.r31.u32 + 116, ctx.r27.u16);
	// sth r27,118(r31)
	REX_STORE_U16(ctx.r31.u32 + 118, ctx.r27.u16);
loc_82366730:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823701F8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,21636
	ctx.r3.s64 = ctx.r11.s64 + 21636;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82370300) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82370308;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r9,4(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// li r7,12
	ctx.r7.s64 = 12;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// bl 0x8236de80
	ctx.lr = 0x8237033C;
	sub_8236DE80(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r29,20
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 20, ctx.xer);
	// stw r11,464(r30)
	REX_STORE_U32(ctx.r30.u32 + 464, ctx.r11.u32);
	// blt cr6,0x82370374
	if (ctx.cr6.lt) goto loc_82370374;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// rlwinm r9,r11,18,14,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 18) & 0x3FFFC;
	// addi r10,r10,17432
	ctx.r10.s64 = ctx.r10.s64 + 17432;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,472(r30)
	REX_STORE_U32(ctx.r30.u32 + 472, ctx.r11.u32);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// stw r11,476(r30)
	REX_STORE_U32(ctx.r30.u32 + 476, ctx.r11.u32);
loc_82370374:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82374138) {
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
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82374160;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82374414
	if (!ctx.cr0.eq) goto loc_82374414;
	// lbz r11,10328(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 10328);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82374414
	if (!ctx.cr0.eq) goto loc_82374414;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lbz r10,10280(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10280);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lwz r8,268(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// li r30,0
	ctx.r30.s64 = 0;
	// li r7,-1
	ctx.r7.s64 = -1;
	// li r5,8
	ctx.r5.s64 = 8;
	// stw r30,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r30.u32);
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// addi r4,r31,10256
	ctx.r4.s64 = ctx.r31.s64 + 10256;
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stw r7,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r7.u32);
	// stb r10,136(r1)
	REX_STORE_U8(ctx.r1.u32 + 136, ctx.r10.u8);
	// ori r6,r6,64
	ctx.r6.u64 = ctx.r6.u64 | 64;
	// stw r5,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// cmpwi cr6,r8,2
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 2, ctx.xer);
	// stw r30,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r30.u32);
	// stw r30,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r30.u32);
	// std r11,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r11.u64);
	// stw r30,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r30.u32);
	// stw r4,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r4.u32);
	// bgt cr6,0x823741dc
	if (ctx.cr6.gt) goto loc_823741DC;
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// ori r6,r6,65
	ctx.r6.u64 = ctx.r6.u64 | 65;
loc_823741DC:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stw r30,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r30.u32);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// stb r30,124(r1)
	REX_STORE_U8(ctx.r1.u32 + 124, ctx.r30.u8);
	// stw r30,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r30,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r30.u32);
	// stb r30,125(r1)
	REX_STORE_U8(ctx.r1.u32 + 125, ctx.r30.u8);
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82374220
	if (ctx.cr6.eq) goto loc_82374220;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// bl 0x823b0d90
	ctx.lr = 0x8237421C;
	sub_823B0D90(ctx, base);
	// lwz r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
loc_82374220:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82374414
	if (ctx.cr0.eq) goto loc_82374414;
	// lwz r9,16(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82374414
	if (ctx.cr6.eq) goto loc_82374414;
	// lwz r11,4(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823742cc
	if (ctx.cr0.eq) goto loc_823742CC;
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82217c38
	ctx.lr = 0x82374254;
	sub_82217C38(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r31,10316
	ctx.r4.s64 = ctx.r31.s64 + 10316;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,10316(r31)
	REX_STORE_U32(ctx.r31.u32 + 10316, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,10320(r31)
	REX_STORE_U32(ctx.r31.u32 + 10320, ctx.r11.u32);
	// bl 0x8231e0d8
	ctx.lr = 0x82374274;
	sub_8231E0D8(ctx, base);
	// lwz r7,0(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lis r8,-32227
	ctx.r8.s64 = -2112028672;
	// stw r7,10316(r31)
	REX_STORE_U32(ctx.r31.u32 + 10316, ctx.r7.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,10320(r31)
	REX_STORE_U32(ctx.r31.u32 + 10320, ctx.r11.u32);
	// lfs f13,10320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 10320);
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,30184(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 30184);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,10320(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 10320, temp.u32);
	// b 0x82374408
	goto loc_82374408;
loc_823742CC:
	// rlwinm. r11,r11,0,1,1
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82374418
	if (ctx.cr0.eq) goto loc_82374418;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x823742f8
	if (!ctx.cr6.eq) goto loc_823742F8;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
loc_823742F8:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// rlwinm. r11,r11,26,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 26) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82374418
	if (ctx.cr0.eq) goto loc_82374418;
	// addi r4,r7,32
	ctx.r4.s64 = ctx.r7.s64 + 32;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x82374310;
	sub_8231E0D8(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stw r6,10316(r31)
	REX_STORE_U32(ctx.r31.u32 + 10316, ctx.r6.u32);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lwz r6,4(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r6,10320(r31)
	REX_STORE_U32(ctx.r31.u32 + 10320, ctx.r6.u32);
	// lfs f0,10320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 10320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r5,32256
	ctx.r5.s64 = ctx.r5.s64 + 32256;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,10320(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 10320, temp.u32);
	// lfs f0,36(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,32(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// lvx128 v6,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v12,v0,v6
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)));
	// lfs f0,27412(r30)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 27412);
	ctx.f0.f64 = double(temp.f32);
	// vcmpeqfp128 v10,v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
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
	// stvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// stfs f13,10324(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 10324, temp.u32);
	// blt cr6,0x8237440c
	if (ctx.cr6.lt) goto loc_8237440C;
loc_82374408:
	// stfs f0,10324(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 10324, temp.u32);
loc_8237440C:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82374418
	goto loc_82374418;
loc_82374414:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82374418:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

DEFINE_REX_FUNC(sub_82389368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82389370;
	__savegprlr_26(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389388;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823894dc
	if (ctx.cr0.eq) goto loc_823894DC;
	// lbz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 296);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823894dc
	if (ctx.cr0.eq) goto loc_823894DC;
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// addi r30,r31,300
	ctx.r30.s64 = ctx.r31.s64 + 300;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823893B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,0
	ctx.r26.s64 = 0;
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,-13032(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + -13032);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8238943c
	if (ctx.cr6.eq) goto loc_8238943C;
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x823aefa8
	ctx.lr = 0x82389438;
	sub_823AEFA8(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
loc_8238943C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389450;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,180(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 180);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389468;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,184(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 184);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82389480;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-13032(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823894b8
	if (ctx.cr6.eq) goto loc_823894B8;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r11,2880
	ctx.r10.s64 = ctx.r11.s64 + 2880;
	// mr r8,r27
	ctx.r8.u64 = ctx.r27.u64;
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823b0938
	ctx.lr = 0x823894B8;
	sub_823B0938(ctx, base);
loc_823894B8:
	// lwz r11,236(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 236);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x823894dc
	if (!ctx.cr6.eq) goto loc_823894DC;
	// addi r4,r31,256
	ctx.r4.s64 = ctx.r31.s64 + 256;
	// addi r3,r31,248
	ctx.r3.s64 = ctx.r31.s64 + 248;
	// bl 0x8235fad0
	ctx.lr = 0x823894D0;
	sub_8235FAD0(ctx, base);
	// addic r11,r3,-1
	ctx.xer.ca = ctx.r3.u32 > 0;
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// subfe r11,r11,r3
	temp.u8 = (~ctx.r11.u32 + ctx.r3.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r3.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r3.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,244(r31)
	REX_STORE_U8(ctx.r31.u32 + 244, ctx.r11.u8);
loc_823894DC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823922D8) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,27776
	ctx.r3.s64 = ctx.r11.s64 + 27776;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82392620) {
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
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r4,19
	ctx.r4.s64 = 19;
	// addi r3,r10,7524
	ctx.r3.s64 = ctx.r10.s64 + 7524;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82392650;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x82392654;
	sub_8245A220(ctx, base);
	// stw r3,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r3.u32);
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

DEFINE_REX_FUNC(sub_82394418) {
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
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// cmplwi cr6,r11,521
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 521, ctx.xer);
	// beq cr6,0x823944b0
	if (ctx.cr6.eq) goto loc_823944B0;
	// cmplwi cr6,r11,522
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 522, ctx.xer);
	// beq cr6,0x82394454
	if (ctx.cr6.eq) goto loc_82394454;
	// bl 0x8235f668
	ctx.lr = 0x82394450;
	sub_8235F668(ctx, base);
	// b 0x823944f4
	goto loc_823944F4;
loc_82394454:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82394474
	if (ctx.cr6.eq) goto loc_82394474;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82364590
	ctx.lr = 0x82394474;
	sub_82364590(ctx, base);
loc_82394474:
	// lbz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 20);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe. r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge 0x82394498
	if (!ctx.cr0.lt) goto loc_82394498;
	// lbz r11,234(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 234);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// b 0x823944a0
	goto loc_823944A0;
loc_82394498:
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_823944A0:
	// lwz r9,272(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x823944f4
	if (!ctx.cr6.eq) goto loc_823944F4;
	// b 0x823944ec
	goto loc_823944EC;
loc_823944B0:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-13060(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823944d0
	if (ctx.cr6.eq) goto loc_823944D0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82364590
	ctx.lr = 0x823944D0;
	sub_82364590(ctx, base);
loc_823944D0:
	// lwz r11,272(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 272);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823944f4
	if (!ctx.cr6.eq) goto loc_823944F4;
	// lbz r11,234(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 234);
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_823944EC:
	// stb r11,252(r31)
	REX_STORE_U8(ctx.r31.u32 + 252, ctx.r11.u8);
	// stw r10,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r10.u32);
loc_823944F4:
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

DEFINE_REX_FUNC(sub_8239DFF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8239DFF8;
	__savegprlr_23(ctx, base);
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af20
	ctx.lr = 0x8239E000;
	__savefpr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f1.f64;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r30,r11,13168
	ctx.r30.s64 = ctx.r11.s64 + 13168;
	// lwz r11,232(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 232);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r23,1
	ctx.r23.s64 = 1;
	// li r24,-1
	ctx.r24.s64 = -1;
	// lfs f26,-700(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -700);
	ctx.f26.f64 = double(temp.f32);
	// addi r26,r10,2500
	ctx.r26.s64 = ctx.r10.s64 + 2500;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8239e6e4
	if (ctx.cr6.gt) goto loc_8239E6E4;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x8239e0d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8239E0D8;
	// bdzf 4*cr6+eq,0x8239e18c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8239E18C;
	// bdzf 4*cr6+eq,0x8239e23c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8239E23C;
	// bdzf 4*cr6+eq,0x8239e264
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8239E264;
	// bdzf 4*cr6+eq,0x8239e4c4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8239E4C4;
	// bdzf 4*cr6+eq,0x8239e598
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_8239E598;
	// bne cr6,0x8239e668
	if (!ctx.cr6.eq) goto loc_8239E668;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235fd60
	ctx.lr = 0x8239E064;
	sub_8235FD60(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,336(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// mulli r10,r10,52
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(52));
	// lwz r11,-12824(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12824);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8239e09c
	if (ctx.cr6.eq) goto loc_8239E09C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x8239e09c
	if (ctx.cr6.eq) goto loc_8239E09C;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// bne cr6,0x8239e0a0
	if (!ctx.cr6.eq) goto loc_8239E0A0;
loc_8239E09C:
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8239E0A0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8239e6e4
	if (!ctx.cr0.eq) goto loc_8239E6E4;
	// lwz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8239e6e4
	if (!ctx.cr6.eq) goto loc_8239E6E4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8239eea8
	ctx.lr = 0x8239E0BC;
	sub_8239EEA8(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,96(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 96);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239E0D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r23,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r23.u32);
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E0D8:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x8239e6e4
	if (ctx.cr6.eq) goto loc_8239E6E4;
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8239e148
	if (ctx.cr6.eq) goto loc_8239E148;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8239E10C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239e140
	if (ctx.cr0.eq) goto loc_8239E140;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r8,328(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// li r9,523
	ctx.r9.s64 = 523;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r25,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r25.u32);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r8,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// b 0x8239e144
	goto loc_8239E144;
loc_8239E140:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_8239E144:
	// bl 0x825a2ef8
	ctx.lr = 0x8239E148;
	sub_825A2EF8(ctx, base);
loc_8239E148:
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// addi r11,r26,17268
	ctx.r11.s64 = ctx.r26.s64 + 17268;
	// li r9,2
	ctx.r9.s64 = 2;
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mulli r10,r10,36
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(36));
	// stfs f26,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// stw r9,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r9.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8239e17c
	if (!ctx.cr6.eq) goto loc_8239E17C;
	// lwz r5,8(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8239e180
	goto loc_8239E180;
loc_8239E17C:
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_8239E180:
	// li r3,416
	ctx.r3.s64 = 416;
loc_8239E184:
	// bl 0x82240a58
	ctx.lr = 0x8239E188;
	sub_82240A58(ctx, base);
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E18C:
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// fadds f13,f0,f27
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// lfs f30,-932(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -932);
	ctx.f30.f64 = double(temp.f32);
	// stfs f13,236(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// lfs f0,31848(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31848);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fcmpu cr6,f31,f30
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// blt cr6,0x8239e1f8
	if (ctx.cr6.lt) goto loc_8239E1F8;
	// stw r23,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r23.u32);
	// addi r11,r26,17268
	ctx.r11.s64 = ctx.r26.s64 + 17268;
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r8,248(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f26,236(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// mulli r10,r10,36
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(36));
	// stw r9,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r9.u32);
	// fmr f31,f30
	ctx.f31.f64 = ctx.f30.f64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8239e1ec
	if (!ctx.cr6.eq) goto loc_8239E1EC;
	// lwz r5,8(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// b 0x8239e1f0
	goto loc_8239E1F0;
loc_8239E1EC:
	// lwz r5,12(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
loc_8239E1F0:
	// li r3,238
	ctx.r3.s64 = 238;
	// bl 0x82240a58
	ctx.lr = 0x8239E1F8;
	sub_82240A58(ctx, base);
loc_8239E1F8:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// fsubs f13,f30,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// addic r8,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// li r11,2
	ctx.r11.s64 = 2;
	// addi r9,r9,-10860
	ctx.r9.s64 = ctx.r9.s64 + -10860;
	// subfe r10,r8,r10
	temp.u8 = (~ctx.r8.u32 + ctx.r10.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r8.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mulli r10,r10,24
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lfs f0,11480(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11480);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,256(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// add r11,r10,r31
	ctx.r11.u64 = ctx.r10.u64 + ctx.r31.u64;
	// addi r11,r11,268
	ctx.r11.s64 = ctx.r11.s64 + 268;
loc_8239E230:
	// stfsu f31,12(r11)
	ctx.fpscr.disableFlushMode();
	ea = 12 + ctx.r11.u32;
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8239e230
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8239E230;
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E23C:
	// lbz r11,265(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 265);
	// stfs f26,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8239e6e4
	if (ctx.cr0.eq) goto loc_8239E6E4;
	// li r11,4
	ctx.r11.s64 = 4;
	// stfs f26,236(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// stfs f26,240(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 240, temp.u32);
	// stw r25,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r25.u32);
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E264:
	// lfs f0,240(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// fadds f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// addi r11,r26,17268
	ctx.r11.s64 = ctx.r26.s64 + 17268;
	// mulli r10,r10,36
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(36));
	// lfs f12,348(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,2488(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2488);
	ctx.f13.f64 = double(temp.f32);
	// fabs f12,f12
	ctx.f12.u64 = ctx.f12.u64 & ~0x8000000000000000;
	// stfs f0,240(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 240, temp.u32);
	// add r27,r10,r11
	ctx.r27.u64 = ctx.r10.u64 + ctx.r11.u64;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8239e2a0
	if (ctx.cr6.lt) goto loc_8239E2A0;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,240(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 240, temp.u32);
	// mr r24,r25
	ctx.r24.u64 = ctx.r25.u64;
loc_8239E2A0:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,16(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fdivs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 / ctx.f0.f64));
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8239e2b8
	if (!ctx.cr6.eq) goto loc_8239E2B8;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8239E2B8:
	// lfs f13,332(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 332);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// lfs f28,-932(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -932);
	ctx.f28.f64 = double(temp.f32);
	// stfs f0,332(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
	// fcmpu cr6,f0,f26
	ctx.cr6.compare(ctx.f0.f64, ctx.f26.f64);
	// bge cr6,0x8239e2d8
	if (!ctx.cr6.lt) goto loc_8239E2D8;
	// fadds f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f28.f64));
	// b 0x8239e2e4
	goto loc_8239E2E4;
loc_8239E2D8:
	// fcmpu cr6,f0,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x8239e2e8
	if (!ctx.cr6.gt) goto loc_8239E2E8;
	// fsubs f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f28.f64));
loc_8239E2E4:
	// stfs f0,332(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 332, temp.u32);
loc_8239E2E8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// addi r11,r11,-10860
	ctx.r11.s64 = ctx.r11.s64 + -10860;
	// bne cr6,0x8239e300
	if (!ctx.cr6.eq) goto loc_8239E300;
	// lfs f13,15296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15296);
	ctx.f13.f64 = double(temp.f32);
	// b 0x8239e304
	goto loc_8239E304;
loc_8239E300:
	// lfs f13,1920(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1920);
	ctx.f13.f64 = double(temp.f32);
loc_8239E304:
	// lfs f0,27684(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 27684);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f27,f0
	ctx.f0.f64 = double(float(ctx.f27.f64 * ctx.f0.f64));
	// fcmpu cr6,f12,f0
	ctx.cr6.compare(ctx.f12.f64, ctx.f0.f64);
	// ble cr6,0x8239e438
	if (!ctx.cr6.gt) goto loc_8239E438;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8239e32c
	if (!ctx.cr6.eq) goto loc_8239E32C;
	// lfs f12,244(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 244);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// b 0x8239e330
	goto loc_8239E330;
loc_8239E32C:
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
loc_8239E330:
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x8239e350
	if (!ctx.cr6.eq) goto loc_8239E350;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f30,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f30.f64 = double(temp.f32);
	// b 0x8239e354
	goto loc_8239E354;
loc_8239E350:
	// lfs f30,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
loc_8239E354:
	// extsw r11,r28
	ctx.r11.s64 = ctx.r28.s32;
	// lfs f29,-696(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -696);
	ctx.f29.f64 = double(temp.f32);
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f31,f0,f13
	ctx.f31.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_8239E374:
	// subfic r11,r29,0
	ctx.xer.ca = ctx.r29.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r29.u64;
	// lwz r10,4(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// addi r9,r29,7
	ctx.r9.s64 = ctx.r29.s64 + 7;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// andi. r11,r11,80
	ctx.r11.u64 = ctx.r11.u64 & 80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r11,r11,-40
	ctx.r11.s64 = ctx.r11.s64 + -40;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwzx r10,r9,r27
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r27.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// bne cr6,0x8239e3bc
	if (!ctx.cr6.eq) goto loc_8239E3BC;
	// fmr f3,f28
	ctx.f3.f64 = ctx.f28.f64;
	// b 0x8239e3c0
	goto loc_8239E3C0;
loc_8239E3BC:
	// fmr f3,f29
	ctx.fpscr.disableFlushMode();
	ctx.f3.f64 = ctx.f29.f64;
loc_8239E3C0:
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mr r9,r25
	ctx.r9.u64 = ctx.r25.u64;
	// lwz r8,4(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bge cr6,0x8239e42c
	if (!ctx.cr6.lt) goto loc_8239E42C;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_8239E3D8:
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpw cr6,r8,r28
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r28.s32, ctx.xer);
	// bge cr6,0x8239e3f0
	if (!ctx.cr6.lt) goto loc_8239E3F0;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8239e410
	if (ctx.cr6.lt) goto loc_8239E410;
loc_8239E3F0:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r11,r9,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8239e3d8
	if (ctx.cr6.lt) goto loc_8239E3D8;
	// b 0x8239e42c
	goto loc_8239E42C;
loc_8239E410:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f4,f30
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f30.f64;
	// fmr f2,f31
	ctx.f2.f64 = ctx.f31.f64;
	// bl 0x8239f018
	ctx.lr = 0x8239E420;
	sub_8239F018(ctx, base);
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne cr6,0x8239e42c
	if (!ctx.cr6.eq) goto loc_8239E42C;
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
loc_8239E42C:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// blt cr6,0x8239e374
	if (ctx.cr6.lt) goto loc_8239E374;
loc_8239E438:
	// lbz r11,352(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 352);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8239e498
	if (ctx.cr0.eq) goto loc_8239E498;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
	// li r11,5
	ctx.r11.s64 = 5;
	// lwz r3,360(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfs f26,236(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// stb r25,352(r31)
	REX_STORE_U8(ctx.r31.u32 + 352, ctx.r25.u8);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
	// lwz r29,84(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r24,2
	ctx.r24.s64 = 2;
	// lwz r30,4(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8239e480
	if (ctx.cr6.eq) goto loc_8239E480;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x8239E480;
	sub_825765F0(ctx, base);
loc_8239E480:
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,373
	ctx.r3.s64 = 373;
	// b 0x8239e184
	goto loc_8239E184;
loc_8239E498:
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// beq cr6,0x8239e6e4
	if (ctx.cr6.eq) goto loc_8239E6E4;
	// lfs f0,244(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
	// li r3,265
	ctx.r3.s64 = 265;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,4(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82240a58
	ctx.lr = 0x8239E4BC;
	sub_82240A58(ctx, base);
	// stw r3,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r3.u32);
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E4C4:
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f12,f0,f27
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-10860
	ctx.r11.s64 = ctx.r11.s64 + -10860;
	// stfs f12,236(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f31,f12,f0
	ctx.f31.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// blt cr6,0x8239e544
	if (ctx.cr6.lt) goto loc_8239E544;
	// stfs f26,236(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// addi r11,r26,17268
	ctx.r11.s64 = ctx.r26.s64 + 17268;
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// mulli r10,r10,36
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(36));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// li r10,6
	ctx.r10.s64 = 6;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r10.u32);
	// lwz r28,4(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bne cr6,0x8239e520
	if (!ctx.cr6.eq) goto loc_8239E520;
	// lwz r29,12(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// b 0x8239e524
	goto loc_8239E524;
loc_8239E520:
	// lwz r29,8(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_8239E524:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,416
	ctx.r3.s64 = 416;
	// bl 0x82240a58
	ctx.lr = 0x8239E534;
	sub_82240A58(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// li r3,372
	ctx.r3.s64 = 372;
	// bl 0x82240a58
	ctx.lr = 0x8239E544;
	sub_82240A58(ctx, base);
loc_8239E544:
	// lfs f0,-932(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -932);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// blt cr6,0x8239e558
	if (ctx.cr6.lt) goto loc_8239E558;
	// stfs f26,256(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E558:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f0,1208(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1208);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// ble cr6,0x8239e574
	if (!ctx.cr6.gt) goto loc_8239E574;
	// lfd f0,200(r11)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 200);
	// fsub f31,f0,f31
	ctx.f31.f64 = ctx.f0.f64 - ctx.f31.f64;
loc_8239E574:
	// lfd f0,1648(r11)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r11.u32 + 1648);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// fmul f0,f31,f0
	ctx.f0.f64 = ctx.f31.f64 * ctx.f0.f64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// bne cr6,0x8239e590
	if (!ctx.cr6.eq) goto loc_8239E590;
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_8239E590:
	// stfs f0,256(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E598:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lfs f0,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1708(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1708);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// lfs f11,-932(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -932);
	ctx.f11.f64 = double(temp.f32);
	// stfs f0,236(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// lfs f10,31848(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31848);
	ctx.f10.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fsubs f13,f10,f13
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f13.f64));
	// addi r11,r11,-10860
	ctx.r11.s64 = ctx.r11.s64 + -10860;
	// fdivs f12,f0,f13
	ctx.f12.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fcmpu cr6,f12,f11
	ctx.cr6.compare(ctx.f12.f64, ctx.f11.f64);
	// bgt cr6,0x8239e5d8
	if (ctx.cr6.gt) goto loc_8239E5D8;
	// lfs f13,11480(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11480);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// b 0x8239e614
	goto loc_8239E614;
loc_8239E5D8:
	// fsubs f9,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lfs f13,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f12,1208(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1208);
	ctx.f12.f64 = double(temp.f32);
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// fmuls f13,f9,f13
	ctx.f13.f64 = double(float(ctx.f9.f64 * ctx.f13.f64));
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// ble cr6,0x8239e600
	if (!ctx.cr6.gt) goto loc_8239E600;
	// lfd f12,200(r10)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r10.u32 + 200);
	// fsub f13,f12,f13
	ctx.f13.f64 = ctx.f12.f64 - ctx.f13.f64;
loc_8239E600:
	// lfd f12,1648(r10)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r10.u32 + 1648);
	// fmul f12,f13,f12
	ctx.f12.f64 = ctx.f13.f64 * ctx.f12.f64;
	// lfs f13,11480(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11480);
	ctx.f13.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fadds f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
loc_8239E614:
	// fdivs f0,f0,f10
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f10.f64));
	// stfs f12,256(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// blt cr6,0x8239e638
	if (ctx.cr6.lt) goto loc_8239E638;
	// li r11,7
	ctx.r11.s64 = 7;
	// stfs f13,256(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 256, temp.u32);
	// stfs f26,236(r31)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// fmr f0,f11
	ctx.f0.f64 = ctx.f11.f64;
	// stw r11,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r11.u32);
loc_8239E638:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r11,2
	ctx.r11.s64 = 2;
	// fsubs f0,f11,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mulli r11,r10,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(24));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r11,r11,268
	ctx.r11.s64 = ctx.r11.s64 + 268;
loc_8239E65C:
	// stfsu f0,12(r11)
	ctx.fpscr.disableFlushMode();
	ea = 12 + ctx.r11.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x8239e65c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8239E65C;
	// b 0x8239e6e4
	goto loc_8239E6E4;
loc_8239E668:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stfs f26,236(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r31.u32 + 236, temp.u32);
	// lwz r10,328(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// stw r23,232(r31)
	REX_STORE_U32(ctx.r31.u32 + 232, ctx.r23.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r11,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r11.u32);
	// beq cr6,0x8239e6e4
	if (ctx.cr6.eq) goto loc_8239E6E4;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x8239E6A4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8239e6d8
	if (ctx.cr0.eq) goto loc_8239E6D8;
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r8,328(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// li r9,524
	ctx.r9.s64 = 524;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r25,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r25.u32);
	// stw r9,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r9.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// stw r10,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r10.u32);
	// stw r8,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// b 0x8239e6dc
	goto loc_8239E6DC;
loc_8239E6D8:
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
loc_8239E6DC:
	// bl 0x825a2ef8
	ctx.lr = 0x8239E6E0;
	sub_825A2EF8(ctx, base);
	// stw r25,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r25.u32);
loc_8239E6E4:
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8239e738
	if (ctx.cr6.eq) goto loc_8239E738;
	// cmpwi cr6,r24,-1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, -1, ctx.xer);
	// beq cr6,0x8239e738
	if (ctx.cr6.eq) goto loc_8239E738;
	// addi r10,r26,17364
	ctx.r10.s64 = ctx.r26.s64 + 17364;
	// mulli r11,r24,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(24));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// add r30,r11,r10
	ctx.r30.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_8239E70C:
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f1,f26
	ctx.cr6.compare(ctx.f1.f64, ctx.f26.f64);
	// blt cr6,0x8239e728
	if (ctx.cr6.lt) goto loc_8239E728;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,-4(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -4);
	// lfs f2,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8242d368
	ctx.lr = 0x8239E728;
	sub_8242D368(ctx, base);
loc_8239E728:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,12
	ctx.r30.s64 = ctx.r30.s64 + 12;
	// cmpwi cr6,r29,2
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 2, ctx.xer);
	// blt cr6,0x8239e70c
	if (ctx.cr6.lt) goto loc_8239E70C;
loc_8239E738:
	// fcmpu cr6,f27,f26
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f27.f64, ctx.f26.f64);
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// bgt cr6,0x8239e748
	if (ctx.cr6.gt) goto loc_8239E748;
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
loc_8239E748:
	// stw r25,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r25.u32);
	// stb r11,264(r31)
	REX_STORE_U8(ctx.r31.u32 + 264, ctx.r11.u8);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-80
	ctx.r12.s64 = ctx.r1.s64 + -80;
	// bl 0x8273af6c
	ctx.lr = 0x8239E75C;
	__restfpr_26(ctx, base);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823D0028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-432(r1)
	ea = -432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// bl 0x82213210
	ctx.lr = 0x823D0038;
	sub_82213210(ctx, base);
	// lbz r11,4039(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4039);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823d004c
	if (ctx.cr0.eq) goto loc_823D004C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823d0054
	goto loc_823D0054;
loc_823D004C:
	// bl 0x82213210
	ctx.lr = 0x823D0050;
	sub_82213210(ctx, base);
	// lbz r3,4033(r3)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r3.u32 + 4033);
loc_823D0054:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// bl 0x82445010
	ctx.lr = 0x823D005C;
	sub_82445010(ctx, base);
	// lfs f0,184(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 184);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r1,r1,432
	ctx.r1.s64 = ctx.r1.s64 + 432;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_823D3130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x823D3138;
	__savegprlr_22(ctx, base);
	// stfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r27,0
	ctx.r27.s64 = 0;
	// addi r28,r11,-19936
	ctx.r28.s64 = ctx.r11.s64 + -19936;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
	// lfs f31,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f31.f64 = double(temp.f32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// li r23,255
	ctx.r23.s64 = 255;
	// lis r24,-32227
	ctx.r24.s64 = -2112028672;
	// lis r22,-32112
	ctx.r22.s64 = -2104492032;
	// addi r26,r11,-30896
	ctx.r26.s64 = ctx.r11.s64 + -30896;
	// addi r25,r10,-31112
	ctx.r25.s64 = ctx.r10.s64 + -31112;
loc_823D3178:
	// addi r11,r28,-31048
	ctx.r11.s64 = ctx.r28.s64 + -31048;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwzx r5,r31,r11
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823D318C;
	sub_823C7AF0(ctx, base);
	// addi r10,r28,-31160
	ctx.r10.s64 = ctx.r28.s64 + -31160;
	// lwz r11,-13064(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -13064);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwzx r4,r31,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r10.u32);
	// bne cr6,0x823d31a8
	if (!ctx.cr6.eq) goto loc_823D31A8;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// b 0x823d31b4
	goto loc_823D31B4;
loc_823D31A8:
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235d7f0
	ctx.lr = 0x823D31B4;
	sub_8235D7F0(ctx, base);
loc_823D31B4:
	// stwx r3,r31,r29
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, ctx.r3.u32);
	// add r11,r30,r25
	ctx.r11.u64 = ctx.r30.u64 + ctx.r25.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfsx f0,r30,r25
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r25.u32);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f0,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823D31DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r26,4
	ctx.r11.s64 = ctx.r26.s64 + 4;
	// lwzx r9,r31,r29
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// lfsx f0,r30,r26
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r26.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r28,-30936
	ctx.r10.s64 = ctx.r28.s64 + -30936;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// li r3,-100
	ctx.r3.s64 = -100;
	// lfsx f13,r30,r11
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + ctx.r11.u32);
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
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
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
	// bl 0x823c7f28
	ctx.lr = 0x823D3238;
	sub_823C7F28(ctx, base);
	// lwzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// lfs f0,-18548(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + -18548);
	ctx.f0.f64 = double(temp.f32);
	// li r10,68
	ctx.r10.s64 = 68;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
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
	// stb r27,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r27.u8);
	// stb r27,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r27.u8);
	// stb r27,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r27.u8);
	// stb r23,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r23.u8);
	// lwzx r3,r31,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823D3284;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,8
	ctx.r30.s64 = ctx.r30.s64 + 8;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmplwi cr6,r30,216
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 216, ctx.xer);
	// blt cr6,0x823d3178
	if (ctx.cr6.lt) goto loc_823D3178;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x823c80a8
	ctx.lr = 0x823D329C;
	sub_823C80A8(ctx, base);
	// addi r11,r28,-30780
	ctx.r11.s64 = ctx.r28.s64 + -30780;
	// li r31,12
	ctx.r31.s64 = 12;
	// addi r30,r11,-4
	ctx.r30.s64 = ctx.r11.s64 + -4;
loc_823D32A8:
	// stb r23,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r23.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stb r27,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r27.u8);
	// stb r27,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r27.u8);
	// stb r23,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r23.u8);
	// lwzu r11,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r29
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r29.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823D32D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x823d32a8
	if (!ctx.cr0.eq) goto loc_823D32A8;
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// lfd f31,-96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823E2900) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x823E2908;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x823e2a38
	ctx.lr = 0x823E2914;
	sub_823E2A38(ctx, base);
	// lis r24,-32112
	ctx.r24.s64 = -2104492032;
	// lwz r11,-13068(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -13068);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823e292c
	if (ctx.cr6.eq) goto loc_823E292C;
	// lwz r25,656(r11)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + 656);
	// b 0x823e2930
	goto loc_823E2930;
loc_823E292C:
	// li r25,0
	ctx.r25.s64 = 0;
loc_823E2930:
	// addi r29,r31,12
	ctx.r29.s64 = ctx.r31.s64 + 12;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823f95f0
	ctx.lr = 0x823E2940;
	sub_823F95F0(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r28,0
	ctx.r28.s64 = 0;
	// li r27,14080
	ctx.r27.s64 = 14080;
	// addi r26,r11,22072
	ctx.r26.s64 = ctx.r11.s64 + 22072;
loc_823E2950:
	// lwz r11,-13068(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + -13068);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823e2970
	if (ctx.cr6.eq) goto loc_823E2970;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// bl 0x8223d0d0
	ctx.lr = 0x823E2968;
	sub_8223D0D0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x823e2974
	goto loc_823E2974;
loc_823E2970:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823E2974:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823e2a20
	if (ctx.cr6.eq) goto loc_823E2A20;
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823e2a20
	if (ctx.cr0.eq) goto loc_823E2A20;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x825e02a0
	ctx.lr = 0x823E2998;
	sub_825E02A0(ctx, base);
	// stw r31,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r31.u32);
	// stb r28,4(r3)
	REX_STORE_U8(ctx.r3.u32 + 4, ctx.r28.u8);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// bl 0x82213210
	ctx.lr = 0x823E29AC;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r28,256
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 256, ctx.xer);
	// blt cr6,0x823e29c0
	if (ctx.cr6.lt) goto loc_823E29C0;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x823e29c4
	goto loc_823E29C4;
loc_823E29C0:
	// lwzx r11,r27,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + ctx.r11.u32);
loc_823E29C4:
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stb r11,5(r30)
	REX_STORE_U8(ctx.r30.u32 + 5, ctx.r11.u8);
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823e29e4
	if (!ctx.cr6.eq) goto loc_823E29E4;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x823e29f0
	goto loc_823E29F0;
loc_823E29E4:
	// lwz r10,12(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_823E29F0:
	// lwz r4,8(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823e2a14
	if (!ctx.cr6.lt) goto loc_823E2A14;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r30,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r30.u32);
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// b 0x823e2a20
	goto loc_823E2A20;
loc_823E2A14:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823849b0
	ctx.lr = 0x823E2A20;
	sub_823849B0(ctx, base);
loc_823E2A20:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r27,r27,4
	ctx.r27.s64 = ctx.r27.s64 + 4;
	// cmplw cr6,r28,r25
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r25.u32, ctx.xer);
	// ble cr6,0x823e2950
	if (!ctx.cr6.gt) goto loc_823E2950;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823EC0B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823EC0C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,6
	ctx.r31.s64 = 6;
loc_823EC0D0:
	// lwzu r11,4(r30)
	ea = 4 + ctx.r30.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r30.u32 = ea;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f13,76(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 76);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f13,68(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// lfs f2,72(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 72);
	ctx.f2.f64 = double(temp.f32);
	// fadds f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// bl 0x823eaaf0
	ctx.lr = 0x823EC0F4;
	sub_823EAAF0(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x823ec0d0
	if (!ctx.cr0.eq) goto loc_823EC0D0;
	// lwz r11,36(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// beq cr6,0x823ec110
	if (ctx.cr6.eq) goto loc_823EC110;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x823ec18c
	if (!ctx.cr6.eq) goto loc_823EC18C;
loc_823EC110:
	// lwa r11,44(r29)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r29.u32 + 44));
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// frsp f10,f0
	ctx.f10.f64 = double(float(ctx.f0.f64));
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lfs f0,-22748(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -22748);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r3,56(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 56);
	// lfs f12,3104(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3104);
	ctx.f12.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,17244(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17244);
	ctx.f13.f64 = double(temp.f32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f11,-6412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6412);
	ctx.f11.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// fmadds f0,f10,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, ctx.f12.f64)));
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823beba0
	ctx.lr = 0x823EC18C;
	sub_823BEBA0(ctx, base);
loc_823EC18C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F1CC0) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,124(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823f1ce4
	if (ctx.cr6.eq) goto loc_823F1CE4;
	// bl 0x823f0868
	ctx.lr = 0x823F1CE4;
	sub_823F0868(ctx, base);
loc_823F1CE4:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 128, temp.u32);
	// bl 0x82213210
	ctx.lr = 0x823F1CFC;
	sub_82213210(ctx, base);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,19228(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// bl 0x823eda58
	ctx.lr = 0x823F1D08;
	sub_823EDA58(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823F1D20;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823f1d30
	if (ctx.cr0.eq) goto loc_823F1D30;
	// bl 0x823c9bc8
	ctx.lr = 0x823F1D2C;
	sub_823C9BC8(ctx, base);
	// b 0x823f1d34
	goto loc_823F1D34;
loc_823F1D30:
	// li r3,0
	ctx.r3.s64 = 0;
loc_823F1D34:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// stw r3,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r3.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r9,r11,-21448
	ctx.r9.s64 = ctx.r11.s64 + -21448;
	// lfs f0,-21448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 284, temp.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lfs f0,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,288(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 288, temp.u32);
	// lwz r3,124(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// bl 0x823c9c50
	ctx.lr = 0x823F1D64;
	sub_823C9C50(ctx, base);
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

DEFINE_REX_FUNC(sub_823F5D98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823F5DA0;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stw r4,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r4.u32);
	// li r11,13
	ctx.r11.s64 = 13;
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r3,-4
	ctx.r10.s64 = ctx.r3.s64 + -4;
	// stw r30,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r30.u32);
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// stfs f0,108(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 108, temp.u32);
	// stw r30,68(r3)
	REX_STORE_U32(ctx.r3.u32 + 68, ctx.r30.u32);
	// stw r30,72(r3)
	REX_STORE_U32(ctx.r3.u32 + 72, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r30,76(r3)
	REX_STORE_U32(ctx.r3.u32 + 76, ctx.r30.u32);
	// stb r30,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r30.u8);
	// stb r30,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r30.u8);
	// stb r30,86(r3)
	REX_STORE_U8(ctx.r3.u32 + 86, ctx.r30.u8);
	// stb r30,87(r3)
	REX_STORE_U8(ctx.r3.u32 + 87, ctx.r30.u8);
	// stb r30,88(r3)
	REX_STORE_U8(ctx.r3.u32 + 88, ctx.r30.u8);
	// stw r30,92(r3)
	REX_STORE_U32(ctx.r3.u32 + 92, ctx.r30.u32);
	// stb r30,96(r3)
	REX_STORE_U8(ctx.r3.u32 + 96, ctx.r30.u8);
	// stw r30,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r30.u32);
	// stw r30,104(r3)
	REX_STORE_U32(ctx.r3.u32 + 104, ctx.r30.u32);
	// stb r30,112(r3)
	REX_STORE_U8(ctx.r3.u32 + 112, ctx.r30.u8);
	// stw r30,116(r3)
	REX_STORE_U32(ctx.r3.u32 + 116, ctx.r30.u32);
loc_823F5E08:
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x823f5e08
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823F5E08;
	// stw r30,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r30.u32);
	// stw r30,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r30.u32);
	// bl 0x82213210
	ctx.lr = 0x823F5E1C;
	sub_82213210(ctx, base);
	// lwz r29,19228(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// bl 0x82213210
	ctx.lr = 0x823F5E28;
	sub_82213210(ctx, base);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// addi r29,r29,72
	ctx.r29.s64 = ctx.r29.s64 + 72;
loc_823F5E30:
	// addi r26,r28,1
	ctx.r26.s64 = ctx.r28.s64 + 1;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82577128
	ctx.lr = 0x823F5E3C;
	sub_82577128(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x823f5e58
	if (!ctx.cr0.lt) goto loc_823F5E58;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stb r30,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r30.u8);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// stb r30,1(r11)
	REX_STORE_U8(ctx.r11.u32 + 1, ctx.r30.u8);
	// b 0x823f5f00
	goto loc_823F5F00;
loc_823F5E58:
	// bl 0x82213210
	ctx.lr = 0x823F5E5C;
	sub_82213210(ctx, base);
	// cmplwi cr6,r26,6
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 6, ctx.xer);
	// ble cr6,0x823f5e88
	if (!ctx.cr6.gt) goto loc_823F5E88;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// bl 0x82213210
	ctx.lr = 0x823F5E74;
	sub_82213210(ctx, base);
	// bl 0x82213210
	ctx.lr = 0x823F5E78;
	sub_82213210(ctx, base);
	// lbz r11,18142(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 18142);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// b 0x823f5eec
	goto loc_823F5EEC;
loc_823F5E88:
	// bl 0x82213210
	ctx.lr = 0x823F5E8C;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r28,32
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 32, ctx.xer);
	// blt cr6,0x823f5ea0
	if (ctx.cr6.lt) goto loc_823F5EA0;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x823f5eb0
	goto loc_823F5EB0;
loc_823F5EA0:
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// lbz r11,14012(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 14012);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_823F5EB0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// bl 0x82213210
	ctx.lr = 0x823F5EC8;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r28,32
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 32, ctx.xer);
	// blt cr6,0x823f5edc
	if (ctx.cr6.lt) goto loc_823F5EDC;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x823f5eec
	goto loc_823F5EEC;
loc_823F5EDC:
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// lbz r11,14013(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 14013);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_823F5EEC:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r10,0(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// subfe r11,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stb r11,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r11.u8);
loc_823F5F00:
	// mr r28,r26
	ctx.r28.u64 = ctx.r26.u64;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r27,r27,2
	ctx.r27.s64 = ctx.r27.s64 + 2;
	// bl 0x82213210
	ctx.lr = 0x823F5F10;
	sub_82213210(ctx, base);
	// cmplwi cr6,r27,64
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 64, ctx.xer);
	// blt cr6,0x823f5e30
	if (ctx.cr6.lt) goto loc_823F5E30;
	// bl 0x82213210
	ctx.lr = 0x823F5F1C;
	sub_82213210(ctx, base);
	// stb r30,4036(r3)
	REX_STORE_U8(ctx.r3.u32 + 4036, ctx.r30.u8);
	// bl 0x82213210
	ctx.lr = 0x823F5F24;
	sub_82213210(ctx, base);
	// stb r30,4035(r3)
	REX_STORE_U8(ctx.r3.u32 + 4035, ctx.r30.u8);
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,6
	ctx.r3.s64 = 6;
	// bl 0x822140d0
	ctx.lr = 0x823F5F34;
	sub_822140D0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82401B18) {
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
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r11,-12976(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12976);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82401b5c
	if (ctx.cr6.eq) goto loc_82401B5C;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82401b5c
	if (ctx.cr6.eq) goto loc_82401B5C;
	// bl 0x823ec0b8
	ctx.lr = 0x82401B50;
	sub_823EC0B8(ctx, base);
	// lwz r11,-12976(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12976);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x823ec198
	ctx.lr = 0x82401B5C;
	sub_823EC198(ctx, base);
loc_82401B5C:
	// lbz r11,916(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 916);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// beq cr6,0x82401b98
	if (ctx.cr6.eq) goto loc_82401B98;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x82401b8c
	if (ctx.cr6.eq) goto loc_82401B8C;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bne cr6,0x82401bac
	if (!ctx.cr6.eq) goto loc_82401BAC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,14876(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14876);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x82401b9c
	goto loc_82401B9C;
loc_82401B8C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f1,14876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14876);
	ctx.f1.f64 = double(temp.f32);
	// b 0x82401b9c
	goto loc_82401B9C;
loc_82401B98:
	// lfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f1.f64 = double(temp.f32);
loc_82401B9C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82401e78
	ctx.lr = 0x82401BA4;
	sub_82401E78(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82401fb0
	ctx.lr = 0x82401BAC;
	sub_82401FB0(ctx, base);
loc_82401BAC:
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

DEFINE_REX_FUNC(sub_82407178) {
	REX_FUNC_PROLOGUE();
	// lwz r3,160(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
	// b 0x82407290
	sub_82407290(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82407A40) {
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
	// lwz r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// bl 0x82457b58
	ctx.lr = 0x82407A5C;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x82407A60;
	sub_825FD7A0(ctx, base);
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82407b50
	ctx.lr = 0x82407A6C;
	sub_82407B50(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82407A84;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82407a94
	if (ctx.cr0.eq) goto loc_82407A94;
	// bl 0x823c9508
	ctx.lr = 0x82407A90;
	sub_823C9508(ctx, base);
	// b 0x82407a98
	goto loc_82407A98;
loc_82407A94:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82407A98:
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,12(r8)
	REX_STORE_U32(ctx.r8.u32 + 12, ctx.r10.u32);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lfs f0,-27352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27352);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f0,16(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 16, temp.u32);
	// lfs f13,17264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17264);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// bl 0x82213210
	ctx.lr = 0x82407AD0;
	sub_82213210(ctx, base);
	// lwz r11,19776(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19776);
	// rlwinm. r11,r11,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82407b18
	if (!ctx.cr0.eq) goto loc_82407B18;
	// bl 0x82213210
	ctx.lr = 0x82407AE0;
	sub_82213210(ctx, base);
	// lwz r11,19776(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19776);
	// rlwinm. r11,r11,28,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82407b18
	if (!ctx.cr0.eq) goto loc_82407B18;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r11,r11,10464
	ctx.r11.s64 = ctx.r11.s64 + 10464;
	// lwz r3,452(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 452);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82407b08
	if (ctx.cr6.eq) goto loc_82407B08;
loc_82407B00:
	// bl 0x8242ae88
	ctx.lr = 0x82407B04;
	sub_8242AE88(ctx, base);
	// b 0x82407b20
	goto loc_82407B20;
loc_82407B08:
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r11,r11,10304
	ctx.r11.s64 = ctx.r11.s64 + 10304;
	// lwz r3,140(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// b 0x82407b00
	goto loc_82407B00;
loc_82407B18:
	// lis r3,16
	ctx.r3.s64 = 1048576;
	// ori r3,r3,75
	ctx.r3.u64 = ctx.r3.u64 | 75;
loc_82407B20:
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r3,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r3.u32);
	// stw r11,24(r10)
	REX_STORE_U32(ctx.r10.u32 + 24, ctx.r11.u32);
	// stb r11,8(r10)
	REX_STORE_U8(ctx.r10.u32 + 8, ctx.r11.u8);
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

DEFINE_REX_FUNC(sub_82410740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// std r31,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r9,17
	ctx.r9.s64 = 17;
	// lwz r11,156(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82410760:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// lbz r8,76(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 76);
	// stb r8,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r8.u8);
	// bdnz 0x82410760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82410760;
	// lbz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 76);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8241081c
	if (ctx.cr0.eq) goto loc_8241081C;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r10,-12972(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12972);
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r3,428(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8241081c
	if (ctx.cr6.eq) goto loc_8241081C;
	// lwz r5,68(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// addi r6,r10,-25236
	ctx.r6.s64 = ctx.r10.s64 + -25236;
	// addi r11,r11,-16632
	ctx.r11.s64 = ctx.r11.s64 + -16632;
	// lis r7,-32227
	ctx.r7.s64 = -2112028672;
	// lfs f7,-25236(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -25236);
	ctx.f7.f64 = double(temp.f32);
	// addi r4,r9,18652
	ctx.r4.s64 = ctx.r9.s64 + 18652;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f1,18652(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18652);
	ctx.f1.f64 = double(temp.f32);
	// lfs f9,-76(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -76);
	ctx.f9.f64 = double(temp.f32);
	// li r31,1
	ctx.r31.s64 = 1;
	// lfs f13,-15676(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -15676);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,-10736
	ctx.r10.s64 = ctx.r10.s64 + -10736;
	// lfs f0,2500(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2500);
	ctx.f0.f64 = double(temp.f32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// lfs f10,128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 128);
	ctx.f10.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lfs f8,132(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 132);
	ctx.f8.f64 = double(temp.f32);
	// addi r7,r1,104
	ctx.r7.s64 = ctx.r1.s64 + 104;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f12,-18032(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -18032);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 - ctx.f9.f64));
	// lfs f11,-20840(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -20840);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f8,f7
	ctx.f0.f64 = double(float(ctx.f8.f64 - ctx.f7.f64));
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stb r31,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r31.u8);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x823c5c80
	ctx.lr = 0x8241081C;
	sub_823C5C80(ctx, base);
loc_8241081C:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82418B60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82418B68;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r5,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// addi r28,r11,12236
	ctx.r28.s64 = ctx.r11.s64 + 12236;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// stw r30,180(r3)
	REX_STORE_U32(ctx.r3.u32 + 180, ctx.r30.u32);
	// addi r3,r3,204
	ctx.r3.s64 = ctx.r3.s64 + 204;
	// lfs f0,232(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stw r30,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r30.u32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
	// stb r30,192(r31)
	REX_STORE_U8(ctx.r31.u32 + 192, ctx.r30.u8);
	// stw r30,196(r31)
	REX_STORE_U32(ctx.r31.u32 + 196, ctx.r30.u32);
	// stb r30,200(r31)
	REX_STORE_U8(ctx.r31.u32 + 200, ctx.r30.u8);
	// stb r30,201(r31)
	REX_STORE_U8(ctx.r31.u32 + 201, ctx.r30.u8);
	// bl 0x823cb5c8
	ctx.lr = 0x82418BB8;
	sub_823CB5C8(ctx, base);
	// addi r29,r31,208
	ctx.r29.s64 = ctx.r31.s64 + 208;
	// li r27,1
	ctx.r27.s64 = 1;
loc_82418BC0:
	// stw r30,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r30.u32);
	// lis r11,-32190
	ctx.r11.s64 = -2109603840;
	// stw r30,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r30.u32);
	// li r5,20
	ctx.r5.s64 = 20;
	// addi r6,r11,-30016
	ctx.r6.s64 = ctx.r11.s64 + -30016;
	// li r4,64
	ctx.r4.s64 = 64;
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x82213160
	ctx.lr = 0x82418BE0;
	sub_82213160(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,1288
	ctx.r29.s64 = ctx.r29.s64 + 1288;
	// bge 0x82418bc0
	if (!ctx.cr0.lt) goto loc_82418BC0;
	// li r11,41
	ctx.r11.s64 = 41;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r9,2
	ctx.r9.s64 = 2;
	// stfs f0,2788(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2788, temp.u32);
	// addi r10,r31,16
	ctx.r10.s64 = ctx.r31.s64 + 16;
	// stfs f0,2792(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 2792, temp.u32);
	// stb r30,2796(r31)
	REX_STORE_U8(ctx.r31.u32 + 2796, ctx.r30.u8);
	// stb r30,2797(r31)
	REX_STORE_U8(ctx.r31.u32 + 2797, ctx.r30.u8);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// stw r30,2800(r31)
	REX_STORE_U32(ctx.r31.u32 + 2800, ctx.r30.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r30,2808(r31)
	REX_STORE_U32(ctx.r31.u32 + 2808, ctx.r30.u32);
	// stw r30,2812(r31)
	REX_STORE_U32(ctx.r31.u32 + 2812, ctx.r30.u32);
	// stb r30,2816(r31)
	REX_STORE_U8(ctx.r31.u32 + 2816, ctx.r30.u8);
	// stb r30,2817(r31)
	REX_STORE_U8(ctx.r31.u32 + 2817, ctx.r30.u8);
	// stw r9,2804(r31)
	REX_STORE_U32(ctx.r31.u32 + 2804, ctx.r9.u32);
loc_82418C2C:
	// stwu r30,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r30.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82418c2c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82418C2C;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// stw r11,2784(r31)
	REX_STORE_U32(ctx.r31.u32 + 2784, ctx.r11.u32);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82424240) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82424248;
	__savegprlr_24(ctx, base);
	// stwu r1,-448(r1)
	ea = -448 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,356(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 356);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r10,r10,-30656
	ctx.r10.s64 = ctx.r10.s64 + -30656;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwzx r5,r11,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// bl 0x823c7af0
	ctx.lr = 0x82424274;
	sub_823C7AF0(ctx, base);
	// lwz r11,296(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 296);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x82424298;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r11,440(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 440);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82424310
	if (!ctx.cr0.eq) goto loc_82424310;
	// addi r31,r31,244
	ctx.r31.s64 = ctx.r31.s64 + 244;
	// li r30,12
	ctx.r30.s64 = 12;
loc_824242AC:
	// lis r5,15
	ctx.r5.s64 = 983040;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x824242BC;
	sub_823C7AF0(ctx, base);
	// lwz r11,-44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -44);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x824242E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwzu r11,4(r31)
	ea = 4 + ctx.r31.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r31.u32 = ea;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x82424304;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x824242ac
	if (!ctx.cr0.eq) goto loc_824242AC;
	// b 0x824243f8
	goto loc_824243F8;
loc_82424310:
	// stw r30,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r30.u32);
	// li r27,12
	ctx.r27.s64 = 12;
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// cmpwi cr6,r11,12
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 12, ctx.xer);
	// bgt cr6,0x82424328
	if (ctx.cr6.gt) goto loc_82424328;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
loc_82424328:
	// li r26,0
	ctx.r26.s64 = 0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// addi r28,r11,31384
	ctx.r28.s64 = ctx.r11.s64 + 31384;
loc_8242433C:
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// bge cr6,0x82424394
	if (!ctx.cr6.lt) goto loc_82424394;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r10,404(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r25,r11,r10
	ctx.r25.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x823b4940
	ctx.lr = 0x82424360;
	sub_823B4940(ctx, base);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x823b56a0
	ctx.lr = 0x8242436C;
	sub_823B56A0(ctx, base);
	// rlwinm r25,r3,30,2,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x823c7af0
	ctx.lr = 0x82424380;
	sub_823C7AF0(ctx, base);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82738a28
	ctx.lr = 0x82424390;
	sub_82738A28(ctx, base);
	// b 0x8242439c
	goto loc_8242439C;
loc_82424394:
	// stb r26,112(r1)
	REX_STORE_U8(ctx.r1.u32 + 112, ctx.r26.u8);
	// stb r26,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r26.u8);
loc_8242439C:
	// lwz r11,-44(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + -44);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
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
	ctx.lr = 0x824243C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwzu r11,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
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
	ctx.lr = 0x824243E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,12
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 12, ctx.xer);
	// blt cr6,0x8242433c
	if (ctx.cr6.lt) goto loc_8242433C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82424400
	ctx.lr = 0x824243F8;
	sub_82424400(ctx, base);
loc_824243F8:
	// addi r1,r1,448
	ctx.r1.s64 = ctx.r1.s64 + 448;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824310F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82431100;
	__savegprlr_28(ctx, base);
	// addi r10,r1,-64
	ctx.r10.s64 = ctx.r1.s64 + -64;
	// lfs f0,2432(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2432);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,-80
	ctx.r11.s64 = ctx.r1.s64 + -80;
	// lfs f13,2260(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2260);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,-64
	ctx.r8.s64 = ctx.r1.s64 + -64;
	// stfs f0,-68(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// addi r9,r1,-64
	ctx.r9.s64 = ctx.r1.s64 + -64;
	// stfs f0,-72(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// addi r6,r1,-64
	ctx.r6.s64 = ctx.r1.s64 + -64;
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// addi r31,r1,-64
	ctx.r31.s64 = ctx.r1.s64 + -64;
	// stfs f13,-52(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// addi r29,r1,-64
	ctx.r29.s64 = ctx.r1.s64 + -64;
	// stfs f13,-64(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// addi r7,r1,-80
	ctx.r7.s64 = ctx.r1.s64 + -80;
	// stfs f0,-80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// stfs f13,-56(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// addi r28,r1,-64
	ctx.r28.s64 = ctx.r1.s64 + -64;
	// stfs f13,-60(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// addi r30,r1,-80
	ctx.r30.s64 = ctx.r1.s64 + -80;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,-64
	ctx.r10.s64 = ctx.r1.s64 + -64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,-80
	ctx.r11.s64 = ctx.r1.s64 + -80;
	// lfs f0,-64(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// lfs f0,2264(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2436(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2436);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-64(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f13,-52(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stfs f13,-56(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f13,-60(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f0,-68(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stfs f0,-72(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f0,-80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-64(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r4)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// lfs f0,2260(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2440(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2440);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-64(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f13,-52(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stfs f13,-56(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f13,-60(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f0,-68(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stfs f0,-72(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f0,-80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lvx128 v63,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-64(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 0, temp.u32);
	// lfs f0,2264(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2264);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,2444(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 2444);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,-64(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -64, temp.u32);
	// stfs f13,-52(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -52, temp.u32);
	// stfs f13,-56(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -56, temp.u32);
	// stfs f13,-60(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + -60, temp.u32);
	// stfs f0,-68(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -68, temp.u32);
	// stfs f0,-72(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -72, temp.u32);
	// stfs f0,-76(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -76, temp.u32);
	// stfs f0,-80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -80, temp.u32);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-64(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -64);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82441408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82441410;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r4,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r4.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// bl 0x82441698
	ctx.lr = 0x82441430;
	sub_82441698(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82441440
	if (!ctx.cr0.eq) goto loc_82441440;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x8244146c
	goto loc_8244146C;
loc_82441440:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824414e8
	ctx.lr = 0x8244144C;
	sub_824414E8(ctx, base);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823b52a0
	ctx.lr = 0x82441458;
	sub_823B52A0(ctx, base);
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// subfc r11,r11,r3
	ctx.xer.ca = ctx.r3.u32 >= ctx.r11.u32;
	ctx.r11.u64 = ctx.r3.u64 - ctx.r11.u64;
	// subfze r11,r10
	temp.u8 = ~ctx.r10.u32 + ctx.xer.ca < ~ctx.r10.u32;
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_8244146C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824414e0
	if (ctx.cr0.eq) goto loc_824414E0;
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82441698
	ctx.lr = 0x82441480;
	sub_82441698(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x824414a4
	if (!ctx.cr0.eq) goto loc_824414A4;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x8258af80
	ctx.lr = 0x824414A0;
	sub_8258AF80(ctx, base);
	// b 0x824414e0
	goto loc_824414E0;
loc_824414A4:
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824414e8
	ctx.lr = 0x824414B0;
	sub_824414E8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// add r30,r29,r11
	ctx.r30.u64 = ctx.r29.u64 + ctx.r11.u64;
	// bl 0x823b52a0
	ctx.lr = 0x824414C4;
	sub_823B52A0(ctx, base);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x824414d0
	if (ctx.cr6.lt) goto loc_824414D0;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_824414D0:
	// addi r4,r1,156
	ctx.r4.s64 = ctx.r1.s64 + 156;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x824414e8
	ctx.lr = 0x824414DC;
	sub_824414E8(ctx, base);
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
loc_824414E0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82446E50) {
	REX_FUNC_PROLOGUE();
	// addi r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 1;
	// cmplw cr6,r4,r9
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r9.u32, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
loc_82446E60:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82446e60
	if (!ctx.cr6.eq) goto loc_82446E60;
	// subf r11,r4,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r4.u64;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// li r10,63
	ctx.r10.s64 = 63;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82446ebc
	if (ctx.cr0.eq) goto loc_82446EBC;
loc_82446E90:
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// ble cr6,0x82446ea8
	if (!ctx.cr6.gt) goto loc_82446EA8;
	// stb r11,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r11.u8);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
loc_82446EA8:
	// lbz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82446e90
	if (!ctx.cr0.eq) goto loc_82446E90;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
loc_82446EBC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,0(r9)
	REX_STORE_U8(ctx.r9.u32 + 0, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82448F80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82448F88;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// clrlwi. r11,r4,24
	ctx.r11.u64 = ctx.r4.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82449090
	if (!ctx.cr0.eq) goto loc_82449090;
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// bge cr6,0x824490e4
	if (!ctx.cr6.lt) goto loc_824490E4;
	// lwz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82449008
	if (ctx.cr6.eq) goto loc_82449008;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8258ab70
	ctx.lr = 0x82448FC0;
	sub_8258AB70(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824490e4
	if (ctx.cr0.eq) goto loc_824490E4;
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82448ff8
	if (!ctx.cr6.eq) goto loc_82448FF8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,8(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stb r9,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r9.u8);
	// b 0x824490e4
	goto loc_824490E4;
loc_82448FF8:
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x82449008
	if (ctx.cr6.eq) goto loc_82449008;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x824490e4
	if (!ctx.cr6.eq) goto loc_824490E4;
loc_82449008:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,24
	ctx.r4.s64 = 24;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82449020;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82449060
	if (ctx.cr0.eq) goto loc_82449060;
	// lis r4,12
	ctx.r4.s64 = 786432;
	// lwz r7,8(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// li r5,271
	ctx.r5.s64 = 271;
	// ori r4,r4,31
	ctx.r4.u64 = ctx.r4.u64 | 31;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82584f88
	ctx.lr = 0x82449044;
	sub_82584F88(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,4
	ctx.r10.s64 = 4;
	// addi r11,r11,13924
	ctx.r11.s64 = ctx.r11.s64 + 13924;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// b 0x82449064
	goto loc_82449064;
loc_82449060:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82449064:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8258a8c8
	ctx.lr = 0x82449070;
	sub_8258A8C8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r29,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r29.u32);
	// bl 0x8258c5e8
	ctx.lr = 0x8244908C;
	sub_8258C5E8(ctx, base);
	// b 0x824490e4
	goto loc_824490E4;
loc_82449090:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lwz r31,20(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,20
	ctx.r4.s64 = 20;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824490AC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824490dc
	if (ctx.cr0.eq) goto loc_824490DC;
	// li r10,521
	ctx.r10.s64 = 521;
	// stw r29,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r29.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stw r31,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r31.u32);
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// stw r10,16(r3)
	REX_STORE_U32(ctx.r3.u32 + 16, ctx.r10.u32);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// b 0x824490e0
	goto loc_824490E0;
loc_824490DC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824490E0:
	// bl 0x825a2ef8
	ctx.lr = 0x824490E4;
	sub_825A2EF8(ctx, base);
loc_824490E4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82452DE8) {
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
	// bl 0x82453d80
	ctx.lr = 0x82452DF8;
	sub_82453D80(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,-12948(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12948);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824537A8) {
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
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r11,-12944(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12944);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824537e8
	if (ctx.cr6.eq) goto loc_824537E8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x824537e8
	if (ctx.cr6.eq) goto loc_824537E8;
	// li r6,150
	ctx.r6.s64 = 150;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82454970
	ctx.lr = 0x824537E4;
	sub_82454970(ctx, base);
	// b 0x824537ec
	goto loc_824537EC;
loc_824537E8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824537EC:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824537fc
	if (ctx.cr6.eq) goto loc_824537FC;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// b 0x82453800
	goto loc_82453800;
loc_824537FC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82453800:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824553E0) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12932(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12932);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245542c
	if (ctx.cr6.eq) goto loc_8245542C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245542c
	if (ctx.cr6.eq) goto loc_8245542C;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r10,-12940(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -12940);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8245542c
	if (ctx.cr6.eq) goto loc_8245542C;
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplw cr6,r10,r3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x8245542c
	if (!ctx.cr6.gt) goto loc_8245542C;
	// mulli r10,r3,62
	ctx.r10.s64 = static_cast<int64_t>(ctx.r3.u64 * static_cast<uint64_t>(62));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r3,r11,20
	ctx.r3.s64 = ctx.r11.s64 + 20;
	// blr 
	return;
loc_8245542C:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824563F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,132(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// stfs f13,132(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgtlr cr6
	if (ctx.cr6.gt) return;
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f0,132(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 132, temp.u32);
	// stb r11,112(r3)
	REX_STORE_U8(ctx.r3.u32 + 112, ctx.r11.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82458498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x824584A0;
	__savegprlr_25(ctx, base);
	// stfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// bl 0x825f8d38
	ctx.lr = 0x824584CC;
	sub_825F8D38(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// li r25,0
	ctx.r25.s64 = 0;
	// beq 0x824584f8
	if (ctx.cr0.eq) goto loc_824584F8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8b88
	ctx.lr = 0x824584E0;
	sub_825F8B88(ctx, base);
	// li r6,448
	ctx.r6.s64 = 448;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x824584F4;
	sub_825F8BF8(ctx, base);
	// b 0x824584fc
	goto loc_824584FC;
loc_824584F8:
	// mr r31,r25
	ctx.r31.u64 = ctx.r25.u64;
loc_824584FC:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824585d8
	if (ctx.cr6.eq) goto loc_824585D8;
	// stfs f31,412(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 412, temp.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x8245856c
	if (ctx.cr6.eq) goto loc_8245856C;
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x82458368
	ctx.lr = 0x82458518;
	sub_82458368(ctx, base);
	// clrlwi. r11,r28,24
	ctx.r11.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// beq 0x82458560
	if (ctx.cr0.eq) goto loc_82458560;
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x825fa250
	ctx.lr = 0x82458530;
	sub_825FA250(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82458560
	if (ctx.cr0.eq) goto loc_82458560;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r30,19,11,12
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 19) & 0x180000) | (ctx.r10.u64 & 0xFFFFFFFFFFE7FFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// rlwimi r10,r30,21,9,10
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 21) & 0x600000) | (ctx.r10.u64 & 0xFFFFFFFFFF9FFFFF);
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x825f9cf8
	ctx.lr = 0x82458560;
	sub_825F9CF8(ctx, base);
loc_82458560:
	// stw r27,208(r31)
	REX_STORE_U32(ctx.r31.u32 + 208, ctx.r27.u32);
	// stb r30,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r30.u8);
	// b 0x8245857c
	goto loc_8245857C;
loc_8245856C:
	// li r3,1
	ctx.r3.s64 = 1;
	// bl 0x82458368
	ctx.lr = 0x82458574;
	sub_82458368(ctx, base);
	// stw r3,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r3.u32);
	// stb r25,71(r31)
	REX_STORE_U8(ctx.r31.u32 + 71, ctx.r25.u8);
loc_8245857C:
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lwz r9,408(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 408);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// sth r25,72(r31)
	REX_STORE_U16(ctx.r31.u32 + 72, ctx.r25.u16);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// vupkd3d128 v63,v63,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v63.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v63 = vTemp;
	// ori r9,r9,4
	ctx.r9.u64 = ctx.r9.u64 | 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// li r5,64
	ctx.r5.s64 = 64;
	// stw r9,408(r31)
	REX_STORE_U32(ctx.r31.u32 + 408, ctx.r9.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r26,368(r31)
	REX_STORE_U32(ctx.r31.u32 + 368, ctx.r26.u32);
	// vpermwi128 v62,v63,234
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x15));
	// vpermwi128 v61,v63,186
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x45));
	// vpermwi128 v60,v63,174
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x51));
	// vpermwi128 v63,v63,171
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x54));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8273a030
	ctx.lr = 0x824585D8;
	sub_8273A030(ctx, base);
loc_824585D8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824663B8) {
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
	// li r3,0
	ctx.r3.s64 = 0;
	// bl 0x824043d0
	ctx.lr = 0x824663D8;
	sub_824043D0(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r30,0
	ctx.r30.s64 = 0;
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82466418
	if (ctx.cr0.eq) goto loc_82466418;
	// bl 0x82213210
	ctx.lr = 0x824663F0;
	sub_82213210(ctx, base);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lbz r11,22(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
	// stb r11,4033(r3)
	REX_STORE_U8(ctx.r3.u32 + 4033, ctx.r11.u8);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lbz r11,21(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// stb r11,4032(r3)
	REX_STORE_U8(ctx.r3.u32 + 4032, ctx.r11.u8);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// stb r30,21(r11)
	REX_STORE_U8(ctx.r11.u32 + 21, ctx.r30.u8);
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// stb r30,22(r11)
	REX_STORE_U8(ctx.r11.u32 + 22, ctx.r30.u8);
loc_82466418:
	// lwz r3,72(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82466428
	if (ctx.cr6.eq) goto loc_82466428;
	// bl 0x825e0378
	ctx.lr = 0x82466428;
	sub_825E0378(ctx, base);
loc_82466428:
	// stw r30,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r30.u32);
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

DEFINE_REX_FUNC(sub_8246CB48) {
	REX_FUNC_PROLOGUE();
	// lwz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// lwz r10,124(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8246cb68
	if (ctx.cr6.lt) goto loc_8246CB68;
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8246CB68:
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8246DCF0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8246DCF8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,108(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 108);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r26,r3,80
	ctx.r26.s64 = ctx.r3.s64 + 80;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246dd18
	if (ctx.cr0.eq) goto loc_8246DD18;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82855b44
	ctx.lr = 0x8246DD18;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8246DD18:
	// lbz r11,112(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 112);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246de30
	if (ctx.cr0.eq) goto loc_8246DE30;
	// lwz r11,132(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 132);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8246de20
	if (ctx.cr6.eq) goto loc_8246DE20;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
loc_8246DD38:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8246dd50
	if (ctx.cr6.eq) goto loc_8246DD50;
	// bl 0x823bdef8
	ctx.lr = 0x8246DD4C;
	sub_823BDEF8(ctx, base);
	// b 0x8246ddc4
	goto loc_8246DDC4;
loc_8246DD50:
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x8246ddc0
	if (ctx.cr6.eq) goto loc_8246DDC0;
	// lwz r10,-12824(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + -12824);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// addi r29,r10,136
	ctx.r29.s64 = ctx.r10.s64 + 136;
	// lbz r11,164(r10)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r10.u32 + 164);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246dd80
	if (ctx.cr0.eq) goto loc_8246DD80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b44
	ctx.lr = 0x8246DD80;
	__imp__RtlEnterCriticalSection(ctx, base);
loc_8246DD80:
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246dd9c
	if (!ctx.cr6.eq) goto loc_8246DD9C;
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// beq cr6,0x8246dda0
	if (ctx.cr6.eq) goto loc_8246DDA0;
loc_8246DD9C:
	// li r11,1
	ctx.r11.s64 = 1;
loc_8246DDA0:
	// lbz r10,28(r29)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r29.u32 + 28);
	// clrlwi r31,r11,24
	ctx.r31.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8246ddb8
	if (ctx.cr0.eq) goto loc_8246DDB8;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82855b34
	ctx.lr = 0x8246DDB8;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8246DDB8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x8246ddc4
	goto loc_8246DDC4;
loc_8246DDC0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8246DDC4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8246de10
	if (!ctx.cr0.eq) goto loc_8246DE10;
	// lwz r11,132(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 132);
	// addi r31,r28,128
	ctx.r31.s64 = ctx.r28.s64 + 128;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8246de08
	if (ctx.cr6.eq) goto loc_8246DE08;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// bl 0x825e0378
	ctx.lr = 0x8246DDFC;
	sub_825E0378(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_8246DE08:
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// b 0x8246de14
	goto loc_8246DE14;
loc_8246DE10:
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
loc_8246DE14:
	// lwz r11,132(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 132);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8246dd38
	if (!ctx.cr6.eq) goto loc_8246DD38;
loc_8246DE20:
	// lwz r11,136(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 136);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8246de30
	if (!ctx.cr6.eq) goto loc_8246DE30;
	// stb r11,112(r28)
	REX_STORE_U8(ctx.r28.u32 + 112, ctx.r11.u8);
loc_8246DE30:
	// lbz r11,28(r26)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + 28);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8246de44
	if (ctx.cr0.eq) goto loc_8246DE44;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82855b34
	ctx.lr = 0x8246DE44;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_8246DE44:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82476398) {
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
	// bl 0x8246b058
	ctx.lr = 0x824763B0;
	sub_8246B058(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82478d88
	ctx.lr = 0x824763B8;
	sub_82478D88(ctx, base);
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

DEFINE_REX_FUNC(sub_82478530) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82478538;
	__savegprlr_23(ctx, base);
	// stfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r10,124(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// addi r26,r3,120
	ctx.r26.s64 = ctx.r3.s64 + 120;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824789e8
	if (ctx.cr0.eq) goto loc_824789E8;
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824789e8
	if (ctx.cr0.eq) goto loc_824789E8;
	// addi r27,r1,88
	ctx.r27.s64 = ctx.r1.s64 + 88;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8247857C:
	// lwz r4,308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 848);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478598;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,820(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 820);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824785B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,136
	ctx.r3.s64 = ctx.r1.s64 + 136;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 848);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824785E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r28,r3,4
	ctx.r28.s64 = ctx.r3.s64 + 4;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r11,820(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 820);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478608;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,768(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 768);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247863C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,4(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// clrlwi r4,r3,16
	ctx.r4.u64 = ctx.r3.u32 & 0xFFFF;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bctrl 
	ctx.lr = 0x82478650;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r24,r29,r11
	ctx.r24.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,852(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 852);
	// lwz r28,0(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478678;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r11,476(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 476);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478690;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// fadds f1,f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f31.f64 + ctx.f1.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824786A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,828(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 828);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824786C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,84(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 84);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824786D8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,832(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 832);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824786FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,88(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 88);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247870C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r28,r29,r11
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,816(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 816);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247872C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r4,0(r27)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478748;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,784(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 784);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247876C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,112(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 112);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478780;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,788(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 788);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824787A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824787B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,836(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 836);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824787DC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,120(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 120);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824787EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,840(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 840);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478810;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,176(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 176);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478824;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,780(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 780);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478848;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,184(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 184);
	// clrlwi r4,r3,24
	ctx.r4.u64 = ctx.r3.u32 & 0xFF;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247885C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,856(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 856);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478880;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,188(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 188);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478894;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,308(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r3,r1,152
	ctx.r3.s64 = ctx.r1.s64 + 152;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwzx r24,r29,r11
	ctx.r24.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,848(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 848);
	// lwz r28,0(r24)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r24.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824788C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r11,848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 848);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824788E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,160(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 160);
	// lfs f13,0(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lhz r5,94(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 94);
	// lhz r4,118(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 118);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478910;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247892C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwzx r25,r29,r11
	ctx.r25.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,860(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 860);
	// lwz r28,0(r25)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478950;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,108(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 108);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82478964;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,864(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 864);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247897C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824789c8
	if (ctx.cr0.eq) goto loc_824789C8;
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,868(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 868);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824789A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lhz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// lfs f1,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f1.f64 = double(temp.f32);
	// lwzx r3,r29,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824789C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824789C8:
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8247857c
	if (ctx.cr6.lt) goto loc_8247857C;
loc_824789E8:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// lfd f31,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824A26E8) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824A2704;
	sub_8235EC48(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r11,-21668
	ctx.r4.s64 = ctx.r11.s64 + -21668;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8246b640
	ctx.lr = 0x824A2718;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x824a272c
	if (!ctx.cr6.lt) goto loc_824A272C;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_824A272C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a2744
	if (ctx.cr6.eq) goto loc_824A2744;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x824A2744;
	sub_8246D8F0(ctx, base);
loc_824A2744:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x824A2754;
	sub_8235EC48(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824A4E38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x824A4E40;
	__savegprlr_24(ctx, base);
	// stfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,364(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 364);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824a5498
	if (ctx.cr6.lt) goto loc_824A5498;
	// beq cr6,0x824a5128
	if (ctx.cr6.eq) goto loc_824A5128;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x824a5104
	if (ctx.cr6.lt) goto loc_824A5104;
	// beq cr6,0x824a503c
	if (ctx.cr6.eq) goto loc_824A503C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x824a4f84
	if (ctx.cr6.lt) goto loc_824A4F84;
	// beq cr6,0x824a4e8c
	if (ctx.cr6.eq) goto loc_824A4E8C;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bge cr6,0x824a54a4
	if (!ctx.cr6.lt) goto loc_824A54A4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x824a54a4
	goto loc_824A54A4;
loc_824A4E8C:
	// lwz r3,404(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x824a4ea8
	if (ctx.cr6.eq) goto loc_824A4EA8;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x825765f0
	ctx.lr = 0x824A4EA0;
	sub_825765F0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
loc_824A4EA8:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f11.f64 = double(temp.f32);
	// li r9,6
	ctx.r9.s64 = 6;
	// addi r10,r11,-32216
	ctx.r10.s64 = ctx.r11.s64 + -32216;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// lfs f0,2088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2088);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f12,-1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f13,380(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// fsubs f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 - ctx.f0.f64));
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// fcmpu cr6,f13,f12
	ctx.cr6.compare(ctx.f13.f64, ctx.f12.f64);
	// bge cr6,0x824a4ef0
	if (!ctx.cr6.lt) goto loc_824A4EF0;
	// stfs f12,380(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// stw r9,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r9.u32);
loc_824A4EF0:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824a4f00
	if (!ctx.cr6.lt) goto loc_824A4F00;
	// stfs f12,392(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// stw r9,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r9.u32);
loc_824A4F00:
	// lfs f0,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824a4f14
	if (!ctx.cr6.gt) goto loc_824A4F14;
	// stfs f13,380(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
loc_824A4F14:
	// lfs f0,392(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824a4f24
	if (!ctx.cr6.gt) goto loc_824A4F24;
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
loc_824A4F24:
	// lfs f11,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f0,f11
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f11.f64)));
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x824a4f44
	if (ctx.cr6.lt) goto loc_824A4F44;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x824a4f50
	goto loc_824A4F50;
loc_824A4F44:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824a4f54
	if (!ctx.cr6.lt) goto loc_824A4F54;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_824A4F50:
	// stfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
loc_824A4F54:
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r11,r31,292
	ctx.r11.s64 = ctx.r31.s64 + 292;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_824A4F60:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824a4f78
	if (!ctx.cr6.lt) goto loc_824A4F78;
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_824A4F78:
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// bdnz 0x824a4f60
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824A4F60;
	// b 0x824a54a4
	goto loc_824A54A4;
loc_824A4F84:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f12,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f12.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// lfs f11,392(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 392);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,-32216
	ctx.r11.s64 = ctx.r11.s64 + -32216;
	// addi r10,r10,14376
	ctx.r10.s64 = ctx.r10.s64 + 14376;
	// lfs f0,2088(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2088);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f13,-2140(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// stfs f12,380(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// stfs f0,392(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x824a4fc4
	if (!ctx.cr6.gt) goto loc_824A4FC4;
	// stfs f13,380(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 380, temp.u32);
loc_824A4FC4:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824a4fd0
	if (!ctx.cr6.gt) goto loc_824A4FD0;
	// stfs f13,392(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 392, temp.u32);
loc_824A4FD0:
	// lfs f12,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f0,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f12.f64)));
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x824a4ff0
	if (ctx.cr6.lt) goto loc_824A4FF0;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// b 0x824a5000
	goto loc_824A5000;
loc_824A4FF0:
	// lfs f12,-1908(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1908);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f0,f12
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bge cr6,0x824a5004
	if (!ctx.cr6.lt) goto loc_824A5004;
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
loc_824A5000:
	// stfs f0,396(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
loc_824A5004:
	// lfs f0,416(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// lbz r11,412(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 412);
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,416(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 416, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824a5024
	if (ctx.cr0.eq) goto loc_824A5024;
	// lfs f13,372(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 372);
	ctx.f13.f64 = double(temp.f32);
	// b 0x824a502c
	goto loc_824A502C;
loc_824A5024:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,17288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17288);
	ctx.f13.f64 = double(temp.f32);
loc_824A502C:
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824a54a4
	if (!ctx.cr6.gt) goto loc_824A54A4;
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x824a5490
	goto loc_824A5490;
loc_824A503C:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// addi r11,r11,-32216
	ctx.r11.s64 = ctx.r11.s64 + -32216;
	// addi r9,r9,14376
	ctx.r9.s64 = ctx.r9.s64 + 14376;
	// li r26,0
	ctx.r26.s64 = 0;
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// lfs f12,2088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2088);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,-1908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1908);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,-2140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
loc_824A5060:
	// mulli r11,r26,20
	ctx.r11.s64 = static_cast<int64_t>(ctx.r26.u64 * static_cast<uint64_t>(20));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// lbz r9,288(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 288);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x824a509c
	if (ctx.cr0.eq) goto loc_824A509C;
	// lfs f0,292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f0,f31,f12,f0
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f12.f64, ctx.f0.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824a5094
	if (!ctx.cr6.gt) goto loc_824A5094;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// cmplwi cr6,r26,2
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 2, ctx.xer);
	// bne cr6,0x824a5094
	if (!ctx.cr6.eq) goto loc_824A5094;
	// li r10,1
	ctx.r10.s64 = 1;
loc_824A5094:
	// stfs f0,292(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 292, temp.u32);
	// b 0x824a50b8
	goto loc_824A50B8;
loc_824A509C:
	// lfs f0,296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,296(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 296, temp.u32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// bge cr6,0x824a50b8
	if (!ctx.cr6.lt) goto loc_824A50B8;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,288(r11)
	REX_STORE_U8(ctx.r11.u32 + 288, ctx.r9.u8);
loc_824A50B8:
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// cmplwi cr6,r26,3
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 3, ctx.xer);
	// blt cr6,0x824a5060
	if (ctx.cr6.lt) goto loc_824A5060;
	// clrlwi. r11,r10,24
	ctx.r11.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824a54a4
	if (ctx.cr0.eq) goto loc_824A54A4;
	// lfs f0,408(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 408);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,408(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 408, temp.u32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// bge cr6,0x824a54a4
	if (!ctx.cr6.lt) goto loc_824A54A4;
	// li r11,4
	ctx.r11.s64 = 4;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stw r11,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r10,-21388
	ctx.r3.s64 = ctx.r10.s64 + -21388;
	// addi r4,r31,340
	ctx.r4.s64 = ctx.r31.s64 + 340;
	// bl 0x8257d4d8
	ctx.lr = 0x824A50FC;
	sub_8257D4D8(ctx, base);
	// stw r3,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r3.u32);
	// b 0x824a54a4
	goto loc_824A54A4;
loc_824A5104:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r11,288(r31)
	REX_STORE_U8(ctx.r31.u32 + 288, ctx.r11.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r3,r10,-21412
	ctx.r3.s64 = ctx.r10.s64 + -21412;
	// addi r4,r31,340
	ctx.r4.s64 = ctx.r31.s64 + 340;
	// bl 0x8257d4d8
	ctx.lr = 0x824A5120;
	sub_8257D4D8(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x824a5490
	goto loc_824A5490;
loc_824A5128:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
	// lfs f13,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f13.f64 = double(temp.f32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// li r26,0
	ctx.r26.s64 = 0;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r26,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r26.u32);
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lwz r29,-13032(r8)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r8.u32 + -13032);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// stw r26,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r26.u32);
	// stw r26,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r26.u32);
	// addi r30,r31,340
	ctx.r30.s64 = ctx.r31.s64 + 340;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r6,100(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824a51b0
	if (ctx.cr6.eq) goto loc_824A51B0;
	// addi r7,r5,-1024
	ctx.r7.s64 = ctx.r5.s64 + -1024;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// bl 0x823af5b0
	ctx.lr = 0x824A51B0;
	sub_823AF5B0(ctx, base);
loc_824A51B0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r3,400(r31)
	REX_STORE_U8(ctx.r31.u32 + 400, ctx.r3.u8);
	// beq 0x824a527c
	if (ctx.cr0.eq) goto loc_824A527C;
	// lfs f0,152(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lfs f13,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r27,84(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x824a51f8
	if (ctx.cr6.eq) goto loc_824A51F8;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x823ae820
	ctx.lr = 0x824A51F8;
	sub_823AE820(ctx, base);
loc_824A51F8:
	// add r11,r3,r28
	ctx.r11.u64 = ctx.r3.u64 + ctx.r28.u64;
	// extsw r10,r27
	ctx.r10.s64 = ctx.r27.s32;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,348(r31)
	REX_STORE_U64(ctx.r31.u32 + 348, ctx.r11.u64);
loc_824A527C:
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,348(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 348);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lis r3,-32225
	ctx.r3.s64 = -2111897600;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r3,32720
	ctx.r28.s64 = ctx.r3.s64 + 32720;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r3,-32225
	ctx.r3.s64 = -2111897600;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r29,r1,128
	ctx.r29.s64 = ctx.r1.s64 + 128;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r3,32432
	ctx.r3.s64 = ctx.r3.s64 + 32432;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lfs f13,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lfs f0,352(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// addi r27,r1,128
	ctx.r27.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lwz r25,0(r30)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lwz r24,4(r30)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v59,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r25.u32);
	// stw r24,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r24.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vsubfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,32256
	ctx.r10.s64 = ctx.r10.s64 + 32256;
	// stfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// vsubfp128 v60,v59,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v60,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmaddfp v0,v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v6,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,84(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
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
	// vmaddfp v13,v13,v6,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v11,v10,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
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
	// stvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,388(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 388, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x824A53FC;
	sub_8255F918(ctx, base);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r11,-31872
	ctx.r9.s64 = ctx.r11.s64 + -31872;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r11,14376
	ctx.r29.s64 = ctx.r11.s64 + 14376;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stw r10,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r10.u32);
	// lfs f11,14376(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f11.f64 = double(temp.f32);
	// lwz r11,4(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stfs f11,316(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// stw r11,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r11.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x824A545C;
	sub_8255F918(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r11,3
	ctx.r11.s64 = 3;
	// lfs f0,-1908(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1908);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r31,272
	ctx.r10.s64 = ctx.r31.s64 + 272;
	// stw r9,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r9.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stfs f11,336(r31)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r31.u32 + 336, temp.u32);
	// stw r11,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
loc_824A5480:
	// stb r26,16(r10)
	REX_STORE_U8(ctx.r10.u32 + 16, ctx.r26.u8);
	// stfsu f0,20(r10)
	ctx.fpscr.disableFlushMode();
	ea = 20 + ctx.r10.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x824a5480
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_824A5480;
	// li r11,2
	ctx.r11.s64 = 2;
loc_824A5490:
	// stw r11,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r11.u32);
	// b 0x824a54a4
	goto loc_824A54A4;
loc_824A5498:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// std r11,348(r31)
	REX_STORE_U64(ctx.r31.u32 + 348, ctx.r11.u64);
loc_824A54A4:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// lfd f31,-80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824DFDE8) {
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
	// addi r11,r11,-12872
	ctx.r11.s64 = ctx.r11.s64 + -12872;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824DFE14;
	sub_82469EE8(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824dfe24
	if (ctx.cr0.eq) goto loc_824DFE24;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x824DFE24;
	sub_825E0378(ctx, base);
loc_824DFE24:
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

DEFINE_REX_FUNC(sub_824E08C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x824E08C8;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,316(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 316);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824e09ec
	if (ctx.cr0.eq) goto loc_824E09EC;
	// ld r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 44);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f13,320(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 320);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f12,324(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 324);
	ctx.f12.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f13,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,176(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x824E099C;
	sub_8231E0D8(ctx, base);
	// ld r11,44(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 44);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// li r3,311
	ctx.r3.s64 = 311;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// std r9,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r9.u64);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stw r11,328(r29)
	REX_STORE_U32(ctx.r29.u32 + 328, ctx.r11.u32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// stw r11,332(r29)
	REX_STORE_U32(ctx.r29.u32 + 332, ctx.r11.u32);
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r5,116(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r4,132(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x82240a58
	ctx.lr = 0x824E09E8;
	sub_82240A58(ctx, base);
	// stb r31,316(r29)
	REX_STORE_U8(ctx.r29.u32 + 316, ctx.r31.u8);
loc_824E09EC:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,328(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 328);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r27,r1,96
	ctx.r27.s64 = ctx.r1.s64 + 96;
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f0,332(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 332);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r10,-31440
	ctx.r10.s64 = ctx.r10.s64 + -31440;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r28,r1,80
	ctx.r28.s64 = ctx.r1.s64 + 80;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r29,68
	ctx.r4.s64 = ctx.r29.s64 + 68;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vmulfp128 v62,v60,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x824e1570
	ctx.lr = 0x824E0AD8;
	sub_824E1570(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// addi r11,r11,32256
	ctx.r11.s64 = ctx.r11.s64 + 32256;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// lvx128 v6,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r11.u32);
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
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
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v13,v62,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v0.f32))));
	// lfs f13,27412(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27412);
	ctx.f13.f64 = double(temp.f32);
	// vmulfp128 v12,v0,v6
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)));
	// vcmpeqfp128 v10,v0,v63
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpeqfp128 v8,v0,v63
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v11,v13,v13
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vor v9,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vcmpeqfp128 v5,v13,v63
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vnmsubfp v6,v12,v11,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v6.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v11,v10,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8))));
	// vmaddfp v13,v13,v6,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v12,v13,v9,v11
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8))));
	// vor128 v62,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v12.u8));
	// vcmpeqfp128 v12,v62,v63
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v13,v0,v62
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vsel v12,v8,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vsel v0,v13,v0,v12
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x824e0cd8
	if (!ctx.cr6.gt) goto loc_824E0CD8;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r9,432
	ctx.r9.s64 = 432;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r10,31600
	ctx.r10.s64 = ctx.r10.s64 + 31600;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r30,r1,80
	ctx.r30.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r10,r10,-30720
	ctx.r10.s64 = ctx.r10.s64 + -30720;
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// vrefp128 v0,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v62.f32)));
	// vor128 v10,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vor128 v12,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// vcmpeqfp128 v8,v62,v63
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpeqfp128 v7,v62,v63
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v6,v62,v62
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v62.u8));
	// stfs f0,88(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// vnmsubfp v1,v10,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v10,v13,v13
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v13.u8));
	// vnmsubfp v2,v12,v0,v13
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp128 v4,v0,v63
	simde_mm_store_ps(ctx.v4.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpeqfp128 v3,v0,v63
	simde_mm_store_ps(ctx.v3.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v11,v0,v1,v0
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v12,v0,v2,v0
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v4,v8,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8))));
	// vsel v8,v7,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8))));
	// vor v9,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// vnmsubfp v7,v6,v12,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp128 v10,v62,v9,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v10.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v13,v12,v7,v12
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v12,v11,v10,v11
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vsel v11,v13,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vsel v13,v12,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v63,v63,v11
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v13
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
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
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v60
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,0(r4)
	REX_STORE_U64(ctx.r4.u32 + 0, ctx.r11.u64);
loc_824E0CD8:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lfs f13,0(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// ld r6,44(r29)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r29.u32 + 44);
	// stfs f31,132(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r5,r1,128
	ctx.r5.s64 = ctx.r1.s64 + 128;
	// stfs f31,128(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f31,140(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f31,136(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// bl 0x824e1570
	ctx.lr = 0x824E0D70;
	sub_824E1570(ctx, base);
	// lwz r11,140(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 140);
	// li r7,0
	ctx.r7.s64 = 0;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,16
	ctx.r5.s64 = 16;
	// addi r4,r1,176
	ctx.r4.s64 = ctx.r1.s64 + 176;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E0DA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwa r6,176(r1)
	ctx.r6.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 176));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// std r6,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r6.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lwa r7,180(r1)
	ctx.r7.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 180));
	// std r7,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r7.u64);
	// lfd f13,144(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// bl 0x824e1570
	ctx.lr = 0x824E0E28;
	sub_824E1570(ctx, base);
	// lwa r11,188(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 188));
	// ld r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwa r9,184(r1)
	ctx.r9.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 184));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lfd f0,144(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r9,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r9.u64);
	// lfd f13,144(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x824e1570
	ctx.lr = 0x824E0EB4;
	sub_824E1570(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// std r30,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r30.u64);
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r9,r9,2688
	ctx.r9.s64 = ctx.r9.s64 + 2688;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r8,244(r1)
	REX_STORE_U32(ctx.r1.u32 + 244, ctx.r8.u32);
	// lwz r30,-13032(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// stw r9,240(r1)
	REX_STORE_U32(ctx.r1.u32 + 240, ctx.r9.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// std r10,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r10.u64);
	// beq cr6,0x824e0f10
	if (ctx.cr6.eq) goto loc_824E0F10;
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lfs f0,132(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 132);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x823aefa8
	ctx.lr = 0x824E0F10;
	sub_823AEFA8(ctx, base);
loc_824E0F10:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// stb r3,200(r1)
	REX_STORE_U8(ctx.r1.u32 + 200, ctx.r3.u8);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r31,208(r1)
	REX_STORE_U32(ctx.r1.u32 + 208, ctx.r31.u32);
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r31,212(r1)
	REX_STORE_U32(ctx.r1.u32 + 212, ctx.r31.u32);
	// lis r8,16384
	ctx.r8.s64 = 1073741824;
	// stw r31,216(r1)
	REX_STORE_U32(ctx.r1.u32 + 216, ctx.r31.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stw r9,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r9.u32);
	// ld r11,2880(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,12468(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,196(r1)
	REX_STORE_U32(ctx.r1.u32 + 196, ctx.r8.u32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stw r31,232(r1)
	REX_STORE_U32(ctx.r1.u32 + 232, ctx.r31.u32);
	// stw r7,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r7.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r31,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r31.u32);
	// std r11,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r11.u64);
	// stw r31,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r31.u32);
	// stw r31,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r31.u32);
	// stb r31,172(r1)
	REX_STORE_U8(ctx.r1.u32 + 172, ctx.r31.u8);
	// stb r31,173(r1)
	REX_STORE_U8(ctx.r1.u32 + 173, ctx.r31.u8);
	// beq cr6,0x824e0f90
	if (ctx.cr6.eq) goto loc_824E0F90;
	// lis r6,16384
	ctx.r6.s64 = 1073741824;
	// li r7,0
	ctx.r7.s64 = 0;
	// ori r6,r6,2
	ctx.r6.u64 = ctx.r6.u64 | 2;
	// addi r5,r1,192
	ctx.r5.s64 = ctx.r1.s64 + 192;
	// addi r4,r1,160
	ctx.r4.s64 = ctx.r1.s64 + 160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823b0d90
	ctx.lr = 0x824E0F90;
	sub_823B0D90(ctx, base);
loc_824E0F90:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824e1160
	if (ctx.cr0.eq) goto loc_824E1160;
	// bl 0x824281d8
	ctx.lr = 0x824E0F9C;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// beq 0x824e1098
	if (ctx.cr0.eq) goto loc_824E1098;
	// bl 0x82429960
	ctx.lr = 0x824E0FB0;
	sub_82429960(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// bl 0x8242a5e0
	ctx.lr = 0x824E0FB8;
	sub_8242A5E0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// clrlwi r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x824e1160
	if (!ctx.cr6.eq) goto loc_824E1160;
	// lwz r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x824443c8
	ctx.lr = 0x824E0FD4;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824e1160
	if (ctx.cr0.eq) goto loc_824E1160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82439d78
	ctx.lr = 0x824E0FE4;
	sub_82439D78(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lbz r11,2364(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824e100c
	if (!ctx.cr6.eq) goto loc_824E100C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824e1020
	goto loc_824E1020;
loc_824E100C:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,584(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 584);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1020;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824E1020:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E103C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1058;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 88);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824e1160
	if (!ctx.cr6.eq) goto loc_824E1160;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824e1160
	if (ctx.cr6.eq) goto loc_824E1160;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// b 0x824e115c
	goto loc_824E115C;
loc_824E1098:
	// bl 0x824443c8
	ctx.lr = 0x824E109C;
	sub_824443C8(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824e1160
	if (ctx.cr0.eq) goto loc_824E1160;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82439d78
	ctx.lr = 0x824E10AC;
	sub_82439D78(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lbz r11,2364(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 2364);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lwz r11,2340(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824e10d4
	if (!ctx.cr6.eq) goto loc_824E10D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// b 0x824e10e8
	goto loc_824E10E8;
loc_824E10D4:
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,584(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 584);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E10E8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824E10E8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,156(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 156);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1104;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lwz r3,2340(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824E1120;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824e1160
	if (!ctx.cr0.eq) goto loc_824E1160;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 88);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824e1160
	if (!ctx.cr6.eq) goto loc_824E1160;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824e1160
	if (ctx.cr6.eq) goto loc_824E1160;
	// li r4,0
	ctx.r4.s64 = 0;
loc_824E115C:
	// bl 0x82250220
	ctx.lr = 0x824E1160;
	sub_82250220(ctx, base);
loc_824E1160:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8252F3C8) {
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
	// lwz r10,316(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 316);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,-1648
	ctx.r11.s64 = ctx.r11.s64 + -1648;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8252f458
	if (ctx.cr6.eq) goto loc_8252F458;
	// lwz r8,312(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 312);
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8252f458
	if (ctx.cr6.eq) goto loc_8252F458;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r7,-12816(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + -12816);
loc_8252F410:
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r10,172(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 172);
	// rlwinm r9,r6,4,12,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// bne cr6,0x8252f44c
	if (!ctx.cr6.eq) goto loc_8252F44C;
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8252f44c
	if (ctx.cr6.eq) goto loc_8252F44C;
	// lbz r9,23(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 23);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8252f44c
	if (!ctx.cr0.eq) goto loc_8252F44C;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r9,23(r10)
	REX_STORE_U8(ctx.r10.u32 + 23, ctx.r9.u8);
loc_8252F44C:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r11,r8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x8252f410
	if (!ctx.cr6.eq) goto loc_8252F410;
loc_8252F458:
	// addi r31,r30,308
	ctx.r31.s64 = ctx.r30.s64 + 308;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82524ba8
	ctx.lr = 0x8252F464;
	sub_82524BA8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82524ba8
	ctx.lr = 0x8252F46C;
	sub_82524BA8(ctx, base);
	// lwz r3,312(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 312);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8252f47c
	if (ctx.cr6.eq) goto loc_8252F47C;
	// bl 0x825e0378
	ctx.lr = 0x8252F47C;
	sub_825E0378(ctx, base);
loc_8252F47C:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-4968
	ctx.r11.s64 = ctx.r11.s64 + -4968;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x8252F498;
	sub_82469EE8(ctx, base);
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

DEFINE_REX_FUNC(sub_82534F20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82534F28;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r30,-32228
	ctx.r30.s64 = -2112094208;
	// lis r29,-32114
	ctx.r29.s64 = -2104623104;
	// addi r11,r30,-6412
	ctx.r11.s64 = ctx.r30.s64 + -6412;
	// lis r28,-32111
	ctx.r28.s64 = -2104426496;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f0,2808(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8020(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8020);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11188(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -11188);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82534f98
	ctx.lr = 0x82534F64;
	sub_82534F98(ctx, base);
	// lfs f0,2808(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 2808);
	ctx.f0.f64 = double(temp.f32);
	// li r4,1
	ctx.r4.s64 = 1;
	// lfs f12,-11188(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -11188);
	ctx.f12.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,-6412(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82534f98
	ctx.lr = 0x82534F8C;
	sub_82534F98(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825374D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825374D8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r8
	ctx.r28.u64 = ctx.r8.u64;
	// clrlwi r9,r7,24
	ctx.r9.u64 = ctx.r7.u32 & 0xFF;
	// addi r4,r10,788
	ctx.r4.s64 = ctx.r10.s64 + 788;
	// li r8,3
	ctx.r8.s64 = 3;
	// li r7,43
	ctx.r7.s64 = 43;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82537510;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,800
	ctx.r10.s64 = ctx.r10.s64 + 800;
	// stb r9,329(r31)
	REX_STORE_U8(ctx.r31.u32 + 329, ctx.r9.u8);
	// addic r8,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r8.s64 = ctx.r29.s64 + -1;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stb r9,330(r31)
	REX_STORE_U8(ctx.r31.u32 + 330, ctx.r9.u8);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// subfe r10,r8,r29
	temp.u8 = (~ctx.r8.u32 + ctx.r29.u32 < ~ctx.r8.u32) | (~ctx.r8.u32 + ctx.r29.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r8.u64 + ctx.r29.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// clrlwi. r8,r10,24
	ctx.r8.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lfs f13,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// lwz r8,0(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stw r8,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r8.u32);
	// lwz r8,4(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stfs f0,480(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 480, temp.u32);
	// stfs f13,312(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stw r8,336(r31)
	REX_STORE_U32(ctx.r31.u32 + 336, ctx.r8.u32);
	// stw r9,340(r31)
	REX_STORE_U32(ctx.r31.u32 + 340, ctx.r9.u32);
	// stb r28,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r28.u8);
	// stb r10,308(r31)
	REX_STORE_U8(ctx.r31.u32 + 308, ctx.r10.u8);
	// beq 0x82537580
	if (ctx.cr0.eq) goto loc_82537580;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,312(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
loc_82537580:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8253F098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8253F0A0;
	__savegprlr_28(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,140
	ctx.r4.s64 = 140;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x8253F0C0;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8253f130
	if (ctx.cr0.eq) goto loc_8253F130;
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253F0E4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253F0F8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253F110;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r11,1804
	ctx.r4.s64 = ctx.r11.s64 + 1804;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// bl 0x8225f1c0
	ctx.lr = 0x8253F128;
	sub_8225F1C0(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x8253f134
	goto loc_8253F134;
loc_8253F130:
	// li r31,0
	ctx.r31.s64 = 0;
loc_8253F134:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8253f1c8
	if (ctx.cr6.eq) goto loc_8253F1C8;
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stb r10,91(r31)
	REX_STORE_U8(ctx.r31.u32 + 91, ctx.r10.u8);
	// beq cr6,0x8253f154
	if (ctx.cr6.eq) goto loc_8253F154;
	// stb r10,140(r11)
	REX_STORE_U8(ctx.r11.u32 + 140, ctx.r10.u8);
loc_8253F154:
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253F170;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lfs f13,92(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253F198;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x8253F1A4;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8253f1c8
	if (!ctx.cr6.eq) goto loc_8253F1C8;
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
	ctx.lr = 0x8253F1C8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8253F1C8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82542D60) {
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
	// li r5,99
	ctx.r5.s64 = 99;
	// addi r4,r11,1804
	ctx.r4.s64 = ctx.r11.s64 + 1804;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a4b8
	ctx.lr = 0x82542D84;
	sub_8246A4B8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82542d94
	if (!ctx.cr0.eq) goto loc_82542D94;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_82542D94:
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

DEFINE_REX_FUNC(sub_82544960) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82544968;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82544980;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82544adc
	if (!ctx.cr0.eq) goto loc_82544ADC;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82544adc
	if (ctx.cr6.eq) goto loc_82544ADC;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lwz r28,-13032(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + -13032);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r30,84(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r29,100(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82544a4c
	if (ctx.cr6.eq) goto loc_82544A4C;
	// li r5,3
	ctx.r5.s64 = 3;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823afff8
	ctx.lr = 0x825449E4;
	sub_823AFFF8(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82544a4c
	if (ctx.cr0.eq) goto loc_82544A4C;
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// bl 0x823af1b0
	ctx.lr = 0x825449F4;
	sub_823AF1B0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82544a4c
	if (ctx.cr0.eq) goto loc_82544A4C;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82544adc
	if (ctx.cr6.eq) goto loc_82544ADC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stfs f0,68(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r10,144(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82544a3c
	if (ctx.cr0.eq) goto loc_82544A3C;
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r10.u32);
loc_82544A3C:
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// b 0x82544adc
	goto loc_82544ADC;
loc_82544A4C:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82544a6c
	if (ctx.cr6.eq) goto loc_82544A6C;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823aebd8
	ctx.lr = 0x82544A6C;
	sub_823AEBD8(ctx, base);
loc_82544A6C:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82544adc
	if (!ctx.cr6.lt) goto loc_82544ADC;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f12,48(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
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
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,72(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,48(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 48, temp.u32);
loc_82544ADC:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254FA58) {
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
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r11,-17868
	ctx.r4.s64 = ctx.r11.s64 + -17868;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x8246a2c0
	ctx.lr = 0x8254FA7C;
	sub_8246A2C0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8254fa90
	if (!ctx.cr0.eq) goto loc_8254FA90;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x8254facc
	goto loc_8254FACC;
loc_8254FA90:
	// lbz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 300);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// beq 0x8254faac
	if (ctx.cr0.eq) goto loc_8254FAAC;
	// lfs f12,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// b 0x8254fab0
	goto loc_8254FAB0;
loc_8254FAAC:
	// lfs f12,-232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
loc_8254FAB0:
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lfs f13,-28808(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28808);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
loc_8254FACC:
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

DEFINE_REX_FUNC(sub_82551EF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82551EF8;
	__savegprlr_25(ctx, base);
	// stfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f29.u64);
	// stfd f30,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f30.u64);
	// stfd f31,-72(r1)
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f31.u64);
	// stwu r1,-352(r1)
	ea = -352 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82553040
	if (!ctx.cr0.eq) goto loc_82553040;
	// lfs f0,292(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 292);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fadds f13,f0,f1
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f13,292(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 292, temp.u32);
	// addi r26,r11,-11120
	ctx.r26.s64 = ctx.r11.s64 + -11120;
	// lfs f0,9560(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 9560);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82551f40
	if (!ctx.cr6.gt) goto loc_82551F40;
	// bl 0x825535d0
	ctx.lr = 0x82551F40;
	sub_825535D0(ctx, base);
loc_82551F40:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r30,r31,68
	ctx.r30.s64 = ctx.r31.s64 + 68;
	// addi r11,r11,32480
	ctx.r11.s64 = ctx.r11.s64 + 32480;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8231e0d8
	ctx.lr = 0x82551F5C;
	sub_8231E0D8(ctx, base);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// lwz r11,360(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfs f13,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,188(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,52(r31)
	REX_STORE_U64(ctx.r31.u32 + 52, ctx.r10.u64);
	// blt cr6,0x82552c20
	if (ctx.cr6.lt) goto loc_82552C20;
	// beq cr6,0x82552954
	if (ctx.cr6.eq) goto loc_82552954;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x825526b8
	if (ctx.cr6.lt) goto loc_825526B8;
	// beq cr6,0x8255214c
	if (ctx.cr6.eq) goto loc_8255214C;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82552fa4
	if (!ctx.cr6.lt) goto loc_82552FA4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f11,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f11.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f0,3188(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3188);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f11,f0
	ctx.cr6.compare(ctx.f11.f64, ctx.f0.f64);
	// bge cr6,0x825520b0
	if (!ctx.cr6.lt) goto loc_825520B0;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
	// addi r30,r10,-30128
	ctx.r30.s64 = ctx.r10.s64 + -30128;
	// lfs f0,-2088(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2088);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82552030
	if (!ctx.cr6.lt) goto loc_82552030;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
	// b 0x8255203c
	goto loc_8255203C;
loc_82552030:
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x8255203c
	if (!ctx.cr6.gt) goto loc_8255203C;
	// fmr f0,f12
	ctx.f0.f64 = ctx.f12.f64;
loc_8255203C:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// fsubs f30,f12,f0
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8255205C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,20272(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 20272);
	ctx.f0.f64 = double(temp.f32);
	// li r11,255
	ctx.r11.s64 = 255;
	// fmuls f0,f30,f0
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lbz r10,151(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 151);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825520A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// b 0x82552108
	goto loc_82552108;
loc_825520B0:
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f1,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825520CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552100;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
loc_82552108:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r29,0(r30)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552124;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,100(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,4500(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4500);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fnmsubs f1,f0,f31,f1
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f31.f64, -ctx.f1.f64)));
	// bctrl 
	ctx.lr = 0x82552148;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82552fa4
	goto loc_82552FA4;
loc_8255214C:
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lfs f0,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// addi r28,r1,240
	ctx.r28.s64 = ctx.r1.s64 + 240;
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// addi r29,r1,192
	ctx.r29.s64 = ctx.r1.s64 + 192;
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r25,r1,192
	ctx.r25.s64 = ctx.r1.s64 + 192;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lis r27,-32225
	ctx.r27.s64 = -2111897600;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// vspltisw128 v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r27,r27,32256
	ctx.r27.s64 = ctx.r27.s64 + 32256;
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
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
	// stfs f31,188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f31,184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f31,180(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f31,176(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v59,v59,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v59.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v59,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,204(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,204(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v60,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v6,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// vmulfp128 v13,v63,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,-18424(r9)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18424);
	ctx.f0.f64 = double(temp.f32);
	// vmaddfp v0,v0,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vrsqrtefp v13,v0
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
	// stvx128 v0,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82552398
	if (!ctx.cr6.gt) goto loc_82552398;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stfs f13,204(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// stfs f13,200(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r11,r11,-29712
	ctx.r11.s64 = ctx.r11.s64 + -29712;
	// stfs f13,196(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stfs f13,192(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x82568120
	ctx.lr = 0x82552330;
	sub_82568120(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v61
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
loc_82552398:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// lfs f30,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// lfs f1,-232(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -232);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x82552404
	if (!ctx.cr6.lt) goto loc_82552404;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x825523c4
	if (!ctx.cr6.lt) goto loc_825523C4;
	// fmr f0,f30
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x825523d0
	goto loc_825523D0;
loc_825523C4:
	// fcmpu cr6,f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// ble cr6,0x825523d0
	if (!ctx.cr6.gt) goto loc_825523D0;
	// fmr f0,f1
	ctx.f0.f64 = ctx.f1.f64;
loc_825523D0:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// fsubs f12,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// lfs f13,1908(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmadds f1,f12,f13,f0
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825523F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// b 0x8255241c
	goto loc_8255241C;
loc_82552404:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8255241C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8255241C:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552438;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r10,100(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,4500(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4500);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmuls f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fnmsubs f1,f0,f13,f1
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f1.f64)));
	// bctrl 
	ctx.lr = 0x8255245C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,9492(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 9492);
	ctx.f13.f64 = double(temp.f32);
	// li r30,0
	ctx.r30.s64 = 0;
	// lfs f0,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8255247c
	if (!ctx.cr6.lt) goto loc_8255247C;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// b 0x825524c0
	goto loc_825524C0;
loc_8255247C:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x82552494
	if (ctx.cr6.lt) goto loc_82552494;
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
loc_82552494:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r10,r26,10408
	ctx.r10.s64 = ctx.r26.s64 + 10408;
	// lwz r9,308(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825524BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f30,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_825524C0:
	// lbz r11,349(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 349);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8255255c
	if (!ctx.cr0.eq) goto loc_8255255C;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// lfs f0,332(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 332);
	ctx.f0.f64 = double(temp.f32);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// blt cr6,0x82552550
	if (ctx.cr6.lt) goto loc_82552550;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82552550:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8255255c
	if (ctx.cr0.eq) goto loc_8255255C;
	// stb r27,349(r31)
	REX_STORE_U8(ctx.r31.u32 + 349, ctx.r27.u8);
loc_8255255C:
	// lbz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 348);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82552648
	if (ctx.cr0.eq) goto loc_82552648;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// lfs f13,52(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,56(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 56);
	ctx.f12.f64 = double(temp.f32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,-13032(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v60,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,92(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8255263c
	if (ctx.cr6.eq) goto loc_8255263C;
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lfs f13,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823af008
	ctx.lr = 0x8255263C;
	sub_823AF008(ctx, base);
loc_8255263C:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82552648
	if (!ctx.cr0.eq) goto loc_82552648;
	// stb r30,348(r31)
	REX_STORE_U8(ctx.r31.u32 + 348, ctx.r30.u8);
loc_82552648:
	// lfs f13,3188(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3188);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,356(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82552664
	if (!ctx.cr6.lt) goto loc_82552664;
loc_82552658:
	// fadds f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// b 0x82552fa4
	goto loc_82552FA4;
loc_82552664:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a4a90
	ctx.lr = 0x82552678;
	sub_825A4A90(ctx, base);
	// lwz r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8255268C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r3,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 30) & 0x3FFFFFFF;
	// li r10,3
	ctx.r10.s64 = 3;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// divwu r10,r11,r10
	ctx.r10.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// mulli r10,r10,3
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(3));
	// ld r5,2880(r9)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r9.u32 + 2880);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// addi r11,r11,35
	ctx.r11.s64 = ctx.r11.s64 + 35;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// b 0x82552948
	goto loc_82552948;
loc_825526B8:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r11,12468
	ctx.r30.s64 = ctx.r11.s64 + 12468;
	// lfs f29,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f29.f64 = double(temp.f32);
	// lfs f13,1908(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 1908);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8255270c
	if (!ctx.cr6.lt) goto loc_8255270C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,296(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f12,-232(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -232);
	ctx.f12.f64 = double(temp.f32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lfs f13,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f11,f0,f13
	ctx.f11.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// lfs f0,4500(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4496(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4496);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f11.f64));
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// fmadds f30,f12,f13,f0
	ctx.f30.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// b 0x82552888
	goto loc_82552888;
loc_8255270C:
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r10,3
	ctx.r10.s64 = 3;
	// stfs f29,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// li r3,7
	ctx.r3.s64 = 7;
	// stw r10,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r10.u32);
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lfs f0,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lfs f30,4500(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4500);
	ctx.f30.f64 = double(temp.f32);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x82240a58
	ctx.lr = 0x82552758;
	sub_82240A58(ctx, base);
	// ld r5,44(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f0,340(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// std r5,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r5.u64);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f0,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
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
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// vsubfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f0,232(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8231e0d8
	ctx.lr = 0x8255280C;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r10,r10,-29712
	ctx.r10.s64 = ctx.r10.s64 + -29712;
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f13,220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f13,212(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f13,208(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,320(r31)
	REX_STORE_U64(ctx.r31.u32 + 320, ctx.r11.u64);
loc_82552888:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r28,0(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,104(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x825528A4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,100(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fnmsubs f1,f0,f31,f1
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f31.f64, -ctx.f1.f64)));
	// bctrl 
	ctx.lr = 0x825528C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,9492(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 9492);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x825528dc
	if (!ctx.cr6.lt) goto loc_825528DC;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// b 0x82552924
	goto loc_82552924;
loc_825528DC:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x825528f8
	if (ctx.cr6.lt) goto loc_825528F8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
loc_825528F8:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r10,r26,10408
	ctx.r10.s64 = ctx.r26.s64 + 10408;
	// lwz r9,308(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552920;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stfs f29,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
loc_82552924:
	// lfs f13,3188(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 3188);
	ctx.f13.f64 = double(temp.f32);
loc_82552928:
	// lfs f0,356(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 356);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x82552658
	if (ctx.cr6.lt) goto loc_82552658;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,356(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 356, temp.u32);
	// li r4,35
	ctx.r4.s64 = 35;
	// ld r5,2880(r11)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r11.u32 + 2880);
loc_82552948:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825537a0
	ctx.lr = 0x82552950;
	sub_825537A0(ctx, base);
	// b 0x82552fa4
	goto loc_82552FA4;
loc_82552954:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// lfs f1,1908(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1908);
	ctx.f1.f64 = double(temp.f32);
	// lfs f30,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x82552af8
	if (!ctx.cr6.lt) goto loc_82552AF8;
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bne cr6,0x825529b4
	if (!ctx.cr6.eq) goto loc_825529B4;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// li r3,30
	ctx.r3.s64 = 30;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f0,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// stfd f13,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x82240a58
	ctx.lr = 0x825529B0;
	sub_82240A58(ctx, base);
	// lfs f1,1908(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1908);
	ctx.f1.f64 = double(temp.f32);
loc_825529B4:
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lfs f0,320(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f31,224(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// addi r5,r1,240
	ctx.r5.s64 = ctx.r1.s64 + 240;
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// addi r4,r1,240
	ctx.r4.s64 = ctx.r1.s64 + 240;
	// stfs f31,236(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r28,r1,240
	ctx.r28.s64 = ctx.r1.s64 + 240;
	// stfs f31,232(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r27,r1,240
	ctx.r27.s64 = ctx.r1.s64 + 240;
	// stfs f31,228(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// lfs f13,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,224
	ctx.r3.s64 = ctx.r1.s64 + 224;
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f13,240(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lis r25,-32226
	ctx.r25.s64 = -2111963136;
	// lfs f12,324(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 324);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f12,-30128(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -30128);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v60,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lfs f0,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v62,v62,v60
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f0,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmuls f1,f0,f1
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f1.f64));
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552AE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// b 0x82552b24
	goto loc_82552B24;
loc_82552AF8:
	// stfs f30,72(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stfs f30,0(r30)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552B18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r11,2
	ctx.r11.s64 = 2;
	// stfs f30,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stw r11,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r11.u32);
loc_82552B24:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552B40;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,100(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 100);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,4496(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4496);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fnmsubs f1,f0,f31,f1
	ctx.f1.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f31.f64, -ctx.f1.f64)));
	// bctrl 
	ctx.lr = 0x82552B64;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,9492(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 9492);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,304(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82552b80
	if (!ctx.cr6.lt) goto loc_82552B80;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// b 0x82552c18
	goto loc_82552C18;
loc_82552B80:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// blt cr6,0x82552b9c
	if (ctx.cr6.lt) goto loc_82552B9C;
	// stw r30,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r30.u32);
loc_82552B9C:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r10,r26,10408
	ctx.r10.s64 = ctx.r26.s64 + 10408;
	// lwz r9,308(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhzx r4,r9,r10
	ctx.r4.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,108(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 108);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552BC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// stfs f30,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// std r10,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r10.u64);
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82552c14
	if (ctx.cr6.eq) goto loc_82552C14;
	// lfs f0,148(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r5,148(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x82552C14;
	sub_823AEFA8(ctx, base);
loc_82552C14:
	// stb r3,350(r31)
	REX_STORE_U8(ctx.r31.u32 + 350, ctx.r3.u8);
loc_82552C18:
	// lfs f13,3188(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3188);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82552928
	goto loc_82552928;
loc_82552C20:
	// lfs f13,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 352);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82552c38
	if (!ctx.cr6.lt) goto loc_82552C38;
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// b 0x82552fa0
	goto loc_82552FA0;
loc_82552C38:
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// lfs f0,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// addi r6,r1,224
	ctx.r6.s64 = ctx.r1.s64 + 224;
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r29,r1,224
	ctx.r29.s64 = ctx.r1.s64 + 224;
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfs f0,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r28,r1,240
	ctx.r28.s64 = ctx.r1.s64 + 240;
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r25,r1,240
	ctx.r25.s64 = ctx.r1.s64 + 240;
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r27,r1,224
	ctx.r27.s64 = ctx.r1.s64 + 224;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r5,-32225
	ctx.r5.s64 = -2111897600;
	// lis r3,-32225
	ctx.r3.s64 = -2111897600;
	// addi r5,r5,32384
	ctx.r5.s64 = ctx.r5.s64 + 32384;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r3,32256
	ctx.r5.s64 = ctx.r3.s64 + 32256;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,100(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,240(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,252(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f13,248(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f13,244(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lfs f13,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,224(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// lvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,240(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x82568120
	ctx.lr = 0x82552D54;
	sub_82568120(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lvx128 v1,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// vslw128 v63,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// addi r8,r1,240
	ctx.r8.s64 = ctx.r1.s64 + 240;
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// lfs f0,4(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f0,228(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f0,224(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f0,232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v62,v61,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v60,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f0,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x82568120
	ctx.lr = 0x82552DEC;
	sub_82568120(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,116
	ctx.r4.s64 = 116;
	// stw r10,320(r31)
	REX_STORE_U32(ctx.r31.u32 + 320, ctx.r10.u32);
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r10,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r10.u32);
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x82552E14;
	sub_825E02A0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82552e90
	if (ctx.cr0.eq) goto loc_82552E90;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,124(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 124);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552E38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r10,r10,-30128
	ctx.r10.s64 = ctx.r10.s64 + -30128;
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// lfs f0,21484(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 21484);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f31,f1,f0
	ctx.f31.f64 = double(float(ctx.f1.f64 - ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552E5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82240940
	ctx.lr = 0x82552E6C;
	sub_82240940(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,5124
	ctx.r11.s64 = ctx.r11.s64 + 5124;
	// addi r10,r10,5184
	ctx.r10.s64 = ctx.r10.s64 + 5184;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r10,60(r30)
	REX_STORE_U32(ctx.r30.u32 + 60, ctx.r10.u32);
	// sth r11,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r11.u16);
	// b 0x82552e94
	goto loc_82552E94;
loc_82552E90:
	// li r30,0
	ctx.r30.s64 = 0;
loc_82552E94:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// addi r29,r11,12468
	ctx.r29.s64 = ctx.r11.s64 + 12468;
	// beq cr6,0x82552f98
	if (ctx.cr6.eq) goto loc_82552F98;
	// li r11,60
	ctx.r11.s64 = 60;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// sth r11,112(r30)
	REX_STORE_U16(ctx.r30.u32 + 112, ctx.r11.u16);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552ECC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f13,108(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552EF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552F0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stb r3,108(r30)
	REX_STORE_U8(ctx.r30.u32 + 108, ctx.r3.u8);
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// stw r11,104(r30)
	REX_STORE_U32(ctx.r30.u32 + 104, ctx.r11.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552F38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,36(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552F48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stb r27,86(r30)
	REX_STORE_U8(ctx.r30.u32 + 86, ctx.r27.u8);
	// addi r3,r30,60
	ctx.r3.s64 = ctx.r30.s64 + 60;
	// lfs f3,9492(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 9492);
	ctx.f3.f64 = double(temp.f32);
	// lfs f2,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,3188(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3188);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x82224038
	ctx.lr = 0x82552F60;
	sub_82224038(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82222ad8
	ctx.lr = 0x82552F6C;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82552f98
	if (!ctx.cr6.eq) goto loc_82552F98;
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
	ctx.lr = 0x82552F98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82552F98:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stw r27,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r27.u32);
loc_82552FA0:
	// stfs f0,296(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
loc_82552FA4:
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x82553040
	if (ctx.cr6.eq) goto loc_82553040;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82552FBC;
	sub_82222D88(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82553038
	if (ctx.cr0.eq) goto loc_82553038;
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82552FE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,120(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f0,124(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82553008;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,104(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 104);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82553024;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82553034;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82553040
	goto loc_82553040;
loc_82553038:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,328(r31)
	REX_STORE_U32(ctx.r31.u32 + 328, ctx.r11.u32);
loc_82553040:
	// addi r1,r1,352
	ctx.r1.s64 = ctx.r1.s64 + 352;
	// lfd f29,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f30,-80(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// lfd f31,-72(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F73E0) {
	REX_FUNC_PROLOGUE();
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// stw r5,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r5.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F75B8) {
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
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825f7680
	ctx.lr = 0x825F75E0;
	sub_825F7680(ctx, base);
	// lwz r10,384(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bge cr6,0x825f7660
	if (!ctx.cr6.lt) goto loc_825F7660;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825f7660
	if (ctx.cr6.lt) goto loc_825F7660;
	// ble cr6,0x825f762c
	if (!ctx.cr6.gt) goto loc_825F762C;
	// mulli r11,r10,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(12));
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
loc_825F7608:
	// lwz r8,-12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -12);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r8,-8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// lwz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// addi r11,r11,-12
	ctx.r11.s64 = ctx.r11.s64 + -12;
	// bne 0x825f7608
	if (!ctx.cr0.eq) goto loc_825F7608;
loc_825F762C:
	// mulli r11,r9,12
	ctx.r11.s64 = static_cast<int64_t>(ctx.r9.u64 * static_cast<uint64_t>(12));
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,4(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r8,8(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// add r11,r11,r31
	ctx.r11.u64 = ctx.r11.u64 + ctx.r31.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r8,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r8.u32);
	// lwz r11,384(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 384);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,384(r31)
	REX_STORE_U32(ctx.r31.u32 + 384, ctx.r11.u32);
	// b 0x825f7664
	goto loc_825F7664;
loc_825F7660:
	// li r3,0
	ctx.r3.s64 = 0;
loc_825F7664:
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

DEFINE_REX_FUNC(sub_825FB1B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r5,r3,4
	ctx.r5.s64 = ctx.r3.s64 + 4;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r11,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r11.u32);
	// lhz r11,8(r4)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r4.u32 + 8);
	// sth r11,8(r3)
	REX_STORE_U16(ctx.r3.u32 + 8, ctx.r11.u16);
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r8,12(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r8.u32);
	// beq 0x825fb228
	if (ctx.cr0.eq) goto loc_825FB228;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// subf r8,r3,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r3.u64;
	// li r6,16
	ctx.r6.s64 = 16;
loc_825FB1FC:
	// add r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lvlx128 v63,r8,r11
	temp.u32 = ctx.r8.u32 + ctx.r11.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskL[(temp.u32 & 0xF) * 16])));
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lvrx128 v62,r6,r7
	temp.u32 = ctx.r6.u32 + ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, temp.u32 & 0xF ? simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(temp.u32 & ~0xF)), simde_mm_load_si128((simde__m128i*)&VectorMaskR[(temp.u32 & 0xF) * 16])) : simde_mm_setzero_si128());
	// vor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stvlx128 v63,r0,r11
	ea = ctx.r11.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvrx128 v63,r11,r6
	ea = ctx.r11.u32 + ctx.r6.u32;
	for (size_t i = 0; i < (ea & 0xF); i++)
		REX_STORE_U8(ea - i - 1, ctx.v63.u8[i]);
	// lhz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r9.u32 + 0);
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x825fb1fc
	if (ctx.cr6.lt) goto loc_825FB1FC;
loc_825FB228:
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r10,r4,144
	ctx.r10.s64 = ctx.r4.s64 + 144;
	// addi r11,r3,148
	ctx.r11.s64 = ctx.r3.s64 + 148;
	// subf r7,r3,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r3.u64;
	// li r9,8
	ctx.r9.s64 = 8;
loc_825FB23C:
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// slw r6,r6,r8
	ctx.r6.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r6.u32 << (ctx.r8.u8 & 0x3F));
	// and. r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 & ctx.r4.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq 0x825fb27c
	if (ctx.cr0.eq) goto loc_825FB27C;
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// add r4,r11,r7
	ctx.r4.u64 = ctx.r11.u64 + ctx.r7.u64;
	// stw r6,-4(r11)
	REX_STORE_U32(ctx.r11.u32 + -4, ctx.r6.u32);
	// lwzx r6,r11,r7
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// stw r6,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r6.u32);
	// lwz r6,4(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// stw r6,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r6.u32);
	// lwz r6,8(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// stw r6,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// lwz r6,12(r4)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
loc_825FB27C:
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// addi r10,r10,20
	ctx.r10.s64 = ctx.r10.s64 + 20;
	// addi r11,r11,20
	ctx.r11.s64 = ctx.r11.s64 + 20;
	// bne 0x825fb23c
	if (!ctx.cr0.eq) goto loc_825FB23C;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82604A30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82604A38;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r26,0
	ctx.r26.s64 = 0;
	// stw r4,96(r3)
	REX_STORE_U32(ctx.r3.u32 + 96, ctx.r4.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r26,100(r3)
	REX_STORE_U32(ctx.r3.u32 + 100, ctx.r26.u32);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r26,104(r3)
	REX_STORE_U32(ctx.r3.u32 + 104, ctx.r26.u32);
	// stw r26,108(r3)
	REX_STORE_U32(ctx.r3.u32 + 108, ctx.r26.u32);
	// stw r26,112(r3)
	REX_STORE_U32(ctx.r3.u32 + 112, ctx.r26.u32);
	// stw r26,120(r3)
	REX_STORE_U32(ctx.r3.u32 + 120, ctx.r26.u32);
	// stw r26,124(r3)
	REX_STORE_U32(ctx.r3.u32 + 124, ctx.r26.u32);
	// stw r26,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r26.u32);
	// stw r26,132(r3)
	REX_STORE_U32(ctx.r3.u32 + 132, ctx.r26.u32);
	// stw r26,136(r3)
	REX_STORE_U32(ctx.r3.u32 + 136, ctx.r26.u32);
	// stb r26,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r26.u8);
	// stw r26,140(r3)
	REX_STORE_U32(ctx.r3.u32 + 140, ctx.r26.u32);
	// stw r26,144(r3)
	REX_STORE_U32(ctx.r3.u32 + 144, ctx.r26.u32);
	// stw r26,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r26.u32);
	// lwz r10,28(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 28);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82604a90
	if (ctx.cr0.eq) goto loc_82604A90;
	// li r11,15
	ctx.r11.s64 = 15;
loc_82604A90:
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// clrlwi. r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r26,148(r31)
	REX_STORE_U32(ctx.r31.u32 + 148, ctx.r26.u32);
	// mr r24,r26
	ctx.r24.u64 = ctx.r26.u64;
	// stw r26,108(r31)
	REX_STORE_U32(ctx.r31.u32 + 108, ctx.r26.u32);
	// mr r30,r26
	ctx.r30.u64 = ctx.r26.u64;
	// stw r26,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r26.u32);
	// mr r22,r26
	ctx.r22.u64 = ctx.r26.u64;
	// stw r26,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r26.u32);
	// stw r26,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r26.u32);
	// stw r26,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r26.u32);
	// stw r26,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r26.u32);
	// lwz r23,36(r4)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// beq 0x82604acc
	if (ctx.cr0.eq) goto loc_82604ACC;
	// lwz r24,48(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 48);
loc_82604ACC:
	// rlwinm. r10,r11,0,30,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82604ad8
	if (ctx.cr0.eq) goto loc_82604AD8;
	// lwz r30,32(r4)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r4.u32 + 32);
loc_82604AD8:
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82604ae4
	if (ctx.cr0.eq) goto loc_82604AE4;
	// lwz r22,40(r4)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r4.u32 + 40);
loc_82604AE4:
	// mulli r11,r22,5
	ctx.r11.s64 = static_cast<int64_t>(ctx.r22.u64 * static_cast<uint64_t>(5));
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mulli r11,r24,200
	ctx.r11.s64 = static_cast<int64_t>(ctx.r24.u64 * static_cast<uint64_t>(200));
	// rlwinm r10,r10,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 6) & 0xFFFFFFC0;
	// mulli r25,r23,36
	ctx.r25.s64 = static_cast<int64_t>(ctx.r23.u64 * static_cast<uint64_t>(36));
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add. r3,r11,r25
	ctx.r3.u64 = ctx.r11.u64 + ctx.r25.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82604b10
	if (ctx.cr0.eq) goto loc_82604B10;
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x825f8d38
	ctx.lr = 0x82604B0C;
	sub_825F8D38(ctx, base);
	// stw r3,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r3.u32);
loc_82604B10:
	// lwz r11,100(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82604b68
	if (ctx.cr6.eq) goto loc_82604B68;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
	// stw r11,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r11.u32);
	// lwz r30,32(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r28,68(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// beq cr6,0x82604b5c
	if (ctx.cr6.eq) goto loc_82604B5C;
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
loc_82604B3C:
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82604B4C;
	sub_8273A030(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r29,r29,64
	ctx.r29.s64 = ctx.r29.s64 + 64;
	// addi r28,r28,64
	ctx.r28.s64 = ctx.r28.s64 + 64;
	// bne 0x82604b3c
	if (!ctx.cr0.eq) goto loc_82604B3C;
loc_82604B5C:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// rlwinm r10,r30,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 6) & 0xFFFFFFC0;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82604B68:
	// cmplwi cr6,r23,0
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 0, ctx.xer);
	// beq cr6,0x82604b78
	if (ctx.cr6.eq) goto loc_82604B78;
	// stw r11,104(r31)
	REX_STORE_U32(ctx.r31.u32 + 104, ctx.r11.u32);
	// add r11,r25,r11
	ctx.r11.u64 = ctx.r25.u64 + ctx.r11.u64;
loc_82604B78:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82604bf4
	if (ctx.cr6.eq) goto loc_82604BF4;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// lwz r29,48(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// lwz r28,100(r10)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r10.u32 + 100);
	// beq cr6,0x82604be8
	if (ctx.cr6.eq) goto loc_82604BE8;
	// mr r27,r29
	ctx.r27.u64 = ctx.r29.u64;
loc_82604BA0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82604bcc
	if (ctx.cr6.eq) goto loc_82604BCC;
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r30,4
	ctx.r11.s64 = ctx.r30.s64 + 4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82604BB4:
	// stw r26,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r26.u32);
	// stw r26,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r26.u32);
	// stwu r26,12(r11)
	ea = 12 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r26.u32);
	ctx.r11.u32 = ea;
	// bdnz 0x82604bb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82604BB4;
	// stw r26,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r26.u32);
	// sth r26,4(r30)
	REX_STORE_U16(ctx.r30.u32 + 4, ctx.r26.u16);
loc_82604BCC:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82611830
	ctx.lr = 0x82604BD8;
	sub_82611830(ctx, base);
	// addic. r27,r27,-1
	ctx.xer.ca = ctx.r27.u32 > 0;
	ctx.r27.s64 = ctx.r27.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// addi r30,r30,200
	ctx.r30.s64 = ctx.r30.s64 + 200;
	// addi r28,r28,200
	ctx.r28.s64 = ctx.r28.s64 + 200;
	// bne 0x82604ba0
	if (!ctx.cr0.eq) goto loc_82604BA0;
loc_82604BE8:
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mulli r11,r29,200
	ctx.r11.s64 = static_cast<int64_t>(ctx.r29.u64 * static_cast<uint64_t>(200));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_82604BF4:
	// cmplwi cr6,r22,0
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, 0, ctx.xer);
	// beq cr6,0x82604c74
	if (ctx.cr6.eq) goto loc_82604C74;
	// stw r11,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r11.u32);
	// mr r30,r11
	ctx.r30.u64 = ctx.r11.u64;
	// lwz r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r27,40(r10)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r10.u32 + 40);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// lwz r29,92(r10)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r10.u32 + 92);
	// beq cr6,0x82604c68
	if (ctx.cr6.eq) goto loc_82604C68;
	// addi r3,r11,16
	ctx.r3.s64 = ctx.r11.s64 + 16;
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
loc_82604C20:
	// li r10,8
	ctx.r10.s64 = 8;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82604C30:
	// lhzx r10,r9,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r11.u32);
	// sth r10,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r10.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x82604c30
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82604C30;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82604c4c
	if (ctx.cr6.eq) goto loc_82604C4C;
	// bl 0x825fb150
	ctx.lr = 0x82604C4C;
	sub_825FB150(ctx, base);
loc_82604C4C:
	// addi r4,r29,16
	ctx.r4.s64 = ctx.r29.s64 + 16;
	// bl 0x825fb1b8
	ctx.lr = 0x82604C54;
	sub_825FB1B8(ctx, base);
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,320
	ctx.r30.s64 = ctx.r30.s64 + 320;
	// addi r3,r3,320
	ctx.r3.s64 = ctx.r3.s64 + 320;
	// addi r29,r29,320
	ctx.r29.s64 = ctx.r29.s64 + 320;
	// bne 0x82604c20
	if (!ctx.cr0.eq) goto loc_82604C20;
loc_82604C68:
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// mulli r11,r27,320
	ctx.r11.s64 = static_cast<int64_t>(ctx.r27.u64 * static_cast<uint64_t>(320));
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_82604C74:
	// lwz r10,148(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 148);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x82604c84
	if (!ctx.cr6.gt) goto loc_82604C84;
	// stw r11,144(r31)
	REX_STORE_U32(ctx.r31.u32 + 144, ctx.r11.u32);
loc_82604C84:
	// lwz r10,112(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82604ca8
	if (!ctx.cr6.eq) goto loc_82604CA8;
	// lwz r10,32(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82604ca8
	if (ctx.cr6.eq) goto loc_82604CA8;
	// lwz r10,68(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 68);
	// stw r10,112(r31)
	REX_STORE_U32(ctx.r31.u32 + 112, ctx.r10.u32);
loc_82604CA8:
	// lwz r10,120(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82604cc8
	if (!ctx.cr6.eq) goto loc_82604CC8;
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82604cc8
	if (ctx.cr6.eq) goto loc_82604CC8;
	// lwz r10,92(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// stw r10,120(r31)
	REX_STORE_U32(ctx.r31.u32 + 120, ctx.r10.u32);
loc_82604CC8:
	// lwz r10,124(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82604ce8
	if (!ctx.cr6.eq) goto loc_82604CE8;
	// lwz r10,48(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82604ce8
	if (ctx.cr6.eq) goto loc_82604CE8;
	// lwz r10,100(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
loc_82604CE8:
	// lwz r8,36(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// lwz r10,104(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// ble cr6,0x82604d70
	if (!ctx.cr6.gt) goto loc_82604D70;
	// addi r10,r10,-12
	ctx.r10.s64 = ctx.r10.s64 + -12;
loc_82604D04:
	// stw r11,28(r10)
	REX_STORE_U32(ctx.r10.u32 + 28, ctx.r11.u32);
	// li r8,320
	ctx.r8.s64 = 320;
	// lwz r7,120(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// li r5,200
	ctx.r5.s64 = 200;
	// lwz r4,44(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r6,96(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r6,92(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 92);
	// subf r6,r6,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r6.u64;
	// divwu r8,r6,r8
	ctx.r8.u64 = uint32_t(ctx.r8.u32 ? ctx.r6.u32 / ctx.r8.u32 : 0);
	// mulli r8,r8,320
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(320));
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stw r8,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r8.u32);
	// lwz r7,124(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lwz r8,96(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r6,40(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// addi r11,r11,52
	ctx.r11.s64 = ctx.r11.s64 + 52;
	// lwz r8,100(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 100);
	// subf r8,r8,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r8.u64;
	// divwu r8,r8,r5
	ctx.r8.u64 = uint32_t(ctx.r5.u32 ? ctx.r8.u32 / ctx.r5.u32 : 0);
	// mulli r8,r8,200
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(200));
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// stwu r8,36(r10)
	ea = 36 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// lwz r8,96(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r8,36(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 36);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x82604d04
	if (ctx.cr6.lt) goto loc_82604D04;
loc_82604D70:
	// lwz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82604d84
	if (ctx.cr0.eq) goto loc_82604D84;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82604e70
	ctx.lr = 0x82604D84;
	sub_82604E70(ctx, base);
loc_82604D84:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// li r5,64
	ctx.r5.s64 = 64;
	// addi r4,r10,10984
	ctx.r4.s64 = ctx.r10.s64 + 10984;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,5500(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 5500);
	// stw r11,140(r31)
	REX_STORE_U32(ctx.r31.u32 + 140, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x82604DA4;
	sub_8273A030(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r6,-32240
	ctx.r6.s64 = -2112880640;
	// stw r26,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r26.u32);
	// addi r8,r11,10932
	ctx.r8.s64 = ctx.r11.s64 + 10932;
	// lwz r7,96(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r10,-1
	ctx.r10.s64 = -1;
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// addi r4,r6,12236
	ctx.r4.s64 = ctx.r6.s64 + 12236;
	// stw r10,136(r31)
	REX_STORE_U32(ctx.r31.u32 + 136, ctx.r10.u32);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// lfs f13,12236(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12236);
	ctx.f13.f64 = double(temp.f32);
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// lfs f0,232(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r6,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r6.u32);
	// lwz r6,4(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r6,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r6.u32);
	// lwz r6,8(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r6,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r6.u32);
	// lwz r6,12(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stfs f0,64(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 64, temp.u32);
	// stfs f13,68(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// stw r6,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r6.u32);
	// stfs f0,72(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// lwz r7,36(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// ble cr6,0x82604e60
	if (!ctx.cr6.gt) goto loc_82604E60;
loc_82604E10:
	// lwz r7,16(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// lwz r7,16(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 16);
	// rlwinm r7,r7,0,24,3
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFFF00000FF;
	// stw r7,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r7.u32);
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// lwz r7,4(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// lwz r7,12(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r7,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r7.u32);
	// stw r10,32(r11)
	REX_STORE_U32(ctx.r11.u32 + 32, ctx.r10.u32);
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// lwz r7,96(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// lwz r7,36(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 36);
	// cmplw cr6,r9,r7
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x82604e10
	if (ctx.cr6.lt) goto loc_82604E10;
loc_82604E60:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826257F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82625800;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r10,10612(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 10612);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r12,1
	ctx.r12.s64 = 1;
	// rlwimi r10,r11,0,30,31
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x3) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFFC);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// rldicr r12,r12,50,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 50) & 0xFFFFFFFFFFFFFFFF;
	// stw r10,10612(r3)
	REX_STORE_U32(ctx.r3.u32 + 10612, ctx.r10.u32);
	// addi r11,r9,26760
	ctx.r11.s64 = ctx.r9.s64 + 26760;
	// ld r9,24(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// or r9,r9,r12
	ctx.r9.u64 = ctx.r9.u64 | ctx.r12.u64;
	// mulli r10,r4,12
	ctx.r10.s64 = static_cast<int64_t>(ctx.r4.u64 * static_cast<uint64_t>(12));
	// std r9,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r9.u64);
	// lwzx r7,r10,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// stw r7,10632(r3)
	REX_STORE_U32(ctx.r3.u32 + 10632, ctx.r7.u32);
	// addi r8,r11,4
	ctx.r8.s64 = ctx.r11.s64 + 4;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// addi r11,r9,27176
	ctx.r11.s64 = ctx.r9.s64 + 27176;
	// lwzx r9,r10,r8
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// rlwinm r24,r4,3,0,28
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r9,10636(r3)
	REX_STORE_U32(ctx.r3.u32 + 10636, ctx.r9.u32);
	// addi r9,r11,4
	ctx.r9.s64 = ctx.r11.s64 + 4;
	// lis r8,24897
	ctx.r8.s64 = 1631649792;
	// lwzx r10,r10,r6
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r6.u32);
	// stw r10,10640(r3)
	REX_STORE_U32(ctx.r3.u32 + 10640, ctx.r10.u32);
	// li r12,127
	ctx.r12.s64 = 127;
	// lwzx r11,r24,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r11.u32);
	// ori r10,r8,8449
	ctx.r10.u64 = ctx.r8.u64 | 8449;
	// stw r11,10644(r3)
	REX_STORE_U32(ctx.r3.u32 + 10644, ctx.r11.u32);
	// rldicr r12,r12,39,24
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 39) & 0xFFFFFF8000000000;
	// lwzx r11,r24,r9
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r9.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r11,10648(r3)
	REX_STORE_U32(ctx.r3.u32 + 10648, ctx.r11.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r10,10652(r3)
	REX_STORE_U32(ctx.r3.u32 + 10652, ctx.r10.u32);
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// stw r10,10656(r3)
	REX_STORE_U32(ctx.r3.u32 + 10656, ctx.r10.u32);
	// li r26,0
	ctx.r26.s64 = 0;
	// ld r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 24);
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// ld r4,0(r3)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// cmpldi cr6,r4,0
	ctx.cr6.compare<uint64_t>(ctx.r4.u64, 0, ctx.xer);
	// ld r27,32(r3)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r3.u32 + 32);
	// ld r30,16(r3)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r3.u32 + 16);
	// ld r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r3.u32 + 8);
	// beq cr6,0x826258d8
	if (ctx.cr6.eq) goto loc_826258D8;
	// addi r6,r3,1920
	ctx.r6.s64 = ctx.r3.s64 + 1920;
	// li r5,16384
	ctx.r5.s64 = 16384;
	// bl 0x8262ce88
	ctx.lr = 0x826258D4;
	sub_8262CE88(ctx, base);
	// std r26,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r26.u64);
loc_826258D8:
	// cmpldi cr6,r29,0
	ctx.cr6.compare<uint64_t>(ctx.r29.u64, 0, ctx.xer);
	// beq cr6,0x826258f8
	if (ctx.cr6.eq) goto loc_826258F8;
	// addi r6,r31,6016
	ctx.r6.s64 = ctx.r31.s64 + 6016;
	// li r5,17408
	ctx.r5.s64 = 17408;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262ce88
	ctx.lr = 0x826258F4;
	sub_8262CE88(ctx, base);
	// std r26,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r26.u64);
loc_826258F8:
	// cmpldi cr6,r30,0
	ctx.cr6.compare<uint64_t>(ctx.r30.u64, 0, ctx.xer);
	// beq cr6,0x826259d8
	if (ctx.cr6.eq) goto loc_826259D8;
	// rlwinm r11,r30,0,11,14
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x1E0000;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x8262591c
	if (ctx.cr6.eq) goto loc_8262591C;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262ded8
	ctx.lr = 0x82625918;
	sub_8262DED8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8262591C:
	// ld r11,40(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// and r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 & ctx.r30.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625940
	if (ctx.cr6.eq) goto loc_82625940;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r5,10560(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 10560);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262c758
	ctx.lr = 0x8262593C;
	sub_8262C758(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82625940:
	// clrldi r11,r30,52
	ctx.r11.u64 = ctx.r30.u64 & 0xFFF;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625960
	if (ctx.cr6.eq) goto loc_82625960;
	// addi r6,r31,10548
	ctx.r6.s64 = ctx.r31.s64 + 10548;
	// li r5,8704
	ctx.r5.s64 = 8704;
	// rldicr r4,r30,52,11
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u64, 52) & 0xFFF0000000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x82625960;
	sub_8262CAF0(ctx, base);
loc_82625960:
	// rlwinm r11,r30,0,15,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 0) & 0x1F000;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625980
	if (ctx.cr6.eq) goto loc_82625980;
	// addi r6,r31,10528
	ctx.r6.s64 = ctx.r31.s64 + 10528;
	// li r5,8576
	ctx.r5.s64 = 8576;
	// rldicr r4,r30,47,4
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u64, 47) & 0xF800000000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x82625980;
	sub_8262CAF0(ctx, base);
loc_82625980:
	// lis r12,0
	ctx.r12.s64 = 0;
	// ori r12,r12,65535
	ctx.r12.u64 = ctx.r12.u64 | 65535;
	// rldicr r12,r12,42,21
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 42) & 0xFFFFFC0000000000;
	// and r11,r30,r12
	ctx.r11.u64 = ctx.r30.u64 & ctx.r12.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x826259ac
	if (ctx.cr6.eq) goto loc_826259AC;
	// addi r6,r31,10368
	ctx.r6.s64 = ctx.r31.s64 + 10368;
	// li r5,8192
	ctx.r5.s64 = 8192;
	// rldicr r4,r30,6,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u64, 6) & 0xFFFF000000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x826259AC;
	sub_8262CAF0(ctx, base);
loc_826259AC:
	// lis r12,-32
	ctx.r12.s64 = -2097152;
	// clrldi r12,r12,22
	ctx.r12.u64 = ctx.r12.u64 & 0x3FFFFFFFFFF;
	// and r11,r30,r12
	ctx.r11.u64 = ctx.r30.u64 & ctx.r12.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x826259d4
	if (ctx.cr6.eq) goto loc_826259D4;
	// addi r6,r31,10444
	ctx.r6.s64 = ctx.r31.s64 + 10444;
	// li r5,8448
	ctx.r5.s64 = 8448;
	// rldicr r4,r30,22,20
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r30.u64, 22) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x826259D4;
	sub_8262CAF0(ctx, base);
loc_826259D4:
	// std r26,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r26.u64);
loc_826259D8:
	// cmpldi cr6,r28,0
	ctx.cr6.compare<uint64_t>(ctx.r28.u64, 0, ctx.xer);
	// beq cr6,0x82625a28
	if (ctx.cr6.eq) goto loc_82625A28;
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x826259f8
	if (ctx.cr6.eq) goto loc_826259F8;
	// rldicr r4,r28,32,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r28.u64, 32) & 0xFFFFFFFF00000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262cd30
	ctx.lr = 0x826259F8;
	sub_8262CD30(ctx, base);
loc_826259F8:
	// lis r12,31
	ctx.r12.s64 = 2031616;
	// ori r12,r12,65535
	ctx.r12.u64 = ctx.r12.u64 | 65535;
	// rldicr r12,r12,34,29
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 34) & 0xFFFFFFFC00000000;
	// and r11,r28,r12
	ctx.r11.u64 = ctx.r28.u64 & ctx.r12.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625a24
	if (ctx.cr6.eq) goto loc_82625A24;
	// addi r6,r31,10596
	ctx.r6.s64 = ctx.r31.s64 + 10596;
	// li r5,8832
	ctx.r5.s64 = 8832;
	// rldicr r4,r28,9,20
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r28.u64, 9) & 0xFFFFF80000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x82625A24;
	sub_8262CAF0(ctx, base);
loc_82625A24:
	// std r26,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r26.u64);
loc_82625A28:
	// cmpldi cr6,r27,0
	ctx.cr6.compare<uint64_t>(ctx.r27.u64, 0, ctx.xer);
	// beq cr6,0x82625ac4
	if (ctx.cr6.eq) goto loc_82625AC4;
	// clrldi r11,r27,26
	ctx.r11.u64 = ctx.r27.u64 & 0x3FFFFFFFFF;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625a50
	if (ctx.cr6.eq) goto loc_82625A50;
	// addi r6,r31,10680
	ctx.r6.s64 = ctx.r31.s64 + 10680;
	// li r5,8960
	ctx.r5.s64 = 8960;
	// rldicr r4,r27,26,37
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r27.u64, 26) & 0xFFFFFFFFFC000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x82625A50;
	sub_8262CAF0(ctx, base);
loc_82625A50:
	// li r12,255
	ctx.r12.s64 = 255;
	// rldicr r12,r12,38,25
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 38) & 0xFFFFFFC000000000;
	// and r11,r27,r12
	ctx.r11.u64 = ctx.r27.u64 & ctx.r12.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625a78
	if (ctx.cr6.eq) goto loc_82625A78;
	// addi r6,r31,10832
	ctx.r6.s64 = ctx.r31.s64 + 10832;
	// li r5,9088
	ctx.r5.s64 = 9088;
	// rldicr r4,r27,18,7
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r27.u64, 18) & 0xFF00000000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x82625A78;
	sub_8262CAF0(ctx, base);
loc_82625A78:
	// li r12,63
	ctx.r12.s64 = 63;
	// rldicr r12,r12,49,14
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 49) & 0xFFFE000000000000;
	// and r11,r27,r12
	ctx.r11.u64 = ctx.r27.u64 & ctx.r12.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625a98
	if (ctx.cr6.eq) goto loc_82625A98;
	// rldicr r4,r27,9,5
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r27.u64, 9) & 0xFC00000000000000;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262cbb0
	ctx.lr = 0x82625A98;
	sub_8262CBB0(ctx, base);
loc_82625A98:
	// li r12,1
	ctx.r12.s64 = 1;
	// rldicr r12,r12,56,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 56) & 0xFFFFFFFFFFFFFFFF;
	// and r11,r27,r12
	ctx.r11.u64 = ctx.r27.u64 & ctx.r12.u64;
	// cmpldi cr6,r11,0
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, 0, ctx.xer);
	// beq cr6,0x82625ac0
	if (ctx.cr6.eq) goto loc_82625AC0;
	// addi r6,r31,10112
	ctx.r6.s64 = ctx.r31.s64 + 10112;
	// li r5,18688
	ctx.r5.s64 = 18688;
	// lis r4,-256
	ctx.r4.s64 = -16777216;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262caf0
	ctx.lr = 0x82625AC0;
	sub_8262CAF0(ctx, base);
loc_82625AC0:
	// std r26,32(r31)
	REX_STORE_U64(ctx.r31.u32 + 32, ctx.r26.u64);
loc_82625AC4:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r26,r31,12298
	ctx.r26.s64 = ctx.r31.s64 + 12298;
	// addi r27,r11,17760
	ctx.r27.s64 = ctx.r11.s64 + 17760;
loc_82625AD0:
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82625ae8
	if (!ctx.cr6.gt) goto loc_82625AE8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826274c0
	ctx.lr = 0x82625AE8;
	sub_826274C0(ctx, base);
loc_82625AE8:
	// li r11,8450
	ctx.r11.s64 = 8450;
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// stwu r11,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r3.u32 = ea;
	// cmplwi cr6,r23,65535
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, 65535, ctx.xer);
	// stwu r22,4(r3)
	ea = 4 + ctx.r3.u32;
	REX_STORE_U32(ea, ctx.r22.u32);
	ctx.r3.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// ble cr6,0x82625b20
	if (!ctx.cr6.gt) goto loc_82625B20;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwzx r10,r24,r27
	ctx.r10.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r27.u32);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r11,r10
	ctx.r11.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// rlwinm r11,r11,0,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// mullw r29,r11,r10
	ctx.r29.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
loc_82625B20:
	// lbz r11,12363(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 12363);
	// lbz r10,10940(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 10940);
	// addic r9,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r9.s64 = ctx.r11.s64 + -1;
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// subfe r9,r9,r11
	temp.u8 = (~ctx.r9.u32 + ctx.r11.u32 < ~ctx.r9.u32) | (~ctx.r9.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r9.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lbzx r11,r26,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + ctx.r11.u32);
	// rlwimi r11,r9,8,23,23
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0x100) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFEFF);
	// clrlwi r28,r11,23
	ctx.r28.u64 = ctx.r11.u32 & 0x1FF;
	// rlwinm r28,r28,0,26,23
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 0) & 0xFFFFFFFFFFFFFF3F;
	// bne 0x82625b78
	if (!ctx.cr0.eq) goto loc_82625B78;
	// lis r11,-16383
	ctx.r11.s64 = -1073676288;
	// rlwinm r10,r29,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 16) & 0xFFFF0000;
	// ori r11,r11,8705
	ctx.r11.u64 = ctx.r11.u64 | 8705;
	// clrlwi r9,r25,26
	ctx.r9.u64 = ctx.r25.u32 & 0x3F;
	// stwu r11,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r30.u32 = ea;
	// or r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 | ctx.r9.u64;
	// ori r11,r11,384
	ctx.r11.u64 = ctx.r11.u64 | 384;
	// stwu r28,4(r30)
	ea = 4 + ctx.r30.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r30.u32 = ea;
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stwu r11,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r10.u32 = ea;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x82625c44
	goto loc_82625C44;
loc_82625B78:
	// lwz r11,13436(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13436);
	// addi r3,r31,13424
	ctx.r3.s64 = ctx.r31.s64 + 13424;
	// lwz r10,13440(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 13440);
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// ble cr6,0x82625b98
	if (!ctx.cr6.gt) goto loc_82625B98;
	// bl 0x82626310
	ctx.lr = 0x82625B94;
	sub_82626310(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82625B98:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// stw r30,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r30.u32);
	// lis r9,-16384
	ctx.r9.s64 = -1073741824;
	// addi r8,r11,16
	ctx.r8.s64 = ctx.r11.s64 + 16;
	// ori r9,r9,24576
	ctx.r9.u64 = ctx.r9.u64 | 24576;
	// stw r8,13436(r31)
	REX_STORE_U32(ctx.r31.u32 + 13436, ctx.r8.u32);
	// li r8,-1
	ctx.r8.s64 = -1;
	// stwu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r10.u32 = ea;
	// clrlwi r6,r25,26
	ctx.r6.u64 = ctx.r25.u32 & 0x3F;
	// rlwinm r7,r29,16,0,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 16) & 0xFFFF0000;
	// lis r9,-16383
	ctx.r9.s64 = -1073676288;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// ori r9,r9,8705
	ctx.r9.u64 = ctx.r9.u64 | 8705;
	// stwu r8,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r10.u32 = ea;
	// ori r7,r7,384
	ctx.r7.u64 = ctx.r7.u64 | 384;
	// lis r5,-16384
	ctx.r5.s64 = -1073741824;
	// mr r6,r10
	ctx.r6.u64 = ctx.r10.u64;
	// ori r8,r5,24576
	ctx.r8.u64 = ctx.r5.u64 | 24576;
	// lis r5,-32768
	ctx.r5.s64 = -2147483648;
	// lis r10,-16383
	ctx.r10.s64 = -1073676288;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// ori r4,r10,23041
	ctx.r4.u64 = ctx.r10.u64 | 23041;
	// rlwinm r10,r11,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xFFF;
	// rlwinm r11,r11,0,3,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1FFFFFFE;
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// li r9,26
	ctx.r9.s64 = 26;
	// stwu r28,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r28.u32);
	ctx.r6.u32 = ea;
	// rlwinm r10,r10,0,19,19
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// lis r3,-16384
	ctx.r3.s64 = -1073741824;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ori r10,r3,17921
	ctx.r10.u64 = ctx.r3.u64 | 17921;
	// ori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 | 1;
	// stwu r7,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r7.u32);
	ctx.r6.u32 = ea;
	// li r3,25
	ctx.r3.s64 = 25;
	// stwu r8,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r6.u32 = ea;
	// stwu r5,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r5.u32);
	ctx.r6.u32 = ea;
	// stwu r4,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r4.u32);
	ctx.r6.u32 = ea;
	// stwu r9,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r9.u32);
	ctx.r6.u32 = ea;
	// stwu r11,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r11.u32);
	ctx.r6.u32 = ea;
	// stwu r10,4(r6)
	ea = 4 + ctx.r6.u32;
	REX_STORE_U32(ea, ctx.r10.u32);
	ctx.r6.u32 = ea;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// stwu r3,4(r11)
	ea = 4 + ctx.r11.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r11.u32 = ea;
loc_82625C44:
	// subf. r10,r29,r23
	ctx.r10.u64 = ctx.r23.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r11.u32);
	// beq 0x82625c68
	if (ctx.cr0.eq) goto loc_82625C68;
	// addi r11,r27,4
	ctx.r11.s64 = ctx.r27.s64 + 4;
	// lwzx r11,r24,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r11.u32);
	// subf r9,r11,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r11.u64;
	// add r23,r11,r10
	ctx.r23.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r22,r9,r22
	ctx.r22.u64 = ctx.r9.u64 + ctx.r22.u64;
	// b 0x82625ad0
	goto loc_82625AD0;
loc_82625C68:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82646AB0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82646AB8;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,52(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646ADC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82646bf4
	if (ctx.cr6.eq) goto loc_82646BF4;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82646b00
	if (!ctx.cr6.eq) goto loc_82646B00;
	// lis r29,4919
	ctx.r29.s64 = 322371584;
	// ori r29,r29,61441
	ctx.r29.u64 = ctx.r29.u64 | 61441;
	// b 0x82646b04
	goto loc_82646B04;
loc_82646B00:
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_82646B04:
	// lwz r3,144(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 144);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646B1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x82646bf4
	if (ctx.cr0.lt) goto loc_82646BF4;
	// lwz r3,136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82646b48
	if (ctx.cr6.eq) goto loc_82646B48;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646B44;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82646B48:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82646bf4
	if (ctx.cr6.lt) goto loc_82646BF4;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82646b6c
	if (ctx.cr6.eq) goto loc_82646B6C;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// bl 0x82653278
	ctx.lr = 0x82646B68;
	sub_82653278(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82646B6C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82646bf4
	if (ctx.cr6.lt) goto loc_82646BF4;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// bne cr6,0x82646b9c
	if (!ctx.cr6.eq) goto loc_82646B9C;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,176(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646B98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82646B9C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82646bf4
	if (ctx.cr6.lt) goto loc_82646BF4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646BBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82646bdc
	if (ctx.cr6.eq) goto loc_82646BDC;
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// lwz r9,44(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r10,40(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r10,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
loc_82646BDC:
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,92(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 92);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646BF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82646BF4:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// addi r3,r11,44
	ctx.r3.s64 = ctx.r11.s64 + 44;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82646C0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264DFB0) {
	REX_FUNC_PROLOGUE();
	// addi r3,r3,-16
	ctx.r3.s64 = ctx.r3.s64 + -16;
	// b 0x8264dfa8
	sub_8264DFA8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264E5F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8264E5F8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,-4
	ctx.r30.s64 = ctx.r3.s64 + -4;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r4,r5
	ctx.r4.u64 = ctx.r5.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// bl 0x8264e1e0
	ctx.lr = 0x8264E61C;
	sub_8264E1E0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8264e688
	if (ctx.cr0.lt) goto loc_8264E688;
	// lwz r11,68(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 68);
	// lwz r10,128(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x8264e654
	if (ctx.cr6.eq) goto loc_8264E654;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
	// lwz r5,16(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r11,2
	ctx.r11.s64 = 2;
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 & ctx.r11.u64;
	// bl 0x826607c8
	ctx.lr = 0x8264E654;
	sub_826607C8(ctx, base);
loc_8264E654:
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8264e688
	if (ctx.cr6.lt) goto loc_8264E688;
	// lwz r11,68(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 68);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,128(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 128);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8264e684
	if (ctx.cr6.eq) goto loc_8264E684;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// bl 0x8264da00
	ctx.lr = 0x8264E680;
	sub_8264DA00(ctx, base);
	// b 0x8264e688
	goto loc_8264E688;
loc_8264E684:
	// bl 0x8264ce70
	ctx.lr = 0x8264E688;
	sub_8264CE70(ctx, base);
loc_8264E688:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826535F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x826535F8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
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
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lwz r11,44(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82653620;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826533e8
	ctx.lr = 0x8265362C;
	sub_826533E8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// bl 0x82653180
	ctx.lr = 0x82653638;
	sub_82653180(ctx, base);
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
	ctx.lr = 0x82653650;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82656C90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739eec
	ctx.lr = 0x82656C98;
	__savegprlr_17(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r19,r3
	ctx.r19.u64 = ctx.r3.u64;
	// lwz r28,360(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 360);
	// mr r21,r4
	ctx.r21.u64 = ctx.r4.u64;
	// lhz r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r5.u32 + 0);
	// mr r18,r5
	ctx.r18.u64 = ctx.r5.u64;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// divwu r9,r6,r10
	ctx.r9.u64 = uint32_t(ctx.r10.u32 ? ctx.r6.u32 / ctx.r10.u32 : 0);
	// divwu r8,r9,r28
	ctx.r8.u64 = uint32_t(ctx.r28.u32 ? ctx.r9.u32 / ctx.r28.u32 : 0);
	// rlwinm r7,r8,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82656cdc
	if (!ctx.cr6.lt) goto loc_82656CDC;
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f3c
	__restgprlr_17(ctx, base);
	return;
loc_82656CDC:
	// li r25,0
	ctx.r25.s64 = 0;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// ble cr6,0x82656e40
	if (!ctx.cr6.gt) goto loc_82656E40;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// li r22,0
	ctx.r22.s64 = 0;
	// mullw r23,r10,r28
	ctx.r23.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r28.s32);
	// mullw r24,r11,r28
	ctx.r24.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r28.s32);
loc_82656D00:
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,524(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// mullw r11,r24,r4
	ctx.r11.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r4.s32);
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r27,r11,r21
	ctx.r27.u64 = ctx.r11.u64 + ctx.r21.u64;
	// mullw r11,r23,r4
	ctx.r11.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r4.s32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// add r29,r11,r21
	ctx.r29.u64 = ctx.r11.u64 + ctx.r21.u64;
	// bctrl 
	ctx.lr = 0x82656D2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,88(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// add r8,r25,r28
	ctx.r8.u64 = ctx.r25.u64 + ctx.r28.u64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mullw r11,r8,r9
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r9.s32);
	// add r26,r11,r21
	ctx.r26.u64 = ctx.r11.u64 + ctx.r21.u64;
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// cmplw cr6,r29,r26
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x82656dd0
	if (!ctx.cr6.gt) goto loc_82656DD0;
loc_82656D4C:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82656D68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,524(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// mr r17,r30
	ctx.r17.u64 = ctx.r30.u64;
	// mullw r9,r4,r28
	ctx.r9.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r28.s32);
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// subf r27,r9,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r9.u64;
	// subf r29,r9,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r9.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bctrl 
	ctx.lr = 0x82656D94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,520(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// srawi r10,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r17.s32 >> 1;
	// srawi r11,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 1;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82656DBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mullw r6,r28,r7
	ctx.r6.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r7.s32);
	// subf r29,r6,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r6.u64;
	// cmplw cr6,r29,r26
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r26.u32, ctx.xer);
	// bgt cr6,0x82656d4c
	if (ctx.cr6.gt) goto loc_82656D4C;
loc_82656DD0:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82656DEC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,344(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 344);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r9,88(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// lwz r8,520(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// mullw r7,r28,r9
	ctx.r7.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// lwzx r4,r22,r10
	ctx.r4.u64 = REX_LOAD_U32(ctx.r22.u32 + ctx.r10.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// srawi r11,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 1;
	// srawi r10,r30,1
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 1;
	// subf r4,r7,r29
	ctx.r4.u64 = ctx.r29.u64 - ctx.r7.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82656E20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,344(r19)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r19.u32 + 344);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// cmpw cr6,r25,r28
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r28.s32, ctx.xer);
	// stwx r20,r22,r3
	REX_STORE_U32(ctx.r22.u32 + ctx.r3.u32, ctx.r20.u32);
	// addi r22,r22,4
	ctx.r22.s64 = ctx.r22.s64 + 4;
	// blt cr6,0x82656d00
	if (ctx.cr6.lt) goto loc_82656D00;
loc_82656E40:
	// lhz r11,0(r18)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r18.u32 + 0);
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwinm r10,r11,1,16,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFE;
	// sth r10,0(r18)
	REX_STORE_U16(ctx.r18.u32 + 0, ctx.r10.u16);
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// b 0x82739f3c
	__restgprlr_17(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8266A690) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// blt cr6,0x8266a73c
	if (ctx.cr6.lt) goto loc_8266A73C;
	// beq cr6,0x8266a6f4
	if (ctx.cr6.eq) goto loc_8266A6F4;
	// cmplwi cr6,r3,7
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 7, ctx.xer);
	// blt cr6,0x8266a73c
	if (ctx.cr6.lt) goto loc_8266A73C;
	// bne cr6,0x8266a744
	if (!ctx.cr6.eq) goto loc_8266A744;
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x8266a6c0
	if (!ctx.cr6.eq) goto loc_8266A6C0;
	// lis r11,-32154
	ctx.r11.s64 = -2107244544;
	// addi r11,r11,31736
	ctx.r11.s64 = ctx.r11.s64 + 31736;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A6C0:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x8266a6d4
	if (!ctx.cr6.eq) goto loc_8266A6D4;
	// lis r11,-32154
	ctx.r11.s64 = -2107244544;
	// addi r11,r11,32440
	ctx.r11.s64 = ctx.r11.s64 + 32440;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A6D4:
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// bne cr6,0x8266a6e8
	if (!ctx.cr6.eq) goto loc_8266A6E8;
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// addi r11,r11,-32344
	ctx.r11.s64 = ctx.r11.s64 + -32344;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A6E8:
	// lis r11,-32154
	ctx.r11.s64 = -2107244544;
	// addi r11,r11,30552
	ctx.r11.s64 = ctx.r11.s64 + 30552;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A6F4:
	// cmplwi cr6,r4,1
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 1, ctx.xer);
	// bne cr6,0x8266a708
	if (!ctx.cr6.eq) goto loc_8266A708;
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// addi r11,r11,-26056
	ctx.r11.s64 = ctx.r11.s64 + -26056;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A708:
	// cmplwi cr6,r4,2
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 2, ctx.xer);
	// bne cr6,0x8266a71c
	if (!ctx.cr6.eq) goto loc_8266A71C;
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// addi r11,r11,-29512
	ctx.r11.s64 = ctx.r11.s64 + -29512;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A71C:
	// cmplwi cr6,r4,6
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 6, ctx.xer);
	// bne cr6,0x8266a730
	if (!ctx.cr6.eq) goto loc_8266A730;
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// addi r11,r11,-28472
	ctx.r11.s64 = ctx.r11.s64 + -28472;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A730:
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// addi r11,r11,-31256
	ctx.r11.s64 = ctx.r11.s64 + -31256;
	// b 0x8266a744
	goto loc_8266A744;
loc_8266A73C:
	// lis r11,-32153
	ctx.r11.s64 = -2107179008;
	// addi r11,r11,-24728
	ctx.r11.s64 = ctx.r11.s64 + -24728;
loc_8266A744:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82673638) {
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
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x826736d8
	if (ctx.cr6.lt) goto loc_826736D8;
	// subfic r11,r4,-1
	ctx.xer.ca = ctx.r4.u32 <= 4294967295;
	ctx.r11.u64 = static_cast<uint64_t>(-1) - ctx.r4.u64;
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x826736d8
	if (ctx.cr6.gt) goto loc_826736D8;
	// lis r4,9356
	ctx.r4.s64 = 613154816;
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// bl 0x8263b678
	ctx.lr = 0x82673670;
	sub_8263B678(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826736d8
	if (ctx.cr6.eq) goto loc_826736D8;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// blt cr6,0x826736cc
	if (ctx.cr6.lt) goto loc_826736CC;
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// ble cr6,0x8267369c
	if (!ctx.cr6.gt) goto loc_8267369C;
loc_8267368C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srw r10,r31,r11
	ctx.r10.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r31.u32 >> (ctx.r11.u8 & 0x3F));
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bgt cr6,0x8267368c
	if (ctx.cr6.gt) goto loc_8267368C;
loc_8267369C:
	// li r10,-1
	ctx.r10.s64 = -1;
	// add r9,r3,r31
	ctx.r9.u64 = ctx.r3.u64 + ctx.r31.u64;
	// slw r8,r10,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// and r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 & ctx.r8.u64;
	// subf r6,r3,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r3.u64;
	// mr r3,r7
	ctx.r3.u64 = ctx.r7.u64;
	// stb r6,-1(r7)
	REX_STORE_U8(ctx.r7.u32 + -1, ctx.r6.u8);
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
loc_826736CC:
	// lis r4,9356
	ctx.r4.s64 = 613154816;
	// ori r4,r4,32768
	ctx.r4.u64 = ctx.r4.u64 | 32768;
	// bl 0x8263b710
	ctx.lr = 0x826736D8;
	sub_8263B710(ctx, base);
loc_826736D8:
	// li r3,0
	ctx.r3.s64 = 0;
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

DEFINE_REX_FUNC(sub_82676D00) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82676D08;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,348(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 348);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82676ddc
	if (ctx.cr6.eq) goto loc_82676DDC;
	// lwz r11,244(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 244);
	// li r27,0
	ctx.r27.s64 = 0;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82676dc8
	if (!ctx.cr6.gt) goto loc_82676DC8;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
loc_82676D34:
	// lwz r11,348(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// lwzx r10,r29,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82676db4
	if (ctx.cr6.eq) goto loc_82676DB4;
	// lwz r11,244(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 244);
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82676d94
	if (!ctx.cr6.gt) goto loc_82676D94;
	// mr r31,r27
	ctx.r31.u64 = ctx.r27.u64;
loc_82676D58:
	// lwz r11,348(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// lwzx r11,r29,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82676d80
	if (ctx.cr6.eq) goto loc_82676D80;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x82673628
	ctx.lr = 0x82676D74;
	sub_82673628(ctx, base);
	// lwz r11,348(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// lwzx r10,r29,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// stwx r27,r10,r31
	REX_STORE_U32(ctx.r10.u32 + ctx.r31.u32, ctx.r27.u32);
loc_82676D80:
	// lwz r11,244(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 244);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// cmpw cr6,r28,r11
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82676d58
	if (ctx.cr6.lt) goto loc_82676D58;
loc_82676D94:
	// lwz r11,348(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// lwzx r10,r29,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82676db4
	if (ctx.cr6.eq) goto loc_82676DB4;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// bl 0x82673628
	ctx.lr = 0x82676DAC;
	sub_82673628(ctx, base);
	// lwz r11,348(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// stwx r27,r29,r11
	REX_STORE_U32(ctx.r29.u32 + ctx.r11.u32, ctx.r27.u32);
loc_82676DB4:
	// lwz r11,244(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 244);
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r26,r11
	ctx.cr6.compare<int32_t>(ctx.r26.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82676d34
	if (ctx.cr6.lt) goto loc_82676D34;
loc_82676DC8:
	// lwz r3,348(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 348);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82676ddc
	if (ctx.cr6.eq) goto loc_82676DDC;
	// bl 0x82673628
	ctx.lr = 0x82676DD8;
	sub_82673628(ctx, base);
	// stw r27,348(r30)
	REX_STORE_U32(ctx.r30.u32 + 348, ctx.r27.u32);
loc_82676DDC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8267E4E0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r8,-32114
	ctx.r8.s64 = -2104623104;
	// lwz r11,15792(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 15792);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8267e534
	if (!ctx.cr6.eq) goto loc_8267E534;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// li r9,256
	ctx.r9.s64 = 256;
	// addi r10,r11,14768
	ctx.r10.s64 = ctx.r11.s64 + 14768;
	// li r11,0
	ctx.r11.s64 = 0;
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8267E508:
	// clrlwi r9,r11,27
	ctx.r9.u64 = ctx.r11.u32 & 0x1F;
	// extsb r6,r11
	ctx.r6.s64 = ctx.r11.s8;
	// addi r5,r9,32
	ctx.r5.s64 = ctx.r9.s64 + 32;
	// srawi r9,r6,5
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1F) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 5;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r4,r9,15
	ctx.r4.s64 = ctx.r9.s64 + 15;
	// slw r3,r5,r4
	ctx.r3.u64 = ctx.r4.u8 & 0x20 ? 0 : (ctx.r5.u32 << (ctx.r4.u8 & 0x3F));
	// stwu r3,4(r10)
	ea = 4 + ctx.r10.u32;
	REX_STORE_U32(ea, ctx.r3.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8267e508
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8267E508;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,15792(r8)
	REX_STORE_U32(ctx.r8.u32 + 15792, ctx.r11.u32);
loc_8267E534:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82681EA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82681EB0;
	__savegprlr_14(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r24,36(r4)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r4.u32 + 36);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r30,0(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// srawi r11,r24,8
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r24.s32 >> 8;
	// lis r9,-32254
	ctx.r9.s64 = -2113798144;
	// addze r10,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r10.s64 = temp.s64;
	// lis r8,-32254
	ctx.r8.s64 = -2113798144;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// lis r10,-32254
	ctx.r10.s64 = -2113798144;
	// lis r7,-32254
	ctx.r7.s64 = -2113798144;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// addi r29,r3,224
	ctx.r29.s64 = ctx.r3.s64 + 224;
	// mr r14,r4
	ctx.r14.u64 = ctx.r4.u64;
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// addi r31,r25,516
	ctx.r31.s64 = ctx.r25.s64 + 516;
	// li r16,2
	ctx.r16.s64 = 2;
	// li r23,5
	ctx.r23.s64 = 5;
	// lis r26,-32254
	ctx.r26.s64 = -2113798144;
	// li r15,3
	ctx.r15.s64 = 3;
	// lis r18,-32254
	ctx.r18.s64 = -2113798144;
	// lis r19,-32254
	ctx.r19.s64 = -2113798144;
	// addi r22,r10,4704
	ctx.r22.s64 = ctx.r10.s64 + 4704;
	// addi r27,r9,9448
	ctx.r27.s64 = ctx.r9.s64 + 9448;
	// addi r21,r8,4160
	ctx.r21.s64 = ctx.r8.s64 + 4160;
	// addi r28,r7,9192
	ctx.r28.s64 = ctx.r7.s64 + 9192;
	// addi r20,r11,3680
	ctx.r20.s64 = ctx.r11.s64 + 3680;
loc_82681F20:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplwi cr6,r11,14
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 14, ctx.xer);
	// bgt cr6,0x82681f20
	if (ctx.cr6.gt) goto loc_82681F20;
	// lis r12,-32152
	ctx.r12.s64 = -2107113472;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,8008
	ctx.r12.s64 = ctx.r12.s64 + 8008;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82681F84;
	case 1:
		goto loc_82682060;
	case 2:
		goto loc_826820FC;
	case 3:
		goto loc_82682178;
	case 4:
		goto loc_826821D8;
	case 5:
		goto loc_82681F20;
	case 6:
		goto loc_82681F20;
	case 7:
		goto loc_82681F20;
	case 8:
		goto loc_82681F20;
	case 9:
		goto loc_82681F20;
	case 10:
		goto loc_82681F20;
	case 11:
		goto loc_82681F20;
	case 12:
		goto loc_82681F20;
	case 13:
		goto loc_826822A0;
	case 14:
		goto loc_8268240C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82681F84:
	// stw r17,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r17.u32);
	// lwz r11,592(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82681fa4
	if (ctx.cr6.eq) goto loc_82681FA4;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r10,484(r14)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r14.u32 + 484);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// beq cr6,0x8268232c
	if (ctx.cr6.eq) goto loc_8268232C;
loc_82681FA4:
	// lhz r10,202(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 202);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r9,r24
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x82682354
	if (!ctx.cr6.lt) goto loc_82682354;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82683158
	ctx.lr = 0x82681FD8;
	sub_82683158(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82678d10
	ctx.lr = 0x82681FEC;
	sub_82678D10(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// lwz r10,10624(r19)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r19.u32 + 10624);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x82682018
	if (!ctx.cr6.eq) goto loc_82682018;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stw r16,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r16.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_82682018:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r28
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// rlwinm r9,r10,20,12,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xFFFFF;
	// stw r9,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r9.u32);
	// lbzx r8,r11,r28
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r28.u32);
	// clrlwi r7,r8,28
	ctx.r7.u64 = ctx.r8.u32 & 0xF;
	// stw r7,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r7.u32);
	// lhzx r6,r11,r28
	ctx.r6.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// rlwinm r5,r6,28,28,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 28) & 0xF;
	// stw r5,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
	// lhzx r4,r11,r28
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + ctx.r28.u32);
	// clrlwi r11,r4,28
	ctx.r11.u64 = ctx.r4.u32 & 0xF;
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_82682060:
	// mr r3,r21
	ctx.r3.u64 = ctx.r21.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82683158
	ctx.lr = 0x82682078;
	sub_82683158(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82678d10
	ctx.lr = 0x8268208C;
	sub_82678D10(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// lwz r10,10632(r18)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r18.u32 + 10632);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bne cr6,0x826820ac
	if (!ctx.cr6.eq) goto loc_826820AC;
loc_826820A4:
	// stw r15,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r15.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_826820AC:
	// lbzx r10,r11,r27
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r27.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rlwinm r9,r10,28,4,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0xFFFFFFF;
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r9,r7,r31
	REX_STORE_U32(ctx.r7.u32 + ctx.r31.u32, ctx.r9.u32);
	// lwz r6,80(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r11,6
	ctx.r5.s64 = ctx.r11.s64 + 6;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lbzx r11,r6,r27
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + ctx.r27.u32);
	// clrlwi r10,r11,28
	ctx.r10.u64 = ctx.r11.u32 & 0xF;
	// stwx r10,r4,r31
	REX_STORE_U32(ctx.r4.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
loc_826820EC:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82681f20
	if (!ctx.cr6.eq) goto loc_82681F20;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_826820FC:
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x82683158
	ctx.lr = 0x82682114;
	sub_82683158(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x82678d10
	ctx.lr = 0x82682128;
	sub_82678D10(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// lwz r11,10640(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 10640);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// bne cr6,0x8268214c
	if (!ctx.cr6.eq) goto loc_8268214C;
	// li r11,4
	ctx.r11.s64 = 4;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_8268214C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,5
	ctx.r11.s64 = ctx.r11.s64 + 5;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r9,r31
	REX_STORE_U32(ctx.r9.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x826820ec
	if (!ctx.cr6.eq) goto loc_826820EC;
	// stw r16,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r16.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_82682178:
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwz r4,10640(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 10640);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x826817b0
	ctx.lr = 0x82682190;
	sub_826817B0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r11,5
	ctx.r9.s64 = ctx.r11.s64 + 5;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r10,r8,r31
	REX_STORE_U32(ctx.r8.u32 + ctx.r31.u32, ctx.r10.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x826821c8
	if (!ctx.cr6.eq) goto loc_826821C8;
	// stw r16,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r16.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_826821C8:
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x826820a4
	if (!ctx.cr6.eq) goto loc_826820A4;
	// stw r23,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r23.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_826821D8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82682770
	ctx.lr = 0x826821E8;
	sub_82682770(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lis r11,-32768
	ctx.r11.s64 = -2147483648;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82682218
	if (ctx.cr6.eq) goto loc_82682218;
	// rlwinm r9,r10,1,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// lis r11,16384
	ctx.r11.s64 = 1073741824;
	// stw r9,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r9.u32);
	// li r4,1
	ctx.r4.s64 = 1;
loc_82682218:
	// lwz r9,24(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x8268223c
	if (ctx.cr6.eq) goto loc_8268223C;
	// and r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	// subfic r8,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r8.u64 = static_cast<uint64_t>(31) - ctx.r4.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r7,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r7.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_8268223C:
	// lwz r9,28(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82682260
	if (ctx.cr6.eq) goto loc_82682260;
	// and r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 & ctx.r10.u64;
	// subfic r8,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r8.u64 = static_cast<uint64_t>(31) - ctx.r4.u64;
	// rlwinm r11,r11,31,1,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// srw r7,r9,r8
	ctx.r7.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r8.u8 & 0x3F));
	// stw r7,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r7.u32);
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
loc_82682260:
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82682280
	if (ctx.cr6.eq) goto loc_82682280;
	// subfic r9,r4,31
	ctx.xer.ca = ctx.r4.u32 <= 31;
	ctx.r9.u64 = static_cast<uint64_t>(31) - ctx.r4.u64;
	// and r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 & ctx.r10.u64;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// srw r7,r8,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r9.u8 & 0x3F));
	// stw r7,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r7.u32);
loc_82682280:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82678d10
	ctx.lr = 0x82682288;
	sub_82678D10(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82682424
	if (ctx.cr6.lt) goto loc_82682424;
	// li r11,14
	ctx.r11.s64 = 14;
	// stw r17,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r17.u32);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_826822A0:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r10,r11,5
	ctx.r10.s64 = ctx.r11.s64 + 5;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// bne cr6,0x8268236c
	if (!ctx.cr6.eq) goto loc_8268236C;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r9,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r9.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// lwz r10,592(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826822ec
	if (!ctx.cr6.eq) goto loc_826822EC;
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x826822ec
	if (!ctx.cr6.gt) goto loc_826822EC;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_826822EC:
	// lhz r10,202(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 202);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r8,r24
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r24.s32, ctx.xer);
	// bge cr6,0x82682354
	if (!ctx.cr6.lt) goto loc_82682354;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// bne cr6,0x82681f20
	if (!ctx.cr6.eq) goto loc_82681F20;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// subfic r10,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// subfe r9,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r9.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r11,r9,0,28,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xE;
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// b 0x82681f20
	goto loc_82681F20;
loc_8268232C:
	// lis r11,-32152
	ctx.r11.s64 = -2107113472;
	// li r10,15
	ctx.r10.s64 = 15;
	// addi r9,r11,6792
	ctx.r9.s64 = ctx.r11.s64 + 6792;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// stw r9,484(r30)
	REX_STORE_U32(ctx.r30.u32 + 484, ctx.r9.u32);
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// bl 0x82681a88
	ctx.lr = 0x8268234C;
	sub_82681A88(ctx, base);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_82682354:
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// stw r17,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r17.u32);
	// stw r17,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r17.u32);
	// stw r10,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r10.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8268236C:
	// lwz r11,592(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 592);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82682390
	if (!ctx.cr6.eq) goto loc_82682390;
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r10,88(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x82682390
	if (!ctx.cr6.gt) goto loc_82682390;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_82682390:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// extsh r9,r11
	ctx.r9.s64 = ctx.r11.s16;
	// stw r9,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r9.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r8,r11,5
	ctx.r8.s64 = ctx.r11.s64 + 5;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r17,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r17.u32);
	// lwzx r6,r7,r31
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// stw r6,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r6.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r5,r11,9
	ctx.r5.s64 = ctx.r11.s64 + 9;
	// rlwinm r4,r5,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r4,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + ctx.r31.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82682424
	if (!ctx.cr6.eq) goto loc_82682424;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826823fc
	if (ctx.cr6.eq) goto loc_826823FC;
	// li r11,15
	ctx.r11.s64 = 15;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826823FC:
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8268240C:
	// lis r11,-32152
	ctx.r11.s64 = -2107113472;
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// addi r10,r11,6792
	ctx.r10.s64 = ctx.r11.s64 + 6792;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// stw r10,484(r30)
	REX_STORE_U32(ctx.r30.u32 + 484, ctx.r10.u32);
	// bl 0x82681a88
	ctx.lr = 0x82682424;
	sub_82681A88(ctx, base);
loc_82682424:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826B5708) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x826B5710;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r3,84(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b5744
	if (!ctx.cr0.lt) goto loc_826B5744;
	// bl 0x826c8b78
	ctx.lr = 0x826B5744;
	sub_826C8B78(ctx, base);
loc_826B5744:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwimi r11,r30,31,0,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r10,84(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826b5998
	if (!ctx.cr6.eq) goto loc_826B5998;
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x826b5794
	if (ctx.cr6.eq) goto loc_826B5794;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// sth r11,14(r31)
	REX_STORE_U16(ctx.r31.u32 + 14, ctx.r11.u16);
	// sth r11,16(r31)
	REX_STORE_U16(ctx.r31.u32 + 16, ctx.r11.u16);
	// sth r11,18(r31)
	REX_STORE_U16(ctx.r31.u32 + 18, ctx.r11.u16);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// oris r10,r11,2
	ctx.r10.u64 = ctx.r11.u64 | 131072;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_826B5794:
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r29,84(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// addi r28,r10,19840
	ctx.r28.s64 = ctx.r10.s64 + 19840;
	// ld r9,0(r29)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rldicl r8,r9,9,55
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u64, 9) & 0x1FF;
	// rlwinm r26,r8,1,0,30
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r4,r26,r28
	ctx.r4.u64 = REX_LOAD_U8(ctx.r26.u32 + ctx.r28.u32);
	// bl 0x826c8c48
	ctx.lr = 0x826B57C0;
	sub_826C8C48(ctx, base);
	// addi r7,r28,1
	ctx.r7.s64 = ctx.r28.s64 + 1;
	// li r30,3
	ctx.r30.s64 = 3;
	// lbzx r11,r26,r7
	ctx.r11.u64 = REX_LOAD_U8(ctx.r26.u32 + ctx.r7.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x826b57d8
	if (!ctx.cr6.eq) goto loc_826B57D8;
	// stw r30,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
loc_826B57D8:
	// lwz r10,84(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// lwz r9,20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826b5998
	if (!ctx.cr6.eq) goto loc_826B5998;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// blt cr6,0x826b5998
	if (ctx.cr6.lt) goto loc_826B5998;
	// cmpwi cr6,r11,20
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 20, ctx.xer);
	// bgt cr6,0x826b5998
	if (ctx.cr6.gt) goto loc_826B5998;
	// srawi. r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r26,r11,30
	ctx.r26.u64 = ctx.r11.u32 & 0x3;
	// beq 0x826b58a0
	if (ctx.cr0.eq) goto loc_826B58A0;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// bne cr6,0x826b5998
	if (!ctx.cr6.eq) goto loc_826B5998;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r10,r11,0,15,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFFDFFFF;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// ld r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r7,r8,1,62
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r7,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r7.u64);
	// rldicl r29,r8,1,63
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r8.u64, 1) & 0x1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x826b5844
	if (!ctx.cr0.lt) goto loc_826B5844;
	// bl 0x826c8b78
	ctx.lr = 0x826B5844;
	sub_826C8B78(ctx, base);
loc_826B5844:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// clrlwi r10,r29,24
	ctx.r10.u64 = ctx.r29.u32 & 0xFF;
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lwz r29,84(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r9,20(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826b5998
	if (!ctx.cr6.eq) goto loc_826B5998;
	// ld r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// rldicl r9,r11,6,58
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 6) & 0x3F;
	// addi r28,r10,18416
	ctx.r28.s64 = ctx.r10.s64 + 18416;
	// rlwinm r25,r9,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r4,r25,r28
	ctx.r4.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r28.u32);
	// bl 0x826c8c48
	ctx.lr = 0x826B5884;
	sub_826C8C48(ctx, base);
	// addi r8,r28,1
	ctx.r8.s64 = ctx.r28.s64 + 1;
	// lbzx r11,r25,r8
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r8.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x826b5898
	if (!ctx.cr6.eq) goto loc_826B5898;
	// stw r30,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
loc_826B5898:
	// clrlwi r28,r11,24
	ctx.r28.u64 = ctx.r11.u32 & 0xFF;
	// b 0x826b5910
	goto loc_826B5910;
loc_826B58A0:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// oris r9,r11,2
	ctx.r9.u64 = ctx.r11.u64 | 131072;
	// addi r28,r10,18416
	ctx.r28.s64 = ctx.r10.s64 + 18416;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lwz r29,84(r27)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r29.u32 + 0);
	// rldicl r7,r8,6,58
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u64, 6) & 0x3F;
	// rlwinm r25,r7,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r4,r25,r28
	ctx.r4.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r28.u32);
	// bl 0x826c8c48
	ctx.lr = 0x826B58D0;
	sub_826C8C48(ctx, base);
	// addi r6,r28,1
	ctx.r6.s64 = ctx.r28.s64 + 1;
	// lbzx r11,r25,r6
	ctx.r11.u64 = REX_LOAD_U8(ctx.r25.u32 + ctx.r6.u32);
	// cmplwi cr6,r11,255
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 255, ctx.xer);
	// bne cr6,0x826b58e4
	if (!ctx.cr6.eq) goto loc_826B58E4;
	// stw r30,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r30.u32);
loc_826B58E4:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// subfic r28,r11,15
	ctx.xer.ca = ctx.r11.u32 <= 15;
	ctx.r28.u64 = static_cast<uint64_t>(15) - ctx.r11.u64;
	// bne cr6,0x826b5900
	if (!ctx.cr6.eq) goto loc_826B5900;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x826b5904
	if (ctx.cr6.eq) goto loc_826B5904;
loc_826B5900:
	// li r11,0
	ctx.r11.s64 = 0;
loc_826B5904:
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwimi r10,r11,30,1,1
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x40000000) | (ctx.r10.u64 & 0xFFFFFFFFBFFFFFFF);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
loc_826B5910:
	// lwz r11,84(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x826b5998
	if (!ctx.cr6.eq) goto loc_826B5998;
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// blt cr6,0x826b5998
	if (ctx.cr6.lt) goto loc_826B5998;
	// cmpwi cr6,r28,15
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 15, ctx.xer);
	// bgt cr6,0x826b5998
	if (ctx.cr6.gt) goto loc_826B5998;
	// srawi r5,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r26.s32 >> 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82700948
	ctx.lr = 0x826B5940;
	sub_82700948(ctx, base);
	// clrlwi r5,r26,31
	ctx.r5.u64 = ctx.r26.u32 & 0x1;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82700948
	ctx.lr = 0x826B5950;
	sub_82700948(ctx, base);
	// li r29,1
	ctx.r29.s64 = 1;
loc_826B5954:
	// sraw r11,r28,r30
	temp.u32 = ctx.r30.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r28.s32 < 0) & (((ctx.r28.s32 >> temp.u32) << temp.u32) != ctx.r28.s32);
	ctx.r11.s64 = ctx.r28.s32 >> temp.u32;
	// clrlwi r5,r11,31
	ctx.r5.u64 = ctx.r11.u32 & 0x1;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82700948
	ctx.lr = 0x826B5968;
	sub_82700948(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bge 0x826b5954
	if (!ctx.cr0.lt) goto loc_826B5954;
	// addi r3,r31,14
	ctx.r3.s64 = ctx.r31.s64 + 14;
	// bl 0x826a6d28
	ctx.lr = 0x826B597C;
	sub_826A6D28(ctx, base);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// rlwimi r10,r11,19,12,13
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 19) & 0xC0000) | (ctx.r10.u64 & 0xFFFFFFFFFFF3FFFF);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
loc_826B5998:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826D00F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f0,2524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f3,f0
	ctx.cr6.compare(ctx.f3.f64, ctx.f0.f64);
	// ble cr6,0x826d0638
	if (!ctx.cr6.gt) goto loc_826D0638;
	// fcmpu cr6,f4,f0
	ctx.cr6.compare(ctx.f4.f64, ctx.f0.f64);
	// ble cr6,0x826d0638
	if (!ctx.cr6.gt) goto loc_826D0638;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// extsw r8,r11
	ctx.r8.s64 = ctx.r11.s32;
	// std r8,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r8.u64);
	// lfd f0,-48(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfs f13,7996(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7996);
	ctx.f13.f64 = double(temp.f32);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lfs f0,28280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28280);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f10,f3,f0
	ctx.f10.f64 = double(float(ctx.f3.f64 * ctx.f0.f64));
	// fmuls f9,f11,f13
	ctx.f9.f64 = double(float(ctx.f11.f64 * ctx.f13.f64));
	// fadds f11,f10,f1
	ctx.f11.f64 = double(float(ctx.f10.f64 + ctx.f1.f64));
	// fsubs f8,f9,f4
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f4.f64));
	// fneg f7,f9
	ctx.f7.u64 = ctx.f9.u64 ^ 0x8000000000000000;
	// fsubs f13,f2,f9
	ctx.f13.f64 = double(float(ctx.f2.f64 - ctx.f9.f64));
	// fsubs f0,f2,f8
	ctx.f0.f64 = double(float(ctx.f2.f64 - ctx.f8.f64));
	// fneg f6,f8
	ctx.f6.u64 = ctx.f8.u64 ^ 0x8000000000000000;
	// fsubs f9,f2,f7
	ctx.f9.f64 = double(float(ctx.f2.f64 - ctx.f7.f64));
	// fcmpu cr6,f0,f2
	ctx.cr6.compare(ctx.f0.f64, ctx.f2.f64);
	// fsubs f10,f2,f6
	ctx.f10.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// bgt cr6,0x826d0168
	if (ctx.cr6.gt) goto loc_826D0168;
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
loc_826D0168:
	// fctiwz f12,f2
	ctx.fpscr.disableFlushMode();
	ctx.f12.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfd f12,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f12.u64);
	// lwz r6,-44(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -44);
	// cmpw cr6,r6,r11
	ctx.cr6.compare<int32_t>(ctx.r6.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x826d0180
	if (!ctx.cr6.gt) goto loc_826D0180;
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
loc_826D0180:
	// fsubs f12,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// fsubs f8,f1,f11
	ctx.f8.f64 = double(float(ctx.f1.f64 - ctx.f11.f64));
	// li r4,4
	ctx.r4.s64 = 4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r5,-4
	ctx.r5.s64 = -4;
	// cmpwi cr6,r6,4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 4, ctx.xer);
	// lfd f0,6296(r10)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r10.u32 + 6296);
	// fdivs f12,f8,f12
	ctx.f12.f64 = double(float(ctx.f8.f64 / ctx.f12.f64));
	// blt cr6,0x826d0294
	if (ctx.cr6.lt) goto loc_826D0294;
	// addi r9,r6,-4
	ctx.r9.s64 = ctx.r6.s64 + -4;
	// li r10,2
	ctx.r10.s64 = 2;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r8,r9,1
	ctx.r8.s64 = ctx.r9.s64 + 1;
	// li r9,0
	ctx.r9.s64 = 0;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826D01C0:
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// extsw r31,r31
	ctx.r31.s64 = ctx.r31.s32;
	// std r8,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r8.u64);
	// lfd f8,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// std r31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.r31.u64);
	// lfd f7,-40(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// extsw r31,r11
	ctx.r31.s64 = ctx.r11.s32;
	// std r8,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r8.u64);
	// lfd f3,-24(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// std r31,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r31.u64);
	// lfd f6,-32(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// addi r8,r9,12
	ctx.r8.s64 = ctx.r9.s64 + 12;
	// fcfid f4,f8
	ctx.f4.f64 = double(ctx.f8.s64);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// frsp f2,f5
	ctx.f2.f64 = double(float(ctx.f5.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fcfid f8,f3
	ctx.f8.f64 = double(ctx.f3.s64);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// frsp f6,f4
	ctx.f6.f64 = double(float(ctx.f4.f64));
	// fsubs f5,f2,f13
	ctx.f5.f64 = double(float(ctx.f2.f64 - ctx.f13.f64));
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// fsubs f2,f6,f13
	ctx.f2.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fmadds f8,f5,f12,f11
	ctx.f8.f64 = double(float(std::fma(ctx.f5.f64, ctx.f12.f64, ctx.f11.f64)));
	// fsubs f7,f4,f13
	ctx.f7.f64 = double(float(ctx.f4.f64 - ctx.f13.f64));
	// fsubs f6,f3,f13
	ctx.f6.f64 = double(float(ctx.f3.f64 - ctx.f13.f64));
	// fmadds f5,f2,f12,f11
	ctx.f5.f64 = double(float(std::fma(ctx.f2.f64, ctx.f12.f64, ctx.f11.f64)));
	// fadd f4,f8,f0
	ctx.f4.f64 = ctx.f8.f64 + ctx.f0.f64;
	// fmadds f3,f7,f12,f11
	ctx.f3.f64 = double(float(std::fma(ctx.f7.f64, ctx.f12.f64, ctx.f11.f64)));
	// fmadds f2,f6,f12,f11
	ctx.f2.f64 = double(float(std::fma(ctx.f6.f64, ctx.f12.f64, ctx.f11.f64)));
	// fadd f8,f5,f0
	ctx.f8.f64 = ctx.f5.f64 + ctx.f0.f64;
	// fctiwz f7,f4
	ctx.f7.s64 = std::isnan(ctx.f4.f64) ? int64_t(0x80000000U) : (ctx.f4.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f4.f64));
	// stfiwx f7,r9,r7
	REX_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.f7.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r7,r9,r7
	ctx.r7.u64 = ctx.r9.u64 + ctx.r7.u64;
	// fadd f6,f3,f0
	ctx.f6.f64 = ctx.f3.f64 + ctx.f0.f64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fadd f5,f2,f0
	ctx.f5.f64 = ctx.f2.f64 + ctx.f0.f64;
	// fctiwz f4,f8
	ctx.f4.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f4,r7,r4
	REX_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.f4.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// fctiwz f3,f6
	ctx.f3.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfiwx f3,r7,r5
	REX_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.f3.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// fctiwz f2,f5
	ctx.f2.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfiwx f2,r7,r8
	REX_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.f2.u32);
	// bdnz 0x826d01c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826D01C0;
loc_826D0294:
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d02e0
	if (!ctx.cr6.lt) goto loc_826D02E0;
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826D02A8:
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// std r9,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r9.u64);
	// lfd f8,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// frsp f6,f7
	ctx.f6.f64 = double(float(ctx.f7.f64));
	// fsubs f5,f6,f13
	ctx.f5.f64 = double(float(ctx.f6.f64 - ctx.f13.f64));
	// fmadds f4,f5,f12,f11
	ctx.f4.f64 = double(float(std::fma(ctx.f5.f64, ctx.f12.f64, ctx.f11.f64)));
	// fadd f3,f4,f0
	ctx.f3.f64 = ctx.f4.f64 + ctx.f0.f64;
	// fctiwz f2,f3
	ctx.f2.s64 = std::isnan(ctx.f3.f64) ? int64_t(0x80000000U) : (ctx.f3.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f3.f64));
	// stfiwx f2,r8,r10
	REX_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.f2.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826d02a8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826D02A8;
loc_826D02E0:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r9.u64);
	// lfd f13,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f10,f13
	ctx.cr6.compare(ctx.f10.f64, ctx.f13.f64);
	// bgt cr6,0x826d0304
	if (ctx.cr6.gt) goto loc_826D0304;
	// fmr f13,f10
	ctx.f13.f64 = ctx.f10.f64;
loc_826D0304:
	// fctiwz f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f13.u64);
	// lwz r6,-20(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d03d0
	if (!ctx.cr6.lt) goto loc_826D03D0;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// lfs f13,5864(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
	// blt cr6,0x826d0394
	if (ctx.cr6.lt) goto loc_826D0394;
	// fadds f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f13.f64));
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// rlwinm r9,r9,30,2,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// fadd f8,f12,f0
	ctx.f8.f64 = ctx.f12.f64 + ctx.f0.f64;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fctiwz f7,f8
	ctx.f7.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfd f7,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f7.u64);
	// lwz r9,-20(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
loc_826D0360:
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r8,r10,12
	ctx.r8.s64 = ctx.r10.s64 + 12;
	// stwx r9,r7,r10
	REX_STORE_U32(ctx.r7.u32 + ctx.r10.u32, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r9,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stw r9,-4(r7)
	REX_STORE_U32(ctx.r7.u32 + -4, ctx.r9.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stwx r9,r7,r8
	REX_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.r9.u32);
	// bdnz 0x826d0360
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826D0360;
loc_826D0394:
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d03d0
	if (!ctx.cr6.lt) goto loc_826D03D0;
	// fadds f13,f1,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f1.f64 + ctx.f13.f64));
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// fadd f12,f13,f0
	ctx.f12.f64 = ctx.f13.f64 + ctx.f0.f64;
	// fctiwz f8,f12
	ctx.f8.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f8,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f8.u64);
	// lwz r9,-20(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
loc_826D03C0:
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stwx r9,r8,r10
	REX_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.r9.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826d03c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826D03C0;
loc_826D03D0:
	// lwz r10,4(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// std r9,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r9.u64);
	// lfd f13,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// fcmpu cr6,f9,f13
	ctx.cr6.compare(ctx.f9.f64, ctx.f13.f64);
	// bgt cr6,0x826d03f4
	if (ctx.cr6.gt) goto loc_826D03F4;
	// fmr f13,f9
	ctx.f13.f64 = ctx.f9.f64;
loc_826D03F4:
	// fsubs f12,f11,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = double(float(ctx.f11.f64 - ctx.f1.f64));
	// fsubs f11,f9,f10
	ctx.f11.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fctiwz f9,f13
	ctx.f9.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f9,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f9.u64);
	// fdivs f13,f12,f11
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f11.f64));
	// lwz r6,-20(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d055c
	if (!ctx.cr6.lt) goto loc_826D055C;
	// subf r10,r11,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r11.u64;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x826d0510
	if (ctx.cr6.lt) goto loc_826D0510;
	// subf r10,r11,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r10,-4
	ctx.r8.s64 = ctx.r10.s64 + -4;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// rlwinm r8,r8,30,2,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x3FFFFFFF;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_826D043C:
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// extsw r31,r11
	ctx.r31.s64 = ctx.r11.s32;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r31,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.r31.u64);
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// std r8,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r8.u64);
	// lfd f12,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// extsw r8,r31
	ctx.r8.s64 = ctx.r31.s32;
	// lfd f7,-48(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// extsw r31,r10
	ctx.r31.s64 = ctx.r10.s32;
	// fcfid f5,f7
	ctx.f5.f64 = double(ctx.f7.s64);
	// std r31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.r31.u64);
	// fcfid f6,f12
	ctx.f6.f64 = double(ctx.f12.s64);
	// std r8,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// frsp f12,f5
	ctx.f12.f64 = double(float(ctx.f5.f64));
	// addi r8,r9,12
	ctx.r8.s64 = ctx.r9.s64 + 12;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fsubs f7,f12,f10
	ctx.f7.f64 = double(float(ctx.f12.f64 - ctx.f10.f64));
	// lfd f9,-40(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// lfd f11,-32(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f8,f9
	ctx.f8.f64 = double(ctx.f9.s64);
	// fcfid f3,f11
	ctx.f3.f64 = double(ctx.f11.s64);
	// frsp f4,f8
	ctx.f4.f64 = double(float(ctx.f8.f64));
	// frsp f9,f3
	ctx.f9.f64 = double(float(ctx.f3.f64));
	// fsubs f8,f2,f10
	ctx.f8.f64 = double(float(ctx.f2.f64 - ctx.f10.f64));
	// fmadds f3,f7,f13,f1
	ctx.f3.f64 = double(float(std::fma(ctx.f7.f64, ctx.f13.f64, ctx.f1.f64)));
	// fsubs f11,f4,f10
	ctx.f11.f64 = double(float(ctx.f4.f64 - ctx.f10.f64));
	// fsubs f5,f9,f10
	ctx.f5.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f4,f8,f13,f1
	ctx.f4.f64 = double(float(std::fma(ctx.f8.f64, ctx.f13.f64, ctx.f1.f64)));
	// fadd f9,f3,f0
	ctx.f9.f64 = ctx.f3.f64 + ctx.f0.f64;
	// fmadds f6,f11,f13,f1
	ctx.f6.f64 = double(float(std::fma(ctx.f11.f64, ctx.f13.f64, ctx.f1.f64)));
	// fmadds f12,f5,f13,f1
	ctx.f12.f64 = double(float(std::fma(ctx.f5.f64, ctx.f13.f64, ctx.f1.f64)));
	// fadd f11,f4,f0
	ctx.f11.f64 = ctx.f4.f64 + ctx.f0.f64;
	// fctiwz f5,f9
	ctx.f5.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfiwx f5,r7,r9
	REX_STORE_U32(ctx.r7.u32 + ctx.r9.u32, ctx.f5.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// fadd f2,f6,f0
	ctx.f2.f64 = ctx.f6.f64 + ctx.f0.f64;
	// addi r9,r9,16
	ctx.r9.s64 = ctx.r9.s64 + 16;
	// fadd f7,f12,f0
	ctx.f7.f64 = ctx.f12.f64 + ctx.f0.f64;
	// fctiwz f6,f11
	ctx.f6.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfiwx f6,r7,r4
	REX_STORE_U32(ctx.r7.u32 + ctx.r4.u32, ctx.f6.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// fctiwz f8,f2
	ctx.f8.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f8,r7,r5
	REX_STORE_U32(ctx.r7.u32 + ctx.r5.u32, ctx.f8.u32);
	// lwz r7,20(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// fctiwz f4,f7
	ctx.f4.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfiwx f4,r7,r8
	REX_STORE_U32(ctx.r7.u32 + ctx.r8.u32, ctx.f4.u32);
	// bdnz 0x826d043c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826D043C;
loc_826D0510:
	// cmpw cr6,r11,r6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r6.s32, ctx.xer);
	// bge cr6,0x826d055c
	if (!ctx.cr6.lt) goto loc_826D055C;
	// subf r9,r11,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r11.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826D0524:
	// extsw r9,r11
	ctx.r9.s64 = ctx.r11.s32;
	// lwz r8,20(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// std r9,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r9.u64);
	// lfd f12,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f9,f11
	ctx.f9.f64 = double(float(ctx.f11.f64));
	// fsubs f8,f9,f10
	ctx.f8.f64 = double(float(ctx.f9.f64 - ctx.f10.f64));
	// fmadds f7,f8,f13,f1
	ctx.f7.f64 = double(float(std::fma(ctx.f8.f64, ctx.f13.f64, ctx.f1.f64)));
	// fadd f6,f7,f0
	ctx.f6.f64 = ctx.f7.f64 + ctx.f0.f64;
	// fctiwz f5,f6
	ctx.f5.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfiwx f5,r8,r10
	REX_STORE_U32(ctx.r8.u32 + ctx.r10.u32, ctx.f5.u32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// bdnz 0x826d0524
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826D0524;
loc_826D055C:
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826d059c
	if (!ctx.cr6.gt) goto loc_826D059C;
	// fadd f13,f1,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64 + ctx.f0.f64;
	// li r11,0
	ctx.r11.s64 = 0;
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f12.u64);
	// lwz r8,-20(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
loc_826D0580:
	// lwz r9,24(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r8,r9,r11
	REX_STORE_U32(ctx.r9.u32 + ctx.r11.u32, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x826d0580
	if (ctx.cr6.lt) goto loc_826D0580;
loc_826D059C:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x826d06c8
	if (!ctx.cr6.gt) goto loc_826D06C8;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfs f13,8680(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8680);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f13,f1,f13
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f13.f64));
loc_826D05B8:
	// lwz r9,20(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r8,28(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwzx r7,r9,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// extsw r6,r7
	ctx.r6.s64 = ctx.r7.s32;
	// std r6,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.r6.u64);
	// lfd f12,-24(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// fsubs f9,f13,f10
	ctx.f9.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fadd f8,f9,f0
	ctx.f8.f64 = ctx.f9.f64 + ctx.f0.f64;
	// fctiwz f7,f8
	ctx.f7.s64 = std::isnan(ctx.f8.f64) ? int64_t(0x80000000U) : (ctx.f8.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f8.f64));
	// stfiwx f7,r11,r8
	REX_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.f7.u32);
	// lwz r4,32(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwzx r9,r5,r11
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r11.u32);
	// extsw r8,r9
	ctx.r8.s64 = ctx.r9.s32;
	// std r8,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.r8.u64);
	// lfd f6,-32(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// frsp f4,f5
	ctx.f4.f64 = double(float(ctx.f5.f64));
	// fsubs f3,f13,f4
	ctx.f3.f64 = double(float(ctx.f13.f64 - ctx.f4.f64));
	// fadd f2,f3,f0
	ctx.f2.f64 = ctx.f3.f64 + ctx.f0.f64;
	// fctiwz f1,f2
	ctx.f1.s64 = std::isnan(ctx.f2.f64) ? int64_t(0x80000000U) : (ctx.f2.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f2.f64));
	// stfiwx f1,r4,r11
	REX_STORE_U32(ctx.r4.u32 + ctx.r11.u32, ctx.f1.u32);
	// lwz r7,4(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmpw cr6,r10,r7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x826d05b8
	if (ctx.cr6.lt) goto loc_826D05B8;
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
loc_826D0638:
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x826d06c8
	if (!ctx.cr6.gt) goto loc_826D06C8;
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// li r11,0
	ctx.r11.s64 = 0;
	// lfd f0,6296(r8)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r8.u32 + 6296);
	// fadd f11,f1,f0
	ctx.f11.f64 = ctx.f1.f64 + ctx.f0.f64;
	// lfs f13,5864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
	// fadds f12,f1,f13
	ctx.f12.f64 = double(float(ctx.f1.f64 + ctx.f13.f64));
	// fsubs f10,f1,f13
	ctx.f10.f64 = double(float(ctx.f1.f64 - ctx.f13.f64));
	// fctiwz f8,f11
	ctx.f8.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f8,-32(r1)
	REX_STORE_U64(ctx.r1.u32 + -32, ctx.f8.u64);
	// fadd f9,f12,f0
	ctx.f9.f64 = ctx.f12.f64 + ctx.f0.f64;
	// fadd f7,f10,f0
	ctx.f7.f64 = ctx.f10.f64 + ctx.f0.f64;
	// fctiwz f6,f9
	ctx.f6.s64 = std::isnan(ctx.f9.f64) ? int64_t(0x80000000U) : (ctx.f9.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f9.f64));
	// stfd f6,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f6.u64);
	// fctiwz f5,f7
	ctx.f5.s64 = std::isnan(ctx.f7.f64) ? int64_t(0x80000000U) : (ctx.f7.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f7.f64));
	// stfd f5,-24(r1)
	REX_STORE_U64(ctx.r1.u32 + -24, ctx.f5.u64);
	// lwz r8,-20(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -20);
	// lwz r7,-36(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + -36);
	// lwz r9,-28(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -28);
loc_826D0694:
	// lwz r6,20(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r7,r6,r11
	REX_STORE_U32(ctx.r6.u32 + ctx.r11.u32, ctx.r7.u32);
	// lwz r5,24(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// stwx r9,r5,r11
	REX_STORE_U32(ctx.r5.u32 + ctx.r11.u32, ctx.r9.u32);
	// lwz r4,28(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// stwx r8,r11,r4
	REX_STORE_U32(ctx.r11.u32 + ctx.r4.u32, ctx.r8.u32);
	// lwz r6,32(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// stwx r9,r6,r11
	REX_STORE_U32(ctx.r6.u32 + ctx.r11.u32, ctx.r9.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lwz r5,4(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// blt cr6,0x826d0694
	if (ctx.cr6.lt) goto loc_826D0694;
loc_826D06C8:
	// li r3,0
	ctx.r3.s64 = 0;
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826FF628) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x826FF630;
	__savegprlr_19(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,332(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 332);
	// mr r27,r9
	ctx.r27.u64 = ctx.r9.u64;
	// mr r23,r10
	ctx.r23.u64 = ctx.r10.u64;
	// lwz r10,152(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 152);
	// rlwinm r24,r11,0,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFE;
	// lwz r9,340(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// srawi r22,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r22.s64 = ctx.r24.s32 >> 1;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// srawi r25,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r25.s64 = ctx.r9.s32 >> 1;
	// beq cr6,0x826ff6a4
	if (ctx.cr6.eq) goto loc_826FF6A4;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// lwz r11,15916(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 15916);
	// lwz r25,324(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lwz r27,316(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r29,308(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stw r25,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// stw r27,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r27.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// bctrl 
	ctx.lr = 0x826FF69C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_826FF6A4:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x826ff720
	if (!ctx.cr6.gt) goto loc_826FF720;
	// lwz r21,324(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// lwz r20,316(r1)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r1.u32 + 316);
	// lwz r19,308(r1)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
loc_826FF6B8:
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FF6C8;
	sub_8273A030(ctx, base);
	// add r31,r31,r23
	ctx.r31.u64 = ctx.r31.u64 + ctx.r23.u64;
	// add r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 + ctx.r20.u64;
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FF6E0;
	sub_8273A030(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// add r31,r31,r23
	ctx.r31.u64 = ctx.r31.u64 + ctx.r23.u64;
	// add r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 + ctx.r20.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FF6F8;
	sub_8273A030(ctx, base);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// add r29,r29,r19
	ctx.r29.u64 = ctx.r29.u64 + ctx.r19.u64;
	// add r28,r28,r21
	ctx.r28.u64 = ctx.r28.u64 + ctx.r21.u64;
	// bl 0x8273a030
	ctx.lr = 0x826FF710;
	sub_8273A030(ctx, base);
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// add r27,r27,r19
	ctx.r27.u64 = ctx.r27.u64 + ctx.r19.u64;
	// add r26,r26,r21
	ctx.r26.u64 = ctx.r26.u64 + ctx.r21.u64;
	// bne 0x826ff6b8
	if (!ctx.cr0.eq) goto loc_826FF6B8;
loc_826FF720:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82704A90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x82704A98;
	__savegprlr_18(ctx, base);
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r29,136(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 136);
	// lwz r9,140(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 140);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r31,r10,1
	ctx.r31.s64 = ctx.r10.s64 + 1;
	// lwz r11,1772(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 1772);
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,1776(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 1776);
	// mullw r7,r29,r31
	ctx.r7.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r31.s32);
	// addi r3,r10,1
	ctx.r3.s64 = ctx.r10.s64 + 1;
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// mr r24,r4
	ctx.r24.u64 = ctx.r4.u64;
	// rlwinm r23,r29,3,0,28
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r22,r9,3,0,28
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82704b00
	if (ctx.cr6.eq) goto loc_82704B00;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// cmpwi cr6,r3,16384
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 16384, ctx.xer);
	// beq cr6,0x82704ba4
	if (ctx.cr6.eq) goto loc_82704BA4;
	// lhzx r11,r10,r8
	ctx.r11.u64 = REX_LOAD_U16(ctx.r10.u32 + ctx.r8.u32);
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// b 0x82705094
	goto loc_82705094;
loc_82704B00:
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r6,r29,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r4,r10,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r6,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r6.u64;
	// lhzx r28,r7,r8
	ctx.r28.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lhzx r6,r7,r11
	ctx.r6.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r11.u32);
	// rlwinm r7,r10,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r27,r9,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r26,r4,r8
	ctx.r26.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r8.u32);
	// lhzx r10,r4,r11
	ctx.r10.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r11.u32);
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// lhzx r4,r7,r11
	ctx.r4.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r11.u32);
	// addi r6,r5,-16384
	ctx.r6.s64 = ctx.r5.s64 + -16384;
	// lhzx r11,r27,r11
	ctx.r11.u64 = REX_LOAD_U16(ctx.r27.u32 + ctx.r11.u32);
	// addi r21,r9,-16384
	ctx.r21.s64 = ctx.r9.s64 + -16384;
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// lhzx r19,r7,r8
	ctx.r19.u64 = REX_LOAD_U16(ctx.r7.u32 + ctx.r8.u32);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhzx r27,r27,r8
	ctx.r27.u64 = REX_LOAD_U16(ctx.r27.u32 + ctx.r8.u32);
	// addi r8,r10,-16384
	ctx.r8.s64 = ctx.r10.s64 + -16384;
	// addi r7,r11,-16384
	ctx.r7.s64 = ctx.r11.s64 + -16384;
	// cntlzw r20,r6
	ctx.r20.u64 = ctx.r6.u32 == 0 ? 32 : __builtin_clz(ctx.r6.u32);
	// cntlzw r6,r8
	ctx.r6.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r4,r7
	ctx.r4.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r8,r6,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 27) & 0x1;
	// rlwinm r7,r4,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// cntlzw r21,r21
	ctx.r21.u64 = ctx.r21.u32 == 0 ? 32 : __builtin_clz(ctx.r21.u32);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// rlwinm r6,r21,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 27) & 0x1;
	// rlwinm r7,r20,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 27) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// extsh r4,r28
	ctx.r4.s64 = ctx.r28.s16;
	// add r28,r8,r7
	ctx.r28.u64 = ctx.r8.u64 + ctx.r7.u64;
	// extsh r6,r26
	ctx.r6.s64 = ctx.r26.s16;
	// extsh r7,r19
	ctx.r7.s64 = ctx.r19.s16;
	// extsh r8,r27
	ctx.r8.s64 = ctx.r27.s16;
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// ble cr6,0x82704c80
	if (!ctx.cr6.gt) goto loc_82704C80;
loc_82704BA4:
	// mullw r10,r29,r25
	ctx.r10.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r25.s32);
	// lwz r9,1780(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1780);
	// add r10,r10,r24
	ctx.r10.u64 = ctx.r10.u64 + ctx.r24.u64;
	// li r11,16384
	ctx.r11.s64 = 16384;
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r9,r8
	REX_STORE_U16(ctx.r9.u32 + ctx.r8.u32, ctx.r11.u16);
	// lwz r7,1784(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 1784);
	// sthx r11,r7,r8
	REX_STORE_U16(ctx.r7.u32 + ctx.r8.u32, ctx.r11.u16);
	// lwz r6,14804(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 14804);
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// ble cr6,0x82704c78
	if (!ctx.cr6.gt) goto loc_82704C78;
	// lwz r9,284(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 284);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x82704c78
	if (!ctx.cr6.eq) goto loc_82704C78;
	// lwz r9,3072(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3072);
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// li r31,0
	ctx.r31.s64 = 0;
	// sthx r31,r10,r9
	REX_STORE_U16(ctx.r10.u32 + ctx.r9.u32, ctx.r31.u16);
	// lwz r9,3072(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3072);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// sth r31,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r31.u16);
	// lwz r7,15504(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// cmpwi cr6,r7,7
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 7, ctx.xer);
	// blt cr6,0x82704c78
	if (ctx.cr6.lt) goto loc_82704C78;
	// lwz r9,136(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// lwz r7,15300(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 15300);
	// mullw r6,r9,r25
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r25.s32);
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r5,r10,r24
	ctx.r5.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rlwinm r9,r5,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r9,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r9,r9,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sthx r11,r10,r7
	REX_STORE_U16(ctx.r10.u32 + ctx.r7.u32, ctx.r11.u16);
	// lwz r8,15300(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 15300);
	// add r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 + ctx.r8.u64;
	// sth r11,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r11.u16);
	// lwz r3,15300(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 15300);
	// sthx r11,r9,r3
	REX_STORE_U16(ctx.r9.u32 + ctx.r3.u32, ctx.r11.u16);
	// lwz r8,15300(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 15300);
	// add r8,r9,r8
	ctx.r8.u64 = ctx.r9.u64 + ctx.r8.u64;
	// sth r11,2(r8)
	REX_STORE_U16(ctx.r8.u32 + 2, ctx.r11.u16);
	// lwz r7,15304(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 15304);
	// sthx r11,r10,r7
	REX_STORE_U16(ctx.r10.u32 + ctx.r7.u32, ctx.r11.u16);
	// lwz r8,15304(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 15304);
	// add r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 + ctx.r8.u64;
	// sth r11,2(r6)
	REX_STORE_U16(ctx.r6.u32 + 2, ctx.r11.u16);
	// lwz r5,15304(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 15304);
	// sthx r11,r9,r5
	REX_STORE_U16(ctx.r9.u32 + ctx.r5.u32, ctx.r11.u16);
	// lwz r10,15304(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 15304);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// sth r11,2(r4)
	REX_STORE_U16(ctx.r4.u32 + 2, ctx.r11.u16);
loc_82704C78:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
loc_82704C80:
	// cmpwi cr6,r28,1
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 1, ctx.xer);
	// bne cr6,0x82704e58
	if (!ctx.cr6.eq) goto loc_82704E58;
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// bne cr6,0x82704cfc
	if (!ctx.cr6.eq) goto loc_82704CFC;
	// subf r11,r5,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r5.u64;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subf r3,r5,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r5.u64;
	// subf r31,r4,r7
	ctx.r31.u64 = ctx.r7.u64 - ctx.r4.u64;
	// subf r29,r6,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r6.u64;
	// xor r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r11.u64;
	// subf r28,r4,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r4.u64;
	// xor r3,r3,r11
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// xor r29,r29,r31
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r31.u64;
	// srawi r11,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 31;
	// xor r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 ^ ctx.r31.u64;
	// srawi r8,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r31,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 31;
	// or r29,r11,r8
	ctx.r29.u64 = ctx.r11.u64 | ctx.r8.u64;
	// or r28,r3,r31
	ctx.r28.u64 = ctx.r3.u64 | ctx.r31.u64;
	// and r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 & ctx.r7.u64;
	// and r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	// andc r3,r9,r29
	ctx.r3.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// andc r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// or r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 | ctx.r11.u64;
	// and r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	// or r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r6,r31,r4
	ctx.r6.u64 = ctx.r31.u64 & ctx.r4.u64;
	// or r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r31,r7,r6
	ctx.r31.u64 = ctx.r7.u64 | ctx.r6.u64;
	// b 0x82705094
	goto loc_82705094;
loc_82704CFC:
	// cmpwi cr6,r10,16384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16384, ctx.xer);
	// bne cr6,0x82704d70
	if (!ctx.cr6.eq) goto loc_82704D70;
	// subf r10,r5,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r5.u64;
	// subf r7,r9,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r3,r5,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r5.u64;
	// subf r31,r4,r8
	ctx.r31.u64 = ctx.r8.u64 - ctx.r4.u64;
	// subf r29,r6,r8
	ctx.r29.u64 = ctx.r8.u64 - ctx.r6.u64;
	// xor r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// subf r28,r4,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r4.u64;
	// xor r3,r3,r10
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r10.u64;
	// xor r29,r29,r31
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r31.u64;
	// srawi r10,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 31;
	// xor r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 ^ ctx.r31.u64;
	// srawi r7,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r31,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 31;
	// or r29,r10,r7
	ctx.r29.u64 = ctx.r10.u64 | ctx.r7.u64;
	// or r28,r3,r31
	ctx.r28.u64 = ctx.r3.u64 | ctx.r31.u64;
	// and r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 & ctx.r8.u64;
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// andc r3,r9,r29
	ctx.r3.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// andc r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// and r7,r7,r5
	ctx.r7.u64 = ctx.r7.u64 & ctx.r5.u64;
	// or r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 | ctx.r11.u64;
	// or r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 | ctx.r8.u64;
	// and r5,r31,r4
	ctx.r5.u64 = ctx.r31.u64 & ctx.r4.u64;
	// or r3,r9,r7
	ctx.r3.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r31,r6,r5
	ctx.r31.u64 = ctx.r6.u64 | ctx.r5.u64;
	// b 0x82705094
	goto loc_82705094;
loc_82704D70:
	// cmpwi cr6,r9,16384
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16384, ctx.xer);
	// bne cr6,0x82704de4
	if (!ctx.cr6.eq) goto loc_82704DE4;
	// subf r9,r5,r10
	ctx.r9.u64 = ctx.r10.u64 - ctx.r5.u64;
	// subf r6,r11,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r3,r5,r11
	ctx.r3.u64 = ctx.r11.u64 - ctx.r5.u64;
	// subf r31,r4,r7
	ctx.r31.u64 = ctx.r7.u64 - ctx.r4.u64;
	// subf r29,r8,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r8.u64;
	// xor r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// subf r28,r4,r8
	ctx.r28.u64 = ctx.r8.u64 - ctx.r4.u64;
	// xor r3,r3,r9
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r9.u64;
	// xor r29,r29,r31
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r31.u64;
	// srawi r9,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 31;
	// xor r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 ^ ctx.r31.u64;
	// srawi r6,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r31,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 31;
	// or r29,r9,r6
	ctx.r29.u64 = ctx.r9.u64 | ctx.r6.u64;
	// or r28,r3,r31
	ctx.r28.u64 = ctx.r3.u64 | ctx.r31.u64;
	// and r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 & ctx.r7.u64;
	// andc r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 & ~ctx.r29.u64;
	// and r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 & ctx.r10.u64;
	// andc r10,r8,r28
	ctx.r10.u64 = ctx.r8.u64 & ~ctx.r28.u64;
	// and r8,r6,r5
	ctx.r8.u64 = ctx.r6.u64 & ctx.r5.u64;
	// or r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 | ctx.r11.u64;
	// or r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r6,r31,r4
	ctx.r6.u64 = ctx.r31.u64 & ctx.r4.u64;
	// or r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r31,r7,r6
	ctx.r31.u64 = ctx.r7.u64 | ctx.r6.u64;
	// b 0x82705094
	goto loc_82705094;
loc_82704DE4:
	// cmpwi cr6,r5,16384
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16384, ctx.xer);
	// bne cr6,0x82705094
	if (!ctx.cr6.eq) goto loc_82705094;
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r4,r9,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r9.u64;
	// subf r3,r11,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r11.u64;
	// subf r31,r8,r7
	ctx.r31.u64 = ctx.r7.u64 - ctx.r8.u64;
	// subf r29,r6,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r6.u64;
	// xor r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// xor r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// xor r29,r29,r31
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r31.u64;
	// srawi r5,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 31;
	// xor r31,r28,r31
	ctx.r31.u64 = ctx.r28.u64 ^ ctx.r31.u64;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r31,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 31;
	// or r29,r5,r4
	ctx.r29.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r28,r3,r31
	ctx.r28.u64 = ctx.r3.u64 | ctx.r31.u64;
	// and r4,r4,r11
	ctx.r4.u64 = ctx.r4.u64 & ctx.r11.u64;
	// andc r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// and r8,r31,r8
	ctx.r8.u64 = ctx.r31.u64 & ctx.r8.u64;
	// andc r11,r6,r28
	ctx.r11.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// or r6,r9,r4
	ctx.r6.u64 = ctx.r9.u64 | ctx.r4.u64;
	// and r7,r3,r7
	ctx.r7.u64 = ctx.r3.u64 & ctx.r7.u64;
	// and r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 & ctx.r10.u64;
	// or r4,r11,r8
	ctx.r4.u64 = ctx.r11.u64 | ctx.r8.u64;
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r31,r4,r7
	ctx.r31.u64 = ctx.r4.u64 | ctx.r7.u64;
	// b 0x82705094
	goto loc_82705094;
loc_82704E58:
	// cmpwi cr6,r28,2
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 2, ctx.xer);
	// bne cr6,0x82704ebc
	if (!ctx.cr6.eq) goto loc_82704EBC;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x82704e78
	if (ctx.cr6.eq) goto loc_82704E78;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// mr r31,r8
	ctx.r31.u64 = ctx.r8.u64;
loc_82704E78:
	// cmpwi cr6,r10,16384
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 16384, ctx.xer);
	// beq cr6,0x82704e88
	if (ctx.cr6.eq) goto loc_82704E88;
	// add r3,r10,r3
	ctx.r3.u64 = ctx.r10.u64 + ctx.r3.u64;
	// add r31,r7,r31
	ctx.r31.u64 = ctx.r7.u64 + ctx.r31.u64;
loc_82704E88:
	// cmpwi cr6,r9,16384
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 16384, ctx.xer);
	// beq cr6,0x82704e98
	if (ctx.cr6.eq) goto loc_82704E98;
	// add r3,r9,r3
	ctx.r3.u64 = ctx.r9.u64 + ctx.r3.u64;
	// add r31,r6,r31
	ctx.r31.u64 = ctx.r6.u64 + ctx.r31.u64;
loc_82704E98:
	// cmpwi cr6,r5,16384
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16384, ctx.xer);
	// beq cr6,0x82704ea8
	if (ctx.cr6.eq) goto loc_82704EA8;
	// add r3,r5,r3
	ctx.r3.u64 = ctx.r5.u64 + ctx.r3.u64;
	// add r31,r4,r31
	ctx.r31.u64 = ctx.r4.u64 + ctx.r31.u64;
loc_82704EA8:
	// srawi r11,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 1;
	// addze r3,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r3.s64 = temp.s64;
	// srawi r10,r31,1
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r31.s32 >> 1;
	// addze r31,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r31.s64 = temp.s64;
	// b 0x82705094
	goto loc_82705094;
loc_82704EBC:
	// subf r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r31,r10,r9
	ctx.r31.u64 = ctx.r9.u64 - ctx.r10.u64;
	// subf r29,r9,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r28,r10,r11
	ctx.r28.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r3,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 31;
	// subf r27,r9,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r31,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 31;
	// subf r26,r11,r9
	ctx.r26.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r29,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 31;
	// srawi r28,r28,31
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 31;
	// srawi r27,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 31;
	// srawi r26,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 31;
	// not r21,r31
	ctx.r21.u64 = ~ctx.r31.u64;
	// not r26,r26
	ctx.r26.u64 = ~ctx.r26.u64;
	// not r20,r3
	ctx.r20.u64 = ~ctx.r3.u64;
	// not r28,r28
	ctx.r28.u64 = ~ctx.r28.u64;
	// not r29,r29
	ctx.r29.u64 = ~ctx.r29.u64;
	// not r27,r27
	ctx.r27.u64 = ~ctx.r27.u64;
	// and r19,r20,r26
	ctx.r19.u64 = ctx.r20.u64 & ctx.r26.u64;
	// and r18,r28,r21
	ctx.r18.u64 = ctx.r28.u64 & ctx.r21.u64;
	// and r20,r27,r20
	ctx.r20.u64 = ctx.r27.u64 & ctx.r20.u64;
	// and r28,r28,r29
	ctx.r28.u64 = ctx.r28.u64 & ctx.r29.u64;
	// and r18,r18,r10
	ctx.r18.u64 = ctx.r18.u64 & ctx.r10.u64;
	// and r19,r19,r11
	ctx.r19.u64 = ctx.r19.u64 & ctx.r11.u64;
	// and r27,r27,r29
	ctx.r27.u64 = ctx.r27.u64 & ctx.r29.u64;
	// and r20,r20,r10
	ctx.r20.u64 = ctx.r20.u64 & ctx.r10.u64;
	// and r26,r26,r21
	ctx.r26.u64 = ctx.r26.u64 & ctx.r21.u64;
	// and r28,r28,r11
	ctx.r28.u64 = ctx.r28.u64 & ctx.r11.u64;
	// and r27,r27,r9
	ctx.r27.u64 = ctx.r27.u64 & ctx.r9.u64;
	// or r19,r19,r18
	ctx.r19.u64 = ctx.r19.u64 | ctx.r18.u64;
	// and r26,r26,r9
	ctx.r26.u64 = ctx.r26.u64 & ctx.r9.u64;
	// or r28,r20,r28
	ctx.r28.u64 = ctx.r20.u64 | ctx.r28.u64;
	// or r27,r19,r27
	ctx.r27.u64 = ctx.r19.u64 | ctx.r27.u64;
	// or r28,r28,r26
	ctx.r28.u64 = ctx.r28.u64 | ctx.r26.u64;
	// subf r26,r27,r5
	ctx.r26.u64 = ctx.r5.u64 - ctx.r27.u64;
	// subf r20,r5,r28
	ctx.r20.u64 = ctx.r28.u64 - ctx.r5.u64;
	// xor r21,r3,r21
	ctx.r21.u64 = ctx.r3.u64 ^ ctx.r21.u64;
	// xor r19,r3,r29
	ctx.r19.u64 = ctx.r3.u64 ^ ctx.r29.u64;
	// subf r18,r28,r27
	ctx.r18.u64 = ctx.r27.u64 - ctx.r28.u64;
	// srawi r3,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r26.s32 >> 31;
	// srawi r26,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r26.s64 = ctx.r20.s32 >> 31;
	// srawi r20,r18,31
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x7FFFFFFF) != 0);
	ctx.r20.s64 = ctx.r18.s32 >> 31;
	// eqv r26,r26,r3
	ctx.r26.u64 = ~(ctx.r26.u64 ^ ctx.r3.u64);
	// eqv r3,r20,r3
	ctx.r3.u64 = ~(ctx.r20.u64 ^ ctx.r3.u64);
	// and r10,r21,r10
	ctx.r10.u64 = ctx.r21.u64 & ctx.r10.u64;
	// or r21,r26,r3
	ctx.r21.u64 = ctx.r26.u64 | ctx.r3.u64;
	// xor r31,r31,r29
	ctx.r31.u64 = ctx.r31.u64 ^ ctx.r29.u64;
	// and r11,r19,r11
	ctx.r11.u64 = ctx.r19.u64 & ctx.r11.u64;
	// andc r29,r28,r21
	ctx.r29.u64 = ctx.r28.u64 & ~ctx.r21.u64;
	// and r3,r27,r3
	ctx.r3.u64 = ctx.r27.u64 & ctx.r3.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// and r9,r31,r9
	ctx.r9.u64 = ctx.r31.u64 & ctx.r9.u64;
	// and r5,r26,r5
	ctx.r5.u64 = ctx.r26.u64 & ctx.r5.u64;
	// or r10,r29,r3
	ctx.r10.u64 = ctx.r29.u64 | ctx.r3.u64;
	// or r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 | ctx.r9.u64;
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// subf r9,r8,r7
	ctx.r9.u64 = ctx.r7.u64 - ctx.r8.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r5,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 1;
	// subf r31,r6,r8
	ctx.r31.u64 = ctx.r8.u64 - ctx.r6.u64;
	// addze r3,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r3.s64 = temp.s64;
	// srawi r11,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 31;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r31.s32 >> 31;
	// not r29,r10
	ctx.r29.u64 = ~ctx.r10.u64;
	// not r28,r9
	ctx.r28.u64 = ~ctx.r9.u64;
	// xor r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r29.u64;
	// xor r5,r11,r28
	ctx.r5.u64 = ctx.r11.u64 ^ ctx.r28.u64;
	// xor r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 ^ ctx.r28.u64;
	// and r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 & ctx.r7.u64;
	// and r5,r5,r8
	ctx.r5.u64 = ctx.r5.u64 & ctx.r8.u64;
	// subf r31,r7,r8
	ctx.r31.u64 = ctx.r8.u64 - ctx.r7.u64;
	// subf r27,r6,r7
	ctx.r27.u64 = ctx.r7.u64 - ctx.r6.u64;
	// or r21,r9,r5
	ctx.r21.u64 = ctx.r9.u64 | ctx.r5.u64;
	// and r20,r10,r6
	ctx.r20.u64 = ctx.r10.u64 & ctx.r6.u64;
	// subf r26,r8,r6
	ctx.r26.u64 = ctx.r6.u64 - ctx.r8.u64;
	// srawi r10,r31,31
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r31.s32 >> 31;
	// srawi r9,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r27.s32 >> 31;
	// srawi r5,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r26.s32 >> 31;
	// or r31,r21,r20
	ctx.r31.u64 = ctx.r21.u64 | ctx.r20.u64;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// not r5,r5
	ctx.r5.u64 = ~ctx.r5.u64;
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// and r27,r11,r5
	ctx.r27.u64 = ctx.r11.u64 & ctx.r5.u64;
	// and r26,r10,r29
	ctx.r26.u64 = ctx.r10.u64 & ctx.r29.u64;
	// and r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 & ctx.r11.u64;
	// and r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 & ctx.r28.u64;
	// and r26,r26,r7
	ctx.r26.u64 = ctx.r26.u64 & ctx.r7.u64;
	// and r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 & ctx.r7.u64;
	// and r11,r10,r8
	ctx.r11.u64 = ctx.r10.u64 & ctx.r8.u64;
	// and r27,r27,r8
	ctx.r27.u64 = ctx.r27.u64 & ctx.r8.u64;
	// and r9,r9,r28
	ctx.r9.u64 = ctx.r9.u64 & ctx.r28.u64;
	// and r10,r5,r29
	ctx.r10.u64 = ctx.r5.u64 & ctx.r29.u64;
	// and r5,r9,r6
	ctx.r5.u64 = ctx.r9.u64 & ctx.r6.u64;
	// or r8,r27,r26
	ctx.r8.u64 = ctx.r27.u64 | ctx.r26.u64;
	// or r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 | ctx.r11.u64;
	// and r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 & ctx.r6.u64;
	// or r9,r8,r5
	ctx.r9.u64 = ctx.r8.u64 | ctx.r5.u64;
	// or r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 | ctx.r10.u64;
	// subf r7,r9,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r9.u64;
	// subf r6,r4,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r4.u64;
	// subf r5,r8,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r11,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 31;
	// srawi r10,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 31;
	// srawi r7,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 31;
	// eqv r6,r10,r11
	ctx.r6.u64 = ~(ctx.r10.u64 ^ ctx.r11.u64);
	// eqv r5,r7,r11
	ctx.r5.u64 = ~(ctx.r7.u64 ^ ctx.r11.u64);
	// and r4,r6,r4
	ctx.r4.u64 = ctx.r6.u64 & ctx.r4.u64;
	// or r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// and r10,r9,r5
	ctx.r10.u64 = ctx.r9.u64 & ctx.r5.u64;
	// andc r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 & ~ctx.r11.u64;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r11,r8,r4
	ctx.r11.u64 = ctx.r8.u64 | ctx.r4.u64;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r31,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r31.s64 = temp.s64;
loc_82705094:
	// lwz r11,136(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 136);
	// lwz r10,14804(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 14804);
	// mullw r11,r25,r11
	ctx.r11.s64 = int64_t(ctx.r25.s32) * int64_t(ctx.r11.s32);
	// add r6,r11,r24
	ctx.r6.u64 = ctx.r11.u64 + ctx.r24.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82705148
	if (!ctx.cr6.gt) goto loc_82705148;
	// lwz r11,15504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// mr r7,r3
	ctx.r7.u64 = ctx.r3.u64;
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x82705130
	if (!ctx.cr6.eq) goto loc_82705130;
	// srawi r11,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 2;
	// rlwinm r10,r24,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r25,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srawi r10,r31,2
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r31.s32 >> 2;
	// cmpwi cr6,r11,-8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8, ctx.xer);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bge cr6,0x827050f0
	if (!ctx.cr6.lt) goto loc_827050F0;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r7,r9,r3
	ctx.r7.u64 = ctx.r3.u64 - ctx.r9.u64;
	// b 0x82705104
	goto loc_82705104;
loc_827050F0:
	// cmpw cr6,r11,r23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r23.s32, ctx.xer);
	// ble cr6,0x82705104
	if (!ctx.cr6.gt) goto loc_82705104;
	// subf r11,r11,r23
	ctx.r11.u64 = ctx.r23.u64 - ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r11,r3
	ctx.r7.u64 = ctx.r11.u64 + ctx.r3.u64;
loc_82705104:
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x8270511c
	if (!ctx.cr6.lt) goto loc_8270511C;
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r8,r10,r31
	ctx.r8.u64 = ctx.r31.u64 - ctx.r10.u64;
	// b 0x82705130
	goto loc_82705130;
loc_8270511C:
	// cmpw cr6,r10,r22
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x82705130
	if (!ctx.cr6.gt) goto loc_82705130;
	// subf r11,r10,r22
	ctx.r11.u64 = ctx.r22.u64 - ctx.r10.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
loc_82705130:
	// lwz r10,3072(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3072);
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// sthx r7,r11,r10
	REX_STORE_U16(ctx.r11.u32 + ctx.r10.u32, ctx.r7.u16);
	// lwz r10,3072(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 3072);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// sth r8,2(r7)
	REX_STORE_U16(ctx.r7.u32 + 2, ctx.r8.u16);
loc_82705148:
	// lis r11,-32116
	ctx.r11.s64 = -2104754176;
	// lwz r10,1792(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 1792);
	// rlwinm r9,r3,2,28,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xC;
	// addi r8,r11,27768
	ctx.r8.s64 = ctx.r11.s64 + 27768;
	// rlwinm r7,r31,2,28,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xC;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwzx r11,r9,r8
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwzx r10,r7,r8
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + ctx.r8.u32);
	// add r5,r11,r3
	ctx.r5.u64 = ctx.r11.u64 + ctx.r3.u64;
	// add r4,r10,r31
	ctx.r4.u64 = ctx.r10.u64 + ctx.r31.u64;
	// srawi r9,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 1;
	// srawi r10,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r4.s32 >> 1;
	// beq cr6,0x827051bc
	if (ctx.cr6.eq) goto loc_827051BC;
	// clrlwi r11,r9,31
	ctx.r11.u64 = ctx.r9.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8270519c
	if (ctx.cr6.eq) goto loc_8270519C;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x82705198
	if (!ctx.cr6.gt) goto loc_82705198;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x8270519c
	goto loc_8270519C;
loc_82705198:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_8270519C:
	// clrlwi r11,r10,31
	ctx.r11.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x827051bc
	if (ctx.cr6.eq) goto loc_827051BC;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x827051b8
	if (!ctx.cr6.gt) goto loc_827051B8;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x827051bc
	goto loc_827051BC;
loc_827051B8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_827051BC:
	// lwz r11,15504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// bne cr6,0x82705238
	if (!ctx.cr6.eq) goto loc_82705238;
	// srawi r11,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 2;
	// rlwinm r8,r24,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r7,r25,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// srawi r8,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 2;
	// cmpwi cr6,r11,-8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -8, ctx.xer);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// bge cr6,0x827051f8
	if (!ctx.cr6.lt) goto loc_827051F8;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r7,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r7.u64;
	// b 0x8270520c
	goto loc_8270520C;
loc_827051F8:
	// cmpw cr6,r11,r23
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r23.s32, ctx.xer);
	// ble cr6,0x8270520c
	if (!ctx.cr6.gt) goto loc_8270520C;
	// subf r11,r11,r23
	ctx.r11.u64 = ctx.r23.u64 - ctx.r11.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
loc_8270520C:
	// cmpwi cr6,r8,-8
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -8, ctx.xer);
	// bge cr6,0x82705224
	if (!ctx.cr6.lt) goto loc_82705224;
	// addi r11,r8,8
	ctx.r11.s64 = ctx.r8.s64 + 8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r8,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r8.u64;
	// b 0x82705238
	goto loc_82705238;
loc_82705224:
	// cmpw cr6,r8,r22
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r22.s32, ctx.xer);
	// ble cr6,0x82705238
	if (!ctx.cr6.gt) goto loc_82705238;
	// subf r11,r8,r22
	ctx.r11.u64 = ctx.r22.u64 - ctx.r8.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
loc_82705238:
	// lwz r11,1780(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 1780);
	// rlwinm r8,r6,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// li r3,0
	ctx.r3.s64 = 0;
	// sthx r9,r11,r8
	REX_STORE_U16(ctx.r11.u32 + ctx.r8.u32, ctx.r9.u16);
	// lwz r5,1784(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 1784);
	// sthx r10,r5,r8
	REX_STORE_U16(ctx.r5.u32 + ctx.r8.u32, ctx.r10.u16);
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(__restgprlr_21) {
	REX_FUNC_PROLOGUE();
	// ld r21,-96(r1)
	ctx.r21.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// ld r22,-88(r1)
	ctx.r22.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// ld r23,-80(r1)
	ctx.r23.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// ld r24,-72(r1)
	ctx.r24.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// ld r25,-64(r1)
	ctx.r25.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// ld r26,-56(r1)
	ctx.r26.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// ld r27,-48(r1)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// ld r28,-40(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// ld r29,-32(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + -32);
	// ld r30,-24(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -24);
	// ld r31,-16(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(__savefpr_15) {
	REX_FUNC_PROLOGUE();
	// stfd f15,-136(r12)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r12.u32 + -136, ctx.f15.u64);
	// stfd f16,-128(r12)
	REX_STORE_U64(ctx.r12.u32 + -128, ctx.f16.u64);
	// stfd f17,-120(r12)
	REX_STORE_U64(ctx.r12.u32 + -120, ctx.f17.u64);
	// stfd f18,-112(r12)
	REX_STORE_U64(ctx.r12.u32 + -112, ctx.f18.u64);
	// stfd f19,-104(r12)
	REX_STORE_U64(ctx.r12.u32 + -104, ctx.f19.u64);
	// stfd f20,-96(r12)
	REX_STORE_U64(ctx.r12.u32 + -96, ctx.f20.u64);
	// stfd f21,-88(r12)
	REX_STORE_U64(ctx.r12.u32 + -88, ctx.f21.u64);
	// stfd f22,-80(r12)
	REX_STORE_U64(ctx.r12.u32 + -80, ctx.f22.u64);
	// stfd f23,-72(r12)
	REX_STORE_U64(ctx.r12.u32 + -72, ctx.f23.u64);
	// stfd f24,-64(r12)
	REX_STORE_U64(ctx.r12.u32 + -64, ctx.f24.u64);
	// stfd f25,-56(r12)
	REX_STORE_U64(ctx.r12.u32 + -56, ctx.f25.u64);
	// stfd f26,-48(r12)
	REX_STORE_U64(ctx.r12.u32 + -48, ctx.f26.u64);
	// stfd f27,-40(r12)
	REX_STORE_U64(ctx.r12.u32 + -40, ctx.f27.u64);
	// stfd f28,-32(r12)
	REX_STORE_U64(ctx.r12.u32 + -32, ctx.f28.u64);
	// stfd f29,-24(r12)
	REX_STORE_U64(ctx.r12.u32 + -24, ctx.f29.u64);
	// stfd f30,-16(r12)
	REX_STORE_U64(ctx.r12.u32 + -16, ctx.f30.u64);
	// stfd f31,-8(r12)
	REX_STORE_U64(ctx.r12.u32 + -8, ctx.f31.u64);
	// blr 
	return;
}

DEFINE_REX_FUNC(__savevmx_27) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx v27,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx v28,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v28.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx v29,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx v30,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx v31,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(__savevmx_89) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-624
	ctx.r11.s64 = -624;
	// stvx128 v89,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v89.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-608
	ctx.r11.s64 = -608;
	// stvx128 v90,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v90.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-592
	ctx.r11.s64 = -592;
	// stvx128 v91,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v91.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-576
	ctx.r11.s64 = -576;
	// stvx128 v92,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v92.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-560
	ctx.r11.s64 = -560;
	// stvx128 v93,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v93.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-544
	ctx.r11.s64 = -544;
	// stvx128 v94,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v94.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-528
	ctx.r11.s64 = -528;
	// stvx128 v95,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v95.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-512
	ctx.r11.s64 = -512;
	// stvx128 v96,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v96.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-496
	ctx.r11.s64 = -496;
	// stvx128 v97,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v97.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-480
	ctx.r11.s64 = -480;
	// stvx128 v98,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v98.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-464
	ctx.r11.s64 = -464;
	// stvx128 v99,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v99.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-448
	ctx.r11.s64 = -448;
	// stvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v100.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-432
	ctx.r11.s64 = -432;
	// stvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v101.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-416
	ctx.r11.s64 = -416;
	// stvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v102.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-400
	ctx.r11.s64 = -400;
	// stvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v103.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-384
	ctx.r11.s64 = -384;
	// stvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v104.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-368
	ctx.r11.s64 = -368;
	// stvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v105.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-352
	ctx.r11.s64 = -352;
	// stvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v106.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-336
	ctx.r11.s64 = -336;
	// stvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v107.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-320
	ctx.r11.s64 = -320;
	// stvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v108.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-304
	ctx.r11.s64 = -304;
	// stvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v109.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-288
	ctx.r11.s64 = -288;
	// stvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v110.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// stvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v111.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// stvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v112.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// stvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v113.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// stvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v114.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// stvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v115.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// stvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v116.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// stvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v117.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// stvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v118.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// stvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v119.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// stvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v120.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// stvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v121.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// stvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v122.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// stvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v123.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// stvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v124.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// stvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// stvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// stvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(__restvmx_106) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-352
	ctx.r11.s64 = -352;
	// lvx128 v106,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v106.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-336
	ctx.r11.s64 = -336;
	// lvx128 v107,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v107.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-320
	ctx.r11.s64 = -320;
	// lvx128 v108,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v108.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-304
	ctx.r11.s64 = -304;
	// lvx128 v109,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v109.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-288
	ctx.r11.s64 = -288;
	// lvx128 v110,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v110.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-272
	ctx.r11.s64 = -272;
	// lvx128 v111,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v111.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-256
	ctx.r11.s64 = -256;
	// lvx128 v112,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v112.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-240
	ctx.r11.s64 = -240;
	// lvx128 v113,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v113.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-224
	ctx.r11.s64 = -224;
	// lvx128 v114,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v114.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-208
	ctx.r11.s64 = -208;
	// lvx128 v115,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v115.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-192
	ctx.r11.s64 = -192;
	// lvx128 v116,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v116.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-176
	ctx.r11.s64 = -176;
	// lvx128 v117,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v117.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-160
	ctx.r11.s64 = -160;
	// lvx128 v118,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v118.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-144
	ctx.r11.s64 = -144;
	// lvx128 v119,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v119.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-128
	ctx.r11.s64 = -128;
	// lvx128 v120,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v120.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-112
	ctx.r11.s64 = -112;
	// lvx128 v121,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v121.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-96
	ctx.r11.s64 = -96;
	// lvx128 v122,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v122.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-80
	ctx.r11.s64 = -80;
	// lvx128 v123,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v123.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-64
	ctx.r11.s64 = -64;
	// lvx128 v124,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v124.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-48
	ctx.r11.s64 = -48;
	// lvx128 v125,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-32
	ctx.r11.s64 = -32;
	// lvx128 v126,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-16
	ctx.r11.s64 = -16;
	// lvx128 v127,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8273D7F8) {
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
	// bl 0x8273aa88
	ctx.lr = 0x8273D810;
	sub_8273AA88(ctx, base);
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8273d824
	if (ctx.cr6.eq) goto loc_8273D824;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x8273d828
	if (!ctx.cr6.eq) goto loc_8273D828;
loc_8273D824:
	// bl 0x82741800
	ctx.lr = 0x8273D828;
	sub_82741800(ctx, base);
loc_8273D828:
	// bl 0x8273aa88
	ctx.lr = 0x8273D82C;
	sub_8273AA88(ctx, base);
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8273d848
	if (!ctx.cr6.eq) goto loc_8273D848;
	// bl 0x8273aa88
	ctx.lr = 0x8273D83C;
	sub_8273AA88(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r11,148(r3)
	REX_STORE_U32(ctx.r3.u32 + 148, ctx.r11.u32);
	// b 0x8273d880
	goto loc_8273D880;
loc_8273D848:
	// bl 0x8273aa88
	ctx.lr = 0x8273D84C;
	sub_8273AA88(ctx, base);
	// lwz r11,148(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 148);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8273d87c
	if (ctx.cr6.eq) goto loc_8273D87C;
loc_8273D860:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r31,r10
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x8273d894
	if (ctx.cr6.eq) goto loc_8273D894;
	// lwz r9,8(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// addi r11,r10,8
	ctx.r11.s64 = ctx.r10.s64 + 8;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8273d860
	if (!ctx.cr6.eq) goto loc_8273D860;
loc_8273D87C:
	// bl 0x82741800
	ctx.lr = 0x8273D880;
	sub_82741800(ctx, base);
loc_8273D880:
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
loc_8273D894:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x8273d880
	goto loc_8273D880;
}

DEFINE_REX_FUNC(sub_82742598) {
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
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// rlwinm. r10,r10,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x827425c8
	if (ctx.cr0.eq) goto loc_827425C8;
	// lwz r10,8(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8274260c
	if (ctx.cr6.eq) goto loc_8274260C;
loc_827425C8:
	// lwz r10,4(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r10,4(r4)
	REX_STORE_U32(ctx.r4.u32 + 4, ctx.r10.u32);
	// blt 0x827425f4
	if (ctx.cr0.lt) goto loc_827425F4;
	// lwz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// clrlwi r3,r11,24
	ctx.r3.u64 = ctx.r11.u32 & 0xFF;
	// stb r11,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r11.u8);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r11.u32);
	// b 0x827425fc
	goto loc_827425FC;
loc_827425F4:
	// extsb r3,r11
	ctx.r3.s64 = ctx.r11.s8;
	// bl 0x8273dd20
	ctx.lr = 0x827425FC;
	sub_8273DD20(ctx, base);
loc_827425FC:
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// bne cr6,0x8274260c
	if (!ctx.cr6.eq) goto loc_8274260C;
	// li r11,-1
	ctx.r11.s64 = -1;
	// b 0x82742614
	goto loc_82742614;
loc_8274260C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82742614:
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

DEFINE_REX_FUNC(sub_82748820) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lwz r11,2196(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2196);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82748DA0) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// sth r11,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r11.u16);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x82855944
	ctx.lr = 0x82748DC8;
	__imp__RtlInitAnsiString(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8263c318
	ctx.lr = 0x82748DD0;
	sub_8263C318(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82748de0
	if (ctx.cr0.lt) goto loc_82748DE0;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82748de8
	goto loc_82748DE8;
loc_82748DE0:
	// bl 0x8263c0a8
	ctx.lr = 0x82748DE4;
	sub_8263C0A8(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_82748DE8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8274B040) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// vspltisw128 v63,4
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x4)));
	// vor128 v61,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// vspltisw128 v62,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_set1_epi32(int(0x8)));
	// addi r11,r11,32416
	ctx.r11.s64 = ctx.r11.s64 + 32416;
	// vspltisw128 v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_set1_epi32(int(0x1)));
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// vspltisw128 v59,2
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_set1_epi32(int(0x2)));
	// vcsxwfp128 v7,v63,0
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// vcsxwfp128 v5,v62,0
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// addi r10,r10,32400
	ctx.r10.s64 = ctx.r10.s64 + 32400;
	// vcsxwfp128 v58,v60,8
	simde_mm_store_ps(ctx.v58.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3B800000)))));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcsxwfp128 v60,v60,7
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v60.u32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x3C000000)))));
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vcsxwfp128 v13,v59,0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_cvtepi32_ps(simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vspltw128 v10,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw128 v6,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v11,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v0,v61,v57
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vspltw128 v63,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v59,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v57,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v62,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vcmpgtfp128 v12,v63,v61
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vcmpgtfp128 v8,v59,v61
	simde_mm_store_ps(ctx.v8.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vcmpgtfp128 v9,v57,v61
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vmaddfp v7,v0,v7,v10
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v6,v0,v5,v6
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v10,v0,v13,v11
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmulfp128 v63,v7,v58
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vmulfp128 v60,v6,v60
	simde_mm_store_ps(ctx.v60.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vrfiz128 v63,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v63.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vrfiz128 v60,v60
	simde_mm_store_ps(ctx.v60.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v60.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vaddfp128 v13,v7,v63
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v7.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vaddfp128 v11,v6,v60
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v60.f32)));
	// vsel v12,v11,v13,v12
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsel v13,v12,v10,v8
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8))));
	// vsel v12,v13,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v1,v12,v62
	simde_mm_store_ps(ctx.v1.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v62.f32)));
	// vrlimi128 v1,v61,1,0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_blend_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_permute_ps(simde_mm_load_ps(ctx.v61.f32), 228), 1));
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8275BFB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8275BFC0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275bfec
	if (ctx.cr6.eq) goto loc_8275BFEC;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755cf8
	ctx.lr = 0x8275BFE8;
	sub_82755CF8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_8275BFEC:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r6,4
	ctx.r6.s64 = 4;
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r4,2
	ctx.r4.s64 = 2;
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// lwz r8,104(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mullw r9,r9,r29
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r29.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x827548b8
	ctx.lr = 0x8275C01C;
	sub_827548B8(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8275D828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// lwz r8,100(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 100);
	// mullw r10,r11,r4
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// lwz r9,32(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r7,104(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// mullw r11,r8,r5
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r5.s32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8275d90c
	if (!ctx.cr6.lt) goto loc_8275D90C;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r9,r11,-4
	ctx.r9.s64 = ctx.r11.s64 + -4;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// lis r10,-32249
	ctx.r10.s64 = -2113470464;
	// rlwinm r11,r11,30,2,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x3FFFFFFF;
	// li r5,-32768
	ctx.r5.s64 = -32768;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f0,-30484(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30484);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f13,5864(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
loc_8275D890:
	// lwzu r11,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// stfs f13,8(r6)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// stfs f13,12(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// clrlwi r10,r11,16
	ctx.r10.u64 = ctx.r11.u32 & 0xFFFF;
	// rlwinm r11,r11,16,16,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF;
	// extsh r8,r10
	ctx.r8.s64 = ctx.r10.s16;
	// extsh r7,r11
	ctx.r7.s64 = ctx.r11.s16;
	// subf r8,r5,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r5.u64;
	// subf r7,r5,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r5.u64;
	// cntlzw r8,r8
	ctx.r8.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// cntlzw r7,r7
	ctx.r7.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// rlwinm r8,r8,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// rlwinm r7,r7,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmuls f12,f11,f0
	ctx.f12.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f12,4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz 0x8275d890
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8275D890;
loc_8275D90C:
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275d928
	if (ctx.cr6.eq) goto loc_8275D928;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82755c68
	ctx.lr = 0x8275D928;
	sub_82755C68(ctx, base);
loc_8275D928:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275d944
	if (ctx.cr6.eq) goto loc_8275D944;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82756030
	ctx.lr = 0x8275D944;
	sub_82756030(ctx, base);
loc_8275D944:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82763310) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82763318;
	__savegprlr_23(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r10,r11,-29640
	ctx.r10.s64 = ctx.r11.s64 + -29640;
	// stw r29,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r29.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// lis r6,27760
	ctx.r6.s64 = 1819279360;
	// stw r29,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r29.u32);
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// stw r29,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r29.u32);
	// mr r24,r5
	ctx.r24.u64 = ctx.r5.u64;
	// stw r29,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r29.u32);
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// stw r29,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r29.u32);
	// ori r6,r6,28019
	ctx.r6.u64 = ctx.r6.u64 | 28019;
	// stw r29,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r29.u32);
	// lwz r5,0(r3)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// std r29,0(r9)
	REX_STORE_U64(ctx.r9.u32 + 0, ctx.r29.u64);
	// std r29,8(r9)
	REX_STORE_U64(ctx.r9.u32 + 8, ctx.r29.u64);
	// std r29,16(r9)
	REX_STORE_U64(ctx.r9.u32 + 16, ctx.r29.u64);
	// bl 0x82762998
	ctx.lr = 0x82763374;
	sub_82762998(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8276368c
	if (ctx.cr6.lt) goto loc_8276368C;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r30,132(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// addi r23,r11,-27856
	ctx.r23.s64 = ctx.r11.s64 + -27856;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// bl 0x82764508
	ctx.lr = 0x82763398;
	sub_82764508(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x827633b0
	if (!ctx.cr6.eq) goto loc_827633B0;
	// lis r26,-32761
	ctx.r26.s64 = -2147024896;
	// ori r26,r26,14
	ctx.r26.u64 = ctx.r26.u64 | 14;
	// b 0x82763670
	goto loc_82763670;
loc_827633B0:
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82762700
	ctx.lr = 0x827633C8;
	sub_82762700(ctx, base);
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82763670
	if (ctx.cr6.lt) goto loc_82763670;
	// lbz r10,3(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 3);
	// addi r11,r31,4
	ctx.r11.s64 = ctx.r31.s64 + 4;
	// lbz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 0);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// addi r11,r31,12
	ctx.r11.s64 = ctx.r31.s64 + 12;
	// addi r11,r31,16
	ctx.r11.s64 = ctx.r31.s64 + 16;
	// addi r11,r31,20
	ctx.r11.s64 = ctx.r31.s64 + 20;
	// stb r10,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r10.u8);
	// addi r11,r31,24
	ctx.r11.s64 = ctx.r31.s64 + 24;
	// stb r9,3(r31)
	REX_STORE_U8(ctx.r31.u32 + 3, ctx.r9.u8);
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// lbz r8,2(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 2);
	// addi r30,r31,28
	ctx.r30.s64 = ctx.r31.s64 + 28;
	// lbz r7,1(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 1);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// stb r8,1(r31)
	REX_STORE_U8(ctx.r31.u32 + 1, ctx.r8.u8);
	// stb r7,2(r31)
	REX_STORE_U8(ctx.r31.u32 + 2, ctx.r7.u8);
	// lbz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 4);
	// lbz r5,7(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 7);
	// stb r5,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r5.u8);
	// stb r6,7(r31)
	REX_STORE_U8(ctx.r31.u32 + 7, ctx.r6.u8);
	// lbz r4,5(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 5);
	// lbz r3,6(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 6);
	// stb r3,5(r31)
	REX_STORE_U8(ctx.r31.u32 + 5, ctx.r3.u8);
	// stb r4,6(r31)
	REX_STORE_U8(ctx.r31.u32 + 6, ctx.r4.u8);
	// lbz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 8);
	// lbz r9,11(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 11);
	// stb r9,8(r31)
	REX_STORE_U8(ctx.r31.u32 + 8, ctx.r9.u8);
	// stb r11,11(r31)
	REX_STORE_U8(ctx.r31.u32 + 11, ctx.r11.u8);
	// lbz r8,9(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 9);
	// lbz r7,10(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 10);
	// stb r7,9(r31)
	REX_STORE_U8(ctx.r31.u32 + 9, ctx.r7.u8);
	// stb r8,10(r31)
	REX_STORE_U8(ctx.r31.u32 + 10, ctx.r8.u8);
	// lbz r6,12(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 12);
	// lbz r5,15(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 15);
	// stb r5,12(r31)
	REX_STORE_U8(ctx.r31.u32 + 12, ctx.r5.u8);
	// stb r6,15(r31)
	REX_STORE_U8(ctx.r31.u32 + 15, ctx.r6.u8);
	// lbz r4,13(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 13);
	// lbz r3,14(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 14);
	// stb r3,13(r31)
	REX_STORE_U8(ctx.r31.u32 + 13, ctx.r3.u8);
	// stb r4,14(r31)
	REX_STORE_U8(ctx.r31.u32 + 14, ctx.r4.u8);
	// lbz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 16);
	// lbz r9,19(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 19);
	// stb r9,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r9.u8);
	// stb r11,19(r31)
	REX_STORE_U8(ctx.r31.u32 + 19, ctx.r11.u8);
	// lbz r8,17(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 17);
	// lbz r7,18(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 18);
	// stb r7,17(r31)
	REX_STORE_U8(ctx.r31.u32 + 17, ctx.r7.u8);
	// stb r8,18(r31)
	REX_STORE_U8(ctx.r31.u32 + 18, ctx.r8.u8);
	// lbz r6,20(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 20);
	// lbz r5,23(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 23);
	// stb r5,20(r31)
	REX_STORE_U8(ctx.r31.u32 + 20, ctx.r5.u8);
	// stb r6,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r6.u8);
	// lbz r4,21(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 21);
	// lbz r3,22(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 22);
	// stb r3,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r3.u8);
	// stb r4,22(r31)
	REX_STORE_U8(ctx.r31.u32 + 22, ctx.r4.u8);
	// lbz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// lbz r9,27(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 27);
	// stb r9,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r9.u8);
	// stb r11,27(r31)
	REX_STORE_U8(ctx.r31.u32 + 27, ctx.r11.u8);
	// lbz r8,25(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 25);
	// lbz r7,26(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 26);
	// stb r7,25(r31)
	REX_STORE_U8(ctx.r31.u32 + 25, ctx.r7.u8);
	// stb r8,26(r31)
	REX_STORE_U8(ctx.r31.u32 + 26, ctx.r8.u8);
	// lbz r6,31(r31)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r31.u32 + 31);
	// lbz r5,28(r31)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// stb r6,28(r31)
	REX_STORE_U8(ctx.r31.u32 + 28, ctx.r6.u8);
	// stb r5,31(r31)
	REX_STORE_U8(ctx.r31.u32 + 31, ctx.r5.u8);
	// lbz r4,30(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 30);
	// lbz r3,29(r31)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r31.u32 + 29);
	// stb r4,29(r31)
	REX_STORE_U8(ctx.r31.u32 + 29, ctx.r4.u8);
	// stb r3,30(r31)
	REX_STORE_U8(ctx.r31.u32 + 30, ctx.r3.u8);
	// lbz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 32);
	// lbz r9,35(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 35);
	// stb r9,32(r31)
	REX_STORE_U8(ctx.r31.u32 + 32, ctx.r9.u8);
	// stb r11,35(r31)
	REX_STORE_U8(ctx.r31.u32 + 35, ctx.r11.u8);
	// lbz r8,34(r31)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r31.u32 + 34);
	// lbz r7,33(r31)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r31.u32 + 33);
	// stb r8,33(r31)
	REX_STORE_U8(ctx.r31.u32 + 33, ctx.r8.u8);
	// stb r7,34(r31)
	REX_STORE_U8(ctx.r31.u32 + 34, ctx.r7.u8);
	// lwz r6,28(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// ble cr6,0x827635f8
	if (!ctx.cr6.gt) goto loc_827635F8;
	// addi r11,r31,34
	ctx.r11.s64 = ctx.r31.s64 + 34;
loc_82763528:
	// lbz r9,5(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 5);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// stb r9,2(r11)
	REX_STORE_U8(ctx.r11.u32 + 2, ctx.r9.u8);
	// stb r8,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, ctx.r8.u8);
	// lbz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r6,3(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
	// stb r7,3(r11)
	REX_STORE_U8(ctx.r11.u32 + 3, ctx.r7.u8);
	// stb r6,4(r11)
	REX_STORE_U8(ctx.r11.u32 + 4, ctx.r6.u8);
	// lbz r5,9(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// lbz r4,6(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 6);
	// stb r5,6(r11)
	REX_STORE_U8(ctx.r11.u32 + 6, ctx.r5.u8);
	// stb r4,9(r11)
	REX_STORE_U8(ctx.r11.u32 + 9, ctx.r4.u8);
	// lbz r3,7(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// lbz r9,8(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// stb r9,7(r11)
	REX_STORE_U8(ctx.r11.u32 + 7, ctx.r9.u8);
	// stb r3,8(r11)
	REX_STORE_U8(ctx.r11.u32 + 8, ctx.r3.u8);
	// lbz r8,13(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 13);
	// lbz r7,10(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 10);
	// stb r8,10(r11)
	REX_STORE_U8(ctx.r11.u32 + 10, ctx.r8.u8);
	// stb r7,13(r11)
	REX_STORE_U8(ctx.r11.u32 + 13, ctx.r7.u8);
	// lbz r6,12(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 12);
	// lbz r5,11(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 11);
	// stb r6,11(r11)
	REX_STORE_U8(ctx.r11.u32 + 11, ctx.r6.u8);
	// stb r5,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r5.u8);
	// lbz r4,17(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 17);
	// lbz r3,14(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 14);
	// stb r4,14(r11)
	REX_STORE_U8(ctx.r11.u32 + 14, ctx.r4.u8);
	// stb r3,17(r11)
	REX_STORE_U8(ctx.r11.u32 + 17, ctx.r3.u8);
	// lbz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// lbz r8,15(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 15);
	// stb r9,15(r11)
	REX_STORE_U8(ctx.r11.u32 + 15, ctx.r9.u8);
	// stb r8,16(r11)
	REX_STORE_U8(ctx.r11.u32 + 16, ctx.r8.u8);
	// lbz r7,18(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 18);
	// lbz r6,21(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 21);
	// stb r6,18(r11)
	REX_STORE_U8(ctx.r11.u32 + 18, ctx.r6.u8);
	// stb r7,21(r11)
	REX_STORE_U8(ctx.r11.u32 + 21, ctx.r7.u8);
	// lbz r5,20(r11)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// lbz r4,19(r11)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r11.u32 + 19);
	// stb r5,19(r11)
	REX_STORE_U8(ctx.r11.u32 + 19, ctx.r5.u8);
	// stb r4,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r4.u8);
	// lbz r3,25(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 25);
	// lbz r9,22(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
	// stb r3,22(r11)
	REX_STORE_U8(ctx.r11.u32 + 22, ctx.r3.u8);
	// stb r9,25(r11)
	REX_STORE_U8(ctx.r11.u32 + 25, ctx.r9.u8);
	// lbz r8,24(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 24);
	// lbz r7,23(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 23);
	// stb r8,23(r11)
	REX_STORE_U8(ctx.r11.u32 + 23, ctx.r8.u8);
	// stbu r7,24(r11)
	ea = 24 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r10,r6
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x82763528
	if (ctx.cr6.lt) goto loc_82763528;
loc_827635F8:
	// lwz r27,0(r30)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82763640
	if (ctx.cr6.eq) goto loc_82763640;
	// addi r28,r31,36
	ctx.r28.s64 = ctx.r31.s64 + 36;
loc_82763608:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,24
	ctx.r5.s64 = 24;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x8273a030
	ctx.lr = 0x82763618;
	sub_8273A030(ctx, base);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82763640
	if (ctx.cr6.eq) goto loc_82763640;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r28,r28,24
	ctx.r28.s64 = ctx.r28.s64 + 24;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmplw cr6,r29,r27
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r27.u32, ctx.xer);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// blt cr6,0x82763608
	if (ctx.cr6.lt) goto loc_82763608;
loc_82763640:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82763658
	if (!ctx.cr6.eq) goto loc_82763658;
	// lis r26,-28655
	ctx.r26.s64 = -1877934080;
	// ori r26,r26,3
	ctx.r26.u64 = ctx.r26.u64 | 3;
	// b 0x82763670
	goto loc_82763670;
loc_82763658:
	// lwz r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r9.u32);
loc_82763670:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82763688
	if (ctx.cr6.eq) goto loc_82763688;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// lis r5,24962
	ctx.r5.s64 = 1635909632;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82764518
	ctx.lr = 0x82763688;
	sub_82764518(ctx, base);
loc_82763688:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
loc_8276368C:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82773E70) {
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
	// lwz r3,8(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r11,r11,-29256
	ctx.r11.s64 = ctx.r11.s64 + -29256;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x8276b420
	ctx.lr = 0x82773E98;
	sub_8276B420(ctx, base);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// li r3,260
	ctx.r3.s64 = 260;
	// bl 0x82772060
	ctx.lr = 0x82773EA4;
	sub_82772060(ctx, base);
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

DEFINE_REX_FUNC(sub_827756F0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x827756F8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// cntlzw r11,r4
	ctx.r11.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r4,r7,124
	ctx.r4.s64 = ctx.r7.s64 + 124;
	// addi r3,r11,512
	ctx.r3.s64 = ctx.r11.s64 + 512;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// bl 0x82772048
	ctx.lr = 0x82775724;
	sub_82772048(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82775748
	if (ctx.cr0.eq) goto loc_82775748;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x827755e8
	ctx.lr = 0x82775748;
	sub_827755E8(ctx, base);
loc_82775748:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82777820) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// lwz r10,12(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 12);
	// addi r11,r4,12
	ctx.r11.s64 = ctx.r4.s64 + 12;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82777868
	if (!ctx.cr6.eq) goto loc_82777868;
loc_82777830:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r4
	ea = ctx.r4.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r4
	ea = ctx.r4.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82777830
	if (!ctx.cr0.eq) goto loc_82777830;
	// addi r10,r3,216
	ctx.r10.s64 = ctx.r3.s64 + 216;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r10,220(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// lwz r10,220(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 220);
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// stw r11,220(r3)
	REX_STORE_U32(ctx.r3.u32 + 220, ctx.r11.u32);
loc_82777868:
	// lwz r11,396(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 396);
	// oris r11,r11,1024
	ctx.r11.u64 = ctx.r11.u64 | 67108864;
	// stw r11,396(r3)
	REX_STORE_U32(ctx.r3.u32 + 396, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8277BB08) {
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
	// lwz r10,208(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 208);
	// addi r11,r3,208
	ctx.r11.s64 = ctx.r3.s64 + 208;
	// lwz r8,20(r4)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8277bb68
	if (ctx.cr6.eq) goto loc_8277BB68;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8277bb68
	if (ctx.cr0.eq) goto loc_8277BB68;
loc_8277BB44:
	// lwz r7,56(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 56);
	// addi r10,r9,-4
	ctx.r10.s64 = ctx.r9.s64 + -4;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x8277bb6c
	if (ctx.cr6.eq) goto loc_8277BB6C;
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8277bb68
	if (ctx.cr6.eq) goto loc_8277BB68;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne 0x8277bb44
	if (!ctx.cr0.eq) goto loc_8277BB44;
loc_8277BB68:
	// li r10,0
	ctx.r10.s64 = 0;
loc_8277BB6C:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8277bc0c
	if (ctx.cr6.eq) goto loc_8277BC0C;
loc_8277BB74:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r10
	ea = ctx.r10.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r10
	ea = ctx.r10.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277bb74
	if (!ctx.cr0.eq) goto loc_8277BB74;
	// stw r10,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r10.u32);
	// lwz r4,184(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 184);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x8277bbcc
	if (ctx.cr6.eq) goto loc_8277BBCC;
loc_8277BBA0:
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
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
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
	// bne 0x8277bba0
	if (!ctx.cr0.eq) goto loc_8277BBA0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8277bbcc
	if (!ctx.cr6.eq) goto loc_8277BBCC;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x8277BBCC;
	sub_82772060(ctx, base);
loc_8277BBCC:
	// lwz r11,100(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,184(r31)
	REX_STORE_U32(ctx.r31.u32 + 184, ctx.r11.u32);
	// beq cr6,0x8277bbf8
	if (ctx.cr6.eq) goto loc_8277BBF8;
loc_8277BBDC:
	// mfmsr r9
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r9.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r10,0,r11
	ea = ctx.r11.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r10.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwcx. r10,0,r11
	ea = ctx.r11.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r10.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r9,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r9.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8277bbdc
	if (!ctx.cr0.eq) goto loc_8277BBDC;
loc_8277BBF8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82787510
	ctx.lr = 0x8277BC08;
	sub_82787510(ctx, base);
	// b 0x8277bc24
	goto loc_8277BC24;
loc_8277BC0C:
	// lis r5,-32646
	ctx.r5.s64 = -2139488256;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// ori r5,r5,4106
	ctx.r5.u64 = ctx.r5.u64 | 4106;
	// addi r3,r31,8
	ctx.r3.s64 = ctx.r31.s64 + 8;
	// bl 0x82787510
	ctx.lr = 0x8277BC20;
	sub_82787510(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8277BC24:
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

DEFINE_REX_FUNC(sub_82785908) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r9,r11,-28936
	ctx.r9.s64 = ctx.r11.s64 + -28936;
	// addi r11,r3,8
	ctx.r11.s64 = ctx.r3.s64 + 8;
	// stw r10,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r10.u32);
	// stw r9,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r9.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r11,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82785FE8) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// addi r4,r11,36
	ctx.r4.s64 = ctx.r11.s64 + 36;
	// li r5,12
	ctx.r5.s64 = 12;
	// b 0x8273a030
	sub_8273A030(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82786520) {
	REX_FUNC_PROLOGUE();
	// b 0x82786390
	sub_82786390(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82786608) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// addi r7,r3,28
	ctx.r7.s64 = ctx.r3.s64 + 28;
	// b 0x82786698
	goto loc_82786698;
loc_82786618:
	// lbz r11,52(r6)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r6.u32 + 52);
	// addi r3,r6,-4
	ctx.r3.s64 = ctx.r6.s64 + -4;
	// cmpw cr6,r11,r4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r4.s32, ctx.xer);
	// bne cr6,0x82786694
	if (!ctx.cr6.eq) goto loc_82786694;
	// addi r11,r3,57
	ctx.r11.s64 = ctx.r3.s64 + 57;
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// bne cr6,0x82786684
	if (!ctx.cr6.eq) goto loc_82786684;
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// addi r8,r11,38
	ctx.r8.s64 = ctx.r11.s64 + 38;
loc_8278663C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r31,0(r10)
	ctx.r31.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r31,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r31.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8278665c
	if (!ctx.cr0.eq) goto loc_8278665C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x8278663c
	if (!ctx.cr6.eq) goto loc_8278663C;
loc_8278665C:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82786694
	if (!ctx.cr0.eq) goto loc_82786694;
loc_82786664:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82786664
	if (!ctx.cr0.eq) goto loc_82786664;
	// b 0x827866d0
	goto loc_827866D0;
loc_82786684:
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x827866b4
	if (ctx.cr6.eq) goto loc_827866B4;
loc_82786694:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
loc_82786698:
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x827866ac
	if (ctx.cr6.eq) goto loc_827866AC;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// mr r6,r11
	ctx.r6.u64 = ctx.r11.u64;
	// bne 0x82786618
	if (!ctx.cr0.eq) goto loc_82786618;
loc_827866AC:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827866d0
	goto loc_827866D0;
loc_827866B4:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r3
	ea = ctx.r3.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwcx. r11,0,r3
	ea = ctx.r3.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x827866b4
	if (!ctx.cr0.eq) goto loc_827866B4;
loc_827866D0:
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8278BAC8) {
	REX_FUNC_PROLOGUE();
	// clrlwi r11,r4,22
	ctx.r11.u64 = ctx.r4.u32 & 0x3FF;
	// clrlwi r10,r4,16
	ctx.r10.u64 = ctx.r4.u32 & 0xFFFF;
	// cmplwi cr6,r11,256
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 256, ctx.xer);
	// bge cr6,0x8278baf0
	if (!ctx.cr6.lt) goto loc_8278BAF0;
	// clrlwi r9,r3,16
	ctx.r9.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r9,512
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 512, ctx.xer);
	// blt cr6,0x8278baf0
	if (ctx.cr6.lt) goto loc_8278BAF0;
	// addis r11,r10,1
	ctx.r11.s64 = ctx.r10.s64 + 65536;
	// addi r11,r11,-1024
	ctx.r11.s64 = ctx.r11.s64 + -1024;
	// b 0x8278bb08
	goto loc_8278BB08;
loc_8278BAF0:
	// cmplwi cr6,r11,768
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 768, ctx.xer);
	// blt cr6,0x8278bb0c
	if (ctx.cr6.lt) goto loc_8278BB0C;
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,512
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 512, ctx.xer);
	// bge cr6,0x8278bb0c
	if (!ctx.cr6.lt) goto loc_8278BB0C;
	// addi r11,r10,1024
	ctx.r11.s64 = ctx.r10.s64 + 1024;
loc_8278BB08:
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
loc_8278BB0C:
	// rlwinm r11,r4,0,16,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFC00;
	// clrlwi r10,r3,16
	ctx.r10.u64 = ctx.r3.u32 & 0xFFFF;
	// or r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 | ctx.r10.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8278CEF8) {
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
	// lwz r10,44(r4)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r4.u32 + 44);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// rlwinm. r9,r10,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x8278cf4c
	if (!ctx.cr0.eq) goto loc_8278CF4C;
	// lwz r9,20(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 20);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x8278cf40
	if (!ctx.cr6.eq) goto loc_8278CF40;
	// rlwinm. r10,r10,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x8278cf4c
	if (!ctx.cr0.eq) goto loc_8278CF4C;
	// lwz r10,580(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 580);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,580(r3)
	REX_STORE_U32(ctx.r3.u32 + 580, ctx.r10.u32);
	// b 0x8278cf4c
	goto loc_8278CF4C;
loc_8278CF40:
	// lwz r10,584(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 584);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,584(r11)
	REX_STORE_U32(ctx.r11.u32 + 584, ctx.r10.u32);
loc_8278CF4C:
	// ld r10,1056(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 1056);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lhz r11,1084(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 1084);
	// clrlwi r9,r10,16
	ctx.r9.u64 = ctx.r10.u32 & 0xFFFF;
	// subf r11,r11,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r11.u64;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// subf r4,r11,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r11.u64;
	// bl 0x82799518
	ctx.lr = 0x8278CF6C;
	sub_82799518(ctx, base);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,12(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r11,r31,8
	ctx.r11.s64 = ctx.r31.s64 + 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,8(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// bl 0x82789c80
	ctx.lr = 0x8278CF98;
	sub_82789C80(ctx, base);
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

DEFINE_REX_FUNC(sub_82792338) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82792340;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r3,40
	ctx.r3.s64 = ctx.r3.s64 + 40;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82855b44
	ctx.lr = 0x82792354;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,1188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 1188);
	// lwz r9,20(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r10,r10,0,5,3
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// stw r10,1188(r31)
	REX_STORE_U32(ctx.r31.u32 + 1188, ctx.r10.u32);
	// lwz r30,1048(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 1048);
	// stw r11,1048(r31)
	REX_STORE_U32(ctx.r31.u32 + 1048, ctx.r11.u32);
	// beq cr6,0x827923a8
	if (ctx.cr6.eq) goto loc_827923A8;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bge cr6,0x827923b4
	if (!ctx.cr6.lt) goto loc_827923B4;
	// lwz r10,132(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x827923b4
	if (ctx.cr6.eq) goto loc_827923B4;
	// li r10,3
	ctx.r10.s64 = 3;
	// stw r29,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r29.u32);
	// stb r11,1185(r31)
	REX_STORE_U8(ctx.r31.u32 + 1185, ctx.r11.u8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// stb r11,1184(r31)
	REX_STORE_U8(ctx.r31.u32 + 1184, ctx.r11.u8);
	// bl 0x8278c7b8
	ctx.lr = 0x827923A8;
	sub_8278C7B8(ctx, base);
loc_827923A8:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82789c80
	ctx.lr = 0x827923B0;
	sub_82789C80(ctx, base);
	// b 0x8279241c
	goto loc_8279241C;
loc_827923B4:
	// lwz r11,28(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lbz r3,2(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// bl 0x82793b68
	ctx.lr = 0x827923C0;
	sub_82793B68(ctx, base);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// ble cr6,0x82792410
	if (!ctx.cr6.gt) goto loc_82792410;
	// cmpwi cr6,r3,3
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 3, ctx.xer);
	// beq cr6,0x827923a8
	if (ctx.cr6.eq) goto loc_827923A8;
	// cmpwi cr6,r3,5
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 5, ctx.xer);
	// beq cr6,0x82792400
	if (ctx.cr6.eq) goto loc_82792400;
	// cmpwi cr6,r3,6
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 6, ctx.xer);
	// beq cr6,0x827923a8
	if (ctx.cr6.eq) goto loc_827923A8;
	// cmpwi cr6,r3,7
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 7, ctx.xer);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// beq cr6,0x827923f8
	if (ctx.cr6.eq) goto loc_827923F8;
	// bl 0x8278ecb0
	ctx.lr = 0x827923F4;
	sub_8278ECB0(ctx, base);
	// b 0x8279241c
	goto loc_8279241C;
loc_827923F8:
	// bl 0x8278bf78
	ctx.lr = 0x827923FC;
	sub_8278BF78(ctx, base);
	// b 0x8279241c
	goto loc_8279241C;
loc_82792400:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8278c008
	ctx.lr = 0x8279240C;
	sub_8278C008(ctx, base);
	// b 0x8279241c
	goto loc_8279241C;
loc_82792410:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8278bf20
	ctx.lr = 0x8279241C;
	sub_8278BF20(ctx, base);
loc_8279241C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8278fb08
	ctx.lr = 0x82792424;
	sub_8278FB08(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82789c80
	ctx.lr = 0x8279242C;
	sub_82789C80(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82797060) {
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
	// ld r11,120(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 120);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r4,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bge cr6,0x82797098
	if (!ctx.cr6.lt) goto loc_82797098;
	// bl 0x82748820
	ctx.lr = 0x82797088;
	sub_82748820(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r3,r31,80
	ctx.r3.s64 = ctx.r31.s64 + 80;
	// lwz r4,12(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// bl 0x82795e90
	ctx.lr = 0x82797098;
	sub_82795E90(ctx, base);
loc_82797098:
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

DEFINE_REX_FUNC(sub_82799180) {
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
	// lwz r10,4(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// addi r11,r5,4
	ctx.r11.s64 = ctx.r5.s64 + 4;
	// lwz r9,8(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,8(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r9,4(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,4(r5)
	REX_STORE_U32(ctx.r5.u32 + 4, ctx.r11.u32);
	// stw r11,8(r5)
	REX_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
	// lwz r11,12(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827991f4
	if (ctx.cr6.eq) goto loc_827991F4;
	// lwz r10,204(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// rlwinm. r10,r10,0,5,5
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x827991dc
	if (!ctx.cr0.eq) goto loc_827991DC;
	// lhz r10,76(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 76);
	// andi. r10,r10,65279
	ctx.r10.u64 = ctx.r10.u64 & 65279;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r10,76(r11)
	REX_STORE_U16(ctx.r11.u32 + 76, ctx.r10.u16);
loc_827991DC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,12(r5)
	REX_STORE_U32(ctx.r5.u32 + 12, ctx.r11.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// b 0x82799210
	goto loc_82799210;
loc_827991F4:
	// cmpwi cr6,r6,0
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// beq cr6,0x82799204
	if (ctx.cr6.eq) goto loc_82799204;
	// bl 0x82798c30
	ctx.lr = 0x82799200;
	sub_82798C30(ctx, base);
	// b 0x82799210
	goto loc_82799210;
loc_82799204:
	// lwz r11,200(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 200);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,200(r3)
	REX_STORE_U32(ctx.r3.u32 + 200, ctx.r11.u32);
loc_82799210:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82789c80
	ctx.lr = 0x82799218;
	sub_82789C80(ctx, base);
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

DEFINE_REX_FUNC(sub_8279D1A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8279D1A8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r28,r3,232
	ctx.r28.s64 = ctx.r3.s64 + 232;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x82855b44
	ctx.lr = 0x8279D1C8;
	__imp__RtlEnterCriticalSection(ctx, base);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279ca18
	ctx.lr = 0x8279D1D4;
	sub_8279CA18(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x8279d1e8
	if (!ctx.cr0.eq) goto loc_8279D1E8;
	// lis r31,-32761
	ctx.r31.s64 = -2147024896;
	// ori r31,r31,87
	ctx.r31.u64 = ctx.r31.u64 | 87;
	// b 0x8279d1f8
	goto loc_8279D1F8;
loc_8279D1E8:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x827a1308
	ctx.lr = 0x8279D1F4;
	sub_827A1308(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_8279D1F8:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82855b34
	ctx.lr = 0x8279D200;
	__imp__RtlLeaveCriticalSection(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8279F750) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8279F758;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,44(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// li r25,0
	ctx.r25.s64 = 0;
	// mr r26,r6
	ctx.r26.u64 = ctx.r6.u64;
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// beq cr6,0x8279f7e8
	if (ctx.cr6.eq) goto loc_8279F7E8;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r31,r3,36
	ctx.r31.s64 = ctx.r3.s64 + 36;
	// subf r27,r5,r4
	ctx.r27.u64 = ctx.r4.u64 - ctx.r5.u64;
loc_8279F784:
	// lwz r29,-20(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + -20);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8279F79C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stwx r3,r27,r30
	REX_STORE_U32(ctx.r27.u32 + ctx.r30.u32, ctx.r3.u32);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x8279f7cc
	if (ctx.cr6.eq) goto loc_8279F7CC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8279F7C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r25,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
	// b 0x8279f7d0
	goto loc_8279F7D0;
loc_8279F7CC:
	// stw r25,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r25.u32);
loc_8279F7D0:
	// lwz r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8279f784
	if (ctx.cr6.lt) goto loc_8279F784;
loc_8279F7E8:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827A5798) {
	REX_FUNC_PROLOGUE();
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,-27580(r10)
	REX_STORE_U32(ctx.r10.u32 + -27580, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827A5C40) {
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
	// stwu r1,-3344(r1)
	ea = -3344 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,291
	ctx.r5.s64 = 291;
	// li r4,145
	ctx.r4.s64 = 145;
	// bl 0x827a8338
	ctx.lr = 0x827A5C6C;
	sub_827A8338(ctx, base);
	// li r7,145
	ctx.r7.s64 = 145;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// addi r10,r11,-28032
	ctx.r10.s64 = ctx.r11.s64 + -28032;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// addi r8,r1,1244
	ctx.r8.s64 = ctx.r1.s64 + 1244;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
loc_827A5C88:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// lfs f0,-4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfsu f0,-4(r8)
	ea = -4 + ctx.r8.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r8.u32 = ea;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x827a5c88
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A5C88;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r5,291
	ctx.r5.s64 = 291;
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x827a85e0
	ctx.lr = 0x827A5CD4;
	sub_827A85E0(ctx, base);
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r7,r1,2288
	ctx.r7.s64 = ctx.r1.s64 + 2288;
	// addi r6,r1,1248
	ctx.r6.s64 = ctx.r1.s64 + 1248;
	// li r5,9
	ctx.r5.s64 = 9;
	// li r4,291
	ctx.r4.s64 = 291;
	// lfs f0,-27448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27448);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// bl 0x827a8498
	ctx.lr = 0x827A5CFC;
	sub_827A8498(ctx, base);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// addi r4,r1,2288
	ctx.r4.s64 = ctx.r1.s64 + 2288;
	// addi r3,r1,1248
	ctx.r3.s64 = ctx.r1.s64 + 1248;
	// bl 0x827a7f00
	ctx.lr = 0x827A5D0C;
	sub_827A7F00(ctx, base);
	// addi r1,r1,3344
	ctx.r1.s64 = ctx.r1.s64 + 3344;
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

DEFINE_REX_FUNC(sub_827ACBC0) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// mr r5,r9
	ctx.r5.u64 = ctx.r9.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82855bd4
	ctx.lr = 0x827ACBDC;
	__imp__NtDuplicateObject(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x827acbec
	if (ctx.cr0.lt) goto loc_827ACBEC;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x827acbf4
	goto loc_827ACBF4;
loc_827ACBEC:
	// bl 0x8263bc90
	ctx.lr = 0x827ACBF0;
	sub_8263BC90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_827ACBF4:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ACFA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10600(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10600);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10524(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10524, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD340) {
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
	// lfs f0,22168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10424(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD998) {
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
	// lfs f0,22248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10340(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10340);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE180) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9996(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9824);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9820(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9820, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AEFB8) {
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
	// lfs f0,22648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9680(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9680);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9560(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFC90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,22840
	ctx.r9.s64 = ctx.r11.s64 + 22840;
	// lfs f0,22840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9176(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -9176, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8900);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0FE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1B58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2830) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B32C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7164(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4D80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6780);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6776(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,24008
	ctx.r9.s64 = ctx.r11.s64 + 24008;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6340(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6BB0) {
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
	// lfs f0,24168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5992(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5992);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7F88) {
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
	// lfs f0,24376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9168) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9E70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BAB90) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4012(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BBA38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC9E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-3108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3108);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-3104(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -3104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD198) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2984(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2984);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2880(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BDF40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1628(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1628);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,-2484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BED18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2076(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2076, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BFC30) {
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
	// lfs f0,26200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1620(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0E08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,26504
	ctx.r9.s64 = ctx.r11.s64 + 26504;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,26504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1080(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1080, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3228) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-48(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -48);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-44(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -44, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3E78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,27224
	ctx.r9.s64 = ctx.r11.s64 + 27224;
	// lfs f0,27224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,324(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4CA8) {
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
	// lfs f0,27576(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,696(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 696);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,764(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C70B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2196(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8BC0) {
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
	// lfs f0,28648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2584(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2584);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2668(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,28840
	ctx.r9.s64 = ctx.r11.s64 + 28840;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,28840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3228(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3228, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB2A0) {
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
	// lfs f0,29032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3824(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3824, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CC540) {
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
	// lfs f0,29224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4300(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4300);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4368(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CD7B8) {
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
	// lfs f0,29416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4908(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEA68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,5448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5452(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5452, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CFB50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,5812(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5812);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,5940(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 5940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29884(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29884);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6172(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6172, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,6532(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 6532);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 6640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D21A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7060(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,7460(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7460);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7464(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4018) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,7844(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 7844);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7948(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4E38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8360(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5BF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8764(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6CD8) {
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
	// lfs f0,30888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9136(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9136);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9252(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9252, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7F78) {
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
	// lfs f0,31088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9688(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9688);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D91F8) {
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
	// lfs f0,31304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,10216(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 10216);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10336(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA440) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31496
	ctx.r9.s64 = ctx.r11.s64 + 31496;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10872(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB6E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,11408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11408);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,11412(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC0A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31752
	ctx.r9.s64 = ctx.r11.s64 + 31752;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11692(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD4B8) {
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
	// lfs f0,31944(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31944);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12192(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12192);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12304(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE800) {
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
	// lfs f0,32152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12756(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12756);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12872(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12872, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFAA8) {
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
	// lfs f0,32376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13348);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0C78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1C08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,14412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14416(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2D08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32388(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32388);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14908(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14908, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3C68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4C78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-31976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31976);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,15796(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 15796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5578) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-31148(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31148);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E64E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-29312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16496(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E74C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-27472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,16920(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 16920, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8418) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17348(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17348);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17352(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E92C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-24584
	ctx.r9.s64 = ctx.r11.s64 + -24584;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-24584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18356(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB670) {
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
	// lfs f0,-22536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18720(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18720);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EC8C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,19280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 19280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ED9D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20772(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20772);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEAC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20216(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20216, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF920) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20604(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20608(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20608, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F08C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-18932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F17E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21456(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21456);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2770) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-17892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F3838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f0,-17192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17192);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,22348(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 22348);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,22368(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 22368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5148) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23260(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23260, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6240) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,23792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23792);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,23796(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 23796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6BB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-14688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24060(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7D80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-13716(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13716);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8EA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,24992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24992);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,24996(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 24996, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F97B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,25244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25244);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25248(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA7A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,25700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25700);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,25704(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 25704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FB100) {
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
	// lfs f0,-9688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25852(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25852);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25972(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FC498) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9420(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9420);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26544(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FD298) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26956(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FE160) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,27380(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27380);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,27384(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 27384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEB18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27668(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27668, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FFA50) {
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
	// lfs f0,-8920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28024(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28024);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28112(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800DA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-8728
	ctx.r9.s64 = ctx.r11.s64 + -8728;
	// lfs f0,-8728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28676(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801D08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29124(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29124, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29532);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803C10) {
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
	// lfs f0,-8280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29908);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30028(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30592(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30592, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805D88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31004(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31004);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82806C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-7768
	ctx.r9.s64 = ctx.r11.s64 + -7768;
	// lfs f0,-7768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31444(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 31444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31892(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31892);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808A38) {
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
	// lfs f0,-7448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32264);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32312(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809D70) {
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
	// lfs f0,-7256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32720(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32720);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32664(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32664, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280B0B0) {
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
	// lfs f0,-7064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32168(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32168);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32104(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280C4A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6832);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280D508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31028(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E318) {
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
	// lfs f0,-6424(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6424);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30676(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30676);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30612(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F6E8) {
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
	// lfs f0,-6232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6232);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30124(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30124);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30036(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82810A28) {
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
	// lfs f0,-5976(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5976);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29464(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29464, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28820(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28820, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28436(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813AF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814AD8) {
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
	// lfs f0,-4808(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4808);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27576(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27576);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27492(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815F78) {
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
	// lfs f0,-4520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26884(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26884, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4220(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26328(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26328, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828182E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25816(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819450) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-25308(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25308);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-25304(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -25304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82819C68) {
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
	// lfs f0,-3512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-25128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -25128);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-25060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -25060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B1D0) {
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
	// lfs f0,-3160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24496(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24496);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-23352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23352);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-23348(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -23348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DE50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-2504
	ctx.r9.s64 = ctx.r11.s64 + -2504;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,-2504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23084(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-22500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22500);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-22496(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -22496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281FCC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820D80) {
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
	// lfs f0,-1848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21764(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21764);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21696(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821FB0) {
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
	// lfs f0,-1640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21212);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21164(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823260) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-20624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20620(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828242F0) {
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
	// lfs f0,-1160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20232(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20232);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20120(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828256F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19524);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19520(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19520, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826810) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828276C8) {
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
	// lfs f0,-376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18576(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828A40) {
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
	// lfs f0,-152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-18000(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -18000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829D70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-17448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -17448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17444(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17444, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AE18) {
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
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17068(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17068);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C120) {
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
	// lfs f0,488(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 488);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16504(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16504);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D5C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15792(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15792);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E470) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F4D8) {
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
	// lfs f0,1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14292(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14292);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14288(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832698) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13392(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13392);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13388(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828336E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12904(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12904);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12436(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12436);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835738) {
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
	// lfs f0,2448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12024(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12024);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11936(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82836A60) {
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
	// lfs f0,2680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11464(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11464);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11376(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11376, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837ED8) {
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
	// lfs f0,2928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10832);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10772(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839288) {
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
	// lfs f0,3152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3152);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10260(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10260);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10196(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3408);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-9692(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -9692);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9640(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3628(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3628);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9132(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C5A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D618) {
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
	// lfs f0,3936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8324(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8324);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8224(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8224, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283EA28) {
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
	// lfs f0,4144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4144);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7760(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7760);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7640(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FDD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840DA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,4688
	ctx.r9.s64 = ctx.r11.s64 + 4688;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6592(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6592, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842098) {
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
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6120(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6120);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6036(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828433E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-5476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5476);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5472(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843E30) {
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
	// lfs f0,5272(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5272);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5164(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5164, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845230) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4560(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846230) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4084(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847140) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,5968
	ctx.r9.s64 = ctx.r11.s64 + 5968;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,5968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3648(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848568) {
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
	// lfs f0,6192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3148(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3148);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3044(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-2568(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -2568);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A8F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2012(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2012);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2008(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2008, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B888) {
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
	// lfs f0,6784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1620(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1620);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284CBC0) {
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
	// lfs f0,6992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1060(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1060);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-992(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -992, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284DFC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-488(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -488);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EEC0) {
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
	// lfs f0,7496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-48(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -48);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,60(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 60, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851440) {
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
	// lfs f0,8200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1092(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1092);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1192(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852940) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1796(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1796);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853AB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8868(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8868);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82855568) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8285B6E8) {
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
	// lwz r11,2952(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2952);
	// li r9,1
	ctx.r9.s64 = 1;
	// lwz r10,2112(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 2112);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// addi r8,r11,732
	ctx.r8.s64 = ctx.r11.s64 + 732;
	// lwz r4,248(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r7,r11,735
	ctx.r7.s64 = ctx.r11.s64 + 735;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r10,r10,266
	ctx.r10.s64 = ctx.r10.s64 + 266;
	// add r8,r11,r3
	ctx.r8.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwzx r7,r6,r3
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r7,2904(r3)
	REX_STORE_U32(ctx.r3.u32 + 2904, ctx.r7.u32);
	// lwzx r5,r5,r3
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// stw r5,2916(r3)
	REX_STORE_U32(ctx.r3.u32 + 2916, ctx.r5.u32);
	// lwz r11,2124(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 2124);
	// stw r11,2116(r3)
	REX_STORE_U32(ctx.r3.u32 + 2116, ctx.r11.u32);
	// lwzx r10,r6,r3
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + ctx.r3.u32);
	// stw r10,2120(r3)
	REX_STORE_U32(ctx.r3.u32 + 2120, ctx.r10.u32);
	// stw r9,456(r3)
	REX_STORE_U32(ctx.r3.u32 + 456, ctx.r9.u32);
	// bl 0x826f1178
	ctx.lr = 0x8285B75C;
	sub_826F1178(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826e36e0
	ctx.lr = 0x8285B764;
	sub_826E36E0(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826d7eb0
	ctx.lr = 0x8285B770;
	sub_826D7EB0(ctx, base);
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

DEFINE_REX_FUNC(sub_8287C4B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8287C4B8;
	__savegprlr_28(ctx, base);
	// stwu r1,-896(r1)
	ea = -896 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r7,1
	ctx.r11.s64 = ctx.r7.s64 + 1;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// rlwinm r28,r11,3,0,28
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82873f18
	ctx.lr = 0x8287C4E0;
	sub_82873F18(ctx, base);
	// li r10,1104
	ctx.r10.s64 = 1104;
	// mr r7,r28
	ctx.r7.u64 = ctx.r28.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lvx128 v1,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8287b580
	ctx.lr = 0x8287C500;
	sub_8287B580(ctx, base);
	// addi r1,r1,896
	ctx.r1.s64 = ctx.r1.s64 + 896;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8287FA48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// lwz r9,1144(r7)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r7.u32 + 1144);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// li r7,2
	ctx.r7.s64 = 2;
	// lwz r9,228(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 228);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// vspltish v1,4
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_set1_epi16(short(0x4)));
	// slw r7,r7,r10
	ctx.r7.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r7.u32 << (ctx.r10.u8 & 0x3F));
	// subf r3,r11,r3
	ctx.r3.u64 = ctx.r3.u64 - ctx.r11.u64;
	// lvx128 v0,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// vsplth v2,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// bl 0x828773b0
	ctx.lr = 0x8287FA8C;
	sub_828773B0(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8288B2B0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8288B2B8;
	__savegprlr_26(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r8,r4
	ctx.r8.u64 = ctx.r4.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// dcbzl r0,r7
	ea = (ctx.r7.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// lwz r11,24(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 24);
	// subfic r27,r5,2
	ctx.xer.ca = ctx.r5.u32 <= 2;
	ctx.r27.u64 = static_cast<uint64_t>(2) - ctx.r5.u64;
	// lwz r4,624(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 624);
	// addi r5,r3,168
	ctx.r5.s64 = ctx.r3.s64 + 168;
	// addi r26,r11,1
	ctx.r26.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r30,4(r8)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r31,40(r6)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r6.u32 + 40);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 20);
	// stw r26,24(r6)
	REX_STORE_U32(ctx.r6.u32 + 24, ctx.r26.u32);
	// dcbzl r0,r31
	ea = (ctx.r31.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r29,128
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 128, ctx.xer);
	// blt cr6,0x8288b31c
	if (ctx.cr6.lt) goto loc_8288B31C;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r8
	ctx.r6.u64 = ctx.r8.u64;
	// bl 0x826d4738
	ctx.lr = 0x8288B314;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8288b374
	goto loc_8288B374;
loc_8288B31C:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// ble cr6,0x8288b370
	if (!ctx.cr6.gt) goto loc_8288B370;
	// mtctr r29
	ctx.ctr.u64 = ctx.r29.u64;
loc_8288B328:
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r29,r3,24,8,31
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r29,r7
	ctx.r8.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r7.s32);
	// lbzx r29,r10,r4
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r26,r29,r5
	ctx.r26.u64 = REX_LOAD_U8(ctx.r29.u32 + ctx.r5.u32);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// neg r3,r3
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// rotlwi r29,r29,1
	ctx.r29.u64 = __builtin_rotateleft32(ctx.r29.u32, 1);
	// xor r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// or r9,r26,r9
	ctx.r9.u64 = ctx.r26.u64 | ctx.r9.u64;
	// subf r3,r3,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r3.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r3,r29,r31
	REX_STORE_U16(ctx.r29.u32 + ctx.r31.u32, ctx.r3.u16);
	// bdnz 0x8288b328
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8288B328;
loc_8288B370:
	// stw r11,20(r6)
	REX_STORE_U32(ctx.r6.u32 + 20, ctx.r11.u32);
loc_8288B374:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// rlwinm r11,r27,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 3) & 0xFFFFFFF8;
	// bne cr6,0x8288b3e8
	if (!ctx.cr6.eq) goto loc_8288B3E8;
	// lhz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r9,r10,4
	ctx.r9.s64 = ctx.r10.s64 + 4;
	// srawi r10,r9,3
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7) != 0);
	ctx.r10.s64 = ctx.r9.s32 >> 3;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// addi r8,r10,16
	ctx.r8.s64 = ctx.r10.s64 + 16;
	// srawi r7,r8,5
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1F) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 5;
	// clrlwi r6,r7,16
	ctx.r6.u64 = ctx.r7.u32 & 0xFFFF;
	// rlwinm r5,r6,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000;
	// or r4,r5,r6
	ctx.r4.u64 = ctx.r5.u64 | ctx.r6.u64;
	// rldicr r3,r4,32,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// std r10,112(r11)
	REX_STORE_U64(ctx.r11.u32 + 112, ctx.r10.u64);
	// std r10,96(r11)
	REX_STORE_U64(ctx.r11.u32 + 96, ctx.r10.u64);
	// std r10,80(r11)
	REX_STORE_U64(ctx.r11.u32 + 80, ctx.r10.u64);
	// std r10,64(r11)
	REX_STORE_U64(ctx.r11.u32 + 64, ctx.r10.u64);
	// std r10,48(r11)
	REX_STORE_U64(ctx.r11.u32 + 48, ctx.r10.u64);
	// std r10,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r10.u64);
	// std r10,16(r11)
	REX_STORE_U64(ctx.r11.u32 + 16, ctx.r10.u64);
	// std r10,0(r11)
	REX_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_8288B3E8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// add r4,r11,r28
	ctx.r4.u64 = ctx.r11.u64 + ctx.r28.u64;
	// bl 0x82870e08
	ctx.lr = 0x8288B3F4;
	sub_82870E08(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82890AC8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82890AD0;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r30,r3,15952
	ctx.r30.s64 = ctx.r3.s64 + 15952;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8288e628
	ctx.lr = 0x82890AE4;
	sub_8288E628(ctx, base);
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,-13816(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + -13816);
	// bl 0x82893f28
	ctx.lr = 0x82890AF8;
	sub_82893F28(ctx, base);
	// lhz r10,16004(r31)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// addi r29,r31,17360
	ctx.r29.s64 = ctx.r31.s64 + 17360;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rlwinm r8,r10,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// bl 0x8288e798
	ctx.lr = 0x82890B1C;
	sub_8288E798(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82890bcc
	if (!ctx.cr6.eq) goto loc_82890BCC;
	// lhz r11,16004(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 16004);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r8,r11,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8288de00
	ctx.lr = 0x82890B44;
	sub_8288DE00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82890bcc
	if (!ctx.cr6.eq) goto loc_82890BCC;
	// lwz r11,3916(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82890bb4
	if (ctx.cr6.eq) goto loc_82890BB4;
	// lwz r11,208(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 208);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r10,204(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 204);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r3,17320(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 17320);
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// srawi r29,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r29.s64 = ctx.r10.s32 >> 1;
	// lwz r10,224(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// mullw r11,r9,r3
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r3.s32);
	// lwz r6,3748(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// lwz r30,3744(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mullw r3,r29,r3
	ctx.r3.s64 = int64_t(ctx.r29.s32) * int64_t(ctx.r3.s32);
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r6,r6,r10
	ctx.r6.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r10,r3,r30
	ctx.r10.u64 = ctx.r3.u64 + ctx.r30.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826d4ce0
	ctx.lr = 0x82890BB4;
	sub_826D4CE0(ctx, base);
loc_82890BB4:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82894270
	ctx.lr = 0x82890BC0;
	sub_82894270(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,15596(r31)
	REX_STORE_U32(ctx.r31.u32 + 15596, ctx.r11.u32);
loc_82890BCC:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82893E50) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// vspltish v0,15
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0xF)));
	// cmpwi cr6,r4,32
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 32, ctx.xer);
	// vslb v0,v0,v0
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi8(0x7));
		simde_mm_store_si128((simde__m128i*)ctx.v0.u8, rex::ppc::simde_mm_sllv_epi8(a, shift));
	}
	// beq cr6,0x82893ee8
	if (ctx.cr6.eq) goto loc_82893EE8;
	// cmpwi cr6,r4,64
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 64, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// lvx128 v13,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// vaddshs v12,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// addi r8,r3,64
	ctx.r8.s64 = ctx.r3.s64 + 64;
	// addi r7,r3,80
	ctx.r7.s64 = ctx.r3.s64 + 80;
	// addi r6,r3,96
	ctx.r6.s64 = ctx.r3.s64 + 96;
	// lvx128 v11,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r3,112
	ctx.r5.s64 = ctx.r3.s64 + 112;
	// lvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v8,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v7,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v6,v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v5,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v4,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v4.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v3,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v2,v7,v0
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v1,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v31,v5,v0
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v30,v3,v0
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v8,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v29,v1,v0
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v6,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v4,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v31,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v29,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
loc_82893EE8:
	// addi r11,r3,16
	ctx.r11.s64 = ctx.r3.s64 + 16;
	// lvx128 v13,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r3,32
	ctx.r10.s64 = ctx.r3.s64 + 32;
	// vaddshs v12,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// addi r9,r3,48
	ctx.r9.s64 = ctx.r3.s64 + 48;
	// lvx128 v11,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v9,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v8,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v7,v10,v0
	simde_mm_store_si128((simde__m128i*)ctx.v7.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v6,v8,v0
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// stvx128 v12,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v9,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v7,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v6,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// blr 
	return;
}

