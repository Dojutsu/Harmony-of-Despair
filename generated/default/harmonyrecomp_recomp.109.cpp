#include "harmonyrecomp_funcs.109.h"

DEFINE_REX_FUNC(sub_822170C8) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r11,r11,20580
	ctx.r11.s64 = ctx.r11.s64 + 20580;
	// clrlwi. r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// beq 0x822170f4
	if (ctx.cr0.eq) goto loc_822170F4;
	// bl 0x825e0378
	ctx.lr = 0x822170F4;
	sub_825E0378(ctx, base);
loc_822170F4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

DEFINE_REX_FUNC(sub_8221A5E0) {
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
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// cmplw cr6,r11,r4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r4.u32, ctx.xer);
	// bgt cr6,0x8221a64c
	if (ctx.cr6.gt) goto loc_8221A64C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// addi r4,r11,604
	ctx.r4.s64 = ctx.r11.s64 + 604;
	// bl 0x822167f8
	ctx.lr = 0x8221A618;
	sub_822167F8(ctx, base);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// bl 0x82216678
	ctx.lr = 0x8221A624;
	sub_82216678(ctx, base);
	// bl 0x82216e60
	ctx.lr = 0x8221A628;
	sub_82216E60(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r11,r11,112
	ctx.r11.s64 = ctx.r11.s64 + 112;
	// stw r11,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r11.u32);
	// bl 0x82216d98
	ctx.lr = 0x8221A63C;
	sub_82216D98(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8235ec48
	ctx.lr = 0x8221A64C;
	sub_8235EC48(ctx, base);
loc_8221A64C:
	// lwz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24);
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// rlwinm r9,r11,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8221a684
	if (ctx.cr6.eq) goto loc_8221A684;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8221a688
	goto loc_8221A688;
loc_8221A684:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221A688:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// bgt cr6,0x8221a6b0
	if (ctx.cr6.gt) goto loc_8221A6B0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8221a6a4
	if (ctx.cr6.eq) goto loc_8221A6A4;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8221a6a8
	goto loc_8221A6A8;
loc_8221A6A4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221A6A8:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// subf r9,r11,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r11.u64;
loc_8221A6B0:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8221a6c0
	if (ctx.cr6.eq) goto loc_8221A6C0;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// b 0x8221a6c4
	goto loc_8221A6C4;
loc_8221A6C0:
	// li r11,0
	ctx.r11.s64 = 0;
loc_8221A6C4:
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r8,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lwzx r10,r10,r9
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// add r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
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

DEFINE_REX_FUNC(sub_82223A00) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// stfs f1,40(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 40, temp.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// stfs f1,56(r11)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r11.u32 + 56, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82224958) {
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
	// lwz r11,60(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 60);
	// addi r31,r3,60
	ctx.r31.s64 = ctx.r3.s64 + 60;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82224988;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822249d4
	if (ctx.cr0.eq) goto loc_822249D4;
	// lbz r11,24(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 24);
	// lfs f0,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 4, temp.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822249c0
	if (!ctx.cr0.eq) goto loc_822249C0;
	// lbz r11,25(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 25);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822249c0
	if (ctx.cr0.eq) goto loc_822249C0;
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stb r11,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r11.u8);
	// stb r10,25(r31)
	REX_STORE_U8(ctx.r31.u32 + 25, ctx.r10.u8);
loc_822249C0:
	// lwz r11,36(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822249d4
	if (ctx.cr6.eq) goto loc_822249D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82224560
	ctx.lr = 0x822249D4;
	sub_82224560(ctx, base);
loc_822249D4:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82218310
	ctx.lr = 0x822249DC;
	sub_82218310(ctx, base);
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

DEFINE_REX_FUNC(sub_82229A78) {
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
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,108(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 108);
	// stfs f1,8(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lwz r31,0(r30)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x82229ac8
	goto loc_82229AC8;
loc_82229AA4:
	// lwz r3,8(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82229ac4
	if (ctx.cr6.eq) goto loc_82229AC4;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82229AC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82229AC4:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
loc_82229AC8:
	// cmplw cr6,r31,r30
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r30.u32, ctx.xer);
	// bne cr6,0x82229aa4
	if (!ctx.cr6.eq) goto loc_82229AA4;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
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

DEFINE_REX_FUNC(sub_8222F318) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8222F320;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 20);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8222f4a8
	if (ctx.cr0.eq) goto loc_8222F4A8;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8222f4a8
	if (ctx.cr6.eq) goto loc_8222F4A8;
	// addi r30,r3,64
	ctx.r30.s64 = ctx.r3.s64 + 64;
	// lfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 52);
	ctx.f0.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r3,48(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmpwi cr6,r3,2
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 2, ctx.xer);
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r11,14376
	ctx.r29.s64 = ctx.r11.s64 + 14376;
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r28,84(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// beq cr6,0x8222f3f8
	if (ctx.cr6.eq) goto loc_8222F3F8;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82363f08
	ctx.lr = 0x8222F398;
	sub_82363F08(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8222f3cc
	if (!ctx.cr0.eq) goto loc_8222F3CC;
	// lfs f13,-1908(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1908);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x8222f3c4
	if (!ctx.cr6.gt) goto loc_8222F3C4;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f13,-1628(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1628);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,112(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// b 0x8222f3f8
	goto loc_8222F3F8;
loc_8222F3C4:
	// stfs f13,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 112, temp.u32);
	// b 0x8222f4a8
	goto loc_8222F4A8;
loc_8222F3CC:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
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
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,116(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 116, temp.u32);
loc_8222F3F8:
	// lhz r11,126(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 126);
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// lfs f13,112(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// li r10,4
	ctx.r10.s64 = 4;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// lvx128 v63,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// li r11,255
	ctx.r11.s64 = 255;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
	// lfs f0,-9856(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9856);
	ctx.f0.f64 = double(temp.f32);
	// stb r11,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r11.u8);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lvsl v0,r0,r10
	temp.u32 = ctx.r10.u32;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_load_si128((simde__m128i*)&VectorShiftTableL[(temp.u32 & 0xF) * 16]));
	// vperm128 v63,v63,v63,v0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// stb r11,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r11.u8);
	// lfs f12,116(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 116);
	ctx.f12.f64 = double(temp.f32);
	// li r9,0
	ctx.r9.s64 = 0;
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// lwz r3,28(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 28);
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,177
	ctx.r4.s64 = 177;
	// fctidz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f13.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lbz r11,95(r1)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// stb r11,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r11.u8);
	// lfd f13,96(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f11,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f11.f64 = double(temp.f32);
	// fadds f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 + ctx.f11.f64));
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f12,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f12.u64);
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// subf r6,r10,r11
	ctx.r6.u64 = ctx.r11.u64 - ctx.r10.u64;
	// bl 0x823be020
	ctx.lr = 0x8222F4A8;
	sub_823BE020(ctx, base);
loc_8222F4A8:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82243C80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x82243C88;
	__savegprlr_20(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,268(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 268);
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// lwz r10,264(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// addi r30,r3,260
	ctx.r30.s64 = ctx.r3.s64 + 260;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// rlwinm. r11,r11,0,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFC;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82243da4
	if (ctx.cr0.eq) goto loc_82243DA4;
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82243da4
	if (ctx.cr0.eq) goto loc_82243DA4;
	// addis r27,r3,1
	ctx.r27.s64 = ctx.r3.s64 + 65536;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r27,r27,-3100
	ctx.r27.s64 = ctx.r27.s64 + -3100;
loc_82243CCC:
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// lbz r24,73(r10)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r10.u32 + 73);
	// lhz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 8);
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// bl 0x823bfa70
	ctx.lr = 0x82243CE8;
	sub_823BFA70(ctx, base);
	// lwz r11,264(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 264);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// lwz r10,0(r25)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r4,r25
	ctx.r4.u64 = ctx.r25.u64;
	// lwz r9,0(r27)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r11,r31
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// lwz r10,144(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 144);
	// lwz r26,0(r9)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r22,20(r11)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// bctrl 
	ctx.lr = 0x82243D1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,36(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 36);
	// lwz r21,0(r10)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82243D38;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// mr r20,r3
	ctx.r20.u64 = ctx.r3.u64;
	// mr r3,r25
	ctx.r3.u64 = ctx.r25.u64;
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82243D50;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,556(r26)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r26.u32 + 556);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// lwz r3,0(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r6,r20
	ctx.r6.u64 = ctx.r20.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// mr r7,r22
	ctx.r7.u64 = ctx.r22.u64;
	// clrlwi r8,r23,16
	ctx.r8.u64 = ctx.r23.u32 & 0xFFFF;
	// rlwinm r9,r11,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r10,r21
	ctx.r10.u64 = ctx.r21.u64;
	// bctrl 
	ctx.lr = 0x82243D84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82243ccc
	if (ctx.cr6.lt) goto loc_82243CCC;
loc_82243DA4:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8224BCA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8224BCB0;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,128(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 128);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r27,0
	ctx.r27.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8224bcd0
	if (ctx.cr0.eq) goto loc_8224BCD0;
	// stb r27,128(r3)
	REX_STORE_U8(ctx.r3.u32 + 128, ctx.r27.u8);
loc_8224BCD0:
	// lfs f0,12(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 12);
	ctx.f0.f64 = double(temp.f32);
	// addi r5,r31,28
	ctx.r5.s64 = ctx.r31.s64 + 28;
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// addi r4,r31,36
	ctx.r4.s64 = ctx.r31.s64 + 36;
	// stw r27,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r27.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r27,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r27.u32);
	// mr r28,r27
	ctx.r28.u64 = ctx.r27.u64;
	// mr r26,r27
	ctx.r26.u64 = ctx.r27.u64;
	// bl 0x82322d08
	ctx.lr = 0x8224BCFC;
	sub_82322D08(ctx, base);
	// lbz r11,146(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 146);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8224bd58
	if (ctx.cr0.eq) goto loc_8224BD58;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,148(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 148);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,12468
	ctx.r11.s64 = ctx.r11.s64 + 12468;
	// lfs f13,-232(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -232);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8224bd30
	if (!ctx.cr6.lt) goto loc_8224BD30;
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,148(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
	// li r28,128
	ctx.r28.s64 = 128;
	// b 0x8224bf70
	goto loc_8224BF70;
loc_8224BD30:
	// lis r10,-32219
	ctx.r10.s64 = -2111504384;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f0,148(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 148, temp.u32);
	// addi r10,r10,-18704
	ctx.r10.s64 = ctx.r10.s64 + -18704;
	// stfs f0,12(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 12, temp.u32);
	// stb r27,146(r31)
	REX_STORE_U8(ctx.r31.u32 + 146, ctx.r27.u8);
	// stw r10,124(r31)
	REX_STORE_U32(ctx.r31.u32 + 124, ctx.r10.u32);
	// stb r11,128(r31)
	REX_STORE_U8(ctx.r31.u32 + 128, ctx.r11.u8);
	// b 0x8224bf70
	goto loc_8224BF70;
loc_8224BD58:
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// addi r30,r11,1608
	ctx.r30.s64 = ctx.r11.s64 + 1608;
	// lfs f11,15484(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 15484);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// bge cr6,0x8224bd9c
	if (!ctx.cr6.lt) goto loc_8224BD9C;
	// addi r6,r1,88
	ctx.r6.s64 = ctx.r1.s64 + 88;
	// lbz r4,145(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + 145);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8224bfa8
	ctx.lr = 0x8224BD88;
	sub_8224BFA8(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,146(r31)
	REX_STORE_U8(ctx.r31.u32 + 146, ctx.r11.u8);
	// lwz r28,80(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r26,88(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// b 0x8224bf70
	goto loc_8224BF70;
loc_8224BD9C:
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// bl 0x82322d08
	ctx.lr = 0x8224BDA4;
	sub_82322D08(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f31,88(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 88);
	ctx.f31.f64 = double(temp.f32);
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
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
	// fcmpu cr6,f0,f11
	ctx.cr6.compare(ctx.f0.f64, ctx.f11.f64);
	// bgt cr6,0x8224bddc
	if (ctx.cr6.gt) goto loc_8224BDDC;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8224BDDC:
	// clrlwi. r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r29,r11,-32088
	ctx.r29.s64 = ctx.r11.s64 + -32088;
	// beq 0x8224bdf4
	if (ctx.cr0.eq) goto loc_8224BDF4;
	// li r28,2
	ctx.r28.s64 = 2;
	// b 0x8224be38
	goto loc_8224BE38;
loc_8224BDF4:
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f31,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8224be2c
	if (ctx.cr6.lt) goto loc_8224BE2C;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8224BE2C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224be38
	if (ctx.cr0.eq) goto loc_8224BE38;
	// li r28,1
	ctx.r28.s64 = 1;
loc_8224BE38:
	// fabs f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = ctx.f31.u64 & ~0x8000000000000000;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8224bef8
	if (!ctx.cr6.gt) goto loc_8224BEF8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// bl 0x8224c3c8
	ctx.lr = 0x8224BE60;
	sub_8224C3C8(ctx, base);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f1,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8224bea8
	if (ctx.cr6.lt) goto loc_8224BEA8;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8224BEA8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224bef8
	if (ctx.cr0.eq) goto loc_8224BEF8;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// bgt cr6,0x8224bee4
	if (ctx.cr6.gt) goto loc_8224BEE4;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8224BEE4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224bef4
	if (ctx.cr0.eq) goto loc_8224BEF4;
	// ori r28,r28,2
	ctx.r28.u64 = ctx.r28.u64 | 2;
	// b 0x8224bef8
	goto loc_8224BEF8;
loc_8224BEF4:
	// ori r28,r28,1
	ctx.r28.u64 = ctx.r28.u64 | 1;
loc_8224BEF8:
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,-1084(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1084);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x8224bf34
	if (ctx.cr6.lt) goto loc_8224BF34;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_8224BF34:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8224bf70
	if (ctx.cr0.eq) goto loc_8224BF70;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8224bf68
	if (ctx.cr6.eq) goto loc_8224BF68;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,960(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 960);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8224BF60;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,13
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 13, ctx.xer);
	// beq cr6,0x8224bf70
	if (ctx.cr6.eq) goto loc_8224BF70;
loc_8224BF68:
	// li r26,16
	ctx.r26.s64 = 16;
	// ori r28,r28,16
	ctx.r28.u64 = ctx.r28.u64 | 16;
loc_8224BF70:
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// lbz r10,2364(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 2364);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x8224bf8c
	if (ctx.cr0.eq) goto loc_8224BF8C;
	// stw r28,2368(r11)
	REX_STORE_U32(ctx.r11.u32 + 2368, ctx.r28.u32);
	// stw r26,2372(r11)
	REX_STORE_U32(ctx.r11.u32 + 2372, ctx.r26.u32);
	// b 0x8224bf94
	goto loc_8224BF94;
loc_8224BF8C:
	// stw r27,2368(r11)
	REX_STORE_U32(ctx.r11.u32 + 2368, ctx.r27.u32);
	// stw r27,2372(r11)
	REX_STORE_U32(ctx.r11.u32 + 2372, ctx.r27.u32);
loc_8224BF94:
	// li r3,1
	ctx.r3.s64 = 1;
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82272AB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x82272AC0;
	__savegprlr_22(ctx, base);
	// stwu r1,-304(r1)
	ea = -304 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,0
	ctx.r11.s64 = 0;
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// lwzx r10,r3,r11
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82272f70
	if (ctx.cr6.eq) goto loc_82272F70;
	// addis r22,r3,1
	ctx.r22.s64 = ctx.r3.s64 + 65536;
	// addi r22,r22,-3152
	ctx.r22.s64 = ctx.r22.s64 + -3152;
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82272ef0
	if (ctx.cr6.lt) goto loc_82272EF0;
	// beq cr6,0x82272b24
	if (ctx.cr6.eq) goto loc_82272B24;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82272f70
	if (!ctx.cr6.lt) goto loc_82272F70;
	// bl 0x82279930
	ctx.lr = 0x82272B00;
	sub_82279930(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// ori r10,r10,62392
	ctx.r10.u64 = ctx.r10.u64 | 62392;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r9,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r9.u32);
	// lfs f0,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// stfsx f0,r24,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r24.u32 + ctx.r10.u32, temp.u32);
	// b 0x82272f70
	goto loc_82272F70;
loc_82272B24:
	// addis r10,r24,1
	ctx.r10.s64 = ctx.r24.s64 + 65536;
	// lwz r11,44(r24)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + 44);
	// addi r10,r10,-3144
	ctx.r10.s64 = ctx.r10.s64 + -3144;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lfs f0,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// bne cr6,0x82272b4c
	if (!ctx.cr6.eq) goto loc_82272B4C;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82272f6c
	goto loc_82272F6C;
loc_82272B4C:
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,88(r24)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + 88);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r11,r11,-31232
	ctx.r11.s64 = ctx.r11.s64 + -31232;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lis r7,-32226
	ctx.r7.s64 = -2111963136;
	// li r30,0
	ctx.r30.s64 = 0;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r7,-30128
	ctx.r9.s64 = ctx.r7.s64 + -30128;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r23,r24,88
	ctx.r23.s64 = ctx.r24.s64 + 88;
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f0
	ctx.f13.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// lfs f0,-8796(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8796);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x82272eac
	if (!ctx.cr6.gt) goto loc_82272EAC;
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// stw r30,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r30.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r11,-31728
	ctx.r8.s64 = ctx.r11.s64 + -31728;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r7,-32225
	ctx.r7.s64 = -2111897600;
	// addi r25,r11,12236
	ctx.r25.s64 = ctx.r11.s64 + 12236;
	// addi r7,r7,32720
	ctx.r7.s64 = ctx.r7.s64 + 32720;
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,144
	ctx.r6.s64 = ctx.r1.s64 + 144;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// lfs f0,232(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 232);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stfs f0,0(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x82272C00;
	sub_8255F918(ctx, base);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// vspltisw128 v63,-1
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,23536
	ctx.r9.s64 = ctx.r11.s64 + 23536;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,176
	ctx.r7.s64 = ctx.r1.s64 + 176;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// vslw128 v62,v63,v63
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v63.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_sllv_epi32(a, shift));
	}
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// ld r11,3456(r10)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r10.u32 + 3456);
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r30.u32);
	// lwz r31,-13032(r8)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r8.u32 + -13032);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// vxor128 v63,v63,v62
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v62.u8)));
	// stw r30,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r30.u32);
	// stw r30,192(r1)
	REX_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// std r11,168(r1)
	REX_STORE_U64(ctx.r1.u32 + 168, ctx.r11.u64);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r27,100(r1)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r26,116(r1)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x82272c88
	if (ctx.cr6.eq) goto loc_82272C88;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// addi r6,r27,2048
	ctx.r6.s64 = ctx.r27.s64 + 2048;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823af5b0
	ctx.lr = 0x82272C88;
	sub_823AF5B0(ctx, base);
loc_82272C88:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// clrlwi. r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f6,2232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2232);
	ctx.f6.f64 = double(temp.f32);
	// fmr f5,f6
	ctx.f5.f64 = ctx.f6.f64;
	// beq 0x82272d7c
	if (ctx.cr0.eq) goto loc_82272D7C;
	// lfs f0,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f13,172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r29,116(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r28,100(r1)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82272ce0
	if (ctx.cr6.eq) goto loc_82272CE0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ae578
	ctx.lr = 0x82272CE0;
	sub_823AE578(ctx, base);
loc_82272CE0:
	// extsw r10,r28
	ctx.r10.s64 = ctx.r28.s32;
	// add r11,r3,r29
	ctx.r11.u64 = ctx.r3.u64 + ctx.r29.u64;
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f13
	ctx.f0.f64 = double(float(ctx.f13.f64));
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
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x82272D6C;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82272D70;
	sub_82222370(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f5,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f5.f64 = double(temp.f32);
loc_82272D7C:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82272da4
	if (ctx.cr6.eq) goto loc_82272DA4;
	// li r8,3
	ctx.r8.s64 = 3;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// addi r6,r27,-2048
	ctx.r6.s64 = ctx.r27.s64 + -2048;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// addi r3,r1,160
	ctx.r3.s64 = ctx.r1.s64 + 160;
	// bl 0x823af5b0
	ctx.lr = 0x82272DA4;
	sub_823AF5B0(ctx, base);
loc_82272DA4:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// fmr f0,f6
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f6.f64;
	// beq 0x82272e8c
	if (ctx.cr0.eq) goto loc_82272E8C;
	// lfs f0,172(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 172);
	ctx.f0.f64 = double(temp.f32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,168(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 168);
	ctx.f0.f64 = double(temp.f32);
	// lwz r31,100(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f0.u64);
	// lwz r29,116(r1)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// beq cr6,0x82272df0
	if (ctx.cr6.eq) goto loc_82272DF0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x823ae2c0
	ctx.lr = 0x82272DF0;
	sub_823AE2C0(ctx, base);
loc_82272DF0:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// add r10,r3,r29
	ctx.r10.u64 = ctx.r3.u64 + ctx.r29.u64;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// lfd f0,112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lfd f13,112(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// bl 0x82322d08
	ctx.lr = 0x82272E7C;
	sub_82322D08(ctx, base);
	// bl 0x82222370
	ctx.lr = 0x82272E80;
	sub_82222370(ctx, base);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
loc_82272E8C:
	// lfs f1,0(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// fcmpu cr6,f5,f0
	ctx.cr6.compare(ctx.f5.f64, ctx.f0.f64);
	// li r6,0
	ctx.r6.s64 = 0;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r4,5
	ctx.r4.s64 = 5;
	// blt cr6,0x82272ea8
	if (ctx.cr6.lt) goto loc_82272EA8;
	// li r4,4
	ctx.r4.s64 = 4;
loc_82272EA8:
	// bl 0x8226f4b8
	ctx.lr = 0x82272EAC;
	sub_8226F4B8(ctx, base);
loc_82272EAC:
	// ld r11,96(r24)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r24.u32 + 96);
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x82322d08
	ctx.lr = 0x82272EC4;
	sub_82322D08(ctx, base);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x82222370
	ctx.lr = 0x82272ECC;
	sub_82222370(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,1604(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1604);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x82272f68
	if (ctx.cr6.lt) goto loc_82272F68;
	// stw r30,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r30.u32);
	// b 0x82272f70
	goto loc_82272F70;
loc_82272EF0:
	// cmplwi cr6,r10,1
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 1, ctx.xer);
	// bne cr6,0x82272f70
	if (!ctx.cr6.eq) goto loc_82272F70;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62380
	ctx.r11.u64 = ctx.r11.u64 | 62380;
	// lwzx r11,r24,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r24.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82272f70
	if (!ctx.cr6.eq) goto loc_82272F70;
	// addis r11,r24,1
	ctx.r11.s64 = ctx.r24.s64 + 65536;
	// addis r9,r24,1
	ctx.r9.s64 = ctx.r24.s64 + 65536;
	// addi r11,r11,-3148
	ctx.r11.s64 = ctx.r11.s64 + -3148;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r9,-3144
	ctx.r9.s64 = ctx.r9.s64 + -3144;
	// addi r10,r10,12236
	ctx.r10.s64 = ctx.r10.s64 + 12236;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f12,f0,f1
	ctx.f12.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f12,0(r11)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lfs f0,0(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f1
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f1.f64));
	// stfs f0,0(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fcmpu cr6,f12,f13
	ctx.cr6.compare(ctx.f12.f64, ctx.f13.f64);
	// ble cr6,0x82272f58
	if (!ctx.cr6.gt) goto loc_82272F58;
	// li r9,1
	ctx.r9.s64 = 1;
	// lfs f13,232(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// stw r9,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r9.u32);
loc_82272F58:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,-30128(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82272f70
	if (!ctx.cr6.gt) goto loc_82272F70;
loc_82272F68:
	// li r11,2
	ctx.r11.s64 = 2;
loc_82272F6C:
	// stw r11,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r11.u32);
loc_82272F70:
	// addi r1,r1,304
	ctx.r1.s64 = ctx.r1.s64 + 304;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822A4DD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822A4DD8;
	__savegprlr_29(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f0,0(r4)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfs f13,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r30,r11,30184
	ctx.r30.s64 = ctx.r11.s64 + 30184;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r10,r10,22072
	ctx.r10.s64 = ctx.r10.s64 + 22072;
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r11,40
	ctx.r11.s64 = 40;
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// li r5,0
	ctx.r5.s64 = 0;
	// std r9,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r9.u64);
	// li r4,112
	ctx.r4.s64 = 112;
	// lfs f0,5220(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 5220);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-12200(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -12200);
	ctx.f13.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r3,48(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 48);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stw r11,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// bl 0x825e02a0
	ctx.lr = 0x822A4E30;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x822a4e90
	if (ctx.cr0.eq) goto loc_822A4E90;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f1,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f1.f64 = double(temp.f32);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,-4740(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -4740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1072(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1072);
	ctx.f13.f64 = double(temp.f32);
	// lfs f3,3004(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3004);
	ctx.f3.f64 = double(temp.f32);
	// fadds f4,f0,f13
	ctx.f4.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f2,2076(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2076);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x8221b700
	ctx.lr = 0x822A4E68;
	sub_8221B700(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r11,r11,2712
	ctx.r11.s64 = ctx.r11.s64 + 2712;
	// addi r10,r10,8604
	ctx.r10.s64 = ctx.r10.s64 + 8604;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// lis r11,-32222
	ctx.r11.s64 = -2111700992;
	// stw r10,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r10.u32);
	// addi r11,r11,-7184
	ctx.r11.s64 = ctx.r11.s64 + -7184;
	// stw r11,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r11.u32);
	// b 0x822a4e94
	goto loc_822A4E94;
loc_822A4E90:
	// li r31,0
	ctx.r31.s64 = 0;
loc_822A4E94:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x822a4ef4
	if (ctx.cr6.eq) goto loc_822A4EF4;
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
	ctx.lr = 0x822A4EB4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x822A4EC0;
	sub_82222AD8(ctx, base);
	// addis r10,r29,1
	ctx.r10.s64 = ctx.r29.s64 + 65536;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r10,r10,-2328
	ctx.r10.s64 = ctx.r10.s64 + -2328;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x822a4ef4
	if (!ctx.cr6.eq) goto loc_822A4EF4;
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
	ctx.lr = 0x822A4EF4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_822A4EF4:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822AE968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x822AE970;
	__savegprlr_25(ctx, base);
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af24
	ctx.lr = 0x822AE978;
	__savefpr_27(ctx, base);
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r25,r3,1
	ctx.r25.s64 = ctx.r3.s64 + 65536;
	// fmr f27,f1
	ctx.fpscr.disableFlushMode();
	ctx.f27.f64 = ctx.f1.f64;
	// lis r11,0
	ctx.r11.s64 = 0;
	// addi r25,r25,-3148
	ctx.r25.s64 = ctx.r25.s64 + -3148;
	// ori r29,r11,64245
	ctx.r29.u64 = ctx.r11.u64 | 64245;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822ae9d4
	if (ctx.cr6.lt) goto loc_822AE9D4;
	// bl 0x822b1e30
	ctx.lr = 0x822AE9A4;
	sub_822B1E30(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822ae9d4
	if (ctx.cr0.eq) goto loc_822AE9D4;
	// lbzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r29.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822ae9d4
	if (ctx.cr0.eq) goto loc_822AE9D4;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// lfs f1,-2140(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f1.f64 = double(temp.f32);
loc_822AE9C4:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// li r4,14
	ctx.r4.s64 = 14;
loc_822AE9CC:
	// bl 0x822a9278
	ctx.lr = 0x822AE9D0;
	sub_822A9278(ctx, base);
	// b 0x822aef9c
	goto loc_822AEF9C;
loc_822AE9D4:
	// lwz r11,0(r25)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r25.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822aef40
	if (ctx.cr6.lt) goto loc_822AEF40;
	// beq cr6,0x822aedd4
	if (ctx.cr6.eq) goto loc_822AEDD4;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x822aed64
	if (ctx.cr6.lt) goto loc_822AED64;
	// beq cr6,0x822aecfc
	if (ctx.cr6.eq) goto loc_822AECFC;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// blt cr6,0x822aeab4
	if (ctx.cr6.lt) goto loc_822AEAB4;
	// bne cr6,0x822aef9c
	if (!ctx.cr6.eq) goto loc_822AEF9C;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822aef9c
	if (!ctx.cr0.eq) goto loc_822AEF9C;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r30,r11,14376
	ctx.r30.s64 = ctx.r11.s64 + 14376;
	// li r6,0
	ctx.r6.s64 = 0;
	// ld r11,2880(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 2880);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// lfs f31,-1908(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822AEA44;
	sub_8224A2A0(ctx, base);
	// bl 0x822b1e30
	ctx.lr = 0x822AEA48;
	sub_822B1E30(ctx, base);
	// lfs f1,-2140(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2140);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822aea84
	if (ctx.cr0.eq) goto loc_822AEA84;
	// lbzx r11,r31,r29
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r29.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822ae9c4
	if (!ctx.cr0.eq) goto loc_822AE9C4;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-1296
	ctx.r11.s64 = ctx.r11.s64 + -1296;
	// lfs f0,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// ble cr6,0x822aea88
	if (!ctx.cr6.gt) goto loc_822AEA88;
	// stfs f31,0(r11)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// li r4,13
	ctx.r4.s64 = 13;
	// b 0x822ae9cc
	goto loc_822AE9CC;
loc_822AEA84:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
loc_822AEA88:
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x822a9278
	ctx.lr = 0x822AEA90;
	sub_822A9278(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lfs f0,712(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,64184
	ctx.r11.u64 = ctx.r11.u64 | 64184;
	// ori r10,r10,64180
	ctx.r10.u64 = ctx.r10.u64 | 64180;
	// li r9,0
	ctx.r9.s64 = 0;
	// stwx r9,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r9.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// b 0x822aef9c
	goto loc_822AEF9C;
loc_822AEAB4:
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r30,r11,-4080
	ctx.r30.s64 = ctx.r11.s64 + -4080;
	// addi r28,r28,-3136
	ctx.r28.s64 = ctx.r28.s64 + -3136;
	// addi r11,r10,14376
	ctx.r11.s64 = ctx.r10.s64 + 14376;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f0,792(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 792);
	ctx.f0.f64 = double(temp.f32);
	// addi r26,r10,-6412
	ctx.r26.s64 = ctx.r10.s64 + -6412;
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lfs f29,-1908(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f29.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822aeca8
	if (ctx.cr6.lt) goto loc_822AECA8;
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// ld r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 88);
	// lfs f30,-1904(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1904);
	ctx.f30.f64 = double(temp.f32);
	// addi r29,r29,-3144
	ctx.r29.s64 = ctx.r29.s64 + -3144;
	// lfs f28,-2140(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2140);
	ctx.f28.f64 = double(temp.f32);
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822aeb14
	if (ctx.cr0.eq) goto loc_822AEB14;
	// fmr f31,f28
	ctx.f31.f64 = ctx.f28.f64;
	// b 0x822aeb18
	goto loc_822AEB18;
loc_822AEB14:
	// fmr f31,f30
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f30.f64;
loc_822AEB18:
	// lfs f2,4224(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 4224);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825a4a40
	ctx.lr = 0x822AEB28;
	sub_825A4A40(ctx, base);
	// lfs f2,7032(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 7032);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fadds f0,f1,f2
	ctx.f0.f64 = double(float(ctx.f1.f64 + ctx.f2.f64));
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmuls f31,f0,f31
	ctx.f31.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bl 0x825a4a40
	ctx.lr = 0x822AEB40;
	sub_825A4A40(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// fmuls f0,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f31,148(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8255f918
	ctx.lr = 0x822AEBA4;
	sub_8255F918(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f1,268(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 268);
	ctx.f1.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// ld r27,0(r3)
	ctx.r27.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f2,20200(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20200);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822AEBBC;
	sub_825A4A40(ctx, base);
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822aebd0
	if (ctx.cr0.eq) goto loc_822AEBD0;
	// fmr f30,f28
	ctx.f30.f64 = ctx.f28.f64;
loc_822AEBD0:
	// lfs f0,236(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f9,f0
	ctx.f1.f64 = double(float(ctx.f9.f64 + ctx.f0.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x822AEBDC;
	sub_822EA1A8(ctx, base);
	// fmuls f8,f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f8.f64 = double(float(ctx.f1.f64 * ctx.f30.f64));
	// fmr f1,f9
	ctx.f1.f64 = ctx.f9.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x822AEBE8;
	sub_822EA1A8(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f1,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f1,152(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f1,148(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f1,144(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stfs f8,144(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f8,156(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f8,152(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x8231e0d8
	ctx.lr = 0x822AEC44;
	sub_8231E0D8(ctx, base);
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ld r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// addi r10,r10,-1440
	ctx.r10.s64 = ctx.r10.s64 + -1440;
	// ori r11,r11,62404
	ctx.r11.u64 = ctx.r11.u64 | 62404;
	// lbz r8,0(r10)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// cmplwi r8,0
	ctx.cr0.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne 0x822aec94
	if (!ctx.cr0.eq) goto loc_822AEC94;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lwzx r7,r31,r11
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// lis r6,0
	ctx.r6.s64 = 0;
	// lis r5,0
	ctx.r5.s64 = 0;
	// ori r8,r8,64100
	ctx.r8.u64 = ctx.r8.u64 | 64100;
	// ori r6,r6,64108
	ctx.r6.u64 = ctx.r6.u64 | 64108;
	// ori r5,r5,64116
	ctx.r5.u64 = ctx.r5.u64 | 64116;
	// li r4,1
	ctx.r4.s64 = 1;
	// stb r4,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r4.u8);
	// stdx r27,r31,r8
	REX_STORE_U64(ctx.r31.u32 + ctx.r8.u32, ctx.r27.u64);
	// stdx r9,r31,r6
	REX_STORE_U64(ctx.r31.u32 + ctx.r6.u32, ctx.r9.u64);
	// stwx r7,r31,r5
	REX_STORE_U32(ctx.r31.u32 + ctx.r5.u32, ctx.r7.u32);
loc_822AEC94:
	// add r10,r31,r11
	ctx.r10.u64 = ctx.r31.u64 + ctx.r11.u64;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// stfs f29,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r11.u32);
loc_822AECA8:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lfs f13,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f27
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f27.f64));
	// stfs f13,0(r28)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r28.u32 + 0, temp.u32);
	// addi r11,r11,-3140
	ctx.r11.s64 = ctx.r11.s64 + -3140;
	// lfs f0,0(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f27
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f27.f64));
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822aef9c
	if (ctx.cr6.lt) goto loc_822AEF9C;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,7
	ctx.r4.s64 = 7;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822AECF4;
	sub_8224A2A0(ctx, base);
	// li r11,5
	ctx.r11.s64 = 5;
	// b 0x822aef50
	goto loc_822AEF50;
loc_822AECFC:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,73(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822aef9c
	if (!ctx.cr0.eq) goto loc_822AEF9C;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,6
	ctx.r4.s64 = 6;
	// lfs f1,-1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x8224a2a0
	ctx.lr = 0x822AED30;
	sub_8224A2A0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62400
	ctx.r11.u64 = ctx.r11.u64 | 62400;
	// ori r10,r10,62404
	ctx.r10.u64 = ctx.r10.u64 | 62404;
	// ori r9,r9,62396
	ctx.r9.u64 = ctx.r9.u64 | 62396;
	// li r8,0
	ctx.r8.s64 = 0;
	// li r7,4
	ctx.r7.s64 = 4;
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// stwx r8,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r8.u32);
	// stfsx f1,r31,r9
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// stw r7,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r7.u32);
	// b 0x822aef9c
	goto loc_822AEF9C;
loc_822AED64:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822aef9c
	if (!ctx.cr0.eq) goto loc_822AEF9C;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r11,r11,-3144
	ctx.r11.s64 = ctx.r11.s64 + -3144;
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// rlwinm r10,r10,27,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// stb r10,0(r11)
	REX_STORE_U8(ctx.r11.u32 + 0, ctx.r10.u8);
	// bl 0x822b2a28
	ctx.lr = 0x822AED98;
	sub_822B2A28(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r11,14376
	ctx.r11.s64 = ctx.r11.s64 + 14376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// lfs f1,-1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822AEDC0;
	sub_8224A2A0(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// bl 0x822b3340
	ctx.lr = 0x822AEDD0;
	sub_822B3340(ctx, base);
	// b 0x822aef9c
	goto loc_822AEF9C;
loc_822AEDD4:
	// addis r10,r31,1
	ctx.r10.s64 = ctx.r31.s64 + 65536;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r10,r10,-3140
	ctx.r10.s64 = ctx.r10.s64 + -3140;
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r3,r1,120
	ctx.r3.s64 = ctx.r1.s64 + 120;
	// addi r4,r4,-3104
	ctx.r4.s64 = ctx.r4.s64 + -3104;
	// lfs f1,14376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f1.f64 = double(temp.f32);
	// addi r29,r11,14376
	ctx.r29.s64 = ctx.r11.s64 + 14376;
	// lfs f0,0(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f2,f0,f27
	ctx.f2.f64 = double(float(ctx.f0.f64 + ctx.f27.f64));
	// stfs f2,0(r10)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// bl 0x825a5d18
	ctx.lr = 0x822AEE04;
	sub_825A5D18(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// addi r30,r31,128
	ctx.r30.s64 = ctx.r31.s64 + 128;
	// addi r28,r31,88
	ctx.r28.s64 = ctx.r31.s64 + 88;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r10,128(r31)
	REX_STORE_U32(ctx.r31.u32 + 128, ctx.r10.u32);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// stw r11,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r11.u32);
	// bl 0x822b1e88
	ctx.lr = 0x822AEE2C;
	sub_822B1E88(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// bl 0x82322d08
	ctx.lr = 0x822AEE3C;
	sub_82322D08(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825a5088
	ctx.lr = 0x822AEE44;
	sub_825A5088(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822aef9c
	if (ctx.cr0.eq) goto loc_822AEF9C;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// ld r11,2880(r9)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r9.u32 + 2880);
	// lfs f1,-1908(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// lfs f13,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f1
	ctx.cr6.compare(ctx.f13.f64, ctx.f1.f64);
	// std r11,0(r30)
	REX_STORE_U64(ctx.r30.u32 + 0, ctx.r11.u64);
	// li r11,1
	ctx.r11.s64 = 1;
	// blt cr6,0x822aee94
	if (ctx.cr6.lt) goto loc_822AEE94;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822AEE94:
	// lis r10,0
	ctx.r10.s64 = 0;
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ori r10,r10,62392
	ctx.r10.u64 = ctx.r10.u64 | 62392;
	// beq 0x822aeeb0
	if (ctx.cr0.eq) goto loc_822AEEB0;
	// lbzx r11,r31,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822aeef8
	if (!ctx.cr0.eq) goto loc_822AEEF8;
loc_822AEEB0:
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f0,156(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,1
	ctx.r11.s64 = 1;
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,144(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 144);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f1
	ctx.cr6.compare(ctx.f0.f64, ctx.f1.f64);
	// bge cr6,0x822aeee4
	if (!ctx.cr6.lt) goto loc_822AEEE4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_822AEEE4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822aef1c
	if (ctx.cr0.eq) goto loc_822AEF1C;
	// lbzx r11,r31,r10
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r10.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822aef1c
	if (!ctx.cr0.eq) goto loc_822AEF1C;
loc_822AEEF8:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822AEF14;
	sub_8224A2A0(ctx, base);
	// li r11,2
	ctx.r11.s64 = 2;
	// b 0x822aef50
	goto loc_822AEF50;
loc_822AEF1C:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822AEF38;
	sub_8224A2A0(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x822aef50
	goto loc_822AEF50;
loc_822AEF40:
	// bl 0x824281d8
	ctx.lr = 0x822AEF44;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x822aef58
	if (!ctx.cr0.eq) goto loc_822AEF58;
	// li r11,1
	ctx.r11.s64 = 1;
loc_822AEF50:
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// b 0x822aef9c
	goto loc_822AEF9C;
loc_822AEF58:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f27
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f27.f64;
	// bl 0x822b2b08
	ctx.lr = 0x822AEF64;
	sub_822B2B08(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822aef9c
	if (ctx.cr0.eq) goto loc_822AEF9C;
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// stw r11,0(r25)
	REX_STORE_U32(ctx.r25.u32 + 0, ctx.r11.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// addi r11,r9,14376
	ctx.r11.s64 = ctx.r9.s64 + 14376;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// lfs f1,-1908(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1908);
	ctx.f1.f64 = double(temp.f32);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822AEF9C;
	sub_8224A2A0(ctx, base);
loc_822AEF9C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// addi r12,r1,-64
	ctx.r12.s64 = ctx.r1.s64 + -64;
	// bl 0x8273af70
	ctx.lr = 0x822AEFA8;
	__restfpr_27(ctx, base);
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822D5C98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x822D5CA0;
	__savegprlr_26(ctx, base);
	// stfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -72, ctx.f30.u64);
	// stfd f31,-64(r1)
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r30,r3,1
	ctx.r30.s64 = ctx.r3.s64 + 65536;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r30,r30,-3156
	ctx.r30.s64 = ctx.r30.s64 + -3156;
	// lis r9,-32240
	ctx.r9.s64 = -2112880640;
	// lis r8,0
	ctx.r8.s64 = 0;
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f12,24624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24624);
	ctx.f12.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// li r27,0
	ctx.r27.s64 = 0;
	// lfs f30,12468(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12468);
	ctx.f30.f64 = double(temp.f32);
	// li r26,1
	ctx.r26.s64 = 1;
	// ori r28,r8,62388
	ctx.r28.u64 = ctx.r8.u64 | 62388;
	// ori r29,r7,62420
	ctx.r29.u64 = ctx.r7.u64 | 62420;
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// beq cr6,0x822d5df4
	if (ctx.cr6.eq) goto loc_822D5DF4;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// beq cr6,0x822d5e30
	if (ctx.cr6.eq) goto loc_822D5E30;
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// beq cr6,0x822d5e3c
	if (ctx.cr6.eq) goto loc_822D5E3C;
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// beq cr6,0x822d5ea8
	if (ctx.cr6.eq) goto loc_822D5EA8;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// beq cr6,0x822d5d54
	if (ctx.cr6.eq) goto loc_822D5D54;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// beq cr6,0x822d5da0
	if (ctx.cr6.eq) goto loc_822D5DA0;
	// cmpwi cr6,r11,8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 8, ctx.xer);
	// bne cr6,0x822d5f68
	if (!ctx.cr6.eq) goto loc_822D5F68;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r11,73(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 73);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x822d5f68
	if (!ctx.cr0.eq) goto loc_822D5F68;
	// addis r11,r3,1
	ctx.r11.s64 = ctx.r3.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d5f68
	if (!ctx.cr6.eq) goto loc_822D5F68;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x822d5f68
	goto loc_822D5F68;
loc_822D5D54:
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// addi r11,r11,-3108
	ctx.r11.s64 = ctx.r11.s64 + -3108;
	// addi r10,r10,-18544
	ctx.r10.s64 = ctx.r10.s64 + -18544;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f31,f0
	ctx.f13.f64 = double(float(ctx.f31.f64 + ctx.f0.f64));
	// lfs f0,-28332(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -28332);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,0(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// blt cr6,0x822d5f68
	if (ctx.cr6.lt) goto loc_822D5F68;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,0
	ctx.r10.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r10,r10,62440
	ctx.r10.u64 = ctx.r10.u64 | 62440;
	// li r8,7
	ctx.r8.s64 = 7;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r26,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r26.u32);
	// stwx r9,r31,r10
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, ctx.r9.u32);
	// stw r8,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r8.u32);
loc_822D5DA0:
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
	ctx.lr = 0x822D5DB8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x822d5f68
	if (ctx.cr0.eq) goto loc_822D5F68;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62388
	ctx.r11.u64 = ctx.r11.u64 | 62388;
	// lwzx r4,r31,r11
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x823bfa70
	ctx.lr = 0x822D5DD0;
	sub_823BFA70(ctx, base);
	// clrlwi r11,r3,16
	ctx.r11.u64 = ctx.r3.u32 & 0xFFFF;
	// cmplwi cr6,r11,19
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 19, ctx.xer);
	// bne cr6,0x822d5f68
	if (!ctx.cr6.eq) goto loc_822D5F68;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,8
	ctx.r10.s64 = 8;
	// ori r11,r11,62457
	ctx.r11.u64 = ctx.r11.u64 | 62457;
	// stw r10,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r10.u32);
	// stbx r26,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r26.u8);
	// b 0x822d5f68
	goto loc_822D5F68;
loc_822D5DF4:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lbz r10,73(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + 73);
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne 0x822d5f68
	if (!ctx.cr0.eq) goto loc_822D5F68;
	// stwx r27,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r27.u32);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,1
	ctx.r6.s64 = 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r5,1
	ctx.r5.s64 = 1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8224a2a0
	ctx.lr = 0x822D5E28;
	sub_8224A2A0(ctx, base);
	// li r11,3
	ctx.r11.s64 = 3;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_822D5E30:
	// li r11,4
	ctx.r11.s64 = 4;
	// stfsx f12,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_822D5E3C:
	// lfsx f0,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// fmadds f13,f31,f12,f0
	ctx.f13.f64 = double(float(std::fma(ctx.f31.f64, ctx.f12.f64, ctx.f0.f64)));
	// stfsx f13,r31,r29
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// lfs f0,12216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12216);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x822d5e60
	if (!ctx.cr6.gt) goto loc_822D5E60;
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
loc_822D5E60:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x822D5E74;
	sub_8222FF78(ctx, base);
	// addis r4,r31,1
	ctx.r4.s64 = ctx.r31.s64 + 65536;
	// addi r4,r4,-3136
	ctx.r4.s64 = ctx.r4.s64 + -3136;
	// bl 0x822d6708
	ctx.lr = 0x822D5E80;
	sub_822D6708(ctx, base);
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// lfs f0,-18544(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18544);
	ctx.f0.f64 = double(temp.f32);
	// mr r11,r26
	ctx.r11.u64 = ctx.r26.u64;
	// fcmpu cr6,f1,f0
	ctx.cr6.compare(ctx.f1.f64, ctx.f0.f64);
	// blt cr6,0x822d5e98
	if (ctx.cr6.lt) goto loc_822D5E98;
	// mr r11,r27
	ctx.r11.u64 = ctx.r27.u64;
loc_822D5E98:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822d5f68
	if (ctx.cr0.eq) goto loc_822D5F68;
	// li r11,5
	ctx.r11.s64 = 5;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
loc_822D5EA8:
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// lfsx f13,r31,r29
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r29.u32);
	ctx.f13.f64 = double(temp.f32);
	// add r11,r31,r29
	ctx.r11.u64 = ctx.r31.u64 + ctx.r29.u64;
	// lfs f0,25888(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 25888);
	ctx.f0.f64 = double(temp.f32);
	// fnmsubs f0,f0,f31,f13
	ctx.f0.f64 = double(float(-std::fma(ctx.f0.f64, ctx.f31.f64, -ctx.f13.f64)));
	// stfsx f0,r31,r29
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r29.u32, temp.u32);
	// fcmpu cr6,f0,f30
	ctx.cr6.compare(ctx.f0.f64, ctx.f30.f64);
	// bgt cr6,0x822d5f68
	if (ctx.cr6.gt) goto loc_822D5F68;
	// lis r10,0
	ctx.r10.s64 = 0;
	// stfs f30,0(r11)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// ori r11,r10,62372
	ctx.r11.u64 = ctx.r10.u64 | 62372;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// bne cr6,0x822d5efc
	if (!ctx.cr6.eq) goto loc_822D5EFC;
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3160
	ctx.r11.s64 = ctx.r11.s64 + -3160;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmpwi cr6,r10,-1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -1, ctx.xer);
	// bne cr6,0x822d5f68
	if (!ctx.cr6.eq) goto loc_822D5F68;
	// stw r27,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r27.u32);
	// b 0x822d5f68
	goto loc_822D5F68;
loc_822D5EFC:
	// li r11,6
	ctx.r11.s64 = 6;
	// stwx r26,r31,r28
	REX_STORE_U32(ctx.r31.u32 + ctx.r28.u32, ctx.r26.u32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r6,1
	ctx.r6.s64 = 1;
	// li r5,1
	ctx.r5.s64 = 1;
	// fmr f1,f30
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f30.f64;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x822D5F28;
	sub_8224A2A0(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,88
	ctx.r3.s64 = ctx.r1.s64 + 88;
	// stw r27,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r27.u32);
	// bl 0x8222ff78
	ctx.lr = 0x822D5F48;
	sub_8222FF78(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// addi r3,r11,12564
	ctx.r3.s64 = ctx.r11.s64 + 12564;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d4d8
	ctx.lr = 0x822D5F5C;
	sub_8257D4D8(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62428
	ctx.r11.u64 = ctx.r11.u64 | 62428;
	// stfsx f30,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
loc_822D5F68:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f30,-72(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -72);
	// lfd f31,-64(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822F0320) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x822F0328;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r29,-3148
	ctx.r29.s64 = ctx.r29.s64 + -3148;
	// lwz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x822f0494
	if (ctx.cr6.lt) goto loc_822F0494;
	// beq cr6,0x822f0440
	if (ctx.cr6.eq) goto loc_822F0440;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// blt cr6,0x822f036c
	if (ctx.cr6.lt) goto loc_822F036C;
	// bne cr6,0x822f04d0
	if (!ctx.cr6.eq) goto loc_822F04D0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62654
	ctx.r11.u64 = ctx.r11.u64 | 62654;
	// li r4,12
	ctx.r4.s64 = 12;
	// stbx r10,r3,r11
	REX_STORE_U8(ctx.r3.u32 + ctx.r11.u32, ctx.r10.u8);
	// b 0x822f04c8
	goto loc_822F04C8;
loc_822F036C:
	// addis r30,r31,1
	ctx.r30.s64 = ctx.r31.s64 + 65536;
	// addi r30,r30,-2880
	ctx.r30.s64 = ctx.r30.s64 + -2880;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bgt cr6,0x822f0388
	if (ctx.cr6.gt) goto loc_822F0388;
	// lwz r10,136(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 136);
loc_822F0388:
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm. r11,r11,29,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822f03a4
	if (ctx.cr0.eq) goto loc_822F03A4;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// li r11,1
	ctx.r11.s64 = 1;
	// beq cr6,0x822f03a8
	if (ctx.cr6.eq) goto loc_822F03A8;
loc_822F03A4:
	// li r11,0
	ctx.r11.s64 = 0;
loc_822F03A8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822f03f0
	if (ctx.cr0.eq) goto loc_822F03F0;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8222ff78
	ctx.lr = 0x822F03C4;
	sub_8222FF78(ctx, base);
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,161
	ctx.r3.s64 = 161;
	// li r5,0
	ctx.r5.s64 = 0;
	// bl 0x8257d438
	ctx.lr = 0x822F03D4;
	sub_8257D438(ctx, base);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3144
	ctx.r11.s64 = ctx.r11.s64 + -3144;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplwi cr6,r10,17
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 17, ctx.xer);
	// bge cr6,0x822f03f0
	if (!ctx.cr6.lt) goto loc_822F03F0;
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_822F03F0:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm. r11,r11,31,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x822f04d0
	if (ctx.cr0.eq) goto loc_822F04D0;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r10,1
	ctx.r10.s64 = 1;
	// ori r11,r11,62405
	ctx.r11.u64 = ctx.r11.u64 | 62405;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// stbx r10,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u8);
	// lfs f2,17092(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17092);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,12468(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x822F0428;
	sub_825A4A40(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r10,3
	ctx.r10.s64 = 3;
	// ori r11,r11,62416
	ctx.r11.u64 = ctx.r11.u64 | 62416;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// stfsx f1,r31,r11
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// b 0x822f04d0
	goto loc_822F04D0;
loc_822F0440:
	// lis r11,0
	ctx.r11.s64 = 0;
	// li r9,0
	ctx.r9.s64 = 0;
	// ori r11,r11,62656
	ctx.r11.u64 = ctx.r11.u64 | 62656;
	// li r8,8
	ctx.r8.s64 = 8;
	// li r7,96
	ctx.r7.s64 = 96;
	// li r6,2
	ctx.r6.s64 = 2;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stw r8,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r8.u32);
	// stw r9,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r9.u32);
	// stw r7,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r7.u32);
	// stb r9,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r9.u8);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,31,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// stw r6,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r6.u32);
	// b 0x822f04d0
	goto loc_822F04D0;
loc_822F0494:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62392
	ctx.r11.u64 = ctx.r11.u64 | 62392;
	// lwzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x822f04b0
	if (!ctx.cr6.eq) goto loc_822F04B0;
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r11,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r11.u32);
loc_822F04B0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62404
	ctx.r11.u64 = ctx.r11.u64 | 62404;
	// lbzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + ctx.r11.u32);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822f04d0
	if (ctx.cr0.eq) goto loc_822F04D0;
	// li r4,11
	ctx.r4.s64 = 11;
loc_822F04C8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x822f02a0
	ctx.lr = 0x822F04D0;
	sub_822F02A0(ctx, base);
loc_822F04D0:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_822FBC18) {
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
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// bl 0x82231670
	ctx.lr = 0x822FBC38;
	sub_82231670(ctx, base);
	// addis r9,r31,1
	ctx.r9.s64 = ctx.r31.s64 + 65536;
	// li r8,7
	ctx.r8.s64 = 7;
	// addi r9,r9,-3056
	ctx.r9.s64 = ctx.r9.s64 + -3056;
loc_822FBC44:
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x822fbc58
	if (ctx.cr6.eq) goto loc_822FBC58;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x8223ace0
	ctx.lr = 0x822FBC58;
	sub_8223ACE0(ctx, base);
loc_822FBC58:
	// addic. r8,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r8.s64 = ctx.r8.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bne 0x822fbc44
	if (!ctx.cr0.eq) goto loc_822FBC44;
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

DEFINE_REX_FUNC(sub_822FDDC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x822FDDD0;
	__savegprlr_28(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// addis r29,r3,1
	ctx.r29.s64 = ctx.r3.s64 + 65536;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r29,r29,-2996
	ctx.r29.s64 = ctx.r29.s64 + -2996;
	// li r30,0
	ctx.r30.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// lbz r11,0(r29)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r29.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x822fde7c
	if (ctx.cr0.eq) goto loc_822FDE7C;
	// addis r9,r3,1
	ctx.r9.s64 = ctx.r3.s64 + 65536;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// addi r9,r9,-3096
	ctx.r9.s64 = ctx.r9.s64 + -3096;
	// addi r6,r11,32720
	ctx.r6.s64 = ctx.r11.s64 + 32720;
	// li r8,98
	ctx.r8.s64 = 98;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r11,12
	ctx.r10.s64 = ctx.r11.s64 + 12;
	// addi r10,r11,68
	ctx.r10.s64 = ctx.r11.s64 + 68;
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stw r8,116(r11)
	REX_STORE_U32(ctx.r11.u32 + 116, ctx.r8.u32);
	// stvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r30,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r30.u32);
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// stw r30,112(r11)
	REX_STORE_U32(ctx.r11.u32 + 112, ctx.r30.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stb r28,120(r11)
	REX_STORE_U8(ctx.r11.u32 + 120, ctx.r28.u8);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// ori r10,r10,4
	ctx.r10.u64 = ctx.r10.u64 | 4;
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,31,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFFFFFFFFF1;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// lwz r11,0(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// ld r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lwz r10,72(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// rlwinm r10,r10,0,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFE;
	// stw r10,72(r11)
	REX_STORE_U32(ctx.r11.u32 + 72, ctx.r10.u32);
	// std r8,128(r3)
	REX_STORE_U64(ctx.r3.u32 + 128, ctx.r8.u64);
	// stb r30,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r30.u8);
loc_822FDE7C:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// ld r10,96(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 96);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,-13032(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x822fdec0
	if (ctx.cr6.eq) goto loc_822FDEC0;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
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
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x822FDEC0;
	sub_823AEFA8(ctx, base);
loc_822FDEC0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// clrlwi r10,r3,24
	ctx.r10.u64 = ctx.r3.u32 & 0xFF;
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// lhzx r11,r31,r11
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + ctx.r11.u32);
	// cmplw cr6,r10,r11
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x822fdf10
	if (!ctx.cr6.eq) goto loc_822FDF10;
	// lis r11,0
	ctx.r11.s64 = 0;
	// stb r28,0(r29)
	REX_STORE_U8(ctx.r29.u32 + 0, ctx.r28.u8);
	// lis r10,0
	ctx.r10.s64 = 0;
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// ori r11,r11,62536
	ctx.r11.u64 = ctx.r11.u64 | 62536;
	// lis r7,-32208
	ctx.r7.s64 = -2110783488;
	// ori r10,r10,62460
	ctx.r10.u64 = ctx.r10.u64 | 62460;
	// ori r9,r9,62472
	ctx.r9.u64 = ctx.r9.u64 | 62472;
	// addi r7,r7,-8424
	ctx.r7.s64 = ctx.r7.s64 + -8424;
	// lfs f0,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// stwx r7,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r7.u32);
	// stfsx f0,r31,r10
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r10.u32, temp.u32);
	// stbx r30,r31,r9
	REX_STORE_U8(ctx.r31.u32 + ctx.r9.u32, ctx.r30.u8);
loc_822FDF10:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823058B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823058B8;
	__savegprlr_23(ctx, base);
	// stfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f29.u64);
	// stfd f30,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f30.u64);
	// stfd f31,-88(r1)
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f31.u64);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r10,6(r3)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// addis r26,r3,1
	ctx.r26.s64 = ctx.r3.s64 + 65536;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// extsw r9,r10
	ctx.r9.s64 = ctx.r10.s32;
	// addi r26,r26,-3076
	ctx.r26.s64 = ctx.r26.s64 + -3076;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// frsp f13,f0
	ctx.f13.f64 = double(float(ctx.f0.f64));
	// lbz r9,0(r26)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r26.u32 + 0);
	// lis r8,0
	ctx.r8.s64 = 0;
	// lfs f0,-8644(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,0
	ctx.r7.s64 = 0;
	// lfs f29,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f29.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// ori r30,r8,62484
	ctx.r30.u64 = ctx.r8.u64 | 62484;
	// li r25,1
	ctx.r25.s64 = 1;
	// li r24,0
	ctx.r24.s64 = 0;
	// ori r27,r7,62440
	ctx.r27.u64 = ctx.r7.u64 | 62440;
	// addi r28,r11,-8644
	ctx.r28.s64 = ctx.r11.s64 + -8644;
	// addi r29,r10,12468
	ctx.r29.s64 = ctx.r10.s64 + 12468;
	// cmplwi r9,0
	ctx.cr0.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// fmuls f30,f13,f0
	ctx.f30.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x823059dc
	if (ctx.cr0.eq) goto loc_823059DC;
	// lwz r11,264(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 264);
	// li r7,1
	ctx.r7.s64 = 1;
	// li r6,0
	ctx.r6.s64 = 0;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,2
	ctx.r4.s64 = 2;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8224a2a0
	ctx.lr = 0x82305950;
	sub_8224A2A0(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f0,-844(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -844);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305974;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// stbx r25,r31,r30
	REX_STORE_U8(ctx.r31.u32 + ctx.r30.u32, ctx.r25.u8);
	// ori r11,r11,62485
	ctx.r11.u64 = ctx.r11.u64 | 62485;
	// stbx r24,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r24.u8);
	// bl 0x824281d8
	ctx.lr = 0x82305988;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823059c0
	if (ctx.cr0.eq) goto loc_823059C0;
	// bl 0x824281d8
	ctx.lr = 0x82305994;
	sub_824281D8(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823059d8
	if (ctx.cr0.eq) goto loc_823059D8;
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62480
	ctx.r11.u64 = ctx.r11.u64 | 62480;
	// lwzx r3,r31,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	// bl 0x82429960
	ctx.lr = 0x823059AC;
	sub_82429960(ctx, base);
	// clrlwi r23,r3,24
	ctx.r23.u64 = ctx.r3.u32 & 0xFF;
	// bl 0x8242a5e0
	ctx.lr = 0x823059B4;
	sub_8242A5E0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// cmplw cr6,r23,r11
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x823059d8
	if (!ctx.cr6.eq) goto loc_823059D8;
loc_823059C0:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfsx f0,r31,r27
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r27.u32);
	ctx.f0.f64 = double(temp.f32);
	// ori r11,r11,62556
	ctx.r11.u64 = ctx.r11.u64 | 62556;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// stfsx f0,r31,r27
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r27.u32, temp.u32);
loc_823059D8:
	// stb r24,0(r26)
	REX_STORE_U8(ctx.r26.u32 + 0, ctx.r24.u8);
loc_823059DC:
	// add r27,r31,r27
	ctx.r27.u64 = ctx.r31.u64 + ctx.r27.u64;
	// lfs f13,1812(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1812);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// fadds f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f0,0(r27)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82305ad4
	if (!ctx.cr6.lt) goto loc_82305AD4;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82305f58
	if (!ctx.cr6.eq) goto loc_82305F58;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305A24;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,-16668(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -16668);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfsx f13,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305A9C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r11,-32624
	ctx.r11.s64 = ctx.r11.s64 + -32624;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lfs f1,1812(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 1812);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// b 0x82305cc4
	goto loc_82305CC4;
loc_82305AD4:
	// lfs f13,3188(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3188);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82305bd8
	if (!ctx.cr6.lt) goto loc_82305BD8;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82305f58
	if (!ctx.cr0.eq) goto loc_82305F58;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305B0C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,-16668(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -16668);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfsx f12,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305B84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r10,r10,-29552
	ctx.r10.s64 = ctx.r10.s64 + -29552;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f1,3188(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 3188);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x82308308
	ctx.lr = 0x82305BD4;
	sub_82308308(ctx, base);
	// b 0x82305df0
	goto loc_82305DF0;
loc_82305BD8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r29,r11,18652
	ctx.r29.s64 = ctx.r11.s64 + 18652;
	// lfs f13,-14212(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -14212);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82305ce4
	if (!ctx.cr6.lt) goto loc_82305CE4;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82305f58
	if (!ctx.cr6.eq) goto loc_82305F58;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305C18;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,-1368(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1368);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfsx f12,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
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
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305C90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r10,r10,-32416
	ctx.r10.s64 = ctx.r10.s64 + -32416;
	// lfs f1,-14212(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -14212);
	ctx.f1.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
loc_82305CC4:
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// li r6,4
	ctx.r6.s64 = 4;
	// bl 0x82308308
	ctx.lr = 0x82305CE0;
	sub_82308308(ctx, base);
	// b 0x82305ef0
	goto loc_82305EF0;
loc_82305CE4:
	// lfs f13,-272(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -272);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82305df8
	if (!ctx.cr6.lt) goto loc_82305DF8;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82305f58
	if (!ctx.cr0.eq) goto loc_82305F58;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305D1C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f13,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r11,0
	ctx.r11.s64 = 0;
	// lfs f0,-1368(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1368);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lfsx f12,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
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
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305D94;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r6,20
	ctx.r6.s64 = 20;
	// addi r10,r10,-32416
	ctx.r10.s64 = ctx.r10.s64 + -32416;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lfs f1,-272(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -272);
	ctx.f1.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x82308308
	ctx.lr = 0x82305DE4;
	sub_82308308(ctx, base);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r24,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r24.u32);
loc_82305DF0:
	// stb r25,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r25.u8);
	// b 0x82305f58
	goto loc_82305F58;
loc_82305DF8:
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x82305ef8
	if (!ctx.cr6.lt) goto loc_82305EF8;
	// add r30,r31,r30
	ctx.r30.u64 = ctx.r31.u64 + ctx.r30.u64;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82305f58
	if (!ctx.cr6.eq) goto loc_82305F58;
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305E30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lfs f0,-1368(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + -1368);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// ori r11,r11,62448
	ctx.r11.u64 = ctx.r11.u64 | 62448;
	// lfs f13,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lwz r4,0(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// lfsx f12,r31,r11
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + ctx.r11.u32);
	ctx.f12.f64 = double(temp.f32);
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,0(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 0);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lwz r11,72(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 72);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
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
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// bctrl 
	ctx.lr = 0x82305EA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32224
	ctx.r11.s64 = -2111832064;
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r11,r11,-32416
	ctx.r11.s64 = ctx.r11.s64 + -32416;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// bl 0x823083f8
	ctx.lr = 0x82305EF0;
	sub_823083F8(ctx, base);
loc_82305EF0:
	// stb r24,0(r30)
	REX_STORE_U8(ctx.r30.u32 + 0, ctx.r24.u8);
	// b 0x82305f58
	goto loc_82305F58;
loc_82305EF8:
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lfs f0,-848(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -848);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f0,f30
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f30.f64));
	// stw r25,76(r11)
	REX_STORE_U32(ctx.r11.u32 + 76, ctx.r25.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82305F28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addis r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 65536;
	// addi r11,r11,-3080
	ctx.r11.s64 = ctx.r11.s64 + -3080;
	// lis r10,-32208
	ctx.r10.s64 = -2110783488;
	// addi r10,r10,19392
	ctx.r10.s64 = ctx.r10.s64 + 19392;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r9,r10
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r10.u32, ctx.xer);
	// beq cr6,0x82305f58
	if (ctx.cr6.eq) goto loc_82305F58;
	// lis r10,-32208
	ctx.r10.s64 = -2110783488;
	// stfs f29,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r27.u32 + 0, temp.u32);
	// stb r25,0(r26)
	REX_STORE_U8(ctx.r26.u32 + 0, ctx.r25.u8);
	// addi r10,r10,19392
	ctx.r10.s64 = ctx.r10.s64 + 19392;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
loc_82305F58:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// lfd f29,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f30,-96(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// lfd f31,-88(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82341AE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82341AF0;
	__savegprlr_28(ctx, base);
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af28
	ctx.lr = 0x82341AF8;
	__savefpr_28(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
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
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x82341B24;
	sub_8222FF78(ctx, base);
	// addis r28,r31,1
	ctx.r28.s64 = ctx.r31.s64 + 65536;
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// lfs f0,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r28,r28,-3160
	ctx.r28.s64 = ctx.r28.s64 + -3160;
	// stfs f28,124(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f28,120(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f28,116(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f28,112(r1)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lfs f13,0(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,140(r1)
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// vcmpgefp128. v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82341db8
	if (ctx.cr0.eq) goto loc_82341DB8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x82341BA4;
	sub_8222FF78(ctx, base);
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lfs f0,0(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,124(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f31,112(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f31,120(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f31,116(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82341db8
	if (ctx.cr0.eq) goto loc_82341DB8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x82341C1C;
	sub_8222FF78(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addis r29,r31,1
	ctx.r29.s64 = ctx.r31.s64 + 65536;
	// stfs f30,140(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f30,136(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r29,r29,-3156
	ctx.r29.s64 = ctx.r29.s64 + -3156;
	// stfs f30,132(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f30,128(r1)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82341db8
	if (ctx.cr0.eq) goto loc_82341DB8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8222ff78
	ctx.lr = 0x82341C9C;
	sub_8222FF78(ctx, base);
	// lfs f0,4(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f29,116(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f29,112(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f29,124(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f29,120(r1)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgefp128. v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpge_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82341db8
	if (ctx.cr0.eq) goto loc_82341DB8;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8222ff78
	ctx.lr = 0x82341D14;
	sub_8222FF78(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// lfs f31,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f31.f64 = double(temp.f32);
	// bl 0x8222ff78
	ctx.lr = 0x82341D30;
	sub_8222FF78(ctx, base);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// li r30,0
	ctx.r30.s64 = 0;
	// lwz r31,-13032(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + -13032);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82341d6c
	if (ctx.cr6.eq) goto loc_82341D6C;
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
	ctx.lr = 0x82341D68;
	sub_823AEFA8(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_82341D6C:
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82341da0
	if (ctx.cr6.eq) goto loc_82341DA0;
	// lfs f0,0(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f0.u64);
	// lfs f0,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// bl 0x823aefa8
	ctx.lr = 0x82341DA0;
	sub_823AEFA8(ctx, base);
loc_82341DA0:
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
	// b 0x82341dbc
	goto loc_82341DBC;
loc_82341DB8:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82341DBC:
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-40
	ctx.r12.s64 = ctx.r1.s64 + -40;
	// bl 0x8273af74
	ctx.lr = 0x82341DC8;
	__restfpr_28(ctx, base);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8235AD40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x8235AD48;
	__savegprlr_26(ctx, base);
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273aef0
	ctx.lr = 0x8235AD50;
	__savefpr_14(ctx, base);
	// stwu r1,-816(r1)
	ea = -816 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82237858
	ctx.lr = 0x8235AD5C;
	sub_82237858(ctx, base);
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r10,264(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235ad8c
	if (ctx.cr0.eq) goto loc_8235AD8C;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
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
	ctx.lr = 0x8235AD8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8235AD8C:
	// lwz r11,252(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 252);
	// lwz r10,248(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235adbc
	if (ctx.cr0.eq) goto loc_8235ADBC;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
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
	ctx.lr = 0x8235ADBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8235ADBC:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// li r28,1
	ctx.r28.s64 = 1;
	// ori r11,r11,62396
	ctx.r11.u64 = ctx.r11.u64 | 62396;
	// stb r28,21(r31)
	REX_STORE_U8(ctx.r31.u32 + 21, ctx.r28.u8);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,68(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 68);
	// stbx r28,r31,r11
	REX_STORE_U8(ctx.r31.u32 + ctx.r11.u32, ctx.r28.u8);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8235ADE8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,264(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 264);
	// addis r27,r31,1
	ctx.r27.s64 = ctx.r31.s64 + 65536;
	// addi r27,r27,-3136
	ctx.r27.s64 = ctx.r27.s64 + -3136;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,116(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 116);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8235AE08;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r9,248(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// li r10,5
	ctx.r10.s64 = 5;
	// stw r3,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r3.u32);
	// ori r11,r11,62372
	ctx.r11.u64 = ctx.r11.u64 | 62372;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lis r6,-32224
	ctx.r6.s64 = -2111832064;
	// li r30,0
	ctx.r30.s64 = 0;
	// stwx r10,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r10.u32);
	// lfs f0,448(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// lwz r3,0(r9)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r11,r6,-32768
	ctx.r11.s64 = ctx.r6.s64 + -32768;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,92(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r10,168(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 168);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v61,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v62.f32)));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// vcmpgtfp128. v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// bctrl 
	ctx.lr = 0x8235AE84;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// addi r11,r11,13168
	ctx.r11.s64 = ctx.r11.s64 + 13168;
	// lfs f21,-700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -700);
	ctx.f21.f64 = double(temp.f32);
	// lfs f14,-932(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -932);
	ctx.f14.f64 = double(temp.f32);
	// beq 0x8235b3a8
	if (ctx.cr0.eq) goto loc_8235B3A8;
	// lfs f29,1208(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1208);
	ctx.f29.f64 = double(temp.f32);
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// lfs f19,-696(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -696);
	ctx.f19.f64 = double(temp.f32);
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// lfs f18,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f18.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r8,r10,1612
	ctx.r8.s64 = ctx.r10.s64 + 1612;
	// addi r7,r11,-4080
	ctx.r7.s64 = ctx.r11.s64 + -4080;
	// addi r6,r9,32240
	ctx.r6.s64 = ctx.r9.s64 + 32240;
	// lfs f22,1612(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1612);
	ctx.f22.f64 = double(temp.f32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lfs f25,32240(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 32240);
	ctx.f25.f64 = double(temp.f32);
	// addi r29,r31,436
	ctx.r29.s64 = ctx.r31.s64 + 436;
	// lfs f30,15496(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 15496);
	ctx.f30.f64 = double(temp.f32);
	// addi r26,r11,32720
	ctx.r26.s64 = ctx.r11.s64 + 32720;
	// lfs f24,-12752(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -12752);
	ctx.f24.f64 = double(temp.f32);
	// lfs f28,1244(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 1244);
	ctx.f28.f64 = double(temp.f32);
	// lfs f23,15672(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 15672);
	ctx.f23.f64 = double(temp.f32);
	// lfs f20,2956(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2956);
	ctx.f20.f64 = double(temp.f32);
	// lfs f27,2952(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 2952);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,1140(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 1140);
	ctx.f26.f64 = double(temp.f32);
	// lfs f16,796(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 796);
	ctx.f16.f64 = double(temp.f32);
	// lfs f15,144(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 144);
	ctx.f15.f64 = double(temp.f32);
loc_8235AEF8:
	// addi r11,r30,15604
	ctx.r11.s64 = ctx.r30.s64 + 15604;
	// fmr f2,f15
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f15.f64;
	// li r10,255
	ctx.r10.s64 = 255;
	// fmr f1,f16
	ctx.f1.f64 = ctx.f16.f64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,0
	ctx.r5.s64 = 0;
	// stwx r10,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r10.u32);
	// bl 0x825a4a40
	ctx.lr = 0x8235AF18;
	sub_825A4A40(ctx, base);
	// fmr f17,f1
	ctx.fpscr.disableFlushMode();
	ctx.f17.f64 = ctx.f1.f64;
	// cmplwi cr6,r30,4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 4, ctx.xer);
	// beq cr6,0x8235b2b4
	if (ctx.cr6.eq) goto loc_8235B2B4;
	// lfs f0,460(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 460);
	ctx.f0.f64 = double(temp.f32);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// fcmpu cr6,f0,f21
	ctx.cr6.compare(ctx.f0.f64, ctx.f21.f64);
	// bne cr6,0x8235b084
	if (!ctx.cr6.eq) goto loc_8235B084;
	// addi r3,r1,608
	ctx.r3.s64 = ctx.r1.s64 + 608;
	// bl 0x8231e0d8
	ctx.lr = 0x8235AF3C;
	sub_8231E0D8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r1,224
	ctx.r11.s64 = ctx.r1.s64 + 224;
	// addi r10,r1,528
	ctx.r10.s64 = ctx.r1.s64 + 528;
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,528(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 528);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f21
	ctx.cr6.compare(ctx.f0.f64, ctx.f21.f64);
	// bgt cr6,0x8235af84
	if (ctx.cr6.gt) goto loc_8235AF84;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235AF84:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq 0x8235af9c
	if (ctx.cr0.eq) goto loc_8235AF9C;
	// fmr f2,f30
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f30.f64;
	// fmr f1,f27
	ctx.f1.f64 = ctx.f27.f64;
	// b 0x8235afa4
	goto loc_8235AFA4;
loc_8235AF9C:
	// fmr f2,f28
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f28.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
loc_8235AFA4:
	// bl 0x825a4a40
	ctx.lr = 0x8235AFA8;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f2,f23
	ctx.f2.f64 = ctx.f23.f64;
	// fmr f1,f24
	ctx.f1.f64 = ctx.f24.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8235AFBC;
	sub_825A4A40(ctx, base);
	// addi r11,r1,304
	ctx.r11.s64 = ctx.r1.s64 + 304;
	// stfs f31,308(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 308, temp.u32);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// stfs f31,316(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 316, temp.u32);
	// stfs f31,312(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 312, temp.u32);
	// stfs f31,304(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 304, temp.u32);
	// fmr f31,f1
	ctx.f31.f64 = ctx.f1.f64;
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x8235AFE0;
	sub_8221ADA0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// addi r3,r1,368
	ctx.r3.s64 = ctx.r1.s64 + 368;
	// bl 0x823bcf40
	ctx.lr = 0x8235AFF0;
	sub_823BCF40(ctx, base);
	// addi r4,r1,368
	ctx.r4.s64 = ctx.r1.s64 + 368;
	// addi r3,r1,408
	ctx.r3.s64 = ctx.r1.s64 + 408;
	// bl 0x8231e0d8
	ctx.lr = 0x8235AFFC;
	sub_8231E0D8(ctx, base);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// stfs f31,284(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f31,280(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// stfs f31,276(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// addi r8,r1,464
	ctx.r8.s64 = ctx.r1.s64 + 464;
	// stfs f31,272(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// addi r7,r1,192
	ctx.r7.s64 = ctx.r1.s64 + 192;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,348(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 348, temp.u32);
	// addi r11,r1,592
	ctx.r11.s64 = ctx.r1.s64 + 592;
	// stfs f13,344(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 344, temp.u32);
	// stfs f13,340(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 340, temp.u32);
	// stfs f13,336(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 336, temp.u32);
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
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,464(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 464);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,592(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 592);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// ld r11,128(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// b 0x8235b228
	goto loc_8235B228;
loc_8235B084:
	// addi r3,r1,432
	ctx.r3.s64 = ctx.r1.s64 + 432;
	// fmr f10,f14
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f14.f64;
	// bl 0x8231e0d8
	ctx.lr = 0x8235B090;
	sub_8231E0D8(ctx, base);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// addi r10,r1,496
	ctx.r10.s64 = ctx.r1.s64 + 496;
	// stw r9,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r9.u32);
	// lwz r9,4(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// lfs f0,440(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 440);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,496(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 496);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f21
	ctx.cr6.compare(ctx.f0.f64, ctx.f21.f64);
	// bgt cr6,0x8235b0d8
	if (ctx.cr6.gt) goto loc_8235B0D8;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235B0D8:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235b0e4
	if (ctx.cr0.eq) goto loc_8235B0E4;
	// fmr f10,f29
	ctx.fpscr.disableFlushMode();
	ctx.f10.f64 = ctx.f29.f64;
loc_8235B0E4:
	// addi r11,r1,256
	ctx.r11.s64 = ctx.r1.s64 + 256;
	// lfs f0,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// addi r10,r1,560
	ctx.r10.s64 = ctx.r1.s64 + 560;
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// stfs f0,268(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,560(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 560);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f21
	ctx.cr6.compare(ctx.f0.f64, ctx.f21.f64);
	// bgt cr6,0x8235b11c
	if (ctx.cr6.gt) goto loc_8235B11C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235B11C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r5,0
	ctx.r5.s64 = 0;
	// beq 0x8235b134
	if (ctx.cr0.eq) goto loc_8235B134;
	// fmuls f2,f10,f20
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f20.f64));
	// fmuls f1,f10,f27
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f27.f64));
	// b 0x8235b13c
	goto loc_8235B13C;
loc_8235B134:
	// fmuls f2,f10,f28
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = double(float(ctx.f10.f64 * ctx.f28.f64));
	// fmuls f1,f10,f30
	ctx.f1.f64 = double(float(ctx.f10.f64 * ctx.f30.f64));
loc_8235B13C:
	// bl 0x825a4a40
	ctx.lr = 0x8235B140;
	sub_825A4A40(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// fmr f2,f22
	ctx.f2.f64 = ctx.f22.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8235B154;
	sub_825A4A40(ctx, base);
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// stfs f31,148(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f31,144(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// addi r3,r1,384
	ctx.r3.s64 = ctx.r1.s64 + 384;
	// stfs f31,156(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// fmr f0,f1
	ctx.f0.f64 = ctx.f1.f64;
	// stfs f31,152(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f1,80(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x8221ada0
	ctx.lr = 0x8235B17C;
	sub_8221ADA0(ctx, base);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// addi r4,r1,384
	ctx.r4.s64 = ctx.r1.s64 + 384;
	// addi r3,r1,376
	ctx.r3.s64 = ctx.r1.s64 + 376;
	// bl 0x823bcf40
	ctx.lr = 0x8235B18C;
	sub_823BCF40(ctx, base);
	// addi r4,r1,376
	ctx.r4.s64 = ctx.r1.s64 + 376;
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// bl 0x8231e0d8
	ctx.lr = 0x8235B198;
	sub_8231E0D8(ctx, base);
	// ld r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// lfs f13,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,288
	ctx.r8.s64 = ctx.r1.s64 + 288;
	// lfs f0,460(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 460);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,160
	ctx.r9.s64 = ctx.r1.s64 + 160;
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,300(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 300, temp.u32);
	// stfs f0,296(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 296, temp.u32);
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// stfs f0,292(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 292, temp.u32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// stfs f0,288(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 288, temp.u32);
	// addi r11,r1,416
	ctx.r11.s64 = ctx.r1.s64 + 416;
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r7,r1,448
	ctx.r7.s64 = ctx.r1.s64 + 448;
	// lfs f13,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,328(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 328, temp.u32);
	// stfs f0,324(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 324, temp.u32);
	// stfs f0,320(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 320, temp.u32);
	// stfs f0,332(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 332, temp.u32);
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,416(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 416);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v61,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,116(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f0,448(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 448);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
loc_8235B228:
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r11,r1,176
	ctx.r11.s64 = ctx.r1.s64 + 176;
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,480
	ctx.r10.s64 = ctx.r1.s64 + 480;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fmr f13,f14
	ctx.f13.f64 = ctx.f14.f64;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,480(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 480);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f21
	ctx.cr6.compare(ctx.f0.f64, ctx.f21.f64);
	// bgt cr6,0x8235b268
	if (ctx.cr6.gt) goto loc_8235B268;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235B268:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235b274
	if (ctx.cr0.eq) goto loc_8235B274;
	// fmr f13,f19
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f19.f64;
loc_8235B274:
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r5,0(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// fmr f2,f29
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f29.f64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// fmuls f1,f13,f17
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f17.f64));
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82237bb0
	ctx.lr = 0x8235B294;
	sub_82237BB0(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// li r3,4
	ctx.r3.s64 = 4;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a49b0
	ctx.lr = 0x8235B2A4;
	sub_825A49B0(ctx, base);
	// addi r11,r30,15610
	ctx.r11.s64 = ctx.r30.s64 + 15610;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// stwx r3,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r3.u32);
	// b 0x8235b384
	goto loc_8235B384;
loc_8235B2B4:
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f2,f26
	ctx.fpscr.disableFlushMode();
	ctx.f2.f64 = ctx.f26.f64;
	// fmr f1,f25
	ctx.f1.f64 = ctx.f25.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8235B2C4;
	sub_825A4A40(ctx, base);
	// addi r11,r1,352
	ctx.r11.s64 = ctx.r1.s64 + 352;
	// lfs f13,0(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,356(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 356, temp.u32);
	// addi r10,r1,512
	ctx.r10.s64 = ctx.r1.s64 + 512;
	// stfs f13,352(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 352, temp.u32);
	// fmr f0,f14
	ctx.f0.f64 = ctx.f14.f64;
	// stfs f13,364(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 364, temp.u32);
	// stfs f13,360(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 360, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// mr r11,r28
	ctx.r11.u64 = ctx.r28.u64;
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,512(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 512);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f21
	ctx.cr6.compare(ctx.f13.f64, ctx.f21.f64);
	// bgt cr6,0x8235b300
	if (ctx.cr6.gt) goto loc_8235B300;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8235B300:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8235b30c
	if (ctx.cr0.eq) goto loc_8235B30C;
	// fmr f0,f19
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = ctx.f19.f64;
loc_8235B30C:
	// addi r11,r1,240
	ctx.r11.s64 = ctx.r1.s64 + 240;
	// stfs f1,252(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// stfs f1,248(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// addi r10,r1,544
	ctx.r10.s64 = ctx.r1.s64 + 544;
	// stfs f1,244(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// addi r8,r1,576
	ctx.r8.s64 = ctx.r1.s64 + 576;
	// stfs f1,240(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// fmuls f1,f0,f17
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f17.f64));
	// lvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r6,r1,120
	ctx.r6.s64 = ctx.r1.s64 + 120;
	// lwz r5,0(r27)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r27.u32 + 0);
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r4,4
	ctx.r4.s64 = 4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f2,f18
	ctx.f2.f64 = ctx.f18.f64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,544(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 544);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f0,576(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 576);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// bl 0x82237bb0
	ctx.lr = 0x8235B368;
	sub_82237BB0(ctx, base);
	// li r4,8
	ctx.r4.s64 = 8;
	// li r3,4
	ctx.r3.s64 = 4;
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a49b0
	ctx.lr = 0x8235B378;
	sub_825A49B0(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r11,r11,62456
	ctx.r11.u64 = ctx.r11.u64 | 62456;
	// stwx r3,r31,r11
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, ctx.r3.u32);
loc_8235B384:
	// lwz r11,248(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 248);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,168(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 168);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8235B3A0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmplw cr6,r30,r3
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r3.u32, ctx.xer);
	// blt cr6,0x8235aef8
	if (ctx.cr6.lt) goto loc_8235AEF8;
loc_8235B3A8:
	// lis r11,0
	ctx.r11.s64 = 0;
	// stb r28,588(r31)
	REX_STORE_U8(ctx.r31.u32 + 588, ctx.r28.u8);
	// lis r9,0
	ctx.r9.s64 = 0;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// ori r11,r11,62292
	ctx.r11.u64 = ctx.r11.u64 | 62292;
	// ori r9,r9,62464
	ctx.r9.u64 = ctx.r9.u64 | 62464;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f0,-20940(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20940);
	ctx.f0.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// stfsx f0,r31,r11
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r11.u32, temp.u32);
	// addi r4,r31,88
	ctx.r4.s64 = ctx.r31.s64 + 88;
	// stfsx f14,r31,r9
	temp.f32 = float(ctx.f14.f64);
	REX_STORE_U32(ctx.r31.u32 + ctx.r9.u32, temp.u32);
	// addi r3,r10,13376
	ctx.r3.s64 = ctx.r10.s64 + 13376;
	// ld r11,2880(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 2880);
	// stfs f21,288(r31)
	temp.f32 = float(ctx.f21.f64);
	REX_STORE_U32(ctx.r31.u32 + 288, temp.u32);
	// std r11,128(r31)
	REX_STORE_U64(ctx.r31.u32 + 128, ctx.r11.u64);
	// bl 0x8257d4d8
	ctx.lr = 0x8235B3F0;
	sub_8257D4D8(ctx, base);
	// addi r1,r1,816
	ctx.r1.s64 = ctx.r1.s64 + 816;
	// addi r12,r1,-56
	ctx.r12.s64 = ctx.r1.s64 + -56;
	// bl 0x8273af3c
	ctx.lr = 0x8235B3FC;
	__restfpr_14(ctx, base);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823879B8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x823879C0;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af20
	ctx.lr = 0x823879C8;
	__savefpr_26(ctx, base);
	// stwu r1,-224(r1)
	ea = -224 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,48
	ctx.r10.s64 = 48;
	// addi r30,r11,14376
	ctx.r30.s64 = ctx.r11.s64 + 14376;
	// li r29,0
	ctx.r29.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,24(r3)
	REX_STORE_U32(ctx.r3.u32 + 24, ctx.r29.u32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stvx128 v63,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f30,-1908(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -1908);
	ctx.f30.f64 = double(temp.f32);
	// stfs f30,32(r3)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r3.u32 + 32, temp.u32);
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// lfs f29,-2140(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -2140);
	ctx.f29.f64 = double(temp.f32);
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82387A08;
	sub_825A4A40(ctx, base);
	// lfs f28,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f28.f64 = double(temp.f32);
	// fcmpu cr6,f1,f28
	ctx.cr6.compare(ctx.f1.f64, ctx.f28.f64);
	// ble cr6,0x82387a1c
	if (!ctx.cr6.gt) goto loc_82387A1C;
	// lfs f31,108(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f31.f64 = double(temp.f32);
	// b 0x82387a24
	goto loc_82387A24;
loc_82387A1C:
	// lfs f0,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f0.f64 = double(temp.f32);
	// fneg f31,f0
	ctx.f31.u64 = ctx.f0.u64 ^ 0x8000000000000000;
loc_82387A24:
	// lis r28,-32115
	ctx.r28.s64 = -2104688640;
	// lis r27,-32115
	ctx.r27.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,30348(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 30348);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,30344(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 30344);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82387A3C;
	sub_825A4A40(ctx, base);
	// lfs f0,30344(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 30344);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f27,f1
	ctx.f27.f64 = ctx.f1.f64;
	// lfs f2,30348(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 30348);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82387A54;
	sub_825A4A40(ctx, base);
	// lfs f0,30344(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 30344);
	ctx.f0.f64 = double(temp.f32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f26,f1
	ctx.f26.f64 = ctx.f1.f64;
	// lfs f2,30348(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 30348);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f0
	ctx.f1.f64 = ctx.f0.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82387A6C;
	sub_825A4A40(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stfs f26,92(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f26,88(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f26,84(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f26,80(r1)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f31,108(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r9,32720
	ctx.r9.s64 = ctx.r9.s64 + 32720;
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f31,104(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// li r7,64
	ctx.r7.s64 = 64;
	// stfs f31,100(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// li r6,80
	ctx.r6.s64 = 80;
	// stfs f31,96(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r28,-32228
	ctx.r28.s64 = -2112094208;
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,0
	ctx.r5.s64 = 0;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32227
	ctx.r9.s64 = -2112028672;
	// vor128 v63,v61,v61
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_load_si128((simde__m128i*)ctx.v61.u8));
	// stfs f1,124(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f1,120(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r4,r28,19212
	ctx.r4.s64 = ctx.r28.s64 + 19212;
	// stfs f1,116(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f1,112(r1)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// vmrghw128 v60,v63,v61
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v63.u32)));
	// stfs f27,92(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f27,88(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f27,84(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f27,80(r1)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v59,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmrghw128 v59,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v63,v62,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// lfs f2,20196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 20196);
	ctx.f2.f64 = double(temp.f32);
	// vmrghw128 v62,v58,v61
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), simde_mm_load_si128((simde__m128i*)ctx.v58.u32)));
	// lfs f1,-8096(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + -8096);
	ctx.f1.f64 = double(temp.f32);
	// vmrghw128 v63,v59,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), simde_mm_load_si128((simde__m128i*)ctx.v59.u32)));
	// vmrghw128 v62,v62,v60
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_unpackhi_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), simde_mm_load_si128((simde__m128i*)ctx.v62.u32)));
	// stvx128 v63,r31,r6
	ea = (ctx.r31.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r31,r7
	ea = (ctx.r31.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825a4a40
	ctx.lr = 0x82387B20;
	sub_825A4A40(ctx, base);
	// stfs f1,96(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// lfs f2,-96(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + -96);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,19212(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 19212);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x82387B34;
	sub_825A4A40(ctx, base);
	// stfs f1,100(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// fmr f2,f29
	ctx.f2.f64 = ctx.f29.f64;
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// bl 0x825a4a40
	ctx.lr = 0x82387B48;
	sub_825A4A40(ctx, base);
	// fcmpu cr6,f1,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f1.f64, ctx.f28.f64);
	// ble cr6,0x82387b68
	if (!ctx.cr6.gt) goto loc_82387B68;
	// lfs f0,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,100(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 100);
	ctx.f13.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// fneg f13,f13
	ctx.f13.u64 = ctx.f13.u64 ^ 0x8000000000000000;
	// stfs f0,96(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 96, temp.u32);
	// stfs f13,100(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 100, temp.u32);
loc_82387B68:
	// lwz r30,116(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 116);
	// lwz r28,120(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// b 0x82387b8c
	goto loc_82387B8C;
loc_82387B74:
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lwz r4,0(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82387d08
	ctx.lr = 0x82387B84;
	sub_82387D08(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
loc_82387B8C:
	// cmplw cr6,r30,r28
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82387b74
	if (!ctx.cr6.eq) goto loc_82387B74;
	// addi r1,r1,224
	ctx.r1.s64 = ctx.r1.s64 + 224;
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af6c
	ctx.lr = 0x82387BA0;
	__restfpr_26(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82396E48) {
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
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r3,256
	ctx.r3.s64 = ctx.r3.s64 + 256;
	// addi r11,r11,28384
	ctx.r11.s64 = ctx.r11.s64 + 28384;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// bl 0x823edfb8
	ctx.lr = 0x82396E70;
	sub_823EDFB8(ctx, base);
	// lwz r3,256(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 256);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82396e80
	if (ctx.cr6.eq) goto loc_82396E80;
	// bl 0x825e0378
	ctx.lr = 0x82396E80;
	sub_825E0378(ctx, base);
loc_82396E80:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8235f568
	ctx.lr = 0x82396E88;
	sub_8235F568(ctx, base);
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

DEFINE_REX_FUNC(sub_82399C10) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82399C18;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
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
	// li r4,456
	ctx.r4.s64 = 456;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82399C40;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82399c5c
	if (ctx.cr0.eq) goto loc_82399C5C;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x82399c68
	ctx.lr = 0x82399C58;
	sub_82399C68(ctx, base);
	// b 0x82399c60
	goto loc_82399C60;
loc_82399C5C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82399C60:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8239D488) {
	REX_FUNC_PROLOGUE();
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,29116
	ctx.r3.s64 = ctx.r11.s64 + 29116;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8239D778) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8239D780;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,8
	ctx.r31.s64 = 8;
	// addi r29,r11,29024
	ctx.r29.s64 = ctx.r11.s64 + 29024;
loc_8239D794:
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8235fc38
	ctx.lr = 0x8239D7A0;
	sub_8235FC38(ctx, base);
	// addic. r31,r31,-1
	ctx.xer.ca = ctx.r31.u32 > 0;
	ctx.r31.s64 = ctx.r31.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x8239d794
	if (!ctx.cr0.eq) goto loc_8239D794;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,29060
	ctx.r3.s64 = ctx.r11.s64 + 29060;
	// bl 0x825995a0
	ctx.lr = 0x8239D7B4;
	sub_825995A0(ctx, base);
	// stw r3,336(r30)
	REX_STORE_U32(ctx.r30.u32 + 336, ctx.r3.u32);
	// cmpwi cr6,r3,-1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, -1, ctx.xer);
	// beq cr6,0x8239d7d0
	if (ctx.cr6.eq) goto loc_8239D7D0;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r3,r11,29100
	ctx.r3.s64 = ctx.r11.s64 + 29100;
	// bl 0x8259b620
	ctx.lr = 0x8239D7CC;
	sub_8259B620(ctx, base);
	// stw r3,340(r30)
	REX_STORE_U32(ctx.r30.u32 + 340, ctx.r3.u32);
loc_8239D7D0:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// li r4,12
	ctx.r4.s64 = 12;
	// addi r3,r10,1368
	ctx.r3.s64 = ctx.r10.s64 + 1368;
	// lwz r11,-15508(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -15508);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8239D7EC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x8239D7F0;
	sub_8245A220(ctx, base);
	// stw r3,344(r30)
	REX_STORE_U32(ctx.r30.u32 + 344, ctx.r3.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823A1C50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x823A1C58;
	__savegprlr_23(ctx, base);
	// stwu r1,-368(r1)
	ea = -368 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,76(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 76);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A1C70;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823a20f8
	if (ctx.cr0.eq) goto loc_823A20F8;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,84(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A1C8C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x823a20f8
	if (ctx.cr0.eq) goto loc_823A20F8;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r11,80(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823A1CA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// li r27,-1
	ctx.r27.s64 = -1;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// addi r30,r31,264
	ctx.r30.s64 = ctx.r31.s64 + 264;
	// rlwinm r26,r11,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// li r28,2
	ctx.r28.s64 = 2;
	// li r25,1
	ctx.r25.s64 = 1;
	// lis r29,-32112
	ctx.r29.s64 = -2104492032;
loc_823A1CC8:
	// lbz r11,-24(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + -24);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823a1e44
	if (ctx.cr0.eq) goto loc_823A1E44;
	// lwz r10,88(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// lwz r9,84(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r11,-20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -20);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r10,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 2;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x823a1cf8
	if (ctx.cr6.lt) goto loc_823A1CF8;
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x823a1d04
	goto loc_823A1D04;
loc_823A1CF8:
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r3,r11,r10
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
loc_823A1D04:
	// addi r5,r1,176
	ctx.r5.s64 = ctx.r1.s64 + 176;
	// lfs f0,4(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,192
	ctx.r11.s64 = ctx.r1.s64 + 192;
	// stfs f0,204(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// stfs f0,200(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// addi r24,r1,272
	ctx.r24.s64 = ctx.r1.s64 + 272;
	// stfs f0,196(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// stfs f0,192(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// lwz r4,-16(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + -16);
	// stfs f0,176(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// stb r25,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r25.u8);
	// lvx128 v62,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 272);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f13.u64);
	// lwz r24,132(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.f0.u64);
	// lwz r23,132(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 132);
	// mr r5,r24
	ctx.r5.u64 = ctx.r24.u64;
	// mr r6,r23
	ctx.r6.u64 = ctx.r23.u64;
	// bl 0x823beba0
	ctx.lr = 0x823A1D90;
	sub_823BEBA0(ctx, base);
	// extsw r10,r23
	ctx.r10.s64 = ctx.r23.s32;
	// std r10,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.r10.u64);
	// extsw r11,r24
	ctx.r11.s64 = ctx.r24.s32;
	// std r11,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r11.u64);
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// addi r24,r1,112
	ctx.r24.s64 = ctx.r1.s64 + 112;
	// ld r4,8(r30)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r30.u32 + 8);
	// addi r8,r1,256
	ctx.r8.s64 = ctx.r1.s64 + 256;
	// lfs f1,12512(r29)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 12512);
	ctx.f1.f64 = double(temp.f32);
	// addi r23,r1,160
	ctx.r23.s64 = ctx.r1.s64 + 160;
	// lwz r9,324(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// lis r6,68
	ctx.r6.s64 = 4456448;
	// li r7,1
	ctx.r7.s64 = 1;
	// std r4,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r4.u64);
	// ori r6,r6,32844
	ctx.r6.u64 = ctx.r6.u64 | 32844;
	// lfd f13,136(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfd f0,224(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 224);
	// fcfid f0,f0
	ctx.f0.f64 = double(ctx.f0.s64);
	// li r5,3
	ctx.r5.s64 = 3;
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// addi r3,r1,144
	ctx.r3.s64 = ctx.r1.s64 + 144;
	// lwz r10,424(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 424);
	// lfs f12,44(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 44);
	ctx.f12.f64 = double(temp.f32);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// frsp f0,f0
	ctx.f0.f64 = double(float(ctx.f0.f64));
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
	// fsubs f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f12.f64));
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
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r23
	ea = (ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,256(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 256);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// bl 0x8245afd8
	ctx.lr = 0x823A1E44;
	sub_8245AFD8(ctx, base);
loc_823A1E44:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r30,r30,40
	ctx.r30.s64 = ctx.r30.s64 + 40;
	// bne 0x823a1cc8
	if (!ctx.cr0.eq) goto loc_823A1CC8;
	// lwz r11,88(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r30,r31,80
	ctx.r30.s64 = ctx.r31.s64 + 80;
	// lwz r10,84(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// ble cr6,0x823a1efc
	if (!ctx.cr6.gt) goto loc_823A1EFC;
	// rotlwi r11,r10,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r3,8(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823a1efc
	if (ctx.cr6.eq) goto loc_823A1EFC;
	// lwz r4,336(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x823a1efc
	if (ctx.cr6.lt) goto loc_823A1EFC;
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stb r25,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r25.u8);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1568
	ctx.r6.s64 = 1568;
	// li r5,1328
	ctx.r5.s64 = 1328;
	// bl 0x823beba0
	ctx.lr = 0x823A1EA8;
	sub_823BEBA0(ctx, base);
	// clrlwi r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	// lbz r10,341(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 341);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq 0x823a1ec4
	if (ctx.cr0.eq) goto loc_823A1EC4;
	// stb r11,340(r31)
	REX_STORE_U8(ctx.r31.u32 + 340, ctx.r11.u8);
loc_823A1EC4:
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x823a1efc
	if (!ctx.cr6.eq) goto loc_823A1EFC;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f0,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// lwz r11,424(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// addi r10,r11,40
	ctx.r10.s64 = ctx.r11.s64 + 40;
	// lfs f13,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stfs f13,116(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 116, temp.u32);
	// stfs f13,76(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 76, temp.u32);
loc_823A1EFC:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// ble cr6,0x823a1fc8
	if (!ctx.cr6.gt) goto loc_823A1FC8;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r3,12(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823a1fc8
	if (ctx.cr6.eq) goto loc_823A1FC8;
	// lwz r4,336(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blt cr6,0x823a1fc8
	if (ctx.cr6.lt) goto loc_823A1FC8;
	// stb r25,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r25.u8);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,1568
	ctx.r6.s64 = 1568;
	// li r5,1328
	ctx.r5.s64 = 1328;
	// bl 0x823beba0
	ctx.lr = 0x823A1F50;
	sub_823BEBA0(ctx, base);
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x823a1fc8
	if (!ctx.cr6.eq) goto loc_823A1FC8;
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// lfs f0,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// li r10,4
	ctx.r10.s64 = 4;
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r11,424(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 424);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r10,r11,40
	ctx.r10.s64 = ctx.r11.s64 + 40;
	// addi r10,r11,36
	ctx.r10.s64 = ctx.r11.s64 + 36;
	// lfs f13,44(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 84, temp.u32);
	// fdivs f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 / ctx.f13.f64));
	// stfs f0,44(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 44, temp.u32);
	// stfs f13,116(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 116, temp.u32);
	// stfs f13,76(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 76, temp.u32);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// lfs f0,23848(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23848);
	ctx.f0.f64 = double(temp.f32);
loc_823A1FA0:
	// lfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// bge cr6,0x823a1fb4
	if (!ctx.cr6.lt) goto loc_823A1FB4;
	// fadds f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// b 0x823a1fb8
	goto loc_823A1FB8;
loc_823A1FB4:
	// fsubs f13,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
loc_823A1FB8:
	// stfs f13,0(r10)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,40
	ctx.r10.s64 = ctx.r10.s64 + 40;
	// bdnz 0x823a1fa0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_823A1FA0;
loc_823A1FC8:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// ble cr6,0x823a2050
	if (!ctx.cr6.gt) goto loc_823A2050;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r3,16(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823a2050
	if (ctx.cr6.eq) goto loc_823A2050;
	// lbz r11,348(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 348);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x823a2050
	if (ctx.cr0.eq) goto loc_823A2050;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1360
	ctx.r5.s64 = 1360;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// li r4,0
	ctx.r4.s64 = 0;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f0.u64);
	// lwz r6,140(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stb r25,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r25.u8);
	// bl 0x823beba0
	ctx.lr = 0x823A2050;
	sub_823BEBA0(ctx, base);
loc_823A2050:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,4(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// ble cr6,0x823a20d8
	if (!ctx.cr6.gt) goto loc_823A20D8;
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// lwz r3,20(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x823a20d8
	if (ctx.cr6.eq) goto loc_823A20D8;
	// lwz r11,336(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 336);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x823a20d8
	if (!ctx.cr6.eq) goto loc_823A20D8;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f0.f64 = double(temp.f32);
	// addi r6,r1,160
	ctx.r6.s64 = ctx.r1.s64 + 160;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// mr r9,r27
	ctx.r9.u64 = ctx.r27.u64;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,0
	ctx.r7.s64 = 0;
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r5,1360
	ctx.r5.s64 = 1360;
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// li r4,9
	ctx.r4.s64 = 9;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,136(r1)
	REX_STORE_U64(ctx.r1.u32 + 136, ctx.f0.u64);
	// lwz r6,140(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 140);
	// stb r25,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r25.u8);
	// bl 0x823beba0
	ctx.lr = 0x823A20D8;
	sub_823BEBA0(ctx, base);
loc_823A20D8:
	// lwz r30,356(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// lwz r31,360(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 360);
	// b 0x823a20f0
	goto loc_823A20F0;
loc_823A20E4:
	// lwz r3,0(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// bl 0x823a3050
	ctx.lr = 0x823A20EC;
	sub_823A3050(ctx, base);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
loc_823A20F0:
	// cmplw cr6,r30,r31
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r31.u32, ctx.xer);
	// bne cr6,0x823a20e4
	if (!ctx.cr6.eq) goto loc_823A20E4;
loc_823A20F8:
	// addi r1,r1,368
	ctx.r1.s64 = ctx.r1.s64 + 368;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823C4978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x823C4980;
	__savegprlr_26(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lbz r11,-12978(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + -12978);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm. r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// beq 0x823c4c30
	if (ctx.cr0.eq) goto loc_823C4C30;
	// addi r11,r11,14876
	ctx.r11.s64 = ctx.r11.s64 + 14876;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// addi r10,r10,-4080
	ctx.r10.s64 = ctx.r10.s64 + -4080;
	// addi r9,r9,17132
	ctx.r9.s64 = ctx.r9.s64 + 17132;
	// lfs f0,-2408(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2408);
	ctx.f0.f64 = double(temp.f32);
	// addi r8,r8,-31476
	ctx.r8.s64 = ctx.r8.s64 + -31476;
	// lfs f11,-2404(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2404);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,160(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lfs f10,1256(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1256);
	ctx.f10.f64 = double(temp.f32);
	// lfs f7,4848(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4848);
	ctx.f7.f64 = double(temp.f32);
	// stfs f10,152(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// lfs f6,1424(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1424);
	ctx.f6.f64 = double(temp.f32);
	// stfs f7,144(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lfs f5,-12(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -12);
	ctx.f5.f64 = double(temp.f32);
	// stfs f6,128(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f5,112(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lfs f9,-12692(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -12692);
	ctx.f9.f64 = double(temp.f32);
	// lfs f4,-12404(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -12404);
	ctx.f4.f64 = double(temp.f32);
	// lfs f8,-500(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -500);
	ctx.f8.f64 = double(temp.f32);
	// stfs f9,124(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f4,120(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f12,-15596(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -15596);
	ctx.f12.f64 = double(temp.f32);
	// stfs f8,92(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// lfs f13,780(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 780);
	ctx.f13.f64 = double(temp.f32);
	// stfs f9,96(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r8,152(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r10,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r10.u64);
	// lfs f10,-596(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -596);
	ctx.f10.f64 = double(temp.f32);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r7,144(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stfs f10,108(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// std r8,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r8.u64);
	// lfs f11,3212(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3212);
	ctx.f11.f64 = double(temp.f32);
	// ld r6,128(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// lfs f7,412(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 412);
	ctx.f7.f64 = double(temp.f32);
	// stfs f9,152(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f12,160(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// std r7,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r7.u64);
	// stfs f11,164(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// std r6,344(r1)
	REX_STORE_U64(ctx.r1.u32 + 344, ctx.r6.u64);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// stfs f12,128(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r8,120(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r10,400(r1)
	REX_STORE_U64(ctx.r1.u32 + 400, ctx.r10.u64);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r7,88(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// std r8,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r8.u64);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f9,100(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f9,1248(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 1248);
	ctx.f9.f64 = double(temp.f32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r7,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r7.u64);
	// lfs f8,-2640(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2640);
	ctx.f8.f64 = double(temp.f32);
	// stfs f11,92(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// std r6,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r6.u64);
	// stfs f7,96(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r10,352(r1)
	REX_STORE_U64(ctx.r1.u32 + 352, ctx.r10.u64);
	// stfs f10,156(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f7,-28252(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28252);
	ctx.f7.f64 = double(temp.f32);
	// ld r7,112(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r11,160(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// ld r30,136(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// stfs f11,88(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r4,96(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r8,128(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// std r10,408(r1)
	REX_STORE_U64(ctx.r1.u32 + 408, ctx.r10.u64);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// std r11,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r11.u64);
	// stfs f8,96(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// std r9,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r9.u64);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r31,152(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// std r8,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r8.u64);
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// std r7,360(r1)
	REX_STORE_U64(ctx.r1.u32 + 360, ctx.r7.u64);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r6,416(r1)
	REX_STORE_U64(ctx.r1.u32 + 416, ctx.r6.u64);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r5,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r5.u64);
	// stfs f12,144(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// std r4,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r4.u64);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// std r3,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r3.u64);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// std r31,368(r1)
	REX_STORE_U64(ctx.r1.u32 + 368, ctx.r31.u64);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// std r30,424(r1)
	REX_STORE_U64(ctx.r1.u32 + 424, ctx.r30.u64);
	// stfs f8,160(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// ld r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// stfs f0,164(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f9,104(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// ld r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// std r11,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r11.u64);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// std r10,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r10.u64);
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r9,320(r1)
	REX_STORE_U64(ctx.r1.u32 + 320, ctx.r9.u64);
	// ld r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r11,376(r1)
	REX_STORE_U64(ctx.r1.u32 + 376, ctx.r11.u64);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r10,432(r1)
	REX_STORE_U64(ctx.r1.u32 + 432, ctx.r10.u64);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r9,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r9.u64);
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r11.u64);
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r10,328(r1)
	REX_STORE_U64(ctx.r1.u32 + 328, ctx.r10.u64);
	// ld r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r9,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r9.u64);
	// ld r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r11,440(r1)
	REX_STORE_U64(ctx.r1.u32 + 440, ctx.r11.u64);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r10,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r10.u64);
	// std r9,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r9.u64);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,336(r1)
	REX_STORE_U64(ctx.r1.u32 + 336, ctx.r11.u64);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// std r11,392(r1)
	REX_STORE_U64(ctx.r1.u32 + 392, ctx.r11.u64);
	// std r10,448(r1)
	REX_STORE_U64(ctx.r1.u32 + 448, ctx.r10.u64);
	// b 0x823c4ec4
	goto loc_823C4EC4;
loc_823C4C30:
	// lis r8,-32226
	ctx.r8.s64 = -2111963136;
	// lfs f4,14876(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14876);
	ctx.f4.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f10,17132(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17132);
	ctx.f10.f64 = double(temp.f32);
	// addi r7,r11,14876
	ctx.r7.s64 = ctx.r11.s64 + 14876;
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// stfs f4,116(r1)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r6,r9,17132
	ctx.r6.s64 = ctx.r9.s64 + 17132;
	// lfs f0,-31476(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -31476);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r10,-31476
	ctx.r10.s64 = ctx.r10.s64 + -31476;
	// lfs f13,-2408(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -2408);
	ctx.f13.f64 = double(temp.f32);
	// lfs f11,-2404(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -2404);
	ctx.f11.f64 = double(temp.f32);
	// lfs f7,1256(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1256);
	ctx.f7.f64 = double(temp.f32);
	// stfs f11,136(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// lfs f12,-18760(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -18760);
	ctx.f12.f64 = double(temp.f32);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,-596(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -596);
	ctx.f0.f64 = double(temp.f32);
	// lfs f6,860(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 860);
	ctx.f6.f64 = double(temp.f32);
	// stfs f6,96(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lfs f5,-12404(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -12404);
	ctx.f5.f64 = double(temp.f32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f5,120(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// lfs f9,-12692(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -12692);
	ctx.f9.f64 = double(temp.f32);
	// lfs f8,780(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 780);
	ctx.f8.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f9,128(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f8,132(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f0,148(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// ld r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// stfs f13,152(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f12,156(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// lfs f7,-15596(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -15596);
	ctx.f7.f64 = double(temp.f32);
	// lfs f6,3212(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 3212);
	ctx.f6.f64 = double(temp.f32);
	// ld r9,80(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// lfs f5,412(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 412);
	ctx.f5.f64 = double(temp.f32);
	// std r11,176(r1)
	REX_STORE_U64(ctx.r1.u32 + 176, ctx.r11.u64);
	// lfs f11,-500(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -500);
	ctx.f11.f64 = double(temp.f32);
	// stfs f10,84(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r10,232(r1)
	REX_STORE_U64(ctx.r1.u32 + 232, ctx.r10.u64);
	// stfs f7,160(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// ld r8,96(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f9,164(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// std r9,288(r1)
	REX_STORE_U64(ctx.r1.u32 + 288, ctx.r9.u64);
	// stfs f6,136(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f8,140(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f7,104(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r4,120(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// std r8,344(r1)
	REX_STORE_U64(ctx.r1.u32 + 344, ctx.r8.u64);
	// lfs f10,1248(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 1248);
	ctx.f10.f64 = double(temp.f32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r5,400(r1)
	REX_STORE_U64(ctx.r1.u32 + 400, ctx.r5.u64);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r10,128(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r4,184(r1)
	REX_STORE_U64(ctx.r1.u32 + 184, ctx.r4.u64);
	// stfs f6,88(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stfs f9,92(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// std r11,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r11.u64);
	// stfs f5,120(r1)
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// stfs f11,112(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r10,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r10.u64);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r9,352(r1)
	REX_STORE_U64(ctx.r1.u32 + 352, ctx.r9.u64);
	// stfs f13,144(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f12,148(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// ld r9,136(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// lfs f7,-28252(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -28252);
	ctx.f7.f64 = double(temp.f32);
	// ld r8,104(r1)
	ctx.r8.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// lfs f9,-2640(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -2640);
	ctx.f9.f64 = double(temp.f32);
	// ld r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f7,136(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ld r6,96(r1)
	ctx.r6.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f8,140(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// ld r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// stfs f10,104(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r5,88(r1)
	ctx.r5.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r4,120(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// std r11,408(r1)
	REX_STORE_U64(ctx.r1.u32 + 408, ctx.r11.u64);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r3,112(r1)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// std r10,192(r1)
	REX_STORE_U64(ctx.r1.u32 + 192, ctx.r10.u64);
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r31,128(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// std r9,248(r1)
	REX_STORE_U64(ctx.r1.u32 + 248, ctx.r9.u64);
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// std r8,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r8.u64);
	// stfs f9,120(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// std r7,360(r1)
	REX_STORE_U64(ctx.r1.u32 + 360, ctx.r7.u64);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// std r6,416(r1)
	REX_STORE_U64(ctx.r1.u32 + 416, ctx.r6.u64);
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// std r5,200(r1)
	REX_STORE_U64(ctx.r1.u32 + 200, ctx.r5.u64);
	// stfs f12,116(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// std r4,256(r1)
	REX_STORE_U64(ctx.r1.u32 + 256, ctx.r4.u64);
	// stfs f11,128(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// std r3,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r3.u64);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// std r31,368(r1)
	REX_STORE_U64(ctx.r1.u32 + 368, ctx.r31.u64);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// ld r11,144(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f12,164(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f9,144(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// ld r10,136(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// std r11,424(r1)
	REX_STORE_U64(ctx.r1.u32 + 424, ctx.r11.u64);
	// stfs f10,136(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// ld r9,104(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// std r10,208(r1)
	REX_STORE_U64(ctx.r1.u32 + 208, ctx.r10.u64);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// std r9,264(r1)
	REX_STORE_U64(ctx.r1.u32 + 264, ctx.r9.u64);
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// ld r9,88(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// std r11,320(r1)
	REX_STORE_U64(ctx.r1.u32 + 320, ctx.r11.u64);
	// ld r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 120);
	// std r10,376(r1)
	REX_STORE_U64(ctx.r1.u32 + 376, ctx.r10.u64);
	// ld r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 112);
	// std r9,432(r1)
	REX_STORE_U64(ctx.r1.u32 + 432, ctx.r9.u64);
	// ld r9,128(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r11,216(r1)
	REX_STORE_U64(ctx.r1.u32 + 216, ctx.r11.u64);
	// ld r11,152(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 152);
	// std r10,272(r1)
	REX_STORE_U64(ctx.r1.u32 + 272, ctx.r10.u64);
	// ld r10,160(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r9,328(r1)
	REX_STORE_U64(ctx.r1.u32 + 328, ctx.r9.u64);
	// ld r9,144(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 144);
	// std r11,384(r1)
	REX_STORE_U64(ctx.r1.u32 + 384, ctx.r11.u64);
	// ld r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 136);
	// std r10,440(r1)
	REX_STORE_U64(ctx.r1.u32 + 440, ctx.r10.u64);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r9,224(r1)
	REX_STORE_U64(ctx.r1.u32 + 224, ctx.r9.u64);
	// std r11,280(r1)
	REX_STORE_U64(ctx.r1.u32 + 280, ctx.r11.u64);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// ld r9,96(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// std r10,336(r1)
	REX_STORE_U64(ctx.r1.u32 + 336, ctx.r10.u64);
	// std r11,392(r1)
	REX_STORE_U64(ctx.r1.u32 + 392, ctx.r11.u64);
	// std r9,448(r1)
	REX_STORE_U64(ctx.r1.u32 + 448, ctx.r9.u64);
loc_823C4EC4:
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r26,r1,200
	ctx.r26.s64 = ctx.r1.s64 + 200;
	// lis r28,-32112
	ctx.r28.s64 = -2104492032;
	// lis r27,-32112
	ctx.r27.s64 = -2104492032;
loc_823C4ED4:
	// mr r31,r26
	ctx.r31.u64 = ctx.r26.u64;
	// li r30,4
	ctx.r30.s64 = 4;
loc_823C4EDC:
	// lwz r11,-12988(r27)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r27.u32 + -12988);
	// addi r4,r31,-24
	ctx.r4.s64 = ctx.r31.s64 + -24;
	// add r3,r29,r11
	ctx.r3.u64 = ctx.r29.u64 + ctx.r11.u64;
	// bl 0x8221eae8
	ctx.lr = 0x823C4EEC;
	sub_8221EAE8(ctx, base);
	// lwz r11,-12984(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + -12984);
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// add r3,r29,r11
	ctx.r3.u64 = ctx.r29.u64 + ctx.r11.u64;
	// bl 0x8221eae8
	ctx.lr = 0x823C4EFC;
	sub_8221EAE8(ctx, base);
	// addic. r30,r30,-1
	ctx.xer.ca = ctx.r30.u32 > 0;
	ctx.r30.s64 = ctx.r30.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// addi r31,r31,8
	ctx.r31.s64 = ctx.r31.s64 + 8;
	// bne 0x823c4edc
	if (!ctx.cr0.eq) goto loc_823C4EDC;
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// addi r26,r26,56
	ctx.r26.s64 = ctx.r26.s64 + 56;
	// cmplwi cr6,r29,20
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 20, ctx.xer);
	// blt cr6,0x823c4ed4
	if (ctx.cr6.lt) goto loc_823C4ED4;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F4800) {
	REX_FUNC_PROLOGUE();
	// lwz r3,156(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// lbz r11,76(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 76);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// b 0x823f4a38
	sub_823F4A38(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823F5848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823F5850;
	__savegprlr_29(ctx, base);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// rlwinm r29,r4,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r11,r11,3604
	ctx.r11.s64 = ctx.r11.s64 + 3604;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// lwzx r30,r29,r11
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r11.u32);
	// blt cr6,0x823f58c8
	if (ctx.cr6.lt) goto loc_823F58C8;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// bge cr6,0x823f58c8
	if (!ctx.cr6.lt) goto loc_823F58C8;
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r10,48(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// rlwinm r9,r30,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// addi r11,r11,-20728
	ctx.r11.s64 = ctx.r11.s64 + -20728;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// addi r7,r11,4
	ctx.r7.s64 = ctx.r11.s64 + 4;
	// lis r6,-32228
	ctx.r6.s64 = -2112094208;
	// lwz r5,0(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lfsx f13,r9,r11
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-29492(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfsx f12,r9,r7
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r7.u32);
	ctx.f12.f64 = double(temp.f32);
	// lfs f0,-1292(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -1292);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,0(r5)
	REX_STORE_U64(ctx.r5.u32 + 0, ctx.r11.u64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// bl 0x823c82a8
	ctx.lr = 0x823F58C8;
	sub_823C82A8(ctx, base);
loc_823F58C8:
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,32(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwzx r10,r30,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// lfs f0,-19936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19936);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,0(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,16(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r10,0(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lfs f13,52(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 52);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,48(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 48);
	ctx.f12.f64 = double(temp.f32);
	// fsubs f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// fsubs f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// bctrl 
	ctx.lr = 0x823F5908;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwzx r10,r30,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + ctx.r31.u32);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// lwz r10,16(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r10,8(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x823F593C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lis r11,16
	ctx.r11.s64 = 1048576;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// ori r11,r11,583
	ctx.r11.u64 = ctx.r11.u64 | 583;
	// ori r10,r10,154
	ctx.r10.u64 = ctx.r10.u64 | 154;
	// li r4,256
	ctx.r4.s64 = 256;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r10,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r10.u32);
	// lwzx r5,r29,r9
	ctx.r5.u64 = REX_LOAD_U32(ctx.r29.u32 + ctx.r9.u32);
	// bl 0x823c7af0
	ctx.lr = 0x823F5968;
	sub_823C7AF0(ctx, base);
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,16(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x823F598C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// bl 0x823c8220
	ctx.lr = 0x823F5994;
	sub_823C8220(ctx, base);
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_823FD9E0) {
	REX_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x823FD9E8;
	__savegprlr_29(ctx, base);
	// lwz r11,20(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// mr r10,r3
	ctx.r10.u64 = ctx.r3.u64;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// li r3,-1
	ctx.r3.s64 = -1;
	// bne cr6,0x823fda10
	if (!ctx.cr6.eq) goto loc_823FDA10;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// ble cr6,0x823fda08
	if (!ctx.cr6.gt) goto loc_823FDA08;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_823FDA08:
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// b 0x823fdae0
	goto loc_823FDAE0;
loc_823FDA10:
	// cmplw cr6,r5,r11
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x823fdae0
	if (ctx.cr6.gt) goto loc_823FDAE0;
	// subf r11,r5,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r5.u64;
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// cmplw cr6,r11,r3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r3.u32, ctx.xer);
	// bgt cr6,0x823fda2c
	if (ctx.cr6.gt) goto loc_823FDA2C;
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
loc_823FDA2C:
	// lwz r30,24(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 24);
	// addi r6,r10,4
	ctx.r6.s64 = ctx.r10.s64 + 4;
	// cmplwi cr6,r30,16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16, ctx.xer);
	// blt cr6,0x823fda44
	if (ctx.cr6.lt) goto loc_823FDA44;
	// lwz r11,4(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// b 0x823fda48
	goto loc_823FDA48;
loc_823FDA44:
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_823FDA48:
	// lbz r10,0(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + 0);
	// add r7,r11,r9
	ctx.r7.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsb r31,r10
	ctx.r31.s64 = ctx.r10.s8;
loc_823FDA54:
	// lbz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r7.u32 + 0);
	// extsb r11,r11
	ctx.r11.s64 = ctx.r11.s8;
	// cmpw cr6,r11,r31
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r31.s32, ctx.xer);
	// bne cr6,0x823fdaa4
	if (!ctx.cr6.eq) goto loc_823FDAA4;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
	// mr r11,r7
	ctx.r11.u64 = ctx.r7.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi r5,0
	ctx.cr0.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq 0x823fda9c
	if (ctx.cr0.eq) goto loc_823FDA9C;
	// add r8,r7,r5
	ctx.r8.u64 = ctx.r7.u64 + ctx.r5.u64;
loc_823FDA7C:
	// lbz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lbz r29,0(r10)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// subf. r9,r29,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r29.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x823fda9c
	if (!ctx.cr0.eq) goto loc_823FDA9C;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmpw cr6,r11,r8
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r8.s32, ctx.xer);
	// bne cr6,0x823fda7c
	if (!ctx.cr6.eq) goto loc_823FDA7C;
loc_823FDA9C:
	// cmpwi r9,0
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x823fdac8
	if (ctx.cr0.eq) goto loc_823FDAC8;
loc_823FDAA4:
	// cmplwi cr6,r30,16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16, ctx.xer);
	// blt cr6,0x823fdab4
	if (ctx.cr6.lt) goto loc_823FDAB4;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// b 0x823fdab8
	goto loc_823FDAB8;
loc_823FDAB4:
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_823FDAB8:
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x823fdae0
	if (ctx.cr6.eq) goto loc_823FDAE0;
	// addi r7,r7,-1
	ctx.r7.s64 = ctx.r7.s64 + -1;
	// b 0x823fda54
	goto loc_823FDA54;
loc_823FDAC8:
	// cmplwi cr6,r30,16
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 16, ctx.xer);
	// blt cr6,0x823fdad8
	if (ctx.cr6.lt) goto loc_823FDAD8;
	// lwz r11,0(r6)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// b 0x823fdadc
	goto loc_823FDADC;
loc_823FDAD8:
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
loc_823FDADC:
	// subf r3,r11,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r11.u64;
loc_823FDAE0:
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82404F28) {
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
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r3,156
	ctx.r3.s64 = ctx.r3.s64 + 156;
	// bl 0x8235ec48
	ctx.lr = 0x82404F4C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,128
	ctx.r3.s64 = ctx.r31.s64 + 128;
	// bl 0x8235ec48
	ctx.lr = 0x82404F5C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,100
	ctx.r3.s64 = ctx.r31.s64 + 100;
	// bl 0x8235ec48
	ctx.lr = 0x82404F6C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,72
	ctx.r3.s64 = ctx.r31.s64 + 72;
	// bl 0x8235ec48
	ctx.lr = 0x82404F7C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,44
	ctx.r3.s64 = ctx.r31.s64 + 44;
	// bl 0x8235ec48
	ctx.lr = 0x82404F8C;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// bl 0x8235ec48
	ctx.lr = 0x82404F9C;
	sub_8235EC48(ctx, base);
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

DEFINE_REX_FUNC(sub_82407CE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82407CE8;
	__savegprlr_27(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r5
	ctx.r28.u64 = ctx.r5.u64;
	// bl 0x823c5778
	ctx.lr = 0x82407CF8;
	sub_823C5778(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r10,r11,-31332
	ctx.r10.s64 = ctx.r11.s64 + -31332;
	// stw r30,156(r29)
	REX_STORE_U32(ctx.r29.u32 + 156, ctx.r30.u32);
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stw r10,0(r29)
	REX_STORE_U32(ctx.r29.u32 + 0, ctx.r10.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r27,r11,22072
	ctx.r27.s64 = ctx.r11.s64 + 22072;
	// li r4,36
	ctx.r4.s64 = 36;
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82407D24;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x82407d68
	if (ctx.cr0.eq) goto loc_82407D68;
	// stw r29,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r29.u32);
	// stw r30,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r30.u32);
	// stw r30,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r30.u32);
	// stb r30,24(r31)
	REX_STORE_U8(ctx.r31.u32 + 24, ctx.r30.u8);
	// stb r30,25(r31)
	REX_STORE_U8(ctx.r31.u32 + 25, ctx.r30.u8);
	// stw r30,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r30.u32);
	// stw r30,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r30.u32);
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// stw r30,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r30.u32);
	// stw r30,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r30.u32);
	// bl 0x82213210
	ctx.lr = 0x82407D58;
	sub_82213210(ctx, base);
	// stb r30,159(r3)
	REX_STORE_U8(ctx.r3.u32 + 159, ctx.r30.u8);
	// bl 0x82213210
	ctx.lr = 0x82407D60;
	sub_82213210(ctx, base);
	// stb r30,156(r3)
	REX_STORE_U8(ctx.r3.u32 + 156, ctx.r30.u8);
	// b 0x82407d6c
	goto loc_82407D6C;
loc_82407D68:
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
loc_82407D6C:
	// stw r31,156(r29)
	REX_STORE_U32(ctx.r29.u32 + 156, ctx.r31.u32);
	// stw r28,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r28.u32);
	// lwz r31,156(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 156);
	// lwz r3,16(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// bl 0x82457b58
	ctx.lr = 0x82407D80;
	sub_82457B58(ctx, base);
	// bl 0x825fd7a0
	ctx.lr = 0x82407D84;
	sub_825FD7A0(ctx, base);
	// stw r3,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r3.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82408020
	ctx.lr = 0x82407D90;
	sub_82408020(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r27)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r27.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x82407DA0;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82407db0
	if (ctx.cr0.eq) goto loc_82407DB0;
	// bl 0x823c9508
	ctx.lr = 0x82407DAC;
	sub_823C9508(ctx, base);
	// b 0x82407db4
	goto loc_82407DB4;
loc_82407DB0:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_82407DB4:
	// stw r3,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r3.u32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lfs f0,-27352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,17264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17264);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r11,32(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f0,16(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stfs f13,20(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 20, temp.u32);
	// bl 0x82213210
	ctx.lr = 0x82407DEC;
	sub_82213210(ctx, base);
	// lbz r11,66(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 66);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x82407e14
	if (!ctx.cr0.eq) goto loc_82407E14;
	// bl 0x82213210
	ctx.lr = 0x82407DFC;
	sub_82213210(ctx, base);
	// lbz r11,19278(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 19278);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82407e14
	if (ctx.cr0.eq) goto loc_82407E14;
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// ori r10,r10,393
	ctx.r10.u64 = ctx.r10.u64 | 393;
	// b 0x82407e1c
	goto loc_82407E1C;
loc_82407E14:
	// lis r10,16
	ctx.r10.s64 = 1048576;
	// ori r10,r10,395
	ctx.r10.u64 = ctx.r10.u64 | 395;
loc_82407E1C:
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// li r11,1
	ctx.r11.s64 = 1;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r10,0(r9)
	REX_STORE_U32(ctx.r9.u32 + 0, ctx.r10.u32);
	// stw r11,24(r9)
	REX_STORE_U32(ctx.r9.u32 + 24, ctx.r11.u32);
	// stb r11,8(r9)
	REX_STORE_U8(ctx.r9.u32 + 8, ctx.r11.u8);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82412648) {
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
	// lwz r11,168(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 168);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// rlwinm. r11,r11,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824126c4
	if (!ctx.cr0.eq) goto loc_824126C4;
	// lwz r11,192(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 192);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824126b8
	if (!ctx.cr6.eq) goto loc_824126B8;
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
	ctx.lr = 0x8241268C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8241269c
	if (ctx.cr0.eq) goto loc_8241269C;
	// bl 0x823c8308
	ctx.lr = 0x82412698;
	sub_823C8308(ctx, base);
	// b 0x824126a0
	goto loc_824126A0;
loc_8241269C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824126A0:
	// stw r3,192(r31)
	REX_STORE_U32(ctx.r31.u32 + 192, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824126c8
	if (ctx.cr6.eq) goto loc_824126C8;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r10,156(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 156);
	// stw r10,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r10.u32);
loc_824126B8:
	// lwz r11,168(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 168);
	// ori r11,r11,2
	ctx.r11.u64 = ctx.r11.u64 | 2;
	// stw r11,168(r31)
	REX_STORE_U32(ctx.r31.u32 + 168, ctx.r11.u32);
loc_824126C4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_824126C8:
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

DEFINE_REX_FUNC(sub_82417CE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f0c
	ctx.lr = 0x82417CE8;
	__savegprlr_25(ctx, base);
	// stwu r1,-400(r1)
	ea = -400 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// stw r4,128(r3)
	REX_STORE_U32(ctx.r3.u32 + 128, ctx.r4.u32);
	// mr r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	// lwz r11,124(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// li r25,7
	ctx.r25.s64 = 7;
	// bgt cr6,0x82417d08
	if (ctx.cr6.gt) goto loc_82417D08;
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
loc_82417D08:
	// lis r11,-32227
	ctx.r11.s64 = -2112028672;
	// li r31,0
	ctx.r31.s64 = 0;
	// addi r29,r11,-18012
	ctx.r29.s64 = ctx.r11.s64 + -18012;
	// lis r26,-32112
	ctx.r26.s64 = -2104492032;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
loc_82417D1C:
	// lwz r28,0(r30)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmpw cr6,r31,r25
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r25.s32, ctx.xer);
	// bge cr6,0x82417d60
	if (!ctx.cr6.lt) goto loc_82417D60;
	// lwz r11,-12856(r26)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r26.u32 + -12856);
	// li r5,0
	ctx.r5.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82417d50
	if (ctx.cr6.eq) goto loc_82417D50;
	// lwz r10,128(r27)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r27.u32 + 128);
	// lwz r11,204(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 204);
	// add r10,r31,r10
	ctx.r10.u64 = ctx.r31.u64 + ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// lwz r5,0(r11)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_82417D50:
	// li r4,256
	ctx.r4.s64 = 256;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x823c7b68
	ctx.lr = 0x82417D5C;
	sub_823C7B68(ctx, base);
	// b 0x82417d68
	goto loc_82417D68;
loc_82417D60:
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r11.u8);
loc_82417D68:
	// rlwinm r11,r28,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwzx r11,r11,r27
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r27.u32);
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
	ctx.lr = 0x82417D90;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r30,r30,4
	ctx.r30.s64 = ctx.r30.s64 + 4;
	// addi r11,r29,28
	ctx.r11.s64 = ctx.r29.s64 + 28;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpw cr6,r30,r11
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x82417d1c
	if (ctx.cr6.lt) goto loc_82417D1C;
	// addi r1,r1,400
	ctx.r1.s64 = ctx.r1.s64 + 400;
	// b 0x82739f5c
	__restgprlr_25(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8241F378) {
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
	// li r11,0
	ctx.r11.s64 = 0;
	// lbz r4,496(r3)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r3.u32 + 496);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// stb r11,448(r3)
	REX_STORE_U8(ctx.r3.u32 + 448, ctx.r11.u8);
	// bl 0x8241f030
	ctx.lr = 0x8241F39C;
	sub_8241F030(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,396(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// bl 0x8241dfe8
	ctx.lr = 0x8241F3A8;
	sub_8241DFE8(ctx, base);
	// lwz r10,436(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// li r11,12
	ctx.r11.s64 = 12;
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// lbz r11,448(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 448);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x8241f3cc
	if (ctx.cr0.eq) goto loc_8241F3CC;
	// lwz r11,492(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 492);
	// lwz r10,456(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 456);
	// b 0x8241f3d4
	goto loc_8241F3D4;
loc_8241F3CC:
	// lwz r11,392(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 392);
	// lwz r10,396(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
loc_8241F3D4:
	// lwz r9,436(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,12(r9)
	REX_STORE_U32(ctx.r9.u32 + 12, ctx.r11.u32);
	// lwz r11,436(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// stw r10,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r10.u32);
	// lwz r5,396(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 396);
	// lwz r11,356(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 356);
	// addi r11,r11,90
	ctx.r11.s64 = ctx.r11.s64 + 90;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r4,r11,r31
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// bl 0x8241dbf8
	ctx.lr = 0x8241F400;
	sub_8241DBF8(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8241d480
	ctx.lr = 0x8241F408;
	sub_8241D480(ctx, base);
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

DEFINE_REX_FUNC(sub_82426758) {
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
	// lwz r3,92(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8242677c
	if (ctx.cr6.eq) goto loc_8242677C;
	// bl 0x823c74f0
	ctx.lr = 0x8242677C;
	sub_823C74F0(ctx, base);
loc_8242677C:
	// li r11,0
	ctx.r11.s64 = 0;
	// lis r10,-32115
	ctx.r10.s64 = -2104688640;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r10,22072
	ctx.r11.s64 = ctx.r10.s64 + 22072;
	// li r4,4
	ctx.r4.s64 = 4;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x8242679C;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x824267ac
	if (ctx.cr0.eq) goto loc_824267AC;
	// bl 0x823c9508
	ctx.lr = 0x824267A8;
	sub_823C9508(ctx, base);
	// b 0x824267b0
	goto loc_824267B0;
loc_824267AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824267B0:
	// stw r3,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r3.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// lwz r8,72(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lis r7,16
	ctx.r7.s64 = 1048576;
	// stw r8,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r8.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lwz r8,92(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lfs f0,-27352(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -27352);
	ctx.f0.f64 = double(temp.f32);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// stfs f0,16(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 16, temp.u32);
	// lwz r10,0(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lfs f0,17264(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17264);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,20(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 20, temp.u32);
	// ori r10,r7,290
	ctx.r10.u64 = ctx.r7.u64 | 290;
	// li r9,3
	ctx.r9.s64 = 3;
	// lwz r8,92(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// lwz r8,0(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// li r3,3
	ctx.r3.s64 = 3;
	// stw r10,0(r8)
	REX_STORE_U32(ctx.r8.u32 + 0, ctx.r10.u32);
	// stw r9,24(r8)
	REX_STORE_U32(ctx.r8.u32 + 24, ctx.r9.u32);
	// stb r11,8(r8)
	REX_STORE_U8(ctx.r8.u32 + 8, ctx.r11.u8);
	// stw r11,96(r31)
	REX_STORE_U32(ctx.r31.u32 + 96, ctx.r11.u32);
	// bl 0x823c7bd8
	ctx.lr = 0x82426814;
	sub_823C7BD8(ctx, base);
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

DEFINE_REX_FUNC(sub_8242B048) {
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
	// bl 0x8242af68
	ctx.lr = 0x8242B068;
	sub_8242AF68(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8242b080
	if (ctx.cr0.eq) goto loc_8242B080;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8242b080
	if (ctx.cr6.eq) goto loc_8242B080;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8242B080;
	sub_825E0378(ctx, base);
loc_8242B080:
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

DEFINE_REX_FUNC(sub_8242D830) {
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
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x825a4a90
	ctx.lr = 0x8242D848;
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
	ctx.lr = 0x8242D85C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82430958) {
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
	// lwz r11,2340(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824309f0
	if (ctx.cr6.eq) goto loc_824309F0;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,592(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 592);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8243098C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824309f0
	if (ctx.cr0.eq) goto loc_824309F0;
	// li r6,0
	ctx.r6.s64 = 0;
	// addi r7,r31,2584
	ctx.r7.s64 = ctx.r31.s64 + 2584;
loc_8243099C:
	// lwz r3,-20(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + -20);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824309ac
	if (ctx.cr6.eq) goto loc_824309AC;
	// bl 0x824353a0
	ctx.lr = 0x824309AC;
	sub_824353A0(ctx, base);
loc_824309AC:
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x824309e0
	if (ctx.cr0.eq) goto loc_824309E0;
	// lwz r11,0(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x824309cc
	if (!ctx.cr6.eq) goto loc_824309CC;
	// lwz r10,20(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x82430a08
	if (ctx.cr6.eq) goto loc_82430A08;
loc_824309CC:
	// cmplwi cr6,r11,17
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 17, ctx.xer);
	// bne cr6,0x824309e0
	if (!ctx.cr6.eq) goto loc_824309E0;
	// lwz r11,20(r7)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r7.u32 + 20);
	// cmpwi cr6,r11,9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 9, ctx.xer);
	// beq cr6,0x82430a08
	if (ctx.cr6.eq) goto loc_82430A08;
loc_824309E0:
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// addi r7,r7,4
	ctx.r7.s64 = ctx.r7.s64 + 4;
	// cmpwi cr6,r6,5
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 5, ctx.xer);
	// blt cr6,0x8243099c
	if (ctx.cr6.lt) goto loc_8243099C;
loc_824309F0:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824309F4:
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
loc_82430A08:
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x824309f4
	goto loc_824309F4;
}

DEFINE_REX_FUNC(sub_82436EA0) {
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
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,2968(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2968);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// bl 0x8258ab70
	ctx.lr = 0x82436EC8;
	sub_8258AB70(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x82436f8c
	if (ctx.cr0.eq) goto loc_82436F8C;
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// lfs f0,2440(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2440);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// lfs f13,2432(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2432);
	ctx.f13.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r7,-32227
	ctx.r7.s64 = -2112028672;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r9,r9,32256
	ctx.r9.s64 = ctx.r9.s64 + 32256;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,2444(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2444);
	ctx.f0.f64 = double(temp.f32);
	// vmulfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f13,2264(r31)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2264);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f0,f13
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// lfs f0,-18548(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -18548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,2260(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 2260);
	ctx.f12.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fsubs f2,f13,f0
	ctx.f2.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// fadds f1,f12,f0
	ctx.f1.f64 = double(float(ctx.f12.f64 + ctx.f0.f64));
	// bl 0x82584228
	ctx.lr = 0x82436F50;
	sub_82584228(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32227
	ctx.r10.s64 = -2112028672;
	// li r9,3
	ctx.r9.s64 = 3;
	// li r8,1
	ctx.r8.s64 = 1;
	// lfs f0,-29492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,24344(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 24344);
	ctx.f13.f64 = double(temp.f32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stfs f0,0(r11)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r11.u32 + 0, temp.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stfs f13,4(r11)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r11.u32 + 4, temp.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stw r9,364(r11)
	REX_STORE_U32(ctx.r11.u32 + 364, ctx.r9.u32);
	// lwz r11,12(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// stb r8,360(r11)
	REX_STORE_U8(ctx.r11.u32 + 360, ctx.r8.u8);
	// b 0x82436f94
	goto loc_82436F94;
loc_82436F8C:
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,2968(r31)
	REX_STORE_U32(ctx.r31.u32 + 2968, ctx.r11.u32);
loc_82436F94:
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
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

DEFINE_REX_FUNC(sub_8243FFC8) {
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
	// cmpwi cr6,r4,1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 1, ctx.xer);
	// beq cr6,0x82440024
	if (ctx.cr6.eq) goto loc_82440024;
	// cmpwi cr6,r4,2
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 2, ctx.xer);
	// beq cr6,0x82440000
	if (ctx.cr6.eq) goto loc_82440000;
	// ble cr6,0x8244001c
	if (!ctx.cr6.gt) goto loc_8244001C;
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// ble cr6,0x82440024
	if (!ctx.cr6.gt) goto loc_82440024;
	// cmpwi cr6,r4,6
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 6, ctx.xer);
	// ble cr6,0x8244001c
	if (!ctx.cr6.gt) goto loc_8244001C;
	// cmpwi cr6,r4,8
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 8, ctx.xer);
	// bgt cr6,0x8244001c
	if (ctx.cr6.gt) goto loc_8244001C;
loc_82440000:
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82440014;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm. r11,r3,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82440044
	if (ctx.cr0.eq) goto loc_82440044;
loc_8244001C:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82440048
	goto loc_82440048;
loc_82440024:
	// lwz r3,2340(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,860(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 860);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82440038;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,31
	ctx.r11.u64 = ctx.r3.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r3,0
	ctx.r3.s64 = 0;
	// bne 0x82440048
	if (!ctx.cr0.eq) goto loc_82440048;
loc_82440044:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82440048:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82444358) {
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
	// lwz r11,-12952(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12952);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824443ac
	if (ctx.cr6.eq) goto loc_824443AC;
	// lwz r8,20(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// li r7,0
	ctx.r7.s64 = 0;
loc_8244437C:
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x8244439c
	if (ctx.cr6.eq) goto loc_8244439C;
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// bl 0x824443c8
	ctx.lr = 0x82444390;
	sub_824443C8(ctx, base);
	// lwz r11,2352(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 2352);
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// beq cr6,0x824443c0
	if (ctx.cr6.eq) goto loc_824443C0;
loc_8244439C:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// cmplwi cr6,r7,6
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 6, ctx.xer);
	// blt cr6,0x8244437c
	if (ctx.cr6.lt) goto loc_8244437C;
loc_824443AC:
	// li r3,0
	ctx.r3.s64 = 0;
loc_824443B0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
loc_824443C0:
	// mr r3,r6
	ctx.r3.u64 = ctx.r6.u64;
	// b 0x824443b0
	goto loc_824443B0;
}

DEFINE_REX_FUNC(sub_82446B98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82446BA0;
	__savegprlr_28(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82446cf8
	if (ctx.cr6.eq) goto loc_82446CF8;
	// lwz r29,2504(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 2504);
	// cmplwi cr6,r29,0
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 0, ctx.xer);
	// beq cr6,0x82446cf8
	if (ctx.cr6.eq) goto loc_82446CF8;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,110
	ctx.r4.s64 = 110;
	// lwz r3,44(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82446BD4;
	sub_825E02A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82446BE0:
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x82446bf0
	if (!ctx.cr6.eq) goto loc_82446BF0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82446bf8
	goto loc_82446BF8;
loc_82446BF0:
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r10,r29
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r29.u32);
loc_82446BF8:
	// mr r9,r11
	ctx.r9.u64 = ctx.r11.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// rlwimi r9,r10,16,0,15
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r9.u64 & 0xFFFFFFFF0000FFFF);
	// cmplwi cr6,r11,15
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 15, ctx.xer);
	// stwx r9,r31,r30
	REX_STORE_U32(ctx.r31.u32 + ctx.r30.u32, ctx.r9.u32);
	// addi r31,r31,4
	ctx.r31.s64 = ctx.r31.s64 + 4;
	// blt cr6,0x82446be0
	if (ctx.cr6.lt) goto loc_82446BE0;
	// lwz r3,2340(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + 2340);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,336(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 336);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82446C28;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,36(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 36);
	ctx.f0.f64 = double(temp.f32);
	// lbz r8,24(r3)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r3.u32 + 24);
	// lfs f13,40(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 40);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// lfs f12,28(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 28);
	ctx.f12.f64 = double(temp.f32);
	// lbz r7,87(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// lfs f0,32(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 32);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f12,f12
	ctx.f12.s64 = std::isnan(ctx.f12.f64) ? int64_t(0x80000000U) : (ctx.f12.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f12.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lbz r6,95(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// lwz r29,20(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 20);
	// stfd f12,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f12.u64);
	// addi r9,r3,40
	ctx.r9.s64 = ctx.r3.s64 + 40;
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lbz r5,87(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 87);
	// lbz r3,95(r1)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// li r10,44
	ctx.r10.s64 = 44;
	// addic r4,r8,-1
	ctx.xer.ca = ctx.r8.u32 > 0;
	ctx.r4.s64 = ctx.r8.s64 + -1;
	// stb r7,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r7.u8);
	// subfe r8,r4,r8
	temp.u8 = (~ctx.r4.u32 + ctx.r8.u32 < ~ctx.r4.u32) | (~ctx.r4.u32 + ctx.r8.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r8.u64 = ~ctx.r4.u64 + ctx.r8.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r29,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r29.u8);
	// stb r8,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r8.u8);
	// stb r6,101(r1)
	REX_STORE_U8(ctx.r1.u32 + 101, ctx.r6.u8);
	// stb r5,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r5.u8);
	// stb r3,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r3.u8);
loc_82446CA0:
	// addi r10,r1,102
	ctx.r10.s64 = ctx.r1.s64 + 102;
	// lfsu f0,4(r9)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r9.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r9.u32 = ea;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lbz r8,95(r1)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// stbx r8,r11,r10
	REX_STORE_U8(ctx.r11.u32 + ctx.r10.u32, ctx.r8.u8);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// bdnz 0x82446ca0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82446CA0;
	// add r3,r31,r30
	ctx.r3.u64 = ctx.r31.u64 + ctx.r30.u64;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// li r5,50
	ctx.r5.s64 = 50;
	// bl 0x8273a030
	ctx.lr = 0x82446CD0;
	sub_8273A030(ctx, base);
	// addi r11,r31,50
	ctx.r11.s64 = ctx.r31.s64 + 50;
	// li r6,-1
	ctx.r6.s64 = -1;
	// clrlwi r5,r11,16
	ctx.r5.u64 = ctx.r11.u32 & 0xFFFF;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// li r3,2
	ctx.r3.s64 = 2;
	// bl 0x82429ff8
	ctx.lr = 0x82446CE8;
	sub_82429FF8(ctx, base);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82446cf8
	if (ctx.cr6.eq) goto loc_82446CF8;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x82446CF8;
	sub_825E0378(ctx, base);
loc_82446CF8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82452128) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82452130;
	__savegprlr_28(ctx, base);
	// li r12,-80
	ctx.r12.s64 = -80;
	// stvx128 v126,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v126.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r12,-64
	ctx.r12.s64 = -64;
	// stvx128 v127,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v127.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stwu r1,-272(r1)
	ea = -272 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245228c
	if (ctx.cr6.eq) goto loc_8245228C;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8245228c
	if (ctx.cr6.eq) goto loc_8245228C;
	// lwz r30,52(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 52);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8245228c
	if (ctx.cr6.eq) goto loc_8245228C;
	// lwz r11,72(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 72);
	// vspltisw128 v127,-1
	simde_mm_store_si128((simde__m128i*)ctx.v127.u32, simde_mm_set1_epi32(int(0xFFFFFFFF)));
	// li r28,255
	ctx.r28.s64 = 255;
	// li r31,0
	ctx.r31.s64 = 0;
	// stb r28,100(r1)
	REX_STORE_U8(ctx.r1.u32 + 100, ctx.r28.u8);
	// stb r28,101(r1)
	REX_STORE_U8(ctx.r1.u32 + 101, ctx.r28.u8);
	// vslw128 v126,v127,v127
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_sllv_epi32(a, shift));
	}
	// stb r28,102(r1)
	REX_STORE_U8(ctx.r1.u32 + 102, ctx.r28.u8);
	// stb r11,103(r1)
	REX_STORE_U8(ctx.r1.u32 + 103, ctx.r11.u8);
loc_82452190:
	// lwz r11,56(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 56);
	// rlwinm r10,r31,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xFFFFFFE0;
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// vslw128 v63,v127,v127
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v127.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi32(0x1F));
		simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_sllv_epi32(a, shift));
	}
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r10,r1,176
	ctx.r10.s64 = ctx.r1.s64 + 176;
	// addi r8,r1,144
	ctx.r8.s64 = ctx.r1.s64 + 144;
	// addi r7,r1,160
	ctx.r7.s64 = ctx.r1.s64 + 160;
	// cmplwi cr6,r31,4
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 4, ctx.xer);
	// lfs f0,16(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,20(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v61,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vxor128 v63,v61,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v63.u8)));
	// vxor128 v62,v62,v126
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_xor_si128(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v126.u8)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,160(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 160);
	ctx.f0.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,176(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 176);
	ctx.f13.f64 = double(temp.f32);
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lhz r10,110(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 110);
	// sth r10,118(r30)
	REX_STORE_U16(ctx.r30.u32 + 118, ctx.r10.u16);
	// fctiwz f0,f13
	ctx.f0.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// lhz r10,110(r1)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r1.u32 + 110);
	// sth r10,116(r30)
	REX_STORE_U16(ctx.r30.u32 + 116, ctx.r10.u16);
	// bne cr6,0x82452238
	if (!ctx.cr6.eq) goto loc_82452238;
	// stb r28,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r28.u8);
	// stb r28,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r28.u8);
	// stb r28,98(r1)
	REX_STORE_U8(ctx.r1.u32 + 98, ctx.r28.u8);
	// stb r28,99(r1)
	REX_STORE_U8(ctx.r1.u32 + 99, ctx.r28.u8);
	// lwz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// b 0x8245223c
	goto loc_8245223C;
loc_82452238:
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
loc_8245223C:
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// stfd f13,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.f13.u64);
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r6,116(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// mr r5,r31
	ctx.r5.u64 = ctx.r31.u64;
	// stb r8,87(r1)
	REX_STORE_U8(ctx.r1.u32 + 87, ctx.r8.u8);
	// li r4,31
	ctx.r4.s64 = 31;
	// lwz r9,60(r29)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r29.u32 + 60);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lfs f1,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f1.f64 = double(temp.f32);
	// clrlwi r9,r9,24
	ctx.r9.u64 = ctx.r9.u32 & 0xFF;
	// bl 0x823c09e0
	ctx.lr = 0x82452280;
	sub_823C09E0(ctx, base);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmplwi cr6,r31,6
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 6, ctx.xer);
	// blt cr6,0x82452190
	if (ctx.cr6.lt) goto loc_82452190;
loc_8245228C:
	// addi r1,r1,272
	ctx.r1.s64 = ctx.r1.s64 + 272;
	// li r0,-80
	ctx.r0.s64 = -80;
	// lvx128 v126,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v126.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r0,-64
	ctx.r0.s64 = -64;
	// lvx128 v127,r1,r0
	ea = (ctx.r1.u32 + ctx.r0.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v127.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824606F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82460700;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// li r29,0
	ctx.r29.s64 = 0;
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// stw r29,4(r3)
	REX_STORE_U32(ctx.r3.u32 + 4, ctx.r29.u32);
	// li r5,0
	ctx.r5.s64 = 0;
	// stw r29,32(r3)
	REX_STORE_U32(ctx.r3.u32 + 32, ctx.r29.u32);
	// addi r31,r11,22072
	ctx.r31.s64 = ctx.r11.s64 + 22072;
	// lfs f31,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// li r4,32
	ctx.r4.s64 = 32;
	// stfs f31,8(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stfs f31,12(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 12, temp.u32);
	// lwz r3,44(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// bl 0x825e02a0
	ctx.lr = 0x82460740;
	sub_825E02A0(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x82460750
	if (ctx.cr0.eq) goto loc_82460750;
	// bl 0x822131a0
	ctx.lr = 0x8246074C;
	sub_822131A0(ctx, base);
	// b 0x82460754
	goto loc_82460754;
loc_82460750:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
loc_82460754:
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// stw r3,40(r30)
	REX_STORE_U32(ctx.r30.u32 + 40, ctx.r3.u32);
	// addi r10,r30,160
	ctx.r10.s64 = ctx.r30.s64 + 160;
	// li r11,6
	ctx.r11.s64 = 6;
	// addi r9,r10,-4
	ctx.r9.s64 = ctx.r10.s64 + -4;
	// li r26,-1
	ctx.r26.s64 = -1;
	// lwz r10,-12840(r8)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + -12840);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwz r11,0(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// stfs f31,80(r11)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r11.u32 + 80, temp.u32);
loc_82460780:
	// stwu r8,4(r9)
	ea = 4 + ctx.r9.u32;
	REX_STORE_U32(ea, ctx.r8.u32);
	ctx.r9.u32 = ea;
	// bdnz 0x82460780
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82460780;
	// li r5,0
	ctx.r5.s64 = 0;
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// li r4,16
	ctx.r4.s64 = 16;
	// bl 0x825e02a0
	ctx.lr = 0x82460798;
	sub_825E02A0(ctx, base);
	// mr. r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// beq 0x82460828
	if (ctx.cr0.eq) goto loc_82460828;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8258c490
	ctx.lr = 0x824607A8;
	sub_8258C490(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,15596
	ctx.r11.s64 = ctx.r11.s64 + 15596;
	// li r4,44
	ctx.r4.s64 = 44;
	// stw r11,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r11.u32);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825e02a0
	ctx.lr = 0x824607C4;
	sub_825E02A0(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// beq 0x8246081c
	if (ctx.cr0.eq) goto loc_8246081C;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r28,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r28.u32);
	// li r10,-1
	ctx.r10.s64 = -1;
	// stw r29,12(r31)
	REX_STORE_U32(ctx.r31.u32 + 12, ctx.r29.u32);
	// addi r11,r11,-27424
	ctx.r11.s64 = ctx.r11.s64 + -27424;
	// stw r29,16(r31)
	REX_STORE_U32(ctx.r31.u32 + 16, ctx.r29.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// stw r10,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stw r29,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r29.u32);
	// addi r3,r31,4
	ctx.r3.s64 = ctx.r31.s64 + 4;
	// stb r29,40(r31)
	REX_STORE_U8(ctx.r31.u32 + 40, ctx.r29.u8);
	// li r5,0
	ctx.r5.s64 = 0;
	// stb r27,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r27.u8);
	// addi r4,r11,15572
	ctx.r4.s64 = ctx.r11.s64 + 15572;
	// bl 0x8245d000
	ctx.lr = 0x82460810;
	sub_8245D000(ctx, base);
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// stb r27,41(r31)
	REX_STORE_U8(ctx.r31.u32 + 41, ctx.r27.u8);
	// b 0x82460820
	goto loc_82460820;
loc_8246081C:
	// mr r11,r29
	ctx.r11.u64 = ctx.r29.u64;
loc_82460820:
	// stw r11,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r11.u32);
	// b 0x8246082c
	goto loc_8246082C;
loc_82460828:
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
loc_8246082C:
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8258a8c8
	ctx.lr = 0x82460838;
	sub_8258A8C8(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// stw r11,184(r30)
	REX_STORE_U32(ctx.r30.u32 + 184, ctx.r11.u32);
	// bl 0x8258c5e8
	ctx.lr = 0x8246084C;
	sub_8258C5E8(ctx, base);
	// li r11,8
	ctx.r11.s64 = 8;
	// stb r29,141(r30)
	REX_STORE_U8(ctx.r30.u32 + 141, ctx.r29.u8);
	// stb r29,142(r30)
	REX_STORE_U8(ctx.r30.u32 + 142, ctx.r29.u8);
	// stb r29,140(r30)
	REX_STORE_U8(ctx.r30.u32 + 140, ctx.r29.u8);
	// stb r29,152(r30)
	REX_STORE_U8(ctx.r30.u32 + 152, ctx.r29.u8);
	// stw r11,136(r30)
	REX_STORE_U32(ctx.r30.u32 + 136, ctx.r11.u32);
	// stb r29,153(r30)
	REX_STORE_U8(ctx.r30.u32 + 153, ctx.r29.u8);
	// stw r26,192(r30)
	REX_STORE_U32(ctx.r30.u32 + 192, ctx.r26.u32);
	// stw r26,196(r30)
	REX_STORE_U32(ctx.r30.u32 + 196, ctx.r26.u32);
	// bl 0x82213210
	ctx.lr = 0x82460874;
	sub_82213210(ctx, base);
	// stw r29,4028(r3)
	REX_STORE_U32(ctx.r3.u32 + 4028, ctx.r29.u32);
	// stb r29,154(r30)
	REX_STORE_U8(ctx.r30.u32 + 154, ctx.r29.u8);
	// stb r29,155(r30)
	REX_STORE_U8(ctx.r30.u32 + 155, ctx.r29.u8);
	// stb r29,132(r30)
	REX_STORE_U8(ctx.r30.u32 + 132, ctx.r29.u8);
	// stw r29,148(r30)
	REX_STORE_U32(ctx.r30.u32 + 148, ctx.r29.u32);
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8246E890) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8246E898;
	__savegprlr_29(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8246E8AC;
	sub_8235EC48(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r29,r11,-25908
	ctx.r29.s64 = ctx.r11.s64 + -25908;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// bl 0x8246b640
	ctx.lr = 0x8246E8C4;
	sub_8246B640(ctx, base);
	// lwz r11,104(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r3,84(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8246e8d8
	if (!ctx.cr6.lt) goto loc_8246E8D8;
	// addi r3,r1,84
	ctx.r3.s64 = ctx.r1.s64 + 84;
loc_8246E8D8:
	// lis r31,-32112
	ctx.r31.s64 = -2104492032;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// addi r30,r11,14592
	ctx.r30.s64 = ctx.r11.s64 + 14592;
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e910
	if (ctx.cr6.eq) goto loc_8246E910;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x8246E8F8;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e910
	if (ctx.cr6.eq) goto loc_8246E910;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x8246E910;
	sub_8246D8F0(ctx, base);
loc_8246E910:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8235ec48
	ctx.lr = 0x8246E920;
	sub_8235EC48(ctx, base);
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x8246E930;
	sub_8235EC48(ctx, base);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// li r5,2
	ctx.r5.s64 = 2;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8246b640
	ctx.lr = 0x8246E940;
	sub_8246B640(ctx, base);
	// lwz r11,136(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 136);
	// lwz r3,116(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bge cr6,0x8246e954
	if (!ctx.cr6.lt) goto loc_8246E954;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
loc_8246E954:
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e980
	if (ctx.cr6.eq) goto loc_8246E980;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x8246E968;
	sub_8246D8F0(ctx, base);
	// lwz r11,-12860(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + -12860);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8246e980
	if (ctx.cr6.eq) goto loc_8246E980;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x8246d8f0
	ctx.lr = 0x8246E980;
	sub_8246D8F0(ctx, base);
loc_8246E980:
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,1
	ctx.r4.s64 = 1;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x8235ec48
	ctx.lr = 0x8246E990;
	sub_8235EC48(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82473FD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82473FE0;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// cmpwi cr6,r5,1
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 1, ctx.xer);
	// lfs f13,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f13.f64 = double(temp.f32);
	// bne cr6,0x8247400c
	if (!ctx.cr6.eq) goto loc_8247400C;
	// lfs f13,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
loc_8247400C:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lis r10,-32224
	ctx.r10.s64 = -2111832064;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// lfs f0,-29492(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
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
	ctx.lr = 0x82474068;
	sub_8255F918(ctx, base);
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,18
	ctx.r4.s64 = 18;
	// li r3,8
	ctx.r3.s64 = 8;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// bl 0x82519328
	ctx.lr = 0x82474088;
	sub_82519328(ctx, base);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8247B590) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8247B598;
	__savegprlr_24(ctx, base);
	// stfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -88, ctx.f30.u64);
	// stfd f31,-80(r1)
	REX_STORE_U64(ctx.r1.u32 + -80, ctx.f31.u64);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r26,-32240
	ctx.r26.s64 = -2112880640;
	// lbz r30,184(r3)
	ctx.r30.u64 = REX_LOAD_U8(ctx.r3.u32 + 184);
	// lis r27,-32228
	ctx.r27.s64 = -2112094208;
	// lbz r29,185(r3)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r3.u32 + 185);
	// addi r25,r26,14376
	ctx.r25.s64 = ctx.r26.s64 + 14376;
	// lfs f30,12(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 12);
	ctx.f30.f64 = double(temp.f32);
	// addi r11,r27,1536
	ctx.r11.s64 = ctx.r27.s64 + 1536;
	// lbz r28,186(r3)
	ctx.r28.u64 = REX_LOAD_U8(ctx.r3.u32 + 186);
	// li r5,0
	ctx.r5.s64 = 0;
	// lbz r24,187(r3)
	ctx.r24.u64 = REX_LOAD_U8(ctx.r3.u32 + 187);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lfs f31,-1908(r25)
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + -1908);
	ctx.f31.f64 = double(temp.f32);
	// lfs f2,2904(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2904);
	ctx.f2.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x8247B5E0;
	sub_825A4A40(ctx, base);
	// lfs f0,712(r25)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + 712);
	ctx.f0.f64 = double(temp.f32);
	// fmadds f1,f30,f0,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, ctx.f1.f64)));
	// bl 0x82738be0
	ctx.lr = 0x8247B5EC;
	sub_82738BE0(ctx, base);
	// std r24,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r24.u64);
	// lfd f13,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lfs f0,1536(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 1536);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f1
	ctx.f12.f64 = double(float(ctx.f1.f64));
	// lfs f11,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f11.f64 = double(temp.f32);
	// frsp f10,f13
	ctx.f10.f64 = double(float(ctx.f13.f64));
	// lfs f13,14376(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 14376);
	ctx.f13.f64 = double(temp.f32);
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fsubs f13,f10,f11
	ctx.f13.f64 = double(float(ctx.f10.f64 - ctx.f11.f64));
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8247b628
	if (!ctx.cr6.lt) goto loc_8247B628;
	// fmr f0,f31
	ctx.f0.f64 = ctx.f31.f64;
loc_8247B628:
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// lis r10,8191
	ctx.r10.s64 = 536805376;
	// fctidz f0,f0
	ctx.fpscr.disableFlushMode();
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lbz r7,95(r1)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r1.u32 + 95);
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// stb r7,83(r1)
	REX_STORE_U8(ctx.r1.u32 + 83, ctx.r7.u8);
	// stb r30,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r30.u8);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// stb r29,81(r1)
	REX_STORE_U8(ctx.r1.u32 + 81, ctx.r29.u8);
	// rlwinm r4,r11,3,0,28
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r28,82(r1)
	REX_STORE_U8(ctx.r1.u32 + 82, ctx.r28.u8);
	// ble cr6,0x8247b664
	if (!ctx.cr6.gt) goto loc_8247B664;
	// li r4,-1
	ctx.r4.s64 = -1;
loc_8247B664:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x8247B678;
	sub_825E02A0(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8247b6f8
	if (ctx.cr6.eq) goto loc_8247B6F8;
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// addi r3,r31,16
	ctx.r3.s64 = ctx.r31.s64 + 16;
	// li r9,0
	ctx.r9.s64 = 0;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8247b6d8
	if (!ctx.cr6.gt) goto loc_8247B6D8;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// addi r10,r31,60
	ctx.r10.s64 = ctx.r31.s64 + 60;
loc_8247B6B0:
	// lfs f0,4(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfsu f13,8(r10)
	ea = 8 + ctx.r10.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r10.u32 = ea;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// ld r11,88(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// stdu r11,8(r8)
	ea = 8 + ctx.r8.u32;
	REX_STORE_U64(ea, ctx.r11.u64);
	ctx.r8.u32 = ea;
	// lwz r11,164(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// cmpw cr6,r9,r11
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x8247b6b0
	if (ctx.cr6.lt) goto loc_8247B6B0;
loc_8247B6D8:
	// addi r5,r11,1
	ctx.r5.s64 = ctx.r11.s64 + 1;
	// lwz r8,80(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lfs f1,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f1.f64 = double(temp.f32);
	// lwz r6,48(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// bl 0x8222cce8
	ctx.lr = 0x8247B6F0;
	sub_8222CCE8(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825e0378
	ctx.lr = 0x8247B6F8;
	sub_825E0378(ctx, base);
loc_8247B6F8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// lfd f30,-88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -88);
	// lfd f31,-80(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -80);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8248B3A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8248B3B0;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lhz r11,6(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 6);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lwz r9,128(r3)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r3.u32 + 128);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lwz r8,124(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// addi r31,r3,120
	ctx.r31.s64 = ctx.r3.s64 + 120;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
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
	// li r28,0
	ctx.r28.s64 = 0;
	// srawi. r11,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// fmuls f31,f13,f0
	ctx.f31.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// beq 0x8248b440
	if (ctx.cr0.eq) goto loc_8248B440;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8248B400:
	// lwz r11,124(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 124);
	// lfs f0,316(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 316);
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
	ctx.lr = 0x8248B420;
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
	// blt cr6,0x8248b400
	if (ctx.cr6.lt) goto loc_8248B400;
loc_8248B440:
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
	// beq 0x8248b4a0
	if (ctx.cr0.eq) goto loc_8248B4A0;
	// li r29,0
	ctx.r29.s64 = 0;
loc_8248B460:
	// lwz r11,140(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 140);
	// lfs f0,316(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 316);
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
	ctx.lr = 0x8248B480;
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
	// blt cr6,0x8248b460
	if (ctx.cr6.lt) goto loc_8248B460;
loc_8248B4A0:
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8246c998
	ctx.lr = 0x8248B4AC;
	sub_8246C998(ctx, base);
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82492558) {
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
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
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
	// bne 0x82492660
	if (!ctx.cr0.eq) goto loc_82492660;
	// lbz r11,308(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 308);
	// lfs f0,352(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,356(r3)
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 356);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f13,f13,f1,f0
	ctx.f13.f64 = double(float(std::fma(ctx.f13.f64, ctx.f1.f64, ctx.f0.f64)));
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// stfs f13,352(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 352, temp.u32);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// beq 0x824925ac
	if (ctx.cr0.eq) goto loc_824925AC;
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// lfs f0,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x824925b0
	goto loc_824925B0;
loc_824925AC:
	// lfs f0,12236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12236);
	ctx.f0.f64 = double(temp.f32);
loc_824925B0:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// fmuls f1,f13,f0
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,100(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 100);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824925CC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,404(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 404);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82492618
	if (ctx.cr6.lt) goto loc_82492618;
	// beq cr6,0x82492608
	if (ctx.cr6.eq) goto loc_82492608;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// beq cr6,0x824925f8
	if (ctx.cr6.eq) goto loc_824925F8;
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x82492624
	if (!ctx.cr6.eq) goto loc_82492624;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r31)
	REX_STORE_U8(ctx.r31.u32 + 23, ctx.r11.u8);
	// b 0x82492624
	goto loc_82492624;
loc_824925F8:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82493498
	ctx.lr = 0x82492604;
	sub_82493498(ctx, base);
	// b 0x82492624
	goto loc_82492624;
loc_82492608:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82492678
	ctx.lr = 0x82492614;
	sub_82492678(ctx, base);
	// b 0x82492624
	goto loc_82492624;
loc_82492618:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// fmr f1,f31
	ctx.fpscr.disableFlushMode();
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x82492ad8
	ctx.lr = 0x82492624;
	sub_82492AD8(ctx, base);
loc_82492624:
	// addi r5,r31,376
	ctx.r5.s64 = ctx.r31.s64 + 376;
	// addi r4,r31,44
	ctx.r4.s64 = ctx.r31.s64 + 44;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82322d08
	ctx.lr = 0x82492634;
	sub_82322D08(ctx, base);
	// lfs f2,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f2.f64 = double(temp.f32);
	// lfs f1,84(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x827397e8
	ctx.lr = 0x82492640;
	sub_827397E8(ctx, base);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// frsp f0,f1
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64));
	// stfs f0,396(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 396, temp.u32);
	// bl 0x82222370
	ctx.lr = 0x82492650;
	sub_82222370(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,400(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 400, temp.u32);
loc_82492660:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
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

DEFINE_REX_FUNC(sub_824A08B8) {
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
	// addi r11,r11,-21952
	ctx.r11.s64 = ctx.r11.s64 + -21952;
	// stw r11,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r11.u32);
	// bl 0x82469fb0
	ctx.lr = 0x824A08E0;
	sub_82469FB0(ctx, base);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4750
	ctx.lr = 0x824A08E8;
	sub_825A4750(ctx, base);
	// lwz r3,344(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 344);
	// addi r30,r31,340
	ctx.r30.s64 = ctx.r31.s64 + 340;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x824a08fc
	if (ctx.cr6.eq) goto loc_824A08FC;
	// bl 0x825e0378
	ctx.lr = 0x824A08FC;
	sub_825E0378(ctx, base);
loc_824A08FC:
	// li r11,0
	ctx.r11.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,4(r30)
	REX_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// stw r11,12(r30)
	REX_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// bl 0x82469ee8
	ctx.lr = 0x824A0914;
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

DEFINE_REX_FUNC(sub_824A3520) {
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
	// lwz r11,404(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 404);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// beq cr6,0x824a3554
	if (ctx.cr6.eq) goto loc_824A3554;
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222bb0
	ctx.lr = 0x824A354C;
	sub_82222BB0(ctx, base);
	// li r11,-1
	ctx.r11.s64 = -1;
	// stw r11,404(r31)
	REX_STORE_U32(ctx.r31.u32 + 404, ctx.r11.u32);
loc_824A3554:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82469fb0
	ctx.lr = 0x824A355C;
	sub_82469FB0(ctx, base);
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

DEFINE_REX_FUNC(sub_824A54B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x824A54B8;
	__savegprlr_21(ctx, base);
	// stfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// stwu r1,-384(r1)
	ea = -384 + ctx.r1.u32;
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
	ctx.lr = 0x824A54D4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x824a5d3c
	if (!ctx.cr0.eq) goto loc_824A5D3C;
	// lwz r11,364(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 364);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x824a5d3c
	if (ctx.cr6.eq) goto loc_824A5D3C;
	// lbz r11,400(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 400);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824a5d3c
	if (ctx.cr0.eq) goto loc_824A5D3C;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// li r29,0
	ctx.r29.s64 = 0;
	// addi r30,r31,280
	ctx.r30.s64 = ctx.r31.s64 + 280;
	// lis r23,-32111
	ctx.r23.s64 = -2104426496;
	// addi r22,r11,-32216
	ctx.r22.s64 = ctx.r11.s64 + -32216;
	// lfs f31,-32216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f31.f64 = double(temp.f32);
loc_824A550C:
	// lbz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x824a55c0
	if (ctx.cr0.eq) goto loc_824A55C0;
	// subfic r11,r29,3
	ctx.xer.ca = ctx.r29.u32 <= 3;
	ctx.r11.u64 = static_cast<uint64_t>(3) - ctx.r29.u64;
	// lwz r10,140(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f0,-26020(r23)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -26020);
	ctx.f0.f64 = double(temp.f32);
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f13,80(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lwz r3,0(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// frsp f13,f13
	ctx.f13.f64 = double(float(ctx.f13.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,120(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 120);
	// fadds f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f0.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fadds f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x824A5554;
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
	ctx.lr = 0x824A5570;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,64(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 64);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A558C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lfs f1,12(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
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
	ctx.lr = 0x824A55A8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,140(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x824A55C0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_824A55C0:
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r30,r30,20
	ctx.r30.s64 = ctx.r30.s64 + 20;
	// cmplwi cr6,r29,3
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 3, ctx.xer);
	// blt cr6,0x824a550c
	if (ctx.cr6.lt) goto loc_824A550C;
	// lwz r3,424(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// bl 0x8259be58
	ctx.lr = 0x824A55D8;
	sub_8259BE58(ctx, base);
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// lfs f0,352(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 352);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f13,344(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lhz r29,10(r3)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r3.u32 + 10);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lhz r27,8(r3)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r3.u32 + 8);
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// mr r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// twllei r29,0
	if (ctx.r29.s32 == 0 || ctx.r29.u32 < 0u) ppc_trap(ctx, base, 0);
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// twllei r29,0
	if (ctx.r29.s32 == 0 || ctx.r29.u32 < 0u) ppc_trap(ctx, base, 0);
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fabs f0,f0
	ctx.f0.u64 = ctx.f0.u64 & ~0x8000000000000000;
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// rotlwi r11,r9,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// rotlwi r10,r9,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r9.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// divw r8,r9,r29
	ctx.r8.u64 = uint32_t((ctx.r29.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r9.s32 / ctx.r29.s32 : 0);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// andc r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 & ~ctx.r11.u64;
	// andc r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 & ~ctx.r10.u64;
	// mullw r8,r8,r29
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r29.s32);
	// divw. r28,r9,r29
	ctx.r28.u64 = uint32_t((ctx.r29.s32 && !(ctx.r9.s32 == INT32_MIN && ctx.r29.s32 == -1)) ? ctx.r9.s32 / ctx.r29.s32 : 0);
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// twlgei r11,-1
	if (ctx.r11.s32 == -1 || ctx.r11.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// twlgei r10,-1
	if (ctx.r10.s32 == -1 || ctx.r10.u32 > 4294967295u) ppc_trap(ctx, base, 0);
	// subf r26,r8,r9
	ctx.r26.u64 = ctx.r9.u64 - ctx.r8.u64;
	// beq 0x824a5d3c
	if (ctx.cr0.eq) goto loc_824A5D3C;
	// li r25,0
	ctx.r25.s64 = 0;
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x824a5688
	if (ctx.cr6.eq) goto loc_824A5688;
	// li r25,1
	ctx.r25.s64 = 1;
loc_824A5688:
	// li r4,4
	ctx.r4.s64 = 4;
	// li r3,432
	ctx.r3.s64 = 432;
	// bl 0x825f8d38
	ctx.lr = 0x824A5694;
	sub_825F8D38(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x824a56c0
	if (ctx.cr0.eq) goto loc_824A56C0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8b88
	ctx.lr = 0x824A56A4;
	sub_825F8B88(ctx, base);
	// add r11,r25,r28
	ctx.r11.u64 = ctx.r25.u64 + ctx.r28.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// li r4,13
	ctx.r4.s64 = 13;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x825f8bf8
	ctx.lr = 0x824A56BC;
	sub_825F8BF8(ctx, base);
	// b 0x824a56c4
	goto loc_824A56C4;
loc_824A56C0:
	// li r30,0
	ctx.r30.s64 = 0;
loc_824A56C4:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r8,424(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 424);
	// li r10,-1
	ctx.r10.s64 = -1;
	// addi r9,r11,14376
	ctx.r9.s64 = ctx.r11.s64 + 14376;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// lfs f0,14376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 14376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,-1908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1908);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-2140(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2140);
	ctx.f13.f64 = double(temp.f32);
	// fmr f10,f12
	ctx.f10.f64 = ctx.f12.f64;
	// beq cr6,0x824a58dc
	if (ctx.cr6.eq) goto loc_824A58DC;
	// neg r11,r27
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r27.u64);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// extsw r9,r29
	ctx.r9.s64 = ctx.r29.s32;
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f11,80(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f9,80(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// extsw r9,r27
	ctx.r9.s64 = ctx.r27.s32;
	// fcfid f11,f11
	ctx.f11.f64 = double(ctx.f11.s64);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f8,80(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r11,r8,80
	ctx.r11.s64 = ctx.r8.s64 + 80;
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// mr r9,r28
	ctx.r9.u64 = ctx.r28.u64;
	// frsp f7,f11
	ctx.f7.f64 = double(float(ctx.f11.f64));
	// frsp f6,f9
	ctx.f6.f64 = double(float(ctx.f9.f64));
	// fmuls f9,f8,f0
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f0.f64));
	// fmuls f8,f6,f0
	ctx.f8.f64 = double(float(ctx.f6.f64 * ctx.f0.f64));
loc_824A575C:
	// lfs f11,380(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f11.f64 = double(temp.f32);
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// fmuls f11,f11,f8
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f8.f64));
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f10,148(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// stfs f10,100(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fadds f11,f7,f10
	ctx.f11.f64 = double(float(ctx.f7.f64 + ctx.f10.f64));
	// stfs f11,180(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// lwz r3,8(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stfs f11,116(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stw r3,-72(r11)
	REX_STORE_U32(ctx.r11.u32 + -72, ctx.r3.u32);
	// addi r3,r11,-80
	ctx.r3.s64 = ctx.r11.s64 + -80;
	// lwz r4,12(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// addi r21,r1,96
	ctx.r21.s64 = ctx.r1.s64 + 96;
	// lwz r3,4(r7)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// addic. r9,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r9.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lwz r7,0(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// stw r7,-80(r11)
	REX_STORE_U32(ctx.r11.u32 + -80, ctx.r7.u32);
	// stw r4,-68(r11)
	REX_STORE_U32(ctx.r11.u32 + -68, ctx.r4.u32);
	// stw r3,-76(r11)
	REX_STORE_U32(ctx.r11.u32 + -76, ctx.r3.u32);
	// lfs f10,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f10,f10,f8
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f8.f64));
	// stfs f10,176(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r7,12(r6)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r6.u32 + 12);
	// lwz r4,0(r6)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r6.u32 + 0);
	// lwz r3,4(r6)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r6.u32 + 4);
	// lwz r6,8(r6)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r6.u32 + 8);
	// stw r7,-28(r11)
	REX_STORE_U32(ctx.r11.u32 + -28, ctx.r7.u32);
	// stw r4,-40(r11)
	REX_STORE_U32(ctx.r11.u32 + -40, ctx.r4.u32);
	// stw r3,-36(r11)
	REX_STORE_U32(ctx.r11.u32 + -36, ctx.r3.u32);
	// stw r6,-32(r11)
	REX_STORE_U32(ctx.r11.u32 + -32, ctx.r6.u32);
	// lfs f10,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r7,4(r5)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// lwz r6,8(r5)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// lwz r4,12(r5)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r5.u32 + 12);
	// lwz r5,0(r5)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r6,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r6.u32);
	// stw r4,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r4.u32);
	// stw r5,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r5.u32);
	// lfs f10,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f10,f10,f9
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f9.f64));
	// stfs f10,96(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,8(r21)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r21.u32 + 8);
	// lwz r5,12(r21)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r21.u32 + 12);
	// lwz r4,0(r21)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r21.u32 + 0);
	// lwz r7,4(r21)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r21.u32 + 4);
	// stw r7,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r7.u32);
	// stw r4,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r4.u32);
	// stw r10,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// stw r6,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r6.u32);
	// stw r5,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r5.u32);
	// stw r10,-12(r11)
	REX_STORE_U32(ctx.r11.u32 + -12, ctx.r10.u32);
	// stw r10,-52(r11)
	REX_STORE_U32(ctx.r11.u32 + -52, ctx.r10.u32);
	// lfs f6,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f6.f64 = double(temp.f32);
	// lfs f10,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f10.f64 = double(temp.f32);
	// fneg f10,f10
	ctx.f10.u64 = ctx.f10.u64 ^ 0x8000000000000000;
	// fnmsubs f6,f6,f0,f0
	ctx.f6.f64 = double(float(-std::fma(ctx.f6.f64, ctx.f0.f64, -ctx.f0.f64)));
	// stfs f10,196(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// stfs f6,192(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// ld r7,192(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 192);
	// std r7,-48(r11)
	REX_STORE_U64(ctx.r11.u32 + -48, ctx.r7.u64);
	// lfs f6,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f6.f64 = double(temp.f32);
	// lfs f10,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f10.f64 = double(temp.f32);
	// fsubs f10,f13,f10
	ctx.f10.f64 = double(float(ctx.f13.f64 - ctx.f10.f64));
	// fnmsubs f6,f6,f0,f0
	ctx.f6.f64 = double(float(-std::fma(ctx.f6.f64, ctx.f0.f64, -ctx.f0.f64)));
	// stfs f10,164(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// stfs f6,160(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// ld r7,160(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// std r7,-8(r11)
	REX_STORE_U64(ctx.r11.u32 + -8, ctx.r7.u64);
	// lfs f6,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f6.f64 = double(temp.f32);
	// lfs f10,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f10.f64 = double(temp.f32);
	// fadds f10,f10,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// fsubs f6,f13,f6
	ctx.f6.f64 = double(float(ctx.f13.f64 - ctx.f6.f64));
	// stfs f6,132(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// fmuls f10,f10,f0
	ctx.f10.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f10,128(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// ld r7,128(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// std r7,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r7.u64);
	// fmr f10,f11
	ctx.f10.f64 = ctx.f11.f64;
	// lfs f11,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f11.f64 = double(temp.f32);
	// fadds f11,f11,f13
	ctx.f11.f64 = double(float(ctx.f11.f64 + ctx.f13.f64));
	// lfs f6,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f6.f64 = double(temp.f32);
	// fneg f6,f6
	ctx.f6.u64 = ctx.f6.u64 ^ 0x8000000000000000;
	// stfs f6,84(r1)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r7,80(r1)
	ctx.r7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r7,72(r11)
	REX_STORE_U64(ctx.r11.u32 + 72, ctx.r7.u64);
	// addi r11,r11,160
	ctx.r11.s64 = ctx.r11.s64 + 160;
	// bne 0x824a575c
	if (!ctx.cr0.eq) goto loc_824A575C;
loc_824A58DC:
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x824a5af4
	if (ctx.cr6.eq) goto loc_824A5AF4;
	// neg r11,r27
	ctx.r11.s64 = static_cast<int64_t>(-ctx.r27.u64);
	// stfs f12,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// mullw r9,r28,r29
	ctx.r9.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r29.s32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lfs f11,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f11.f64 = double(temp.f32);
	// stfs f12,120(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f12,184(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// stfs f12,152(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f13,156(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// clrldi r9,r9,32
	ctx.r9.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// mulli r11,r28,160
	ctx.r11.s64 = static_cast<int64_t>(ctx.r28.u64 * static_cast<uint64_t>(160));
	// std r9,160(r1)
	REX_STORE_U64(ctx.r1.u32 + 160, ctx.r9.u64);
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrldi r9,r26,32
	ctx.r9.u64 = ctx.r26.u64 & 0xFFFFFFFF;
	// addi r6,r11,40
	ctx.r6.s64 = ctx.r11.s64 + 40;
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f10,80(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f10,f10
	ctx.f10.f64 = double(ctx.f10.s64);
	// extsw r9,r27
	ctx.r9.s64 = ctx.r27.s32;
	// lfd f9,128(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// frsp f10,f10
	ctx.f10.f64 = double(float(ctx.f10.f64));
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfd f8,160(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + 160);
	// fcfid f8,f8
	ctx.f8.f64 = double(ctx.f8.s64);
	// std r9,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r9.u64);
	// lfd f7,80(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r9,r1,176
	ctx.r9.s64 = ctx.r1.s64 + 176;
	// frsp f9,f9
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// frsp f8,f8
	ctx.f8.f64 = double(float(ctx.f8.f64));
	// stfs f8,100(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f8,148(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// fmuls f9,f9,f0
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// fadds f8,f10,f8
	ctx.f8.f64 = double(float(ctx.f10.f64 + ctx.f8.f64));
	// stfs f8,116(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f8,180(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// fmuls f11,f11,f9
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f9.f64));
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lwz r6,12(r7)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// lwz r5,4(r7)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// lwz r4,0(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// lwz r7,8(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// stw r5,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r5.u32);
	// fcfid f7,f7
	ctx.f7.f64 = double(ctx.f7.s64);
	// stw r4,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r4.u32);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// lfs f8,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f8.f64 = double(temp.f32);
	// fmuls f9,f8,f9
	ctx.f9.f64 = double(float(ctx.f8.f64 * ctx.f9.f64));
	// stfs f9,112(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// lwz r5,4(r8)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// frsp f11,f7
	ctx.f11.f64 = double(float(ctx.f7.f64));
	// lwz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// lwz r7,8(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// stw r8,52(r11)
	REX_STORE_U32(ctx.r11.u32 + 52, ctx.r8.u32);
	// stw r7,48(r11)
	REX_STORE_U32(ctx.r11.u32 + 48, ctx.r7.u32);
	// fmuls f11,f11,f0
	ctx.f11.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stw r5,44(r11)
	REX_STORE_U32(ctx.r11.u32 + 44, ctx.r5.u32);
	// stw r6,40(r11)
	REX_STORE_U32(ctx.r11.u32 + 40, ctx.r6.u32);
	// lfs f9,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f9,f9,f11
	ctx.f9.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfs f9,176(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lwz r7,12(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// lwz r6,8(r9)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// stw r6,88(r11)
	REX_STORE_U32(ctx.r11.u32 + 88, ctx.r6.u32);
	// lwz r8,4(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,0(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// stw r9,80(r11)
	REX_STORE_U32(ctx.r11.u32 + 80, ctx.r9.u32);
	// addi r9,r1,144
	ctx.r9.s64 = ctx.r1.s64 + 144;
	// stw r8,84(r11)
	REX_STORE_U32(ctx.r11.u32 + 84, ctx.r8.u32);
	// stw r7,92(r11)
	REX_STORE_U32(ctx.r11.u32 + 92, ctx.r7.u32);
	// lfs f9,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f11,f9,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// stfs f11,144(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stw r10,148(r11)
	REX_STORE_U32(ctx.r11.u32 + 148, ctx.r10.u32);
	// extsw r8,r29
	ctx.r8.s64 = ctx.r29.s32;
	// stw r10,108(r11)
	REX_STORE_U32(ctx.r11.u32 + 108, ctx.r10.u32);
	// stw r10,68(r11)
	REX_STORE_U32(ctx.r11.u32 + 68, ctx.r10.u32);
	// stw r10,28(r11)
	REX_STORE_U32(ctx.r11.u32 + 28, ctx.r10.u32);
	// std r8,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r8.u64);
	// lwz r10,4(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// lwz r7,8(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// lwz r9,12(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 12);
	// stw r10,124(r11)
	REX_STORE_U32(ctx.r11.u32 + 124, ctx.r10.u32);
	// stw r8,120(r11)
	REX_STORE_U32(ctx.r11.u32 + 120, ctx.r8.u32);
	// stw r7,128(r11)
	REX_STORE_U32(ctx.r11.u32 + 128, ctx.r7.u32);
	// stw r9,132(r11)
	REX_STORE_U32(ctx.r11.u32 + 132, ctx.r9.u32);
	// lfd f9,80(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// lfs f11,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f11.f64 = double(temp.f32);
	// fneg f11,f11
	ctx.f11.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// lfs f8,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f8.f64 = double(temp.f32);
	// fnmsubs f8,f8,f0,f0
	ctx.f8.f64 = double(float(-std::fma(ctx.f8.f64, ctx.f0.f64, -ctx.f0.f64)));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// frsp f11,f9
	ctx.f11.f64 = double(float(ctx.f9.f64));
	// stfs f8,80(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,32(r11)
	REX_STORE_U64(ctx.r11.u32 + 32, ctx.r10.u64);
	// lfs f9,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f9.f64 = double(temp.f32);
	// fdivs f11,f10,f11
	ctx.f11.f64 = double(float(ctx.f10.f64 / ctx.f11.f64));
	// lfs f10,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f10.f64 = double(temp.f32);
	// fnmsubs f10,f10,f0,f0
	ctx.f10.f64 = double(float(-std::fma(ctx.f10.f64, ctx.f0.f64, -ctx.f0.f64)));
	// stfs f10,80(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// fsubs f9,f11,f9
	ctx.f9.f64 = double(float(ctx.f11.f64 - ctx.f9.f64));
	// stfs f9,84(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,72(r11)
	REX_STORE_U64(ctx.r11.u32 + 72, ctx.r10.u64);
	// lfs f10,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f10.f64 = double(temp.f32);
	// lfs f9,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f9.f64 = double(temp.f32);
	// fadds f9,f9,f13
	ctx.f9.f64 = double(float(ctx.f9.f64 + ctx.f13.f64));
	// fsubs f11,f11,f10
	ctx.f11.f64 = double(float(ctx.f11.f64 - ctx.f10.f64));
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f11,f9,f0
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,112(r11)
	REX_STORE_U64(ctx.r11.u32 + 112, ctx.r10.u64);
	// lfs f11,396(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 396);
	ctx.f11.f64 = double(temp.f32);
	// lfs f10,380(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 380);
	ctx.f10.f64 = double(temp.f32);
	// fadds f10,f10,f13
	ctx.f10.f64 = double(float(ctx.f10.f64 + ctx.f13.f64));
	// fneg f11,f11
	ctx.f11.u64 = ctx.f11.u64 ^ 0x8000000000000000;
	// stfs f11,84(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// fmuls f11,f10,f0
	ctx.f11.f64 = double(float(ctx.f10.f64 * ctx.f0.f64));
	// stfs f11,80(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,152(r11)
	REX_STORE_U64(ctx.r11.u32 + 152, ctx.r10.u64);
loc_824A5AF4:
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f11,344(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 344);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,108(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// stfs f11,100(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f11,104(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lfs f10,340(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 340);
	ctx.f10.f64 = double(temp.f32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f10,120(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r8,r1,208
	ctx.r8.s64 = ctx.r1.s64 + 208;
	// stfs f10,116(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
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
	// stfs f10,112(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r7,r1,224
	ctx.r7.s64 = ctx.r1.s64 + 224;
	// addi r6,r1,240
	ctx.r6.s64 = ctx.r1.s64 + 240;
	// stfs f11,96(r1)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r3,r1,256
	ctx.r3.s64 = ctx.r1.s64 + 256;
	// lwz r11,-12872(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12872);
	// vpermwi128 v63,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// vpermwi128 v62,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// stfs f10,124(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vpermwi128 v61,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v61.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// vpermwi128 v60,v59,171
	simde_mm_store_si128((simde__m128i*)ctx.v60.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x54));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v58,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v58,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq cr6,0x824a5b8c
	if (ctx.cr6.eq) goto loc_824A5B8C;
	// lfs f11,664(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 664);
	ctx.f11.f64 = double(temp.f32);
	// b 0x824a5b90
	goto loc_824A5B90;
loc_824A5B8C:
	// fmr f11,f13
	ctx.fpscr.disableFlushMode();
	ctx.f11.f64 = ctx.f13.f64;
loc_824A5B90:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// stfs f12,104(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// fdivs f11,f13,f11
	ctx.f11.f64 = double(float(ctx.f13.f64 / ctx.f11.f64));
	// vpermwi128 v58,v59,234
	simde_mm_store_si128((simde__m128i*)ctx.v58.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x15));
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vspltw128 v57,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v57.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// vspltw128 v56,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v56.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// lfs f10,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f10.f64 = double(temp.f32);
	// lwz r10,-15444(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + -15444);
	// vspltw128 v55,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v55.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// lwz r11,-15432(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + -15432);
	// vspltw128 v54,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v54.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// vmulfp128 v11,v57,v58
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vpermwi128 v0,v59,186
	simde_mm_store_si128((simde__m128i*)ctx.v0.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x45));
	// vmulfp128 v9,v56,v58
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v56.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v12,v63,1
	simde_mm_store_si128((simde__m128i*)ctx.v12.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xAA));
	// vmulfp128 v7,v55,v58
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v55.f32), simde_mm_load_ps(ctx.v58.f32)));
	// vspltw128 v10,v62,1
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xAA));
	// std r10,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r10.u64);
	// vmulfp128 v5,v54,v58
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v58.f32)));
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// vspltw128 v8,v61,1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xAA));
	// vspltw128 v6,v60,1
	simde_mm_store_si128((simde__m128i*)ctx.v6.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xAA));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// vpermwi128 v13,v59,174
	simde_mm_store_si128((simde__m128i*)ctx.v13.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0x51));
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// vspltw128 v4,v63,2
	simde_mm_store_si128((simde__m128i*)ctx.v4.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x55));
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// vspltw128 v3,v62,2
	simde_mm_store_si128((simde__m128i*)ctx.v3.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x55));
	// addi r8,r1,224
	ctx.r8.s64 = ctx.r1.s64 + 224;
	// vspltw128 v2,v61,2
	simde_mm_store_si128((simde__m128i*)ctx.v2.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x55));
	// addi r7,r1,240
	ctx.r7.s64 = ctx.r1.s64 + 240;
	// vspltw128 v1,v60,2
	simde_mm_store_si128((simde__m128i*)ctx.v1.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x55));
	// addi r6,r1,256
	ctx.r6.s64 = ctx.r1.s64 + 256;
	// vspltw128 v31,v63,3
	simde_mm_store_si128((simde__m128i*)ctx.v31.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0x0));
	// lwz r10,-15508(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + -15508);
	// vmaddfp v12,v12,v0,v11
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vspltw128 v30,v62,3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0x0));
	// vmaddfp v11,v10,v0,v9
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vspltw128 v29,v61,3
	simde_mm_store_si128((simde__m128i*)ctx.v29.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0x0));
	// vmaddfp v10,v8,v0,v7
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v7.f32)));
	// vspltw128 v28,v60,3
	simde_mm_store_si128((simde__m128i*)ctx.v28.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0x0));
	// vmaddfp v0,v6,v0,v5
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// lis r5,-32226
	ctx.r5.s64 = -2111963136;
	// li r4,12
	ctx.r4.s64 = 12;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r3,r5,1368
	ctx.r3.s64 = ctx.r5.s64 + 1368;
	// lfd f9,128(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f9,f9
	ctx.f9.f64 = double(ctx.f9.s64);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// vmaddfp v12,v4,v13,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v3,v13,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v3.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v10,v2,v13,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v2.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v13,v1,v13,v0
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// frsp f9,f9
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f9.f64 = double(float(ctx.f9.f64));
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f11
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f11.f64));
	// fmuls f11,f9,f11
	ctx.f11.f64 = double(float(ctx.f9.f64 * ctx.f11.f64));
	// fnmsubs f13,f12,f0,f13
	ctx.f13.f64 = double(float(-std::fma(ctx.f12.f64, ctx.f0.f64, -ctx.f13.f64)));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmsubs f0,f11,f0,f10
	ctx.f0.f64 = double(float(std::fma(ctx.f11.f64, ctx.f0.f64, -ctx.f10.f64)));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v0,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v12,v31,v0,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v31.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// vmaddfp v11,v30,v0,v11
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v30.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v11.f32)));
	// vmaddfp v10,v29,v0,v10
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v29.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vmaddfp v0,v28,v0,v13
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v28.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v12,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v10,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bctrl 
	ctx.lr = 0x824A5CBC;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// bl 0x8245a220
	ctx.lr = 0x824A5CC0;
	sub_8245A220(ctx, base);
	// stw r3,76(r30)
	REX_STORE_U32(ctx.r30.u32 + 76, ctx.r3.u32);
	// lfs f0,23572(r22)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r22.u32 + 23572);
	ctx.f0.f64 = double(temp.f32);
	// stw r24,208(r30)
	REX_STORE_U32(ctx.r30.u32 + 208, ctx.r24.u32);
	// lfs f13,-26020(r23)
	temp.u32 = REX_LOAD_U32(ctx.r23.u32 + -26020);
	ctx.f13.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,71(r30)
	REX_STORE_U8(ctx.r30.u32 + 71, ctx.r11.u8);
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lhz r11,6(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 6);
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// addi r4,r1,208
	ctx.r4.s64 = ctx.r1.s64 + 208;
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,4
	ctx.r11.u64 = ctx.r11.u64 | 4;
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// li r5,64
	ctx.r5.s64 = 64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// stfs f0,412(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 412, temp.u32);
	// lwz r11,3616(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 3616);
	// stw r11,368(r30)
	REX_STORE_U32(ctx.r30.u32 + 368, ctx.r11.u32);
	// lwz r11,408(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 408);
	// ori r11,r11,448
	ctx.r11.u64 = ctx.r11.u64 | 448;
	// stw r11,408(r30)
	REX_STORE_U32(ctx.r30.u32 + 408, ctx.r11.u32);
	// bl 0x8273a030
	ctx.lr = 0x824A5D2C;
	sub_8273A030(ctx, base);
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,5
	ctx.r4.s64 = 5;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82459d08
	ctx.lr = 0x824A5D3C;
	sub_82459D08(ctx, base);
loc_824A5D3C:
	// addi r1,r1,384
	ctx.r1.s64 = ctx.r1.s64 + 384;
	// lfd f31,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_824EBA18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x824EBA20;
	__savegprlr_22(ctx, base);
	// stfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-240(r1)
	ea = -240 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// mr r25,r6
	ctx.r25.u64 = ctx.r6.u64;
	// clrlwi r23,r10,24
	ctx.r23.u64 = ctx.r10.u32 & 0xFF;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// mr r26,r7
	ctx.r26.u64 = ctx.r7.u64;
	// mr r27,r8
	ctx.r27.u64 = ctx.r8.u64;
	// mr r24,r9
	ctx.r24.u64 = ctx.r9.u64;
	// mr r7,r5
	ctx.r7.u64 = ctx.r5.u64;
	// addi r4,r11,-25908
	ctx.r4.s64 = ctx.r11.s64 + -25908;
	// mr r9,r23
	ctx.r9.u64 = ctx.r23.u64;
	// li r8,2
	ctx.r8.s64 = 2;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r5,r25
	ctx.r5.u64 = ctx.r25.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x824EBA68;
	sub_825190E8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lwz r10,324(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 324);
	// li r30,0
	ctx.r30.s64 = 0;
	// addi r11,r11,-11496
	ctx.r11.s64 = ctx.r11.s64 + -11496;
	// addi r29,r31,352
	ctx.r29.s64 = ctx.r31.s64 + 352;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// stw r30,356(r31)
	REX_STORE_U32(ctx.r31.u32 + 356, ctx.r30.u32);
	// stw r30,360(r31)
	REX_STORE_U32(ctx.r31.u32 + 360, ctx.r30.u32);
	// stw r30,364(r31)
	REX_STORE_U32(ctx.r31.u32 + 364, ctx.r30.u32);
	// stb r10,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r10.u8);
	// lwz r3,4(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// bl 0x825a4640
	ctx.lr = 0x824EBA98;
	sub_825A4640(ctx, base);
	// lis r22,-32112
	ctx.r22.s64 = -2104492032;
	// lwz r11,-12816(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + -12816);
	// lwz r4,4(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r11,132(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 132);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// bl 0x825a48b0
	ctx.lr = 0x824EBAB4;
	sub_825A48B0(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r9,-32228
	ctx.r9.s64 = -2112094208;
	// stb r23,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r23.u8);
	// addi r11,r11,12236
	ctx.r11.s64 = ctx.r11.s64 + 12236;
	// stw r30,332(r31)
	REX_STORE_U32(ctx.r31.u32 + 332, ctx.r30.u32);
	// lis r6,-32226
	ctx.r6.s64 = -2111963136;
	// addi r7,r9,-6412
	ctx.r7.s64 = ctx.r9.s64 + -6412;
	// addic r10,r24,-1
	ctx.xer.ca = ctx.r24.u32 > 0;
	ctx.r10.s64 = ctx.r24.s64 + -1;
	// rlwinm r8,r25,4,12,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 4) & 0xFFFF0;
	// subfe r10,r10,r24
	temp.u8 = (~ctx.r10.u32 + ctx.r24.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r24.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r10.u64 = ~ctx.r10.u64 + ctx.r24.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// lfs f31,232(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 232);
	ctx.f31.f64 = double(temp.f32);
	// lfs f0,-30128(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -30128);
	ctx.f0.f64 = double(temp.f32);
	// stfs f31,292(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stb r10,320(r31)
	REX_STORE_U8(ctx.r31.u32 + 320, ctx.r10.u8);
	// stfs f0,296(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// lfs f30,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// lwz r9,-12816(r22)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r22.u32 + -12816);
	// lwz r9,172(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 172);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwz r8,0(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 0);
	// cmplw cr6,r8,r25
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r25.u32, ctx.xer);
	// bne cr6,0x824ebdb4
	if (!ctx.cr6.eq) goto loc_824EBDB4;
	// lwz r9,4(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 4);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x824ebdb4
	if (ctx.cr6.eq) goto loc_824EBDB4;
	// lwz r9,8(r9)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r9.u32 + 8);
	// rlwinm. r9,r9,31,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x824ebcbc
	if (ctx.cr0.eq) goto loc_824EBCBC;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r30,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r30.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stw r9,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r9.u32);
	// cmpwi cr6,r28,8
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 8, ctx.xer);
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lfs f0,4(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// bne cr6,0x824ebc14
	if (!ctx.cr6.eq) goto loc_824EBC14;
	// lis r9,-32225
	ctx.r9.s64 = -2111897600;
	// addi r8,r1,80
	ctx.r8.s64 = ctx.r1.s64 + 80;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r9,r9,32496
	ctx.r9.s64 = ctx.r9.s64 + 32496;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824ebb7c
	if (ctx.cr0.eq) goto loc_824EBB7C;
	// lfs f12,236(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x824ebb80
	goto loc_824EBB80;
loc_824EBB7C:
	// fmr f12,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f30.f64;
loc_824EBB80:
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lfs f0,0(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f13,4852(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4852);
	ctx.f13.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
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
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
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
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// b 0x824ebd9c
	goto loc_824EBD9C;
loc_824EBC14:
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r8,r8,32752
	ctx.r8.s64 = ctx.r8.s64 + 32752;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824ebc4c
	if (ctx.cr0.eq) goto loc_824EBC4C;
	// lfs f12,236(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
	// b 0x824ebc50
	goto loc_824EBC50;
loc_824EBC4C:
	// fmr f12,f30
	ctx.fpscr.disableFlushMode();
	ctx.f12.f64 = ctx.f30.f64;
loc_824EBC50:
	// lfs f13,-2544(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -2544);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// fmuls f13,f12,f13
	ctx.f13.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f13,80(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f13,92(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f13,88(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// b 0x824ebd74
	goto loc_824EBD74;
loc_824EBCBC:
	// stw r26,344(r31)
	REX_STORE_U32(ctx.r31.u32 + 344, ctx.r26.u32);
	// lis r8,-32224
	ctx.r8.s64 = -2111832064;
	// stw r30,316(r31)
	REX_STORE_U32(ctx.r31.u32 + 316, ctx.r30.u32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// addi r8,r8,-31744
	ctx.r8.s64 = ctx.r8.s64 + -31744;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// clrlwi. r10,r10,24
	ctx.r10.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,4(r27)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// beq 0x824ebd08
	if (ctx.cr0.eq) goto loc_824EBD08;
	// fmr f12,f30
	ctx.fpscr.disableFlushModeUnconditional();
	ctx.f12.f64 = ctx.f30.f64;
	// b 0x824ebd0c
	goto loc_824EBD0C;
loc_824EBD08:
	// lfs f12,236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f12.f64 = double(temp.f32);
loc_824EBD0C:
	// lfs f13,-2544(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -2544);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f12,f13
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f13.f64));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// lfs f0,0(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
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
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
loc_824EBD74:
	// lvx128 v61,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v61,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
loc_824EBD9C:
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r10,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r10.u64);
loc_824EBDB4:
	// lis r10,-32114
	ctx.r10.s64 = -2104623104;
	// lfs f0,18360(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 18360);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,300(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// lis r28,-32114
	ctx.r28.s64 = -2104623104;
	// lfs f13,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lfs f12,2044(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2044);
	ctx.f12.f64 = double(temp.f32);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// stfs f12,324(r31)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r31.u32 + 324, temp.u32);
	// lfs f0,-524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -524);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f13.f64));
	// stfs f0,304(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// lfs f2,-528(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -528);
	ctx.f2.f64 = double(temp.f32);
	// bl 0x825a4a40
	ctx.lr = 0x824EBDEC;
	sub_825A4A40(ctx, base);
	// stfs f1,308(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// lfs f2,-528(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -528);
	ctx.f2.f64 = double(temp.f32);
	// lwz r5,4(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// fmr f1,f31
	ctx.f1.f64 = ctx.f31.f64;
	// bl 0x825a4a40
	ctx.lr = 0x824EBE00;
	sub_825A4A40(ctx, base);
	// stfs f1,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stfs f30,68(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 68, temp.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// stfs f31,72(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 72, temp.u32);
	// stb r30,348(r31)
	REX_STORE_U8(ctx.r31.u32 + 348, ctx.r30.u8);
	// stfs f31,328(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 328, temp.u32);
	// bl 0x82217698
	ctx.lr = 0x824EBE1C;
	sub_82217698(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stb r30,271(r31)
	REX_STORE_U8(ctx.r31.u32 + 271, ctx.r30.u8);
	// addi r1,r1,240
	ctx.r1.s64 = ctx.r1.s64 + 240;
	// lfd f30,-104(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8250E288) {
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
	// bl 0x8250e2e0
	ctx.lr = 0x8250E2A8;
	sub_8250E2E0(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8250e2c0
	if (ctx.cr0.eq) goto loc_8250E2C0;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8250e2c0
	if (ctx.cr6.eq) goto loc_8250E2C0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8250E2C0;
	sub_825E0378(ctx, base);
loc_8250E2C0:
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

DEFINE_REX_FUNC(sub_8250F1E8) {
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
	// bl 0x8250f240
	ctx.lr = 0x8250F208;
	sub_8250F240(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8250f220
	if (ctx.cr0.eq) goto loc_8250F220;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x8250f220
	if (ctx.cr6.eq) goto loc_8250F220;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x8250F220;
	sub_825E0378(ctx, base);
loc_8250F220:
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

DEFINE_REX_FUNC(sub_82510490) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bnelr 
	if (!ctx.cr0.eq) return;
	// lwz r11,308(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 308);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bnelr cr6
	if (!ctx.cr6.eq) return;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lbz r10,304(r3)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r3.u32 + 304);
	// li r9,1
	ctx.r9.s64 = 1;
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// cmplwi r10,0
	ctx.cr0.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// stw r9,308(r3)
	REX_STORE_U32(ctx.r3.u32 + 308, ctx.r9.u32);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,296(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 296, temp.u32);
	// beq 0x825104d4
	if (ctx.cr0.eq) goto loc_825104D4;
	// lfs f11,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f11.f64 = double(temp.f32);
	// b 0x825104d8
	goto loc_825104D8;
loc_825104D4:
	// lfs f11,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f11.f64 = double(temp.f32);
loc_825104D8:
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// stfs f0,52(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 52, temp.u32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,20344
	ctx.r9.s64 = ctx.r11.s64 + 20344;
	// li r8,0
	ctx.r8.s64 = 0;
	// lfs f12,20344(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20344);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,-15720(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -15720);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,-8128(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8128);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 * ctx.f0.f64));
	// stfs f13,72(r3)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r3.u32 + 72, temp.u32);
	// fmuls f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 * ctx.f12.f64));
	// stfs f0,68(r3)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r3.u32 + 68, temp.u32);
	// stb r8,116(r3)
	REX_STORE_U8(ctx.r3.u32 + 116, ctx.r8.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82512CF8) {
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
	// bl 0x82512d50
	ctx.lr = 0x82512D18;
	sub_82512D50(ctx, base);
	// clrlwi. r11,r30,31
	ctx.r11.u64 = ctx.r30.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82512d30
	if (ctx.cr0.eq) goto loc_82512D30;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82512d30
	if (ctx.cr6.eq) goto loc_82512D30;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825e0378
	ctx.lr = 0x82512D30;
	sub_825E0378(ctx, base);
loc_82512D30:
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

DEFINE_REX_FUNC(sub_82516CF8) {
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
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8273af24
	ctx.lr = 0x82516D10;
	__savefpr_27(ctx, base);
	// stwu r1,-208(r1)
	ea = -208 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// std r5,240(r1)
	REX_STORE_U64(ctx.r1.u32 + 240, ctx.r5.u64);
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// fmr f31,f1
	ctx.fpscr.disableFlushMode();
	ctx.f31.f64 = ctx.f1.f64;
	// li r9,0
	ctx.r9.s64 = 0;
	// fmr f30,f2
	ctx.f30.f64 = ctx.f2.f64;
	// addi r4,r10,-5288
	ctx.r4.s64 = ctx.r10.s64 + -5288;
	// fmr f29,f3
	ctx.f29.f64 = ctx.f3.f64;
	// li r8,12
	ctx.r8.s64 = 12;
	// fmr f28,f4
	ctx.f28.f64 = ctx.f4.f64;
	// li r7,7
	ctx.r7.s64 = 7;
	// fmr f27,f5
	ctx.f27.f64 = ctx.f5.f64;
	// li r6,9
	ctx.r6.s64 = 9;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82516D54;
	sub_825190E8(ctx, base);
	// addi r11,r1,128
	ctx.r11.s64 = ctx.r1.s64 + 128;
	// addi r10,r1,128
	ctx.r10.s64 = ctx.r1.s64 + 128;
	// lfs f0,244(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,132(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lwz r6,308(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 308);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r5,300(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 300);
	// lfs f13,240(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 240);
	ctx.f13.f64 = double(temp.f32);
	// lwz r4,292(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 292);
	// stfs f13,128(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lis r3,-32225
	ctx.r3.s64 = -2111897600;
	// stfs f13,140(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// stfs f13,136(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// addi r3,r3,-5120
	ctx.r3.s64 = ctx.r3.s64 + -5120;
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stb r11,320(r31)
	REX_STORE_U8(ctx.r31.u32 + 320, ctx.r11.u8);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r11,324(r31)
	REX_STORE_U32(ctx.r31.u32 + 324, ctx.r11.u32);
	// stvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// fmr f1,f30
	ctx.f1.f64 = ctx.f30.f64;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r5,300(r31)
	REX_STORE_U32(ctx.r31.u32 + 300, ctx.r5.u32);
	// lfs f0,128(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 128);
	ctx.f0.f64 = double(temp.f32);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stb r6,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r6.u8);
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stb r4,80(r31)
	REX_STORE_U8(ctx.r31.u32 + 80, ctx.r4.u8);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// lfs f0,12468(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// stfs f31,296(r31)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r31.u32 + 296, temp.u32);
	// stfs f30,304(r31)
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r31.u32 + 304, temp.u32);
	// stfs f29,308(r31)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r31.u32 + 308, temp.u32);
	// stfs f27,312(r31)
	temp.f32 = float(ctx.f27.f64);
	REX_STORE_U32(ctx.r31.u32 + 312, temp.u32);
	// stfs f28,316(r31)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// bl 0x822ea1a8
	ctx.lr = 0x82516E0C;
	sub_822EA1A8(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// fmr f9,f1
	ctx.fpscr.disableFlushMode();
	ctx.f9.f64 = ctx.f1.f64;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// lfs f6,236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 236);
	ctx.f6.f64 = double(temp.f32);
	// fadds f1,f30,f6
	ctx.f1.f64 = double(float(ctx.f30.f64 + ctx.f6.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82516E24;
	sub_822EA1A8(ctx, base);
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// addi r30,r11,624
	ctx.r30.s64 = ctx.r11.s64 + 624;
	// lfs f0,984(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 984);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f1,f0
	ctx.f13.f64 = double(float(ctx.f1.f64 * ctx.f0.f64));
	// stfs f13,52(r31)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r31.u32 + 52, temp.u32);
	// fmuls f0,f9,f0
	ctx.f0.f64 = double(float(ctx.f9.f64 * ctx.f0.f64));
	// stfs f0,56(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 56, temp.u32);
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// cmplwi cr6,r11,30
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 30, ctx.xer);
	// bge cr6,0x82516f18
	if (!ctx.cr6.lt) goto loc_82516F18;
	// lfs f0,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,312(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// ble cr6,0x82516f18
	if (!ctx.cr6.gt) goto loc_82516F18;
	// ld r11,52(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 52);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,316(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 316, temp.u32);
	// std r11,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r11.u64);
	// std r10,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r10.u64);
	// bl 0x8255f918
	ctx.lr = 0x82516E84;
	sub_8255F918(ctx, base);
	// ld r3,0(r3)
	ctx.r3.u64 = REX_LOAD_U64(ctx.r3.u32 + 0);
	// bl 0x82517460
	ctx.lr = 0x82516E8C;
	sub_82517460(ctx, base);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82516f10
	if (!ctx.cr0.eq) goto loc_82516F10;
	// lfs f0,304(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f3,308(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 308);
	ctx.f3.f64 = double(temp.f32);
	// lfs f8,296(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 296);
	ctx.f8.f64 = double(temp.f32);
	// fmadds f2,f8,f3,f0
	ctx.f2.f64 = double(float(std::fma(ctx.f8.f64, ctx.f3.f64, ctx.f0.f64)));
	// fadds f1,f2,f6
	ctx.f1.f64 = double(float(ctx.f2.f64 + ctx.f6.f64));
	// bl 0x822ea1a8
	ctx.lr = 0x82516EAC;
	sub_822EA1A8(ctx, base);
	// lfs f9,0(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f9.f64 = double(temp.f32);
	// fmuls f0,f1,f9
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fmr f1,f2
	ctx.f1.f64 = ctx.f2.f64;
	// bl 0x822ea1a8
	ctx.lr = 0x82516EC0;
	sub_822EA1A8(ctx, base);
	// fmuls f0,f1,f9
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f1.f64 * ctx.f9.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// addi r3,r1,128
	ctx.r3.s64 = ctx.r1.s64 + 128;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// bl 0x8255f918
	ctx.lr = 0x82516EE0;
	sub_8255F918(ctx, base);
	// lbz r9,81(r31)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// lwz r11,300(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 300);
	// lfs f5,312(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 312);
	ctx.f5.f64 = double(temp.f32);
	// lbz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r31.u32 + 80);
	// lfs f4,316(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 316);
	ctx.f4.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// fmr f1,f8
	ctx.f1.f64 = ctx.f8.f64;
	// stw r9,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r9.u32);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// ld r4,128(r1)
	ctx.r4.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// bl 0x82516c48
	ctx.lr = 0x82516F10;
	sub_82516C48(ctx, base);
loc_82516F10:
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,320(r31)
	REX_STORE_U8(ctx.r31.u32 + 320, ctx.r11.u8);
loc_82516F18:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,208
	ctx.r1.s64 = ctx.r1.s64 + 208;
	// addi r12,r1,-24
	ctx.r12.s64 = ctx.r1.s64 + -24;
	// bl 0x8273af70
	ctx.lr = 0x82516F28;
	__restfpr_27(ctx, base);
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

DEFINE_REX_FUNC(sub_82528E80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82528E88;
	__savegprlr_26(ctx, base);
	// stwu r1,-192(r1)
	ea = -192 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lbz r11,23(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 23);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne 0x825290d8
	if (!ctx.cr0.eq) goto loc_825290D8;
	// lbz r11,289(r3)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r3.u32 + 289);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82528eb4
	if (ctx.cr0.eq) goto loc_82528EB4;
	// li r11,1
	ctx.r11.s64 = 1;
	// stb r11,23(r3)
	REX_STORE_U8(ctx.r3.u32 + 23, ctx.r11.u8);
	// b 0x825290d8
	goto loc_825290D8;
loc_82528EB4:
	// lbz r11,834(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 834);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82528efc
	if (ctx.cr0.eq) goto loc_82528EFC;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r30,r31,836
	ctx.r30.s64 = ctx.r31.s64 + 836;
	// li r6,256
	ctx.r6.s64 = 256;
	// lwz r3,88(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// li r4,0
	ctx.r4.s64 = 0;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// bl 0x82518670
	ctx.lr = 0x82528EE4;
	sub_82518670(ctx, base);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825290e0
	ctx.lr = 0x82528EF0;
	sub_825290E0(ctx, base);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,776(r31)
	REX_STORE_U32(ctx.r31.u32 + 776, ctx.r3.u32);
	// stb r11,834(r31)
	REX_STORE_U8(ctx.r31.u32 + 834, ctx.r11.u8);
loc_82528EFC:
	// lwz r11,772(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 772);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825290d8
	if (!ctx.cr6.eq) goto loc_825290D8;
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r9,88(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// rlwinm r10,r9,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFF0;
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
	// bne cr6,0x82528f38
	if (!ctx.cr6.eq) goto loc_82528F38;
	// lwz r3,4(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x82528f44
	if (!ctx.cr6.eq) goto loc_82528F44;
loc_82528F38:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// b 0x825290d4
	goto loc_825290D4;
loc_82528F44:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x82430a88
	ctx.lr = 0x82528F4C;
	sub_82430A88(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lwz r10,804(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 804);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// cmpwi cr6,r10,1
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 1, ctx.xer);
	// lfs f12,-236(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f12.f64 = double(temp.f32);
	// bne cr6,0x82528f68
	if (!ctx.cr6.eq) goto loc_82528F68;
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
loc_82528F68:
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 84);
	ctx.f0.f64 = double(temp.f32);
	// addi r9,r1,112
	ctx.r9.s64 = ctx.r1.s64 + 112;
	// lfs f13,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// lis r6,-32111
	ctx.r6.s64 = -2104426496;
	// lfs f0,-29492(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29492);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// fmuls f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r4,r6,3456
	ctx.r4.s64 = ctx.r6.s64 + 3456;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r30,r1,112
	ctx.r30.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r9,-32224
	ctx.r9.s64 = -2111832064;
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r9,r9,-31312
	ctx.r9.s64 = ctx.r9.s64 + -31312;
	// lfs f12,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f12.f64 = double(temp.f32);
	// addi r29,r1,112
	ctx.r29.s64 = ctx.r1.s64 + 112;
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r28,r1,112
	ctx.r28.s64 = ctx.r1.s64 + 112;
	// stfs f13,120(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// addi r7,r1,80
	ctx.r7.s64 = ctx.r1.s64 + 80;
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r27,r1,112
	ctx.r27.s64 = ctx.r1.s64 + 112;
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,96
	ctx.r26.s64 = ctx.r1.s64 + 96;
	// lfs f0,4(r4)
	temp.u32 = REX_LOAD_U32(ctx.r4.u32 + 4);
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
	// lvx128 v61,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v60,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v60,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f13,124(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stfs f13,120(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f13,116(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v60,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v60
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v60.f32)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// lvx128 v63,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v61,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f13,124(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lfs f0,3456(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 3456);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v62,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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
	// stvx128 v63,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// addi r10,r1,112
	ctx.r10.s64 = ctx.r1.s64 + 112;
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lvx128 v63,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
loc_825290D4:
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
loc_825290D8:
	// addi r1,r1,192
	ctx.r1.s64 = ctx.r1.s64 + 192;
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8253F1D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x8253F1D8;
	__savegprlr_28(ctx, base);
	// stfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -48, ctx.f31.u64);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x82218310
	ctx.lr = 0x8253F1E8;
	sub_82218310(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f0,8(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f0.f64 = double(temp.f32);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lfs f31,12468(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12468);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// beq cr6,0x8253f3a4
	if (ctx.cr6.eq) goto loc_8253F3A4;
	// lis r28,-32228
	ctx.r28.s64 = -2112094208;
	// lfs f0,60(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-1628(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1628);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8253f254
	if (!ctx.cr6.lt) goto loc_8253F254;
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bne cr6,0x8253f244
	if (!ctx.cr6.eq) goto loc_8253F244;
	// lfs f0,20(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 20);
	ctx.f0.f64 = double(temp.f32);
	// li r3,125
	ctx.r3.s64 = 125;
	// lfs f13,16(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.f0.u64);
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// bl 0x82240a58
	ctx.lr = 0x8253F244;
	sub_82240A58(ctx, base);
loc_8253F244:
	// lfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,8(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// b 0x8253f3a0
	goto loc_8253F3A0;
loc_8253F254:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// li r5,0
	ctx.r5.s64 = 0;
	// addi r11,r11,22072
	ctx.r11.s64 = ctx.r11.s64 + 22072;
	// li r4,112
	ctx.r4.s64 = 112;
	// lwz r3,48(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 48);
	// bl 0x825e02a0
	ctx.lr = 0x8253F26C;
	sub_825E02A0(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq 0x8253f2e0
	if (ctx.cr0.eq) goto loc_8253F2E0;
	// lhz r11,58(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 58);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// extsw r11,r11
	ctx.r11.s64 = ctx.r11.s32;
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// std r11,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r11.u64);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r4,r8,1804
	ctx.r4.s64 = ctx.r8.s64 + 1804;
	// lfd f0,88(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lfs f0,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f13
	ctx.f12.f64 = double(float(ctx.f13.f64));
	// lfs f13,-9908(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9908);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f1,f12,f0,f13
	ctx.f1.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// bl 0x822237b8
	ctx.lr = 0x8253F2B0;
	sub_822237B8(ctx, base);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// stfs f31,100(r30)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r30.u32 + 100, temp.u32);
	// lis r9,-32114
	ctx.r9.s64 = -2104623104;
	// addi r11,r11,2048
	ctx.r11.s64 = ctx.r11.s64 + 2048;
	// li r10,103
	ctx.r10.s64 = 103;
	// stw r11,0(r30)
	REX_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// li r11,0
	ctx.r11.s64 = 0;
	// sth r10,96(r30)
	REX_STORE_U16(ctx.r30.u32 + 96, ctx.r10.u16);
	// lfs f0,3312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 3312);
	ctx.f0.f64 = double(temp.f32);
	// stw r11,108(r30)
	REX_STORE_U32(ctx.r30.u32 + 108, ctx.r11.u32);
	// stfs f0,104(r30)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r30.u32 + 104, temp.u32);
	// b 0x8253f2e4
	goto loc_8253F2E4;
loc_8253F2E0:
	// li r30,0
	ctx.r30.s64 = 0;
loc_8253F2E4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8253f378
	if (ctx.cr6.eq) goto loc_8253F378;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// addi r4,r31,16
	ctx.r4.s64 = ctx.r31.s64 + 16;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r11,24(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 24);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8253F304;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lwz r9,64(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r11,12416
	ctx.r11.s64 = ctx.r11.s64 + 12416;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwz r10,36(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// lfsx f13,r9,r11
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f1,f13,f0
	ctx.f1.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8253F334;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,68(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 68);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bge cr6,0x8253f348
	if (!ctx.cr6.lt) goto loc_8253F348;
	// li r11,2
	ctx.r11.s64 = 2;
	// stb r11,90(r30)
	REX_STORE_U8(ctx.r30.u32 + 90, ctx.r11.u8);
loc_8253F348:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82222ad8
	ctx.lr = 0x8253F354;
	sub_82222AD8(ctx, base);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// cmpwi cr6,r11,-1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, -1, ctx.xer);
	// bne cr6,0x8253f378
	if (!ctx.cr6.eq) goto loc_8253F378;
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
	ctx.lr = 0x8253F378;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8253F378:
	// lwz r11,64(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// li r10,3
	ctx.r10.s64 = 3;
	// lfs f13,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 60);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// lfs f0,-1628(r28)
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + -1628);
	ctx.f0.f64 = double(temp.f32);
	// fsubs f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// subfc r10,r10,r11
	ctx.xer.ca = ctx.r11.u32 >= ctx.r10.u32;
	ctx.r10.u64 = ctx.r11.u64 - ctx.r10.u64;
	// stw r11,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r11.u32);
	// subfe r11,r10,r10
	temp.u8 = (~ctx.r10.u32 + ctx.r10.u32 < ~ctx.r10.u32) | (~ctx.r10.u32 + ctx.r10.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r10.u64 + ctx.r10.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 & ctx.r29.u64;
loc_8253F3A0:
	// stfs f0,60(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 60, temp.u32);
loc_8253F3A4:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// lfd f31,-48(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -48);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254A618) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8254A620;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,384(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 384);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8254a6b8
	if (ctx.cr6.eq) goto loc_8254A6B8;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
loc_8254A63C:
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8254a6a8
	if (ctx.cr6.eq) goto loc_8254A6A8;
	// lwz r10,-12816(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + -12816);
	// rlwinm r8,r11,4,12,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFF0;
	// clrlwi r9,r11,16
	ctx.r9.u64 = ctx.r11.u32 & 0xFFFF;
	// lwz r10,172(r10)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r10.u32 + 172);
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r7,0(r8)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r8.u32 + 0);
	// cmplw cr6,r7,r11
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254a678
	if (!ctx.cr6.eq) goto loc_8254A678;
	// lwz r8,4(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// li r8,1
	ctx.r8.s64 = 1;
	// bne cr6,0x8254a67c
	if (!ctx.cr6.eq) goto loc_8254A67C;
loc_8254A678:
	// li r8,0
	ctx.r8.s64 = 0;
loc_8254A67C:
	// clrlwi. r8,r8,24
	ctx.r8.u64 = ctx.r8.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq 0x8254a6a8
	if (ctx.cr0.eq) goto loc_8254A6A8;
	// rlwinm r9,r9,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// cmplw cr6,r9,r11
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254a6a8
	if (!ctx.cr6.eq) goto loc_8254A6A8;
	// lwz r3,4(r10)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x8254a6a8
	if (ctx.cr6.eq) goto loc_8254A6A8;
	// bl 0x8254a900
	ctx.lr = 0x8254A6A8;
	sub_8254A900(ctx, base);
loc_8254A6A8:
	// lwz r31,0(r31)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lwz r11,384(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 384);
	// cmplw cr6,r31,r11
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254a63c
	if (!ctx.cr6.eq) goto loc_8254A63C;
loc_8254A6B8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8254DE98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x8254DEA0;
	__savegprlr_22(ctx, base);
	// stfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f29.u64);
	// stfd f30,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f30.u64);
	// stfd f31,-96(r1)
	REX_STORE_U64(ctx.r1.u32 + -96, ctx.f31.u64);
	// stwu r1,-528(r1)
	ea = -528 + ctx.r1.u32;
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
	ctx.lr = 0x8254DEC4;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// clrlwi. r11,r3,24
	ctx.r11.u64 = ctx.r3.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8254e274
	if (!ctx.cr0.eq) goto loc_8254E274;
	// lwz r11,332(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 332);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8254e274
	if (!ctx.cr6.eq) goto loc_8254E274;
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8254e274
	if (!ctx.cr6.gt) goto loc_8254E274;
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r25,-32112
	ctx.r25.s64 = -2104492032;
	// lis r9,-32226
	ctx.r9.s64 = -2111963136;
	// li r8,1
	ctx.r8.s64 = 1;
	// ld r11,3456(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 3456);
	// addi r9,r9,2688
	ctx.r9.s64 = ctx.r9.s64 + 2688;
	// ld r10,3128(r10)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r10.u32 + 3128);
	// li r22,0
	ctx.r22.s64 = 0;
	// lwz r27,-13032(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + -13032);
	// stw r9,288(r1)
	REX_STORE_U32(ctx.r1.u32 + 288, ctx.r9.u32);
	// stw r8,292(r1)
	REX_STORE_U32(ctx.r1.u32 + 292, ctx.r8.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// std r11,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r11.u64);
	// std r10,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r10.u64);
	// beq cr6,0x8254df50
	if (ctx.cr6.eq) goto loc_8254DF50;
	// lfs f0,48(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 48);
	ctx.f0.f64 = double(temp.f32);
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// lfs f13,44(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 44);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f0,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.f0.u64);
	// stfd f13,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.f13.u64);
	// lwz r5,108(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// bl 0x823aefa8
	ctx.lr = 0x8254DF4C;
	sub_823AEFA8(ctx, base);
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
loc_8254DF50:
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8254e274
	if (ctx.cr6.eq) goto loc_8254E274;
	// lis r8,-32240
	ctx.r8.s64 = -2112880640;
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32242
	ctx.r10.s64 = -2113011712;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// addi r26,r11,32736
	ctx.r26.s64 = ctx.r11.s64 + 32736;
	// lfs f29,12468(r8)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 12468);
	ctx.f29.f64 = double(temp.f32);
	// addi r24,r10,31600
	ctx.r24.s64 = ctx.r10.s64 + 31600;
	// addi r23,r9,2880
	ctx.r23.s64 = ctx.r9.s64 + 2880;
loc_8254DF80:
	// lfs f0,16(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f29
	ctx.cr6.compare(ctx.f0.f64, ctx.f29.f64);
	// ble cr6,0x8254e214
	if (!ctx.cr6.gt) goto loc_8254E214;
	// ld r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lfs f13,8(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// stfs f13,172(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// stfs f13,168(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// addi r8,r1,320
	ctx.r8.s64 = ctx.r1.s64 + 320;
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// li r7,432
	ctx.r7.s64 = 432;
	// std r11,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r11.u64);
	// stfs f13,160(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// lfs f13,116(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 116);
	ctx.f13.f64 = double(temp.f32);
	// addi r11,r1,272
	ctx.r11.s64 = ctx.r1.s64 + 272;
	// lvx128 v8,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,400
	ctx.r6.s64 = ctx.r1.s64 + 400;
	// vor v10,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_load_si128((simde__m128i*)ctx.v8.u8));
	// vrefp v13,v8
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v8.f32)));
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// vcmpeqfp128 v2,v8,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,204(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 204, temp.u32);
	// addi r5,r1,256
	ctx.r5.s64 = ctx.r1.s64 + 256;
	// vrefp v12,v10
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v12.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v10.f32)));
	// stfs f0,200(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 200, temp.u32);
	// vcmpeqfp128 v7,v13,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v7.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,196(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 196, temp.u32);
	// vcmpeqfp128 v9,v10,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v9.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,192(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 192, temp.u32);
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lvx128 v0,r24,r7
	ea = (ctx.r24.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// lfs f12,12(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// vnmsubfp v1,v8,v13,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f12,252(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 252, temp.u32);
	// addi r4,r1,352
	ctx.r4.s64 = ctx.r1.s64 + 352;
	// stfs f12,248(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 248, temp.u32);
	// li r29,1
	ctx.r29.s64 = 1;
	// stfs f12,244(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 244, temp.u32);
	// li r28,3
	ctx.r28.s64 = 3;
	// stfs f12,240(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 240, temp.u32);
	// stfs f13,284(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 284, temp.u32);
	// stfs f13,280(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 280, temp.u32);
	// vcmpeqfp128 v11,v12,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v11.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v62,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,276(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 276, temp.u32);
	// vnmsubfp v5,v10,v12,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f13,272(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 272, temp.u32);
	// vmaddfp v6,v13,v1,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v6.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v1.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsel v3,v2,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8))));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubfp128 v63,v63,v62
	simde_mm_store_ps(ctx.v63.f32, simde_mm_sub_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,320(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 320);
	ctx.f0.f64 = double(temp.f32);
	// vmaddfp v5,v12,v5,v12
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v5.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v12.f32)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v7,v8,v6,v0
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v6.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// stfs f0,268(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 268, temp.u32);
	// vsel v4,v9,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// stfs f0,264(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 264, temp.u32);
	// addi r11,r1,384
	ctx.r11.s64 = ctx.r1.s64 + 384;
	// stfs f0,260(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 260, temp.u32);
	// stfs f0,256(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 256, temp.u32);
	// lfs f0,400(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 400);
	ctx.f0.f64 = double(temp.f32);
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v0,v10,v5,v0
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v5.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v11,v6,v7,v6
	simde_mm_store_ps(ctx.v11.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v6.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vmaddfp v0,v5,v0,v5
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v5.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vsel v10,v11,v13,v3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v63,v63,v10
	simde_mm_store_ps(ctx.v63.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v10.f32)));
	// vsel v13,v0,v12,v4
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// stfs f0,140(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// lvx128 v62,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v62,v62,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v13.f32)));
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f31,352(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 352);
	ctx.f31.f64 = double(temp.f32);
	// lfs f30,384(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 384);
	ctx.f30.f64 = double(temp.f32);
loc_8254E0D8:
	// ld r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r31.u32 + 44);
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// std r11,312(r1)
	REX_STORE_U64(ctx.r1.u32 + 312, ctx.r11.u64);
	// mr r8,r10
	ctx.r8.u64 = ctx.r10.u64;
	// addi r11,r1,208
	ctx.r11.s64 = ctx.r1.s64 + 208;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// std r10,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.r10.u64);
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// std r8,112(r1)
	REX_STORE_U64(ctx.r1.u32 + 112, ctx.r8.u64);
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,220(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 220, temp.u32);
	// addi r6,r1,176
	ctx.r6.s64 = ctx.r1.s64 + 176;
	// lfd f13,312(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + 312);
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// fcfid f12,f13
	ctx.f12.f64 = double(ctx.f13.s64);
	// lfs f13,124(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 124);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,236(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 236, temp.u32);
	// cmplwi cr6,r27,0
	ctx.cr6.compare<uint32_t>(ctx.r27.u32, 0, ctx.xer);
	// stfs f13,232(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 232, temp.u32);
	// stfs f13,228(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 228, temp.u32);
	// stfs f13,224(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 224, temp.u32);
	// lvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,216(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 216, temp.u32);
	// stfs f0,212(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 212, temp.u32);
	// stfs f0,208(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 208, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// frsp f0,f12
	ctx.f0.f64 = double(float(ctx.f12.f64));
	// fmuls f13,f30,f0
	ctx.f13.f64 = double(float(ctx.f30.f64 * ctx.f0.f64));
	// stfs f13,188(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
	// fmuls f0,f31,f0
	ctx.f0.f64 = double(float(ctx.f31.f64 * ctx.f0.f64));
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
	// lvx128 v61,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,184(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f13,180(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v62,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// lfs f0,336(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 336);
	ctx.f0.f64 = double(temp.f32);
	// fadds f13,f0,f31
	ctx.f13.f64 = double(float(ctx.f0.f64 + ctx.f31.f64));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// fsubs f0,f0,f31
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f31.f64));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,368(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 368);
	ctx.f13.f64 = double(temp.f32);
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// fadds f0,f13,f30
	ctx.f0.f64 = double(float(ctx.f13.f64 + ctx.f30.f64));
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// fsubs f0,f13,f30
	ctx.f0.f64 = double(float(ctx.f13.f64 - ctx.f30.f64));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// ld r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// ld r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + 104);
	// std r10,296(r1)
	REX_STORE_U64(ctx.r1.u32 + 296, ctx.r10.u64);
	// std r11,304(r1)
	REX_STORE_U64(ctx.r1.u32 + 304, ctx.r11.u64);
	// beq cr6,0x8254e200
	if (ctx.cr6.eq) goto loc_8254E200;
	// lbz r11,81(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 81);
	// lfs f0,196(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 196);
	ctx.f0.f64 = double(temp.f32);
	// fctidz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x8000000000000000ULL) : (ctx.f0.f64 > double(LLONG_MAX)) ? LLONG_MAX : simde_mm_cvttsd_si64(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,120(r1)
	REX_STORE_U64(ctx.r1.u32 + 120, ctx.f0.u64);
	// mr r10,r23
	ctx.r10.u64 = ctx.r23.u64;
	// lfs f1,200(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 200);
	ctx.f1.f64 = double(temp.f32);
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// addi r3,r1,288
	ctx.r3.s64 = ctx.r1.s64 + 288;
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// stw r11,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// lwz r4,100(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// lwz r8,124(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x823b0938
	ctx.lr = 0x8254E1FC;
	sub_823B0938(ctx, base);
	// lwz r27,-13032(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + -13032);
loc_8254E200:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// bne 0x8254e0d8
	if (!ctx.cr0.eq) goto loc_8254E0D8;
	// lwz r30,0(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// b 0x8254e268
	goto loc_8254E268;
loc_8254E214:
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// addi r30,r31,320
	ctx.r30.s64 = ctx.r31.s64 + 320;
	// lwz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r3,r11
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x8254e254
	if (ctx.cr6.eq) goto loc_8254E254;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r11,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r11.u32);
	// bl 0x825e0378
	ctx.lr = 0x8254E244;
	sub_825E0378(ctx, base);
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// lwz r27,-13032(r25)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r25.u32 + -13032);
loc_8254E254:
	// lwz r11,328(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 328);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// ble cr6,0x8254e274
	if (!ctx.cr6.gt) goto loc_8254E274;
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// lwz r30,0(r11)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
loc_8254E268:
	// lwz r11,324(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 324);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x8254df80
	if (!ctx.cr6.eq) goto loc_8254DF80;
loc_8254E274:
	// addi r1,r1,528
	ctx.r1.s64 = ctx.r1.s64 + 528;
	// lfd f29,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f29.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f30,-104(r1)
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// lfd f31,-96(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -96);
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82573340) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82573348;
	__savegprlr_28(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r28,r7
	ctx.r28.u64 = ctx.r7.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// li r9,0
	ctx.r9.s64 = 0;
	// li r8,12
	ctx.r8.s64 = 12;
	// li r7,71
	ctx.r7.s64 = 71;
	// li r6,10
	ctx.r6.s64 = 10;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// bl 0x825190e8
	ctx.lr = 0x82573378;
	sub_825190E8(ctx, base);
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// stb r28,81(r31)
	REX_STORE_U8(ctx.r31.u32 + 81, ctx.r28.u8);
	// addi r11,r11,12472
	ctx.r11.s64 = ctx.r11.s64 + 12472;
	// addi r10,r10,12336
	ctx.r10.s64 = ctx.r10.s64 + 12336;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// stw r10,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r10.u32);
	// lfs f0,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,292(r31)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 292, temp.u32);
	// bne cr6,0x825733a8
	if (!ctx.cr6.eq) goto loc_825733A8;
	// lfs f0,-236(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -236);
	ctx.f0.f64 = double(temp.f32);
	// b 0x825733ac
	goto loc_825733AC;
loc_825733A8:
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
loc_825733AC:
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r9,100(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 100);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,88(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 88);
	// ori r6,r10,32
	ctx.r6.u64 = ctx.r10.u64 | 32;
	// li r30,0
	ctx.r30.s64 = 0;
	// stfs f0,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r31.u32 + 300, temp.u32);
	// rlwimi r9,r8,0,30,31
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x3) | (ctx.r9.u64 & 0xFFFFFFFFFFFFFFFC);
	// stw r6,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// lwz r11,-12816(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + -12816);
	// rlwinm r10,r7,4,12,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 4) & 0xFFFF0;
	// stw r30,304(r31)
	REX_STORE_U32(ctx.r31.u32 + 304, ctx.r30.u32);
	// stw r9,100(r31)
	REX_STORE_U32(ctx.r31.u32 + 100, ctx.r9.u32);
	// lwz r11,172(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 172);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x8257343c
	if (!ctx.cr6.eq) goto loc_8257343C;
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8257343c
	if (ctx.cr6.eq) goto loc_8257343C;
	// lwz r10,8(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// rlwinm. r10,r10,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x8257343c
	if (ctx.cr0.eq) goto loc_8257343C;
	// lwz r10,2340(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 2340);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8257343c
	if (ctx.cr6.eq) goto loc_8257343C;
	// rotlwi r3,r10,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,652(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 652);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82573430;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,1
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 1, ctx.xer);
	// bne cr6,0x8257343c
	if (!ctx.cr6.eq) goto loc_8257343C;
	// li r30,1
	ctx.r30.s64 = 1;
loc_8257343C:
	// clrlwi. r11,r30,24
	ctx.r11.u64 = ctx.r30.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lfs f13,300(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 300);
	ctx.f13.f64 = double(temp.f32);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f12,0(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// addi r6,r1,112
	ctx.r6.s64 = ctx.r1.s64 + 112;
	// lfs f0,-32216(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32216);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// bne 0x82573520
	if (!ctx.cr0.eq) goto loc_82573520;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// stfs f12,84(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// stfs f12,92(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stfs f12,88(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// stfs f12,80(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// addi r4,r1,112
	ctx.r4.s64 = ctx.r1.s64 + 112;
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// stfs f0,100(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r7,r7,-31872
	ctx.r7.s64 = ctx.r7.s64 + -31872;
	// lfs f13,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// lvx128 v62,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v63,v62
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v62.f32)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r1,96
	ctx.r9.s64 = ctx.r1.s64 + 96;
	// lfs f0,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
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
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// stfs f0,108(r1)
	ctx.fpscr.disableFlushModeUnconditional();
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
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
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
	// stvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,84(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// b 0x825735dc
	goto loc_825735DC;
loc_82573520:
	// addi r9,r1,80
	ctx.r9.s64 = ctx.r1.s64 + 80;
	// stfs f0,84(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stfs f0,92(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 92, temp.u32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f0,88(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 88, temp.u32);
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// lfs f0,4(r29)
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lis r7,-32224
	ctx.r7.s64 = -2111832064;
	// lvx128 v61,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// addi r7,r7,-30944
	ctx.r7.s64 = ctx.r7.s64 + -30944;
	// stfs f0,112(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// stfs f12,108(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// lvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// stfs f12,104(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f12,96(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// stfs f12,100(r1)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v62,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v63,v62,v63
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v63.f32)));
	// lvx128 v62,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddfp128 v62,v62,v61
	simde_mm_store_ps(ctx.v62.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v61.f32)));
	// stvx128 v62,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f13,112(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f13.f64 = double(temp.f32);
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f13,96(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
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
	// lvx128 v63,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lfs f0,112(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 112);
	ctx.f0.f64 = double(temp.f32);
	// stfs f13,104(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// stfs f13,108(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// lvx128 v63,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stfs f0,84(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 84, temp.u32);
	// lfs f0,96(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
loc_825735DC:
	// stfs f0,80(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// ld r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// std r11,44(r31)
	REX_STORE_U64(ctx.r31.u32 + 44, ctx.r11.u64);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8258A820) {
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
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// lwz r10,8(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r11,-12788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12788);
	// lwz r9,32(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 32);
	// lwz r5,16(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,4(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r3,r9,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8258A86C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,-12788(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + -12788);
	// lwz r9,36(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 36);
	// lwz r5,16(r10)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + 16);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,8(r10)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r3,r9,r11
	ctx.r3.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8258A89C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// li r11,-1
	ctx.r11.s64 = -1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r11,16(r10)
	REX_STORE_U32(ctx.r10.u32 + 16, ctx.r11.u32);
	// bl 0x8258c5e8
	ctx.lr = 0x8258A8B0;
	sub_8258C5E8(ctx, base);
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

DEFINE_REX_FUNC(sub_8258C918) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8258C920;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r4,48(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 48);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// li r29,-1
	ctx.r29.s64 = -1;
	// lis r30,-32112
	ctx.r30.s64 = -2104492032;
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8258c948
	if (ctx.cr6.eq) goto loc_8258C948;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x8258C944;
	sub_82599798(ctx, base);
	// stw r29,48(r31)
	REX_STORE_U32(ctx.r31.u32 + 48, ctx.r29.u32);
loc_8258C948:
	// lwz r4,52(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmpwi cr6,r4,-1
	ctx.cr6.compare<int32_t>(ctx.r4.s32, -1, ctx.xer);
	// beq cr6,0x8258c960
	if (ctx.cr6.eq) goto loc_8258C960;
	// lwz r3,-12824(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + -12824);
	// bl 0x82599798
	ctx.lr = 0x8258C95C;
	sub_82599798(ctx, base);
	// stw r29,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r29.u32);
loc_8258C960:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8258FF18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f08
	ctx.lr = 0x8258FF20;
	__savegprlr_24(ctx, base);
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af0c
	ctx.lr = 0x8258FF28;
	__savefpr_21(ctx, base);
	// stwu r1,-256(r1)
	ea = -256 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,108(r3)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r3.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r6,r11,-32216
	ctx.r6.s64 = ctx.r11.s64 + -32216;
	// lis r11,-32228
	ctx.r11.s64 = -2112094208;
	// li r24,0
	ctx.r24.s64 = 0;
	// addi r7,r11,-6412
	ctx.r7.s64 = ctx.r11.s64 + -6412;
	// lfs f0,10532(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 10532);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// lfs f0,4224(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 4224);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x8258ffb4
	if (!ctx.cr6.gt) goto loc_8258FFB4;
	// lwz r10,124(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 124);
	// li r8,1
	ctx.r8.s64 = 1;
	// mr r11,r24
	ctx.r11.u64 = ctx.r24.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x8258ff94
	if (!ctx.cr6.gt) goto loc_8258FF94;
	// addi r10,r3,40
	ctx.r10.s64 = ctx.r3.s64 + 40;
loc_8258FF74:
	// lwz r9,-20(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + -20);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stb r8,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r8.u8);
	// lwzu r9,4(r10)
	ea = 4 + ctx.r10.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r10.u32 = ea;
	// stb r8,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r8.u8);
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmpw cr6,r11,r9
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8258ff74
	if (ctx.cr6.lt) goto loc_8258FF74;
loc_8258FF94:
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r25,r31,68
	ctx.r25.s64 = ctx.r31.s64 + 68;
	// addi r11,r25,-4
	ctx.r11.s64 = ctx.r25.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8258FFA4:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stb r8,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r8.u8);
	// bdnz 0x8258ffa4
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8258FFA4;
	// b 0x82590004
	goto loc_82590004;
loc_8258FFB4:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// mr r10,r24
	ctx.r10.u64 = ctx.r24.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x8258ffe8
	if (!ctx.cr6.gt) goto loc_8258FFE8;
	// addi r11,r31,40
	ctx.r11.s64 = ctx.r31.s64 + 40;
loc_8258FFC8:
	// lwz r9,-20(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + -20);
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stb r24,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r24.u8);
	// lwzu r9,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stb r24,14(r9)
	REX_STORE_U8(ctx.r9.u32 + 14, ctx.r24.u8);
	// lwz r9,124(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// blt cr6,0x8258ffc8
	if (ctx.cr6.lt) goto loc_8258FFC8;
loc_8258FFE8:
	// li r10,2
	ctx.r10.s64 = 2;
	// addi r25,r31,68
	ctx.r25.s64 = ctx.r31.s64 + 68;
	// addi r11,r25,-4
	ctx.r11.s64 = ctx.r25.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_8258FFF8:
	// lwzu r10,4(r11)
	ea = 4 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U32(ea);
	ctx.r11.u32 = ea;
	// stb r24,14(r10)
	REX_STORE_U8(ctx.r10.u32 + 14, ctx.r24.u8);
	// bdnz 0x8258fff8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8258FFF8;
loc_82590004:
	// lbz r11,128(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 128);
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r30,r10,12236
	ctx.r30.s64 = ctx.r10.s64 + 12236;
	// beq 0x82590020
	if (ctx.cr0.eq) goto loc_82590020;
	// lfs f13,7032(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 7032);
	ctx.f13.f64 = double(temp.f32);
	// b 0x82590024
	goto loc_82590024;
loc_82590020:
	// lfs f13,232(r30)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 232);
	ctx.f13.f64 = double(temp.f32);
loc_82590024:
	// lis r26,-32114
	ctx.r26.s64 = -2104623104;
	// lfs f0,8020(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 8020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f23,-2544(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + -2544);
	ctx.f23.f64 = double(temp.f32);
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lfs f12,2244(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2244);
	ctx.f12.f64 = double(temp.f32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r27,r10,-4080
	ctx.r27.s64 = ctx.r10.s64 + -4080;
	// lfs f11,8244(r26)
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 8244);
	ctx.f11.f64 = double(temp.f32);
	// fsubs f0,f0,f11
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f11.f64));
	// lfs f22,380(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 380);
	ctx.f22.f64 = double(temp.f32);
	// fmadds f0,f0,f23,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f23.f64, ctx.f13.f64)));
	// fadds f0,f0,f12
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f12.f64));
	// beq cr6,0x82590060
	if (ctx.cr6.eq) goto loc_82590060;
	// lfs f24,188(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 188);
	ctx.f24.f64 = double(temp.f32);
	// b 0x82590064
	goto loc_82590064;
loc_82590060:
	// fmr f24,f22
	ctx.fpscr.disableFlushMode();
	ctx.f24.f64 = ctx.f22.f64;
loc_82590064:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82590074
	if (ctx.cr6.eq) goto loc_82590074;
	// lfs f25,20852(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 20852);
	ctx.f25.f64 = double(temp.f32);
	// b 0x82590078
	goto loc_82590078;
loc_82590074:
	// fmr f25,f23
	ctx.fpscr.disableFlushMode();
	ctx.f25.f64 = ctx.f23.f64;
loc_82590078:
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// lfs f31,12280(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12280);
	ctx.f31.f64 = double(temp.f32);
	// mr r29,r24
	ctx.r29.u64 = ctx.r24.u64;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82590120
	if (!ctx.cr6.gt) goto loc_82590120;
	// lfs f30,0(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 0);
	ctx.f30.f64 = double(temp.f32);
	// fmuls f29,f0,f31
	ctx.f29.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// fsubs f0,f0,f30
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f30.f64));
	// lfs f27,0(r7)
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 0);
	ctx.f27.f64 = double(temp.f32);
	// lfs f26,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f26.f64 = double(temp.f32);
	// addi r28,r31,40
	ctx.r28.s64 = ctx.r31.s64 + 40;
	// fmuls f28,f0,f31
	ctx.f28.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
loc_825900A8:
	// extsw r11,r29
	ctx.r11.s64 = ctx.r29.s32;
	// lwz r3,-20(r28)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r28.u32 + -20);
	// lfs f13,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f13.f64 = double(temp.f32);
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f0,80(r1)
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f0
	ctx.f12.f64 = double(ctx.f0.s64);
	// lfs f0,2248(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2248);
	ctx.f0.f64 = double(temp.f32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmadds f12,f12,f27,f26
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f27.f64, ctx.f26.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fsubs f12,f12,f24
	ctx.f12.f64 = double(float(ctx.f12.f64 - ctx.f24.f64));
	// fmuls f12,f12,f25
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f25.f64));
	// fmadds f21,f12,f13,f0
	ctx.f21.f64 = double(float(std::fma(ctx.f12.f64, ctx.f13.f64, ctx.f0.f64)));
	// fmuls f2,f21,f31
	ctx.f2.f64 = double(float(ctx.f21.f64 * ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x825900F0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwzu r3,4(r28)
	ea = 4 + ctx.r28.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r28.u32 = ea;
	// fsubs f0,f21,f30
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f21.f64 - ctx.f30.f64));
	// fmr f1,f28
	ctx.f1.f64 = ctx.f28.f64;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmuls f2,f0,f31
	ctx.f2.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82590110;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,124(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 124);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// blt cr6,0x825900a8
	if (ctx.cr6.lt) goto loc_825900A8;
loc_82590120:
	// lfs f12,108(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 108);
	ctx.f12.f64 = double(temp.f32);
	// mr r31,r24
	ctx.r31.u64 = ctx.r24.u64;
	// lfs f0,392(r27)
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + 392);
	ctx.f0.f64 = double(temp.f32);
	// addi r29,r25,-4
	ctx.r29.s64 = ctx.r25.s64 + -4;
	// lfs f13,2248(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2248);
	ctx.f13.f64 = double(temp.f32);
	// fmadds f0,f12,f0,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f12.f64, ctx.f0.f64, ctx.f13.f64)));
	// fmuls f30,f0,f31
	ctx.f30.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
loc_8259013C:
	// extsw r11,r31
	ctx.r11.s64 = ctx.r31.s32;
	// lfs f0,8244(r26)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + 8244);
	ctx.f0.f64 = double(temp.f32);
	// lwzu r3,4(r29)
	ea = 4 + ctx.r29.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);
	ctx.r29.u32 = ea;
	// lfs f13,2244(r30)
	temp.u32 = REX_LOAD_U32(ctx.r30.u32 + 2244);
	ctx.f13.f64 = double(temp.f32);
	// std r11,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r11.u64);
	// lfd f12,80(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// fmr f2,f30
	ctx.f2.f64 = ctx.f30.f64;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// fmadds f12,f12,f23,f22
	ctx.f12.f64 = double(float(std::fma(ctx.f12.f64, ctx.f23.f64, ctx.f22.f64)));
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// fsubs f0,f12,f0
	ctx.f0.f64 = double(float(ctx.f12.f64 - ctx.f0.f64));
	// fmadds f0,f0,f23,f13
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f23.f64, ctx.f13.f64)));
	// fmuls f1,f0,f31
	ctx.f1.f64 = double(float(ctx.f0.f64 * ctx.f31.f64));
	// bctrl 
	ctx.lr = 0x82590180;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// cmpwi cr6,r31,2
	ctx.cr6.compare<int32_t>(ctx.r31.s32, 2, ctx.xer);
	// blt cr6,0x8259013c
	if (ctx.cr6.lt) goto loc_8259013C;
	// addi r1,r1,256
	ctx.r1.s64 = ctx.r1.s64 + 256;
	// addi r12,r1,-72
	ctx.r12.s64 = ctx.r1.s64 + -72;
	// bl 0x8273af58
	ctx.lr = 0x82590198;
	__restfpr_21(ctx, base);
	// b 0x82739f58
	__restgprlr_24(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825A4900) {
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
	// stw r3,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x825a4a90
	ctx.lr = 0x825A4918;
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
	ctx.lr = 0x825A492C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825A5AC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-8(r1)
	REX_STORE_U32(ctx.r1.u32 + -8, ctx.r12.u32);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lvx128 v58,r0,r3
	ea = (ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lvx128 v53,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmsum3fp128 v62,v58,v58
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v62.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v58.f32), 0xEF));
	// vmsum3fp128 v61,v53,v53
	simde_mm_store_ps(ctx.v61.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_load_ps(ctx.v53.f32), 0xEF));
	// addi r11,r11,32256
	ctx.r11.s64 = ctx.r11.s64 + 32256;
	// vspltisw128 v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v59.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// vor128 v11,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// lvx128 v57,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r10,-11344
	ctx.r10.s64 = ctx.r10.s64 + -11344;
	// vor128 v12,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v53.u8));
	// lvx128 v3,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v2,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v3.u8));
	// lvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vcmpgtfp128. v63,v57,v63
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// vrsqrtefp128 v0,v62
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v62.f32))));
	// vrsqrtefp128 v13,v61
	simde_mm_store_ps(ctx.v13.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_sqrt_ps(simde_mm_load_ps(ctx.v61.f32))));
	// vmulfp128 v10,v62,v3
	simde_mm_store_ps(ctx.v10.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v3.f32)));
	// vmulfp128 v8,v61,v2
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v2.f32)));
	// vcmpeqfp128 v6,v62,v59
	simde_mm_store_ps(ctx.v6.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vcmpeqfp128 v5,v61,v59
	simde_mm_store_ps(ctx.v5.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vcmpeqfp128 v29,v62,v59
	simde_mm_store_ps(ctx.v29.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vcmpeqfp128 v30,v61,v59
	simde_mm_store_ps(ctx.v30.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v61.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vmulfp128 v9,v0,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vor v4,v0,v0
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_load_si128((simde__m128i*)ctx.v0.u8));
	// vmulfp128 v7,v13,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v13.f32)));
	// vcmpeqfp128 v1,v0,v59
	simde_mm_store_ps(ctx.v1.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vcmpeqfp128 v31,v13,v59
	simde_mm_store_ps(ctx.v31.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vnmsubfp v3,v10,v9,v3
	simde_mm_store_ps(ctx.v3.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v3.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vnmsubfp v2,v8,v7,v2
	simde_mm_store_ps(ctx.v2.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v2.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vsel v8,v6,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8))));
	// vsel v7,v5,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v5.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v31.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8))));
	// vmaddfp v0,v0,v3,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v3.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vmaddfp v10,v13,v2,v13
	simde_mm_store_ps(ctx.v10.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v13.f32), simde_mm_load_ps(ctx.v2.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vsel v9,v0,v4,v8
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8))));
	// vsel v0,v10,v13,v7
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8))));
	// vmulfp128 v13,v58,v9
	simde_mm_store_ps(ctx.v13.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v58.f32), simde_mm_load_ps(ctx.v9.f32)));
	// vmulfp128 v0,v53,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v53.f32), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v27,v13,v11,v29
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v11.u8))));
	// vsel v28,v0,v12,v30
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a5d04
	if (ctx.cr0.eq) goto loc_825A5D04;
	// vmsum3fp128 v1,v27,v28
	simde_mm_store_ps(ctx.v1.f32, simde_mm_dp_ps(simde_mm_load_ps(ctx.v27.f32), simde_mm_load_ps(ctx.v28.f32), 0xEF));
	// addi r11,r1,96
	ctx.r11.s64 = ctx.r1.s64 + 96;
	// stvx128 v1,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x824cce98
	ctx.lr = 0x825A5B8C;
	sub_824CCE98(ctx, base);
	// lvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmulfp128 v54,v57,v63
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v54.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v57.f32), simde_mm_load_ps(ctx.v63.f32)));
	// vcmpgtfp128. v63,v1,v54
	simde_mm_store_ps(ctx.v63.f32, simde_mm_cmpgt_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v54.f32)));
	ctx.cr6.setFromMask(simde_mm_load_ps(ctx.v63.f32), 0xF);
	// mfocrf r11,2
	ctx.r11.u64 = (ctx.cr6.lt << 7) | (ctx.cr6.gt << 6) | (ctx.cr6.eq << 5) | (ctx.cr6.so << 4);
	// rlwinm. r11,r11,25,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 25) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x825a5cfc
	if (ctx.cr0.eq) goto loc_825A5CFC;
	// lis r11,-32240
	ctx.r11.s64 = -2112880640;
	// lfs f13,96(r1)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 96);
	ctx.f13.f64 = double(temp.f32);
	// addi r10,r11,12472
	ctx.r10.s64 = ctx.r11.s64 + 12472;
	// lfs f0,12472(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12472);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// fsubs f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f0.f64));
	// lfs f0,1732(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1732);
	ctx.f0.f64 = double(temp.f32);
	// fabs f13,f13
	ctx.f13.u64 = ctx.f13.u64 & ~0x8000000000000000;
	// fcmpu cr6,f13,f0
	ctx.cr6.compare(ctx.f13.f64, ctx.f0.f64);
	// ble cr6,0x825a5bd0
	if (!ctx.cr6.gt) goto loc_825A5BD0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_825A5BD0:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x825a5cb8
	if (!ctx.cr0.eq) goto loc_825A5CB8;
	// vrefp v0,v1
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_div_ps(simde_mm_set1_ps(1), simde_mm_load_ps(ctx.v1.f32)));
	// lis r11,-32242
	ctx.r11.s64 = -2113011712;
	// li r10,432
	ctx.r10.s64 = 432;
	// vor v8,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// addi r11,r11,31600
	ctx.r11.s64 = ctx.r11.s64 + 31600;
	// vor v11,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v1.u8));
	// vcmpeqfp128 v10,v1,v59
	simde_mm_store_ps(ctx.v10.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v59.f32)));
	// li r9,160
	ctx.r9.s64 = 160;
	// addi r8,r1,96
	ctx.r8.s64 = ctx.r1.s64 + 96;
	// vor v2,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v27.u8));
	// li r7,176
	ctx.r7.s64 = 176;
	// vor v1,v28,v28
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v28.u8));
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// lvx128 v13,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r9
	ea = (ctx.r11.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r11,r7
	ea = (ctx.r11.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vnmsubfp v7,v8,v0,v13
	simde_mm_store_ps(ctx.v7.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v8.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vcmpeqfp128 v12,v0,v59
	simde_mm_store_ps(ctx.v12.f32, simde_mm_cmpeq_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v59.f32)));
	// vmaddfp v9,v0,v7,v0
	simde_mm_store_ps(ctx.v9.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsel v8,v10,v12,v12
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8))));
	// vnmsubfp v13,v11,v9,v13
	simde_mm_store_ps(ctx.v13.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v13.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vmaddfp v13,v9,v13,v9
	simde_mm_store_ps(ctx.v13.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v9.f32)));
	// vsel v30,v13,v0,v8
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_or_si128(simde_mm_andnot_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)), simde_mm_and_si128(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8))));
	// bl 0x825e19a0
	ctx.lr = 0x825A5C40;
	sub_825E19A0(ctx, base);
	// vmulfp128 v2,v54,v30
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v2.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v54.f32), simde_mm_load_ps(ctx.v30.f32)));
	// bl 0x825e1700
	ctx.lr = 0x825A5C48;
	sub_825E1700(ctx, base);
loc_825A5C48:
	// vmulfp128 v0,v1,v53
	ctx.fpscr.enableFlushMode();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v1.f32), simde_mm_load_ps(ctx.v53.f32)));
	// vsldoi128 v12,v53,v53,4
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), 12));
	// vsldoi v4,v1,v1,4
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8), 12));
	// addi r11,r1,80
	ctx.r11.s64 = ctx.r1.s64 + 80;
	// vspltw v10,v1,3
	simde_mm_store_si128((simde__m128i*)ctx.v10.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v1.u32), 0x0));
	// addi r10,r1,96
	ctx.r10.s64 = ctx.r1.s64 + 96;
	// vmulfp128 v5,v10,v53
	simde_mm_store_ps(ctx.v5.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v53.f32)));
	// lvx128 v7,r0,r11
	ea = (ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v63,v1,v1,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v6,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm v9,v1,v1,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm128 v8,v53,v53,v7
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v13,v53,v53,v6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vor128 v11,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmaddfp v4,v4,v12,v0
	simde_mm_store_ps(ctx.v4.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v4.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vsldoi128 v62,v0,v0,8
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_alignr_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), 8));
	// vor128 v12,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// vmaddfp v0,v9,v8,v5
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v8.f32)), simde_mm_load_ps(ctx.v5.f32)));
	// vaddfp128 v63,v62,v4
	simde_mm_store_ps(ctx.v63.f32, simde_mm_add_ps(simde_mm_load_ps(ctx.v62.f32), simde_mm_load_ps(ctx.v4.f32)));
	// vnmsubfp v0,v11,v13,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v11.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// vspltw128 v63,v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v63.u32), 0xFF));
	// vmulfp128 v8,v63,v1
	simde_mm_store_ps(ctx.v8.f32, simde_mm_mul_ps(simde_mm_load_ps(ctx.v63.f32), simde_mm_load_ps(ctx.v1.f32)));
	// vperm v13,v0,v0,v6
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// vperm v11,v0,v0,v7
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vmaddfp v0,v10,v0,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v10.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vmaddfp v0,v9,v11,v0
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v9.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v0.f32)));
	// vnmsubfp v1,v12,v13,v0
	simde_mm_store_ps(ctx.v1.f32, simde_mm_xor_ps(simde_mm_sub_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v13.f32)), simde_mm_load_ps(ctx.v0.f32)), simde_mm_castsi128_ps(simde_mm_set1_epi32(int(0x80000000)))));
	// b 0x825a5d08
	goto loc_825A5D08;
loc_825A5CB8:
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// vor128 v2,v54,v54
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_load_si128((simde__m128i*)ctx.v54.u8));
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r11,3264
	ctx.r11.s64 = ctx.r11.s64 + 3264;
	// lis r9,-32242
	ctx.r9.s64 = -2113011712;
	// li r8,160
	ctx.r8.s64 = 160;
	// addi r9,r9,31600
	ctx.r9.s64 = ctx.r9.s64 + 31600;
	// addi r7,r1,96
	ctx.r7.s64 = ctx.r1.s64 + 96;
	// lvx128 v1,r11,r10
	ea = (ctx.r11.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,176
	ctx.r11.s64 = 176;
	// addi r10,r1,80
	ctx.r10.s64 = ctx.r1.s64 + 80;
	// lvx128 v63,r9,r8
	ea = (ctx.r9.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v63,r9,r11
	ea = (ctx.r9.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v63,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// bl 0x825e1ad0
	ctx.lr = 0x825A5CF8;
	sub_825E1AD0(ctx, base);
	// b 0x825a5c48
	goto loc_825A5C48;
loc_825A5CFC:
	// vor128 v1,v58,v58
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v58.u8));
	// b 0x825a5d08
	goto loc_825A5D08;
loc_825A5D04:
	// vor128 v1,v53,v53
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_load_si128((simde__m128i*)ctx.v53.u8));
loc_825A5D08:
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825C9888) {
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
	// lwz r11,372(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 372);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// beq cr6,0x825c98d8
	if (ctx.cr6.eq) goto loc_825C98D8;
	// cmplwi cr6,r11,32
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 32, ctx.xer);
	// beq cr6,0x825c98d8
	if (ctx.cr6.eq) goto loc_825C98D8;
	// lwz r10,376(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 376);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825c98d8
	if (!ctx.cr6.eq) goto loc_825C98D8;
	// lwz r10,392(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 392);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825c98d8
	if (ctx.cr6.eq) goto loc_825C98D8;
	// lwz r10,448(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 448);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825c98f8
	if (ctx.cr6.eq) goto loc_825C98F8;
loc_825C98D8:
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825c9a08
	if (!ctx.cr6.eq) goto loc_825C9A08;
	// cmplwi cr6,r11,16
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16, ctx.xer);
	// bne cr6,0x825c9a08
	if (!ctx.cr6.eq) goto loc_825C9A08;
	// lwz r11,380(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 380);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x825c9a08
	if (!ctx.cr6.eq) goto loc_825C9A08;
loc_825C98F8:
	// lwz r11,424(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 424);
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c9910
	if (ctx.cr6.eq) goto loc_825C9910;
	// stw r30,64(r11)
	REX_STORE_U32(ctx.r11.u32 + 64, ctx.r30.u32);
	// stw r30,424(r31)
	REX_STORE_U32(ctx.r31.u32 + 424, ctx.r30.u32);
loc_825C9910:
	// lwz r11,428(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c9960
	if (ctx.cr6.eq) goto loc_825C9960;
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x825c9930
	if (ctx.cr6.eq) goto loc_825C9930;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bne cr6,0x825c9948
	if (!ctx.cr6.eq) goto loc_825C9948;
loc_825C9930:
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825c9960
	if (!ctx.cr6.eq) goto loc_825C9960;
	// lwz r10,372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x825c9960
	if (!ctx.cr6.eq) goto loc_825C9960;
loc_825C9948:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825C9960;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825C9960:
	// lwz r11,432(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825c99b0
	if (ctx.cr6.eq) goto loc_825C99B0;
	// lwz r10,88(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 88);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// beq cr6,0x825c9980
	if (ctx.cr6.eq) goto loc_825C9980;
	// cmpwi cr6,r10,5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 5, ctx.xer);
	// bne cr6,0x825c9998
	if (!ctx.cr6.eq) goto loc_825C9998;
loc_825C9980:
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825c99b0
	if (!ctx.cr6.eq) goto loc_825C99B0;
	// lwz r10,372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// bne cr6,0x825c99b0
	if (!ctx.cr6.eq) goto loc_825C99B0;
loc_825C9998:
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// addi r3,r11,4
	ctx.r3.s64 = ctx.r11.s64 + 4;
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r9,0(r10)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
	// bctrl 
	ctx.lr = 0x825C99B0;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_825C99B0:
	// stw r30,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r30.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lfs f1,388(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 388);
	ctx.f1.f64 = double(temp.f32);
	// bl 0x825c9d68
	ctx.lr = 0x825C99C8;
	sub_825C9D68(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x825c99e4
	if (ctx.cr6.lt) goto loc_825C99E4;
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x825c99e4
	if (ctx.cr6.eq) goto loc_825C99E4;
	// stw r11,448(r31)
	REX_STORE_U32(ctx.r31.u32 + 448, ctx.r11.u32);
loc_825C99E4:
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x825c99fc
	if (!ctx.cr6.eq) goto loc_825C99FC;
	// lwz r10,372(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 372);
	// cmplwi cr6,r10,16
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16, ctx.xer);
	// beq cr6,0x825c9a00
	if (ctx.cr6.eq) goto loc_825C9A00;
loc_825C99FC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_825C9A00:
	// stw r11,380(r31)
	REX_STORE_U32(ctx.r31.u32 + 380, ctx.r11.u32);
	// stw r30,392(r31)
	REX_STORE_U32(ctx.r31.u32 + 392, ctx.r30.u32);
loc_825C9A08:
	// lwz r3,428(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 428);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825c9a18
	if (ctx.cr6.eq) goto loc_825C9A18;
	// bl 0x825c5de0
	ctx.lr = 0x825C9A18;
	sub_825C5DE0(ctx, base);
loc_825C9A18:
	// lwz r3,432(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 432);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825c9a28
	if (ctx.cr6.eq) goto loc_825C9A28;
	// bl 0x825c5de0
	ctx.lr = 0x825C9A28;
	sub_825C5DE0(ctx, base);
loc_825C9A28:
	// lwz r3,436(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 436);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x825c9a38
	if (ctx.cr6.eq) goto loc_825C9A38;
	// bl 0x825c5de0
	ctx.lr = 0x825C9A38;
	sub_825C5DE0(ctx, base);
loc_825C9A38:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x825ba560
	ctx.lr = 0x825C9A40;
	sub_825BA560(ctx, base);
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

DEFINE_REX_FUNC(sub_825DDAE0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x825DDAE8;
	__savegprlr_22(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r27,r4
	ctx.r27.u64 = ctx.r4.u64;
	// neg r10,r11
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// and r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// rlwinm r10,r11,20,27,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0x10;
	// srw r9,r11,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r11.u32 >> (ctx.r10.u8 & 0x3F));
	// rlwinm r11,r9,27,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x8;
	// srw r8,r9,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r9.u32 >> (ctx.r11.u8 & 0x3F));
	// rlwinm r9,r8,30,29,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 30) & 0x4;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// srw r8,r8,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r9.u8 & 0x3F));
	// rlwinm r11,r8,31,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x2;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// srw r8,r8,r11
	ctx.r8.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r11.u8 & 0x3F));
	// rlwinm r10,r8,31,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x1;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// srw r9,r8,r10
	ctx.r9.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 >> (ctx.r10.u8 & 0x3F));
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,75
	ctx.r11.s64 = ctx.r11.s64 + 75;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r11,r3
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r25,r4,r10
	ctx.r25.u64 = ctx.r10.u64 - ctx.r4.u64;
loc_825DDB58:
	// mr r29,r11
	ctx.r29.u64 = ctx.r11.u64;
loc_825DDB5C:
	// lwz r10,16(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 16);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x825ddb70
	if (ctx.cr6.eq) goto loc_825DDB70;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x825ddb74
	goto loc_825DDB74;
loc_825DDB70:
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
loc_825DDB74:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825ddb98
	if (ctx.cr6.eq) goto loc_825DDB98;
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// rlwinm r10,r10,0,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFC;
	// subf r10,r27,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r27.u64;
	// cmplw cr6,r10,r25
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r25.u32, ctx.xer);
	// bge cr6,0x825ddb5c
	if (!ctx.cr6.lt) goto loc_825DDB5C;
	// mr r25,r10
	ctx.r25.u64 = ctx.r10.u64;
	// b 0x825ddb58
	goto loc_825DDB58;
loc_825DDB98:
	// lwz r9,16(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r29,r9
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825dde38
	if (ctx.cr6.lt) goto loc_825DDE38;
	// add r22,r29,r27
	ctx.r22.u64 = ctx.r29.u64 + ctx.r27.u64;
	// cmplw cr6,r29,r22
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r22.u32, ctx.xer);
	// bge cr6,0x825dde38
	if (!ctx.cr6.lt) goto loc_825DDE38;
	// lwz r30,12(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 12);
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// lwz r28,24(r29)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// cmplw cr6,r30,r29
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r29.u32, ctx.xer);
	// addi r24,r11,23116
	ctx.r24.s64 = ctx.r11.s64 + 23116;
	// addi r23,r10,23060
	ctx.r23.s64 = ctx.r10.s64 + 23060;
	// beq cr6,0x825ddbe8
	if (ctx.cr6.eq) goto loc_825DDBE8;
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825ddc48
	if (ctx.cr6.lt) goto loc_825DDC48;
	// stw r30,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r30.u32);
	// stw r11,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r11.u32);
	// b 0x825ddc5c
	goto loc_825DDC5C;
loc_825DDBE8:
	// lwz r30,20(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// addi r11,r29,20
	ctx.r11.s64 = ctx.r29.s64 + 20;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825ddc08
	if (!ctx.cr6.eq) goto loc_825DDC08;
	// lwz r30,16(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// addi r11,r29,16
	ctx.r11.s64 = ctx.r29.s64 + 16;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825ddc5c
	if (ctx.cr6.eq) goto loc_825DDC5C;
loc_825DDC08:
	// lwz r8,20(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// addi r10,r30,20
	ctx.r10.s64 = ctx.r30.s64 + 20;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// bne cr6,0x825ddc28
	if (!ctx.cr6.eq) goto loc_825DDC28;
	// lwz r8,16(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// addi r10,r30,16
	ctx.r10.s64 = ctx.r30.s64 + 16;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x825ddc34
	if (ctx.cr6.eq) goto loc_825DDC34;
loc_825DDC28:
	// lwz r30,0(r10)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// b 0x825ddc08
	goto loc_825DDC08;
loc_825DDC34:
	// cmplw cr6,r11,r9
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r9.u32, ctx.xer);
	// blt cr6,0x825ddc48
	if (ctx.cr6.lt) goto loc_825DDC48;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// b 0x825ddc5c
	goto loc_825DDC5C;
loc_825DDC48:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3797
	ctx.r5.s64 = 3797;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x825da098
	ctx.lr = 0x825DDC5C;
	sub_825DA098(ctx, base);
loc_825DDC5C:
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x825ddd68
	if (ctx.cr6.eq) goto loc_825DDD68;
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// addi r11,r11,75
	ctx.r11.s64 = ctx.r11.s64 + 75;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// cmplw cr6,r29,r10
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x825ddca4
	if (!ctx.cr6.eq) goto loc_825DDCA4;
	// stwx r30,r11,r31
	REX_STORE_U32(ctx.r11.u32 + ctx.r31.u32, ctx.r30.u32);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x825ddce8
	if (!ctx.cr6.eq) goto loc_825DDCE8;
	// lwz r11,28(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 28);
	// lwz r10,4(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// slw r11,r26,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r11.u8 & 0x3F));
	// andc r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 & ~ctx.r11.u64;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
	// b 0x825ddd68
	goto loc_825DDD68;
loc_825DDCA4:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r28,r11
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x825ddccc
	if (ctx.cr6.lt) goto loc_825DDCCC;
	// lwz r11,16(r28)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r28.u32 + 16);
	// cmplw cr6,r11,r29
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r29.u32, ctx.xer);
	// bne cr6,0x825ddcc4
	if (!ctx.cr6.eq) goto loc_825DDCC4;
	// stw r30,16(r28)
	REX_STORE_U32(ctx.r28.u32 + 16, ctx.r30.u32);
	// b 0x825ddce0
	goto loc_825DDCE0;
loc_825DDCC4:
	// stw r30,20(r28)
	REX_STORE_U32(ctx.r28.u32 + 20, ctx.r30.u32);
	// b 0x825ddce0
	goto loc_825DDCE0;
loc_825DDCCC:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3797
	ctx.r5.s64 = 3797;
	// bl 0x825da098
	ctx.lr = 0x825DDCE0;
	sub_825DA098(ctx, base);
loc_825DDCE0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x825ddd68
	if (ctx.cr6.eq) goto loc_825DDD68;
loc_825DDCE8:
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x825ddd54
	if (ctx.cr6.lt) goto loc_825DDD54;
	// stw r28,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r28.u32);
	// lwz r11,16(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 16);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825ddd30
	if (ctx.cr6.eq) goto loc_825DDD30;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825ddd1c
	if (ctx.cr6.lt) goto loc_825DDD1C;
	// stw r11,16(r30)
	REX_STORE_U32(ctx.r30.u32 + 16, ctx.r11.u32);
	// stw r30,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r30.u32);
	// b 0x825ddd30
	goto loc_825DDD30;
loc_825DDD1C:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3797
	ctx.r5.s64 = 3797;
	// bl 0x825da098
	ctx.lr = 0x825DDD30;
	sub_825DA098(ctx, base);
loc_825DDD30:
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825ddd68
	if (ctx.cr6.eq) goto loc_825DDD68;
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825ddd54
	if (ctx.cr6.lt) goto loc_825DDD54;
	// stw r11,20(r30)
	REX_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
	// stw r30,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r30.u32);
	// b 0x825ddd68
	goto loc_825DDD68;
loc_825DDD54:
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3797
	ctx.r5.s64 = 3797;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x825da098
	ctx.lr = 0x825DDD68;
	sub_825DA098(ctx, base);
loc_825DDD68:
	// cmplwi cr6,r25,16
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 16, ctx.xer);
	// bge cr6,0x825ddd98
	if (!ctx.cr6.lt) goto loc_825DDD98;
	// add r11,r25,r29
	ctx.r11.u64 = ctx.r25.u64 + ctx.r29.u64;
	// add r10,r25,r27
	ctx.r10.u64 = ctx.r25.u64 + ctx.r27.u64;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// ori r9,r10,3
	ctx.r9.u64 = ctx.r10.u64 | 3;
	// addi r10,r11,4
	ctx.r10.s64 = ctx.r11.s64 + 4;
	// stw r9,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// lwz r10,4(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// stw r10,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r10.u32);
	// b 0x825dde30
	goto loc_825DDE30;
loc_825DDD98:
	// ori r11,r27,3
	ctx.r11.u64 = ctx.r27.u64 | 3;
	// ori r10,r25,1
	ctx.r10.u64 = ctx.r25.u64 | 1;
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// stw r10,4(r22)
	REX_STORE_U32(ctx.r22.u32 + 4, ctx.r10.u32);
	// stwx r25,r22,r25
	REX_STORE_U32(ctx.r22.u32 + ctx.r25.u32, ctx.r25.u32);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x825dde28
	if (ctx.cr6.eq) goto loc_825DDE28;
	// rlwinm r8,r11,29,3,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 29) & 0x1FFFFFFF;
	// lwz r10,0(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// rlwinm r11,r11,0,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFF8;
	// lwz r28,20(r31)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// add r9,r11,r31
	ctx.r9.u64 = ctx.r11.u64 + ctx.r31.u64;
	// slw r11,r26,r8
	ctx.r11.u64 = ctx.r8.u8 & 0x20 ? 0 : (ctx.r26.u32 << (ctx.r8.u8 & 0x3F));
	// addi r30,r9,36
	ctx.r30.s64 = ctx.r9.s64 + 36;
	// and. r9,r10,r11
	ctx.r9.u64 = ctx.r10.u64 & ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// bne 0x825dddec
	if (!ctx.cr0.eq) goto loc_825DDDEC;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// b 0x825dde18
	goto loc_825DDE18;
loc_825DDDEC:
	// lwz r11,8(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r10,16(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x825dde04
	if (ctx.cr6.lt) goto loc_825DDE04;
	// mr r27,r11
	ctx.r27.u64 = ctx.r11.u64;
	// b 0x825dde18
	goto loc_825DDE18;
loc_825DDE04:
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3803
	ctx.r5.s64 = 3803;
	// bl 0x825da098
	ctx.lr = 0x825DDE18;
	sub_825DA098(ctx, base);
loc_825DDE18:
	// stw r28,8(r30)
	REX_STORE_U32(ctx.r30.u32 + 8, ctx.r28.u32);
	// stw r28,12(r27)
	REX_STORE_U32(ctx.r27.u32 + 12, ctx.r28.u32);
	// stw r27,8(r28)
	REX_STORE_U32(ctx.r28.u32 + 8, ctx.r27.u32);
	// stw r30,12(r28)
	REX_STORE_U32(ctx.r28.u32 + 12, ctx.r30.u32);
loc_825DDE28:
	// stw r25,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r25.u32);
	// stw r22,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r22.u32);
loc_825DDE30:
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// b 0x825dde58
	goto loc_825DDE58;
loc_825DDE38:
	// lis r11,-32225
	ctx.r11.s64 = -2111897600;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// addi r4,r11,23060
	ctx.r4.s64 = ctx.r11.s64 + 23060;
	// addi r3,r10,23116
	ctx.r3.s64 = ctx.r10.s64 + 23116;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,3809
	ctx.r5.s64 = 3809;
	// bl 0x825da098
	ctx.lr = 0x825DDE54;
	sub_825DA098(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_825DDE58:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825F3CE8) {
	REX_FUNC_PROLOGUE();
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_825F3D50) {
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
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// cmplwi cr6,r5,2
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 2, ctx.xer);
	// bge cr6,0x825f3d80
	if (!ctx.cr6.lt) goto loc_825F3D80;
	// lis r3,-16380
	ctx.r3.s64 = -1073479680;
	// ori r3,r3,2
	ctx.r3.u64 = ctx.r3.u64 | 2;
	// b 0x825f3e2c
	goto loc_825F3E2C;
loc_825F3D80:
	// li r5,4
	ctx.r5.s64 = 4;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x82639688
	ctx.lr = 0x825F3D90;
	sub_82639688(ctx, base);
	// lis r11,-32226
	ctx.r11.s64 = -2111963136;
	// lfs f13,0(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// lis r10,0
	ctx.r10.s64 = 0;
	// addi r11,r11,-4080
	ctx.r11.s64 = ctx.r11.s64 + -4080;
	// ori r10,r10,65535
	ctx.r10.u64 = ctx.r10.u64 | 65535;
	// lfs f0,244(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 244);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f13,f13,f0
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f13.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x825f3dc8
	if (!ctx.cr6.lt) goto loc_825F3DC8;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x825f3dd4
	goto loc_825F3DD4;
loc_825F3DC8:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x825f3dd4
	if (!ctx.cr6.gt) goto loc_825F3DD4;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_825F3DD4:
	// lfs f13,4(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// sth r11,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r11.u16);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// fctiwz f0,f0
	ctx.f0.s64 = std::isnan(ctx.f0.f64) ? int64_t(0x80000000U) : (ctx.f0.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f0.f64));
	// stfd f0,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.f0.u64);
	// lwz r11,92(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x825f3dfc
	if (!ctx.cr6.lt) goto loc_825F3DFC;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x825f3e08
	goto loc_825F3E08;
loc_825F3DFC:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x825f3e08
	if (!ctx.cr6.gt) goto loc_825F3E08;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_825F3E08:
	// sth r11,82(r1)
	REX_STORE_U16(ctx.r1.u32 + 82, ctx.r11.u16);
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// lwz r3,16(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 16);
	// bl 0x82749078
	ctx.lr = 0x825F3E18;
	sub_82749078(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// lis r10,-16380
	ctx.r10.s64 = -1073479680;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// ori r10,r10,1
	ctx.r10.u64 = ctx.r10.u64 | 1;
	// and r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 & ctx.r10.u64;
loc_825F3E2C:
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

DEFINE_REX_FUNC(sub_825F91A0) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x825F91A8;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r4,4096
	ctx.r4.s64 = 4096;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8260fce0
	ctx.lr = 0x825F91CC;
	sub_8260FCE0(ctx, base);
	// rlwinm. r11,r31,0,21,21
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 0) & 0x400;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// beq 0x825f91f0
	if (ctx.cr0.eq) goto loc_825F91F0;
	// rlwinm r11,r3,12,20,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 12) & 0xFFF;
	// clrlwi r10,r3,3
	ctx.r10.u64 = ctx.r3.u32 & 0x1FFFFFFF;
	// addi r11,r11,512
	ctx.r11.s64 = ctx.r11.s64 + 512;
	// rlwinm r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addis r31,r11,-16384
	ctx.r31.s64 = ctx.r11.s64 + -1073741824;
loc_825F91F0:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x8274a3f0
	ctx.lr = 0x825F91FC;
	sub_8274A3F0(ctx, base);
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8260fe98
	ctx.lr = 0x825F9204;
	sub_8260FE98(ctx, base);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_825FC200) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x825FC208;
	__savegprlr_28(ctx, base);
	// lwz r11,444(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 444);
	// addi r7,r1,32
	ctx.r7.s64 = ctx.r1.s64 + 32;
	// li r5,12
	ctx.r5.s64 = 12;
	// li r12,32
	ctx.r12.s64 = 32;
	// stvx128 v1,r1,r12
	ea = (ctx.r1.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,1
	ctx.r9.s64 = 1;
	// li r8,8
	ctx.r8.s64 = 8;
	// sth r8,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r8.u16);
	// li r6,67
	ctx.r6.s64 = 67;
	// sth r6,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r6.u16);
	// sth r5,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r5.u16);
	// addi r10,r3,436
	ctx.r10.s64 = ctx.r3.s64 + 436;
	// sth r9,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r9.u16);
	// addi r31,r1,32
	ctx.r31.s64 = ctx.r1.s64 + 32;
	// lwz r4,0(r7)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r7.u32 + 0);
	// li r28,0
	ctx.r28.s64 = 0;
	// stw r4,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r4.u32);
	// li r29,69
	ctx.r29.s64 = 69;
	// lwz r10,4(r7)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r7.u32 + 4);
	// stw r10,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r10.u32);
	// lwz r30,8(r7)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r7.u32 + 8);
	// stw r30,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r30.u32);
	// lwz r7,12(r7)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r7.u32 + 12);
	// stw r7,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r7.u32);
	// lwz r6,4(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r5,12(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// sth r10,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r10.u16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,444(r3)
	REX_STORE_U32(ctx.r3.u32 + 444, ctx.r11.u32);
	// lwz r10,8(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// sth r8,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r8.u16);
	// sth r29,0(r11)
	REX_STORE_U16(ctx.r11.u32 + 0, ctx.r29.u16);
	// sth r28,4(r11)
	REX_STORE_U16(ctx.r11.u32 + 4, ctx.r28.u16);
	// sth r9,6(r11)
	REX_STORE_U16(ctx.r11.u32 + 6, ctx.r9.u16);
	// stw r7,8(r11)
	REX_STORE_U32(ctx.r11.u32 + 8, ctx.r7.u32);
	// stw r6,12(r11)
	REX_STORE_U32(ctx.r11.u32 + 12, ctx.r6.u32);
	// stw r10,16(r11)
	REX_STORE_U32(ctx.r11.u32 + 16, ctx.r10.u32);
	// stw r5,20(r11)
	REX_STORE_U32(ctx.r11.u32 + 20, ctx.r5.u32);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// sth r10,2(r11)
	REX_STORE_U16(ctx.r11.u32 + 2, ctx.r10.u16);
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// clrlwi r10,r10,16
	ctx.r10.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r11,444(r3)
	REX_STORE_U32(ctx.r3.u32 + 444, ctx.r11.u32);
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82604478) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f10
	ctx.lr = 0x82604480;
	__savegprlr_26(ctx, base);
	// stfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -64, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r26,r4
	ctx.r26.u64 = ctx.r4.u64;
	// cmplw cr6,r3,r4
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82604528
	if (ctx.cr6.eq) goto loc_82604528;
	// addi r30,r3,32
	ctx.r30.s64 = ctx.r3.s64 + 32;
	// cmplw cr6,r30,r4
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r4.u32, ctx.xer);
	// beq cr6,0x82604528
	if (ctx.cr6.eq) goto loc_82604528;
	// addi r27,r30,32
	ctx.r27.s64 = ctx.r30.s64 + 32;
loc_826044A8:
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
	// bl 0x8273a030
	ctx.lr = 0x826044BC;
	sub_8273A030(ctx, base);
	// lfs f0,28(r28)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f31,108(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 108);
	ctx.f31.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x826044d4
	if (ctx.cr6.gt) goto loc_826044D4;
	// li r11,0
	ctx.r11.s64 = 0;
loc_826044D4:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r31,r30
	ctx.r31.u64 = ctx.r30.u64;
	// beq 0x82604534
	if (ctx.cr0.eq) goto loc_82604534;
	// cmplw cr6,r28,r30
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, ctx.r30.u32, ctx.xer);
	// beq cr6,0x82604508
	if (ctx.cr6.eq) goto loc_82604508;
	// subf r29,r30,r27
	ctx.r29.u64 = ctx.r27.u64 - ctx.r30.u64;
loc_826044EC:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// li r5,32
	ctx.r5.s64 = 32;
	// add r3,r29,r31
	ctx.r3.u64 = ctx.r29.u64 + ctx.r31.u64;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x82604500;
	sub_8273A030(ctx, base);
	// cmplw cr6,r31,r28
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x826044ec
	if (!ctx.cr6.eq) goto loc_826044EC;
loc_82604508:
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
loc_8260450C:
	// li r5,32
	ctx.r5.s64 = 32;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// bl 0x8273a030
	ctx.lr = 0x82604518;
	sub_8273A030(ctx, base);
	// addi r30,r30,32
	ctx.r30.s64 = ctx.r30.s64 + 32;
	// addi r27,r27,32
	ctx.r27.s64 = ctx.r27.s64 + 32;
	// cmplw cr6,r30,r26
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r26.u32, ctx.xer);
	// bne cr6,0x826044a8
	if (!ctx.cr6.eq) goto loc_826044A8;
loc_82604528:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-64(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -64);
	// b 0x82739f60
	__restgprlr_26(ctx, base);
	return;
loc_82604534:
	// addi r31,r31,-32
	ctx.r31.s64 = ctx.r31.s64 + -32;
	// li r11,1
	ctx.r11.s64 = 1;
	// lfs f0,28(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f31,f0
	ctx.cr6.compare(ctx.f31.f64, ctx.f0.f64);
	// bgt cr6,0x8260454c
	if (ctx.cr6.gt) goto loc_8260454C;
	// li r11,0
	ctx.r11.s64 = 0;
loc_8260454C:
	// clrlwi. r11,r11,24
	ctx.r11.u64 = ctx.r11.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// beq 0x8260450c
	if (ctx.cr0.eq) goto loc_8260450C;
	// li r5,32
	ctx.r5.s64 = 32;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// bl 0x8273a030
	ctx.lr = 0x82604564;
	sub_8273A030(ctx, base);
	// mr r29,r31
	ctx.r29.u64 = ctx.r31.u64;
	// b 0x82604534
	goto loc_82604534;
}

DEFINE_REX_FUNC(sub_8260CDB8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	PPCVRegister vTemp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f00
	ctx.lr = 0x8260CDC0;
	__savegprlr_22(ctx, base);
	// stwu r1,-288(r1)
	ea = -288 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r30,r4,4
	ctx.r30.s64 = ctx.r4.s64 + 4;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x8260d0c0
	if (ctx.cr6.eq) goto loc_8260D0C0;
	// li r6,12
	ctx.r6.s64 = 12;
	// mulli r5,r11,3
	ctx.r5.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(3));
	// li r4,8
	ctx.r4.s64 = 8;
	// bl 0x8260c928
	ctx.lr = 0x8260CDEC;
	sub_8260C928(ctx, base);
	// lwz r10,0(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r11,8(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 8);
	// li r9,0
	ctx.r9.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// ble cr6,0x8260d0c0
	if (!ctx.cr6.gt) goto loc_8260D0C0;
	// lis r10,-32225
	ctx.r10.s64 = -2111897600;
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lis r8,-32225
	ctx.r8.s64 = -2111897600;
	// addi r6,r10,32288
	ctx.r6.s64 = ctx.r10.s64 + 32288;
	// addi r8,r8,32272
	ctx.r8.s64 = ctx.r8.s64 + 32272;
	// lis r7,-32240
	ctx.r7.s64 = -2112880640;
	// addi r10,r3,10
	ctx.r10.s64 = ctx.r3.s64 + 10;
	// lvx128 v11,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vor v9,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// lfs f0,12468(r7)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r7.u32 + 12468);
	ctx.f0.f64 = double(temp.f32);
	// vor v8,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// stfs f0,104(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 104, temp.u32);
	// vor v7,v11,v11
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_load_si128((simde__m128i*)ctx.v11.u8));
	// stfs f0,108(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 108, temp.u32);
	// vor v6,v10,v10
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_load_si128((simde__m128i*)ctx.v10.u8));
	// stfs f0,120(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 120, temp.u32);
	// li r8,16
	ctx.r8.s64 = 16;
	// stfs f0,124(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 124, temp.u32);
	// stfs f0,136(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 136, temp.u32);
	// stfs f0,140(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 140, temp.u32);
	// stfs f0,152(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 152, temp.u32);
	// stfs f0,156(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 156, temp.u32);
	// stfs f0,168(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 168, temp.u32);
	// stfs f0,172(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 172, temp.u32);
	// stfs f0,184(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 184, temp.u32);
	// stfs f0,188(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 188, temp.u32);
loc_8260CE6C:
	// lwz r7,0(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// vor128 v62,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// addi r5,r1,112
	ctx.r5.s64 = ctx.r1.s64 + 112;
	// stfs f13,100(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 100, temp.u32);
	// addi r4,r1,128
	ctx.r4.s64 = ctx.r1.s64 + 128;
	// stfs f0,96(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 96, temp.u32);
	// addi r29,r1,144
	ctx.r29.s64 = ctx.r1.s64 + 144;
	// lvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r28,r1,160
	ctx.r28.s64 = ctx.r1.s64 + 160;
	// lvx128 v12,r7,r8
	ea = (ctx.r7.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r24,r1,176
	ctx.r24.s64 = ctx.r1.s64 + 176;
	// lvx128 v0,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v0,v12,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v12.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v0,v11,v10
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v11.f32)), simde_mm_load_ps(ctx.v10.f32)));
	// vor128 v61,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// li r6,2
	ctx.r6.s64 = 2;
	// vor128 v60,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// li r27,14
	ctx.r27.s64 = 14;
	// vor128 v59,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// li r26,-6
	ctx.r26.s64 = -6;
	// vor128 v58,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// li r25,6
	ctx.r25.s64 = 6;
	// vor128 v57,v63,v63
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_load_si128((simde__m128i*)ctx.v63.u8));
	// addi r7,r11,12
	ctx.r7.s64 = ctx.r11.s64 + 12;
	// li r23,18
	ctx.r23.s64 = 18;
	// vpkd3d128 v62,v0,3,1,3
	temp.u32 = (ctx.v0.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v0.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v0.u32[3]&0x7FE000)>>13) : 0x0;
	ctx.v62.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v62.u16[7] |= ((ctx.v0.u32[3]&0x80000000)>>16);
	temp.u32 = (ctx.v0.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v0.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v0.u32[2]&0x7FE000)>>13) : 0x0;
	ctx.v62.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v62.u16[6] |= ((ctx.v0.u32[2]&0x80000000)>>16);
	// vspltw128 v62,v62,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v62.u32), 0xFF));
	// stvewx128 v62,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r22,0(r31)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,4(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// lfs f12,0(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f12.f64 = double(temp.f32);
	// lfs f13,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,112(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 112, temp.u32);
	// stfs f0,116(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 116, temp.u32);
	// lvx128 v13,r0,r22
	ea = (ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r22,r8
	ea = (ctx.r22.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v0,v9,v8
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v9.f32)), simde_mm_load_ps(ctx.v8.f32)));
	// vpkd3d128 v61,v0,3,1,3
	temp.u32 = (ctx.v0.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v0.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v0.u32[3]&0x7FE000)>>13) : 0x0;
	ctx.v61.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v61.u16[7] |= ((ctx.v0.u32[3]&0x80000000)>>16);
	temp.u32 = (ctx.v0.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v0.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v0.u32[2]&0x7FE000)>>13) : 0x0;
	ctx.v61.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v61.u16[6] |= ((ctx.v0.u32[2]&0x80000000)>>16);
	// vspltw128 v62,v61,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v61.u32), 0xFF));
	// stvewx128 v62,r10,r6
	ea = (ctx.r10.u32 + ctx.r6.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r6,0(r31)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// lfs f0,0(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,4(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f12.f64 = double(temp.f32);
	// fadds f13,f13,f12
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f12.f64));
	// stfs f13,132(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 132, temp.u32);
	// stfs f0,128(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 128, temp.u32);
	// lvx128 v13,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r6,r8
	ea = (ctx.r6.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v12,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vmaddfp v0,v12,v0,v13
	ctx.fpscr.enableFlushModeUnconditional();
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v12.f32), simde_mm_load_ps(ctx.v0.f32)), simde_mm_load_ps(ctx.v13.f32)));
	// vmaddfp v0,v0,v7,v6
	simde_mm_store_ps(ctx.v0.f32, simde_mm_add_ps(simde_mm_mul_ps(simde_mm_load_ps(ctx.v0.f32), simde_mm_load_ps(ctx.v7.f32)), simde_mm_load_ps(ctx.v6.f32)));
	// vpkd3d128 v60,v0,3,1,3
	temp.u32 = (ctx.v0.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v0.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v0.u32[3]&0x7FE000)>>13) : 0x0;
	ctx.v60.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v60.u16[7] |= ((ctx.v0.u32[3]&0x80000000)>>16);
	temp.u32 = (ctx.v0.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v0.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v0.u32[2]&0x7FE000)>>13) : 0x0;
	ctx.v60.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v60.u16[6] |= ((ctx.v0.u32[2]&0x80000000)>>16);
	// vspltw128 v62,v60,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v60.u32), 0xFF));
	// stvewx128 v62,r10,r27
	ea = (ctx.r10.u32 + ctx.r27.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,144(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 144, temp.u32);
	// stfs f13,148(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 148, temp.u32);
	// lvx128 v62,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkd3d128 v59,v62,3,1,3
	ctx.fpscr.enableFlushModeUnconditional();
	temp.u32 = (ctx.v62.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v62.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v62.u32[3]&0x7FE000)>>13) : 0x0;
	ctx.v59.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v59.u16[7] |= ((ctx.v62.u32[3]&0x80000000)>>16);
	temp.u32 = (ctx.v62.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v62.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v62.u32[2]&0x7FE000)>>13) : 0x0;
	ctx.v59.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v59.u16[6] |= ((ctx.v62.u32[2]&0x80000000)>>16);
	// vspltw128 v62,v59,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v59.u32), 0xFF));
	// stvewx128 v62,r10,r26
	ea = (ctx.r10.u32 + ctx.r26.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f13,20(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,24(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,160(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 160, temp.u32);
	// stfs f13,164(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 164, temp.u32);
	// lvx128 v62,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkd3d128 v58,v62,3,1,3
	ctx.fpscr.enableFlushModeUnconditional();
	temp.u32 = (ctx.v62.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v62.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v62.u32[3]&0x7FE000)>>13) : 0x0;
	ctx.v58.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v58.u16[7] |= ((ctx.v62.u32[3]&0x80000000)>>16);
	temp.u32 = (ctx.v62.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v62.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v62.u32[2]&0x7FE000)>>13) : 0x0;
	ctx.v58.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v58.u16[6] |= ((ctx.v62.u32[2]&0x80000000)>>16);
	// vspltw128 v62,v58,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v58.u32), 0xFF));
	// stvewx128 v62,r10,r25
	ea = (ctx.r10.u32 + ctx.r25.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// lfs f13,16(r11)
	ctx.fpscr.disableFlushModeUnconditional();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// lfs f0,28(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,180(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 180, temp.u32);
	// stfs f13,176(r1)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r1.u32 + 176, temp.u32);
	// lvx128 v62,r0,r24
	ea = (ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// vpkd3d128 v57,v62,3,1,3
	ctx.fpscr.enableFlushModeUnconditional();
	temp.u32 = (ctx.v62.u32[3]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v62.u32[3]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v62.u32[3]&0x7FE000)>>13) : 0x0;
	ctx.v57.u16[7] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v57.u16[7] |= ((ctx.v62.u32[3]&0x80000000)>>16);
	temp.u32 = (ctx.v62.u32[2]&0x7FFFFFFF);
	vTemp.u8[0] = (temp.f32 != temp.f32) || (temp.f32 > 65504.0f) ? 0xFF : ((ctx.v62.u32[2]&0x7f800000)>>23);
	temp.u16 = vTemp.u8[0] != 0xFF ? ((ctx.v62.u32[2]&0x7FE000)>>13) : 0x0;
	ctx.v57.u16[6] = vTemp.u8[0] != 0xFF ? (vTemp.u8[0] > 0x70 ? (((vTemp.u8[0]-0x70)<<10)+temp.u16) : (0x71-vTemp.u8[0] > 31 ? 0x0 : ((0x400+temp.u16)>>(0x71-vTemp.u8[0])))) : 0x7FFF;
	ctx.v57.u16[6] |= ((ctx.v62.u32[2]&0x80000000)>>16);
	// addi r3,r3,36
	ctx.r3.s64 = ctx.r3.s64 + 36;
	// vspltw128 v62,v57,0
	simde_mm_store_si128((simde__m128i*)ctx.v62.u32, simde_mm_shuffle_epi32(simde_mm_load_si128((simde__m128i*)ctx.v57.u32), 0xFF));
	// stvewx128 v62,r10,r23
	ea = (ctx.r10.u32 + ctx.r23.u32) & ~0x3;
	REX_STORE_U32(ea, ctx.v62.u32[3 - ((ea & 0xF) >> 2)]);
	// lwz r6,32(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r29,83(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r4,82(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r4,r29,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwimi r6,r4,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r5,r6,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lbz r29,82(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r6,83(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r4,81(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// stb r5,-2(r10)
	REX_STORE_U8(ctx.r10.u32 + -2, ctx.r5.u8);
	// stb r29,0(r10)
	REX_STORE_U8(ctx.r10.u32 + 0, ctx.r29.u8);
	// stb r4,-1(r10)
	REX_STORE_U8(ctx.r10.u32 + -1, ctx.r4.u8);
	// stb r6,1(r10)
	REX_STORE_U8(ctx.r10.u32 + 1, ctx.r6.u8);
	// lwz r6,32(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r4,83(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// lbz r29,82(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// rlwimi r29,r4,8,16,23
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFF00) | (ctx.r29.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r29,16
	ctx.r4.u64 = ctx.r29.u32 & 0xFFFF;
	// lbz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// rlwimi r6,r4,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r5,r6,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lbz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r29,81(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r5,83(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// stb r5,13(r10)
	REX_STORE_U8(ctx.r10.u32 + 13, ctx.r5.u8);
	// lbz r6,82(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// stb r4,10(r10)
	REX_STORE_U8(ctx.r10.u32 + 10, ctx.r4.u8);
	// stb r29,11(r10)
	REX_STORE_U8(ctx.r10.u32 + 11, ctx.r29.u8);
	// stb r6,12(r10)
	REX_STORE_U8(ctx.r10.u32 + 12, ctx.r6.u8);
	// lwz r6,32(r11)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r11.u32 + 32);
	// addi r11,r11,36
	ctx.r11.s64 = ctx.r11.s64 + 36;
	// stw r6,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r6.u32);
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// lbz r5,80(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r4,82(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r29,83(r1)
	ctx.r29.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// rlwimi r4,r29,8,16,23
	ctx.r4.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 8) & 0xFF00) | (ctx.r4.u64 & 0xFFFFFFFFFFFF00FF);
	// clrlwi r4,r4,16
	ctx.r4.u64 = ctx.r4.u32 & 0xFFFF;
	// rlwimi r6,r4,8,0,23
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r6.u64 & 0xFFFFFFFF000000FF);
	// rlwimi r5,r6,8,0,23
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFFFFFF00) | (ctx.r5.u64 & 0xFFFFFFFF000000FF);
	// stw r5,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r5.u32);
	// lbz r5,82(r1)
	ctx.r5.u64 = REX_LOAD_U8(ctx.r1.u32 + 82);
	// lbz r6,83(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 83);
	// stb r6,25(r10)
	REX_STORE_U8(ctx.r10.u32 + 25, ctx.r6.u8);
	// lbz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r1.u32 + 80);
	// lbz r6,81(r1)
	ctx.r6.u64 = REX_LOAD_U8(ctx.r1.u32 + 81);
	// stb r6,23(r10)
	REX_STORE_U8(ctx.r10.u32 + 23, ctx.r6.u8);
	// stb r5,24(r10)
	REX_STORE_U8(ctx.r10.u32 + 24, ctx.r5.u8);
	// stb r4,22(r10)
	REX_STORE_U8(ctx.r10.u32 + 22, ctx.r4.u8);
	// addi r10,r10,36
	ctx.r10.s64 = ctx.r10.s64 + 36;
	// lwz r6,0(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// blt cr6,0x8260ce6c
	if (ctx.cr6.lt) goto loc_8260CE6C;
loc_8260D0C0:
	// addi r1,r1,288
	ctx.r1.s64 = ctx.r1.s64 + 288;
	// b 0x82739f50
	__restgprlr_22(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82639840) {
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
	// stw r4,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r4.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// stw r3,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r3.u32);
	// li r7,8
	ctx.r7.s64 = 8;
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// ori r4,r4,8
	ctx.r4.u64 = ctx.r4.u64 | 8;
	// li r3,251
	ctx.r3.s64 = 251;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// bl 0x82855704
	ctx.lr = 0x82639874;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82639884
	if (!ctx.cr0.lt) goto loc_82639884;
	// li r3,1627
	ctx.r3.s64 = 1627;
	// b 0x826398a4
	goto loc_826398A4;
loc_82639884:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x826398a0
	if (!ctx.cr6.eq) goto loc_826398A0;
	// bl 0x8263bcc8
	ctx.lr = 0x82639890;
	sub_8263BCC8(ctx, base);
	// li r11,1627
	ctx.r11.s64 = 1627;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// and r3,r10,r11
	ctx.r3.u64 = ctx.r10.u64 & ctx.r11.u64;
	// b 0x826398a4
	goto loc_826398A4;
loc_826398A0:
	// li r3,997
	ctx.r3.s64 = 997;
loc_826398A4:
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

DEFINE_REX_FUNC(sub_8263A978) {
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
	// lis r11,-32116
	ctx.r11.s64 = -2104754176;
	// lwz r11,13024(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 13024);
	// lwz r11,4(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8263A998;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8263a9a8
	if (ctx.cr0.lt) goto loc_8263A9A8;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x8263a9b0
	goto loc_8263A9B0;
loc_8263A9A8:
	// bl 0x8263bc90
	ctx.lr = 0x8263A9AC;
	sub_8263BC90(ctx, base);
	// li r3,0
	ctx.r3.s64 = 0;
loc_8263A9B0:
	// addi r1,r1,96
	ctx.r1.s64 = ctx.r1.s64 + 96;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8263B770) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8263B778;
	__savegprlr_29(ctx, base);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// stw r4,204(r1)
	REX_STORE_U32(ctx.r1.u32 + 204, ctx.r4.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r31,0
	ctx.r31.s64 = 0;
	// li r5,24
	ctx.r5.s64 = 24;
	// li r4,0
	ctx.r4.s64 = 0;
	// stw r31,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r31.u32);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x8273a590
	ctx.lr = 0x8263B7A0;
	sub_8273A590(ctx, base);
	// addi r11,r1,108
	ctx.r11.s64 = ctx.r1.s64 + 108;
	// stw r31,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r31.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// li r5,1
	ctx.r5.s64 = 1;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r3,r1,124
	ctx.r3.s64 = ctx.r1.s64 + 124;
	// stw r31,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r31.u32);
	// bl 0x82855a14
	ctx.lr = 0x8263B7C0;
	__imp__NtCreateEvent(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x8263b820
	if (ctx.cr0.lt) goto loc_8263B820;
	// addi r8,r1,104
	ctx.r8.s64 = ctx.r1.s64 + 104;
	// addi r11,r1,112
	ctx.r11.s64 = ctx.r1.s64 + 112;
	// stw r8,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r8.u32);
	// mr r10,r29
	ctx.r10.u64 = ctx.r29.u64;
	// li r9,1
	ctx.r9.s64 = 1;
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// addi r7,r1,204
	ctx.r7.s64 = ctx.r1.s64 + 204;
	// li r6,1
	ctx.r6.s64 = 1;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// li r3,255
	ctx.r3.s64 = 255;
	// bl 0x828558b4
	ctx.lr = 0x8263B7FC;
	__imp__XamShowMessageBoxUIEx(ctx, base);
	// stw r3,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// cmplwi cr6,r3,997
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 997, ctx.xer);
	// bne cr6,0x8263b818
	if (!ctx.cr6.eq) goto loc_8263B818;
	// li r5,1
	ctx.r5.s64 = 1;
	// addi r4,r1,96
	ctx.r4.s64 = ctx.r1.s64 + 96;
	// addi r3,r1,112
	ctx.r3.s64 = ctx.r1.s64 + 112;
	// bl 0x82639e80
	ctx.lr = 0x8263B818;
	sub_82639E80(ctx, base);
loc_8263B818:
	// lwz r3,124(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 124);
	// bl 0x82855ae4
	ctx.lr = 0x8263B820;
	__imp__NtClose(ctx, base);
loc_8263B820:
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82641850) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82641858;
	__savegprlr_29(ctx, base);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mullw r3,r5,r6
	ctx.r3.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r6.s32);
	// lis r4,9367
	ctx.r4.s64 = 613875712;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r6
	ctx.r29.u64 = ctx.r6.u64;
	// bl 0x8263b678
	ctx.lr = 0x82641874;
	sub_8263B678(ctx, base);
	// stw r3,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r3.u32);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq 0x8264189c
	if (ctx.cr0.eq) goto loc_8264189C;
	// clrldi r11,r29,32
	ctx.r11.u64 = ctx.r29.u64 & 0xFFFFFFFF;
	// stw r30,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r30.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// li r3,0
	ctx.r3.s64 = 0;
	// slw r11,r10,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r11.u8 & 0x3F));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x826418ac
	goto loc_826418AC;
loc_8264189C:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// li r11,0
	ctx.r11.s64 = 0;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// stw r11,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r11.u32);
loc_826418AC:
	// stw r11,8(r31)
	REX_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82642D40) {
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
	// addi r11,r3,4
	ctx.r11.s64 = ctx.r3.s64 + 4;
loc_82642D54:
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
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
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
	// bne 0x82642d54
	if (!ctx.cr0.eq) goto loc_82642D54;
	// mr r31,r10
	ctx.r31.u64 = ctx.r10.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82642db0
	if (!ctx.cr6.eq) goto loc_82642DB0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82642d9c
	if (ctx.cr6.eq) goto loc_82642D9C;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r11,12(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 12);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82642D98;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82642da0
	goto loc_82642DA0;
loc_82642D9C:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82642DA0:
	// bl 0x8264cf40
	ctx.lr = 0x82642DA4;
	sub_8264CF40(ctx, base);
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// addi r3,r11,13120
	ctx.r3.s64 = ctx.r11.s64 + 13120;
	// bl 0x82641f78
	ctx.lr = 0x82642DB0;
	sub_82641F78(ctx, base);
loc_82642DB0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
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

DEFINE_REX_FUNC(sub_82646720) {
	REX_FUNC_PROLOGUE();
	// lwz r11,12(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beqlr cr6
	if (ctx.cr6.eq) return;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,20(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 20);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctr 
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	return;
}

DEFINE_REX_FUNC(sub_82647468) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82647470;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,64(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x826475bc
	if (ctx.cr6.eq) goto loc_826475BC;
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// rlwinm. r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x826474a4
	if (ctx.cr0.eq) goto loc_826474A4;
	// lis r30,-30570
	ctx.r30.s64 = -2003435520;
	// ori r30,r30,1
	ctx.r30.u64 = ctx.r30.u64 | 1;
	// b 0x826475bc
	goto loc_826475BC;
loc_826474A4:
	// lwz r11,60(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,68(r31)
	REX_STORE_U32(ctx.r31.u32 + 68, ctx.r4.u32);
	// stw r4,64(r31)
	REX_STORE_U32(ctx.r31.u32 + 64, ctx.r4.u32);
	// stw r11,60(r31)
	REX_STORE_U32(ctx.r31.u32 + 60, ctx.r11.u32);
	// bl 0x82654848
	ctx.lr = 0x826474BC;
	sub_82654848(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x826475bc
	if (ctx.cr0.lt) goto loc_826475BC;
	// lwz r3,52(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 52);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826474dc
	if (ctx.cr6.eq) goto loc_826474DC;
	// bl 0x82652a98
	ctx.lr = 0x826474D4;
	sub_82652A98(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// b 0x826474e0
	goto loc_826474E0;
loc_826474DC:
	// mr r30,r28
	ctx.r30.u64 = ctx.r28.u64;
loc_826474E0:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826475bc
	if (ctx.cr6.lt) goto loc_826475BC;
	// lwz r11,56(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 56);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8264758c
	if (ctx.cr0.eq) goto loc_8264758C;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// addi r29,r31,132
	ctx.r29.s64 = ctx.r31.s64 + 132;
	// lwz r4,132(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 132);
	// bl 0x826424a8
	ctx.lr = 0x82647504;
	sub_826424A8(ctx, base);
	// stw r28,132(r31)
	REX_STORE_U32(ctx.r31.u32 + 132, ctx.r28.u32);
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// stw r28,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r28.u32);
	// bl 0x82645460
	ctx.lr = 0x82647514;
	sub_82645460(ctx, base);
	// mr. r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt 0x826475bc
	if (ctx.cr0.lt) goto loc_826475BC;
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// lwz r5,140(r31)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lwz r7,4(r11)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// bl 0x82653858
	ctx.lr = 0x8264753C;
	sub_82653858(ctx, base);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// lwz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// lwz r11,8(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82647558;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826475bc
	if (ctx.cr6.lt) goto loc_826475BC;
	// lwz r11,4(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 4);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8264758c
	if (!ctx.cr6.eq) goto loc_8264758C;
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lis r4,4919
	ctx.r4.s64 = 322371584;
	// ori r4,r4,61441
	ctx.r4.u64 = ctx.r4.u64 | 61441;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82647588;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_8264758C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x826475bc
	if (ctx.cr6.lt) goto loc_826475BC;
	// lwz r3,140(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 140);
	// lis r5,4919
	ctx.r5.s64 = 322371584;
	// lwz r11,120(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 120);
	// ori r5,r5,61441
	ctx.r5.u64 = ctx.r5.u64 | 61441;
	// lwz r10,0(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r4,4(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,44(r10)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + 44);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x826475B8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
loc_826475BC:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8264E978) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8264E980;
	__savegprlr_29(ctx, base);
	// stfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -40, ctx.f31.u64);
	// stwu r1,-176(r1)
	ea = -176 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r8,64(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 64);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x8264eae0
	if (ctx.cr6.lt) goto loc_8264EAE0;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// addi r11,r3,40
	ctx.r11.s64 = ctx.r3.s64 + 40;
	// lwz r7,56(r3)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// stw r10,40(r3)
	REX_STORE_U32(ctx.r3.u32 + 40, ctx.r10.u32);
	// lwz r3,0(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 0);
	// lfs f31,5864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5864);
	ctx.f31.f64 = double(temp.f32);
	// stw r7,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r7.u32);
	// lfs f0,80(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// stw r3,44(r31)
	REX_STORE_U32(ctx.r31.u32 + 44, ctx.r3.u32);
	// bne cr6,0x8264ea98
	if (!ctx.cr6.eq) goto loc_8264EA98;
	// lwz r9,60(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 60);
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// beq cr6,0x8264ea34
	if (ctx.cr6.eq) goto loc_8264EA34;
	// lwz r7,72(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// addi r6,r1,80
	ctx.r6.s64 = ctx.r1.s64 + 80;
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r3,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r3.u32);
	// stfs f31,80(r1)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// stw r6,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r6.u32);
	// stw r10,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// addi r3,r1,96
	ctx.r3.s64 = ctx.r1.s64 + 96;
	// stw r9,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r9.u32);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// stw r8,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r8.u32);
	// stw r7,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r7.u32);
	// stw r7,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r7.u32);
	// stw r10,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r10.u32);
	// stw r5,132(r1)
	REX_STORE_U32(ctx.r1.u32 + 132, ctx.r5.u32);
	// lwz r11,84(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 84);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x8264EA30;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x8264ea40
	goto loc_8264EA40;
loc_8264EA34:
	// rlwinm r5,r8,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r4,0(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// bl 0x8263a4c0
	ctx.lr = 0x8264EA40;
	sub_8263A4C0(ctx, base);
loc_8264EA40:
	// lwz r10,68(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x8264eaf4
	if (ctx.cr6.eq) goto loc_8264EAF4;
	// lwz r9,72(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r11,44(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r11
	ctx.r4.u64 = ctx.r10.u64 + ctx.r11.u64;
	// bl 0x8273a030
	ctx.lr = 0x8264EA6C;
	sub_8273A030(ctx, base);
	// lwz r9,72(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r8,68(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// rlwinm r5,r9,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r10,44(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 44);
	// subf r9,r9,r8
	ctx.r9.u64 = ctx.r8.u64 - ctx.r9.u64;
	// lwz r11,48(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r5,r11
	ctx.r3.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// bl 0x8273a030
	ctx.lr = 0x8264EA94;
	sub_8273A030(ctx, base);
	// b 0x8264eaf4
	goto loc_8264EAF4;
loc_8264EA98:
	// lwz r10,80(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8264EAA8;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lfs f0,92(r31)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 92);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bne cr6,0x8264eaf4
	if (!ctx.cr6.eq) goto loc_8264EAF4;
	// lfs f0,96(r31)
	temp.u32 = REX_LOAD_U32(ctx.r31.u32 + 96);
	ctx.f0.f64 = double(temp.f32);
	// fcmpu cr6,f0,f31
	ctx.cr6.compare(ctx.f0.f64, ctx.f31.f64);
	// bne cr6,0x8264eaf4
	if (!ctx.cr6.eq) goto loc_8264EAF4;
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,76(r31)
	REX_STORE_U32(ctx.r31.u32 + 76, ctx.r10.u32);
	// lfs f0,2524(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,80(r1)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + 80, temp.u32);
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// stw r11,52(r31)
	REX_STORE_U32(ctx.r31.u32 + 52, ctx.r11.u32);
	// b 0x8264eaf4
	goto loc_8264EAF4;
loc_8264EAE0:
	// lwz r11,72(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// li r4,0
	ctx.r4.s64 = 0;
	// lwz r3,48(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 48);
	// mulli r5,r11,12
	ctx.r5.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(12));
	// bl 0x8273a590
	ctx.lr = 0x8264EAF4;
	sub_8273A590(ctx, base);
loc_8264EAF4:
	// lwz r10,72(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 72);
	// lwz r11,68(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 68);
	// twllei r10,0
	if (ctx.r10.s32 == 0 || ctx.r10.u32 < 0u) ppc_trap(ctx, base, 0);
	// divwu r11,r11,r10
	ctx.r11.u64 = uint32_t(ctx.r10.u32 ? ctx.r11.u32 / ctx.r10.u32 : 0);
	// stw r11,8(r29)
	REX_STORE_U32(ctx.r29.u32 + 8, ctx.r11.u32);
	// lwz r11,4(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// stw r11,4(r29)
	REX_STORE_U32(ctx.r29.u32 + 4, ctx.r11.u32);
	// addi r1,r1,176
	ctx.r1.s64 = ctx.r1.s64 + 176;
	// lfd f31,-40(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -40);
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8265F948) {
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
	// addi r3,r3,4
	ctx.r3.s64 = ctx.r3.s64 + 4;
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// bl 0x82660900
	ctx.lr = 0x8265F96C;
	sub_82660900(ctx, base);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r30,28(r31)
	REX_STORE_U32(ctx.r31.u32 + 28, ctx.r30.u32);
	// addi r11,r11,24344
	ctx.r11.s64 = ctx.r11.s64 + 24344;
	// addi r10,r10,24288
	ctx.r10.s64 = ctx.r10.s64 + 24288;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r10,4(r31)
	REX_STORE_U32(ctx.r31.u32 + 4, ctx.r10.u32);
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

DEFINE_REX_FUNC(sub_82661150) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82661158;
	__savegprlr_28(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bl 0x826610d0
	ctx.lr = 0x82661168;
	sub_826610D0(ctx, base);
	// lwz r30,212(r29)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r29.u32 + 212);
	// b 0x826611d0
	goto loc_826611D0;
loc_82661170:
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x8266118c
	if (ctx.cr6.eq) goto loc_8266118C;
	// lwz r30,4(r30)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r31,0(r11)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// b 0x82661190
	goto loc_82661190;
loc_8266118C:
	// li r31,0
	ctx.r31.s64 = 0;
loc_82661190:
	// lwz r11,12(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 12);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// beq cr6,0x826611b4
	if (ctx.cr6.eq) goto loc_826611B4;
	// lwz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 0);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// bne cr6,0x826611d0
	if (!ctx.cr6.eq) goto loc_826611D0;
	// lwz r11,20(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// cmplw cr6,r11,r28
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x826611d0
	if (!ctx.cr6.eq) goto loc_826611D0;
loc_826611B4:
	// addi r3,r29,8
	ctx.r3.s64 = ctx.r29.s64 + 8;
	// bl 0x8264d498
	ctx.lr = 0x826611BC;
	sub_8264D498(ctx, base);
	// lwz r11,8(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// beq cr6,0x826611d0
	if (ctx.cr6.eq) goto loc_826611D0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8264cf40
	ctx.lr = 0x826611D0;
	sub_8264CF40(ctx, base);
loc_826611D0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82661170
	if (!ctx.cr6.eq) goto loc_82661170;
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826690C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739efc
	ctx.lr = 0x826690D0;
	__savegprlr_21(ctx, base);
	// stfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + -112, ctx.f30.u64);
	// stfd f31,-104(r1)
	REX_STORE_U64(ctx.r1.u32 + -104, ctx.f31.u64);
	// lwz r10,16(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// lis r5,-32256
	ctx.r5.s64 = -2113929216;
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,12(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 12);
	// addi r9,r11,48
	ctx.r9.s64 = ctx.r11.s64 + 48;
	// lwz r31,24(r3)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lwz r8,0(r3)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// stw r10,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r10.u32);
	// lfs f13,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	ctx.f13.f64 = double(temp.f32);
	// fctiwz f12,f13
	ctx.f12.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f12,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.f12.u64);
	// lwz r10,-204(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -204);
	// extsw r11,r10
	ctx.r11.s64 = ctx.r10.s32;
	// std r11,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.r11.u64);
	// lfd f11,-208(r1)
	ctx.f11.u64 = REX_LOAD_U64(ctx.r1.u32 + -208);
	// fcfid f10,f11
	ctx.f10.f64 = double(ctx.f11.s64);
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// frsp f9,f10
	ctx.f9.f64 = double(float(ctx.f10.f64));
	// add r10,r10,r6
	ctx.r10.u64 = ctx.r10.u64 + ctx.r6.u64;
	// lfs f12,24804(r5)
	temp.u32 = REX_LOAD_U32(ctx.r5.u32 + 24804);
	ctx.f12.f64 = double(temp.f32);
	// stw r4,-208(r1)
	REX_STORE_U32(ctx.r1.u32 + -208, ctx.r4.u32);
	// lwz r4,4(r3)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r3.u32 + 4);
	// lfs f0,-208(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -208);
	ctx.f0.f64 = double(temp.f32);
	// lwz r30,28(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// lwz r11,36(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 36);
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// fsubs f11,f13,f9
	ctx.f11.f64 = double(float(ctx.f13.f64 - ctx.f9.f64));
	// beq cr6,0x82669210
	if (ctx.cr6.eq) goto loc_82669210;
	// lhz r10,8(r8)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r8.u32 + 8);
	// lhz r28,10(r8)
	ctx.r28.u64 = REX_LOAD_U16(ctx.r8.u32 + 10);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// lhz r6,0(r8)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// lhz r29,2(r8)
	ctx.r29.u64 = REX_LOAD_U16(ctx.r8.u32 + 2);
	// std r10,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.r10.u64);
	// extsh r10,r28
	ctx.r10.s64 = ctx.r28.s16;
	// lhz r26,6(r8)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r8.u32 + 6);
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lfd f13,-208(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -208);
	// lhz r27,4(r8)
	ctx.r27.u64 = REX_LOAD_U16(ctx.r8.u32 + 4);
	// extsh r29,r29
	ctx.r29.s64 = ctx.r29.s16;
	// std r10,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.r10.u64);
	// std r6,-200(r1)
	REX_STORE_U64(ctx.r1.u32 + -200, ctx.r6.u64);
	// extsh r10,r26
	ctx.r10.s64 = ctx.r26.s16;
	// std r29,-192(r1)
	REX_STORE_U64(ctx.r1.u32 + -192, ctx.r29.u64);
	// extsh r6,r27
	ctx.r6.s64 = ctx.r27.s16;
	// lfd f9,-192(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + -192);
	// std r10,-192(r1)
	REX_STORE_U64(ctx.r1.u32 + -192, ctx.r10.u64);
	// lfd f10,-200(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + -200);
	// std r6,-200(r1)
	REX_STORE_U64(ctx.r1.u32 + -200, ctx.r6.u64);
	// lfd f7,-192(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -192);
	// fcfid f1,f13
	ctx.f1.f64 = double(ctx.f13.s64);
	// lfd f5,-200(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -200);
	// lfd f8,-208(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -208);
	// fcfid f13,f8
	ctx.f13.f64 = double(ctx.f8.s64);
	// fcfid f6,f7
	ctx.f6.f64 = double(ctx.f7.s64);
	// fcfid f4,f10
	ctx.f4.f64 = double(ctx.f10.s64);
	// fcfid f3,f5
	ctx.f3.f64 = double(ctx.f5.s64);
	// fcfid f2,f9
	ctx.f2.f64 = double(ctx.f9.s64);
	// frsp f5,f13
	ctx.f5.f64 = double(float(ctx.f13.f64));
	// frsp f10,f6
	ctx.f10.f64 = double(float(ctx.f6.f64));
	// frsp f9,f4
	ctx.f9.f64 = double(float(ctx.f4.f64));
	// frsp f8,f3
	ctx.f8.f64 = double(float(ctx.f3.f64));
	// frsp f7,f2
	ctx.f7.f64 = double(float(ctx.f2.f64));
	// frsp f6,f1
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// fmuls f4,f10,f12
	ctx.f4.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f4,12(r9)
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ctx.r9.u32 + 12, temp.u32);
	// fmuls f3,f9,f12
	ctx.f3.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfs f3,0(r9)
	temp.f32 = float(ctx.f3.f64);
	REX_STORE_U32(ctx.r9.u32 + 0, temp.u32);
	// fmuls f2,f8,f12
	ctx.f2.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfs f2,8(r9)
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ctx.r9.u32 + 8, temp.u32);
	// fmuls f1,f7,f12
	ctx.f1.f64 = double(float(ctx.f7.f64 * ctx.f12.f64));
	// stfs f1,4(r9)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r9.u32 + 4, temp.u32);
	// fmuls f13,f6,f12
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f12.f64));
	// stfs f13,16(r9)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r9.u32 + 16, temp.u32);
	// fmuls f10,f5,f12
	ctx.f10.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// stfs f10,20(r9)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r9.u32 + 20, temp.u32);
loc_82669210:
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// lfs f13,5864(r10)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
	// bge cr6,0x82669324
	if (!ctx.cr6.lt) goto loc_82669324;
	// mr r10,r4
	ctx.r10.u64 = ctx.r4.u64;
loc_82669224:
	// cmplw cr6,r7,r30
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82669564
	if (!ctx.cr6.lt) goto loc_82669564;
	// addi r29,r11,-6
	ctx.r29.s64 = ctx.r11.s64 + -6;
	// addi r28,r11,-5
	ctx.r28.s64 = ctx.r11.s64 + -5;
	// addi r27,r11,-4
	ctx.r27.s64 = ctx.r11.s64 + -4;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r29,r29,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r27,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// addi r26,r11,2
	ctx.r26.s64 = ctx.r11.s64 + 2;
	// addi r25,r11,-3
	ctx.r25.s64 = ctx.r11.s64 + -3;
	// lfsx f9,r29,r9
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r9.u32);
	ctx.f9.f64 = double(temp.f32);
	// addi r24,r11,3
	ctx.r24.s64 = ctx.r11.s64 + 3;
	// lfsx f8,r28,r9
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r9.u32);
	ctx.f8.f64 = double(temp.f32);
	// addi r23,r11,-2
	ctx.r23.s64 = ctx.r11.s64 + -2;
	// lfsx f7,r27,r9
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r9.u32);
	ctx.f7.f64 = double(temp.f32);
	// addi r22,r11,4
	ctx.r22.s64 = ctx.r11.s64 + 4;
	// lfs f6,0(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 0);
	ctx.f6.f64 = double(temp.f32);
	// addi r21,r11,5
	ctx.r21.s64 = ctx.r11.s64 + 5;
	// lfs f3,4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f3.f64 = double(temp.f32);
	// rlwinm r26,r26,2,0,29
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f4,f6,f9
	ctx.f4.f64 = double(float(ctx.f6.f64 - ctx.f9.f64));
	// rlwinm r25,r25,2,0,29
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// fsubs f1,f3,f8
	ctx.f1.f64 = double(float(ctx.f3.f64 - ctx.f8.f64));
	// rlwinm r24,r24,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lfs f10,-4(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + -4);
	ctx.f10.f64 = double(temp.f32);
	// rlwinm r29,r23,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r28,r22,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r27,r21,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsx f6,r26,r9
	temp.u32 = REX_LOAD_U32(ctx.r26.u32 + ctx.r9.u32);
	ctx.f6.f64 = double(temp.f32);
	// lfsx f5,r25,r9
	temp.u32 = REX_LOAD_U32(ctx.r25.u32 + ctx.r9.u32);
	ctx.f5.f64 = double(temp.f32);
	// fsubs f6,f6,f7
	ctx.f6.f64 = double(float(ctx.f6.f64 - ctx.f7.f64));
	// lfsx f3,r24,r9
	temp.u32 = REX_LOAD_U32(ctx.r24.u32 + ctx.r9.u32);
	ctx.f3.f64 = double(temp.f32);
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// lfsx f2,r29,r9
	temp.u32 = REX_LOAD_U32(ctx.r29.u32 + ctx.r9.u32);
	ctx.f2.f64 = double(temp.f32);
	// fsubs f3,f3,f5
	ctx.f3.f64 = double(float(ctx.f3.f64 - ctx.f5.f64));
	// lfsx f31,r28,r9
	temp.u32 = REX_LOAD_U32(ctx.r28.u32 + ctx.r9.u32);
	ctx.f31.f64 = double(temp.f32);
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// lfsx f30,r27,r9
	temp.u32 = REX_LOAD_U32(ctx.r27.u32 + ctx.r9.u32);
	ctx.f30.f64 = double(temp.f32);
	// fsubs f31,f31,f2
	ctx.f31.f64 = double(float(ctx.f31.f64 - ctx.f2.f64));
	// fsubs f30,f30,f10
	ctx.f30.f64 = double(float(ctx.f30.f64 - ctx.f10.f64));
	// fmadds f9,f4,f0,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f4.f64, ctx.f0.f64, ctx.f9.f64)));
	// stfs f9,0(r10)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmadds f8,f1,f0,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f1.f64, ctx.f0.f64, ctx.f8.f64)));
	// stfsu f8,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmadds f7,f6,f0,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f6.f64, ctx.f0.f64, ctx.f7.f64)));
	// stfsu f7,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmadds f6,f3,f0,f5
	ctx.f6.f64 = double(float(std::fma(ctx.f3.f64, ctx.f0.f64, ctx.f5.f64)));
	// stfsu f6,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmadds f5,f31,f0,f2
	ctx.f5.f64 = double(float(std::fma(ctx.f31.f64, ctx.f0.f64, ctx.f2.f64)));
	// stfsu f5,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmadds f4,f30,f0,f10
	ctx.f4.f64 = double(float(std::fma(ctx.f30.f64, ctx.f0.f64, ctx.f10.f64)));
	// stfsu f4,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// blt cr6,0x8266931c
	if (ctx.cr6.lt) goto loc_8266931C;
loc_8266930C:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8266930c
	if (!ctx.cr6.lt) goto loc_8266930C;
loc_8266931C:
	// cmpwi cr6,r11,6
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 6, ctx.xer);
	// blt cr6,0x82669224
	if (ctx.cr6.lt) goto loc_82669224;
loc_82669324:
	// cmplw cr6,r7,r30
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r30.u32, ctx.xer);
	// bge cr6,0x82669564
	if (!ctx.cr6.lt) goto loc_82669564;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
loc_82669334:
	// rlwinm r6,r11,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r29,r11,-5
	ctx.r29.s64 = ctx.r11.s64 + -5;
	// addi r4,r11,-6
	ctx.r4.s64 = ctx.r11.s64 + -6;
	// addi r28,r11,-4
	ctx.r28.s64 = ctx.r11.s64 + -4;
	// addi r27,r11,2
	ctx.r27.s64 = ctx.r11.s64 + 2;
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r28,r28,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r27,r27,1,0,30
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r29,r29,r8
	ctx.r29.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r8.u32);
	// addi r25,r11,-3
	ctx.r25.s64 = ctx.r11.s64 + -3;
	// lhz r23,2(r6)
	ctx.r23.u64 = REX_LOAD_U16(ctx.r6.u32 + 2);
	// addi r24,r11,3
	ctx.r24.s64 = ctx.r11.s64 + 3;
	// lhzx r4,r4,r8
	ctx.r4.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r8.u32);
	// extsh r29,r29
	ctx.r29.s64 = ctx.r29.s16;
	// lhzx r28,r28,r8
	ctx.r28.u64 = REX_LOAD_U16(ctx.r28.u32 + ctx.r8.u32);
	// extsh r23,r23
	ctx.r23.s64 = ctx.r23.s16;
	// lhzx r27,r27,r8
	ctx.r27.u64 = REX_LOAD_U16(ctx.r27.u32 + ctx.r8.u32);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lhz r26,0(r6)
	ctx.r26.u64 = REX_LOAD_U16(ctx.r6.u32 + 0);
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// extsh r26,r26
	ctx.r26.s64 = ctx.r26.s16;
	// subf r23,r29,r23
	ctx.r23.u64 = ctx.r23.u64 - ctx.r29.u64;
	// subf r26,r4,r26
	ctx.r26.u64 = ctx.r26.u64 - ctx.r4.u64;
	// subf r27,r28,r27
	ctx.r27.u64 = ctx.r27.u64 - ctx.r28.u64;
	// extsw r4,r4
	ctx.r4.s64 = ctx.r4.s32;
	// extsw r29,r29
	ctx.r29.s64 = ctx.r29.s32;
	// extsw r23,r23
	ctx.r23.s64 = ctx.r23.s32;
	// std r4,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.r4.u64);
	// extsw r28,r28
	ctx.r28.s64 = ctx.r28.s32;
	// lfd f5,-168(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// extsw r27,r27
	ctx.r27.s64 = ctx.r27.s32;
	// std r29,-208(r1)
	REX_STORE_U64(ctx.r1.u32 + -208, ctx.r29.u64);
	// std r23,-200(r1)
	REX_STORE_U64(ctx.r1.u32 + -200, ctx.r23.u64);
	// lfd f9,-200(r1)
	ctx.f9.u64 = REX_LOAD_U64(ctx.r1.u32 + -200);
	// lfd f8,-208(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -208);
	// std r28,-176(r1)
	REX_STORE_U64(ctx.r1.u32 + -176, ctx.r28.u64);
	// std r27,-184(r1)
	REX_STORE_U64(ctx.r1.u32 + -184, ctx.r27.u64);
	// lfd f7,-184(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -184);
	// lfd f6,-176(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -176);
	// extsw r26,r26
	ctx.r26.s64 = ctx.r26.s32;
	// rlwinm r29,r25,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// std r26,-192(r1)
	REX_STORE_U64(ctx.r1.u32 + -192, ctx.r26.u64);
	// lfd f10,-192(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + -192);
	// fcfid f3,f10
	ctx.f3.f64 = double(ctx.f10.s64);
	// rlwinm r4,r24,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// lhzx r4,r4,r8
	ctx.r4.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r8.u32);
	// fcfid f2,f9
	ctx.f2.f64 = double(ctx.f9.s64);
	// lhzx r29,r29,r8
	ctx.r29.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r8.u32);
	// fcfid f1,f8
	ctx.f1.f64 = double(ctx.f8.s64);
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// fcfid f10,f7
	ctx.f10.f64 = double(ctx.f7.s64);
	// extsh r29,r29
	ctx.r29.s64 = ctx.r29.s16;
	// fcfid f9,f6
	ctx.f9.f64 = double(ctx.f6.s64);
	// addi r7,r7,6
	ctx.r7.s64 = ctx.r7.s64 + 6;
	// frsp f6,f3
	ctx.f6.f64 = double(float(ctx.f3.f64));
	// subf r4,r29,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r29.u64;
	// extsw r28,r29
	ctx.r28.s64 = ctx.r29.s32;
	// extsw r4,r4
	ctx.r4.s64 = ctx.r4.s32;
	// std r28,-152(r1)
	REX_STORE_U64(ctx.r1.u32 + -152, ctx.r28.u64);
	// std r4,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.r4.u64);
	// lfd f7,-160(r1)
	ctx.f7.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// frsp f8,f4
	ctx.f8.f64 = double(float(ctx.f4.f64));
	// frsp f5,f2
	ctx.f5.f64 = double(float(ctx.f2.f64));
	// frsp f4,f1
	ctx.f4.f64 = double(float(ctx.f1.f64));
	// frsp f3,f10
	ctx.f3.f64 = double(float(ctx.f10.f64));
	// frsp f2,f9
	ctx.f2.f64 = double(float(ctx.f9.f64));
	// fcfid f1,f7
	ctx.f1.f64 = double(ctx.f7.s64);
	// fmadds f10,f6,f0,f8
	ctx.f10.f64 = double(float(std::fma(ctx.f6.f64, ctx.f0.f64, ctx.f8.f64)));
	// fmadds f9,f5,f0,f4
	ctx.f9.f64 = double(float(std::fma(ctx.f5.f64, ctx.f0.f64, ctx.f4.f64)));
	// fmadds f8,f3,f0,f2
	ctx.f8.f64 = double(float(std::fma(ctx.f3.f64, ctx.f0.f64, ctx.f2.f64)));
	// frsp f7,f1
	ctx.f7.f64 = double(float(ctx.f1.f64));
	// fmuls f6,f10,f12
	ctx.f6.f64 = double(float(ctx.f10.f64 * ctx.f12.f64));
	// stfs f6,0(r10)
	temp.f32 = float(ctx.f6.f64);
	REX_STORE_U32(ctx.r10.u32 + 0, temp.u32);
	// fmuls f5,f9,f12
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfsu f5,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmuls f4,f8,f12
	ctx.f4.f64 = double(float(ctx.f8.f64 * ctx.f12.f64));
	// stfsu f4,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f4.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// addi r4,r11,5
	ctx.r4.s64 = ctx.r11.s64 + 5;
	// lhz r6,-2(r6)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r6.u32 + -2);
	// addi r29,r11,-2
	ctx.r29.s64 = ctx.r11.s64 + -2;
	// lfd f3,-152(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + -152);
	// rlwinm r4,r4,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// fcfid f2,f3
	ctx.f2.f64 = double(ctx.f3.s64);
	// addi r28,r11,4
	ctx.r28.s64 = ctx.r11.s64 + 4;
	// rlwinm r29,r29,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r28,r28,1,0,30
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// lhzx r4,r4,r8
	ctx.r4.u64 = REX_LOAD_U16(ctx.r4.u32 + ctx.r8.u32);
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
	// extsw r27,r6
	ctx.r27.s64 = ctx.r6.s32;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// lhzx r29,r29,r8
	ctx.r29.u64 = REX_LOAD_U16(ctx.r29.u32 + ctx.r8.u32);
	// std r27,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r27.u64);
	// subf r6,r6,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r6.u64;
	// lhzx r4,r28,r8
	ctx.r4.u64 = REX_LOAD_U16(ctx.r28.u32 + ctx.r8.u32);
	// extsh r29,r29
	ctx.r29.s64 = ctx.r29.s16;
	// frsp f9,f2
	ctx.f9.f64 = double(float(ctx.f2.f64));
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// extsh r4,r4
	ctx.r4.s64 = ctx.r4.s16;
	// std r6,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r6.u64);
	// lfd f6,-136(r1)
	ctx.f6.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// subf r6,r29,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r29.u64;
	// fcfid f2,f6
	ctx.f2.f64 = double(ctx.f6.s64);
	// extsw r6,r6
	ctx.r6.s64 = ctx.r6.s32;
	// lfd f1,-144(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// extsw r4,r29
	ctx.r4.s64 = ctx.r29.s32;
	// fcfid f10,f1
	ctx.f10.f64 = double(ctx.f1.s64);
	// std r6,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r6.u64);
	// lfd f3,-120(r1)
	ctx.f3.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// std r4,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.r4.u64);
	// lfd f5,-128(r1)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// fcfid f4,f5
	ctx.f4.f64 = double(ctx.f5.s64);
	// fcfid f1,f3
	ctx.f1.f64 = double(ctx.f3.s64);
	// frsp f8,f10
	ctx.f8.f64 = double(float(ctx.f10.f64));
	// fmadds f9,f7,f0,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f9.f64)));
	// frsp f10,f4
	ctx.f10.f64 = double(float(ctx.f4.f64));
	// frsp f7,f2
	ctx.f7.f64 = double(float(ctx.f2.f64));
	// frsp f6,f1
	ctx.f6.f64 = double(float(ctx.f1.f64));
	// fmuls f5,f9,f12
	ctx.f5.f64 = double(float(ctx.f9.f64 * ctx.f12.f64));
	// stfsu f5,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f5.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fmadds f4,f7,f0,f8
	ctx.f4.f64 = double(float(std::fma(ctx.f7.f64, ctx.f0.f64, ctx.f8.f64)));
	// fmadds f3,f6,f0,f10
	ctx.f3.f64 = double(float(std::fma(ctx.f6.f64, ctx.f0.f64, ctx.f10.f64)));
	// fadds f0,f11,f0
	ctx.f0.f64 = double(float(ctx.f11.f64 + ctx.f0.f64));
	// fmuls f2,f4,f12
	ctx.f2.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// fmuls f1,f3,f12
	ctx.f1.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// stfsu f1,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// stfsu f2,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f2.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// blt cr6,0x8266955c
	if (ctx.cr6.lt) goto loc_8266955C;
loc_8266954C:
	// fsubs f0,f0,f13
	ctx.fpscr.disableFlushMode();
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// fcmpu cr6,f0,f13
	ctx.cr6.compare(ctx.f0.f64, ctx.f13.f64);
	// bge cr6,0x8266954c
	if (!ctx.cr6.lt) goto loc_8266954C;
loc_8266955C:
	// cmplw cr6,r7,r30
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r30.u32, ctx.xer);
	// blt cr6,0x82669334
	if (ctx.cr6.lt) goto loc_82669334;
loc_82669564:
	// addi r10,r31,-6
	ctx.r10.s64 = ctx.r31.s64 + -6;
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// bge cr6,0x82669574
	if (!ctx.cr6.lt) goto loc_82669574;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
loc_82669574:
	// subf r10,r31,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r31.u64;
	// stfs f0,-208(r1)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r1.u32 + -208, temp.u32);
	// neg r7,r31
	ctx.r7.s64 = static_cast<int64_t>(-ctx.r31.u64);
	// lwz r6,-208(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + -208);
	// addi r11,r10,-6
	ctx.r11.s64 = ctx.r10.s64 + -6;
	// stw r6,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r6.u32);
	// stw r10,36(r3)
	REX_STORE_U32(ctx.r3.u32 + 36, ctx.r10.u32);
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8266963c
	if (!ctx.cr6.lt) goto loc_8266963C;
	// subf r10,r11,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r11.u64;
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x82669600
	if (ctx.cr6.lt) goto loc_82669600;
	// subf r10,r11,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r11.u64;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// addi r4,r10,-4
	ctx.r4.s64 = ctx.r10.s64 + -4;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r4,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// add r6,r6,r9
	ctx.r6.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 + ctx.r9.u64;
	// rlwinm r3,r10,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r6,-4
	ctx.r5.s64 = ctx.r6.s64 + -4;
	// addi r6,r4,-4
	ctx.r6.s64 = ctx.r4.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r11,r3,r11
	ctx.r11.u64 = ctx.r3.u64 + ctx.r11.u64;
loc_826695DC:
	// lfs f0,4(r6)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 4);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,4(r5)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r5.u32 + 4, temp.u32);
	// lfs f13,8(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 8);
	ctx.f13.f64 = double(temp.f32);
	// stfs f13,8(r5)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r5.u32 + 8, temp.u32);
	// lfs f11,12(r6)
	temp.u32 = REX_LOAD_U32(ctx.r6.u32 + 12);
	ctx.f11.f64 = double(temp.f32);
	// stfs f11,12(r5)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r5.u32 + 12, temp.u32);
	// lfsu f0,16(r6)
	ea = 16 + ctx.r6.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r6.u32 = ea;
	// stfsu f0,16(r5)
	ea = 16 + ctx.r5.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r5.u32 = ea;
	// bdnz 0x826695dc
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826695DC;
loc_82669600:
	// cmpw cr6,r11,r7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x8266963c
	if (!ctx.cr6.lt) goto loc_8266963C;
	// add r5,r11,r31
	ctx.r5.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r6,r11,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r10,r11,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r11.u64;
	// rlwinm r5,r5,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// addi r5,r7,-4
	ctx.r5.s64 = ctx.r7.s64 + -4;
	// addi r7,r6,-4
	ctx.r7.s64 = ctx.r6.s64 + -4;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82669630:
	// lfsu f0,4(r7)
	ctx.fpscr.disableFlushMode();
	ea = 4 + ctx.r7.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f0.f64 = double(temp.f32);
	ctx.r7.u32 = ea;
	// stfsu f0,4(r5)
	ea = 4 + ctx.r5.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r5.u32 = ea;
	// bdnz 0x82669630
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82669630;
loc_8266963C:
	// neg r10,r11
	ctx.r10.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// blt cr6,0x82669700
	if (ctx.cr6.lt) goto loc_82669700;
	// subfic r10,r11,-4
	ctx.xer.ca = ctx.r11.u32 <= 4294967292;
	ctx.r10.u64 = static_cast<uint64_t>(-4) - ctx.r11.u64;
	// add r6,r11,r31
	ctx.r6.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r10,r10,30,2,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 30) & 0x3FFFFFFF;
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// rlwinm r6,r6,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// addi r7,r7,-4
	ctx.r7.s64 = ctx.r7.s64 + -4;
	// addi r10,r6,-2
	ctx.r10.s64 = ctx.r6.s64 + -2;
	// add r11,r5,r11
	ctx.r11.u64 = ctx.r5.u64 + ctx.r11.u64;
loc_8266967C:
	// lhz r5,4(r10)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r3,2(r10)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lhz r4,6(r10)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r10.u32 + 6);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lhzu r6,8(r10)
	ea = 8 + ctx.r10.u32;
	ctx.r6.u64 = REX_LOAD_U16(ea);
	ctx.r10.u32 = ea;
	// std r5,-144(r1)
	REX_STORE_U64(ctx.r1.u32 + -144, ctx.r5.u64);
	// extsh r5,r4
	ctx.r5.s64 = ctx.r4.s16;
	// std r3,-136(r1)
	REX_STORE_U64(ctx.r1.u32 + -136, ctx.r3.u64);
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// std r5,-128(r1)
	REX_STORE_U64(ctx.r1.u32 + -128, ctx.r5.u64);
	// std r3,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r3.u64);
	// lfd f0,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f9,f0
	ctx.f9.f64 = double(ctx.f0.s64);
	// lfd f13,-128(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -128);
	// frsp f4,f9
	ctx.f4.f64 = double(float(ctx.f9.f64));
	// lfd f10,-136(r1)
	ctx.f10.u64 = REX_LOAD_U64(ctx.r1.u32 + -136);
	// fcfid f11,f13
	ctx.f11.f64 = double(ctx.f13.s64);
	// lfd f8,-144(r1)
	ctx.f8.u64 = REX_LOAD_U64(ctx.r1.u32 + -144);
	// fcfid f7,f10
	ctx.f7.f64 = double(ctx.f10.s64);
	// fcfid f6,f8
	ctx.f6.f64 = double(ctx.f8.s64);
	// fmuls f0,f4,f12
	ctx.f0.f64 = double(float(ctx.f4.f64 * ctx.f12.f64));
	// frsp f5,f11
	ctx.f5.f64 = double(float(ctx.f11.f64));
	// frsp f3,f7
	ctx.f3.f64 = double(float(ctx.f7.f64));
	// frsp f2,f6
	ctx.f2.f64 = double(float(ctx.f6.f64));
	// fmuls f1,f5,f12
	ctx.f1.f64 = double(float(ctx.f5.f64 * ctx.f12.f64));
	// stfs f1,12(r7)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r7.u32 + 12, temp.u32);
	// fmuls f13,f3,f12
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f12.f64));
	// stfs f13,4(r7)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r7.u32 + 4, temp.u32);
	// fmuls f11,f2,f12
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// stfs f11,8(r7)
	temp.f32 = float(ctx.f11.f64);
	REX_STORE_U32(ctx.r7.u32 + 8, temp.u32);
	// stfsu f0,16(r7)
	ea = 16 + ctx.r7.u32;
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r7.u32 = ea;
	// bdnz 0x8266967c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266967C;
loc_82669700:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bge cr6,0x82669750
	if (!ctx.cr6.lt) goto loc_82669750;
	// add r7,r11,r31
	ctx.r7.u64 = ctx.r11.u64 + ctx.r31.u64;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r6,r11
	ctx.r6.s64 = static_cast<int64_t>(-ctx.r11.u64);
	// rlwinm r7,r7,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r10,r9
	ctx.r11.u64 = ctx.r10.u64 + ctx.r9.u64;
	// add r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 + ctx.r8.u64;
	// addi r10,r11,-4
	ctx.r10.s64 = ctx.r11.s64 + -4;
	// addi r11,r9,-2
	ctx.r11.s64 = ctx.r9.s64 + -2;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
loc_8266972C:
	// lhzu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r9.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// std r8,-120(r1)
	REX_STORE_U64(ctx.r1.u32 + -120, ctx.r8.u64);
	// lfd f0,-120(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + -120);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// frsp f11,f13
	ctx.f11.f64 = double(float(ctx.f13.f64));
	// fmuls f10,f11,f12
	ctx.f10.f64 = double(float(ctx.f11.f64 * ctx.f12.f64));
	// stfsu f10,4(r10)
	ea = 4 + ctx.r10.u32;
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x8266972c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8266972C;
loc_82669750:
	// lfd f30,-112(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f30.u64 = REX_LOAD_U64(ctx.r1.u32 + -112);
	// lfd f31,-104(r1)
	ctx.f31.u64 = REX_LOAD_U64(ctx.r1.u32 + -104);
	// b 0x82739f4c
	__restgprlr_21(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826A03C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ef8
	ctx.lr = 0x826A03C8;
	__savegprlr_20(ctx, base);
	// stwu r1,-512(r1)
	ea = -512 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// li r21,0
	ctx.r21.s64 = 0;
	// li r28,1
	ctx.r28.s64 = 1;
	// mr r22,r3
	ctx.r22.u64 = ctx.r3.u64;
	// stw r21,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r21.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r28,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r28.u32);
	// bne cr6,0x826a03f4
	if (!ctx.cr6.eq) goto loc_826A03F4;
	// li r3,7
	ctx.r3.s64 = 7;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_826A03F4:
	// lwz r31,0(r22)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r11,16(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a0410
	if (ctx.cr6.eq) goto loc_826A0410;
	// li r3,13
	ctx.r3.s64 = 13;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_826A0410:
	// lwz r20,3364(r31)
	ctx.r20.u64 = REX_LOAD_U32(ctx.r31.u32 + 3364);
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r20
	ctx.r3.u64 = ctx.r20.u64;
	// mr r30,r21
	ctx.r30.u64 = ctx.r21.u64;
	// bl 0x826ba718
	ctx.lr = 0x826A0434;
	sub_826BA718(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a0554
	if (ctx.cr6.eq) goto loc_826A0554;
loc_826A0440:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x826a0498
	if (!ctx.cr6.eq) goto loc_826A0498;
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// add r29,r5,r30
	ctx.r29.u64 = ctx.r5.u64 + ctx.r30.u64;
	// cmplwi cr6,r29,256
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, 256, ctx.xer);
	// bge cr6,0x826a049c
	if (!ctx.cr6.lt) goto loc_826A049C;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// add r3,r30,r11
	ctx.r3.u64 = ctx.r30.u64 + ctx.r11.u64;
	// bl 0x8273a030
	ctx.lr = 0x826A046C;
	sub_8273A030(ctx, base);
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// lwz r3,3364(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3364);
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r30,r29
	ctx.r30.u64 = ctx.r29.u64;
	// bl 0x826ba718
	ctx.lr = 0x826A048C;
	sub_826BA718(ctx, base);
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a0440
	if (!ctx.cr6.eq) goto loc_826A0440;
loc_826A0498:
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
loc_826A049C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x826a0528
	if (ctx.cr6.eq) goto loc_826A0528;
	// lwz r11,24176(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24176);
	// add r29,r5,r30
	ctx.r29.u64 = ctx.r5.u64 + ctx.r30.u64;
	// cmpw cr6,r29,r11
	ctx.cr6.compare<int32_t>(ctx.r29.s32, ctx.r11.s32, ctx.xer);
	// ble cr6,0x826a04f0
	if (!ctx.cr6.gt) goto loc_826A04F0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a04c4
	if (ctx.cr6.eq) goto loc_826A04C4;
	// lwz r3,24180(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24180);
	// bl 0x826bedc8
	ctx.lr = 0x826A04C4;
	sub_826BEDC8(ctx, base);
loc_826A04C4:
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x826bedb8
	ctx.lr = 0x826A04D0;
	sub_826BEDB8(ctx, base);
	// stw r3,24180(r31)
	REX_STORE_U32(ctx.r31.u32 + 24180, ctx.r3.u32);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne cr6,0x826a04ec
	if (!ctx.cr6.eq) goto loc_826A04EC;
	// li r3,2
	ctx.r3.s64 = 2;
	// stw r21,24176(r31)
	REX_STORE_U32(ctx.r31.u32 + 24176, ctx.r21.u32);
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_826A04EC:
	// stw r29,24176(r31)
	REX_STORE_U32(ctx.r31.u32 + 24176, ctx.r29.u32);
loc_826A04F0:
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r3,24180(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 24180);
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// bl 0x8273a030
	ctx.lr = 0x826A0500;
	sub_8273A030(ctx, base);
	// lwz r11,24180(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24180);
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// add r3,r11,r30
	ctx.r3.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8273a030
	ctx.lr = 0x826A0514;
	sub_8273A030(ctx, base);
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// lwz r10,24180(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 24180);
	// stw r10,116(r1)
	REX_STORE_U32(ctx.r1.u32 + 116, ctx.r10.u32);
loc_826A0528:
	// lwz r11,120(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a0554
	if (ctx.cr6.eq) goto loc_826A0554;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x826a0548
	if (ctx.cr6.eq) goto loc_826A0548;
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x826a0554
	if (!ctx.cr6.eq) goto loc_826A0554;
loc_826A0548:
	// li r3,11
	ctx.r3.s64 = 11;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_826A0554:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// stw r21,22320(r31)
	REX_STORE_U32(ctx.r31.u32 + 22320, ctx.r21.u32);
	// stw r21,22336(r31)
	REX_STORE_U32(ctx.r31.u32 + 22336, ctx.r21.u32);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// stw r21,22324(r31)
	REX_STORE_U32(ctx.r31.u32 + 22324, ctx.r21.u32);
	// stw r21,22328(r31)
	REX_STORE_U32(ctx.r31.u32 + 22328, ctx.r21.u32);
	// bne cr6,0x826a0618
	if (!ctx.cr6.eq) goto loc_826A0618;
	// lwz r11,116(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// lbz r10,0(r11)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// rlwinm r9,r10,0,30,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2;
	// mr r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826a0594
	if (ctx.cr6.eq) goto loc_826A0594;
	// stw r28,22336(r31)
	REX_STORE_U32(ctx.r31.u32 + 22336, ctx.r28.u32);
	// stw r21,14804(r31)
	REX_STORE_U32(ctx.r31.u32 + 14804, ctx.r21.u32);
	// b 0x826a059c
	goto loc_826A059C;
loc_826A0594:
	// stw r21,22336(r31)
	REX_STORE_U32(ctx.r31.u32 + 22336, ctx.r21.u32);
	// stw r28,14804(r31)
	REX_STORE_U32(ctx.r31.u32 + 14804, ctx.r28.u32);
loc_826A059C:
	// rlwinm r10,r11,30,31,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 30) & 0x1;
	// rlwinm r9,r11,0,26,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20;
	// stw r10,22320(r31)
	REX_STORE_U32(ctx.r31.u32 + 22320, ctx.r10.u32);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x826a05b8
	if (ctx.cr6.eq) goto loc_826A05B8;
	// stw r28,22332(r31)
	REX_STORE_U32(ctx.r31.u32 + 22332, ctx.r28.u32);
	// b 0x826a05bc
	goto loc_826A05BC;
loc_826A05B8:
	// stw r21,22332(r31)
	REX_STORE_U32(ctx.r31.u32 + 22332, ctx.r21.u32);
loc_826A05BC:
	// lwz r11,112(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// addic. r5,r11,-1
	ctx.xer.ca = ctx.r11.u32 > 0;
	ctx.r5.s64 = ctx.r11.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// bne 0x826a05fc
	if (!ctx.cr0.eq) goto loc_826A05FC;
	// addi r8,r1,120
	ctx.r8.s64 = ctx.r1.s64 + 120;
	// lwz r3,3364(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 3364);
	// addi r7,r1,112
	ctx.r7.s64 = ctx.r1.s64 + 112;
	// li r6,4
	ctx.r6.s64 = 4;
	// addi r5,r1,116
	ctx.r5.s64 = ctx.r1.s64 + 116;
	// li r4,0
	ctx.r4.s64 = 0;
	// bl 0x826ba718
	ctx.lr = 0x826A05E8;
	sub_826BA718(ctx, base);
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// addi r11,r11,-7
	ctx.r11.s64 = ctx.r11.s64 + -7;
	// cntlzw r10,r11
	ctx.r10.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r7,r10,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// b 0x826a061c
	goto loc_826A061C;
loc_826A05FC:
	// lwz r11,15504(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15504);
	// lwz r10,116(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r9,r11,-7
	ctx.r9.s64 = ctx.r11.s64 + -7;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// cntlzw r8,r9
	ctx.r8.u64 = ctx.r9.u32 == 0 ? 32 : __builtin_clz(ctx.r9.u32);
	// rlwinm r7,r8,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x1;
	// b 0x826a0624
	goto loc_826A0624;
loc_826A0618:
	// li r7,0
	ctx.r7.s64 = 0;
loc_826A061C:
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_826A0624:
	// lwz r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r3,80(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// bl 0x826c88a8
	ctx.lr = 0x826A0630;
	sub_826C88A8(ctx, base);
	// lwz r11,80(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 80);
	// lwz r10,120(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// stw r10,24(r11)
	REX_STORE_U32(ctx.r11.u32 + 24, ctx.r10.u32);
	// lwz r3,0(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8269e720
	ctx.lr = 0x826A064C;
	sub_8269E720(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a0814
	if (!ctx.cr6.eq) goto loc_826A0814;
	// lwz r3,0(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826a080c
	if (ctx.cr6.eq) goto loc_826A080C;
	// lwz r11,15332(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 15332);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x826a067c
	if (!ctx.cr6.eq) goto loc_826A067C;
	// lwz r11,15400(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 15400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a080c
	if (ctx.cr6.eq) goto loc_826A080C;
loc_826A067C:
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// mr r25,r21
	ctx.r25.u64 = ctx.r21.u64;
	// beq cr6,0x826a0690
	if (ctx.cr6.eq) goto loc_826A0690;
	// lwz r25,156(r3)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r3.u32 + 156);
	// bne cr6,0x826a0698
	if (!ctx.cr6.eq) goto loc_826A0698;
loc_826A0690:
	// mr r26,r21
	ctx.r26.u64 = ctx.r21.u64;
	// b 0x826a069c
	goto loc_826A069C;
loc_826A0698:
	// lwz r26,160(r3)
	ctx.r26.u64 = REX_LOAD_U32(ctx.r3.u32 + 160);
loc_826A069C:
	// lwz r24,88(r3)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r3.u32 + 88);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// lwz r23,92(r3)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r3.u32 + 92);
	// lwz r29,20632(r3)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r3.u32 + 20632);
	// lwz r28,20636(r3)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r3.u32 + 20636);
	// lwz r27,15268(r3)
	ctx.r27.u64 = REX_LOAD_U32(ctx.r3.u32 + 15268);
	// beq cr6,0x826a06d8
	if (ctx.cr6.eq) goto loc_826A06D8;
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a06cc
	if (ctx.cr6.eq) goto loc_826A06CC;
	// li r30,13
	ctx.r30.s64 = 13;
	// b 0x826a06dc
	goto loc_826A06DC;
loc_826A06CC:
	// lwz r30,3680(r3)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r3.u32 + 3680);
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bgt cr6,0x826a06dc
	if (ctx.cr6.gt) goto loc_826A06DC;
loc_826A06D8:
	// li r30,30
	ctx.r30.s64 = 30;
loc_826A06DC:
	// lwz r11,15400(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 15400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826a073c
	if (ctx.cr6.eq) goto loc_826A073C;
	// bl 0x826a0328
	ctx.lr = 0x826A06EC;
	sub_826A0328(ctx, base);
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r5,22358
	ctx.r5.s64 = 1465253888;
	// lfs f2,2524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f2.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// stw r21,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r21.u32);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// ori r5,r5,20530
	ctx.r5.u64 = ctx.r5.u64 | 20530;
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x826a0128
	ctx.lr = 0x826A0738;
	sub_826A0128(ctx, base);
	// b 0x826a078c
	goto loc_826A078C;
loc_826A073C:
	// bl 0x826a0328
	ctx.lr = 0x826A0740;
	sub_826A0328(ctx, base);
	// stw r29,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// extsw r11,r30
	ctx.r11.s64 = ctx.r30.s32;
	// stw r28,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r28.u32);
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// stw r27,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r27.u32);
	// std r11,128(r1)
	REX_STORE_U64(ctx.r1.u32 + 128, ctx.r11.u64);
	// lfd f0,128(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f0.u64 = REX_LOAD_U64(ctx.r1.u32 + 128);
	// fcfid f13,f0
	ctx.f13.f64 = double(ctx.f0.s64);
	// lis r5,22349
	ctx.r5.s64 = 1464664064;
	// lfs f2,2524(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 2524);
	ctx.f2.f64 = double(temp.f32);
	// li r10,0
	ctx.r10.s64 = 0;
	// mr r9,r26
	ctx.r9.u64 = ctx.r26.u64;
	// stw r21,0(r22)
	REX_STORE_U32(ctx.r22.u32 + 0, ctx.r21.u32);
	// mr r8,r25
	ctx.r8.u64 = ctx.r25.u64;
	// frsp f1,f13
	ctx.f1.f64 = double(float(ctx.f13.f64));
	// ori r5,r5,22067
	ctx.r5.u64 = ctx.r5.u64 | 22067;
	// mr r4,r20
	ctx.r4.u64 = ctx.r20.u64;
	// mr r3,r22
	ctx.r3.u64 = ctx.r22.u64;
	// bl 0x826a0128
	ctx.lr = 0x826A078C;
	sub_826A0128(ctx, base);
loc_826A078C:
	// lwz r11,0(r22)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x826a0818
	if (!ctx.cr6.eq) goto loc_826A0818;
	// stw r24,15340(r11)
	REX_STORE_U32(ctx.r11.u32 + 15340, ctx.r24.u32);
	// lwz r10,0(r22)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// stw r23,15344(r10)
	REX_STORE_U32(ctx.r10.u32 + 15344, ctx.r23.u32);
	// lwz r9,15504(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 15504);
	// cmpwi cr6,r9,7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 7, ctx.xer);
	// lwz r6,120(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 120);
	// bne cr6,0x826a07dc
	if (!ctx.cr6.eq) goto loc_826A07DC;
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r9,116(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// addi r5,r10,-1
	ctx.r5.s64 = ctx.r10.s64 + -1;
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// stw r5,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// lwz r10,15504(r11)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + 15504);
	// addi r8,r10,-7
	ctx.r8.s64 = ctx.r10.s64 + -7;
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r7,r7,27,31,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// b 0x826a07e8
	goto loc_826A07E8;
loc_826A07DC:
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
loc_826A07E8:
	// lwz r3,80(r11)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r11.u32 + 80);
	// bl 0x826c88a8
	ctx.lr = 0x826A07F0;
	sub_826C88A8(ctx, base);
	// lwz r5,112(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r3,0(r22)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r22.u32 + 0);
	// lwz r4,116(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 116);
	// bl 0x8269e720
	ctx.lr = 0x826A0800;
	sub_8269E720(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
loc_826A080C:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8269f778
	ctx.lr = 0x826A0814;
	sub_8269F778(ctx, base);
loc_826A0814:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
loc_826A0818:
	// addi r1,r1,512
	ctx.r1.s64 = ctx.r1.s64 + 512;
	// b 0x82739f48
	__restgprlr_20(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_826DBB30) {
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
	// lwz r3,15688(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 15688);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// stw r11,3384(r31)
	REX_STORE_U32(ctx.r31.u32 + 3384, ctx.r11.u32);
	// beq cr6,0x826dbb68
	if (ctx.cr6.eq) goto loc_826DBB68;
	// bl 0x826bedc8
	ctx.lr = 0x826DBB64;
	sub_826BEDC8(ctx, base);
	// stw r30,15688(r31)
	REX_STORE_U32(ctx.r31.u32 + 15688, ctx.r30.u32);
loc_826DBB68:
	// lwz r3,15696(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15696);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbb7c
	if (ctx.cr6.eq) goto loc_826DBB7C;
	// bl 0x826bedc8
	ctx.lr = 0x826DBB78;
	sub_826BEDC8(ctx, base);
	// stw r30,15696(r31)
	REX_STORE_U32(ctx.r31.u32 + 15696, ctx.r30.u32);
loc_826DBB7C:
	// lwz r3,15692(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15692);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbb90
	if (ctx.cr6.eq) goto loc_826DBB90;
	// bl 0x826bedc8
	ctx.lr = 0x826DBB8C;
	sub_826BEDC8(ctx, base);
	// stw r30,15692(r31)
	REX_STORE_U32(ctx.r31.u32 + 15692, ctx.r30.u32);
loc_826DBB90:
	// lwz r3,15700(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15700);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbba4
	if (ctx.cr6.eq) goto loc_826DBBA4;
	// bl 0x826bedc8
	ctx.lr = 0x826DBBA0;
	sub_826BEDC8(ctx, base);
	// stw r30,15700(r31)
	REX_STORE_U32(ctx.r31.u32 + 15700, ctx.r30.u32);
loc_826DBBA4:
	// lwz r11,24896(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 24896);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826dbbf4
	if (ctx.cr6.eq) goto loc_826DBBF4;
	// lis r10,0
	ctx.r10.s64 = 0;
	// ori r9,r10,32896
	ctx.r9.u64 = ctx.r10.u64 | 32896;
	// lwzx r8,r11,r9
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r9.u32);
	// cmplw cr6,r31,r8
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x826dbbf4
	if (ctx.cr6.eq) goto loc_826DBBF4;
	// stw r30,15704(r31)
	REX_STORE_U32(ctx.r31.u32 + 15704, ctx.r30.u32);
	// stw r30,15712(r31)
	REX_STORE_U32(ctx.r31.u32 + 15712, ctx.r30.u32);
	// stw r30,15720(r31)
	REX_STORE_U32(ctx.r31.u32 + 15720, ctx.r30.u32);
	// stw r30,15728(r31)
	REX_STORE_U32(ctx.r31.u32 + 15728, ctx.r30.u32);
	// stw r30,15736(r31)
	REX_STORE_U32(ctx.r31.u32 + 15736, ctx.r30.u32);
	// stw r30,15744(r31)
	REX_STORE_U32(ctx.r31.u32 + 15744, ctx.r30.u32);
	// stw r30,15752(r31)
	REX_STORE_U32(ctx.r31.u32 + 15752, ctx.r30.u32);
	// stw r30,15760(r31)
	REX_STORE_U32(ctx.r31.u32 + 15760, ctx.r30.u32);
	// stw r30,15768(r31)
	REX_STORE_U32(ctx.r31.u32 + 15768, ctx.r30.u32);
	// stw r30,15776(r31)
	REX_STORE_U32(ctx.r31.u32 + 15776, ctx.r30.u32);
	// stw r30,15784(r31)
	REX_STORE_U32(ctx.r31.u32 + 15784, ctx.r30.u32);
	// b 0x826dbce0
	goto loc_826DBCE0;
loc_826DBBF4:
	// lwz r3,15704(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15704);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc08
	if (ctx.cr6.eq) goto loc_826DBC08;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC04;
	sub_826BEDC8(ctx, base);
	// stw r30,15704(r31)
	REX_STORE_U32(ctx.r31.u32 + 15704, ctx.r30.u32);
loc_826DBC08:
	// lwz r3,15712(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15712);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc1c
	if (ctx.cr6.eq) goto loc_826DBC1C;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC18;
	sub_826BEDC8(ctx, base);
	// stw r30,15712(r31)
	REX_STORE_U32(ctx.r31.u32 + 15712, ctx.r30.u32);
loc_826DBC1C:
	// lwz r3,15720(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15720);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc30
	if (ctx.cr6.eq) goto loc_826DBC30;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC2C;
	sub_826BEDC8(ctx, base);
	// stw r30,15720(r31)
	REX_STORE_U32(ctx.r31.u32 + 15720, ctx.r30.u32);
loc_826DBC30:
	// lwz r3,15728(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15728);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc44
	if (ctx.cr6.eq) goto loc_826DBC44;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC40;
	sub_826BEDC8(ctx, base);
	// stw r30,15728(r31)
	REX_STORE_U32(ctx.r31.u32 + 15728, ctx.r30.u32);
loc_826DBC44:
	// lwz r3,15736(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15736);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc58
	if (ctx.cr6.eq) goto loc_826DBC58;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC54;
	sub_826BEDC8(ctx, base);
	// stw r30,15736(r31)
	REX_STORE_U32(ctx.r31.u32 + 15736, ctx.r30.u32);
loc_826DBC58:
	// lwz r3,15744(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15744);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc6c
	if (ctx.cr6.eq) goto loc_826DBC6C;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC68;
	sub_826BEDC8(ctx, base);
	// stw r30,15744(r31)
	REX_STORE_U32(ctx.r31.u32 + 15744, ctx.r30.u32);
loc_826DBC6C:
	// lwz r3,15752(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15752);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc80
	if (ctx.cr6.eq) goto loc_826DBC80;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC7C;
	sub_826BEDC8(ctx, base);
	// stw r30,15752(r31)
	REX_STORE_U32(ctx.r31.u32 + 15752, ctx.r30.u32);
loc_826DBC80:
	// lwz r3,15760(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15760);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbc94
	if (ctx.cr6.eq) goto loc_826DBC94;
	// bl 0x826bedc8
	ctx.lr = 0x826DBC90;
	sub_826BEDC8(ctx, base);
	// stw r30,15760(r31)
	REX_STORE_U32(ctx.r31.u32 + 15760, ctx.r30.u32);
loc_826DBC94:
	// lwz r3,15768(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15768);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbca8
	if (ctx.cr6.eq) goto loc_826DBCA8;
	// bl 0x826bedc8
	ctx.lr = 0x826DBCA4;
	sub_826BEDC8(ctx, base);
	// stw r30,15768(r31)
	REX_STORE_U32(ctx.r31.u32 + 15768, ctx.r30.u32);
loc_826DBCA8:
	// lwz r3,15776(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15776);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbcbc
	if (ctx.cr6.eq) goto loc_826DBCBC;
	// bl 0x826bedc8
	ctx.lr = 0x826DBCB8;
	sub_826BEDC8(ctx, base);
	// stw r30,15776(r31)
	REX_STORE_U32(ctx.r31.u32 + 15776, ctx.r30.u32);
loc_826DBCBC:
	// lwz r3,15784(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15784);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbcd0
	if (ctx.cr6.eq) goto loc_826DBCD0;
	// bl 0x826bedc8
	ctx.lr = 0x826DBCCC;
	sub_826BEDC8(ctx, base);
	// stw r30,15784(r31)
	REX_STORE_U32(ctx.r31.u32 + 15784, ctx.r30.u32);
loc_826DBCD0:
	// lwz r3,15792(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 15792);
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x826dbce4
	if (ctx.cr6.eq) goto loc_826DBCE4;
	// bl 0x826bedc8
	ctx.lr = 0x826DBCE0;
	sub_826BEDC8(ctx, base);
loc_826DBCE0:
	// stw r30,15792(r31)
	REX_STORE_U32(ctx.r31.u32 + 15792, ctx.r30.u32);
loc_826DBCE4:
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

DEFINE_REX_FUNC(sub_826E8950) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x826E8958;
	__savegprlr_14(ctx, base);
	// rlwinm r30,r5,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r10,76(r1)
	REX_STORE_U32(ctx.r1.u32 + 76, ctx.r10.u32);
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r8,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r8.u32);
	// add r29,r30,r4
	ctx.r29.u64 = ctx.r30.u64 + ctx.r4.u64;
	// stw r9,68(r1)
	REX_STORE_U32(ctx.r1.u32 + 68, ctx.r9.u32);
	// add r24,r6,r7
	ctx.r24.u64 = ctx.r6.u64 + ctx.r7.u64;
	// vspltish v0,4
	simde_mm_store_si128((simde__m128i*)ctx.v0.s16, simde_mm_set1_epi16(short(0x4)));
	// lis r10,-32253
	ctx.r10.s64 = -2113732608;
	// vspltish v13,3
	simde_mm_store_si128((simde__m128i*)ctx.v13.s16, simde_mm_set1_epi16(short(0x3)));
	// mr r8,r9
	ctx.r8.u64 = ctx.r9.u64;
	// lwz r25,84(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// add r9,r5,r11
	ctx.r9.u64 = ctx.r5.u64 + ctx.r11.u64;
	// add r28,r30,r29
	ctx.r28.u64 = ctx.r30.u64 + ctx.r29.u64;
	// add r23,r24,r7
	ctx.r23.u64 = ctx.r24.u64 + ctx.r7.u64;
	// vmrghh v5,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// addi r5,r10,17264
	ctx.r5.s64 = ctx.r10.s64 + 17264;
	// vmrghh v4,v0,v13
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_unpackhi_epi16(simde_mm_load_si128((simde__m128i*)ctx.v13.u16), simde_mm_load_si128((simde__m128i*)ctx.v0.u16)));
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,-16
	ctx.r10.s64 = -16;
	// add r27,r30,r28
	ctx.r27.u64 = ctx.r30.u64 + ctx.r28.u64;
	// add r22,r23,r7
	ctx.r22.u64 = ctx.r23.u64 + ctx.r7.u64;
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lvx128 v0,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r31,r7,r6
	ctx.r31.u64 = ctx.r6.u64 - ctx.r7.u64;
	// add r26,r30,r27
	ctx.r26.u64 = ctx.r30.u64 + ctx.r27.u64;
	// lvx128 v7,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r21,r22,r7
	ctx.r21.u64 = ctx.r22.u64 + ctx.r7.u64;
	// add r11,r30,r3
	ctx.r11.u64 = ctx.r30.u64 + ctx.r3.u64;
	// add r30,r30,r26
	ctx.r30.u64 = ctx.r30.u64 + ctx.r26.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// li r20,1
	ctx.r20.s64 = 1;
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// subf r18,r7,r31
	ctx.r18.u64 = ctx.r31.u64 - ctx.r7.u64;
	// add r19,r21,r7
	ctx.r19.u64 = ctx.r21.u64 + ctx.r7.u64;
	// ble cr6,0x826e8d64
	if (!ctx.cr6.gt) goto loc_826E8D64;
	// subf r9,r11,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r11.u64;
	// mtctr r25
	ctx.ctr.u64 = ctx.r25.u64;
	// subf r16,r11,r28
	ctx.r16.u64 = ctx.r28.u64 - ctx.r11.u64;
	// subf r15,r11,r27
	ctx.r15.u64 = ctx.r27.u64 - ctx.r11.u64;
	// stw r9,-172(r1)
	REX_STORE_U32(ctx.r1.u32 + -172, ctx.r9.u32);
	// subf r14,r11,r26
	ctx.r14.u64 = ctx.r26.u64 - ctx.r11.u64;
	// subf r10,r11,r30
	ctx.r10.u64 = ctx.r30.u64 - ctx.r11.u64;
	// mr r7,r11
	ctx.r7.u64 = ctx.r11.u64;
	// subf r25,r11,r4
	ctx.r25.u64 = ctx.r4.u64 - ctx.r11.u64;
	// subf r29,r11,r29
	ctx.r29.u64 = ctx.r29.u64 - ctx.r11.u64;
	// subf r3,r31,r6
	ctx.r3.u64 = ctx.r6.u64 - ctx.r31.u64;
	// subf r30,r31,r24
	ctx.r30.u64 = ctx.r24.u64 - ctx.r31.u64;
	// subf r28,r31,r23
	ctx.r28.u64 = ctx.r23.u64 - ctx.r31.u64;
	// subf r27,r31,r22
	ctx.r27.u64 = ctx.r22.u64 - ctx.r31.u64;
	// subf r26,r31,r21
	ctx.r26.u64 = ctx.r21.u64 - ctx.r31.u64;
	// subf r17,r31,r19
	ctx.r17.u64 = ctx.r19.u64 - ctx.r31.u64;
loc_826E8A28:
	// lwz r11,60(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 60);
	// li r4,0
	ctx.r4.s64 = 0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x826e8a78
	if (ctx.cr6.eq) goto loc_826E8A78;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// lwz r8,76(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 76);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// std r10,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.r10.u64);
	// stw r11,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r11.u32);
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r8,-176(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// subf r4,r8,r4
	ctx.r4.u64 = ctx.r4.u64 - ctx.r8.u64;
	// lwz r10,60(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 60);
	// cntlzw r4,r4
	ctx.r4.u64 = ctx.r4.u32 == 0 ? 32 : __builtin_clz(ctx.r4.u32);
	// lwz r8,68(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 68);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// ld r10,-168(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// rlwinm r4,r4,27,31,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// stw r11,60(r1)
	REX_STORE_U32(ctx.r1.u32 + 60, ctx.r11.u32);
loc_826E8A78:
	// li r11,0
	ctx.r11.s64 = 0;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x826e8ac8
	if (ctx.cr6.eq) goto loc_826E8AC8;
	// lhz r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r8.u32 + 0);
	// std r10,-168(r1)
	REX_STORE_U64(ctx.r1.u32 + -168, ctx.r10.u64);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r9,76(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 76);
	// lwz r10,92(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// stw r11,-176(r1)
	REX_STORE_U32(ctx.r1.u32 + -176, ctx.r11.u32);
	// rlwinm r11,r9,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,-172(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -172);
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// stw r8,68(r1)
	REX_STORE_U32(ctx.r1.u32 + 68, ctx.r8.u32);
	// std r9,-160(r1)
	REX_STORE_U64(ctx.r1.u32 + -160, ctx.r9.u64);
	// lwz r9,-176(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + -176);
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// cntlzw r11,r10
	ctx.r11.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// ld r10,-168(r1)
	ctx.r10.u64 = REX_LOAD_U64(ctx.r1.u32 + -168);
	// ld r9,-160(r1)
	ctx.r9.u64 = REX_LOAD_U64(ctx.r1.u32 + -160);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
loc_826E8AC8:
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// beq cr6,0x826e8c68
	if (ctx.cr6.eq) goto loc_826E8C68;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826e8c20
	if (ctx.cr6.eq) goto loc_826E8C20;
	// lvx128 v12,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v63,0
	simde_mm_store_si128((simde__m128i*)ctx.v63.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r7,r25
	ea = (ctx.r7.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v3,v12,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v12.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v3.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vsubshs v6,v12,v11
	simde_mm_store_si128((simde__m128i*)ctx.v6.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// lvx128 v10,r7,r9
	ea = (ctx.r7.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsubshs v2,v11,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// lvx128 v9,r7,r29
	ea = (ctx.r7.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vslh v1,v11,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v11.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v1.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// vsubshs v12,v10,v9
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v10.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// vsubshs v8,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_subs_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vslh v31,v10,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v10.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v31.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vslh v30,v9,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v9.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v30.u8, rex::ppc::simde_mm_sllv_epi16(a, shift));
	}
	// vaddshs v29,v3,v2
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// vaddshs v28,v1,v6
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// vaddshs v27,v31,v8
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v26,v30,v12
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v25,v29,v8
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vaddshs v24,v28,v12
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vaddshs v23,v27,v4
	simde_mm_store_si128((simde__m128i*)ctx.v23.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vaddshs v22,v26,v5
	simde_mm_store_si128((simde__m128i*)ctx.v22.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v21,v25,v5
	simde_mm_store_si128((simde__m128i*)ctx.v21.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// vaddshs v20,v24,v4
	simde_mm_store_si128((simde__m128i*)ctx.v20.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// vsrah v19,v23,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v23.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v19.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v18,v22,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v22.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v18.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v17,v21,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v21.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v17.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vsrah v16,v20,v13
	{
		simde__m128i a = simde_mm_load_si128((simde__m128i*)ctx.v20.u8);
		simde__m128i b = simde_mm_load_si128((simde__m128i*)ctx.v13.u8);
		simde__m128i shift = simde_mm_and_si128(b, simde_mm_set1_epi16(0xF));
		simde_mm_store_si128((simde__m128i*)ctx.v16.u8, rex::ppc::simde_mm_srav_epi16(a, shift));
	}
	// vaddshs v15,v19,v0
	simde_mm_store_si128((simde__m128i*)ctx.v15.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v19.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v14,v18,v0
	simde_mm_store_si128((simde__m128i*)ctx.v14.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v18.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v12,v17,v0
	simde_mm_store_si128((simde__m128i*)ctx.v12.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v17.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v11,v16,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v16.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vpkshus128 v62,v15,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v15.s16)));
	// vpkshus128 v59,v14,v63
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v14.s16)));
	// vpkshus128 v61,v12,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v12.s16)));
	// vpkshus128 v60,v11,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v11.s16)));
	// beq cr6,0x826e8b94
	if (ctx.cr6.eq) goto loc_826E8B94;
	// add r11,r5,r31
	ctx.r11.u64 = ctx.r5.u64 + ctx.r31.u64;
	// lvx128 v58,r5,r31
	ea = (ctx.r5.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r4,r31,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r31.u64;
	// vperm128 v61,v61,v58,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v57,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v57.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v56,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v56.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v60,v60,v57,v7
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v57.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v55,r11,r30
	ea = (ctx.r11.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v55.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v62,v62,v56,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v56.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v59,v59,v55,v7
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v55.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
loc_826E8B94:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// stvlx128 v62,r18,r5
	ea = ctx.r18.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvlx128 v61,r31,r5
	ea = ctx.r31.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v61.u8[15 - i]);
	// stvlx128 v60,r6,r5
	ea = ctx.r6.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stvlx128 v59,r24,r5
	ea = ctx.r24.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v59.u8[15 - i]);
	// bne cr6,0x826e8d54
	if (!ctx.cr6.eq) goto loc_826E8D54;
	// lvx128 v12,r7,r16
	ea = (ctx.r7.u32 + ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lvx128 v11,r7,r15
	ea = (ctx.r7.u32 + ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v10,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v9,r7,r14
	ea = (ctx.r7.u32 + ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v8,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v6,r7,r10
	ea = (ctx.r7.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v3,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v2,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v2.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vpkshus128 v62,v10,v63
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vpkshus128 v61,v8,v63
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// vpkshus128 v60,v3,v63
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vpkshus128 v63,v2,v63
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v63.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// beq cr6,0x826e8c0c
	if (ctx.cr6.eq) goto loc_826E8C0C;
	// add r11,r5,r31
	ctx.r11.u64 = ctx.r5.u64 + ctx.r31.u64;
	// lvx128 v54,r11,r28
	ea = (ctx.r11.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v54.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v53,r11,r27
	ea = (ctx.r11.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v53.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v62,v62,v54,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v54.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v52,r11,r26
	ea = (ctx.r11.u32 + ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v52.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v61,v61,v53,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v53.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v51,r11,r17
	ea = (ctx.r11.u32 + ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v51.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v60,v60,v52,v7
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v52.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v63,v63,v51,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v51.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
loc_826E8C0C:
	// stvlx128 v62,r23,r5
	ea = ctx.r23.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvlx128 v61,r22,r5
	ea = ctx.r22.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v61.u8[15 - i]);
	// stvlx128 v60,r21,r5
	ea = ctx.r21.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// stvlx128 v63,r19,r5
	ea = ctx.r19.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// b 0x826e8d54
	goto loc_826E8D54;
loc_826E8C20:
	// lvx128 v12,r7,r9
	ea = (ctx.r7.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v50,0
	simde_mm_store_si128((simde__m128i*)ctx.v50.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v11,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v10,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v9,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// vpkshus128 v63,v10,v50
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v50.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vpkshus128 v62,v9,v50
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v50.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// beq cr6,0x826e8c5c
	if (ctx.cr6.eq) goto loc_826E8C5C;
	// add r11,r5,r31
	ctx.r11.u64 = ctx.r5.u64 + ctx.r31.u64;
	// lvx128 v49,r5,r31
	ea = (ctx.r5.u32 + ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v49.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// subf r4,r31,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r31.u64;
	// vperm128 v62,v62,v49,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v49.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v48,r11,r4
	ea = (ctx.r11.u32 + ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v48.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v63,v63,v48,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v48.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
loc_826E8C5C:
	// stvlx128 v63,r18,r5
	ea = ctx.r18.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvlx128 v62,r31,r5
	ea = ctx.r31.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// b 0x826e8d54
	goto loc_826E8D54;
loc_826E8C68:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826e8d54
	if (ctx.cr6.eq) goto loc_826E8D54;
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// lvx128 v12,r7,r25
	ea = (ctx.r7.u32 + ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v11,r7,r29
	ea = (ctx.r7.u32 + ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v10,v12,v0
	simde_mm_store_si128((simde__m128i*)ctx.v10.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v12.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x826e8cc0
	if (ctx.cr6.eq) goto loc_826E8CC0;
	// vspltisw128 v47,0
	simde_mm_store_si128((simde__m128i*)ctx.v47.u32, simde_mm_set1_epi32(int(0x0)));
	// vaddshs v9,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v9.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// vpkshus128 v63,v10,v47
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v47.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vpkshus128 v62,v9,v47
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v47.s16), simde_mm_load_si128((simde__m128i*)ctx.v9.s16)));
	// beq cr6,0x826e8cb4
	if (ctx.cr6.eq) goto loc_826E8CB4;
	// add r11,r5,r31
	ctx.r11.u64 = ctx.r5.u64 + ctx.r31.u64;
	// lvx128 v46,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v46.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v45,r11,r30
	ea = (ctx.r11.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v45.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v63,v63,v46,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v46.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v62,v62,v45,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v45.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
loc_826E8CB4:
	// stvlx128 v63,r6,r5
	ea = ctx.r6.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvlx128 v62,r24,r5
	ea = ctx.r24.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// b 0x826e8d54
	goto loc_826E8D54;
loc_826E8CC0:
	// lvx128 v9,r7,r16
	ea = (ctx.r7.u32 + ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vspltisw128 v44,0
	simde_mm_store_si128((simde__m128i*)ctx.v44.u32, simde_mm_set1_epi32(int(0x0)));
	// lvx128 v6,r7,r15
	ea = (ctx.r7.u32 + ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v8,v11,v0
	simde_mm_store_si128((simde__m128i*)ctx.v8.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v11.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v2,r7,r14
	ea = (ctx.r7.u32 + ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v3,v9,v0
	simde_mm_store_si128((simde__m128i*)ctx.v3.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v9.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// lvx128 v31,r7,r10
	ea = (ctx.r7.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v1,v6,v0
	simde_mm_store_si128((simde__m128i*)ctx.v1.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vaddshs v30,v2,v0
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vpkshus128 v63,v10,v44
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v10.s16)));
	// vaddshs v29,v31,v0
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v0.s16)));
	// vpkshus128 v62,v8,v44
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// vpkshus128 v61,v3,v44
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// vpkshus128 v60,v1,v44
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// vpkshus128 v59,v30,v44
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// vpkshus128 v58,v29,v44
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v44.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// beq cr6,0x826e8d3c
	if (ctx.cr6.eq) goto loc_826E8D3C;
	// add r11,r5,r31
	ctx.r11.u64 = ctx.r5.u64 + ctx.r31.u64;
	// lvx128 v43,r11,r3
	ea = (ctx.r11.u32 + ctx.r3.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v43.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v42,r11,r30
	ea = (ctx.r11.u32 + ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v42.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v63,v63,v43,v7
	simde_mm_store_si128((simde__m128i*)ctx.v63.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v63.u8), simde_mm_load_si128((simde__m128i*)ctx.v43.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v41,r11,r28
	ea = (ctx.r11.u32 + ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v41.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v62,v62,v42,v7
	simde_mm_store_si128((simde__m128i*)ctx.v62.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v62.u8), simde_mm_load_si128((simde__m128i*)ctx.v42.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v40,r11,r27
	ea = (ctx.r11.u32 + ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v40.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v61,v61,v41,v7
	simde_mm_store_si128((simde__m128i*)ctx.v61.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v61.u8), simde_mm_load_si128((simde__m128i*)ctx.v41.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v39,r11,r26
	ea = (ctx.r11.u32 + ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v39.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v60,v60,v40,v7
	simde_mm_store_si128((simde__m128i*)ctx.v60.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v60.u8), simde_mm_load_si128((simde__m128i*)ctx.v40.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// lvx128 v38,r11,r17
	ea = (ctx.r11.u32 + ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v38.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vperm128 v59,v59,v39,v7
	simde_mm_store_si128((simde__m128i*)ctx.v59.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v59.u8), simde_mm_load_si128((simde__m128i*)ctx.v39.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
	// vperm128 v58,v58,v38,v7
	simde_mm_store_si128((simde__m128i*)ctx.v58.u8, rex::ppc::simde_mm_perm_epi8_(simde_mm_load_si128((simde__m128i*)ctx.v58.u8), simde_mm_load_si128((simde__m128i*)ctx.v38.u8), simde_mm_load_si128((simde__m128i*)ctx.v7.u8)));
loc_826E8D3C:
	// stvlx128 v63,r6,r5
	ea = ctx.r6.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v63.u8[15 - i]);
	// stvlx128 v62,r24,r5
	ea = ctx.r24.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v62.u8[15 - i]);
	// stvlx128 v61,r23,r5
	ea = ctx.r23.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v61.u8[15 - i]);
	// stvlx128 v60,r22,r5
	ea = ctx.r22.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v60.u8[15 - i]);
	// stvlx128 v59,r21,r5
	ea = ctx.r21.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v59.u8[15 - i]);
	// stvlx128 v58,r19,r5
	ea = ctx.r19.u32 + ctx.r5.u32;
	for (size_t i = 0; i < (16 - (ea & 0xF)); i++)
		REX_STORE_U8(ea + i, ctx.v58.u8[15 - i]);
loc_826E8D54:
	// xori r20,r20,1
	ctx.r20.u64 = ctx.r20.u64 ^ 1;
	// addi r7,r7,16
	ctx.r7.s64 = ctx.r7.s64 + 16;
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// bdnz 0x826e8a28
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_826E8A28;
loc_826E8D64:
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8272AD98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x8272ADA0;
	__savegprlr_23(ctx, base);
	// lwz r11,14624(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 14624);
	// subf r27,r7,r8
	ctx.r27.u64 = ctx.r8.u64 - ctx.r7.u64;
	// lwz r10,14480(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 14480);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8272ade0
	if (ctx.cr6.eq) goto loc_8272ADE0;
	// rotlwi r8,r11,0
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lwz r31,14628(r9)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r9.u32 + 14628);
	// srawi r11,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 2;
	// lwz r30,14632(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 14632);
	// mullw r29,r8,r7
	ctx.r29.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addze r11,r11
	temp.s64 = ctx.r11.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r11.u32;
	ctx.r11.s64 = temp.s64;
	// mullw r28,r31,r7
	ctx.r28.s64 = int64_t(ctx.r31.s32) * int64_t(ctx.r7.s32);
	// subf r26,r10,r8
	ctx.r26.u64 = ctx.r8.u64 - ctx.r10.u64;
	// subf r25,r11,r31
	ctx.r25.u64 = ctx.r31.u64 - ctx.r11.u64;
	// subf r24,r11,r30
	ctx.r24.u64 = ctx.r30.u64 - ctx.r11.u64;
	// b 0x8272adfc
	goto loc_8272ADFC;
loc_8272ADE0:
	// lwz r11,14588(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 14588);
	// mullw r29,r11,r7
	ctx.r29.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r7.s32);
	// subf r26,r10,r11
	ctx.r26.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r28,r29,2
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x3) != 0);
	ctx.r28.s64 = ctx.r29.s32 >> 2;
	// srawi r8,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r26.s32 >> 2;
	// addze r25,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r25.s64 = temp.s64;
	// mr r24,r25
	ctx.r24.u64 = ctx.r25.u64;
loc_8272ADFC:
	// lwz r10,14604(r9)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + 14604);
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// lwz r8,14588(r9)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + 14588);
	// lwz r11,14608(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 14608);
	// srawi r31,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r31.s64 = ctx.r10.s32 >> 2;
	// lwz r23,14492(r9)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r9.u32 + 14492);
	// mullw r11,r11,r8
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r8.s32);
	// lwz r30,14500(r9)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r9.u32 + 14500);
	// addze r31,r31
	temp.s64 = ctx.r31.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r31.u32;
	ctx.r31.s64 = temp.s64;
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// mullw r8,r23,r7
	ctx.r8.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r7.s32);
	// add r11,r31,r11
	ctx.r11.u64 = ctx.r31.u64 + ctx.r11.u64;
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// add r8,r8,r30
	ctx.r8.u64 = ctx.r8.u64 + ctx.r30.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// add r4,r8,r3
	ctx.r4.u64 = ctx.r8.u64 + ctx.r3.u64;
	// ble cr6,0x8272aed8
	if (!ctx.cr6.gt) goto loc_8272AED8;
	// addi r6,r5,-1
	ctx.r6.s64 = ctx.r5.s64 + -1;
	// lwz r7,14480(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 14480);
	// mtctr r27
	ctx.ctr.u64 = ctx.r27.u64;
	// addi r5,r11,-1
	ctx.r5.s64 = ctx.r11.s64 + -1;
loc_8272AE64:
	// li r8,0
	ctx.r8.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// ble cr6,0x8272aec0
	if (!ctx.cr6.gt) goto loc_8272AEC0;
	// addi r11,r4,-5
	ctx.r11.s64 = ctx.r4.s64 + -5;
loc_8272AE74:
	// lbz r7,0(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 0);
	// addi r8,r8,4
	ctx.r8.s64 = ctx.r8.s64 + 4;
	// stb r7,5(r11)
	REX_STORE_U8(ctx.r11.u32 + 5, ctx.r7.u8);
	// lbz r3,1(r10)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + 1);
	// stb r3,7(r11)
	REX_STORE_U8(ctx.r11.u32 + 7, ctx.r3.u8);
	// lbz r7,2(r10)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r10.u32 + 2);
	// stb r7,9(r11)
	REX_STORE_U8(ctx.r11.u32 + 9, ctx.r7.u8);
	// lbz r3,3(r10)
	ctx.r3.u64 = REX_LOAD_U8(ctx.r10.u32 + 3);
	// addi r10,r10,4
	ctx.r10.s64 = ctx.r10.s64 + 4;
	// stb r3,11(r11)
	REX_STORE_U8(ctx.r11.u32 + 11, ctx.r3.u8);
	// lbzu r7,1(r6)
	ea = 1 + ctx.r6.u32;
	ctx.r7.u64 = REX_LOAD_U8(ea);
	ctx.r6.u32 = ea;
	// stb r7,10(r11)
	REX_STORE_U8(ctx.r11.u32 + 10, ctx.r7.u8);
	// stb r7,6(r11)
	REX_STORE_U8(ctx.r11.u32 + 6, ctx.r7.u8);
	// lbzu r7,1(r5)
	ea = 1 + ctx.r5.u32;
	ctx.r7.u64 = REX_LOAD_U8(ea);
	ctx.r5.u32 = ea;
	// stb r7,12(r11)
	REX_STORE_U8(ctx.r11.u32 + 12, ctx.r7.u8);
	// stbu r7,8(r11)
	ea = 8 + ctx.r11.u32;
	REX_STORE_U8(ea, ctx.r7.u8);
	ctx.r11.u32 = ea;
	// lwz r7,14480(r9)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r9.u32 + 14480);
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// blt cr6,0x8272ae74
	if (ctx.cr6.lt) goto loc_8272AE74;
loc_8272AEC0:
	// lwz r11,14492(r9)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r9.u32 + 14492);
	// add r10,r26,r10
	ctx.r10.u64 = ctx.r26.u64 + ctx.r10.u64;
	// add r6,r25,r6
	ctx.r6.u64 = ctx.r25.u64 + ctx.r6.u64;
	// add r5,r24,r5
	ctx.r5.u64 = ctx.r24.u64 + ctx.r5.u64;
	// add r4,r11,r4
	ctx.r4.u64 = ctx.r11.u64 + ctx.r4.u64;
	// bdnz 0x8272ae64
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272AE64;
loc_8272AED8:
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8272E648) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// blelr cr6
	if (!ctx.cr6.gt) return;
	// addi r11,r3,-2
	ctx.r11.s64 = ctx.r3.s64 + -2;
	// mtctr r4
	ctx.ctr.u64 = ctx.r4.u64;
loc_8272E658:
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// addi r9,r10,-128
	ctx.r9.s64 = ctx.r10.s64 + -128;
	// sthu r9,2(r11)
	ea = 2 + ctx.r11.u32;
	REX_STORE_U16(ea, ctx.r9.u16);
	ctx.r11.u32 = ea;
	// bdnz 0x8272e658
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8272E658;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8272F928) {
	REX_FUNC_PROLOGUE();
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// lis r11,-32141
	ctx.r11.s64 = -2106392576;
	// lis r10,-32141
	ctx.r10.s64 = -2106392576;
	// addi r11,r11,-6464
	ctx.r11.s64 = ctx.r11.s64 + -6464;
	// addi r10,r10,-6544
	ctx.r10.s64 = ctx.r10.s64 + -6544;
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// stw r11,15880(r3)
	REX_STORE_U32(ctx.r3.u32 + 15880, ctx.r11.u32);
	// lis r8,-32141
	ctx.r8.s64 = -2106392576;
	// stw r10,3160(r3)
	REX_STORE_U32(ctx.r3.u32 + 3160, ctx.r10.u32);
	// lis r7,-32141
	ctx.r7.s64 = -2106392576;
	// lis r6,-32141
	ctx.r6.s64 = -2106392576;
	// lis r5,-32119
	ctx.r5.s64 = -2104950784;
	// lis r4,-32119
	ctx.r4.s64 = -2104950784;
	// lis r31,-32141
	ctx.r31.s64 = -2106392576;
	// lis r30,-32141
	ctx.r30.s64 = -2106392576;
	// addi r9,r9,-4408
	ctx.r9.s64 = ctx.r9.s64 + -4408;
	// addi r8,r8,-2248
	ctx.r8.s64 = ctx.r8.s64 + -2248;
	// addi r7,r7,-2000
	ctx.r7.s64 = ctx.r7.s64 + -2000;
	// stw r9,20944(r3)
	REX_STORE_U32(ctx.r3.u32 + 20944, ctx.r9.u32);
	// addi r6,r6,-6584
	ctx.r6.s64 = ctx.r6.s64 + -6584;
	// stw r8,20936(r3)
	REX_STORE_U32(ctx.r3.u32 + 20936, ctx.r8.u32);
	// addi r5,r5,15952
	ctx.r5.s64 = ctx.r5.s64 + 15952;
	// stw r7,20940(r3)
	REX_STORE_U32(ctx.r3.u32 + 20940, ctx.r7.u32);
	// addi r4,r4,15560
	ctx.r4.s64 = ctx.r4.s64 + 15560;
	// stw r6,15864(r3)
	REX_STORE_U32(ctx.r3.u32 + 15864, ctx.r6.u32);
	// addi r11,r31,-6816
	ctx.r11.s64 = ctx.r31.s64 + -6816;
	// stw r5,15868(r3)
	REX_STORE_U32(ctx.r3.u32 + 15868, ctx.r5.u32);
	// addi r10,r30,13816
	ctx.r10.s64 = ctx.r30.s64 + 13816;
	// stw r4,15872(r3)
	REX_STORE_U32(ctx.r3.u32 + 15872, ctx.r4.u32);
	// stw r11,15876(r3)
	REX_STORE_U32(ctx.r3.u32 + 15876, ctx.r11.u32);
	// stw r10,3156(r3)
	REX_STORE_U32(ctx.r3.u32 + 3156, ctx.r10.u32);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82734A08) {
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
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// addi r11,r11,-28808
	ctx.r11.s64 = ctx.r11.s64 + -28808;
	// lwz r4,44(r11)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r11.u32 + 44);
	// cmplwi r4,0
	ctx.cr0.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// bne 0x82734a3c
	if (!ctx.cr0.eq) goto loc_82734A3C;
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,5
	ctx.r3.u64 = ctx.r3.u64 | 5;
	// b 0x82734a78
	goto loc_82734A78;
loc_82734A3C:
	// sth r3,80(r1)
	REX_STORE_U16(ctx.r1.u32 + 80, ctx.r3.u16);
	// lis r9,-32141
	ctx.r9.s64 = -2106392576;
	// li r6,4
	ctx.r6.s64 = 4;
	// lhz r5,40(r11)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r11.u32 + 40);
	// addi r7,r9,18672
	ctx.r7.s64 = ctx.r9.s64 + 18672;
	// addi r3,r1,80
	ctx.r3.s64 = ctx.r1.s64 + 80;
	// bl 0x8273ca60
	ctx.lr = 0x82734A58;
	sub_8273CA60(ctx, base);
	// cmplwi r3,0
	ctx.cr0.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// bne 0x82734a6c
	if (!ctx.cr0.eq) goto loc_82734A6C;
	// lis r3,-32747
	ctx.r3.s64 = -2146107392;
	// ori r3,r3,14
	ctx.r3.u64 = ctx.r3.u64 | 14;
	// b 0x82734a78
	goto loc_82734A78;
loc_82734A6C:
	// lhz r11,2(r3)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r3.u32 + 2);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r11,0(r31)
	REX_STORE_U32(ctx.r31.u32 + 0, ctx.r11.u32);
loc_82734A78:
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

DEFINE_REX_FUNC(sub_82735E60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x82735E68;
	__savegprlr_29(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// bl 0x82855ce4
	ctx.lr = 0x82735E7C;
	__imp__XamSessionRefObjByHandle(ctx, base);
	// mr. r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r31.s32, 0, ctx.xer);
	// bne 0x82735ef0
	if (!ctx.cr0.eq) goto loc_82735EF0;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// lis r4,11
	ctx.r4.s64 = 720896;
	// std r10,104(r1)
	REX_STORE_U64(ctx.r1.u32 + 104, ctx.r10.u64);
	// li r7,16
	ctx.r7.s64 = 16;
	// addi r6,r1,96
	ctx.r6.s64 = ctx.r1.s64 + 96;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// ori r4,r4,20
	ctx.r4.u64 = ctx.r4.u64 | 20;
	// li r3,251
	ctx.r3.s64 = 251;
	// bl 0x82855704
	ctx.lr = 0x82735EB4;
	__imp__XMsgStartIORequest(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bge 0x82735ec4
	if (!ctx.cr0.lt) goto loc_82735EC4;
	// li r31,1627
	ctx.r31.s64 = 1627;
	// b 0x82735ee8
	goto loc_82735EE8;
loc_82735EC4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82735ee4
	if (!ctx.cr6.eq) goto loc_82735EE4;
	// bl 0x8263bcc8
	ctx.lr = 0x82735ED0;
	sub_8263BCC8(ctx, base);
	// subfic r11,r3,0
	ctx.xer.ca = ctx.r3.u32 <= 0;
	ctx.r11.u64 = static_cast<uint64_t>(0) - ctx.r3.u64;
	// li r10,1627
	ctx.r10.s64 = 1627;
	// subfe r11,r11,r11
	temp.u8 = (~ctx.r11.u32 + ctx.r11.u32 < ~ctx.r11.u32) | (~ctx.r11.u32 + ctx.r11.u32 + ctx.xer.ca < ctx.xer.ca);
	ctx.r11.u64 = ~ctx.r11.u64 + ctx.r11.u64 + ctx.xer.ca;
	ctx.xer.ca = temp.u8;
	// and r31,r11,r10
	ctx.r31.u64 = ctx.r11.u64 & ctx.r10.u64;
	// b 0x82735ee8
	goto loc_82735EE8;
loc_82735EE4:
	// li r31,997
	ctx.r31.s64 = 997;
loc_82735EE8:
	// lwz r3,80(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// bl 0x82855a64
	ctx.lr = 0x82735EF0;
	__imp__ObDereferenceObject(ctx, base);
loc_82735EF0:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736CA0) {
	REX_FUNC_PROLOGUE();
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855e24
	__imp__NetDll_closesocket(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82736D00) {
	REX_FUNC_PROLOGUE();
	// mr r8,r7
	ctx.r8.u64 = ctx.r7.u64;
	// mr r7,r6
	ctx.r7.u64 = ctx.r6.u64;
	// mr r6,r5
	ctx.r6.u64 = ctx.r5.u64;
	// mr r5,r4
	ctx.r5.u64 = ctx.r4.u64;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// li r3,1
	ctx.r3.s64 = 1;
	// b 0x82855e64
	__imp__NetDll_select(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827378C8) {
	REX_FUNC_PROLOGUE();
	// lwz r11,8(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 8);
	// cmplw cr6,r4,r11
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x827378e0
	if (!ctx.cr6.gt) goto loc_827378E0;
	// lis r3,-32744
	ctx.r3.s64 = -2145910784;
	// ori r3,r3,8193
	ctx.r3.u64 = ctx.r3.u64 | 8193;
	// blr 
	return;
loc_827378E0:
	// stw r4,12(r3)
	REX_STORE_U32(ctx.r3.u32 + 12, ctx.r4.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82737E90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82737E98;
	__savegprlr_27(ctx, base);
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r28,r3
	ctx.r28.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r4,r6
	ctx.r4.u64 = ctx.r6.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// mr r27,r7
	ctx.r27.u64 = ctx.r7.u64;
	// bl 0x82736630
	ctx.lr = 0x82737EBC;
	sub_82736630(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82737f88
	if (ctx.cr0.lt) goto loc_82737F88;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// clrlwi r10,r11,26
	ctx.r10.u64 = ctx.r11.u32 & 0x3F;
	// cmplwi cr6,r10,63
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 63, ctx.xer);
	// beq cr6,0x82737f88
	if (ctx.cr6.eq) goto loc_82737F88;
	// rlwinm. r11,r11,0,0,24
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFF80;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82737f60
	if (ctx.cr0.eq) goto loc_82737F60;
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82737cd8
	ctx.lr = 0x82737EE8;
	sub_82737CD8(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82737f88
	if (ctx.cr0.lt) goto loc_82737F88;
	// addi r5,r1,84
	ctx.r5.s64 = ctx.r1.s64 + 84;
	// lhz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U16(ctx.r1.u32 + 80);
	// lwz r3,20(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 20);
	// bl 0x82736a48
	ctx.lr = 0x82737F00;
	sub_82736A48(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82737f88
	if (ctx.cr0.lt) goto loc_82737F88;
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// clrlwi r10,r29,30
	ctx.r10.u64 = ctx.r29.u32 & 0x3;
	// clrlwi r11,r11,26
	ctx.r11.u64 = ctx.r11.u32 & 0x3F;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bge cr6,0x82737f90
	if (!ctx.cr6.lt) goto loc_82737F90;
	// cmplwi cr6,r10,3
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 3, ctx.xer);
	// bgt cr6,0x82737f90
	if (ctx.cr6.gt) goto loc_82737F90;
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// add r11,r11,r28
	ctx.r11.u64 = ctx.r11.u64 + ctx.r28.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm. r9,r9,0,1,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0x40000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq 0x82737f44
	if (ctx.cr0.eq) goto loc_82737F44;
	// lis r3,-32768
	ctx.r3.s64 = -2147483648;
	// ori r3,r3,16389
	ctx.r3.u64 = ctx.r3.u64 | 16389;
	// b 0x82737f88
	goto loc_82737F88;
loc_82737F44:
	// lwz r9,84(r1)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// li r8,1
	ctx.r8.s64 = 1;
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwimi r10,r8,31,0,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// stw r7,4(r11)
	REX_STORE_U32(ctx.r11.u32 + 4, ctx.r7.u32);
	// stw r10,0(r11)
	REX_STORE_U32(ctx.r11.u32 + 0, ctx.r10.u32);
	// std r9,8(r11)
	REX_STORE_U64(ctx.r11.u32 + 8, ctx.r9.u64);
loc_82737F60:
	// lbz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r30.u32 + 0);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// clrlwi r4,r11,26
	ctx.r4.u64 = ctx.r11.u32 & 0x3F;
	// bl 0x82737de0
	ctx.lr = 0x82737F74;
	sub_82737DE0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt 0x82737f88
	if (ctx.cr0.lt) goto loc_82737F88;
	// lwz r11,80(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// ld r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r11.u32 + 8);
	// stw r11,0(r27)
	REX_STORE_U32(ctx.r27.u32 + 0, ctx.r11.u32);
loc_82737F88:
	// addi r1,r1,144
	ctx.r1.s64 = ctx.r1.s64 + 144;
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
loc_82737F90:
	// lis r3,-32761
	ctx.r3.s64 = -2147024896;
	// ori r3,r3,87
	ctx.r3.u64 = ctx.r3.u64 | 87;
	// b 0x82737f88
	goto loc_82737F88;
}

DEFINE_REX_FUNC(sub_8273AD00) {
	REX_FUNC_PROLOGUE();
	// cmpw r3,r4
	ctx.cr0.compare<int32_t>(ctx.r3.s32, ctx.r4.s32, ctx.xer);
	// beqlr- 
	if (ctx.cr0.eq) return;
	// bge+ 0x8273ad10
	if (!ctx.cr0.lt) goto loc_8273AD10;
	// b 0x8273a030
	sub_8273A030(ctx, base);
	return;
loc_8273AD10:
	// addi r0,r5,1
	ctx.r0.s64 = ctx.r5.s64 + 1;
	// add r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 + ctx.r5.u64;
	// add r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 + ctx.r5.u64;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// b 0x8273ad38
	goto loc_8273AD38;
loc_8273AD24:
	// addi r5,r5,-1
	ctx.r5.s64 = ctx.r5.s64 + -1;
	// lbz r0,-1(r4)
	ctx.r0.u64 = REX_LOAD_U8(ctx.r4.u32 + -1);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stb r0,-1(r3)
	REX_STORE_U8(ctx.r3.u32 + -1, ctx.r0.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
loc_8273AD38:
	// andi. r0,r3,3
	ctx.r0.u64 = ctx.r3.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bdnzf eq,0x8273ad24
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0 && !ctx.cr0.eq) goto loc_8273AD24;
	// rlwinm. r0,r5,30,2,31
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// beq- 0x8273ad68
	if (ctx.cr0.eq) goto loc_8273AD68;
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// andi. r0,r4,3
	ctx.r0.u64 = ctx.r4.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// bne- 0x8273ad8c
	if (!ctx.cr0.eq) goto loc_8273AD8C;
loc_8273AD54:
	// lwz r7,-4(r4)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r4.u32 + -4);
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r7,-4(r3)
	REX_STORE_U32(ctx.r3.u32 + -4, ctx.r7.u32);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// bdnz+ 0x8273ad54
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273AD54;
loc_8273AD68:
	// andi. r0,r5,3
	ctx.r0.u64 = ctx.r5.u64 & 3;
	ctx.cr0.compare<int32_t>(ctx.r0.s32, 0, ctx.xer);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// beqlr+ 
	if (ctx.cr0.eq) return;
loc_8273AD74:
	// lbz r0,-1(r4)
	ctx.r0.u64 = REX_LOAD_U8(ctx.r4.u32 + -1);
	// addi r4,r4,-1
	ctx.r4.s64 = ctx.r4.s64 + -1;
	// stb r0,-1(r3)
	REX_STORE_U8(ctx.r3.u32 + -1, ctx.r0.u8);
	// addi r3,r3,-1
	ctx.r3.s64 = ctx.r3.s64 + -1;
	// bdnz+ 0x8273ad74
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273AD74;
	// blr 
	return;
loc_8273AD8C:
	// lbz r7,-1(r4)
	ctx.r7.u64 = REX_LOAD_U8(ctx.r4.u32 + -1);
	// addi r3,r3,-4
	ctx.r3.s64 = ctx.r3.s64 + -4;
	// lbz r8,-2(r4)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r4.u32 + -2);
	// rlwimi r7,r8,8,16,23
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFF00) | (ctx.r7.u64 & 0xFFFFFFFFFFFF00FF);
	// lbz r9,-3(r4)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r4.u32 + -3);
	// rlwimi r7,r9,16,8,15
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFF0000) | (ctx.r7.u64 & 0xFFFFFFFFFF00FFFF);
	// lbz r10,-4(r4)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r4.u32 + -4);
	// rlwimi r7,r10,24,0,7
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 24) & 0xFF000000) | (ctx.r7.u64 & 0xFFFFFFFF00FFFFFF);
	// addi r4,r4,-4
	ctx.r4.s64 = ctx.r4.s64 + -4;
	// stw r7,0(r3)
	REX_STORE_U32(ctx.r3.u32 + 0, ctx.r7.u32);
	// bdnz 0x8273ad8c
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8273AD8C;
	// b 0x8273ad68
	goto loc_8273AD68;
}

DEFINE_REX_FUNC(__savevmx_94) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
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

DEFINE_REX_FUNC(__restvmx_100) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// li r11,-448
	ctx.r11.s64 = -448;
	// lvx128 v100,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v100.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-432
	ctx.r11.s64 = -432;
	// lvx128 v101,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v101.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-416
	ctx.r11.s64 = -416;
	// lvx128 v102,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v102.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-400
	ctx.r11.s64 = -400;
	// lvx128 v103,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v103.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-384
	ctx.r11.s64 = -384;
	// lvx128 v104,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v104.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,-368
	ctx.r11.s64 = -368;
	// lvx128 v105,r11,r12
	ea = (ctx.r11.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v105.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
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

DEFINE_REX_FUNC(sub_8273EA40) {
	REX_FUNC_PROLOGUE();
	// stfd f1,16(r1)
	ctx.fpscr.disableFlushMode();
	REX_STORE_U64(ctx.r1.u32 + 16, ctx.f1.u64);
	// lhz r11,16(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 16);
	// stfd f1,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.f1.u64);
	// addi r10,r4,1022
	ctx.r10.s64 = ctx.r4.s64 + 1022;
	// andi. r11,r11,32783
	ctx.r11.u64 = ctx.r11.u64 & 32783;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r10,r10,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// sth r11,-16(r1)
	REX_STORE_U16(ctx.r1.u32 + -16, ctx.r11.u16);
	// lfd f1,-16(r1)
	ctx.f1.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82740690) {
	REX_FUNC_PROLOGUE();
	// lis r12,-32250
	ctx.r12.s64 = -2113536000;
	// lfd f4,22928(r12)
	ctx.fpscr.disableFlushMode();
	ctx.f4.u64 = REX_LOAD_U64(ctx.r12.u32 + 22928);
	// lis r12,-32250
	ctx.r12.s64 = -2113536000;
	// lfd f5,22936(r12)
	ctx.f5.u64 = REX_LOAD_U64(ctx.r12.u32 + 22936);
	// fcmpu cr0,f1,f4
	ctx.cr0.compare(ctx.f1.f64, ctx.f4.f64);
	// beq- 0x827406d0
	if (ctx.cr0.eq) goto loc_827406D0;
	// fabs f6,f1
	ctx.f6.u64 = ctx.f1.u64 & ~0x8000000000000000;
	// fcmpu cr0,f6,f5
	ctx.cr0.compare(ctx.f6.f64, ctx.f5.f64);
	// bge- 0x827406d0
	if (!ctx.cr0.lt) goto loc_827406D0;
	// fcmpu cr0,f1,f4
	ctx.cr0.compare(ctx.f1.f64, ctx.f4.f64);
	// blt 0x827406c8
	if (ctx.cr0.lt) goto loc_827406C8;
	// fadd f4,f1,f5
	ctx.f4.f64 = ctx.f1.f64 + ctx.f5.f64;
	// fsub f1,f4,f5
	ctx.f1.f64 = ctx.f4.f64 - ctx.f5.f64;
	// b 0x827406d0
	goto loc_827406D0;
loc_827406C8:
	// fsub f4,f1,f5
	ctx.fpscr.disableFlushMode();
	ctx.f4.f64 = ctx.f1.f64 - ctx.f5.f64;
	// fadd f1,f4,f5
	ctx.f1.f64 = ctx.f4.f64 + ctx.f5.f64;
loc_827406D0:
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82741F2C) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// std r31,-8(r1)
	REX_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// addi r31,r12,-144
	ctx.r31.s64 = ctx.r12.s64 + -144;
	// std r30,-16(r1)
	REX_STORE_U64(ctx.r1.u32 + -16, ctx.r30.u64);
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// stw r12,-24(r1)
	REX_STORE_U32(ctx.r1.u32 + -24, ctx.r12.u32);
	// stwu r1,-112(r1)
	ea = -112 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r30,164(r31)
	ctx.r30.u64 = REX_LOAD_U32(ctx.r31.u32 + 164);
	// b 0x82741f64
	goto loc_82741F64;
loc_82741F64:
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82745a68
	ctx.lr = 0x82741F6C;
	sub_82745A68(ctx, base);
	// lwz r1,0(r1)
	ctx.r1.u64 = REX_LOAD_U32(ctx.r1.u32 + 0);
	// ld r31,-8(r1)
	ctx.r31.u64 = REX_LOAD_U64(ctx.r1.u32 + -8);
	// ld r30,-16(r1)
	ctx.r30.u64 = REX_LOAD_U64(ctx.r1.u32 + -16);
	// lwz r12,-24(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -24);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82743E90) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f18
	ctx.lr = 0x82743E98;
	__savegprlr_28(ctx, base);
	// addi r31,r1,-144
	ctx.r31.s64 = ctx.r1.s64 + -144;
	// stwu r1,-144(r1)
	ea = -144 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r30,r6
	ctx.r30.u64 = ctx.r6.u64;
	// lwz r11,4(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 4);
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r10,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r10.u32);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82744100
	if (ctx.cr6.eq) goto loc_82744100;
	// lbz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r11.u32 + 8);
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82744100
	if (ctx.cr0.eq) goto loc_82744100;
	// lwz r11,8(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 8);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82743ee0
	if (!ctx.cr6.eq) goto loc_82743EE0;
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r10,r10,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq 0x82744100
	if (ctx.cr0.eq) goto loc_82744100;
loc_82743EE0:
	// lwz r10,0(r5)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r5.u32 + 0);
	// rlwinm. r9,r10,0,0,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// mr r28,r4
	ctx.r28.u64 = ctx.r4.u64;
	// bne 0x82743ef4
	if (!ctx.cr0.eq) goto loc_82743EF4;
	// add r28,r11,r4
	ctx.r28.u64 = ctx.r11.u64 + ctx.r4.u64;
loc_82743EF4:
	// nop 
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// rlwinm. r11,r10,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// li r4,1
	ctx.r4.s64 = 1;
	// lwz r3,24(r29)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// beq 0x82743f7c
	if (ctx.cr0.eq) goto loc_82743F7C;
	// bl 0x82745bb0
	ctx.lr = 0x82743F14;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82745bb0
	ctx.lr = 0x82743F28;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// lwz r10,24(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// lwz r8,12(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r9,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
	// blt cr6,0x82743f74
	if (ctx.cr6.lt) goto loc_82743F74;
	// lwz r8,4(r11)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r8,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r9,r8,r11
	ctx.r9.u64 = ctx.r8.u64 + ctx.r11.u64;
	// stw r11,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r11.u32);
	// stw r9,80(r31)
	REX_STORE_U32(ctx.r31.u32 + 80, ctx.r9.u32);
loc_82743F74:
	// stw r9,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r9.u32);
	// b 0x827440e4
	goto loc_827440E4;
loc_82743F7C:
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// clrlwi. r11,r11,31
	ctx.r11.u64 = ctx.r11.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82744014
	if (ctx.cr0.eq) goto loc_82744014;
	// bl 0x82745bb0
	ctx.lr = 0x82743F8C;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82745bb0
	ctx.lr = 0x82743FA0;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// lwz r5,20(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// lwz r4,24(r29)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// bl 0x8273ad00
	ctx.lr = 0x82743FB8;
	sub_8273AD00(ctx, base);
	// lwz r11,20(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// cmplwi cr6,r11,4
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 4, ctx.xer);
	// bne cr6,0x827440e4
	if (!ctx.cr6.eq) goto loc_827440E4;
	// lwz r8,0(r28)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x827440e4
	if (ctx.cr6.eq) goto loc_827440E4;
	// lwz r10,8(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// lwz r9,12(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
	// blt cr6,0x8274400c
	if (ctx.cr6.lt) goto loc_8274400C;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r8,r9,r8
	ctx.r8.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// lwzx r11,r8,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r11.u32);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r10,r9,r11
	ctx.r10.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r11.u32);
	// stw r10,84(r31)
	REX_STORE_U32(ctx.r31.u32 + 84, ctx.r10.u32);
loc_8274400C:
	// stw r10,0(r28)
	REX_STORE_U32(ctx.r28.u32 + 0, ctx.r10.u32);
	// b 0x827440e4
	goto loc_827440E4;
loc_82744014:
	// lwz r11,24(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82744090
	if (!ctx.cr6.eq) goto loc_82744090;
	// bl 0x82745bb0
	ctx.lr = 0x82744024;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82745bb0
	ctx.lr = 0x82744038;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// lwz r10,24(r29)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// addi r11,r30,8
	ctx.r11.s64 = ctx.r30.s64 + 8;
	// lwz r9,8(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r8,12(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 12);
	// add r4,r9,r10
	ctx.r4.u64 = ctx.r9.u64 + ctx.r10.u64;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// stw r4,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
	// blt cr6,0x82744080
	if (ctx.cr6.lt) goto loc_82744080;
	// lwz r9,4(r11)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r11.u32 + 4);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// lwzx r10,r9,r10
	ctx.r10.u64 = REX_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// lwzx r11,r10,r11
	ctx.r11.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r11,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r11.u32);
	// stw r4,88(r31)
	REX_STORE_U32(ctx.r31.u32 + 88, ctx.r4.u32);
loc_82744080:
	// lwz r5,20(r30)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r30.u32 + 20);
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273ad00
	ctx.lr = 0x8274408C;
	sub_8273AD00(ctx, base);
	// b 0x827440e4
	goto loc_827440E4;
loc_82744090:
	// bl 0x82745bb0
	ctx.lr = 0x82744094;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82745bb0
	ctx.lr = 0x827440A8;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// lwz r3,24(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 24);
	// bl 0x82745bb0
	ctx.lr = 0x827440B8;
	sub_82745BB0(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x827440e0
	if (ctx.cr0.eq) goto loc_827440E0;
	// lwz r11,0(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 0);
	// rlwinm r11,r11,0,29,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4;
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// rlwinm r11,r11,27,31,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// xori r11,r11,1
	ctx.r11.u64 = ctx.r11.u64 ^ 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,92(r31)
	REX_STORE_U32(ctx.r31.u32 + 92, ctx.r11.u32);
	// b 0x827440e4
	goto loc_827440E4;
loc_827440E0:
	// bl 0x82741800
	ctx.lr = 0x827440E4;
	sub_82741800(ctx, base);
loc_827440E4:
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// mr r8,r8
	ctx.r8.u64 = ctx.r8.u64;
	// b 0x827440f8
	goto loc_827440F8;
loc_827440F8:
	// lwz r3,92(r31)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r31.u32 + 92);
	// b 0x82744104
	goto loc_82744104;
loc_82744100:
	// li r3,0
	ctx.r3.s64 = 0;
loc_82744104:
	// addi r1,r31,144
	ctx.r1.s64 = ctx.r31.s64 + 144;
	// b 0x82739f68
	__restgprlr_28(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8275C4F0) {
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
	// rlwinm r10,r7,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bge cr6,0x8275c5c0
	if (!ctx.cr6.lt) goto loc_8275C5C0;
	// subf r10,r11,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
	// rlwinm r10,r10,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// lfs f0,-30536(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30536);
	ctx.f0.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// lfs f13,5864(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 5864);
	ctx.f13.f64 = double(temp.f32);
loc_8275C554:
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// rlwinm r10,r10,22,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 22) & 0x1F;
	// std r10,80(r1)
	REX_STORE_U64(ctx.r1.u32 + 80, ctx.r10.u64);
	// lfd f12,80(r1)
	ctx.fpscr.disableFlushMode();
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 80);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,0(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 0, temp.u32);
	// lhz r10,2(r11)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r11.u32 + 2);
	// rlwinm r10,r10,27,27,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1F;
	// std r10,88(r1)
	REX_STORE_U64(ctx.r1.u32 + 88, ctx.r10.u64);
	// lfd f12,88(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 88);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,4(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 4, temp.u32);
	// lhzu r10,2(r11)
	ea = 2 + ctx.r11.u32;
	ctx.r10.u64 = REX_LOAD_U16(ea);
	ctx.r11.u32 = ea;
	// clrlwi r10,r10,27
	ctx.r10.u64 = ctx.r10.u32 & 0x1F;
	// std r10,96(r1)
	REX_STORE_U64(ctx.r1.u32 + 96, ctx.r10.u64);
	// lfd f12,96(r1)
	ctx.f12.u64 = REX_LOAD_U64(ctx.r1.u32 + 96);
	// fcfid f12,f12
	ctx.f12.f64 = double(ctx.f12.s64);
	// stfs f13,12(r6)
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ctx.r6.u32 + 12, temp.u32);
	// frsp f12,f12
	ctx.f12.f64 = double(float(ctx.f12.f64));
	// fmuls f12,f12,f0
	ctx.f12.f64 = double(float(ctx.f12.f64 * ctx.f0.f64));
	// stfs f12,8(r6)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r6.u32 + 8, temp.u32);
	// addi r6,r6,16
	ctx.r6.s64 = ctx.r6.s64 + 16;
	// bdnz 0x8275c554
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_8275C554;
loc_8275C5C0:
	// lwz r11,24(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275c5dc
	if (ctx.cr6.eq) goto loc_8275C5DC;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82755c68
	ctx.lr = 0x8275C5DC;
	sub_82755C68(ctx, base);
loc_8275C5DC:
	// lwz r11,16(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 16);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x8275c5f8
	if (ctx.cr6.eq) goto loc_8275C5F8;
	// lwz r11,104(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 104);
	// rlwinm r11,r11,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// bl 0x82756030
	ctx.lr = 0x8275C5F8;
	sub_82756030(ctx, base);
loc_8275C5F8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82760858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f14
	ctx.lr = 0x82760860;
	__savegprlr_27(ctx, base);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273aef0
	ctx.lr = 0x82760868;
	__savefpr_14(ctx, base);
	// cmplwi cr6,r6,3
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 3, ctx.xer);
	// bne cr6,0x82760884
	if (!ctx.cr6.eq) goto loc_82760884;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r31,r11,-29736
	ctx.r31.s64 = ctx.r11.s64 + -29736;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r30,r11,-29748
	ctx.r30.s64 = ctx.r11.s64 + -29748;
	// b 0x82760894
	goto loc_82760894;
loc_82760884:
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r31,r11,-29764
	ctx.r31.s64 = ctx.r11.s64 + -29764;
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// addi r30,r11,-29780
	ctx.r30.s64 = ctx.r11.s64 + -29780;
loc_82760894:
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// addi r8,r11,-3168
	ctx.r8.s64 = ctx.r11.s64 + -3168;
	// addi r7,r1,-272
	ctx.r7.s64 = ctx.r1.s64 + -272;
	// li r10,16
	ctx.r10.s64 = 16;
	// lwz r29,-3168(r11)
	ctx.r29.u64 = REX_LOAD_U32(ctx.r11.u32 + -3168);
	// addi r5,r5,8
	ctx.r5.s64 = ctx.r5.s64 + 8;
	// lfs f0,2524(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2524);
	ctx.f0.f64 = double(temp.f32);
	// lwz r9,4(r8)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r8.u32 + 4);
	// fmr f26,f0
	ctx.f26.f64 = ctx.f0.f64;
	// lwz r28,8(r8)
	ctx.r28.u64 = REX_LOAD_U32(ctx.r8.u32 + 8);
	// fmr f29,f0
	ctx.f29.f64 = ctx.f0.f64;
	// lwz r8,12(r8)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r8.u32 + 12);
	// fmr f28,f0
	ctx.f28.f64 = ctx.f0.f64;
	// stw r29,0(r7)
	REX_STORE_U32(ctx.r7.u32 + 0, ctx.r29.u32);
	// mr r11,r5
	ctx.r11.u64 = ctx.r5.u64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r9,4(r7)
	REX_STORE_U32(ctx.r7.u32 + 4, ctx.r9.u32);
	// stw r28,8(r7)
	REX_STORE_U32(ctx.r7.u32 + 8, ctx.r28.u32);
	// stw r8,12(r7)
	REX_STORE_U32(ctx.r7.u32 + 12, ctx.r8.u32);
	// lfs f31,-264(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -264);
	ctx.f31.f64 = double(temp.f32);
	// lfs f1,-268(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -268);
	ctx.f1.f64 = double(temp.f32);
	// lfs f30,-272(r1)
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -272);
	ctx.f30.f64 = double(temp.f32);
loc_827608F0:
	// lfs f11,-8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8);
	ctx.f11.f64 = double(temp.f32);
	// fcmpu cr6,f11,f30
	ctx.cr6.compare(ctx.f11.f64, ctx.f30.f64);
	// bge cr6,0x82760900
	if (!ctx.cr6.lt) goto loc_82760900;
	// fmr f30,f11
	ctx.f30.f64 = ctx.f11.f64;
loc_82760900:
	// lfs f12,-4(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4);
	ctx.f12.f64 = double(temp.f32);
	// fcmpu cr6,f12,f1
	ctx.cr6.compare(ctx.f12.f64, ctx.f1.f64);
	// bge cr6,0x82760910
	if (!ctx.cr6.lt) goto loc_82760910;
	// fmr f1,f12
	ctx.f1.f64 = ctx.f12.f64;
loc_82760910:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f31
	ctx.cr6.compare(ctx.f13.f64, ctx.f31.f64);
	// bge cr6,0x82760920
	if (!ctx.cr6.lt) goto loc_82760920;
	// fmr f31,f13
	ctx.f31.f64 = ctx.f13.f64;
loc_82760920:
	// fcmpu cr6,f11,f26
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f11.f64, ctx.f26.f64);
	// ble cr6,0x8276092c
	if (!ctx.cr6.gt) goto loc_8276092C;
	// fmr f26,f11
	ctx.f26.f64 = ctx.f11.f64;
loc_8276092C:
	// fcmpu cr6,f12,f29
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f12.f64, ctx.f29.f64);
	// ble cr6,0x82760938
	if (!ctx.cr6.gt) goto loc_82760938;
	// fmr f29,f12
	ctx.f29.f64 = ctx.f12.f64;
loc_82760938:
	// fcmpu cr6,f13,f28
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f13.f64, ctx.f28.f64);
	// ble cr6,0x82760944
	if (!ctx.cr6.gt) goto loc_82760944;
	// fmr f28,f13
	ctx.f28.f64 = ctx.f13.f64;
loc_82760944:
	// addi r11,r11,16
	ctx.r11.s64 = ctx.r11.s64 + 16;
	// bdnz 0x827608f0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827608F0;
	// fsubs f13,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f1.f64));
	// lis r11,-32255
	ctx.r11.s64 = -2113863680;
	// fsubs f12,f28,f31
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// fsubs f11,f26,f30
	ctx.f11.f64 = double(float(ctx.f26.f64 - ctx.f30.f64));
	// lfs f10,10980(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 10980);
	ctx.f10.f64 = double(temp.f32);
	// fmuls f9,f13,f13
	ctx.f9.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f9,f12,f12,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f12.f64, ctx.f12.f64, ctx.f9.f64)));
	// fmadds f3,f11,f11,f9
	ctx.f3.f64 = double(float(std::fma(ctx.f11.f64, ctx.f11.f64, ctx.f9.f64)));
	// fcmpu cr6,f3,f10
	ctx.cr6.compare(ctx.f3.f64, ctx.f10.f64);
	// blt cr6,0x82760cb4
	if (ctx.cr6.lt) goto loc_82760CB4;
	// lis r9,-32256
	ctx.r9.s64 = -2113929216;
	// fadds f6,f26,f30
	ctx.f6.f64 = double(float(ctx.f26.f64 + ctx.f30.f64));
	// fadds f5,f29,f1
	ctx.f5.f64 = double(float(ctx.f29.f64 + ctx.f1.f64));
	// lis r8,-32256
	ctx.r8.s64 = -2113929216;
	// fadds f4,f28,f31
	ctx.f4.f64 = double(float(ctx.f28.f64 + ctx.f31.f64));
	// li r10,16
	ctx.r10.s64 = 16;
	// addi r11,r5,-16
	ctx.r11.s64 = ctx.r5.s64 + -16;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// lfs f10,5864(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5864);
	ctx.f10.f64 = double(temp.f32);
	// fmr f9,f0
	ctx.f9.f64 = ctx.f0.f64;
	// fdivs f2,f10,f3
	ctx.f2.f64 = double(float(ctx.f10.f64 / ctx.f3.f64));
	// lfs f27,7996(r8)
	temp.u32 = REX_LOAD_U32(ctx.r8.u32 + 7996);
	ctx.f27.f64 = double(temp.f32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fmuls f6,f6,f27
	ctx.f6.f64 = double(float(ctx.f6.f64 * ctx.f27.f64));
	// fmuls f5,f5,f27
	ctx.f5.f64 = double(float(ctx.f5.f64 * ctx.f27.f64));
	// fmuls f4,f4,f27
	ctx.f4.f64 = double(float(ctx.f4.f64 * ctx.f27.f64));
	// fmuls f11,f2,f11
	ctx.f11.f64 = double(float(ctx.f2.f64 * ctx.f11.f64));
	// fmuls f13,f2,f13
	ctx.f13.f64 = double(float(ctx.f2.f64 * ctx.f13.f64));
	// fmuls f12,f2,f12
	ctx.f12.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
loc_827609C8:
	// lfs f2,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f2.f64 = double(temp.f32);
	// lfs f25,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f25.f64 = double(temp.f32);
	// fsubs f24,f2,f6
	ctx.f24.f64 = double(float(ctx.f2.f64 - ctx.f6.f64));
	// lfsu f2,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f2.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// fsubs f25,f25,f5
	ctx.f25.f64 = double(float(ctx.f25.f64 - ctx.f5.f64));
	// fsubs f2,f2,f4
	ctx.f2.f64 = double(float(ctx.f2.f64 - ctx.f4.f64));
	// fmuls f24,f24,f11
	ctx.f24.f64 = double(float(ctx.f24.f64 * ctx.f11.f64));
	// fmuls f25,f25,f13
	ctx.f25.f64 = double(float(ctx.f25.f64 * ctx.f13.f64));
	// fmuls f2,f2,f12
	ctx.f2.f64 = double(float(ctx.f2.f64 * ctx.f12.f64));
	// fsubs f23,f24,f25
	ctx.f23.f64 = double(float(ctx.f24.f64 - ctx.f25.f64));
	// fadds f22,f25,f24
	ctx.f22.f64 = double(float(ctx.f25.f64 + ctx.f24.f64));
	// fadds f25,f2,f25
	ctx.f25.f64 = double(float(ctx.f2.f64 + ctx.f25.f64));
	// fadds f21,f23,f2
	ctx.f21.f64 = double(float(ctx.f23.f64 + ctx.f2.f64));
	// fsubs f22,f22,f2
	ctx.f22.f64 = double(float(ctx.f22.f64 - ctx.f2.f64));
	// fadds f25,f25,f24
	ctx.f25.f64 = double(float(ctx.f25.f64 + ctx.f24.f64));
	// fsubs f2,f23,f2
	ctx.f2.f64 = double(float(ctx.f23.f64 - ctx.f2.f64));
	// fmadds f8,f21,f21,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f21.f64, ctx.f21.f64, ctx.f8.f64)));
	// fmadds f9,f22,f22,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f22.f64, ctx.f22.f64, ctx.f9.f64)));
	// fmadds f10,f25,f25,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f25.f64, ctx.f25.f64, ctx.f10.f64)));
	// fmadds f7,f2,f2,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f2.f64, ctx.f2.f64, ctx.f7.f64)));
	// bdnz 0x827609c8
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_827609C8;
	// li r10,3
	ctx.r10.s64 = 3;
	// stfs f7,-260(r1)
	temp.f32 = float(ctx.f7.f64);
	REX_STORE_U32(ctx.r1.u32 + -260, temp.u32);
	// stfs f10,-272(r1)
	temp.f32 = float(ctx.f10.f64);
	REX_STORE_U32(ctx.r1.u32 + -272, temp.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stfs f9,-268(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -268, temp.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stfs f8,-264(r1)
	temp.f32 = float(ctx.f8.f64);
	REX_STORE_U32(ctx.r1.u32 + -264, temp.u32);
	// addi r9,r1,-268
	ctx.r9.s64 = ctx.r1.s64 + -268;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
loc_82760A40:
	// lfs f13,0(r9)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fcmpu cr6,f13,f10
	ctx.cr6.compare(ctx.f13.f64, ctx.f10.f64);
	// ble cr6,0x82760a54
	if (!ctx.cr6.gt) goto loc_82760A54;
	// fmr f10,f13
	ctx.f10.f64 = ctx.f13.f64;
	// mr r8,r11
	ctx.r8.u64 = ctx.r11.u64;
loc_82760A54:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// bdnz 0x82760a40
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82760A40;
	// rlwinm. r11,r8,0,30,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0x2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82760a74
	if (ctx.cr0.eq) goto loc_82760A74;
	// fmr f13,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f1.f64;
	// fmr f1,f29
	ctx.f1.f64 = ctx.f29.f64;
	// fmr f29,f13
	ctx.f29.f64 = ctx.f13.f64;
loc_82760A74:
	// clrlwi. r11,r8,31
	ctx.r11.u64 = ctx.r8.u32 & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82760a88
	if (ctx.cr0.eq) goto loc_82760A88;
	// fmr f13,f31
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = ctx.f31.f64;
	// fmr f31,f28
	ctx.f31.f64 = ctx.f28.f64;
	// fmr f28,f13
	ctx.f28.f64 = ctx.f13.f64;
loc_82760A88:
	// lis r11,-32249
	ctx.r11.s64 = -2113470464;
	// lfs f9,-29784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -29784);
	ctx.f9.f64 = double(temp.f32);
	// stfs f9,-288(r1)
	temp.f32 = float(ctx.f9.f64);
	REX_STORE_U32(ctx.r1.u32 + -288, temp.u32);
	// fcmpu cr6,f3,f9
	ctx.cr6.compare(ctx.f3.f64, ctx.f9.f64);
	// blt cr6,0x82760cb4
	if (ctx.cr6.lt) goto loc_82760CB4;
	// addi r8,r6,-1
	ctx.r8.s64 = ctx.r6.s64 + -1;
	// lis r10,-32256
	ctx.r10.s64 = -2113929216;
	// clrldi r11,r8,32
	ctx.r11.u64 = ctx.r8.u64 & 0xFFFFFFFF;
	// lis r9,-32249
	ctx.r9.s64 = -2113470464;
	// std r11,-272(r1)
	REX_STORE_U64(ctx.r1.u32 + -272, ctx.r11.u64);
	// lfd f13,-272(r1)
	ctx.f13.u64 = REX_LOAD_U64(ctx.r1.u32 + -272);
	// fcfid f13,f13
	ctx.f13.f64 = double(ctx.f13.s64);
	// lis r11,-32256
	ctx.r11.s64 = -2113929216;
	// lfs f24,8220(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8220);
	ctx.f24.f64 = double(temp.f32);
	// li r7,0
	ctx.r7.s64 = 0;
	// lfs f23,28312(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28312);
	ctx.f23.f64 = double(temp.f32);
	// frsp f25,f13
	ctx.f25.f64 = double(float(ctx.f13.f64));
	// lfs f22,-29788(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29788);
	ctx.f22.f64 = double(temp.f32);
	// b 0x82760ad8
	goto loc_82760AD8;
loc_82760AD4:
	// lfs f9,-288(r1)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r1.u32 + -288);
	ctx.f9.f64 = double(temp.f32);
loc_82760AD8:
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82760b24
	if (ctx.cr6.eq) goto loc_82760B24;
	// addi r10,r1,-264
	ctx.r10.s64 = ctx.r1.s64 + -264;
	// mtctr r6
	ctx.ctr.u64 = ctx.r6.u64;
	// mr r11,r31
	ctx.r11.u64 = ctx.r31.u64;
	// subf r9,r31,r30
	ctx.r9.u64 = ctx.r30.u64 - ctx.r31.u64;
loc_82760AF0:
	// lfs f13,0(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 0);
	ctx.f13.f64 = double(temp.f32);
	// fmuls f12,f13,f30
	ctx.f12.f64 = double(float(ctx.f13.f64 * ctx.f30.f64));
	// lfsx f11,r9,r11
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	ctx.f11.f64 = double(temp.f32);
	// fmuls f10,f13,f1
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f1.f64));
	// addi r11,r11,4
	ctx.r11.s64 = ctx.r11.s64 + 4;
	// fmuls f13,f13,f31
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f31.f64));
	// fmadds f12,f11,f26,f12
	ctx.f12.f64 = double(float(std::fma(ctx.f11.f64, ctx.f26.f64, ctx.f12.f64)));
	// stfs f12,8(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 8, temp.u32);
	// fmadds f12,f11,f29,f10
	ctx.f12.f64 = double(float(std::fma(ctx.f11.f64, ctx.f29.f64, ctx.f10.f64)));
	// stfs f12,12(r10)
	temp.f32 = float(ctx.f12.f64);
	REX_STORE_U32(ctx.r10.u32 + 12, temp.u32);
	// fmadds f13,f11,f28,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f11.f64, ctx.f28.f64, ctx.f13.f64)));
	// stfsu f13,16(r10)
	ea = 16 + ctx.r10.u32;
	temp.f32 = float(ctx.f13.f64);
	REX_STORE_U32(ea, temp.u32);
	ctx.r10.u32 = ea;
	// bdnz 0x82760af0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82760AF0;
loc_82760B24:
	// fsubs f13,f29,f1
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f29.f64 - ctx.f1.f64));
	// fsubs f12,f28,f31
	ctx.f12.f64 = double(float(ctx.f28.f64 - ctx.f31.f64));
	// fsubs f11,f26,f30
	ctx.f11.f64 = double(float(ctx.f26.f64 - ctx.f30.f64));
	// fmuls f10,f13,f13
	ctx.f10.f64 = double(float(ctx.f13.f64 * ctx.f13.f64));
	// fmadds f10,f12,f12,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f12.f64, ctx.f12.f64, ctx.f10.f64)));
	// fmadds f10,f11,f11,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f11.f64, ctx.f11.f64, ctx.f10.f64)));
	// fcmpu cr6,f10,f9
	ctx.cr6.compare(ctx.f10.f64, ctx.f9.f64);
	// blt cr6,0x82760cb4
	if (ctx.cr6.lt) goto loc_82760CB4;
	// fdivs f21,f25,f10
	ctx.f21.f64 = double(float(ctx.f25.f64 / ctx.f10.f64));
	// li r10,16
	ctx.r10.s64 = 16;
	// fmr f3,f0
	ctx.f3.f64 = ctx.f0.f64;
	// addi r11,r5,-16
	ctx.r11.s64 = ctx.r5.s64 + -16;
	// fmr f4,f0
	ctx.f4.f64 = ctx.f0.f64;
	// fmr f5,f0
	ctx.f5.f64 = ctx.f0.f64;
	// fmr f6,f0
	ctx.f6.f64 = ctx.f0.f64;
	// fmr f7,f0
	ctx.f7.f64 = ctx.f0.f64;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// fmr f8,f0
	ctx.f8.f64 = ctx.f0.f64;
	// fmr f9,f0
	ctx.f9.f64 = ctx.f0.f64;
	// fmr f10,f0
	ctx.f10.f64 = ctx.f0.f64;
	// fmuls f11,f21,f11
	ctx.f11.f64 = double(float(ctx.f21.f64 * ctx.f11.f64));
	// fmuls f2,f21,f13
	ctx.f2.f64 = double(float(ctx.f21.f64 * ctx.f13.f64));
	// fmuls f12,f21,f12
	ctx.f12.f64 = double(float(ctx.f21.f64 * ctx.f12.f64));
loc_82760B80:
	// lfs f13,12(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f13,f13,f1
	ctx.f13.f64 = double(float(ctx.f13.f64 - ctx.f1.f64));
	// lfs f21,16(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 16);
	ctx.f21.f64 = double(temp.f32);
	// fsubs f21,f21,f31
	ctx.f21.f64 = double(float(ctx.f21.f64 - ctx.f31.f64));
	// lfs f20,8(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f20.f64 = double(temp.f32);
	// fsubs f20,f20,f30
	ctx.f20.f64 = double(float(ctx.f20.f64 - ctx.f30.f64));
	// fmuls f13,f13,f2
	ctx.f13.f64 = double(float(ctx.f13.f64 * ctx.f2.f64));
	// fmadds f13,f21,f12,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f21.f64, ctx.f12.f64, ctx.f13.f64)));
	// fmadds f13,f20,f11,f13
	ctx.f13.f64 = double(float(std::fma(ctx.f20.f64, ctx.f11.f64, ctx.f13.f64)));
	// fcmpu cr6,f13,f25
	ctx.cr6.compare(ctx.f13.f64, ctx.f25.f64);
	// blt cr6,0x82760bb4
	if (ctx.cr6.lt) goto loc_82760BB4;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// b 0x82760bc4
	goto loc_82760BC4;
loc_82760BB4:
	// fadds f13,f13,f27
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f13.f64 + ctx.f27.f64));
	// fctiwz f13,f13
	ctx.f13.s64 = std::isnan(ctx.f13.f64) ? int64_t(0x80000000U) : (ctx.f13.f64 >= double(INT_MAX)) ? INT_MAX : simde_mm_cvttsd_si32(simde_mm_load_sd(&ctx.f13.f64));
	// stfd f13,-272(r1)
	REX_STORE_U64(ctx.r1.u32 + -272, ctx.f13.u64);
	// lwz r10,-268(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + -268);
loc_82760BC4:
	// rlwinm r9,r10,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 4) & 0xFFFFFFF0;
	// lfs f21,8(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8);
	ctx.f21.f64 = double(temp.f32);
	// addi r29,r1,-256
	ctx.r29.s64 = ctx.r1.s64 + -256;
	// lfs f20,12(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12);
	ctx.f20.f64 = double(temp.f32);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lfsu f13,16(r11)
	ea = 16 + ctx.r11.u32;
	temp.u32 = REX_LOAD_U32(ea);
	ctx.f13.f64 = double(temp.f32);
	ctx.r11.u32 = ea;
	// addi r28,r1,-252
	ctx.r28.s64 = ctx.r1.s64 + -252;
	// addi r27,r1,-248
	ctx.r27.s64 = ctx.r1.s64 + -248;
	// lfsx f16,r9,r29
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r29.u32);
	ctx.f16.f64 = double(temp.f32);
	// fsubs f21,f16,f21
	ctx.f21.f64 = double(float(ctx.f16.f64 - ctx.f21.f64));
	// lfsx f19,r10,r31
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	ctx.f19.f64 = double(temp.f32);
	// lfsx f18,r10,r30
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + ctx.r30.u32);
	ctx.f18.f64 = double(temp.f32);
	// fmuls f17,f19,f23
	ctx.f17.f64 = double(float(ctx.f19.f64 * ctx.f23.f64));
	// lfsx f14,r9,r28
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r28.u32);
	ctx.f14.f64 = double(temp.f32);
	// fmuls f15,f18,f23
	ctx.f15.f64 = double(float(ctx.f18.f64 * ctx.f23.f64));
	// lfsx f16,r9,r27
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + ctx.r27.u32);
	ctx.f16.f64 = double(temp.f32);
	// fsubs f20,f14,f20
	ctx.f20.f64 = double(float(ctx.f14.f64 - ctx.f20.f64));
	// fsubs f13,f16,f13
	ctx.f13.f64 = double(float(ctx.f16.f64 - ctx.f13.f64));
	// fmadds f10,f19,f17,f10
	ctx.f10.f64 = double(float(std::fma(ctx.f19.f64, ctx.f17.f64, ctx.f10.f64)));
	// fmadds f9,f18,f15,f9
	ctx.f9.f64 = double(float(std::fma(ctx.f18.f64, ctx.f15.f64, ctx.f9.f64)));
	// fmadds f8,f17,f21,f8
	ctx.f8.f64 = double(float(std::fma(ctx.f17.f64, ctx.f21.f64, ctx.f8.f64)));
	// fmadds f7,f17,f20,f7
	ctx.f7.f64 = double(float(std::fma(ctx.f17.f64, ctx.f20.f64, ctx.f7.f64)));
	// fmadds f6,f17,f13,f6
	ctx.f6.f64 = double(float(std::fma(ctx.f17.f64, ctx.f13.f64, ctx.f6.f64)));
	// fmadds f5,f15,f21,f5
	ctx.f5.f64 = double(float(std::fma(ctx.f15.f64, ctx.f21.f64, ctx.f5.f64)));
	// fmadds f4,f15,f20,f4
	ctx.f4.f64 = double(float(std::fma(ctx.f15.f64, ctx.f20.f64, ctx.f4.f64)));
	// fmadds f3,f15,f13,f3
	ctx.f3.f64 = double(float(std::fma(ctx.f15.f64, ctx.f13.f64, ctx.f3.f64)));
	// bdnz 0x82760b80
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82760B80;
	// fcmpu cr6,f10,f0
	ctx.cr6.compare(ctx.f10.f64, ctx.f0.f64);
	// ble cr6,0x82760c48
	if (!ctx.cr6.gt) goto loc_82760C48;
	// fdivs f13,f24,f10
	ctx.f13.f64 = double(float(ctx.f24.f64 / ctx.f10.f64));
	// fmadds f30,f13,f8,f30
	ctx.f30.f64 = double(float(std::fma(ctx.f13.f64, ctx.f8.f64, ctx.f30.f64)));
	// fmadds f1,f13,f7,f1
	ctx.f1.f64 = double(float(std::fma(ctx.f13.f64, ctx.f7.f64, ctx.f1.f64)));
	// fmadds f31,f13,f6,f31
	ctx.f31.f64 = double(float(std::fma(ctx.f13.f64, ctx.f6.f64, ctx.f31.f64)));
loc_82760C48:
	// fcmpu cr6,f9,f0
	ctx.fpscr.disableFlushMode();
	ctx.cr6.compare(ctx.f9.f64, ctx.f0.f64);
	// ble cr6,0x82760c60
	if (!ctx.cr6.gt) goto loc_82760C60;
	// fdivs f13,f24,f9
	ctx.f13.f64 = double(float(ctx.f24.f64 / ctx.f9.f64));
	// fmadds f26,f13,f5,f26
	ctx.f26.f64 = double(float(std::fma(ctx.f13.f64, ctx.f5.f64, ctx.f26.f64)));
	// fmadds f29,f13,f4,f29
	ctx.f29.f64 = double(float(std::fma(ctx.f13.f64, ctx.f4.f64, ctx.f29.f64)));
	// fmadds f28,f13,f3,f28
	ctx.f28.f64 = double(float(std::fma(ctx.f13.f64, ctx.f3.f64, ctx.f28.f64)));
loc_82760C60:
	// fmuls f13,f8,f8
	ctx.fpscr.disableFlushMode();
	ctx.f13.f64 = double(float(ctx.f8.f64 * ctx.f8.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x82760ca8
	if (!ctx.cr6.lt) goto loc_82760CA8;
	// fmuls f13,f7,f7
	ctx.f13.f64 = double(float(ctx.f7.f64 * ctx.f7.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x82760ca8
	if (!ctx.cr6.lt) goto loc_82760CA8;
	// fmuls f13,f6,f6
	ctx.f13.f64 = double(float(ctx.f6.f64 * ctx.f6.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x82760ca8
	if (!ctx.cr6.lt) goto loc_82760CA8;
	// fmuls f13,f5,f5
	ctx.f13.f64 = double(float(ctx.f5.f64 * ctx.f5.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x82760ca8
	if (!ctx.cr6.lt) goto loc_82760CA8;
	// fmuls f13,f4,f4
	ctx.f13.f64 = double(float(ctx.f4.f64 * ctx.f4.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// bge cr6,0x82760ca8
	if (!ctx.cr6.lt) goto loc_82760CA8;
	// fmuls f13,f3,f3
	ctx.f13.f64 = double(float(ctx.f3.f64 * ctx.f3.f64));
	// fcmpu cr6,f13,f22
	ctx.cr6.compare(ctx.f13.f64, ctx.f22.f64);
	// blt cr6,0x82760cb4
	if (ctx.cr6.lt) goto loc_82760CB4;
loc_82760CA8:
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// cmplwi cr6,r7,8
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 8, ctx.xer);
	// blt cr6,0x82760ad4
	if (ctx.cr6.lt) goto loc_82760AD4;
loc_82760CB4:
	// stfs f30,0(r3)
	ctx.fpscr.disableFlushMode();
	temp.f32 = float(ctx.f30.f64);
	REX_STORE_U32(ctx.r3.u32 + 0, temp.u32);
	// stfs f1,4(r3)
	temp.f32 = float(ctx.f1.f64);
	REX_STORE_U32(ctx.r3.u32 + 4, temp.u32);
	// stfs f31,8(r3)
	temp.f32 = float(ctx.f31.f64);
	REX_STORE_U32(ctx.r3.u32 + 8, temp.u32);
	// stfs f26,0(r4)
	temp.f32 = float(ctx.f26.f64);
	REX_STORE_U32(ctx.r4.u32 + 0, temp.u32);
	// stfs f29,4(r4)
	temp.f32 = float(ctx.f29.f64);
	REX_STORE_U32(ctx.r4.u32 + 4, temp.u32);
	// stfs f28,8(r4)
	temp.f32 = float(ctx.f28.f64);
	REX_STORE_U32(ctx.r4.u32 + 8, temp.u32);
	// addi r12,r1,-48
	ctx.r12.s64 = ctx.r1.s64 + -48;
	// bl 0x8273af3c
	ctx.lr = 0x82760CD4;
	__restfpr_14(ctx, base);
	// b 0x82739f64
	__restgprlr_27(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8277F268) {
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
	// lwz r11,288(r4)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r4.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x8277f2b4
	if (!ctx.cr0.eq) goto loc_8277F2B4;
	// lwz r11,60(r5)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r5.u32 + 60);
	// li r10,4
	ctx.r10.s64 = 4;
	// sth r6,85(r1)
	REX_STORE_U16(ctx.r1.u32 + 85, ctx.r6.u16);
	// li r9,11
	ctx.r9.s64 = 11;
	// stw r7,87(r1)
	REX_STORE_U32(ctx.r1.u32 + 87, ctx.r7.u32);
	// li r8,0
	ctx.r8.s64 = 0;
	// stb r10,80(r1)
	REX_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// li r7,0
	ctx.r7.s64 = 0;
	// li r6,11
	ctx.r6.s64 = 11;
	// stw r11,81(r1)
	REX_STORE_U32(ctx.r1.u32 + 81, ctx.r11.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// bl 0x8277e648
	ctx.lr = 0x8277F2B0;
	sub_8277E648(ctx, base);
	// b 0x8277f2b8
	goto loc_8277F2B8;
loc_8277F2B4:
	// li r3,0
	ctx.r3.s64 = 0;
loc_8277F2B8:
	// addi r1,r1,112
	ctx.r1.s64 = ctx.r1.s64 + 112;
	// lwz r12,-8(r1)
	ctx.r12.u64 = REX_LOAD_U32(ctx.r1.u32 + -8);
	// mtlr r12
	ctx.lr = ctx.r12.u64;
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82781E48) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f04
	ctx.lr = 0x82781E50;
	__savegprlr_23(ctx, base);
	// stwu r1,-160(r1)
	ea = -160 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// li r24,0
	ctx.r24.s64 = 0;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// bge cr6,0x82781e74
	if (!ctx.cr6.lt) goto loc_82781E74;
loc_82781E68:
	// lis r29,-32646
	ctx.r29.s64 = -2139488256;
	// ori r29,r29,4106
	ctx.r29.u64 = ctx.r29.u64 | 4106;
	// b 0x8278208c
	goto loc_8278208C;
loc_82781E74:
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// addi r23,r5,1
	ctx.r23.s64 = ctx.r5.s64 + 1;
	// addi r26,r6,-1
	ctx.r26.s64 = ctx.r6.s64 + -1;
	// rlwinm. r25,r11,3,31,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0x1;
	ctx.cr0.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq 0x82781fe0
	if (ctx.cr0.eq) goto loc_82781FE0;
	// lwz r11,284(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 284);
	// cmplw cr6,r26,r11
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, ctx.r11.u32, ctx.xer);
	// bne cr6,0x82781e68
	if (!ctx.cr6.eq) goto loc_82781E68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82784c60
	ctx.lr = 0x82781E9C;
	sub_82784C60(ctx, base);
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,2,2
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x20000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82781f70
	if (ctx.cr0.eq) goto loc_82781F70;
	// lwz r11,156(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 156);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82781f34
	if (ctx.cr6.eq) goto loc_82781F34;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r11,156(r30)
	REX_STORE_U32(ctx.r30.u32 + 156, ctx.r11.u32);
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// clrlwi r11,r11,1
	ctx.r11.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// lwz r10,148(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 148);
	// lwz r11,196(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 196);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,196(r30)
	REX_STORE_U32(ctx.r30.u32 + 196, ctx.r11.u32);
	// bne cr6,0x82781fe0
	if (!ctx.cr6.eq) goto loc_82781FE0;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82781ef4
	if (!ctx.cr6.eq) goto loc_82781EF4;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x827805e8
	ctx.lr = 0x82781EF0;
	sub_827805E8(ctx, base);
	// b 0x82781f28
	goto loc_82781F28;
loc_82781EF4:
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,9,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82781f10
	if (ctx.cr0.eq) goto loc_82781F10;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82776690
	ctx.lr = 0x82781F10;
	sub_82776690(ctx, base);
loc_82781F10:
	// lwz r11,196(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 196);
	// lwz r10,200(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 200);
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// bne cr6,0x82781fe0
	if (!ctx.cr6.eq) goto loc_82781FE0;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x8277d790
	ctx.lr = 0x82781F28;
	sub_8277D790(ctx, base);
loc_82781F28:
	// mr. r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne 0x8278208c
	if (!ctx.cr0.eq) goto loc_8278208C;
	// b 0x82781fe0
	goto loc_82781FE0;
loc_82781F34:
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
	// bne 0x82781f34
	if (!ctx.cr0.eq) goto loc_82781F34;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// li r5,10000
	ctx.r5.s64 = 10000;
	// li r4,-1
	ctx.r4.s64 = -1;
	// oris r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 | 2097152;
	// addi r3,r31,96
	ctx.r3.s64 = ctx.r31.s64 + 96;
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// bl 0x82784e88
	ctx.lr = 0x82781F6C;
	sub_82784E88(ctx, base);
	// b 0x82781fe0
	goto loc_82781FE0;
loc_82781F70:
	// lwz r4,64(r31)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r31.u32 + 64);
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82781fe0
	if (ctx.cr6.eq) goto loc_82781FE0;
	// addi r28,r30,8
	ctx.r28.s64 = ctx.r30.s64 + 8;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x827865b0
	ctx.lr = 0x82781F88;
	sub_827865B0(ctx, base);
	// mr. r27,r3
	ctx.r27.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq 0x82781e68
	if (ctx.cr0.eq) goto loc_82781E68;
	// lwz r11,396(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 396);
	// rlwinm. r11,r11,0,9,9
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x400000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82781fb8
	if (ctx.cr0.eq) goto loc_82781FB8;
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// rlwinm. r11,r11,0,6,6
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x2000000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82781fb8
	if (!ctx.cr0.eq) goto loc_82781FB8;
	// li r5,1
	ctx.r5.s64 = 1;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82776690
	ctx.lr = 0x82781FB8;
	sub_82776690(ctx, base);
loc_82781FB8:
	// li r5,0
	ctx.r5.s64 = 0;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82787510
	ctx.lr = 0x82781FC8;
	sub_82787510(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82786970
	ctx.lr = 0x82781FD8;
	sub_82786970(ctx, base);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x8278208c
	if (!ctx.cr6.eq) goto loc_8278208C;
loc_82781FE0:
	// cmplwi cr6,r26,0
	ctx.cr6.compare<uint32_t>(ctx.r26.u32, 0, ctx.xer);
	// beq cr6,0x8278200c
	if (ctx.cr6.eq) goto loc_8278200C;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r23
	ctx.r4.u64 = ctx.r23.u64;
	// li r3,257
	ctx.r3.s64 = 257;
	// bl 0x82778158
	ctx.lr = 0x82781FF8;
	sub_82778158(ctx, base);
	// mr. r24,r3
	ctx.r24.u64 = ctx.r3.u64;
	ctx.cr0.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne 0x8278200c
	if (!ctx.cr0.eq) goto loc_8278200C;
	// lis r29,-32761
	ctx.r29.s64 = -2147024896;
	// ori r29,r29,14
	ctx.r29.u64 = ctx.r29.u64 | 14;
	// b 0x82782054
	goto loc_82782054;
loc_8278200C:
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82779528
	ctx.lr = 0x82782018;
	sub_82779528(ctx, base);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// beq cr6,0x82782030
	if (ctx.cr6.eq) goto loc_82782030;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82779490
	ctx.lr = 0x8278202C;
	sub_82779490(ctx, base);
	// b 0x82782050
	goto loc_82782050;
loc_82782030:
	// lwz r11,288(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 288);
	// oris r11,r11,64
	ctx.r11.u64 = ctx.r11.u64 | 4194304;
	// rlwinm. r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,288(r31)
	REX_STORE_U32(ctx.r31.u32 + 288, ctx.r11.u32);
	// bne 0x82782050
	if (!ctx.cr0.eq) goto loc_82782050;
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x82777820
	ctx.lr = 0x82782050;
	sub_82777820(ctx, base);
loc_82782050:
	// li r29,0
	ctx.r29.s64 = 0;
loc_82782054:
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x8278208c
	if (ctx.cr6.eq) goto loc_8278208C;
loc_8278205C:
	// mfmsr r10
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.r10.u64 = REX_CHECK_GLOBAL_LOCK();
	// mtmsrd r13,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r13.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_ENTER_GLOBAL_LOCK();
	// lwarx r11,0,r24
	ea = ctx.r24.u32;
	ctx.reserved.u32 = *(uint32_t*)REX_RAW_ADDR(ea);
	ctx.r11.u64 = __builtin_bswap32(ctx.reserved.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stwcx. r11,0,r24
	ea = ctx.r24.u32;
	ctx.cr0.lt = 0;
	ctx.cr0.gt = 0;
	ctx.cr0.eq = __sync_bool_compare_and_swap(reinterpret_cast<uint32_t*>(REX_RAW_ADDR(ea)), ctx.reserved.s32, __builtin_bswap32(ctx.r11.s32));
	ctx.cr0.so = ctx.xer.so;
	// mtmsrd r10,1
	std::atomic_thread_fence(std::memory_order_seq_cst);
	ctx.msr = (ctx.r10.u32 & 0x8020) | (ctx.msr & ~0x8020);
	REX_LEAVE_GLOBAL_LOCK();
	// bne 0x8278205c
	if (!ctx.cr0.eq) goto loc_8278205C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x8278208c
	if (!ctx.cr6.eq) goto loc_8278208C;
	// mr r4,r24
	ctx.r4.u64 = ctx.r24.u64;
	// lwz r3,4(r24)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r24.u32 + 4);
	// bl 0x82772060
	ctx.lr = 0x8278208C;
	sub_82772060(ctx, base);
loc_8278208C:
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// addi r1,r1,160
	ctx.r1.s64 = ctx.r1.s64 + 160;
	// b 0x82739f54
	__restgprlr_23(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_8278E648) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739f1c
	ctx.lr = 0x8278E650;
	__savegprlr_29(ctx, base);
	// stwu r1,-128(r1)
	ea = -128 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// bl 0x82748820
	ctx.lr = 0x8278E660;
	sub_82748820(ctx, base);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// addi r3,r31,688
	ctx.r3.s64 = ctx.r31.s64 + 688;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// subf r4,r29,r30
	ctx.r4.u64 = ctx.r30.u64 - ctx.r29.u64;
	// bl 0x82796f10
	ctx.lr = 0x8278E674;
	sub_82796F10(ctx, base);
	// stw r30,472(r31)
	REX_STORE_U32(ctx.r31.u32 + 472, ctx.r30.u32);
	// stw r30,468(r31)
	REX_STORE_U32(ctx.r31.u32 + 468, ctx.r30.u32);
	// addi r5,r1,80
	ctx.r5.s64 = ctx.r1.s64 + 80;
	// stw r30,1064(r31)
	REX_STORE_U32(ctx.r31.u32 + 1064, ctx.r30.u32);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x8278d680
	ctx.lr = 0x8278E690;
	sub_8278D680(ctx, base);
	// cmpwi r3,0
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq 0x8278e6a8
	if (ctx.cr0.eq) goto loc_8278E6A8;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// lwz r4,80(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r3,r31,364
	ctx.r3.s64 = ctx.r31.s64 + 364;
	// bl 0x82795b30
	ctx.lr = 0x8278E6A8;
	sub_82795B30(ctx, base);
loc_8278E6A8:
	// li r10,1
	ctx.r10.s64 = 1;
	// lbz r11,1184(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 1184);
	// lwz r9,1188(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 1188);
	// li r8,250
	ctx.r8.s64 = 250;
	// stw r10,20(r31)
	REX_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// andi. r11,r11,250
	ctx.r11.u64 = ctx.r11.u64 & 250;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// oris r10,r9,1024
	ctx.r10.u64 = ctx.r9.u64 | 67108864;
	// stb r8,1185(r31)
	REX_STORE_U8(ctx.r31.u32 + 1185, ctx.r8.u8);
	// stb r11,1184(r31)
	REX_STORE_U8(ctx.r31.u32 + 1184, ctx.r11.u8);
	// addi r3,r31,184
	ctx.r3.s64 = ctx.r31.s64 + 184;
	// stw r10,1188(r31)
	REX_STORE_U32(ctx.r31.u32 + 1188, ctx.r10.u32);
	// bl 0x82795bd0
	ctx.lr = 0x8278E6D8;
	sub_82795BD0(ctx, base);
	// addi r1,r1,128
	ctx.r1.s64 = ctx.r1.s64 + 128;
	// b 0x82739f6c
	__restgprlr_29(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827930F8) {
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
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// addi r30,r11,-2988
	ctx.r30.s64 = ctx.r11.s64 + -2988;
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// bl 0x82855b44
	ctx.lr = 0x82793120;
	__imp__RtlEnterCriticalSection(ctx, base);
	// lwz r10,32(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// lwz r9,36(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// addi r11,r31,32
	ctx.r11.s64 = ctx.r31.s64 + 32;
	// addi r3,r30,8
	ctx.r3.s64 = ctx.r30.s64 + 8;
	// stw r9,4(r10)
	REX_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// lwz r10,36(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 36);
	// lwz r9,32(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 32);
	// stw r9,0(r10)
	REX_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r11,32(r31)
	REX_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// stw r11,36(r31)
	REX_STORE_U32(ctx.r31.u32 + 36, ctx.r11.u32);
	// bl 0x82855b34
	ctx.lr = 0x8279314C;
	__imp__RtlLeaveCriticalSection(ctx, base);
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

DEFINE_REX_FUNC(sub_82794DA0) {
	REX_FUNC_PROLOGUE();
	// lwz r3,28(r3)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// b 0x82793b98
	sub_82793B98(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_82794F80) {
	REX_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x82794F88;
	__savegprlr_14(ctx, base);
	// stwu r1,-416(r1)
	ea = -416 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lwz r11,56(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 56);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// sth r4,446(r1)
	REX_STORE_U16(ctx.r1.u32 + 446, ctx.r4.u16);
	// mr r21,r7
	ctx.r21.u64 = ctx.r7.u64;
	// sth r5,454(r1)
	REX_STORE_U16(ctx.r1.u32 + 454, ctx.r5.u16);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// stw r6,460(r1)
	REX_STORE_U32(ctx.r1.u32 + 460, ctx.r6.u32);
	// stw r7,468(r1)
	REX_STORE_U32(ctx.r1.u32 + 468, ctx.r7.u32);
	// ble cr6,0x82794fc8
	if (!ctx.cr6.gt) goto loc_82794FC8;
	// lwz r11,28(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 28);
	// lwz r10,24(r3)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r3.u32 + 24);
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// subf r4,r10,r11
	ctx.r4.u64 = ctx.r11.u64 - ctx.r10.u64;
	// b 0x8279536c
	goto loc_8279536C;
loc_82794FC8:
	// li r29,0
	ctx.r29.s64 = 0;
	// lhz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 328);
	// mr r25,r29
	ctx.r25.u64 = ctx.r29.u64;
	// stw r29,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r29.u32);
	// mr r16,r29
	ctx.r16.u64 = ctx.r29.u64;
	// stw r29,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r29.u32);
	// mr r28,r29
	ctx.r28.u64 = ctx.r29.u64;
	// mr r17,r29
	ctx.r17.u64 = ctx.r29.u64;
	// mr r15,r29
	ctx.r15.u64 = ctx.r29.u64;
	// mr r14,r29
	ctx.r14.u64 = ctx.r29.u64;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82795360
	if (ctx.cr0.eq) goto loc_82795360;
	// addi r18,r1,128
	ctx.r18.s64 = ctx.r1.s64 + 128;
	// addi r24,r30,78
	ctx.r24.s64 = ctx.r30.s64 + 78;
	// addi r31,r21,18
	ctx.r31.s64 = ctx.r21.s64 + 18;
loc_82795004:
	// lwz r10,36(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// addi r19,r29,1
	ctx.r19.s64 = ctx.r29.s64 + 1;
	// lhz r9,328(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 328);
	// addi r20,r24,-6
	ctx.r20.s64 = ctx.r24.s64 + -6;
	// lhz r11,-2(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + -2);
	// cmplw cr6,r19,r9
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r9.u32, ctx.xer);
	// add r22,r11,r10
	ctx.r22.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bge cr6,0x8279502c
	if (!ctx.cr6.lt) goto loc_8279502C;
	// lhz r10,12(r20)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r20.u32 + 12);
	// b 0x82795030
	goto loc_82795030;
loc_8279502C:
	// lwz r10,32(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
loc_82795030:
	// addi r26,r31,-18
	ctx.r26.s64 = ctx.r31.s64 + -18;
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// stw r26,0(r18)
	REX_STORE_U32(ctx.r18.u32 + 0, ctx.r26.u32);
	// lis r6,255
	ctx.r6.s64 = 16711680;
	// mr r8,r29
	ctx.r8.u64 = ctx.r29.u64;
	// addi r7,r1,128
	ctx.r7.s64 = ctx.r1.s64 + 128;
	// ori r6,r6,65535
	ctx.r6.u64 = ctx.r6.u64 | 65535;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x8279a128
	ctx.lr = 0x8279505C;
	sub_8279A128(ctx, base);
	// lhz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// mr r23,r3
	ctx.r23.u64 = ctx.r3.u64;
	// rlwinm. r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne 0x827950e0
	if (!ctx.cr0.eq) goto loc_827950E0;
	// lwz r11,0(r20)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x827950a4
	if (ctx.cr6.eq) goto loc_827950A4;
	// rotlwi r3,r11,0
	ctx.r3.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r4,-32646
	ctx.r4.s64 = -2139488256;
	// ori r4,r4,4108
	ctx.r4.u64 = ctx.r4.u64 | 4108;
	// lwz r11,0(r3)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r3.u32 + 0);
	// lwz r11,8(r11)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r11.u32 + 8);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82795094;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r11,330(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 330);
	// addis r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 65536;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sth r11,330(r30)
	REX_STORE_U16(ctx.r30.u32 + 330, ctx.r11.u16);
loc_827950A4:
	// lhz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// rlwinm. r11,r11,0,17,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827950c4
	if (ctx.cr0.eq) goto loc_827950C4;
	// clrlwi r11,r15,24
	ctx.r11.u64 = ctx.r15.u32 & 0xFF;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// clrlwi r15,r11,24
	ctx.r15.u64 = ctx.r11.u32 & 0xFF;
	// stb r15,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r15.u8);
	// b 0x82795264
	goto loc_82795264;
loc_827950C4:
	// clrlwi r11,r17,24
	ctx.r11.u64 = ctx.r17.u32 & 0xFF;
	// addi r10,r25,1
	ctx.r10.s64 = ctx.r25.s64 + 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// clrlwi r17,r11,24
	ctx.r17.u64 = ctx.r11.u32 & 0xFF;
	// stb r17,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r17.u8);
	// b 0x82795260
	goto loc_82795260;
loc_827950E0:
	// rlwinm. r11,r11,0,17,17
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827950f0
	if (ctx.cr0.eq) goto loc_827950F0;
	// stb r15,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r15.u8);
	// b 0x82795108
	goto loc_82795108;
loc_827950F0:
	// lwz r11,100(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r25,1
	ctx.r10.s64 = ctx.r25.s64 + 1;
	// stb r17,0(r31)
	REX_STORE_U8(ctx.r31.u32 + 0, ctx.r17.u8);
	// add r11,r27,r11
	ctx.r11.u64 = ctx.r27.u64 + ctx.r11.u64;
	// stw r10,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_82795108:
	// lhz r11,0(r24)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// rlwinm. r11,r11,0,19,19
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x1000;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82795170
	if (ctx.cr0.eq) goto loc_82795170;
	// lbz r11,-3(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -3);
	// lhz r5,-10(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + -10);
	// lwz r4,0(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bne cr6,0x82795144
	if (!ctx.cr6.eq) goto loc_82795144;
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// bl 0x8279a3e8
	ctx.lr = 0x82795130;
	sub_8279A3E8(ctx, base);
	// addi r3,r1,116
	ctx.r3.s64 = ctx.r1.s64 + 116;
	// li r21,7
	ctx.r21.s64 = 7;
	// bl 0x8279a420
	ctx.lr = 0x8279513C;
	sub_8279A420(ctx, base);
	// sth r3,-6(r31)
	REX_STORE_U16(ctx.r31.u32 + -6, ctx.r3.u16);
	// b 0x8279515c
	goto loc_8279515C;
loc_82795144:
	// addi r3,r1,108
	ctx.r3.s64 = ctx.r1.s64 + 108;
	// bl 0x8279a3c8
	ctx.lr = 0x8279514C;
	sub_8279A3C8(ctx, base);
	// lwz r11,108(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// li r21,0
	ctx.r21.s64 = 0;
	// lhz r11,0(r11)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// sth r11,-6(r31)
	REX_STORE_U16(ctx.r31.u32 + -6, ctx.r11.u16);
loc_8279515C:
	// lbz r11,-4(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + -4);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// ori r11,r11,8
	ctx.r11.u64 = ctx.r11.u64 | 8;
	// stb r11,-4(r31)
	REX_STORE_U8(ctx.r31.u32 + -4, ctx.r11.u8);
	// b 0x82795174
	goto loc_82795174;
loc_82795170:
	// li r21,0
	ctx.r21.s64 = 0;
loc_82795174:
	// clrlwi r25,r28,16
	ctx.r25.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplw cr6,r29,r25
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r25.u32, ctx.xer);
	// beq cr6,0x82795240
	if (ctx.cr6.eq) goto loc_82795240;
	// lhz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// lwz r11,36(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// rlwinm. r10,r10,0,18,18
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x2000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r28,r16,r11
	ctx.r28.u64 = ctx.r16.u64 + ctx.r11.u64;
	// beq 0x82795208
	if (ctx.cr0.eq) goto loc_82795208;
	// lhz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 328);
	// li r7,0
	ctx.r7.s64 = 0;
	// lhz r3,-8(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + -8);
	// li r6,1
	ctx.r6.s64 = 1;
	// subf r11,r19,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r19.u64;
	// lhz r9,-10(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + -10);
	// li r5,1
	ctx.r5.s64 = 1;
	// lwz r10,-14(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + -14);
	// cntlzw r11,r11
	ctx.r11.u64 = ctx.r11.u32 == 0 ? 32 : __builtin_clz(ctx.r11.u32);
	// lbz r4,-3(r31)
	ctx.r4.u64 = REX_LOAD_U8(ctx.r31.u32 + -3);
	// sth r3,86(r1)
	REX_STORE_U16(ctx.r1.u32 + 86, ctx.r3.u16);
	// rlwinm r8,r11,27,31,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x1;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82799fb0
	ctx.lr = 0x827951CC;
	sub_82799FB0(ctx, base);
	// lhz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// subf r11,r23,r3
	ctx.r11.u64 = ctx.r3.u64 - ctx.r23.u64;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// rlwinm. r10,r10,0,17,17
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x4000;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// bne 0x827951f0
	if (!ctx.cr0.eq) goto loc_827951F0;
	// lwz r10,100(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
loc_827951F0:
	// add r3,r29,r28
	ctx.r3.u64 = ctx.r29.u64 + ctx.r28.u64;
	// lhz r5,-10(r31)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r31.u32 + -10);
	// lwz r4,0(r26)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r26.u32 + 0);
	// bl 0x8273ad00
	ctx.lr = 0x82795200;
	sub_8273AD00(ctx, base);
	// mr r23,r29
	ctx.r23.u64 = ctx.r29.u64;
	// b 0x82795218
	goto loc_82795218;
loc_82795208:
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r22
	ctx.r4.u64 = ctx.r22.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x8273ad00
	ctx.lr = 0x82795218;
	sub_8273AD00(ctx, base);
loc_82795218:
	// addi r10,r25,9
	ctx.r10.s64 = ctx.r25.s64 + 9;
	// lwz r9,0(r20)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r20.u32 + 0);
	// rlwinm r11,r25,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// stwx r9,r10,r30
	REX_STORE_U32(ctx.r10.u32 + ctx.r30.u32, ctx.r9.u32);
	// sth r16,76(r11)
	REX_STORE_U16(ctx.r11.u32 + 76, ctx.r16.u16);
	// lhz r10,0(r24)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r24.u32 + 0);
	// andi. r10,r10,57343
	ctx.r10.u64 = ctx.r10.u64 & 57343;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sth r10,78(r11)
	REX_STORE_U16(ctx.r11.u32 + 78, ctx.r10.u16);
loc_82795240:
	// clrlwi r11,r21,16
	ctx.r11.u64 = ctx.r21.u32 & 0xFFFF;
	// lwz r21,468(r1)
	ctx.r21.u64 = REX_LOAD_U32(ctx.r1.u32 + 468);
	// addi r10,r25,1
	ctx.r10.s64 = ctx.r25.s64 + 1;
	// add r11,r11,r23
	ctx.r11.u64 = ctx.r11.u64 + ctx.r23.u64;
	// clrlwi r28,r10,16
	ctx.r28.u64 = ctx.r10.u32 & 0xFFFF;
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// add r16,r27,r16
	ctx.r16.u64 = ctx.r27.u64 + ctx.r16.u64;
	// sth r11,-2(r31)
	REX_STORE_U16(ctx.r31.u32 + -2, ctx.r11.u16);
loc_82795260:
	// lwz r25,104(r1)
	ctx.r25.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
loc_82795264:
	// lhz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 328);
	// mr r29,r19
	ctx.r29.u64 = ctx.r19.u64;
	// addi r18,r18,4
	ctx.r18.s64 = ctx.r18.s64 + 4;
	// addi r24,r24,8
	ctx.r24.s64 = ctx.r24.s64 + 8;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x82795004
	if (ctx.cr6.lt) goto loc_82795004;
	// cmplwi cr6,r14,0
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 0, ctx.xer);
	// beq cr6,0x82795360
	if (ctx.cr6.eq) goto loc_82795360;
	// clrlwi r11,r28,16
	ctx.r11.u64 = ctx.r28.u32 & 0xFFFF;
	// cmplw cr6,r19,r11
	ctx.cr6.compare<uint32_t>(ctx.r19.u32, ctx.r11.u32, ctx.xer);
	// beq cr6,0x82795360
	if (ctx.cr6.eq) goto loc_82795360;
	// lhz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 328);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi r11,0
	ctx.cr0.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq 0x82795360
	if (ctx.cr0.eq) goto loc_82795360;
	// addi r31,r21,12
	ctx.r31.s64 = ctx.r21.s64 + 12;
loc_827952A8:
	// lbz r11,2(r31)
	ctx.r11.u64 = REX_LOAD_U8(ctx.r31.u32 + 2);
	// rlwinm. r11,r11,0,28,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x8;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x8279534c
	if (ctx.cr0.eq) goto loc_8279534C;
	// addi r5,r1,96
	ctx.r5.s64 = ctx.r1.s64 + 96;
	// lhz r3,0(r31)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// addi r4,r1,97
	ctx.r4.s64 = ctx.r1.s64 + 97;
	// bl 0x8278bb20
	ctx.lr = 0x827952C4;
	sub_8278BB20(ctx, base);
	// lbz r9,97(r1)
	ctx.r9.u64 = REX_LOAD_U8(ctx.r1.u32 + 97);
	// mr. r11,r9
	ctx.r11.u64 = ctx.r9.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x827952e8
	if (ctx.cr0.eq) goto loc_827952E8;
	// mulli r10,r11,20
	ctx.r10.s64 = static_cast<int64_t>(ctx.r11.u64 * static_cast<uint64_t>(20));
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// lbz r10,-2(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + -2);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r9,r11,24
	ctx.r9.u64 = ctx.r11.u32 & 0xFF;
	// stb r9,97(r1)
	REX_STORE_U8(ctx.r1.u32 + 97, ctx.r9.u8);
loc_827952E8:
	// lbz r10,96(r1)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r1.u32 + 96);
	// mr. r11,r10
	ctx.r11.u64 = ctx.r10.u64;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq 0x82795310
	if (ctx.cr0.eq) goto loc_82795310;
	// add r10,r11,r25
	ctx.r10.u64 = ctx.r11.u64 + ctx.r25.u64;
	// mulli r10,r10,20
	ctx.r10.s64 = static_cast<int64_t>(ctx.r10.u64 * static_cast<uint64_t>(20));
	// add r10,r10,r21
	ctx.r10.u64 = ctx.r10.u64 + ctx.r21.u64;
	// lbz r10,-2(r10)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r10.u32 + -2);
	// subf r11,r10,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r10.u64;
	// clrlwi r10,r11,24
	ctx.r10.u64 = ctx.r11.u32 & 0xFF;
	// stb r10,96(r1)
	REX_STORE_U8(ctx.r1.u32 + 96, ctx.r10.u8);
loc_82795310:
	// clrlwi. r11,r9,24
	ctx.r11.u64 = ctx.r9.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne 0x82795334
	if (!ctx.cr0.eq) goto loc_82795334;
	// clrlwi. r9,r10,24
	ctx.r9.u64 = ctx.r10.u32 & 0xFF;
	ctx.cr0.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne 0x82795334
	if (!ctx.cr0.eq) goto loc_82795334;
	// lhz r11,332(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 332);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// clrlwi r11,r11,22
	ctx.r11.u64 = ctx.r11.u32 & 0x3FF;
	// ori r11,r11,32768
	ctx.r11.u64 = ctx.r11.u64 | 32768;
	// b 0x82795340
	goto loc_82795340;
loc_82795334:
	// rlwinm r10,r10,8,16,23
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 8) & 0xFF00;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// clrlwi r11,r11,16
	ctx.r11.u64 = ctx.r11.u32 & 0xFFFF;
loc_82795340:
	// lhz r9,4(r31)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r31.u32 + 4);
	// lwz r10,36(r30)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r30.u32 + 36);
	// sthx r11,r9,r10
	REX_STORE_U16(ctx.r9.u32 + ctx.r10.u32, ctx.r11.u16);
loc_8279534C:
	// lhz r11,328(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 328);
	// addi r29,r29,1
	ctx.r29.s64 = ctx.r29.s64 + 1;
	// addi r31,r31,20
	ctx.r31.s64 = ctx.r31.s64 + 20;
	// cmplw cr6,r29,r11
	ctx.cr6.compare<uint32_t>(ctx.r29.u32, ctx.r11.u32, ctx.xer);
	// blt cr6,0x827952a8
	if (ctx.cr6.lt) goto loc_827952A8;
loc_82795360:
	// lwz r4,100(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// sth r28,328(r30)
	REX_STORE_U16(ctx.r30.u32 + 328, ctx.r28.u16);
	// stw r16,32(r30)
	REX_STORE_U32(ctx.r30.u32 + 32, ctx.r16.u32);
loc_8279536C:
	// lwz r11,32(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 32);
	// addi r8,r1,112
	ctx.r8.s64 = ctx.r1.s64 + 112;
	// lwz r6,460(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 460);
	// subfic r7,r11,1264
	ctx.xer.ca = ctx.r11.u32 <= 1264;
	ctx.r7.u64 = static_cast<uint64_t>(1264) - ctx.r11.u64;
	// lwz r3,28(r30)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r30.u32 + 28);
	// lhz r5,446(r1)
	ctx.r5.u64 = REX_LOAD_U16(ctx.r1.u32 + 446);
	// bl 0x82794468
	ctx.lr = 0x82795388;
	sub_82794468(ctx, base);
	// lwz r10,112(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
	// lhz r11,454(r1)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r1.u32 + 454);
	// subf r10,r10,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r10.u64;
	// stw r3,24(r30)
	REX_STORE_U32(ctx.r30.u32 + 24, ctx.r3.u32);
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// cntlzw r10,r10
	ctx.r10.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// sth r11,334(r30)
	REX_STORE_U16(ctx.r30.u32 + 334, ctx.r11.u16);
	// rlwinm r3,r10,27,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 27) & 0x1;
	// addi r1,r1,416
	ctx.r1.s64 = ctx.r1.s64 + 416;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

DEFINE_REX_FUNC(sub_827AEA30) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9724(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9724);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-9720(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -9720, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AF370) {
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
	// lfs f0,22712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9532(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9532);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9448(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9448, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827AFE20) {
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
	// lfs f0,22840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9240(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9240);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9132(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B0A50) {
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
	// lfs f0,23016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8832(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8832);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8768(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8768, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B1718) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23176(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23176);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8492(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8492);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8384(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8384, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B2368) {
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
	// lfs f0,23352(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23352);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-8064(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -8064);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-8016(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -8016, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B3210) {
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
	// lfs f0,23496(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23496);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7696(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7696);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7580(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B43F0) {
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
	// lfs f0,23720(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23720);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7168(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7168);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7056(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7056, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B55B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-6532(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6532, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-6108(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6108);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-8644(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -8644);
	ctx.f13.f64 = double(temp.f32);
	// fsubs f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 - ctx.f13.f64));
	// stfs f0,-6100(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -6100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B6FD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24268(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24268);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5752(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5752, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B7DE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-5336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5332(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5332, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B8C88) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-4940(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4940);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4936(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4936, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827B9B78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,24760
	ctx.r9.s64 = ctx.r11.s64 + 24760;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,24760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BAB40) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-4068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4068);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-4024(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -4024, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BB518) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-3728(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3728);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-3724(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -3724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BC330) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,25480
	ctx.r9.s64 = ctx.r11.s64 + 25480;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3300(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3300, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BD638) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,25688
	ctx.r9.s64 = ctx.r11.s64 + 25688;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,25688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 25688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2744(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BE6E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-2260(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2260);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2256(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2256, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827BF538) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-1836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C0470) {
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
	// lfs f0,26344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,624(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 624);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-1452(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -1452);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-1368(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -1368, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C1640) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -992);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-844(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2050) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,26752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 26752);
	ctx.f0.f64 = double(temp.f32);
	// fneg f0,f0
	ctx.f0.u64 = ctx.f0.u64 ^ 0x8000000000000000;
	// stfs f0,-580(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C2C18) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C3AF8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,220(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 220, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C4848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,628(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 628, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C5878) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27756(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27756);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1108(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1108, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C6890) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,1600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C77B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,2064(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2064);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2068(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2068, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C8660) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,28584
	ctx.r9.s64 = ctx.r11.s64 + 28584;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,28584(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28584);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,2512(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 2512, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827C97D0) {
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
	// lfs f0,28776(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28776);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,2952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 2952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,3020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 3020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CA980) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,3532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3532);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,3536(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 3536, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CB968) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32240
	ctx.r10.s64 = -2112880640;
	// addi r9,r11,29096
	ctx.r9.s64 = ctx.r11.s64 + 29096;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4020(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4020, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CCB18) {
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
	// lfs f0,29288(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29288);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,4484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 4484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,4540(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 4540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CDD60) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,5068(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5068);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,5072(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 5072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827CEE48) {
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
	// lfs f0,29608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5444(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5444);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,5560(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 5560, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D0058) {
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
	// lfs f0,29800(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29800);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,5980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 5980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6092(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6092, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D12D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,29992
	ctx.r9.s64 = ctx.r11.s64 + 29992;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,29992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 29992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,6632(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 6632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D25F0) {
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
	// lfs f0,30184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30184);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,7084(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 7084);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,7188(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 7188, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D3858) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,30376
	ctx.r9.s64 = ctx.r11.s64 + 30376;
	// lfs f0,30376(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30376);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,7724(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 7724, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D47A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,8164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8168(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D5548) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30716(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30716);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,8568(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 8568, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D6638) {
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
	// lfs f0,30824(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30824);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,8952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 8952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9060(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9060, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D7890) {
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
	// lfs f0,31032(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31032);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,9480(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 9480);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,9596(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 9596, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D8AE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31224
	ctx.r9.s64 = ctx.r11.s64 + 31224;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31224(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31224);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10132(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10132, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827D9DD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32228
	ctx.r10.s64 = -2112094208;
	// addi r9,r11,31432
	ctx.r9.s64 = ctx.r11.s64 + 31432;
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// lfs f0,31432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 31432);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,10684(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 10684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DB0A0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,11228(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11228);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,11232(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 11232, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DBA80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11512(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11512);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11516(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11516, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DC9B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,11980(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 11980);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,11984(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 11984, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DD938) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,12432(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 12432);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,12436(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 12436, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DE280) {
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
	// lfs f0,32088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,12592(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 12592);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,12708(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 12708, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827DF600) {
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
	// lfs f0,32296(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32296);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,13176(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 13176);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,13280(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 13280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E0868) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32115
	ctx.r11.s64 = -2104688640;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// addi r9,r11,32504
	ctx.r9.s64 = ctx.r11.s64 + 32504;
	// lfs f0,32504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,13816(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 13816, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E1730) {
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
	// lfs f0,-32760(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32760);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,14152(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 14152);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,14264(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 14264, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E2AA0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,14844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 14844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E3B08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,15300(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 15300);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15304(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15304, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E4A98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-32008(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32008);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15640(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15640);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,15748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 15748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E5A10) {
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
	// lfs f0,-31160(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -31160);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16064(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16064);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16180(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16180, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E6F60) {
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
	// lfs f0,-28600(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28600);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16724(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16724);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,16796(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 16796, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E8238) {
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
	// lfs f0,-26712(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26712);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,17196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 17196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,17308(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 17308, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827E96F8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,17896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 17896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,17900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 17900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EA4D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,-23624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -23624);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,18280(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 18280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB068) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,18608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 18608);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,18612(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 18612, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EB900) {
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
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,18732(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 18732);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,18852(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 18852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827ECDE0) {
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
	// lfs f0,-21816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -21816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,19280(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 19280);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,19420(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 19420, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EE210) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-20476(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -20476);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,19972(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 19972, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827EEF10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,20332(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 20332);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20336(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20336, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0088) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-19072(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19072);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,20808(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 20808, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F0ED0) {
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
	// lfs f0,21184(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21184);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18512(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18512);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,21208(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 21208, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F29D0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,21956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 21956);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,21960(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 21960, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F39C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,22404(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 22404);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,22408(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 22408, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F4BC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-16320(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -16320);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23100(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23100, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F5900) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,23536(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 23536);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,23540(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 23540, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F69A0) {
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
	// lfs f0,-14896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -14896);
	ctx.f0.f64 = double(temp.f32);
	// addi r11,r8,-4080
	ctx.r11.s64 = ctx.r8.s64 + -4080;
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,23980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 23980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f13,f0,f13,f12
	ctx.f13.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// lfs f0,80(r11)
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 80);
	ctx.f0.f64 = double(temp.f32);
	// fmuls f0,f13,f0
	ctx.f0.f64 = double(float(ctx.f13.f64 * ctx.f0.f64));
	// stfs f0,24000(r7)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r7.u32 + 24000, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F8598) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,24740(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 24740);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,24744(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 24744, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827F9548) {
	REX_FUNC_PROLOGUE();
	// lis r8,-32112
	ctx.r8.s64 = -2104492032;
	// li r7,3
	ctx.r7.s64 = 3;
	// addi r6,r8,25184
	ctx.r6.s64 = ctx.r8.s64 + 25184;
	// li r10,7
	ctx.r10.s64 = 7;
	// li r5,97
	ctx.r5.s64 = 97;
	// lwz r11,25184(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 25184);
	// li r9,1
	ctx.r9.s64 = 1;
	// rlwimi r11,r7,1,24,31
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFF) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF00);
	// stw r11,25184(r8)
	REX_STORE_U32(ctx.r8.u32 + 25184, ctx.r11.u32);
	// stb r10,2(r6)
	REX_STORE_U8(ctx.r6.u32 + 2, ctx.r10.u8);
	// lwz r11,25184(r8)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r8.u32 + 25184);
	// rlwimi r11,r5,16,8,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 16) & 0xFF0000) | (ctx.r11.u64 & 0xFFFFFFFFFF00FFFF);
	// stw r11,25184(r8)
	REX_STORE_U32(ctx.r8.u32 + 25184, ctx.r11.u32);
	// stb r9,25184(r8)
	REX_STORE_U8(ctx.r8.u32 + 25184, ctx.r9.u8);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FAA58) {
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
	// lfs f0,-9768(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9768);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,25664(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 25664);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,25780(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 25780, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FBEA8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26372(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26372, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FCCD0) {
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
	// lfs f13,26736(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 26736);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,26788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 26788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FDDD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-9164(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -9164);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FEBD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,27688(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 27688);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,27692(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 27692, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_827FFB68) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8920(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8920);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,28036(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 28036);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28144(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28144, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82800A48) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28576(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28576, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82801848) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,28984(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 28984);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,28988(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 28988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82802988) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29488(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82803788) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,-8256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,29900(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 29900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828045D8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,30312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30312);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,30316(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 30316, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,30612(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 30612);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,30616(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 30616, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82805E78) {
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
	// lfs f0,-7896(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7896);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,30976(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 30976);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31036(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31036, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828071E0) {
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
	// lfs f0,-7704(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7704);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10848(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10848);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,31528(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 31528);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,31600(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + 31600, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828085E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32112
	ctx.r10.s64 = -2104492032;
	// lfs f0,32180(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32180);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,32184(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 32184, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809028) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32112
	ctx.r11.s64 = -2104492032;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32112
	ctx.r9.s64 = -2104492032;
	// lfs f0,32480(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 32480);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,32484(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 32484, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82809F08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-7256
	ctx.r9.s64 = ctx.r11.s64 + -7256;
	// lfs f0,-7256(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7256);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32620(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -32620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280AE98) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-32172(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -32172);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-32168(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -32168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280BCE0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6936(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6936);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-31800(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -31800);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-31748(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -31748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280CD88) {
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
	// lfs f0,-6744(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6744);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-31364(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -31364);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-31248(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -31248, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280E0C0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6412(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6412);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-30684(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -30684, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8280F188) {
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
	// lfs f0,-6304(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6304);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-30296(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -30296);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-30192(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -30192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828103B0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-6016(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -6016);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-29656(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -29656, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828112E0) {
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
	// lfs f0,-5848(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5848);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-29320(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -29320);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-29204(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -29204, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828126E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-28624(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -28624);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-28620(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -28620, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82813500) {
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
	// lfs f0,-5448(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5448);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,15088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 15088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-28316(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -28316);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-28200(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -28200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82814908) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-27548(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -27548);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27544(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27544, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82815A78) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4616(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4616);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-27040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -27040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82816818) {
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
	// lfs f0,-4440(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4440);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-26748(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -26748);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-26632(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -26632, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82817BC8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-26048(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -26048);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-26044(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -26044, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82818BD8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// addi r9,r11,-3816
	ctx.r9.s64 = ctx.r11.s64 + -3816;
	// lfs f0,-3816(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3816);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25556(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -25556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828199E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3500(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3500);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-25136(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -25136, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281A9E0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-24652(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -24652);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24648(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24648, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281BC08) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-3020(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -3020);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-24120(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -24120, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281CA10) {
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
	// lfs f0,-2840(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2840);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23784(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23784);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23696(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23696, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281DCD0) {
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
	// lfs f0,-2504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-23196(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -23196);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-23128(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -23128, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8281F040) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-22560(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -22560);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-22556(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -22556, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828200E0) {
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
	// lfs f0,-2056(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2056);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-22192(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -22192);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-22072(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -22072, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82821438) {
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
	// lfs f0,-1784(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1784);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32028(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32028);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21580(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21580);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-21500(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -21500, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828228D8) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-21016(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -21016);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-20900(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -20900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82823C80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1240(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1240);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-20416(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -20416);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-20308(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -20308, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82824BD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-19864(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -19864);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19860(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19860, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82825AF0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-656(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -656);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-19392(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -19392, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82826C20) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-520(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -520);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-18996(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -18996);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18888(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18888, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82827B80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-18444(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -18444);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-18440(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -18440, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82828AB8) {
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
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-18056(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -18056);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-17988(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -17988, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82829DD0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,104(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 104);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-17432(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -17432, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282AE40) {
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
	// lfs f0,216(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 216);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-17068(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -17068);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-16952(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -16952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282C170) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,572(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 572);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-16380(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -16380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282D010) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-15956(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -15956);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-15952(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -15952, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282E050) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// addi r9,r11,872
	ctx.r9.s64 = ctx.r11.s64 + 872;
	// lis r8,-32111
	ctx.r8.s64 = -2104426496;
	// lfs f0,872(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 872);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,16(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + 16);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-15472(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -15472, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8282F490) {
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
	// lfs f0,1096(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1096);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-14980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -14980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-14876(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -14876, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82830838) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,1428(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 1428);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-14292(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -14292, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82831680) {
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
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-13980(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -13980);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-13868(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -13868, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82832CC0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-13204(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -13204);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-13200(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -13200, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82833608) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-12932(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12932);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-12928(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -12928, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828344E8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,2208(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2208);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-12488(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -12488, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835070) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-12144(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -12144);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-12140(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -12140, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82835A70) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2532(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2532);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-11844(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -11844, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828368E8) {
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
	// lfs f0,2680(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2680);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-11464(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -11464);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-11416(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -11416, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82837CE8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-10836(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -10836);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-10832(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -10832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82838D00) {
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
	// lfs f0,3088(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3088);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-10244(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -10244);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-10448(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -10448);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-10360(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -10360, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283A1E8) {
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
	// lfs f0,3344(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3344);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9868(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9868);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9748(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9748, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283B5D0) {
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
	// lfs f0,3552(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 3552);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-9276(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -9276);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-9168(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -9168, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283CA10) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-8700(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8700);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-8580(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -8580, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283D290) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-8328(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -8328);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-8324(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -8324, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283E398) {
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
	// lfs f0,4080(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4080);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,13088(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 13088);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7952(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7952);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7832(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7832, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283F7A8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-7244(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -7244);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-7240(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -7240, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8283FF78) {
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
	// lfs f0,4528(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4528);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-32216(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -32216);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-7072(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -7072);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-7004(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -7004, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_828414D0) {
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
	// lfs f0,4752(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4752);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-6484(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -6484);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-6380(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -6380, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82842928) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,4992(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 4992);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-5892(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -5892);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5788(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5788, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82843800) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-5356(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -5356);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-5352(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -5352, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82844710) {
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
	// lfs f0,5400(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5400);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1608(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1608);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-5020(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -5020);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-4900(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -4900, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82845B80) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-4284(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -4284);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-4280(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -4280, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82846C50) {
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
	// lfs f0,5888(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 5888);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,12468(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 12468);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-3892(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3892);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3792(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3792, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82847FB8) {
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
	// lfs f12,-3312(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -3312);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-3212(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -3212, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82849378) {
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
	// lfs f0,6336(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 6336);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-30128(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -30128);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-2744(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -2744);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-2636(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -2636, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284A7F0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-2044(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -2044);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-2040(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -2040, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284B6C8) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,-1608(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1608);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-1604(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -1604, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284C678) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,-1152(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + -1152);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,-1148(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + -1148, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284D098) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,7092(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7092);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,-852(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + -852, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284DF48) {
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
	// lfs f0,7312(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 7312);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-6412(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -6412);
	ctx.f13.f64 = double(temp.f32);
	// lfs f12,-512(r9)
	temp.u32 = REX_LOAD_U32(ctx.r9.u32 + -512);
	ctx.f12.f64 = double(temp.f32);
	// fmadds f0,f0,f13,f12
	ctx.f0.f64 = double(float(std::fma(ctx.f0.f64, ctx.f13.f64, ctx.f12.f64)));
	// stfs f0,-396(r8)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r8.u32 + -396, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8284F310) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,188(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 188);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,192(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 192, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82850388) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8000(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8000);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,688(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 688, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82851468) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8200(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8200);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1092(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1092);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1196(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1196, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852458) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lfs f0,8396(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8396);
	ctx.f0.f64 = double(temp.f32);
	// stfs f0,1640(r10)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r10.u32 + 1640, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82852CB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32114
	ctx.r11.s64 = -2104623104;
	// lis r10,-32111
	ctx.r10.s64 = -2104426496;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,8504(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 8504);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,1792(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + 1792);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,1896(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 1896, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_82853C50) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	// lis r11,-32111
	ctx.r11.s64 = -2104426496;
	// lis r10,-32226
	ctx.r10.s64 = -2111963136;
	// lis r9,-32111
	ctx.r9.s64 = -2104426496;
	// lfs f0,2360(r11)
	ctx.fpscr.disableFlushMode();
	temp.u32 = REX_LOAD_U32(ctx.r11.u32 + 2360);
	ctx.f0.f64 = double(temp.f32);
	// lfs f13,-16516(r10)
	temp.u32 = REX_LOAD_U32(ctx.r10.u32 + -16516);
	ctx.f13.f64 = double(temp.f32);
	// fadds f0,f0,f13
	ctx.f0.f64 = double(float(ctx.f0.f64 + ctx.f13.f64));
	// stfs f0,2364(r9)
	temp.f32 = float(ctx.f0.f64);
	REX_STORE_U32(ctx.r9.u32 + 2364, temp.u32);
	// blr 
	return;
}

DEFINE_REX_FUNC(sub_8286FFB0) {
	REX_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82739ee0
	ctx.lr = 0x8286FFB8;
	__savegprlr_14(ctx, base);
	// stwu r1,-320(r1)
	ea = -320 + ctx.r1.u32;
	REX_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lwz r6,22488(r3)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r3.u32 + 22488);
	// mr r30,r4
	ctx.r30.u64 = ctx.r4.u64;
	// stw r3,340(r1)
	REX_STORE_U32(ctx.r1.u32 + 340, ctx.r3.u32);
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r11,224(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 224);
	// lwz r8,3748(r31)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r31.u32 + 3748);
	// lwz r7,3752(r31)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r31.u32 + 3752);
	// lwz r9,3744(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 3744);
	// add r5,r8,r11
	ctx.r5.u64 = ctx.r8.u64 + ctx.r11.u64;
	// lwz r10,220(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 220);
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r11,268(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 268);
	// lwz r8,1312(r30)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r30.u32 + 1312);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// stw r6,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r6.u32);
	// lwz r9,22500(r31)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r31.u32 + 22500);
	// stw r9,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r9.u32);
	// lwz r7,616(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 616);
	// stw r7,36(r29)
	REX_STORE_U32(ctx.r29.u32 + 36, ctx.r7.u32);
	// lwz r6,428(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// stw r6,40(r29)
	REX_STORE_U32(ctx.r29.u32 + 40, ctx.r6.u32);
	// lwz r9,1164(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1164);
	// stw r9,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r9.u32);
	// lwz r7,616(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 616);
	// stw r7,36(r29)
	REX_STORE_U32(ctx.r29.u32 + 36, ctx.r7.u32);
	// lwz r6,428(r30)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r30.u32 + 428);
	// stw r6,40(r29)
	REX_STORE_U32(ctx.r29.u32 + 40, ctx.r6.u32);
	// lwz r9,1164(r30)
	ctx.r9.u64 = REX_LOAD_U32(ctx.r30.u32 + 1164);
	// stw r9,44(r29)
	REX_STORE_U32(ctx.r29.u32 + 44, ctx.r9.u32);
	// lhz r9,50(r30)
	ctx.r9.u64 = REX_LOAD_U16(ctx.r30.u32 + 50);
	// lhz r6,52(r30)
	ctx.r6.u64 = REX_LOAD_U16(ctx.r30.u32 + 52);
	// rlwinm r6,r6,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r7,r9,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r10,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r10.u32);
	// stw r11,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r11.u32);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r4,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r4.u32);
	// stw r3,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r3.u32);
	// stw r6,112(r1)
	REX_STORE_U32(ctx.r1.u32 + 112, ctx.r6.u32);
	// stw r7,108(r1)
	REX_STORE_U32(ctx.r1.u32 + 108, ctx.r7.u32);
	// beq cr6,0x828704f8
	if (ctx.cr6.eq) goto loc_828704F8;
	// li r15,16
	ctx.r15.s64 = 16;
	// li r14,32
	ctx.r14.s64 = 32;
	// li r16,48
	ctx.r16.s64 = 48;
	// li r17,64
	ctx.r17.s64 = 64;
	// li r18,80
	ctx.r18.s64 = 80;
	// li r19,96
	ctx.r19.s64 = 96;
	// li r20,112
	ctx.r20.s64 = 112;
loc_82870088:
	// li r11,0
	ctx.r11.s64 = 0;
	// lwz r24,92(r1)
	ctx.r24.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r23,84(r1)
	ctx.r23.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// lwz r22,88(r1)
	ctx.r22.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// beq cr6,0x828704b4
	if (ctx.cr6.eq) goto loc_828704B4;
loc_828700A4:
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
	// addi r9,r8,8
	ctx.r9.s64 = ctx.r8.s64 + 8;
	// ld r11,0(r8)
	ctx.r11.u64 = REX_LOAD_U64(ctx.r8.u32 + 0);
	// stw r9,100(r1)
	REX_STORE_U32(ctx.r1.u32 + 100, ctx.r9.u32);
	// lwz r6,0(r10)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r10.u32 + 0);
	// rlwinm r8,r6,0,21,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x700;
	// cmplwi cr6,r8,1024
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1024, ctx.xer);
	// beq cr6,0x82870484
	if (ctx.cr6.eq) goto loc_82870484;
	// rldicl r10,r11,8,56
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// lwz r7,388(r30)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r30.u32 + 388);
	// rldicl r9,r11,16,48
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 16) & 0xFFFF;
	// stw r24,144(r1)
	REX_STORE_U32(ctx.r1.u32 + 144, ctx.r24.u32);
	// clrlwi r10,r10,26
	ctx.r10.u64 = ctx.r10.u32 & 0x3F;
	// stw r23,160(r1)
	REX_STORE_U32(ctx.r1.u32 + 160, ctx.r23.u32);
	// mr r26,r11
	ctx.r26.u64 = ctx.r11.u64;
	// lhz r11,76(r30)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r30.u32 + 76);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r22,164(r1)
	REX_STORE_U32(ctx.r1.u32 + 164, ctx.r22.u32);
	// rlwinm r6,r6,0,15,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x10000;
	// add r5,r10,r8
	ctx.r5.u64 = ctx.r10.u64 + ctx.r8.u64;
	// addi r8,r24,8
	ctx.r8.s64 = ctx.r24.s64 + 8;
	// rlwinm r10,r5,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r11,124(r1)
	REX_STORE_U32(ctx.r1.u32 + 124, ctx.r11.u32);
	// clrlwi r21,r9,26
	ctx.r21.u64 = ctx.r9.u32 & 0x3F;
	// stw r8,148(r1)
	REX_STORE_U32(ctx.r1.u32 + 148, ctx.r8.u32);
	// add r28,r10,r7
	ctx.r28.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lhz r10,74(r30)
	ctx.r10.u64 = REX_LOAD_U16(ctx.r30.u32 + 74);
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82870124
	if (ctx.cr6.eq) goto loc_82870124;
	// add r9,r10,r24
	ctx.r9.u64 = ctx.r10.u64 + ctx.r24.u64;
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// b 0x8287012c
	goto loc_8287012C;
loc_82870124:
	// rotlwi r9,r10,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r10.u32, 3);
	// add r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 + ctx.r24.u64;
loc_8287012C:
	// addi r7,r9,8
	ctx.r7.s64 = ctx.r9.s64 + 8;
	// stw r9,152(r1)
	REX_STORE_U32(ctx.r1.u32 + 152, ctx.r9.u32);
	// stw r10,120(r1)
	REX_STORE_U32(ctx.r1.u32 + 120, ctx.r10.u32);
	// stw r7,156(r1)
	REX_STORE_U32(ctx.r1.u32 + 156, ctx.r7.u32);
	// lis r7,-32113
	ctx.r7.s64 = -2104557568;
	// lwz r8,-11948(r7)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r7.u32 + -11948);
	// cmplwi cr6,r8,9
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 9, ctx.xer);
	// bgt cr6,0x8287028c
	if (ctx.cr6.gt) goto loc_8287028C;
	// lis r12,-32121
	ctx.r12.s64 = -2105081856;
	// rlwinm r0,r8,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r12,r12,356
	ctx.r12.s64 = ctx.r12.s64 + 356;
	// lwzx r0,r12,r0
	ctx.r0.u64 = REX_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r8.u32) {
	case 0:
		goto loc_8287018C;
	case 1:
		goto loc_828701E0;
	case 2:
		goto loc_82870234;
	case 3:
		goto loc_8287023C;
	case 4:
		goto loc_8287028C;
	case 5:
		goto loc_8287028C;
	case 6:
		goto loc_8287028C;
	case 7:
		goto loc_8287028C;
	case 8:
		goto loc_8287018C;
	case 9:
		goto loc_828701E0;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_8287018C:
	// addi r11,r24,128
	ctx.r11.s64 = ctx.r24.s64 + 128;
	// dcbt r0,r11
	// dcbt r10,r11
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r11
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// dcbt r6,r11
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r11
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// dcbt r4,r11
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r11
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r10,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r10.u64;
	// dcbt r5,r11
	// b 0x8287028c
	goto loc_8287028C;
loc_828701E0:
	// addi r11,r9,128
	ctx.r11.s64 = ctx.r9.s64 + 128;
	// dcbt r0,r11
	// dcbt r10,r11
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r11
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// dcbt r6,r11
	// rlwinm r5,r10,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r11
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// dcbt r4,r11
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r10,r9
	ctx.r3.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r11
	// rlwinm r6,r10,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r10,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r10.u64;
	// dcbt r5,r11
	// b 0x8287028c
	goto loc_8287028C;
loc_82870234:
	// addi r10,r23,128
	ctx.r10.s64 = ctx.r23.s64 + 128;
	// b 0x82870240
	goto loc_82870240;
loc_8287023C:
	// addi r10,r22,128
	ctx.r10.s64 = ctx.r22.s64 + 128;
loc_82870240:
	// dcbt r0,r10
	// dcbt r11,r10
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r10
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// dcbt r6,r10
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r10
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// dcbt r4,r10
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r9,r3,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r9,r10
	// rlwinm r6,r11,3,0,28
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r5,r11,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r11.u64;
	// dcbt r5,r10
loc_8287028C:
	// addi r11,r8,1
	ctx.r11.s64 = ctx.r8.s64 + 1;
	// li r27,0
	ctx.r27.s64 = 0;
	// srawi r10,r11,4
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 4;
	// addze r9,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r9.s64 = temp.s64;
	// rlwinm r8,r9,4,0,27
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r11,r8,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r8.u64;
	// stw r11,-11948(r7)
	REX_STORE_U32(ctx.r7.u32 + -11948, ctx.r11.u32);
loc_828702A8:
	// clrlwi r10,r21,31
	ctx.r10.u64 = ctx.r21.u32 & 0x1;
	// rldicl r9,r26,20,44
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r26.u64, 20) & 0xFFFFF;
	// srawi r25,r27,2
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3) != 0);
	ctx.r25.s64 = ctx.r27.s32 >> 2;
	// clrlwi r11,r9,29
	ctx.r11.u64 = ctx.r9.u32 & 0x7;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82870468
	if (ctx.cr6.eq) goto loc_82870468;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x828703f8
	if (!ctx.cr6.eq) goto loc_828703F8;
	// lwz r11,24(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 24);
	// addi r5,r30,168
	ctx.r5.s64 = ctx.r30.s64 + 168;
	// lwz r4,444(r30)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r30.u32 + 444);
	// li r10,0
	ctx.r10.s64 = 0;
	// addi r3,r11,1
	ctx.r3.s64 = ctx.r11.s64 + 1;
	// lwz r7,0(r28)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r28.u32 + 0);
	// lwz r6,4(r28)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r28.u32 + 4);
	// li r9,0
	ctx.r9.s64 = 0;
	// lwz r31,40(r29)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r29.u32 + 40);
	// lbz r8,0(r11)
	ctx.r8.u64 = REX_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r29)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r29.u32 + 20);
	// stw r3,24(r29)
	REX_STORE_U32(ctx.r29.u32 + 24, ctx.r3.u32);
	// dcbzl r0,r31
	ea = (ctx.r31.u32) & ~127;
	memset((void*)REX_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r8,128
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 128, ctx.xer);
	// blt cr6,0x8287031c
	if (ctx.cr6.lt) goto loc_8287031C;
	// mr r7,r29
	ctx.r7.u64 = ctx.r29.u64;
	// mr r6,r28
	ctx.r6.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// bl 0x826d4738
	ctx.lr = 0x82870314;
	sub_826D4738(ctx, base);
	// mr r9,r3
	ctx.r9.u64 = ctx.r3.u64;
	// b 0x8287037c
	goto loc_8287037C;
loc_8287031C:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble cr6,0x82870378
	if (!ctx.cr6.gt) goto loc_82870378;
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
loc_82870328:
	// lhz r3,0(r11)
	ctx.r3.u64 = REX_LOAD_U16(ctx.r11.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r15,r3,24,8,31
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 24) & 0xFFFFFF;
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r8,r15,r7
	ctx.r8.s64 = int64_t(ctx.r15.s32) * int64_t(ctx.r7.s32);
	// lbzx r15,r10,r4
	ctx.r15.u64 = REX_LOAD_U8(ctx.r10.u32 + ctx.r4.u32);
	// lbzx r14,r15,r5
	ctx.r14.u64 = REX_LOAD_U8(ctx.r15.u32 + ctx.r5.u32);
	// rlwinm r3,r3,25,31,31
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 25) & 0x1;
	// add r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	// neg r3,r3
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r3.u64);
	// rotlwi r15,r15,1
	ctx.r15.u64 = __builtin_rotateleft32(ctx.r15.u32, 1);
	// xor r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r3.u64;
	// or r9,r14,r9
	ctx.r9.u64 = ctx.r14.u64 | ctx.r9.u64;
	// subf r3,r3,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r3.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// sthx r3,r15,r31
	REX_STORE_U16(ctx.r15.u32 + ctx.r31.u32, ctx.r3.u16);
	// bdnz 0x82870328
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82870328;
	// li r14,32
	ctx.r14.s64 = 32;
	// li r15,16
	ctx.r15.s64 = 16;
loc_82870378:
	// stw r11,20(r29)
	REX_STORE_U32(ctx.r29.u32 + 20, ctx.r11.u32);
loc_8287037C:
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x828703e8
	if (!ctx.cr6.eq) goto loc_828703E8;
	// lhz r11,0(r31)
	ctx.r11.u64 = REX_LOAD_U16(ctx.r31.u32 + 0);
	// addi r9,r1,128
	ctx.r9.s64 = ctx.r1.s64 + 128;
	// addi r8,r1,128
	ctx.r8.s64 = ctx.r1.s64 + 128;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// srawi r10,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r6,r11,16
	ctx.r6.s64 = ctx.r11.s64 + 16;
	// srawi r5,r6,5
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1F) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 5;
	// clrlwi r4,r5,16
	ctx.r4.u64 = ctx.r5.u32 & 0xFFFF;
	// stw r4,128(r1)
	REX_STORE_U32(ctx.r1.u32 + 128, ctx.r4.u32);
	// lvx128 v0,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)REX_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vsplth v0,v0,1
	simde_mm_store_si128((simde__m128i*)ctx.v0.u16, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u16), simde_mm_set1_epi16(short(0xD0C))));
	// stvx128 v0,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r0,r31
	ea = (ctx.r31.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r15
	ea = (ctx.r31.u32 + ctx.r15.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r14
	ea = (ctx.r31.u32 + ctx.r14.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r16
	ea = (ctx.r31.u32 + ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r17
	ea = (ctx.r31.u32 + ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r18
	ea = (ctx.r31.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r19
	ea = (ctx.r31.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v0,r31,r20
	ea = (ctx.r31.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)REX_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// b 0x8287043c
	goto loc_8287043C;
loc_828703E8:
	// mr r4,r31
	ctx.r4.u64 = ctx.r31.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82870a60
	ctx.lr = 0x828703F4;
	sub_82870A60(ctx, base);
	// b 0x8287043c
	goto loc_8287043C;
loc_828703F8:
	// rldicl r10,r26,24,40
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u64, 24) & 0xFFFFFF;
	// lwz r7,36(r29)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r29.u32 + 36);
	// rlwinm r11,r11,0,29,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x6;
	// clrlwi r5,r10,28
	ctx.r5.u64 = ctx.r10.u32 & 0xF;
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// add r9,r5,r30
	ctx.r9.u64 = ctx.r5.u64 + ctx.r30.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mr r31,r7
	ctx.r31.u64 = ctx.r7.u64;
	// lbz r10,320(r9)
	ctx.r10.u64 = REX_LOAD_U8(ctx.r9.u32 + 320);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r8,r11,159
	ctx.r8.s64 = ctx.r11.s64 + 159;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r30
	ctx.r10.u64 = REX_LOAD_U32(ctx.r11.u32 + ctx.r30.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x8287043C;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_8287043C:
	// lwz r11,960(r30)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r30.u32 + 960);
	// rlwinm r10,r25,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r9,r1,120
	ctx.r9.s64 = ctx.r1.s64 + 120;
	// rlwinm r8,r27,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,144
	ctx.r7.s64 = ctx.r1.s64 + 144;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// lwzx r5,r10,r9
	ctx.r5.u64 = REX_LOAD_U32(ctx.r10.u32 + ctx.r9.u32);
	// lwzx r4,r8,r7
	ctx.r4.u64 = REX_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// bctrl 
	ctx.lr = 0x82870464;
	REX_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r31,340(r1)
	ctx.r31.u64 = REX_LOAD_U32(ctx.r1.u32 + 340);
loc_82870468:
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// rlwinm r21,r21,31,1,31
	ctx.r21.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 31) & 0x7FFFFFFF;
	// rldicr r26,r26,8,55
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r26.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r27,6
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 6, ctx.xer);
	// blt cr6,0x828702a8
	if (ctx.cr6.lt) goto loc_828702A8;
	// lwz r7,108(r1)
	ctx.r7.u64 = REX_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r10,80(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 80);
loc_82870484:
	// lwz r11,96(r1)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r1.u32 + 96);
	// addi r10,r10,24
	ctx.r10.s64 = ctx.r10.s64 + 24;
	// lwz r8,100(r1)
	ctx.r8.u64 = REX_LOAD_U32(ctx.r1.u32 + 100);
	// addi r24,r24,16
	ctx.r24.s64 = ctx.r24.s64 + 16;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stw r10,80(r1)
	REX_STORE_U32(ctx.r1.u32 + 80, ctx.r10.u32);
	// addi r23,r23,8
	ctx.r23.s64 = ctx.r23.s64 + 8;
	// stw r11,96(r1)
	REX_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// addi r22,r22,8
	ctx.r22.s64 = ctx.r22.s64 + 8;
	// cmplw cr6,r11,r7
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r7.u32, ctx.xer);
	// blt cr6,0x828700a4
	if (ctx.cr6.lt) goto loc_828700A4;
	// lwz r6,112(r1)
	ctx.r6.u64 = REX_LOAD_U32(ctx.r1.u32 + 112);
loc_828704B4:
	// lwz r10,104(r1)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r11,232(r31)
	ctx.r11.u64 = REX_LOAD_U32(ctx.r31.u32 + 232);
	// lwz r5,84(r1)
	ctx.r5.u64 = REX_LOAD_U32(ctx.r1.u32 + 84);
	// addi r9,r10,1
	ctx.r9.s64 = ctx.r10.s64 + 1;
	// lwz r3,88(r1)
	ctx.r3.u64 = REX_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r4,92(r1)
	ctx.r4.u64 = REX_LOAD_U32(ctx.r1.u32 + 92);
	// add r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 + ctx.r5.u64;
	// lwz r10,228(r31)
	ctx.r10.u64 = REX_LOAD_U32(ctx.r31.u32 + 228);
	// add r3,r11,r3
	ctx.r3.u64 = ctx.r11.u64 + ctx.r3.u64;
	// cmplw cr6,r9,r6
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, ctx.r6.u32, ctx.xer);
	// stw r9,104(r1)
	REX_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// add r11,r4,r10
	ctx.r11.u64 = ctx.r4.u64 + ctx.r10.u64;
	// stw r5,84(r1)
	REX_STORE_U32(ctx.r1.u32 + 84, ctx.r5.u32);
	// stw r3,88(r1)
	REX_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// stw r11,92(r1)
	REX_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// blt cr6,0x82870088
	if (ctx.cr6.lt) goto loc_82870088;
	// li r3,0
	ctx.r3.s64 = 0;
loc_828704F8:
	// addi r1,r1,320
	ctx.r1.s64 = ctx.r1.s64 + 320;
	// b 0x82739f30
	__restgprlr_14(ctx, base);
	return;
}

