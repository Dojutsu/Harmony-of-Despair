#include "harmonyrecomp_funcs.65.h"

DEFINE_REX_FUNC(sub_822152F8) {
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
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// bl 0x82215ed0
	ctx.lr = 0x82215320;
	sub_82215ED0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82215358
	if (!ctx.cr0.eq) goto loc_82215358;
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82215e00
	ctx.lr = 0x82215334;
	sub_82215E00(ctx, base);
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82215358
	if (ctx.cr6.eq) goto loc_82215358;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r4,0(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// bl 0x82216598
	ctx.lr = 0x82215358;
	sub_82216598(ctx, base);
loc_82215358:
	// li r3,0
	ctx.r3.s64 = 0;
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

DEFINE_REX_FUNC(sub_8221D0E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x8221D0E8;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,112(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 112);
	// li r21,1
	ctx.r21.s64 = 1;
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// stb r21,164(r3)
	REX_STORE_U8(ctx.r3.u32 + 164, ctx.r21.u8);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x8221d4c8
	if (!ctx.cr6.eq) goto loc_8221D4C8;
	// lwz r31,4(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8221d4c8
	if (ctx.cr6.eq) goto loc_8221D4C8;
	// lis r22,-32226
	ctx.r22.s64 = -2111963136;
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r24,0
	ctx.r24.s64 = 0;
	// rlwinm. r10,r11,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f31,-8644(r22)
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -8644);
	ctx.f31.f64 = double(temp.f32);
	// li r23,0
	ctx.r23.s64 = 0;
	// li r25,0
	ctx.r25.s64 = 0;
	// li r27,0
	ctx.r27.s64 = 0;
	// beq 0x8221d1f4
	if (ctx.cr0.eq) goto loc_8221D1F4;
	// lwz r30,44(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221d4c8
	if (ctx.cr6.eq) goto loc_8221D4C8;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
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
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// lwz r23,84(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r24,84(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x824321a8
	ctx.lr = 0x8221D1CC;
	sub_824321A8(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r10,2
	ctx.r10.s64 = 2;
	// lwz r4,92(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// subfic r11,r11,0
	ctx.xer.ca = ctx.r11.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r11.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r25,r11,r10
	ctx.r25.u64 = ctx.r11.u64 & ctx.r10.u64;
	// bl 0x823bfa70
	ctx.lr = 0x8221D1EC;
	sub_823BFA70(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// b 0x8221d47c
	goto loc_8221D47C;
loc_8221D1F4:
	// rlwinm. r11,r11,30,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221d4c8
	if (ctx.cr0.eq) goto loc_8221D4C8;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// addi r26,r31,260
	ctx.r26.s64 = ctx.r31.s64 + 260;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221d21c
	if (!ctx.cr0.eq) goto loc_8221D21C;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8221d238
	goto loc_8221D238;
loc_8221D21C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221D234;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8221D238:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221d330
	if (ctx.cr6.eq) goto loc_8221D330;
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221d260
	if (!ctx.cr0.eq) goto loc_8221D260;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8221d278
	goto loc_8221D278;
loc_8221D260:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221D278;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8221D278:
	// lbz r11,84(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 84);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8221d330
	if (ctx.cr0.eq) goto loc_8221D330;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8221d330
	if (ctx.cr0.eq) goto loc_8221D330;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x8221D2A0;
	sub_8222FF78(ctx, base);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f0,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r23,84(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bne 0x8221d2dc
	if (!ctx.cr0.eq) goto loc_8221D2DC;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8221d2f8
	goto loc_8221D2F8;
loc_8221D2DC:
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
	ctx.lr = 0x8221D2F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8221D2F8:
	// lwz r11,8(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r10,4(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221d314
	if (!ctx.cr0.eq) goto loc_8221D314;
	// li r27,-1
	ctx.r27.s64 = -1;
	// b 0x8221d32c
	goto loc_8221D32C;
loc_8221D314:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r4,8(r11)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r11.u32 + 8);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x8221D328;
	sub_823BFA70(ctx, base);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8221D32C:
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
loc_8221D330:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221d41c
	if (!ctx.cr0.eq) goto loc_8221D41C;
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// addi r29,r31,244
	ctx.r29.s64 = ctx.r31.s64 + 244;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221d358
	if (!ctx.cr0.eq) goto loc_8221D358;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x8221d41c
	goto loc_8221D41C;
loc_8221D358:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 152);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221D370;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8221d41c
	if (ctx.cr0.eq) goto loc_8221D41C;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x8221D38C;
	sub_8222FF78(ctx, base);
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r23,100(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bne 0x8221d3c8
	if (!ctx.cr0.eq) goto loc_8221D3C8;
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x8221d3e4
	goto loc_8221D3E4;
loc_8221D3C8:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221D3E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
loc_8221D3E4:
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// lwz r10,4(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8221d400
	if (!ctx.cr0.eq) goto loc_8221D400;
	// li r27,-1
	ctx.r27.s64 = -1;
	// b 0x8221d41c
	goto loc_8221D41C;
loc_8221D400:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8221D418;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
loc_8221D41C:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,-8644(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// fmr f13,f0
	ctx.f13.f64 = ctx.f0.f64;
	// lwz r9,8(r26)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r8,4(r26)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r26.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lhz r7,6(r31)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r11,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 2;
	// extsw r9,r7
	ctx.r9.s64 = ctx.r7.s32;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f31,f12,f13,f0
	ctx.f31.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
loc_8221D47C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8221d4c8
	if (ctx.cr6.eq) goto loc_8221D4C8;
	// lfs f0,40(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi r11,r27,16
	ctx.r11.u64 = ctx.r27.u32 & 0xFFFF;
	// stfs f0,128(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 128, temp.u32);
	// lfs f0,44(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 132, temp.u32);
	// lfs f0,56(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 56);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,136(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 136, temp.u32);
	// lfs f0,96(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,140(r28)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r28.u32 + 140, temp.u32);
	// lwz r10,120(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 120);
	// stw r11,148(r28)
	REX_STORE_U32(ctx.r28.u32 + 148, ctx.r11.u32);
	// stw r24,152(r28)
	REX_STORE_U32(ctx.r28.u32 + 152, ctx.r24.u32);
	// stw r23,156(r28)
	REX_STORE_U32(ctx.r28.u32 + 156, ctx.r23.u32);
	// stw r25,160(r28)
	REX_STORE_U32(ctx.r28.u32 + 160, ctx.r25.u32);
	// stw r10,144(r28)
	REX_STORE_U32(ctx.r28.u32 + 144, ctx.r10.u32);
	// stb r21,164(r28)
	REX_STORE_U8(ctx.r28.u32 + 164, ctx.r21.u8);
loc_8221D4C8:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822470A8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822470B0;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r31,r3,1
	ctx.r31.s64 = ctx.r3.s64 + 65536;
	// addi r31,r31,-3100
	ctx.r31.s64 = ctx.r31.s64 + -3100;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,424(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822470D0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,52
	ctx.r11.s64 = 52;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822471c4
	if (ctx.cr0.eq) goto loc_822471C4;
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,424(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822470FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,424(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 424);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224711C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r28,8(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x822471c4
	if (ctx.cr6.eq) goto loc_822471C4;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8224712C:
	// lwz r30,44(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x822471b8
	if (ctx.cr6.eq) goto loc_822471B8;
	// lbz r11,49(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 49);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822471b8
	if (ctx.cr0.eq) goto loc_822471B8;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x82247150;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822471b8
	if (ctx.cr0.eq) goto loc_822471B8;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82247164;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822471b8
	if (ctx.cr0.eq) goto loc_822471B8;
	// lbz r11,50(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 50);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8224718c
	if (!ctx.cr0.eq) goto loc_8224718C;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r29,84(r3)
	REX_STORE_U8(ctx.r3.u32 + 84, ctx.r29.u8);
	// stb r29,85(r3)
	REX_STORE_U8(ctx.r3.u32 + 85, ctx.r29.u8);
	// stb r11,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r11.u8);
	// b 0x822471b8
	goto loc_822471B8;
loc_8224718C:
	// lwz r11,96(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 96);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x822471b8
	if (!ctx.cr6.eq) goto loc_822471B8;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x822471A4;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stb r29,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r29.u8);
	// stw r11,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r11.u32);
	// stb r29,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r29.u8);
	// stb r29,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r29.u8);
loc_822471B8:
	// addi r31,r31,52
	ctx.r31.s64 = ctx.r31.s64 + 52;
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x8224712c
	if (!ctx.cr6.eq) goto loc_8224712C;
loc_822471C4:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8224E108) {
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
	// bl 0x82231670
	ctx.lr = 0x8224E120;
	sub_82231670(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12964(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8224e154
	if (ctx.cr6.eq) goto loc_8224E154;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,576(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 576);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// beq cr6,0x8224e154
	if (ctx.cr6.eq) goto loc_8224E154;
	// lfs f12,152(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
	// stfs f13,576(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 576, temp.u32);
loc_8224E154:
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

DEFINE_REX_FUNC(sub_82250AF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82250AF8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f12,f1
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f1.f64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r30,-3032
	ctx.r30.s64 = ctx.r30.s64 + -3032;
	// li r29,0
	ctx.r29.s64 = 0;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82250b2c
	if (ctx.cr0.eq) goto loc_82250B2C;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,10
	ctx.r4.s64 = 10;
	// bl 0x8224f2d8
	ctx.lr = 0x82250B28;
	sub_8224F2D8(ctx, base);
	// stb r29,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r29.u8);
loc_82250B2C:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r11,r11,-3060
	ctx.r11.s64 = ctx.r11.s64 + -3060;
	// lfs f13,-6412(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82250b50
	if (!ctx.cr6.lt) goto loc_82250B50;
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// b 0x82250be0
	goto loc_82250BE0;
loc_82250B50:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// addi r10,r10,-2955
	ctx.r10.s64 = ctx.r10.s64 + -2955;
	// lbz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq 0x82250bac
	if (ctx.cr0.eq) goto loc_82250BAC;
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// stb r29,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r29.u8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r9,r9,-3040
	ctx.r9.s64 = ctx.r9.s64 + -3040;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// ori r10,r10,62580
	ctx.r10.u64 = ctx.r10.u64 | 62580;
	// ori r8,r8,62500
	ctx.r8.u64 = ctx.r8.u64 | 62500;
	// lwz r6,0(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lis r5,-32219
	ctx.r5.s64 = -2111504384;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r5,r5,3056
	ctx.r5.s64 = ctx.r5.s64 + 3056;
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stbx r29,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r29.u8);
	// stw r5,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
	// stb r4,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r4.u8);
	// stwx r6,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r6.u32);
	// b 0x82250be0
	goto loc_82250BE0;
loc_82250BAC:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r9,0
	ctx.r9.s64 = 0;
	// addi r10,r10,-3040
	ctx.r10.s64 = ctx.r10.s64 + -3040;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// ori r9,r9,62500
	ctx.r9.u64 = ctx.r9.u64 | 62500;
	// lis r7,-32219
	ctx.r7.s64 = -2111504384;
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r7,r7,-1440
	ctx.r7.s64 = ctx.r7.s64 + -1440;
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stb r5,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r5.u8);
	// stw r7,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stwx r6,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r6.u32);
loc_82250BE0:
	// stfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8225EA68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8225EA70;
	__savegprlr_29(ctx, base);
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f29.u64);
	// stfd f30,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// lwz r11,248(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f29,f1
	ctx.f29.f64 = ctx.f1.f64;
	// addi r30,r30,-2744
	ctx.r30.s64 = ctx.r30.s64 + -2744;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f0.f64));
	// stfs f0,0(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 0, temp.u32);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EAB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,112(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 112);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EAD4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EAF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EB0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,176(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 176);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EB28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f1,-5828(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5828);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EB48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f1,-5836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5836);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EB68;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f1,-5832(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5832);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EB88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r11,1608
	ctx.r29.s64 = ctx.r11.s64 + 1608;
	// lfs f31,24420(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 24420);
	ctx.f31.f64 = double(temp.f32);
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x82738be0
	ctx.lr = 0x8225EBA0;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
	// lfs f30,-32216(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f30.f64 = double(temp.f32);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,248(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r3,4(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EC10;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r4,r1,104
	ctx.r4.s64 = ctx.r1.s64 + 104;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EC2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f0,-4(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// ori r11,r11,62808
	ctx.r11.u64 = ctx.r11.u64 | 62808;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f13,24208(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24208);
	ctx.f13.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// addi r10,r8,-4080
	ctx.r10.s64 = ctx.r8.s64 + -4080;
	// lfs f12,-5868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5868);
	ctx.f12.f64 = double(temp.f32);
	// ori r8,r7,62812
	ctx.r8.u64 = ctx.r7.u64 | 62812;
	// lfs f11,892(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 892);
	ctx.f11.f64 = double(temp.f32);
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lfs f12,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f1,f12,f31
	ctx.f1.f64 = double(float(ctx.f12.f64 * ctx.f31.f64));
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fmuls f0,f31,f11
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f11.f64));
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// bl 0x82738be0
	ctx.lr = 0x8225EC80;
	sub_82738BE0(ctx, base);
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lwz r7,248(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r3,12(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225ECF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-2736
	ctx.r30.s64 = ctx.r30.s64 + -2736;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8225ef14
	if (ctx.cr6.lt) goto loc_8225EF14;
	// beq cr6,0x8225ee3c
	if (ctx.cr6.eq) goto loc_8225EE3C;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8225ee04
	if (ctx.cr6.lt) goto loc_8225EE04;
	// bne cr6,0x8225efdc
	if (!ctx.cr6.eq) goto loc_8225EFDC;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r11,r11,62796
	ctx.r11.u64 = ctx.r11.u64 | 62796;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225ED48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,-20940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f0,f29,f0,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f29.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// bge cr6,0x8225eda8
	if (!ctx.cr6.lt) goto loc_8225EDA8;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// b 0x8225edd4
	goto loc_8225EDD4;
loc_8225EDA8:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8225edcc
	if (ctx.cr6.eq) goto loc_8225EDCC;
loc_8225EDB0:
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stb r10,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r10.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// b 0x8225efd4
	goto loc_8225EFD4;
loc_8225EDCC:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,12(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
loc_8225EDD4:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// stb r29,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r29.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EDF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stw r29,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r29.u32);
	// ori r11,r11,62804
	ctx.r11.u64 = ctx.r11.u64 | 62804;
	// stwx r29,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r29.u32);
	// b 0x8225efdc
	goto loc_8225EFDC;
loc_8225EE04:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,-2740
	ctx.r11.s64 = ctx.r11.s64 + -2740;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f29,f13
	ctx.f13.f64 = double(float(ctx.f29.f64 + ctx.f13.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8225efdc
	if (!ctx.cr6.gt) goto loc_8225EFDC;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r9,3
	ctx.r9.s64 = 3;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// lfs f0,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// b 0x8225efdc
	goto loc_8225EFDC;
loc_8225EE3C:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// ori r11,r11,62796
	ctx.r11.u64 = ctx.r11.u64 | 62796;
	// addi r3,r1,100
	ctx.r3.s64 = ctx.r1.s64 + 100;
	// lfs f0,12468(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// lwz r4,12(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,144(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 144);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EE6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,-20940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20940);
	ctx.f0.f64 = double(temp.f32);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmadds f0,f29,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f29.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// ble cr6,0x8225eedc
	if (!ctx.cr6.gt) goto loc_8225EEDC;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// b 0x8225efd4
	goto loc_8225EFD4;
loc_8225EEDC:
	// cmplwi cr6,r10,255
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 255, ctx.xer);
	// blt cr6,0x8225edb0
	if (ctx.cr6.lt) goto loc_8225EDB0;
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lwz r3,12(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bctrl 
	ctx.lr = 0x8225EF04;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// b 0x8225efdc
	goto loc_8225EFDC;
loc_8225EF14:
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r11,255
	ctx.r11.s64 = 255;
	// li r9,0
	ctx.r9.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lwz r3,12(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// stb r9,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r9.u8);
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,140(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 140);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EF48;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62804
	ctx.r11.u64 = ctx.r11.u64 | 62804;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8225efdc
	if (ctx.cr6.eq) goto loc_8225EFDC;
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// clrlwi r4,r11,16
	ctx.r4.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EF88;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,32(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EFA4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r30,12(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EFC8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_8225EFD4:
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8225EFDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8225EFDC:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
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

DEFINE_REX_FUNC(sub_82297640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82297648;
	__savegprlr_27(ctx, base);
	// stfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f31.u64);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// bl 0x82297418
	ctx.lr = 0x82297664;
	sub_82297418(ctx, base);
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r30,1
	ctx.r30.s64 = 1;
	// bl 0x824281d8
	ctx.lr = 0x82297670;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r4,0
	ctx.r4.s64 = 0;
	// beq 0x822976a4
	if (ctx.cr0.eq) goto loc_822976A4;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x8223e768
	ctx.lr = 0x82297688;
	sub_8223E768(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822976a0
	if (ctx.cr0.eq) goto loc_822976A0;
	// lfs f0,556(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 556);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,556(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 556, temp.u32);
	// b 0x822976a4
	goto loc_822976A4;
loc_822976A0:
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
loc_822976A4:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822976b8
	if (ctx.cr0.eq) goto loc_822976B8;
	// lfs f0,152(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 152);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stfs f0,152(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 152, temp.u32);
loc_822976B8:
	// fctiwz f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f31.f64) ? int64_t(0x80000000U) : (ctx.f31.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f31.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stw r4,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r4.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r4,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r4.u32);
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r6,r31,196
	ctx.r6.s64 = ctx.r31.s64 + 196;
	// lfs f2,176(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 176);
	ctx.f2.f64 = double(temp.f32);
	// lwa r5,24(r11)
	ctx.r5.s64 = int32_t(REX_LOAD_U32(ctx.r11.u32 + 24));
	// lfs f3,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f3.f64 = double(temp.f32);
	// lwz r28,4(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// lwz r30,116(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// frsp f1,f0
	ctx.f1.f64 = double(float(ctx.f0.f64));
	// bl 0x822178a8
	ctx.lr = 0x82297714;
	sub_822178A8(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x823b2da0
	ctx.lr = 0x82297720;
	sub_823B2DA0(ctx, base);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82297778
	if (ctx.cr6.eq) goto loc_82297778;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r11,r11,32752
	ctx.r11.s64 = ctx.r11.s64 + 32752;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f0,104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// bl 0x8258c108
	ctx.lr = 0x82297778;
	sub_8258C108(ctx, base);
loc_82297778:
	// lwz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 192);
	// li r7,-1
	ctx.r7.s64 = -1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8229778c
	if (ctx.cr6.eq) goto loc_8229778C;
	// lhz r7,74(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 74);
loc_8229778C:
	// addi r8,r31,436
	ctx.r8.s64 = ctx.r31.s64 + 436;
	// lwz r5,220(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r3,r1,104
	ctx.r3.s64 = ctx.r1.s64 + 104;
	// bl 0x82218a48
	ctx.lr = 0x822977A4;
	sub_82218A48(ctx, base);
	// bl 0x824281d8
	ctx.lr = 0x822977A8;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82297854
	if (ctx.cr0.eq) goto loc_82297854;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x8223e768
	ctx.lr = 0x822977BC;
	sub_8223E768(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82297854
	if (ctx.cr0.eq) goto loc_82297854;
	// cmpwi cr6,r27,1
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 1, ctx.xer);
	// bne cr6,0x822977d4
	if (!ctx.cr6.eq) goto loc_822977D4;
	// li r30,2
	ctx.r30.s64 = 2;
	// b 0x822977f0
	goto loc_822977F0;
loc_822977D4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// bne cr6,0x822977e4
	if (!ctx.cr6.eq) goto loc_822977E4;
	// li r30,3
	ctx.r30.s64 = 3;
	// b 0x822977f0
	goto loc_822977F0;
loc_822977E4:
	// cmpwi cr6,r27,2
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 2, ctx.xer);
	// bne cr6,0x82297878
	if (!ctx.cr6.eq) goto loc_82297878;
	// li r30,4
	ctx.r30.s64 = 4;
loc_822977F0:
	// bl 0x82429a18
	ctx.lr = 0x822977F4;
	sub_82429A18(ctx, base);
	// lis r11,-32241
	ctx.r11.s64 = -2112946176;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,63380
	ctx.r10.u64 = ctx.r10.u64 | 63380;
	// addi r4,r4,-2160
	ctx.r4.s64 = ctx.r4.s64 + -2160;
	// lfs f0,20068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20068);
	ctx.f0.f64 = double(temp.f32);
	// clrlwi r9,r30,24
	ctx.r9.u64 = ctx.r30.u32 & 0xFF;
	// fmuls f0,f1,f0
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// sth r9,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r9.u16);
	// addi r11,r27,15659
	ctx.r11.s64 = ctx.r27.s64 + 15659;
	// lis r9,0
	ctx.r9.s64 = 0;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r9,r9,63404
	ctx.r9.u64 = ctx.r9.u64 | 63404;
	// li r6,-1
	ctx.r6.s64 = -1;
	// li r5,44
	ctx.r5.s64 = 44;
	// li r3,10
	ctx.r3.s64 = 10;
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r8,116(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// lfsx f0,r11,r31
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfiwx f0,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.f0.u32);
	// bl 0x82429ff8
	ctx.lr = 0x82297854;
	sub_82429FF8(ctx, base);
loc_82297854:
	// addi r11,r27,15659
	ctx.r11.s64 = ctx.r27.s64 + 15659;
	// addi r10,r27,15662
	ctx.r10.s64 = ctx.r27.s64 + 15662;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f13,r11,r31
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfsx f0,r10,r31
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82297878
	if (ctx.cr6.lt) goto loc_82297878;
	// stfsx f0,r11,r31
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, temp.u32);
loc_82297878:
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// lfd f31,-56(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A7018) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef0
	ctx.lr = 0x822A7020;
	__savegprlr_18(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r25,r11,9464
	ctx.r25.s64 = ctx.r11.s64 + 9464;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// bl 0x8222fa58
	ctx.lr = 0x822A7038;
	sub_8222FA58(ctx, base);
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,-32240
	ctx.r4.s64 = -2112880640;
	// ori r5,r5,62420
	ctx.r5.u64 = ctx.r5.u64 | 62420;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f0,12468(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// stfsx f0,r31,r5
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, temp.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,62376
	ctx.r10.u64 = ctx.r10.u64 | 62376;
	// ori r9,r9,62380
	ctx.r9.u64 = ctx.r9.u64 | 62380;
	// ori r8,r8,62384
	ctx.r8.u64 = ctx.r8.u64 | 62384;
	// ori r7,r7,62388
	ctx.r7.u64 = ctx.r7.u64 | 62388;
	// lis r3,-32226
	ctx.r3.s64 = -2111963136;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// ori r6,r6,62392
	ctx.r6.u64 = ctx.r6.u64 | 62392;
	// addi r28,r28,-3092
	ctx.r28.s64 = ctx.r28.s64 + -3092;
	// stfsx f0,r31,r8
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, temp.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r5,r3,9600
	ctx.r5.s64 = ctx.r3.s64 + 9600;
	// li r26,1
	ctx.r26.s64 = 1;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// li r29,-1
	ctx.r29.s64 = -1;
	// stw r5,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// stwx r30,r31,r7
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u32);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stbx r30,r31,r10
	REX_STORE_U8(ctx.r31.u32 + ctx.r10.u32, ctx.r30.u8);
	// lis r4,0
	ctx.r4.s64 = 0;
	// stwx r26,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r26.u32);
	// lis r27,0
	ctx.r27.s64 = 0;
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// ori r8,r8,62452
	ctx.r8.u64 = ctx.r8.u64 | 62452;
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// ori r5,r4,64092
	ctx.r5.u64 = ctx.r4.u64 | 64092;
	// stw r29,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r29.u32);
	// ori r9,r27,64096
	ctx.r9.u64 = ctx.r27.u64 | 64096;
	// lis r7,0
	ctx.r7.s64 = 0;
	// stbx r30,r31,r8
	REX_STORE_U8(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u8);
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ori r8,r7,64100
	ctx.r8.u64 = ctx.r7.u64 | 64100;
	// stwx r30,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// lis r4,0
	ctx.r4.s64 = 0;
	// lis r3,0
	ctx.r3.s64 = 0;
	// lis r27,0
	ctx.r27.s64 = 0;
	// lis r24,0
	ctx.r24.s64 = 0;
	// lis r23,0
	ctx.r23.s64 = 0;
	// lis r22,0
	ctx.r22.s64 = 0;
	// lis r21,0
	ctx.r21.s64 = 0;
	// lis r20,0
	ctx.r20.s64 = 0;
	// lis r19,0
	ctx.r19.s64 = 0;
	// ori r18,r10,64108
	ctx.r18.u64 = ctx.r10.u64 | 64108;
	// ld r10,3456(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// ori r9,r9,64116
	ctx.r9.u64 = ctx.r9.u64 | 64116;
	// stdx r10,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r10.u64);
	// ori r7,r7,64120
	ctx.r7.u64 = ctx.r7.u64 | 64120;
	// ori r5,r5,64124
	ctx.r5.u64 = ctx.r5.u64 | 64124;
	// ori r4,r4,64132
	ctx.r4.u64 = ctx.r4.u64 | 64132;
	// ori r3,r3,64136
	ctx.r3.u64 = ctx.r3.u64 | 64136;
	// ori r27,r27,64140
	ctx.r27.u64 = ctx.r27.u64 | 64140;
	// ori r24,r24,64144
	ctx.r24.u64 = ctx.r24.u64 | 64144;
	// ori r23,r23,64148
	ctx.r23.u64 = ctx.r23.u64 | 64148;
	// ori r22,r22,64156
	ctx.r22.u64 = ctx.r22.u64 | 64156;
	// ori r21,r21,64160
	ctx.r21.u64 = ctx.r21.u64 | 64160;
	// ori r20,r20,64161
	ctx.r20.u64 = ctx.r20.u64 | 64161;
	// ori r19,r19,64180
	ctx.r19.u64 = ctx.r19.u64 | 64180;
	// ld r10,2880(r6)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r6.u32 + 2880);
	// lis r8,0
	ctx.r8.s64 = 0;
	// stwx r30,r31,r9
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u32);
	// lis r9,0
	ctx.r9.s64 = 0;
	// stbx r30,r31,r7
	REX_STORE_U8(ctx.r31.u32 + ctx.r7.u32, ctx.r30.u8);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lis r6,0
	ctx.r6.s64 = 0;
	// ori r8,r8,64184
	ctx.r8.u64 = ctx.r8.u64 | 64184;
	// stdx r10,r31,r18
	REX_STORE_U64(ctx.r31.u32 + ctx.r18.u32, ctx.r10.u64);
	// lis r18,0
	ctx.r18.s64 = 0;
	// ld r10,3456(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// stfsx f0,r31,r4
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, temp.u32);
	// stdx r10,r31,r5
	REX_STORE_U64(ctx.r31.u32 + ctx.r5.u32, ctx.r10.u64);
	// lis r4,-32228
	ctx.r4.s64 = -2112094208;
	// lis r5,0
	ctx.r5.s64 = 0;
	// stbx r30,r31,r3
	REX_STORE_U8(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u8);
	// lfs f13,11948(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 11948);
	ctx.f13.f64 = double(temp.f32);
	// ori r3,r9,64228
	ctx.r3.u64 = ctx.r9.u64 | 64228;
	// stwx r30,r31,r27
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, ctx.r30.u32);
	// ori r7,r7,64240
	ctx.r7.u64 = ctx.r7.u64 | 64240;
	// stbx r30,r31,r24
	REX_STORE_U8(ctx.r31.u32 + ctx.r24.u32, ctx.r30.u8);
	// ori r6,r6,64600
	ctx.r6.u64 = ctx.r6.u64 | 64600;
	// ori r5,r5,64604
	ctx.r5.u64 = ctx.r5.u64 | 64604;
	// ld r10,3456(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// ori r4,r18,64608
	ctx.r4.u64 = ctx.r18.u64 | 64608;
	// stdx r10,r31,r23
	REX_STORE_U64(ctx.r31.u32 + ctx.r23.u32, ctx.r10.u64);
	// li r9,6
	ctx.r9.s64 = 6;
	// stfsx f13,r31,r19
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r19.u32, temp.u32);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// stfsx f0,r31,r7
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r7.u32, temp.u32);
	// stwx r30,r31,r22
	REX_STORE_U32(ctx.r31.u32 + ctx.r22.u32, ctx.r30.u32);
	// addi r10,r10,-724
	ctx.r10.s64 = ctx.r10.s64 + -724;
	// stbx r30,r31,r21
	REX_STORE_U8(ctx.r31.u32 + ctx.r21.u32, ctx.r30.u8);
	// stbx r30,r31,r20
	REX_STORE_U8(ctx.r31.u32 + ctx.r20.u32, ctx.r30.u8);
	// stwx r30,r31,r8
	REX_STORE_U32(ctx.r31.u32 + ctx.r8.u32, ctx.r30.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stwx r30,r31,r3
	REX_STORE_U32(ctx.r31.u32 + ctx.r3.u32, ctx.r30.u32);
	// stbx r30,r31,r6
	REX_STORE_U8(ctx.r31.u32 + ctx.r6.u32, ctx.r30.u8);
	// stwx r30,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r30.u32);
	// stwx r29,r31,r4
	REX_STORE_U32(ctx.r31.u32 + ctx.r4.u32, ctx.r29.u32);
loc_822A7204:
	// stfs f0,8(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// stw r30,12(r10)
	REX_STORE_U32(ctx.r10.u32 + 12, ctx.r30.u32);
	// stb r30,16(r10)
	REX_STORE_U8(ctx.r10.u32 + 16, ctx.r30.u8);
	// stb r30,17(r10)
	REX_STORE_U8(ctx.r10.u32 + 17, ctx.r30.u8);
	// stw r30,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// ld r9,3456(r11)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// stfs f0,28(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 28, temp.u32);
	// std r9,20(r10)
	REX_STORE_U64(ctx.r10.u32 + 20, ctx.r9.u64);
	// stbu r30,32(r10)
	ea = 32 + ctx.r10.u32;
	REX_STORE_U8(ea, ctx.r30.u8);
	ctx.r10.u32 = ea;
	// bdnz 0x822a7204
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_822A7204;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// addi r3,r3,-528
	ctx.r3.s64 = ctx.r3.s64 + -528;
	// bl 0x822131a0
	ctx.lr = 0x822A7238;
	sub_822131A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r11,r11,65040
	ctx.r11.u64 = ctx.r11.u64 | 65040;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// ori r10,r10,62448
	ctx.r10.u64 = ctx.r10.u64 | 62448;
	// addi r27,r27,-1240
	ctx.r27.s64 = ctx.r27.s64 + -1240;
	// stbx r30,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r30.u8);
	// stw r29,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r29.u32);
	// stwx r29,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r29.u32);
	// stb r30,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r30.u8);
	// lwz r11,-12964(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -12964);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a72c8
	if (ctx.cr6.eq) goto loc_822A72C8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,64560
	ctx.r11.u64 = ctx.r11.u64 | 64560;
	// addi r3,r3,-1236
	ctx.r3.s64 = ctx.r3.s64 + -1236;
	// li r5,260
	ctx.r5.s64 = 260;
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
	// bl 0x8273a590
	ctx.lr = 0x822A7290;
	sub_8273A590(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// addis r3,r31,1
	ctx.r3.s64 = ctx.r31.s64 + 65536;
	// ori r11,r11,64596
	ctx.r11.u64 = ctx.r11.u64 | 64596;
	// addi r3,r3,-972
	ctx.r3.s64 = ctx.r3.s64 + -972;
	// li r5,32
	ctx.r5.s64 = 32;
	// li r4,0
	ctx.r4.s64 = 0;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
	// bl 0x8273a590
	ctx.lr = 0x822A72B0;
	sub_8273A590(ctx, base);
	// lis r11,-32213
	ctx.r11.s64 = -2111111168;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// addi r3,r11,11544
	ctx.r3.s64 = ctx.r11.s64 + 11544;
	// bl 0x8242a0f8
	ctx.lr = 0x822A72C4;
	sub_8242A0F8(ctx, base);
	// stb r26,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r26.u8);
loc_822A72C8:
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// stb r26,236(r31)
	REX_STORE_U8(ctx.r31.u32 + 236, ctx.r26.u8);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r29,r11,-16100
	ctx.r29.s64 = ctx.r11.s64 + -16100;
	// lwz r11,-12860(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a730c
	if (ctx.cr6.eq) goto loc_822A730C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x822A72F0;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a730c
	if (ctx.cr6.eq) goto loc_822A730C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r11,-15060
	ctx.r3.s64 = ctx.r11.s64 + -15060;
	// bl 0x8246d8f0
	ctx.lr = 0x822A730C;
	sub_8246D8F0(ctx, base);
loc_822A730C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x822A731C;
	sub_8235EC48(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8246b640
	ctx.lr = 0x822A732C;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x822a7340
	if (!ctx.cr6.lt) goto loc_822A7340;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_822A7340:
	// lwz r11,-12860(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a736c
	if (ctx.cr6.eq) goto loc_822A736C;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x822A7354;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a736c
	if (ctx.cr6.eq) goto loc_822A736C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x822A736C;
	sub_8246D8F0(ctx, base);
loc_822A736C:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x822A737C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x822A738C;
	sub_8235EC48(ctx, base);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8246b640
	ctx.lr = 0x822A739C;
	sub_8246B640(ctx, base);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x822a73b0
	if (!ctx.cr6.lt) goto loc_822A73B0;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
loc_822A73B0:
	// lwz r11,-12860(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822a73c4
	if (ctx.cr6.eq) goto loc_822A73C4;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x822A73C4;
	sub_8246D8F0(ctx, base);
loc_822A73C4:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x822A73D4;
	sub_8235EC48(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f40
	__restgprlr_18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822C2B70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x822C2B78;
	__savegprlr_14(ctx, base);
	// stwu r1,-1616(r1)
	ea = -1616 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r19,264(r3)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r20,-1
	ctx.r20.s64 = -1;
	// lwz r18,268(r3)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// li r22,0
	ctx.r22.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r20,452(r3)
	REX_STORE_U32(ctx.r3.u32 + 452, ctx.r20.u32);
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// cmplw cr6,r19,r18
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r18.u32, ctx.xer);
	// beq cr6,0x822c35b8
	if (ctx.cr6.eq) goto loc_822C35B8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r27,1
	ctx.r27.s64 = 1;
	// lis r24,-32112
	ctx.r24.s64 = -2104492032;
	// addi r26,r11,32256
	ctx.r26.s64 = ctx.r11.s64 + 32256;
	// addi r21,r10,2668
	ctx.r21.s64 = ctx.r10.s64 + 2668;
	// addi r25,r9,2688
	ctx.r25.s64 = ctx.r9.s64 + 2688;
	// addi r23,r8,2880
	ctx.r23.s64 = ctx.r8.s64 + 2880;
loc_822C2BC8:
	// lwz r31,0(r19)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r19.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,40(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 40);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2BE0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822c35ac
	if (!ctx.cr0.eq) goto loc_822C35AC;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2BFC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822c35ac
	if (ctx.cr0.eq) goto loc_822C35AC;
	// lhz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r31.u32 + 8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x822C2C10;
	sub_823BFA70(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r11,232(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2C2C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bne cr6,0x822c2f5c
	if (!ctx.cr6.eq) goto loc_822C2F5C;
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2C5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822c35a4
	if (ctx.cr0.eq) goto loc_822C35A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2C7C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwa r3,112(r1)
	ctx.r3.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 112));
	// lfs f13,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
	// std r3,880(r1)
	REX_STORE_U64(ctx.r1.u32 + 880, ctx.r3.u64);
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stfs f13,316(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// addi r8,r1,848
	ctx.r8.s64 = ctx.r1.s64 + 848;
	// stfs f13,312(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// lwa r4,116(r1)
	ctx.r4.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 116));
	// stfs f13,308(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lwa r30,120(r1)
	ctx.r30.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 120));
	// stfs f13,304(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// std r30,952(r1)
	REX_STORE_U64(ctx.r1.u32 + 952, ctx.r30.u64);
	// stfs f13,636(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 636, temp.u32);
	// std r4,912(r1)
	REX_STORE_U64(ctx.r1.u32 + 912, ctx.r4.u64);
	// stfs f13,632(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 632, temp.u32);
	// lwa r31,124(r1)
	ctx.r31.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 124));
	// stfs f13,628(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 628, temp.u32);
	// std r31,1032(r1)
	REX_STORE_U64(ctx.r1.u32 + 1032, ctx.r31.u64);
	// stfs f13,624(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 624, temp.u32);
	// addi r11,r1,720
	ctx.r11.s64 = ctx.r1.s64 + 720;
	// lfd f13,880(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 880);
	// addi r5,r1,592
	ctx.r5.s64 = ctx.r1.s64 + 592;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f12,952(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 952);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lfs f0,164(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 164);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,1296
	ctx.r7.s64 = ctx.r1.s64 + 1296;
	// stfs f0,732(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 732, temp.u32);
	// addi r6,r1,1376
	ctx.r6.s64 = ctx.r1.s64 + 1376;
	// stfs f0,728(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 728, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f0,724(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 724, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f0,720(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 720, temp.u32);
	// stfs f0,604(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 604, temp.u32);
	// stfs f0,600(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// stfs f0,596(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,860(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 860, temp.u32);
	// stfs f13,856(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 856, temp.u32);
	// stfs f13,852(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 852, temp.u32);
	// stfs f13,848(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 848, temp.u32);
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,592(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// lfd f0,912(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 912);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,368
	ctx.r11.s64 = ctx.r1.s64 + 368;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,348(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f0,344(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f0,340(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f0,336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfd f0,1032(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 1032);
	// vaddfp128 v60,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// fcfid f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(ctx.f0.s64);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcfid f13,f12
	ctx.f13.f64 = double(ctx.f12.s64);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,1408
	ctx.r10.s64 = ctx.r1.s64 + 1408;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f0,376(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// stfs f0,372(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// stfs f13,412(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f13,408(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f13,404(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f13,400(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,432
	ctx.r8.s64 = ctx.r1.s64 + 432;
	// lfs f13,1376(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1376);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,440(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// addi r9,r1,752
	ctx.r9.s64 = ctx.r1.s64 + 752;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,624
	ctx.r7.s64 = ctx.r1.s64 + 624;
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,1296(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1296);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,764(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 764, temp.u32);
	// addi r11,r1,400
	ctx.r11.s64 = ctx.r1.s64 + 400;
	// stfs f0,760(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 760, temp.u32);
	// addi r6,r1,1440
	ctx.r6.s64 = ctx.r1.s64 + 1440;
	// stfs f0,756(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 756, temp.u32);
	// addi r4,r1,464
	ctx.r4.s64 = ctx.r1.s64 + 464;
	// stfs f0,752(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 752, temp.u32);
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r30,r1,1104
	ctx.r30.s64 = ctx.r1.s64 + 1104;
	// stfs f13,436(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// addi r17,r1,1360
	ctx.r17.s64 = ctx.r1.s64 + 1360;
	// stfs f13,444(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// addi r28,r1,816
	ctx.r28.s64 = ctx.r1.s64 + 816;
	// stfs f13,432(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// lwz r31,-13032(r24)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r24.u32 + -13032);
	// lvx128 v59,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,1136
	ctx.r11.s64 = ctx.r1.s64 + 1136;
	// lvx128 v60,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,1072
	ctx.r7.s64 = ctx.r1.s64 + 1072;
	// vaddfp128 v60,v60,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v60.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v59.f32)));
	// lvx128 v59,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,1008(r1)
	REX_STORE_U32(ctx.r1.u32 + 1008, ctx.r25.u32);
	// lfs f0,1408(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1408);
	ctx.f0.f64 = double(temp.f32);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// ld r10,168(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 168);
	// std r10,1016(r1)
	REX_STORE_U64(ctx.r1.u32 + 1016, ctx.r10.u64);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,496
	ctx.r8.s64 = ctx.r1.s64 + 496;
	// stfs f0,668(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 668, temp.u32);
	// stw r27,1012(r1)
	REX_STORE_U32(ctx.r1.u32 + 1012, ctx.r27.u32);
	// stfs f0,664(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 664, temp.u32);
	// stfs f0,660(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 660, temp.u32);
	// stfs f0,656(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 656, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1440(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1440);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,476(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// stfs f0,472(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// stfs f0,468(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// stfs f0,464(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// lvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v61,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v59,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stfs f0,184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// ld r10,184(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 184);
	// stvx128 v62,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1104(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1104);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,828(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 828, temp.u32);
	// stfs f0,824(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 824, temp.u32);
	// std r10,1024(r1)
	REX_STORE_U64(ctx.r1.u32 + 1024, ctx.r10.u64);
	// stfs f0,820(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 820, temp.u32);
	// stfs f0,816(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 816, temp.u32);
	// lfs f0,1360(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1360);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,508(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// stfs f0,504(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stfs f0,500(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f0,496(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822c2f0c
	if (ctx.cr6.eq) goto loc_822C2F0C;
	// lfs f0,1136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1136);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f13,1072(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1072);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x822C2F08;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822C2F0C:
	// lfs f0,168(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f1,520(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 520);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822c2f50
	if (ctx.cr6.eq) goto loc_822C2F50;
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// stw r22,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r22.u32);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,1008
	ctx.r3.s64 = ctx.r1.s64 + 1008;
	// bl 0x823b0938
	ctx.lr = 0x822C2F4C;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_822C2F50:
	// stw r11,452(r29)
	REX_STORE_U32(ctx.r29.u32 + 452, ctx.r11.u32);
	// stw r21,1008(r1)
	REX_STORE_U32(ctx.r1.u32 + 1008, ctx.r21.u32);
	// b 0x822c35a0
	goto loc_822C35A0;
loc_822C2F5C:
	// lwz r11,232(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 232);
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2F6C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x822c35a4
	if (!ctx.cr6.gt) goto loc_822C35A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2F9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822c329c
	if (ctx.cr0.eq) goto loc_822C329C;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,200
	ctx.r3.s64 = ctx.r1.s64 + 200;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C2FBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,204(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 204);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,688
	ctx.r11.s64 = ctx.r1.s64 + 688;
	// lwa r4,112(r1)
	ctx.r4.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 112));
	// lfs f13,200(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 200);
	ctx.f13.f64 = double(temp.f32);
	// lwa r3,116(r1)
	ctx.r3.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 116));
	// addi r9,r1,528
	ctx.r9.s64 = ctx.r1.s64 + 528;
	// stfs f0,700(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 700, temp.u32);
	// std r4,928(r1)
	REX_STORE_U64(ctx.r1.u32 + 928, ctx.r4.u64);
	// stfs f0,692(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 692, temp.u32);
	// std r3,936(r1)
	REX_STORE_U64(ctx.r1.u32 + 936, ctx.r3.u64);
	// stfs f0,688(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 688, temp.u32);
	// addi r5,r1,784
	ctx.r5.s64 = ctx.r1.s64 + 784;
	// stfs f13,540(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// lwa r17,120(r1)
	ctx.r17.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 120));
	// stfs f13,536(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// addi r10,r1,560
	ctx.r10.s64 = ctx.r1.s64 + 560;
	// stfs f0,696(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 696, temp.u32);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// stfs f13,532(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// std r17,888(r1)
	REX_STORE_U64(ctx.r1.u32 + 888, ctx.r17.u64);
	// stfs f13,528(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// lwa r30,124(r1)
	ctx.r30.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 124));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r30,896(r1)
	REX_STORE_U64(ctx.r1.u32 + 896, ctx.r30.u64);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,1168
	ctx.r7.s64 = ctx.r1.s64 + 1168;
	// stfs f0,796(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 796, temp.u32);
	// addi r6,r1,1424
	ctx.r6.s64 = ctx.r1.s64 + 1424;
	// stfs f0,792(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 792, temp.u32);
	// addi r11,r1,288
	ctx.r11.s64 = ctx.r1.s64 + 288;
	// stfs f0,788(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 788, temp.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// stfs f0,784(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 784, temp.u32);
	// mr r3,r17
	ctx.r3.u64 = ctx.r17.u64;
	// stfs f13,332(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f13,328(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f13,320(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lfd f0,928(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 928);
	// lfd f13,936(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 936);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f12,896(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 896);
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f13,560(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f13,572(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f13,568(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f13,564(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// lfd f13,888(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 888);
	// fcfid f0,f13
	ctx.f0.f64 = double(ctx.f13.s64);
	// fcfid f13,f12
	ctx.f13.f64 = double(ctx.f12.s64);
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// vaddfp128 v61,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// frsp f13,f13
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,1328
	ctx.r10.s64 = ctx.r1.s64 + 1328;
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f13,300(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f13,296(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f13,292(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f13,288(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// lfs f0,1168(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1168);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,364(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// addi r8,r1,416
	ctx.r8.s64 = ctx.r1.s64 + 416;
	// stfs f0,360(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// stfs f0,356(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// addi r6,r1,208
	ctx.r6.s64 = ctx.r1.s64 + 208;
	// stfs f0,352(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// addi r4,r1,1200
	ctx.r4.s64 = ctx.r1.s64 + 1200;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r17,r1,1232
	ctx.r17.s64 = ctx.r1.s64 + 1232;
	// lfs f13,1424(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1424);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,384
	ctx.r7.s64 = ctx.r1.s64 + 384;
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,448
	ctx.r3.s64 = ctx.r1.s64 + 448;
	// lvx128 v60,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r15,r1,480
	ctx.r15.s64 = ctx.r1.s64 + 480;
	// vaddfp128 v61,v61,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f13,396(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f13,392(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// addi r16,r1,1392
	ctx.r16.s64 = ctx.r1.s64 + 1392;
	// stfs f13,388(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// addi r14,r1,1264
	ctx.r14.s64 = ctx.r1.s64 + 1264;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,512
	ctx.r11.s64 = ctx.r1.s64 + 512;
	// stfs f13,384(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// addi r6,r1,1088
	ctx.r6.s64 = ctx.r1.s64 + 1088;
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// ld r10,176(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// std r10,1048(r1)
	REX_STORE_U64(ctx.r1.u32 + 1048, ctx.r10.u64);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// lfs f0,1328(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1328);
	ctx.f0.f64 = double(temp.f32);
	// lwz r30,-13032(r24)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r24.u32 + -13032);
	// stfs f0,428(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// stw r25,1040(r1)
	REX_STORE_U32(ctx.r1.u32 + 1040, ctx.r25.u32);
	// stfs f0,424(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// stw r27,1044(r1)
	REX_STORE_U32(ctx.r1.u32 + 1044, ctx.r27.u32);
	// stfs f0,420(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1200(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1200);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,452(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f13,456(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f13,448(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// stfs f13,460(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ld r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// lvx128 v59,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v59
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vaddfp128 v62,v62,v60
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v61,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r10,1056(r1)
	REX_STORE_U64(ctx.r1.u32 + 1056, ctx.r10.u64);
	// stvx128 v62,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1232(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1232);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,492(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f0,488(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// stfs f0,484(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// stfs f0,480(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// lfs f0,1392(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,512(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stfs f0,524(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// stfs f0,520(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// stfs f0,516(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// lvx128 v62,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822c324c
	if (ctx.cr6.eq) goto loc_822C324C;
	// lfs f0,1264(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1264);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f0,1088(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1088);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// bl 0x823aefa8
	ctx.lr = 0x822C3248;
	sub_823AEFA8(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_822C324C:
	// lfs f0,168(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r7,4(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f1,520(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 520);
	ctx.f1.f64 = double(temp.f32);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// mr r11,r20
	ctx.r11.u64 = ctx.r20.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x822c3290
	if (ctx.cr6.eq) goto loc_822C3290;
	// stw r22,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r22.u32);
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// ori r4,r4,9
	ctx.r4.u64 = ctx.r4.u64 | 9;
	// addi r3,r1,1040
	ctx.r3.s64 = ctx.r1.s64 + 1040;
	// bl 0x823b0938
	ctx.lr = 0x822C328C;
	sub_823B0938(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_822C3290:
	// stw r11,452(r29)
	REX_STORE_U32(ctx.r29.u32 + 452, ctx.r11.u32);
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
	// stw r21,1040(r1)
	REX_STORE_U32(ctx.r1.u32 + 1040, ctx.r21.u32);
loc_822C329C:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,228(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 228);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C32C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822c35a4
	if (ctx.cr0.eq) goto loc_822C35A4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,192
	ctx.r3.s64 = ctx.r1.s64 + 192;
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x822C32E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f13,192(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 192);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// lwa r3,112(r1)
	ctx.r3.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 112));
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// lwa r4,116(r1)
	ctx.r4.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 116));
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// std r4,960(r1)
	REX_STORE_U64(ctx.r1.u32 + 960, ctx.r4.u64);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// std r3,904(r1)
	REX_STORE_U64(ctx.r1.u32 + 904, ctx.r3.u64);
	// lfs f0,196(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r5,r1,544
	ctx.r5.s64 = ctx.r1.s64 + 544;
	// stfs f0,252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f0,248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// lwa r31,124(r1)
	ctx.r31.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 124));
	// stfs f0,244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r8,r1,608
	ctx.r8.s64 = ctx.r1.s64 + 608;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwa r11,120(r1)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r1.u32 + 120));
	// stfs f0,240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// std r11,944(r1)
	REX_STORE_U64(ctx.r1.u32 + 944, ctx.r11.u64);
	// stfs f0,556(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// stfs f0,552(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// std r31,920(r1)
	REX_STORE_U64(ctx.r1.u32 + 920, ctx.r31.u64);
	// stfs f0,548(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// addi r10,r1,576
	ctx.r10.s64 = ctx.r1.s64 + 576;
	// stfs f0,544(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// addi r6,r1,1120
	ctx.r6.s64 = ctx.r1.s64 + 1120;
	// stfs f13,652(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 652, temp.u32);
	// addi r7,r1,1152
	ctx.r7.s64 = ctx.r1.s64 + 1152;
	// stfs f13,648(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 648, temp.u32);
	// addi r11,r1,640
	ctx.r11.s64 = ctx.r1.s64 + 640;
	// stfs f13,644(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 644, temp.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// stfs f13,640(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 640, temp.u32);
	// lfd f13,960(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 960);
	// lfd f12,904(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 904);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f0,944(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 944);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lfd f11,920(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 920);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,684(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 684, temp.u32);
	// stfs f0,680(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 680, temp.u32);
	// stfs f0,676(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 676, temp.u32);
	// stfs f0,672(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 672, temp.u32);
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
	// frsp f13,f12
	ctx.f13.f64 = double(float(ctx.f12.f64));
	// stfs f13,612(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// stfs f13,608(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// frsp f12,f11
	ctx.f12.f64 = double(float(ctx.f11.f64));
	// stfs f13,620(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 620, temp.u32);
	// stfs f13,616(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// stfs f0,588(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// stfs f0,584(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f0,580(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f0,576(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stfs f12,716(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 716, temp.u32);
	// stfs f12,712(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 712, temp.u32);
	// stfs f12,708(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// stfs f12,704(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 704, temp.u32);
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,672
	ctx.r10.s64 = ctx.r1.s64 + 672;
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,704
	ctx.r8.s64 = ctx.r1.s64 + 704;
	// lvx128 v60,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,1216
	ctx.r7.s64 = ctx.r1.s64 + 1216;
	// vaddfp128 v61,v61,v60
	simde_mm_store_ps(ctx.v61.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v60.f32)));
	// addi r10,r1,768
	ctx.r10.s64 = ctx.r1.s64 + 768;
	// lfs f0,1152(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1152);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,1184
	ctx.r9.s64 = ctx.r1.s64 + 1184;
	// stfs f0,780(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 780, temp.u32);
	// addi r6,r1,832
	ctx.r6.s64 = ctx.r1.s64 + 832;
	// lvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,736
	ctx.r8.s64 = ctx.r1.s64 + 736;
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stfs f0,776(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 776, temp.u32);
	// stfs f0,772(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 772, temp.u32);
	// addi r11,r1,800
	ctx.r11.s64 = ctx.r1.s64 + 800;
	// stfs f0,768(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 768, temp.u32);
	// addi r5,r1,1280
	ctx.r5.s64 = ctx.r1.s64 + 1280;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r4,r1,1248
	ctx.r4.s64 = ctx.r1.s64 + 1248;
	// lfs f13,1120(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1120);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r1,272
	ctx.r30.s64 = ctx.r1.s64 + 272;
	// stfs f13,748(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 748, temp.u32);
	// addi r31,r1,864
	ctx.r31.s64 = ctx.r1.s64 + 864;
	// stfs f13,744(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 744, temp.u32);
	// addi r28,r1,1344
	ctx.r28.s64 = ctx.r1.s64 + 1344;
	// stfs f13,740(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 740, temp.u32);
	// addi r17,r1,1312
	ctx.r17.s64 = ctx.r1.s64 + 1312;
	// stfs f13,736(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 736, temp.u32);
	// lwz r3,-13032(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + -13032);
	// stvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r25,976(r1)
	REX_STORE_U32(ctx.r1.u32 + 976, ctx.r25.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r27,980(r1)
	REX_STORE_U32(ctx.r1.u32 + 980, ctx.r27.u32);
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1216);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1184(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1184);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,812(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 812, temp.u32);
	// ld r10,144(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stfs f13,808(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 808, temp.u32);
	// std r10,984(r1)
	REX_STORE_U64(ctx.r1.u32 + 984, ctx.r10.u64);
	// stfs f0,844(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 844, temp.u32);
	// stfs f0,840(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 840, temp.u32);
	// stfs f0,836(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 836, temp.u32);
	// stfs f0,832(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 832, temp.u32);
	// stfs f13,804(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 804, temp.u32);
	// stfs f13,800(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 800, temp.u32);
	// lvx128 v60,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// stvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,156(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r11,992(r1)
	REX_STORE_U64(ctx.r1.u32 + 992, ctx.r11.u64);
	// lfs f0,1248(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1248);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,876(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 876, temp.u32);
	// stfs f0,872(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 872, temp.u32);
	// stfs f0,868(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 868, temp.u32);
	// stfs f0,864(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 864, temp.u32);
	// lfs f0,1280(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1280);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f0,280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f0,272(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lvx128 v61,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x822c359c
	if (ctx.cr6.eq) goto loc_822C359C;
	// lfs f0,1312(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1312);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lfs f0,1344(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1344);
	ctx.f0.f64 = double(temp.f32);
	// lwz r5,132(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x822C3564;
	sub_823AEFA8(ctx, base);
	// lfs f0,168(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r6,4(r29)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lis r4,16384
	ctx.r4.s64 = 1073741824;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lfs f1,520(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 520);
	ctx.f1.f64 = double(temp.f32);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// stw r22,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r22.u32);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// ori r4,r4,1
	ctx.r4.u64 = ctx.r4.u64 | 1;
	// addi r3,r1,976
	ctx.r3.s64 = ctx.r1.s64 + 976;
	// bl 0x823b0938
	ctx.lr = 0x822C359C;
	sub_823B0938(ctx, base);
loc_822C359C:
	// stw r21,976(r1)
	REX_STORE_U32(ctx.r1.u32 + 976, ctx.r21.u32);
loc_822C35A0:
	// mr r30,r27
	ctx.r30.u64 = ctx.r27.u64;
loc_822C35A4:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822c35b8
	if (!ctx.cr0.eq) goto loc_822C35B8;
loc_822C35AC:
	// addi r19,r19,4
	ctx.r19.s64 = ctx.r19.s64 + 4;
	// cmplw cr6,r19,r18
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r18.u32, ctx.xer);
	// bne cr6,0x822c2bc8
	if (!ctx.cr6.eq) goto loc_822C2BC8;
loc_822C35B8:
	// addi r1,r1,1616
	ctx.r1.s64 = ctx.r1.s64 + 1616;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823297C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x823297D0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32205
	ctx.r10.s64 = -2110586880;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// addi r10,r10,-24472
	ctx.r10.s64 = ctx.r10.s64 + -24472;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwzx r11,r3,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82329a48
	if (!ctx.cr6.eq) goto loc_82329A48;
	// bl 0x82232628
	ctx.lr = 0x823297FC;
	sub_82232628(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82329bcc
	if (!ctx.cr0.eq) goto loc_82329BCC;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r30,0(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// bl 0x8222ff78
	ctx.lr = 0x82329824;
	sub_8222FF78(ctx, base);
	// lwz r11,64(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 64);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329838;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8232985C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r29,r29,-3164
	ctx.r29.s64 = ctx.r29.s64 + -3164;
	// lfs f13,-30128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82329bcc
	if (!ctx.cr6.lt) goto loc_82329BCC;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r30,-32115
	ctx.r30.s64 = -2104688640;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfs f13,27412(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 27412);
	ctx.f13.f64 = double(temp.f32);
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,40(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// subfic r31,r10,14
	ctx.xer.ca = ctx.r10.u32 <= 14;
	ctx.r31.u64 = static_cast<uint64_t>(14) - ctx.r10.u64;
	// fabs f31,f13
	ctx.f31.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823298C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// bne cr6,0x82329988
	if (!ctx.cr6.eq) goto loc_82329988;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82329904
	if (ctx.cr6.eq) goto loc_82329904;
	// li r11,80
	ctx.r11.s64 = 80;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_823298D8:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r9,r10,-80
	ctx.r9.s64 = ctx.r10.s64 + -80;
	// lfs f0,-80(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-40(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -40, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r9,r11,r10
	ctx.r9.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lfs f0,40(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r11,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, temp.u32);
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// bdnz 0x823298d8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823298D8;
loc_82329904:
	// subfic r11,r31,14
	ctx.xer.ca = ctx.r31.u32 <= 14;
	ctx.r11.u64 = static_cast<uint64_t>(14) - ctx.r31.u64;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27412(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 27412);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mulli r11,r10,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfsx f12,r11,r9
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f12.f64 = double(temp.f32);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r8,r10,3
	ctx.r8.s64 = ctx.r10.s64 + 3;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// mulli r8,r8,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r8.u64 * static_cast<uint64_t>(40));
	// mulli r7,r10,40
	ctx.r7.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fnmsubs f13,f11,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fadds f12,f13,f12
	ctx.f12.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f12,40(r9)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r9.u32 + 40, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfsx f12,r8,r10
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// fadds f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 + ctx.f13.f64));
	// stfsx f13,r7,r10
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,72(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 72, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,112(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 112, temp.u32);
	// b 0x82329bcc
	goto loc_82329BCC;
loc_82329988:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x823299c4
	if (ctx.cr6.eq) goto loc_823299C4;
	// li r11,0
	ctx.r11.s64 = 0;
	// mtctr r31
	ctx.ctr.u64 = ctx.r31.u64;
loc_82329998:
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r11,120
	ctx.r10.s64 = ctx.r11.s64 + 120;
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lfs f0,40(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r11,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r8,r10,r9
	ctx.r8.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lfs f0,-40(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -40);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// stfsx f0,r10,r9
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + ctx.r9.u32, temp.u32);
	// bdnz 0x82329998
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82329998;
loc_823299C4:
	// subfic r11,r31,14
	ctx.xer.ca = ctx.r31.u32 <= 14;
	ctx.r11.u64 = static_cast<uint64_t>(14) - ctx.r31.u64;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,27412(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 27412);
	ctx.f0.f64 = double(temp.f32);
	// rlwinm r10,r31,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 2) & 0xFFFFFFFC;
	// clrldi r8,r11,32
	ctx.r8.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mulli r11,r10,40
	ctx.r11.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// add r8,r11,r9
	ctx.r8.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// addi r10,r10,3
	ctx.r10.s64 = ctx.r10.s64 + 3;
	// mulli r7,r7,40
	ctx.r7.s64 = static_cast<int64_t>(ctx.r7.u64 * static_cast<uint64_t>(40));
	// lfs f12,40(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 40);
	ctx.f12.f64 = double(temp.f32);
	// mulli r8,r10,40
	ctx.r8.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(40));
	// lfd f11,88(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// fnmsubs f13,f11,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f13.f64)));
	// fdivs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f0.f64));
	// fmuls f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fsubs f12,f12,f13
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfsx f12,r11,r9
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfsx f12,r7,r10
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + ctx.r10.u32);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 - ctx.f13.f64));
	// stfsx f13,r8,r10
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r8.u32 + ctx.r10.u32, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,32(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 32, temp.u32);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stfs f0,152(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 152, temp.u32);
	// b 0x82329bcc
	goto loc_82329BCC;
loc_82329A48:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62409
	ctx.r11.u64 = ctx.r11.u64 | 62409;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82329bc4
	if (ctx.cr0.eq) goto loc_82329BC4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// addi r30,r11,17284
	ctx.r30.s64 = ctx.r11.s64 + 17284;
	// addi r29,r29,-3164
	ctx.r29.s64 = ctx.r29.s64 + -3164;
	// lfs f0,-12844(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -12844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82329bc4
	if (ctx.cr6.lt) goto loc_82329BC4;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329A94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82329bcc
	if (ctx.cr0.eq) goto loc_82329BCC;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f0,2136(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2136);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82329bcc
	if (!ctx.cr6.lt) goto loc_82329BCC;
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// lfs f0,-12844(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -12844);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fsubs f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// lwz r28,0(r11)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r29,0(r28)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// bl 0x8222ff78
	ctx.lr = 0x82329ADC;
	sub_8222FF78(ctx, base);
	// lwz r11,64(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 64);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329AF0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82329B14;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmuls f10,f31,f31
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = double(float(ctx.f31.f64 * ctx.f31.f64));
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,12468
	ctx.r9.s64 = ctx.r11.s64 + 12468;
	// fmuls f9,f31,f0
	ctx.f9.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f11,-188(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -188);
	ctx.f11.f64 = double(temp.f32);
	// lfs f13,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29492(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,1908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1908);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f8,f31,f0
	ctx.f8.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
	// lfs f0,2916(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2916);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f12,f10,f12
	ctx.f12.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// fmsubs f0,f12,f0,f9
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f9.f64)));
	// fmadds f12,f12,f11,f8
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f11.f64, ctx.f8.f64)));
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82329b5c
	if (!ctx.cr6.lt) goto loc_82329B5C;
	// fmr f0,f13
	ctx.f0.f64 = ctx.f13.f64;
loc_82329B5C:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f13,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f13,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// stfs f0,80(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f0,120(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 120);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f12.f64));
	// stfs f0,120(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 120, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f0,124(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 124);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82329bcc
	if (!ctx.cr6.lt) goto loc_82329BCC;
	// stfs f0,4(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lfs f0,84(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// b 0x82329bcc
	goto loc_82329BCC;
loc_82329BC4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82231a30
	ctx.lr = 0x82329BCC;
	sub_82231A30(ctx, base);
loc_82329BCC:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82346108) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x82346110;
	__savegprlr_24(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x8231e0d8
	ctx.lr = 0x82346124;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r7,12468
	ctx.r11.s64 = ctx.r7.s64 + 12468;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r6,r1,128
	ctx.r6.s64 = ctx.r1.s64 + 128;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r5,-32112
	ctx.r5.s64 = -2104492032;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r27,0
	ctx.r27.s64 = 0;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r25,0
	ctx.r25.s64 = 0;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r24,1
	ctx.r24.s64 = 1;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r30,-13032(r5)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r5.u32 + -13032);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f4,12468(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f4.f64 = double(temp.f32);
	// lfs f3,1736(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1736);
	ctx.f3.f64 = double(temp.f32);
	// fmr f5,f4
	ctx.f5.f64 = ctx.f4.f64;
	// fmr f6,f4
	ctx.f6.f64 = ctx.f4.f64;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fcmpu cr6,f13,f3
	ctx.cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// ble cr6,0x82346244
	if (!ctx.cr6.gt) goto loc_82346244;
	// fcmpu cr6,f0,f4
	ctx.cr6.compare(ctx.f0.f64, ctx.f4.f64);
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// ble cr6,0x82346204
	if (!ctx.cr6.gt) goto loc_82346204;
	// li r27,1
	ctx.r27.s64 = 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823461f4
	if (ctx.cr6.eq) goto loc_823461F4;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823ae578
	ctx.lr = 0x823461F4;
	sub_823AE578(ctx, base);
loc_823461F4:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// b 0x8234623c
	goto loc_8234623C;
loc_82346204:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82346230
	if (ctx.cr6.eq) goto loc_82346230;
	// fctiwz f13,f13
	ctx.fpscr.disableFlushMode();
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823ae2c0
	ctx.lr = 0x82346230;
	sub_823AE2C0(ctx, base);
loc_82346230:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_8234623C:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f5,f0
	ctx.f5.f64 = double(float(ctx.f0.f64));
loc_82346244:
	// lfs f0,128(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f3
	ctx.cr6.compare(ctx.f13.f64, ctx.f3.f64);
	// ble cr6,0x823462e4
	if (!ctx.cr6.gt) goto loc_823462E4;
	// fcmpu cr6,f0,f4
	ctx.cr6.compare(ctx.f0.f64, ctx.f4.f64);
	// lfs f0,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// li r3,0
	ctx.r3.s64 = 0;
	// ble cr6,0x823462a8
	if (!ctx.cr6.gt) goto loc_823462A8;
	// li r25,1
	ctx.r25.s64 = 1;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82346298
	if (ctx.cr6.eq) goto loc_82346298;
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f13.u64);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aebd8
	ctx.lr = 0x82346298;
	sub_823AEBD8(ctx, base);
loc_82346298:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x823462dc
	goto loc_823462DC;
loc_823462A8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x823462d0
	if (ctx.cr6.eq) goto loc_823462D0;
	// fctiwz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r3,100(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823ae820
	ctx.lr = 0x823462D0;
	sub_823AE820(ctx, base);
loc_823462D0:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
loc_823462DC:
	// fcfid f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f6,f0
	ctx.f6.f64 = double(float(ctx.f0.f64));
loc_823462E4:
	// fabs f0,f5
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = ctx.f5.u64 & ~0x8000000000000000;
	// fabs f12,f6
	ctx.f12.u64 = ctx.f6.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f3
	ctx.cr6.compare(ctx.f0.f64, ctx.f3.f64);
	// ble cr6,0x823463e4
	if (!ctx.cr6.gt) goto loc_823463E4;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r29,r11,32752
	ctx.r29.s64 = ctx.r11.s64 + 32752;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82346360
	if (ctx.cr6.eq) goto loc_82346360;
	// lfs f11,4(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f11.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// fctiwz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// fctiwz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f11.u64);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823af008
	ctx.lr = 0x8234635C;
	sub_823AF008(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
loc_82346360:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r3,0
	ctx.r3.s64 = 0;
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x823463bc
	if (ctx.cr6.eq) goto loc_823463BC;
	// lfs f13,4(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f11,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f11.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// fctiwz f11,f11
	ctx.f11.s64 = std::isnan(ctx.f11.f64) ? int64_t(0x80000000U) : (ctx.f11.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f11.f64));
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// stfd f11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f11.u64);
	// lwz r5,100(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r4,84(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823af008
	ctx.lr = 0x823463BC;
	sub_823AF008(ctx, base);
loc_823463BC:
	// clrlwi. r10,r28,24
	ctx.r10.u64 = ctx.r28.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x823463e4
	if (ctx.cr0.eq) goto loc_823463E4;
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823463e4
	if (ctx.cr0.eq) goto loc_823463E4;
	// cmplwi cr6,r10,8
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 8, ctx.xer);
	// beq cr6,0x823463e4
	if (ctx.cr6.eq) goto loc_823463E4;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x823463e4
	if (ctx.cr6.eq) goto loc_823463E4;
	// fmr f0,f4
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f4.f64;
	// li r24,0
	ctx.r24.s64 = 0;
loc_823463E4:
	// clrlwi. r11,r27,24
	ctx.r11.u64 = ctx.r27.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8234644c
	if (ctx.cr0.eq) goto loc_8234644C;
	// clrlwi. r10,r25,24
	ctx.r10.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8234644c
	if (ctx.cr0.eq) goto loc_8234644C;
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82346440
	if (ctx.cr0.eq) goto loc_82346440;
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x82346440
	if (ctx.cr6.gt) goto loc_82346440;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
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
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 4, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// b 0x823464fc
	goto loc_823464FC;
loc_82346440:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// b 0x823464cc
	goto loc_823464CC;
loc_8234644C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82346488
	if (ctx.cr6.eq) goto loc_82346488;
	// clrlwi. r10,r25,24
	ctx.r10.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82346480
	if (!ctx.cr0.eq) goto loc_82346480;
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823464c4
	if (ctx.cr0.eq) goto loc_823464C4;
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x823464c4
	if (ctx.cr6.gt) goto loc_823464C4;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r10,32608
	ctx.r10.s64 = ctx.r10.s64 + 32608;
	// b 0x823464d4
	goto loc_823464D4;
loc_82346480:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823464b4
	if (!ctx.cr6.eq) goto loc_823464B4;
loc_82346488:
	// clrlwi. r11,r25,24
	ctx.r11.u64 = ctx.r25.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823464b4
	if (ctx.cr0.eq) goto loc_823464B4;
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82346440
	if (ctx.cr0.eq) goto loc_82346440;
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// bgt cr6,0x82346440
	if (ctx.cr6.gt) goto loc_82346440;
loc_823464A0:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// addi r10,r10,32688
	ctx.r10.s64 = ctx.r10.s64 + 32688;
	// b 0x823464d4
	goto loc_823464D4;
loc_823464B4:
	// clrlwi. r11,r24,24
	ctx.r11.u64 = ctx.r24.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823464c4
	if (ctx.cr0.eq) goto loc_823464C4;
	// fcmpu cr6,f0,f12
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f12.f64);
	// ble cr6,0x823464a0
	if (!ctx.cr6.gt) goto loc_823464A0;
loc_823464C4:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r11,r11,32608
	ctx.r11.s64 = ctx.r11.s64 + 32608;
loc_823464CC:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r10,r10,32720
	ctx.r10.s64 = ctx.r10.s64 + 32720;
loc_823464D4:
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r26)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r26.u32 + 0, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r26)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r26.u32 + 4, temp.u32);
loc_823464FC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82363FE8) {
	REX_FUNC_PROLOGUE();
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
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lwz r11,-13060(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -13060);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82364074
	if (ctx.cr6.eq) goto loc_82364074;
	// lbz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 164);
	// addi r3,r11,136
	ctx.r3.s64 = ctx.r11.s64 + 136;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82364020
	if (ctx.cr0.eq) goto loc_82364020;
	// bl 0x82855b44
	ctx.lr = 0x8236401C;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r11,-13060(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -13060);
loc_82364020:
	// lbz r10,164(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 164);
	// addi r3,r11,136
	ctx.r3.s64 = ctx.r11.s64 + 136;
	// lwz r31,168(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x82364038
	if (ctx.cr0.eq) goto loc_82364038;
	// bl 0x82855b34
	ctx.lr = 0x82364038;
	__imp__RtlLeaveCriticalSection(ctx, base);
loc_82364038:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82364074
	if (ctx.cr6.eq) goto loc_82364074;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stw r31,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r31.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// li r9,533
	ctx.r9.s64 = 533;
	// addi r10,r10,20580
	ctx.r10.s64 = ctx.r10.s64 + 20580;
	// stw r11,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// lwz r3,-12816(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + -12816);
	// bl 0x825a2f98
	ctx.lr = 0x82364074;
	sub_825A2F98(ctx, base);
loc_82364074:
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

DEFINE_REX_FUNC(sub_82366A38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82366A40;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273aef4
	ctx.lr = 0x82366A48;
	__savefpr_15(ctx, base);
	// li r12,-336
	ctx.r12.s64 = -336;
	// stvx128 v125,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v125.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-320
	ctx.r12.s64 = -320;
	// stvx128 v126,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-304
	ctx.r12.s64 = -304;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-1280(r1)
	ea = -1280 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,84(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 84, temp.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r4,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r4.u32);
	// addi r26,r11,12236
	ctx.r26.s64 = ctx.r11.s64 + 12236;
	// stw r9,80(r3)
	REX_STORE_U32(ctx.r3.u32 + 80, ctx.r9.u32);
	// li r23,0
	ctx.r23.s64 = 0;
	// lwz r28,1364(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 1364);
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// stw r23,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r23.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mr r29,r8
	ctx.r29.u64 = ctx.r8.u64;
	// lfs f15,232(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 232);
	ctx.f15.f64 = double(temp.f32);
	// stfs f15,20(r30)
	temp.f32 = float(ctx.f15.f64);
	REX_STORE_U32(ctx.r30.u32 + 20, temp.u32);
	// bl 0x825a5088
	ctx.lr = 0x82366AA0;
	sub_825A5088(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82366ae8
	if (ctx.cr0.eq) goto loc_82366AE8;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r11,r11,32688
	ctx.r11.s64 = ctx.r11.s64 + 32688;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// b 0x82366af8
	goto loc_82366AF8;
loc_82366AE8:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,176
	ctx.r3.s64 = ctx.r1.s64 + 176;
	// bl 0x825a5160
	ctx.lr = 0x82366AF4;
	sub_825A5160(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
loc_82366AF8:
	// stw r29,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r29.u32);
	// clrldi r8,r29,32
	ctx.r8.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// stw r31,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r31.u32);
	// lfs f13,0(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// std r8,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r8.u64);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r8,r1,160
	ctx.r8.s64 = ctx.r1.s64 + 160;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// clrldi r7,r31,32
	ctx.r7.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// lfs f10,4(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 4);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lfs f12,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// std r7,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r7.u64);
	// stfs f12,172(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r31,r1,224
	ctx.r31.s64 = ctx.r1.s64 + 224;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r27,r1,208
	ctx.r27.s64 = ctx.r1.s64 + 208;
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// addi r25,r1,176
	ctx.r25.s64 = ctx.r1.s64 + 176;
	// lfs f0,12(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// mr r24,r23
	ctx.r24.u64 = ctx.r23.u64;
	// lfs f13,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// mr r28,r23
	ctx.r28.u64 = ctx.r23.u64;
	// stfs f12,168(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stw r23,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r23.u32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stw r23,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r23.u32);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stw r23,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r23.u32);
	// lfs f12,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// mr r29,r23
	ctx.r29.u64 = ctx.r23.u64;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f10,172(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f10,168(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f10,160(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f11,8(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 8);
	ctx.f11.f64 = double(temp.f32);
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,140(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfd f11,176(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// lfd f10,192(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f11
	ctx.f0.f64 = double(float(ctx.f11.f64));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f13,f10
	ctx.f13.f64 = double(float(ctx.f10.f64));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f30.f64 = double(temp.f32);
	// lfs f17,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f17.f64 = double(temp.f32);
	// stfs f12,188(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f12,180(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f12,176(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stvx128 v62,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f29,f17,f30
	ctx.f29.f64 = double(float(ctx.f17.f64 - ctx.f30.f64));
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stvx128 v63,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// lvx128 v63,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f16,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f16.f64 = double(temp.f32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// lfs f27,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f27.f64 = double(temp.f32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f28,f16,f27
	ctx.f28.f64 = double(float(ctx.f16.f64 - ctx.f27.f64));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r25,-32228
	ctx.r25.s64 = -2112094208;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f22,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f22.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f26,f29,f0
	ctx.f26.f64 = double(float(ctx.f29.f64 / ctx.f0.f64));
	// lfs f0,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f25,f28,f13
	ctx.f25.f64 = double(float(ctx.f28.f64 / ctx.f13.f64));
	// lfs f24,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f24.f64 = double(temp.f32);
	// lfs f12,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f23,f12,f24
	ctx.f23.f64 = double(float(ctx.f12.f64 - ctx.f24.f64));
	// lfs f18,1424(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1424);
	ctx.f18.f64 = double(temp.f32);
	// fsubs f21,f0,f22
	ctx.f21.f64 = double(float(ctx.f0.f64 - ctx.f22.f64));
	// fabs f20,f26
	ctx.f20.u64 = ctx.f26.u64 & ~0x8000000000000000;
	// fabs f19,f25
	ctx.f19.u64 = ctx.f25.u64 & ~0x8000000000000000;
loc_82366CB4:
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82366ccc
	if (ctx.cr6.eq) goto loc_82366CCC;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x82366cd0
	if (ctx.cr6.lt) goto loc_82366CD0;
loc_82366CCC:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_82366CD0:
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// bne cr6,0x82366ce4
	if (!ctx.cr6.eq) goto loc_82366CE4;
	// fmr f31,f27
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f27.f64;
	// b 0x82366d10
	goto loc_82366D10;
loc_82366CE4:
	// lwz r10,16(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82366cf8
	if (!ctx.cr6.eq) goto loc_82366CF8;
	// fmr f31,f16
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f16.f64;
	// b 0x82366d10
	goto loc_82366D10;
loc_82366CF8:
	// clrldi r10,r29,32
	ctx.r10.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// std r10,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r10.u64);
	// lfd f0,176(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmadds f31,f0,f25,f27
	ctx.f31.f64 = double(float(std::fma(ctx.f0.f64, ctx.f25.f64, ctx.f27.f64)));
loc_82366D10:
	// mr r31,r23
	ctx.r31.u64 = ctx.r23.u64;
	// clrlwi r27,r11,24
	ctx.r27.u64 = ctx.r11.u32 & 0xFF;
loc_82366D18:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// beq cr6,0x82366d38
	if (ctx.cr6.eq) goto loc_82366D38;
	// lfs f0,1536(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 1536);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f2,f19,f0
	ctx.f2.f64 = double(float(ctx.f19.f64 * ctx.f0.f64));
	// fmuls f1,f19,f18
	ctx.f1.f64 = double(float(ctx.f19.f64 * ctx.f18.f64));
	// bl 0x825a4a40
	ctx.lr = 0x82366D34;
	sub_825A4A40(ctx, base);
	// fadds f31,f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = double(float(ctx.f1.f64 + ctx.f31.f64));
loc_82366D38:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82366d48
	if (!ctx.cr6.eq) goto loc_82366D48;
	// fmr f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f30.f64;
	// b 0x82366d8c
	goto loc_82366D8C;
loc_82366D48:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82366d5c
	if (!ctx.cr6.eq) goto loc_82366D5C;
	// fmr f0,f17
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f17.f64;
	// b 0x82366d8c
	goto loc_82366D8C;
loc_82366D5C:
	// lfs f0,1536(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 1536);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmuls f2,f20,f0
	ctx.f2.f64 = double(float(ctx.f20.f64 * ctx.f0.f64));
	// fmuls f1,f20,f18
	ctx.f1.f64 = double(float(ctx.f20.f64 * ctx.f18.f64));
	// bl 0x825a4a40
	ctx.lr = 0x82366D70;
	sub_825A4A40(ctx, base);
	// clrldi r11,r31,32
	ctx.r11.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// std r11,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r11.u64);
	// lfd f0,192(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmadds f0,f0,f26,f1
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f26.f64, ctx.f1.f64)));
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
loc_82366D8C:
	// fsubs f13,f0,f30
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r4,r1,288
	ctx.r4.s64 = ctx.r1.s64 + 288;
	// stfs f31,248(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// fsubs f12,f31,f27
	ctx.f12.f64 = double(float(ctx.f31.f64 - ctx.f27.f64));
	// stfs f31,244(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r6,r1,272
	ctx.r6.s64 = ctx.r1.s64 + 272;
	// stfs f31,240(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f31,252(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r5,r1,304
	ctx.r5.s64 = ctx.r1.s64 + 304;
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// fdivs f0,f13,f29
	ctx.f0.f64 = double(float(ctx.f13.f64 / ctx.f29.f64));
	// stvx128 v62,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmadds f0,f0,f23,f24
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f23.f64, ctx.f24.f64)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fdivs f13,f12,f28
	ctx.f13.f64 = double(float(ctx.f12.f64 / ctx.f28.f64));
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// fmadds f13,f13,f21,f22
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f21.f64, ctx.f22.f64)));
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,288(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 288);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// ld r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// stfs f13,276(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// stfs f13,284(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f13,280(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f13,272(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f11,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,132(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f13,224(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 224);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// bne cr6,0x82366e6c
	if (!ctx.cr6.eq) goto loc_82366E6C;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// b 0x82366e78
	goto loc_82366E78;
loc_82366E6C:
	// lwz r11,124(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// subf r11,r24,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r24.u64;
	// srawi r11,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 4;
loc_82366E78:
	// subf r10,r24,r28
	ctx.r10.u64 = ctx.r28.u64 - ctx.r24.u64;
	// srawi r10,r10,4
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82366ec0
	if (!ctx.cr6.lt) goto loc_82366EC0;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82366eb4
	if (ctx.cr6.eq) goto loc_82366EB4;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// stw r9,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// stw r8,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r8.u32);
	// stw r11,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r11.u32);
loc_82366EB4:
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// b 0x82366ed8
	goto loc_82366ED8;
loc_82366EC0:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82367e38
	ctx.lr = 0x82366ED0;
	sub_82367E38(ctx, base);
	// lwz r28,120(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r24,116(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_82366ED8:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82366d18
	if (!ctx.cr6.gt) goto loc_82366D18;
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82366cb4
	if (!ctx.cr6.gt) goto loc_82366CB4;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// stw r23,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r23.u32);
	// mr r21,r23
	ctx.r21.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x823675e0
	if (!ctx.cr6.gt) goto loc_823675E0;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f29,100(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 100);
	ctx.f29.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f28,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f28.f64 = double(temp.f32);
	// lis r9,-32115
	ctx.r9.s64 = -2104688640;
	// lfs f27,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r19,-32111
	ctx.r19.s64 = -2104426496;
	// lis r22,-32111
	ctx.r22.s64 = -2104426496;
	// addi r18,r11,-32576
	ctx.r18.s64 = ctx.r11.s64 + -32576;
	// addi r17,r10,712
	ctx.r17.s64 = ctx.r10.s64 + 712;
	// addi r20,r9,22072
	ctx.r20.s64 = ctx.r9.s64 + 22072;
	// addi r16,r8,112
	ctx.r16.s64 = ctx.r8.s64 + 112;
	// b 0x82366f48
	goto loc_82366F48;
loc_82366F44:
	// li r23,0
	ctx.r23.s64 = 0;
loc_82366F48:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// mr r25,r23
	ctx.r25.u64 = ctx.r23.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x823675d0
	if (!ctx.cr6.gt) goto loc_823675D0;
	// stfs f28,284(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// stfs f28,280(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// stfs f28,276(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r23,r30,32
	ctx.r23.s64 = ctx.r30.s64 + 32;
	// stfs f28,272(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// stfs f29,268(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f29,264(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// stfs f29,260(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f29,256(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lvx128 v125,r0,r18
	ea = (ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v126,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v127,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82366F90:
	// lfs f0,44(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 44);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f0
	ctx.f2.f64 = ctx.f0.f64;
	// fneg f1,f0
	ctx.f1.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// bl 0x825a4a40
	ctx.lr = 0x82366FA4;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// lfs f2,52(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 52);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,48(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 48);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82366FB8;
	sub_825A4A40(ctx, base);
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// stfs f30,240(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f30,244(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// stfs f30,248(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// stfs f30,252(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x82366FDC;
	sub_8221ADA0(ctx, base);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f13,620(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 620);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// lfs f11,612(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 612);
	ctx.f11.f64 = double(temp.f32);
	// stfs f13,476(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// addi r9,r1,480
	ctx.r9.s64 = ctx.r1.s64 + 480;
	// stfs f13,472(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,616(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 616);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,720
	ctx.r7.s64 = ctx.r1.s64 + 720;
	// stfs f11,124(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r6,r1,688
	ctx.r6.s64 = ctx.r1.s64 + 688;
	// stfs f11,120(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,488(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// lfs f12,608(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 608);
	ctx.f12.f64 = double(temp.f32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,468(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// stfs f13,464(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// stfs f0,492(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// stfs f0,484(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// stfs f0,480(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// lfs f2,60(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 60);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,56(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 56);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v11,v63,v126
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v126.f32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v13,v63,v126
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v126.f32)));
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddcfp128 v0,v127,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v127.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vor128 v13,v127,v127
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v127.u8));
	// vmaddcfp128 v13,v12,v13,v11
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// stvx128 v0,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825a4a40
	ctx.lr = 0x82367080;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 44);
	// li r4,96
	ctx.r4.s64 = 96;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// bl 0x825e02a0
	ctx.lr = 0x82367094;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823670f0
	if (ctx.cr0.eq) goto loc_823670F0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f15,8(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f15.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f27,12(r3)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// li r10,4
	ctx.r10.s64 = 4;
	// stb r11,0(r3)
	REX_STORE_U8(ctx.r3.u32 + 0, ctx.r11.u8);
	// stfs f15,4(r3)
	temp.f32 = float(ctx.f15.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// addi r11,r3,32
	ctx.r11.s64 = ctx.r3.s64 + 32;
	// addi r9,r11,-8
	ctx.r9.s64 = ctx.r11.s64 + -8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r11,-16
	ctx.r10.s64 = ctx.r11.s64 + -16;
	// ld r11,3456(r22)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r22.u32 + 3456);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ld r11,2880(r19)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r19.u32 + 2880);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
loc_823670D4:
	// ld r11,3456(r22)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r22.u32 + 3456);
	// stdu r11,16(r10)
	ea = 16 + ctx.r10.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r10.u32 = ea;
	// ld r11,3456(r22)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r22.u32 + 3456);
	// stdu r11,16(r9)
	ea = 16 + ctx.r9.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r9.u32 = ea;
	// bdnz 0x823670d4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823670D4;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x823670f4
	goto loc_823670F4;
loc_823670F0:
	// li r31,0
	ctx.r31.s64 = 0;
loc_823670F4:
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// addi r7,r1,496
	ctx.r7.s64 = ctx.r1.s64 + 496;
	// addi r9,r31,32
	ctx.r9.s64 = ctx.r31.s64 + 32;
	// addi r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 1;
	// addi r11,r31,48
	ctx.r11.s64 = ctx.r31.s64 + 48;
	// mullw r11,r10,r21
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r21.s32);
	// add r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 + ctx.r25.u64;
	// addi r11,r31,64
	ctx.r11.s64 = ctx.r31.s64 + 64;
	// rlwinm r8,r10,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// addi r11,r31,80
	ctx.r11.s64 = ctx.r31.s64 + 80;
	// add r11,r8,r24
	ctx.r11.u64 = ctx.r8.u64 + ctx.r24.u64;
	// addi r6,r11,16
	ctx.r6.s64 = ctx.r11.s64 + 16;
	// lwzx r8,r8,r24
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r24.u32);
	// stw r8,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r8.u32);
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r8.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r8,40(r31)
	REX_STORE_U32(ctx.r31.u32 + 40, ctx.r8.u32);
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// stw r8,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r8.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// rlwinm r8,r8,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// add r6,r8,r24
	ctx.r6.u64 = ctx.r8.u64 + ctx.r24.u64;
	// lwzx r8,r8,r24
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r24.u32);
	// stw r8,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r8.u32);
	// lwz r8,4(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// stw r8,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r8.u32);
	// lwz r8,8(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r8,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r8.u32);
	// lwz r8,12(r6)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// addi r6,r1,640
	ctx.r6.s64 = ctx.r1.s64 + 640;
	// stw r8,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r8.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// add r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 + ctx.r24.u64;
	// lwzx r10,r10,r24
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r24.u32);
	// stw r10,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r10.u32);
	// lwz r10,4(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// stw r10,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r10.u32);
	// lwz r10,8(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// stw r10,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r10.u32);
	// lwz r10,12(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// stw r10,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// lwz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// stw r10,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r10.u32);
	// lwz r11,28(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 28);
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,508(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// addi r11,r1,528
	ctx.r11.s64 = ctx.r1.s64 + 528;
	// stfs f0,504(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// stfs f0,500(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f0,496(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// lfs f12,36(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 36);
	ctx.f12.f64 = double(temp.f32);
	// lfs f11,52(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 52);
	ctx.f11.f64 = double(temp.f32);
	// lfs f0,64(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 64);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,32(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 32);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,540(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,592
	ctx.r7.s64 = ctx.r1.s64 + 592;
	// stfs f11,572(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// stfs f13,536(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// stfs f13,532(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// stfs f13,528(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// stfs f11,568(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// stfs f11,564(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// stfs f11,560(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f12,348(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// stfs f12,344(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f12,340(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f12,336(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stfs f0,604(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 604, temp.u32);
	// stfs f0,600(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,560
	ctx.r10.s64 = ctx.r1.s64 + 560;
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// stfs f0,596(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// addi r28,r1,368
	ctx.r28.s64 = ctx.r1.s64 + 368;
	// stfs f0,592(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// addi r4,r1,544
	ctx.r4.s64 = ctx.r1.s64 + 544;
	// lfs f0,80(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,816
	ctx.r3.s64 = ctx.r1.s64 + 816;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// addi r29,r1,672
	ctx.r29.s64 = ctx.r1.s64 + 672;
	// stfs f0,376(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// addi r11,r1,832
	ctx.r11.s64 = ctx.r1.s64 + 832;
	// stfs f0,372(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// addi r26,r1,512
	ctx.r26.s64 = ctx.r1.s64 + 512;
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stw r11,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r11.u32);
	// addi r27,r1,448
	ctx.r27.s64 = ctx.r1.s64 + 448;
	// lfs f13,68(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f13.f64 = double(temp.f32);
	// addi r15,r1,384
	ctx.r15.s64 = ctx.r1.s64 + 384;
	// stfs f13,396(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// stfs f13,392(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// addi r14,r1,704
	ctx.r14.s64 = ctx.r1.s64 + 704;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,4
	ctx.r11.s64 = 4;
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r10,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// lfs f0,640(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 640);
	ctx.f0.f64 = double(temp.f32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,556(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// addi r10,r9,-16
	ctx.r10.s64 = ctx.r9.s64 + -16;
	// stfs f0,548(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// stfs f0,552(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// addi r11,r1,320
	ctx.r11.s64 = ctx.r1.s64 + 320;
	// stfs f0,544(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// addi r9,r1,576
	ctx.r9.s64 = ctx.r1.s64 + 576;
	// lfs f0,84(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r31,16
	ctx.r8.s64 = ctx.r31.s64 + 16;
	// stfs f0,428(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 428, temp.u32);
	// stfs f0,424(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 424, temp.u32);
	// stfs f0,420(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,816(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 816);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r7,160(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 160);
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,388(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// stfs f13,384(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// lvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,524(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// stfs f0,520(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// stfs f0,512(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stfs f0,516(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// lvx128 v62,r0,r15
	ea = (ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v60,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v60.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,672(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 672);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,460(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f0,456(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f0,452(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f0,448(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// stvx128 v62,r0,r14
	ea = (ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,704(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 704);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,588(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// lvx128 v61,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,584(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f0,580(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f0,576(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,832(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 832);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,332(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stfs f13,328(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// lwz r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,320(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// addi r5,r1,352
	ctx.r5.s64 = ctx.r1.s64 + 352;
	// addi r7,r1,736
	ctx.r7.s64 = ctx.r1.s64 + 736;
	// addi r4,r1,848
	ctx.r4.s64 = ctx.r1.s64 + 848;
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,800
	ctx.r6.s64 = ctx.r1.s64 + 800;
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v125
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v125.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,800(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 800);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,364(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// stfs f0,360(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// stfs f0,356(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// stfs f0,352(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// lfs f0,736(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 736);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v125
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v125.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,848(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 848);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,16(r31)
	REX_STORE_U64(ctx.r31.u32 + 16, ctx.r11.u64);
loc_823673E8:
	// lfs f13,0(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// stfs f13,444(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// addi r11,r1,400
	ctx.r11.s64 = ctx.r1.s64 + 400;
	// stfs f13,440(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// addi r7,r1,768
	ctx.r7.s64 = ctx.r1.s64 + 768;
	// stfs f13,436(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// addi r5,r1,288
	ctx.r5.s64 = ctx.r1.s64 + 288;
	// stfs f13,432(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// addi r6,r1,304
	ctx.r6.s64 = ctx.r1.s64 + 304;
	// lfs f0,16(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,656
	ctx.r4.s64 = ctx.r1.s64 + 656;
	// stfs f0,412(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// stfs f0,408(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// stfs f0,400(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,20(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,300(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f13,292(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// stfs f13,296(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// stfs f13,288(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// lfs f0,4(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,316(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f0,312(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f0,304(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// stfs f0,308(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,768(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 768);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,656(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 656);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// ld r11,192(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// stdu r11,16(r10)
	ea = 16 + ctx.r10.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r10.u32 = ea;
	// bdnz 0x823673e8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823673E8;
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// lfs f13,688(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 688);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// lfs f0,720(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 720);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,752
	ctx.r8.s64 = ctx.r1.s64 + 752;
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r7,r1,784
	ctx.r7.s64 = ctx.r1.s64 + 784;
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// li r4,12
	ctx.r4.s64 = 12;
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// stfs f31,88(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f31,84(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f31,92(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f30,4(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,752(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 752);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lfs f0,784(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 784);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// ld r11,176(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 176);
	// std r11,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r11.u64);
	// lwz r28,4(r23)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r23.u32 + 4);
	// lwz r3,44(r20)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r20.u32 + 44);
	// lwz r26,4(r28)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82367528;
	sub_825E02A0(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq 0x82367534
	if (ctx.cr0.eq) goto loc_82367534;
	// stw r28,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r28.u32);
loc_82367534:
	// addic. r27,r29,4
	ctx.xer.ca = ctx.r29.u32 > 4294967291;
	ctx.r27.s64 = ctx.r29.s64 + 4;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x82367540
	if (ctx.cr0.eq) goto loc_82367540;
	// stw r26,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r26.u32);
loc_82367540:
	// addic. r11,r29,8
	ctx.xer.ca = ctx.r29.u32 > 4294967287;
	ctx.r11.s64 = ctx.r29.s64 + 8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8236754c
	if (ctx.cr0.eq) goto loc_8236754C;
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
loc_8236754C:
	// lis r11,16383
	ctx.r11.s64 = 1073676288;
	// lwz r10,8(r23)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// ori r11,r11,65535
	ctx.r11.u64 = ctx.r11.u64 | 65535;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x8236759c
	if (!ctx.cr6.lt) goto loc_8236759C;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x822167f8
	ctx.lr = 0x82367570;
	sub_822167F8(ctx, base);
	// addi r4,r1,864
	ctx.r4.s64 = ctx.r1.s64 + 864;
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x82216678
	ctx.lr = 0x8236757C;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x82367580;
	sub_82216E60(ctx, base);
	// stw r16,896(r1)
	REX_STORE_U32(ctx.r1.u32 + 896, ctx.r16.u32);
	// addi r3,r1,896
	ctx.r3.s64 = ctx.r1.s64 + 896;
	// bl 0x82216d98
	ctx.lr = 0x8236758C;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,864
	ctx.r3.s64 = ctx.r1.s64 + 864;
	// bl 0x8235ec48
	ctx.lr = 0x8236759C;
	sub_8235EC48(ctx, base);
loc_8236759C:
	// lwz r11,8(r23)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r23.u32 + 8);
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,8(r23)
	REX_STORE_U32(ctx.r23.u32 + 8, ctx.r11.u32);
	// stw r29,4(r28)
	REX_STORE_U32(ctx.r28.u32 + 4, ctx.r29.u32);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stw r29,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r11.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// cmplw cr6,r25,r11
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82366f90
	if (ctx.cr6.lt) goto loc_82366F90;
loc_823675D0:
	// lwz r11,16(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// cmplw cr6,r21,r11
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82366f44
	if (ctx.cr6.lt) goto loc_82366F44;
loc_823675E0:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x823675f0
	if (ctx.cr6.eq) goto loc_823675F0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x825e0378
	ctx.lr = 0x823675F0;
	sub_825E0378(ctx, base);
loc_823675F0:
	// addi r1,r1,1280
	ctx.r1.s64 = ctx.r1.s64 + 1280;
	// li r0,-336
	ctx.r0.s64 = -336;
	// lvx128 v125,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v125.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-320
	ctx.r0.s64 = -320;
	// lvx128 v126,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-304
	ctx.r0.s64 = -304;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af40
	ctx.lr = 0x82367614;
	__restfpr_15(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823CB3A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823CB3B0;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af24
	ctx.lr = 0x823CB3B8;
	__savefpr_27(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,36(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823cb5b4
	if (!ctx.cr0.eq) goto loc_823CB5B4;
	// lwz r10,12(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// ble cr6,0x823cb5b4
	if (!ctx.cr6.gt) goto loc_823CB5B4;
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// lfs f4,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f4.f64 = double(temp.f32);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// extsw r8,r8
	ctx.r8.s64 = ctx.r8.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r28,r9,1608
	ctx.r28.s64 = ctx.r9.s64 + 1608;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// lfs f28,-3796(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -3796);
	ctx.f28.f64 = double(temp.f32);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// fmuls f0,f0,f4
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f4.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// fcmpu cr6,f0,f28
	ctx.cr6.compare(ctx.f0.f64, ctx.f28.f64);
	// ble cr6,0x823cb438
	if (!ctx.cr6.gt) goto loc_823CB438;
	// fmr f28,f0
	ctx.f28.f64 = ctx.f0.f64;
loc_823CB438:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r27,r11,14376
	ctx.r27.s64 = ctx.r11.s64 + 14376;
	// bne cr6,0x823cb450
	if (!ctx.cr6.eq) goto loc_823CB450;
	// lfs f30,-1908(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -1908);
	ctx.f30.f64 = double(temp.f32);
	// b 0x823cb484
	goto loc_823CB484;
loc_823CB450:
	// extsw r10,r10
	ctx.r10.s64 = ctx.r10.s32;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lwa r11,20(r31)
	ctx.r11.s64 = int32_t(REX_LOAD_U32(ctx.r31.u32 + 20));
	// fsubs f0,f4,f28
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f4.f64 - ctx.f28.f64));
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// fdivs f30,f0,f13
	ctx.f30.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
loc_823CB484:
	// lbz r11,28(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 28);
	// li r29,0
	ctx.r29.s64 = 0;
	// li r30,-1
	ctx.r30.s64 = -1;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823cb4c0
	if (ctx.cr0.eq) goto loc_823CB4C0;
	// stb r29,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r29.u8);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f3,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lfs f2,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f2.f64 = double(temp.f32);
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r6,24(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lfs f1,-30128(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823c67c0
	ctx.lr = 0x823CB4C0;
	sub_823C67C0(ctx, base);
loc_823CB4C0:
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f31,-8020(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -8020);
	ctx.f31.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lfs f29,-1904(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + -1904);
	ctx.f29.f64 = double(temp.f32);
	// li r4,9
	ctx.r4.s64 = 9;
	// lfs f27,-10564(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -10564);
	ctx.f27.f64 = double(temp.f32);
	// lwz r6,24(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// fsubs f2,f13,f31
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f31.f64));
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// stb r29,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r29.u8);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// fsubs f3,f0,f27
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f27.f64));
	// bl 0x823c67c0
	ctx.lr = 0x823CB504;
	sub_823C67C0(ctx, base);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// li r4,10
	ctx.r4.s64 = 10;
	// lwz r6,24(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// fmr f4,f28
	ctx.f4.f64 = ctx.f28.f64;
	// stb r29,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r29.u8);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// fadds f3,f0,f30
	ctx.f3.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// fsubs f2,f13,f31
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f31.f64));
	// bl 0x823c67c0
	ctx.lr = 0x823CB538;
	sub_823C67C0(ctx, base);
	// lfs f0,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fadds f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lfs f13,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lwz r6,24(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// stb r29,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r29.u8);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// fsubs f2,f13,f31
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f31.f64));
	// fadds f0,f0,f28
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f28.f64));
	// fsubs f3,f0,f27
	ctx.f3.f64 = double(float(ctx.f0.f64 - ctx.f27.f64));
	// bl 0x823c67c0
	ctx.lr = 0x823CB574;
	sub_823C67C0(ctx, base);
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// fmadds f13,f28,f0,f30
	ctx.f13.f64 = double(float(std::fma(ctx.f28.f64, ctx.f0.f64, ctx.f30.f64)));
	// lfs f0,-984(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,4(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f12.f64 = double(temp.f32);
	// mr r9,r30
	ctx.r9.u64 = ctx.r30.u64;
	// lfs f11,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
	// li r4,12
	ctx.r4.s64 = 12;
	// lfs f1,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lwz r6,24(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r3,36(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// fmr f4,f29
	ctx.f4.f64 = ctx.f29.f64;
	// stb r29,95(r1)
	REX_STORE_U8(ctx.r1.u32 + 95, ctx.r29.u8);
	// fadds f3,f13,f12
	ctx.f3.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// fadds f2,f11,f0
	ctx.f2.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// bl 0x823c67c0
	ctx.lr = 0x823CB5B4;
	sub_823C67C0(ctx, base);
loc_823CB5B4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af70
	ctx.lr = 0x823CB5C0;
	__restfpr_27(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823DAF18) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// b 0x823dc7d0
	sub_823DC7D0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823DB098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x823DB0A0;
	__savegprlr_24(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,240(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 240);
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82457b58
	ctx.lr = 0x823DB0B4;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x823DB0B8;
	sub_825FD7A0(ctx, base);
	// stw r3,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dcfc8
	ctx.lr = 0x823DB0C4;
	sub_823DCFC8(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r30,r11,22072
	ctx.r30.s64 = ctx.r11.s64 + 22072;
	// li r4,188
	ctx.r4.s64 = 188;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823DB0DC;
	sub_825E02A0(ctx, base);
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823db0fc
	if (ctx.cr0.eq) goto loc_823DB0FC;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lwz r4,9852(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 9852);
	// bl 0x823bdc58
	ctx.lr = 0x823DB0F4;
	sub_823BDC58(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// b 0x823db100
	goto loc_823DB100;
loc_823DB0FC:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_823DB100:
	// li r10,10
	ctx.r10.s64 = 10;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r10.u32);
	// bl 0x823dd740
	ctx.lr = 0x823DB114;
	sub_823DD740(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dd8e8
	ctx.lr = 0x823DB11C;
	sub_823DD8E8(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823DB12C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823db13c
	if (ctx.cr0.eq) goto loc_823DB13C;
	// bl 0x823c8308
	ctx.lr = 0x823DB138;
	sub_823C8308(ctx, base);
	// b 0x823db140
	goto loc_823DB140;
loc_823DB13C:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_823DB140:
	// stw r3,212(r31)
	REX_STORE_U32(ctx.r31.u32 + 212, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823DB160;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823db170
	if (ctx.cr0.eq) goto loc_823DB170;
	// bl 0x823c8308
	ctx.lr = 0x823DB16C;
	sub_823C8308(ctx, base);
	// b 0x823db174
	goto loc_823DB174;
loc_823DB170:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_823DB174:
	// stw r3,216(r31)
	REX_STORE_U32(ctx.r31.u32 + 216, ctx.r3.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r10,240(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x823DB194;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x823db1a4
	if (ctx.cr0.eq) goto loc_823DB1A4;
	// bl 0x823c8308
	ctx.lr = 0x823DB1A0;
	sub_823C8308(ctx, base);
	// b 0x823db1a8
	goto loc_823DB1A8;
loc_823DB1A4:
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
loc_823DB1A8:
	// stw r3,224(r31)
	REX_STORE_U32(ctx.r31.u32 + 224, ctx.r3.u32);
	// li r11,7
	ctx.r11.s64 = 7;
	// addi r30,r31,312
	ctx.r30.s64 = ctx.r31.s64 + 312;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r9,240(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 240);
	// stw r9,8(r10)
	REX_STORE_U32(ctx.r10.u32 + 8, ctx.r9.u32);
	// stw r29,292(r31)
	REX_STORE_U32(ctx.r31.u32 + 292, ctx.r29.u32);
	// stw r11,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r11.u32);
	// lwz r11,320(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 320);
	// lwz r10,316(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 316);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823db208
	if (ctx.cr6.eq) goto loc_823DB208;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// cmplw cr6,r11,r11
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823db204
	if (ctx.cr6.eq) goto loc_823DB204;
loc_823DB1E4:
	// lbz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 0);
	// stb r8,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r8.u8);
	// lbz r8,1(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 1);
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// stb r8,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r8.u8);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// bne cr6,0x823db1e4
	if (!ctx.cr6.eq) goto loc_823DB1E4;
loc_823DB204:
	// stw r10,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
loc_823DB208:
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// lwz r7,-12856(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + -12856);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x823db22c
	if (ctx.cr6.eq) goto loc_823DB22C;
	// lwz r11,208(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 208);
	// lwz r10,204(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 204);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_823DB22C:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x823db43c
	if (!ctx.cr6.gt) goto loc_823DB43C;
	// mr r26,r24
	ctx.r26.u64 = ctx.r24.u64;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
loc_823DB23C:
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x823db254
	if (ctx.cr6.eq) goto loc_823DB254;
	// lwz r11,204(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 204);
	// lwzx r11,r11,r26
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r26.u32);
	// lwz r29,0(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_823DB254:
	// bl 0x82213210
	ctx.lr = 0x823DB258;
	sub_82213210(ctx, base);
	// addi r11,r29,-1
	ctx.r11.s64 = ctx.r29.s64 + -1;
	// addi r10,r3,4120
	ctx.r10.s64 = ctx.r3.s64 + 4120;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// blt cr6,0x823db270
	if (ctx.cr6.lt) goto loc_823DB270;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// b 0x823db284
	goto loc_823DB284;
loc_823DB270:
	// addi r11,r11,7006
	ctx.r11.s64 = ctx.r11.s64 + 7006;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r11,r11,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r10.u32);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_823DB284:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823db42c
	if (ctx.cr0.eq) goto loc_823DB42C;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// clrlwi r28,r29,24
	ctx.r28.u64 = ctx.r29.u32 & 0xFF;
	// stb r24,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r24.u8);
	// stb r28,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r28.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823db2ac
	if (!ctx.cr6.eq) goto loc_823DB2AC;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// b 0x823db2b8
	goto loc_823DB2B8;
loc_823DB2AC:
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
loc_823DB2B8:
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823db2e8
	if (!ctx.cr6.lt) goto loc_823DB2E8;
	// cmplwi r4,0
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq 0x823db2dc
	if (ctx.cr0.eq) goto loc_823DB2DC;
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// sth r11,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r11.u16);
loc_823DB2DC:
	// addi r11,r4,2
	ctx.r11.s64 = ctx.r4.s64 + 2;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// b 0x823db2f4
	goto loc_823DB2F4;
loc_823DB2E8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823de458
	ctx.lr = 0x823DB2F4;
	sub_823DE458(ctx, base);
loc_823DB2F4:
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// stb r28,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r28.u8);
	// stb r10,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823db314
	if (!ctx.cr6.eq) goto loc_823DB314;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// b 0x823db320
	goto loc_823DB320;
loc_823DB314:
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
loc_823DB320:
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823db350
	if (!ctx.cr6.lt) goto loc_823DB350;
	// cmplwi r4,0
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq 0x823db344
	if (ctx.cr0.eq) goto loc_823DB344;
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// sth r11,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r11.u16);
loc_823DB344:
	// addi r11,r4,2
	ctx.r11.s64 = ctx.r4.s64 + 2;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// b 0x823db35c
	goto loc_823DB35C;
loc_823DB350:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823de458
	ctx.lr = 0x823DB35C;
	sub_823DE458(ctx, base);
loc_823DB35C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82577128
	ctx.lr = 0x823DB364;
	sub_82577128(ctx, base);
	// lwz r7,-12856(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + -12856);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x823db378
	if (!ctx.cr0.lt) goto loc_823DB378;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// b 0x823db3bc
	goto loc_823DB3BC;
loc_823DB378:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x823db3b4
	if (ctx.cr6.eq) goto loc_823DB3B4;
	// lwz r11,204(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 204);
	// rlwinm r10,r3,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// addi r11,r11,92
	ctx.r11.s64 = ctx.r11.s64 + 92;
	// lwz r10,24(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// blt cr6,0x823db3a8
	if (ctx.cr6.lt) goto loc_823DB3A8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// b 0x823db3ac
	goto loc_823DB3AC;
loc_823DB3A8:
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
loc_823DB3AC:
	// bl 0x8257d3e8
	ctx.lr = 0x823DB3B0;
	sub_8257D3E8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_823DB3B4:
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r11,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
loc_823DB3BC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823db430
	if (ctx.cr0.eq) goto loc_823DB430;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// li r10,2
	ctx.r10.s64 = 2;
	// stb r28,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r28.u8);
	// stb r10,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r10.u8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x823db3e4
	if (!ctx.cr6.eq) goto loc_823DB3E4;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// b 0x823db3f0
	goto loc_823DB3F0;
loc_823DB3E4:
	// lwz r10,12(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
loc_823DB3F0:
	// lwz r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x823db420
	if (!ctx.cr6.lt) goto loc_823DB420;
	// cmplwi r4,0
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq 0x823db414
	if (ctx.cr0.eq) goto loc_823DB414;
	// lhz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// sth r11,0(r4)
	REX_STORE_U16(ctx.r4.u32 + 0, ctx.r11.u16);
loc_823DB414:
	// addi r11,r4,2
	ctx.r11.s64 = ctx.r4.s64 + 2;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// b 0x823db430
	goto loc_823DB430;
loc_823DB420:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x823de458
	ctx.lr = 0x823DB42C;
	sub_823DE458(ctx, base);
loc_823DB42C:
	// lwz r7,-12856(r27)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r27.u32 + -12856);
loc_823DB430:
	// addic. r25,r25,-1
	ctx.xer.ca = ctx.r25.u32 > 0;
	ctx.r25.s64 = ctx.r25.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// addi r26,r26,4
	ctx.r26.s64 = ctx.r26.s64 + 4;
	// bne 0x823db23c
	if (!ctx.cr0.eq) goto loc_823DB23C;
loc_823DB43C:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// stw r11,268(r31)
	REX_STORE_U32(ctx.r31.u32 + 268, ctx.r11.u32);
	// bl 0x82213210
	ctx.lr = 0x823DB454;
	sub_82213210(ctx, base);
	// lbz r11,4039(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4039);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x823db470
	if (!ctx.cr0.eq) goto loc_823DB470;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// bgt cr6,0x823db474
	if (ctx.cr6.gt) goto loc_823DB474;
loc_823DB470:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_823DB474:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r11,291(r31)
	REX_STORE_U8(ctx.r31.u32 + 291, ctx.r11.u8);
	// bne 0x823db58c
	if (!ctx.cr0.eq) goto loc_823DB58C;
	// li r30,96
	ctx.r30.s64 = 96;
	// lwz r3,12(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// li r27,255
	ctx.r27.s64 = 255;
	// stb r30,84(r1)
	REX_STORE_U8(ctx.r1.u32 + 84, ctx.r30.u8);
	// addi r4,r1,84
	ctx.r4.s64 = ctx.r1.s64 + 84;
	// stb r27,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r27.u8);
	// stb r30,85(r1)
	REX_STORE_U8(ctx.r1.u32 + 85, ctx.r30.u8);
	// stb r30,86(r1)
	REX_STORE_U8(ctx.r1.u32 + 86, ctx.r30.u8);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823DB4B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r10,20
	ctx.r10.s64 = 20;
	// stw r10,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r10.u32);
	// li r9,21
	ctx.r9.s64 = 21;
	// li r8,22
	ctx.r8.s64 = 22;
	// li r10,23
	ctx.r10.s64 = 23;
	// stw r9,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r9.u32);
	// stw r8,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r8.u32);
	// li r9,24
	ctx.r9.s64 = 24;
	// stw r10,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r10.u32);
	// li r8,25
	ctx.r8.s64 = 25;
	// li r10,27
	ctx.r10.s64 = 27;
	// stw r9,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// stw r8,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r8.u32);
	// li r9,28
	ctx.r9.s64 = 28;
	// stw r10,136(r1)
	REX_STORE_U32(ctx.r1.u32 + 136, ctx.r10.u32);
	// li r8,29
	ctx.r8.s64 = 29;
	// li r10,30
	ctx.r10.s64 = 30;
	// stw r9,140(r1)
	REX_STORE_U32(ctx.r1.u32 + 140, ctx.r9.u32);
	// stw r8,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r8.u32);
	// li r9,31
	ctx.r9.s64 = 31;
	// stw r10,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r10.u32);
	// li r8,33
	ctx.r8.s64 = 33;
	// li r10,34
	ctx.r10.s64 = 34;
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// stw r8,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r8.u32);
	// li r9,32
	ctx.r9.s64 = 32;
	// stw r10,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r10.u32);
	// li r8,35
	ctx.r8.s64 = 35;
	// li r10,36
	ctx.r10.s64 = 36;
	// stw r9,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r9.u32);
	// stw r8,168(r1)
	REX_STORE_U32(ctx.r1.u32 + 168, ctx.r8.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r10,172(r1)
	REX_STORE_U32(ctx.r1.u32 + 172, ctx.r10.u32);
	// li r9,37
	ctx.r9.s64 = 37;
	// li r8,38
	ctx.r8.s64 = 38;
	// li r10,40
	ctx.r10.s64 = 40;
	// stw r9,176(r1)
	REX_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// stw r8,180(r1)
	REX_STORE_U32(ctx.r1.u32 + 180, ctx.r8.u32);
	// addi r28,r11,-4
	ctx.r28.s64 = ctx.r11.s64 + -4;
	// stw r10,184(r1)
	REX_STORE_U32(ctx.r1.u32 + 184, ctx.r10.u32);
	// li r29,19
	ctx.r29.s64 = 19;
loc_823DB554:
	// stb r30,88(r1)
	REX_STORE_U8(ctx.r1.u32 + 88, ctx.r30.u8);
	// addi r4,r1,88
	ctx.r4.s64 = ctx.r1.s64 + 88;
	// stb r30,90(r1)
	REX_STORE_U8(ctx.r1.u32 + 90, ctx.r30.u8);
	// stb r30,89(r1)
	REX_STORE_U8(ctx.r1.u32 + 89, ctx.r30.u8);
	// stb r27,91(r1)
	REX_STORE_U8(ctx.r1.u32 + 91, ctx.r27.u8);
	// lwzu r11,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823DB584;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x823db554
	if (!ctx.cr0.eq) goto loc_823DB554;
loc_823DB58C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r11,-12848(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12848);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x823db5b0
	if (ctx.cr6.eq) goto loc_823DB5B0;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// b 0x823db5b4
	goto loc_823DB5B4;
loc_823DB5B0:
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
loc_823DB5B4:
	// stw r11,272(r31)
	REX_STORE_U32(ctx.r31.u32 + 272, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r24,276(r31)
	REX_STORE_U32(ctx.r31.u32 + 276, ctx.r24.u32);
	// stw r24,280(r31)
	REX_STORE_U32(ctx.r31.u32 + 280, ctx.r24.u32);
	// stw r24,284(r31)
	REX_STORE_U32(ctx.r31.u32 + 284, ctx.r24.u32);
	// bl 0x823ddb30
	ctx.lr = 0x823DB5CC;
	sub_823DDB30(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lwz r10,284(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// addi r29,r31,228
	ctx.r29.s64 = ctx.r31.s64 + 228;
	// addi r28,r11,-4
	ctx.r28.s64 = ctx.r11.s64 + -4;
	// li r30,2
	ctx.r30.s64 = 2;
	// stw r10,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r10.u32);
	// lwz r11,280(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
loc_823DB5EC:
	// lwz r11,4(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// lwz r3,36(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// bl 0x823bdef8
	ctx.lr = 0x823DB5F8;
	sub_823BDEF8(ctx, base);
	// lwzu r11,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r11.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwzu r10,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// stw r11,20(r10)
	REX_STORE_U32(ctx.r10.u32 + 20, ctx.r11.u32);
	// bne 0x823db5ec
	if (!ctx.cr0.eq) goto loc_823DB5EC;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ddf30
	ctx.lr = 0x823DB618;
	sub_823DDF30(ctx, base);
	// mr r30,r24
	ctx.r30.u64 = ctx.r24.u64;
loc_823DB61C:
	// bl 0x82213210
	ctx.lr = 0x823DB620;
	sub_82213210(ctx, base);
	// add r11,r3,r30
	ctx.r11.u64 = ctx.r3.u64 + ctx.r30.u64;
	// lbz r11,4148(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 4148);
	// cmplwi cr6,r11,100
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 100, ctx.xer);
	// ble cr6,0x823db634
	if (!ctx.cr6.gt) goto loc_823DB634;
	// li r11,100
	ctx.r11.s64 = 100;
loc_823DB634:
	// clrlwi r5,r11,24
	ctx.r5.u64 = ctx.r11.u32 & 0xFF;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dd6a0
	ctx.lr = 0x823DB644;
	sub_823DD6A0(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r30,3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 3, ctx.xer);
	// blt cr6,0x823db61c
	if (ctx.cr6.lt) goto loc_823DB61C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dd1f0
	ctx.lr = 0x823DB658;
	sub_823DD1F0(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dd268
	ctx.lr = 0x823DB660;
	sub_823DD268(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823dd4e8
	ctx.lr = 0x823DB668;
	sub_823DD4E8(ctx, base);
	// lwz r4,252(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x823db67c
	if (ctx.cr6.eq) goto loc_823DB67C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823ddc58
	ctx.lr = 0x823DB67C;
	sub_823DDC58(ctx, base);
loc_823DB67C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,280(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 280);
	// lwz r4,256(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// bl 0x823ddd98
	ctx.lr = 0x823DB68C;
	sub_823DDD98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r5,284(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// lwz r4,260(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 260);
	// bl 0x823dde38
	ctx.lr = 0x823DB69C;
	sub_823DDE38(ctx, base);
	// bl 0x82213210
	ctx.lr = 0x823DB6A0;
	sub_82213210(ctx, base);
	// addi r11,r3,4120
	ctx.r11.s64 = ctx.r3.s64 + 4120;
	// li r9,3
	ctx.r9.s64 = 3;
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// addi r8,r11,28
	ctx.r8.s64 = ctx.r11.s64 + 28;
	// addi r7,r31,720
	ctx.r7.s64 = ctx.r31.s64 + 720;
	// lbz r6,31(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 31);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// stb r6,723(r31)
	REX_STORE_U8(ctx.r31.u32 + 723, ctx.r6.u8);
loc_823DB6C0:
	// lbzx r9,r8,r10
	ctx.r9.u64 = REX_LOAD_U8(ctx.r8.u32 + ctx.r10.u32);
	// stbx r9,r10,r7
	REX_STORE_U8(ctx.r10.u32 + ctx.r7.u32, ctx.r9.u8);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// bdnz 0x823db6c0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823DB6C0;
	// addi r10,r11,13532
	ctx.r10.s64 = ctx.r11.s64 + 13532;
	// addi r11,r31,336
	ctx.r11.s64 = ctx.r31.s64 + 336;
	// li r9,32
	ctx.r9.s64 = 32;
loc_823DB6DC:
	// li r8,3
	ctx.r8.s64 = 3;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_823DB6E4:
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// bdnz 0x823db6e4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823DB6E4;
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x823db6dc
	if (!ctx.cr0.eq) goto loc_823DB6DC;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82407180) {
	REX_FUNC_PROLOGUE();
	// b 0x823f99c8
	sub_823F99C8(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82407838) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82407840;
	__savegprlr_25(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r30,156(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// addi r11,r11,-31360
	ctx.r11.s64 = ctx.r11.s64 + -31360;
	// mr r25,r4
	ctx.r25.u64 = ctx.r4.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x824078b8
	if (ctx.cr6.eq) goto loc_824078B8;
	// lwz r3,32(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82407878
	if (ctx.cr6.eq) goto loc_82407878;
	// bl 0x823c74f0
	ctx.lr = 0x82407878;
	sub_823C74F0(ctx, base);
loc_82407878:
	// addi r31,r30,-4
	ctx.r31.s64 = ctx.r30.s64 + -4;
	// stw r27,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r27.u32);
	// li r29,4
	ctx.r29.s64 = 4;
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
loc_82407888:
	// lwz r11,-13064(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -13064);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824078a4
	if (ctx.cr6.eq) goto loc_824078A4;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824078a4
	if (ctx.cr6.eq) goto loc_824078A4;
	// bl 0x8235d960
	ctx.lr = 0x824078A4;
	sub_8235D960(ctx, base);
loc_824078A4:
	// addic. r29,r29,-1
	ctx.xer.ca = ctx.r29.u32 > 0;
	ctx.r29.s64 = ctx.r29.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stwu r27,4(r31)
	ea = 4 + ctx.r31.u32;
	REX_STORE_U32(ea, ctx.r27.u32);
	ctx.r31.u32 = ea;
	// bne 0x82407888
	if (!ctx.cr0.eq) goto loc_82407888;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x824078B8;
	sub_825E0378(ctx, base);
loc_824078B8:
	// stw r27,156(r28)
	REX_STORE_U32(ctx.r28.u32 + 156, ctx.r27.u32);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x823c4360
	ctx.lr = 0x824078C4;
	sub_823C4360(ctx, base);
	// clrlwi. r11,r25,31
	ctx.r11.u64 = ctx.r25.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824078d4
	if (ctx.cr0.eq) goto loc_824078D4;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x825e0378
	ctx.lr = 0x824078D4;
	sub_825E0378(ctx, base);
loc_824078D4:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8240CA20) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x823c7068
	ctx.lr = 0x8240CA40;
	sub_823C7068(ctx, base);
	// lwz r31,160(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 160);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// lbz r11,152(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 152);
	// stb r11,4(r31)
	REX_STORE_U8(ctx.r31.u32 + 4, ctx.r11.u8);
	// bl 0x82213210
	ctx.lr = 0x8240CA54;
	sub_82213210(ctx, base);
	// lbz r11,4038(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4038);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x8240cae8
	if (!ctx.cr0.eq) goto loc_8240CAE8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8240cab4
	if (ctx.cr6.eq) goto loc_8240CAB4;
	// lfs f0,20(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// fadds f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,26028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26028);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,280(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 280);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f31.f64));
	// stfs f13,280(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 280, temp.u32);
	// lfs f13,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8240cab4
	if (!ctx.cr6.gt) goto loc_8240CAB4;
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8240caac
	if (ctx.cr6.eq) goto loc_8240CAAC;
	// bl 0x823f0868
	ctx.lr = 0x8240CAAC;
	sub_823F0868(ctx, base);
loc_8240CAAC:
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r11.u32);
loc_8240CAB4:
	// bl 0x82213210
	ctx.lr = 0x8240CAB8;
	sub_82213210(ctx, base);
	// lwz r11,19228(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 19228);
	// lwz r11,2664(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 2664);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8240cae8
	if (!ctx.cr6.gt) goto loc_8240CAE8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x8240cae8
	if (!ctx.cr6.eq) goto loc_8240CAE8;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,12468(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 20, temp.u32);
	// bl 0x8240c7f0
	ctx.lr = 0x8240CAE8;
	sub_8240C7F0(ctx, base);
loc_8240CAE8:
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

DEFINE_REX_FUNC(sub_824152C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824152C8;
	__savegprlr_29(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,172(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 172);
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// lis r9,16
	ctx.r9.s64 = 1048576;
	// lis r8,16
	ctx.r8.s64 = 1048576;
	// addi r7,r1,88
	ctx.r7.s64 = ctx.r1.s64 + 88;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// ori r10,r10,263
	ctx.r10.u64 = ctx.r10.u64 | 263;
	// ori r9,r9,258
	ctx.r9.u64 = ctx.r9.u64 | 258;
	// ori r8,r8,260
	ctx.r8.u64 = ctx.r8.u64 | 260;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lwzx r5,r11,r7
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r7.u32);
	// bl 0x823c7af0
	ctx.lr = 0x82415310;
	sub_823C7AF0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82415334;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c8220
	ctx.lr = 0x8241533C;
	sub_823C8220(ctx, base);
	// addi r11,r1,88
	ctx.r11.s64 = ctx.r1.s64 + 88;
	// li r10,9
	ctx.r10.s64 = 9;
	// li r9,10
	ctx.r9.s64 = 10;
	// li r8,11
	ctx.r8.s64 = 11;
	// stw r10,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r10.u32);
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r8,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r8.u32);
	// addi r29,r11,-4
	ctx.r29.s64 = ctx.r11.s64 + -4;
loc_82415360:
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// cmpw cr6,r11,r30
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r30.s32, ctx.xer);
	// li r11,-1
	ctx.r11.s64 = -1;
	// beq cr6,0x82415374
	if (ctx.cr6.eq) goto loc_82415374;
	// li r11,255
	ctx.r11.s64 = 255;
loc_82415374:
	// rlwinm r8,r11,16,24,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFF;
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// rlwinm r7,r11,24,24,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 24) & 0xFF;
	// lwzu r10,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// stb r8,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r8.u8);
	// rlwinm r11,r11,8,24,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0xFF;
	// stb r7,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r7.u8);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r3,r10,r31
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824153B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,3
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 3, ctx.xer);
	// blt cr6,0x82415360
	if (ctx.cr6.lt) goto loc_82415360;
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r10,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r10.u32);
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// stw r11,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r11.u32);
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241FE78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8241FE80;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,184(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 184);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241fedc
	if (ctx.cr0.eq) goto loc_8241FEDC;
	// lwz r11,80(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,17(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 17);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// lwz r11,88(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// li r10,0
	ctx.r10.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stb r10,184(r3)
	REX_STORE_U8(ctx.r3.u32 + 184, ctx.r10.u8);
	// beq cr6,0x8241fec4
	if (ctx.cr6.eq) goto loc_8241FEC4;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82420634
	if (!ctx.cr6.eq) goto loc_82420634;
loc_8241FEC4:
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82420c68
	ctx.lr = 0x8241FED0;
	sub_82420C68(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,96(r31)
	REX_STORE_U8(ctx.r31.u32 + 96, ctx.r11.u8);
	// b 0x82420634
	goto loc_82420634;
loc_8241FEDC:
	// lbz r11,185(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 185);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241ff18
	if (ctx.cr0.eq) goto loc_8241FF18;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,17(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 17);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// lwz r11,188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// li r10,0
	ctx.r10.s64 = 0;
	// li r9,1
	ctx.r9.s64 = 1;
	// stb r10,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r10.u8);
	// li r3,6
	ctx.r3.s64 = 6;
	// stb r9,153(r11)
	REX_STORE_U8(ctx.r11.u32 + 153, ctx.r9.u8);
	// b 0x82420630
	goto loc_82420630;
loc_8241FF18:
	// lwz r11,172(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 172);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x824204b8
	if (ctx.cr6.lt) goto loc_824204B8;
	// beq cr6,0x82420014
	if (ctx.cr6.eq) goto loc_82420014;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x8241ffec
	if (ctx.cr6.lt) goto loc_8241FFEC;
	// beq cr6,0x8241ffc4
	if (ctx.cr6.eq) goto loc_8241FFC4;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x8241ffa8
	if (ctx.cr6.lt) goto loc_8241FFA8;
	// bne cr6,0x82420634
	if (!ctx.cr6.eq) goto loc_82420634;
	// bl 0x82213210
	ctx.lr = 0x8241FF44;
	sub_82213210(ctx, base);
	// lbz r11,4038(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 4038);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241ff58
	if (ctx.cr0.eq) goto loc_8241FF58;
	// li r11,40
	ctx.r11.s64 = 40;
	// b 0x8241ff80
	goto loc_8241FF80;
loc_8241FF58:
	// bl 0x8242a5e0
	ctx.lr = 0x8241FF5C;
	sub_8242A5E0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8241ff6c
	if (!ctx.cr0.eq) goto loc_8241FF6C;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x8241ff70
	goto loc_8241FF70;
loc_8241FF6C:
	// bl 0x8242aa28
	ctx.lr = 0x8241FF70;
	sub_8242AA28(ctx, base);
loc_8241FF70:
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// addi r11,r11,12
	ctx.r11.s64 = ctx.r11.s64 + 12;
loc_8241FF80:
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// li r30,1
	ctx.r30.s64 = 1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// li r3,6
	ctx.r3.s64 = 6;
	// stw r30,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r30.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stb r30,153(r10)
	REX_STORE_U8(ctx.r10.u32 + 153, ctx.r30.u8);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
	// b 0x82420630
	goto loc_82420630;
loc_8241FFA8:
	// lwz r11,196(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82420634
	if (ctx.cr6.eq) goto loc_82420634;
	// lbz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82420634
	if (!ctx.cr0.eq) goto loc_82420634;
	// b 0x8241ffe0
	goto loc_8241FFE0;
loc_8241FFC4:
	// lwz r3,196(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 196);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8241ffe0
	if (ctx.cr6.eq) goto loc_8241FFE0;
	// bl 0x823c7568
	ctx.lr = 0x8241FFD4;
	sub_823C7568(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r11,4
	ctx.r11.s64 = 4;
	// bne 0x8241ffe4
	if (!ctx.cr0.eq) goto loc_8241FFE4;
loc_8241FFE0:
	// li r11,5
	ctx.r11.s64 = 5;
loc_8241FFE4:
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// b 0x82420634
	goto loc_82420634;
loc_8241FFEC:
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r10,22(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 22);
	// subfic r10,r10,0
	ctx.xer.ca = ctx.r10.u32 <= 0;
	ctx.r10.u64 = static_cast<uint64_t>(0) - ctx.r10.u64;
	// subfe r10,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// addi r10,r10,5
	ctx.r10.s64 = ctx.r10.s64 + 5;
	// stw r10,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r10.u32);
	// stb r9,22(r11)
	REX_STORE_U8(ctx.r11.u32 + 22, ctx.r9.u8);
	// b 0x82420634
	goto loc_82420634;
loc_82420014:
	// lwz r29,92(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// bl 0x82213210
	ctx.lr = 0x8242001C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x8242002C;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420368
	if (ctx.cr0.eq) goto loc_82420368;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,-3
	ctx.r11.s64 = ctx.r11.s64 + -3;
	// cmplwi cr6,r11,7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 7, ctx.xer);
	// bgt cr6,0x8242035c
	if (ctx.cr6.gt) goto loc_8242035C;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bdzf 4*cr6+eq,0x824200c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824200C8;
	// bdzf 4*cr6+eq,0x82420140
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82420140;
	// bdzf 4*cr6+eq,0x824201a4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824201A4;
	// bdzf 4*cr6+eq,0x824201fc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824201FC;
	// bdzf 4*cr6+eq,0x82420254
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_82420254;
	// bdzf 4*cr6+eq,0x824202ac
	--ctx.ctr.u64;
	if (ctx.ctr.u32 == 0 && !ctx.cr6.eq) goto loc_824202AC;
	// bne cr6,0x82420304
	if (!ctx.cr6.eq) goto loc_82420304;
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x823c83b8
	ctx.lr = 0x82420080;
	sub_823C83B8(ctx, base);
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// li r11,0
	ctx.r11.s64 = 0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82420098
	if (!ctx.cr6.eq) goto loc_82420098;
	// li r10,60
	ctx.r10.s64 = 60;
	// b 0x824200a4
	goto loc_824200A4;
loc_82420098:
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// bne cr6,0x824200b8
	if (!ctx.cr6.eq) goto loc_824200B8;
	// li r10,61
	ctx.r10.s64 = 61;
loc_824200A4:
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lwz r9,188(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,136(r9)
	REX_STORE_U64(ctx.r9.u32 + 136, ctx.r10.u64);
loc_824200B8:
	// lwz r10,180(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// b 0x82420630
	goto loc_82420630;
loc_824200C8:
	// li r30,1
	ctx.r30.s64 = 1;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stb r30,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r30.u8);
	// lfs f1,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x824200E0;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8242010c
	if (!ctx.cr6.eq) goto loc_8242010C;
	// li r9,60
	ctx.r9.s64 = 60;
	// lwz r11,188(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,136(r11)
	REX_STORE_U64(ctx.r11.u32 + 136, ctx.r10.u64);
	// b 0x82420130
	goto loc_82420130;
loc_8242010C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82420130
	if (!ctx.cr6.eq) goto loc_82420130;
	// li r11,61
	ctx.r11.s64 = 61;
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_82420130:
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r30,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r30.u32);
	// b 0x82420630
	goto loc_82420630;
loc_82420140:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x82420158;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8242016c
	if (!ctx.cr6.eq) goto loc_8242016C;
	// li r11,60
	ctx.r11.s64 = 60;
	// b 0x82420178
	goto loc_82420178;
loc_8242016C:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82420190
	if (!ctx.cr6.eq) goto loc_82420190;
	// li r11,61
	ctx.r11.s64 = 61;
loc_82420178:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_82420190:
	// li r10,2
	ctx.r10.s64 = 2;
loc_82420194:
	// lwz r11,180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// li r3,4
	ctx.r3.s64 = 4;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// b 0x82420630
	goto loc_82420630;
loc_824201A4:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x824201BC;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x824201d0
	if (!ctx.cr6.eq) goto loc_824201D0;
	// li r11,60
	ctx.r11.s64 = 60;
	// b 0x824201dc
	goto loc_824201DC;
loc_824201D0:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824201f4
	if (!ctx.cr6.eq) goto loc_824201F4;
	// li r11,61
	ctx.r11.s64 = 61;
loc_824201DC:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_824201F4:
	// li r10,3
	ctx.r10.s64 = 3;
	// b 0x82420194
	goto loc_82420194;
loc_824201FC:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x82420214;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82420228
	if (!ctx.cr6.eq) goto loc_82420228;
	// li r11,60
	ctx.r11.s64 = 60;
	// b 0x82420234
	goto loc_82420234;
loc_82420228:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8242024c
	if (!ctx.cr6.eq) goto loc_8242024C;
	// li r11,61
	ctx.r11.s64 = 61;
loc_82420234:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_8242024C:
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x82420194
	goto loc_82420194;
loc_82420254:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x8242026C;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82420280
	if (!ctx.cr6.eq) goto loc_82420280;
	// li r11,60
	ctx.r11.s64 = 60;
	// b 0x8242028c
	goto loc_8242028C;
loc_82420280:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824202a4
	if (!ctx.cr6.eq) goto loc_824202A4;
	// li r11,61
	ctx.r11.s64 = 61;
loc_8242028C:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_824202A4:
	// li r10,5
	ctx.r10.s64 = 5;
	// b 0x82420194
	goto loc_82420194;
loc_824202AC:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x824202C4;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x824202d8
	if (!ctx.cr6.eq) goto loc_824202D8;
	// li r11,60
	ctx.r11.s64 = 60;
	// b 0x824202e4
	goto loc_824202E4;
loc_824202D8:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x824202fc
	if (!ctx.cr6.eq) goto loc_824202FC;
	// li r11,61
	ctx.r11.s64 = 61;
loc_824202E4:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_824202FC:
	// li r10,6
	ctx.r10.s64 = 6;
	// b 0x82420194
	goto loc_82420194;
loc_82420304:
	// li r11,1
	ctx.r11.s64 = 1;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// stb r11,185(r31)
	REX_STORE_U8(ctx.r31.u32 + 185, ctx.r11.u8);
	// lfs f1,12472(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,84(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// bl 0x823c83b8
	ctx.lr = 0x8242031C;
	sub_823C83B8(ctx, base);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82420330
	if (!ctx.cr6.eq) goto loc_82420330;
	// li r11,60
	ctx.r11.s64 = 60;
	// b 0x8242033c
	goto loc_8242033C;
loc_82420330:
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82420354
	if (!ctx.cr6.eq) goto loc_82420354;
	// li r11,61
	ctx.r11.s64 = 61;
loc_8242033C:
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r10,188(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,136(r10)
	REX_STORE_U64(ctx.r10.u32 + 136, ctx.r11.u64);
loc_82420354:
	// li r10,7
	ctx.r10.s64 = 7;
	// b 0x82420194
	goto loc_82420194;
loc_8242035C:
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// b 0x82420634
	goto loc_82420634;
loc_82420368:
	// bl 0x82213210
	ctx.lr = 0x8242036C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x8242037C;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824203a4
	if (ctx.cr0.eq) goto loc_824203A4;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r11,96(r31)
	REX_STORE_U8(ctx.r31.u32 + 96, ctx.r11.u8);
	// bl 0x82420c68
	ctx.lr = 0x8242039C;
	sub_82420C68(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82420630
	goto loc_82420630;
loc_824203A4:
	// bl 0x82213210
	ctx.lr = 0x824203A8;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8242d5f8
	ctx.lr = 0x824203BC;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824203d0
	if (!ctx.cr0.eq) goto loc_824203D0;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d5f8
	ctx.lr = 0x824203D0;
	sub_8242D5F8(ctx, base);
loc_824203D0:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8242045c
	if (ctx.cr0.eq) goto loc_8242045C;
	// bl 0x82213210
	ctx.lr = 0x824203DC;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8242d6e8
	ctx.lr = 0x824203F0;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82420404
	if (!ctx.cr0.eq) goto loc_82420404;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d6e8
	ctx.lr = 0x82420404;
	sub_8242D6E8(ctx, base);
loc_82420404:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// bge cr6,0x82420428
	if (!ctx.cr6.lt) goto loc_82420428;
	// li r11,10
	ctx.r11.s64 = 10;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_82420428:
	// lbz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 192);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82420448
	if (!ctx.cr0.eq) goto loc_82420448;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x82420448
	if (!ctx.cr6.eq) goto loc_82420448;
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
loc_82420448:
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82420634
	if (ctx.cr6.eq) goto loc_82420634;
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82420624
	goto loc_82420624;
loc_8242045C:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7df8
	ctx.lr = 0x82420464;
	sub_823C7DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7e90
	ctx.lr = 0x82420474;
	sub_823C7E90(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// li r10,3
	ctx.r10.s64 = 3;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// ble cr6,0x82420498
	if (!ctx.cr6.gt) goto loc_82420498;
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
loc_82420498:
	// lbz r11,192(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 192);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82420448
	if (!ctx.cr0.eq) goto loc_82420448;
	// lwz r11,92(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// cmpwi cr6,r11,10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 10, ctx.xer);
	// bne cr6,0x82420448
	if (!ctx.cr6.eq) goto loc_82420448;
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// b 0x82420448
	goto loc_82420448;
loc_824204B8:
	// lwz r29,88(r31)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// bl 0x82213210
	ctx.lr = 0x824204C0;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,13
	ctx.r3.s64 = 13;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x824204D0;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420534
	if (ctx.cr0.eq) goto loc_82420534;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82420510
	if (ctx.cr6.lt) goto loc_82420510;
	// beq cr6,0x82420510
	if (ctx.cr6.eq) goto loc_82420510;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x82420500
	if (ctx.cr6.lt) goto loc_82420500;
	// li r11,0
	ctx.r11.s64 = 0;
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// b 0x82420630
	goto loc_82420630;
loc_82420500:
	// li r3,4
	ctx.r3.s64 = 4;
loc_82420504:
	// li r11,2
	ctx.r11.s64 = 2;
	// stw r11,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r11.u32);
	// b 0x82420630
	goto loc_82420630;
loc_82420510:
	// li r30,1
	ctx.r30.s64 = 1;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stw r30,172(r31)
	REX_STORE_U32(ctx.r31.u32 + 172, ctx.r30.u32);
	// stb r30,184(r31)
	REX_STORE_U8(ctx.r31.u32 + 184, ctx.r30.u8);
	// lfs f1,12472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x823c83b8
	ctx.lr = 0x8242052C;
	sub_823C83B8(ctx, base);
	// li r3,4
	ctx.r3.s64 = 4;
	// b 0x82420630
	goto loc_82420630;
loc_82420534:
	// bl 0x82213210
	ctx.lr = 0x82420538;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,14
	ctx.r3.s64 = 14;
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x8242d670
	ctx.lr = 0x82420548;
	sub_8242D670(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420558
	if (ctx.cr0.eq) goto loc_82420558;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82420504
	goto loc_82420504;
loc_82420558:
	// bl 0x82213210
	ctx.lr = 0x8242055C;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8242d5f8
	ctx.lr = 0x82420570;
	sub_8242D5F8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82420584
	if (!ctx.cr0.eq) goto loc_82420584;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d5f8
	ctx.lr = 0x82420584;
	sub_8242D5F8(ctx, base);
loc_82420584:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824205d8
	if (ctx.cr0.eq) goto loc_824205D8;
	// bl 0x82213210
	ctx.lr = 0x82420590;
	sub_82213210(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// lwz r30,4(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8242d6e8
	ctx.lr = 0x824205A4;
	sub_8242D6E8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824205b8
	if (!ctx.cr0.eq) goto loc_824205B8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,17
	ctx.r3.s64 = 17;
	// bl 0x8242d6e8
	ctx.lr = 0x824205B8;
	sub_8242D6E8(ctx, base);
loc_824205B8:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// bge 0x82420614
	if (!ctx.cr0.lt) goto loc_82420614;
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x82420610
	goto loc_82420610;
loc_824205D8:
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7df8
	ctx.lr = 0x824205E0;
	sub_823C7DF8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x823c7e90
	ctx.lr = 0x824205F0;
	sub_823C7E90(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82420634
	if (ctx.cr0.eq) goto loc_82420634;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// ble cr6,0x82420614
	if (!ctx.cr6.gt) goto loc_82420614;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82420610:
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
loc_82420614:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// cmpw cr6,r11,r29
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r29.s32, ctx.xer);
	// beq cr6,0x82420634
	if (ctx.cr6.eq) goto loc_82420634;
	// li r4,0
	ctx.r4.s64 = 0;
loc_82420624:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82420c68
	ctx.lr = 0x8242062C;
	sub_82420C68(ctx, base);
	// li r3,1
	ctx.r3.s64 = 1;
loc_82420630:
	// bl 0x823c7bd8
	ctx.lr = 0x82420634;
	sub_823C7BD8(ctx, base);
loc_82420634:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82455A70) {
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
	// lwz r11,-12908(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12908);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82455ab0
	if (ctx.cr6.eq) goto loc_82455AB0;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82455ab0
	if (ctx.cr6.eq) goto loc_82455AB0;
	// li r6,60
	ctx.r6.s64 = 60;
	// addi r4,r11,12
	ctx.r4.s64 = ctx.r11.s64 + 12;
	// mr r3,r10
	ctx.r3.u64 = ctx.r10.u64;
	// bl 0x82454970
	ctx.lr = 0x82455AAC;
	sub_82454970(ctx, base);
	// b 0x82455ab4
	goto loc_82455AB4;
loc_82455AB0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82455AB4:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82455ac4
	if (ctx.cr6.eq) goto loc_82455AC4;
	// lhz r3,12(r3)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r3.u32 + 12);
	// b 0x82455ac8
	goto loc_82455AC8;
loc_82455AC4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82455AC8:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_824581E8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x824581F0;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// lwz r11,-12876(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12876);
	// addi r31,r11,52
	ctx.r31.s64 = ctx.r11.s64 + 52;
	// lwz r10,60(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// lwz r11,56(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 56);
	// subf r11,r11,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,1024
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1024, ctx.xer);
	// bge cr6,0x824582b0
	if (!ctx.cr6.lt) goto loc_824582B0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,8
	ctx.r4.s64 = 8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82458238;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82458258
	if (ctx.cr0.eq) goto loc_82458258;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r30,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r30.u32);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// sth r29,4(r3)
	REX_STORE_U16(ctx.r3.u32 + 4, ctx.r29.u16);
	// stb r10,6(r3)
	REX_STORE_U8(ctx.r3.u32 + 6, ctx.r10.u8);
	// b 0x8245825c
	goto loc_8245825C;
loc_82458258:
	// li r9,0
	ctx.r9.s64 = 0;
loc_8245825C:
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r9,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82458274
	if (!ctx.cr6.eq) goto loc_82458274;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82458280
	goto loc_82458280;
loc_82458274:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
loc_82458280:
	// lwz r4,8(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// subf r10,r10,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r10.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x824582a4
	if (!ctx.cr6.lt) goto loc_824582A4;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// b 0x824582b0
	goto loc_824582B0;
loc_824582A4:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x823849b0
	ctx.lr = 0x824582B0;
	sub_823849B0(ctx, base);
loc_824582B0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8245F928) {
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
	// lwz r30,-12864(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + -12864);
	// lwz r11,10084(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10084);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8245f9f8
	if (!ctx.cr6.eq) goto loc_8245F9F8;
	// lwz r11,10080(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 10080);
	// lbz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8245f9f8
	if (!ctx.cr0.eq) goto loc_8245F9F8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x8245f9f0
	if (!ctx.cr6.eq) goto loc_8245F9F0;
	// lwz r31,32(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// li r9,34
	ctx.r9.s64 = 34;
	// lwz r4,24(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lwz r8,128(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 128);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// lwz r7,132(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// addi r9,r31,-4
	ctx.r9.s64 = ctx.r31.s64 + -4;
	// stw r4,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r4.u32);
	// stw r11,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r11.u32);
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
loc_8245F9A0:
	// lwzu r6,4(r9)
	ea = 4 + ctx.r9.u32;
	ctx.r6.u64 = REX_LOAD_U32(ea);
	ctx.r9.u32 = ea;
	// add r10,r6,r10
	ctx.r10.u64 = ctx.r6.u64 + ctx.r10.u64;
	// bdnz 0x8245f9a0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F9A0;
	// li r9,2463
	ctx.r9.s64 = 2463;
	// stw r8,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r8.u32);
	// addi r8,r31,136
	ctx.r8.s64 = ctx.r31.s64 + 136;
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// stw r7,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r7.u32);
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_8245F9C8:
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// bdnz 0x8245f9c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8245F9C8;
	// stw r11,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r11.u32);
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// addi r3,r11,24576
	ctx.r3.s64 = ctx.r11.s64 + 24576;
	// bl 0x8245fb70
	ctx.lr = 0x8245F9E4;
	sub_8245FB70(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r3,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r3.u32);
	// b 0x8245f9f4
	goto loc_8245F9F4;
loc_8245F9F0:
	// li r11,-1
	ctx.r11.s64 = -1;
loc_8245F9F4:
	// stw r11,10084(r30)
	REX_STORE_U32(ctx.r30.u32 + 10084, ctx.r11.u32);
loc_8245F9F8:
	// lwz r3,10084(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 10084);
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

DEFINE_REX_FUNC(sub_82467BC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82467BC8;
	__savegprlr_29(ctx, base);
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af10
	ctx.lr = 0x82467BD0;
	__savefpr_22(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r29,r11,14376
	ctx.r29.s64 = ctx.r11.s64 + 14376;
	// addi r11,r10,-4080
	ctx.r11.s64 = ctx.r10.s64 + -4080;
	// lis r10,-32241
	ctx.r10.s64 = -2112946176;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// lfs f29,-1908(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1908);
	ctx.f29.f64 = double(temp.f32);
	// lfs f25,3204(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3204);
	ctx.f25.f64 = double(temp.f32);
	// lfs f26,20068(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20068);
	ctx.f26.f64 = double(temp.f32);
	// lfs f24,3200(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3200);
	ctx.f24.f64 = double(temp.f32);
	// lfs f23,3196(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3196);
	ctx.f23.f64 = double(temp.f32);
	// lfs f22,3192(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3192);
	ctx.f22.f64 = double(temp.f32);
	// lfs f28,3188(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3188);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,-136(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -136);
	ctx.f27.f64 = double(temp.f32);
loc_82467C10:
	// fmr f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f29.f64;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// fmr f30,f29
	ctx.f30.f64 = ctx.f29.f64;
	// blt cr6,0x82467ca4
	if (ctx.cr6.lt) goto loc_82467CA4;
	// beq cr6,0x82467c38
	if (ctx.cr6.eq) goto loc_82467C38;
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// bge cr6,0x82467ca8
	if (!ctx.cr6.lt) goto loc_82467CA8;
	// fmr f31,f28
	ctx.f31.f64 = ctx.f28.f64;
	// fmr f30,f26
	ctx.f30.f64 = ctx.f26.f64;
	// b 0x82467ca8
	goto loc_82467CA8;
loc_82467C38:
	// lbz r11,121(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 121);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82467c4c
	if (ctx.cr0.eq) goto loc_82467C4C;
	// fmr f31,f22
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f22.f64;
	// b 0x82467c50
	goto loc_82467C50;
loc_82467C4C:
	// fmr f31,f23
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f23.f64;
loc_82467C50:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82467c60
	if (ctx.cr6.eq) goto loc_82467C60;
	// fmr f30,f24
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f24.f64;
	// b 0x82467c64
	goto loc_82467C64;
loc_82467C60:
	// fmr f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f25.f64;
loc_82467C64:
	// lwz r3,104(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 104);
	// bl 0x8259be58
	ctx.lr = 0x82467C6C;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82467ca8
	if (ctx.cr0.eq) goto loc_82467CA8;
	// lhz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lfd f0,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fcmpu cr6,f0,f27
	ctx.cr6.compare(ctx.f0.f64, ctx.f27.f64);
	// blt cr6,0x82467ca8
	if (ctx.cr6.lt) goto loc_82467CA8;
	// fsubs f0,f0,f27
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f27.f64));
	// stfs f0,128(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 128, temp.u32);
	// b 0x82467ca8
	goto loc_82467CA8;
loc_82467CA4:
	// stfs f29,128(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r30.u32 + 128, temp.u32);
loc_82467CA8:
	// clrldi r11,r31,32
	ctx.r11.u64 = ctx.r31.u64 & 0xFFFFFFFF;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// addi r10,r31,25
	ctx.r10.s64 = ctx.r31.s64 + 25;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f0,104(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// rlwinm r11,r10,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r4,r11,r30
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// frsp f3,f0
	ctx.f3.f64 = double(float(ctx.f0.f64));
	// bl 0x82467e80
	ctx.lr = 0x82467CD8;
	sub_82467E80(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,3
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 3, ctx.xer);
	// blt cr6,0x82467c10
	if (ctx.cr6.lt) goto loc_82467C10;
	// lwz r11,72(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 72);
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bne cr6,0x82467dfc
	if (!ctx.cr6.eq) goto loc_82467DFC;
	// lwz r3,108(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 108);
	// bl 0x8259be58
	ctx.lr = 0x82467CF8;
	sub_8259BE58(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82467dfc
	if (ctx.cr0.eq) goto loc_82467DFC;
	// lhz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// lfs f0,128(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f28,f0
	ctx.f13.f64 = double(float(ctx.f28.f64 - ctx.f0.f64));
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r3,432(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 432);
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f12,104(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lbz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// bne 0x82467d84
	if (!ctx.cr0.eq) goto loc_82467D84;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r30,140
	ctx.r11.s64 = ctx.r30.s64 + 140;
loc_82467D50:
	// lwz r8,-8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -8);
	// lbz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x82467d84
	if (!ctx.cr0.eq) goto loc_82467D84;
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r8.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x82467d84
	if (!ctx.cr0.eq) goto loc_82467D84;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// cmplwi cr6,r10,2
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 2, ctx.xer);
	// blt cr6,0x82467d50
	if (ctx.cr6.lt) goto loc_82467D50;
	// b 0x82467d88
	goto loc_82467D88;
loc_82467D84:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82467D88:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82467dfc
	if (!ctx.cr0.eq) goto loc_82467DFC;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lwz r11,3652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 3652);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82467dd8
	if (ctx.cr6.eq) goto loc_82467DD8;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x82467dd0
	if (ctx.cr6.eq) goto loc_82467DD0;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x82467dc8
	if (ctx.cr6.eq) goto loc_82467DC8;
	// addi r11,r11,-5
	ctx.r11.s64 = ctx.r11.s64 + -5;
	// li r10,3
	ctx.r10.s64 = 3;
	// addic r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82467ddc
	goto loc_82467DDC;
loc_82467DC8:
	// li r4,4
	ctx.r4.s64 = 4;
	// b 0x82467ddc
	goto loc_82467DDC;
loc_82467DD0:
	// li r4,1
	ctx.r4.s64 = 1;
	// b 0x82467ddc
	goto loc_82467DDC;
loc_82467DD8:
	// li r4,2
	ctx.r4.s64 = 2;
loc_82467DDC:
	// li r11,1
	ctx.r11.s64 = 1;
	// li r9,-1
	ctx.r9.s64 = -1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r11.u8);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,984
	ctx.r6.s64 = 984;
	// bl 0x823beba0
	ctx.lr = 0x82467DFC;
	sub_823BEBA0(ctx, base);
loc_82467DFC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82468320
	ctx.lr = 0x82467E04;
	sub_82468320(ctx, base);
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-32
	ctx.r12.s64 = ctx.r1.s64 + -32;
	// bl 0x8273af5c
	ctx.lr = 0x82467E10;
	__restfpr_22(ctx, base);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824796F8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82479700;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r26,r3
	ctx.r26.u64 = ctx.r3.u64;
	// lwz r3,308(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1012(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1012);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247971C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82479760
	if (ctx.cr6.eq) goto loc_82479760;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x8247975c
	if (ctx.cr6.eq) goto loc_8247975C;
loc_8247973C:
	// li r5,40
	ctx.r5.s64 = 40;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x8247974C;
	sub_8273A030(ctx, base);
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// addi r29,r29,40
	ctx.r29.s64 = ctx.r29.s64 + 40;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x8247973c
	if (!ctx.cr6.eq) goto loc_8247973C;
loc_8247975C:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_82479760:
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1016(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1016);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479774;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824797b8
	if (ctx.cr6.eq) goto loc_824797B8;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824797b4
	if (ctx.cr6.eq) goto loc_824797B4;
loc_82479794:
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824797A4;
	sub_8273A030(ctx, base);
	// addi r30,r30,56
	ctx.r30.s64 = ctx.r30.s64 + 56;
	// addi r29,r29,56
	ctx.r29.s64 = ctx.r29.s64 + 56;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x82479794
	if (!ctx.cr6.eq) goto loc_82479794;
loc_824797B4:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_824797B8:
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1020(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824797CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,56
	ctx.r11.s64 = 56;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// li r25,-1
	ctx.r25.s64 = -1;
	// li r27,0
	ctx.r27.s64 = 0;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82479884
	if (ctx.cr0.eq) goto loc_82479884;
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1020(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479800;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,308(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,1020(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479820;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x8247987c
	goto loc_8247987C;
loc_82479828:
	// lwz r30,48(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x82479878
	if (ctx.cr6.eq) goto loc_82479878;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x82479840;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82479878
	if (ctx.cr0.eq) goto loc_82479878;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82479854;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82479878
	if (ctx.cr0.eq) goto loc_82479878;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x82479868;
	sub_82222BB0(ctx, base);
	// stw r25,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r25.u32);
	// stb r27,52(r31)
	REX_STORE_U8(ctx.r31.u32 + 52, ctx.r27.u8);
	// stb r27,53(r31)
	REX_STORE_U8(ctx.r31.u32 + 53, ctx.r27.u8);
	// stb r27,54(r31)
	REX_STORE_U8(ctx.r31.u32 + 54, ctx.r27.u8);
loc_82479878:
	// addi r31,r31,56
	ctx.r31.s64 = ctx.r31.s64 + 56;
loc_8247987C:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82479828
	if (!ctx.cr6.eq) goto loc_82479828;
loc_82479884:
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1020(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1020);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479898;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824798dc
	if (ctx.cr6.eq) goto loc_824798DC;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824798d8
	if (ctx.cr6.eq) goto loc_824798D8;
loc_824798B8:
	// li r5,56
	ctx.r5.s64 = 56;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824798C8;
	sub_8273A030(ctx, base);
	// addi r30,r30,56
	ctx.r30.s64 = ctx.r30.s64 + 56;
	// addi r29,r29,56
	ctx.r29.s64 = ctx.r29.s64 + 56;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x824798b8
	if (!ctx.cr6.eq) goto loc_824798B8;
loc_824798D8:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_824798DC:
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824798F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r11,52
	ctx.r11.s64 = 52;
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// divw. r11,r10,r11
	ctx.r11.u64 = uint32_t((ctx.r11.s32 && !(ctx.r10.s32 == INT32_MIN && ctx.r11.s32 == -1)) ? ctx.r10.s32 / ctx.r11.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824799a0
	if (ctx.cr0.eq) goto loc_824799A0;
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247991C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,308(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r31,4(r10)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,1024(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8247993C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,8(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// b 0x82479998
	goto loc_82479998;
loc_82479944:
	// lwz r30,44(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x82479994
	if (ctx.cr6.eq) goto loc_82479994;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222c98
	ctx.lr = 0x8247995C;
	sub_82222C98(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82479994
	if (ctx.cr0.eq) goto loc_82479994;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222d88
	ctx.lr = 0x82479970;
	sub_82222D88(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82479994
	if (ctx.cr0.eq) goto loc_82479994;
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x82479984;
	sub_82222BB0(ctx, base);
	// stw r25,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r25.u32);
	// stb r27,48(r31)
	REX_STORE_U8(ctx.r31.u32 + 48, ctx.r27.u8);
	// stb r27,49(r31)
	REX_STORE_U8(ctx.r31.u32 + 49, ctx.r27.u8);
	// stb r27,50(r31)
	REX_STORE_U8(ctx.r31.u32 + 50, ctx.r27.u8);
loc_82479994:
	// addi r31,r31,52
	ctx.r31.s64 = ctx.r31.s64 + 52;
loc_82479998:
	// cmplw cr6,r31,r29
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x82479944
	if (!ctx.cr6.eq) goto loc_82479944;
loc_824799A0:
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1024);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824799B4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824799f8
	if (ctx.cr6.eq) goto loc_824799F8;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x824799f4
	if (ctx.cr6.eq) goto loc_824799F4;
loc_824799D4:
	// li r5,52
	ctx.r5.s64 = 52;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x824799E4;
	sub_8273A030(ctx, base);
	// addi r30,r30,52
	ctx.r30.s64 = ctx.r30.s64 + 52;
	// addi r29,r29,52
	ctx.r29.s64 = ctx.r29.s64 + 52;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x824799d4
	if (!ctx.cr6.eq) goto loc_824799D4;
loc_824799F4:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_824799F8:
	// lwz r3,308(r26)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r26.u32 + 308);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,1028(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 1028);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82479A0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r29,4(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r31,8(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r29,r31
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82479a50
	if (ctx.cr6.eq) goto loc_82479A50;
	// mr r30,r31
	ctx.r30.u64 = ctx.r31.u64;
	// cmplw cr6,r31,r31
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x82479a4c
	if (ctx.cr6.eq) goto loc_82479A4C;
loc_82479A2C:
	// li r5,100
	ctx.r5.s64 = 100;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8273a030
	ctx.lr = 0x82479A3C;
	sub_8273A030(ctx, base);
	// addi r30,r30,100
	ctx.r30.s64 = ctx.r30.s64 + 100;
	// addi r29,r29,100
	ctx.r29.s64 = ctx.r29.s64 + 100;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x82479a2c
	if (!ctx.cr6.eq) goto loc_82479A2C;
loc_82479A4C:
	// stw r29,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r29.u32);
loc_82479A50:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824968A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x824968A8;
	__savegprlr_14(ctx, base);
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af08
	ctx.lr = 0x824968B0;
	__savefpr_20(ctx, base);
	// stwu r1,-2432(r1)
	ea = -2432 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// ld r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// addi r31,r11,12236
	ctx.r31.s64 = ctx.r11.s64 + 12236;
	// ld r11,0(r5)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r5.u32 + 0);
	// li r14,0
	ctx.r14.s64 = 0;
	// mr r25,r3
	ctx.r25.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// stw r14,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r14.u32);
	// std r10,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r10.u64);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lfs f0,1968(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 1968);
	ctx.f0.f64 = double(temp.f32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bge cr6,0x82498aec
	if (!ctx.cr6.lt) goto loc_82498AEC;
	// lis r19,-32112
	ctx.r19.s64 = -2104492032;
	// lfs f6,220(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f6.f64 = double(temp.f32);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// lwz r29,-13032(r19)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r19.u32 + -13032);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82496934
	if (ctx.cr6.eq) goto loc_82496934;
	// lfs f0,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f6
	ctx.f13.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f13,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f13.u64);
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// stfd f0,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.f0.u64);
	// lwz r3,300(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// bl 0x823ae820
	ctx.lr = 0x82496934;
	sub_823AE820(ctx, base);
loc_82496934:
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lfd f0,120(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f6,140(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f6,132(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f26,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f26.f64 = double(temp.f32);
	// stfs f26,140(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f26,136(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f26,132(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f26,128(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// stfs f26,220(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82498af4
	if (!ctx.cr0.eq) goto loc_82498AF4;
	// lfs f6,212(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f6.f64 = double(temp.f32);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82496a08
	if (ctx.cr6.eq) goto loc_82496A08;
	// fctiwz f13,f6
	ctx.f13.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f13,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f13.u64);
	// lfs f0,208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 208);
	ctx.f0.f64 = double(temp.f32);
	// li r6,1
	ctx.r6.s64 = 1;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// li r5,0
	ctx.r5.s64 = 0;
	// stfd f0,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.f0.u64);
	// lwz r3,300(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// lwz r4,124(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x823aebd8
	ctx.lr = 0x82496A08;
	sub_823AEBD8(ctx, base);
loc_82496A08:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,4(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// std r11,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r11.u64);
	// lfd f13,120(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// stfs f6,248(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// stfs f6,244(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,332(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f6,240(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// stfs f6,252(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f13,328(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f13,324(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f13,320(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f0,136(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f28,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f28.f64 = double(temp.f32);
	// stfs f28,140(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f28,132(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f28,128(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f28,136(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f28,212(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82498af4
	if (!ctx.cr0.eq) goto loc_82498AF4;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// ld r18,216(r1)
	ctx.r18.u64 = REX_LOAD_U64(ctx.r1.u32 + 216);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f21,232(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 232);
	ctx.f21.f64 = double(temp.f32);
	// addi r26,r10,3456
	ctx.r26.s64 = ctx.r10.s64 + 3456;
	// lfs f24,236(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 236);
	ctx.f24.f64 = double(temp.f32);
	// addi r15,r11,616
	ctx.r15.s64 = ctx.r11.s64 + 616;
	// lfs f25,0(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f25.f64 = double(temp.f32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// fmr f30,f21
	ctx.f30.f64 = ctx.f21.f64;
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// std r18,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r18.u64);
	// lis r8,-32115
	ctx.r8.s64 = -2104688640;
	// std r18,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r18.u64);
	// mr r24,r18
	ctx.r24.u64 = ctx.r18.u64;
	// lfs f31,24988(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 24988);
	ctx.f31.f64 = double(temp.f32);
	// mr r30,r14
	ctx.r30.u64 = ctx.r14.u64;
	// lfs f20,16672(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 16672);
	ctx.f20.f64 = double(temp.f32);
	// stw r14,368(r25)
	REX_STORE_U32(ctx.r25.u32 + 368, ctx.r14.u32);
	// std r11,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r11.u64);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f23,0(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// li r23,1
	ctx.r23.s64 = 1;
	// addi r11,r11,32720
	ctx.r11.s64 = ctx.r11.s64 + 32720;
	// lis r20,-32112
	ctx.r20.s64 = -2104492032;
	// stw r11,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r11.u32);
	// addi r21,r10,32432
	ctx.r21.s64 = ctx.r10.s64 + 32432;
	// addi r17,r9,32688
	ctx.r17.s64 = ctx.r9.s64 + 32688;
	// addi r16,r8,22072
	ctx.r16.s64 = ctx.r8.s64 + 22072;
loc_82496B1C:
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// mr r22,r14
	ctx.r22.u64 = ctx.r14.u64;
	// std r11,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r11.u64);
	// bl 0x82499fa8
	ctx.lr = 0x82496B3C;
	sub_82499FA8(ctx, base);
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// fmr f6,f24
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = ctx.f24.f64;
	// beq 0x82496b74
	if (ctx.cr0.eq) goto loc_82496B74;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lvx128 v61,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// addi r3,r1,1408
	ctx.r3.s64 = ctx.r1.s64 + 1408;
	// bl 0x82322d08
	ctx.lr = 0x82496B5C;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82496B60;
	sub_82222370(ctx, base);
	// vsubfp128 v63,v1,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v61.f32)));
	// addi r11,r1,1888
	ctx.r11.s64 = ctx.r1.s64 + 1888;
	// stw r29,368(r25)
	REX_STORE_U32(ctx.r25.u32 + 368, ctx.r29.u32);
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,1888(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1888);
	ctx.f6.f64 = double(temp.f32);
loc_82496B74:
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,280
	ctx.r3.s64 = ctx.r1.s64 + 280;
	// std r11,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r11.u64);
	// bl 0x82499d90
	ctx.lr = 0x82496B8C;
	sub_82499D90(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,280
	ctx.r4.s64 = ctx.r1.s64 + 280;
	// addi r3,r1,1440
	ctx.r3.s64 = ctx.r1.s64 + 1440;
	// bl 0x82322d08
	ctx.lr = 0x82496BA0;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82496BA4;
	sub_82222370(ctx, base);
	// addi r11,r1,1600
	ctx.r11.s64 = ctx.r1.s64 + 1600;
	// fcmpu cr6,f6,f21
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f6.f64, ctx.f21.f64);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82496bcc
	if (!ctx.cr6.gt) goto loc_82496BCC;
	// lfs f0,1600(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1600);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f6,f0
	ctx.cr6.compare(ctx.f6.f64, ctx.f0.f64);
	// bge cr6,0x82496bcc
	if (!ctx.cr6.lt) goto loc_82496BCC;
	// ld r28,256(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + 256);
	// mr r22,r23
	ctx.r22.u64 = ctx.r23.u64;
	// b 0x82496bd0
	goto loc_82496BD0;
loc_82496BCC:
	// ld r28,280(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + 280);
loc_82496BD0:
	// std r28,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r28.u64);
	// clrlwi. r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82496be4
	if (!ctx.cr0.eq) goto loc_82496BE4;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82498aec
	if (ctx.cr6.eq) goto loc_82498AEC;
loc_82496BE4:
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// addi r4,r1,256
	ctx.r4.s64 = ctx.r1.s64 + 256;
	// addi r3,r1,1824
	ctx.r3.s64 = ctx.r1.s64 + 1824;
	// bl 0x82322d08
	ctx.lr = 0x82496BF4;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82496BF8;
	sub_82222370(ctx, base);
	// addi r11,r1,2048
	ctx.r11.s64 = ctx.r1.s64 + 2048;
	// lfs f27,220(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f27.f64 = double(temp.f32);
	// lfs f22,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f22.f64 = double(temp.f32);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f29,2048(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2048);
	ctx.f29.f64 = double(temp.f32);
	// fsubs f0,f31,f29
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f29.f64));
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f20
	ctx.cr6.compare(ctx.f0.f64, ctx.f20.f64);
	// bgt cr6,0x82496c58
	if (ctx.cr6.gt) goto loc_82496C58;
	// lfs f0,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,1136
	ctx.r11.s64 = ctx.r1.s64 + 1136;
	// stfs f0,1140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1140, temp.u32);
	// addi r10,r1,1632
	ctx.r10.s64 = ctx.r1.s64 + 1632;
	// stfs f0,1136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1136, temp.u32);
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1144, temp.u32);
	// stfs f0,1148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1148, temp.u32);
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// fadds f30,f30,f0
	ctx.f30.f64 = double(float(ctx.f30.f64 + ctx.f0.f64));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1632(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1632);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82497c74
	goto loc_82497C74;
loc_82496C58:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// ble cr6,0x82497450
	if (!ctx.cr6.gt) goto loc_82497450;
	// fcmpu cr6,f30,f25
	ctx.cr6.compare(ctx.f30.f64, ctx.f25.f64);
	// ble cr6,0x8249741c
	if (!ctx.cr6.gt) goto loc_8249741C;
	// clrlwi. r11,r22,24
	ctx.r11.u64 = ctx.r22.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82496d60
	if (!ctx.cr0.eq) goto loc_82496D60;
	// lwz r11,368(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82496d60
	if (!ctx.cr6.eq) goto loc_82496D60;
	// addi r10,r1,528
	ctx.r10.s64 = ctx.r1.s64 + 528;
	// lfs f0,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,536(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 536, temp.u32);
	// addi r9,r1,944
	ctx.r9.s64 = ctx.r1.s64 + 944;
	// stfs f0,540(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 540, temp.u32);
	// addi r8,r1,1920
	ctx.r8.s64 = ctx.r1.s64 + 1920;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,-13032(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13032);
	// lvx128 v0,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// stfs f0,532(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 532, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f13,952(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 952, temp.u32);
	// stfs f0,528(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 528, temp.u32);
	// stfs f13,956(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 956, temp.u32);
	// stfs f13,948(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 948, temp.u32);
	// stfs f13,944(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 944, temp.u32);
	// lvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82496d00
	if (ctx.cr6.eq) goto loc_82496D00;
	// lfs f0,1920(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1920);
	ctx.f0.f64 = double(temp.f32);
	// li r6,0
	ctx.r6.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f0.u64);
	// lfs f0,260(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 260);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.f0.u64);
	// lwz r4,284(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// lwz r3,148(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// bl 0x823aebd8
	ctx.lr = 0x82496D00;
	sub_823AEBD8(ctx, base);
loc_82496D00:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// lfs f0,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,572(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 572, temp.u32);
	// addi r10,r1,1296
	ctx.r10.s64 = ctx.r1.s64 + 1296;
	// std r11,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r11.u64);
	// addi r11,r1,560
	ctx.r11.s64 = ctx.r1.s64 + 560;
	// stfs f0,564(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 564, temp.u32);
	// addi r9,r1,1664
	ctx.r9.s64 = ctx.r1.s64 + 1664;
	// stfs f0,560(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 560, temp.u32);
	// stfs f0,568(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 568, temp.u32);
	// lfd f0,288(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 288);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,1296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1296, temp.u32);
	// stfs f0,1308(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1308, temp.u32);
	// stfs f0,1300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1300, temp.u32);
	// stfs f0,1304(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1304, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,1664(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1664);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// b 0x82496e58
	goto loc_82496E58;
loc_82496D60:
	// lwz r11,-12816(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + -12816);
	// lwz r9,368(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 368);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82496e50
	if (!ctx.cr6.eq) goto loc_82496E50;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82496e50
	if (ctx.cr6.eq) goto loc_82496E50;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82496e50
	if (ctx.cr0.eq) goto loc_82496E50;
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// bne 0x82496dac
	if (!ctx.cr0.eq) goto loc_82496DAC;
	// bl 0x82430c30
	ctx.lr = 0x82496DA8;
	sub_82430C30(ctx, base);
	// b 0x82496db0
	goto loc_82496DB0;
loc_82496DAC:
	// bl 0x82430cf0
	ctx.lr = 0x82496DB0;
	sub_82430CF0(ctx, base);
loc_82496DB0:
	// addi r11,r1,976
	ctx.r11.s64 = ctx.r1.s64 + 976;
	// lfs f0,276(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 276);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,592
	ctx.r10.s64 = ctx.r1.s64 + 592;
	// stfs f0,600(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 600, temp.u32);
	// stfs f26,984(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 984, temp.u32);
	// stfs f26,980(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 980, temp.u32);
	// stfs f0,604(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 604, temp.u32);
	// stfs f0,592(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 592, temp.u32);
	// stfs f26,976(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 976, temp.u32);
	// stfs f0,596(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 596, temp.u32);
	// stfs f26,988(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 988, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82496e1c
	if (ctx.cr0.eq) goto loc_82496E1C;
	// addi r11,r1,624
	ctx.r11.s64 = ctx.r1.s64 + 624;
	// stfs f26,624(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 624, temp.u32);
	// stfs f26,632(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 632, temp.u32);
	// addi r10,r1,2160
	ctx.r10.s64 = ctx.r1.s64 + 2160;
	// stfs f26,636(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 636, temp.u32);
	// stfs f26,628(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 628, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,276(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
loc_82496E1C:
	// addi r11,r1,1168
	ctx.r11.s64 = ctx.r1.s64 + 1168;
	// stfs f0,1180(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1180, temp.u32);
	// stfs f0,1176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1176, temp.u32);
	// addi r10,r1,1696
	ctx.r10.s64 = ctx.r1.s64 + 1696;
	// stfs f0,1172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1172, temp.u32);
	// stfs f0,1168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1168, temp.u32);
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,1696(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1696);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// b 0x82496e54
	goto loc_82496E54;
loc_82496E50:
	// lfs f30,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f30.f64 = double(temp.f32);
loc_82496E54:
	// stw r14,368(r25)
	REX_STORE_U32(ctx.r25.u32 + 368, ctx.r14.u32);
loc_82496E58:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r1,1008
	ctx.r10.s64 = ctx.r1.s64 + 1008;
	// addi r9,r1,688
	ctx.r9.s64 = ctx.r1.s64 + 688;
	// stfs f31,668(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 668, temp.u32);
	// rlwinm r11,r30,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f31,660(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 660, temp.u32);
	// addi r8,r1,656
	ctx.r8.s64 = ctx.r1.s64 + 656;
	// stfs f31,656(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 656, temp.u32);
	// add r31,r11,r25
	ctx.r31.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stfs f31,664(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 664, temp.u32);
	// addi r7,r1,1728
	ctx.r7.s64 = ctx.r1.s64 + 1728;
	// addi r11,r1,1952
	ctx.r11.s64 = ctx.r1.s64 + 1952;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stb r23,388(r31)
	REX_STORE_U8(ctx.r31.u32 + 388, ctx.r23.u8);
	// addi r3,r1,2144
	ctx.r3.s64 = ctx.r1.s64 + 2144;
	// std r24,392(r31)
	REX_STORE_U64(ctx.r31.u32 + 392, ctx.r24.u64);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1008(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1008, temp.u32);
	// stfs f0,1020(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1020, temp.u32);
	// stfs f0,1012(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1012, temp.u32);
	// stfs f0,1016(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1016, temp.u32);
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,696(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 696, temp.u32);
	// stfs f13,688(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 688, temp.u32);
	// stfs f13,692(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 692, temp.u32);
	// stfs f13,700(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 700, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v61,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v61.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v61,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1952(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1952);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,392(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 392, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1728(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1728);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,396(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 396, temp.u32);
	// ld r11,392(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 392);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82496EFC;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82496F1C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82496f4c
	if (ctx.cr0.eq) goto loc_82496F4C;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x82496f50
	goto loc_82496F50;
loc_82496F4C:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_82496F50:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497100
	if (ctx.cr6.eq) goto loc_82497100;
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// addi r10,r1,720
	ctx.r10.s64 = ctx.r1.s64 + 720;
	// std r24,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r24.u64);
	// addi r9,r1,1264
	ctx.r9.s64 = ctx.r1.s64 + 1264;
	// stfs f31,1276(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1276, temp.u32);
	// addi r8,r1,1040
	ctx.r8.s64 = ctx.r1.s64 + 1040;
	// stfs f31,1272(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1272, temp.u32);
	// addi r7,r1,2080
	ctx.r7.s64 = ctx.r1.s64 + 2080;
	// stfs f31,1264(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1264, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// std r11,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r11.u64);
	// stfs f31,1268(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1268, temp.u32);
	// addi r11,r1,1760
	ctx.r11.s64 = ctx.r1.s64 + 1760;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,1536
	ctx.r3.s64 = ctx.r1.s64 + 1536;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,732(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 732, temp.u32);
	// stfs f0,728(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 728, temp.u32);
	// stfs f0,724(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 724, temp.u32);
	// stfs f0,720(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 720, temp.u32);
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1040(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1040, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1052(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1052, temp.u32);
	// stfs f0,1048(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1048, temp.u32);
	// stfs f0,1044(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1044, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2080(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2080);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,384(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 384, temp.u32);
	// lfs f0,1760(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1760);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,388(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 388, temp.u32);
	// ld r11,384(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 384);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82496FF8;
	sub_8255F918(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,1200
	ctx.r10.s64 = ctx.r1.s64 + 1200;
	// stfs f31,764(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 764, temp.u32);
	// addi r9,r1,752
	ctx.r9.s64 = ctx.r1.s64 + 752;
	// stfs f31,760(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 760, temp.u32);
	// stfs f31,756(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 756, temp.u32);
	// addi r8,r1,1984
	ctx.r8.s64 = ctx.r1.s64 + 1984;
	// stfs f31,752(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 752, temp.u32);
	// addi r7,r1,784
	ctx.r7.s64 = ctx.r1.s64 + 784;
	// stw r6,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r24,r1,1376
	ctx.r24.s64 = ctx.r1.s64 + 1376;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stfs f0,1212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1212, temp.u32);
	// addi r3,r1,2112
	ctx.r3.s64 = ctx.r1.s64 + 2112;
	// stfs f0,1208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1208, temp.u32);
	// stfs f0,1204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1204, temp.u32);
	// stfs f0,1200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1200, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,796(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 796, temp.u32);
	// stfs f13,792(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 792, temp.u32);
	// stfs f13,788(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 788, temp.u32);
	// stfs f13,784(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 784, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1984(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1376(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1376);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,400(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 400, temp.u32);
	// stfs f0,404(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 404, temp.u32);
	// ld r11,400(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 400);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x8249709C;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r25,372
	ctx.r3.s64 = ctx.r25.s64 + 372;
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r11,376(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824970c8
	if (!ctx.cr6.eq) goto loc_824970C8;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// b 0x824970d4
	goto loc_824970D4;
loc_824970C8:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_824970D4:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x824970f8
	if (!ctx.cr6.lt) goto loc_824970F8;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x82497100
	goto loc_82497100;
loc_824970F8:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823849b0
	ctx.lr = 0x82497100;
	sub_823849B0(ctx, base);
loc_82497100:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82497270
	if (!ctx.cr6.eq) goto loc_82497270;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x82497118;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8249713c
	if (ctx.cr0.eq) goto loc_8249713C;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x82497140
	goto loc_82497140;
loc_8249713C:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_82497140:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497270
	if (ctx.cr6.eq) goto loc_82497270;
	// lfs f13,304(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,1072
	ctx.r11.s64 = ctx.r1.s64 + 1072;
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,200(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,1084(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1084, temp.u32);
	// stfs f0,1080(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1080, temp.u32);
	// addi r9,r1,1392
	ctx.r9.s64 = ctx.r1.s64 + 1392;
	// stfs f0,1076(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1076, temp.u32);
	// addi r8,r1,1424
	ctx.r8.s64 = ctx.r1.s64 + 1424;
	// stfs f0,1072(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1072, temp.u32);
	// addi r5,r1,416
	ctx.r5.s64 = ctx.r1.s64 + 416;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,1568
	ctx.r3.s64 = ctx.r1.s64 + 1568;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1392(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1392);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,416(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 416, temp.u32);
	// lfs f0,1424(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1424);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,420(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 420, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x824971A8;
	sub_82322D08(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f31,828(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 828, temp.u32);
	// addi r10,r1,1328
	ctx.r10.s64 = ctx.r1.s64 + 1328;
	// addi r9,r1,816
	ctx.r9.s64 = ctx.r1.s64 + 816;
	// stfs f31,824(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 824, temp.u32);
	// stfs f31,820(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 820, temp.u32);
	// addi r8,r1,1456
	ctx.r8.s64 = ctx.r1.s64 + 1456;
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// stfs f31,816(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 816, temp.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r7,r1,848
	ctx.r7.s64 = ctx.r1.s64 + 848;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r24,r1,1488
	ctx.r24.s64 = ctx.r1.s64 + 1488;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f0,1332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1332, temp.u32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stfs f0,1340(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1340, temp.u32);
	// addi r3,r1,2152
	ctx.r3.s64 = ctx.r1.s64 + 2152;
	// stfs f0,1336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1336, temp.u32);
	// stfs f0,1328(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1328, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,852(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 852, temp.u32);
	// stfs f13,848(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 848, temp.u32);
	// stfs f13,860(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 860, temp.u32);
	// stfs f13,856(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 856, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,1456(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1456);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,408(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 408, temp.u32);
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1488(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1488);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,412(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 412, temp.u32);
	// ld r11,408(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 408);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x8249724C;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r23,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r23.u8);
	// bl 0x82396cc8
	ctx.lr = 0x82497270;
	sub_82396CC8(ctx, base);
loc_82497270:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x82497280;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824972a4
	if (ctx.cr0.eq) goto loc_824972A4;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x824972a8
	goto loc_824972A8;
loc_824972A4:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_824972A8:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497408
	if (ctx.cr6.eq) goto loc_82497408;
	// addi r11,r1,880
	ctx.r11.s64 = ctx.r1.s64 + 880;
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,892(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 892, temp.u32);
	// addi r8,r1,1232
	ctx.r8.s64 = ctx.r1.s64 + 1232;
	// stfs f0,888(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 888, temp.u32);
	// addi r10,r1,1104
	ctx.r10.s64 = ctx.r1.s64 + 1104;
	// stfs f0,880(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 880, temp.u32);
	// addi r7,r1,1552
	ctx.r7.s64 = ctx.r1.s64 + 1552;
	// stfs f0,884(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 884, temp.u32);
	// addi r9,r1,1520
	ctx.r9.s64 = ctx.r1.s64 + 1520;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// stfs f0,1236(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1236, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,1232(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1232, temp.u32);
	// addi r3,r1,2176
	ctx.r3.s64 = ctx.r1.s64 + 2176;
	// stfs f0,1244(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1244, temp.u32);
	// stfs f0,1240(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1240, temp.u32);
	// stfs f29,1116(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 1116, temp.u32);
	// stfs f29,1112(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 1112, temp.u32);
	// stfs f29,1108(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 1108, temp.u32);
	// stfs f29,1104(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 1104, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,1520(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1520);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,364(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1552(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1552);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,360(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// ld r11,360(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 360);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82497344;
	sub_8255F918(ctx, base);
	// lwz r24,0(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// addi r11,r1,912
	ctx.r11.s64 = ctx.r1.s64 + 912;
	// stfs f31,912(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 912, temp.u32);
	// stfs f31,920(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 920, temp.u32);
	// addi r8,r1,480
	ctx.r8.s64 = ctx.r1.s64 + 480;
	// stfs f31,924(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 924, temp.u32);
	// addi r7,r1,1616
	ctx.r7.s64 = ctx.r1.s64 + 1616;
	// stfs f31,916(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 916, temp.u32);
	// addi r9,r1,512
	ctx.r9.s64 = ctx.r1.s64 + 512;
	// stw r24,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r24.u32);
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,4(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// addi r6,r1,1584
	ctx.r6.s64 = ctx.r1.s64 + 1584;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
	// lfs f12,304(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f12.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,492(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 492, temp.u32);
	// addi r5,r1,336
	ctx.r5.s64 = ctx.r1.s64 + 336;
	// stfs f0,488(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 488, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,484(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 484, temp.u32);
	// addi r3,r1,1472
	ctx.r3.s64 = ctx.r1.s64 + 1472;
	// stfs f0,480(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 480, temp.u32);
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,524(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 524, temp.u32);
	// stfs f13,512(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 512, temp.u32);
	// stfs f13,516(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 516, temp.u32);
	// stfs f13,520(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 520, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1584(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1616(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1616);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,336(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
	// stfs f13,340(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x824973E4;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r14,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r14.u8);
	// bl 0x82396cc8
	ctx.lr = 0x82497408;
	sub_82396CC8(ctx, base);
loc_82497408:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bge cr6,0x82498aec
	if (!ctx.cr6.lt) goto loc_82498AEC;
	// b 0x82497420
	goto loc_82497420;
loc_8249741C:
	// lfs f30,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f30.f64 = double(temp.f32);
loc_82497420:
	// addi r11,r1,432
	ctx.r11.s64 = ctx.r1.s64 + 432;
	// stfs f30,440(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 440, temp.u32);
	// stfs f30,436(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 436, temp.u32);
	// addi r10,r1,1648
	ctx.r10.s64 = ctx.r1.s64 + 1648;
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f30,444(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 444, temp.u32);
	// stfs f30,432(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 432, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1648(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1648);
	ctx.f0.f64 = double(temp.f32);
	// b 0x82497c64
	goto loc_82497C64;
loc_82497450:
	// fcmpu cr6,f30,f25
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f30.f64, ctx.f25.f64);
	// ble cr6,0x82497c34
	if (!ctx.cr6.gt) goto loc_82497C34;
	// addi r11,r1,544
	ctx.r11.s64 = ctx.r1.s64 + 544;
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,576
	ctx.r10.s64 = ctx.r1.s64 + 576;
	// stfs f0,556(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 556, temp.u32);
	// stfs f0,552(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 552, temp.u32);
	// stfs f0,548(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 548, temp.u32);
	// stfs f0,544(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 544, temp.u32);
	// stfs f22,588(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 588, temp.u32);
	// stfs f22,584(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 584, temp.u32);
	// stfs f22,580(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 580, temp.u32);
	// stfs f22,576(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 576, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// bne 0x824974e4
	if (!ctx.cr0.eq) goto loc_824974E4;
	// addi r11,r1,608
	ctx.r11.s64 = ctx.r1.s64 + 608;
	// lfs f0,4(r26)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,640
	ctx.r10.s64 = ctx.r1.s64 + 640;
	// stfs f0,620(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 620, temp.u32);
	// stfs f0,616(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 616, temp.u32);
	// stfs f0,612(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 612, temp.u32);
	// stfs f0,608(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 608, temp.u32);
	// stfs f27,652(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 652, temp.u32);
	// stfs f27,648(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 648, temp.u32);
	// stfs f27,644(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 644, temp.u32);
	// stfs f27,640(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 640, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
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
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
	// beq 0x824974e8
	if (ctx.cr0.eq) goto loc_824974E8;
loc_824974E4:
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
loc_824974E8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82497c34
	if (ctx.cr0.eq) goto loc_82497C34;
	// clrlwi. r11,r22,24
	ctx.r11.u64 = ctx.r22.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824975d8
	if (!ctx.cr0.eq) goto loc_824975D8;
	// lwz r11,368(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 368);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824975d8
	if (!ctx.cr6.eq) goto loc_824975D8;
	// addi r10,r1,672
	ctx.r10.s64 = ctx.r1.s64 + 672;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,704
	ctx.r9.s64 = ctx.r1.s64 + 704;
	// stfs f22,716(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 716, temp.u32);
	// stfs f0,684(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 684, temp.u32);
	// addi r8,r1,1680
	ctx.r8.s64 = ctx.r1.s64 + 1680;
	// stfs f0,680(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 680, temp.u32);
	// lwz r11,-13032(r19)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r19.u32 + -13032);
	// stfs f0,676(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 676, temp.u32);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// stfs f0,672(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 672, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f22,712(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 712, temp.u32);
	// stfs f22,708(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 708, temp.u32);
	// stfs f22,704(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 704, temp.u32);
	// lvx128 v0,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x8249757c
	if (ctx.cr6.eq) goto loc_8249757C;
	// lfs f0,1680(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1680);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f27
	ctx.f13.s64 = std::isnan(ctx.f27.f64) ? int64_t(0x80000000U) : (ctx.f27.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f27.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.f13.u64);
	// stfd f0,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.f0.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,148(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r3,284(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 284);
	// bl 0x823ae820
	ctx.lr = 0x8249757C;
	sub_823AE820(ctx, base);
loc_8249757C:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// stfs f27,748(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 748, temp.u32);
	// addi r10,r1,768
	ctx.r10.s64 = ctx.r1.s64 + 768;
	// stfs f27,744(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 744, temp.u32);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// addi r11,r1,736
	ctx.r11.s64 = ctx.r1.s64 + 736;
	// stfs f27,740(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 740, temp.u32);
	// addi r9,r1,1712
	ctx.r9.s64 = ctx.r1.s64 + 1712;
	// stfs f27,736(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 736, temp.u32);
	// lfd f0,152(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,780(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 780, temp.u32);
	// stfs f0,776(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 776, temp.u32);
	// stfs f0,772(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 772, temp.u32);
	// stfs f0,768(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 768, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,1712(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1712);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// b 0x824976d0
	goto loc_824976D0;
loc_824975D8:
	// lwz r11,-12816(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + -12816);
	// lwz r9,368(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 368);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824976c8
	if (!ctx.cr6.eq) goto loc_824976C8;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824976c8
	if (ctx.cr6.eq) goto loc_824976C8;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824976c8
	if (ctx.cr0.eq) goto loc_824976C8;
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// addi r4,r1,264
	ctx.r4.s64 = ctx.r1.s64 + 264;
	// bne 0x82497624
	if (!ctx.cr0.eq) goto loc_82497624;
	// bl 0x82430c30
	ctx.lr = 0x82497620;
	sub_82430C30(ctx, base);
	// b 0x82497628
	goto loc_82497628;
loc_82497624:
	// bl 0x82430cf0
	ctx.lr = 0x82497628;
	sub_82430CF0(ctx, base);
loc_82497628:
	// addi r11,r1,832
	ctx.r11.s64 = ctx.r1.s64 + 832;
	// lfs f0,268(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 268);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,800
	ctx.r10.s64 = ctx.r1.s64 + 800;
	// stfs f0,812(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 812, temp.u32);
	// stfs f0,808(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 808, temp.u32);
	// stfs f0,804(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 804, temp.u32);
	// stfs f0,800(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 800, temp.u32);
	// stfs f28,844(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 844, temp.u32);
	// stfs f28,840(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 840, temp.u32);
	// stfs f28,836(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 836, temp.u32);
	// stfs f28,832(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 832, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82497694
	if (ctx.cr0.eq) goto loc_82497694;
	// addi r11,r1,864
	ctx.r11.s64 = ctx.r1.s64 + 864;
	// stfs f28,876(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 876, temp.u32);
	// stfs f28,868(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 868, temp.u32);
	// addi r10,r1,1744
	ctx.r10.s64 = ctx.r1.s64 + 1744;
	// stfs f28,864(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 864, temp.u32);
	// stfs f28,872(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 872, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1744(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1744);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
loc_82497694:
	// addi r11,r1,896
	ctx.r11.s64 = ctx.r1.s64 + 896;
	// stfs f0,908(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 908, temp.u32);
	// stfs f0,904(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 904, temp.u32);
	// addi r10,r1,1776
	ctx.r10.s64 = ctx.r1.s64 + 1776;
	// stfs f0,900(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 900, temp.u32);
	// stfs f0,896(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 896, temp.u32);
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
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
	// lfs f30,1776(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1776);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,116(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// b 0x824976cc
	goto loc_824976CC;
loc_824976C8:
	// lfs f30,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f30.f64 = double(temp.f32);
loc_824976CC:
	// stw r14,368(r25)
	REX_STORE_U32(ctx.r25.u32 + 368, ctx.r14.u32);
loc_824976D0:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r8,r1,928
	ctx.r8.s64 = ctx.r1.s64 + 928;
	// addi r10,r1,960
	ctx.r10.s64 = ctx.r1.s64 + 960;
	// stfs f31,940(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 940, temp.u32);
	// rlwinm r11,r30,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f31,936(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 936, temp.u32);
	// addi r9,r1,992
	ctx.r9.s64 = ctx.r1.s64 + 992;
	// stfs f31,932(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 932, temp.u32);
	// add r31,r11,r25
	ctx.r31.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stfs f31,928(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 928, temp.u32);
	// addi r7,r1,1840
	ctx.r7.s64 = ctx.r1.s64 + 1840;
	// addi r11,r1,1808
	ctx.r11.s64 = ctx.r1.s64 + 1808;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stb r23,388(r31)
	REX_STORE_U8(ctx.r31.u32 + 388, ctx.r23.u8);
	// addi r3,r1,1360
	ctx.r3.s64 = ctx.r1.s64 + 1360;
	// std r24,392(r31)
	REX_STORE_U64(ctx.r31.u32 + 392, ctx.r24.u64);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,964(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 964, temp.u32);
	// stfs f0,960(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 960, temp.u32);
	// stfs f13,996(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 996, temp.u32);
	// stfs f13,992(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 992, temp.u32);
	// stfs f13,1004(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1004, temp.u32);
	// stfs f13,1000(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1000, temp.u32);
	// stfs f0,972(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 972, temp.u32);
	// stfs f0,968(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 968, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1808(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1808);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,380(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 380, temp.u32);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,1840(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1840);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,376(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 376, temp.u32);
	// ld r11,376(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 376);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82497774;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82497794;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824977c4
	if (ctx.cr0.eq) goto loc_824977C4;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x824977c8
	goto loc_824977C8;
loc_824977C4:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_824977C8:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497978
	if (ctx.cr6.eq) goto loc_82497978;
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// addi r10,r1,448
	ctx.r10.s64 = ctx.r1.s64 + 448;
	// std r24,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r24.u64);
	// addi r8,r1,1024
	ctx.r8.s64 = ctx.r1.s64 + 1024;
	// stfs f31,1036(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1036, temp.u32);
	// addi r9,r1,464
	ctx.r9.s64 = ctx.r1.s64 + 464;
	// stfs f31,1032(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1032, temp.u32);
	// addi r7,r1,1872
	ctx.r7.s64 = ctx.r1.s64 + 1872;
	// stfs f31,1028(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1028, temp.u32);
	// addi r6,r1,1904
	ctx.r6.s64 = ctx.r1.s64 + 1904;
	// std r11,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r11.u64);
	// stfs f31,1024(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1024, temp.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,2016
	ctx.r3.s64 = ctx.r1.s64 + 2016;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,460(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 460, temp.u32);
	// stfs f0,456(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 456, temp.u32);
	// stfs f0,452(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 452, temp.u32);
	// stfs f0,448(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 448, temp.u32);
	// lfs f13,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,472(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 472, temp.u32);
	// stfs f13,464(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 464, temp.u32);
	// stfs f13,476(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 476, temp.u32);
	// stfs f13,468(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 468, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1872(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1872);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,344(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// lfs f0,1904(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1904);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,348(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// ld r11,344(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 344);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82497870;
	sub_8255F918(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,1088
	ctx.r10.s64 = ctx.r1.s64 + 1088;
	// stfs f31,1068(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1068, temp.u32);
	// addi r9,r1,1056
	ctx.r9.s64 = ctx.r1.s64 + 1056;
	// stfs f31,1064(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1064, temp.u32);
	// stfs f31,1060(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1060, temp.u32);
	// addi r8,r1,1936
	ctx.r8.s64 = ctx.r1.s64 + 1936;
	// stfs f31,1056(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1056, temp.u32);
	// addi r7,r1,1120
	ctx.r7.s64 = ctx.r1.s64 + 1120;
	// stw r6,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r6.u32);
	// addi r24,r1,1968
	ctx.r24.s64 = ctx.r1.s64 + 1968;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,1504
	ctx.r3.s64 = ctx.r1.s64 + 1504;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1092(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1092, temp.u32);
	// stfs f0,1100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1100, temp.u32);
	// stfs f0,1096(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1096, temp.u32);
	// stfs f0,1088(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1088, temp.u32);
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1128, temp.u32);
	// stfs f0,1124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1124, temp.u32);
	// stfs f0,1120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1120, temp.u32);
	// stfs f0,1132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1132, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lfs f0,1936(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1936);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,352(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1968(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 1968);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,356(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// ld r11,352(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 352);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82497914;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r3,r25,372
	ctx.r3.s64 = ctx.r25.s64 + 372;
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// lwz r11,376(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 376);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82497940
	if (!ctx.cr6.eq) goto loc_82497940;
	// mr r10,r14
	ctx.r10.u64 = ctx.r14.u64;
	// b 0x8249794c
	goto loc_8249794C;
loc_82497940:
	// lwz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
loc_8249794C:
	// lwz r4,8(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// subf r11,r11,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r11.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x82497970
	if (!ctx.cr6.lt) goto loc_82497970;
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// stw r31,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r31.u32);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// b 0x82497978
	goto loc_82497978;
loc_82497970:
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x823849b0
	ctx.lr = 0x82497978;
	sub_823849B0(ctx, base);
loc_82497978:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82497ae8
	if (!ctx.cr6.eq) goto loc_82497AE8;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x82497990;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824979b4
	if (ctx.cr0.eq) goto loc_824979B4;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x824979b8
	goto loc_824979B8;
loc_824979B4:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_824979B8:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497ae8
	if (ctx.cr6.eq) goto loc_82497AE8;
	// lfs f13,304(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,1152
	ctx.r11.s64 = ctx.r1.s64 + 1152;
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,200(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,1164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1164, temp.u32);
	// stfs f0,1160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1160, temp.u32);
	// addi r9,r1,2000
	ctx.r9.s64 = ctx.r1.s64 + 2000;
	// stfs f0,1156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1156, temp.u32);
	// addi r8,r1,2032
	ctx.r8.s64 = ctx.r1.s64 + 2032;
	// stfs f0,1152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1152, temp.u32);
	// addi r5,r1,368
	ctx.r5.s64 = ctx.r1.s64 + 368;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,1856
	ctx.r3.s64 = ctx.r1.s64 + 1856;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2000(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2000);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,368(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 368, temp.u32);
	// lfs f0,2032(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2032);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,372(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 372, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x82497A20;
	sub_82322D08(ctx, base);
	// lwz r6,0(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// stfs f31,1196(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1196, temp.u32);
	// addi r10,r1,1216
	ctx.r10.s64 = ctx.r1.s64 + 1216;
	// stfs f31,1184(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1184, temp.u32);
	// addi r8,r1,1184
	ctx.r8.s64 = ctx.r1.s64 + 1184;
	// stfs f31,1188(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1188, temp.u32);
	// addi r9,r1,1248
	ctx.r9.s64 = ctx.r1.s64 + 1248;
	// stfs f31,1192(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1192, temp.u32);
	// stw r6,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r6.u32);
	// addi r7,r1,2064
	ctx.r7.s64 = ctx.r1.s64 + 2064;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r24,r1,2096
	ctx.r24.s64 = ctx.r1.s64 + 2096;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// stfs f13,1228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1228, temp.u32);
	// addi r3,r1,1792
	ctx.r3.s64 = ctx.r1.s64 + 1792;
	// stfs f13,1216(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1216, temp.u32);
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,1224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1224, temp.u32);
	// stfs f13,1220(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 1220, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,1260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1260, temp.u32);
	// stfs f0,1256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1256, temp.u32);
	// stfs f0,1248(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1248, temp.u32);
	// stfs f0,1252(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1252, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2064(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2064);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// lfs f0,2096(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2096);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// ld r11,296(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 296);
	// std r11,144(r1)
	REX_STORE_U64(ctx.r1.u32 + 144, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82497AC4;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r23,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r23.u8);
	// bl 0x82396cc8
	ctx.lr = 0x82497AE8;
	sub_82396CC8(ctx, base);
loc_82497AE8:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x82497AF8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82497b1c
	if (ctx.cr0.eq) goto loc_82497B1C;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x82497b20
	goto loc_82497B20;
loc_82497B1C:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_82497B20:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82497c20
	if (ctx.cr6.eq) goto loc_82497C20;
	// addi r11,r1,1280
	ctx.r11.s64 = ctx.r1.s64 + 1280;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,1312
	ctx.r10.s64 = ctx.r1.s64 + 1312;
	// stfs f0,1292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1292, temp.u32);
	// stfs f0,1288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1288, temp.u32);
	// addi r9,r1,1344
	ctx.r9.s64 = ctx.r1.s64 + 1344;
	// stfs f0,1284(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1284, temp.u32);
	// addi r7,r1,2128
	ctx.r7.s64 = ctx.r1.s64 + 2128;
	// stfs f0,1280(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1280, temp.u32);
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// stfs f31,1324(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1324, temp.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// stfs f31,1320(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1320, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f31,1316(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1316, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f31,1312(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 1312, temp.u32);
	// lfs f0,304(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f23
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f23.f64));
	// stfs f0,1356(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1356, temp.u32);
	// stfs f0,1352(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1352, temp.u32);
	// stfs f0,1348(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1348, temp.u32);
	// stfs f0,1344(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 1344, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 2128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82497BB4;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,496
	ctx.r10.s64 = ctx.r1.s64 + 496;
	// stfs f29,500(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 500, temp.u32);
	// stfs f29,504(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 504, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f29,496(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 496, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stfs f29,508(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 508, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x8225f518
	ctx.lr = 0x82497BEC;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x82497BFC;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r23,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r23.u8);
	// bl 0x82396cc8
	ctx.lr = 0x82497C20;
	sub_82396CC8(ctx, base);
loc_82497C20:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// bge cr6,0x82498aec
	if (!ctx.cr6.lt) goto loc_82498AEC;
	// b 0x82497c38
	goto loc_82497C38;
loc_82497C34:
	// lfs f30,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f30.f64 = double(temp.f32);
loc_82497C38:
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// stfs f30,236(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// stfs f30,232(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f30,228(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f30,224(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v63,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
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
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
loc_82497C64:
	// ld r24,112(r1)
	ctx.r24.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// lfs f30,8(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f30.f64 = double(temp.f32);
	// fmr f31,f29
	ctx.f31.f64 = ctx.f29.f64;
	// std r24,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r24.u64);
loc_82497C74:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f28,188(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f28,184(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f28,180(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f28,176(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
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
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82497cc4
	if (!ctx.cr0.eq) goto loc_82497CC4;
	// mr r30,r22
	ctx.r30.u64 = ctx.r22.u64;
	// std r28,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r28.u64);
	// b 0x82496b1c
	goto loc_82496B1C;
loc_82497CC4:
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,264
	ctx.r4.s64 = ctx.r1.s64 + 264;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// std r11,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r11.u64);
	// bl 0x82499fa8
	ctx.lr = 0x82497CE0;
	sub_82499FA8(ctx, base);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// fmr f6,f24
	ctx.fpscr.disableFlushMode();
	ctx.f6.f64 = ctx.f24.f64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82497d18
	if (ctx.cr6.eq) goto loc_82497D18;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// lvx128 v61,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,264
	ctx.r4.s64 = ctx.r1.s64 + 264;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82322d08
	ctx.lr = 0x82497D04;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82497D08;
	sub_82222370(ctx, base);
	// vsubfp128 v63,v1,v61
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v61.f32)));
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f6,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f6.f64 = double(temp.f32);
loc_82497D18:
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,272
	ctx.r3.s64 = ctx.r1.s64 + 272;
	// std r11,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r11.u64);
	// bl 0x82499d90
	ctx.lr = 0x82497D30;
	sub_82499D90(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,272
	ctx.r4.s64 = ctx.r1.s64 + 272;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82322d08
	ctx.lr = 0x82497D44;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82497D48;
	sub_82222370(ctx, base);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// fcmpu cr6,f6,f21
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f6.f64, ctx.f21.f64);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ble cr6,0x82497d68
	if (!ctx.cr6.gt) goto loc_82497D68;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// ld r11,264(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 264);
	// fcmpu cr6,f6,f0
	ctx.cr6.compare(ctx.f6.f64, ctx.f0.f64);
	// blt cr6,0x82497d6c
	if (ctx.cr6.lt) goto loc_82497D6C;
loc_82497D68:
	// ld r11,272(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 272);
loc_82497D6C:
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// clrlwi. r30,r22,24
	ctx.r30.u64 = ctx.r22.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// lwz r31,-13032(r19)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r19.u32 + -13032);
	// lfs f5,116(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f5.f64 = double(temp.f32);
	// bne 0x82497e84
	if (!ctx.cr0.eq) goto loc_82497E84;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
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
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f21
	ctx.cr6.compare(ctx.f0.f64, ctx.f21.f64);
	// bgt cr6,0x82497db8
	if (ctx.cr6.gt) goto loc_82497DB8;
	// mr r11,r14
	ctx.r11.u64 = ctx.r14.u64;
loc_82497DB8:
	// lfs f6,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f6.f64 = double(temp.f32);
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq 0x82497dfc
	if (ctx.cr0.eq) goto loc_82497DFC;
	// beq cr6,0x82497df4
	if (ctx.cr6.eq) goto loc_82497DF4;
	// fctiwz f0,f6
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.f0.u64);
	// fctiwz f0,f5
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f0,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.f0.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,156(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r4,292(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// bl 0x823ae578
	ctx.lr = 0x82497DF4;
	sub_823AE578(ctx, base);
loc_82497DF4:
	// addi r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 1;
	// b 0x82497e28
	goto loc_82497E28;
loc_82497DFC:
	// beq cr6,0x82497e24
	if (ctx.cr6.eq) goto loc_82497E24;
	// fctiwz f0,f5
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfd f0,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.f0.u64);
	// fctiwz f0,f6
	ctx.f0.s64 = std::isnan(ctx.f6.f64) ? int64_t(0x80000000U) : (ctx.f6.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f6.f64));
	// stfd f0,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.f0.u64);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r3,292(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// bl 0x823ae2c0
	ctx.lr = 0x82497E24;
	sub_823AE2C0(ctx, base);
loc_82497E24:
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
loc_82497E28:
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f6,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f6,104(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f6,100(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfd f0,152(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f11,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// b 0x82497e88
	goto loc_82497E88;
loc_82497E84:
	// lfs f11,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
loc_82497E88:
	// clrlwi. r11,r29,24
	ctx.r11.u64 = ctx.r29.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82497e98
	if (!ctx.cr0.eq) goto loc_82497E98;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82498aec
	if (ctx.cr6.eq) goto loc_82498AEC;
loc_82497E98:
	// addi r5,r1,208
	ctx.r5.s64 = ctx.r1.s64 + 208;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82322d08
	ctx.lr = 0x82497EA8;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82497EAC;
	sub_82222370(ctx, base);
	// addi r11,r1,160
	ctx.r11.s64 = ctx.r1.s64 + 160;
	// ld r28,208(r1)
	ctx.r28.u64 = REX_LOAD_U64(ctx.r1.u32 + 208);
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f30.f64 = double(temp.f32);
	// fsubs f0,f30,f31
	ctx.f0.f64 = double(float(ctx.f30.f64 - ctx.f31.f64));
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fcmpu cr6,f0,f20
	ctx.cr6.compare(ctx.f0.f64, ctx.f20.f64);
	// ble cr6,0x8249878c
	if (!ctx.cr6.gt) goto loc_8249878C;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
	// fcmpu cr6,f30,f31
	ctx.cr6.compare(ctx.f30.f64, ctx.f31.f64);
	// std r28,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r28.u64);
	// bge cr6,0x82498314
	if (!ctx.cr6.lt) goto loc_82498314;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82497fa4
	if (!ctx.cr6.eq) goto loc_82497FA4;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fctiwz f13,f5
	ctx.f13.s64 = std::isnan(ctx.f5.f64) ? int64_t(0x80000000U) : (ctx.f5.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f5.f64));
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v0,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfd f13,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.f13.u64);
	// lfs f0,212(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.f0.u64);
	// lwz r3,156(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// bl 0x823ae158
	ctx.lr = 0x82497F60;
	sub_823AE158(ctx, base);
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// lfd f0,152(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82498074
	goto loc_82498074;
loc_82497FA4:
	// lwz r11,-12816(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + -12816);
	// lwz r9,368(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 368);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x82498080
	if (!ctx.cr6.eq) goto loc_82498080;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82498080
	if (ctx.cr6.eq) goto loc_82498080;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82498080
	if (ctx.cr0.eq) goto loc_82498080;
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// bl 0x82430c30
	ctx.lr = 0x82497FE4;
	sub_82430C30(ctx, base);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
	ctx.f0.f64 = double(temp.f32);
	// stfs f26,108(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f26,104(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f26,100(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f26,96(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8249804c
	if (ctx.cr0.eq) goto loc_8249804C;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f26,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f26,104(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f26,100(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f26,96(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
loc_8249804C:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_82498074:
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r29,112(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
loc_82498080:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// rlwinm r11,r30,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// add r31,r11,r25
	ctx.r31.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r23,388(r31)
	REX_STORE_U8(ctx.r31.u32 + 388, ctx.r23.u8);
	// std r24,392(r31)
	REX_STORE_U64(ctx.r31.u32 + 392, ctx.r24.u64);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x824980B8;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8255f918
	ctx.lr = 0x824980C8;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824980E8;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498118
	if (ctx.cr0.eq) goto loc_82498118;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x8249811c
	goto loc_8249811C;
loc_82498118:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_8249811C:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824981cc
	if (ctx.cr6.eq) goto loc_824981CC;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// std r24,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r24.u64);
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// std r29,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r29.u64);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x82498154;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8255f918
	ctx.lr = 0x82498164;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x8225f518
	ctx.lr = 0x8249819C;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x824981AC;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,372
	ctx.r3.s64 = ctx.r25.s64 + 372;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bl 0x82396cc8
	ctx.lr = 0x824981CC;
	sub_82396CC8(ctx, base);
loc_824981CC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x824982e0
	if (!ctx.cr6.eq) goto loc_824982E0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x824981E4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498208
	if (ctx.cr0.eq) goto loc_82498208;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x8249820c
	goto loc_8249820C;
loc_82498208:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_8249820C:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824982e0
	if (ctx.cr6.eq) goto loc_824982E0;
	// lfs f0,8(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f13,304(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,200(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
loc_8249824C:
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x82498274;
	sub_82322D08(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// bl 0x8225f518
	ctx.lr = 0x824982AC;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x824982BC;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r23,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r23.u8);
	// bl 0x82396cc8
	ctx.lr = 0x824982E0;
	sub_82396CC8(ctx, base);
loc_824982E0:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x824982F0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824986b0
	if (ctx.cr0.eq) goto loc_824986B0;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x824986b4
	goto loc_824986B4;
loc_82498314:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82498400
	if (!ctx.cr6.eq) goto loc_82498400;
	// addi r3,r1,216
	ctx.r3.s64 = ctx.r1.s64 + 216;
	// bl 0x82346fa0
	ctx.lr = 0x82498324;
	sub_82346FA0(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82498338
	if (ctx.cr0.eq) goto loc_82498338;
	// std r18,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r18.u64);
	// lfs f27,220(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 220);
	ctx.f27.f64 = double(temp.f32);
	// lfs f22,216(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 216);
	ctx.f22.f64 = double(temp.f32);
loc_82498338:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r3,r14
	ctx.r3.u64 = ctx.r14.u64;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// stfs f22,188(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f22,184(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f22,180(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f22,176(r1)
	temp.f32 = float(ctx.f22.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v0,r0,r21
	ea = (ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824983ac
	if (ctx.cr6.eq) goto loc_824983AC;
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f27
	ctx.f13.s64 = std::isnan(ctx.f27.f64) ? int64_t(0x80000000U) : (ctx.f27.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f27.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.f13.u64);
	// stfd f0,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.f0.u64);
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r4,156(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 156);
	// lwz r3,292(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// bl 0x823ae820
	ctx.lr = 0x824983AC;
	sub_823AE820(ctx, base);
loc_824983AC:
	// extsw r11,r3
	ctx.r11.s64 = ctx.r3.s32;
	// stfs f27,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f27,104(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// std r11,152(r1)
	REX_STORE_U64(ctx.r1.u32 + 152, ctx.r11.u64);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f27,100(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f27,96(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfd f0,152(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x824984d4
	goto loc_824984D4;
loc_82498400:
	// lwz r11,-12816(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + -12816);
	// lwz r9,368(r25)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r25.u32 + 368);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r9
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r9.u32, ctx.xer);
	// bne cr6,0x824984e0
	if (!ctx.cr6.eq) goto loc_824984E0;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824984e0
	if (ctx.cr6.eq) goto loc_824984E0;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824984e0
	if (ctx.cr0.eq) goto loc_824984E0;
	// addi r4,r1,152
	ctx.r4.s64 = ctx.r1.s64 + 152;
	// bl 0x82430cf0
	ctx.lr = 0x82498440;
	sub_82430CF0(ctx, base);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,212(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,156(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 156);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824984ac
	if (ctx.cr0.eq) goto loc_824984AC;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f13.f64 = double(temp.f32);
loc_824984AC:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
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
loc_824984D4:
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r29,112(r1)
	ctx.r29.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
loc_824984E0:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// rlwinm r11,r30,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// add r31,r11,r25
	ctx.r31.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r23,388(r31)
	REX_STORE_U8(ctx.r31.u32 + 388, ctx.r23.u8);
	// std r24,392(r31)
	REX_STORE_U64(ctx.r31.u32 + 392, ctx.r24.u64);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x82498518;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8255f918
	ctx.lr = 0x82498528;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82498548;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498578
	if (ctx.cr0.eq) goto loc_82498578;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x8249857c
	goto loc_8249857C;
loc_82498578:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_8249857C:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8249862c
	if (ctx.cr6.eq) goto loc_8249862C;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// std r24,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r24.u64);
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// std r29,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r29.u64);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x824985B4;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8255f918
	ctx.lr = 0x824985C4;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x8225f518
	ctx.lr = 0x824985FC;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x8249860C;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,372
	ctx.r3.s64 = ctx.r25.s64 + 372;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bl 0x82396cc8
	ctx.lr = 0x8249862C;
	sub_82396CC8(ctx, base);
loc_8249862C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x824982e0
	if (!ctx.cr6.eq) goto loc_824982E0;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x82498644;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498668
	if (ctx.cr0.eq) goto loc_82498668;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x8249866c
	goto loc_8249866C;
loc_82498668:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_8249866C:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824982e0
	if (ctx.cr6.eq) goto loc_824982E0;
	// lfs f0,8(r15)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,304(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// lwz r10,200(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8249824c
	goto loc_8249824C;
loc_824986B0:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_824986B4:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82498774
	if (ctx.cr6.eq) goto loc_82498774;
	// std r29,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r29.u64);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f31,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
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
	// lfs f13,304(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82498750;
	sub_8255F918(ctx, base);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r14,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r14.u8);
	// bl 0x82396cc8
	ctx.lr = 0x82498774;
	sub_82396CC8(ctx, base);
loc_82498774:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bge cr6,0x82498aec
	if (!ctx.cr6.lt) goto loc_82498AEC;
	// mr r24,r29
	ctx.r24.u64 = ctx.r29.u64;
	// std r29,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r29.u64);
loc_8249878C:
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// rlwinm r11,r30,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 5) & 0xFFFFFFE0;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// add r31,r11,r25
	ctx.r31.u64 = ctx.r11.u64 + ctx.r25.u64;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r23,388(r31)
	REX_STORE_U8(ctx.r31.u32 + 388, ctx.r23.u8);
	// std r24,392(r31)
	REX_STORE_U64(ctx.r31.u32 + 392, ctx.r24.u64);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x824987C4;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8255f918
	ctx.lr = 0x824987D4;
	sub_8255F918(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,32
	ctx.r4.s64 = 32;
	// stw r11,400(r31)
	REX_STORE_U32(ctx.r31.u32 + 400, ctx.r11.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x824987F4;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498824
	if (ctx.cr0.eq) goto loc_82498824;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,16(r3)
	REX_STORE_U64(ctx.r3.u32 + 16, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// std r11,24(r3)
	REX_STORE_U64(ctx.r3.u32 + 24, ctx.r11.u64);
	// b 0x82498828
	goto loc_82498828;
loc_82498824:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_82498828:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824988d8
	if (ctx.cr6.eq) goto loc_824988D8;
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// std r24,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r24.u64);
	// stfs f30,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// std r28,8(r31)
	REX_STORE_U64(ctx.r31.u32 + 8, ctx.r28.u64);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x82498860;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// bl 0x8255f918
	ctx.lr = 0x82498870;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,320
	ctx.r3.s64 = ctx.r1.s64 + 320;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r9.u32);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r11.u32);
	// bl 0x8225f518
	ctx.lr = 0x824988A8;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x824988B8;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,372
	ctx.r3.s64 = ctx.r25.s64 + 372;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r11.u32);
	// bl 0x82396cc8
	ctx.lr = 0x824988D8;
	sub_82396CC8(ctx, base);
loc_824988D8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x824989ec
	if (!ctx.cr6.eq) goto loc_824989EC;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x824988F0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498914
	if (ctx.cr0.eq) goto loc_82498914;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x82498918
	goto loc_82498918;
loc_82498914:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_82498918:
	// stw r31,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x824989ec
	if (ctx.cr6.eq) goto loc_824989EC;
	// lfs f13,304(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,200(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 200);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x82498980;
	sub_82322D08(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,240
	ctx.r3.s64 = ctx.r1.s64 + 240;
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lvx128 v1,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8225f518
	ctx.lr = 0x824989B8;
	sub_8225F518(ctx, base);
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// addi r4,r1,192
	ctx.r4.s64 = ctx.r1.s64 + 192;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x8255f918
	ctx.lr = 0x824989C8;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r23,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r23.u8);
	// bl 0x82396cc8
	ctx.lr = 0x824989EC;
	sub_82396CC8(ctx, base);
loc_824989EC:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,44(r16)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r16.u32 + 44);
	// li r4,20
	ctx.r4.s64 = 20;
	// bl 0x825e02a0
	ctx.lr = 0x824989FC;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82498a20
	if (ctx.cr0.eq) goto loc_82498A20;
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// ld r11,0(r26)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// stb r23,16(r3)
	REX_STORE_U8(ctx.r3.u32 + 16, ctx.r23.u8);
	// std r11,8(r3)
	REX_STORE_U64(ctx.r3.u32 + 8, ctx.r11.u64);
	// b 0x82498a24
	goto loc_82498A24;
loc_82498A20:
	// mr r31,r14
	ctx.r31.u64 = ctx.r14.u64;
loc_82498A24:
	// stw r31,200(r1)
	REX_STORE_U32(ctx.r1.u32 + 200, ctx.r31.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82498ae4
	if (ctx.cr6.eq) goto loc_82498AE4;
	// std r28,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r28.u64);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// stfs f30,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f30,104(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,304
	ctx.r8.s64 = ctx.r1.s64 + 304;
	// stfs f30,100(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// stfs f30,96(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// lfs f0,8(r15)
	temp.u32 = REX_LOAD_U32(ctx.r15.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r1,120
	ctx.r5.s64 = ctx.r1.s64 + 120;
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f13,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,184(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// lfs f13,304(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 304);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
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
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lfs f0,304(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82498AC0;
	sub_8255F918(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// addi r4,r1,200
	ctx.r4.s64 = ctx.r1.s64 + 200;
	// addi r3,r25,1416
	ctx.r3.s64 = ctx.r25.s64 + 1416;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r11.u32);
	// stb r14,16(r31)
	REX_STORE_U8(ctx.r31.u32 + 16, ctx.r14.u8);
	// bl 0x82396cc8
	ctx.lr = 0x82498AE4;
	sub_82396CC8(ctx, base);
loc_82498AE4:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
loc_82498AEC:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,1412(r25)
	REX_STORE_U32(ctx.r25.u32 + 1412, ctx.r11.u32);
loc_82498AF4:
	// addi r1,r1,2432
	ctx.r1.s64 = ctx.r1.s64 + 2432;
	// addi r12,r1,-152
	ctx.r12.s64 = ctx.r1.s64 + -152;
	// bl 0x8273af54
	ctx.lr = 0x82498B00;
	__restfpr_20(ctx, base);
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825C6F50) {
	REX_FUNC_PROLOGUE();
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lbz r3,9(r11)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r11.u32 + 9);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C7430) {
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
	// lwz r3,28(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r10,r11,20688
	ctx.r10.s64 = ctx.r11.s64 + 20688;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// beq cr6,0x825c7470
	if (ctx.cr6.eq) goto loc_825C7470;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C7470;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825C7470:
	// lwz r3,24(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825c7490
	if (ctx.cr6.eq) goto loc_825C7490;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825C7490;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825C7490:
	// lwz r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x825c74d4
	if (ctx.cr6.eq) goto loc_825C74D4;
	// lwz r10,-4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// addi r3,r11,-4
	ctx.r3.s64 = ctx.r11.s64 + -4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825c74c8
	if (ctx.cr6.eq) goto loc_825C74C8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,3
	ctx.r4.s64 = 3;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825C74C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x825c74d4
	goto loc_825C74D4;
loc_825C74C8:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825c74d4
	if (ctx.cr6.eq) goto loc_825C74D4;
	// bl 0x825e0378
	ctx.lr = 0x825C74D4;
	sub_825E0378(ctx, base);
loc_825C74D4:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r10,r11,18140
	ctx.r10.s64 = ctx.r11.s64 + 18140;
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_825CD2B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825CD2C0;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x825cd2dc
	if (!ctx.cr6.eq) goto loc_825CD2DC;
	// bl 0x825b32d0
	ctx.lr = 0x825CD2D8;
	sub_825B32D0(ctx, base);
	// stw r3,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r3.u32);
loc_825CD2DC:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CD2F4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825cd394
	if (ctx.cr6.eq) goto loc_825CD394;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// li r30,1
	ctx.r30.s64 = 1;
	// lbz r10,7(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 7);
	// clrlwi r29,r10,31
	ctx.r29.u64 = ctx.r10.u32 & 0x1;
	// bne cr6,0x825cd354
	if (!ctx.cr6.eq) goto loc_825CD354;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x825cd340
	if (ctx.cr6.eq) goto loc_825CD340;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CD330;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r9,76(r3)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r3.u32 + 76);
	// rlwinm r8,r9,0,25,25
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x825cd358
	if (!ctx.cr6.eq) goto loc_825CD358;
loc_825CD340:
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// bl 0x825c7a18
	ctx.lr = 0x825CD34C;
	sub_825C7A18(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825cd358
	if (!ctx.cr6.eq) goto loc_825CD358;
loc_825CD354:
	// li r30,0
	ctx.r30.s64 = 0;
loc_825CD358:
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,64(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x825CD36C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r8,8(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x825CD38C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
loc_825CD394:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825D5A38) {
	REX_FUNC_PROLOGUE();
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
	// addi r11,r1,84
	ctx.r11.s64 = ctx.r1.s64 + 84;
	// li r31,0
	ctx.r31.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r4,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// beq cr6,0x825d5b24
	if (ctx.cr6.eq) goto loc_825D5B24;
	// lis r11,19558
	ctx.r11.s64 = 1281753088;
	// lwz r10,64(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// ori r9,r11,20853
	ctx.r9.u64 = ctx.r11.u64 | 20853;
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// bne cr6,0x825d5b24
	if (!ctx.cr6.eq) goto loc_825D5B24;
	// lwz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 76);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825d5af8
	if (ctx.cr6.eq) goto loc_825D5AF8;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x825d5af8
	if (ctx.cr6.eq) goto loc_825D5AF8;
	// rlwinm r9,r10,26,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 26) & 0x1;
	// lwz r8,12(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r7,r10,28,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 28) & 0x1;
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r6,20(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// lwz r5,4(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825d51f0
	ctx.lr = 0x825D5AAC;
	sub_825D51F0(ctx, base);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825d5ac8
	if (ctx.cr6.eq) goto loc_825D5AC8;
	// cmplwi cr6,r3,258
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 258, ctx.xer);
	// beq cr6,0x825d5aec
	if (ctx.cr6.eq) goto loc_825D5AEC;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bgt cr6,0x825d5ae0
	if (ctx.cr6.gt) goto loc_825D5AE0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_825D5AC8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
loc_825D5AE0:
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// oris r31,r11,32775
	ctx.r31.u64 = ctx.r11.u64 | 2147942400;
	// b 0x825d5ac8
	goto loc_825D5AC8;
loc_825D5AEC:
	// lis r31,-32719
	ctx.r31.s64 = -2144272384;
	// ori r31,r31,1
	ctx.r31.u64 = ctx.r31.u64 | 1;
	// b 0x825d5ac8
	goto loc_825D5AC8;
loc_825D5AF8:
	// ld r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// bl 0x825d4f18
	ctx.lr = 0x825D5B00;
	sub_825D4F18(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x825d5ac8
	if (!ctx.cr6.eq) goto loc_825D5AC8;
	// lis r3,-32719
	ctx.r3.s64 = -2144272384;
	// ori r3,r3,1
	ctx.r3.u64 = ctx.r3.u64 | 1;
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
loc_825D5B24:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
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

DEFINE_REX_FUNC(sub_825E2010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825E2018;
	__savegprlr_29(ctx, base);
	// stfd f29,-56(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -56, ctx.f29.u64);
	// stfd f30,-48(r1)
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f30.u64);
	// stfd f31,-40(r1)
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r10,r11,12236
	ctx.r10.s64 = ctx.r11.s64 + 12236;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lfs f29,12236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f29.f64 = double(temp.f32);
	// lfs f30,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f30.f64 = double(temp.f32);
	// fcmpu cr6,f1,f30
	ctx.cr6.compare(ctx.f1.f64, ctx.f30.f64);
	// bne cr6,0x825e2054
	if (!ctx.cr6.eq) goto loc_825E2054;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825e208c
	if (ctx.cr6.eq) goto loc_825E208C;
loc_825E2054:
	// subf r4,r30,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r30.u64;
	// fsubs f1,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f29.f64 - ctx.f31.f64));
	// bl 0x825e1c10
	ctx.lr = 0x825E2060;
	sub_825E1C10(ctx, base);
	// addi r4,r30,-1
	ctx.r4.s64 = ctx.r30.s64 + -1;
	// fmr f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f30.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825e1c10
	ctx.lr = 0x825E2070;
	sub_825E1C10(ctx, base);
	// clrldi r11,r30,32
	ctx.r11.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// fmuls f0,f30,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f30.f64 * ctx.f1.f64));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f30,f0,f13
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
loc_825E208C:
	// fcmpu cr6,f31,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f29.f64);
	// bne cr6,0x825e209c
	if (!ctx.cr6.eq) goto loc_825E209C;
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// beq cr6,0x825e20d8
	if (ctx.cr6.eq) goto loc_825E20D8;
loc_825E209C:
	// subf r29,r30,r31
	ctx.r29.u64 = ctx.r31.u64 - ctx.r30.u64;
	// fsubs f1,f29,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f29.f64 - ctx.f31.f64));
	// addi r4,r29,-1
	ctx.r4.s64 = ctx.r29.s64 + -1;
	// bl 0x825e1c10
	ctx.lr = 0x825E20AC;
	sub_825E1C10(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmr f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f29.f64 = ctx.f1.f64;
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825e1c10
	ctx.lr = 0x825E20BC;
	sub_825E1C10(ctx, base);
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// fmuls f0,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f29.f64 * ctx.f1.f64));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fnmsubs f30,f0,f13,f30
	ctx.f30.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f13.f64, -ctx.f30.f64)));
loc_825E20D8:
	// subf r4,r30,r31
	ctx.r4.u64 = ctx.r31.u64 - ctx.r30.u64;
	// cmplw cr6,r31,r4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x825e20fc
	if (ctx.cr6.eq) goto loc_825E20FC;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// ble cr6,0x825e20fc
	if (!ctx.cr6.gt) goto loc_825E20FC;
	// addi r3,r31,-1
	ctx.r3.s64 = ctx.r31.s64 + -1;
	// bl 0x825e1ca8
	ctx.lr = 0x825E20F4;
	sub_825E1CA8(ctx, base);
	// mullw r11,r3,r31
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r31.s32);
	// b 0x825e2100
	goto loc_825E2100;
loc_825E20FC:
	// li r11,1
	ctx.r11.s64 = 1;
loc_825E2100:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// cmplwi cr6,r30,1
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 1, ctx.xer);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// fmuls f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f30.f64));
	// bgt cr6,0x825e2128
	if (ctx.cr6.gt) goto loc_825E2128;
	// li r11,1
	ctx.r11.s64 = 1;
	// b 0x825e2134
	goto loc_825E2134;
loc_825E2128:
	// addi r3,r30,-1
	ctx.r3.s64 = ctx.r30.s64 + -1;
	// bl 0x825e1c60
	ctx.lr = 0x825E2130;
	sub_825E1C60(ctx, base);
	// mullw r11,r3,r30
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
loc_825E2134:
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fdivs f1,f0,f13
	ctx.f1.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f29,-56(r1)
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -56);
	// lfd f30,-48(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// lfd f31,-40(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825E86A0) {
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
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// li r8,1
	ctx.r8.s64 = 1;
	// addi r11,r11,24024
	ctx.r11.s64 = ctx.r11.s64 + 24024;
	// addi r10,r10,23224
	ctx.r10.s64 = ctx.r10.s64 + 23224;
	// stw r8,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r8.u32);
	// addi r9,r9,23292
	ctx.r9.s64 = ctx.r9.s64 + 23292;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// stw r10,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r10.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stw r9,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r9.u32);
	// addi r3,r3,12
	ctx.r3.s64 = ctx.r3.s64 + 12;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// bl 0x825e54c0
	ctx.lr = 0x825E86F0;
	sub_825E54C0(ctx, base);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r11,r31,104
	ctx.r11.s64 = ctx.r31.s64 + 104;
	// stw r30,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// stw r11,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r11.u32);
	// bne cr6,0x825e8714
	if (!ctx.cr6.eq) goto loc_825E8714;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r9,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r9.u32);
loc_825E8714:
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// addi r9,r9,-15552
	ctx.r9.s64 = ctx.r9.s64 + -15552;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,72(r31)
	REX_STORE_U32(ctx.r31.u32 + 72, ctx.r9.u32);
	// beq cr6,0x825e874c
	if (ctx.cr6.eq) goto loc_825E874C;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
loc_825E8730:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r8,0,r9
	ea = ctx.r9.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r8.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r8,r8,1
	ctx.r8.s64 = ctx.r8.s64 + 1;
	// stwcx. r8,0,r9
	ea = ctx.r9.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r8.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x825e8730
	if (!ctx.cr0.eq) goto loc_825E8730;
loc_825E874C:
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stw r10,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r10.u32);
	// addi r9,r9,23672
	ctx.r9.s64 = ctx.r9.s64 + 23672;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// stw r9,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r9.u32);
	// addi r8,r8,23740
	ctx.r8.s64 = ctx.r8.s64 + 23740;
	// addi r7,r7,23396
	ctx.r7.s64 = ctx.r7.s64 + 23396;
	// li r9,-1
	ctx.r9.s64 = -1;
	// stw r8,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r8.u32);
	// stw r7,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r7.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// std r10,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r10.u64);
	// stw r9,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r9.u32);
	// stb r10,20(r11)
	REX_STORE_U8(ctx.r11.u32 + 20, ctx.r10.u8);
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

DEFINE_REX_FUNC(sub_825EF650) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825EF658;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// subf r11,r4,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r4.u64;
	// addi r30,r5,-4
	ctx.r30.s64 = ctx.r5.s64 + -4;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subf r10,r4,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r4.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// add r31,r10,r4
	ctx.r31.u64 = ctx.r10.u64 + ctx.r4.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// ble cr6,0x825ef6ec
	if (!ctx.cr6.gt) goto loc_825EF6EC;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r11,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r28,r29,r4
	ctx.r28.u64 = ctx.r29.u64 + ctx.r4.u64;
	// add r5,r27,r4
	ctx.r5.u64 = ctx.r27.u64 + ctx.r4.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x825ef998
	ctx.lr = 0x825EF6BC;
	sub_825EF998(ctx, base);
	// add r5,r29,r31
	ctx.r5.u64 = ctx.r29.u64 + ctx.r31.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// subf r3,r29,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r29.u64;
	// bl 0x825ef998
	ctx.lr = 0x825EF6CC;
	sub_825EF998(ctx, base);
	// subf r29,r29,r30
	ctx.r29.u64 = ctx.r30.u64 - ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// subf r3,r27,r30
	ctx.r3.u64 = ctx.r30.u64 - ctx.r27.u64;
	// bl 0x825ef998
	ctx.lr = 0x825EF6E0;
	sub_825EF998(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825ef6f0
	goto loc_825EF6F0;
loc_825EF6EC:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
loc_825EF6F0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825ef998
	ctx.lr = 0x825EF6F8;
	sub_825EF998(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x825ef734
	if (!ctx.cr6.lt) goto loc_825EF734;
loc_825EF708:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// lwz r8,-4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + -4);
	// lhz r9,94(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 94);
	// lhz r8,94(r8)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + 94);
	// cmplw cr6,r9,r8
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x825ef734
	if (ctx.cr6.lt) goto loc_825EF734;
	// bgt cr6,0x825ef734
	if (ctx.cr6.gt) goto loc_825EF734;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825ef708
	if (ctx.cr6.lt) goto loc_825EF708;
loc_825EF734:
	// cmplw cr6,r6,r25
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x825ef764
	if (!ctx.cr6.lt) goto loc_825EF764;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r9,94(r10)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r10.u32 + 94);
loc_825EF744:
	// lwz r10,0(r6)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lhz r10,94(r10)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r10.u32 + 94);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825ef764
	if (ctx.cr6.lt) goto loc_825EF764;
	// bgt cr6,0x825ef764
	if (ctx.cr6.gt) goto loc_825EF764;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r6,r25
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x825ef744
	if (ctx.cr6.lt) goto loc_825EF744;
loc_825EF764:
	// mr r10,r6
	ctx.r10.u64 = ctx.r6.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// b 0x825ef7ac
	goto loc_825EF7AC;
loc_825EF770:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lhz r9,94(r9)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r9.u32 + 94);
	// lhz r8,94(r7)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r7.u32 + 94);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825ef7a8
	if (ctx.cr6.lt) goto loc_825EF7A8;
	// bgt cr6,0x825ef7b4
	if (ctx.cr6.gt) goto loc_825EF7B4;
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x825ef7a8
	if (ctx.cr6.eq) goto loc_825EF7A8;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
loc_825EF7A8:
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
loc_825EF7AC:
	// cmplw cr6,r10,r25
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x825ef770
	if (ctx.cr6.lt) goto loc_825EF770;
loc_825EF7B4:
	// cmplw cr6,r5,r26
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x825ef80c
	if (!ctx.cr6.gt) goto loc_825EF80C;
	// addi r9,r5,-4
	ctx.r9.s64 = ctx.r5.s64 + -4;
loc_825EF7C0:
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lhz r8,94(r8)
	ctx.r8.u64 = REX_LOAD_U16(ctx.r8.u32 + 94);
	// lhz r7,94(r7)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r7.u32 + 94);
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// blt cr6,0x825ef7f8
	if (ctx.cr6.lt) goto loc_825EF7F8;
	// bgt cr6,0x825ef808
	if (ctx.cr6.gt) goto loc_825EF808;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825ef7f8
	if (ctx.cr6.eq) goto loc_825EF7F8;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// stw r7,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
loc_825EF7F8:
	// addi r5,r5,-4
	ctx.r5.s64 = ctx.r5.s64 + -4;
	// addi r9,r9,-4
	ctx.r9.s64 = ctx.r9.s64 + -4;
	// cmplw cr6,r26,r5
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r5.u32, ctx.xer);
	// blt cr6,0x825ef7c0
	if (ctx.cr6.lt) goto loc_825EF7C0;
loc_825EF808:
	// cmplw cr6,r5,r26
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r26.u32, ctx.xer);
loc_825EF80C:
	// bne cr6,0x825ef868
	if (!ctx.cr6.eq) goto loc_825EF868;
	// cmplw cr6,r10,r25
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x825ef8cc
	if (ctx.cr6.eq) goto loc_825EF8CC;
	// cmplw cr6,r6,r10
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x825ef838
	if (ctx.cr6.eq) goto loc_825EF838;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x825ef838
	if (ctx.cr6.eq) goto loc_825EF838;
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r8,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
loc_825EF838:
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825ef7ac
	if (ctx.cr6.eq) goto loc_825EF7AC;
	// lwz r7,0(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r4,0(r8)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r7,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r7.u32);
	// stw r4,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r4.u32);
	// b 0x825ef7ac
	goto loc_825EF7AC;
loc_825EF868:
	// cmplw cr6,r10,r25
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r25.u32, ctx.xer);
	// addi r5,r5,-4
	ctx.r5.s64 = ctx.r5.s64 + -4;
	// bne cr6,0x825ef8b0
	if (!ctx.cr6.eq) goto loc_825EF8B0;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825ef890
	if (ctx.cr6.eq) goto loc_825EF890;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r8,0(r5)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r9,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r9.u32);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
loc_825EF890:
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// cmplw cr6,r11,r6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x825ef7ac
	if (ctx.cr6.eq) goto loc_825EF7AC;
	// lwz r9,0(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r8,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r8.u32);
	// b 0x825ef7ac
	goto loc_825EF7AC;
loc_825EF8B0:
	// cmplw cr6,r10,r5
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r5.u32, ctx.xer);
	// beq cr6,0x825ef7a8
	if (ctx.cr6.eq) goto loc_825EF7A8;
	// lwz r9,0(r5)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r8.u32);
	// b 0x825ef7a8
	goto loc_825EF7A8;
loc_825EF8CC:
	// stw r11,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r11.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r6,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r6.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FF408) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x825FF410;
	__savegprlr_24(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// subf r11,r4,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r4.u64;
	// addi r29,r5,-4
	ctx.r29.s64 = ctx.r5.s64 + -4;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// subf r10,r4,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r4.u64;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// addze r9,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r9.s64 = temp.s64;
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// mr r25,r5
	ctx.r25.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,40
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 40, ctx.xer);
	// add r31,r10,r4
	ctx.r31.u64 = ctx.r10.u64 + ctx.r4.u64;
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// ble cr6,0x825ff4a4
	if (!ctx.cr6.gt) goto loc_825FF4A4;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// srawi r11,r11,3
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 3;
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// rlwinm r30,r11,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r11,3,0,28
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// add r28,r30,r4
	ctx.r28.u64 = ctx.r30.u64 + ctx.r4.u64;
	// add r5,r27,r4
	ctx.r5.u64 = ctx.r27.u64 + ctx.r4.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// bl 0x825ff7f0
	ctx.lr = 0x825FF474;
	sub_825FF7F0(ctx, base);
	// add r5,r30,r31
	ctx.r5.u64 = ctx.r30.u64 + ctx.r31.u64;
	// subf r3,r30,r31
	ctx.r3.u64 = ctx.r31.u64 - ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825ff7f0
	ctx.lr = 0x825FF484;
	sub_825FF7F0(ctx, base);
	// subf r30,r30,r29
	ctx.r30.u64 = ctx.r29.u64 - ctx.r30.u64;
	// subf r3,r27,r29
	ctx.r3.u64 = ctx.r29.u64 - ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// bl 0x825ff7f0
	ctx.lr = 0x825FF498;
	sub_825FF7F0(ctx, base);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// b 0x825ff4a8
	goto loc_825FF4A8;
loc_825FF4A4:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
loc_825FF4A8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x825ff7f0
	ctx.lr = 0x825FF4B0;
	sub_825FF7F0(ctx, base);
	// mr r8,r31
	ctx.r8.u64 = ctx.r31.u64;
	// addi r6,r31,4
	ctx.r6.s64 = ctx.r31.s64 + 4;
	// cmplw cr6,r26,r31
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r31.u32, ctx.xer);
	// bge cr6,0x825ff510
	if (!ctx.cr6.lt) goto loc_825FF510;
loc_825FF4C0:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// addi r10,r8,-4
	ctx.r10.s64 = ctx.r8.s64 + -4;
	// lwz r9,-4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + -4);
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,412(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x825ff4e4
	if (ctx.cr6.lt) goto loc_825FF4E4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FF4E4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff510
	if (!ctx.cr0.eq) goto loc_825FF510;
	// fcmpu cr6,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x825ff4fc
	if (ctx.cr6.lt) goto loc_825FF4FC;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FF4FC:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff510
	if (!ctx.cr0.eq) goto loc_825FF510;
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// cmplw cr6,r26,r10
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825ff4c0
	if (ctx.cr6.lt) goto loc_825FF4C0;
loc_825FF510:
	// cmplw cr6,r6,r25
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x825ff564
	if (!ctx.cr6.lt) goto loc_825FF564;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f13,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
loc_825FF520:
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x825ff538
	if (ctx.cr6.lt) goto loc_825FF538;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FF538:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff564
	if (!ctx.cr0.eq) goto loc_825FF564;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x825ff550
	if (ctx.cr6.lt) goto loc_825FF550;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FF550:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff564
	if (!ctx.cr0.eq) goto loc_825FF564;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r6,r25
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x825ff520
	if (ctx.cr6.lt) goto loc_825FF520;
loc_825FF564:
	// mr r9,r6
	ctx.r9.u64 = ctx.r6.u64;
	// mr r7,r8
	ctx.r7.u64 = ctx.r8.u64;
	// b 0x825ff5d4
	goto loc_825FF5D4;
loc_825FF570:
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lfs f0,412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f13,412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x825ff590
	if (ctx.cr6.lt) goto loc_825FF590;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FF590:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff5d0
	if (!ctx.cr0.eq) goto loc_825FF5D0;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x825ff5a8
	if (ctx.cr6.lt) goto loc_825FF5A8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825FF5A8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825ff5dc
	if (!ctx.cr0.eq) goto loc_825FF5DC;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825ff5d0
	if (ctx.cr6.eq) goto loc_825FF5D0;
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r5,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r5.u32);
loc_825FF5D0:
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
loc_825FF5D4:
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// blt cr6,0x825ff570
	if (ctx.cr6.lt) goto loc_825FF570;
loc_825FF5DC:
	// cmplw cr6,r7,r26
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r26.u32, ctx.xer);
	// ble cr6,0x825ff658
	if (!ctx.cr6.gt) goto loc_825FF658;
	// addi r11,r7,-4
	ctx.r11.s64 = ctx.r7.s64 + -4;
loc_825FF5E8:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f0,412(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 412);
	ctx.f0.f64 = double(temp.f32);
	// li r10,1
	ctx.r10.s64 = 1;
	// lfs f13,412(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 412);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x825ff608
	if (ctx.cr6.lt) goto loc_825FF608;
	// li r10,0
	ctx.r10.s64 = 0;
loc_825FF608:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x825ff644
	if (!ctx.cr0.eq) goto loc_825FF644;
	// fcmpu cr6,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// li r10,1
	ctx.r10.s64 = 1;
	// blt cr6,0x825ff620
	if (ctx.cr6.lt) goto loc_825FF620;
	// li r10,0
	ctx.r10.s64 = 0;
loc_825FF620:
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x825ff654
	if (!ctx.cr0.eq) goto loc_825FF654;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// cmplw cr6,r8,r11
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825ff644
	if (ctx.cr6.eq) goto loc_825FF644;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r5,0(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
loc_825FF644:
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// addi r11,r11,-4
	ctx.r11.s64 = ctx.r11.s64 + -4;
	// cmplw cr6,r26,r7
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x825ff5e8
	if (ctx.cr6.lt) goto loc_825FF5E8;
loc_825FF654:
	// cmplw cr6,r7,r26
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r26.u32, ctx.xer);
loc_825FF658:
	// bne cr6,0x825ff6b4
	if (!ctx.cr6.eq) goto loc_825FF6B4;
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x825ff720
	if (ctx.cr6.eq) goto loc_825FF720;
	// cmplw cr6,r6,r9
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, ctx.r9.u32, ctx.xer);
	// beq cr6,0x825ff684
	if (ctx.cr6.eq) goto loc_825FF684;
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x825ff684
	if (ctx.cr6.eq) goto loc_825FF684;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
loc_825FF684:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// addi r6,r6,4
	ctx.r6.s64 = ctx.r6.s64 + 4;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x825ff5d4
	if (ctx.cr6.eq) goto loc_825FF5D4;
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r5,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r5.u32);
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// b 0x825ff5d4
	goto loc_825FF5D4;
loc_825FF6B4:
	// cmplw cr6,r9,r25
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r25.u32, ctx.xer);
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// bne cr6,0x825ff6fc
	if (!ctx.cr6.eq) goto loc_825FF6FC;
	// addi r8,r8,-4
	ctx.r8.s64 = ctx.r8.s64 + -4;
	// cmplw cr6,r7,r8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x825ff6dc
	if (ctx.cr6.eq) goto loc_825FF6DC;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stw r11,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r11.u32);
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
loc_825FF6DC:
	// addi r6,r6,-4
	ctx.r6.s64 = ctx.r6.s64 + -4;
	// cmplw cr6,r8,r6
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r6.u32, ctx.xer);
	// beq cr6,0x825ff5d4
	if (ctx.cr6.eq) goto loc_825FF5D4;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stw r11,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r11.u32);
	// stw r10,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r10.u32);
	// b 0x825ff5d4
	goto loc_825FF5D4;
loc_825FF6FC:
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// beq cr6,0x825ff5d4
	if (ctx.cr6.eq) goto loc_825FF5D4;
	// lwz r10,0(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// stw r5,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r5.u32);
	// b 0x825ff5d4
	goto loc_825FF5D4;
loc_825FF720:
	// stw r8,0(r24)
	REX_STORE_U32(ctx.r24.u32 + 0, ctx.r8.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// stw r6,4(r24)
	REX_STORE_U32(ctx.r24.u32 + 4, ctx.r6.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82619CE8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82619CF0;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82619d10
	if (!ctx.cr6.eq) goto loc_82619D10;
loc_82619D08:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82619e20
	goto loc_82619E20;
loc_82619D10:
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// beq cr6,0x82619d30
	if (ctx.cr6.eq) goto loc_82619D30;
	// cmpwi cr6,r31,8
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 8, ctx.xer);
	// beq cr6,0x82619d30
	if (ctx.cr6.eq) goto loc_82619D30;
	// cmpwi cr6,r31,6
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 6, ctx.xer);
	// beq cr6,0x82619d30
	if (ctx.cr6.eq) goto loc_82619D30;
	// cmpwi cr6,r31,4
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 4, ctx.xer);
	// bne cr6,0x82619d08
	if (!ctx.cr6.eq) goto loc_82619D08;
loc_82619D30:
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// addi r10,r10,32688
	ctx.r10.s64 = ctx.r10.s64 + 32688;
	// addi r29,r11,22072
	ctx.r29.s64 = ctx.r11.s64 + 22072;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,144
	ctx.r4.s64 = 144;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmrghw128 v62,v60,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), simde_mm_load_si128((simde__m128i*)ctx.v60.u32)));
	// vmrghw128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v61.u32)));
	// vmrghw128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825e02a0
	ctx.lr = 0x82619D74;
	sub_825E02A0(ctx, base);
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82619d98
	if (ctx.cr0.eq) goto loc_82619D98;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x8261b390
	ctx.lr = 0x82619D90;
	sub_8261B390(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82619d9c
	goto loc_82619D9C;
loc_82619D98:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82619D9C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82619d08
	if (ctx.cr6.eq) goto loc_82619D08;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82619e28
	ctx.lr = 0x82619DB0;
	sub_82619E28(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne 0x82619de0
	if (!ctx.cr0.eq) goto loc_82619DE0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82619dc8
	if (ctx.cr6.eq) goto loc_82619DC8;
	// bl 0x825e0378
	ctx.lr = 0x82619DC8;
	sub_825E0378(ctx, base);
loc_82619DC8:
	// stw r28,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r28.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r28,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// stw r28,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r28.u32);
	// bl 0x825e0378
	ctx.lr = 0x82619DDC;
	sub_825E0378(ctx, base);
	// b 0x82619d08
	goto loc_82619D08;
loc_82619DE0:
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 4);
	// li r4,12
	ctx.r4.s64 = 12;
	// bl 0x825e02a0
	ctx.lr = 0x82619DF0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82619e08
	if (ctx.cr0.eq) goto loc_82619E08;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// bl 0x82619fd8
	ctx.lr = 0x82619E00;
	sub_82619FD8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82619e0c
	goto loc_82619E0C;
loc_82619E08:
	// mr r31,r28
	ctx.r31.u64 = ctx.r28.u64;
loc_82619E0C:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82619e1c
	if (!ctx.cr6.eq) goto loc_82619E1C;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x82619E1C;
	sub_825E0378(ctx, base);
loc_82619E1C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_82619E20:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82620610) {
	REX_FUNC_PROLOGUE();
	// b 0x8261fa18
	sub_8261FA18(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82620978) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82620980;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,3180
	ctx.r11.s64 = ctx.r4.s64 + 3180;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r29,r11,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r4,48
	ctx.r11.s64 = ctx.r4.s64 + 48;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// mulli r11,r11,24
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(24));
	// lwzx r28,r29,r3
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r3.u32);
	// beq cr6,0x82620a80
	if (ctx.cr6.eq) goto loc_82620A80;
	// lwz r27,48(r5)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r5.u32 + 48);
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r7,32(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 32);
	// rlwinm r9,r27,12,20,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 12) & 0xFFF;
	// lwz r26,44(r5)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r5.u32 + 44);
	// rlwinm r10,r7,12,20,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 12) & 0xFFF;
	// lwz r25,28(r5)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r5.u32 + 28);
	// addi r9,r9,512
	ctx.r9.s64 = ctx.r9.s64 + 512;
	// lwz r24,36(r5)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r5.u32 + 36);
	// addi r10,r10,512
	ctx.r10.s64 = ctx.r10.s64 + 512;
	// lwz r22,0(r11)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r30,r7,3
	ctx.r30.u64 = ctx.r7.u32 & 0x1FFFFFFF;
	// lwz r21,12(r11)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// rlwinm r8,r9,0,19,19
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x1000;
	// lwz r20,20(r11)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// rlwinm r3,r10,0,19,19
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x1000;
	// lwz r23,40(r5)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r5.u32 + 40);
	// add r9,r31,r4
	ctx.r9.u64 = ctx.r31.u64 + ctx.r4.u64;
	// lwz r4,16(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r7,r27,0,3,22
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x1FFFFE00;
	// lwz r27,4(r11)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r10,r26
	ctx.r10.u64 = ctx.r26.u64;
	// stw r24,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r24.u32);
	// add r7,r8,r7
	ctx.r7.u64 = ctx.r8.u64 + ctx.r7.u64;
	// add r3,r3,r30
	ctx.r3.u64 = ctx.r3.u64 + ctx.r30.u64;
	// rlwimi r10,r4,0,30,21
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFFFFFFFFFFFC03) | (ctx.r10.u64 & 0x3FC);
	// lbz r8,12126(r9)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r9.u32 + 12126);
	// rlwimi r25,r22,0,10,21
	ctx.r25.u64 = (__builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 0) & 0x3FFC00) | (ctx.r25.u64 & 0xFFFFFFFFFFC003FF);
	// rlwimi r3,r27,0,20,20
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 0) & 0x800) | (ctx.r3.u64 & 0xFFFFFFFFFFFFF7FF);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// rlwimi r23,r21,0,1,12
	ctx.r23.u64 = (__builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 0) & 0x7FF80000) | (ctx.r23.u64 & 0xFFFFFFFF8007FFFF);
	// stw r25,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// rlwimi r7,r20,0,23,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 0) & 0x1FF) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFE00);
	// stw r3,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// rlwinm r4,r26,30,28,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 30) & 0xF;
	// stw r23,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r23.u32);
	// stw r7,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// cmplw cr6,r4,r8
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x82620a48
	if (!ctx.cr6.gt) goto loc_82620A48;
	// rotlwi r8,r26,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r26.u32, 0);
	// rlwinm r8,r8,30,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0xF;
loc_82620A48:
	// lwz r7,44(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 44);
	// rlwimi r10,r8,2,26,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0x3C) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFFC3);
	// lbz r9,12152(r9)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r9.u32 + 12152);
	// rlwinm r8,r7,26,28,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 26) & 0xF;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// cmplw cr6,r8,r9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r9.u32, ctx.xer);
	// bge cr6,0x82620a68
	if (!ctx.cr6.lt) goto loc_82620A68;
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
loc_82620A68:
	// ld r8,24(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 24);
	// rlwimi r10,r9,6,22,25
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 6) & 0x3C0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFC3F);
	// or r9,r8,r6
	ctx.r9.u64 = ctx.r8.u64 | ctx.r6.u64;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// std r9,24(r31)
	REX_STORE_U64(ctx.r31.u32 + 24, ctx.r9.u64);
	// b 0x82620a8c
	goto loc_82620A8C;
loc_82620A80:
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
loc_82620A8C:
	// stwx r5,r29,r31
	REX_STORE_U32(ctx.r29.u32 + ctx.r31.u32, ctx.r5.u32);
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82620afc
	if (ctx.cr6.eq) goto loc_82620AFC;
	// lwz r11,10908(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10908);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82620aac
	if (ctx.cr6.eq) goto loc_82620AAC;
	// stw r11,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r11.u32);
	// b 0x82620afc
	goto loc_82620AFC;
loc_82620AAC:
	// lwz r11,10912(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 10912);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// and. r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 & ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82620afc
	if (ctx.cr0.eq) goto loc_82620AFC;
	// lwz r11,13736(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 13736);
	// lwz r3,13732(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 13732);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82620ad4
	if (ctx.cr6.lt) goto loc_82620AD4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8262e9d0
	ctx.lr = 0x82620AD4;
	sub_8262E9D0(ctx, base);
loc_82620AD4:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r3,8
	ctx.r9.s64 = ctx.r3.s64 + 8;
	// rlwimi r11,r28,30,2,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 30) & 0x3FFFFFFF) | (ctx.r11.u64 & 0xFFFFFFFFC0000000);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// rlwinm r11,r11,0,2,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r11.u64);
	// stw r9,13732(r31)
	REX_STORE_U32(ctx.r31.u32 + 13732, ctx.r9.u32);
loc_82620AFC:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82632580) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// stfs f1,-32(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + -32, temp.u32);
	// addi r10,r1,-32
	ctx.r10.s64 = ctx.r1.s64 + -32;
	// vspltisw128 v60,-1
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// vspltisw128 v58,-9
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_set1_epi32(int(0xFFFFFFF7)));
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r9,r9,31856
	ctx.r9.s64 = ctx.r9.s64 + 31856;
	// stfs f2,-16(r1)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r1.u32 + -16, temp.u32);
	// lfs f0,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// vslw128 v57,v60,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,-28(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -28, temp.u32);
	// vupkd3d128 v63,v59,4
	temp.f32 = 3.0f;
	temp.s32 += ctx.v59.s16[1];
	vTemp.f32[3] = temp.f32;
	temp.f32 = 3.0f;
	temp.s32 += ctx.v59.s16[0];
	vTemp.f32[2] = temp.f32;
	vTemp.f32[1] = 0.0f;
	vTemp.f32[0] = 1.0f;
	ctx.v63 = vTemp;
	// stfs f0,-24(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -24, temp.u32);
	// vslw128 v3,v60,v58
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v58.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stfs f0,-20(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -20, temp.u32);
	// addi r11,r8,31872
	ctx.r11.s64 = ctx.r8.s64 + 31872;
	// stfs f0,-12(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -12, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// vspltw128 v56,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// stfs f0,-8(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -8, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,31824
	ctx.r8.s64 = ctx.r8.s64 + 31824;
	// vspltw128 v2,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// addi r7,r1,-16
	ctx.r7.s64 = ctx.r1.s64 + -16;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v1,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vor128 v13,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// vspltw128 v30,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v31,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stfs f0,-4(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -4, temp.u32);
	// vspltw128 v29,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// vspltw128 v27,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v27.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v28,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r11,r9,31840
	ctx.r11.s64 = ctx.r9.s64 + 31840;
	// vspltw128 v12,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vspltw128 v4,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vspltw128 v7,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v7.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// vspltw128 v10,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// vspltw128 v26,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltw128 v5,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// vspltw128 v6,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// vspltw128 v8,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// vspltw128 v11,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v11.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v55,1
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_set1_epi32(int(0x1)));
	// vandc128 v54,v61,v57
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcfpsxws128 v62,v63,0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_si128((simde__m128i*)ctx.v62.s32, rex::ppc::simde_mm_vctsxs(simde_mm_load_ps(ctx.v63.f32)));
	// vor128 v0,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// vlogefp128 v54,v54
	ctx.v54.f32[0] = log2f(ctx.v54.f32[0]);
	ctx.v54.f32[1] = log2f(ctx.v54.f32[1]);
	ctx.v54.f32[2] = log2f(ctx.v54.f32[2]);
	ctx.v54.f32[3] = log2f(ctx.v54.f32[3]);
	// vcmpeqfp128 v9,v63,v59
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vand128 v62,v62,v55
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8)));
	// vsel v3,v0,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vsubfp128 v0,v3,v56
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v56.f32)));
	// vrfim128 v54,v54
	simde_mm_store_ps(ctx.v54.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v54.f32), SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_NO_EXC));
	// vmulfp128 v13,v0,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v1,v0,v1,v2
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v2.f32)));
	// vmaddfp v31,v0,v30,v31
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v30.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmulfp128 v2,v0,v63
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v3,v54,v63
	simde_mm_store_ps(ctx.v3.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vmulfp128 v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v1,v13,v29,v1
	simde_mm_store_ps(ctx.v1.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v29.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v31,v13,v28,v31
	simde_mm_store_ps(ctx.v31.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v28.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmulfp128 v30,v13,v13
	simde_mm_store_ps(ctx.v30.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v13,v0,v27,v1
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v27.f32)), simde_mm_load_ps(ctx.v1.f32)));
	// vmaddfp v0,v0,v26,v31
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v26.f32)), simde_mm_load_ps(ctx.v31.f32)));
	// vmaddfp v0,v30,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v2,v0,v3
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v3.f32)));
	// vrfim128 v54,v0
	simde_mm_store_ps(ctx.v54.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v0.f32), SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_NO_EXC));
	// vsubfp128 v0,v0,v54
	simde_mm_store_ps(ctx.v0.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v54.f32)));
	// vexptefp128 v54,v54
	{
		simde__m128 x = simde_mm_load_ps(ctx.v54.f32);
		simde__m128 n = simde_mm_round_ps(x, SIMDE_MM_FROUND_TO_NEG_INF | SIMDE_MM_FROUND_NO_EXC);
		simde__m128 f = simde_mm_sub_ps(x, n);
		simde__m128 p = simde_mm_set1_ps(1.8775767e-3f);
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(8.9893397e-3f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(5.5826318e-2f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(2.4015361e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(6.9315308e-1f));
		p = simde_mm_add_ps(simde_mm_mul_ps(p, f), simde_mm_set1_ps(1.0f));
		simde__m128i exp_bits = simde_mm_slli_epi32(
			simde_mm_add_epi32(simde_mm_cvttps_epi32(n), simde_mm_set1_epi32(127)), 23);
		simde_mm_store_ps(ctx.v54.f32, simde_mm_mul_ps(p, simde_mm_castsi128_ps(exp_bits)));
	}
	// vmulfp128 v13,v0,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v4,v0,v4,v12
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v4.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v6,v0,v6,v5
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vmulfp128 v0,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v7,v13,v7,v4
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v4.f32)));
	// vmaddfp v8,v13,v8,v6
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vand128 v57,v61,v57
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8)));
	// vslw128 v62,v62,v60
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v62.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vmaddfp v7,v0,v10,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v10.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vmulfp128 v13,v13,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vslw128 v60,v60,v58
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v60.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v58.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_sllv_epi32(a, shift));
	}
	// vcmpeqfp128 v58,v61,v59
	simde_mm_store_ps(ctx.v58.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// addi r11,r1,-16
	ctx.r11.s64 = ctx.r1.s64 + -16;
	// vcmpgtfp128 v53,v59,v63
	simde_mm_store_ps(ctx.v53.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vand128 v62,v57,v62
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vrfiz128 v57,v63
	simde_mm_store_ps(ctx.v57.f32, simde_mm_round_ps(simde_mm_load_ps(ctx.v63.f32), SIMDE_MM_FROUND_TO_ZERO | SIMDE_MM_FROUND_NO_EXC));
	// vcmpgtfp128 v61,v59,v61
	simde_mm_store_ps(ctx.v61.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v59.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vsrw128 v10,v60,v55
	ctx.v10.u32[0] = ctx.v60.u32[0] >> (ctx.v55.u8[0] & 0x1F);
	ctx.v10.u32[1] = ctx.v60.u32[1] >> (ctx.v55.u8[4] & 0x1F);
	ctx.v10.u32[2] = ctx.v60.u32[2] >> (ctx.v55.u8[8] & 0x1F);
	ctx.v10.u32[3] = ctx.v60.u32[3] >> (ctx.v55.u8[12] & 0x1F);
	// vmaddfp v8,v0,v11,v8
	simde_mm_store_ps(ctx.v8.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vor128 v11,v59,v62
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vor128 v0,v56,v56
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)ctx.v56.u8));
	// vor128 v60,v58,v9
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// vcmpeqfp128 v63,v63,v57
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v57.f32)));
	// vmaddfp v7,v13,v8,v7
	simde_mm_store_ps(ctx.v7.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vandc128 v13,v58,v53
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8)));
	// vsel v13,v10,v11,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vandc128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8)));
	// vsel v8,v13,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vor128 v61,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v7.u8));
	// vor128 v7,v63,v60
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8)));
	// vrefp128 v0,v61
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v61.f32)));
	// vor128 v9,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vor128 v10,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// vnmsubfp v6,v9,v0,v12
	simde_mm_store_ps(ctx.v6.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vor v13,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vmaddfp v0,v0,v6,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v12,v10,v0,v12
	simde_mm_store_ps(ctx.v12.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v0,v0,v12,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v12,v13,v0,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// vmulfp128 v63,v54,v12
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v12.f32)));
	// vor128 v0,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// vsel v13,v0,v8,v7
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v8.u8))));
	// stvx128 v13,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f1,-16(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -16);
	ctx.f1.f64 = double(temp.f32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_826531F8) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8265321C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82653260
	if (ctx.cr0.eq) goto loc_82653260;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82653238;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// beq cr6,0x82653260
	if (ctx.cr6.eq) goto loc_82653260;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82653254;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne cr6,0x82653264
	if (!ctx.cr6.eq) goto loc_82653264;
loc_82653260:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82653264:
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

DEFINE_REX_FUNC(sub_82657828) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef4
	ctx.lr = 0x82657830;
	__savegprlr_19(ctx, base);
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273aef0
	ctx.lr = 0x82657838;
	__savefpr_14(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r31,0(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r21,r3
	ctx.r21.u64 = ctx.r3.u64;
	// lwz r11,352(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 352);
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// lwz r20,360(r3)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r3.u32 + 360);
	// mr r23,r6
	ctx.r23.u64 = ctx.r6.u64;
	// lwz r27,384(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 384);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r25,34(r31)
	ctx.r25.u64 = REX_LOAD_U16(ctx.r31.u32 + 34);
	// beq cr6,0x82657e08
	if (ctx.cr6.eq) goto loc_82657E08;
	// lwz r11,424(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 424);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82657874
	if (ctx.cr6.eq) goto loc_82657874;
	// li r20,6
	ctx.r20.s64 = 6;
loc_82657874:
	// cmpwi cr6,r25,6
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 6, ctx.xer);
	// bne cr6,0x82657b2c
	if (!ctx.cr6.eq) goto loc_82657B2C;
	// cmpwi cr6,r20,2
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 2, ctx.xer);
	// bne cr6,0x82657b2c
	if (!ctx.cr6.eq) goto loc_82657B2C;
	// lwz r11,372(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + 372);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f29,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f29.f64 = double(temp.f32);
	// lfs f28,4(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f28.f64 = double(temp.f32);
	// lfs f27,8(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 8);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,12(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12);
	ctx.f26.f64 = double(temp.f32);
	// lfs f25,16(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 16);
	ctx.f25.f64 = double(temp.f32);
	// lfs f24,20(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20);
	ctx.f24.f64 = double(temp.f32);
	// lfs f23,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f23.f64 = double(temp.f32);
	// lfs f22,4(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4);
	ctx.f22.f64 = double(temp.f32);
	// lfs f21,8(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8);
	ctx.f21.f64 = double(temp.f32);
	// lfs f20,12(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12);
	ctx.f20.f64 = double(temp.f32);
	// lfs f19,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f19.f64 = double(temp.f32);
	// lfs f18,20(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20);
	ctx.f18.f64 = double(temp.f32);
	// ble cr6,0x82657e08
	if (!ctx.cr6.gt) goto loc_82657E08;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lfs f0,7996(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7996);
	ctx.f0.f64 = double(temp.f32);
	// lfs f30,2524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f30.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
loc_826578E0:
	// lwz r11,524(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826578FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r9,524(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// li r6,1
	ctx.r6.s64 = 1;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// frsp f31,f13
	ctx.f31.f64 = double(float(ctx.f13.f64));
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x8265792C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lwz r7,524(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// li r6,2
	ctx.r6.s64 = 2;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// std r8,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r8.u64);
	// lfd f12,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// frsp f17,f11
	ctx.f17.f64 = double(float(ctx.f11.f64));
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x8265795C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r4,r3
	ctx.r4.s64 = ctx.r3.s32;
	// lwz r11,524(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// li r6,3
	ctx.r6.s64 = 3;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// std r4,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r4.u64);
	// lfd f10,104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f9,f10
	ctx.f9.f64 = double(ctx.f10.s64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// frsp f16,f9
	ctx.f16.f64 = double(float(ctx.f9.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8265798C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r9,524(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// li r6,4
	ctx.r6.s64 = 4;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// lfd f8,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f7,f8
	ctx.f7.f64 = double(ctx.f8.s64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// frsp f15,f7
	ctx.f15.f64 = double(float(ctx.f7.f64));
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826579BC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r8,r3
	ctx.r8.s64 = ctx.r3.s32;
	// lwz r7,524(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// li r6,5
	ctx.r6.s64 = 5;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// std r8,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r8.u64);
	// lfd f6,120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// fcfid f5,f6
	ctx.f5.f64 = double(ctx.f6.s64);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// frsp f14,f5
	ctx.f14.f64 = double(float(ctx.f5.f64));
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826579EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r6,r3
	ctx.r6.s64 = ctx.r3.s32;
	// fmuls f4,f14,f25
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = double(float(ctx.f14.f64 * ctx.f25.f64));
	// fmuls f3,f14,f19
	ctx.f3.f64 = double(float(ctx.f14.f64 * ctx.f19.f64));
	// std r6,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r6.u64);
	// lfd f2,128(r1)
	ctx.f2.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f1,f2
	ctx.f1.f64 = double(ctx.f2.s64);
	// frsp f0,f1
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// fmadds f13,f0,f24,f4
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f24.f64, ctx.f4.f64)));
	// fmadds f12,f0,f18,f3
	ctx.f12.f64 = double(float(std::fma(ctx.f0.f64, ctx.f18.f64, ctx.f3.f64)));
	// fmadds f11,f15,f26,f13
	ctx.f11.f64 = double(float(std::fma(ctx.f15.f64, ctx.f26.f64, ctx.f13.f64)));
	// fmadds f10,f15,f20,f12
	ctx.f10.f64 = double(float(std::fma(ctx.f15.f64, ctx.f20.f64, ctx.f12.f64)));
	// fmadds f9,f16,f27,f11
	ctx.f9.f64 = double(float(std::fma(ctx.f16.f64, ctx.f27.f64, ctx.f11.f64)));
	// fmadds f8,f17,f28,f9
	ctx.f8.f64 = double(float(std::fma(ctx.f17.f64, ctx.f28.f64, ctx.f9.f64)));
	// fmadds f0,f31,f29,f8
	ctx.f0.f64 = double(float(std::fma(ctx.f31.f64, ctx.f29.f64, ctx.f8.f64)));
	// fmadds f7,f16,f21,f10
	ctx.f7.f64 = double(float(std::fma(ctx.f16.f64, ctx.f21.f64, ctx.f10.f64)));
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// fmadds f6,f17,f22,f7
	ctx.f6.f64 = double(float(std::fma(ctx.f17.f64, ctx.f22.f64, ctx.f7.f64)));
	// lfs f17,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f17.f64 = double(temp.f32);
	// fmadds f31,f31,f23,f6
	ctx.f31.f64 = double(float(std::fma(ctx.f31.f64, ctx.f23.f64, ctx.f6.f64)));
	// bge cr6,0x82657a50
	if (!ctx.cr6.lt) goto loc_82657A50;
	// fsubs f0,f0,f17
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f17.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f13.u64);
	// lwz r3,140(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// b 0x82657a60
	goto loc_82657A60;
loc_82657A50:
	// fadds f0,f0,f17
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f17.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f13.u64);
	// lwz r3,140(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
loc_82657A60:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82657a78
	if (ctx.cr6.lt) goto loc_82657A78;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82657a7c
	if (!ctx.cr6.gt) goto loc_82657A7C;
loc_82657A78:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82657A7C:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82657A94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// fcmpu cr6,f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f31.f64, ctx.f30.f64);
	// bge cr6,0x82657ab0
	if (!ctx.cr6.lt) goto loc_82657AB0;
	// fsubs f0,f31,f17
	ctx.f0.f64 = double(float(ctx.f31.f64 - ctx.f17.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f13.u64);
	// lwz r3,140(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// b 0x82657ac0
	goto loc_82657AC0;
loc_82657AB0:
	// fadds f0,f31,f17
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f31.f64 + ctx.f17.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f13.u64);
	// lwz r3,140(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
loc_82657AC0:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82657ad8
	if (ctx.cr6.lt) goto loc_82657AD8;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82657adc
	if (!ctx.cr6.gt) goto loc_82657ADC;
loc_82657AD8:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82657ADC:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82657AF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r23,r9,r23
	ctx.r23.u64 = ctx.r9.u64 + ctx.r23.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// bne 0x826578e0
	if (!ctx.cr0.eq) goto loc_826578E0;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af3c
	ctx.lr = 0x82657B28;
	__restfpr_14(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_82657B2C:
	// cmpw cr6,r25,r20
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r20.s32, ctx.xer);
	// blt cr6,0x82657c9c
	if (ctx.cr6.lt) goto loc_82657C9C;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// ble cr6,0x82657e08
	if (!ctx.cr6.gt) goto loc_82657E08;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r19,r20,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r22,r5
	ctx.r22.u64 = ctx.r5.u64;
	// lfs f31,7996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7996);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,2524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f30.f64 = double(temp.f32);
loc_82657B54:
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a590
	ctx.lr = 0x82657B64;
	sub_8273A590(ctx, base);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x82657be8
	if (!ctx.cr6.gt) goto loc_82657BE8;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r24,r20
	ctx.r24.u64 = ctx.r20.u64;
loc_82657B74:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x82657bdc
	if (!ctx.cr6.gt) goto loc_82657BDC;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82657B84:
	// lwz r11,524(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82657BA0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r9,372(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 372);
	// lfsx f0,r28,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r27.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// std r10,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f13,136(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// cmpw cr6,r30,r25
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r25.s32, ctx.xer);
	// frsp f11,f12
	ctx.f11.f64 = double(float(ctx.f12.f64));
	// lwzx r8,r28,r9
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r9.u32);
	// lfsx f10,r8,r29
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	ctx.f10.f64 = double(temp.f32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// fmadds f9,f11,f10,f0
	ctx.f9.f64 = double(float(std::fma(ctx.f11.f64, ctx.f10.f64, ctx.f0.f64)));
	// stfsx f9,r28,r27
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r28.u32 + ctx.r27.u32, temp.u32);
	// blt cr6,0x82657b84
	if (ctx.cr6.lt) goto loc_82657B84;
loc_82657BDC:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// bne 0x82657b74
	if (!ctx.cr0.eq) goto loc_82657B74;
loc_82657BE8:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x82657c6c
	if (!ctx.cr6.gt) goto loc_82657C6C;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
loc_82657BF8:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82657c18
	if (!ctx.cr6.lt) goto loc_82657C18;
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// b 0x82657c28
	goto loc_82657C28;
loc_82657C18:
	// fadds f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
loc_82657C28:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82657c40
	if (ctx.cr6.lt) goto loc_82657C40;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82657c44
	if (!ctx.cr6.gt) goto loc_82657C44;
loc_82657C40:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82657C44:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82657C5C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r30,r20
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r20.s32, ctx.xer);
	// blt cr6,0x82657bf8
	if (ctx.cr6.lt) goto loc_82657BF8;
loc_82657C6C:
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// mullw r11,r10,r25
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r25.s32);
	// mullw r10,r10,r20
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r20.s32);
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r23,r10,r23
	ctx.r23.u64 = ctx.r10.u64 + ctx.r23.u64;
	// bne 0x82657b54
	if (!ctx.cr0.eq) goto loc_82657B54;
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af3c
	ctx.lr = 0x82657C98;
	__restfpr_14(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
loc_82657C9C:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r22,r5,-1
	ctx.r22.s64 = ctx.r5.s64 + -1;
	// mullw r10,r22,r11
	ctx.r10.s64 = int64_t(ctx.r22.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r10,r25
	ctx.r11.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r25.s32);
	// mullw r10,r10,r20
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r20.s32);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// add r23,r10,r23
	ctx.r23.u64 = ctx.r10.u64 + ctx.r23.u64;
	// blt cr6,0x82657e08
	if (ctx.cr6.lt) goto loc_82657E08;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// rlwinm r19,r20,2,0,29
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f31,7996(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7996);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,2524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f30.f64 = double(temp.f32);
loc_82657CD4:
	// mr r5,r19
	ctx.r5.u64 = ctx.r19.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x8273a590
	ctx.lr = 0x82657CE4;
	sub_8273A590(ctx, base);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x82657d68
	if (!ctx.cr6.gt) goto loc_82657D68;
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r24,r20
	ctx.r24.u64 = ctx.r20.u64;
loc_82657CF4:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// ble cr6,0x82657d5c
	if (!ctx.cr6.gt) goto loc_82657D5C;
	// li r29,0
	ctx.r29.s64 = 0;
loc_82657D04:
	// lwz r11,524(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 524);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lhz r5,110(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + 110);
	// lwz r4,88(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82657D20;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// extsw r10,r3
	ctx.r10.s64 = ctx.r3.s32;
	// lwz r9,372(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + 372);
	// lfsx f0,r28,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r27.u32);
	ctx.f0.f64 = double(temp.f32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// std r10,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// lfd f12,136(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// fcfid f11,f12
	ctx.f11.f64 = double(ctx.f12.s64);
	// cmpw cr6,r30,r25
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r25.s32, ctx.xer);
	// frsp f10,f11
	ctx.f10.f64 = double(float(ctx.f11.f64));
	// lwzx r8,r28,r9
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + ctx.r9.u32);
	// lfsx f13,r8,r29
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + ctx.r29.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// fmadds f9,f10,f13,f0
	ctx.f9.f64 = double(float(std::fma(ctx.f10.f64, ctx.f13.f64, ctx.f0.f64)));
	// stfsx f9,r28,r27
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r28.u32 + ctx.r27.u32, temp.u32);
	// blt cr6,0x82657d04
	if (ctx.cr6.lt) goto loc_82657D04;
loc_82657D5C:
	// addic. r24,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r24.s64 = ctx.r24.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// bne 0x82657cf4
	if (!ctx.cr0.eq) goto loc_82657CF4;
loc_82657D68:
	// li r30,0
	ctx.r30.s64 = 0;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// ble cr6,0x82657dec
	if (!ctx.cr6.gt) goto loc_82657DEC;
	// mr r29,r27
	ctx.r29.u64 = ctx.r27.u64;
loc_82657D78:
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bge cr6,0x82657d98
	if (!ctx.cr6.lt) goto loc_82657D98;
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// b 0x82657da8
	goto loc_82657DA8;
loc_82657D98:
	// fadds f0,f0,f31
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// fctiwz f13,f0
	ctx.f13.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r3,132(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
loc_82657DA8:
	// lwz r11,112(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 112);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82657dc0
	if (ctx.cr6.lt) goto loc_82657DC0;
	// lwz r11,116(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// cmpw cr6,r3,r11
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x82657dc4
	if (!ctx.cr6.gt) goto loc_82657DC4;
loc_82657DC0:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
loc_82657DC4:
	// lwz r11,520(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 520);
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82657DDC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// cmpw cr6,r30,r20
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r20.s32, ctx.xer);
	// blt cr6,0x82657d78
	if (ctx.cr6.lt) goto loc_82657D78;
loc_82657DEC:
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addic. r22,r22,-1
	ctx.xer.ca = ctx.r22.u32 > 0;
	ctx.r22.s64 = ctx.r22.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// mullw r10,r11,r25
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r25.s32);
	// mullw r9,r11,r20
	ctx.r9.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r20.s32);
	// subf r26,r10,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r10.u64;
	// subf r23,r9,r23
	ctx.r23.u64 = ctx.r23.u64 - ctx.r9.u64;
	// bge 0x82657cd4
	if (!ctx.cr0.lt) goto loc_82657CD4;
loc_82657E08:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// addi r12,r1,-112
	ctx.r12.s64 = ctx.r1.s64 + -112;
	// bl 0x8273af3c
	ctx.lr = 0x82657E18;
	__restfpr_14(ctx, base);
	// b 0x82739f44
	__restgprlr_19(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82690F10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82690F18;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r29,28(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r31,r6
	ctx.r31.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82690f5c
	if (ctx.cr6.eq) goto loc_82690F5C;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82690f5c
	if (ctx.cr6.eq) goto loc_82690F5C;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82690f5c
	if (ctx.cr6.eq) goto loc_82690F5C;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82690f5c
	if (ctx.cr6.eq) goto loc_82690F5C;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// bne cr6,0x82690f6c
	if (!ctx.cr6.eq) goto loc_82690F6C;
loc_82690F5C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82690F6C:
	// stb r3,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r3.u8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82690fa8
	if (ctx.cr6.lt) goto loc_82690FA8;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// stb r10,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r10.u8);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stw r9,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r9.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// stw r8,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r8.u32);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82690FA8:
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwz r4,0(r28)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82690FCC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82691018
	if (ctx.cr6.lt) goto loc_82691018;
	// ld r10,8(r29)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r29.u32 + 8);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r11,8(r29)
	REX_STORE_U64(ctx.r29.u32 + 8, ctx.r11.u64);
	// lwz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r9,0(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r8.u32);
	// lwz r7,0(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lbz r6,0(r7)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// stb r6,0(r27)
	REX_STORE_U8(ctx.r27.u32 + 0, ctx.r6.u8);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// stw r5,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r5.u32);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r4,r11,-1
	ctx.r4.s64 = ctx.r11.s64 + -1;
	// stw r4,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r4.u32);
loc_82691018:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82699CE0) {
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
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82699d5c
	if (ctx.cr6.eq) goto loc_82699D5C;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lwz r3,4(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// addi r4,r11,13608
	ctx.r4.s64 = ctx.r11.s64 + 13608;
	// bl 0x8268f750
	ctx.lr = 0x82699D18;
	sub_8268F750(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82699d5c
	if (!ctx.cr6.eq) goto loc_82699D5C;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r11,12876
	ctx.r4.s64 = ctx.r11.s64 + 12876;
	// bl 0x8268f750
	ctx.lr = 0x82699D30;
	sub_8268F750(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82699d5c
	if (!ctx.cr6.eq) goto loc_82699D5C;
	// lis r11,-32254
	ctx.r11.s64 = -2113798144;
	// lwz r3,4(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r4,r11,13604
	ctx.r4.s64 = ctx.r11.s64 + 13604;
	// bl 0x8268f750
	ctx.lr = 0x82699D48;
	sub_8268F750(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82699d5c
	if (!ctx.cr6.eq) goto loc_82699D5C;
	// lis r3,-32688
	ctx.r3.s64 = -2142240768;
	// ori r3,r3,3
	ctx.r3.u64 = ctx.r3.u64 | 3;
	// b 0x82699dbc
	goto loc_82699DBC;
loc_82699D5C:
	// lis r11,-32151
	ctx.r11.s64 = -2107047936;
	// lis r10,-32151
	ctx.r10.s64 = -2107047936;
	// lis r9,-32150
	ctx.r9.s64 = -2106982400;
	// lis r8,-32151
	ctx.r8.s64 = -2107047936;
	// addi r4,r11,352
	ctx.r4.s64 = ctx.r11.s64 + 352;
	// lis r7,-32151
	ctx.r7.s64 = -2107047936;
	// addi r11,r10,27208
	ctx.r11.s64 = ctx.r10.s64 + 27208;
	// stw r4,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// lis r6,-32151
	ctx.r6.s64 = -2107047936;
	// addi r10,r9,-26720
	ctx.r10.s64 = ctx.r9.s64 + -26720;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r5,-32151
	ctx.r5.s64 = -2107047936;
	// addi r9,r8,27784
	ctx.r9.s64 = ctx.r8.s64 + 27784;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// addi r8,r7,28192
	ctx.r8.s64 = ctx.r7.s64 + 28192;
	// addi r7,r6,2960
	ctx.r7.s64 = ctx.r6.s64 + 2960;
	// stw r9,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// addi r6,r5,3408
	ctx.r6.s64 = ctx.r5.s64 + 3408;
	// stw r8,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r8.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r7,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r7.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r6,24(r31)
	REX_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// stw r5,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
loc_82699DBC:
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

DEFINE_REX_FUNC(sub_8269C5A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x8269C5A8;
	__savegprlr_25(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// stw r11,0(r6)
	REX_STORE_U32(ctx.r6.u32 + 0, ctx.r11.u32);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// std r11,0(r7)
	REX_STORE_U64(ctx.r7.u32 + 0, ctx.r11.u64);
	// mr r26,r5
	ctx.r26.u64 = ctx.r5.u64;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// mr r27,r6
	ctx.r27.u64 = ctx.r6.u64;
	// lwz r31,44(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// mr r25,r7
	ctx.r25.u64 = ctx.r7.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x8269c4d8
	ctx.lr = 0x8269C5E0;
	sub_8269C4D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c724
	if (ctx.cr6.lt) goto loc_8269C724;
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8269c61c
	if (ctx.cr6.eq) goto loc_8269C61C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// ld r4,56(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 56);
	// bl 0x8269c020
	ctx.lr = 0x8269C600;
	sub_8269C020(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c724
	if (ctx.cr6.lt) goto loc_8269C724;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8269c4d8
	ctx.lr = 0x8269C614;
	sub_8269C4D8(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c724
	if (ctx.cr6.lt) goto loc_8269C724;
loc_8269C61C:
	// ld r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// addi r6,r1,84
	ctx.r6.s64 = ctx.r1.s64 + 84;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// bl 0x8269be28
	ctx.lr = 0x8269C634;
	sub_8269BE28(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c724
	if (ctx.cr6.lt) goto loc_8269C724;
	// lwz r30,80(r1)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ld r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// cmpld cr6,r8,r10
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r10.u64, ctx.xer);
	// bne cr6,0x8269c67c
	if (!ctx.cr6.eq) goto loc_8269C67C;
	// ld r4,128(r31)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r31.u32 + 128);
	// lwz r11,136(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// subf r10,r4,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r4.u64;
	// cmpld cr6,r10,r11
	ctx.cr6.compare<uint64_t>(ctx.r10.u64, ctx.r11.u64, ctx.xer);
	// blt cr6,0x8269c67c
	if (ctx.cr6.lt) goto loc_8269C67C;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8269ba30
	ctx.lr = 0x8269C66C;
	sub_8269BA30(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x8269c724
	if (ctx.cr6.lt) goto loc_8269C724;
	// ld r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// std r8,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r8.u64);
loc_8269C67C:
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// clrldi r11,r28,32
	ctx.r11.u64 = ctx.r28.u64 & 0xFFFFFFFF;
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// ld r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r9.u32 + 8);
	// subf r7,r8,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r8.u64;
	// add r6,r7,r9
	ctx.r6.u64 = ctx.r7.u64 + ctx.r9.u64;
	// cmpld cr6,r6,r11
	ctx.cr6.compare<uint64_t>(ctx.r6.u64, ctx.r11.u64, ctx.xer);
	// blt cr6,0x8269c6d0
	if (ctx.cr6.lt) goto loc_8269C6D0;
	// stw r28,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r28.u32);
	// lwz r9,0(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ld r8,40(r31)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// ld r10,8(r9)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r9.u32 + 8);
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r6,r8,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r8.u64;
	// cmpld cr6,r6,r11
	ctx.cr6.compare<uint64_t>(ctx.r6.u64, ctx.r11.u64, ctx.xer);
	// bne cr6,0x8269c6f0
	if (!ctx.cr6.eq) goto loc_8269C6F0;
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// b 0x8269c6f0
	goto loc_8269C6F0;
loc_8269C6D0:
	// rotlwi r11,r9,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// rotlwi r9,r8,0
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r8.u32, 0);
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r8,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r8.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r7,r11,-1
	ctx.r7.s64 = ctx.r11.s64 + -1;
	// stw r7,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r7.u32);
loc_8269C6F0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// ld r9,40(r31)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// ld r7,8(r11)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// subf r11,r7,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r7.u64;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r6,0(r26)
	REX_STORE_U32(ctx.r26.u32 + 0, ctx.r6.u32);
	// ld r5,40(r31)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// std r5,0(r25)
	REX_STORE_U64(ctx.r25.u32 + 0, ctx.r5.u64);
	// lwz r11,0(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// ld r10,40(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 40);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// std r4,40(r31)
	REX_STORE_U64(ctx.r31.u32 + 40, ctx.r4.u64);
loc_8269C724:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826B96B8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826B96C0;
	__savegprlr_14(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r10,80(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 80);
	// li r22,1
	ctx.r22.s64 = 1;
	// lwz r26,22248(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 22248);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// lwz r23,22244(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 22244);
	// mr r14,r6
	ctx.r14.u64 = ctx.r6.u64;
	// stw r4,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r4.u32);
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// stw r5,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r5.u32);
	// mr r15,r8
	ctx.r15.u64 = ctx.r8.u64;
	// stw r24,22272(r3)
	REX_STORE_U32(ctx.r3.u32 + 22272, ctx.r24.u32);
	// mr r21,r24
	ctx.r21.u64 = ctx.r24.u64;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
	// stw r22,32(r10)
	REX_STORE_U32(ctx.r10.u32 + 32, ctx.r22.u32);
	// mr r17,r24
	ctx.r17.u64 = ctx.r24.u64;
	// lwz r9,3700(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 3700);
	// mr r19,r24
	ctx.r19.u64 = ctx.r24.u64;
	// stw r7,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r7.u32);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r24,22276(r3)
	REX_STORE_U32(ctx.r3.u32 + 22276, ctx.r24.u32);
	// mr r16,r24
	ctx.r16.u64 = ctx.r24.u64;
	// bne cr6,0x826b974c
	if (!ctx.cr6.eq) goto loc_826B974C;
	// stw r24,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r24.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lwz r7,22272(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 22272);
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8269f118
	ctx.lr = 0x826B9744;
	sub_8269F118(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826b9f68
	if (!ctx.cr6.eq) goto loc_826B9F68;
loc_826B974C:
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x826b9f64
	if (ctx.cr6.eq) goto loc_826B9F64;
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x826b9f64
	if (ctx.cr6.eq) goto loc_826B9F64;
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x826b9f64
	if (ctx.cr6.eq) goto loc_826B9F64;
	// lwz r3,276(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x826b978c
	if (!ctx.cr6.lt) goto loc_826B978C;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8273a030
	ctx.lr = 0x826B9780;
	sub_8273A030(ctx, base);
	// lwz r3,276(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
loc_826B978C:
	// lwz r11,22252(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22252);
	// add r5,r31,r3
	ctx.r5.u64 = ctx.r31.u64 + ctx.r3.u64;
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x826b97c0
	if (!ctx.cr6.gt) goto loc_826B97C0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b95d0
	ctx.lr = 0x826B97A8;
	sub_826B95D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826b9f68
	if (!ctx.cr6.eq) goto loc_826B9F68;
	// lwz r26,22248(r30)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r30.u32 + 22248);
	// lwz r3,276(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r23,22244(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 22244);
loc_826B97C0:
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x826b985c
	if (!ctx.cr6.lt) goto loc_826B985C;
loc_826B97C8:
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826b9884
	if (ctx.cr6.eq) goto loc_826B9884;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwz r3,3364(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 3364);
	// addi r7,r1,276
	ctx.r7.s64 = ctx.r1.s64 + 276;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,268
	ctx.r5.s64 = ctx.r1.s64 + 268;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826ba718
	ctx.lr = 0x826B97F0;
	sub_826BA718(ctx, base);
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// lwz r8,22252(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 22252);
	// lwz r9,276(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// add r5,r31,r9
	ctx.r5.u64 = ctx.r31.u64 + ctx.r9.u64;
	// cmplw cr6,r5,r8
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r8.u32, ctx.xer);
	// ble cr6,0x826b982c
	if (!ctx.cr6.gt) goto loc_826B982C;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b95d0
	ctx.lr = 0x826B981C;
	sub_826B95D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826b9f68
	if (!ctx.cr6.eq) goto loc_826B9F68;
	// lwz r26,22248(r30)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r30.u32 + 22248);
	// lwz r23,22244(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 22244);
loc_826B982C:
	// add r3,r31,r26
	ctx.r3.u64 = ctx.r31.u64 + ctx.r26.u64;
	// lwz r5,276(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// bl 0x8273a030
	ctx.lr = 0x826B983C;
	sub_8273A030(ctx, base);
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r26,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r26.u32);
	// add r31,r31,r11
	ctx.r31.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r31,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r31.u32);
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// blt cr6,0x826b97c8
	if (ctx.cr6.lt) goto loc_826B97C8;
loc_826B985C:
	// lbz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826b9884
	if (!ctx.cr6.eq) goto loc_826B9884;
	// lbz r11,1(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 1);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826b9884
	if (!ctx.cr6.eq) goto loc_826B9884;
	// lbz r11,2(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 2);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// beq cr6,0x826b9888
	if (ctx.cr6.eq) goto loc_826B9888;
loc_826B9884:
	// mr r11,r22
	ctx.r11.u64 = ctx.r22.u64;
loc_826B9888:
	// stw r11,22220(r30)
	REX_STORE_U32(ctx.r30.u32 + 22220, ctx.r11.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r24,22268(r30)
	REX_STORE_U32(ctx.r30.u32 + 22268, ctx.r24.u32);
	// beq cr6,0x826b98b4
	if (ctx.cr6.eq) goto loc_826B98B4;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r3,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r3.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r4,0(r14)
	REX_STORE_U32(ctx.r14.u32 + 0, ctx.r4.u32);
	// stw r11,0(r15)
	REX_STORE_U32(ctx.r15.u32 + 0, ctx.r11.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826B98B4:
	// li r20,3
	ctx.r20.s64 = 3;
	// li r18,2
	ctx.r18.s64 = 2;
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// blt cr6,0x826b9e28
	if (ctx.cr6.lt) goto loc_826B9E28;
loc_826B98C4:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x826b9e28
	if (!ctx.cr6.eq) goto loc_826B9E28;
loc_826B98CC:
	// addi r11,r4,4
	ctx.r11.s64 = ctx.r4.s64 + 4;
	// lbz r5,3(r4)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r4.u32 + 3);
	// cmplwi cr6,r3,8
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 8, ctx.xer);
	// mr r28,r11
	ctx.r28.u64 = ctx.r11.u64;
	// blt cr6,0x826b9974
	if (ctx.cr6.lt) goto loc_826B9974;
	// addi r6,r3,-1
	ctx.r6.s64 = ctx.r3.s64 + -1;
	// lhz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// li r9,6
	ctx.r9.s64 = 6;
	// cmplwi cr6,r6,6
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 6, ctx.xer);
	// ble cr6,0x826b9974
	if (!ctx.cr6.gt) goto loc_826B9974;
loc_826B98F8:
	// lhz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// and r31,r10,r7
	ctx.r31.u64 = ctx.r10.u64 & ctx.r7.u64;
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// clrlwi r31,r31,16
	ctx.r31.u64 = ctx.r31.u32 & 0xFFFF;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x826b9948
	if (!ctx.cr6.eq) goto loc_826B9948;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x826b9928
	if (!ctx.cr6.eq) goto loc_826B9928;
	// rlwinm r31,r7,0,16,23
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFF00;
	// cmplwi cr6,r31,256
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 256, ctx.xer);
	// beq cr6,0x826b9960
	if (ctx.cr6.eq) goto loc_826B9960;
loc_826B9928:
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x826b9948
	if (!ctx.cr6.eq) goto loc_826B9948;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x826b9948
	if (!ctx.cr6.eq) goto loc_826B9948;
	// addi r10,r9,2
	ctx.r10.s64 = ctx.r9.s64 + 2;
	// cmplw cr6,r3,r10
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r10.u32, ctx.xer);
	// bgt cr6,0x826b9968
	if (ctx.cr6.gt) goto loc_826B9968;
loc_826B9948:
	// addi r9,r9,2
	ctx.r9.s64 = ctx.r9.s64 + 2;
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x826b98f8
	if (ctx.cr6.lt) goto loc_826B98F8;
	// b 0x826b9974
	goto loc_826B9974;
loc_826B9960:
	// addi r27,r11,-2
	ctx.r27.s64 = ctx.r11.s64 + -2;
	// b 0x826b996c
	goto loc_826B996C;
loc_826B9968:
	// addi r27,r11,-1
	ctx.r27.s64 = ctx.r11.s64 + -1;
loc_826B996C:
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// bne cr6,0x826b997c
	if (!ctx.cr6.eq) goto loc_826B997C;
loc_826B9974:
	// add r27,r4,r3
	ctx.r27.u64 = ctx.r4.u64 + ctx.r3.u64;
	// mr r25,r22
	ctx.r25.u64 = ctx.r22.u64;
loc_826B997C:
	// clrlwi r10,r5,24
	ctx.r10.u64 = ctx.r5.u32 & 0xFF;
	// stw r10,22224(r30)
	REX_STORE_U32(ctx.r30.u32 + 22224, ctx.r10.u32);
	// cmplwi cr6,r10,13
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 13, ctx.xer);
	// beq cr6,0x826b999c
	if (ctx.cr6.eq) goto loc_826B999C;
	// cmplwi cr6,r10,12
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 12, ctx.xer);
	// beq cr6,0x826b999c
	if (ctx.cr6.eq) goto loc_826B999C;
	// cmplwi cr6,r10,11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 11, ctx.xer);
	// bne cr6,0x826b99a0
	if (!ctx.cr6.eq) goto loc_826B99A0;
loc_826B999C:
	// mr r17,r22
	ctx.r17.u64 = ctx.r22.u64;
loc_826B99A0:
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// bne cr6,0x826b9a50
	if (!ctx.cr6.eq) goto loc_826B9A50;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// bne cr6,0x826b9a50
	if (!ctx.cr6.eq) goto loc_826B9A50;
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9a54
	if (!ctx.cr6.eq) goto loc_826B9A54;
	// subf r31,r4,r27
	ctx.r31.u64 = ctx.r27.u64 - ctx.r4.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x826B99CC;
	sub_8273A030(ctx, base);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,276
	ctx.r7.s64 = ctx.r1.s64 + 276;
	// lwz r3,3364(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 3364);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,268
	ctx.r5.s64 = ctx.r1.s64 + 268;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826ba718
	ctx.lr = 0x826B99E8;
	sub_826BA718(ctx, base);
	// lwz r11,80(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// lwz r9,22252(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 22252);
	// lwz r8,276(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// add r5,r31,r8
	ctx.r5.u64 = ctx.r31.u64 + ctx.r8.u64;
	// cmplw cr6,r5,r9
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r9.u32, ctx.xer);
	// ble cr6,0x826b9a24
	if (!ctx.cr6.gt) goto loc_826B9A24;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b95d0
	ctx.lr = 0x826B9A14;
	sub_826B95D0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826b9f68
	if (!ctx.cr6.eq) goto loc_826B9F68;
	// lwz r26,22248(r30)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r30.u32 + 22248);
	// lwz r23,22244(r30)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r30.u32 + 22244);
loc_826B9A24:
	// add r3,r31,r26
	ctx.r3.u64 = ctx.r31.u64 + ctx.r26.u64;
	// lwz r5,276(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// bl 0x8273a030
	ctx.lr = 0x826B9A34;
	sub_8273A030(ctx, base);
	// lwz r11,276(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// stw r26,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r26.u32);
	// add r3,r31,r11
	ctx.r3.u64 = ctx.r31.u64 + ctx.r11.u64;
	// mr r25,r24
	ctx.r25.u64 = ctx.r24.u64;
	// stw r3,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r3.u32);
	// b 0x826b98cc
	goto loc_826B98CC;
loc_826B9A50:
	// lwz r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_826B9A54:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x826b9b0c
	if (ctx.cr6.eq) goto loc_826B9B0C;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// bne cr6,0x826b9b0c
	if (!ctx.cr6.eq) goto loc_826B9B0C;
	// subf r11,r28,r27
	ctx.r11.u64 = ctx.r27.u64 - ctx.r28.u64;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x826b9aa8
	if (!ctx.cr6.gt) goto loc_826B9AA8;
	// lbz r8,-1(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -1);
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// bne cr6,0x826b9aa8
	if (!ctx.cr6.eq) goto loc_826B9AA8;
	// lbz r8,-2(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -2);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x826b9aa8
	if (!ctx.cr6.eq) goto loc_826B9AA8;
	// lbz r8,-3(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -3);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x826b9aa8
	if (!ctx.cr6.eq) goto loc_826B9AA8;
	// stb r24,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r24.u8);
	// stw r20,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r20.u32);
	// stb r24,22241(r30)
	REX_STORE_U8(ctx.r30.u32 + 22241, ctx.r24.u8);
	// stb r22,22242(r30)
	REX_STORE_U8(ctx.r30.u32 + 22242, ctx.r22.u8);
	// b 0x826b9afc
	goto loc_826B9AFC;
loc_826B9AA8:
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// ble cr6,0x826b9ad8
	if (!ctx.cr6.gt) goto loc_826B9AD8;
	// lbz r8,-1(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -1);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x826b9ad8
	if (!ctx.cr6.eq) goto loc_826B9AD8;
	// lbz r8,-2(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -2);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x826b9ad8
	if (!ctx.cr6.eq) goto loc_826B9AD8;
	// stb r24,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r24.u8);
	// stw r18,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r18.u32);
	// stb r24,22241(r30)
	REX_STORE_U8(ctx.r30.u32 + 22241, ctx.r24.u8);
	// b 0x826b9afc
	goto loc_826B9AFC;
loc_826B9AD8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b9af8
	if (ctx.cr6.eq) goto loc_826B9AF8;
	// lbz r8,-1(r27)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r27.u32 + -1);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x826b9af8
	if (!ctx.cr6.eq) goto loc_826B9AF8;
	// stb r24,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r24.u8);
	// stw r22,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r22.u32);
	// b 0x826b9afc
	goto loc_826B9AFC;
loc_826B9AF8:
	// stw r24,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r24.u32);
loc_826B9AFC:
	// lwz r8,22228(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 22228);
	// mr r19,r22
	ctx.r19.u64 = ctx.r22.u64;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// add r27,r11,r28
	ctx.r27.u64 = ctx.r11.u64 + ctx.r28.u64;
loc_826B9B0C:
	// cmplwi cr6,r10,13
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 13, ctx.xer);
	// beq cr6,0x826b9d04
	if (ctx.cr6.eq) goto loc_826B9D04;
	// cmplwi cr6,r10,12
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 12, ctx.xer);
	// beq cr6,0x826b9d04
	if (ctx.cr6.eq) goto loc_826B9D04;
	// cmplwi cr6,r10,11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 11, ctx.xer);
	// beq cr6,0x826b9d04
	if (ctx.cr6.eq) goto loc_826B9D04;
	// subf r5,r28,r27
	ctx.r5.u64 = ctx.r27.u64 - ctx.r28.u64;
	// cmpwi cr6,r10,28
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 28, ctx.xer);
	// bgt cr6,0x826b9c40
	if (ctx.cr6.gt) goto loc_826B9C40;
	// beq cr6,0x826b9c10
	if (ctx.cr6.eq) goto loc_826B9C10;
	// cmpwi cr6,r10,15
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 15, ctx.xer);
	// bgt cr6,0x826b9bd8
	if (ctx.cr6.gt) goto loc_826B9BD8;
	// beq cr6,0x826b9b98
	if (ctx.cr6.eq) goto loc_826B9B98;
	// cmpwi cr6,r10,10
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 10, ctx.xer);
	// beq cr6,0x826b9b90
	if (ctx.cr6.eq) goto loc_826B9B90;
	// cmpwi cr6,r10,14
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 14, ctx.xer);
	// bne cr6,0x826b9cfc
	if (!ctx.cr6.eq) goto loc_826B9CFC;
	// lwz r11,15504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,80(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// addi r11,r11,-7
	ctx.r11.s64 = ctx.r11.s64 + -7;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x826c88a8
	ctx.lr = 0x826B9B70;
	sub_826C88A8(ctx, base);
	// lwz r9,3700(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 3700);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x826b9ee4
	if (!ctx.cr6.eq) goto loc_826B9EE4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826a5388
	ctx.lr = 0x826B9B84;
	sub_826A5388(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826b9f68
	if (!ctx.cr6.eq) goto loc_826B9F68;
	// b 0x826b9e04
	goto loc_826B9E04;
loc_826B9B90:
	// stw r22,3704(r30)
	REX_STORE_U32(ctx.r30.u32 + 3704, ctx.r22.u32);
	// b 0x826b9e0c
	goto loc_826B9E0C;
loc_826B9B98:
	// lwz r11,15504(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 15504);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,80(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 80);
	// addi r11,r11,-7
	ctx.r11.s64 = ctx.r11.s64 + -7;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// bl 0x826c88a8
	ctx.lr = 0x826B9BB8;
	sub_826C88A8(ctx, base);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826be328
	ctx.lr = 0x826B9BC4;
	sub_826BE328(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826b9e04
	if (ctx.cr6.eq) goto loc_826B9E04;
	// stw r22,3700(r30)
	REX_STORE_U32(ctx.r30.u32 + 3700, ctx.r22.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826B9BD8:
	// cmpwi cr6,r10,27
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 27, ctx.xer);
	// bne cr6,0x826b9cfc
	if (!ctx.cr6.eq) goto loc_826B9CFC;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9bf4
	if (!ctx.cr6.eq) goto loc_826B9BF4;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// beq cr6,0x826b9bf8
	if (ctx.cr6.eq) goto loc_826B9BF8;
loc_826B9BF4:
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
loc_826B9BF8:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b94d8
	ctx.lr = 0x826B9C0C;
	sub_826B94D8(ctx, base);
	// b 0x826b9e04
	goto loc_826B9E04;
loc_826B9C10:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9c24
	if (!ctx.cr6.eq) goto loc_826B9C24;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// beq cr6,0x826b9c28
	if (ctx.cr6.eq) goto loc_826B9C28;
loc_826B9C24:
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
loc_826B9C28:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,7
	ctx.r4.s64 = 7;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b94d8
	ctx.lr = 0x826B9C3C;
	sub_826B94D8(ctx, base);
	// b 0x826b9e04
	goto loc_826B9E04;
loc_826B9C40:
	// cmpwi cr6,r10,31
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 31, ctx.xer);
	// bgt cr6,0x826b9cec
	if (ctx.cr6.gt) goto loc_826B9CEC;
	// beq cr6,0x826b9cbc
	if (ctx.cr6.eq) goto loc_826B9CBC;
	// cmpwi cr6,r10,29
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 29, ctx.xer);
	// beq cr6,0x826b9c8c
	if (ctx.cr6.eq) goto loc_826B9C8C;
	// cmpwi cr6,r10,30
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 30, ctx.xer);
	// bne cr6,0x826b9cfc
	if (!ctx.cr6.eq) goto loc_826B9CFC;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9c70
	if (!ctx.cr6.eq) goto loc_826B9C70;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// beq cr6,0x826b9c74
	if (ctx.cr6.eq) goto loc_826B9C74;
loc_826B9C70:
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
loc_826B9C74:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b94d8
	ctx.lr = 0x826B9C88;
	sub_826B94D8(ctx, base);
	// b 0x826b9e04
	goto loc_826B9E04;
loc_826B9C8C:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9ca0
	if (!ctx.cr6.eq) goto loc_826B9CA0;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// beq cr6,0x826b9ca4
	if (ctx.cr6.eq) goto loc_826B9CA4;
loc_826B9CA0:
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
loc_826B9CA4:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b94d8
	ctx.lr = 0x826B9CB8;
	sub_826B94D8(ctx, base);
	// b 0x826b9e04
	goto loc_826B9E04;
loc_826B9CBC:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9cd0
	if (!ctx.cr6.eq) goto loc_826B9CD0;
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// beq cr6,0x826b9cd4
	if (ctx.cr6.eq) goto loc_826B9CD4;
loc_826B9CD0:
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
loc_826B9CD4:
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826b94d8
	ctx.lr = 0x826B9CE8;
	sub_826B94D8(ctx, base);
	// b 0x826b9e04
	goto loc_826B9E04;
loc_826B9CEC:
	// cmpwi cr6,r10,32
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 32, ctx.xer);
	// blt cr6,0x826b9cfc
	if (ctx.cr6.lt) goto loc_826B9CFC;
	// cmpwi cr6,r10,64
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 64, ctx.xer);
	// ble cr6,0x826b9e0c
	if (!ctx.cr6.gt) goto loc_826B9E0C;
loc_826B9CFC:
	// li r16,4
	ctx.r16.s64 = 4;
	// b 0x826b9e0c
	goto loc_826B9E0C;
loc_826B9D04:
	// subf. r31,r28,r27
	ctx.r31.u64 = ctx.r27.u64 - ctx.r28.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x826b9d2c
	if (ctx.cr0.eq) goto loc_826B9D2C;
	// add r11,r31,r28
	ctx.r11.u64 = ctx.r31.u64 + ctx.r28.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
loc_826B9D14:
	// lbz r7,0(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x826b9d2c
	if (!ctx.cr6.eq) goto loc_826B9D2C;
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// bne 0x826b9d14
	if (!ctx.cr0.eq) goto loc_826B9D14;
loc_826B9D2C:
	// lwz r11,3700(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 3700);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826b9df0
	if (!ctx.cr6.eq) goto loc_826B9DF0;
	// cmplwi cr6,r10,12
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 12, ctx.xer);
	// bne cr6,0x826b9d54
	if (!ctx.cr6.eq) goto loc_826B9D54;
	// lwz r11,22172(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22172);
	// stw r31,22188(r30)
	REX_STORE_U32(ctx.r30.u32 + 22188, ctx.r31.u32);
	// stw r21,22276(r30)
	REX_STORE_U32(ctx.r30.u32 + 22276, ctx.r21.u32);
	// stw r22,22272(r30)
	REX_STORE_U32(ctx.r30.u32 + 22272, ctx.r22.u32);
	// stw r11,22176(r30)
	REX_STORE_U32(ctx.r30.u32 + 22176, ctx.r11.u32);
loc_826B9D54:
	// cmplwi cr6,r10,13
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 13, ctx.xer);
	// bne cr6,0x826b9d6c
	if (!ctx.cr6.eq) goto loc_826B9D6C;
	// lwz r11,22216(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22216);
	// stw r31,22184(r30)
	REX_STORE_U32(ctx.r30.u32 + 22184, ctx.r31.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,22216(r30)
	REX_STORE_U32(ctx.r30.u32 + 22216, ctx.r11.u32);
loc_826B9D6C:
	// cmplwi cr6,r10,11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 11, ctx.xer);
	// bne cr6,0x826b9df0
	if (!ctx.cr6.eq) goto loc_826B9DF0;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// ble cr6,0x826b9e80
	if (!ctx.cr6.gt) goto loc_826B9E80;
	// lbz r11,0(r28)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lbz r9,1(r28)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r28.u32 + 1);
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// rotlwi r10,r11,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// lwz r7,22272(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 22272);
	// rlwinm r11,r9,25,7,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 25) & 0x1FFFFFF;
	// li r4,1
	ctx.r4.s64 = 1;
	// add r8,r11,r10
	ctx.r8.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// addi r29,r28,1
	ctx.r29.s64 = ctx.r28.s64 + 1;
	// bl 0x8269f118
	ctx.lr = 0x826B9DB0;
	sub_8269F118(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x826b9dec
	if (ctx.cr6.eq) goto loc_826B9DEC;
	// cmpwi cr6,r3,4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 4, ctx.xer);
	// bne cr6,0x826b9edc
	if (!ctx.cr6.eq) goto loc_826B9EDC;
	// lwz r10,84(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r11,r21,1
	ctx.r11.s64 = ctx.r21.s64 + 1;
	// li r16,4
	ctx.r16.s64 = 4;
	// rlwinm r9,r10,31,24,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0xFF;
	// addi r31,r31,-2
	ctx.r31.s64 = ctx.r31.s64 + -2;
	// stbx r9,r23,r21
	REX_STORE_U8(ctx.r23.u32 + ctx.r21.u32, ctx.r9.u8);
	// addi r28,r28,2
	ctx.r28.s64 = ctx.r28.s64 + 2;
	// lbz r8,0(r29)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// clrlwi r7,r8,25
	ctx.r7.u64 = ctx.r8.u32 & 0x7F;
	// addi r21,r11,1
	ctx.r21.s64 = ctx.r11.s64 + 1;
	// stbx r7,r23,r11
	REX_STORE_U8(ctx.r23.u32 + ctx.r11.u32, ctx.r7.u8);
loc_826B9DEC:
	// lwz r29,292(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
loc_826B9DF0:
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// add r3,r23,r21
	ctx.r3.u64 = ctx.r23.u64 + ctx.r21.u64;
	// bl 0x8273a030
	ctx.lr = 0x826B9E00;
	sub_8273A030(ctx, base);
	// add r21,r31,r21
	ctx.r21.u64 = ctx.r31.u64 + ctx.r21.u64;
loc_826B9E04:
	// lwz r4,268(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 268);
	// lwz r3,276(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 276);
loc_826B9E0C:
	// subf r11,r27,r4
	ctx.r11.u64 = ctx.r4.u64 - ctx.r27.u64;
	// stw r27,268(r1)
	REX_STORE_U32(ctx.r1.u32 + 268, ctx.r27.u32);
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// stw r3,276(r1)
	REX_STORE_U32(ctx.r1.u32 + 276, ctx.r3.u32);
	// cmplwi cr6,r3,4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 4, ctx.xer);
	// bge cr6,0x826b98c4
	if (!ctx.cr6.lt) goto loc_826B98C4;
loc_826B9E28:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x826b9f4c
	if (ctx.cr6.eq) goto loc_826B9F4C;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// bne cr6,0x826b9f4c
	if (!ctx.cr6.eq) goto loc_826B9F4C;
	// add r11,r23,r21
	ctx.r11.u64 = ctx.r23.u64 + ctx.r21.u64;
	// cmplwi cr6,r21,2
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 2, ctx.xer);
	// ble cr6,0x826b9ef0
	if (!ctx.cr6.gt) goto loc_826B9EF0;
	// lbz r9,-1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// cmplwi cr6,r9,1
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 1, ctx.xer);
	// bne cr6,0x826b9ef0
	if (!ctx.cr6.eq) goto loc_826B9EF0;
	// lbz r9,-2(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -2);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826b9ef0
	if (!ctx.cr6.eq) goto loc_826B9EF0;
	// lbz r9,-3(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -3);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826b9ef0
	if (!ctx.cr6.eq) goto loc_826B9EF0;
	// stb r24,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r24.u8);
	// stw r20,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r20.u32);
	// stb r24,22241(r30)
	REX_STORE_U8(ctx.r30.u32 + 22241, ctx.r24.u8);
	// stb r22,22242(r30)
	REX_STORE_U8(ctx.r30.u32 + 22242, ctx.r22.u8);
	// b 0x826b9f44
	goto loc_826B9F44;
loc_826B9E80:
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x826b9df0
	if (!ctx.cr6.eq) goto loc_826B9DF0;
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// stw r22,22268(r30)
	REX_STORE_U32(ctx.r30.u32 + 22268, ctx.r22.u32);
	// bne cr6,0x826b9df0
	if (!ctx.cr6.eq) goto loc_826B9DF0;
	// lwz r11,22228(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22228);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bgt cr6,0x826b9ee4
	if (ctx.cr6.gt) goto loc_826B9EE4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826b9ec0
	if (ctx.cr6.eq) goto loc_826B9EC0;
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// addi r11,r10,22241
	ctx.r11.s64 = ctx.r10.s64 + 22241;
loc_826B9EB4:
	// lbz r10,-2(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + -2);
	// stbu r10,-1(r11)
	ea = -1 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r10.u8);
	ctx.r11.u32 = ea;
	// bdnz 0x826b9eb4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826B9EB4;
loc_826B9EC0:
	// lbz r10,0(r28)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r28.u32 + 0);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// lwz r11,22228(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22228);
	// addi r9,r11,1
	ctx.r9.s64 = ctx.r11.s64 + 1;
	// stb r10,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r10.u8);
	// stw r9,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r9.u32);
	// b 0x826b9df0
	goto loc_826B9DF0;
loc_826B9EDC:
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x826b9f68
	if (!ctx.cr6.eq) goto loc_826B9F68;
loc_826B9EE4:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826B9EF0:
	// cmplwi cr6,r21,1
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 1, ctx.xer);
	// ble cr6,0x826b9f20
	if (!ctx.cr6.gt) goto loc_826B9F20;
	// lbz r9,-1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826b9f20
	if (!ctx.cr6.eq) goto loc_826B9F20;
	// lbz r9,-2(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + -2);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// bne cr6,0x826b9f20
	if (!ctx.cr6.eq) goto loc_826B9F20;
	// stb r24,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r24.u8);
	// stw r18,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r18.u32);
	// stb r24,22241(r30)
	REX_STORE_U8(ctx.r30.u32 + 22241, ctx.r24.u8);
	// b 0x826b9f44
	goto loc_826B9F44;
loc_826B9F20:
	// cmplwi cr6,r21,0
	ctx.cr6.compare<uint32_t>(ctx.r21.u32, 0, ctx.xer);
	// beq cr6,0x826b9f40
	if (ctx.cr6.eq) goto loc_826B9F40;
	// lbz r11,-1(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -1);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826b9f40
	if (!ctx.cr6.eq) goto loc_826B9F40;
	// stb r24,22240(r30)
	REX_STORE_U8(ctx.r30.u32 + 22240, ctx.r24.u8);
	// stw r22,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r22.u32);
	// b 0x826b9f44
	goto loc_826B9F44;
loc_826B9F40:
	// stw r24,22228(r30)
	REX_STORE_U32(ctx.r30.u32 + 22228, ctx.r24.u32);
loc_826B9F44:
	// lwz r11,22228(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 22228);
	// subf r21,r11,r21
	ctx.r21.u64 = ctx.r21.u64 - ctx.r11.u64;
loc_826B9F4C:
	// stw r23,0(r14)
	REX_STORE_U32(ctx.r14.u32 + 0, ctx.r23.u32);
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// stw r21,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r21.u32);
	// stw r10,0(r15)
	REX_STORE_U32(ctx.r15.u32 + 0, ctx.r10.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_826B9F64:
	// li r3,7
	ctx.r3.s64 = 7;
loc_826B9F68:
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826FC610) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x826FC618;
	__savegprlr_21(ctx, base);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r21,-32110
	ctx.r21.s64 = -2104360960;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// mr r22,r6
	ctx.r22.u64 = ctx.r6.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// lwz r11,-13808(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -13808);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// mr r26,r8
	ctx.r26.u64 = ctx.r8.u64;
	// mr r25,r9
	ctx.r25.u64 = ctx.r9.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826FC654;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,-13808(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + -13808);
	// addi r24,r30,8
	ctx.r24.s64 = ctx.r30.s64 + 8;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// addi r4,r1,116
	ctx.r4.s64 = ctx.r1.s64 + 116;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC674;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r31,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,-13808(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + -13808);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// add r29,r11,r30
	ctx.r29.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r5,r1,88
	ctx.r5.s64 = ctx.r1.s64 + 88;
	// addi r4,r1,120
	ctx.r4.s64 = ctx.r1.s64 + 120;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FC698;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,-13808(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + -13808);
	// addi r23,r29,8
	ctx.r23.s64 = ctx.r29.s64 + 8;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r1,92
	ctx.r5.s64 = ctx.r1.s64 + 92;
	// addi r4,r1,124
	ctx.r4.s64 = ctx.r1.s64 + 124;
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FC6B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,-13808(r21)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r21.u32 + -13808);
	// mr r6,r26
	ctx.r6.u64 = ctx.r26.u64;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826FC6D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-13808(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -13808);
	// mr r6,r25
	ctx.r6.u64 = ctx.r25.u64;
	// addi r5,r1,100
	ctx.r5.s64 = ctx.r1.s64 + 100;
	// addi r4,r1,132
	ctx.r4.s64 = ctx.r1.s64 + 132;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826FC6F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,84(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// srawi r8,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 31;
	// lwz r4,88(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r7,r10,1,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0x1;
	// subfc r6,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r6.u64 = ctx.r11.u64 - ctx.r10.u64;
	// adde r11,r7,r8
	temp.u8 = (ctx.r7.u32 + ctx.r8.u32 < ctx.r7.u32) | (ctx.r7.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r5,r9
	ctx.r3.u64 = REX_LOAD_U32(ctx.r5.u32 + ctx.r9.u32);
	// cmpw cr6,r3,r4
	ctx.cr6.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// bgt cr6,0x826fc724
	if (ctx.cr6.gt) goto loc_826FC724;
	// li r11,2
	ctx.r11.s64 = 2;
loc_826FC724:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,92(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// lwzx r7,r10,r8
	ctx.r7.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r8.u32);
	// cmpw cr6,r7,r9
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r9.s32, ctx.xer);
	// bgt cr6,0x826fc740
	if (ctx.cr6.gt) goto loc_826FC740;
	// li r11,3
	ctx.r11.s64 = 3;
loc_826FC740:
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// li r9,4
	ctx.r9.s64 = 4;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// lwzx r7,r8,r7
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_826FC760:
	// lwzx r10,r11,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r10,32
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 32, ctx.xer);
	// bge cr6,0x826fc784
	if (!ctx.cr6.lt) goto loc_826FC784;
	// cmpwi cr6,r7,64
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 64, ctx.xer);
	// blt cr6,0x826fc784
	if (ctx.cr6.lt) goto loc_826FC784;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lwzx r5,r8,r10
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// stwx r5,r11,r9
	REX_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r5.u32);
loc_826FC784:
	// cmpwi cr6,r7,16
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 16, ctx.xer);
	// bge cr6,0x826fc794
	if (!ctx.cr6.lt) goto loc_826FC794;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stwx r6,r11,r10
	REX_STORE_U32(ctx.r11.u32 + ctx.r10.u32, ctx.r6.u32);
loc_826FC794:
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// bdnz 0x826fc760
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826FC760;
	// lis r21,-32110
	ctx.r21.s64 = -2104360960;
	// lwz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// rlwinm r22,r22,1,0,30
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,-13804(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -13804);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826FC7C4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,-13804(r21)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r21.u32 + -13804);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x826FC7E0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r9,-13804(r21)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r21.u32 + -13804);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x826FC7FC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r8,-13804(r21)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r21.u32 + -13804);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// lwz r6,124(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// mr r3,r23
	ctx.r3.u64 = ctx.r23.u64;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x826FC818;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r7,-13804(r21)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r21.u32 + -13804);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// lwz r6,128(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 128);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r7
	ctx.ctr.u64 = ctx.r7.u64;
	// bctrl 
	ctx.lr = 0x826FC834;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,-13804(r21)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r21.u32 + -13804);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r6,132(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826FC850;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8270A438) {
	REX_FUNC_PROLOGUE();
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne cr6,0x8270a44c
	if (!ctx.cr6.eq) goto loc_8270A44C;
loc_8270A444:
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8270A44C:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r8.u32);
	// beq cr6,0x8270a444
	if (ctx.cr6.eq) goto loc_8270A444;
	// lwz r9,16(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmpw cr6,r5,r9
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x8270a444
	if (!ctx.cr6.lt) goto loc_8270A444;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x8270a48c
	if (!ctx.cr6.eq) goto loc_8270A48C;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// stw r9,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// bne cr6,0x8270a4e8
	if (!ctx.cr6.eq) goto loc_8270A4E8;
	// stw r8,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r8.u32);
	// b 0x8270a4e8
	goto loc_8270A4E8;
loc_8270A48C:
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x8270a4a8
	if (!ctx.cr6.eq) goto loc_8270A4A8;
	// cmpwi cr6,r9,1
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 1, ctx.xer);
	// bne cr6,0x8270a4a8
	if (!ctx.cr6.eq) goto loc_8270A4A8;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// b 0x8270a4e8
	goto loc_8270A4E8;
loc_8270A4A8:
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// bne cr6,0x8270a4b8
	if (!ctx.cr6.eq) goto loc_8270A4B8;
	// addi r10,r9,-1
	ctx.r10.s64 = ctx.r9.s64 + -1;
loc_8270A4B8:
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble 0x8270a4d0
	if (!ctx.cr0.gt) goto loc_8270A4D0;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8270A4C8:
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// bdnz 0x8270a4c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8270A4C8;
loc_8270A4D0:
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmpwi cr6,r5,-1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, -1, ctx.xer);
	// lwz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stw r8,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r8.u32);
	// bne cr6,0x8270a4e8
	if (!ctx.cr6.eq) goto loc_8270A4E8;
	// stw r9,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
loc_8270A4E8:
	// lwz r9,4(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,0(r4)
	REX_STORE_U32(ctx.r4.u32 + 0, ctx.r9.u32);
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r8,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r8.u32);
	// lwz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
	// bne cr6,0x8270a50c
	if (!ctx.cr6.eq) goto loc_8270A50C;
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
loc_8270A50C:
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82710810) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82710818;
	__savegprlr_14(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r9,0(r4)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r8,15504(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 15504);
	// li r21,0
	ctx.r21.s64 = 0;
	// lwz r26,84(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 84);
	// mr r23,r5
	ctx.r23.u64 = ctx.r5.u64;
	// cmpwi cr6,r8,6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 6, ctx.xer);
	// mr r10,r7
	ctx.r10.u64 = ctx.r7.u64;
	// lwz r3,12(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// mr r22,r21
	ctx.r22.u64 = ctx.r21.u64;
	// lwz r8,16(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 16);
	// mr r25,r21
	ctx.r25.u64 = ctx.r21.u64;
	// lwz r31,20(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + 20);
	// mr r14,r21
	ctx.r14.u64 = ctx.r21.u64;
	// lwz r30,24(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 24);
	// lwz r28,4(r9)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r11,8(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r20,0(r9)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r19,28(r9)
	ctx.r19.u64 = REX_LOAD_U32(ctx.r9.u32 + 28);
	// addi r15,r11,1
	ctx.r15.s64 = ctx.r11.s64 + 1;
	// lwz r18,32(r9)
	ctx.r18.u64 = REX_LOAD_U32(ctx.r9.u32 + 32);
	// lwz r4,12(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// ld r6,0(r26)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// lwz r7,8(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// stw r8,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r8.u32);
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// stw r30,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r30.u32);
	// stw r28,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r28.u32);
	// blt cr6,0x827108b0
	if (ctx.cr6.lt) goto loc_827108B0;
	// lwz r9,12(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r17,0(r10)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r16,4(r10)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// stw r9,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r9.u32);
	// b 0x827108c4
	goto loc_827108C4;
loc_827108B0:
	// lwz r10,308(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 308);
	// lwz r11,304(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 304);
	// lwz r17,312(r27)
	ctx.r17.u64 = REX_LOAD_U32(ctx.r27.u32 + 312);
	// lwz r16,316(r27)
	ctx.r16.u64 = REX_LOAD_U32(ctx.r27.u32 + 316);
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
loc_827108C4:
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// lwz r11,1760(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// dcbz r0,r11
	ea = (ctx.r11.u32) & ~31;
	memset((void*)REX_RAW_ADDR(ea), 0, 32);
	// li r10,128
	ctx.r10.s64 = 128;
	// lwz r9,1760(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// dcbz r10,r9
	ea = (ctx.r10.u32 + ctx.r9.u32) & ~31;
	memset((void*)REX_RAW_ADDR(ea), 0, 32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r24,r11,32768
	ctx.r24.u64 = ctx.r11.u64 | 32768;
	// b 0x827108ec
	goto loc_827108EC;
loc_827108E8:
	// lwz r28,88(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
loc_827108EC:
	// rldicl r11,r6,10,54
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u64, 10) & 0x3FF;
	// lwz r10,0(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// extsh r31,r8
	ctx.r31.s64 = ctx.r8.s16;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x82710970
	if (ctx.cr6.lt) goto loc_82710970;
	// clrlwi r11,r31,28
	ctx.r11.u64 = ctx.r31.u32 & 0xF;
	// clrldi r10,r31,60
	ctx.r10.u64 = ctx.r31.u64 & 0xF;
	// subf. r7,r11,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// sld r6,r6,r10
	ctx.r6.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r6.u64 << (ctx.r10.u8 & 0x7F));
	// bge 0x82710968
	if (!ctx.cr0.lt) goto loc_82710968;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82710950
	if (!ctx.cr6.lt) goto loc_82710950;
	// ld r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// addi r10,r7,16
	ctx.r10.s64 = ctx.r7.s64 + 16;
	// addi r7,r7,48
	ctx.r7.s64 = ctx.r7.s64 + 48;
	// rldicr r9,r11,0,47
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFFFFFF0000;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r4,r4,6
	ctx.r4.s64 = ctx.r4.s64 + 6;
	// srd r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// srawi r31,r31,4
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 4;
	// b 0x82710a48
	goto loc_82710A48;
loc_82710950:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82710728
	ctx.lr = 0x82710958;
	sub_82710728(ctx, base);
	// lwz r7,8(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r4,12(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
loc_82710968:
	// srawi r31,r31,4
	ctx.xer.ca = (ctx.r31.s32 < 0) & ((ctx.r31.u32 & 0xF) != 0);
	ctx.r31.s64 = ctx.r31.s32 >> 4;
	// b 0x82710a48
	goto loc_82710A48;
loc_82710970:
	// addic. r7,r7,-10
	ctx.xer.ca = ctx.r7.u32 > 9;
	ctx.r7.s64 = ctx.r7.s64 + -10;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// rldicr r6,r6,10,53
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u64, 10) & 0xFFFFFFFFFFFFFC00;
	// bge 0x827109c4
	if (!ctx.cr0.lt) goto loc_827109C4;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x827109ac
	if (!ctx.cr6.lt) goto loc_827109AC;
	// ld r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// addi r10,r7,16
	ctx.r10.s64 = ctx.r7.s64 + 16;
	// addi r7,r7,48
	ctx.r7.s64 = ctx.r7.s64 + 48;
	// rldicr r9,r11,0,47
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFFFFFF0000;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r4,r4,6
	ctx.r4.s64 = ctx.r4.s64 + 6;
	// srd r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// b 0x827109c4
	goto loc_827109C4;
loc_827109AC:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82710728
	ctx.lr = 0x827109B4;
	sub_82710728(ctx, base);
	// lwz r7,8(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r4,12(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
loc_827109C4:
	// cmpdi cr6,r6,0
	ctx.cr6.compare<int64_t>(ctx.r6.s64, 0, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x827109d4
	if (ctx.cr6.lt) goto loc_827109D4;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
loc_827109D4:
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// add r31,r11,r31
	ctx.r31.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rldicr r6,r6,1,62
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// bge 0x82710a2c
	if (!ctx.cr0.lt) goto loc_82710A2C;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82710a14
	if (!ctx.cr6.lt) goto loc_82710A14;
	// ld r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// addi r10,r7,16
	ctx.r10.s64 = ctx.r7.s64 + 16;
	// addi r7,r7,48
	ctx.r7.s64 = ctx.r7.s64 + 48;
	// rldicr r9,r11,0,47
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFFFFFF0000;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r4,r4,6
	ctx.r4.s64 = ctx.r4.s64 + 6;
	// srd r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// b 0x82710a2c
	goto loc_82710A2C;
loc_82710A14:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82710728
	ctx.lr = 0x82710A1C;
	sub_82710728(ctx, base);
	// lwz r7,8(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r4,12(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
loc_82710A2C:
	// add r11,r31,r24
	ctx.r11.u64 = ctx.r31.u64 + ctx.r24.u64;
	// lwz r10,0(r20)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r10
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r10.u32);
	// extsh r31,r8
	ctx.r31.s64 = ctx.r8.s16;
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt cr6,0x827109c4
	if (ctx.cr6.lt) goto loc_827109C4;
loc_82710A48:
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// clrlwi r11,r31,24
	ctx.r11.u64 = ctx.r31.u32 & 0xFF;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82711430
	if (!ctx.cr6.eq) goto loc_82711430;
	// clrlwi r30,r11,24
	ctx.r30.u64 = ctx.r11.u32 & 0xFF;
	// cmpw cr6,r30,r28
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x82710b28
	if (ctx.cr6.eq) goto loc_82710B28;
	// lbzx r11,r30,r18
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r18.u32);
	// lbzx r10,r30,r19
	ctx.r10.u64 = REX_LOAD_U8(ctx.r30.u32 + ctx.r19.u32);
	// add r31,r11,r25
	ctx.r31.u64 = ctx.r11.u64 + ctx.r25.u64;
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// cmplwi cr6,r31,64
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 64, ctx.xer);
	// bge cr6,0x82711430
	if (!ctx.cr6.lt) goto loc_82711430;
	// lbzx r10,r31,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r23.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// rlwinm r9,r10,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r14,r8,r14
	ctx.r14.u64 = ctx.r8.u64 | ctx.r14.u64;
	// bne cr6,0x82710a9c
	if (!ctx.cr6.eq) goto loc_82710A9C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// b 0x82710aa4
	goto loc_82710AA4;
loc_82710A9C:
	// mullw r11,r11,r17
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r17.s32);
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
loc_82710AA4:
	// sradi r10,r6,63
	ctx.xer.ca = (ctx.r6.s64 < 0) & ((ctx.r6.u64 & 0x7FFFFFFFFFFFFFFF) != 0);
	ctx.r10.s64 = ctx.r6.s64 >> 63;
	// lbzx r9,r31,r23
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r23.u32);
	// lwz r8,1760(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// addic. r7,r7,-1
	ctx.xer.ca = ctx.r7.u32 > 0;
	ctx.r7.s64 = ctx.r7.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// extsw r3,r10
	ctx.r3.s64 = ctx.r10.s32;
	// rotlwi r10,r9,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// xor r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// rldicr r6,r6,1,62
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// subf r3,r3,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r3.u64;
	// stwx r3,r10,r8
	REX_STORE_U32(ctx.r10.u32 + ctx.r8.u32, ctx.r3.u32);
	// bge 0x82710b18
	if (!ctx.cr0.lt) goto loc_82710B18;
	// addi r11,r5,-4
	ctx.r11.s64 = ctx.r5.s64 + -4;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82710b00
	if (!ctx.cr6.lt) goto loc_82710B00;
	// ld r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r4.u32 + 0);
	// addi r10,r7,16
	ctx.r10.s64 = ctx.r7.s64 + 16;
	// addi r7,r7,48
	ctx.r7.s64 = ctx.r7.s64 + 48;
	// rldicr r9,r11,0,47
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFFFFFF0000;
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// addi r4,r4,6
	ctx.r4.s64 = ctx.r4.s64 + 6;
	// srd r11,r9,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r9.u64 >> (ctx.r8.u8 & 0x7F));
	// add r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 + ctx.r6.u64;
	// b 0x82710b18
	goto loc_82710B18;
loc_82710B00:
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82710728
	ctx.lr = 0x82710B08;
	sub_82710728(ctx, base);
	// lwz r7,8(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// lwz r4,12(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
loc_82710B18:
	// addi r25,r31,1
	ctx.r25.s64 = ctx.r31.s64 + 1;
	// cmplw cr6,r30,r15
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r15.u32, ctx.xer);
	// blt cr6,0x827108ec
	if (ctx.cr6.lt) goto loc_827108EC;
	// b 0x82711424
	goto loc_82711424;
loc_82710B28:
	// std r6,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r6.u64);
	// stw r4,12(r26)
	REX_STORE_U32(ctx.r26.u32 + 12, ctx.r4.u32);
	// stw r5,16(r26)
	REX_STORE_U32(ctx.r26.u32 + 16, ctx.r5.u32);
	// stw r7,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r7.u32);
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// rldicr r9,r10,1,62
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r11.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r9,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r9.u64);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82710b60
	if (!ctx.cr0.lt) goto loc_82710B60;
	// bl 0x826c8b78
	ctx.lr = 0x82710B60;
	sub_826C8B78(ctx, base);
loc_82710B60:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82710d18
	if (ctx.cr6.eq) goto loc_82710D18;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82711440
	if (!ctx.cr6.eq) goto loc_82711440;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r20)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// rldicl r10,r11,10,54
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 10) & 0x3FF;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82710c58
	if (ctx.cr6.lt) goto loc_82710C58;
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
	// bge cr6,0x82710c50
	if (!ctx.cr6.lt) goto loc_82710C50;
loc_82710BB8:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82710be4
	if (ctx.cr6.lt) goto loc_82710BE4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x82710BD4;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82710bb8
	if (ctx.cr6.eq) goto loc_82710BB8;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82710c94
	goto loc_82710C94;
loc_82710BE4:
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
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
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82710C50:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82710c94
	goto loc_82710C94;
loc_82710C58:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x82710C64;
	sub_826C8C48(ctx, base);
loc_82710C64:
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
	ctx.lr = 0x82710C7C;
	sub_826C8C48(ctx, base);
	// add r10,r30,r24
	ctx.r10.u64 = ctx.r30.u64 + ctx.r24.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82710c64
	if (ctx.cr6.lt) goto loc_82710C64;
loc_82710C94:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82711440
	if (!ctx.cr6.eq) goto loc_82711440;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x82711440
	if (ctx.cr6.eq) goto loc_82711440;
	// lbzx r10,r11,r19
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r19.u32);
	// cmplw cr6,r11,r15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r15.u32, ctx.xer);
	// lbzx r28,r11,r18
	ctx.r28.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r18.u32);
	// extsb r11,r10
	ctx.r11.s64 = ctx.r10.s8;
	// blt cr6,0x82710cd4
	if (ctx.cr6.lt) goto loc_82710CD4;
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// li r22,1
	ctx.r22.s64 = 1;
	// b 0x82710cd8
	goto loc_82710CD8;
loc_82710CD4:
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
loc_82710CD8:
	// lbzx r9,r28,r10
	ctx.r9.u64 = REX_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// extsb r10,r9
	ctx.r10.s64 = ctx.r9.s8;
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// add r31,r10,r11
	ctx.r31.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// bge 0x82710d08
	if (!ctx.cr0.lt) goto loc_82710D08;
	// bl 0x826c8b78
	ctx.lr = 0x82710D08;
	sub_826C8B78(ctx, base);
loc_82710D08:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8271136c
	if (ctx.cr6.eq) goto loc_8271136C;
	// neg r31,r31
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r31.u64);
	// b 0x8271136c
	goto loc_8271136C;
loc_82710D18:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
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
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82710d40
	if (!ctx.cr0.lt) goto loc_82710D40;
	// bl 0x826c8b78
	ctx.lr = 0x82710D40;
	sub_826C8B78(ctx, base);
loc_82710D40:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82710efc
	if (ctx.cr6.eq) goto loc_82710EFC;
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82711440
	if (!ctx.cr6.eq) goto loc_82711440;
	// ld r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r20)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// rldicl r10,r11,10,54
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 10) & 0x3FF;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82710e38
	if (ctx.cr6.lt) goto loc_82710E38;
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
	// bge cr6,0x82710e30
	if (!ctx.cr6.lt) goto loc_82710E30;
loc_82710D98:
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82710dc4
	if (ctx.cr6.lt) goto loc_82710DC4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8ab8
	ctx.lr = 0x82710DB4;
	sub_826C8AB8(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82710d98
	if (ctx.cr6.eq) goto loc_82710D98;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82710e74
	goto loc_82710E74;
loc_82710DC4:
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
	// lbz r6,4(r11)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r11.u32 + 3);
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
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	REX_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82710E30:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82710e74
	goto loc_82710E74;
loc_82710E38:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8c48
	ctx.lr = 0x82710E44;
	sub_826C8C48(ctx, base);
loc_82710E44:
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
	ctx.lr = 0x82710E5C;
	sub_826C8C48(ctx, base);
	// add r10,r30,r24
	ctx.r10.u64 = ctx.r30.u64 + ctx.r24.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = REX_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82710e44
	if (ctx.cr6.lt) goto loc_82710E44;
loc_82710E74:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// clrlwi r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82711440
	if (!ctx.cr6.eq) goto loc_82711440;
	// clrlwi r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	// cmpw cr6,r11,r28
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r28.s32, ctx.xer);
	// beq cr6,0x82711440
	if (ctx.cr6.eq) goto loc_82711440;
	// lbzx r10,r11,r19
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r19.u32);
	// cmplw cr6,r11,r15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r15.u32, ctx.xer);
	// lbzx r11,r11,r18
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r18.u32);
	// lwz r9,1932(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 1932);
	// extsb r31,r10
	ctx.r31.s64 = ctx.r10.s8;
	// blt cr6,0x82710eb8
	if (ctx.cr6.lt) goto loc_82710EB8;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// li r22,1
	ctx.r22.s64 = 1;
	// b 0x82710ebc
	goto loc_82710EBC;
loc_82710EB8:
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_82710EBC:
	// lbzx r10,r31,r10
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r9,8(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// ld r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// bge 0x82710eec
	if (!ctx.cr0.lt) goto loc_82710EEC;
	// bl 0x826c8b78
	ctx.lr = 0x82710EEC;
	sub_826C8B78(ctx, base);
loc_82710EEC:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8271136c
	if (ctx.cr6.eq) goto loc_8271136C;
	// neg r31,r31
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r31.u64);
	// b 0x8271136c
	goto loc_8271136C;
loc_82710EFC:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82711440
	if (!ctx.cr6.eq) goto loc_82711440;
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
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82710f30
	if (!ctx.cr0.lt) goto loc_82710F30;
	// bl 0x826c8b78
	ctx.lr = 0x82710F30;
	sub_826C8B78(ctx, base);
loc_82710F30:
	// lwz r11,15504(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 15504);
	// mr r22,r31
	ctx.r22.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// blt cr6,0x82711204
	if (ctx.cr6.lt) goto loc_82711204;
	// lwz r11,1968(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 1968);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82710f58
	if (ctx.cr6.eq) goto loc_82710F58;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x827058f8
	ctx.lr = 0x82710F54;
	sub_827058F8(ctx, base);
	// stw r21,1968(r27)
	REX_STORE_U32(ctx.r27.u32 + 1968, ctx.r21.u32);
loc_82710F58:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// lwz r30,1976(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 1976);
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// ble cr6,0x82710f7c
	if (!ctx.cr6.gt) goto loc_82710F7C;
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// b 0x8271102c
	goto loc_8271102C;
loc_82710F7C:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82710f8c
	if (!ctx.cr6.eq) goto loc_82710F8C;
	// mr r28,r21
	ctx.r28.u64 = ctx.r21.u64;
	// b 0x8271102c
	goto loc_8271102C;
loc_82710F8C:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82710fec
	if (!ctx.cr6.gt) goto loc_82710FEC;
loc_82710F94:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82710fec
	if (ctx.cr6.eq) goto loc_82710FEC;
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
	// bge 0x82710fdc
	if (!ctx.cr0.lt) goto loc_82710FDC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82710FDC;
	sub_826C8B78(ctx, base);
loc_82710FDC:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82710f94
	if (ctx.cr6.gt) goto loc_82710F94;
loc_82710FEC:
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
	// bge 0x82711028
	if (!ctx.cr0.lt) goto loc_82711028;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82711028;
	sub_826C8B78(ctx, base);
loc_82711028:
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
loc_8271102C:
	// lwz r3,84(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
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
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	REX_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	REX_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82711054
	if (!ctx.cr0.lt) goto loc_82711054;
	// bl 0x826c8b78
	ctx.lr = 0x82711054;
	sub_826C8B78(ctx, base);
loc_82711054:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// lwz r30,1972(r27)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r27.u32 + 1972);
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x82711140
	if (ctx.cr6.eq) goto loc_82711140;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x82711084
	if (!ctx.cr6.gt) goto loc_82711084;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// neg r31,r21
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r21.u64);
	// b 0x8271136c
	goto loc_8271136C;
loc_82711084:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82711098
	if (!ctx.cr6.eq) goto loc_82711098;
	// mr r11,r21
	ctx.r11.u64 = ctx.r21.u64;
	// neg r31,r21
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r21.u64);
	// b 0x8271136c
	goto loc_8271136C;
loc_82711098:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827110f8
	if (!ctx.cr6.gt) goto loc_827110F8;
loc_827110A0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827110f8
	if (ctx.cr6.eq) goto loc_827110F8;
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
	// bge 0x827110e8
	if (!ctx.cr0.lt) goto loc_827110E8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x827110E8;
	sub_826C8B78(ctx, base);
loc_827110E8:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827110a0
	if (ctx.cr6.gt) goto loc_827110A0;
loc_827110F8:
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
	// bge 0x82711134
	if (!ctx.cr0.lt) goto loc_82711134;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82711134;
	sub_826C8B78(ctx, base);
loc_82711134:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// neg r31,r30
	ctx.r31.s64 = static_cast<int64_t>(-ctx.r30.u64);
	// b 0x8271136c
	goto loc_8271136C;
loc_82711140:
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x82711150
	if (!ctx.cr6.gt) goto loc_82711150;
	// mr r31,r21
	ctx.r31.u64 = ctx.r21.u64;
	// b 0x8271136c
	goto loc_8271136C;
loc_82711150:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82711160
	if (!ctx.cr6.eq) goto loc_82711160;
	// mr r31,r21
	ctx.r31.u64 = ctx.r21.u64;
	// b 0x8271136c
	goto loc_8271136C;
loc_82711160:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827111c0
	if (!ctx.cr6.gt) goto loc_827111C0;
loc_82711168:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827111c0
	if (ctx.cr6.eq) goto loc_827111C0;
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
	// bge 0x827111b0
	if (!ctx.cr0.lt) goto loc_827111B0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x827111B0;
	sub_826C8B78(ctx, base);
loc_827111B0:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82711168
	if (ctx.cr6.gt) goto loc_82711168;
loc_827111C0:
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
	// bge 0x827111fc
	if (!ctx.cr0.lt) goto loc_827111FC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x827111FC;
	sub_826C8B78(ctx, base);
loc_827111FC:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// b 0x8271136c
	goto loc_8271136C;
loc_82711204:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// li r30,6
	ctx.r30.s64 = 6;
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,6
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 6, ctx.xer);
	// bge cr6,0x82711278
	if (!ctx.cr6.lt) goto loc_82711278;
loc_82711220:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82711278
	if (ctx.cr6.eq) goto loc_82711278;
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
	// bge 0x82711268
	if (!ctx.cr0.lt) goto loc_82711268;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82711268;
	sub_826C8B78(ctx, base);
loc_82711268:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82711220
	if (ctx.cr6.gt) goto loc_82711220;
loc_82711278:
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
	// bge 0x827112b4
	if (!ctx.cr0.lt) goto loc_827112B4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x827112B4;
	sub_826C8B78(ctx, base);
loc_827112B4:
	// lwz r31,84(r27)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r27.u32 + 84);
	// mr r28,r30
	ctx.r28.u64 = ctx.r30.u64;
	// li r30,8
	ctx.r30.s64 = 8;
	// mr r29,r21
	ctx.r29.u64 = ctx.r21.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// bge cr6,0x8271132c
	if (!ctx.cr6.lt) goto loc_8271132C;
loc_827112D4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8271132c
	if (ctx.cr6.eq) goto loc_8271132C;
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
	// bge 0x8271131c
	if (!ctx.cr0.lt) goto loc_8271131C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x8271131C;
	sub_826C8B78(ctx, base);
loc_8271131C:
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x827112d4
	if (ctx.cr6.gt) goto loc_827112D4;
loc_8271132C:
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
	// bge 0x82711368
	if (!ctx.cr0.lt) goto loc_82711368;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x826c8b78
	ctx.lr = 0x82711368;
	sub_826C8B78(ctx, base);
loc_82711368:
	// extsb r31,r30
	ctx.r31.s64 = ctx.r30.s8;
loc_8271136C:
	// lwz r10,20(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// add r11,r28,r25
	ctx.r11.u64 = ctx.r28.u64 + ctx.r25.u64;
	// lwz r4,12(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 12);
	// lwz r5,16(r26)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r26.u32 + 16);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ld r6,0(r26)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r26.u32 + 0);
	// lwz r7,8(r26)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r26.u32 + 8);
	// bne cr6,0x82711430
	if (!ctx.cr6.eq) goto loc_82711430;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bge cr6,0x82711430
	if (!ctx.cr6.lt) goto loc_82711430;
	// lbzx r10,r11,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r23.u32);
	// cmpwi cr6,r31,1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 1, ctx.xer);
	// rlwinm r9,r10,29,3,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 29) & 0x1FFFFFFF;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r14,r8,r14
	ctx.r14.u64 = ctx.r8.u64 | ctx.r14.u64;
	// bne cr6,0x827113c4
	if (!ctx.cr6.eq) goto loc_827113C4;
	// clrlwi r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	// lwz r9,1760(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// rotlwi r3,r10,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r8,r3,r9
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r8.u32);
	// b 0x82711418
	goto loc_82711418;
loc_827113C4:
	// cmpwi cr6,r31,-1
	ctx.cr6.compare<int32_t>(ctx.r31.s32, -1, ctx.xer);
	// bne cr6,0x827113e4
	if (!ctx.cr6.eq) goto loc_827113E4;
	// lbzx r10,r11,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r23.u32);
	// lwz r9,1760(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// lwz r8,84(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rotlwi r3,r10,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// stwx r8,r3,r9
	REX_STORE_U32(ctx.r3.u32 + ctx.r9.u32, ctx.r8.u32);
	// b 0x82711418
	goto loc_82711418;
loc_827113E4:
	// lwz r8,1760(r27)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r27.u32 + 1760);
	// cmpwi cr6,r31,0
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// ble cr6,0x82711404
	if (!ctx.cr6.gt) goto loc_82711404;
	// lbzx r9,r11,r23
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r23.u32);
	// mullw r10,r31,r17
	ctx.r10.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r17.s32);
	// rotlwi r3,r9,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r9.u32, 2);
	// add r10,r10,r16
	ctx.r10.u64 = ctx.r10.u64 + ctx.r16.u64;
	// b 0x82711414
	goto loc_82711414;
loc_82711404:
	// lbzx r10,r11,r23
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + ctx.r23.u32);
	// mullw r9,r31,r17
	ctx.r9.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r17.s32);
	// rotlwi r3,r10,2
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 2);
	// subf r10,r16,r9
	ctx.r10.u64 = ctx.r9.u64 - ctx.r16.u64;
loc_82711414:
	// stwx r10,r3,r8
	REX_STORE_U32(ctx.r3.u32 + ctx.r8.u32, ctx.r10.u32);
loc_82711418:
	// addi r25,r11,1
	ctx.r25.s64 = ctx.r11.s64 + 1;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x827108e8
	if (ctx.cr6.eq) goto loc_827108E8;
loc_82711424:
	// lwz r11,20(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8271144c
	if (ctx.cr6.eq) goto loc_8271144C;
loc_82711430:
	// stw r4,12(r26)
	REX_STORE_U32(ctx.r26.u32 + 12, ctx.r4.u32);
	// stw r5,16(r26)
	REX_STORE_U32(ctx.r26.u32 + 16, ctx.r5.u32);
	// std r6,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r6.u64);
	// stw r7,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r7.u32);
loc_82711440:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
loc_8271144C:
	// stw r14,1944(r27)
	REX_STORE_U32(ctx.r27.u32 + 1944, ctx.r14.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r4,12(r26)
	REX_STORE_U32(ctx.r26.u32 + 12, ctx.r4.u32);
	// stw r5,16(r26)
	REX_STORE_U32(ctx.r26.u32 + 16, ctx.r5.u32);
	// std r6,0(r26)
	REX_STORE_U64(ctx.r26.u32 + 0, ctx.r6.u64);
	// stw r7,8(r26)
	REX_STORE_U32(ctx.r26.u32 + 8, ctx.r7.u32);
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82742538) {
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
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// addi r30,r11,-13536
	ctx.r30.s64 = ctx.r11.s64 + -13536;
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_82742558:
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82742570
	if (ctx.cr6.eq) goto loc_82742570;
	// bl 0x8273c660
	ctx.lr = 0x82742568;
	sub_8273C660(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82742570:
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// addi r11,r30,256
	ctx.r11.s64 = ctx.r30.s64 + 256;
	// cmpw cr6,r31,r11
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82742558
	if (ctx.cr6.lt) goto loc_82742558;
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

DEFINE_REX_FUNC(sub_82745800) {
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
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82745868
	if (ctx.cr6.lt) goto loc_82745868;
	// lis r11,-32110
	ctx.r11.s64 = -2104360960;
	// lwz r11,-13564(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13564);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// bge cr6,0x82745868
	if (!ctx.cr6.lt) goto loc_82745868;
	// srawi r11,r3,5
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1F) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 5;
	// lis r10,-32110
	ctx.r10.s64 = -2104360960;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,-13536
	ctx.r10.s64 = ctx.r10.s64 + -13536;
	// clrlwi r11,r3,27
	ctx.r11.u64 = ctx.r3.u32 & 0x1F;
	// mulli r11,r11,72
	ctx.r11.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(72));
	// lwzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lbz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 4);
	// clrlwi. r10,r10,31
	ctx.r10.u64 = ctx.r10.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82745868
	if (ctx.cr0.eq) goto loc_82745868;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// beq cr6,0x82745868
	if (ctx.cr6.eq) goto loc_82745868;
	// li r10,-1
	ctx.r10.s64 = -1;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82745884
	goto loc_82745884;
loc_82745868:
	// bl 0x8273dc40
	ctx.lr = 0x8274586C;
	sub_8273DC40(ctx, base);
	// li r11,9
	ctx.r11.s64 = 9;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x8273dc78
	ctx.lr = 0x82745878;
	sub_8273DC78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r10,0
	ctx.r10.s64 = 0;
	// li r3,-1
	ctx.r3.s64 = -1;
loc_82745884:
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8274AF50) {
	REX_FUNC_PROLOGUE();
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
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// mullw r8,r6,r8
	ctx.r8.s64 = int64_t(ctx.r6.s32) * int64_t(ctx.r8.s32);
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mullw r5,r4,r10
	ctx.r5.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r10.s32);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// bl 0x8274acd0
	ctx.lr = 0x8274AF90;
	sub_8274ACD0(ctx, base);
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

DEFINE_REX_FUNC(sub_8274C190) {
	REX_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplwi cr6,r11,8
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 8, ctx.xer);
	// beq cr6,0x8274c2c0
	if (ctx.cr6.eq) goto loc_8274C2C0;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c23c
	if (ctx.cr6.eq) goto loc_8274C23C;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// beq cr6,0x8274c1b8
	if (ctx.cr6.eq) goto loc_8274C1B8;
	// twi 31,r0,22
	ppc_trap(ctx, base, 22);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
loc_8274C1B8:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8274c230
	if (!ctx.cr6.eq) goto loc_8274C230;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,44(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c224
	if (ctx.cr6.eq) goto loc_8274C224;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c224
	if (ctx.cr6.eq) goto loc_8274C224;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c224
	if (ctx.cr6.eq) goto loc_8274C224;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,56(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x8274c230
	if (!ctx.cr6.eq) goto loc_8274C230;
loc_8274C224:
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// addi r3,r11,-16832
	ctx.r3.s64 = ctx.r11.s64 + -16832;
	// blr 
	return;
loc_8274C230:
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// addi r3,r11,-16960
	ctx.r3.s64 = ctx.r11.s64 + -16960;
	// blr 
	return;
loc_8274C23C:
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x8274c2b4
	if (!ctx.cr6.eq) goto loc_8274C2B4;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,44(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 44);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c2a8
	if (ctx.cr6.eq) goto loc_8274C2A8;
	// lwz r11,32(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 32);
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c2a8
	if (ctx.cr6.eq) goto loc_8274C2A8;
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// lwz r10,52(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 52);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x8274c2a8
	if (ctx.cr6.eq) goto loc_8274C2A8;
	// lwz r11,40(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 40);
	// lwz r10,56(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// srw r11,r11,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x8274c2b4
	if (!ctx.cr6.eq) goto loc_8274C2B4;
loc_8274C2A8:
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// addi r3,r11,-17112
	ctx.r3.s64 = ctx.r11.s64 + -17112;
	// blr 
	return;
loc_8274C2B4:
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// addi r3,r11,-17240
	ctx.r3.s64 = ctx.r11.s64 + -17240;
	// blr 
	return;
loc_8274C2C0:
	// lis r11,-32139
	ctx.r11.s64 = -2106261504;
	// addi r3,r11,-17312
	ctx.r3.s64 = ctx.r11.s64 + -17312;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8275BE88) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x8275BE90;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275beb8
	if (ctx.cr6.eq) goto loc_8275BEB8;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// bl 0x82755cf8
	ctx.lr = 0x8275BEB4;
	sub_82755CF8(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
loc_8275BEB8:
	// lwz r11,96(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 96);
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// mullw r11,r11,r29
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r29.s32);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r8,104(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// mullw r9,r9,r27
	ctx.r9.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r27.s32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// add r29,r11,r10
	ctx.r29.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ble cr6,0x8275bf18
	if (!ctx.cr6.gt) goto loc_8275BF18;
	// mr r28,r6
	ctx.r28.u64 = ctx.r6.u64;
loc_8275BEE8:
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,4
	ctx.r6.s64 = 4;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827548b8
	ctx.lr = 0x8275BF00;
	sub_827548B8(ctx, base);
	// lwz r11,104(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 104);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// addi r29,r29,2
	ctx.r29.s64 = ctx.r29.s64 + 2;
	// addi r28,r28,16
	ctx.r28.s64 = ctx.r28.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x8275bee8
	if (ctx.cr6.lt) goto loc_8275BEE8;
loc_8275BF18:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8275DAE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8275DAF0;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
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
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8275dc2c
	if (!ctx.cr6.lt) goto loc_8275DC2C;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// addi r5,r11,-8
	ctx.r5.s64 = ctx.r11.s64 + -8;
	// addi r11,r10,-1
	ctx.r11.s64 = ctx.r10.s64 + -1;
	// li r10,-32768
	ctx.r10.s64 = -32768;
	// rlwinm r11,r11,29,3,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f0,-30484(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30484);
	ctx.f0.f64 = double(temp.f32);
loc_8275DB48:
	// ldu r11,8(r5)
	ea = 8 + ctx.r5.u32;
	ctx.r11.u64 = REX_LOAD_U64(ea);
	ctx.r5.u32 = ea;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// rldicl r7,r11,48,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u64, 48) & 0xFFFFFFFFFFFF;
	// extsh r4,r9
	ctx.r4.s64 = ctx.r9.s16;
	// rldicl r8,r11,16,48
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFF;
	// rldicl r30,r11,32,32
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF;
	// clrlwi r11,r7,16
	ctx.r11.u64 = ctx.r7.u32 & 0xFFFF;
	// subf r7,r10,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r10.u64;
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// extsh r31,r11
	ctx.r31.s64 = ctx.r11.s16;
	// cntlzw r7,r7
	ctx.r7.u64 = ctx.r7.u32 == 0 ? 32 : __builtin_clz(ctx.r7.u32);
	// subf r29,r10,r4
	ctx.r29.u64 = ctx.r4.u64 - ctx.r10.u64;
	// subf r31,r10,r31
	ctx.r31.u64 = ctx.r31.u64 - ctx.r10.u64;
	// rlwinm r4,r7,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// cntlzw r7,r29
	ctx.r7.u64 = ctx.r29.u32 == 0 ? 32 : __builtin_clz(ctx.r29.u32);
	// cntlzw r29,r31
	ctx.r29.u64 = ctx.r31.u32 == 0 ? 32 : __builtin_clz(ctx.r31.u32);
	// add r4,r4,r9
	ctx.r4.u64 = ctx.r4.u64 + ctx.r9.u64;
	// rlwinm r9,r29,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 27) & 0x1;
	// rlwinm r31,r7,27,31,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// clrlwi r7,r30,16
	ctx.r7.u64 = ctx.r30.u32 & 0xFFFF;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// add r8,r31,r8
	ctx.r8.u64 = ctx.r31.u64 + ctx.r8.u64;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// extsh r11,r7
	ctx.r11.s64 = ctx.r7.s16;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// lfd f11,96(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// extsh r8,r4
	ctx.r8.s64 = ctx.r4.s16;
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// rlwinm r30,r11,27,31,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// add r11,r30,r7
	ctx.r11.u64 = ctx.r30.u64 + ctx.r7.u64;
	// std r8,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r8.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// frsp f11,f11
	ctx.f11.f64 = double(float(ctx.f11.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// std r11,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r11.u64);
	// lfd f10,104(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f11,4(r6)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f10,8(r6)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f13,12(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz 0x8275db48
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8275DB48;
loc_8275DC2C:
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275dc48
	if (ctx.cr6.eq) goto loc_8275DC48;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82755c68
	ctx.lr = 0x8275DC48;
	sub_82755C68(ctx, base);
loc_8275DC48:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275dc64
	if (ctx.cr6.eq) goto loc_8275DC64;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82756030
	ctx.lr = 0x8275DC64;
	sub_82756030(ctx, base);
loc_8275DC64:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82765130) {
	REX_FUNC_PROLOGUE();
	// lwz r10,248(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 248);
	// addi r11,r3,248
	ctx.r11.s64 = ctx.r3.s64 + 248;
	// b 0x82765150
	goto loc_82765150;
loc_8276513C:
	// ld r8,-76(r10)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r10.u32 + -76);
	// addi r9,r10,-92
	ctx.r9.s64 = ctx.r10.s64 + -92;
	// cmpld cr6,r8,r4
	ctx.cr6.compare<uint64_t>(ctx.r8.u64, ctx.r4.u64, ctx.xer);
	// beq cr6,0x82765164
	if (ctx.cr6.eq) goto loc_82765164;
	// lwz r10,0(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
loc_82765150:
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82765170
	if (ctx.cr6.eq) goto loc_82765170;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x8276513c
	if (!ctx.cr0.eq) goto loc_8276513C;
	// b 0x82765170
	goto loc_82765170;
loc_82765164:
	// lwz r11,396(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 396);
	// rlwinm. r11,r11,0,4,4
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82765174
	if (!ctx.cr0.eq) goto loc_82765174;
loc_82765170:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82765174:
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82766D68) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82766D70;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r11,r4,95
	ctx.r11.s64 = ctx.r4.s64 + 95;
	// li r28,0
	ctx.r28.s64 = 0;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// lwzx r31,r11,r3
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r10,r11,0,2,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82766da0
	if (ctx.cr0.eq) goto loc_82766DA0;
	// li r30,1
	ctx.r30.s64 = 1;
loc_82766DA0:
	// rlwinm. r10,r11,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82766db0
	if (ctx.cr0.eq) goto loc_82766DB0;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r10,2
	ctx.r30.u64 = ctx.r10.u64 | 2;
loc_82766DB0:
	// rlwinm. r10,r11,0,6,6
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82766dc0
	if (ctx.cr0.eq) goto loc_82766DC0;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r10,4
	ctx.r30.u64 = ctx.r10.u64 | 4;
loc_82766DC0:
	// rlwinm r11,r11,0,10,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF3FFFFF;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// li r4,252
	ctx.r4.s64 = 252;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639a00
	ctx.lr = 0x82766DDC;
	sub_82639A00(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82766df0
	if (!ctx.cr0.eq) goto loc_82766DF0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82766e48
	if (!ctx.cr6.eq) goto loc_82766E48;
loc_82766DF0:
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,251
	ctx.r4.s64 = 251;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639a00
	ctx.lr = 0x82766E04;
	sub_82639A00(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82766e2c
	if (!ctx.cr0.eq) goto loc_82766E2C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82766e5c
	if (ctx.cr6.eq) goto loc_82766E5C;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// oris r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 4194304;
	// ori r30,r10,16
	ctx.r30.u64 = ctx.r10.u64 | 16;
	// b 0x82766e58
	goto loc_82766E58;
loc_82766E2C:
	// cmplwi cr6,r3,1245
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1245, ctx.xer);
	// bne cr6,0x82766e5c
	if (!ctx.cr6.eq) goto loc_82766E5C;
	// lwz r11,28(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82766e48
	if (ctx.cr6.eq) goto loc_82766E48;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82766e5c
	if (!ctx.cr6.eq) goto loc_82766E5C;
loc_82766E48:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// oris r11,r11,128
	ctx.r11.u64 = ctx.r11.u64 | 8388608;
	// ori r30,r10,8
	ctx.r30.u64 = ctx.r10.u64 | 8;
loc_82766E58:
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
loc_82766E5C:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,235
	ctx.r4.s64 = 235;
	// rlwinm r11,r11,0,12,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFFCFFFFF;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// bl 0x82639a00
	ctx.lr = 0x82766E7C;
	sub_82639A00(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82766e9c
	if (!ctx.cr0.eq) goto loc_82766E9C;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82766e9c
	if (ctx.cr6.eq) goto loc_82766E9C;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r10,32
	ctx.r30.u64 = ctx.r10.u64 | 32;
	// b 0x82766efc
	goto loc_82766EFC;
loc_82766E9C:
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,234
	ctx.r4.s64 = 234;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82639a00
	ctx.lr = 0x82766EB0;
	sub_82639A00(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82766ed8
	if (!ctx.cr0.eq) goto loc_82766ED8;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82766f08
	if (ctx.cr6.eq) goto loc_82766F08;
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// oris r11,r11,16
	ctx.r11.u64 = ctx.r11.u64 | 1048576;
	// ori r30,r10,64
	ctx.r30.u64 = ctx.r10.u64 | 64;
	// b 0x82766f04
	goto loc_82766F04;
loc_82766ED8:
	// cmplwi cr6,r3,1245
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1245, ctx.xer);
	// bne cr6,0x82766f08
	if (!ctx.cr6.eq) goto loc_82766F08;
	// lwz r11,28(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + 28);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82766ef4
	if (ctx.cr6.eq) goto loc_82766EF4;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x82766f08
	if (!ctx.cr6.eq) goto loc_82766F08;
loc_82766EF4:
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r10,8
	ctx.r30.u64 = ctx.r10.u64 | 8;
loc_82766EFC:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
loc_82766F04:
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
loc_82766F08:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// rlwinm. r10,r11,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82766f1c
	if (ctx.cr0.eq) goto loc_82766F1C;
	// clrlwi r10,r30,16
	ctx.r10.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r10,128
	ctx.r30.u64 = ctx.r10.u64 | 128;
loc_82766F1C:
	// rlwinm. r11,r11,0,27,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82766f2c
	if (ctx.cr0.eq) goto loc_82766F2C;
	// clrlwi r11,r30,16
	ctx.r11.u64 = ctx.r30.u32 & 0xFFFF;
	// ori r30,r11,256
	ctx.r30.u64 = ctx.r11.u64 | 256;
loc_82766F2C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82771948) {
	REX_FUNC_PROLOGUE();
	// b 0x827711d0
	sub_827711D0(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82771E90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	// mr r9,r10
	ctx.r9.u64 = ctx.r10.u64;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// bne cr6,0x82771eb0
	if (!ctx.cr6.eq) goto loc_82771EB0;
	// li r7,128
	ctx.r7.s64 = 128;
loc_82771EB0:
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// bl 0x82781058
	ctx.lr = 0x82771EC8;
	sub_82781058(ctx, base);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827726F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32761
	ctx.r11.s64 = -2147024896;
	// lwz r10,20(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// ori r11,r11,996
	ctx.r11.u64 = ctx.r11.u64 | 996;
	// cmpw cr6,r10,r11
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r11.s32, ctx.xer);
	// beq cr6,0x82772714
	if (ctx.cr6.eq) goto loc_82772714;
	// li r3,2
	ctx.r3.s64 = 2;
	// blr 
	return;
loc_82772714:
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// addic r10,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r10.s64 = ctx.r11.s64 + -1;
	// subfe r3,r10,r11
	temp.u8 = (~ctx.r10.u32 + ctx.r11.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r3.u64 = ~ctx.r10.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82773540) {
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
	// mr r3,r4
	ctx.r3.u64 = ctx.r4.u64;
	// li r5,15
	ctx.r5.s64 = 15;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8273a590
	ctx.lr = 0x8277356C;
	sub_8273A590(ctx, base);
	// addi r31,r31,344
	ctx.r31.s64 = ctx.r31.s64 + 344;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8273a560
	ctx.lr = 0x82773578;
	sub_8273A560(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,0
	ctx.r3.s64 = 0;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// li r8,15
	ctx.r8.s64 = 15;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r10,0
	ctx.r10.s64 = 0;
	// bl 0x8263a7b8
	ctx.lr = 0x8277359C;
	sub_8263A7B8(ctx, base);
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

DEFINE_REX_FUNC(sub_82775070) {
	REX_FUNC_PROLOGUE();
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,60(r3)
	REX_STORE_U32(ctx.r3.u32 + 60, ctx.r11.u32);
	// b 0x82775008
	sub_82775008(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827756E0) {
	REX_FUNC_PROLOGUE();
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r11,0(r5)
	REX_STORE_U32(ctx.r5.u32 + 0, ctx.r11.u32);
	// b 0x82775350
	sub_82775350(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82775A08) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82775A10;
	__savegprlr_29(ctx, base);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addi r29,r3,32
	ctx.r29.s64 = ctx.r3.s64 + 32;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x827841e0
	ctx.lr = 0x82775A2C;
	sub_827841E0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// blt 0x82775aa4
	if (ctx.cr0.lt) goto loc_82775AA4;
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r10,13
	ctx.r10.s64 = 13;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// stw r31,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r31.u32);
	// stw r31,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r31.u32);
	// stb r31,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r31.u8);
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// bl 0x82736440
	ctx.lr = 0x82775A5C;
	sub_82736440(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82775a70
	if (ctx.cr0.eq) goto loc_82775A70;
	// bl 0x827758b8
	ctx.lr = 0x82775A68;
	sub_827758B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// b 0x82775a90
	goto loc_82775A90;
loc_82775A70:
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r3,514
	ctx.r3.s64 = 514;
	// bl 0x82736c70
	ctx.lr = 0x82775A7C;
	sub_82736C70(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x82775a9c
	if (ctx.cr0.eq) goto loc_82775A9C;
	// bl 0x827758b8
	ctx.lr = 0x82775A88;
	sub_827758B8(ctx, base);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82736450
	ctx.lr = 0x82775A90;
	sub_82736450(ctx, base);
loc_82775A90:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82784340
	ctx.lr = 0x82775A98;
	sub_82784340(ctx, base);
	// b 0x82775aa4
	goto loc_82775AA4;
loc_82775A9C:
	// bl 0x82748820
	ctx.lr = 0x82775AA0;
	sub_82748820(ctx, base);
	// stw r3,44(r30)
	REX_STORE_U32(ctx.r30.u32 + 44, ctx.r3.u32);
loc_82775AA4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82779BB8) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82779BC0;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,56(r4)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r4.u32 + 56);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r27,r5
	ctx.r27.u64 = ctx.r5.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x82779e8c
	if (ctx.cr6.eq) goto loc_82779E8C;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x82779e18
	if (ctx.cr6.eq) goto loc_82779E18;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// lwz r11,52(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 52);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,308(r3)
	REX_STORE_U32(ctx.r3.u32 + 308, ctx.r11.u32);
	// stw r28,52(r4)
	REX_STORE_U32(ctx.r4.u32 + 52, ctx.r28.u32);
	// beq cr6,0x82779d1c
	if (ctx.cr6.eq) goto loc_82779D1C;
	// lwz r11,100(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 100);
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,312(r3)
	REX_STORE_U32(ctx.r3.u32 + 312, ctx.r11.u32);
	// beq cr6,0x82779c3c
	if (ctx.cr6.eq) goto loc_82779C3C;
loc_82779C10:
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
	// bne 0x82779c10
	if (!ctx.cr0.eq) goto loc_82779C10;
	// lwz r4,312(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r30,r4,12
	ctx.r30.s64 = ctx.r4.s64 + 12;
	// lwz r29,8(r4)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r4.u32 + 8);
	// b 0x82779c44
	goto loc_82779C44;
loc_82779C3C:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// mr r29,r28
	ctx.r29.u64 = ctx.r28.u64;
loc_82779C44:
	// lwz r3,308(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82779c58
	if (ctx.cr6.eq) goto loc_82779C58;
	// bl 0x82779490
	ctx.lr = 0x82779C54;
	sub_82779490(ctx, base);
	// b 0x82779cc0
	goto loc_82779CC0;
loc_82779C58:
	// lwz r4,188(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 188);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82779c90
	if (ctx.cr6.eq) goto loc_82779C90;
loc_82779C64:
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
	// bne 0x82779c64
	if (!ctx.cr0.eq) goto loc_82779C64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82779c90
	if (!ctx.cr6.eq) goto loc_82779C90;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82779C90;
	sub_82772060(ctx, base);
loc_82779C90:
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82779cb8
	if (ctx.cr6.eq) goto loc_82779CB8;
loc_82779C9C:
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
	// bne 0x82779c9c
	if (!ctx.cr0.eq) goto loc_82779C9C;
loc_82779CB8:
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// stw r11,188(r31)
	REX_STORE_U32(ctx.r31.u32 + 188, ctx.r11.u32);
loc_82779CC0:
	// lwz r9,140(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r8,32
	ctx.r8.s64 = 32;
	// lwz r7,136(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r6,12
	ctx.r6.s64 = 12;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// stw r6,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r6.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r8,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r8.u32);
	// stw r9,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r9.u32);
	// stw r7,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r7.u32);
	// beq cr6,0x82779d04
	if (ctx.cr6.eq) goto loc_82779D04;
	// lwz r9,60(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r9,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r9.u32);
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// b 0x82779d10
	goto loc_82779D10;
loc_82779D04:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r28,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r28.u32);
	// stw r11,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
loc_82779D10:
	// stw r30,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r30.u32);
	// stw r29,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r29.u32);
	// b 0x82779f78
	goto loc_82779F78;
loc_82779D1C:
	// lwz r4,180(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 180);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82779d54
	if (ctx.cr6.eq) goto loc_82779D54;
loc_82779D28:
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
	// bne 0x82779d28
	if (!ctx.cr0.eq) goto loc_82779D28;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82779d54
	if (!ctx.cr6.eq) goto loc_82779D54;
	// lwz r3,4(r4)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x82779D54;
	sub_82772060(ctx, base);
loc_82779D54:
	// lwz r11,100(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 100);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// beq cr6,0x82779dac
	if (ctx.cr6.eq) goto loc_82779DAC;
loc_82779D64:
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
	// bne 0x82779d64
	if (!ctx.cr0.eq) goto loc_82779D64;
	// lwz r11,312(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// lwz r8,8(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
loc_82779D8C:
	// mfmsr r7
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r7.u64 = REX_CHECK_GLOBAL_LOCK();
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
	// mtmsrd r7,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r7.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x82779d8c
	if (!ctx.cr0.eq) goto loc_82779D8C;
	// b 0x82779db4
	goto loc_82779DB4;
loc_82779DAC:
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// mr r8,r28
	ctx.r8.u64 = ctx.r28.u64;
loc_82779DB4:
	// lwz r7,312(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 312);
	// li r6,32
	ctx.r6.s64 = 32;
	// lwz r5,140(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// li r4,11
	ctx.r4.s64 = 11;
	// lwz r3,136(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stw r4,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r4.u32);
	// stw r7,180(r31)
	REX_STORE_U32(ctx.r31.u32 + 180, ctx.r7.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stw r6,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r6.u32);
	// stw r5,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r5.u32);
	// stw r3,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r3.u32);
	// beq cr6,0x82779e00
	if (ctx.cr6.eq) goto loc_82779E00;
	// lwz r7,60(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 60);
	// stw r7,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r7.u32);
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// stw r11,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r11.u32);
	// b 0x82779e0c
	goto loc_82779E0C;
loc_82779E00:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// stw r28,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r28.u32);
	// stw r11,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r11.u32);
loc_82779E0C:
	// stw r9,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r9.u32);
	// stw r8,264(r31)
	REX_STORE_U32(ctx.r31.u32 + 264, ctx.r8.u32);
	// b 0x82779f78
	goto loc_82779F78;
loc_82779E18:
	// lwz r10,52(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,28
	ctx.r8.s64 = 28;
	// li r7,10
	ctx.r7.s64 = 10;
	// addi r11,r31,236
	ctx.r11.s64 = ctx.r31.s64 + 236;
	// stw r10,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r10.u32);
	// stw r9,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r9.u32);
	// lwz r6,140(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r10,308(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r9,396(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// stw r8,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r8.u32);
	// lwz r8,136(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// stw r7,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r7.u32);
	// stw r8,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r8.u32);
	// stw r6,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r6.u32);
	// oris r9,r9,32768
	ctx.r9.u64 = ctx.r9.u64 | 2147483648;
	// lwz r8,60(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 60);
	// stw r8,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r8.u32);
	// lwz r8,76(r10)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r10.u32 + 76);
	// stw r8,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r8.u32);
	// lwz r10,168(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 168);
	// stw r10,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r10.u32);
	// stw r9,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r9.u32);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// oris r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 65536;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// b 0x82779f88
	goto loc_82779F88;
loc_82779E8C:
	// lwz r11,52(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 52);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r11,308(r31)
	REX_STORE_U32(ctx.r31.u32 + 308, ctx.r11.u32);
	// stw r28,52(r30)
	REX_STORE_U32(ctx.r30.u32 + 52, ctx.r28.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm. r10,r10,0,1,1
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x82779eb8
	if (!ctx.cr0.eq) goto loc_82779EB8;
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
loc_82779EB8:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm r10,r10,0,4,2
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFEFFFFFFF;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm. r10,r10,0,14,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x20000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82779ef4
	if (ctx.cr0.eq) goto loc_82779EF4;
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// rlwinm r10,r10,0,15,13
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFDFFFF;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r10,288(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 288);
	// oris r10,r10,2048
	ctx.r10.u64 = ctx.r10.u64 | 134217728;
	// stw r10,288(r11)
	REX_STORE_U32(ctx.r11.u32 + 288, ctx.r10.u32);
loc_82779EF4:
	// lwz r11,308(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// lwz r11,88(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82779f20
	if (ctx.cr6.eq) goto loc_82779F20;
loc_82779F04:
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
	// bne 0x82779f04
	if (!ctx.cr0.eq) goto loc_82779F04;
loc_82779F20:
	// lwz r9,136(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 136);
	// li r10,28
	ctx.r10.s64 = 28;
	// stw r11,312(r31)
	REX_STORE_U32(ctx.r31.u32 + 312, ctx.r11.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// lwz r8,140(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r6,308(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 308);
	// stw r10,236(r31)
	REX_STORE_U32(ctx.r31.u32 + 236, ctx.r10.u32);
	// addi r10,r31,236
	ctx.r10.s64 = ctx.r31.s64 + 236;
	// stw r9,248(r31)
	REX_STORE_U32(ctx.r31.u32 + 248, ctx.r9.u32);
	// stw r7,240(r31)
	REX_STORE_U32(ctx.r31.u32 + 240, ctx.r7.u32);
	// stw r8,244(r31)
	REX_STORE_U32(ctx.r31.u32 + 244, ctx.r8.u32);
	// lwz r9,60(r6)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r6.u32 + 60);
	// stw r9,252(r31)
	REX_STORE_U32(ctx.r31.u32 + 252, ctx.r9.u32);
	// beq cr6,0x82779f70
	if (ctx.cr6.eq) goto loc_82779F70;
	// addi r9,r11,12
	ctx.r9.s64 = ctx.r11.s64 + 12;
	// stw r9,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r9.u32);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// stw r11,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r11.u32);
	// b 0x82779f78
	goto loc_82779F78;
loc_82779F70:
	// stw r28,256(r31)
	REX_STORE_U32(ctx.r31.u32 + 256, ctx.r28.u32);
	// stw r28,260(r31)
	REX_STORE_U32(ctx.r31.u32 + 260, ctx.r28.u32);
loc_82779F78:
	// lwz r11,396(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// oris r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 2147483648;
	// stw r11,396(r31)
	REX_STORE_U32(ctx.r31.u32 + 396, ctx.r11.u32);
	// stw r10,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r10.u32);
loc_82779F88:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82795BD0) {
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
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm r11,r11,0,2,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,56(r3)
	REX_STORE_U32(ctx.r3.u32 + 56, ctx.r11.u32);
	// beq 0x82795c1c
	if (ctx.cr0.eq) goto loc_82795C1C;
	// addi r3,r3,8
	ctx.r3.s64 = ctx.r3.s64 + 8;
	// bl 0x82784f68
	ctx.lr = 0x82795C00;
	sub_82784F68(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82795c1c
	if (ctx.cr0.lt) goto loc_82795C1C;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// stw r11,56(r31)
	REX_STORE_U32(ctx.r31.u32 + 56, ctx.r11.u32);
	// bl 0x82789c80
	ctx.lr = 0x82795C1C;
	sub_82789C80(ctx, base);
loc_82795C1C:
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

DEFINE_REX_FUNC(sub_82797D70) {
	REX_FUNC_PROLOGUE();
	// lwz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// li r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32768
	ctx.r10.s64 = -2147483648;
	// rlwinm. r8,r11,0,6,6
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82797da0
	if (ctx.cr0.eq) goto loc_82797DA0;
	// lwz r8,184(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 184);
	// subf r8,r4,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r4.u64;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82797da0
	if (ctx.cr6.lt) goto loc_82797DA0;
	// rlwinm r11,r11,0,7,5
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFDFFFFFF;
	// stw r9,184(r3)
	REX_STORE_U32(ctx.r3.u32 + 184, ctx.r9.u32);
	// stw r11,204(r3)
	REX_STORE_U32(ctx.r3.u32 + 204, ctx.r11.u32);
loc_82797DA0:
	// lwz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// rlwinm. r8,r11,0,7,7
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x82797dc8
	if (ctx.cr0.eq) goto loc_82797DC8;
	// lwz r8,188(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 188);
	// subf r8,r4,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r4.u64;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82797dc8
	if (ctx.cr6.lt) goto loc_82797DC8;
	// rlwinm r11,r11,0,8,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFEFFFFFF;
	// stw r9,188(r3)
	REX_STORE_U32(ctx.r3.u32 + 188, ctx.r9.u32);
	// stw r11,204(r3)
	REX_STORE_U32(ctx.r3.u32 + 204, ctx.r11.u32);
loc_82797DC8:
	// lwz r11,204(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 204);
	// rlwinm. r8,r11,0,8,8
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x800000;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beqlr 
	if (ctx.cr0.eq) return;
	// lwz r8,192(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 192);
	// subf r8,r4,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r4.u64;
	// cmplw cr6,r8,r10
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r10.u32, ctx.xer);
	// bltlr cr6
	if (ctx.cr6.lt) return;
	// rlwinm r11,r11,0,9,7
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFFF7FFFFF;
	// stw r9,192(r3)
	REX_STORE_U32(ctx.r3.u32 + 192, ctx.r9.u32);
	// stw r11,204(r3)
	REX_STORE_U32(ctx.r3.u32 + 204, ctx.r11.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8279BF78) {
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
	// lbz r11,79(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 79);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm. r10,r11,0,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x10;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8279bfb0
	if (ctx.cr0.eq) goto loc_8279BFB0;
	// bl 0x8279bcb0
	ctx.lr = 0x8279BF9C;
	sub_8279BCB0(ctx, base);
	// lbz r11,79(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 79);
	// andi. r11,r11,239
	ctx.r11.u64 = ctx.r11.u64 & 239;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
loc_8279BFA4:
	// li r3,1
	ctx.r3.s64 = 1;
	// stb r11,79(r31)
	REX_STORE_U8(ctx.r31.u32 + 79, ctx.r11.u8);
	// b 0x8279c064
	goto loc_8279C064;
loc_8279BFB0:
	// rlwinm. r10,r11,0,0,24
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8279bfe4
	if (ctx.cr0.eq) goto loc_8279BFE4;
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm. r11,r11,0,17,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8279bfcc
	if (!ctx.cr0.eq) goto loc_8279BFCC;
	// lwz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_8279BFCC:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279bbb8
	ctx.lr = 0x8279BFD8;
	sub_8279BBB8(ctx, base);
	// lbz r11,79(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 79);
	// clrlwi r11,r11,25
	ctx.r11.u64 = ctx.r11.u32 & 0x7F;
	// b 0x8279bfa4
	goto loc_8279BFA4;
loc_8279BFE4:
	// rlwinm. r10,r11,0,25,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x40;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8279c018
	if (ctx.cr0.eq) goto loc_8279C018;
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm. r11,r11,0,18,18
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8279c000
	if (!ctx.cr0.eq) goto loc_8279C000;
	// lwz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_8279C000:
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279bbb8
	ctx.lr = 0x8279C00C;
	sub_8279BBB8(ctx, base);
	// lbz r11,79(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 79);
	// andi. r11,r11,191
	ctx.r11.u64 = ctx.r11.u64 & 191;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x8279bfa4
	goto loc_8279BFA4;
loc_8279C018:
	// rlwinm. r11,r11,0,26,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lhz r11,76(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 76);
	// beq 0x8279c04c
	if (ctx.cr0.eq) goto loc_8279C04C;
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r6,0
	ctx.r6.s64 = 0;
	// bne 0x8279c034
	if (!ctx.cr0.eq) goto loc_8279C034;
	// lwz r6,80(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
loc_8279C034:
	// li r5,2
	ctx.r5.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8279bbb8
	ctx.lr = 0x8279C040;
	sub_8279BBB8(ctx, base);
	// lbz r11,79(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 79);
	// andi. r11,r11,223
	ctx.r11.u64 = ctx.r11.u64 & 223;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// b 0x8279bfa4
	goto loc_8279BFA4;
loc_8279C04C:
	// clrlwi r11,r11,17
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFF;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// sth r11,76(r31)
	REX_STORE_U16(ctx.r31.u32 + 76, ctx.r11.u16);
	// bl 0x82797918
	ctx.lr = 0x8279C060;
	sub_82797918(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8279C064:
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

DEFINE_REX_FUNC(sub_827A5368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x827A5370;
	__savegprlr_29(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x827a54b0
	if (ctx.cr6.eq) goto loc_827A54B0;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmplwi cr6,r10,64206
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 64206, ctx.xer);
	// bne cr6,0x827a54b0
	if (!ctx.cr6.eq) goto loc_827A54B0;
	// lbz r10,12(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 12);
	// cmplwi cr6,r10,11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 11, ctx.xer);
	// beq cr6,0x827a53a4
	if (ctx.cr6.eq) goto loc_827A53A4;
	// li r3,6115
	ctx.r3.s64 = 6115;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A53A4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x827a53b4
	if (!ctx.cr6.eq) goto loc_827A53B4;
	// li r3,6170
	ctx.r3.s64 = 6170;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A53B4:
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x827a53c8
	if (!ctx.cr6.eq) goto loc_827A53C8;
	// li r3,6130
	ctx.r3.s64 = 6130;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A53C8:
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x827a53dc
	if (!ctx.cr6.eq) goto loc_827A53DC;
	// li r3,6125
	ctx.r3.s64 = 6125;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A53DC:
	// lhz r9,14(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 14);
	// addi r8,r11,14
	ctx.r8.s64 = ctx.r11.s64 + 14;
	// lhz r10,12(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827a53f8
	if (ctx.cr6.lt) goto loc_827A53F8;
	// li r3,6145
	ctx.r3.s64 = 6145;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A53F8:
	// lhz r9,18(r11)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r11.u32 + 18);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x827a540c
	if (ctx.cr6.lt) goto loc_827A540C;
	// li r3,6150
	ctx.r3.s64 = 6150;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A540C:
	// lbz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 16);
	// addi r9,r11,16
	ctx.r9.s64 = ctx.r11.s64 + 16;
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// ble cr6,0x827a5424
	if (!ctx.cr6.gt) goto loc_827A5424;
	// li r3,6135
	ctx.r3.s64 = 6135;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A5424:
	// lbz r10,20(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 20);
	// cmplwi cr6,r10,7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 7, ctx.xer);
	// ble cr6,0x827a5438
	if (!ctx.cr6.gt) goto loc_827A5438;
	// li r3,6140
	ctx.r3.s64 = 6140;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A5438:
	// stw r11,28(r3)
	REX_STORE_U32(ctx.r3.u32 + 28, ctx.r11.u32);
	// addi r30,r1,96
	ctx.r30.s64 = ctx.r1.s64 + 96;
	// lhz r7,12(r11)
	ctx.r7.u64 = REX_LOAD_U16(ctx.r11.u32 + 12);
	// addi r29,r1,160
	ctx.r29.s64 = ctx.r1.s64 + 160;
	// lwz r6,8(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r5,r11,4
	ctx.r5.s64 = ctx.r11.s64 + 4;
	// lwz r3,16(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// stw r30,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r30.u32);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// bl 0x827a6578
	ctx.lr = 0x827A5468;
	sub_827A6578(ctx, base);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x827a54a8
	if (ctx.cr6.eq) goto loc_827A54A8;
	// li r9,12
	ctx.r9.s64 = 12;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,0(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 0, temp.u32);
	// addi r10,r31,48
	ctx.r10.s64 = ctx.r31.s64 + 48;
	// li r11,0
	ctx.r11.s64 = 0;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_827A5488:
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lfsx f0,r11,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	ctx.f0.f64 = double(temp.f32);
	// lfsx f13,r11,r8
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// stfs f0,-44(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -44, temp.u32);
	// stfsu f13,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x827a5488
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827A5488;
loc_827A54A8:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x827a54b4
	goto loc_827A54B4;
loc_827A54B0:
	// li r3,6100
	ctx.r3.s64 = 6100;
loc_827A54B4:
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AD090) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-10504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10504);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-10500(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -10500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD318) {
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
	// lfs f0,22168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10564(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10564);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10428(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10428, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AD950) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10340(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10340);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10236(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ADE68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,22312
	ctx.r9.s64 = ctx.r11.s64 + 22312;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,22312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10084(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AE690) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9836(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9836, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AEEF8) {
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
	// lfs f0,22648(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22648);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9680(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9680);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFC00) {
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
	// lfs f0,22840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9192(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1368) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8492(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8492, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2040) {
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
	// lfs f0,23288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8212);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8112(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8112, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2E30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7692(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7692);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-7688(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -7688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3C68) {
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
	// lfs f0,23624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7276(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B4B78) {
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
	// lfs f0,23784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6960(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6960);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6840(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B5D20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6416(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6416);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6312(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6312, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B68D8) {
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
	// lfs f0,24168(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24168);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6028(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6028);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5960(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7A20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,24312
	ctx.r9.s64 = ctx.r11.s64 + 24312;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-5440(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -5440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8DF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-4900(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4900);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4896(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -4896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9798) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BA560) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4212(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB220) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3824);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3820(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3820, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BBE88) {
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
	// lfs f0,25400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3544(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3544);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3436(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD2F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BDFF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2464(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2464);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2460(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BEDD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2052(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BFD18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,26200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1700(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1700);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1596(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0A28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1196(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1BA0) {
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
	// lfs f0,26712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-772(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -772);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-712(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -712, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2C98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -208);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-204(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,252(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 252);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,684(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5A18) {
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
	// lfs f0,27736(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27736);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1088(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1088);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1156(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1156, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6B48) {
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
	// lfs f0,28120(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28120);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,1624(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1624);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1688(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C7C10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28524);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2208(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8C70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,2684(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2684);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,2688(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 2688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C9888) {
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
	// lfs f0,28776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3040(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CAA28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,3504(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 3504);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3556(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CBA30) {
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
	// lfs f0,29096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,3940(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3940);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4044(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CCAD0) {
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
	// lfs f0,29288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4532(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CDD20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,29504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEDF8) {
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
	// lfs f0,29608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5444(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5444);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5552(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5552, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0010) {
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
	// lfs f0,29800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6084(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6084, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D1278) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,29992
	ctx.r9.s64 = ctx.r11.s64 + 29992;
	// lfs f0,29992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,6620(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 6620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D21C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30196(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30196);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7064(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7064, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D2F88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 7468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D4060) {
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
	// lfs f0,30440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7844(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7844);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7956(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7956, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D52D8) {
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
	// lfs f0,30632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8376(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8376);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,8496(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 8496, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6508) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,30824
	ctx.r9.s64 = ctx.r11.s64 + 30824;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,30824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30824);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9028(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9028, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D77F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31032
	ctx.r9.s64 = ctx.r11.s64 + 31032;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8B38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,10032(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 10032);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10140(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D99F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,10564(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10564);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DA7B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,31584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,10972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 10972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB888) {
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
	// lfs f0,31688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,11460(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 11460, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DCAD0) {
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
	// lfs f0,31880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,11972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 11972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DDCC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,12540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 12540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DECC8) {
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
	// lfs f0,32216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12928(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12928);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13012(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13012, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DFEB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0DF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,13980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 13980);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13984(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 13984, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1DC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14472(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2F40) {
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
	// lfs f0,-32368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32368);
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
	// stfs f0,14976(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 14976, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E43C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15452(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15452);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15556(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E51B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,-31928
	ctx.r9.s64 = ctx.r11.s64 + -31928;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-31928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,15948(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 15948, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6750) {
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
	// lfs f0,-29320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16512(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16512);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16572(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16572, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E79E8) {
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
	// lfs f0,-27480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16972(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16972);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8F00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17684(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E9F28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18116(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18116);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18120(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EAE28) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18544);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18548(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18548, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EBD58) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,18968(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18968);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,18972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 18972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECC88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-21816
	ctx.r9.s64 = ctx.r11.s64 + -21816;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-21816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19384(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE0D0) {
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
	// lfs f0,-20776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19804(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19804);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19940(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19940, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EF320) {
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
	// lfs f0,-19672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,20392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,20448(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 20448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F05D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,20860(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 20860);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20964(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20964, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F15F0) {
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
	// lfs f0,-18328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18328);
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
	// stfs f0,21408(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 21408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F2D00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lis r7,-32112
	ctx.r7.s64 = -2104492032;
	// lfs f0,22028(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22028);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17384(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17384);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,22052(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 22052, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4870) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-16680
	ctx.r9.s64 = ctx.r11.s64 + -16680;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-16680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,23016(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 23016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5B60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,-15896
	ctx.r9.s64 = ctx.r11.s64 + -15896;
	// lfs f0,-15896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23608(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 23608, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F6AF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-14696(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14696);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24036(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F7A38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-13936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-25312(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -25312);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,24468(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24468, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8948) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-12344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24744(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24744);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F98D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-10248(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10248);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,25232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25232);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,25284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 25284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FA970) {
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
	// lfs f0,-9768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25640(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25640);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25756(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FBBF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-9560
	ctx.r9.s64 = ctx.r11.s64 + -9560;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-9560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,26296(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 26296, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FCF38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,26748(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26748);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDE38) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FECF8) {
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
	// lfs f0,-9048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,27656(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 27656);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,27724(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 27724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800050) {
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
	// lfs f0,-8856(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8856);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,28208(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 28208);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28288(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28288, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828013B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,-8664
	ctx.r9.s64 = ctx.r11.s64 + -8664;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-8664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,28852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 28852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828027A0) {
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
	// lfs f0,-8472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,29332(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 29332);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29436(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803A68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,-8280
	ctx.r9.s64 = ctx.r11.s64 + -8280;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,-8280(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8280);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,29984(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 29984, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82804E40) {
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
	// lfs f0,-8088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30460(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30460);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,30560(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 30560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828061C8) {
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
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31012(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31012);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31128(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31128, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82807548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-7632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,31696(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 31696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82808328) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32100(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32100);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32104(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32104, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809200) {
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
	// lfs f0,-7384(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7384);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,32448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32448);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,32536(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 32536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280A628) {
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
	// lfs f0,-7192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-32524(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -32524);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-32412(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -32412, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BA28) {
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
	// lfs f0,-7000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31948(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31948);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CD38) {
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
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31256(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E020) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-30708(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30708);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30704(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30704, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F100) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-6304
	ctx.r9.s64 = ctx.r11.s64 + -6304;
	// lfs f0,-6304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30208(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -30208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280FEE8) {
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
	// lfs f0,-6104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29868);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828111B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-29344(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -29344);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29236(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29236, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82812130) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5636(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5636);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28784(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28784, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813200) {
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
	// lfs f0,-5448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28352(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28352);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28284(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814258) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4956);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27764(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27764, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815348) {
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
	// lfs f0,-4744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-27356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -27356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-27248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -27248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816740) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-26660(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26660);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-26656(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -26656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817120) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26372(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26372);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26368(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828181A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-25860(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -25860);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25856(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25856, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828192B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3672(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3672);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-25400(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -25400);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25348(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25348, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A3D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24844);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24840(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24840, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281B118) {
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
	// lfs f0,-3160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-24496(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -24496);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-24436(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -24436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281C438) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-23880(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23880);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-23876(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -23876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281D418) {
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
	// lfs f0,-2632(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2632);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23388(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23388, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281E7D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2324(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2324);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F790) {
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
	// lfs f0,-2136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22388(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22388);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22340(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22340, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82820AE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-21780(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21780);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-21776(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -21776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821A48) {
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
	// lfs f0,-1720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21396(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21396);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21324(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82822E30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-1496
	ctx.r9.s64 = ctx.r11.s64 + -1496;
	// lfs f0,-1496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20744(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -20744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823D88) {
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
	// lfs f0,-1240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-20392(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -20392);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20280(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825220) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19676(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19676, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825F80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-664(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -664);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-19364(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -19364);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826F40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18796(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828280E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18284(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18284, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828F68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-60(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -60);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282A0D8) {
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
	// lfs f0,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17448);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17344(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17344, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282B2E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-16812(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16812);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C3F8) {
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
	// lfs f0,568(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 568);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-16356(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -16356);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16300(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D6C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15756(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15756, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E710) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,952
	ctx.r9.s64 = ctx.r11.s64 + 952;
	// lfs f0,952(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 952);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15272(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -15272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F6F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-14812(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14812);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830520) {
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
	// lfs f0,1352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14468);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831998) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13772(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13772, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832958) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-13304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-13300(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -13300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833A08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12804(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12804);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12800(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12800, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82834AD8) {
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
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-12408(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12408);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-12308(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -12308, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835CF0) {
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
	// lfs f0,2520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11836(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11836);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837000) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-11212(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -11212);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11208(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828381B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2928(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2928);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10796(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10796);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838FF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10276(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10276, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82839E68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-9852(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9852);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9848(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9848, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283AF60) {
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
	// lfs f0,3472(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3472);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9468);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9356(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9356, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283C3E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8764(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8764);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8760(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8760, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D250) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,3960(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3960);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E1C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,4080
	ctx.r9.s64 = ctx.r11.s64 + 4080;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,4080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7880(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7880, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F678) {
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
	// lfs f0,4368(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4368);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7336(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7336);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7272(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7272, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82840820) {
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
	// lfs f0,4608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6864);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6752(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82841D68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6136(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6136);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6132(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842C20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5700);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5696(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843D80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-5188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5188);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-5184(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -5184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828445D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-4940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4940);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4936(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -4936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845050) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4620(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846028) {
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
	// lfs f0,5744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-4268(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -4268);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4148(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847538) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6052(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6052);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82848398) {
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
	// lfs f0,6192(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6192);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3160(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3160);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3096(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3096, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849810) {
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
	// lfs f0,6416(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6416);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2580);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284ACE8) {
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
	// lfs f0,6640(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6640);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2008(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2008);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1892(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1892, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C190) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,6864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1396(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -1396);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D058) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-860(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284DE50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,7312
	ctx.r9.s64 = ctx.r11.s64 + 7312;
	// lfs f0,7312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-424(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -424, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284EE50) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-72(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -72);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,48(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 48, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850308) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,668(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 668);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,672(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 672, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851358) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,8200
	ctx.r9.s64 = ctx.r11.s64 + 8200;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,8200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,1168(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 1168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852880) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8524(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8524);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1776(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1776, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828539B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2276(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2276);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828553D0) {
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
	// addi r11,r11,-2988
	ctx.r11.s64 = ctx.r11.s64 + -2988;
	// addi r3,r11,8
	ctx.r3.s64 = ctx.r11.s64 + 8;
	// bl 0x82855c54
	ctx.lr = 0x828553EC;
	__imp__RtlInitializeCriticalSection(ctx, base);
	// lis r11,-32123
	ctx.r11.s64 = -2105212928;
	// addi r3,r11,22176
	ctx.r3.s64 = ctx.r11.s64 + 22176;
	// bl 0x827387e8
	ctx.lr = 0x828553F8;
	sub_827387E8(ctx, base);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82874BD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82874BD8;
	__savegprlr_26(ctx, base);
	// rlwinm r10,r4,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// lvsl v7,r0,r3
	temp.u32 = ctx.r3.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r11,16
	ctx.r11.s64 = 16;
	// lvx128 v62,r3,r4
	ea = (ctx.r3.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// vspltisb v0,0
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_set1_epi8(char(0x0)));
	// add r5,r3,r4
	ctx.r5.u64 = ctx.r3.u64 + ctx.r4.u64;
	// vspltish v12,2
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_set1_epi16(short(0x2)));
	// rlwinm r9,r4,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// vspltish v11,4
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_set1_epi16(short(0x4)));
	// add r8,r10,r4
	ctx.r8.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// lvx128 v61,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 + ctx.r4.u64;
	// vperm128 v5,v63,v61,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v60,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r31,r9,r4
	ctx.r31.u64 = ctx.r9.u64 + ctx.r4.u64;
	// lvsl v6,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// rlwinm r5,r4,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// add r30,r7,r4
	ctx.r30.u64 = ctx.r7.u64 + ctx.r4.u64;
	// vperm128 v4,v62,v60,v6
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// add r5,r5,r3
	ctx.r5.u64 = ctx.r5.u64 + ctx.r3.u64;
	// lvx128 v59,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v3,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v1,r0,r9
	temp.u32 = ctx.r9.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r3,1104
	ctx.r3.s64 = 1104;
	// lvx128 v58,r9,r4
	ea = (ctx.r9.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v10,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v55,r31,r11
	ea = (ctx.r31.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v6,v59,v56,v1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvsl v7,r0,r31
	temp.u32 = ctx.r31.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r28,48
	ctx.r28.s64 = 48;
	// lvx128 v57,r7,r4
	ea = (ctx.r7.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v4,v58,v55,v7
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v54,r30,r11
	ea = (ctx.r30.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubshs v2,v10,v3
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// lvsl v5,r0,r30
	temp.u32 = ctx.r30.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vmrghb v9,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v53,r5,r11
	ea = (ctx.r5.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v31,v57,v54,v5
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)));
	// lvx128 v52,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v8,v0,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v1,r0,r5
	temp.u32 = ctx.r5.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// li r27,96
	ctx.r27.s64 = 96;
	// lvx128 v51,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v30,v52,v53,v1
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8)));
	// lvx128 v48,r10,r11
	ea = (ctx.r10.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v4,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvsl v7,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vsubshs v28,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vperm128 v5,v51,v48,v7
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v49,r8,r4
	ea = (ctx.r8.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v47,r8,r11
	ea = (ctx.r8.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v47.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghb v29,v0,v30
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v46,r7,r11
	ea = (ctx.r7.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r26,144
	ctx.r26.s64 = 144;
	// lvx128 v50,r10,r4
	ea = (ctx.r10.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v50.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,192
	ctx.r9.s64 = 192;
	// lvsl v7,r0,r7
	temp.u32 = ctx.r7.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vsubshs v1,v8,v9
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// lvsl v6,r0,r8
	temp.u32 = ctx.r8.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v31,v49,v46,v7
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v6,v50,v47,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v50.u8), simde_mm_load_si128((simde__m128i*)ctx.v47.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vsubshs v30,v29,v4
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vmrghb v7,v0,v5
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v13,r6,r3
	ea = (ctx.r6.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,240
	ctx.r8.s64 = 240;
	// vslh v27,v2,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vmrghb v5,v0,v31
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r7,288
	ctx.r7.s64 = 288;
	// vmrghb v6,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_unpackhi_epi8(simde_mm_load_si128((simde__m128i*)ctx.v6.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// li r6,336
	ctx.r6.s64 = 336;
	// vslh v29,v30,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v30.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubshs v26,v7,v8
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vsubshs v23,v4,v5
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vsubshs v25,v6,v7
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// vsubshs v24,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vslh v22,v28,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v28.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v22.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v21,v1,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v21.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v19,v25,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v25.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v18,v24,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v24.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v17,v23,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v20,v26,v12
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v26.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v20.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v16,v29,v13
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v15,v27,v13
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v14,v22,v13
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v22.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v0,v21,v13
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v21.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v12,v20,v13
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v20.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v2,v19,v13
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v1,v18,v13
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vaddshs v31,v17,v13
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v13.s16)));
	// vsrah v30,v16,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v16.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v29,v15,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v15.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v29.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v28,v14,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v14.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v28.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v27,v0,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v0.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v27.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v26,v12,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v26.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v25,v2,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v2.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v25.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v24,v1,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v1.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v24.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v23,v31,v11
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v31.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v23.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v22,v30,v4
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v21,v29,v3
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vaddshs v20,v28,v10
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v19,v27,v9
	simde_mm_store_si128((simde__m128i*)ctx.v19.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vaddshs v18,v26,v8
	simde_mm_store_si128((simde__m128i*)ctx.v18.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvx128 v22,r29,r6
	ea = (ctx.r29.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v17,v25,v7
	simde_mm_store_si128((simde__m128i*)ctx.v17.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// stvx128 v21,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v16,v24,v6
	simde_mm_store_si128((simde__m128i*)ctx.v16.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// stvx128 v20,r29,r28
	ea = (ctx.r29.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v15,v23,v5
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v23.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvx128 v19,r29,r27
	ea = (ctx.r29.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v18,r29,r26
	ea = (ctx.r29.u32 + ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v17,r29,r9
	ea = (ctx.r29.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v16,r29,r8
	ea = (ctx.r29.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v15,r29,r7
	ea = (ctx.r29.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

